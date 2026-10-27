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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->grpBuscar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTarjetasRFID))->BeginInit();
			this->pnlTitulo->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpBuscar
			// 
			this->grpBuscar->BackColor = System::Drawing::SystemColors::Control;
			this->grpBuscar->Controls->Add(this->btnDesactivarRFID);
			this->grpBuscar->Controls->Add(this->btnEditarRFID);
			this->grpBuscar->Controls->Add(this->btnAsociarRFID);
			this->grpBuscar->Controls->Add(this->btnMostrarTodos);
			this->grpBuscar->Controls->Add(this->btnBuscar);
			this->grpBuscar->Controls->Add(this->txtBuscar);
			this->grpBuscar->Controls->Add(this->dgvTarjetasRFID);
			this->grpBuscar->Controls->Add(this->lblBuscar);
			this->grpBuscar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grpBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBuscar->Location = System::Drawing::Point(0, 65);
			this->grpBuscar->Name = L"grpBuscar";
			this->grpBuscar->Size = System::Drawing::Size(1126, 483);
			this->grpBuscar->TabIndex = 59;
			this->grpBuscar->TabStop = false;
			this->grpBuscar->Text = L"Buscar tarjeta / cliente";
			// 
			// btnDesactivarRFID
			// 
			this->btnDesactivarRFID->AutoSize = true;
			this->btnDesactivarRFID->BackColor = System::Drawing::Color::Red;
			this->btnDesactivarRFID->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDesactivarRFID->ForeColor = System::Drawing::Color::White;
			this->btnDesactivarRFID->Location = System::Drawing::Point(666, 400);
			this->btnDesactivarRFID->Margin = System::Windows::Forms::Padding(4);
			this->btnDesactivarRFID->Name = L"btnDesactivarRFID";
			this->btnDesactivarRFID->Size = System::Drawing::Size(240, 53);
			this->btnDesactivarRFID->TabIndex = 82;
			this->btnDesactivarRFID->Text = L"Desactivar RFID";
			this->btnDesactivarRFID->UseVisualStyleBackColor = false;
			this->btnDesactivarRFID->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnDesactivarRFID_Click);
			// 
			// btnEditarRFID
			// 
			this->btnEditarRFID->AutoSize = true;
			this->btnEditarRFID->BackColor = System::Drawing::Color::DarkOrange;
			this->btnEditarRFID->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditarRFID->ForeColor = System::Drawing::Color::White;
			this->btnEditarRFID->Location = System::Drawing::Point(439, 400);
			this->btnEditarRFID->Margin = System::Windows::Forms::Padding(4);
			this->btnEditarRFID->Name = L"btnEditarRFID";
			this->btnEditarRFID->Size = System::Drawing::Size(178, 53);
			this->btnEditarRFID->TabIndex = 81;
			this->btnEditarRFID->Text = L"Editar RFID";
			this->btnEditarRFID->UseVisualStyleBackColor = false;
			this->btnEditarRFID->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnEditarRFID_Click);
			// 
			// btnAsociarRFID
			// 
			this->btnAsociarRFID->AutoSize = true;
			this->btnAsociarRFID->BackColor = System::Drawing::Color::ForestGreen;
			this->btnAsociarRFID->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAsociarRFID->ForeColor = System::Drawing::Color::White;
			this->btnAsociarRFID->Location = System::Drawing::Point(186, 400);
			this->btnAsociarRFID->Margin = System::Windows::Forms::Padding(4);
			this->btnAsociarRFID->Name = L"btnAsociarRFID";
			this->btnAsociarRFID->Size = System::Drawing::Size(200, 53);
			this->btnAsociarRFID->TabIndex = 80;
			this->btnAsociarRFID->Text = L"Asociar RFID";
			this->btnAsociarRFID->UseVisualStyleBackColor = false;
			this->btnAsociarRFID->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnAsociarRFID_Click);
			// 
			// btnMostrarTodos
			// 
			this->btnMostrarTodos->AutoSize = true;
			this->btnMostrarTodos->BackColor = System::Drawing::Color::Blue;
			this->btnMostrarTodos->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMostrarTodos->ForeColor = System::Drawing::Color::White;
			this->btnMostrarTodos->Location = System::Drawing::Point(874, 40);
			this->btnMostrarTodos->Margin = System::Windows::Forms::Padding(4);
			this->btnMostrarTodos->Name = L"btnMostrarTodos";
			this->btnMostrarTodos->Size = System::Drawing::Size(212, 53);
			this->btnMostrarTodos->TabIndex = 79;
			this->btnMostrarTodos->Text = L"Mostrar todos";
			this->btnMostrarTodos->UseVisualStyleBackColor = false;
			this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnMostrarTodos_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->AutoSize = true;
			this->btnBuscar->BackColor = System::Drawing::Color::Gray;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(725, 40);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(119, 53);
			this->btnBuscar->TabIndex = 78;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmAdministracionRFID::btnBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBuscar->Location = System::Drawing::Point(419, 44);
			this->txtBuscar->Margin = System::Windows::Forms::Padding(4);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(213, 42);
			this->txtBuscar->TabIndex = 77;
			// 
			// dgvTarjetasRFID
			// 
			this->dgvTarjetasRFID->AllowUserToAddRows = false;
			this->dgvTarjetasRFID->AllowUserToDeleteRows = false;
			this->dgvTarjetasRFID->AllowUserToResizeRows = false;
			this->dgvTarjetasRFID->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTarjetasRFID->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle12->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle12->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvTarjetasRFID->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle12;
			this->dgvTarjetasRFID->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarjetasRFID->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->colId,
					this->colUID, this->colCliente, this->colDocumento, this->colEmision, this->colVencimiento, this->colEstado
			});
			this->dgvTarjetasRFID->EnableHeadersVisualStyles = false;
			this->dgvTarjetasRFID->Location = System::Drawing::Point(41, 121);
			this->dgvTarjetasRFID->Margin = System::Windows::Forms::Padding(4);
			this->dgvTarjetasRFID->MultiSelect = false;
			this->dgvTarjetasRFID->Name = L"dgvTarjetasRFID";
			this->dgvTarjetasRFID->ReadOnly = true;
			this->dgvTarjetasRFID->RowHeadersVisible = false;
			this->dgvTarjetasRFID->RowHeadersWidth = 51;
			this->dgvTarjetasRFID->RowTemplate->Height = 24;
			this->dgvTarjetasRFID->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTarjetasRFID->Size = System::Drawing::Size(1045, 250);
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
			this->lblBuscar->AutoSize = true;
			this->lblBuscar->BackColor = System::Drawing::SystemColors::Control;
			this->lblBuscar->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBuscar->Location = System::Drawing::Point(35, 49);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->Size = System::Drawing::Size(359, 34);
			this->lblBuscar->TabIndex = 61;
			this->lblBuscar->Text = L"UID, cliente o documento:";
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Gadugi", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(12, 12);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(334, 40);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Administración RFID";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlTitulo
			// 
			this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pnlTitulo->Controls->Add(this->lblTitulo);
			this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitulo->Location = System::Drawing::Point(0, 0);
			this->pnlTitulo->Name = L"pnlTitulo";
			this->pnlTitulo->Size = System::Drawing::Size(1126, 65);
			this->pnlTitulo->TabIndex = 58;
			// 
			// frmAdministracionRFID
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1126, 548);
			this->Controls->Add(this->grpBuscar);
			this->Controls->Add(this->pnlTitulo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
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
