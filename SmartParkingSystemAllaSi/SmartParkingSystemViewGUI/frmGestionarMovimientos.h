#pragma once

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemDAO;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmGestionarMovimientos
	/// </summary>
	public ref class frmGestionarMovimientos : public System::Windows::Forms::Form
	{
	public:
		frmGestionarMovimientos(void)
		{
			InitializeComponent();

			movimientoController = gcnew MovimientoController();

			if (cmbBxEstado->Items->Count > 0) {
				cmbBxEstado->SelectedIndex = 1; 
			}

			sugerirIdMovimiento();
			cargarMovimientos();

			this->dgvMovimientos->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmGestionarMovimientos::dgvMovimientos_CellClick);
		}
	private:
		MovimientoController^ movimientoController;

		void sugerirIdMovimiento() {
			try {
				List<Movimiento^>^ lista = movimientoController->buscarTodosArchivo();
				int siguienteId = 1;
				if (lista != nullptr && lista->Count > 0) {
					int maxId = 0;
					for each (Movimiento ^ m in lista) {
						if (m->getIdMovimiento() > maxId) maxId = m->getIdMovimiento();
					}
					siguienteId = maxId + 1;
				}
				txtIdMov->Text = siguienteId.ToString();
			}
			catch (Exception^) {
				txtIdMov->Text = "1";
			}
		}

		void cargarMovimientos() {
			dgvMovimientos->Rows->Clear();
			try {
				List<Movimiento^>^ lista = movimientoController->buscarTodosArchivo();
				if (lista != nullptr) {
					for each (Movimiento ^ m in lista) {
						String^ estadoStr = m->getAnulada() ? "Anulada" : "Activa";
						dgvMovimientos->Rows->Add(
							m->getIdMovimiento(),
							m->getMonto().ToString("F2"),
							m->getTipoMovimiento(),
							estadoStr,
							m->getFechaHoraMovimento().ToString("yyyy-MM-dd HH:mm"),
							m->getDescripcion()
						);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar movimientos: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			dgvMovimientos->ClearSelection();
		}

		void limpiarCampos() {
			txtMonto->Clear();
			txtDescripcion->Clear();
			if (cmbBxTipoMov->Items->Count > 0) cmbBxTipoMov->SelectedIndex = -1;
			if (cmbBxEstado->Items->Count > 1) cmbBxEstado->SelectedIndex = 1; 
			sugerirIdMovimiento();
			txtMonto->Focus();
			dgvMovimientos->ClearSelection();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmGestionarMovimientos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblTitulo;
	protected:
	private: System::Windows::Forms::Panel^ pnlTitulo;
	private: System::Windows::Forms::DataGridView^ dgvMovimientos;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdMov;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colMonto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipoMov;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDescripcion;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Button^ btnBuscar;

	private: System::Windows::Forms::Button^ btnModificar;
	private: System::Windows::Forms::GroupBox^ gbDatosMovimiento;

	private: System::Windows::Forms::Button^ btnRegistrar;
	private: System::Windows::Forms::Label^ lblPenalizacionTicket;
	private: System::Windows::Forms::TextBox^ txtDescripcion;
	private: System::Windows::Forms::Label^ lblDescripcion;



	private: System::Windows::Forms::Label^ lblEstado;

	private: System::Windows::Forms::TextBox^ txtMonto;

	private: System::Windows::Forms::Label^ lblMonto;

	private: System::Windows::Forms::TextBox^ txtIdMov;

	private: System::Windows::Forms::Label^ lblIdMov;

	private: System::Windows::Forms::Panel^ pnlInfo;
	private: System::Windows::Forms::ComboBox^ cmbBxEstado;
	private: System::Windows::Forms::ComboBox^ cmbBxTipoMov;
	private: System::Windows::Forms::TextBox^ txtBusqueda;
	private: System::Windows::Forms::Label^ lblBusqueda;

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
		void InitializeComponent(void)
		{
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
			this->dgvMovimientos = (gcnew System::Windows::Forms::DataGridView());
			this->colIdMov = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMonto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipoMov = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDescripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->gbDatosMovimiento = (gcnew System::Windows::Forms::GroupBox());
			this->txtBusqueda = (gcnew System::Windows::Forms::TextBox());
			this->lblBusqueda = (gcnew System::Windows::Forms::Label());
			this->cmbBxEstado = (gcnew System::Windows::Forms::ComboBox());
			this->cmbBxTipoMov = (gcnew System::Windows::Forms::ComboBox());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->lblPenalizacionTicket = (gcnew System::Windows::Forms::Label());
			this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());
			this->lblDescripcion = (gcnew System::Windows::Forms::Label());
			this->lblEstado = (gcnew System::Windows::Forms::Label());
			this->txtMonto = (gcnew System::Windows::Forms::TextBox());
			this->lblMonto = (gcnew System::Windows::Forms::Label());
			this->txtIdMov = (gcnew System::Windows::Forms::TextBox());
			this->lblIdMov = (gcnew System::Windows::Forms::Label());
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->pnlTitulo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMovimientos))->BeginInit();
			this->gbDatosMovimiento->SuspendLayout();
			this->pnlInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Gadugi", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(12, 12);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(521, 40);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Registrar y evaluar Movimientos";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlTitulo
			// 
			this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlTitulo->Controls->Add(this->lblTitulo);
			this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitulo->Location = System::Drawing::Point(0, 0);
			this->pnlTitulo->Name = L"pnlTitulo";
			this->pnlTitulo->Size = System::Drawing::Size(1164, 65);
			this->pnlTitulo->TabIndex = 56;
			// 
			// dgvMovimientos
			// 
			this->dgvMovimientos->AllowUserToAddRows = false;
			this->dgvMovimientos->AllowUserToDeleteRows = false;
			this->dgvMovimientos->AllowUserToResizeRows = false;
			this->dgvMovimientos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvMovimientos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvMovimientos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colIdMov,
					this->colMonto, this->colTipoMov, this->colEstado, this->colFecha, this->colDescripcion
			});
			this->dgvMovimientos->Location = System::Drawing::Point(78, 452);
			this->dgvMovimientos->Margin = System::Windows::Forms::Padding(4);
			this->dgvMovimientos->MultiSelect = false;
			this->dgvMovimientos->Name = L"dgvMovimientos";
			this->dgvMovimientos->ReadOnly = true;
			this->dgvMovimientos->RowHeadersVisible = false;
			this->dgvMovimientos->RowHeadersWidth = 51;
			this->dgvMovimientos->RowTemplate->Height = 24;
			this->dgvMovimientos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvMovimientos->Size = System::Drawing::Size(985, 275);
			this->dgvMovimientos->TabIndex = 76;
			// 
			// colIdMov
			// 
			this->colIdMov->FillWeight = 35.10694F;
			this->colIdMov->HeaderText = L"ID";
			this->colIdMov->MinimumWidth = 6;
			this->colIdMov->Name = L"colIdMov";
			this->colIdMov->ReadOnly = true;
			// 
			// colMonto
			// 
			this->colMonto->FillWeight = 100.9732F;
			this->colMonto->HeaderText = L"Monto (S/)";
			this->colMonto->MinimumWidth = 6;
			this->colMonto->Name = L"colMonto";
			this->colMonto->ReadOnly = true;
			// 
			// colTipoMov
			// 
			this->colTipoMov->FillWeight = 75.9732F;
			this->colTipoMov->HeaderText = L"Tipo";
			this->colTipoMov->MinimumWidth = 6;
			this->colTipoMov->Name = L"colTipoMov";
			this->colTipoMov->ReadOnly = true;
			// 
			// colEstado
			// 
			this->colEstado->FillWeight = 62.9732F;
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// colFecha
			// 
			this->colFecha->FillWeight = 112.9732F;
			this->colFecha->HeaderText = L"Fecha";
			this->colFecha->MinimumWidth = 6;
			this->colFecha->Name = L"colFecha";
			this->colFecha->ReadOnly = true;
			// 
			// colDescripcion
			// 
			this->colDescripcion->FillWeight = 152.9732F;
			this->colDescripcion->HeaderText = L"Descripcion";
			this->colDescripcion->MinimumWidth = 6;
			this->colDescripcion->Name = L"colDescripcion";
			this->colDescripcion->ReadOnly = true;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->AutoSize = true;
			this->btnLimpiar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::Color::White;
			this->btnLimpiar->Location = System::Drawing::Point(266, 301);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(4);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(128, 53);
			this->btnLimpiar->TabIndex = 75;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmGestionarMovimientos::btnLimpiar_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->AutoSize = true;
			this->btnBuscar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(758, 371);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(138, 53);
			this->btnBuscar->TabIndex = 74;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmGestionarMovimientos::btnBuscar_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->AutoSize = true;
			this->btnModificar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnModificar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnModificar->ForeColor = System::Drawing::Color::White;
			this->btnModificar->Location = System::Drawing::Point(721, 301);
			this->btnModificar->Margin = System::Windows::Forms::Padding(4);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(152, 53);
			this->btnModificar->TabIndex = 73;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = false;
			this->btnModificar->Click += gcnew System::EventHandler(this, &frmGestionarMovimientos::btnModificar_Click);
			// 
			// gbDatosMovimiento
			// 
			this->gbDatosMovimiento->Controls->Add(this->txtBusqueda);
			this->gbDatosMovimiento->Controls->Add(this->lblBusqueda);
			this->gbDatosMovimiento->Controls->Add(this->cmbBxEstado);
			this->gbDatosMovimiento->Controls->Add(this->cmbBxTipoMov);
			this->gbDatosMovimiento->Controls->Add(this->dgvMovimientos);
			this->gbDatosMovimiento->Controls->Add(this->btnLimpiar);
			this->gbDatosMovimiento->Controls->Add(this->btnBuscar);
			this->gbDatosMovimiento->Controls->Add(this->btnModificar);
			this->gbDatosMovimiento->Controls->Add(this->btnRegistrar);
			this->gbDatosMovimiento->Controls->Add(this->lblPenalizacionTicket);
			this->gbDatosMovimiento->Controls->Add(this->txtDescripcion);
			this->gbDatosMovimiento->Controls->Add(this->lblDescripcion);
			this->gbDatosMovimiento->Controls->Add(this->lblEstado);
			this->gbDatosMovimiento->Controls->Add(this->txtMonto);
			this->gbDatosMovimiento->Controls->Add(this->lblMonto);
			this->gbDatosMovimiento->Controls->Add(this->txtIdMov);
			this->gbDatosMovimiento->Controls->Add(this->lblIdMov);
			this->gbDatosMovimiento->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbDatosMovimiento->Location = System::Drawing::Point(12, 71);
			this->gbDatosMovimiento->Name = L"gbDatosMovimiento";
			this->gbDatosMovimiento->Size = System::Drawing::Size(1141, 752);
			this->gbDatosMovimiento->TabIndex = 57;
			this->gbDatosMovimiento->TabStop = false;
			this->gbDatosMovimiento->Text = L"Datos del movimiento";
			// 
			// txtBusqueda
			// 
			this->txtBusqueda->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtBusqueda->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBusqueda->Location = System::Drawing::Point(507, 375);
			this->txtBusqueda->Margin = System::Windows::Forms::Padding(4);
			this->txtBusqueda->Name = L"txtBusqueda";
			this->txtBusqueda->Size = System::Drawing::Size(176, 42);
			this->txtBusqueda->TabIndex = 80;
			// 
			// lblBusqueda
			// 
			this->lblBusqueda->AutoSize = true;
			this->lblBusqueda->BackColor = System::Drawing::Color::White;
			this->lblBusqueda->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBusqueda->Location = System::Drawing::Point(211, 380);
			this->lblBusqueda->Name = L"lblBusqueda";
			this->lblBusqueda->Size = System::Drawing::Size(242, 34);
			this->lblBusqueda->TabIndex = 79;
			this->lblBusqueda->Text = L"Busqueda por ID:";
			// 
			// cmbBxEstado
			// 
			this->cmbBxEstado->FormattingEnabled = true;
			this->cmbBxEstado->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Anulada ", L"Activa" });
			this->cmbBxEstado->Location = System::Drawing::Point(668, 197);
			this->cmbBxEstado->Name = L"cmbBxEstado";
			this->cmbBxEstado->Size = System::Drawing::Size(273, 33);
			this->cmbBxEstado->TabIndex = 78;
			// 
			// cmbBxTipoMov
			// 
			this->cmbBxTipoMov->FormattingEnabled = true;
			this->cmbBxTipoMov->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Servicio", L"Multa", L"Membresia", L"Reparacion",
					L"Reembolso"
			});
			this->cmbBxTipoMov->Location = System::Drawing::Point(668, 147);
			this->cmbBxTipoMov->Name = L"cmbBxTipoMov";
			this->cmbBxTipoMov->Size = System::Drawing::Size(273, 33);
			this->cmbBxTipoMov->TabIndex = 77;
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->AutoSize = true;
			this->btnRegistrar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnRegistrar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegistrar->ForeColor = System::Drawing::Color::White;
			this->btnRegistrar->Location = System::Drawing::Point(483, 301);
			this->btnRegistrar->Margin = System::Windows::Forms::Padding(4);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(148, 53);
			this->btnRegistrar->TabIndex = 72;
			this->btnRegistrar->Text = L"Registrar";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &frmGestionarMovimientos::btnRegistrar_Click);
			// 
			// lblPenalizacionTicket
			// 
			this->lblPenalizacionTicket->AutoSize = true;
			this->lblPenalizacionTicket->BackColor = System::Drawing::Color::White;
			this->lblPenalizacionTicket->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPenalizacionTicket->Location = System::Drawing::Point(172, 144);
			this->lblPenalizacionTicket->Name = L"lblPenalizacionTicket";
			this->lblPenalizacionTicket->Size = System::Drawing::Size(290, 34);
			this->lblPenalizacionTicket->TabIndex = 69;
			this->lblPenalizacionTicket->Text = L"Tipo de Movimiento:";
			// 
			// txtDescripcion
			// 
			this->txtDescripcion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtDescripcion->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDescripcion->Location = System::Drawing::Point(668, 237);
			this->txtDescripcion->Margin = System::Windows::Forms::Padding(4);
			this->txtDescripcion->Name = L"txtDescripcion";
			this->txtDescripcion->Size = System::Drawing::Size(273, 42);
			this->txtDescripcion->TabIndex = 68;
			// 
			// lblDescripcion
			// 
			this->lblDescripcion->AutoSize = true;
			this->lblDescripcion->BackColor = System::Drawing::Color::White;
			this->lblDescripcion->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDescripcion->Location = System::Drawing::Point(172, 245);
			this->lblDescripcion->Name = L"lblDescripcion";
			this->lblDescripcion->Size = System::Drawing::Size(175, 34);
			this->lblDescripcion->TabIndex = 67;
			this->lblDescripcion->Text = L"Descripcion:";
			// 
			// lblEstado
			// 
			this->lblEstado->AutoSize = true;
			this->lblEstado->BackColor = System::Drawing::Color::White;
			this->lblEstado->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstado->Location = System::Drawing::Point(172, 194);
			this->lblEstado->Name = L"lblEstado";
			this->lblEstado->Size = System::Drawing::Size(414, 34);
			this->lblEstado->TabIndex = 65;
			this->lblEstado->Text = L"Estado actual del Movimiento:";
			// 
			// txtMonto
			// 
			this->txtMonto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtMonto->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtMonto->Location = System::Drawing::Point(668, 86);
			this->txtMonto->Margin = System::Windows::Forms::Padding(4);
			this->txtMonto->Name = L"txtMonto";
			this->txtMonto->Size = System::Drawing::Size(273, 42);
			this->txtMonto->TabIndex = 64;
			// 
			// lblMonto
			// 
			this->lblMonto->AutoSize = true;
			this->lblMonto->BackColor = System::Drawing::Color::White;
			this->lblMonto->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMonto->Location = System::Drawing::Point(172, 91);
			this->lblMonto->Name = L"lblMonto";
			this->lblMonto->Size = System::Drawing::Size(168, 34);
			this->lblMonto->TabIndex = 63;
			this->lblMonto->Text = L"Monto (S/):";
			// 
			// txtIdMov
			// 
			this->txtIdMov->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdMov->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIdMov->Location = System::Drawing::Point(668, 33);
			this->txtIdMov->Margin = System::Windows::Forms::Padding(4);
			this->txtIdMov->Name = L"txtIdMov";
			this->txtIdMov->ReadOnly = true;
			this->txtIdMov->Size = System::Drawing::Size(273, 42);
			this->txtIdMov->TabIndex = 62;
			// 
			// lblIdMov
			// 
			this->lblIdMov->AutoSize = true;
			this->lblIdMov->BackColor = System::Drawing::Color::White;
			this->lblIdMov->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIdMov->Location = System::Drawing::Point(172, 41);
			this->lblIdMov->Name = L"lblIdMov";
			this->lblIdMov->Size = System::Drawing::Size(222, 34);
			this->lblIdMov->TabIndex = 61;
			this->lblIdMov->Text = L"ID Movimiento:";
			// 
			// pnlInfo
			// 
			this->pnlInfo->BackColor = System::Drawing::Color::White;
			this->pnlInfo->Controls->Add(this->gbDatosMovimiento);
			this->pnlInfo->Controls->Add(this->pnlTitulo);
			this->pnlInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlInfo->Location = System::Drawing::Point(0, 0);
			this->pnlInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(1164, 850);
			this->pnlInfo->TabIndex = 15;
			// 
			// frmGestionarMovimientos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1164, 850);
			this->Controls->Add(this->pnlInfo);
			this->Name = L"frmGestionarMovimientos";
			this->Text = L"Gestionar Movimientos";
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvMovimientos))->EndInit();
			this->gbDatosMovimiento->ResumeLayout(false);
			this->gbDatosMovimiento->PerformLayout();
			this->pnlInfo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnRegistrar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {

			if (String::IsNullOrWhiteSpace(txtMonto->Text) ||
				cmbBxTipoMov->SelectedIndex == -1 ||
				cmbBxEstado->SelectedIndex == -1 ||
				String::IsNullOrWhiteSpace(txtDescripcion->Text)) {
				MessageBox::Show("Debe completar todos los campos obligatorios para registrar el movimiento.", "Campos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			double monto = 0.0;
			if (!Double::TryParse(txtMonto->Text->Trim(), monto)) {
				MessageBox::Show("El monto ingresado no tiene un formato numérico válido.", "Dato inválido", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				txtMonto->Focus();
				txtMonto->SelectAll();
				return;
			}

			int id = Convert::ToInt32(txtIdMov->Text);
			String^ tipo = cmbBxTipoMov->SelectedItem->ToString();
			String^ estadoTexto = cmbBxEstado->SelectedItem->ToString();
			bool anulada = (estadoTexto->Trim() == "Anulada");
			String^ descripcion = txtDescripcion->Text->Trim();

			DateTime fechaHoraActual = DateTime::Now;

			Movimiento^ nuevoMov = gcnew Movimiento();
			nuevoMov->setIdMovimiento(id);
			nuevoMov->setMonto(monto);
			nuevoMov->setTipoMovimiento(tipo);
			nuevoMov->setAnulada(anulada);
			nuevoMov->setDescripcion(descripcion);
			nuevoMov->setFechaHoraMovimento(fechaHoraActual);
			nuevoMov->setListaPagos(gcnew List<Pago^>());

			movimientoController->registrarArchivo(nuevoMov);

			MessageBox::Show("¡Movimiento registrado con éxito!", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			cargarMovimientos();
			limpiarCampos();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al registrar movimiento: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		limpiarCampos();
		cargarMovimientos();
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (String::IsNullOrWhiteSpace(txtBusqueda->Text)) {
				cargarMovimientos();
				return;
			}

			int idBusq = Convert::ToInt32(txtBusqueda->Text->Trim());
			Movimiento^ m = movimientoController->buscarxIdArchivo(idBusq);

			dgvMovimientos->Rows->Clear();
			if (m != nullptr) {
				String^ estadoStr = m->getAnulada() ? "Anulada" : "Activa";
				dgvMovimientos->Rows->Add(
					m->getIdMovimiento(),
					m->getMonto().ToString("F2"),
					m->getTipoMovimiento(),
					estadoStr,
					m->getFechaHoraMovimento().ToString("yyyy-MM-dd HH:mm"),
					m->getDescripcion()
				);
			}
			else {
				MessageBox::Show("No se encontró ningún movimiento con el ID especificado.", "Sin resultados", MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarMovimientos();
			}
		}
		catch (Exception^) {
			MessageBox::Show("Ingrese un ID numérico válido para la búsqueda.", "Formato incorrecto", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		dgvMovimientos->ClearSelection();
	}

	private: System::Void dgvMovimientos_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = dgvMovimientos->Rows[e->RowIndex];

			txtIdMov->Text = row->Cells[0]->Value->ToString();
			txtMonto->Text = row->Cells[1]->Value->ToString();
			cmbBxTipoMov->Text = row->Cells[2]->Value->ToString();
			cmbBxEstado->Text = row->Cells[3]->Value->ToString();
			txtDescripcion->Text = row->Cells[5]->Value->ToString();

			txtMonto->ReadOnly = true;
			txtDescripcion->ReadOnly = true;
		}
	}

	private: System::Void btnModificar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (String::IsNullOrWhiteSpace(txtIdMov->Text)) {
				MessageBox::Show("Seleccione de la tabla el movimiento que desea modificar.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			int idMov = Convert::ToInt32(txtIdMov->Text);
			Movimiento^ movExistente = movimientoController->buscarxIdArchivo(idMov);

			if (movExistente != nullptr) {
				if (cmbBxTipoMov->SelectedIndex == -1 || cmbBxEstado->SelectedIndex == -1) {
					MessageBox::Show("Debe seleccionar un tipo y un estado válidos.", "Campos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				bool eraActivoAntes = !movExistente->getAnulada();
				bool seVaAAnularAhora = (cmbBxEstado->SelectedItem->ToString()->Trim() == "Anulada");

				movExistente->setTipoMovimiento(cmbBxTipoMov->SelectedItem->ToString());
				movExistente->setAnulada(seVaAAnularAhora);

				movimientoController->modificarArchivo(movExistente);

				if (eraActivoAntes && seVaAAnularAhora && movExistente->getTipoMovimiento() != "Reembolso") {
					List<Movimiento^>^ lista = movimientoController->buscarTodosArchivo();
					int siguienteId = 1;
					if (lista != nullptr && lista->Count > 0) {
						int maxId = 0;
						for each (Movimiento ^ m in lista) {
							if (m->getIdMovimiento() > maxId) maxId = m->getIdMovimiento();
						}
						siguienteId = maxId + 1;
					}

					Movimiento^ movReembolso = gcnew Movimiento();
					movReembolso->setIdMovimiento(siguienteId);
					movReembolso->setMonto(movExistente->getMonto());
					movReembolso->setTipoMovimiento("Reembolso");
					movReembolso->setAnulada(false);
					movReembolso->setDescripcion("Reembolso automático" + movExistente->getIdMovimiento());
					movReembolso->setFechaHoraMovimento(DateTime::Now);
					movReembolso->setListaPagos(gcnew List<Pago^>());

					movimientoController->registrarArchivo(movReembolso);
				}

				MessageBox::Show("Movimiento modificado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				cargarMovimientos();
				limpiarCampos();
			}
			else {
				MessageBox::Show("No se encontró el movimiento a modificar en el archivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al modificar el movimiento: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
