#pragma once
#include "frmVerInfo.h"
#include "frmEditarInfo.h"

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
	/// Summary for frmBuscarCliente
	/// </summary>
	public ref class frmBuscarCliente : public System::Windows::Forms::Form
	{
	public:

		int idClienteVisualizar;

		frmBuscarCliente(int idCliente)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->txtPassword->PasswordChar = '*'; //bloqueamos la visibilidad del password
			this->idClienteVisualizar = idCliente;

			try {
				SmartParkingSystemController::ClienteController^ controller = gcnew SmartParkingSystemController::ClienteController();
				Cliente^ clienteView = controller->buscarxIdArchivo(this->idClienteVisualizar);

				if (clienteView != nullptr) {
					
					this->txtID->Text = Convert::ToString(clienteView->getIdPersona());
					this->txtNombres->Text = clienteView->getNombres();
					this->txtApellidos->Text = clienteView->getApellidos();
					this->txtDocumento->Text = clienteView->getDocumento();
					this->txtTelefono->Text = clienteView->getTelefono();
					this->txtCorreo->Text = clienteView->getCorreo();
					this->txtPassword->Text = clienteView->getClaveHash();
					this->cboEstado->Text = clienteView->getEstado() ? "Activo" : "Inactivo";

					this->dtpRegistro->Value = clienteView->getFechaRegistro();

					this->txtSaldo->Text = Convert::ToString(clienteView->getSaldo());
					this->dtpAfiliacion->Value = clienteView->getFechaAfiliacion();
					this->txtObservaciones->Text = clienteView->getObservaciones();
					this->cboSuscripcion->Text = (clienteView->getTipo() == TipoCliente::Miembro) ? "Miembro" : "Normal";

					this->chboReqPref->Checked = clienteView->getRequierePreferencial();
					if (clienteView->getRequierePreferencial()) {
						this->txtDiscapacidad->Text = clienteView->getDiscapacidad();
						this->txtDiscapacidad->Show();
						this->lblDiscapacidad->Show();
					}
					else {
						this->txtDiscapacidad->Clear();
						this->txtDiscapacidad->Hide();
						this->lblDiscapacidad->Hide();
					}

					String^ textoTarjetas = "";
					if (clienteView->getListaTarjetasRFID() != nullptr) {
						for each(auto tarjeta in clienteView->getListaTarjetasRFID()) {
							
							textoTarjetas += Convert::ToString(tarjeta->getIdTarjeta()) + "\r\n";
						}
					}
					this->txtIDTarjetas->Text = textoTarjetas;

					String^ textoVehiculos = "";
					if (clienteView->getListaVehiculos() != nullptr) {
						for each(auto vehiculo in clienteView->getListaVehiculos()) {
						
							textoVehiculos += vehiculo->getPlaca() + "\r\n";
						}
					}
					this->txtVehiculos->Text = textoVehiculos;

					String^ textoMembresia = "Ninguna";
					if (clienteView->getListasMembresias() != nullptr && clienteView->getListasMembresias()->Count > 0) {
						textoMembresia = Convert::ToString(clienteView->getListasMembresias()[0]->getTipo()); 
					}
					this->cboTipoSuscripcion->Text = textoMembresia;
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error crítico al extraer la información del archivo plano.", "Error de Sistema", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmBuscarCliente()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::PictureBox^ MoreTarjetas;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txtObservaciones;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ txtDiscapacidad;
	private: System::Windows::Forms::Label^ lblDiscapacidad;
	private: System::Windows::Forms::ComboBox^ cboSuscripcion;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ txtDocumento;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ txtSaldo;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::CheckBox^ chboReqPref;
	private: System::Windows::Forms::TextBox^ txtTelefono;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtCorreo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ dtpAfiliacion;
	private: System::Windows::Forms::TextBox^ txtID;
	private: System::Windows::Forms::TextBox^ txtNombres;
	private: System::Windows::Forms::ComboBox^ cboEstado;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtApellidos;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtIDTarjetas;
	private: System::Windows::Forms::DateTimePicker^ dtpRegistro;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ txtVehiculos;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::ComboBox^ cboTipoSuscripcion;

	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::PictureBox^ MoreVehiculos;
	private: System::Windows::Forms::PictureBox^ ViewPassword;
	private: System::Windows::Forms::PictureBox^ MoreObservaciones;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::PictureBox^ pictureBox3;
private: System::Windows::Forms::PictureBox^ pictureBox2;
private: System::Windows::Forms::PictureBox^ pictureBox4;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmBuscarCliente::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txtID = (gcnew System::Windows::Forms::TextBox());
			this->ViewPassword = (gcnew System::Windows::Forms::PictureBox());
			this->MoreObservaciones = (gcnew System::Windows::Forms::PictureBox());
			this->MoreVehiculos = (gcnew System::Windows::Forms::PictureBox());
			this->cboTipoSuscripcion = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->txtVehiculos = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->dtpRegistro = (gcnew System::Windows::Forms::DateTimePicker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtIDTarjetas = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtObservaciones = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtDiscapacidad = (gcnew System::Windows::Forms::TextBox());
			this->lblDiscapacidad = (gcnew System::Windows::Forms::Label());
			this->cboSuscripcion = (gcnew System::Windows::Forms::ComboBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtDocumento = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txtSaldo = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->chboReqPref = (gcnew System::Windows::Forms::CheckBox());
			this->txtTelefono = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtCorreo = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dtpAfiliacion = (gcnew System::Windows::Forms::DateTimePicker());
			this->txtNombres = (gcnew System::Windows::Forms::TextBox());
			this->cboEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtApellidos = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->MoreTarjetas = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewPassword))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreObservaciones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreVehiculos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreTarjetas))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->txtID);
			this->panel2->Controls->Add(this->ViewPassword);
			this->panel2->Controls->Add(this->MoreObservaciones);
			this->panel2->Controls->Add(this->MoreVehiculos);
			this->panel2->Controls->Add(this->cboTipoSuscripcion);
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->txtVehiculos);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->dtpRegistro);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->txtIDTarjetas);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->txtObservaciones);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->txtDiscapacidad);
			this->panel2->Controls->Add(this->lblDiscapacidad);
			this->panel2->Controls->Add(this->cboSuscripcion);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->txtDocumento);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->txtSaldo);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->chboReqPref);
			this->panel2->Controls->Add(this->txtTelefono);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->txtPassword);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->txtCorreo);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->dtpAfiliacion);
			this->panel2->Controls->Add(this->txtNombres);
			this->panel2->Controls->Add(this->cboEstado);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->txtApellidos);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->MoreTarjetas);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 55);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(847, 453);
			this->panel2->TabIndex = 16;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(1393, 316);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(29, 26);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 98;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(792, 422);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(29, 26);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 97;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(792, 35);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(29, 26);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 96;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(792, 90);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(29, 26);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 95;
			this->pictureBox1->TabStop = false;
			// 
			// txtID
			// 
			this->txtID->BackColor = System::Drawing::Color::Silver;
			this->txtID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtID->Location = System::Drawing::Point(442, 33);
			this->txtID->Margin = System::Windows::Forms::Padding(5);
			this->txtID->Name = L"txtID";
			this->txtID->ReadOnly = true;
			this->txtID->Size = System::Drawing::Size(343, 28);
			this->txtID->TabIndex = 64;
			// 
			// ViewPassword
			// 
			this->ViewPassword->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ViewPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ViewPassword->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ViewPassword.Image")));
			this->ViewPassword->Location = System::Drawing::Point(1522, 88);
			this->ViewPassword->Margin = System::Windows::Forms::Padding(2);
			this->ViewPassword->Name = L"ViewPassword";
			this->ViewPassword->Size = System::Drawing::Size(29, 26);
			this->ViewPassword->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ViewPassword->TabIndex = 94;
			this->ViewPassword->TabStop = false;
			this->ViewPassword->Click += gcnew System::EventHandler(this, &frmBuscarCliente::ViewPassword_Click);
			// 
			// MoreObservaciones
			// 
			this->MoreObservaciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->MoreObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MoreObservaciones->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MoreObservaciones.Image")));
			this->MoreObservaciones->Location = System::Drawing::Point(1522, 149);
			this->MoreObservaciones->Margin = System::Windows::Forms::Padding(2);
			this->MoreObservaciones->Name = L"MoreObservaciones";
			this->MoreObservaciones->Size = System::Drawing::Size(29, 26);
			this->MoreObservaciones->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->MoreObservaciones->TabIndex = 93;
			this->MoreObservaciones->TabStop = false;
			this->MoreObservaciones->Click += gcnew System::EventHandler(this, &frmBuscarCliente::MoreObservaciones_Click);
			// 
			// MoreVehiculos
			// 
			this->MoreVehiculos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->MoreVehiculos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MoreVehiculos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MoreVehiculos.Image")));
			this->MoreVehiculos->Location = System::Drawing::Point(825, 422);
			this->MoreVehiculos->Margin = System::Windows::Forms::Padding(2);
			this->MoreVehiculos->Name = L"MoreVehiculos";
			this->MoreVehiculos->Size = System::Drawing::Size(29, 26);
			this->MoreVehiculos->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->MoreVehiculos->TabIndex = 92;
			this->MoreVehiculos->TabStop = false;
			this->MoreVehiculos->Click += gcnew System::EventHandler(this, &frmBuscarCliente::MoreVehiculos_Click);
			// 
			// cboTipoSuscripcion
			// 
			this->cboTipoSuscripcion->BackColor = System::Drawing::Color::White;
			this->cboTipoSuscripcion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTipoSuscripcion->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->cboTipoSuscripcion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->cboTipoSuscripcion->FormattingEnabled = true;
			this->cboTipoSuscripcion->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Premium", L"Normal" });
			this->cboTipoSuscripcion->Location = System::Drawing::Point(1172, 258);
			this->cboTipoSuscripcion->Name = L"cboTipoSuscripcion";
			this->cboTipoSuscripcion->Size = System::Drawing::Size(215, 30);
			this->cboTipoSuscripcion->TabIndex = 91;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label16->Location = System::Drawing::Point(915, 258);
			this->label16->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(204, 22);
			this->label16->TabIndex = 90;
			this->label16->Text = L"Tipo de Suscripción:";
			// 
			// txtVehiculos
			// 
			this->txtVehiculos->BackColor = System::Drawing::Color::Silver;
			this->txtVehiculos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtVehiculos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtVehiculos->Location = System::Drawing::Point(442, 422);
			this->txtVehiculos->Margin = System::Windows::Forms::Padding(5);
			this->txtVehiculos->Name = L"txtVehiculos";
			this->txtVehiculos->ReadOnly = true;
			this->txtVehiculos->Size = System::Drawing::Size(343, 28);
			this->txtVehiculos->TabIndex = 89;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label14->Location = System::Drawing::Point(192, 424);
			this->label14->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(210, 22);
			this->label14->TabIndex = 88;
			this->label14->Text = L"Vehículos Asociados:";
			// 
			// panel5
			// 
			this->panel5->Location = System::Drawing::Point(167, 705);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(1560, 32);
			this->panel5->TabIndex = 87;
			// 
			// panel4
			// 
			this->panel4->AutoScroll = true;
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel4->Location = System::Drawing::Point(137, 22);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(10, 560);
			this->panel4->TabIndex = 56;
			// 
			// dtpRegistro
			// 
			this->dtpRegistro->CustomFormat = L"dd/MM/yyyy";
			this->dtpRegistro->Enabled = false;
			this->dtpRegistro->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->dtpRegistro->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpRegistro->Location = System::Drawing::Point(1172, 366);
			this->dtpRegistro->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->dtpRegistro->Name = L"dtpRegistro";
			this->dtpRegistro->Size = System::Drawing::Size(215, 27);
			this->dtpRegistro->TabIndex = 86;
			this->dtpRegistro->Value = System::DateTime(2026, 10, 22, 0, 0, 0, 0);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(915, 366);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(157, 22);
			this->label7->TabIndex = 85;
			this->label7->Text = L"Fecha Registro:";
			// 
			// txtIDTarjetas
			// 
			this->txtIDTarjetas->BackColor = System::Drawing::Color::Silver;
			this->txtIDTarjetas->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtIDTarjetas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtIDTarjetas->Location = System::Drawing::Point(442, 88);
			this->txtIDTarjetas->Margin = System::Windows::Forms::Padding(5);
			this->txtIDTarjetas->Name = L"txtIDTarjetas";
			this->txtIDTarjetas->ReadOnly = true;
			this->txtIDTarjetas->Size = System::Drawing::Size(343, 28);
			this->txtIDTarjetas->TabIndex = 84;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(192, 88);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 22);
			this->label2->TabIndex = 83;
			this->label2->Text = L"IDs Tarjetas:";
			// 
			// txtObservaciones
			// 
			this->txtObservaciones->BackColor = System::Drawing::Color::White;
			this->txtObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtObservaciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtObservaciones->Location = System::Drawing::Point(1172, 147);
			this->txtObservaciones->Margin = System::Windows::Forms::Padding(5);
			this->txtObservaciones->Name = L"txtObservaciones";
			this->txtObservaciones->Size = System::Drawing::Size(343, 28);
			this->txtObservaciones->TabIndex = 82;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label15->Location = System::Drawing::Point(915, 147);
			this->label15->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(158, 22);
			this->label15->TabIndex = 81;
			this->label15->Text = L"Observaciones:";
			// 
			// txtDiscapacidad
			// 
			this->txtDiscapacidad->BackColor = System::Drawing::Color::White;
			this->txtDiscapacidad->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtDiscapacidad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtDiscapacidad->Location = System::Drawing::Point(1172, 487);
			this->txtDiscapacidad->Margin = System::Windows::Forms::Padding(5);
			this->txtDiscapacidad->Name = L"txtDiscapacidad";
			this->txtDiscapacidad->Size = System::Drawing::Size(343, 28);
			this->txtDiscapacidad->TabIndex = 80;
			// 
			// lblDiscapacidad
			// 
			this->lblDiscapacidad->AutoSize = true;
			this->lblDiscapacidad->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->lblDiscapacidad->Location = System::Drawing::Point(915, 489);
			this->lblDiscapacidad->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lblDiscapacidad->Name = L"lblDiscapacidad";
			this->lblDiscapacidad->Size = System::Drawing::Size(143, 22);
			this->lblDiscapacidad->TabIndex = 79;
			this->lblDiscapacidad->Text = L"Discapacidad:";
			// 
			// cboSuscripcion
			// 
			this->cboSuscripcion->BackColor = System::Drawing::Color::White;
			this->cboSuscripcion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboSuscripcion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->cboSuscripcion->FormattingEnabled = true;
			this->cboSuscripcion->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Normal", L"Miembro" });
			this->cboSuscripcion->Location = System::Drawing::Point(1172, 200);
			this->cboSuscripcion->Name = L"cboSuscripcion";
			this->cboSuscripcion->Size = System::Drawing::Size(215, 30);
			this->cboSuscripcion->TabIndex = 78;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label13->Location = System::Drawing::Point(915, 200);
			this->label13->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(129, 22);
			this->label13->TabIndex = 77;
			this->label13->Text = L"Suscripción:";
			// 
			// txtDocumento
			// 
			this->txtDocumento->BackColor = System::Drawing::Color::White;
			this->txtDocumento->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtDocumento->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtDocumento->Location = System::Drawing::Point(442, 252);
			this->txtDocumento->Margin = System::Windows::Forms::Padding(5);
			this->txtDocumento->Name = L"txtDocumento";
			this->txtDocumento->Size = System::Drawing::Size(343, 28);
			this->txtDocumento->TabIndex = 76;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(192, 252);
			this->label12->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(124, 22);
			this->label12->TabIndex = 75;
			this->label12->Text = L"Documento:";
			// 
			// txtSaldo
			// 
			this->txtSaldo->BackColor = System::Drawing::Color::White;
			this->txtSaldo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtSaldo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtSaldo->Location = System::Drawing::Point(442, 369);
			this->txtSaldo->Margin = System::Windows::Forms::Padding(5);
			this->txtSaldo->Name = L"txtSaldo";
			this->txtSaldo->Size = System::Drawing::Size(343, 28);
			this->txtSaldo->TabIndex = 74;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label11->Location = System::Drawing::Point(192, 369);
			this->label11->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(70, 22);
			this->label11->TabIndex = 73;
			this->label11->Text = L"Saldo:";
			// 
			// chboReqPref
			// 
			this->chboReqPref->AutoSize = true;
			this->chboReqPref->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->chboReqPref->Location = System::Drawing::Point(196, 489);
			this->chboReqPref->Name = L"chboReqPref";
			this->chboReqPref->Size = System::Drawing::Size(229, 26);
			this->chboReqPref->TabIndex = 72;
			this->chboReqPref->Text = L"Requiere Preferencial";
			this->chboReqPref->UseVisualStyleBackColor = true;
			this->chboReqPref->CheckStateChanged += gcnew System::EventHandler(this, &frmBuscarCliente::chboReqPref_CheckedChanged);
			// 
			// txtTelefono
			// 
			this->txtTelefono->BackColor = System::Drawing::Color::White;
			this->txtTelefono->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtTelefono->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtTelefono->Location = System::Drawing::Point(442, 312);
			this->txtTelefono->Margin = System::Windows::Forms::Padding(5);
			this->txtTelefono->Name = L"txtTelefono";
			this->txtTelefono->Size = System::Drawing::Size(343, 28);
			this->txtTelefono->TabIndex = 71;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label10->Location = System::Drawing::Point(192, 312);
			this->label10->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(98, 22);
			this->label10->TabIndex = 70;
			this->label10->Text = L"Teléfono:";
			// 
			// txtPassword
			// 
			this->txtPassword->BackColor = System::Drawing::Color::White;
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtPassword->Location = System::Drawing::Point(1172, 88);
			this->txtPassword->Margin = System::Windows::Forms::Padding(5);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(343, 28);
			this->txtPassword->TabIndex = 69;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label9->Location = System::Drawing::Point(915, 88);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(125, 22);
			this->label9->TabIndex = 68;
			this->label9->Text = L"Contraseña:";
			// 
			// txtCorreo
			// 
			this->txtCorreo->BackColor = System::Drawing::Color::White;
			this->txtCorreo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtCorreo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtCorreo->Location = System::Drawing::Point(1172, 35);
			this->txtCorreo->Margin = System::Windows::Forms::Padding(5);
			this->txtCorreo->Name = L"txtCorreo";
			this->txtCorreo->Size = System::Drawing::Size(343, 28);
			this->txtCorreo->TabIndex = 67;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(915, 35);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 22);
			this->label1->TabIndex = 66;
			this->label1->Text = L"Correo:";
			// 
			// dtpAfiliacion
			// 
			this->dtpAfiliacion->CustomFormat = L"dd/MM/yyyy";
			this->dtpAfiliacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F));
			this->dtpAfiliacion->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dtpAfiliacion->Location = System::Drawing::Point(1172, 315);
			this->dtpAfiliacion->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->dtpAfiliacion->Name = L"dtpAfiliacion";
			this->dtpAfiliacion->Size = System::Drawing::Size(215, 27);
			this->dtpAfiliacion->TabIndex = 65;
			this->dtpAfiliacion->Value = System::DateTime(2026, 10, 22, 0, 0, 0, 0);
			// 
			// txtNombres
			// 
			this->txtNombres->BackColor = System::Drawing::Color::White;
			this->txtNombres->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtNombres->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtNombres->Location = System::Drawing::Point(442, 147);
			this->txtNombres->Margin = System::Windows::Forms::Padding(5);
			this->txtNombres->Name = L"txtNombres";
			this->txtNombres->Size = System::Drawing::Size(343, 28);
			this->txtNombres->TabIndex = 63;
			// 
			// cboEstado
			// 
			this->cboEstado->BackColor = System::Drawing::Color::White;
			this->cboEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboEstado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->cboEstado->FormattingEnabled = true;
			this->cboEstado->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Activo", L"Inactivo" });
			this->cboEstado->Location = System::Drawing::Point(1172, 424);
			this->cboEstado->Name = L"cboEstado";
			this->cboEstado->Size = System::Drawing::Size(215, 30);
			this->cboEstado->TabIndex = 62;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label8->Location = System::Drawing::Point(915, 424);
			this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(82, 22);
			this->label8->TabIndex = 61;
			this->label8->Text = L"Estado:";
			// 
			// txtApellidos
			// 
			this->txtApellidos->BackColor = System::Drawing::Color::White;
			this->txtApellidos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtApellidos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtApellidos->Location = System::Drawing::Point(442, 200);
			this->txtApellidos->Margin = System::Windows::Forms::Padding(5);
			this->txtApellidos->Name = L"txtApellidos";
			this->txtApellidos->Size = System::Drawing::Size(343, 28);
			this->txtApellidos->TabIndex = 57;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(915, 315);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(163, 22);
			this->label6->TabIndex = 60;
			this->label6->Text = L"Fecha Afiliación:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(192, 149);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 22);
			this->label5->TabIndex = 59;
			this->label5->Text = L"Nombres:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(192, 200);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 22);
			this->label4->TabIndex = 58;
			this->label4->Text = L"Apellidos:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(192, 35);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 22);
			this->label3->TabIndex = 56;
			this->label3->Text = L"ID Cliente:";
			// 
			// MoreTarjetas
			// 
			this->MoreTarjetas->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->MoreTarjetas->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MoreTarjetas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MoreTarjetas.Image")));
			this->MoreTarjetas->Location = System::Drawing::Point(825, 90);
			this->MoreTarjetas->Margin = System::Windows::Forms::Padding(2);
			this->MoreTarjetas->Name = L"MoreTarjetas";
			this->MoreTarjetas->Size = System::Drawing::Size(29, 26);
			this->MoreTarjetas->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->MoreTarjetas->TabIndex = 46;
			this->MoreTarjetas->TabStop = false;
			this->MoreTarjetas->Click += gcnew System::EventHandler(this, &frmBuscarCliente::pictureBox1_Click);
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
			this->panel1->TabIndex = 15;
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(25, 8);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(279, 31);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Buscar Cliente";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(440, 13);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 31);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmBuscarCliente::button1_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->btnGuardarEdit);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 508);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(847, 52);
			this->panel3->TabIndex = 17;
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(210, 13);
			this->btnGuardarEdit->Margin = System::Windows::Forms::Padding(2);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(178, 31);
			this->btnGuardarEdit->TabIndex = 92;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmBuscarCliente::btnGuardarEdit_Click);
			// 
			// frmBuscarCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 560);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"frmBuscarCliente";
			this->Text = L"frmBuscarCliente";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewPassword))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreObservaciones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreVehiculos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreTarjetas))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
