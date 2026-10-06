#pragma once
#include "frmBalanceTurno.h"

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmTurno
	/// </summary>
	public ref class frmTurno : public System::Windows::Forms::Form
	{
	public:
		frmTurno(void)
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
		~frmTurno()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:













	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ Balanceturnobtn;

	private: System::Windows::Forms::Button^ Salidabtn;
	private: System::Windows::Forms::Button^ Iniciobtn;















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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Balanceturnobtn = (gcnew System::Windows::Forms::Button());
			this->Salidabtn = (gcnew System::Windows::Forms::Button());
			this->Iniciobtn = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 55);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(847, 441);
			this->panel2->TabIndex = 19;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmTurno::panel2_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox1->Controls->Add(this->Balanceturnobtn);
			this->groupBox1->Controls->Add(this->Salidabtn);
			this->groupBox1->Controls->Add(this->Iniciobtn);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(85, 49);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(664, 348);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Hora Actual:";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmTurno::groupBox1_Enter);
			// 
			// Balanceturnobtn
			// 
			this->Balanceturnobtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Balanceturnobtn->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Balanceturnobtn->ForeColor = System::Drawing::Color::White;
			this->Balanceturnobtn->Location = System::Drawing::Point(225, 242);
			this->Balanceturnobtn->Margin = System::Windows::Forms::Padding(2);
			this->Balanceturnobtn->Name = L"Balanceturnobtn";
			this->Balanceturnobtn->Size = System::Drawing::Size(183, 43);
			this->Balanceturnobtn->TabIndex = 70;
			this->Balanceturnobtn->Text = L"Balance Turno";
			this->Balanceturnobtn->UseVisualStyleBackColor = false;
			this->Balanceturnobtn->Click += gcnew System::EventHandler(this, &frmTurno::Balanceturnobtn_Click);
			// 
			// Salidabtn
			// 
			this->Salidabtn->BackColor = System::Drawing::Color::Firebrick;
			this->Salidabtn->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Salidabtn->ForeColor = System::Drawing::Color::White;
			this->Salidabtn->Location = System::Drawing::Point(361, 159);
			this->Salidabtn->Margin = System::Windows::Forms::Padding(2);
			this->Salidabtn->Name = L"Salidabtn";
			this->Salidabtn->Size = System::Drawing::Size(183, 43);
			this->Salidabtn->TabIndex = 69;
			this->Salidabtn->Text = L"Registrar Salida";
			this->Salidabtn->UseVisualStyleBackColor = false;
			this->Salidabtn->Click += gcnew System::EventHandler(this, &frmTurno::Salidabtn_Click);
			// 
			// Iniciobtn
			// 
			this->Iniciobtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Iniciobtn->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Iniciobtn->ForeColor = System::Drawing::Color::White;
			this->Iniciobtn->Location = System::Drawing::Point(109, 159);
			this->Iniciobtn->Margin = System::Windows::Forms::Padding(2);
			this->Iniciobtn->Name = L"Iniciobtn";
			this->Iniciobtn->Size = System::Drawing::Size(183, 43);
			this->Iniciobtn->TabIndex = 12;
			this->Iniciobtn->Text = L"Registrar Inicio";
			this->Iniciobtn->UseVisualStyleBackColor = false;
			this->Iniciobtn->Click += gcnew System::EventHandler(this, &frmTurno::Iniciobtn_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Black", 40.25F, System::Drawing::FontStyle::Bold));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label8->Location = System::Drawing::Point(149, 45);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(359, 76);
			this->label8->TabIndex = 68;
			this->label8->Text = L"3:00.00 AM";
			this->label8->Click += gcnew System::EventHandler(this, &frmTurno::label8_Click);
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(25, 8);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(541, 31);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Gestión de Turno";
			this->textInfoCliente->TextChanged += gcnew System::EventHandler(this, &frmTurno::textInfoCliente_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Controls->Add(this->textInfoCliente);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(847, 55);
			this->panel1->TabIndex = 18;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmTurno::panel1_Paint);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(325, 19);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 31);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmTurno::button1_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 496);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(847, 64);
			this->panel3->TabIndex = 20;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmTurno::panel3_Paint);
			// 
			// frmTurno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 560);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmTurno";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"frmTurno";
			this->panel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	this->Close();
}

private: System::Void Iniciobtn_Click(System::Object^ sender, System::EventArgs^ e) { //Registrar Inicio
	bool TurnoAnteriorAbierto = false;
	if (TurnoAnteriorAbierto) {
		MessageBox::Show("No se pudo inciar un nuevo turno \nExiste un turno actualmente activo \nRecuerde cerrar el turno anterior para poder abrir uno nuevo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		MessageBox::Show("Turno iniciado correctamente \nNo olvide cerrar su turno antes de retirarse","Éxito", MessageBoxButtons::OK ,MessageBoxIcon::Information);
	}
}

private: System::Void Salidabtn_Click(System::Object^ sender, System::EventArgs^ e) { //Registrar Salida
	MessageBox::Show("Turno cerrado correctamente", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

private: System::Void Balanceturnobtn_Click(System::Object^ sender, System::EventArgs^ e) { //Balance Turno
	frmBalanceTurno^ VentanaBalanceTurno = gcnew frmBalanceTurno();

	VentanaBalanceTurno->ShowDialog();
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textInfoCliente_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
