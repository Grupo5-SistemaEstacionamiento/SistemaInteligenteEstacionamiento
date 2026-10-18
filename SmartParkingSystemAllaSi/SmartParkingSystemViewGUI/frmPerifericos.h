#pragma once
#include "frmNuevoPeriferico.h"
#include "frmEditarPeriferico.h"

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
	/// Summary for frmPerifericos
	/// </summary>
	public ref class frmPerifericos : public System::Windows::Forms::Form
	{
	public:
		frmPerifericos(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//

			this->Filtro->Text = "Todos";

			SmartParkingSystemController::PerifericoController^ Controller = gcnew PerifericoController();
			
			List<Periferico^>^ ListaInicio = Controller->ListarTodosLosPerifericos();

			mostrarGrilla(ListaInicio);
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmPerifericos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ TextBuscar;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel1;





	private: System::Windows::Forms::ComboBox^ Filtro;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;








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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmPerifericos::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Filtro = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->TextBuscar = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::Purple;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(824, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(165, 48);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmPerifericos::button2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(777, 74);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(42, 48);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 39;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &frmPerifericos::pictureBox2_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(56, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(191, 33);
			this->label2->TabIndex = 29;
			this->label2->Text = L"ID Periferico:";
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox2->Controls->Add(this->Filtro);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Controls->Add(this->TextBuscar);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->groupBox2->Location = System::Drawing::Point(38, 23);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Size = System::Drawing::Size(1188, 209);
			this->groupBox2->TabIndex = 40;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Buscar Empleado";
			// 
			// Filtro
			// 
			this->Filtro->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Filtro->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Filtro->FormattingEnabled = true;
			this->Filtro->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Todos", L"Sensores IR", L"Lectores RFID", L"Indicadores LED",
					L"Servomotores"
			});
			this->Filtro->Location = System::Drawing::Point(285, 149);
			this->Filtro->Name = L"Filtro";
			this->Filtro->Size = System::Drawing::Size(374, 41);
			this->Filtro->TabIndex = 41;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(56, 149);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 33);
			this->label1->TabIndex = 40;
			this->label1->Text = L"Filtrando por:";
			// 
			// TextBuscar
			// 
			this->TextBuscar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TextBuscar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBuscar->Location = System::Drawing::Point(285, 77);
			this->TextBuscar->Name = L"TextBuscar";
			this->TextBuscar->Size = System::Drawing::Size(486, 40);
			this->TextBuscar->TabIndex = 38;
			this->TextBuscar->UseWaitCursor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 85);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1270, 679);
			this->panel2->TabIndex = 31;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column5, this->Column2, this->Column3, this->Column4, this->Column6, this->Column7
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(38, 242);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->Size = System::Drawing::Size(1188, 415);
			this->dataGridView1->TabIndex = 41;
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(296, 34);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(188, 48);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Editar";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &frmPerifericos::button4_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button6);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->button5);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 764);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1270, 98);
			this->panel3->TabIndex = 32;
			// 
			// button6
			// 
			this->button6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button6->BackColor = System::Drawing::Color::RoyalBlue;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Location = System::Drawing::Point(750, 34);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(188, 48);
			this->button6->TabIndex = 16;
			this->button6->Text = L"Detalles";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(976, 34);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 48);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmPerifericos::button1_Click);
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(523, 34);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(188, 48);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Eliminar";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &frmPerifericos::button5_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->BackColor = System::Drawing::Color::LimeGreen;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(71, 34);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(188, 48);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Nuevo";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &frmPerifericos::button3_Click);
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(38, 22);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(812, 46);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Gestionar Periféricos";
			this->textInfoCliente->TextChanged += gcnew System::EventHandler(this, &frmPerifericos::textInfoCliente_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Controls->Add(this->textInfoCliente);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1270, 85);
			this->panel1->TabIndex = 30;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 8;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 161;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Tipo";
			this->Column5->MinimumWidth = 8;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 160;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Ubicación";
			this->Column2->MinimumWidth = 8;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 161;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Fecha Instalación";
			this->Column3->MinimumWidth = 8;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 160;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Fecha Último Mantenimiento";
			this->Column4->MinimumWidth = 8;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 161;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Estado";
			this->Column6->MinimumWidth = 8;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 160;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Detalles";
			this->Column7->MinimumWidth = 8;
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 300;
			// 
			// frmPerifericos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 862);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmPerifericos";
			this->Text = L"frmPerifericos";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textInfoCliente_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}

