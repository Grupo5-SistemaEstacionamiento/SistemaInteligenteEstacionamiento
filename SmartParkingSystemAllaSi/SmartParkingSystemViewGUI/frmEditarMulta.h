#pragma once

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmEditarMulta
	/// </summary>
	public ref class frmEditarMulta : public System::Windows::Forms::Form
	{
	public:
		frmEditarMulta(void)
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
		~frmEditarMulta()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::ComboBox^ cmbTipo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtUbicacion;
	private: System::Windows::Forms::TextBox^ txtAlias;
	private: System::Windows::Forms::TextBox^ txtSerialId;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label8;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->cmbTipo = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtUbicacion = (gcnew System::Windows::Forms::TextBox());
			this->txtAlias = (gcnew System::Windows::Forms::TextBox());
			this->txtSerialId = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->grpBoxPrincipal->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(255, 245);
			this->textBox1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(536, 34);
			this->textBox1->TabIndex = 9;
			// 
			// cmbTipo
			// 
			this->cmbTipo->BackColor = System::Drawing::Color::White;
			this->cmbTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipo->FormattingEnabled = true;
			this->cmbTipo->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Mal Estacionado", L"Uso Indebido de Espacios Exclusivos",
					L"Conducta Disruptiva", L"Cometio Fraude de Estadía"
			});
			this->cmbTipo->Location = System::Drawing::Point(255, 126);
			this->cmbTipo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->cmbTipo->Name = L"cmbTipo";
			this->cmbTipo->Size = System::Drawing::Size(285, 37);
			this->cmbTipo->TabIndex = 3;
			this->cmbTipo->SelectedIndexChanged += gcnew System::EventHandler(this, &frmEditarMulta::cmbTipo_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(19, 313);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 29);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Monto:";
			// 
			// txtUbicacion
			// 
			this->txtUbicacion->BackColor = System::Drawing::Color::White;
			this->txtUbicacion->Location = System::Drawing::Point(255, 308);
			this->txtUbicacion->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->txtUbicacion->Name = L"txtUbicacion";
			this->txtUbicacion->Size = System::Drawing::Size(536, 34);
			this->txtUbicacion->TabIndex = 5;
			// 
			// txtAlias
			// 
			this->txtAlias->BackColor = System::Drawing::Color::White;
			this->txtAlias->Location = System::Drawing::Point(255, 182);
			this->txtAlias->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->txtAlias->Name = L"txtAlias";
			this->txtAlias->Size = System::Drawing::Size(536, 34);
			this->txtAlias->TabIndex = 2;
			// 
			// txtSerialId
			// 
			this->txtSerialId->BackColor = System::Drawing::Color::White;
			this->txtSerialId->Location = System::Drawing::Point(255, 68);
			this->txtSerialId->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->txtSerialId->Name = L"txtSerialId";
			this->txtSerialId->Size = System::Drawing::Size(167, 34);
			this->txtSerialId->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 245);
			this->label6->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 29);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Fecha:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 129);
			this->label5->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(156, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Penalizacion:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(19, 182);
			this->label4->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(125, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Anotacion:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 68);
			this->label3->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(178, 29);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Placa Vehiculo:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(27, 17);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(378, 23);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Advertencia: No deje ningun espacio vacio";
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(457, 511);
			this->btnRegresarEdit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(221, 38);
			this->btnRegresarEdit->TabIndex = 22;
			this->btnRegresarEdit->Text = L"Cancelar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmEditarMulta::btnRegresarEdit_Click);
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(172, 511);
			this->btnGuardarEdit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(237, 38);
			this->btnGuardarEdit->TabIndex = 24;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 568);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(911, 63);
			this->panel2->TabIndex = 21;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(11, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 29);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Editar Multa";
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->grpBoxPrincipal->Controls->Add(this->comboBox1);
			this->grpBoxPrincipal->Controls->Add(this->label8);
			this->grpBoxPrincipal->Controls->Add(this->textBox1);
			this->grpBoxPrincipal->Controls->Add(this->cmbTipo);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Controls->Add(this->txtUbicacion);
			this->grpBoxPrincipal->Controls->Add(this->txtAlias);
			this->grpBoxPrincipal->Controls->Add(this->txtSerialId);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(31, 60);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->grpBoxPrincipal->Size = System::Drawing::Size(825, 428);
			this->grpBoxPrincipal->TabIndex = 23;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Edite la descripcion de la multa";
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::Color::White;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Por Pagar", L"Pagada", L"Anulada", L"En Revisión" });
			this->comboBox1->Location = System::Drawing::Point(255, 368);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(285, 37);
			this->comboBox1->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(19, 368);
			this->label8->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(94, 29);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Estado:";
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
			this->panel1->Size = System::Drawing::Size(911, 52);
			this->panel1->TabIndex = 20;
			// 
			// frmEditarMulta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(911, 631);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->btnGuardarEdit);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"frmEditarMulta";
			this->Text = L"Editar Multa";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Cancelar

		this->Close();
	}
private: System::Void cmbTipo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
