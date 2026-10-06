#pragma once
#include "frmTurno.h"
#include "frmEmergencia.h"
#include "frmBuscar.h"
#include "frmMapaAdmin.h"
#include "frmReportar.h"
#include "frmAdminEmpleados.h"
#include "frmTarifa.h"
/*
#include "frmAdminTarjetas.h"
#include "frmAdminSuscripciones.h"
#include "frmBalance"
*/ 

//Las pantallas q se abren dentro del panel tmb debe ser incluidas 
#include "frmBuscarPlaca.h"
#include "frmBuscarCliente.h"

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPrincipalAdmin
	/// </summary>
	public ref class frmPrincipalAdmin : public System::Windows::Forms::Form
	{
	public:
		frmPrincipalAdmin(void)
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
		~frmPrincipalAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlContenedor;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btnCerrarSesion;



	private: System::Windows::Forms::Panel^ pnlMenu;

	private: System::Windows::Forms::Button^ Empleadobtn;

	private: System::Windows::Forms::Button^ Rerportarbtn;

	private: System::Windows::Forms::Button^ Mapbtn;

	private: System::Windows::Forms::Button^ Searchbtn;

	private: System::Windows::Forms::Button^ Emergenciabtn;

	private: System::Windows::Forms::Button^ Turnobtn;
	private: System::Windows::Forms::Button^ AdminSubsbtn;
	private: System::Windows::Forms::Button^ AdminRFIDbtn;


	private: System::Windows::Forms::Button^ Balancebtn;
	private: System::Windows::Forms::Button^ AdminTarifasbtn;





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
			this->pnlContenedor = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->pnlMenu = (gcnew System::Windows::Forms::Panel());
			this->Balancebtn = (gcnew System::Windows::Forms::Button());
			this->AdminTarifasbtn = (gcnew System::Windows::Forms::Button());
			this->AdminSubsbtn = (gcnew System::Windows::Forms::Button());
			this->AdminRFIDbtn = (gcnew System::Windows::Forms::Button());
			this->Empleadobtn = (gcnew System::Windows::Forms::Button());
			this->Rerportarbtn = (gcnew System::Windows::Forms::Button());
			this->Mapbtn = (gcnew System::Windows::Forms::Button());
			this->Searchbtn = (gcnew System::Windows::Forms::Button());
			this->Emergenciabtn = (gcnew System::Windows::Forms::Button());
			this->Turnobtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->pnlMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlContenedor
			// 
			this->pnlContenedor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pnlContenedor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlContenedor->Location = System::Drawing::Point(211, 52);
			this->pnlContenedor->Name = L"pnlContenedor";
			this->pnlContenedor->Size = System::Drawing::Size(847, 560);
			this->pnlContenedor->TabIndex = 11;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1058, 52);
			this->panel1->TabIndex = 12;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(749, 34);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Administración Estacionamiento Inteligente Allá-Sí";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &frmPrincipalAdmin::textBox1_TextChanged);
			// 
			// btnCerrarSesion
			// 
			this->btnCerrarSesion->BackColor = System::Drawing::Color::Brown;
			this->btnCerrarSesion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnCerrarSesion->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->btnCerrarSesion->Location = System::Drawing::Point(0, 520);
			this->btnCerrarSesion->Name = L"btnCerrarSesion";
			this->btnCerrarSesion->Size = System::Drawing::Size(211, 40);
			this->btnCerrarSesion->TabIndex = 6;
			this->btnCerrarSesion->Text = L"Cerrar Sesión";
			this->btnCerrarSesion->UseVisualStyleBackColor = false;
			this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::btnCerrarSesion_Click);
			// 
			// pnlMenu
			// 
			this->pnlMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->pnlMenu->Controls->Add(this->btnCerrarSesion);
			this->pnlMenu->Controls->Add(this->Balancebtn);
			this->pnlMenu->Controls->Add(this->AdminTarifasbtn);
			this->pnlMenu->Controls->Add(this->AdminSubsbtn);
			this->pnlMenu->Controls->Add(this->AdminRFIDbtn);
			this->pnlMenu->Controls->Add(this->Empleadobtn);
			this->pnlMenu->Controls->Add(this->Rerportarbtn);
			this->pnlMenu->Controls->Add(this->Mapbtn);
			this->pnlMenu->Controls->Add(this->Searchbtn);
			this->pnlMenu->Controls->Add(this->Emergenciabtn);
			this->pnlMenu->Controls->Add(this->Turnobtn);
			this->pnlMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlMenu->Location = System::Drawing::Point(0, 52);
			this->pnlMenu->Name = L"pnlMenu";
			this->pnlMenu->Size = System::Drawing::Size(211, 560);
			this->pnlMenu->TabIndex = 10;
			// 
			// Balancebtn
			// 
			this->Balancebtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->Balancebtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->Balancebtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Balancebtn->ForeColor = System::Drawing::Color::White;
			this->Balancebtn->Location = System::Drawing::Point(0, 468);
			this->Balancebtn->Name = L"Balancebtn";
			this->Balancebtn->Size = System::Drawing::Size(211, 52);
			this->Balancebtn->TabIndex = 17;
			this->Balancebtn->Text = L"Balance";
			this->Balancebtn->UseVisualStyleBackColor = false;
			this->Balancebtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::Balancebtn_Click);
			// 
			// AdminTarifasbtn
			// 
			this->AdminTarifasbtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->AdminTarifasbtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->AdminTarifasbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->AdminTarifasbtn->ForeColor = System::Drawing::Color::White;
			this->AdminTarifasbtn->Location = System::Drawing::Point(0, 416);
			this->AdminTarifasbtn->Name = L"AdminTarifasbtn";
			this->AdminTarifasbtn->Size = System::Drawing::Size(211, 52);
			this->AdminTarifasbtn->TabIndex = 16;
			this->AdminTarifasbtn->Text = L"Administrar Tarifas";
			this->AdminTarifasbtn->UseVisualStyleBackColor = false;
			this->AdminTarifasbtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::AdminTarifasbtn_Click);
			// 
			// AdminSubsbtn
			// 
			this->AdminSubsbtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->AdminSubsbtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->AdminSubsbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AdminSubsbtn->ForeColor = System::Drawing::Color::White;
			this->AdminSubsbtn->Location = System::Drawing::Point(0, 364);
			this->AdminSubsbtn->Name = L"AdminSubsbtn";
			this->AdminSubsbtn->Size = System::Drawing::Size(211, 52);
			this->AdminSubsbtn->TabIndex = 15;
			this->AdminSubsbtn->Text = L"Administrar Membresías";
			this->AdminSubsbtn->UseVisualStyleBackColor = false;
			this->AdminSubsbtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::AdminSubsbtn_Click);
			// 
			// AdminRFIDbtn
			// 
			this->AdminRFIDbtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->AdminRFIDbtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->AdminRFIDbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AdminRFIDbtn->ForeColor = System::Drawing::Color::White;
			this->AdminRFIDbtn->Location = System::Drawing::Point(0, 312);
			this->AdminRFIDbtn->Name = L"AdminRFIDbtn";
			this->AdminRFIDbtn->Size = System::Drawing::Size(211, 52);
			this->AdminRFIDbtn->TabIndex = 14;
			this->AdminRFIDbtn->Text = L"Administrar Tarjetas";
			this->AdminRFIDbtn->UseVisualStyleBackColor = false;
			this->AdminRFIDbtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::AdminRFIDbtn_Click);
			// 
			// Empleadobtn
			// 
			this->Empleadobtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->Empleadobtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->Empleadobtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Empleadobtn->ForeColor = System::Drawing::Color::White;
			this->Empleadobtn->Location = System::Drawing::Point(0, 260);
			this->Empleadobtn->Name = L"Empleadobtn";
			this->Empleadobtn->Size = System::Drawing::Size(211, 52);
			this->Empleadobtn->TabIndex = 13;
			this->Empleadobtn->Text = L"Administrar Empleados";
			this->Empleadobtn->UseVisualStyleBackColor = false;
			this->Empleadobtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::Empleadobtn_Click);
			// 
			// Rerportarbtn
			// 
			this->Rerportarbtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->Rerportarbtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->Rerportarbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Rerportarbtn->ForeColor = System::Drawing::Color::White;
			this->Rerportarbtn->Location = System::Drawing::Point(0, 208);
			this->Rerportarbtn->Name = L"Rerportarbtn";
			this->Rerportarbtn->Size = System::Drawing::Size(211, 52);
			this->Rerportarbtn->TabIndex = 12;
			this->Rerportarbtn->Text = L"Reportar Vehículo";
			this->Rerportarbtn->UseVisualStyleBackColor = false;
			this->Rerportarbtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::Rerportarbtn_Click);
			// 
			// Mapbtn
			// 
			this->Mapbtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->Mapbtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->Mapbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mapbtn->ForeColor = System::Drawing::Color::White;
			this->Mapbtn->Location = System::Drawing::Point(0, 156);
			this->Mapbtn->Name = L"Mapbtn";
			this->Mapbtn->Size = System::Drawing::Size(211, 52);
			this->Mapbtn->TabIndex = 11;
			this->Mapbtn->Text = L"Mapa 2D";
			this->Mapbtn->UseVisualStyleBackColor = false;
			this->Mapbtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::Mapbtn_Click);
			// 
			// Searchbtn
			// 
			this->Searchbtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->Searchbtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->Searchbtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Searchbtn->ForeColor = System::Drawing::Color::White;
			this->Searchbtn->Location = System::Drawing::Point(0, 104);
			this->Searchbtn->Name = L"Searchbtn";
			this->Searchbtn->Size = System::Drawing::Size(211, 52);
			this->Searchbtn->TabIndex = 10;
			this->Searchbtn->Text = L"Buscar";
			this->Searchbtn->UseVisualStyleBackColor = false;
			this->Searchbtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::Searchbtn_Click);
			// 
			// Emergenciabtn
			// 
			this->Emergenciabtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->Emergenciabtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->Emergenciabtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Emergenciabtn->ForeColor = System::Drawing::Color::White;
			this->Emergenciabtn->Location = System::Drawing::Point(0, 52);
			this->Emergenciabtn->Name = L"Emergenciabtn";
			this->Emergenciabtn->Size = System::Drawing::Size(211, 52);
			this->Emergenciabtn->TabIndex = 9;
			this->Emergenciabtn->Text = L"Activar Emergencia";
			this->Emergenciabtn->UseVisualStyleBackColor = false;
			this->Emergenciabtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::Emergenciabtn_Click);
			// 
			// Turnobtn
			// 
			this->Turnobtn->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->Turnobtn->Dock = System::Windows::Forms::DockStyle::Top;
			this->Turnobtn->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Turnobtn->ForeColor = System::Drawing::Color::White;
			this->Turnobtn->Location = System::Drawing::Point(0, 0);
			this->Turnobtn->Name = L"Turnobtn";
			this->Turnobtn->Size = System::Drawing::Size(211, 52);
			this->Turnobtn->TabIndex = 8;
			this->Turnobtn->Text = L"Turno";
			this->Turnobtn->UseVisualStyleBackColor = false;
			this->Turnobtn->Click += gcnew System::EventHandler(this, &frmPrincipalAdmin::Turnobtn_Click);
			// 
			// frmPrincipalAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1058, 612);
			this->Controls->Add(this->pnlContenedor);
			this->Controls->Add(this->pnlMenu);
			this->Controls->Add(this->panel1);
			this->Name = L"frmPrincipalAdmin";
			this->Text = L"Gestión de Estacionamiento Alla-Si";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->pnlMenu->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Windows::Forms::Form^ actual = nullptr;

	private: System::Void AbrirFormulario(System::Windows::Forms::Form^ hijo) {
		//Cerramos la ventana ya abierta si es q se desea abrir otra
		if (this->actual != nullptr) {
			this->actual->Close();
		}

		this->actual = hijo; //Actualizamos a la ventana actualmente abierta

		hijo->TopLevel = false; //Evitamos que se abra sobre el dashboard

		hijo->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; //Quitamos bordes a todas las ventanas emergentes

		hijo->Dock = System::Windows::Forms::DockStyle::Fill;

		this->pnlContenedor->Controls->Add(hijo); //Agnadimos en el panel contenedor la ventana emergente
		hijo->Show();
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) { //Cerrar Sesión

	Application::Restart();

}
private: System::Void Turnobtn_Click(System::Object^ sender, System::EventArgs^ e) { //Turno

	this->AbrirFormulario(gcnew frmTurno());
}
private: System::Void Emergenciabtn_Click(System::Object^ sender, System::EventArgs^ e) { //Emergencia

	this->AbrirFormulario(gcnew frmEmergencia());

}
private: System::Void Searchbtn_Click(System::Object^ sender, System::EventArgs^ e) { //Buscar

	frmBuscar^ Buscador = gcnew frmBuscar(); //Creamos el objeto form del buscador
	Buscador->OnBuscarClienteClick += gcnew System::EventHandler(this, &frmPrincipalAdmin::AbrirBusquedaCliente);
	Buscador->OnBuscarPlacaClick += gcnew System::EventHandler(this, &frmPrincipalAdmin::AbrirBusquedaPlaca);

	this->AbrirFormulario(Buscador); //abrimos al buscador

}

