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
	/// Summary for frmBuscar
	/// </summary>
	public ref class frmBuscar : public System::Windows::Forms::Form
	{
	public:

		int idSeleccionado; 

		frmBuscar(void)
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
		~frmBuscar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:




	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ TextBuscarCliente;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ TextBuscarPlaca;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::PictureBox^ btnMoreCliente;
	private: System::Windows::Forms::PictureBox^ btnMorePlaca;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmBuscar::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnMoreCliente = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->TextBuscarCliente = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnMorePlaca = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->TextBuscarPlaca = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMoreCliente))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMorePlaca))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox1->Controls->Add(this->btnMoreCliente);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Controls->Add(this->TextBuscarCliente);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->groupBox1->Location = System::Drawing::Point(124, 166);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(996, 145);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Buscar Cliente:";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmBuscar::groupBox1_Enter);
			// 
			// btnMoreCliente
			// 
			this->btnMoreCliente->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnMoreCliente->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnMoreCliente->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnMoreCliente->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMoreCliente.Image")));
			this->btnMoreCliente->Location = System::Drawing::Point(852, 78);
			this->btnMoreCliente->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMoreCliente->Name = L"btnMoreCliente";
			this->btnMoreCliente->Size = System::Drawing::Size(42, 40);
			this->btnMoreCliente->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->btnMoreCliente->TabIndex = 50;
			this->btnMoreCliente->TabStop = false;
			this->btnMoreCliente->Click += gcnew System::EventHandler(this, &frmBuscar::btnMoreCliente_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(790, 78);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(42, 40);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 39;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &frmBuscar::pictureBox1_Click);
			// 
			// TextBuscarCliente
			// 
			this->TextBuscarCliente->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TextBuscarCliente->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBuscarCliente->Location = System::Drawing::Point(285, 78);
			this->TextBuscarCliente->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TextBuscarCliente->Name = L"TextBuscarCliente";
			this->TextBuscarCliente->Size = System::Drawing::Size(486, 40);
			this->TextBuscarCliente->TabIndex = 38;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(48, 74);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 33);
			this->label1->TabIndex = 29;
			this->label1->Text = L"ID Cliente:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 85);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1270, 679);
			this->panel2->TabIndex = 22;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox2->Controls->Add(this->btnMorePlaca);
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Controls->Add(this->TextBuscarPlaca);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->groupBox2->Location = System::Drawing::Point(124, 358);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Size = System::Drawing::Size(996, 145);
			this->groupBox2->TabIndex = 40;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Buscar Vehiculo";
			// 
			// btnMorePlaca
			// 
			this->btnMorePlaca->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnMorePlaca->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnMorePlaca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->btnMorePlaca->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMorePlaca.Image")));
			this->btnMorePlaca->Location = System::Drawing::Point(852, 78);
			this->btnMorePlaca->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMorePlaca->Name = L"btnMorePlaca";
			this->btnMorePlaca->Size = System::Drawing::Size(42, 40);
			this->btnMorePlaca->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->btnMorePlaca->TabIndex = 51;
			this->btnMorePlaca->TabStop = false;
			this->btnMorePlaca->Click += gcnew System::EventHandler(this, &frmBuscar::btnMorePlaca_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(790, 78);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(42, 40);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 39;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &frmBuscar::pictureBox2_Click);
			// 
			// TextBuscarPlaca
			// 
			this->TextBuscarPlaca->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TextBuscarPlaca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBuscarPlaca->Location = System::Drawing::Point(285, 78);
			this->TextBuscarPlaca->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TextBuscarPlaca->Name = L"TextBuscarPlaca";
			this->TextBuscarPlaca->Size = System::Drawing::Size(486, 40);
			this->TextBuscarPlaca->TabIndex = 38;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(32, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(223, 33);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Placa Vehiculo:";
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(35, 22);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(812, 46);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Administrar Clientes y Vehículos";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Controls->Add(this->textInfoCliente);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1270, 85);
			this->panel1->TabIndex = 21;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(488, 29);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(249, 48);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmBuscar::button1_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 764);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1270, 98);
			this->panel3->TabIndex = 23;
			// 
			// frmBuscar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 862);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmBuscar";
			this->Text = L"frmBuscar";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMoreCliente))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMorePlaca))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion

public: 

	event System::EventHandler^ OnBuscarClienteClick;
	event System::EventHandler^ OnBuscarPlacaClick;
	event System::EventHandler^ OnMoreClienteClick;
	event System::EventHandler^ OnMorePlacaClick;

private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) { //Lupa Usuario


	if (!System::String::IsNullOrWhiteSpace(TextBuscarCliente->Text)) {//Veficamos que no este vacio el textbox
		//MessageBox::Show("Búsqueda realizada con éxito", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information); //para debuggin en realidad
		
		int idBuscado = 0;
		try {
			idBuscado = Convert::ToInt32(this->TextBuscarCliente->Text->Trim());
		}
		catch (Exception^) {
			MessageBox::Show("El ID debe contener exclusivamente números.", "Formato inválido", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();
		Cliente^ clienteEncontrado = Controller->buscarxIdArchivo(idBuscado);

		if (clienteEncontrado != nullptr) {
			this->idSeleccionado = idBuscado;
			OnBuscarClienteClick(this, e); //Activamos el evento si se da click y hay algo de texto en la textbox
		}
		else {
			MessageBox::Show("El ID ingresado no se encuentra registrado en el sistema.", "Cliente no encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}
	else {
		MessageBox::Show("Por favor, complete la casilla para buscar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) { //Lupa Placa
	String^ placa = this->TextBuscarPlaca->Text->Trim();

	if (String::IsNullOrWhiteSpace(placa)) {
		MessageBox::Show("Por favor, complete la casilla para buscar", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	Vehiculo^ encontrado = (gcnew VehiculoController())->buscarxPlacaArchivo(placa);
	if (encontrado == nullptr) {
		MessageBox::Show("La placa ingresada no se encuentra registrada en el sistema.", "Vehículo no encontrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	this->idSeleccionado = encontrado->getIdVehiculo(); // reutiliza el mismo campo que la búsqueda de cliente
	OnBuscarPlacaClick(this, e);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	this ->Close();
}
private: System::Void btnMoreCliente_Click(System::Object^ sender, System::EventArgs^ e) { //More Cliente

	OnMoreClienteClick(this, e); //Activamos el evento si se da click 

}
private: System::Void btnMorePlaca_Click(System::Object^ sender, System::EventArgs^ e) { //More Placa

	OnMorePlacaClick(this, e); //Activamos el evento si se da click 

}

//----------------------------------------------------------------------------------------------------------
};
}
