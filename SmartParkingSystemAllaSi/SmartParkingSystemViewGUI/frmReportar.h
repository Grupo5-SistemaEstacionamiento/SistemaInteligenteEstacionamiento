#pragma once

#include "frmRegistrarMulta.h"
#include "frmEditarMulta.h"

using namespace System::Globalization;

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmReportar
	/// </summary>
	public ref class frmReportar : public System::Windows::Forms::Form
	{
	private:
		PenalizacionController^ penalizacionController;

		void mostrarGrilla(
			System::Collections::Generic::List<Penalizacion^>^ lista)
		{
			dataGridView1->Rows->Clear();

			for each (Penalizacion ^ p in lista)
			{
				int fila = dataGridView1->Rows->Add(
					p->getPlacaVehiculo(),
					p->getTipo().ToString()->Replace("_", " "),
					p->getMotivo(),
					p->getFechaHora().ToString("dd/MM/yyyy"),
					p->getMonto().ToString(
						"F2", CultureInfo::InvariantCulture),
					p->getPagado() ? "Pagada" : "Por Pagar"
				);

				// Guardamos el ID sin agregar otra columna visible.
				dataGridView1->Rows[fila]->Tag =
					p->getIdPenalizacion();
			}

			dataGridView1->ClearSelection();
		}

		void actualizarGrilla()
		{
			mostrarGrilla(
				penalizacionController->listarPenalizaciones());
		}

		int obtenerIdSeleccionado()
		{
			if (dataGridView1->SelectedRows->Count == 0)
				return -1;

			DataGridViewRow^ fila =
				dataGridView1->SelectedRows[0];

			if (fila->IsNewRow || fila->Tag == nullptr)
				return -1;

			return safe_cast<int>(fila->Tag);
		}

	public:
		frmReportar(void)
		{
			InitializeComponent();

			this->Text = "Gestionar Penalizaciones";

			penalizacionController =
				gcnew PenalizacionController();

			dataGridView1->ReadOnly = true;
			dataGridView1->AllowUserToAddRows = false;
			dataGridView1->AllowUserToDeleteRows = false;
			dataGridView1->MultiSelect = false;

			dataGridView1->SelectionMode =
				DataGridViewSelectionMode::FullRowSelect;

			dataGridView1->AutoSizeColumnsMode =
				DataGridViewAutoSizeColumnsMode::Fill;

			actualizarGrilla();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmReportar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ TextBuscarPlaca;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;




















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmReportar::typeid));
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->TextBuscarPlaca = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->pictureBox2);
			this->groupBox2->Controls->Add(this->TextBuscarPlaca);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->groupBox2->Location = System::Drawing::Point(33, 22);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(1056, 116);
			this->groupBox2->TabIndex = 40;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Buscar Placa";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Purple;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(796, 59);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 38);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Limpiar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmReportar::button2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(742, 59);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(37, 38);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 39;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &frmReportar::pictureBox2_Click);
			// 
			// TextBuscarPlaca
			// 
			this->TextBuscarPlaca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TextBuscarPlaca->Location = System::Drawing::Point(288, 62);
			this->TextBuscarPlaca->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TextBuscarPlaca->Name = L"TextBuscarPlaca";
			this->TextBuscarPlaca->Size = System::Drawing::Size(433, 34);
			this->TextBuscarPlaca->TabIndex = 38;
			this->TextBuscarPlaca->UseWaitCursor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(28, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(229, 29);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Placa del vehiculo:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Controls->Add(this->groupBox2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 68);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1129, 542);
			this->panel2->TabIndex = 25;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column6, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(33, 145);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1056, 384);
			this->dataGridView1->TabIndex = 41;
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(33, 14);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(721, 39);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Gestionar Penalizaciones";
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
			this->panel1->TabIndex = 24;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->button5);
			this->panel3->Controls->Add(this->button4);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 610);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1129, 79);
			this->panel3->TabIndex = 26;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(745, 27);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(167, 38);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmReportar::button1_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Red;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(553, 27);
			this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(167, 38);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Eliminar";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &frmReportar::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(347, 27);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(167, 38);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Editar";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &frmReportar::button4_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LimeGreen;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(153, 27);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(167, 38);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Nuevo";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &frmReportar::button3_Click);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Placa del vehiculo";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Tipo de penalizacion";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Anotaciones";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Fecha";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Monto";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Estado";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// frmReportar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1129, 689);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmReportar";
			this->Text = L"frmReportar";
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) { // Buscar (Lupa)
		String^ placa = TextBuscarPlaca->Text->Trim();

		if (String::IsNullOrWhiteSpace(placa))
		{
			MessageBox::Show(
				"Ingrese una placa para realizar la búsqueda.",
				"Búsqueda",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			return;
		}

		auto resultados =
			penalizacionController->buscarPorPlaca(placa);

		mostrarGrilla(resultados);

		if (resultados->Count == 0)
		{
			MessageBox::Show(
				"No se encontraron penalizaciones para la placa ingresada.",
				"Sin resultados",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Limpiar
		TextBuscarPlaca->Clear();
		actualizarGrilla();
		TextBuscarPlaca->Focus();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Registrar
		frmRegistrarMulta^ ventana =
			gcnew frmRegistrarMulta();

		if (ventana->ShowDialog(this) ==
			System::Windows::Forms::DialogResult::OK)
		{
			TextBuscarPlaca->Clear();
			actualizarGrilla();
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // Editar
		int id = obtenerIdSeleccionado();

		if (id <= 0)
		{
			MessageBox::Show(
				"Debe seleccionar una penalización de la tabla "
				"para poder editarla.",
				"Selección requerida",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			return;
		}

		frmEditarMulta^ ventana =
			gcnew frmEditarMulta(id);

		if (ventana->ShowDialog(this) ==
			System::Windows::Forms::DialogResult::OK)
		{
			TextBuscarPlaca->Clear();
			actualizarGrilla();
		}
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { // Eliminar
		int id = obtenerIdSeleccionado();

		if (id <= 0)
		{
			MessageBox::Show(
				"Debe seleccionar una penalización de la tabla "
				"para poder eliminarla.",
				"Selección requerida",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			return;
		}

		System::Windows::Forms::DialogResult respuesta =
			MessageBox::Show(
				"¿Está seguro de que desea eliminar "
				"la penalización seleccionada?",
				"Confirmar eliminación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question);

		if (respuesta !=
			System::Windows::Forms::DialogResult::Yes)
			return;

		bool eliminado =
			penalizacionController->eliminarPenalizacion(id);

		if (!eliminado)
		{
			MessageBox::Show(
				"No se pudo eliminar la penalización.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			return;
		}

		MessageBox::Show(
			"Penalización eliminada correctamente.",
			"Eliminación exitosa",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information);

		TextBuscarPlaca->Clear();
		actualizarGrilla();
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Regresar
		this->DialogResult =
			System::Windows::Forms::DialogResult::Cancel;

		this->Close();
	}
};
}