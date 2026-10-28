#pragma once

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemDAO;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmRegistroAcceso
	/// </summary>
	public ref class frmRegistroAcceso : public System::Windows::Forms::Form
	{
	public:
		frmRegistroAcceso(void)
		{
			InitializeComponent();
			registroController = gcnew RegistroAccesoController();
			CargarRegistrosEnGrilla(registroController->listarRegistros()); 
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmRegistroAcceso()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		RegistroAccesoController^ registroController;

	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Panel^ pnlTitulo;
	private: System::Windows::Forms::DataGridView^ dgvAccesos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdAcceso;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCodTarjeta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHoraIngreso;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHoraSalida;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCodEspacio;
	private: System::Windows::Forms::Button^ btnBuscar;

	private: System::Windows::Forms::GroupBox^ gbRegAcceso;
	private: System::Windows::Forms::Label^ lblBusq;


	private: System::Windows::Forms::Panel^ pnlInfo;
	private: System::Windows::Forms::TextBox^ txtBusqAccesos;


	private:
		void CargarRegistrosEnGrilla(List<RegistroAcceso^>^ lista) {
			dgvAccesos->Rows->Clear();
			try {
				if (lista != nullptr) {
					for each (RegistroAcceso ^ r in lista) {
						String^ horaSalidaStr;

						if (r->getFechaHoraSalida() == DateTime::MinValue || r->getFechaHoraSalida().Year < 2000) {
							horaSalidaStr = "Cliente todavía está usando el espacio";
						}
						else {
							horaSalidaStr = r->getFechaHoraSalida().ToString("yyyy-MM-dd HH:mm:ss");
						}

						String^ codEspacio = "N/A";
						if (r->getEspacioEstacionamiento() != nullptr) {
							codEspacio = r->getEspacioEstacionamiento()->getCodigo(); 
						}

						String^ codTarjeta = "N/A";
						if (r->getObservacion() != nullptr && !String::IsNullOrEmpty(r->getObservacion())) {
							codTarjeta = r->getObservacion();
						}

						dgvAccesos->Rows->Add(
							r->getIdRegistro(), 
							codTarjeta,
							r->getFechaHoraIngreso().ToString("yyyy-MM-dd HH:mm:ss"), 
							codEspacio,
							horaSalidaStr
						);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar los registros: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			dgvAccesos->ClearSelection();
		}

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
			this->dgvAccesos = (gcnew System::Windows::Forms::DataGridView());
			this->colIdAcceso = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCodTarjeta = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colHoraIngreso = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCodEspacio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colHoraSalida = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->gbRegAcceso = (gcnew System::Windows::Forms::GroupBox());
			this->txtBusqAccesos = (gcnew System::Windows::Forms::TextBox());
			this->lblBusq = (gcnew System::Windows::Forms::Label());
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->pnlTitulo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAccesos))->BeginInit();
			this->gbRegAcceso->SuspendLayout();
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
			this->lblTitulo->Size = System::Drawing::Size(442, 40);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Visualizar Accesos y Salidas";
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
			this->pnlTitulo->Size = System::Drawing::Size(1171, 65);
			this->pnlTitulo->TabIndex = 56;
			// 
			// dgvAccesos
			// 
			this->dgvAccesos->AllowUserToAddRows = false;
			this->dgvAccesos->AllowUserToDeleteRows = false;
			this->dgvAccesos->AllowUserToResizeRows = false;
			this->dgvAccesos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvAccesos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAccesos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colIdAcceso,
					this->colCodTarjeta, this->colHoraIngreso, this->colCodEspacio, this->colHoraSalida
			});
			this->dgvAccesos->Location = System::Drawing::Point(82, 173);
			this->dgvAccesos->Margin = System::Windows::Forms::Padding(4);
			this->dgvAccesos->MultiSelect = false;
			this->dgvAccesos->Name = L"dgvAccesos";
			this->dgvAccesos->ReadOnly = true;
			this->dgvAccesos->RowHeadersVisible = false;
			this->dgvAccesos->RowHeadersWidth = 51;
			this->dgvAccesos->RowTemplate->Height = 24;
			this->dgvAccesos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvAccesos->Size = System::Drawing::Size(980, 459);
			this->dgvAccesos->TabIndex = 76;
			// 
			// colIdAcceso
			// 
			this->colIdAcceso->FillWeight = 40.10694F;
			this->colIdAcceso->HeaderText = L"ID";
			this->colIdAcceso->MinimumWidth = 6;
			this->colIdAcceso->Name = L"colIdAcceso";
			this->colIdAcceso->ReadOnly = true;
			// 
			// colCodTarjeta
			// 
			this->colCodTarjeta->FillWeight = 114.9732F;
			this->colCodTarjeta->HeaderText = L"Codigo de Tarjeta";
			this->colCodTarjeta->MinimumWidth = 6;
			this->colCodTarjeta->Name = L"colCodTarjeta";
			this->colCodTarjeta->ReadOnly = true;
			// 
			// colHoraIngreso
			// 
			this->colHoraIngreso->FillWeight = 114.9732F;
			this->colHoraIngreso->HeaderText = L"Hora de Ingreso";
			this->colHoraIngreso->MinimumWidth = 6;
			this->colHoraIngreso->Name = L"colHoraIngreso";
			this->colHoraIngreso->ReadOnly = true;
			// 
			// colCodEspacio
			// 
			this->colCodEspacio->FillWeight = 114.9732F;
			this->colCodEspacio->HeaderText = L"Codigo de Espacio";
			this->colCodEspacio->MinimumWidth = 6;
			this->colCodEspacio->Name = L"colCodEspacio";
			this->colCodEspacio->ReadOnly = true;
			// 
			// colHoraSalida
			// 
			this->colHoraSalida->FillWeight = 114.9732F;
			this->colHoraSalida->HeaderText = L"Hora de Salida";
			this->colHoraSalida->MinimumWidth = 6;
			this->colHoraSalida->Name = L"colHoraSalida";
			this->colHoraSalida->ReadOnly = true;
			// 
			// btnBuscar
			// 
			this->btnBuscar->AutoSize = true;
			this->btnBuscar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(882, 74);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(128, 53);
			this->btnBuscar->TabIndex = 75;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			// 
			// gbRegAcceso
			// 
			this->gbRegAcceso->Controls->Add(this->txtBusqAccesos);
			this->gbRegAcceso->Controls->Add(this->dgvAccesos);
			this->gbRegAcceso->Controls->Add(this->btnBuscar);
			this->gbRegAcceso->Controls->Add(this->lblBusq);
			this->gbRegAcceso->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbRegAcceso->Location = System::Drawing::Point(12, 71);
			this->gbRegAcceso->Name = L"gbRegAcceso";
			this->gbRegAcceso->Size = System::Drawing::Size(1141, 642);
			this->gbRegAcceso->TabIndex = 57;
			this->gbRegAcceso->TabStop = false;
			this->gbRegAcceso->Text = L"Busqueda de Accesos";
			// 
			// txtBusqAccesos
			// 
			this->txtBusqAccesos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtBusqAccesos->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBusqAccesos->Location = System::Drawing::Point(539, 78);
			this->txtBusqAccesos->Margin = System::Windows::Forms::Padding(4);
			this->txtBusqAccesos->Name = L"txtBusqAccesos";
			this->txtBusqAccesos->ReadOnly = true;
			this->txtBusqAccesos->Size = System::Drawing::Size(267, 42);
			this->txtBusqAccesos->TabIndex = 77;
			// 
			// lblBusq
			// 
			this->lblBusq->AutoSize = true;
			this->lblBusq->BackColor = System::Drawing::Color::White;
			this->lblBusq->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBusq->Location = System::Drawing::Point(123, 83);
			this->lblBusq->Name = L"lblBusq";
			this->lblBusq->Size = System::Drawing::Size(386, 34);
			this->lblBusq->TabIndex = 61;
			this->lblBusq->Text = L"Codigo de tarjeta empleada:";
			// 
			// pnlInfo
			// 
			this->pnlInfo->BackColor = System::Drawing::Color::White;
			this->pnlInfo->Controls->Add(this->gbRegAcceso);
			this->pnlInfo->Controls->Add(this->pnlTitulo);
			this->pnlInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlInfo->Location = System::Drawing::Point(0, 0);
			this->pnlInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(1171, 777);
			this->pnlInfo->TabIndex = 15;
			// 
			// frmRegistroAcceso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1171, 777);
			this->Controls->Add(this->pnlInfo);
			this->Name = L"frmRegistroAcceso";
			this->Text = L"frmRegistroAcceso";
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAccesos))->EndInit();
			this->gbRegAcceso->ResumeLayout(false);
			this->gbRegAcceso->PerformLayout();
			this->pnlInfo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filtro = txtBusqAccesos->Text->Trim();
		List<RegistroAcceso^>^ listaTotal = registroController->listarRegistros();
		List<RegistroAcceso^>^ listaFiltrada = gcnew List<RegistroAcceso^>();

		if (String::IsNullOrWhiteSpace(filtro)) {
			CargarRegistrosEnGrilla(listaTotal);
			return;
		}

		for each (RegistroAcceso ^ r in listaTotal) {
			String^ tarjeta = r->getObservacion();
			if (tarjeta != nullptr && tarjeta->Equals(filtro, StringComparison::InvariantCultureIgnoreCase)) {
				listaFiltrada->Add(r);
			}
		}

		CargarRegistrosEnGrilla(listaFiltrada);
	}
};
}