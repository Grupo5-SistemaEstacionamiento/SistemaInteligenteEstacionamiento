#pragma once

namespace ParkingSystemView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmEmergencia
	/// </summary>
	public ref class frmEmergencia : public System::Windows::Forms::Form
	{
	public:
		frmEmergencia(void)
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
		~frmEmergencia()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnDesactivar;


	private: System::Windows::Forms::Button^ btnActivar;




	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnRegresar;


	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textEstadoOperativo;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textSonido;



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
			this->textSonido = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textEstadoOperativo = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnDesactivar = (gcnew System::Windows::Forms::Button());
			this->btnActivar = (gcnew System::Windows::Forms::Button());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
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
			this->panel2->TabIndex = 22;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->groupBox1->Controls->Add(this->textSonido);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textEstadoOperativo);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->btnDesactivar);
			this->groupBox1->Controls->Add(this->btnActivar);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(85, 49);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(664, 348);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Gestionar Emergencia";
			// 
			// textSonido
			// 
			this->textSonido->BackColor = System::Drawing::SystemColors::Control;
			this->textSonido->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textSonido->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textSonido->Location = System::Drawing::Point(314, 93);
			this->textSonido->Margin = System::Windows::Forms::Padding(2);
			this->textSonido->Name = L"textSonido";
			this->textSonido->ReadOnly = true;
			this->textSonido->Size = System::Drawing::Size(166, 29);
			this->textSonido->TabIndex = 74;
			this->textSonido->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(204, 92);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 27);
			this->label1->TabIndex = 73;
			this->label1->Text = L"Sonido:";
			// 
			// textEstadoOperativo
			// 
			this->textEstadoOperativo->BackColor = System::Drawing::SystemColors::Control;
			this->textEstadoOperativo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textEstadoOperativo->ForeColor = System::Drawing::SystemColors::ControlText;
			this->textEstadoOperativo->Location = System::Drawing::Point(336, 55);
			this->textEstadoOperativo->Margin = System::Windows::Forms::Padding(2);
			this->textEstadoOperativo->Name = L"textEstadoOperativo";
			this->textEstadoOperativo->ReadOnly = true;
			this->textEstadoOperativo->Size = System::Drawing::Size(166, 29);
			this->textEstadoOperativo->TabIndex = 72;
			this->textEstadoOperativo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial Black", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(124, 54);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(199, 27);
			this->label7->TabIndex = 71;
			this->label7->Text = L"Estado Operativo:";
			this->label7->Click += gcnew System::EventHandler(this, &frmEmergencia::label7_Click);
			// 
			// btnDesactivar
			// 
			this->btnDesactivar->BackColor = System::Drawing::Color::Firebrick;
			this->btnDesactivar->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDesactivar->ForeColor = System::Drawing::Color::White;
			this->btnDesactivar->Location = System::Drawing::Point(209, 225);
			this->btnDesactivar->Margin = System::Windows::Forms::Padding(2);
			this->btnDesactivar->Name = L"btnDesactivar";
			this->btnDesactivar->Size = System::Drawing::Size(216, 43);
			this->btnDesactivar->TabIndex = 69;
			this->btnDesactivar->Text = L"Desactivar Alarma";
			this->btnDesactivar->UseVisualStyleBackColor = false;
			this->btnDesactivar->Click += gcnew System::EventHandler(this, &frmEmergencia::btnDesactivar_Click);
			// 
			// btnActivar
			// 
			this->btnActivar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnActivar->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActivar->ForeColor = System::Drawing::Color::White;
			this->btnActivar->Location = System::Drawing::Point(209, 159);
			this->btnActivar->Margin = System::Windows::Forms::Padding(2);
			this->btnActivar->Name = L"btnActivar";
			this->btnActivar->Size = System::Drawing::Size(216, 43);
			this->btnActivar->TabIndex = 12;
			this->btnActivar->Text = L"Activar Alarma";
			this->btnActivar->UseVisualStyleBackColor = false;
			this->btnActivar->Click += gcnew System::EventHandler(this, &frmEmergencia::btnActivar_Click);
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::Red;
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(24, 11);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(541, 31);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"EMERGENCIA";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Red;
			this->panel1->Controls->Add(this->textInfoCliente);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(847, 55);
			this->panel1->TabIndex = 21;
			// 
			// btnRegresar
			// 
			this->btnRegresar->BackColor = System::Drawing::Color::Brown;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresar->ForeColor = System::Drawing::Color::White;
			this->btnRegresar->Location = System::Drawing::Point(325, 19);
			this->btnRegresar->Margin = System::Windows::Forms::Padding(2);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(166, 31);
			this->btnRegresar->TabIndex = 11;
			this->btnRegresar->Text = L"Regresar";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmEmergencia::btnRegresar_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->btnRegresar);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 496);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(847, 64);
			this->panel3->TabIndex = 23;
			// 
			// frmEmergencia
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 560);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmEmergencia";
			this->Text = L"frmEmergencia";
			this->panel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void btnActivar_Click(System::Object^ sender, System::EventArgs^ e) { //Activar Alarma
	bool EstadoOperativoAlarma = true;
	if (EstadoOperativoAlarma) {
		this->textEstadoOperativo->Text = "CONECTADA";
		this->textEstadoOperativo->BackColor = System::Drawing::Color::Green;
		this->textEstadoOperativo->ForeColor = System::Drawing::Color::White;

		this->textSonido->Text = "SONANDO";
		this->textSonido->BackColor = System::Drawing::Color::Red;
		this->textSonido->ForeColor = System::Drawing::Color::White;

		MessageBox::Show("¡PROTOCOLO DE EMERGENCIA ACTIVADO! \nSONANDO ALARMA", "ACTIVADO", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	else{

		MessageBox::Show("La alarma se encuentra actualmente desconectada \nPara volverla a activar ir al módulo fiísico y utilice la palanca", "Atención", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		this->textEstadoOperativo->Text = "DESCONECTADA";
		this->textEstadoOperativo->BackColor = System::Drawing::Color::Red;
		this->textEstadoOperativo->ForeColor = System::Drawing::Color::White;
	}

}
private: System::Void btnDesactivar_Click(System::Object^ sender, System::EventArgs^ e) { //Desactivar Alarma

	this->textSonido->Text = "SILENCIADA";
	this->textSonido->BackColor = System::Drawing::Color::Green;
	this->textSonido->ForeColor = System::Drawing::Color::White;

	MessageBox::Show("Se ha silenciado la alarma \nAlarma Desacivada", "DESACTIVADO", MessageBoxButtons::OK, MessageBoxIcon::Information);

}
private: System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	this->Close();
}
};
}
