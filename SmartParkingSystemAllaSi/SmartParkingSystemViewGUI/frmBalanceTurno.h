#pragma once

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemController;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmBalanceTurno
	/// </summary>
	public ref class frmBalanceTurno : public System::Windows::Forms::Form
	{
	private:
		TurnoCajaController^ turnoController;
		TableLayoutPanel^ tablaBalance;

		void agregarDato(
			int fila,
			String^ titulo,
			String^ valor)
		{
			Label^ etiqueta = gcnew Label();
			etiqueta->Text = titulo;
			etiqueta->Dock = DockStyle::Fill;
			etiqueta->TextAlign = ContentAlignment::MiddleLeft;
			etiqueta->Font = gcnew Drawing::Font(
				L"Arial", 10, FontStyle::Bold);

			Label^ contenido = gcnew Label();
			contenido->Text = valor;
			contenido->Dock = DockStyle::Fill;
			contenido->TextAlign = ContentAlignment::MiddleLeft;
			contenido->AutoEllipsis = true;

			tablaBalance->Controls->Add(etiqueta, 0, fila);
			tablaBalance->Controls->Add(contenido, 1, fila);
		}

		void mostrarBalance()
		{
			tablaBalance->Controls->Clear();

			TurnoCaja^ turno =
				turnoController->buscarTurnoAbierto();

			if (turno == nullptr)
			{
				agregarDato(0, L"Estado", L"No hay turno abierto");
				return;
			}

			String^ empleado = L"No identificado";

			if (turno->getEmpleado() != nullptr)
			{
				empleado =
					turno->getEmpleado()->getCodigoEmpleado();
			}

			agregarDato(0, L"Turno",
				turno->getIdTurno().ToString());

			agregarDato(1, L"Empleado", empleado);

			agregarDato(2, L"Fecha de inicio",
				turno->getFechaHoraIngreso().ToString(
					L"dd/MM/yyyy HH:mm:ss"));

			agregarDato(3, L"Estado", turno->getEstado());

			agregarDato(4, L"Saldo inicial",
				L"S/ " + turno->getSaldoInicial().ToString(L"F2"));

			agregarDato(5, L"Saldo final",
				L"Pendiente de cierre");
		}

	public:
		frmBalanceTurno(void)
		{
			InitializeComponent();

			turnoController = gcnew TurnoCajaController();

			tablaBalance = gcnew TableLayoutPanel();
			tablaBalance->ColumnCount = 2;
			tablaBalance->RowCount = 6;
			tablaBalance->Location = Drawing::Point(25, 65);
			tablaBalance->Size = Drawing::Size(630, 155);
			tablaBalance->Anchor =
				AnchorStyles::Top | AnchorStyles::Left |
				AnchorStyles::Right;

			tablaBalance->ColumnStyles->Add(
				gcnew ColumnStyle(SizeType::Percent, 40));

			tablaBalance->ColumnStyles->Add(
				gcnew ColumnStyle(SizeType::Percent, 60));

			for (int i = 0; i < 6; i++)
			{
				tablaBalance->RowStyles->Add(
					gcnew RowStyle(SizeType::Percent, 100.0f / 6));
			}

			this->Controls->Add(tablaBalance);
			tablaBalance->BringToFront();

			try
			{
				// Recuperar la información del turno.
				mostrarBalance();
			}
			catch (Exception^ ex)
			{
				// Permitir que el formulario permanezca abierto.
				tablaBalance->Controls->Clear();

				agregarDato(
					0,
					L"Estado",
					L"No se pudieron recuperar los datos");

				MessageBox::Show(
					L"Error al recuperar el balance:\n" + ex->Message,
					L"Advertencia",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmBalanceTurno()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;

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
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(254, 242);
			this->btnRegresarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(166, 31);
			this->btnRegresarEdit->TabIndex = 21;
			this->btnRegresarEdit->Text = L"Regresar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmBalanceTurno::btnRegresarEdit_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 292);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(683, 51);
			this->panel2->TabIndex = 20;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(683, 42);
			this->panel1->TabIndex = 19;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(8, 12);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 22);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Balance Turno";
			// 
			// frmBalanceTurno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(683, 343);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"frmBalanceTurno";
			this->Text = L"Balance Específico Durante el Turno Actual";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
		this->DialogResult =
			System::Windows::Forms::DialogResult::Cancel;

		this->Close();
	}
};
}
