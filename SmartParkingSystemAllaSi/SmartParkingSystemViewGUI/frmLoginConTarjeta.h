#pragma once

#include "frmPrincipalCliente.h"

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmLoginConTarjeta
	/// </summary>
	public ref class frmLoginConTarjeta : public System::Windows::Forms::Form
	{
	public:
		frmLoginConTarjeta(void)
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
		~frmLoginConTarjeta()
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
	private: System::Windows::Forms::TextBox^ TextBoxRFID;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmLoginConTarjeta::typeid));
			this->pnlContenedor = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TextBoxRFID = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pnlContenedor->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pnlContenedor
			// 
			this->pnlContenedor->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->pnlContenedor->Controls->Add(this->button1);
			this->pnlContenedor->Controls->Add(this->pictureBox2);
			this->pnlContenedor->Controls->Add(this->pictureBox1);
			this->pnlContenedor->Controls->Add(this->label1);
			this->pnlContenedor->Controls->Add(this->label2);
			this->pnlContenedor->Controls->Add(this->TextBoxRFID);
			this->pnlContenedor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlContenedor->Location = System::Drawing::Point(0, 52);
			this->pnlContenedor->Name = L"pnlContenedor";
			this->pnlContenedor->Size = System::Drawing::Size(1058, 560);
			this->pnlContenedor->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(475, 505);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 31);
			this->button1->TabIndex = 62;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmLoginConTarjeta::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(704, 430);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(41, 41);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 60;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &frmLoginConTarjeta::pictureBox1_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(348, 369);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(351, 22);
			this->label1->TabIndex = 59;
			this->label1->Text = L"Por favor, acérque su tarjeta al lector";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(306, 433);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(69, 26);
			this->label2->TabIndex = 58;
			this->label2->Text = L"RFID:";
			this->label2->Click += gcnew System::EventHandler(this, &frmLoginConTarjeta::label2_Click);
			// 
			// TextBoxRFID
			// 
			this->TextBoxRFID->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TextBoxRFID->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->TextBoxRFID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBoxRFID->ForeColor = System::Drawing::Color::White;
			this->TextBoxRFID->Location = System::Drawing::Point(389, 439);
			this->TextBoxRFID->Margin = System::Windows::Forms::Padding(2);
			this->TextBoxRFID->Name = L"TextBoxRFID";
			this->TextBoxRFID->PasswordChar = '*';
			this->TextBoxRFID->Size = System::Drawing::Size(310, 20);
			this->TextBoxRFID->TabIndex = 2;
			this->TextBoxRFID->UseSystemPasswordChar = true;
			this->TextBoxRFID->UseWaitCursor = true;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1058, 52);
			this->panel1->TabIndex = 14;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1023, 34);
			this->textBox1->TabIndex = 0;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"Sistema de Estacionamiento Inteligente Alla-Si";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(311, 86);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(468, 266);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 61;
			this->pictureBox2->TabStop = false;
			// 
			// frmLoginConTarjeta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1058, 612);
			this->Controls->Add(this->pnlContenedor);
			this->Controls->Add(this->panel1);
			this->Name = L"frmLoginConTarjeta";
			this->Text = L"Portal Sistema de Estacionamiento Inteligente Alla-Si";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->pnlContenedor->ResumeLayout(false);
			this->pnlContenedor->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) { //Boton next

		frmPrincipal^ UICliente = gcnew frmPrincipal();
		
		this->Hide();

		UICliente->ShowDialog();

		this->Close();

	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	Application::Restart();
}
};
}