//Para regresar con eventos------------------------------------------------------------------------------------
public: 

	event System::EventHandler^ OnRegresar;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	OnRegresar(this, e);
}

//--------------------------------------------------------------------------------------------------------------


private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) { //More Ids tarjetas

	frmVerInfo^ ventanaEdicion = gcnew frmVerInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}

private: System::Void pictureBox9_Click(System::Object^ sender, System::EventArgs^ e) { //More Vehiculos

	frmEditarInfo^ ventanaEdicion = gcnew frmEditarInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}

private: System::Void btnGuardarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Guardar
	if (String::IsNullOrWhiteSpace(this->txtNombres->Text) || String::IsNullOrWhiteSpace(this->txtApellidos->Text) || String::IsNullOrWhiteSpace(this->txtDocumento->Text) || String::IsNullOrWhiteSpace(this->txtTelefono->Text) || String::IsNullOrWhiteSpace(this->txtCorreo->Text) || String::IsNullOrWhiteSpace(this->txtPassword->Text)) {

		MessageBox::Show("Por favor, complete todos los campos obligatorios del perfil.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	try {
		SmartParkingSystemController::ClienteController^ controller = gcnew SmartParkingSystemController::ClienteController();

		Cliente^ clienteMod = controller->buscarxIdArchivo(this->idClienteVisualizar);

		if (clienteMod != nullptr) {

			clienteMod->setNombres(this->txtNombres->Text->Trim());
			clienteMod->setApellidos(this->txtApellidos->Text->Trim());
			clienteMod->setDocumento(this->txtDocumento->Text->Trim());
			clienteMod->setTelefono(this->txtTelefono->Text->Trim());
			clienteMod->setCorreo(this->txtCorreo->Text->Trim());
			clienteMod->setClaveHash(this->txtPassword->Text->Trim());
			clienteMod->setObservaciones(this->txtObservaciones->Text->Trim());

			double nuevoSaldo = 0.0;
			try {
				nuevoSaldo = Convert::ToDouble(this->txtSaldo->Text->Trim());
			}
			catch (Exception^) {
				MessageBox::Show("El formato del saldo es incorrecto. Use solo números.", "Error de Formato", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			clienteMod->setSaldo(nuevoSaldo);

			clienteMod->setEstado(this->cboEstado->Text == "Activo");
			clienteMod->setTipo((this->cboSuscripcion->Text == "Miembro") ? TipoCliente::Miembro : TipoCliente::Normal);

			bool requierePref = this->chboReqPref->Checked;
			clienteMod->setRequierePreferencial(requierePref);
			clienteMod->setDiscapacidad(requierePref ? this->txtDiscapacidad->Text->Trim() : String::Empty);
			clienteMod->setFechaAfiliacion(this->dtpAfiliacion->Value);

			controller->modificarArchivo(this->idClienteVisualizar, clienteMod);

			MessageBox::Show("Perfil de cliente actualizado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close(); // Cierra el modal y devuelve el foco al Dashboard
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ocurrió un error crítico al intentar guardar los cambios en el archivo.", "Error de E/S", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void ViewPassword_Click(System::Object^ sender, System::EventArgs^ e) { //Ojito Password

	if (this->txtPassword->PasswordChar == '*') {
		
		this->txtPassword->PasswordChar = '\0'; // desactivamos la mascara de seguridad 
	}
	else {
		
		this->txtPassword->PasswordChar = '*'; // Restauramos la mascara de seguridad
	}

}
private: System::Void MoreObservaciones_Click(System::Object^ sender, System::EventArgs^ e) { //More Observaciones

	frmVerInfo^ ventanaEdicion = gcnew frmVerInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}

private: System::Void chboReqPref_CheckedChanged(System::Object^ sender, System::EventArgs^ e) { //Behaviour de la checkbox
	if (this->chboReqPref->Checked) {
		this->lblDiscapacidad->Show();
		this->txtDiscapacidad->Show();
		this->txtDiscapacidad->Enabled = true;
		this->txtDiscapacidad->Focus();
	}
	else {
		// Bloquea y limpia el texto para evitar guardar "fantasmas"
		this->lblDiscapacidad->Hide();
		this->txtDiscapacidad->Hide();
		this->txtDiscapacidad->Enabled = false;
		this->txtDiscapacidad->Clear();
	}
}


private: System::Void MoreVehiculos_Click(System::Object^ sender, System::EventArgs^ e) { //More vehiculos

	frmVerInfo^ ventanaEdicion = gcnew frmVerInfo(); //Abrimos una ventana
	ventanaEdicion->ShowDialog();

}

//---------------------------------------------------------------------------
};
}
