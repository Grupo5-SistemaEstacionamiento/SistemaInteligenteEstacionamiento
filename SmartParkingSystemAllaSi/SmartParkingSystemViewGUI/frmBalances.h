#pragma once

#include "frmGestionarMovimientos.h"
//#include "frmPrincipalAdmin.h"
#include "frmGraficasBalances.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemViewGUI {

	ref class frmGraficasBalances;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmBalances
	/// </summary>
	public ref class frmBalances : public System::Windows::Forms::Form
	{
	public:
		frmBalances(void)
		{
			InitializeComponent();

			balanceController = gcnew BalancesController();
			turnoCajaController = gcnew TurnoCajaController(); 

			ultimoIdTurnoInscritoEnBalance = 0;
			cajaCerrada = false;

			sincronizarPuntoDeCorte();
			cargarTurnos();
			cargarBalances();
			prepararCamposNuevoTurno();
		}
	private:
		BalancesController^ balanceController;
		TurnoCajaController^ turnoCajaController;

		int ultimoIdTurnoInscritoEnBalance;
	private: System::Windows::Forms::Button^ btnGestionarMov;
	private: System::Windows::Forms::Label^ lblBuscarFechaBalance;
	private: System::Windows::Forms::TextBox^ txtBusqFecha;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::Button^ btnGraficas;


		   bool cajaCerrada;

		void sincronizarPuntoDeCorte() {
			try {
				BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
				List<BalanceDiario^>^ listaBalances = balanceDao->buscarTodosArchivo();
				if (listaBalances != nullptr && listaBalances->Count > 0) {
					int turnosAbarcadosTotales = 0;
					for each (BalanceDiario ^ b in listaBalances) {
						turnosAbarcadosTotales += b->getCantidadTurnos();
					}
					ultimoIdTurnoInscritoEnBalance = turnosAbarcadosTotales;
				}
			}
			catch (Exception^) {}
		}

		void prepararCamposNuevoTurno() {
			try {
				TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
				List<TurnoCaja^>^ lista = turnoDao->buscarTodosArchivo();

				TurnoCaja^ turnoActivo = nullptr;
				if (lista != nullptr) {
					for each (TurnoCaja ^ t in lista) {
						if (t->getEstado() != "Cerrado") {
							turnoActivo = t;
							break;
						}
					}
				}

				if (turnoActivo != nullptr) {

					txtIdTurno->Text = turnoActivo->getIdTurno().ToString();
					txtSaldoInicial->Text = turnoActivo->getSaldoInicial().ToString("F2");

					if (turnoActivo->getEmpleado() != nullptr) {
						txtCodEmpleado->Text = turnoActivo->getEmpleado()->getCodigoEmpleado();
					}
					else {
						txtCodEmpleado->Text = "N/A";
					}

					txtCodEmpleado->ReadOnly = true;
				}
				else {

					txtCodEmpleado->ReadOnly = false;
					int siguienteId = 1;
					double saldoInicialSugerido = 0.0;

					if (lista != nullptr && lista->Count > 0) {
						TurnoCaja^ ultimoTurno = lista[lista->Count - 1];
						siguienteId = ultimoTurno->getIdTurno() + 1;

						if (ultimoTurno->getEstado() == "Cerrado") {
							saldoInicialSugerido = ultimoTurno->getSaldoFinal();
						}
						else {
							saldoInicialSugerido = ultimoTurno->getSaldoInicial();
						}
					}

					txtIdTurno->Text = siguienteId.ToString();
					txtSaldoInicial->Text = saldoInicialSugerido.ToString("F2");
					txtCodEmpleado->Clear();
					txtCodEmpleado->Focus();
				}
			}
			catch (Exception^) {
				txtIdTurno->Text = "1";
				txtSaldoInicial->Text = "0.00";
			}
		}
		void cargarTurnos() {
			dgvTurnos->Rows->Clear();
			try {
				TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
				List<TurnoCaja^>^ lista = turnoDao->buscarTodosArchivo();
				if (lista != nullptr) {
					for each (TurnoCaja ^ turno in lista) {
						String^ strSaldoFinal;
						String^ strHoraFinal;

						if (turno->getEstado() == "Cerrado") {
							strSaldoFinal = turno->getSaldoFinal().ToString("F2");
							strHoraFinal = turno->getFechaHoraSalida().ToString("yyyy-MM-dd HH:mm");
						}
						else {
							strSaldoFinal = "Turno activo";
							strHoraFinal = "Turno activo";
						}

						String^ codigoEmp = "N/A";
						if (turno->getEmpleado() != nullptr) {
							codigoEmp = turno->getEmpleado()->getCodigoEmpleado();
						}

						dgvTurnos->Rows->Add(
							turno->getIdTurno(),
							codigoEmp,
							turno->getSaldoInicial().ToString("F2"),
							turno->getFechaHoraIngreso().ToString("yyyy-MM-dd HH:mm"),
							strSaldoFinal,
							strHoraFinal
						);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar turnos: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			dgvTurnos->ClearSelection();
		}

		void cargarBalances() {
			dgvBalances->Rows->Clear();

			if (dgvBalances->Columns->Count < 5) {
				DataGridViewTextBoxColumn^ colResultado = gcnew DataGridViewTextBoxColumn();
				colResultado->Name = "colResultado";
				colResultado->HeaderText = "Monto Neto (S/)";
				colResultado->FillWeight = 80.0F;
				colResultado->ReadOnly = true;
				dgvBalances->Columns->Add(colResultado);
			}

			try {
				BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
				List<BalanceDiario^>^ listaBalances = balanceDao->buscarTodosArchivo();
				if (listaBalances != nullptr) {
					for each (BalanceDiario ^ b in listaBalances) {
						double saldoInicial = b->getTotalSaldoInicialTurnos();
						double saldoFinal = b->getTotalSaldoFinalTurnos();
						double diferencia = saldoFinal - saldoInicial; 

						int rowIndex = dgvBalances->Rows->Add(
							b->getFecha().ToString("dd/MM/yyyy"),
							b->getCantidadTurnos(),
							saldoInicial.ToString("F2"),
							saldoFinal.ToString("F2"),
							diferencia.ToString("F2")
						);

						DataGridViewRow^ row = dgvBalances->Rows[rowIndex];
						if (diferencia < 0) {
							row->Cells[4]->Style->BackColor = System::Drawing::Color::MistyRose;
							row->Cells[4]->Style->ForeColor = System::Drawing::Color::DarkRed;
							row->Cells[4]->ToolTipText = "Pérdida en el día";
						}
						else if (diferencia > 0) {
							row->Cells[4]->Style->BackColor = System::Drawing::Color::Honeydew;
							row->Cells[4]->Style->ForeColor = System::Drawing::Color::DarkGreen;
							row->Cells[4]->ToolTipText = "Ganancia en el día";
						}
						else {
							row->Cells[4]->Style->BackColor = System::Drawing::Color::White;
							row->Cells[4]->Style->ForeColor = System::Drawing::Color::Black;
							row->Cells[4]->ToolTipText = "Sin variación";
						}
					}
				}
			}
			catch (Exception^) {}
			dgvBalances->ClearSelection();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmBalances()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTitulo;
	protected:
	private: System::Windows::Forms::Panel^ pnlTitulo;
	private: System::Windows::Forms::DataGridView^ dgvTurnos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdTurno;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSaldoInicial;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCodigoEmpleado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHoraInicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSaldoFinal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHoraFinal;
	private: System::Windows::Forms::Button^ btnLimpiar1;

	private: System::Windows::Forms::Button^ btnIniciarTurno;

	private: System::Windows::Forms::GroupBox^ gbTurnosCaja;




	private: System::Windows::Forms::Label^ lblDescuentoMembresia;
	private: System::Windows::Forms::TextBox^ txtCodEmpleado;
	private: System::Windows::Forms::Label^ lblCodEmpleado;


	private: System::Windows::Forms::TextBox^ txtSaldoInicial;
	private: System::Windows::Forms::Label^ lblSaldoInicial;


	private: System::Windows::Forms::TextBox^ txtIdTurno;
	private: System::Windows::Forms::Label^ lblIdTurno;


	private: System::Windows::Forms::Panel^ pnlInfo;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Button^ btnTerminarTurno;
	private: System::Windows::Forms::TextBox^ txtObs;


	private: System::Windows::Forms::Label^ labelObs;
	private: System::Windows::Forms::TextBox^ txtSaldoFinal;

	private: System::Windows::Forms::Button^ btnCerrarCaja;

	private: System::Windows::Forms::Button^ btnCalBalance;

	private: System::Windows::Forms::DataGridView^ dgvBalances;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFechaBalance;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCantidadTurnos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSaldoInicialDia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSaldoFinalDia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colGanaciaDia;
	private: System::Windows::Forms::Button^ btnLimpiar2;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::GroupBox^ groupBoxBalances;
	private: System::Windows::Forms::Button^ button10;





	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		private: System::Windows::Forms::Form^ actual = nullptr;
		/*private: System::Void AbrirFormulario(System::Windows::Forms::Form^ hijo) {
			//Cerramos la ventana ya abierta si es q se desea abrir otra
			if (this->actual != nullptr) {
				this->actual->Close();
			}

			this->actual = hijo; //Actualizamos a la ventana actualmente abierta

			hijo->TopLevel = false; //Evitamos que se abra sobre el dashboard

			hijo->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; //Quitamos bordes a todas las ventanas emergentes

			hijo->Dock = System::Windows::Forms::DockStyle::Fill;

			this->pnlContenedor->Controls->Add(hijo); //Agnadimos en el panel contenedor la ventana emergente
			hijo->Show();
		}*/
		
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
			this->dgvTurnos = (gcnew System::Windows::Forms::DataGridView());
			this->colIdTurno = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCodigoEmpleado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colSaldoInicial = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colHoraInicio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colSaldoFinal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colHoraFinal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnLimpiar1 = (gcnew System::Windows::Forms::Button());
			this->btnIniciarTurno = (gcnew System::Windows::Forms::Button());
			this->gbTurnosCaja = (gcnew System::Windows::Forms::GroupBox());
			this->btnGestionarMov = (gcnew System::Windows::Forms::Button());
			this->btnLimpiar2 = (gcnew System::Windows::Forms::Button());
			this->btnCerrarCaja = (gcnew System::Windows::Forms::Button());
			this->btnCalBalance = (gcnew System::Windows::Forms::Button());
			this->txtSaldoFinal = (gcnew System::Windows::Forms::TextBox());
			this->labelObs = (gcnew System::Windows::Forms::Label());
			this->txtObs = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnTerminarTurno = (gcnew System::Windows::Forms::Button());
			this->lblDescuentoMembresia = (gcnew System::Windows::Forms::Label());
			this->txtCodEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->lblCodEmpleado = (gcnew System::Windows::Forms::Label());
			this->txtSaldoInicial = (gcnew System::Windows::Forms::TextBox());
			this->lblSaldoInicial = (gcnew System::Windows::Forms::Label());
			this->txtIdTurno = (gcnew System::Windows::Forms::TextBox());
			this->lblIdTurno = (gcnew System::Windows::Forms::Label());
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->groupBoxBalances = (gcnew System::Windows::Forms::GroupBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtBusqFecha = (gcnew System::Windows::Forms::TextBox());
			this->lblBuscarFechaBalance = (gcnew System::Windows::Forms::Label());
			this->dgvBalances = (gcnew System::Windows::Forms::DataGridView());
			this->colFechaBalance = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCantidadTurnos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colSaldoInicialDia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colSaldoFinalDia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colGanaciaDia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->btnGraficas = (gcnew System::Windows::Forms::Button());
			this->pnlTitulo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTurnos))->BeginInit();
			this->gbTurnosCaja->SuspendLayout();
			this->pnlInfo->SuspendLayout();
			this->groupBoxBalances->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBalances))->BeginInit();
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(9, 10);
			this->lblTitulo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(393, 32);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Balances del estacionamiento";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlTitulo
			// 
			this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlTitulo->Controls->Add(this->lblTitulo);
			this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitulo->Location = System::Drawing::Point(0, 0);
			this->pnlTitulo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pnlTitulo->Name = L"pnlTitulo";
			this->pnlTitulo->Size = System::Drawing::Size(1443, 53);
			this->pnlTitulo->TabIndex = 56;
			this->pnlTitulo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmBalances::pnlTitulo_Paint);
			// 
			// dgvTurnos
			// 
			this->dgvTurnos->AllowUserToAddRows = false;
			this->dgvTurnos->AllowUserToDeleteRows = false;
			this->dgvTurnos->AllowUserToResizeRows = false;
			this->dgvTurnos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle27->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle27->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle27->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle27->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle27->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle27->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvTurnos->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle27;
			this->dgvTurnos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTurnos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colIdTurno,
					this->colCodigoEmpleado, this->colSaldoInicial, this->colHoraInicio, this->colSaldoFinal, this->colHoraFinal
			});
			this->dgvTurnos->Location = System::Drawing::Point(16, 234);
			this->dgvTurnos->MultiSelect = false;
			this->dgvTurnos->Name = L"dgvTurnos";
			this->dgvTurnos->ReadOnly = true;
			dataGridViewCellStyle29->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle29->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle29->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle29->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle29->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle29->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvTurnos->RowHeadersDefaultCellStyle = dataGridViewCellStyle29;
			this->dgvTurnos->RowHeadersVisible = false;
			this->dgvTurnos->RowHeadersWidth = 51;
			this->dgvTurnos->RowTemplate->Height = 24;
			this->dgvTurnos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTurnos->Size = System::Drawing::Size(670, 203);
			this->dgvTurnos->TabIndex = 76;
			// 
			// colIdTurno
			// 
			this->colIdTurno->FillWeight = 34.10694F;
			this->colIdTurno->HeaderText = L"ID";
			this->colIdTurno->MinimumWidth = 6;
			this->colIdTurno->Name = L"colIdTurno";
			this->colIdTurno->ReadOnly = true;
			// 
			// colCodigoEmpleado
			// 
			this->colCodigoEmpleado->FillWeight = 85.9732F;
			this->colCodigoEmpleado->HeaderText = L"Codigo empleado";
			this->colCodigoEmpleado->MinimumWidth = 6;
			this->colCodigoEmpleado->Name = L"colCodigoEmpleado";
			this->colCodigoEmpleado->ReadOnly = true;
			// 
			// colSaldoInicial
			// 
			this->colSaldoInicial->FillWeight = 85.9732F;
			this->colSaldoInicial->HeaderText = L"Saldo Inicial (S/)";
			this->colSaldoInicial->MinimumWidth = 6;
			this->colSaldoInicial->Name = L"colSaldoInicial";
			this->colSaldoInicial->ReadOnly = true;
			// 
			// colHoraInicio
			// 
			this->colHoraInicio->FillWeight = 125.9732F;
			this->colHoraInicio->HeaderText = L"Hora de Inicio";
			this->colHoraInicio->MinimumWidth = 6;
			this->colHoraInicio->Name = L"colHoraInicio";
			this->colHoraInicio->ReadOnly = true;
			// 
			// colSaldoFinal
			// 
			this->colSaldoFinal->FillWeight = 85.9732F;
			this->colSaldoFinal->HeaderText = L"Saldo Final (S/)";
			this->colSaldoFinal->MinimumWidth = 6;
			this->colSaldoFinal->Name = L"colSaldoFinal";
			this->colSaldoFinal->ReadOnly = true;
			// 
			// colHoraFinal
			// 
			this->colHoraFinal->FillWeight = 125.9732F;
			this->colHoraFinal->HeaderText = L"Hora de Finalizacion";
			this->colHoraFinal->MinimumWidth = 6;
			this->colHoraFinal->Name = L"colHoraFinal";
			this->colHoraFinal->ReadOnly = true;
			// 
			// btnLimpiar1
			// 
			this->btnLimpiar1->AutoSize = true;
			this->btnLimpiar1->BackColor = System::Drawing::Color::Purple;
			this->btnLimpiar1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnLimpiar1->ForeColor = System::Drawing::Color::White;
			this->btnLimpiar1->Location = System::Drawing::Point(46, 168);
			this->btnLimpiar1->Name = L"btnLimpiar1";
			this->btnLimpiar1->Size = System::Drawing::Size(97, 36);
			this->btnLimpiar1->TabIndex = 75;
			this->btnLimpiar1->Text = L"Limpiar";
			this->btnLimpiar1->UseVisualStyleBackColor = false;
			this->btnLimpiar1->Click += gcnew System::EventHandler(this, &frmBalances::btnLimpiar1_Click);
			// 
			// btnIniciarTurno
			// 
			this->btnIniciarTurno->AutoSize = true;
			this->btnIniciarTurno->BackColor = System::Drawing::Color::LimeGreen;
			this->btnIniciarTurno->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnIniciarTurno->ForeColor = System::Drawing::Color::White;
			this->btnIniciarTurno->Location = System::Drawing::Point(176, 168);
			this->btnIniciarTurno->Name = L"btnIniciarTurno";
			this->btnIniciarTurno->Size = System::Drawing::Size(142, 36);
			this->btnIniciarTurno->TabIndex = 72;
			this->btnIniciarTurno->Text = L"Iniciar turno";
			this->btnIniciarTurno->UseVisualStyleBackColor = false;
			this->btnIniciarTurno->Click += gcnew System::EventHandler(this, &frmBalances::btnIniciarTurno_Click);
			// 
			// gbTurnosCaja
			// 
			this->gbTurnosCaja->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->gbTurnosCaja->Controls->Add(this->btnGestionarMov);
			this->gbTurnosCaja->Controls->Add(this->btnLimpiar2);
			this->gbTurnosCaja->Controls->Add(this->btnCerrarCaja);
			this->gbTurnosCaja->Controls->Add(this->btnCalBalance);
			this->gbTurnosCaja->Controls->Add(this->txtSaldoFinal);
			this->gbTurnosCaja->Controls->Add(this->labelObs);
			this->gbTurnosCaja->Controls->Add(this->txtObs);
			this->gbTurnosCaja->Controls->Add(this->label1);
			this->gbTurnosCaja->Controls->Add(this->btnTerminarTurno);
			this->gbTurnosCaja->Controls->Add(this->dgvTurnos);
			this->gbTurnosCaja->Controls->Add(this->btnLimpiar1);
			this->gbTurnosCaja->Controls->Add(this->btnIniciarTurno);
			this->gbTurnosCaja->Controls->Add(this->lblDescuentoMembresia);
			this->gbTurnosCaja->Controls->Add(this->txtCodEmpleado);
			this->gbTurnosCaja->Controls->Add(this->lblCodEmpleado);
			this->gbTurnosCaja->Controls->Add(this->txtSaldoInicial);
			this->gbTurnosCaja->Controls->Add(this->lblSaldoInicial);
			this->gbTurnosCaja->Controls->Add(this->txtIdTurno);
			this->gbTurnosCaja->Controls->Add(this->lblIdTurno);
			this->gbTurnosCaja->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbTurnosCaja->Location = System::Drawing::Point(9, 60);
			this->gbTurnosCaja->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->gbTurnosCaja->Name = L"gbTurnosCaja";
			this->gbTurnosCaja->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->gbTurnosCaja->Size = System::Drawing::Size(712, 524);
			this->gbTurnosCaja->TabIndex = 57;
			this->gbTurnosCaja->TabStop = false;
			this->gbTurnosCaja->Text = L"Turnos de caja ";
			// 
			// btnGestionarMov
			// 
			this->btnGestionarMov->AutoSize = true;
			this->btnGestionarMov->BackColor = System::Drawing::Color::RoyalBlue;
			this->btnGestionarMov->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnGestionarMov->ForeColor = System::Drawing::Color::White;
			this->btnGestionarMov->Location = System::Drawing::Point(418, 127);
			this->btnGestionarMov->Name = L"btnGestionarMov";
			this->btnGestionarMov->Size = System::Drawing::Size(256, 36);
			this->btnGestionarMov->TabIndex = 85;
			this->btnGestionarMov->Text = L"Gestionar Movimientos";
			this->btnGestionarMov->UseVisualStyleBackColor = false;
			this->btnGestionarMov->Click += gcnew System::EventHandler(this, &frmBalances::btnGestionarMov_Click);
			// 
			// btnLimpiar2
			// 
			this->btnLimpiar2->AutoSize = true;
			this->btnLimpiar2->BackColor = System::Drawing::Color::Purple;
			this->btnLimpiar2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnLimpiar2->ForeColor = System::Drawing::Color::White;
			this->btnLimpiar2->Location = System::Drawing::Point(397, 168);
			this->btnLimpiar2->Name = L"btnLimpiar2";
			this->btnLimpiar2->Size = System::Drawing::Size(97, 36);
			this->btnLimpiar2->TabIndex = 84;
			this->btnLimpiar2->Text = L"Limpiar";
			this->btnLimpiar2->UseVisualStyleBackColor = false;
			this->btnLimpiar2->Click += gcnew System::EventHandler(this, &frmBalances::btnLimpiar2_Click);
			// 
			// btnCerrarCaja
			// 
			this->btnCerrarCaja->AutoSize = true;
			this->btnCerrarCaja->BackColor = System::Drawing::Color::Crimson;
			this->btnCerrarCaja->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnCerrarCaja->ForeColor = System::Drawing::Color::White;
			this->btnCerrarCaja->Location = System::Drawing::Point(128, 462);
			this->btnCerrarCaja->Name = L"btnCerrarCaja";
			this->btnCerrarCaja->Size = System::Drawing::Size(169, 36);
			this->btnCerrarCaja->TabIndex = 83;
			this->btnCerrarCaja->Text = L"Cerrar caja";
			this->btnCerrarCaja->UseVisualStyleBackColor = false;
			this->btnCerrarCaja->Click += gcnew System::EventHandler(this, &frmBalances::btnCerrarCaja_Click);
			// 
			// btnCalBalance
			// 
			this->btnCalBalance->AutoSize = true;
			this->btnCalBalance->BackColor = System::Drawing::Color::Green;
			this->btnCalBalance->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnCalBalance->ForeColor = System::Drawing::Color::White;
			this->btnCalBalance->Location = System::Drawing::Point(388, 462);
			this->btnCalBalance->Name = L"btnCalBalance";
			this->btnCalBalance->Size = System::Drawing::Size(190, 36);
			this->btnCalBalance->TabIndex = 82;
			this->btnCalBalance->Text = L"Calcular balance";
			this->btnCalBalance->UseVisualStyleBackColor = false;
			this->btnCalBalance->Click += gcnew System::EventHandler(this, &frmBalances::btnCalBalance_Click);
			// 
			// txtSaldoFinal
			// 
			this->txtSaldoFinal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtSaldoFinal->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSaldoFinal->Location = System::Drawing::Point(542, 32);
			this->txtSaldoFinal->Name = L"txtSaldoFinal";
			this->txtSaldoFinal->ReadOnly = true;
			this->txtSaldoFinal->Size = System::Drawing::Size(155, 35);
			this->txtSaldoFinal->TabIndex = 81;
			// 
			// labelObs
			// 
			this->labelObs->AutoSize = true;
			this->labelObs->BackColor = System::Drawing::Color::White;
			this->labelObs->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelObs->Location = System::Drawing::Point(367, 75);
			this->labelObs->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelObs->Name = L"labelObs";
			this->labelObs->Size = System::Drawing::Size(169, 26);
			this->labelObs->TabIndex = 80;
			this->labelObs->Text = L"Observaciones:";
			this->labelObs->Click += gcnew System::EventHandler(this, &frmBalances::label2_Click);
			// 
			// txtObs
			// 
			this->txtObs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtObs->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtObs->Location = System::Drawing::Point(542, 75);
			this->txtObs->Name = L"txtObs";
			this->txtObs->Size = System::Drawing::Size(155, 35);
			this->txtObs->TabIndex = 79;
			this->txtObs->TextChanged += gcnew System::EventHandler(this, &frmBalances::txtSaldoFinal_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(370, 36);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 26);
			this->label1->TabIndex = 78;
			this->label1->Text = L"Saldo final:";
			this->label1->Click += gcnew System::EventHandler(this, &frmBalances::label1_Click);
			// 
			// btnTerminarTurno
			// 
			this->btnTerminarTurno->AutoSize = true;
			this->btnTerminarTurno->BackColor = System::Drawing::Color::Red;
			this->btnTerminarTurno->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnTerminarTurno->ForeColor = System::Drawing::Color::White;
			this->btnTerminarTurno->Location = System::Drawing::Point(518, 168);
			this->btnTerminarTurno->Name = L"btnTerminarTurno";
			this->btnTerminarTurno->Size = System::Drawing::Size(172, 36);
			this->btnTerminarTurno->TabIndex = 77;
			this->btnTerminarTurno->Text = L"Terminar turno";
			this->btnTerminarTurno->UseVisualStyleBackColor = false;
			this->btnTerminarTurno->Click += gcnew System::EventHandler(this, &frmBalances::btnTerminarTurno_Click);
			// 
			// lblDescuentoMembresia
			// 
			this->lblDescuentoMembresia->AutoSize = true;
			this->lblDescuentoMembresia->BackColor = System::Drawing::Color::White;
			this->lblDescuentoMembresia->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDescuentoMembresia->Location = System::Drawing::Point(6, 160);
			this->lblDescuentoMembresia->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblDescuentoMembresia->Name = L"lblDescuentoMembresia";
			this->lblDescuentoMembresia->Size = System::Drawing::Size(0, 26);
			this->lblDescuentoMembresia->TabIndex = 67;
			// 
			// txtCodEmpleado
			// 
			this->txtCodEmpleado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCodEmpleado->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCodEmpleado->Location = System::Drawing::Point(208, 115);
			this->txtCodEmpleado->Name = L"txtCodEmpleado";
			this->txtCodEmpleado->Size = System::Drawing::Size(149, 35);
			this->txtCodEmpleado->TabIndex = 66;
			// 
			// lblCodEmpleado
			// 
			this->lblCodEmpleado->AutoSize = true;
			this->lblCodEmpleado->BackColor = System::Drawing::Color::White;
			this->lblCodEmpleado->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCodEmpleado->Location = System::Drawing::Point(6, 119);
			this->lblCodEmpleado->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCodEmpleado->Name = L"lblCodEmpleado";
			this->lblCodEmpleado->Size = System::Drawing::Size(201, 26);
			this->lblCodEmpleado->TabIndex = 65;
			this->lblCodEmpleado->Text = L"Codigo empleado:";
			// 
			// txtSaldoInicial
			// 
			this->txtSaldoInicial->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtSaldoInicial->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSaldoInicial->Location = System::Drawing::Point(208, 75);
			this->txtSaldoInicial->Name = L"txtSaldoInicial";
			this->txtSaldoInicial->Size = System::Drawing::Size(149, 35);
			this->txtSaldoInicial->TabIndex = 64;
			// 
			// lblSaldoInicial
			// 
			this->lblSaldoInicial->AutoSize = true;
			this->lblSaldoInicial->BackColor = System::Drawing::Color::White;
			this->lblSaldoInicial->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblSaldoInicial->Location = System::Drawing::Point(6, 79);
			this->lblSaldoInicial->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblSaldoInicial->Name = L"lblSaldoInicial";
			this->lblSaldoInicial->Size = System::Drawing::Size(141, 26);
			this->lblSaldoInicial->TabIndex = 63;
			this->lblSaldoInicial->Text = L"Saldo inicial:";
			// 
			// txtIdTurno
			// 
			this->txtIdTurno->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdTurno->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIdTurno->Location = System::Drawing::Point(208, 32);
			this->txtIdTurno->Name = L"txtIdTurno";
			this->txtIdTurno->ReadOnly = true;
			this->txtIdTurno->Size = System::Drawing::Size(149, 35);
			this->txtIdTurno->TabIndex = 62;
			// 
			// lblIdTurno
			// 
			this->lblIdTurno->AutoSize = true;
			this->lblIdTurno->BackColor = System::Drawing::Color::White;
			this->lblIdTurno->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIdTurno->Location = System::Drawing::Point(6, 38);
			this->lblIdTurno->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblIdTurno->Name = L"lblIdTurno";
			this->lblIdTurno->Size = System::Drawing::Size(108, 26);
			this->lblIdTurno->TabIndex = 61;
			this->lblIdTurno->Text = L"ID Turno:";
			// 
			// pnlInfo
			// 
			this->pnlInfo->AutoScroll = true;
			this->pnlInfo->BackColor = System::Drawing::Color::White;
			this->pnlInfo->Controls->Add(this->btnGraficas);
			this->pnlInfo->Controls->Add(this->gbTurnosCaja);
			this->pnlInfo->Controls->Add(this->pnlTitulo);
			this->pnlInfo->Controls->Add(this->groupBoxBalances);
			this->pnlInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlInfo->Location = System::Drawing::Point(0, 0);
			this->pnlInfo->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(1443, 857);
			this->pnlInfo->TabIndex = 15;
			// 
			// groupBoxBalances
			// 
			this->groupBoxBalances->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBoxBalances->Controls->Add(this->btnBuscar);
			this->groupBoxBalances->Controls->Add(this->txtBusqFecha);
			this->groupBoxBalances->Controls->Add(this->lblBuscarFechaBalance);
			this->groupBoxBalances->Controls->Add(this->dgvBalances);
			this->groupBoxBalances->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->groupBoxBalances->Location = System::Drawing::Point(732, 60);
			this->groupBoxBalances->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBoxBalances->Name = L"groupBoxBalances";
			this->groupBoxBalances->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBoxBalances->Size = System::Drawing::Size(584, 524);
			this->groupBoxBalances->TabIndex = 57;
			this->groupBoxBalances->TabStop = false;
			this->groupBoxBalances->Text = L"Balances ";
			// 
			// btnBuscar
			// 
			this->btnBuscar->AutoSize = true;
			this->btnBuscar->BackColor = System::Drawing::Color::DarkOrchid;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(426, 35);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(96, 36);
			this->btnBuscar->TabIndex = 86;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmBalances::btnBuscar_Click);
			// 
			// txtBusqFecha
			// 
			this->txtBusqFecha->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtBusqFecha->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBusqFecha->Location = System::Drawing::Point(238, 34);
			this->txtBusqFecha->Name = L"txtBusqFecha";
			this->txtBusqFecha->Size = System::Drawing::Size(155, 35);
			this->txtBusqFecha->TabIndex = 86;
			// 
			// lblBuscarFechaBalance
			// 
			this->lblBuscarFechaBalance->AutoSize = true;
			this->lblBuscarFechaBalance->BackColor = System::Drawing::Color::White;
			this->lblBuscarFechaBalance->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBuscarFechaBalance->Location = System::Drawing::Point(44, 36);
			this->lblBuscarFechaBalance->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblBuscarFechaBalance->Name = L"lblBuscarFechaBalance";
			this->lblBuscarFechaBalance->Size = System::Drawing::Size(191, 26);
			this->lblBuscarFechaBalance->TabIndex = 85;
			this->lblBuscarFechaBalance->Text = L"Buscar por fecha:";
			// 
			// dgvBalances
			// 
			this->dgvBalances->AllowUserToAddRows = false;
			this->dgvBalances->AllowUserToDeleteRows = false;
			this->dgvBalances->AllowUserToResizeRows = false;
			this->dgvBalances->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle30->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			dataGridViewCellStyle30->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle30->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle30->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle30->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvBalances->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle30;
			this->dgvBalances->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBalances->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colFechaBalance,
					this->colCantidadTurnos, this->colSaldoInicialDia, this->colSaldoFinalDia, this->colGanaciaDia
			});
			this->dgvBalances->Location = System::Drawing::Point(23, 102);
			this->dgvBalances->MultiSelect = false;
			this->dgvBalances->Name = L"dgvBalances";
			this->dgvBalances->ReadOnly = true;
			dataGridViewCellStyle31->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle31->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			dataGridViewCellStyle31->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle31->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle31->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle31->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvBalances->RowHeadersDefaultCellStyle = dataGridViewCellStyle31;
			this->dgvBalances->RowHeadersVisible = false;
			this->dgvBalances->RowHeadersWidth = 51;
			this->dgvBalances->RowTemplate->Height = 24;
			this->dgvBalances->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvBalances->Size = System::Drawing::Size(535, 396);
			this->dgvBalances->TabIndex = 84;
			// 
			// colFechaBalance
			// 
			this->colFechaBalance->FillWeight = 60.10694F;
			this->colFechaBalance->HeaderText = L"Fecha";
			this->colFechaBalance->MinimumWidth = 6;
			this->colFechaBalance->Name = L"colFechaBalance";
			this->colFechaBalance->ReadOnly = true;
			// 
			// colCantidadTurnos
			// 
			this->colCantidadTurnos->FillWeight = 48.9832F;
			this->colCantidadTurnos->HeaderText = L"Cantidad turnos";
			this->colCantidadTurnos->MinimumWidth = 6;
			this->colCantidadTurnos->Name = L"colCantidadTurnos";
			this->colCantidadTurnos->ReadOnly = true;
			// 
			// colSaldoInicialDia
			// 
			this->colSaldoInicialDia->FillWeight = 70.9732F;
			this->colSaldoInicialDia->HeaderText = L"Saldo inicial del dia  (S/)";
			this->colSaldoInicialDia->MinimumWidth = 6;
			this->colSaldoInicialDia->Name = L"colSaldoInicialDia";
			this->colSaldoInicialDia->ReadOnly = true;
			// 
			// colSaldoFinalDia
			// 
			this->colSaldoFinalDia->FillWeight = 70.9732F;
			this->colSaldoFinalDia->HeaderText = L"Saldo final del dia (S/)";
			this->colSaldoFinalDia->MinimumWidth = 6;
			this->colSaldoFinalDia->Name = L"colSaldoFinalDia";
			this->colSaldoFinalDia->ReadOnly = true;
			// 
			// colGanaciaDia
			// 
			this->colGanaciaDia->FillWeight = 90.9732F;
			this->colGanaciaDia->HeaderText = L"Ganancia del dia (S/)";
			this->colGanaciaDia->MinimumWidth = 6;
			this->colGanaciaDia->Name = L"colGanaciaDia";
			this->colGanaciaDia->ReadOnly = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(612, 209);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 43);
			this->button2->TabIndex = 84;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->AutoSize = true;
			this->button3->BackColor = System::Drawing::Color::Crimson;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(394, 559);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(225, 43);
			this->button3->TabIndex = 83;
			this->button3->Text = L"Cerrar caja";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// button4
			// 
			this->button4->AutoSize = true;
			this->button4->BackColor = System::Drawing::Color::MediumAquamarine;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(688, 559);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(251, 43);
			this->button4->TabIndex = 82;
			this->button4->Text = L"Calcular balance";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(806, 39);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(205, 35);
			this->textBox1->TabIndex = 81;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(577, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(211, 34);
			this->label2->TabIndex = 80;
			this->label2->Text = L"Observaciones:";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(806, 91);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(205, 35);
			this->textBox2->TabIndex = 79;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(577, 44);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 34);
			this->label3->TabIndex = 78;
			this->label3->Text = L"Saldo final:";
			// 
			// button5
			// 
			this->button5->AutoSize = true;
			this->button5->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(764, 209);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(225, 43);
			this->button5->TabIndex = 77;
			this->button5->Text = L"Terminar turno";
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->AutoSize = true;
			this->button6->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(27, 209);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(128, 43);
			this->button6->TabIndex = 75;
			this->button6->Text = L"Limpiar";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->AutoSize = true;
			this->button7->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Location = System::Drawing::Point(166, 559);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(152, 43);
			this->button7->TabIndex = 73;
			this->button7->Text = L"Modificar";
			this->button7->UseVisualStyleBackColor = false;
			// 
			// button8
			// 
			this->button8->AutoSize = true;
			this->button8->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Location = System::Drawing::Point(193, 209);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(188, 43);
			this->button8->TabIndex = 72;
			this->button8->Text = L"Iniciar turno";
			this->button8->UseVisualStyleBackColor = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(16, 199);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 34);
			this->label4->TabIndex = 67;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(277, 144);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(205, 35);
			this->textBox3->TabIndex = 66;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(16, 149);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(254, 34);
			this->label5->TabIndex = 65;
			this->label5->Text = L"Codigo empleado:";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(277, 94);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(205, 35);
			this->textBox4->TabIndex = 64;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(16, 99);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(181, 34);
			this->label6->TabIndex = 63;
			this->label6->Text = L"Saldo inicial:";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(277, 41);
			this->textBox5->Margin = System::Windows::Forms::Padding(4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(205, 35);
			this->textBox5->TabIndex = 62;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(16, 49);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(139, 34);
			this->label7->TabIndex = 61;
			this->label7->Text = L"ID Turno:";
			// 
			// button9
			// 
			this->button9->AutoSize = true;
			this->button9->BackColor = System::Drawing::Color::Red;
			this->button9->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Location = System::Drawing::Point(816, 209);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(138, 43);
			this->button9->TabIndex = 74;
			this->button9->UseVisualStyleBackColor = false;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(164, 417);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 85;
			this->button10->Text = L"button10";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// btnGraficas
			// 
			this->btnGraficas->AutoSize = true;
			this->btnGraficas->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnGraficas->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGraficas->ForeColor = System::Drawing::Color::White;
			this->btnGraficas->Location = System::Drawing::Point(918, 589);
			this->btnGraficas->Name = L"btnGraficas";
			this->btnGraficas->Size = System::Drawing::Size(207, 36);
			this->btnGraficas->TabIndex = 85;
			this->btnGraficas->Text = L"Graficas Balances";
			this->btnGraficas->UseVisualStyleBackColor = false;
			this->btnGraficas->Click += gcnew System::EventHandler(this, &frmBalances::btnGraficas_Click);
			// 
			// frmBalances
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1443, 857);
			this->Controls->Add(this->pnlInfo);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"frmBalances";
			this->Text = L"frmBalances";
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTurnos))->EndInit();
			this->gbTurnosCaja->ResumeLayout(false);
			this->gbTurnosCaja->PerformLayout();
			this->pnlInfo->ResumeLayout(false);
			this->pnlInfo->PerformLayout();
			this->groupBoxBalances->ResumeLayout(false);
			this->groupBoxBalances->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBalances))->EndInit();
			this->ResumeLayout(false);

		}
		#pragma endregion
		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void txtSaldoFinal_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void pnlTitulo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
	
	private: System::Void btnIniciarTurno_Click(System::Object^ sender, System::EventArgs^ e) {
		try {

			if (cajaCerrada) {
				MessageBox::Show("La caja se encuentra CERRADA. Debe calcular el balance diario antes de iniciar nuevos turnos.", "Acción denegada", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ codEmpleado = txtCodEmpleado->Text->Trim();
			if (String::IsNullOrWhiteSpace(codEmpleado)) {
				MessageBox::Show("Debe ingresar el código del empleado para iniciar el turno.", "Datos insuficientes", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				txtCodEmpleado->Focus();
				return;
			}

			TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
			List<TurnoCaja^>^ lista = turnoDao->buscarTodosArchivo();
			if (lista != nullptr) {
				for each (TurnoCaja ^ t in lista) {
					if (t->getEstado() != "Cerrado") {
						MessageBox::Show("Ya existe un turno activo (ID: " + t->getIdTurno() + "). Debe terminarlo antes de iniciar uno nuevo.", "Restricción", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
				}
			}

			int idTurno = Convert::ToInt32(txtIdTurno->Text);
			double saldoInicial = Convert::ToDouble(txtSaldoInicial->Text);

			Empleado^ empleadoAsignado = nullptr;
			try {
				EmpleadoDAO^ empDao = gcnew EmpleadoDAO();
				empleadoAsignado = empDao->buscarxCodigoArchivo(codEmpleado);
			}
			catch (...) {}

			if (empleadoAsignado == nullptr) {
				MessageBox::Show("El código de empleado ingresado no existe en el sistema.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				txtCodEmpleado->Focus();
				return;
			}

			TurnoCaja^ nuevoTurno = gcnew TurnoCaja();
			nuevoTurno->setIdTurno(idTurno);
			nuevoTurno->setFechaHoraIngreso(DateTime::Now);
			nuevoTurno->setSaldoInicial(saldoInicial);
			nuevoTurno->setSaldoFinal(saldoInicial);
			nuevoTurno->setEstado("Abierto");
			nuevoTurno->setEmpleado(empleadoAsignado);
			nuevoTurno->setListaMovimientos(gcnew List<Movimiento^>());

			turnoDao->registrarTurnoArchivo(nuevoTurno);

			MessageBox::Show("¡Turno iniciado con éxito!", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			cargarTurnos();
			prepararCamposNuevoTurno();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al iniciar turno: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	
	private: System::Void btnTerminarTurno_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
			List<TurnoCaja^>^ lista = turnoDao->buscarTodosArchivo();
			TurnoCaja^ turnoActivo = nullptr;

			if (lista != nullptr) {
				for each (TurnoCaja ^ t in lista) {
					if (t->getEstado() != "Cerrado") {
						turnoActivo = t;
						break;
					}
				}
			}

			if (turnoActivo == nullptr) {
				MessageBox::Show("No hay ningún turno activo para terminar.", "Datos insuficientes", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			DateTime horaSalida = DateTime::Now;

			double saldoFinalCalculado = turnoActivo->getSaldoInicial();

			MovimientoDAO^ movDao = gcnew MovimientoDAO();
			List<Movimiento^>^ todosLosMovimientos = movDao->buscarTodosArchivo();

			if (todosLosMovimientos != nullptr) {
				for each (Movimiento ^ mov in todosLosMovimientos) {
					if (!mov->getAnulada() && mov->getFechaHoraMovimento() >= turnoActivo->getFechaHoraIngreso() && mov->getFechaHoraMovimento() <= horaSalida) {

						double montoMov = mov->getMonto();
						String^ tipo = mov->getTipoMovimiento();

						if (tipo != nullptr && (tipo->Equals("Reparación", StringComparison::OrdinalIgnoreCase) || tipo->Equals("Reembolso", StringComparison::OrdinalIgnoreCase))) {
							saldoFinalCalculado -= Math::Abs(montoMov); 
						}
						else {
							saldoFinalCalculado += montoMov; 
						}
					}
				}
			}

			turnoActivo->setFechaHoraSalida(horaSalida);
			turnoActivo->setSaldoFinal(saldoFinalCalculado);
			turnoActivo->setEstado("Cerrado");

			if (txtObs != nullptr && !String::IsNullOrEmpty(txtObs->Text)) {
				turnoActivo->setObservacion(txtObs->Text->Trim());
			}

			turnoDao->modificarTurnoArchivo(turnoActivo);

			if (txtSaldoFinal != nullptr) {
				txtSaldoFinal->Text = saldoFinalCalculado.ToString("F2");
			}

			MessageBox::Show("Turno finalizado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			cargarTurnos();
			prepararCamposNuevoTurno();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al terminar turno: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnCerrarCaja_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
			List<TurnoCaja^>^ lista = turnoDao->buscarTodosArchivo();

			if (lista != nullptr) {
				for each (TurnoCaja ^ t in lista) {
					if (t->getEstado() != "Cerrado") {
						MessageBox::Show("No se puede cerrar la caja porque todavía hay un turno activo (ID: " + t->getIdTurno() + "). Debe terminarlo antes.", "Acción denegada", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
				}
			}

			bool existenTurnosCerradosPendientes = false;

			if (lista != nullptr) {
				for each (TurnoCaja ^ t in lista) {
					if (t->getIdTurno() > ultimoIdTurnoInscritoEnBalance && t->getEstado() == "Cerrado") {
						existenTurnosCerradosPendientes = true;
						break;
					}
				}
			}

			if (!existenTurnosCerradosPendientes) {
				MessageBox::Show("No hay turnos cerrados nuevos pendientes de balance.", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			cajaCerrada = true;
			MessageBox::Show("Caja cerrada exitosamente. Ya puede proceder a calcular el balance.", "Cierre de Caja", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al cerrar caja: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnCalBalance_Click(System::Object^ sender, System::EventArgs^ e) {
		try {

			if (!cajaCerrada) {
				MessageBox::Show("Debe ejecutar el 'Cierre de caja' antes de calcular el balance diario.", "Acción Requerida", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
			List<TurnoCaja^>^ todosLosTurnos = turnoDao->buscarTodosArchivo();
			List<TurnoCaja^>^ turnosParaBalance = gcnew List<TurnoCaja^>();

			if (todosLosTurnos != nullptr) {
				for each (TurnoCaja ^ t in todosLosTurnos) {
					if (t->getIdTurno() > ultimoIdTurnoInscritoEnBalance && t->getEstado() == "Cerrado") {
						turnosParaBalance->Add(t);
					}
				}
			}

			if (turnosParaBalance->Count == 0) {
				MessageBox::Show("No hay turnos disponibles para este balance.", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			TurnoCaja^ primerTurno = turnosParaBalance[0];
			TurnoCaja^ ultimoTurno = turnosParaBalance[turnosParaBalance->Count - 1];

			double saldoInicialDia = primerTurno->getSaldoInicial();
			double saldoFinalDia = ultimoTurno->getSaldoFinal();
			int cantidadTurnos = turnosParaBalance->Count;
			DateTime fechaBalance = DateTime::Now.Date; 

			BalanceDiario^ nuevoBalance = gcnew BalanceDiario();
			nuevoBalance->setFecha(fechaBalance);
			nuevoBalance->setCantidadTurnos(cantidadTurnos);
			nuevoBalance->setTotalSaldoInicialTurnos(saldoInicialDia);
			nuevoBalance->setTotalSaldoFinalTurnos(saldoFinalDia);

			BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
			balanceDao->registrarBalanceArchivo(nuevoBalance);

			ultimoIdTurnoInscritoEnBalance = ultimoTurno->getIdTurno();
			cajaCerrada = false;

			MessageBox::Show("¡Balance diario calculado y registrado exitosamente!", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			cargarBalances();
			prepararCamposNuevoTurno();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al calcular balance: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void btnLimpiar1_Click(System::Object^ sender, System::EventArgs^ e) {
		txtCodEmpleado->Clear();
		txtCodEmpleado->Focus();
	}

	private: System::Void btnLimpiar2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtObs != nullptr) txtObs->Clear();
		if (txtSaldoFinal != nullptr) txtSaldoFinal->Clear();
		txtCodEmpleado->Focus();
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (txtBusqFecha == nullptr || String::IsNullOrWhiteSpace(txtBusqFecha->Text)) {
				MessageBox::Show("Debe ingresar una fecha válida para realizar la búsqueda.", "Datos insuficientes", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				if (txtBusqFecha != nullptr) {
					txtBusqFecha->Clear();
					txtBusqFecha->Focus();
				}
				return;
			}

			String^ textoFecha = txtBusqFecha->Text->Trim();
			DateTime fechaBusqueda;

			if (!DateTime::TryParse(textoFecha, fechaBusqueda)) {
				MessageBox::Show("El formato de fecha ingresado no es válido. Por favor, utilice un formato correcto (Ej: DD/MM/YYYY o YYYY-MM-DD).", "Datos inválidos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				txtBusqFecha->Focus();
				txtBusqFecha->SelectAll();
				return;
			}

			dgvBalances->Rows->Clear();
			BalanceDiarioDAO^ balanceDao = gcnew BalanceDiarioDAO();
			BalanceDiario^ b = balanceDao->buscarPorFechaArchivo(fechaBusqueda.Date);

			if (b != nullptr) {
				double saldoInicial = b->getTotalSaldoInicialTurnos();
				double saldoFinal = b->getTotalSaldoFinalTurnos();
				double diferencia = saldoFinal - saldoInicial;

				int rowIndex = dgvBalances->Rows->Add(
					b->getFecha().ToString("dd/MM/yyyy"),
					b->getCantidadTurnos(),
					saldoInicial.ToString("F2"),
					saldoFinal.ToString("F2"),
					diferencia.ToString("F2")
				);

				DataGridViewRow^ row = dgvBalances->Rows[rowIndex];
				if (diferencia < 0) {
					row->Cells[4]->Style->BackColor = System::Drawing::Color::MistyRose;
					row->Cells[4]->Style->ForeColor = System::Drawing::Color::DarkRed;
					row->Cells[4]->ToolTipText = "Pérdida en el día";
				}
				else if (diferencia > 0) {
					row->Cells[4]->Style->BackColor = System::Drawing::Color::Honeydew;
					row->Cells[4]->Style->ForeColor = System::Drawing::Color::DarkGreen;
					row->Cells[4]->ToolTipText = "Ganancia en el día";
				}
				else {
					row->Cells[4]->Style->BackColor = System::Drawing::Color::White;
					row->Cells[4]->Style->ForeColor = System::Drawing::Color::Black;
					row->Cells[4]->ToolTipText = "Sin variación";
				}
			}
			else {
				MessageBox::Show("No se encontró ningún balance registrado para la fecha especificada.", "Sin resultados", MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarBalances();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al buscar el balance: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		dgvBalances->ClearSelection();
	}
	private: System::Void btnGestionarMov_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			TurnoCajaDAO^ turnoDao = gcnew TurnoCajaDAO();
			List<TurnoCaja^>^ lista = turnoDao->buscarTodosArchivo();
			TurnoCaja^ turnoActivo = nullptr;

			if (lista != nullptr) {
				for each (TurnoCaja ^ t in lista) {
					if (t->getEstado() != "Cerrado") {
						turnoActivo = t;
						break;
					}
				}
			}

			if (turnoActivo == nullptr) {
				MessageBox::Show("Debe iniciar un turno activo antes de gestionar o registrar movimientos de caja.", "Turno requerido", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			frmGestionarMovimientos^ ventanaMovimientos = gcnew frmGestionarMovimientos();
			ventanaMovimientos->ShowDialog(); 

			cargarTurnos();
			prepararCamposNuevoTurno();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al abrir la gestión de movimientos: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnGraficas_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//this->AbrirFormulario(gcnew frmGraficasBalances);
	    
		// Crea el formulario para registrar una nueva suscripción.
		frmGraficasBalances^ formularioGraficas =
			gcnew frmGraficasBalances();

		// Abre el formulario como ventana modal.
		System::Windows::Forms::DialogResult resultado =
			formularioGraficas->ShowDialog();

		
	
	}

	
};
}
