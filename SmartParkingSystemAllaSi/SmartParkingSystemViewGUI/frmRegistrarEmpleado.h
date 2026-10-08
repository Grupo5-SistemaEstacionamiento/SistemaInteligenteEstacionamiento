#pragma once

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SmartParkingSystemModel;
	using namespace SmartParkingSystemController;

	/// <summary>
	/// Summary for frmRegistrarEmpleado
	/// </summary>
	public ref class frmRegistrarEmpleado : public System::Windows::Forms::Form
	{
	public:
		frmRegistrarEmpleado(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmRegistrarEmpleado()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textCodigoEmpleado;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textNombresEmpleado;
	private: System::Windows::Forms::TextBox^ textFechaEmpleado;

	private: System::Windows::Forms::TextBox^ textApellidosEmpleado;




	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::ComboBox^ textEstadoEmpleado;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;

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
			this->textCodigoEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textNombresEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->textFechaEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->textApellidosEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->textEstadoEmpleado = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->grpBoxPrincipal->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textCodigoEmpleado
			// 
			this->textCodigoEmpleado->BackColor = System::Drawing::Color::White;
			this->textCodigoEmpleado->Location = System::Drawing::Point(206, 52);
			this->textCodigoEmpleado->Margin = System::Windows::Forms::Padding(5);
			this->textCodigoEmpleado->Name = L"textCodigoEmpleado";
			this->textCodigoEmpleado->Size = System::Drawing::Size(388, 28);
			this->textCodigoEmpleado->TabIndex = 13;
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(343, 415);
			this->btnRegresarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(166, 31);
			this->btnRegresarEdit->TabIndex = 32;
			this->btnRegresarEdit->Text = L"Cancelar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmRegistrarEmpleado::btnRegresarEdit_Click);
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(129, 415);
			this->btnGuardarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(178, 31);
			this->btnGuardarEdit->TabIndex = 34;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmRegistrarEmpleado::btnGuardarEdit_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 462);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(683, 51);
			this->panel2->TabIndex = 31;
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
			// textNombresEmpleado
			// 
			this->textNombresEmpleado->BackColor = System::Drawing::Color::White;
			this->textNombresEmpleado->Location = System::Drawing::Point(206, 101);
			this->textNombresEmpleado->Margin = System::Windows::Forms::Padding(5);
			this->textNombresEmpleado->Name = L"textNombresEmpleado";
			this->textNombresEmpleado->Size = System::Drawing::Size(388, 28);
			this->textNombresEmpleado->TabIndex = 12;
			// 
			// textFechaEmpleado
			// 
			this->textFechaEmpleado->BackColor = System::Drawing::Color::White;
			this->textFechaEmpleado->Location = System::Drawing::Point(206, 199);
			this->textFechaEmpleado->Margin = System::Windows::Forms::Padding(5);
			this->textFechaEmpleado->Name = L"textFechaEmpleado";
			this->textFechaEmpleado->Size = System::Drawing::Size(388, 28);
			this->textFechaEmpleado->TabIndex = 9;
			// 
			// textApellidosEmpleado
			// 
			this->textApellidosEmpleado->BackColor = System::Drawing::Color::White;
			this->textApellidosEmpleado->Location = System::Drawing::Point(206, 148);
			this->textApellidosEmpleado->Margin = System::Windows::Forms::Padding(5);
			this->textApellidosEmpleado->Name = L"textApellidosEmpleado";
			this->textApellidosEmpleado->Size = System::Drawing::Size(388, 28);
			this->textApellidosEmpleado->TabIndex = 2;
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->grpBoxPrincipal->Controls->Add(this->textCodigoEmpleado);
			this->grpBoxPrincipal->Controls->Add(this->textNombresEmpleado);
			this->grpBoxPrincipal->Controls->Add(this->textEstadoEmpleado);
			this->grpBoxPrincipal->Controls->Add(this->label8);
			this->grpBoxPrincipal->Controls->Add(this->textFechaEmpleado);
			this->grpBoxPrincipal->Controls->Add(this->textApellidosEmpleado);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(23, 49);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(619, 348);
			this->grpBoxPrincipal->TabIndex = 33;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Inserte la Información del Empleado";
			// 
			// textEstadoEmpleado
			// 
			this->textEstadoEmpleado->BackColor = System::Drawing::Color::White;
			this->textEstadoEmpleado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->textEstadoEmpleado->FormattingEnabled = true;
			this->textEstadoEmpleado->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"En Jornada", L"Termino Jornada" });
			this->textEstadoEmpleado->Location = System::Drawing::Point(206, 256);
			this->textEstadoEmpleado->Name = L"textEstadoEmpleado";
			this->textEstadoEmpleado->Size = System::Drawing::Size(215, 30);
			this->textEstadoEmpleado->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(14, 259);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(129, 24);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Estado Turno:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(14, 199);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(179, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Fecha Contratación:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(14, 105);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(93, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Nombres:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 148);
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
			this->label3->Size = System::Drawing::Size(168, 24);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Código Empleado:";
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
			this->label2->Size = System::Drawing::Size(169, 22);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Añadir Empleado";
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
			this->panel1->Size = System::Drawing::Size(683, 42);
			this->panel1->TabIndex = 30;
			// 
			// frmRegistrarEmpleado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(683, 513);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->btnGuardarEdit);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Controls->Add(this->panel1);
			this->Name = L"frmRegistrarEmpleado";
			this->Text = L"Añadir Nuevo Empleado";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Cancelar
		this->Close();
	}
