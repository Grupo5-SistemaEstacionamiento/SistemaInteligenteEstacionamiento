#pragma once
#include "frmNuevoVehiculo.h"
#include "frmEditarVehiculo.h"
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
	/// Summary for frmMorePlaca
	/// </summary>
	public ref class frmMorePlaca : public System::Windows::Forms::Form
	{
	public:

		int idSelect;

		frmMorePlaca(void)
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->cboFiltro->SelectedIndex = 0;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMorePlaca()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cboFiltro;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnLimpiar;

	private: System::Windows::Forms::PictureBox^ pbLupita;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ btnMas;
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ btnRegresar;

	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnNuevo;

	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
























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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMorePlaca::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->cboFiltro = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->pbLupita = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnMas = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnRegresar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLupita))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// cboFiltro
			// 
			this->cboFiltro->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cboFiltro->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboFiltro->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cboFiltro->FormattingEnabled = true;
			this->cboFiltro->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Todos", L"Automovil", L"Motocicleta" });
			this->cboFiltro->Location = System::Drawing::Point(285, 149);
			this->cboFiltro->Name = L"cboFiltro";
			this->cboFiltro->Size = System::Drawing::Size(374, 41);
			this->cboFiltro->TabIndex = 41;
			this->cboFiltro->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMorePlaca::cboFiltro_SelectedIndexChanged);
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
			// btnLimpiar
			// 
			this->btnLimpiar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnLimpiar->BackColor = System::Drawing::Color::Purple;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::Color::White;
			this->btnLimpiar->Location = System::Drawing::Point(824, 74);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(165, 48);
			this->btnLimpiar->TabIndex = 12;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmMorePlaca::btnLimpiar_Click);
			// 
			// pbLupita
			// 
			this->pbLupita->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pbLupita->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLupita.Image")));
			this->pbLupita->Location = System::Drawing::Point(777, 74);
			this->pbLupita->Name = L"pbLupita";
			this->pbLupita->Size = System::Drawing::Size(42, 48);
			this->pbLupita->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbLupita->TabIndex = 39;
			this->pbLupita->TabStop = false;
			this->pbLupita->Click += gcnew System::EventHandler(this, &frmMorePlaca::pbLupita_Click);
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
			this->label2->Size = System::Drawing::Size(223, 33);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Placa Vehiculo:";
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox2->Controls->Add(this->cboFiltro);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->btnLimpiar);
			this->groupBox2->Controls->Add(this->pbLupita);
			this->groupBox2->Controls->Add(this->txtBuscar);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->groupBox2->Location = System::Drawing::Point(38, 22);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox2->Size = System::Drawing::Size(1188, 209);
			this->groupBox2->TabIndex = 40;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Buscar Vehiculo";
			// 
			// txtBuscar
			// 
			this->txtBuscar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->txtBuscar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBuscar->Location = System::Drawing::Point(285, 77);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(486, 40);
			this->txtBuscar->TabIndex = 38;
			this->txtBuscar->UseWaitCursor = true;
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
			this->panel2->TabIndex = 37;
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
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column1,
					this->Column5, this->Column8, this->Column2, this->Column3, this->Column4, this->Column6, this->Column7
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(38, 240);
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
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmMorePlaca::dataGridView1_CellDoubleClick);
			// 
			// btnMas
			// 
			this->btnMas->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnMas->BackColor = System::Drawing::Color::Teal;
			this->btnMas->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMas->ForeColor = System::Drawing::Color::White;
			this->btnMas->Location = System::Drawing::Point(747, 34);
			this->btnMas->Name = L"btnMas";
			this->btnMas->Size = System::Drawing::Size(188, 48);
			this->btnMas->TabIndex = 16;
			this->btnMas->Text = L"Más";
			this->btnMas->UseVisualStyleBackColor = false;
			this->btnMas->Click += gcnew System::EventHandler(this, &frmMorePlaca::btnMas_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnEditar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::Color::White;
			this->btnEditar->Location = System::Drawing::Point(322, 34);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(188, 48);
			this->btnEditar->TabIndex = 13;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMorePlaca::btnEditar_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->btnMas);
			this->panel3->Controls->Add(this->btnRegresar);
			this->panel3->Controls->Add(this->btnEliminar);
			this->panel3->Controls->Add(this->btnEditar);
			this->panel3->Controls->Add(this->btnNuevo);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 764);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1270, 98);
			this->panel3->TabIndex = 38;
			// 
			// btnRegresar
			// 
			this->btnRegresar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnRegresar->BackColor = System::Drawing::Color::Brown;
			this->btnRegresar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresar->ForeColor = System::Drawing::Color::White;
			this->btnRegresar->Location = System::Drawing::Point(954, 34);
			this->btnRegresar->Name = L"btnRegresar";
			this->btnRegresar->Size = System::Drawing::Size(188, 48);
			this->btnRegresar->TabIndex = 15;
			this->btnRegresar->Text = L"Regresar";
			this->btnRegresar->UseVisualStyleBackColor = false;
			this->btnRegresar->Click += gcnew System::EventHandler(this, &frmMorePlaca::btnRegresar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnEliminar->BackColor = System::Drawing::Color::Red;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::Color::White;
			this->btnEliminar->Location = System::Drawing::Point(538, 34);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(188, 48);
			this->btnEliminar->TabIndex = 14;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMorePlaca::btnEliminar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnNuevo->BackColor = System::Drawing::Color::LimeGreen;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::Color::White;
			this->btnNuevo->Location = System::Drawing::Point(111, 34);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(188, 48);
			this->btnNuevo->TabIndex = 12;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMorePlaca::btnNuevo_Click);
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
			this->textInfoCliente->Text = L"Gestionar Vehiculos";
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
			this->panel1->TabIndex = 36;
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
			this->Column5->HeaderText = L"Placa";
			this->Column5->MinimumWidth = 8;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 80;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Dueño";
			this->Column8->MinimumWidth = 8;
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Width = 180;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Marca";
			this->Column2->MinimumWidth = 8;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Modelo";
			this->Column3->MinimumWidth = 8;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Color";
			this->Column4->MinimumWidth = 8;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 80;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Tipo";
			this->Column6->MinimumWidth = 8;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Width = 80;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Anotaciones";
			this->Column7->MinimumWidth = 8;
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Width = 550;
			// 
			// frmMorePlaca
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 862);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmMorePlaca";
			this->Text = L"frmMorePlaca";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLupita))->EndInit();
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

