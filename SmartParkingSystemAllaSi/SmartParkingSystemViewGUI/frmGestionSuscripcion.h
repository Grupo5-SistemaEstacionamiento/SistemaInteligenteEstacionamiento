#pragma once

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemController;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmGestionSuscripcion
	/// </summary>
	public ref class frmGestionSuscripcion : public System::Windows::Forms::Form
	{
	private:
		// Controlador encargado de gestionar las membresías.
		MembresiaController^ membresiaController;

		// Lista de clientes mostrados en el ComboBox.
		List<Cliente^>^ clientes;

		// Indica si el formulario trabaja en modo edición.
		bool modoEdicion;

		// ID de la membresía que se está editando.
		int idMembresiaEditar;

	private:
		// Carga los clientes registrados en el ComboBox.
		void cargarClientes()
		{
			cmbCliente->Items->Clear();

			clientes =
				membresiaController->listarClientes();

			for each (Cliente ^ cliente in clientes)
			{
				String^ nombreCompleto =
					cliente->getNombres() + " " +
					cliente->getApellidos();

				// Se agrega solamente el nombre visible.
				cmbCliente->Items->Add(nombreCompleto);
			}

			// Selecciona el primer cliente cuando exista alguno.
			if (cmbCliente->Items->Count > 0)
			{
				cmbCliente->SelectedIndex = 0;
			}
		}

	private:
		// Carga los tipos de membresía disponibles.
		void cargarTiposMembresia()
		{
			cmbTipoMembresia->Items->Clear();

			cmbTipoMembresia->Items->Add("Regular");
			cmbTipoMembresia->Items->Add("Premium");

			cmbTipoMembresia->SelectedIndex = 0;
		}

	private:
		// Prepara el formulario para registrar una nueva suscripción.
		void prepararNuevaSuscripcion()
		{
			modoEdicion = false;
			idMembresiaEditar = 0;

			// Genera automáticamente el ID.
			txtIdMembresia->Text =
				membresiaController->obtenerSiguienteId().ToString();

			// Establece fechas iniciales.
			dtpFechaInicio->Value = DateTime::Today;
			dtpFechaFin->Value = DateTime::Today.AddMonths(1);

			// Valores iniciales.
			txtDescuento->Clear();
			txtPrecio->Clear();

			this->Text = "Nueva Suscripción";
		}

		// Carga en el formulario los datos de la membresía que será modificada.
		void cargarMembresiaEditar()
		{
			Membresia^ membresia =
				membresiaController->buscarMembresiaPorId(
					idMembresiaEditar
				);

			// Verifica que la membresía exista.
			if (membresia == nullptr)
			{
				MessageBox::Show(
					"No se encontró la suscripción seleccionada.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);

				return;
			}

			// Muestra el ID sin permitir modificarlo.
			txtIdMembresia->Text =
				membresia->getIdMembresia().ToString();

			// Busca en la lista el cliente asociado.
			for (int i = 0; i < clientes->Count; i++)
			{
				if (clientes[i]->getIdPersona() ==
					membresia->getIdCliente())
				{
					cmbCliente->SelectedIndex = i;
					break;
				}
			}

			// Selecciona el tipo de membresía.
			if (membresia->getTipo() ==
				TipoMembresia::Premium)
			{
				cmbTipoMembresia->SelectedItem = "Premium";
			}
			else
			{
				cmbTipoMembresia->SelectedItem = "Regular";
			}

			// Carga las fechas existentes.
			dtpFechaInicio->Value =
				membresia->getFechaInicio();

			dtpFechaFin->Value =
				membresia->getFechaFin();

			// Muestra los valores con dos decimales.
			txtDescuento->Text =
				membresia->getPorcentajeDescuento().ToString("F2");

			txtPrecio->Text =
				membresia->getPrecio().ToString("F2");

			// Cambia el título para identificar el modo edición.
			this->Text = "Editar Suscripción";

			// El ID permanece bloqueado.
			txtIdMembresia->ReadOnly = true;

			// El cliente asociado permanece visible,
			// pero no puede modificarse durante la edición.
			cmbCliente->Enabled = false;
		}

	public:
		frmGestionSuscripcion(void)
		{
			InitializeComponent();

			// Inicializa el controlador.
			membresiaController =
				gcnew MembresiaController();

			// Inicializa la lista de clientes.
			clientes =
				gcnew List<Cliente^>();

			// Carga la información necesaria.
			cargarClientes();
			cargarTiposMembresia();

			// Prepara el formulario para un nuevo registro.
			prepararNuevaSuscripcion();
		}

		// Constructor utilizado para editar una suscripción existente.
		frmGestionSuscripcion(int idMembresia)
		{
			InitializeComponent();

			// Inicializa el controlador.
			membresiaController =
				gcnew MembresiaController();

			// Inicializa la lista de clientes.
			clientes =
				gcnew List<Cliente^>();

			// Activa el modo edición.
			modoEdicion = true;
			idMembresiaEditar = idMembresia;

			// Carga los datos necesarios para los ComboBox.
			cargarClientes();
			cargarTiposMembresia();

			// Carga los datos de la membresía seleccionada.
			cargarMembresiaEditar();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmGestionSuscripcion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtIdMembresia;
	protected:

	protected:







	private: System::Windows::Forms::TextBox^ txtDescuento;
	private: System::Windows::Forms::TextBox^ txtPrecio;




	private: System::Windows::Forms::ComboBox^ cmbCliente;
	private: System::Windows::Forms::ComboBox^ cmbTipoMembresia;
	private: System::Windows::Forms::DateTimePicker^ dtpFechaInicio;
	private: System::Windows::Forms::DateTimePicker^ dtpFechaFin;
	private: System::Windows::Forms::Label^ lblPrecio;













	private: System::Windows::Forms::Label^ lblDescuento;
	private: System::Windows::Forms::Label^ lblFechaFin;



	private: System::Windows::Forms::Label^ lblFechaInicio;

	private: System::Windows::Forms::Label^ lblTipoMembresia;

	private: System::Windows::Forms::Label^ lblCliente;

	private: System::Windows::Forms::Label^ lblIdMembresia;
	private: System::Windows::Forms::Button^ btnCancelar;

	private: System::Windows::Forms::Button^ btnGuardar;



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
			this->txtIdMembresia = (gcnew System::Windows::Forms::TextBox());
			this->txtDescuento = (gcnew System::Windows::Forms::TextBox());
			this->txtPrecio = (gcnew System::Windows::Forms::TextBox());
			this->cmbCliente = (gcnew System::Windows::Forms::ComboBox());
			this->cmbTipoMembresia = (gcnew System::Windows::Forms::ComboBox());
			this->dtpFechaInicio = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpFechaFin = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblPrecio = (gcnew System::Windows::Forms::Label());
			this->lblDescuento = (gcnew System::Windows::Forms::Label());
			this->lblFechaFin = (gcnew System::Windows::Forms::Label());
			this->lblFechaInicio = (gcnew System::Windows::Forms::Label());
			this->lblTipoMembresia = (gcnew System::Windows::Forms::Label());
			this->lblCliente = (gcnew System::Windows::Forms::Label());
			this->lblIdMembresia = (gcnew System::Windows::Forms::Label());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->btnGuardar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtIdMembresia
			// 
			this->txtIdMembresia->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdMembresia->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIdMembresia->Location = System::Drawing::Point(354, 70);
			this->txtIdMembresia->Margin = System::Windows::Forms::Padding(4);
			this->txtIdMembresia->Name = L"txtIdMembresia";
			this->txtIdMembresia->ReadOnly = true;
			this->txtIdMembresia->Size = System::Drawing::Size(200, 42);
			this->txtIdMembresia->TabIndex = 66;
			// 
			// txtDescuento
			// 
			this->txtDescuento->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtDescuento->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDescuento->Location = System::Drawing::Point(354, 314);
			this->txtDescuento->Margin = System::Windows::Forms::Padding(4);
			this->txtDescuento->Name = L"txtDescuento";
			this->txtDescuento->Size = System::Drawing::Size(200, 42);
			this->txtDescuento->TabIndex = 76;
			// 
			// txtPrecio
			// 
			this->txtPrecio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtPrecio->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPrecio->Location = System::Drawing::Point(354, 364);
			this->txtPrecio->Margin = System::Windows::Forms::Padding(4);
			this->txtPrecio->Name = L"txtPrecio";
			this->txtPrecio->Size = System::Drawing::Size(200, 42);
			this->txtPrecio->TabIndex = 78;
			// 
			// cmbCliente
			// 
			this->cmbCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbCliente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCliente->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbCliente->FormattingEnabled = true;
			this->cmbCliente->Location = System::Drawing::Point(354, 119);
			this->cmbCliente->Name = L"cmbCliente";
			this->cmbCliente->Size = System::Drawing::Size(200, 43);
			this->cmbCliente->TabIndex = 79;
			// 
			// cmbTipoMembresia
			// 
			this->cmbTipoMembresia->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipoMembresia->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipoMembresia->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbTipoMembresia->FormattingEnabled = true;
			this->cmbTipoMembresia->Location = System::Drawing::Point(354, 168);
			this->cmbTipoMembresia->Name = L"cmbTipoMembresia";
			this->cmbTipoMembresia->Size = System::Drawing::Size(200, 43);
			this->cmbTipoMembresia->TabIndex = 80;
			// 
			// dtpFechaInicio
			// 
			this->dtpFechaInicio->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtpFechaInicio->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dtpFechaInicio->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->dtpFechaInicio->CalendarTitleForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->dtpFechaInicio->Enabled = false;
			this->dtpFechaInicio->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpFechaInicio->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaInicio->Location = System::Drawing::Point(354, 217);
			this->dtpFechaInicio->Name = L"dtpFechaInicio";
			this->dtpFechaInicio->Size = System::Drawing::Size(200, 42);
			this->dtpFechaInicio->TabIndex = 88;
			// 
			// dtpFechaFin
			// 
			this->dtpFechaFin->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpFechaFin->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dtpFechaFin->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->dtpFechaFin->CalendarTitleForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->dtpFechaFin->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dtpFechaFin->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaFin->Location = System::Drawing::Point(354, 265);
			this->dtpFechaFin->Name = L"dtpFechaFin";
			this->dtpFechaFin->Size = System::Drawing::Size(200, 42);
			this->dtpFechaFin->TabIndex = 89;
			// 
			// lblPrecio
			// 
			this->lblPrecio->AutoSize = true;
			this->lblPrecio->BackColor = System::Drawing::SystemColors::Control;
			this->lblPrecio->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrecio->Location = System::Drawing::Point(60, 369);
			this->lblPrecio->Name = L"lblPrecio";
			this->lblPrecio->Size = System::Drawing::Size(160, 34);
			this->lblPrecio->TabIndex = 96;
			this->lblPrecio->Text = L"Precio (S/):";
			// 
			// lblDescuento
			// 
			this->lblDescuento->AutoSize = true;
			this->lblDescuento->BackColor = System::Drawing::SystemColors::Control;
			this->lblDescuento->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDescuento->Location = System::Drawing::Point(60, 319);
			this->lblDescuento->Name = L"lblDescuento";
			this->lblDescuento->Size = System::Drawing::Size(213, 34);
			this->lblDescuento->TabIndex = 95;
			this->lblDescuento->Text = L"Descuento (%):";
			// 
			// lblFechaFin
			// 
			this->lblFechaFin->AutoSize = true;
			this->lblFechaFin->BackColor = System::Drawing::SystemColors::Control;
			this->lblFechaFin->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFechaFin->Location = System::Drawing::Point(60, 273);
			this->lblFechaFin->Name = L"lblFechaFin";
			this->lblFechaFin->Size = System::Drawing::Size(142, 34);
			this->lblFechaFin->TabIndex = 94;
			this->lblFechaFin->Text = L"Fecha fin:";
			// 
			// lblFechaInicio
			// 
			this->lblFechaInicio->AutoSize = true;
			this->lblFechaInicio->BackColor = System::Drawing::SystemColors::Control;
			this->lblFechaInicio->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFechaInicio->Location = System::Drawing::Point(60, 225);
			this->lblFechaInicio->Name = L"lblFechaInicio";
			this->lblFechaInicio->Size = System::Drawing::Size(177, 34);
			this->lblFechaInicio->TabIndex = 93;
			this->lblFechaInicio->Text = L"Fecha inicio:";
			// 
			// lblTipoMembresia
			// 
			this->lblTipoMembresia->AutoSize = true;
			this->lblTipoMembresia->BackColor = System::Drawing::SystemColors::Control;
			this->lblTipoMembresia->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTipoMembresia->Location = System::Drawing::Point(60, 173);
			this->lblTipoMembresia->Name = L"lblTipoMembresia";
			this->lblTipoMembresia->Size = System::Drawing::Size(234, 34);
			this->lblTipoMembresia->TabIndex = 92;
			this->lblTipoMembresia->Text = L"Tipo membresía:";
			// 
			// lblCliente
			// 
			this->lblCliente->AutoSize = true;
			this->lblCliente->BackColor = System::Drawing::SystemColors::Control;
			this->lblCliente->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCliente->Location = System::Drawing::Point(60, 124);
			this->lblCliente->Name = L"lblCliente";
			this->lblCliente->Size = System::Drawing::Size(114, 34);
			this->lblCliente->TabIndex = 91;
			this->lblCliente->Text = L"Cliente:";
			// 
			// lblIdMembresia
			// 
			this->lblIdMembresia->AutoSize = true;
			this->lblIdMembresia->BackColor = System::Drawing::SystemColors::Control;
			this->lblIdMembresia->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIdMembresia->Location = System::Drawing::Point(60, 75);
			this->lblIdMembresia->Name = L"lblIdMembresia";
			this->lblIdMembresia->Size = System::Drawing::Size(206, 34);
			this->lblIdMembresia->TabIndex = 90;
			this->lblIdMembresia->Text = L"ID membresía:";
			// 
			// btnCancelar
			// 
			this->btnCancelar->AutoSize = true;
			this->btnCancelar->BackColor = System::Drawing::Color::Red;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(354, 453);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(4);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(145, 53);
			this->btnCancelar->TabIndex = 98;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmGestionSuscripcion::btnCancelar_Click);
			// 
			// btnGuardar
			// 
			this->btnGuardar->AutoSize = true;
			this->btnGuardar->BackColor = System::Drawing::Color::ForestGreen;
			this->btnGuardar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardar->ForeColor = System::Drawing::Color::White;
			this->btnGuardar->Location = System::Drawing::Point(131, 453);
			this->btnGuardar->Margin = System::Windows::Forms::Padding(4);
			this->btnGuardar->Name = L"btnGuardar";
			this->btnGuardar->Size = System::Drawing::Size(135, 53);
			this->btnGuardar->TabIndex = 97;
			this->btnGuardar->Text = L"Guardar";
			this->btnGuardar->UseVisualStyleBackColor = false;
			this->btnGuardar->Click += gcnew System::EventHandler(this, &frmGestionSuscripcion::btnGuardar_Click);
			// 
			// frmGestionSuscripcion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(632, 573);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGuardar);
			this->Controls->Add(this->lblPrecio);
			this->Controls->Add(this->lblDescuento);
			this->Controls->Add(this->lblFechaFin);
			this->Controls->Add(this->lblFechaInicio);
			this->Controls->Add(this->lblTipoMembresia);
			this->Controls->Add(this->lblCliente);
			this->Controls->Add(this->lblIdMembresia);
			this->Controls->Add(this->dtpFechaFin);
			this->Controls->Add(this->dtpFechaInicio);
			this->Controls->Add(this->cmbTipoMembresia);
			this->Controls->Add(this->cmbCliente);
			this->Controls->Add(this->txtPrecio);
			this->Controls->Add(this->txtDescuento);
			this->Controls->Add(this->txtIdMembresia);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmGestionSuscripcion";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gestión de Suscripción";
			this->Load += gcnew System::EventHandler(this, &frmGestionSuscripcion::frmGestionSuscripcion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmGestionSuscripcion_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verifica que exista un cliente seleccionado.
		if (cmbCliente->SelectedIndex < 0)
		{
			MessageBox::Show(
				"Debe seleccionar un cliente para asociarlo a una membresía.",
				"Registro de datos - Cliente",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
			return;
		}

		// Verifica que exista un tipo de membresía seleccionado.
		if (cmbTipoMembresia->SelectedIndex < 0)
		{
			MessageBox::Show(
				"Debe seleccionar un tipo de membresía.",
				"Registro de datos - Membresía",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
			return;
		}

		// La fecha de fin debe ser posterior a la fecha de inicio.
		if (dtpFechaFin->Value.Date <= dtpFechaInicio->Value.Date)
		{
			MessageBox::Show(
				"La fecha de fin debe ser posterior a la fecha de inicio.",
				"Registro de datos - Fecha fin",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		// Verifica que se haya ingresado el descuento.
		if (String::IsNullOrWhiteSpace(txtDescuento->Text))
		{
			MessageBox::Show(
				"Debe ingresar el descuento de la membresía asociada.",
				"Registro de datos - Descuento",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			txtDescuento->Focus();
			return;
		}

		// Verifica que se haya ingresado el precio.
		if (String::IsNullOrWhiteSpace(txtPrecio->Text))
		{
			MessageBox::Show(
				"Debe ingresar el precio de la membresía asociada.",
				"Registro de datos - Precio",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			txtPrecio->Focus();
			return;
		}

		// Valida que el descuento sea numérico.
		double descuento;

		if (!Double::TryParse(txtDescuento->Text, descuento))
		{
			MessageBox::Show(
				"Ingrese un valor de descuento válido.",
				"Registro de datos - Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);

			txtDescuento->Focus();
			return;
		}

		// Valida que el precio sea numérico.
		double precio;

		if (!Double::TryParse(txtPrecio->Text, precio))
		{
			MessageBox::Show(
				"Ingrese un valor de precio válido.",
				"Registro de datos - Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);

			txtPrecio->Focus();
			return;
		}

		// El descuento debe estar entre 0 % y 100 %.
		if (descuento < 0 || descuento > 100)
		{
			MessageBox::Show(
				"El descuento debe estar entre 0 y 100.",
				"Registro de datos - Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);

			txtDescuento->Focus();
			return;
		}

		// El precio no puede ser negativo.
		if (precio < 0)
		{
			MessageBox::Show(
				"El precio no puede ser negativo.",
				"Registro de datos - Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);

			txtPrecio->Focus();
			return;
		}

		// Recupera el cliente seleccionado.
		// El índice del ComboBox corresponde al índice de la lista clientes.
		int indiceCliente = cmbCliente->SelectedIndex;

		if (indiceCliente >= clientes->Count)
		{
			MessageBox::Show(
				"No se pudo identificar al cliente seleccionado.",
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		Cliente^ clienteSeleccionado =
			clientes[indiceCliente];

		// En una nueva suscripción, verifica que el cliente
		// no tenga actualmente otra membresía activa.
		if (!modoEdicion &&
			membresiaController->clienteTieneMembresiaActiva(
				clienteSeleccionado->getIdPersona()))
		{
			MessageBox::Show(
				"El cliente seleccionado ya posee una suscripción activa.\n\n"
				"Para registrar una nueva suscripción, primero debe"
				" cancelar la suscripción actual del cliente.",
				"Suscripción activa",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			return;
		}

		// Determina el tipo de membresía.
		TipoMembresia tipo;

		if (cmbTipoMembresia->SelectedItem->ToString() == "Premium")
		{
			tipo = TipoMembresia::Premium;
		}
		else
		{
			tipo = TipoMembresia::Regular;
		}

		// Determina el ID que se utilizará.
		int idMembresia =
			Convert::ToInt32(txtIdMembresia->Text);

		// Construye la membresía con los datos del formulario.
		Membresia^ membresia =
			gcnew Membresia(
				idMembresia,
				clienteSeleccionado->getIdPersona(),
				dtpFechaInicio->Value.Date,
				dtpFechaFin->Value.Date,
				descuento,
				true,
				precio,
				tipo
			);

		bool operacionCorrecta;

		// Decide si debe registrar o modificar.
		if (modoEdicion)
		{
			operacionCorrecta =
				membresiaController->modificarMembresia(
					membresia
				);
		}
		else
		{
			operacionCorrecta =
				membresiaController->registrarMembresia(
					membresia
				);
		}

		// Verifica el resultado.
		if (operacionCorrecta)
		{
			String^ mensaje;

			if (modoEdicion)
			{
				mensaje =
					"La suscripción fue modificada correctamente.";
			}
			else
			{
				mensaje =
					"La suscripción fue registrada correctamente.";
			}

			MessageBox::Show(
				mensaje,
				"Operación exitosa",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			// Informa al formulario anterior que hubo cambios.
			this->DialogResult =
				System::Windows::Forms::DialogResult::OK;

			this->Close();
		}
		else
		{
			String^ mensajeError;

			if (modoEdicion)
			{
				mensajeError =
					"No se pudo modificar la suscripción.";
			}
			else
			{
				mensajeError =
					"No se pudo registrar la suscripción.";
			}

			MessageBox::Show(
				mensajeError,
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Cierra la ventana sin guardar cambios.
		this->DialogResult =
			System::Windows::Forms::DialogResult::Cancel;

		this->Close();
	}
	};
}
