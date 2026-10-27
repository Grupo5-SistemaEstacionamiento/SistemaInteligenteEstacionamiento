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
	/// Summary for frmNuevoVehiculo
	/// </summary>
	public ref class frmNuevoVehiculo : public System::Windows::Forms::Form
	{
	public:
		frmNuevoVehiculo(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->clienteDueno = nullptr;
			this->cboTipo->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmNuevoVehiculo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txtAnotaciones;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ txtColor;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::TextBox^ txtPlaca;
	private: System::Windows::Forms::TextBox^ txtMarca;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::TextBox^ txtOwnerID;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cboTipo;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ txtModelo;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtOwner;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	private: Cliente^ clienteDueno;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmNuevoVehiculo::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txtAnotaciones = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtColor = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->txtOwner = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtModelo = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cboTipo = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtOwnerID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->txtPlaca = (gcnew System::Windows::Forms::TextBox());
			this->txtMarca = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->grpBoxPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel2->SuspendLayout();
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
			this->label2->Size = System::Drawing::Size(156, 22);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Añadir Vehículo";
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
			// txtAnotaciones
			// 
			this->txtAnotaciones->BackColor = System::Drawing::Color::White;
			this->txtAnotaciones->Location = System::Drawing::Point(740, 165);
			this->txtAnotaciones->Margin = System::Windows::Forms::Padding(5);
			this->txtAnotaciones->Name = L"txtAnotaciones";
			this->txtAnotaciones->Size = System::Drawing::Size(293, 28);
			this->txtAnotaciones->TabIndex = 33;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(577, 169);
			this->label15->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(120, 24);
			this->label15->TabIndex = 32;
			this->label15->Text = L"Anotaciones:";
			// 
			// txtColor
			// 
			this->txtColor->BackColor = System::Drawing::Color::White;
			this->txtColor->Location = System::Drawing::Point(177, 284);
			this->txtColor->Margin = System::Windows::Forms::Padding(5);
			this->txtColor->Name = L"txtColor";
			this->txtColor->Size = System::Drawing::Size(293, 28);
			this->txtColor->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(14, 288);
			this->label12->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(60, 24);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Color:";
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(578, 465);
			this->btnRegresarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(166, 31);
			this->btnRegresarEdit->TabIndex = 42;
			this->btnRegresarEdit->Text = L"Cancelar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmNuevoVehiculo::btnRegresarEdit_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->grpBoxPrincipal->Controls->Add(this->pictureBox3);
			this->grpBoxPrincipal->Controls->Add(this->txtOwner);
			this->grpBoxPrincipal->Controls->Add(this->label8);
			this->grpBoxPrincipal->Controls->Add(this->txtModelo);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->cboTipo);
			this->grpBoxPrincipal->Controls->Add(this->label13);
			this->grpBoxPrincipal->Controls->Add(this->txtAnotaciones);
			this->grpBoxPrincipal->Controls->Add(this->label15);
			this->grpBoxPrincipal->Controls->Add(this->txtColor);
			this->grpBoxPrincipal->Controls->Add(this->label12);
			this->grpBoxPrincipal->Controls->Add(this->txtOwnerID);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Controls->Add(this->txtID);
			this->grpBoxPrincipal->Controls->Add(this->txtPlaca);
			this->grpBoxPrincipal->Controls->Add(this->txtMarca);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(23, 67);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(1092, 362);
			this->grpBoxPrincipal->TabIndex = 43;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Inserte la Información del Vehículo";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(1040, 109);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(29, 26);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 108;
			this->pictureBox3->TabStop = false;
			// 
			// txtOwner
			// 
			this->txtOwner->BackColor = System::Drawing::Color::Silver;
			this->txtOwner->Location = System::Drawing::Point(740, 107);
			this->txtOwner->Margin = System::Windows::Forms::Padding(5);
			this->txtOwner->Name = L"txtOwner";
			this->txtOwner->ReadOnly = true;
			this->txtOwner->Size = System::Drawing::Size(293, 28);
			this->txtOwner->TabIndex = 107;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(577, 111);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 24);
			this->label8->TabIndex = 106;
			this->label8->Text = L"Dueño:";
			// 
			// txtModelo
			// 
			this->txtModelo->BackColor = System::Drawing::Color::White;
			this->txtModelo->Location = System::Drawing::Point(177, 228);
			this->txtModelo->Margin = System::Windows::Forms::Padding(5);
			this->txtModelo->Name = L"txtModelo";
			this->txtModelo->Size = System::Drawing::Size(293, 28);
			this->txtModelo->TabIndex = 104;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(14, 229);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 24);
			this->label6->TabIndex = 105;
			this->label6->Text = L"Modelo: ";
			// 
			// cboTipo
			// 
			this->cboTipo->BackColor = System::Drawing::Color::White;
			this->cboTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTipo->FormattingEnabled = true;
			this->cboTipo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Automovil", L"Motocicleta" });
			this->cboTipo->Location = System::Drawing::Point(740, 223);
			this->cboTipo->Name = L"cboTipo";
			this->cboTipo->Size = System::Drawing::Size(215, 30);
			this->cboTipo->TabIndex = 103;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(577, 226);
			this->label13->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(53, 24);
			this->label13->TabIndex = 102;
			this->label13->Text = L"Tipo:";
			// 
			// txtOwnerID
			// 
			this->txtOwnerID->BackColor = System::Drawing::Color::White;
			this->txtOwnerID->Location = System::Drawing::Point(740, 51);
			this->txtOwnerID->Margin = System::Windows::Forms::Padding(5);
			this->txtOwnerID->Name = L"txtOwnerID";
			this->txtOwnerID->Size = System::Drawing::Size(293, 28);
			this->txtOwnerID->TabIndex = 18;
			this->txtOwnerID->TextChanged += gcnew System::EventHandler(this, &frmNuevoVehiculo::txtOwnerID_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(577, 55);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 24);
			this->label1->TabIndex = 17;
			this->label1->Text = L"ID Dueño:";
			// 
			// txtID
			// 
			this->txtID->BackColor = System::Drawing::Color::White;
			this->txtID->Location = System::Drawing::Point(177, 51);
			this->txtID->Margin = System::Windows::Forms::Padding(5);
			this->txtID->Name = L"txtID";
			this->txtID->Size = System::Drawing::Size(293, 28);
			this->txtID->TabIndex = 13;
			// 
			// txtPlaca
			// 
			this->txtPlaca->BackColor = System::Drawing::Color::White;
			this->txtPlaca->Location = System::Drawing::Point(177, 107);
			this->txtPlaca->Margin = System::Windows::Forms::Padding(5);
			this->txtPlaca->Name = L"txtPlaca";
			this->txtPlaca->Size = System::Drawing::Size(293, 28);
			this->txtPlaca->TabIndex = 12;
			// 
			// txtMarca
			// 
			this->txtMarca->BackColor = System::Drawing::Color::White;
			this->txtMarca->Location = System::Drawing::Point(177, 170);
			this->txtMarca->Margin = System::Windows::Forms::Padding(5);
			this->txtMarca->Name = L"txtMarca";
			this->txtMarca->Size = System::Drawing::Size(293, 28);
			this->txtMarca->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(14, 112);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Placa:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 171);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Marca:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 55);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 24);
			this->label3->TabIndex = 0;
			this->label3->Text = L"ID Vehículo:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 534);
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
			this->btnGuardarEdit->Location = System::Drawing::Point(350, 465);
			this->btnGuardarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(178, 31);
			this->btnGuardarEdit->TabIndex = 44;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmNuevoVehiculo::btnGuardarEdit_Click);
			// 
			// frmNuevoVehiculo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1144, 585);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->btnGuardarEdit);
			this->Name = L"frmNuevoVehiculo";
			this->Text = L"Registrar Vehiculo";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnGuardarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Guardar

		if (String::IsNullOrWhiteSpace(this->txtID->Text) || String::IsNullOrWhiteSpace(this->txtPlaca->Text) ||
			String::IsNullOrWhiteSpace(this->txtMarca->Text) || String::IsNullOrWhiteSpace(this->txtModelo->Text) ||
			String::IsNullOrWhiteSpace(this->txtColor->Text) || String::IsNullOrWhiteSpace(this->txtOwnerID->Text) ||
			this->cboTipo->SelectedIndex < 0) {
			MessageBox::Show("Por favor, complete todos los campos obligatorios antes de guardar.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (this->clienteDueno == nullptr) {
			MessageBox::Show("El ID del dueño no corresponde a ningún cliente registrado.", "Cliente inexistente", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->txtOwnerID->Focus();
			return;
		}

		try {
			int idVehiculo = Convert::ToInt32(this->txtID->Text->Trim());
			String^ placa = this->txtPlaca->Text->Trim()->ToUpper();
			String^ marca = this->txtMarca->Text->Trim();
			String^ modelo = this->txtModelo->Text->Trim();
			String^ color = this->txtColor->Text->Trim();
			String^ anotaciones = this->txtAnotaciones->Text->Trim()->Replace(";", ",");

			TipoVehiculo tipo = (this->cboTipo->SelectedIndex == 0) ? TipoVehiculo::automovil : TipoVehiculo::motocicleta;

			VehiculoController^ controller = gcnew VehiculoController();

			if (controller->buscarxIdArchivo(idVehiculo) != nullptr) {
				MessageBox::Show("Ya existe un vehículo con ese ID.", "Error de Duplicidad", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (controller->buscarxPlacaArchivo(placa) != nullptr) {
				MessageBox::Show("Ya existe un vehículo registrado con esta placa.", "Error de Duplicidad", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			Vehiculo^ nuevo = gcnew Vehiculo();
			nuevo->setIdVehiculo(idVehiculo);
			nuevo->setPlaca(placa);
			nuevo->setMarca(marca);
			nuevo->setModelo(modelo);
			nuevo->setColor(color);
			nuevo->setTipo(tipo);
			nuevo->setAnotaciones(anotaciones);
			nuevo->setCliente(this->clienteDueno);

			controller->registrarArchivo(nuevo);

			MessageBox::Show("Vehículo registrado exitosamente en el sistema.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
		catch (FormatException^) {
			MessageBox::Show("El ID Vehículo debe ser un número entero.", "Error de Formato", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ocurrió un error inesperado: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Cancelar
	this->Close();
}

private: void mostrarEstadoDueno(String^ texto, Color fondo) {
	this->txtOwner->Text = texto;
	this->txtOwner->BackColor = fondo;
}

private: System::Void txtOwnerID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->clienteDueno = nullptr;
	String^ txt = this->txtOwnerID->Text->Trim();

	if (txt->Length == 0) { mostrarEstadoDueno("", Color::Silver); return; } //Si no hay texto se muestra vacio y gris (Silver)

	int id;
	if (!Int32::TryParse(txt, id)) { mostrarEstadoDueno("ID inválido (solo números)", Color::LightCoral); return; } //SI colocan letras mostramos esto

	ClienteController^ Controller = gcnew ClienteController();
	Cliente^ c = Controller->buscarxIdArchivo(id);

	if (c == nullptr) { mostrarEstadoDueno("Cliente inexistente", Color::LightCoral); return; } //Si no se encuentra el ID se muestra esto

	this->clienteDueno = c;
	mostrarEstadoDueno(c->getNombres() + " " + c->getApellidos(), Color::LightGreen); //Si sí existe imprimimos sus nombres y apellidos
}


//---------------------------------------------------------------------------------------------
};
}
