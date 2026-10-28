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
	/// Summary for frmEditarVehiculo
	/// </summary>
	public ref class frmEditarVehiculo : public System::Windows::Forms::Form
	{
	public:
	public:
		int idVehiculoEditar;

		frmEditarVehiculo(int idVehiculo)
		{
			InitializeComponent();
			this->idVehiculoEditar = idVehiculo;
			this->clienteDueno = nullptr;

			try {
				VehiculoController^ controller = gcnew VehiculoController();
				Vehiculo^ v = controller->buscarxIdArchivo(this->idVehiculoEditar);

				if (v == nullptr) {
					MessageBox::Show("No se encontró el vehículo seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					this->btnGuardarEdit->Enabled = false;
					return;
				}

				this->txtID->Text = v->getIdVehiculo().ToString();
				this->txtPlaca->Text = v->getPlaca();
				this->txtMarca->Text = v->getMarca();
				this->txtModelo->Text = v->getModelo();
				this->cboColor->Text = v->getColor();
				this->txtAnotaciones->Text = v->getAnotaciones();
				this->cboTipo->SelectedIndex = (v->getTipo() == TipoVehiculo::automovil) ? 0 : 1;

				if (v->getCliente() != nullptr) {
					// Al asignar el texto se dispara TextChanged: rellena txtOwner y clienteDueno
					this->txtOwnerID->Text = v->getCliente()->getIdPersona().ToString();
				}
				else {
					mostrarEstadoDueno("Sin dueño asignado", Color::LightCoral);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar los datos del vehículo: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEditarVehiculo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	protected:
	private: System::Windows::Forms::TextBox^ txtOwner;
	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::TextBox^ txtAnotaciones;
	private: System::Windows::Forms::Label^ label15;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtModelo;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ cboTipo;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txtOwnerID;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtPlaca;
	private: System::Windows::Forms::TextBox^ txtMarca;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private: Cliente^ clienteDueno;
	private: System::Windows::Forms::ComboBox^ cboColor;

	protected:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmEditarVehiculo::typeid));
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->txtOwner = (gcnew System::Windows::Forms::TextBox());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->txtAnotaciones = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtModelo = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cboTipo = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txtOwnerID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPlaca = (gcnew System::Windows::Forms::TextBox());
			this->txtMarca = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->cboColor = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->grpBoxPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(1560, 168);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(42, 39);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 108;
			this->pictureBox3->TabStop = false;
			// 
			// txtOwner
			// 
			this->txtOwner->BackColor = System::Drawing::Color::Silver;
			this->txtOwner->Location = System::Drawing::Point(1110, 165);
			this->txtOwner->Margin = System::Windows::Forms::Padding(8);
			this->txtOwner->Name = L"txtOwner";
			this->txtOwner->ReadOnly = true;
			this->txtOwner->Size = System::Drawing::Size(438, 39);
			this->txtOwner->TabIndex = 107;
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(525, 715);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(267, 48);
			this->btnGuardarEdit->TabIndex = 49;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmEditarVehiculo::btnGuardarEdit_Click_1);
			// 
			// txtAnotaciones
			// 
			this->txtAnotaciones->BackColor = System::Drawing::Color::White;
			this->txtAnotaciones->Location = System::Drawing::Point(1110, 254);
			this->txtAnotaciones->Margin = System::Windows::Forms::Padding(8);
			this->txtAnotaciones->Name = L"txtAnotaciones";
			this->txtAnotaciones->Size = System::Drawing::Size(438, 39);
			this->txtAnotaciones->TabIndex = 33;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(866, 260);
			this->label15->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(180, 32);
			this->label15->TabIndex = 32;
			this->label15->Text = L"Anotaciones:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(21, 443);
			this->label12->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(90, 32);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Color:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(30, 22);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(467, 27);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Advertencia: No deje ningún espacio vacío";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(866, 171);
			this->label8->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(106, 32);
			this->label8->TabIndex = 106;
			this->label8->Text = L"Dueño:";
			// 
			// txtModelo
			// 
			this->txtModelo->BackColor = System::Drawing::Color::White;
			this->txtModelo->Location = System::Drawing::Point(266, 351);
			this->txtModelo->Margin = System::Windows::Forms::Padding(8);
			this->txtModelo->Name = L"txtModelo";
			this->txtModelo->Size = System::Drawing::Size(438, 39);
			this->txtModelo->TabIndex = 104;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 352);
			this->label6->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(123, 32);
			this->label6->TabIndex = 105;
			this->label6->Text = L"Modelo: ";
			// 
			// cboTipo
			// 
			this->cboTipo->BackColor = System::Drawing::Color::White;
			this->cboTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTipo->FormattingEnabled = true;
			this->cboTipo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Automovil", L"Motocicleta" });
			this->cboTipo->Location = System::Drawing::Point(1110, 343);
			this->cboTipo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboTipo->Name = L"cboTipo";
			this->cboTipo->Size = System::Drawing::Size(320, 40);
			this->cboTipo->TabIndex = 103;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(866, 348);
			this->label13->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(78, 32);
			this->label13->TabIndex = 102;
			this->label13->Text = L"Tipo:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 822);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1716, 78);
			this->panel2->TabIndex = 46;
			// 
			// txtOwnerID
			// 
			this->txtOwnerID->BackColor = System::Drawing::Color::White;
			this->txtOwnerID->Location = System::Drawing::Point(1110, 78);
			this->txtOwnerID->Margin = System::Windows::Forms::Padding(8);
			this->txtOwnerID->Name = L"txtOwnerID";
			this->txtOwnerID->Size = System::Drawing::Size(438, 39);
			this->txtOwnerID->TabIndex = 18;
			this->txtOwnerID->TextChanged += gcnew System::EventHandler(this, &frmEditarVehiculo::txtOwnerID_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(866, 85);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 32);
			this->label1->TabIndex = 17;
			this->label1->Text = L"ID Dueño:";
			// 
			// txtPlaca
			// 
			this->txtPlaca->BackColor = System::Drawing::Color::White;
			this->txtPlaca->Location = System::Drawing::Point(266, 165);
			this->txtPlaca->Margin = System::Windows::Forms::Padding(8);
			this->txtPlaca->Name = L"txtPlaca";
			this->txtPlaca->Size = System::Drawing::Size(438, 39);
			this->txtPlaca->TabIndex = 12;
			// 
			// txtMarca
			// 
			this->txtMarca->BackColor = System::Drawing::Color::White;
			this->txtMarca->Location = System::Drawing::Point(266, 262);
			this->txtMarca->Margin = System::Windows::Forms::Padding(8);
			this->txtMarca->Name = L"txtMarca";
			this->txtMarca->Size = System::Drawing::Size(438, 39);
			this->txtMarca->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 172);
			this->label5->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 32);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Placa:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 263);
			this->label4->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 32);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Marca:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 85);
			this->label3->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(167, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = L"ID Vehículo:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1716, 65);
			this->panel1->TabIndex = 45;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(219, 33);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Editar Vehículo";
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(867, 715);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(249, 48);
			this->btnRegresarEdit->TabIndex = 47;
			this->btnRegresarEdit->Text = L"Cancelar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmEditarVehiculo::btnRegresarEdit_Click);
			// 
			// txtID
			// 
			this->txtID->BackColor = System::Drawing::Color::Silver;
			this->txtID->Location = System::Drawing::Point(266, 78);
			this->txtID->Margin = System::Windows::Forms::Padding(8);
			this->txtID->Name = L"txtID";
			this->txtID->ReadOnly = true;
			this->txtID->Size = System::Drawing::Size(438, 39);
			this->txtID->TabIndex = 13;
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->grpBoxPrincipal->Controls->Add(this->cboColor);
			this->grpBoxPrincipal->Controls->Add(this->pictureBox1);
			this->grpBoxPrincipal->Controls->Add(this->pictureBox3);
			this->grpBoxPrincipal->Controls->Add(this->txtOwner);
			this->grpBoxPrincipal->Controls->Add(this->label8);
			this->grpBoxPrincipal->Controls->Add(this->txtModelo);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->cboTipo);
			this->grpBoxPrincipal->Controls->Add(this->label13);
			this->grpBoxPrincipal->Controls->Add(this->txtAnotaciones);
			this->grpBoxPrincipal->Controls->Add(this->label15);
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
			this->grpBoxPrincipal->Location = System::Drawing::Point(34, 103);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(8);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(8);
			this->grpBoxPrincipal->Size = System::Drawing::Size(1638, 557);
			this->grpBoxPrincipal->TabIndex = 48;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Inserte la Información del Vehículo";
			// 
			// cboColor
			// 
			this->cboColor->BackColor = System::Drawing::Color::White;
			this->cboColor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->cboColor->FormattingEnabled = true;
			this->cboColor->Items->AddRange(gcnew cli::array< System::Object^  >(14) {
				L"Blanco", L"Negro", L"Rojo", L"Azul", L"Amarillo",
					L"Verde", L"Naranja", L"Morado", L"Celeste", L"Turquesa", L"Marron", L"Gris", L"Beige", L"Plata"
			});
			this->cboColor->Location = System::Drawing::Point(266, 443);
			this->cboColor->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboColor->Name = L"cboColor";
			this->cboColor->Size = System::Drawing::Size(320, 40);
			this->cboColor->TabIndex = 116;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(716, 78);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(42, 39);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 109;
			this->pictureBox1->TabStop = false;
			// 
			// frmEditarVehiculo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1716, 900);
			this->Controls->Add(this->btnGuardarEdit);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmEditarVehiculo";
			this->Text = L"Modificar Vehículo";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: void mostrarEstadoDueno(String^ texto, Color fondo) { //misma hvda q en guardar
	this->txtOwner->Text = texto;
	this->txtOwner->BackColor = fondo;
}

