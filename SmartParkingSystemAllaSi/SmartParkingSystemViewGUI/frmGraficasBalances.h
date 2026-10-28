#pragma once
//#include "frmBalances.h"



namespace SmartParkingSystemViewGUI {

	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmGraficasBalances
	/// </summary>

	public ref class frmGraficasBalances : public System::Windows::Forms::Form
	{

	
	public:
		// Variable para guardar el panel que viene desde afuera
		System::Windows::Forms::Panel^ panelContenedorPadre;

		// Constructor que recibe el panel contenedor
		frmGraficasBalances(System::Windows::Forms::Panel^ panelDestino) {
			InitializeComponent();
			panelContenedorPadre = panelDestino; // Lo guardamos
		}

		// (Opcional) Si en algún lugar aún creas el formulario sin parámetros, 
		// puedes dejar este constructor por defecto vacío para evitar errores:
		frmGraficasBalances() {
			InitializeComponent();
			panelContenedorPadre = nullptr;
			label1->Visible = false;
			label2->Visible = false;
			comboBoxFiltro1->Visible = false;
			comboBoxFiltro2->Visible = false;
		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmGraficasBalances()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlTitulo;
	protected:
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DateTimePicker^ dtpFechaVencimiento;
	private: System::Windows::Forms::Label^ lblFechaVencimiento;
	private: System::Windows::Forms::ComboBox^ comboFrecuencia;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBoxFiltro1;
	private: System::Windows::Forms::ComboBox^ comboBoxFiltro2;
	private: System::Windows::Forms::Label^ label2;



	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dtpFechaVencimiento = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblFechaVencimiento = (gcnew System::Windows::Forms::Label());
			this->comboFrecuencia = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxFiltro1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxFiltro2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pnlTitulo->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlTitulo
			// 
			this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlTitulo->Controls->Add(this->lblTitulo);
			this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitulo->Location = System::Drawing::Point(0, 0);
			this->pnlTitulo->Margin = System::Windows::Forms::Padding(2);
			this->pnlTitulo->Name = L"pnlTitulo";
			this->pnlTitulo->Size = System::Drawing::Size(757, 53);
			this->pnlTitulo->TabIndex = 57;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Gadugi", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(9, 10);
			this->lblTitulo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(274, 32);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Graficas de balances";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 358);
			this->panel3->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(757, 64);
			this->panel3->TabIndex = 58;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(280, 19);
			this->button1->Margin = System::Windows::Forms::Padding(2, 1, 2, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 31);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmGraficasBalances::button1_Click);
			// 
			// dtpFechaVencimiento
			// 
			this->dtpFechaVencimiento->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtpFechaVencimiento->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dtpFechaVencimiento->CalendarTitleBackColor = System::Drawing::SystemColors::ControlText;
			this->dtpFechaVencimiento->CalendarTitleForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->dtpFechaVencimiento->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dtpFechaVencimiento->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpFechaVencimiento->Location = System::Drawing::Point(595, 311);
			this->dtpFechaVencimiento->Margin = System::Windows::Forms::Padding(2);
			this->dtpFechaVencimiento->Name = L"dtpFechaVencimiento";
			this->dtpFechaVencimiento->Size = System::Drawing::Size(151, 35);
			this->dtpFechaVencimiento->TabIndex = 106;
			// 
			// lblFechaVencimiento
			// 
			this->lblFechaVencimiento->AutoSize = true;
			this->lblFechaVencimiento->BackColor = System::Drawing::SystemColors::Control;
			this->lblFechaVencimiento->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFechaVencimiento->Location = System::Drawing::Point(22, 72);
			this->lblFechaVencimiento->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblFechaVencimiento->Name = L"lblFechaVencimiento";
			this->lblFechaVencimiento->Size = System::Drawing::Size(239, 26);
			this->lblFechaVencimiento->TabIndex = 111;
			this->lblFechaVencimiento->Text = L"Seleccione frecuencia:";
			this->lblFechaVencimiento->Click += gcnew System::EventHandler(this, &frmGraficasBalances::lblFechaVencimiento_Click);
			// 
			// comboFrecuencia
			// 
			this->comboFrecuencia->FormattingEnabled = true;
			this->comboFrecuencia->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Vista Diaria", L"Vista Mensual" });
			this->comboFrecuencia->Location = System::Drawing::Point(266, 77);
			this->comboFrecuencia->Name = L"comboFrecuencia";
			this->comboFrecuencia->Size = System::Drawing::Size(154, 21);
			this->comboFrecuencia->TabIndex = 112;
			this->comboFrecuencia->SelectedIndexChanged += gcnew System::EventHandler(this, &frmGraficasBalances::comboFrecuencia_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(23, 121);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 22);
			this->label1->TabIndex = 113;
			this->label1->Text = L"default";
			// 
			// comboBoxFiltro1
			// 
			this->comboBoxFiltro1->FormattingEnabled = true;
			this->comboBoxFiltro1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Vista diaria", L"Vista mensual" });
			this->comboBoxFiltro1->Location = System::Drawing::Point(266, 122);
			this->comboBoxFiltro1->Name = L"comboBoxFiltro1";
			this->comboBoxFiltro1->Size = System::Drawing::Size(154, 21);
			this->comboBoxFiltro1->TabIndex = 114;
			this->comboBoxFiltro1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmGraficasBalances::comboBoxFiltro1_SelectedIndexChanged);
			// 
			// comboBoxFiltro2
			// 
			this->comboBoxFiltro2->FormattingEnabled = true;
			this->comboBoxFiltro2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"2024", L"2025", L"2026" });
			this->comboBoxFiltro2->Location = System::Drawing::Point(266, 168);
			this->comboBoxFiltro2->Name = L"comboBoxFiltro2";
			this->comboBoxFiltro2->Size = System::Drawing::Size(154, 21);
			this->comboBoxFiltro2->TabIndex = 115;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(23, 168);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 22);
			this->label2->TabIndex = 116;
			this->label2->Text = L"default";
			// 
			// frmGraficasBalances
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 422);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBoxFiltro2);
			this->Controls->Add(this->comboBoxFiltro1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboFrecuencia);
			this->Controls->Add(this->lblFechaVencimiento);
			this->Controls->Add(this->dtpFechaVencimiento);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->pnlTitulo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"frmGraficasBalances";
			this->Text = L"Graficas Balances";
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Si guardamos el panel contenedor padre, lo usamos para limpiar o volver
			if (panelContenedorPadre != nullptr) {
				// Opción A: Limpiamos el panel para dejar libre el menú lateral
				panelContenedorPadre->Controls->Clear();


			}
			else {
				// Respaldo por si se abrió de otra forma
				this->Close();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al regresar: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
private: System::Void lblFechaVencimiento_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboFrecuencia_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	if (comboFrecuencia->SelectedItem == nullptr) {
		label1->Visible = false;
		label2->Visible = false;
		comboBoxFiltro1->Visible = false;
		comboBoxFiltro2->Visible = false;
		return;
	}

	String^ seleccion = comboFrecuencia->SelectedItem->ToString();

	label1->Visible = true;
	comboBoxFiltro1->Visible = true;

	if (seleccion == "Vista Diaria") {

		// Configuramos etiquetas y opciones para el filtro diario
		label2->Visible = true;
		comboBoxFiltro2->Visible = true;

		label1->Text = "Seleccionar Mes:";
		label2->Text = "Seleccionar Año:";
		// Llenamos el ComboBox con los meses del año
		comboBoxFiltro1->Items->Clear();
		comboBoxFiltro1->Items->Add("Enero");
		comboBoxFiltro1->Items->Add("Febrero");
		comboBoxFiltro1->Items->Add("Marzo");
		comboBoxFiltro1->Items->Add("Abril");
		comboBoxFiltro1->Items->Add("Mayo");
		comboBoxFiltro1->Items->Add("Junio");
		comboBoxFiltro1->Items->Add("Julio");
		comboBoxFiltro1->Items->Add("Agosto");
		comboBoxFiltro1->Items->Add("Setiembre");
		comboBoxFiltro1->Items->Add("Octubre");
		comboBoxFiltro1->Items->Add("Noviembre");
		comboBoxFiltro1->Items->Add("Diciembre");
		// ... (puedes agregar los demás meses o cargarlos por código desde tus datos)
		comboBoxFiltro1->SelectedIndex = 0;
		comboBoxFiltro2->SelectedIndex = 0;

	}
	else if (seleccion == "Vista Mensual") {
		// Configuramos para la vista mensual (ej. solo elegir el año a analizar)
		label1->Text = "Seleccionar Año:";
		comboBoxFiltro2->Visible = false;
		label2->Visible = false;
		//lblSelector2->Visible = false;      // Ocultamos el segundo selector si no hace falta
		//comboBoxFiltro2->Visible = false;

		// Llenamos con los años disponibles en tus registros de balances
		comboBoxFiltro1->Items->Clear();
		comboBoxFiltro1->Items->Add("2025");
		comboBoxFiltro1->Items->Add("2026");
		comboBoxFiltro1->SelectedIndex = 0;
	}
}

	private: System::Void comboBoxFiltro1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    // Verificamos qué vista está activa y actualizamos el gráfico con el nuevo filtro
    if (comboFrecuencia->SelectedItem->ToString() == "Vista Diaria") {
        // Obtener el mes seleccionado y recargar la gráfica diaria
        // CargarGraficaDiariaPorMes(comboBoxFiltro1->SelectedItem->ToString());
    } 
    else {
        // Obtener el año seleccionado y recargar la gráfica mensual
        // CargarGraficaMensualPorAnio(comboBoxFiltro1->SelectedItem->ToString());
    }

}
};
}
