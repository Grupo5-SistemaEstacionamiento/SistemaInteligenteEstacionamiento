#pragma once

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;
	using namespace SmartParkingSystemController;
	using namespace SmartParkingSystemModel;

	/// <summary>
	/// Summary for frmEditarCliente
	/// </summary>
	public ref class frmEditarCliente : public System::Windows::Forms::Form
	{
	public:

		int idClienteEditar;

		frmEditarCliente(int idCliente)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->idClienteEditar = idCliente;

			try {
				SmartParkingSystemController::ClienteController^ controller = gcnew SmartParkingSystemController::ClienteController();

				Cliente^ clienteEdit = controller->buscarxIdArchivo(this->idClienteEditar);

				if (clienteEdit != nullptr) {

					this->txtID->Text = Convert::ToString(clienteEdit->getIdPersona());
					this->txtSaldo->Text = Convert::ToString(clienteEdit->getSaldo());
					this->dtpAfiliacion->Value = clienteEdit->getFechaAfiliacion();
					this->txtNombres->Text = clienteEdit->getNombres();
					this->txtApellidos->Text = clienteEdit->getApellidos();
					this->txtDocumento->Text = clienteEdit->getDocumento();
					this->txtTelefono->Text = clienteEdit->getTelefono();
					this->txtCorreo->Text = clienteEdit->getCorreo();
					this->txtPassword->Text = clienteEdit->getClaveHash();
					this->txtObservaciones->Text = clienteEdit->getObservaciones();

					this->cboSuscripcion->Text = (clienteEdit->getTipo() == TipoCliente::Miembro) ? "Miembro" : "Normal";
					this->cboEstado->Text = clienteEdit->getEstado() ? "Activo" : "Inactivo";

					// Lógica del CheckBox de Discapacidad
					this->chboReqPref->Checked = clienteEdit->getRequierePreferencial();
					if (clienteEdit->getRequierePreferencial()) {
						this->txtDiscapacidad->Enabled = true;
						this->txtDiscapacidad->Visible = true;
						this->lblDiscapacidad->Visible = true;
						this->txtDiscapacidad->Text = clienteEdit->getDiscapacidad();
					}
					else {
						this->txtDiscapacidad->Enabled = false;
						this->txtDiscapacidad->Visible = false;
						this->lblDiscapacidad->Visible = false;
						this->txtDiscapacidad->Clear();
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar los datos del cliente.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEditarCliente()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtObservaciones;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ txtDiscapacidad;
	private: System::Windows::Forms::Label^ lblDiscapacidad;
	private: System::Windows::Forms::ComboBox^ cboSuscripcion;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ txtDocumento;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ txtSaldo;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::CheckBox^ chboReqPref;
	private: System::Windows::Forms::TextBox^ txtTelefono;
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtCorreo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ dtpAfiliacion;

	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::TextBox^ txtNombres;
	private: System::Windows::Forms::ComboBox^ cboEstado;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtApellidos;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Button^ btnGuardarEdit;
private: System::Windows::Forms::PictureBox^ pictureBox2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmEditarCliente::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtObservaciones = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtDiscapacidad = (gcnew System::Windows::Forms::TextBox());
			this->lblDiscapacidad = (gcnew System::Windows::Forms::Label());
			this->cboSuscripcion = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtDocumento = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txtSaldo = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->chboReqPref = (gcnew System::Windows::Forms::CheckBox());
			this->txtTelefono = (gcnew System::Windows::Forms::TextBox());
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dtpAfiliacion = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->txtNombres = (gcnew System::Windows::Forms::TextBox());
			this->cboEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtApellidos = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			this->grpBoxPrincipal->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(8, 12);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(134, 22);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Editar Cliente";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1144, 42);
			this->panel1->TabIndex = 40;
			// 
			// txtObservaciones
			// 
			this->txtObservaciones->BackColor = System::Drawing::Color::White;
			this->txtObservaciones->Location = System::Drawing::Point(719, 170);
			this->txtObservaciones->Margin = System::Windows::Forms::Padding(5);
			this->txtObservaciones->Name = L"txtObservaciones";
			this->txtObservaciones->Size = System::Drawing::Size(293, 28);
			this->txtObservaciones->TabIndex = 33;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(556, 174);
			this->label15->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(142, 24);
			this->label15->TabIndex = 32;
			this->label15->Text = L"Observaciones:";
			// 
			// txtDiscapacidad
			// 
			this->txtDiscapacidad->BackColor = System::Drawing::Color::White;
			this->txtDiscapacidad->Location = System::Drawing::Point(719, 400);
			this->txtDiscapacidad->Margin = System::Windows::Forms::Padding(5);
			this->txtDiscapacidad->Name = L"txtDiscapacidad";
			this->txtDiscapacidad->Size = System::Drawing::Size(293, 28);
			this->txtDiscapacidad->TabIndex = 31;
			// 
			// lblDiscapacidad
			// 
			this->lblDiscapacidad->AutoSize = true;
			this->lblDiscapacidad->Location = System::Drawing::Point(556, 403);
			this->lblDiscapacidad->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lblDiscapacidad->Name = L"lblDiscapacidad";
			this->lblDiscapacidad->Size = System::Drawing::Size(128, 24);
			this->lblDiscapacidad->TabIndex = 30;
			this->lblDiscapacidad->Text = L"Discapacidad:";
			// 
			// cboSuscripcion
			// 
			this->cboSuscripcion->BackColor = System::Drawing::Color::White;
			this->cboSuscripcion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSuscripcion->FormattingEnabled = true;
			this->cboSuscripcion->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Normal", L"Miembro" });
			this->cboSuscripcion->Location = System::Drawing::Point(719, 229);
			this->cboSuscripcion->Name = L"cboSuscripcion";
			this->cboSuscripcion->Size = System::Drawing::Size(215, 30);
			this->cboSuscripcion->TabIndex = 29;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(556, 232);
			this->label13->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(114, 24);
			this->label13->TabIndex = 28;
			this->label13->Text = L"Suscripción:";
			// 
			// txtDocumento
			// 
			this->txtDocumento->BackColor = System::Drawing::Color::White;
			this->txtDocumento->Location = System::Drawing::Point(177, 231);
			this->txtDocumento->Margin = System::Windows::Forms::Padding(5);
			this->txtDocumento->Name = L"txtDocumento";
			this->txtDocumento->Size = System::Drawing::Size(293, 28);
			this->txtDocumento->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(14, 235);
			this->label12->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(113, 24);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Documento:";
			// 
			// txtSaldo
			// 
			this->txtSaldo->BackColor = System::Drawing::Color::White;
			this->txtSaldo->Location = System::Drawing::Point(177, 343);
			this->txtSaldo->Margin = System::Windows::Forms::Padding(5);
			this->txtSaldo->Name = L"txtSaldo";
			this->txtSaldo->Size = System::Drawing::Size(293, 28);
			this->txtSaldo->TabIndex = 25;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(14, 347);
			this->label11->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(63, 24);
			this->label11->TabIndex = 24;
			this->label11->Text = L"Saldo:";
			// 
			// chboReqPref
			// 
			this->chboReqPref->AutoSize = true;
			this->chboReqPref->Location = System::Drawing::Point(18, 399);
			this->chboReqPref->Name = L"chboReqPref";
			this->chboReqPref->Size = System::Drawing::Size(212, 28);
			this->chboReqPref->TabIndex = 23;
			this->chboReqPref->Text = L"Requiere Preferencial";
			this->chboReqPref->UseVisualStyleBackColor = true;
			this->chboReqPref->CheckStateChanged += gcnew System::EventHandler(this, &frmEditarCliente::chboReqPref_CheckedChanged);
			// 
			// txtTelefono
			// 
			this->txtTelefono->BackColor = System::Drawing::Color::White;
			this->txtTelefono->Location = System::Drawing::Point(177, 289);
			this->txtTelefono->Margin = System::Windows::Forms::Padding(5);
			this->txtTelefono->Name = L"txtTelefono";
			this->txtTelefono->Size = System::Drawing::Size(293, 28);
			this->txtTelefono->TabIndex = 22;
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(583, 548);
			this->btnRegresarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(166, 31);
			this->btnRegresarEdit->TabIndex = 42;
			this->btnRegresarEdit->Text = L"Cancelar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmEditarCliente::btnRegresarEdit_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->grpBoxPrincipal->Controls->Add(this->pictureBox2);
			this->grpBoxPrincipal->Controls->Add(this->txtObservaciones);
			this->grpBoxPrincipal->Controls->Add(this->label15);
			this->grpBoxPrincipal->Controls->Add(this->txtDiscapacidad);
			this->grpBoxPrincipal->Controls->Add(this->lblDiscapacidad);
			this->grpBoxPrincipal->Controls->Add(this->cboSuscripcion);
			this->grpBoxPrincipal->Controls->Add(this->label13);
			this->grpBoxPrincipal->Controls->Add(this->txtDocumento);
			this->grpBoxPrincipal->Controls->Add(this->label12);
			this->grpBoxPrincipal->Controls->Add(this->txtSaldo);
			this->grpBoxPrincipal->Controls->Add(this->label11);
			this->grpBoxPrincipal->Controls->Add(this->chboReqPref);
			this->grpBoxPrincipal->Controls->Add(this->txtTelefono);
			this->grpBoxPrincipal->Controls->Add(this->label10);
			this->grpBoxPrincipal->Controls->Add(this->txtPassword);
			this->grpBoxPrincipal->Controls->Add(this->label9);
			this->grpBoxPrincipal->Controls->Add(this->txtCorreo);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Controls->Add(this->dtpAfiliacion);
			this->grpBoxPrincipal->Controls->Add(this->txtID);
			this->grpBoxPrincipal->Controls->Add(this->txtNombres);
			this->grpBoxPrincipal->Controls->Add(this->cboEstado);
			this->grpBoxPrincipal->Controls->Add(this->label8);
			this->grpBoxPrincipal->Controls->Add(this->txtApellidos);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(23, 67);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(1092, 454);
			this->grpBoxPrincipal->TabIndex = 43;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Inserte la Información del Cliente";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(14, 292);
			this->label10->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(90, 24);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Teléfono:";
			// 
			// txtPassword
			// 
			this->txtPassword->BackColor = System::Drawing::Color::White;
			this->txtPassword->Location = System::Drawing::Point(719, 109);
			this->txtPassword->Margin = System::Windows::Forms::Padding(5);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(293, 28);
			this->txtPassword->TabIndex = 20;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(556, 113);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(111, 24);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Contraseña:";
			// 
			// txtCorreo
			// 
			this->txtCorreo->BackColor = System::Drawing::Color::White;
			this->txtCorreo->Location = System::Drawing::Point(719, 51);
			this->txtCorreo->Margin = System::Windows::Forms::Padding(5);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(293, 28);
			this->txtCorreo->TabIndex = 18;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(556, 55);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 24);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Correo:";
			// 
			// dtpAfiliacion
			// 
			this->dtpAfiliacion->CustomFormat = L"dd/MM/yyyy";
			this->dtpAfiliacion->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpAfiliacion->Location = System::Drawing::Point(719, 289);
			this->dtpAfiliacion->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->dtpAfiliacion->Name = L"dtpAfiliacion";
			this->dtpAfiliacion->Size = System::Drawing::Size(215, 28);
			this->dtpAfiliacion->TabIndex = 16;
			this->dtpAfiliacion->Value = System::DateTime(2026, 10, 22, 0, 0, 0, 0);
			// 
			// txtID
			// 
			this->txtID->BackColor = System::Drawing::Color::Silver;
			this->txtID->Location = System::Drawing::Point(177, 51);
			this->txtID->Margin = System::Windows::Forms::Padding(5);
			this->txtID->Name = L"txtID";
			this->txtID->ReadOnly = true;
			this->txtID->Size = System::Drawing::Size(293, 28);
			this->txtID->TabIndex = 13;
			// 
			// txtNombres
			// 
			this->txtNombres->BackColor = System::Drawing::Color::White;
			this->txtNombres->Location = System::Drawing::Point(177, 107);
			this->txtNombres->Margin = System::Windows::Forms::Padding(5);
			this->txtNombres->Name = L"txtNombres";
			this->txtNombres->Size = System::Drawing::Size(293, 28);
			this->txtNombres->TabIndex = 12;
			// 
			// cboEstado
			// 
			this->cboEstado->BackColor = System::Drawing::Color::White;
			this->cboEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboEstado->FormattingEnabled = true;
			this->cboEstado->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Activo", L"Inactivo" });
			this->cboEstado->Location = System::Drawing::Point(719, 343);
			this->cboEstado->Name = L"cboEstado";
			this->cboEstado->Size = System::Drawing::Size(215, 30);
			this->cboEstado->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(556, 343);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(73, 24);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Estado:";
			// 
			// txtApellidos
			// 
			this->txtApellidos->BackColor = System::Drawing::Color::White;
			this->txtApellidos->Location = System::Drawing::Point(177, 170);
			this->txtApellidos->Margin = System::Windows::Forms::Padding(5);
			this->txtApellidos->Name = L"txtApellidos";
			this->txtApellidos->Size = System::Drawing::Size(293, 28);
			this->txtApellidos->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(556, 289);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(149, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Fecha Afiliación:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(14, 112);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Nombres:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 171);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(93, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Apellidos:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 55);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 24);
			this->label3->TabIndex = 0;
			this->label3->Text = L"ID Cliente:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 596);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1144, 51);
			this->panel2->TabIndex = 41;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(20, 14);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(302, 18);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Advertencia: No deje ningún espacio vacío";
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(355, 548);
			this->btnGuardarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(178, 31);
			this->btnGuardarEdit->TabIndex = 44;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmEditarCliente::btnGuardarEdit_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(481, 53);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(29, 26);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 97;
			this->pictureBox2->TabStop = false;
			// 
			// frmEditarCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1144, 647);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->btnGuardarEdit);
			this->Name = L"frmEditarCliente";
			this->Text = L"Modificar Cliente";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnGuardarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Guardar
		if (String::IsNullOrWhiteSpace(this->txtNombres->Text) || String::IsNullOrWhiteSpace(this->txtApellidos->Text) || String::IsNullOrWhiteSpace(this->txtDocumento->Text) || String::IsNullOrWhiteSpace(this->txtTelefono->Text) || String::IsNullOrWhiteSpace(this->txtCorreo->Text) || String::IsNullOrWhiteSpace(this->txtPassword->Text)) {

			MessageBox::Show("Por favor, complete todos los campos obligatorios.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			SmartParkingSystemController::ClienteController^ controller = gcnew SmartParkingSystemController::ClienteController();
			Cliente^ clienteEdit = controller->buscarxIdArchivo(this->idClienteEditar);

			if (clienteEdit != nullptr) {

				clienteEdit->setNombres(this->txtNombres->Text);
				clienteEdit->setApellidos(this->txtApellidos->Text);
				clienteEdit->setDocumento(this->txtDocumento->Text);
				clienteEdit->setTelefono(this->txtTelefono->Text);
				clienteEdit->setCorreo(this->txtCorreo->Text);
				clienteEdit->setClaveHash(this->txtPassword->Text);
				clienteEdit->setObservaciones(this->txtObservaciones->Text);

				clienteEdit->setFechaAfiliacion(this->dtpAfiliacion->Value);

				double nuevoSaldo = 0.0;
				try {
					nuevoSaldo = Convert::ToDouble(this->txtSaldo->Text);
				}
				catch (...) {
					//nuevoSaldo = clienteEdit->getSaldo(); // Si hay error, conservamos el saldo anterior
					MessageBox::Show("Se ha producido un error al registrar el saldo, \npor favor vuelva a intentarlo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error );
					return;
				}
				clienteEdit->setSaldo(nuevoSaldo);

				clienteEdit->setSaldo(nuevoSaldo);

				clienteEdit->setEstado(this->cboEstado->Text == "Activo");
				clienteEdit->setTipo((this->cboSuscripcion->Text == "Miembro") ? TipoCliente::Miembro : TipoCliente::Normal);

				bool requierePref = this->chboReqPref->Checked;
				clienteEdit->setRequierePreferencial(requierePref);
				clienteEdit->setDiscapacidad(requierePref ? this->txtDiscapacidad->Text : String::Empty);

				controller->modificarArchivo(this->idClienteEditar, clienteEdit);

				MessageBox::Show("Cliente actualizado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ocurrió un error al intentar guardar los cambios.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Cancelar
	this->Close();
}

private: System::Void chboReqPref_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { //Behaviour de la checkbox
	if (this->chboReqPref->Checked) {
		this->lblDiscapacidad->Show();
		this->txtDiscapacidad->Show();
		this->txtDiscapacidad->Enabled = true;
		this->txtDiscapacidad->Focus();
	}
	else {
		// Bloquea y limpia el texto para evitar guardar "fantasmas"
		this->lblDiscapacidad->Hide();
		this->txtDiscapacidad->Hide();
		this->txtDiscapacidad->Enabled = false;
		this->txtDiscapacidad->Clear();
	}
}

};
}