//Para regresar con eventos------------------------------------------------------------------------------------

public:

	event System::EventHandler^ OnRegresar;

private: System::Void btnRegresar_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar

	OnRegresar(this, e);

}

//--------------------------------------------------------------------------------------------------------------


private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) { //Nuevo

	frmNuevoVehiculo^ ventana = gcnew frmNuevoVehiculo();
	ventana->ShowDialog();

	recargarGrilla();
}

private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) { //Limpiar
	this->txtBuscar->Text = "";
	this->cboFiltro->SelectedIndex = 0;
	recargarGrilla();
}

private: System::Void pbLupita_Click(System::Object^ sender, System::EventArgs^ e) { //Lupita
	SmartParkingSystemController::VehiculoController^ Controller = gcnew SmartParkingSystemController::VehiculoController();
	String^ filtroAplicado = this->cboFiltro->Text;
	List<Vehiculo^>^ resultadoFinal = gcnew List<Vehiculo^>();

	// ESCENARIO A: El usuario escribió una placa en la caja de texto
	if (!String::IsNullOrWhiteSpace(this->txtBuscar->Text)) {

		Vehiculo^ encontrado = Controller->buscarxPlacaArchivo(this->txtBuscar->Text);

		if (encontrado != nullptr) {
			// Verificamos que el vehículo encontrado coincida con el ComboBox (si hay filtro activo)
			if ((filtroAplicado == "Automovil" && encontrado->getTipo() != TipoVehiculo::automovil) ||
				(filtroAplicado == "Motocicleta" && encontrado->getTipo() != TipoVehiculo::motocicleta)) {
				// Existe la placa, pero no es del tipo seleccionado en el combo.
			}
			else {
				resultadoFinal->Add(encontrado);
			}
		}
	}
	// ESCENARIO B: La caja de placa está vacía, filtramos solo por el ComboBox
	else {
		if (String::IsNullOrWhiteSpace(filtroAplicado) || filtroAplicado == "Todos") {
			resultadoFinal = Controller->buscarTodosArchivo();
		}
		else {
			resultadoFinal = Controller->FiltrarPorTipoArchivo(filtroAplicado);
		}
	}

	// Mostramos resultados
	if (resultadoFinal->Count == 0) {
		MessageBox::Show("No se encontró ningún vehículo que coincida con los criterios de búsqueda.", "Sin resultados", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	mostrarGrilla(resultadoFinal);
}

private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) { //Editar

	if (this->dataGridView1->SelectedRows->Count > 0) {

		String^ idSeleccionado = this->dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString()->Trim(); //Obtenemos el id de la fila seleccionada 

		int idVehiculo = Convert::ToInt32(idSeleccionado);

		frmEditarVehiculo^ ventana = gcnew frmEditarVehiculo(idVehiculo);
		ventana->ShowDialog();

		recargarGrilla();
	}
	else {
		MessageBox::Show("Por favor, seleccione un vehículo para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

}

private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) { //Eliminar

	if (this->dataGridView1->SelectedRows->Count > 0) {
		System::Windows::Forms::DialogResult respuesta = MessageBox::Show("¿Está seguro de que desea eliminar al vehículo seleccionado?", "Confirmación de anulación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (respuesta == System::Windows::Forms::DialogResult::No) {
			return; // Salir si cancela
		}

		String^ idString = this->dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString(); //Obtenemos el codigo de la fila seleccionada

		int idSeleccionado = Convert::ToInt32(idString);

		SmartParkingSystemController::VehiculoController^ Controller = gcnew VehiculoController();

		Controller->eliminarArchivo(idSeleccionado); //Llamamos a la funcion eliminarArchivo del controlador enviandole el codigo del empleado a eliminar

		recargarGrilla();

		MessageBox::Show("Vehiculo eliminado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else {
		MessageBox::Show("Por favor, seleccione un empleado para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

}

private: System::Void btnMas_Click(System::Object^ sender, System::EventArgs^ e) { //Mas

	if (this->dataGridView1->SelectedRows->Count > 0) {
		try {

			int idCapturado = Convert::ToInt32(this->dataGridView1->SelectedRows[0]->Cells[0]->Value);

			this->idSelect = idCapturado;

			//OnVerMasV(this, e); //ver mas del vehiculo
		}
		catch (Exception^ ex) {
			MessageBox::Show("No se pudo extraer el ID del vehiculo de la tabla.", "Error de Lectura", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	else {
		MessageBox::Show("Por favor, seleccione un cliente para ver su información.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

}


private: bool obtenerColorVehiculo(String^ nombre, System::Drawing::Color% resultado) {
	String^ n = (nombre == nullptr) ? "" : nombre->Trim()->ToUpper();
	if (n == "ROJO") resultado = System::Drawing::Color::Red; //1
	else if (n == "AZUL") resultado = System::Drawing::Color::RoyalBlue; //2 
	else if (n == "CELESTE") resultado = System::Drawing::Color::SkyBlue; //3
	else if (n == "VERDE") resultado = System::Drawing::Color::SeaGreen; //4
	else if (n == "AMARILLO") resultado = System::Drawing::Color::Gold; //5
	else if (n == "NARANJA") resultado = System::Drawing::Color::DarkOrange; //6
	else if (n == "NEGRO") resultado = System::Drawing::Color::Black; //7
	else if (n == "BLANCO") resultado = System::Drawing::Color::White; //8
	else if (n == "GRIS") resultado = System::Drawing::Color::Gray; //9
	else if (n == "PLATA" || n == "PLATEADO") resultado = System::Drawing::Color::Silver; //10
	else if (n == "MARRON" || n == "MARRÓN") resultado = System::Drawing::Color::SaddleBrown; //11
	else if (n == "BEIGE") resultado = System::Drawing::Color::Beige; //12
	else if (n == "TURQUESA") resultado = System::Drawing::Color::Turquoise; //13
	else if (n == "MORADO") resultado = System::Drawing::Color::MediumSlateBlue; //14


	
	else return false;
	return true;
}


private: void recargarGrilla() {
	VehiculoController^ controller = gcnew VehiculoController();
	String^ filtro = this->cboFiltro->Text;
	List<Vehiculo^>^ lista = (String::IsNullOrWhiteSpace(filtro) || filtro == "Todos")
		? controller->buscarTodosArchivo()
		: controller->FiltrarPorTipoArchivo(filtro);
	mostrarGrilla(lista);
}

private: System::Void cboFiltro_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { //Filtro
	this->txtBuscar->Text = ""; // evita conflicto con la búsqueda por placa
	recargarGrilla();
}

private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) { //Editar con doble clic
	if (e->RowIndex < 0) return; // ignora los encabezados
	int id = Convert::ToInt32(this->dataGridView1->Rows[e->RowIndex]->Cells[0]->Value);
	frmEditarVehiculo^ ventana = gcnew frmEditarVehiculo(id);
	ventana->ShowDialog();
	recargarGrilla();
}

private: void mostrarGrilla(List<Vehiculo^>^ vehiculos) {
	this->dataGridView1->Rows->Clear();
	if (vehiculos == nullptr || vehiculos->Count == 0) return;

	for each (Vehiculo ^ vehiculo in vehiculos) {
		if (vehiculo == nullptr) continue;

		String^ textoDueno = "Sin dueño";
		Cliente^ dueno = vehiculo->getCliente();
		if (dueno != nullptr) {
			textoDueno = dueno->getIdPersona().ToString() + " - " + dueno->getNombres() + " " + dueno->getApellidos();
		}

		array<String^>^ fila = gcnew array<String^>(8);
		fila[0] = vehiculo->getIdVehiculo().ToString();
		fila[1] = vehiculo->getPlaca();
		fila[2] = textoDueno;
		fila[3] = vehiculo->getMarca();
		fila[4] = vehiculo->getModelo();
		fila[5] = vehiculo->getColor();
		fila[6] = (vehiculo->getTipo() == TipoVehiculo::automovil) ? "Automóvil" : "Motocicleta";

		fila[7] = vehiculo->getAnotaciones();

		int rowIndex = this->dataGridView1->Rows->Add(fila);

		System::Drawing::Color colorCelda;
		if (obtenerColorVehiculo(vehiculo->getColor(), colorCelda)) {
			DataGridViewCell^ celda = this->dataGridView1->Rows[rowIndex]->Cells[5];
			celda->Style->BackColor = colorCelda;
			double brillo = 0.299 * colorCelda.R + 0.587 * colorCelda.G + 0.114 * colorCelda.B;
			celda->Style->ForeColor = (brillo > 140) ? System::Drawing::Color::Black : System::Drawing::Color::White;
		}
	}
}

//-------------------------------------------------------------------------------------------------------
};
}
