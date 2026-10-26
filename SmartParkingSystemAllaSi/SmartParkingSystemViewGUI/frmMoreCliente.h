#pragma once
#include "frmNuevoCliente.h"
#include "frmEditarCliente.h"

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
	/// Summary for frmMoreCliente
	/// </summary>
	public ref class frmMoreCliente : public System::Windows::Forms::Form
	{
	public:

		int idSelect;

		frmMoreCliente(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();

			List<Cliente^>^ ListaInicial = Controller->buscarTodosArchivo();

			mostrarGrilla(ListaInicial);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMoreCliente()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ btnEliminar;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ btnEditar;







	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ComboBox^ cboFiltro;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ TextBuscar;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::Button^ btnMas;

	protected:





































	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMoreCliente::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->cboFiltro = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->TextBuscar = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnMas = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
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
			this->panel1->TabIndex = 33;
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(25, 14);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(541, 31);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Gestionar Clientes";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(636, 22);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 31);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmMoreCliente::button1_Click_1);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnEliminar->BackColor = System::Drawing::Color::Red;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::Color::White;
			this->btnEliminar->Location = System::Drawing::Point(359, 22);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(2);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(125, 31);
			this->btnEliminar->TabIndex = 14;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMoreCliente::btnEliminar_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->BackColor = System::Drawing::Color::LimeGreen;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(74, 22);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 31);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Nuevo";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &frmMoreCliente::button3_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->btnMas);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->btnEliminar);
			this->panel3->Controls->Add(this->btnEditar);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 496);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(847, 64);
			this->panel3->TabIndex = 35;
			// 
			// btnEditar
			// 
			this->btnEditar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnEditar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::Color::White;
			this->btnEditar->Location = System::Drawing::Point(215, 22);
			this->btnEditar->Margin = System::Windows::Forms::Padding(2);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(125, 31);
			this->btnEditar->TabIndex = 13;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMoreCliente::btnEditar_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::MediumSlateBlue;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column5, this->Column2, this->Column3, this->Column4, this->Column6, this->Column7
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(25, 216);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->Size = System::Drawing::Size(792, 270);
			this->dataGridView1->TabIndex = 41;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 8;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 50;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Nombres";
			this->Column5->MinimumWidth = 8;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 120;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Apellidos";
			this->Column2->MinimumWidth = 8;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 150;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Tipo Cliente";
			this->Column3->MinimumWidth = 8;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 150;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Saldo";
			this->Column4->MinimumWidth = 8;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 150;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Estado";
			this->Column6->MinimumWidth = 8;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 80;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Observaciones";
			this->Column7->MinimumWidth = 8;
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 550;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(847, 560);
			this->panel2->TabIndex = 34;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox2->Controls->Add(this->cboFiltro);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Controls->Add(this->TextBuscar);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->groupBox2->Location = System::Drawing::Point(25, 74);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(792, 136);
			this->groupBox2->TabIndex = 40;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Buscar Empleado";
			// 
			// cboFiltro
			// 
			this->cboFiltro->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cboFiltro->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cboFiltro->FormattingEnabled = true;
			this->cboFiltro->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Todos", L"Miembro", L"Normal" });
			this->cboFiltro->Location = System::Drawing::Point(190, 97);
			this->cboFiltro->Margin = System::Windows::Forms::Padding(2);
			this->cboFiltro->Name = L"cboFiltro";
			this->cboFiltro->Size = System::Drawing::Size(251, 30);
			this->cboFiltro->TabIndex = 41;
			this->cboFiltro->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMoreCliente::cboFiltro_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(37, 97);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 22);
			this->label1->TabIndex = 40;
			this->label1->Text = L"Filtrando por:";
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::Purple;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(549, 48);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 31);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmMoreCliente::button2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(518, 48);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(28, 31);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 39;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &frmMoreCliente::pictureBox2_Click);
			// 
			// TextBuscar
			// 
			this->TextBuscar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TextBuscar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBuscar->Location = System::Drawing::Point(190, 50);
			this->TextBuscar->Margin = System::Windows::Forms::Padding(2);
			this->TextBuscar->Name = L"TextBuscar";
			this->TextBuscar->Size = System::Drawing::Size(325, 29);
			this->TextBuscar->TabIndex = 38;
			this->TextBuscar->UseWaitCursor = true;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(37, 51);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 22);
			this->label2->TabIndex = 29;
			this->label2->Text = L"ID Persona:";
			// 
			// btnMas
			// 
			this->btnMas->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnMas->BackColor = System::Drawing::Color::Teal;
			this->btnMas->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMas->ForeColor = System::Drawing::Color::White;
			this->btnMas->Location = System::Drawing::Point(498, 22);
			this->btnMas->Margin = System::Windows::Forms::Padding(2);
			this->btnMas->Name = L"btnMas";
			this->btnMas->Size = System::Drawing::Size(125, 31);
			this->btnMas->TabIndex = 16;
			this->btnMas->Text = L"Más";
			this->btnMas->UseVisualStyleBackColor = false;
			this->btnMas->Click += gcnew System::EventHandler(this, &frmMoreCliente::btnMas_Click);
			// 
			// frmMoreCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 560);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmMoreCliente";
			this->Text = L"frmMoreCliente";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


		//Para regresar con eventos------------------------------------------------------------------------------------
	public:

		event System::EventHandler^ OnRegresar;
		event System::EventHandler^ OnVerMas;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
		OnRegresar(this, e);
	}

		   //--------------------------------------------------------------------------------------------------------------

