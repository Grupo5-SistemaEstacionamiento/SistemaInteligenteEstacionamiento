#pragma once
#include "frmPrincipalCliente.h"
#include "frmPrincipalAdmin.h"

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmLogin
	/// </summary>
	public ref class frmLogin : public System::Windows::Forms::Form
	{
	public:
		frmLogin(void)
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
		~frmLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlContenedor;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::GroupBox^ groupBox1;






	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ TextBoxPassword;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ TextBoxCorreo;
	private: System::Windows::Forms::Button^ btnIngresar;


	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label5;










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
			this->pnlContenedor = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->TextBoxCorreo = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->TextBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pnlContenedor->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlContenedor
			// 
			this->pnlContenedor->BackColor = System::Drawing::Color::White;
			this->pnlContenedor->Controls->Add(this->panel5);
			this->pnlContenedor->Controls->Add(this->panel4);
			this->pnlContenedor->Controls->Add(this->groupBox1);
			this->pnlContenedor->Controls->Add(this->label1);
			this->pnlContenedor->Controls->Add(this->panel3);
			this->pnlContenedor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlContenedor->Location = System::Drawing::Point(0, 64);
			this->pnlContenedor->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pnlContenedor->Name = L"pnlContenedor";
			this->pnlContenedor->Size = System::Drawing::Size(1411, 689);
			this->pnlContenedor->TabIndex = 11;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel5->Location = System::Drawing::Point(1367, 7);
			this->panel5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(13, 575);
			this->panel5->TabIndex = 61;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel4->Location = System::Drawing::Point(40, 16);
			this->panel4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(13, 575);
			this->panel4->TabIndex = 60;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox1->Controls->Add(this->btnIngresar);
			this->groupBox1->Controls->Add(this->TextBoxCorreo);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->TextBoxPassword);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(273, 178);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(885, 324);
			this->groupBox1->TabIndex = 59;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ingrese su Informacion";
			// 
			// btnIngresar
			// 
			this->btnIngresar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIngresar->ForeColor = System::Drawing::Color::White;
			this->btnIngresar->Location = System::Drawing::Point(335, 187);
			this->btnIngresar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(221, 55);
			this->btnIngresar->TabIndex = 70;
			this->btnIngresar->Text = L"Ingresar";
			this->btnIngresar->UseVisualStyleBackColor = false;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &frmLogin::button1_Click);
			// 
			// TextBoxCorreo
			// 
			this->TextBoxCorreo->BackColor = System::Drawing::Color::White;
			this->TextBoxCorreo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBoxCorreo->Location = System::Drawing::Point(405, 65);
			this->TextBoxCorreo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TextBoxCorreo->Name = L"TextBoxCorreo";
			this->TextBoxCorreo->Size = System::Drawing::Size(413, 30);
			this->TextBoxCorreo->TabIndex = 69;
			this->TextBoxCorreo->UseWaitCursor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label7->Location = System::Drawing::Point(297, 268);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(277, 33);
			this->label7->TabIndex = 68;
			this->label7->Text = L"Alla No pero Alla Si!";
			// 
			// TextBoxPassword
			// 
			this->TextBoxPassword->BackColor = System::Drawing::Color::White;
			this->TextBoxPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBoxPassword->Location = System::Drawing::Point(405, 122);
			this->TextBoxPassword->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TextBoxPassword->Name = L"TextBoxPassword";
			this->TextBoxPassword->PasswordChar = '*';
			this->TextBoxPassword->Size = System::Drawing::Size(413, 30);
			this->TextBoxPassword->TabIndex = 62;
			this->TextBoxPassword->UseSystemPasswordChar = true;
			this->TextBoxPassword->UseWaitCursor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(156, 118);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(191, 35);
			this->label2->TabIndex = 57;
			this->label2->Text = L"Contrasena:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(57, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(303, 35);
			this->label4->TabIndex = 56;
			this->label4->Text = L"Correo Electronico: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 26.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->label1->Location = System::Drawing::Point(124, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(320, 62);
			this->label1->TabIndex = 57;
			this->label1->Text = L"Bienvenido! ";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->label5);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 597);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1411, 92);
			this->panel3->TabIndex = 58;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(60, 15);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(623, 69);
			this->label5->TabIndex = 60;
			this->label5->Text = L"Consejo:\r\nPara entrar como cliente-> U: cliente@estacionamiento.com - p: 1234\r\nPa"
				L"ra entrar como admin-> U: admin@estacionamiento.com - p: 1234 \r\n";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1411, 64);
			this->panel1->TabIndex = 12;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(16, 15);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1364, 43);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Sistema de Estacionamiento Inteligente Alla-Si";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &frmLogin::textBox1_TextChanged);
			// 
			// frmLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1411, 753);
			this->Controls->Add(this->pnlContenedor);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"frmLogin";
			this->Text = L"Portal Sistema de Estacionamiento Inteligente Alla-Si";
			this->pnlContenedor->ResumeLayout(false);
			this->pnlContenedor->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Ingresar

		if (TextBoxCorreo->Text == "cliente@estacionamiento.com" && TextBoxPassword->Text == "1234") {
			frmPrincipal^ UICliente = gcnew frmPrincipal(); //Deberia llamarse fmrPrincipalCliente pero me equivoque al crear el archivo originalmente :(

			this->Hide();

			UICliente->ShowDialog();

			this->Close();

		}
		else if(TextBoxCorreo->Text == "admin@estacionamiento.com" && TextBoxPassword->Text == "1234"){
			frmPrincipalAdmin^ UIAdmin = gcnew frmPrincipalAdmin(); //Deberia llamarse fmrPrincipalCliente pero me equivoque al crear el archivo originalmente :(

			this->Hide();

			UIAdmin->ShowDialog();

			this->Close();
		}
		else {
			MessageBox::Show("Acceso denegado \n Correo o contraseña inválidos \n Por favor, intente denuevo","Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