private: System::Void txtOwnerID_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->clienteDueno = nullptr;
	String^ txt = this->txtOwnerID->Text->Trim();

	if (txt->Length == 0) { mostrarEstadoDueno("", Color::Silver); return; }

	int id;
	if (!Int32::TryParse(txt, id)) { mostrarEstadoDueno("ID inválido (solo números)", Color::LightCoral); return; }

	Cliente^ c = (gcnew ClienteController())->buscarxIdArchivo(id);
	if (c == nullptr) { mostrarEstadoDueno("Cliente inexistente", Color::LightCoral); return; }

	this->clienteDueno = c;
	mostrarEstadoDueno(c->getNombres() + " " + c->getApellidos(), Color::LightGreen);
}

private: System::Void btnGuardarEdit_Click_1(System::Object^ sender, System::EventArgs^ e) { //Guardar
	if (String::IsNullOrWhiteSpace(this->txtPlaca->Text) || String::IsNullOrWhiteSpace(this->txtMarca->Text) ||
		String::IsNullOrWhiteSpace(this->txtModelo->Text) || String::IsNullOrWhiteSpace(this->cboColor->Text) ||
		String::IsNullOrWhiteSpace(this->txtOwnerID->Text) || this->cboTipo->SelectedIndex < 0) {
		MessageBox::Show("Por favor, complete todos los campos obligatorios.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (this->clienteDueno == nullptr) {
		MessageBox::Show("El ID del dueño no corresponde a ningún cliente registrado.", "Cliente inexistente", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->txtOwnerID->Focus();
		return;
	}

	try {
		VehiculoController^ controller = gcnew VehiculoController();
		Vehiculo^ v = controller->buscarxIdArchivo(this->idVehiculoEditar);
		if (v == nullptr) {
			MessageBox::Show("El vehículo ya no existe en el sistema.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ placa = this->txtPlaca->Text->Trim()->ToUpper();
		Vehiculo^ otro = controller->buscarxPlacaArchivo(placa);
		if (otro != nullptr && otro->getIdVehiculo() != this->idVehiculoEditar) {
			MessageBox::Show("Ya existe otro vehículo registrado con esta placa.", "Error de Duplicidad", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		v->setPlaca(placa);
		v->setMarca(this->txtMarca->Text->Trim());
		v->setModelo(this->txtModelo->Text->Trim());
		v->setColor(this->cboColor->Text->Trim());
		v->setAnotaciones(this->txtAnotaciones->Text->Trim());
		v->setTipo((this->cboTipo->SelectedIndex == 0) ? TipoVehiculo::automovil : TipoVehiculo::motocicleta);
		v->setCliente(this->clienteDueno);

		controller->modificarArchivo(v);

		MessageBox::Show("Vehículo actualizado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ocurrió un error al guardar los cambios: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Cancelar
	this->Close();
}

//---------------------------------------------------------------------------------------------------
};
}
