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
			// frmGraficasBalances
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 422);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->pnlTitulo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"frmGraficasBalances";
			this->Text = L"Graficas Balances";
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

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
};
}