private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) { //Lupita

	if (!String::IsNullOrWhiteSpace(this->TextBuscar->Text)) {
		SmartParkingSystemController::PerifericoController^ Controller = gcnew PerifericoController();

		String^ filtroAplicado = this->Filtro->Text;

		List<Periferico^>^ PerifericosEncontrados;

		if (String::IsNullOrWhiteSpace(filtroAplicado) || filtroAplicado == "Todos") {
			PerifericosEncontrados = Controller->ListarTodosLosPerifericos();
		}

		else {
			PerifericosEncontrados = Controller->FiltrarPorTipo(filtroAplicado);

		}
		mostrarGrilla(PerifericosEncontrados);
	}
	else {
		MessageBox::Show("Por favor, ingrese un ID para buscar.", "Error de búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //Limpiar

	this->TextBuscar->Text = "";

	this->dataGridView1->Rows->Clear(); // Limpia la grilla

	SmartParkingSystemController::PerifericoController^ Controller = gcnew PerifericoController();

	List<Periferico^>^ ListaLimpia = Controller->ListarTodosLosPerifericos();

	mostrarGrilla(ListaLimpia);
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //Nuevo

	SmartParkingSystemController::PerifericoController^ Controller = gcnew PerifericoController();

	frmNuevoPeriferico^ ventana = gcnew frmNuevoPeriferico();
	ventana->ShowDialog();

	List<Periferico^>^ listaEmpleados = Controller->ListarTodosLosPerifericos();
	mostrarGrilla(listaEmpleados);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { //Editar
	if (this->dataGridView1->SelectedRows->Count > 0) {

		int idPeriferico = Convert::ToInt32(this->dataGridView1->SelectedRows[0]->Cells[0]->Value);

		frmEditarPeriferico^ ventanaEdicion = gcnew frmEditarPeriferico(idPeriferico);

		ventanaEdicion->ShowDialog();

		SmartParkingSystemController::PerifericoController^ controller = gcnew PerifericoController();

		List<Periferico^>^ PerifericosActualizados = controller->ListarTodosLosPerifericos();
		mostrarGrilla(PerifericosActualizados);
	}
	else {
		MessageBox::Show("Por favor, seleccione un periférico para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar

	this->Close();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { //Eliminar

	if (this->dataGridView1->SelectedRows->Count > 0) {

		int idSeleccionado = Convert::ToInt32(this->dataGridView1->SelectedRows[0]->Cells[0]->Value);

		System::Windows::Forms::DialogResult respuesta = MessageBox::Show( "¿Está seguro que desea eliminar el periférico con ID: " + idSeleccionado + "?", "Confirmar Eliminación", MessageBoxButtons::YesNo,MessageBoxIcon::Warning);

		if (respuesta == System::Windows::Forms::DialogResult::Yes) {

			SmartParkingSystemController::PerifericoController^ controller = gcnew SmartParkingSystemController::PerifericoController();

			controller->EliminarPeriferico(idSeleccionado);

			MessageBox::Show("Periférico eliminado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			List<Periferico^>^ PerifericosActualizados = controller->ListarTodosLosPerifericos();
			mostrarGrilla(PerifericosActualizados);
		}
	}
	else {
		MessageBox::Show("Por favor, seleccione toda la fila del periférico haciendo clic en la flecha del margen izquierdo.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

private: void mostrarGrilla(List<Periferico^>^ perifericos) {
   this->dataGridView1->Rows->Clear(); // Limpiar la grilla antes de mostrar los resultados

	if (perifericos == nullptr || perifericos->Count == 0) {
		//MessageBox::Show("No se encontraron empleados.", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	for (int i = 0; i < perifericos->Count; i++) {

		Periferico^ periferico = perifericos[i];

		if (periferico == nullptr) continue;

			array<String^>^ filaGrilla = gcnew array<String^>(7); // Ajusta el tamaño según las columnas que quieras mostrar
			filaGrilla[0] = periferico->getIdPeriferico().ToString();
			filaGrilla[1] = periferico->getTipoString();
			filaGrilla[2] = periferico->getUbicacion();
			filaGrilla[3] = periferico->getFechaInstalacion().ToString("dd/MM/yyyy");;
			filaGrilla[4] = periferico->getFechaUltimoMant().ToString("dd/MM/yyyy");
			filaGrilla[5] = periferico->getEstado().ToString(); // Convertir booleano a texto
			filaGrilla[6] = periferico->getDetallesResumen();
			this->dataGridView1->Rows->Add(filaGrilla);
	}
}
};
}
