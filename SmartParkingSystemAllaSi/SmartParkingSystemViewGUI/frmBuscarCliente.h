#pragma once
#include "frmVerInfo.h"
#include "frmEditarInfo.h"

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmBuscarCliente
	/// </summary>
	public ref class frmBuscarCliente : public System::Windows::Forms::Form
	{
	public:
		frmBuscarCliente(void)
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
		~frmBuscarCliente()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel3;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::PictureBox^ pictureBox13;
	private: System::Windows::Forms::PictureBox^ pictureBox12;
	private: System::Windows::Forms::PictureBox^ pictureBox11;
	private: System::Windows::Forms::PictureBox^ pictureBox10;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmBuscarCliente::typeid));
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 610);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1129, 79);
			this->panel3->TabIndex = 17;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(433, 23);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(221, 38);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmBuscarCliente::button1_Click);
			// 
			// textBox9
			// 
			this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox9->Location = System::Drawing::Point(516, 433);
			this->textBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(433, 22);
			this->textBox9->TabIndex = 63;
			// 
			// textBox8
			// 
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox8->Location = System::Drawing::Point(516, 377);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(433, 22);
			this->textBox8->TabIndex = 62;
			// 
			// textBox7
			// 
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox7->Location = System::Drawing::Point(516, 329);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(433, 22);
			this->textBox7->TabIndex = 61;
			// 
			// textBox6
			// 
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox6->Location = System::Drawing::Point(516, 279);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(433, 22);
			this->textBox6->TabIndex = 60;
			// 
			// textBox5
			// 
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox5->Location = System::Drawing::Point(516, 231);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(433, 22);
			this->textBox5->TabIndex = 59;
			// 
			// textBox4
			// 
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->Location = System::Drawing::Point(516, 178);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(433, 22);
			this->textBox4->TabIndex = 58;
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Location = System::Drawing::Point(516, 127);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(433, 22);
			this->textBox3->TabIndex = 57;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Location = System::Drawing::Point(516, 81);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(433, 22);
			this->textBox2->TabIndex = 56;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel4->Location = System::Drawing::Point(45, 25);
			this->panel4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(13, 433);
			this->panel4->TabIndex = 55;
			// 
			// pictureBox9
			// 
			this->pictureBox9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(968, 426);
			this->pictureBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(38, 32);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 54;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox9_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->pictureBox13);
			this->panel2->Controls->Add(this->pictureBox12);
			this->panel2->Controls->Add(this->pictureBox11);
			this->panel2->Controls->Add(this->pictureBox10);
			this->panel2->Controls->Add(this->pictureBox8);
			this->panel2->Controls->Add(this->pictureBox7);
			this->panel2->Controls->Add(this->pictureBox6);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->textBox9);
			this->panel2->Controls->Add(this->textBox8);
			this->panel2->Controls->Add(this->textBox7);
			this->panel2->Controls->Add(this->textBox6);
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->pictureBox9);
			this->panel2->Controls->Add(this->pictureBox5);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 68);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1129, 621);
			this->panel2->TabIndex = 16;
			// 
			// pictureBox13
			// 
			this->pictureBox13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
			this->pictureBox13->Location = System::Drawing::Point(1024, 224);
			this->pictureBox13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(38, 32);
			this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox13->TabIndex = 71;
			this->pictureBox13->TabStop = false;
			this->pictureBox13->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox13_Click);
			// 
			// pictureBox12
			// 
			this->pictureBox12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
			this->pictureBox12->Location = System::Drawing::Point(1024, 178);
			this->pictureBox12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(38, 32);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox12->TabIndex = 70;
			this->pictureBox12->TabStop = false;
			this->pictureBox12->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox12_Click);
			// 
			// pictureBox11
			// 
			this->pictureBox11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(1024, 426);
			this->pictureBox11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(38, 32);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox11->TabIndex = 69;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox11_Click);
			// 
			// pictureBox10
			// 
			this->pictureBox10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox10->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(968, 372);
			this->pictureBox10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(38, 32);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox10->TabIndex = 68;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox10_Click);
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(968, 273);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(38, 32);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 67;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox8_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(968, 122);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(38, 32);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 66;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox7_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(968, 322);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(38, 32);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 66;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox6_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(968, 75);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(38, 32);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 65;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1024, 31);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(38, 32);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 64;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox2_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(968, 224);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(38, 32);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 50;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(968, 178);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(38, 32);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 49;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(968, 31);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(38, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 46;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(516, 31);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(433, 22);
			this->textBox1->TabIndex = 37;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(115, 431);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(253, 29);
			this->label9->TabIndex = 36;
			this->label9->Text = L"Vehiculos Asociados";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::White;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(115, 377);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(174, 29);
			this->label8->TabIndex = 35;
			this->label8->Text = L"Discapacidad:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(115, 322);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(229, 29);
			this->label7->TabIndex = 34;
			this->label7->Text = L"Correo Electronico";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(115, 127);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(129, 29);
			this->label6->TabIndex = 33;
			this->label6->Text = L"Apellidos:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(115, 273);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(251, 29);
			this->label5->TabIndex = 32;
			this->label5->Text = L"Número de Telefono:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(115, 224);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 29);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Documentos:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(115, 178);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 29);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Membresia:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(115, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 29);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Nombres:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(115, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(153, 29);
			this->label1->TabIndex = 28;
			this->label1->Text = L"IDs Tarjetas:";
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
			this->panel1->Size = System::Drawing::Size(1129, 68);
			this->panel1->TabIndex = 15;
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(33, 10);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(372, 39);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Buscar Cliente";
			// 
			// frmBuscarCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1129, 689);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"frmBuscarCliente";
			this->Text = L"frmBuscarCliente";
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

public: 

	event System::EventHandler^ OnRegresar;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	OnRegresar(this, e);
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) { //More Ids tarjetas

	frmVerInfo^ ventanaEdicion = gcnew frmVerInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) { //Editar IDS Tarjetas

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Nombres

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox7_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Apellidos

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) { //More Membresia

	frmVerInfo^ ventanaEdicion = gcnew frmVerInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox12_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Membresia

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) { //More Documentos

	frmVerInfo^ ventanaEdicion = gcnew frmVerInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox13_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Documentos

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox8_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Telefono

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox6_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Correo

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Discapacidad

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox9_Click(System::Object^ sender, System::EventArgs^ e) { //More Vehiculos

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
private: System::Void pictureBox11_Click(System::Object^ sender, System::EventArgs^ e) { //Editar Vehiculos

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}
};
}
