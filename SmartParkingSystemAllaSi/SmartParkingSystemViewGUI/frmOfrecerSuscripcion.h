#pragma once

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmOfrecerSuscripcion
	/// </summary>
	public ref class frmOfrecerSuscripcion : public System::Windows::Forms::Form
	{
	public:
		frmOfrecerSuscripcion(void)
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
		~frmOfrecerSuscripcion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel2;








	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox1;





	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;

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
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
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
			this->panel1->Size = System::Drawing::Size(1108, 68);
			this->panel1->TabIndex = 24;
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
			this->textInfoCliente->Size = System::Drawing::Size(721, 39);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Se parte de la familia Alla-Si!";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->comboBox1);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1108, 562);
			this->panel2->TabIndex = 25;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(107, 130);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(885, 359);
			this->groupBox1->TabIndex = 56;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Planes Disponibles";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(732, 133);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(106, 44);
			this->label8->TabIndex = 74;
			this->label8->Text = L"/ año";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox3->Location = System::Drawing::Point(556, 133);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(153, 30);
			this->textBox3->TabIndex = 73;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(387, 123);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(157, 44);
			this->label6->TabIndex = 72;
			this->label6->Text = L"/ mes  o";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox2->Location = System::Drawing::Point(556, 78);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(153, 30);
			this->textBox2->TabIndex = 71;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(387, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(157, 44);
			this->label5->TabIndex = 70;
			this->label5->Text = L"/ mes  o";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(732, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 44);
			this->label3->TabIndex = 69;
			this->label3->Text = L"/ año";
			this->label3->Click += gcnew System::EventHandler(this, &frmOfrecerSuscripcion::label3_Click);
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
			this->label7->Location = System::Drawing::Point(149, 234);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(579, 66);
			this->label7->TabIndex = 68;
			this->label7->Text = L"Acerquese a una cabina de administracion\r\npara adquirir sus membresia de inmediat"
				L"o!";
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textBox6->Location = System::Drawing::Point(228, 78);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(153, 30);
			this->textBox6->TabIndex = 67;
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(228, 133);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(153, 30);
			this->textBox1->TabIndex = 62;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(23, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(191, 44);
			this->label2->TabIndex = 57;
			this->label2->Text = L"Premium:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(23, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 44);
			this->label1->TabIndex = 56;
			this->label1->Text = L"Classic:";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(501, 41);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(489, 24);
			this->comboBox1->TabIndex = 55;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(101, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(363, 29);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Seleccione Placa del Vehículo:";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 562);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1108, 79);
			this->panel3->TabIndex = 26;
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
			this->button1->Click += gcnew System::EventHandler(this, &frmOfrecerSuscripcion::button1_Click);
			// 
			// frmOfrecerSuscripcion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1108, 641);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"frmOfrecerSuscripcion";
			this->Text = L"frmOfrecerSuscripcion";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	this->Close();
}
};
}
