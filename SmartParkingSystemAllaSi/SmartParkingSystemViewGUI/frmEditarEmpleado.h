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
	/// Summary for frmEditarEmpleado
	/// </summary>
	public ref class frmEditarEmpleado : public System::Windows::Forms::Form
	{
	public:
		frmEditarEmpleado(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		frmEditarEmpleado(String^ codigoSeleccionado)
		{
			InitializeComponent(); //Al iniciar la pantalla de editar empleado se abre con los campos ya llenos
			
			EmpleadoController^ Controller = gcnew EmpleadoController();
			Empleado^ empleado = Controller->buscarxCodigoArchivo(codigoSeleccionado);

			if (empleado != nullptr) {
				this->textCodigoEmpleado->Text = empleado->getCodigoEmpleado();
				this->textNombresEmpleado->Text = empleado->getNombres();
				this->textApellidosEmpleado->Text = empleado->getApellidos();
				this->textFechaEmpleado->Text = empleado->getFechaContratacion().ToString("dd/MM/yyyy", System::Globalization::CultureInfo::InvariantCulture);
				this->textEstadoEmpleado->SelectedIndex = empleado->getEnTurno() ? 0 : 1;
			}
			else {
				MessageBox::Show("No se encontró en el archivo a nadie con el código exacto: '" + codigoSeleccionado + "'", "Aviso de Carga", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEditarEmpleado()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ textEstadoEmpleado;





	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textFechaEmpleado;


	private: System::Windows::Forms::TextBox^ textApellidosEmpleado;





	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textCodigoEmpleado;
	private: System::Windows::Forms::TextBox^ textNombresEmpleado;



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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textEstadoEmpleado = (gcnew System::Windows::Forms::ComboBox());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->textCodigoEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->textNombresEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textFechaEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->textApellidosEmpleado = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->grpBoxPrincipal->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1025, 65);
			this->panel1->TabIndex = 25;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(239, 33);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Editar Empleado";
			// 
			// textEstadoEmpleado
			// 
			this->textEstadoEmpleado->BackColor = System::Drawing::Color::White;
			this->textEstadoEmpleado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->textEstadoEmpleado->FormattingEnabled = true;
			this->textEstadoEmpleado->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"En Jornada", L"Termino Jornada" });
			this->textEstadoEmpleado->Location = System::Drawing::Point(309, 394);
			this->textEstadoEmpleado->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textEstadoEmpleado->Name = L"textEstadoEmpleado";
			this->textEstadoEmpleado->Size = System::Drawing::Size(320, 40);
			this->textEstadoEmpleado->TabIndex = 11;
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
			this->grpBoxPrincipal->Location = System::Drawing::Point(35, 75);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(8);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(8);
			this->grpBoxPrincipal->Size = System::Drawing::Size(928, 535);
			this->grpBoxPrincipal->TabIndex = 28;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Edite la Informacion del Empleado";
			this->grpBoxPrincipal->Enter += gcnew System::EventHandler(this, &frmEditarEmpleado::grpBoxPrincipal_Enter);
			// 
			// textCodigoEmpleado
			// 
			this->textCodigoEmpleado->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->textCodigoEmpleado->Location = System::Drawing::Point(309, 80);
			this->textCodigoEmpleado->Margin = System::Windows::Forms::Padding(8);
			this->textCodigoEmpleado->Name = L"textCodigoEmpleado";
			this->textCodigoEmpleado->ReadOnly = true;
			this->textCodigoEmpleado->Size = System::Drawing::Size(580, 39);
			this->textCodigoEmpleado->TabIndex = 13;
			this->textCodigoEmpleado->TextChanged += gcnew System::EventHandler(this, &frmEditarEmpleado::textBox3_TextChanged);
			// 
			// textNombresEmpleado
			// 
			this->textNombresEmpleado->BackColor = System::Drawing::Color::White;
			this->textNombresEmpleado->Location = System::Drawing::Point(309, 155);
			this->textNombresEmpleado->Margin = System::Windows::Forms::Padding(8);
			this->textNombresEmpleado->Name = L"textNombresEmpleado";
			this->textNombresEmpleado->Size = System::Drawing::Size(580, 39);
			this->textNombresEmpleado->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 399);
			this->label8->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(192, 32);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Estado Turno:";
			this->label8->Click += gcnew System::EventHandler(this, &frmEditarEmpleado::label8_Click);
			// 
			// textFechaEmpleado
			// 
			this->textFechaEmpleado->BackColor = System::Drawing::Color::White;
			this->textFechaEmpleado->Location = System::Drawing::Point(309, 306);
			this->textFechaEmpleado->Margin = System::Windows::Forms::Padding(8);
			this->textFechaEmpleado->Name = L"textFechaEmpleado";
			this->textFechaEmpleado->Size = System::Drawing::Size(580, 39);
			this->textFechaEmpleado->TabIndex = 9;
			// 
			// textApellidosEmpleado
			// 
			this->textApellidosEmpleado->BackColor = System::Drawing::Color::White;
			this->textApellidosEmpleado->Location = System::Drawing::Point(309, 228);
			this->textApellidosEmpleado->Margin = System::Windows::Forms::Padding(8);
			this->textApellidosEmpleado->Name = L"textApellidosEmpleado";
			this->textApellidosEmpleado->Size = System::Drawing::Size(580, 39);
			this->textApellidosEmpleado->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 306);
			this->label6->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(270, 32);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Fecha Contratacion:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 161);
			this->label5->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(136, 32);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Nombres:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 228);
			this->label4->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 32);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Apellidos:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 85);
			this->label3->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(249, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Codigo Empleado:";
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(514, 639);
			this->btnRegresarEdit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(249, 48);
			this->btnRegresarEdit->TabIndex = 27;
			this->btnRegresarEdit->Text = L"Cancelar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmEditarEmpleado::btnRegresarEdit_Click);
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(194, 639);
			this->btnGuardarEdit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(267, 48);
			this->btnGuardarEdit->TabIndex = 29;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmEditarEmpleado::btnGuardarEdit_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 710);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1025, 79);
			this->panel2->TabIndex = 26;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(30, 21);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(466, 27);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Advertencia: No deje ningun espacio vacio";
			// 
			// frmEditarEmpleado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1025, 789);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->btnGuardarEdit);
			this->Controls->Add(this->panel2);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmEditarEmpleado";
			this->Text = L"Editar Información Empleado";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Cancelar
		this->Close();
	}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
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
	Empleado^ empleadoEditado = gcnew Empleado();

	// 2. Usar los setters para guardar la información que sacaste de los TextBox
	empleadoEditado->setCodigoEmpleado(Codigo);
	empleadoEditado->setNombres(Nombres);
	empleadoEditado->setApellidos(Apellidos);

	// OJO: Como en tu modelo la Fecha es DateTime y el Estado es bool, debemos convertirlos:
	try {
		DateTime fechaCorrecta = DateTime::ParseExact(Fecha, "dd/MM/yyyy", System::Globalization::CultureInfo::InvariantCulture); //Conversor a formato de fecha hispano
		empleadoEditado->setFechaContratacion(fechaCorrecta);

		bool estaEnJornada = (Estado == "En Jornada") ? true : false;
		empleadoEditado->setEstado(estaEnJornada);
		empleadoEditado->setEnTurno(estaEnJornada);
	}
	catch (Exception^ ex) {
		MessageBox::Show("Formato de fecha inválido! \nPor favor use dd/MM/yyyy.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Evita que el programa explote si escriben letras en la fecha
	}

	// 3. Declarar el controlador
	EmpleadoController^ empleadoController = gcnew EmpleadoController();

	// 4. Validar manualmente si el ID ya existe antes de guardar
	Empleado^ empleadoExistente = empleadoController->buscarxCodigoArchivo(Codigo);

	if (empleadoExistente == nullptr) {
		MessageBox::Show("No se encontró ningún empleado con este código.", "Error: Duplicidad de Búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return; // Corta la ejecución aquí
	}

	// 5. Como es un ID nuevo y el método es void, simplemente lo mandamos a registrar
	empleadoController->modificarArchivo(empleadoEditado);

	// 6. Mensaje de éxito y cierre de ventana
	MessageBox::Show("Empleado modificado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close(); // Cierra el formulario actual

}
private: System::Void grpBoxPrincipal_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