private: System::Void btnGuardarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Guardar


	String^ Codigo = textCodigoEmpleado->Text; //Pilla los datos escritos y los covierte a una variable string
	String^ Nombres = textNombresEmpleado->Text;
	String^ Apellidos = textApellidosEmpleado->Text;
	String^ Fecha = textFechaEmpleado->Text;
	String^ Estado = textEstadoEmpleado->Text;
	// Validar los campos antes de guardar
	if (String::IsNullOrWhiteSpace(Codigo) || String::IsNullOrWhiteSpace(Nombres) || String::IsNullOrWhiteSpace(Apellidos) || String::IsNullOrWhiteSpace(Fecha) || String::IsNullOrWhiteSpace(Estado)) {
		MessageBox::Show("Por favor, complete todos los campos.", "Error: Campos Técnicos Vacíos", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// 1. Instanciar al empleado vacío (usando el constructor por defecto)
	Empleado^ nuevoEmpleado = gcnew Empleado();

	// 2. Usar los setters para guardar la información que sacaste de los TextBox
	nuevoEmpleado->setCodigoEmpleado(Codigo);
	nuevoEmpleado->setNombres(Nombres);
	nuevoEmpleado->setApellidos(Apellidos);

	// OJO: Como en tu modelo la Fecha es DateTime y el Estado es bool, debemos convertirlos:
	try {
		DateTime fechaCorrecta = DateTime::ParseExact(Fecha, "dd/MM/yyyy", System::Globalization::CultureInfo::InvariantCulture); //Conversor a formato de fecha hispano
		nuevoEmpleado->setFechaContratacion(fechaCorrecta);
		// Suponiendo que el estado lo guardas como "Activo" en la caja de texto
		bool estaEnJornada = (Estado == "En Jornada") ? true : false;
		nuevoEmpleado->setEstado(estaEnJornada);
		nuevoEmpleado->setEnTurno(estaEnJornada);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Formato de fecha inválido! \nPor favor use dd/MM/yyyy.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Evita que el programa explote si escriben letras en la fecha
	}

	// 3. Declarar el controlador
	EmpleadoController^ empleadoController = gcnew EmpleadoController();

	// 4. Validar manualmente si el ID ya existe antes de guardar
	Empleado^ empleadoExistente = empleadoController->buscarxCodigoArchivo(Codigo);

	if (empleadoExistente != nullptr) {
		// Si encontró a alguien, el ID está duplicado
		MessageBox::Show("El valor de ID ingresado ya está asociado a otro empleado.", "Error: Duplicidad de Datos", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Corta la ejecución aquí
	}

	// 5. Como es un ID nuevo y el método es void, simplemente lo mandamos a registrar
	empleadoController->registrarArchivo(nuevoEmpleado);

	// 6. Mensaje de éxito y cierre de ventana
	MessageBox::Show("Empleado agregado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close(); // Cierra el formulario actual
	
}
};
}