//Funciones Callback
private: System::Void AbrirBusquedaCliente(System::Object^ sender, System::EventArgs^ e) {
	frmBuscarCliente^ BuscaClientes = gcnew frmBuscarCliente();
	BuscaClientes->OnRegresar += gcnew System::EventHandler(this, &frmPrincipalAdmin::RegresarBuscador);

	this->AbrirFormulario(BuscaClientes);
}

private: System::Void AbrirBusquedaPlaca(System::Object^ sender, System::EventArgs^ e) {

	frmBuscarPlaca^ BuscaPlacas = gcnew frmBuscarPlaca();
	BuscaPlacas->OnRegresar += gcnew System::EventHandler(this, &frmPrincipalAdmin::RegresarBuscador);

	this->AbrirFormulario(BuscaPlacas);
}

private: System::Void RegresarBuscador(System::Object^ sender, System::EventArgs^ e) {

	this->AbrirFormulario(gcnew frmBuscar());
}

//Piedad al revisar profe me tomo una eternidad aprender a hacer esto
//-------------------------------------------------------------------------------------------------------------------------
private: System::Void Mapbtn_Click(System::Object^ sender, System::EventArgs^ e) { //Mapa Admin

	this->AbrirFormulario(gcnew frmMapaAdmin());

}
private: System::Void Rerportarbtn_Click(System::Object^ sender, System::EventArgs^ e) { //Reportar

	this->AbrirFormulario(gcnew frmReportar());

}
private: System::Void Empleadobtn_Click(System::Object^ sender, System::EventArgs^ e) { //Admin Empleados

	this->AbrirFormulario(gcnew frmAdminEmpleados());

}
private: System::Void AdminRFIDbtn_Click(System::Object^ sender, System::EventArgs^ e) { //Admin Tarjetas RFID
}
private: System::Void AdminSubsbtn_Click(System::Object^ sender, System::EventArgs^ e) { //Admin Membresia
}
private: System::Void AdminTarifasbtn_Click(System::Object^ sender, System::EventArgs^ e) { //Admin Tarifas

	this->AbrirFormulario(gcnew frmTarifa());
}
private: System::Void Balancebtn_Click(System::Object^ sender, System::EventArgs^ e) { //Balance
}
};
}
