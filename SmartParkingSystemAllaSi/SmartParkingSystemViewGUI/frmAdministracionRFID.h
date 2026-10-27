#pragma once

#include "frmGestionRFID.h"

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmAdministracionRFID
	/// </summary>
	public ref class frmAdministracionRFID : public System::Windows::Forms::Form
	{
	private:
		SmartParkingSystemController::TarjetaRFIDController^ tarjetaRFIDController;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colUID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCliente;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDocumento;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEmision;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colVencimiento;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
		   SmartParkingSystemController::ClienteController^ clienteController;

		   // Muestra en el DataGridView las tarjetas RFID de una lista determinada.
	private:
		void mostrarTarjetas(List<TarjetaRFID^>^ tarjetas)
		{
			// Limpia los registros mostrados anteriormente.
			dgvTarjetasRFID->Rows->Clear();

			for each (TarjetaRFID ^ tarjeta in tarjetas)
			{
				// Busca al cliente asociado a la tarjeta RFID.
				Cliente^ cliente =
					clienteController->buscarClientePorId(
						tarjeta->getIdCliente()
					);

				String^ nombreCliente = "No disponible";
				String^ documentoCliente = "No disponible";

				// Obtiene los datos del cliente asociado.
				if (cliente != nullptr)
				{
					nombreCliente =
						cliente->getNombres() + " " +
						cliente->getApellidos();

					documentoCliente =
						cliente->getDocumento();
				}

				// Muestra la información de la tarjeta RFID.
				dgvTarjetasRFID->Rows->Add(
					tarjeta->getIdTarjeta(),
					tarjeta->getCodigoUID(),
					nombreCliente,
					documentoCliente,
					tarjeta->getFechaEmision().ToString("dd/MM/yyyy"),
					tarjeta->getFechaVencimiento().ToString("dd/MM/yyyy"),
					tarjeta->estaActiva() ? "Activa" : "Inactiva"
				);
			}

			// Evita que quede seleccionada automáticamente la primera fila.
			dgvTarjetasRFID->ClearSelection();
		}

		// Carga todas las tarjetas RFID registradas.
	private:
		void cargarTarjetas()
		{
			List<TarjetaRFID^>^ tarjetas =
				tarjetaRFIDController->listarTarjetas();

			mostrarTarjetas(tarjetas);
		}

		//Constructor
	public:
		frmAdministracionRFID(void)
		{
			InitializeComponent();

			// Inicializa el controlador de tarjetas RFID.
			tarjetaRFIDController =
				gcnew SmartParkingSystemController::TarjetaRFIDController();

			clienteController =
				gcnew SmartParkingSystemController::ClienteController();

			// Carga las tarjetas RFID registradas.
			cargarTarjetas();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAdministracionRFID()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ grpBuscar;
	private: System::Windows::Forms::Button^ btnDesactivarRFID;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btnEditarRFID;

	private: System::Windows::Forms::Button^ btnAsociarRFID;

	private: System::Windows::Forms::Button^ btnMostrarTodos;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::DataGridView^ dgvTarjetasRFID;








	private: System::Windows::Forms::Label^ lblBuscar;
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Panel^ pnlTitulo;















	protected:


















	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->grpBuscar = (gcnew System::Windows::Forms::GroupBox());
			this->btnDesactivarRFID = (gcnew System::Windows::Forms::Button());
			this->btnEditarRFID = (gcnew System::Windows::Forms::Button());
			this->btnAsociarRFID = (gcnew System::Windows::Forms::Button());
			this->btnMostrarTodos = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->dgvTarjetasRFID = (gcnew System::Windows::Forms::DataGridView());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colUID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDocumento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEmision = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colVencimiento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblBuscar = (gcnew System::Windows::Forms::Label());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->grpBuscar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTarjetasRFID))->BeginInit();
			this->pnlTitulo->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpBuscar
			// 
			this->grpBuscar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grpBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->grpBuscar->Controls->Add(this->btnMostrarTodos);
			this->grpBuscar->Controls->Add(this->btnBuscar);
			this->grpBuscar->Controls->Add(this->txtBuscar);
			this->grpBuscar->Controls->Add(this->lblBuscar);
			this->grpBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->grpBuscar->Location = System::Drawing::Point(47, 138);
			this->grpBuscar->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->grpBuscar->Name = L"grpBuscar";
			this->grpBuscar->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->grpBuscar->Size = System::Drawing::Size(1188, 145);
			this->grpBuscar->TabIndex = 59;
			this->grpBuscar->TabStop = false;
			this->grpBuscar->Text = L"Buscar tarjeta / cliente";
			// 
			// btnDesactivarRFID
			// 
			this->btnDesactivarRFID->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnDesactivarRFID->AutoSize = true;
			this->btnDesactivarRFID->BackColor = System::Drawing::Color::Red;
			this->btnDesactivarRFID->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnDesactivarRFID->ForeColor = System::Drawing::Color::White;
			this->btnDesactivarRFID->Location = System::Drawing::Point(779, 26);
			this->btnDesactivarRFID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnDesactivarRFID->Name = L"btnDesactivarRFID";
			this->btnDesactivarRFID->Size = System::Drawing::Size(260, 48);
			this->btnDesactivarRFID->TabIndex = 82;
			this->btnDesactivarRFID->Text = L"Desactivar RFID";
			this->btnDesactivarRFID->UseVisualStyleBackColor = false;
			this->btnDesactivarRFID->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnDesactivarRFID_Click);
			// 
			// btnEditarRFID
			// 
			this->btnEditarRFID->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnEditarRFID->AutoSize = true;
			this->btnEditarRFID->BackColor = System::Drawing::Color::DarkOrange;
			this->btnEditarRFID->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnEditarRFID->ForeColor = System::Drawing::Color::White;
			this->btnEditarRFID->Location = System::Drawing::Point(477, 26);
			this->btnEditarRFID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnEditarRFID->Name = L"btnEditarRFID";
			this->btnEditarRFID->Size = System::Drawing::Size(260, 48);
			this->btnEditarRFID->TabIndex = 81;
			this->btnEditarRFID->Text = L"Editar RFID";
			this->btnEditarRFID->UseVisualStyleBackColor = false;
			this->btnEditarRFID->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnEditarRFID_Click);
			// 
			// btnAsociarRFID
			// 
			this->btnAsociarRFID->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnAsociarRFID->AutoSize = true;
			this->btnAsociarRFID->BackColor = System::Drawing::Color::LimeGreen;
			this->btnAsociarRFID->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnAsociarRFID->ForeColor = System::Drawing::Color::White;
			this->btnAsociarRFID->Location = System::Drawing::Point(170, 26);
			this->btnAsociarRFID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnAsociarRFID->Name = L"btnAsociarRFID";
			this->btnAsociarRFID->Size = System::Drawing::Size(260, 48);
			this->btnAsociarRFID->TabIndex = 80;
			this->btnAsociarRFID->Text = L"Asociar RFID";
			this->btnAsociarRFID->UseVisualStyleBackColor = false;
			this->btnAsociarRFID->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnAsociarRFID_Click);
			// 
			// btnMostrarTodos
			// 
			this->btnMostrarTodos->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnMostrarTodos->AutoSize = true;
			this->btnMostrarTodos->BackColor = System::Drawing::Color::Blue;
			this->btnMostrarTodos->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnMostrarTodos->ForeColor = System::Drawing::Color::White;
			this->btnMostrarTodos->Location = System::Drawing::Point(933, 51);
			this->btnMostrarTodos->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnMostrarTodos->Name = L"btnMostrarTodos";
			this->btnMostrarTodos->Size = System::Drawing::Size(235, 48);
			this->btnMostrarTodos->TabIndex = 79;
			this->btnMostrarTodos->Text = L"Mostrar todos";
			this->btnMostrarTodos->UseVisualStyleBackColor = false;
			this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnMostrarTodos_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnBuscar->AutoSize = true;
			this->btnBuscar->BackColor = System::Drawing::Color::DarkOrchid;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(761, 51);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(154, 48);
			this->btnBuscar->TabIndex = 78;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtBuscar->BackColor = System::Drawing::Color::White;
			this->txtBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->txtBuscar->Location = System::Drawing::Point(390, 55);
			this->txtBuscar->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(363, 40);
			this->txtBuscar->TabIndex = 77;
			// 
			// dgvTarjetasRFID
			// 
			this->dgvTarjetasRFID->AllowUserToAddRows = false;
			this->dgvTarjetasRFID->AllowUserToDeleteRows = false;
			this->dgvTarjetasRFID->AllowUserToResizeRows = false;
			this->dgvTarjetasRFID->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dgvTarjetasRFID->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTarjetasRFID->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvTarjetasRFID->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvTarjetasRFID->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarjetasRFID->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->colId,
					this->colUID, this->colCliente, this->colDocumento, this->colEmision, this->colVencimiento, this->colEstado
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvTarjetasRFID->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvTarjetasRFID->EnableHeadersVisualStyles = false;
			this->dgvTarjetasRFID->Location = System::Drawing::Point(47, 323);
			this->dgvTarjetasRFID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dgvTarjetasRFID->MultiSelect = false;
			this->dgvTarjetasRFID->Name = L"dgvTarjetasRFID";
			this->dgvTarjetasRFID->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvTarjetasRFID->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dgvTarjetasRFID->RowHeadersVisible = false;
			this->dgvTarjetasRFID->RowHeadersWidth = 51;
			this->dgvTarjetasRFID->RowTemplate->Height = 24;
			this->dgvTarjetasRFID->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTarjetasRFID->Size = System::Drawing::Size(1188, 312);
			this->dgvTarjetasRFID->TabIndex = 76;
			// 
			// colId
			// 
			this->colId->FillWeight = 40.10694F;
			this->colId->HeaderText = L"Id";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			this->colId->ReadOnly = true;
			this->colId->Visible = false;
			// 
			// colUID
			// 
			this->colUID->HeaderText = L"UID";
			this->colUID->MinimumWidth = 6;
			this->colUID->Name = L"colUID";
			this->colUID->ReadOnly = true;
			// 
			// colCliente
			// 
			this->colCliente->FillWeight = 114.9732F;
			this->colCliente->HeaderText = L"Cliente";
			this->colCliente->MinimumWidth = 6;
			this->colCliente->Name = L"colCliente";
			this->colCliente->ReadOnly = true;
			// 
			// colDocumento
			// 
			this->colDocumento->FillWeight = 114.9732F;
			this->colDocumento->HeaderText = L"Documento";
			this->colDocumento->MinimumWidth = 6;
			this->colDocumento->Name = L"colDocumento";
			this->colDocumento->ReadOnly = true;
			// 
			// colEmision
			// 
			this->colEmision->FillWeight = 114.9732F;
			this->colEmision->HeaderText = L"Emisión";
			this->colEmision->MinimumWidth = 6;
			this->colEmision->Name = L"colEmision";
			this->colEmision->ReadOnly = true;
			// 
			// colVencimiento
			// 
			this->colVencimiento->FillWeight = 114.9732F;
			this->colVencimiento->HeaderText = L"Vencimiento";
			this->colVencimiento->MinimumWidth = 6;
			this->colVencimiento->Name = L"colVencimiento";
			this->colVencimiento->ReadOnly = true;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// lblBuscar
			// 
			this->lblBuscar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lblBuscar->AutoSize = true;
			this->lblBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->lblBuscar->Location = System::Drawing::Point(19, 58);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->Size = System::Drawing::Size(364, 33);
			this->lblBuscar->TabIndex = 61;
			this->lblBuscar->Text = L"UID, cliente o documento:";
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(14, 15);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(408, 46);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Administración RFID";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlTitulo
			// 
			this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlTitulo->Controls->Add(this->lblTitulo);
			this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitulo->Location = System::Drawing::Point(0, 0);
			this->pnlTitulo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->pnlTitulo->Name = L"pnlTitulo";
			this->pnlTitulo->Size = System::Drawing::Size(1270, 81);
			this->pnlTitulo->TabIndex = 58;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->grpBuscar);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->dgvTarjetasRFID);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1270, 862);
			this->panel2->TabIndex = 60;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->btnDesactivarRFID);
			this->panel3->Controls->Add(this->btnEditarRFID);
			this->panel3->Controls->Add(this->btnAsociarRFID);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 763);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1270, 99);
			this->panel3->TabIndex = 27;
			// 
			// frmAdministracionRFID
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 862);
			this->Controls->Add(this->pnlTitulo);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmAdministracionRFID";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Administración RFID";
			this->Load += gcnew System::EventHandler(this, &frmAdministracionRFID::frmAdministracionRFID_Load);
			this->grpBuscar->ResumeLayout(false);
			this->grpBuscar->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTarjetasRFID))->EndInit();
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmAdministracionRFID_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   // Muestra nuevamente todas las tarjetas RFID registradas.
	private: System::Void btnMostrarTodos_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Limpia el criterio de búsqueda.
		txtBuscar->Clear();

		// Carga nuevamente todas las tarjetas RFID.
		cargarTarjetas();

		// Devuelve el foco al cuadro de búsqueda.
		txtBuscar->Focus();
	}
		   // Busca tarjetas RFID por UID, cliente o documento.
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ criterio = txtBuscar->Text->Trim();

		// Si no se ingresó un criterio, muestra todas las tarjetas.
		if (String::IsNullOrWhiteSpace(criterio))
		{
			cargarTarjetas();
			return;
		}

		String^ textoBuscado =
			criterio->ToLower();

		List<TarjetaRFID^>^ tarjetas =
			tarjetaRFIDController->listarTarjetas();

		List<TarjetaRFID^>^ resultados =
			gcnew List<TarjetaRFID^>();

		for each (TarjetaRFID ^ tarjeta in tarjetas)
		{
			// Comprueba primero el código UID.
			String^ uid =
				tarjeta->getCodigoUID()->ToLower();

			// El UID admite coincidencias parciales.
			bool coincideUID =
				uid->Contains(textoBuscado);

			// Busca al cliente asociado a la tarjeta.
			Cliente^ cliente =
				clienteController->buscarClientePorId(
					tarjeta->getIdCliente()
				);

			bool coincideCliente = false;
			bool coincideDocumento = false;

			if (cliente != nullptr)
			{
				String^ nombres =
					cliente->getNombres()->ToLower();

				String^ apellidos =
					cliente->getApellidos()->ToLower();

				String^ documento =
					cliente->getDocumento()->ToLower();

				// Separa nombres y apellidos para comprobar cada palabra.
				array<String^>^ palabrasNombres =
					nombres->Split(' ');

				array<String^>^ palabrasApellidos =
					apellidos->Split(' ');

				// Comprueba los nombres desde sus caracteres iniciales.
				for each (String ^ nombre in palabrasNombres)
				{
					if (nombre->StartsWith(textoBuscado))
					{
						coincideCliente = true;
						break;
					}
				}

				// Si todavía no existe coincidencia,
				// comprueba también los apellidos.
				if (!coincideCliente)
				{
					for each (String ^ apellido in palabrasApellidos)
					{
						if (apellido->StartsWith(textoBuscado))
						{
							coincideCliente = true;
							break;
						}
					}
				}

				// El documento admite coincidencias parciales
				// únicamente desde sus primeros dígitos.
				coincideDocumento =
					documento->StartsWith(textoBuscado);
			}

			// Agrega la tarjeta si coincide con alguno
			// de los criterios permitidos.
			if (coincideUID ||
				coincideCliente ||
				coincideDocumento)
			{
				resultados->Add(tarjeta);
			}
		}

		// Muestra solamente las coincidencias encontradas.
		mostrarTarjetas(resultados);

		// Informa cuando no se encontraron resultados.
		if (resultados->Count == 0)
		{
			MessageBox::Show(
				"No se encontraron tarjetas RFID que coincidan "
				"con el criterio ingresado.",
				"Resultados de búsqueda",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}
	}
		   // Abre el formulario para asociar una nueva tarjeta RFID.
	private: System::Void btnAsociarRFID_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmGestionRFID^ formulario =
			gcnew frmGestionRFID();

		// Recarga la tabla si se registró correctamente.
		if (formulario->ShowDialog() ==
			System::Windows::Forms::DialogResult::OK)
		{
			cargarTarjetas();
		}
	}
		   // Abre el formulario para editar la tarjeta RFID seleccionada.
	private: System::Void btnEditarRFID_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Verifica que exista una fila seleccionada.
		if (dgvTarjetasRFID->SelectedRows->Count == 0)
		{
			MessageBox::Show(
				"Debe seleccionar una tarjeta RFID para editar.",
				"Editar tarjeta RFID",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
			return;
		}

		// Obtiene el ID interno de la tarjeta seleccionada.
		int idTarjeta =
			Convert::ToInt32(
				dgvTarjetasRFID->SelectedRows[0]->Cells[0]->Value
			);

		TarjetaRFID^ tarjeta =
			tarjetaRFIDController->buscarPorId(idTarjeta);

		if (tarjeta == nullptr)
		{
			MessageBox::Show(
				"No se encontró la tarjeta RFID seleccionada.",
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// Una tarjeta inactiva se conserva como historial
		// y ya no puede ser modificada.
		if (!tarjeta->estaActiva())
		{
			MessageBox::Show(
				"La tarjeta RFID seleccionada ya se encuentra inactiva"
				" y no puede ser modificada.",
				"Tarjeta RFID inactiva",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
			return;
		}

		frmGestionRFID^ formulario =
			gcnew frmGestionRFID(idTarjeta);

		// Recarga la tabla si se modificó correctamente.
		if (formulario->ShowDialog() ==
			System::Windows::Forms::DialogResult::OK)
		{
			cargarTarjetas();
		}
	}
		   // Desactiva la tarjeta RFID seleccionada.
	private: System::Void btnDesactivarRFID_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Verifica que exista una fila seleccionada.
		if (dgvTarjetasRFID->SelectedRows->Count == 0)
		{
			MessageBox::Show(
				"Debe seleccionar una tarjeta RFID para desactivar.",
				"Desactivar tarjeta RFID",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
			return;
		}

		// Obtiene el ID interno de la tarjeta seleccionada.
		int idTarjeta =
			Convert::ToInt32(
				dgvTarjetasRFID->SelectedRows[0]->Cells[0]->Value
			);

		TarjetaRFID^ tarjeta =
			tarjetaRFIDController->buscarPorId(idTarjeta);

		if (tarjeta == nullptr)
		{
			MessageBox::Show(
				"No se encontró la tarjeta RFID seleccionada.",
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// Evita volver a desactivar una tarjeta inactiva.
		if (!tarjeta->estaActiva())
		{
			MessageBox::Show(
				"La tarjeta RFID seleccionada ya se encuentra inactiva.",
				"Tarjeta RFID inactiva",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
			return;
		}

		System::Windows::Forms::DialogResult respuesta =
			MessageBox::Show(
				"¿Está seguro de que desea desactivar la "
				"tarjeta RFID seleccionada?\n\n"
				"La tarjeta permanecerá registrada en el historial.",
				"Confirmar desactivación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);

		if (respuesta !=
			System::Windows::Forms::DialogResult::Yes)
		{
			return;
		}

		if (tarjetaRFIDController->desactivarTarjeta(idTarjeta))
		{
			MessageBox::Show(
				"Tarjeta RFID desactivada correctamente.",
				"Operación exitosa",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			cargarTarjetas();
		}
		else
		{
			MessageBox::Show(
				"No se pudo desactivar la tarjeta RFID.",
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}
	};
}
