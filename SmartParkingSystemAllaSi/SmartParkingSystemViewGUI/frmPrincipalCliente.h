#pragma once
#include "frmConsultarTiempo.h"
#include "frmInfoCliente.h"
#include "frmModInfo.h"
#include "frmSuscripcion.h"
#include "frmSaldo.h"
#include "frmMapa.h"
#include "frmVehiculosAsociados.h"
#include "frmOfrecerSuscripcion.h"

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
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
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ pnlContenedor;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btnModInfo;
	private: System::Windows::Forms::Button^ btnSubscipcion;

	private: System::Windows::Forms::Button^ btnConsultaTiempo;


	private: System::Windows::Forms::Button^ btnCerrarSesion;
	private: System::Windows::Forms::Panel^ pnlMenu;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnVehiculosAsociados;

	private: System::Windows::Forms::Button^ btnSaldo;

	private: System::Windows::Forms::Button^ btnMapa2D;














	protected:

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
			this->pnlContenedor = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnModInfo = (gcnew System::Windows::Forms::Button());
			this->btnSubscipcion = (gcnew System::Windows::Forms::Button());
			this->btnConsultaTiempo = (gcnew System::Windows::Forms::Button());
			this->btnCerrarSesion = (gcnew System::Windows::Forms::Button());
			this->pnlMenu = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnMapa2D = (gcnew System::Windows::Forms::Button());
			this->btnVehiculosAsociados = (gcnew System::Windows::Forms::Button());
			this->btnSaldo = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->pnlMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlContenedor
			// 
			this->pnlContenedor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->pnlContenedor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlContenedor->Location = System::Drawing::Point(281, 64);
			this->pnlContenedor->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pnlContenedor->Name = L"pnlContenedor";
			this->pnlContenedor->Size = System::Drawing::Size(1130, 689);
			this->pnlContenedor->TabIndex = 2;
			this->pnlContenedor->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmPrincipal::pnlContenedor_Paint);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1411, 64);
			this->panel1->TabIndex = 9;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmPrincipal::panel1_Paint);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 22, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(16, 15);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1364, 43);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Sistema de Estacionamiento Inteligente Alla-Si";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &frmPrincipal::textBox1_TextChanged);
			// 
			// btnModInfo
			// 
			this->btnModInfo->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnModInfo->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnModInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnModInfo->ForeColor = System::Drawing::Color::White;
			this->btnModInfo->Location = System::Drawing::Point(0, 0);
			this->btnModInfo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnModInfo->Name = L"btnModInfo";
			this->btnModInfo->Size = System::Drawing::Size(281, 64);
			this->btnModInfo->TabIndex = 0;
			this->btnModInfo->Text = L"Informacion";
			this->btnModInfo->UseVisualStyleBackColor = false;
			this->btnModInfo->Click += gcnew System::EventHandler(this, &frmPrincipal::button1_Click);
			// 
			// btnSubscipcion
			// 
			this->btnSubscipcion->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnSubscipcion->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnSubscipcion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSubscipcion->ForeColor = System::Drawing::Color::White;
			this->btnSubscipcion->Location = System::Drawing::Point(0, 222);
			this->btnSubscipcion->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSubscipcion->Name = L"btnSubscipcion";
			this->btnSubscipcion->Size = System::Drawing::Size(281, 64);
			this->btnSubscipcion->TabIndex = 1;
			this->btnSubscipcion->Text = L"Membresia";
			this->btnSubscipcion->UseVisualStyleBackColor = false;
			this->btnSubscipcion->Click += gcnew System::EventHandler(this, &frmPrincipal::button2_Click);
			// 
			// btnConsultaTiempo
			// 
			this->btnConsultaTiempo->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnConsultaTiempo->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnConsultaTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnConsultaTiempo->ForeColor = System::Drawing::Color::White;
			this->btnConsultaTiempo->Location = System::Drawing::Point(0, 286);
			this->btnConsultaTiempo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnConsultaTiempo->Name = L"btnConsultaTiempo";
			this->btnConsultaTiempo->Size = System::Drawing::Size(281, 79);
			this->btnConsultaTiempo->TabIndex = 3;
			this->btnConsultaTiempo->Text = L"Consultar Tiempo Estadia";
			this->btnConsultaTiempo->UseVisualStyleBackColor = false;
			this->btnConsultaTiempo->Click += gcnew System::EventHandler(this, &frmPrincipal::btnConsultaTiempo_Click);
			// 
			// btnCerrarSesion
			// 
			this->btnCerrarSesion->BackColor = System::Drawing::Color::Brown;
			this->btnCerrarSesion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnCerrarSesion->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnCerrarSesion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCerrarSesion->ForeColor = System::Drawing::Color::White;
			this->btnCerrarSesion->Location = System::Drawing::Point(0, 429);
			this->btnCerrarSesion->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnCerrarSesion->Name = L"btnCerrarSesion";
			this->btnCerrarSesion->Size = System::Drawing::Size(281, 52);
			this->btnCerrarSesion->TabIndex = 6;
			this->btnCerrarSesion->Text = L"Cerrar Sesion";
			this->btnCerrarSesion->UseVisualStyleBackColor = false;
			this->btnCerrarSesion->Click += gcnew System::EventHandler(this, &frmPrincipal::btnCerrarSesion_Click);
			// 
			// pnlMenu
			// 
			this->pnlMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(85)));
			this->pnlMenu->Controls->Add(this->label1);
			this->pnlMenu->Controls->Add(this->btnCerrarSesion);
			this->pnlMenu->Controls->Add(this->btnMapa2D);
			this->pnlMenu->Controls->Add(this->btnConsultaTiempo);
			this->pnlMenu->Controls->Add(this->btnSubscipcion);
			this->pnlMenu->Controls->Add(this->btnVehiculosAsociados);
			this->pnlMenu->Controls->Add(this->btnSaldo);
			this->pnlMenu->Controls->Add(this->btnModInfo);
			this->pnlMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->pnlMenu->Location = System::Drawing::Point(0, 64);
			this->pnlMenu->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->pnlMenu->Name = L"pnlMenu";
			this->pnlMenu->Size = System::Drawing::Size(281, 689);
			this->pnlMenu->TabIndex = 1;
			this->pnlMenu->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmPrincipal::pnlMenu_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(43, 496);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 24);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Bievenido David! ";
			this->label1->Click += gcnew System::EventHandler(this, &frmPrincipal::label1_Click);
			// 
			// btnMapa2D
			// 
			this->btnMapa2D->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnMapa2D->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnMapa2D->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnMapa2D->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMapa2D->ForeColor = System::Drawing::Color::White;
			this->btnMapa2D->Location = System::Drawing::Point(0, 365);
			this->btnMapa2D->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnMapa2D->Name = L"btnMapa2D";
			this->btnMapa2D->Size = System::Drawing::Size(281, 64);
			this->btnMapa2D->TabIndex = 4;
			this->btnMapa2D->Text = L"Mapa Establecimiento";
			this->btnMapa2D->UseVisualStyleBackColor = false;
			this->btnMapa2D->Click += gcnew System::EventHandler(this, &frmPrincipal::btnMapa2D_Click);
			// 
			// btnVehiculosAsociados
			// 
			this->btnVehiculosAsociados->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnVehiculosAsociados->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnVehiculosAsociados->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnVehiculosAsociados->ForeColor = System::Drawing::Color::White;
			this->btnVehiculosAsociados->Location = System::Drawing::Point(0, 143);
			this->btnVehiculosAsociados->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnVehiculosAsociados->Name = L"btnVehiculosAsociados";
			this->btnVehiculosAsociados->Size = System::Drawing::Size(281, 79);
			this->btnVehiculosAsociados->TabIndex = 9;
			this->btnVehiculosAsociados->Text = L"Vehiculos Asociados";
			this->btnVehiculosAsociados->UseVisualStyleBackColor = false;
			this->btnVehiculosAsociados->Click += gcnew System::EventHandler(this, &frmPrincipal::btnVehiculosAsociados_Click);
			// 
			// btnSaldo
			// 
			this->btnSaldo->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnSaldo->Dock = System::Windows::Forms::DockStyle::Top;
			this->btnSaldo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaldo->ForeColor = System::Drawing::Color::White;
			this->btnSaldo->Location = System::Drawing::Point(0, 64);
			this->btnSaldo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSaldo->Name = L"btnSaldo";
			this->btnSaldo->Size = System::Drawing::Size(281, 79);
			this->btnSaldo->TabIndex = 8;
			this->btnSaldo->Text = L"Consultar Saldo";
			this->btnSaldo->UseVisualStyleBackColor = false;
			this->btnSaldo->Click += gcnew System::EventHandler(this, &frmPrincipal::btnSaldo_Click);
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1411, 753);
			this->Controls->Add(this->pnlContenedor);
			this->Controls->Add(this->pnlMenu);
			this->Controls->Add(this->panel1);
			this->IsMdiContainer = true;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"frmPrincipal";
			this->Text = L"Portal Sistema de Estacionamiento Inteligente Alla Si";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->pnlMenu->ResumeLayout(false);
			this->pnlMenu->PerformLayout();
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

	private: System::Void frmPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //btnModInfo

		this->AbrirFormulario(gcnew frmModInfo());

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //btnSuscripcion (Mebresia)
		bool EstaSuscrito = true;

		if (EstaSuscrito) {
			this->AbrirFormulario(gcnew frmSuscripcion());
		}
		else {
			this->AbrirFormulario(gcnew frmOfrecerSuscripcion);
		}

	}

private: System::Void pnlMenu_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void pnlContenedor_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void btnConsultaTiempo_Click(System::Object^ sender, System::EventArgs^ e) { //btnTiempo

	this->AbrirFormulario(gcnew frmConsultarTiempo());

}

private: System::Void btnMapa2D_Click(System::Object^ sender, System::EventArgs^ e) { //btnMapa

	this->AbrirFormulario(gcnew frmMapa());

}

private: System::Void btnCerrarSesion_Click(System::Object^ sender, System::EventArgs^ e) { //btnCerrar

	Application::Restart();

}

private: System::Void btnSaldo_Click(System::Object^ sender, System::EventArgs^ e) { //btnSaldo

	this->AbrirFormulario(gcnew frmSaldo());

}
private: System::Void btnVehiculosAsociados_Click(System::Object^ sender, System::EventArgs^ e) { //btnVehiculos

	this->AbrirFormulario(gcnew frmVehiculosAsociados());

}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