private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) { //Lupita

	SmartParkingSystemController::ClienteController^ Controller = gcnew SmartParkingSystemController::ClienteController();
	String^ filtroAplicado = this->cboFiltro->Text;
	List<Cliente^>^ resultadoFinal = gcnew List<Cliente^>();

	// ESCENARIO A: El usuario escribió un ID en la caja de texto
	if (!String::IsNullOrWhiteSpace(this->TextBuscar->Text)) {
		int idBuscado = 0;
		try {
			idBuscado = Convert::ToInt32(this->TextBuscar->Text);
		}
		catch (Exception^) {
			MessageBox::Show("Por favor, ingrese solo números en el campo de ID.", "Formato inválido", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		Cliente^ encontrado = Controller->buscarxIdArchivo(idBuscado);

		if (encontrado != nullptr) {
			// Verificamos que el ID encontrado también respete lo que dice el ComboBox (si hay filtro)
			if ((filtroAplicado == "Miembro" && encontrado->getTipo() != TipoCliente::Miembro) ||
				(filtroAplicado == "Normal" && encontrado->getTipo() != TipoCliente::Normal)) {
				// Existe, pero no es del tipo seleccionado en el combo, se ignora.
			}
			else {
				resultadoFinal->Add(encontrado);
			}
		}
	}
	// ESCENARIO B: La caja de ID está vacía, filtramos solo por el ComboBox
	else {
		if (String::IsNullOrWhiteSpace(filtroAplicado) || filtroAplicado == "Todos") {
			resultadoFinal = Controller->buscarTodosArchivo();
		}
		else {
			resultadoFinal = Controller->FiltrarPorTipo(filtroAplicado);
		}
	}

	// Mostramos resultados
	if (resultadoFinal->Count == 0) {
		MessageBox::Show("No se encontró ningún cliente que coincida con los criterios de búsqueda.", "Sin resultados", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	mostrarGrilla(resultadoFinal);
}

private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) { //Regresar

	OnRegresar(this, e);

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { //Nuevo

	SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();

	frmNuevoCliente^ ventana = gcnew frmNuevoCliente();
	ventana->ShowDialog();

	List<Cliente^>^ listaEmpleados = Controller->buscarTodosArchivo();
	mostrarGrilla(listaEmpleados);

}
private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) { //Eliminar
	

	if (this->dataGridView1->SelectedRows->Count > 0) {
		System::Windows::Forms::DialogResult respuesta = MessageBox::Show("¿Está seguro de que desea anular al empleado seleccionado?", "Confirmación de anulación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (respuesta == System::Windows::Forms::DialogResult::No) {
			return; // Salir si cancela
		}

		String^ idString = this->dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString(); //Obtenemos el codigo de la fila seleccionada

		int idSeleccionado = Convert::ToInt32(idString);

		SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();

		Controller->eliminarArchivo(idSeleccionado); //Llamamos a la funcion eliminarArchivo del controlador enviandole el codigo del empleado a eliminar

		List<Cliente^>^ listaActualizada = Controller->buscarTodosArchivo();
		mostrarGrilla(listaActualizada); //Actualizamos la grilla con la lista actualizada)

		MessageBox::Show("Cliente eliminado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else {
		MessageBox::Show("Por favor, seleccione un empleado para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

}
private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) { //Editar
	if (this->dataGridView1->SelectedRows->Count > 0) {

		SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();

		String^ idSeleccionado = this->dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString()->Trim(); //Obtenemos el id de la fila seleccionada 
		
		int idCliente = Convert::ToInt32(idSeleccionado);

		frmEditarCliente^ ventana = gcnew frmEditarCliente(idCliente);
		ventana->ShowDialog();

		List<Cliente^>^ listaClientes = Controller->buscarTodosArchivo();
		mostrarGrilla(listaClientes);
	}
	else {
		MessageBox::Show("Por favor, seleccione un cliente para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

}


private: void mostrarGrilla(List<Cliente^>^ clientes) {
	this->dataGridView1->Rows->Clear(); // Limpiar la grilla antes de mostrar los resultados

	if (clientes == nullptr || clientes->Count == 0) {
		//MessageBox::Show("No se encontraron clientes.", "Información", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	for (int i = 0; i < clientes->Count; i++) {

		Cliente^ cliente = clientes[i];

		if (cliente == nullptr) continue;

		array<String^>^ filaGrilla = gcnew array<String^>(7); // Ajusta el tamaño según las columnas que se muestran
		filaGrilla[0] = cliente->getIdPersona().ToString();
		filaGrilla[1] = cliente->getNombres();
		filaGrilla[2] = cliente->getApellidos();
		filaGrilla[3] = cliente->getTipo().ToString();
		filaGrilla[4] = cliente->getSaldo().ToString();

		//Usamos formato diferente para 5 xq para estado vamos a pintar la casilla de un color particular

		String^ estadoStr = cliente->getEstado() ? "Activo" : "Inactivo";
		filaGrilla[5] = estadoStr;

		filaGrilla[6] = cliente->getObservaciones();

		int rowIndex = this->dataGridView1->Rows->Add(filaGrilla);

		//Pintamos la celda [5] de esa fila dependiendo de su estado
		if (estadoStr == "Activo") {
			this->dataGridView1->Rows[rowIndex]->Cells[5]->Style->BackColor = System::Drawing::Color::LightGreen;
			this->dataGridView1->Rows[rowIndex]->Cells[5]->Style->ForeColor = System::Drawing::Color::DarkGreen;
		}
	
		else if (estadoStr == "Inactivo") {
			this->dataGridView1->Rows[rowIndex]->Cells[5]->Style->BackColor = System::Drawing::Color::LightPink;
			this->dataGridView1->Rows[rowIndex]->Cells[5]->Style->ForeColor = System::Drawing::Color::DarkRed;
		}
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //Limpiar

	this->cboFiltro->Text = "Todos";
	this->TextBuscar->Text = "";

	SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();
	List<Cliente^>^ ListaClientes = gcnew List<Cliente^>();

	ListaClientes = Controller->buscarTodosArchivo();

	mostrarGrilla(ListaClientes);
}

private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) { //para editar altok con doble click
	// Validamos que el clic haya sido en una fila real y no en los encabezados
	if (e->RowIndex >= 0) {
		// Extraemos el ID de la primera columna (índice 0)
		int idSeleccionado = Convert::ToInt32(this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value);

		// Abrimos la ventana de edición pasándole el ID
		frmEditarCliente^ ventanaEditar = gcnew frmEditarCliente(idSeleccionado);
		ventanaEditar->ShowDialog(); // ShowDialog pausa esta ventana hasta que se cierre la de edición

		SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();
		List<Cliente^>^ ListaClientes = gcnew List<Cliente^>();
		ListaClientes = Controller->buscarTodosArchivo();

		mostrarGrilla(ListaClientes);
	}
}
private: System::Void cboFiltro_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { //Filtro

	this->TextBuscar->Text = ""; //Limpiamos el buscador de la lupita antes para no causar conflictos

	SmartParkingSystemController::ClienteController^ controller = gcnew ClienteController();

	String^ filtro = this->cboFiltro->Text;

	SmartParkingSystemController::ClienteController^ Controller = gcnew ClienteController();
	List<Cliente^>^ ListaCompleta = Controller->buscarTodosArchivo();

	List<Cliente^>^ ListaFiltrada = gcnew List<Cliente^>();

	if (filtro == "Todos" || String::IsNullOrEmpty(filtro)) {
		ListaFiltrada = ListaCompleta; // Si dice "Todos", pasamos la lista entera
	}
	else {
		ListaFiltrada = controller->FiltrarPorTipo(filtro);
	}

	mostrarGrilla(ListaFiltrada);

}
private: System::Void btnMas_Click(System::Object^ sender, System::EventArgs^ e) { //Mas

	if (this->dataGridView1->SelectedRows->Count > 0) {
		try {

			int idCapturado = Convert::ToInt32(this->dataGridView1->SelectedRows[0]->Cells[0]->Value);

			this->idSelect = idCapturado;

			OnVerMas(this, e);
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se pudo extraer el ID del cliente de la tabla.", "Error de Lectura", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
	}
	else {
		MessageBox::Show("Por favor, seleccione un cliente para ver su información.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
};
}
