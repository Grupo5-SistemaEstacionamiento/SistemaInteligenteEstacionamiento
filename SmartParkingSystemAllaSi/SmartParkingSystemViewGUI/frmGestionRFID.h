#pragma once

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
	/// Resumen de frmGestionRFID
	/// </summary>
	public ref class frmGestionRFID : public System::Windows::Forms::Form
	{
	private:
		SmartParkingSystemController::TarjetaRFIDController^ tarjetaRFIDController;
		SmartParkingSystemController::ClienteController^ clienteController;

		// Indica si el formulario se utiliza para editar una tarjeta.
		bool modoEdicion;

		// ID de la tarjeta que se está editando.
		int idTarjeta;

		// Carga los clientes registrados en el ComboBox.
	private:
		void cargarClientes()
		{
			cmbCliente->Items->Clear();

			List<Cliente^>^ clientes =
				clienteController->listarClientes();

			for each (Cliente ^ cliente in clientes)
			{
				// Muestra nombre completo y documento del cliente.
				String^ textoCliente =
					cliente->getNombres() + " " +
					cliente->getApellidos() + " - " +
					cliente->getDocumento();

				cmbCliente->Items->Add(textoCliente);
			}

			// Evita seleccionar automáticamente un cliente.
			cmbCliente->SelectedIndex = -1;
		}

		// Selecciona en el ComboBox al cliente asociado a la tarjeta.
	private:
		void seleccionarCliente(int idCliente)
		{
			List<Cliente^>^ clientes =
				clienteController->listarClientes();

			for (int i = 0; i < clientes->Count; i++)
			{
				if (clientes[i]->getIdPersona() == idCliente)
				{
					cmbCliente->SelectedIndex = i;
					return;
				}
			}

			cmbCliente->SelectedIndex = -1;
		}

		// Configura el formulario para asociar una nueva tarjeta RFID.
	private:
		void configurarModoNuevo()
		{
			this->Text = "Asociar RFID";

			modoEdicion = false;
			idTarjeta = 0;

			txtCodigoUID->Clear();

			dtpFechaEmision->Value =
				DateTime::Now;

			dtpFechaVencimiento->Value =
				DateTime::Now.AddYears(1);

			txtEstado->Text = "Activa";

			cmbCliente->SelectedIndex = -1;
		}

		// Carga los datos de una tarjeta RFID para su edición.
	private:
		void cargarTarjeta()
		{
			TarjetaRFID^ tarjeta =
				tarjetaRFIDController->buscarPorId(idTarjeta);

			if (tarjeta == nullptr)
			{
				MessageBox::Show(
					"No se encontró la tarjeta RFID seleccionada.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);

				this->DialogResult =
					System::Windows::Forms::DialogResult::Cancel;

				this->Close();
				return;
			}

			txtCodigoUID->Text =
				tarjeta->getCodigoUID();

			seleccionarCliente(
				tarjeta->getIdCliente()
			);

			dtpFechaEmision->Value =
				tarjeta->getFechaEmision();

			dtpFechaVencimiento->Value =
				tarjeta->getFechaVencimiento();

			txtEstado->Text =
				tarjeta->estaActiva()
				? "Activa"
				: "Inactiva";
		}

	public:
		// Constructor para asociar una nueva tarjeta RFID.
		frmGestionRFID(void)
		{
			InitializeComponent();

			// Inicializa los controladores necesarios.
			tarjetaRFIDController =
				gcnew SmartParkingSystemController::TarjetaRFIDController();

			clienteController =
				gcnew SmartParkingSystemController::ClienteController();

			// Carga los clientes disponibles.
			cargarClientes();

			// Configura el formulario en modo nuevo.
			configurarModoNuevo();
		}


		// Constructor para editar una tarjeta RFID existente.
		frmGestionRFID(int idTarjeta)
		{
			InitializeComponent();

			// Inicializa los controladores necesarios.
			tarjetaRFIDController =
				gcnew SmartParkingSystemController::TarjetaRFIDController();

			clienteController =
				gcnew SmartParkingSystemController::ClienteController();

			this->modoEdicion = true;
			this->idTarjeta = idTarjeta;

			this->Text = "Editar RFID";

			// El cliente asociado no puede modificarse durante la edición.
			cmbCliente->Enabled = false;

			// Carga los clientes disponibles.
			cargarClientes();

			// Carga la información de la tarjeta seleccionada.
			cargarTarjeta();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmGestionRFID()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCancelar;
	protected:
	private: System::Windows::Forms::Button^ btnGuardar;
	private: System::Windows::Forms::Label^ lblCodigoUID;
	private: System::Windows::Forms::Label^ lblEstado;


	private: System::Windows::Forms::Label^ lblFechaVencimiento;

	private: System::Windows::Forms::Label^ lblFechaEmision;


	private: System::Windows::Forms::Label^ lblCliente;

	private: System::Windows::Forms::DateTimePicker^ dtpFechaVencimiento;


	private: System::Windows::Forms::DateTimePicker^ dtpFechaEmision;


	private: System::Windows::Forms::ComboBox^ cmbCliente;
	private: System::Windows::Forms::TextBox^ txtCodigoUID;
	private: System::Windows::Forms::TextBox^ txtEstado;





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
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->lblCodigoUID = (gcnew System::Windows::Forms::Label());
			this->lblEstado = (gcnew System::Windows::Forms::Label());
			this->lblFechaVencimiento = (gcnew System::Windows::Forms::Label());
			this->lblFechaEmision = (gcnew System::Windows::Forms::Label());
			this->lblCliente = (gcnew System::Windows::Forms::Label());
			this->dtpFechaVencimiento = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpFechaEmision = (gcnew System::Windows::Forms::DateTimePicker());
			this->cmbCliente = (gcnew System::Windows::Forms::ComboBox());
			this->txtCodigoUID = (gcnew System::Windows::Forms::TextBox());
			this->txtEstado = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnCancelar
			// 
			this->btnCancelar->AutoSize = true;
			this->btnCancelar->BackColor = System::Drawing::Color::Red;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(358, 356);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(4);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(145, 53);
			this->btnCancelar->TabIndex = 114;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmGestionRFID::btnCancelar_Click);
			// 
			// btnGuardar
			// 
			this->btnGuardar->AutoSize = true;
			this->btnGuardar->BackColor = System::Drawing::Color::ForestGreen;
			this->btnGuardar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardar->ForeColor = System::Drawing::Color::White;
			this->btnGuardar->Location = System::Drawing::Point(138, 356);
			this->btnGuardar->Margin = System::Windows::Forms::Padding(4);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(135, 53);
			this->btnGuardar->TabIndex = 113;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = false;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmGestionRFID::btnGuardar_Click);
			// 
			// lblCodigoUID
			// 
			this->lblCodigoUID->AutoSize = true;
			this->lblCodigoUID->BackColor = System::Drawing::SystemColors::Control;
			this->lblCodigoUID->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCodigoUID->Location = System::Drawing::Point(67, 78);
			this->lblCodigoUID->Name = L"lblCodigoUID";
			this->lblCodigoUID->Size = System::Drawing::Size(265, 34);
			this->lblCodigoUID->TabIndex = 112;
			this->lblCodigoUID->Text = L"UID / Código RFID:";
			// 
			// lblEstado
			// 
			this->lblEstado->AutoSize = true;
			this->lblEstado->BackColor = System::Drawing::SystemColors::Control;
			this->lblEstado->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstado->Location = System::Drawing::Point(67, 272);
			this->lblEstado->Name = L"lblEstado";
			this->lblEstado->Size = System::Drawing::Size(110, 34);
			this->lblEstado->TabIndex = 111;
			this->lblEstado->Text = L"Estado:";
			// 
			// lblFechaVencimiento
			// 
			this->lblFechaVencimiento->AutoSize = true;
			this->lblFechaVencimiento->BackColor = System::Drawing::SystemColors::Control;
			this->lblFechaVencimiento->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFechaVencimiento->Location = System::Drawing::Point(67, 226);
			this->lblFechaVencimiento->Name = L"lblFechaVencimiento";
			this->lblFechaVencimiento->Size = System::Drawing::Size(268, 34);
			this->lblFechaVencimiento->TabIndex = 110;
			this->lblFechaVencimiento->Text = L"Fecha vencimiento:";
			// 
			// lblFechaEmision
			// 
			this->lblFechaEmision->AutoSize = true;
			this->lblFechaEmision->BackColor = System::Drawing::SystemColors::Control;
			this->lblFechaEmision->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFechaEmision->Location = System::Drawing::Point(67, 178);
			this->lblFechaEmision->Name = L"lblFechaEmision";
			this->lblFechaEmision->Size = System::Drawing::Size(209, 34);
			this->lblFechaEmision->TabIndex = 109;
			this->lblFechaEmision->Text = L"Fecha emisión:";
			// 
			// lblCliente
			// 
			this->lblCliente->AutoSize = true;
			this->lblCliente->BackColor = System::Drawing::SystemColors::Control;
			this->lblCliente->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCliente->Location = System::Drawing::Point(67, 126);
			this->lblCliente->Name = L"lblCliente";
			this->lblCliente->Size = System::Drawing::Size(114, 34);
			this->lblCliente->TabIndex = 107;
			this->lblCliente->Text = L"Cliente:";
			// 
			// dtpFechaVencimiento
			// 
			this->dtpFechaVencimiento->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtpFechaVencimiento->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dtpFechaVencimiento->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->dtpFechaVencimiento->CalendarTitleForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->dtpFechaVencimiento->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtpFechaVencimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaVencimiento->Location = System::Drawing::Point(361, 218);
			this->dtpFechaVencimiento->Name = L"dtpFechaVencimiento";
			this->dtpFechaVencimiento->Size = System::Drawing::Size(200, 42);
			this->dtpFechaVencimiento->TabIndex = 105;
			// 
			// dtpFechaEmision
			// 
			this->dtpFechaEmision->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtpFechaEmision->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dtpFechaEmision->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->dtpFechaEmision->CalendarTitleForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->dtpFechaEmision->Enabled = false;
			this->dtpFechaEmision->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpFechaEmision->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaEmision->Location = System::Drawing::Point(361, 170);
			this->dtpFechaEmision->Name = L"dtpFechaEmision";
			this->dtpFechaEmision->Size = System::Drawing::Size(200, 42);
			this->dtpFechaEmision->TabIndex = 104;
			// 
			// cmbCliente
			// 
			this->cmbCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbCliente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCliente->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbCliente->FormattingEnabled = true;
			this->cmbCliente->Location = System::Drawing::Point(361, 121);
			this->cmbCliente->Name = L"cmbCliente";
			this->cmbCliente->Size = System::Drawing::Size(200, 43);
			this->cmbCliente->TabIndex = 102;
			// 
			// txtCodigoUID
			// 
			this->txtCodigoUID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCodigoUID->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtCodigoUID->Location = System::Drawing::Point(361, 73);
			this->txtCodigoUID->Margin = System::Windows::Forms::Padding(4);
			this->txtCodigoUID->Name = L"txtCodigoUID";
			this->txtCodigoUID->Size = System::Drawing::Size(200, 42);
			this->txtCodigoUID->TabIndex = 101;
			// 
			// txtEstado
			// 
			this->txtEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtEstado->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEstado->Location = System::Drawing::Point(361, 267);
			this->txtEstado->Margin = System::Windows::Forms::Padding(4);
			this->txtEstado->Name = L"txtEstado";
			this->txtEstado->ReadOnly = true;
			this->txtEstado->Size = System::Drawing::Size(200, 42);
			this->txtEstado->TabIndex = 100;
			// 
			// frmGestionRFID
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 483);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->lblCodigoUID);
			this->Controls->Add(this->lblEstado);
			this->Controls->Add(this->lblFechaVencimiento);
			this->Controls->Add(this->lblFechaEmision);
			this->Controls->Add(this->lblCliente);
			this->Controls->Add(this->dtpFechaVencimiento);
			this->Controls->Add(this->dtpFechaEmision);
			this->Controls->Add(this->cmbCliente);
			this->Controls->Add(this->txtCodigoUID);
			this->Controls->Add(this->txtEstado);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmGestionRFID";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Gestión RFID";
			this->Load += gcnew System::EventHandler(this, &frmGestionRFID::frmGestionRFID_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmGestionRFID_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   // Cierra el formulario sin guardar cambios.
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->DialogResult =
			System::Windows::Forms::DialogResult::Cancel;

		this->Close();
	}
		   // Guarda una nueva tarjeta RFID o los cambios realizados.
	private:
		System::Void btnGuardar_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			// Valida que se haya ingresado un código UID.
			if (String::IsNullOrWhiteSpace(txtCodigoUID->Text))
			{
				MessageBox::Show(
					"Debe ingresar el código UID de la tarjeta RFID.",
					"Registro de datos - Código UID",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				txtCodigoUID->Focus();
				return;
			}

			// Valida que se haya seleccionado un cliente.
			if (cmbCliente->SelectedIndex < 0)
			{
				MessageBox::Show(
					"Debe seleccionar un cliente.",
					"Registro de datos - Cliente",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				cmbCliente->Focus();
				return;
			}

			// Valida la fecha de vencimiento.
			if (dtpFechaVencimiento->Value.Date <= DateTime::Now.Date)
			{
				MessageBox::Show(
					"La fecha de vencimiento debe ser posterior a la fecha actual.",
					"Registro de datos - Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);

				dtpFechaVencimiento->Focus();
				return;
			}

			// Obtiene el cliente seleccionado.
			List<Cliente^>^ clientes =
				clienteController->listarClientes();

			if (cmbCliente->SelectedIndex >= clientes->Count)
			{
				MessageBox::Show(
					"No se pudo obtener el cliente seleccionado.",
					"Error del sistema",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			Cliente^ clienteSeleccionado =
				clientes[cmbCliente->SelectedIndex];

			String^ codigoUID =
				txtCodigoUID->Text->Trim();

			// Evita que un cliente posea más de una tarjeta RFID activa.
			int idExcluir =
				modoEdicion ? idTarjeta : 0;

			if (tarjetaRFIDController->clienteTieneTarjetaActiva(
				clienteSeleccionado->getIdPersona(),
				idExcluir))
			{
				MessageBox::Show(
					"El cliente seleccionado ya posee una tarjeta RFID activa.\n\n"
					"Para asociar una nueva tarjeta, primero debe"
					" desactivar la tarjeta actual del cliente.",
					"Tarjeta RFID activa",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				cmbCliente->Focus();
				return;
			}

			bool resultado = false;

			if (!modoEdicion)
			{
				// Registra y asocia una nueva tarjeta RFID.
				resultado =
					tarjetaRFIDController->registrarTarjeta(
						clienteSeleccionado->getIdPersona(),
						codigoUID,
						dtpFechaVencimiento->Value
					);
			}
			else
			{
				// Modifica únicamente los datos editables
				// de la tarjeta RFID seleccionada.
				resultado =
					tarjetaRFIDController->modificarTarjeta(
						idTarjeta,
						codigoUID,
						dtpFechaVencimiento->Value
					);
			}

			if (!resultado)
			{
				MessageBox::Show(
					modoEdicion
					? "No se pudo modificar la tarjeta RFID. "
					"Verifique que el UID no pertenezca a otra tarjeta."
					: "No se pudo asociar la tarjeta RFID. "
					"Verifique que el UID no esté registrado.",
					"Error del sistema",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);

				return;
			}

			MessageBox::Show(
				modoEdicion
				? "Tarjeta RFID modificada correctamente."
				: "Tarjeta RFID asociada correctamente.",
				"Operación exitosa",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			this->DialogResult =
				System::Windows::Forms::DialogResult::OK;

			this->Close();
		}
	};
}
