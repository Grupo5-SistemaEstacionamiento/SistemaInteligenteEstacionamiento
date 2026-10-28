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
	/// Summary for frmBuscarPlaca
	/// </summary>
	public ref class frmBuscarPlaca : public System::Windows::Forms::Form
	{
	public:
		int idVehiculoVisualizar;
		int idDuenoSelect; // lo lee el dashboard al abrir la ficha del dueño

		frmBuscarPlaca(int idVehiculo)
		{
			InitializeComponent();
			this->idVehiculoVisualizar = idVehiculo;
			this->idDuenoSelect = 0;
			this->clienteDueno = nullptr;

			try {
				VehiculoController^ controller = gcnew VehiculoController();
				Vehiculo^ v = controller->buscarxIdArchivo(idVehiculo);

				if (v == nullptr) {
					MessageBox::Show("No se encontró el vehículo seleccionado.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					this->btnGuardarEdit->Enabled = false;
					return;
				}

				this->txtIDVehiculo->Text = v->getIdVehiculo().ToString();
				this->txtPlaca->Text = v->getPlaca();
				this->txtMarca->Text = v->getMarca();
				this->txtModelo->Text = v->getModelo();
				this->txtAnotaciones->Text = v->getAnotaciones();
				this->cboTipo->SelectedIndex = (v->getTipo() == TipoVehiculo::automovil) ? 0 : 1;

				// Si el color guardado no está en la lista, queda sin seleccionar (-1)
				this->cboColor->SelectedIndex = this->cboColor->FindStringExact(v->getColor()->Trim());
				if (this->cboColor->SelectedIndex < 0) {
					MessageBox::Show("El color registrado (" + v->getColor() + ") no está en la lista. Elija uno nuevo antes de guardar.", "Color no reconocido", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}

				if (v->getCliente() != nullptr) {
					// Dispara TextChanged: rellena txtOwner y clienteDueno
					this->txtIDOwner->Text = v->getCliente()->getIdPersona().ToString();
				}
				else {
					mostrarEstadoDueno("Sin dueño asignado", Color::LightCoral);
				}

				mostrarSinDatosOperativos();
				// actualizarImagenVehiculo(); // pendiente, ver bloque comentado abajo
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al cargar los datos del vehículo: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmBuscarPlaca()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Cliente^ clienteDueno;

	private: System::Windows::Forms::TextBox^ textInfoCliente;
	protected:
	private: System::Windows::Forms::Panel^ panel1;

	



	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txtPlaca;












	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::PictureBox^ moreAnotaciones;

	private: System::Windows::Forms::TextBox^ txtIDVehiculo;




	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::PictureBox^ morePenalizaciones;


	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;


	private: System::Windows::Forms::TextBox^ txtModelo;

	private: System::Windows::Forms::TextBox^ txtMarca;
	private: System::Windows::Forms::ComboBox^ cboTipo;
	private: System::Windows::Forms::TextBox^ txtPenalizaciones;



	private: System::Windows::Forms::TextBox^ txtTiempoEstadia;

	private: System::Windows::Forms::TextBox^ txtOwner;

	private: System::Windows::Forms::TextBox^ txtIDOwner;
	private: System::Windows::Forms::TextBox^ txtAnotaciones;


	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ MoreOwner;

	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::TextBox^ txtEspacioOcupado;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ txtHoraIngreso;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ txtMontonAcumulado;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ lblEstado;
private: System::Windows::Forms::Panel^ pnlEstadoColor;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::ComboBox^ cboColor;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmBuscarPlaca::typeid));
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->cboColor = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pnlEstadoColor = (gcnew System::Windows::Forms::Panel());
			this->lblEstado = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtMontonAcumulado = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtEspacioOcupado = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtHoraIngreso = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->MoreOwner = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->txtAnotaciones = (gcnew System::Windows::Forms::TextBox());
			this->txtPenalizaciones = (gcnew System::Windows::Forms::TextBox());
			this->txtTiempoEstadia = (gcnew System::Windows::Forms::TextBox());
			this->txtOwner = (gcnew System::Windows::Forms::TextBox());
			this->txtIDOwner = (gcnew System::Windows::Forms::TextBox());
			this->cboTipo = (gcnew System::Windows::Forms::ComboBox());
			this->txtModelo = (gcnew System::Windows::Forms::TextBox());
			this->txtMarca = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->morePenalizaciones = (gcnew System::Windows::Forms::PictureBox());
			this->txtPlaca = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->moreAnotaciones = (gcnew System::Windows::Forms::PictureBox());
			this->txtIDVehiculo = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreOwner))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->morePenalizaciones))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moreAnotaciones))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// textInfoCliente
			// 
			this->textInfoCliente->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->textInfoCliente->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textInfoCliente->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textInfoCliente->ForeColor = System::Drawing::Color::White;
			this->textInfoCliente->Location = System::Drawing::Point(37, 12);
			this->textInfoCliente->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textInfoCliente->Name = L"textInfoCliente";
			this->textInfoCliente->Size = System::Drawing::Size(418, 46);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Buscar Placa";
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
			this->panel1->Size = System::Drawing::Size(1270, 85);
			this->panel1->TabIndex = 18;
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->cboColor);
			this->panel2->Controls->Add(this->pictureBox8);
			this->panel2->Controls->Add(this->pictureBox7);
			this->panel2->Controls->Add(this->pictureBox6);
			this->panel2->Controls->Add(this->pictureBox4);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->txtMontonAcumulado);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->txtEspacioOcupado);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->txtHoraIngreso);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->MoreOwner);
			this->panel2->Controls->Add(this->pictureBox5);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->txtAnotaciones);
			this->panel2->Controls->Add(this->txtPenalizaciones);
			this->panel2->Controls->Add(this->txtTiempoEstadia);
			this->panel2->Controls->Add(this->txtOwner);
			this->panel2->Controls->Add(this->txtIDOwner);
			this->panel2->Controls->Add(this->cboTipo);
			this->panel2->Controls->Add(this->txtModelo);
			this->panel2->Controls->Add(this->txtMarca);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->morePenalizaciones);
			this->panel2->Controls->Add(this->txtPlaca);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->moreAnotaciones);
			this->panel2->Controls->Add(this->txtIDVehiculo);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 85);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1270, 677);
			this->panel2->TabIndex = 19;
			// 
			// cboColor
			// 
			this->cboColor->BackColor = System::Drawing::Color::White;
			this->cboColor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboColor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->cboColor->FormattingEnabled = true;
			this->cboColor->Items->AddRange(gcnew cli::array< System::Object^  >(14) {
				L"Blanco", L"Negro", L"Rojo", L"Azul", L"Amarillo",
					L"Verde", L"Naranja", L"Morado", L"Celeste", L"Turquesa", L"Marron", L"Gris", L"Beige", L"Plata"
			});
			this->cboColor->Location = System::Drawing::Point(477, 356);
			this->cboColor->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboColor->Name = L"cboColor";
			this->cboColor->Size = System::Drawing::Size(320, 40);
			this->cboColor->TabIndex = 115;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(970, 913);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(42, 39);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 114;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(970, 547);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(42, 39);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 113;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(970, 823);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(42, 39);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 112;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(970, 733);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(42, 39);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 111;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(970, 642);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(42, 39);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 110;
			this->pictureBox1->TabStop = false;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel6->Controls->Add(this->pnlEstadoColor);
			this->panel6->Controls->Add(this->lblEstado);
			this->panel6->Controls->Add(this->label15);
			this->panel6->Location = System::Drawing::Point(1183, 675);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(674, 63);
			this->panel6->TabIndex = 109;
			// 
			// pnlEstadoColor
			// 
			this->pnlEstadoColor->BackColor = System::Drawing::Color::Silver;
			this->pnlEstadoColor->Location = System::Drawing::Point(606, 0);
			this->pnlEstadoColor->Name = L"pnlEstadoColor";
			this->pnlEstadoColor->Size = System::Drawing::Size(68, 63);
			this->pnlEstadoColor->TabIndex = 112;
			// 
			// lblEstado
			// 
			this->lblEstado->AutoSize = true;
			this->lblEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lblEstado->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEstado->Location = System::Drawing::Point(161, 17);
			this->lblEstado->Name = L"lblEstado";
			this->lblEstado->Size = System::Drawing::Size(422, 33);
			this->lblEstado->TabIndex = 111;
			this->lblEstado->Text = L"Error al Conseguir el Estado :(";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label15->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(33, 17);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(118, 33);
			this->label15->TabIndex = 110;
			this->label15->Text = L"Estado:";
			// 
			// txtMontonAcumulado
			// 
			this->txtMontonAcumulado->BackColor = System::Drawing::Color::Silver;
			this->txtMontonAcumulado->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtMontonAcumulado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtMontonAcumulado->Location = System::Drawing::Point(477, 823);
			this->txtMontonAcumulado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtMontonAcumulado->Name = L"txtMontonAcumulado";
			this->txtMontonAcumulado->ReadOnly = true;
			this->txtMontonAcumulado->Size = System::Drawing::Size(487, 39);
			this->txtMontonAcumulado->TabIndex = 108;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::White;
			this->label14->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(129, 823);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(270, 33);
			this->label14->TabIndex = 107;
			this->label14->Text = L"Monto Acumulado:";
			// 
			// txtEspacioOcupado
			// 
			this->txtEspacioOcupado->BackColor = System::Drawing::Color::Silver;
			this->txtEspacioOcupado->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtEspacioOcupado->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtEspacioOcupado->Location = System::Drawing::Point(477, 733);
			this->txtEspacioOcupado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEspacioOcupado->Name = L"txtEspacioOcupado";
			this->txtEspacioOcupado->ReadOnly = true;
			this->txtEspacioOcupado->Size = System::Drawing::Size(487, 39);
			this->txtEspacioOcupado->TabIndex = 106;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::White;
			this->label13->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(129, 735);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(258, 33);
			this->label13->TabIndex = 105;
			this->label13->Text = L"Espacio ocupado:";
			// 
			// txtHoraIngreso
			// 
			this->txtHoraIngreso->BackColor = System::Drawing::Color::Silver;
			this->txtHoraIngreso->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtHoraIngreso->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtHoraIngreso->Location = System::Drawing::Point(477, 640);
			this->txtHoraIngreso->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtHoraIngreso->Name = L"txtHoraIngreso";
			this->txtHoraIngreso->ReadOnly = true;
			this->txtHoraIngreso->Size = System::Drawing::Size(487, 39);
			this->txtHoraIngreso->TabIndex = 104;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::White;
			this->label12->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(129, 642);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(239, 33);
			this->label12->TabIndex = 103;
			this->label12->Text = L"Hora de Ingreso:";
			// 
			// MoreOwner
			// 
			this->MoreOwner->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->MoreOwner->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MoreOwner->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MoreOwner.Image")));
			this->MoreOwner->Location = System::Drawing::Point(1891, 892);
			this->MoreOwner->Name = L"MoreOwner";
			this->MoreOwner->Size = System::Drawing::Size(42, 39);
			this->MoreOwner->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->MoreOwner->TabIndex = 47;
			this->MoreOwner->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(1183, 29);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(674, 678);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 102;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(1843, 892);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(42, 39);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 101;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(970, 31);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(42, 39);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 100;
			this->pictureBox2->TabStop = false;
			// 
			// txtAnotaciones
			// 
			this->txtAnotaciones->BackColor = System::Drawing::Color::White;
			this->txtAnotaciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtAnotaciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtAnotaciones->Location = System::Drawing::Point(477, 1003);
			this->txtAnotaciones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtAnotaciones->Name = L"txtAnotaciones";
			this->txtAnotaciones->Size = System::Drawing::Size(487, 39);
			this->txtAnotaciones->TabIndex = 99;
			// 
			// txtPenalizaciones
			// 
			this->txtPenalizaciones->BackColor = System::Drawing::Color::Silver;
			this->txtPenalizaciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPenalizaciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtPenalizaciones->Location = System::Drawing::Point(477, 913);
			this->txtPenalizaciones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtPenalizaciones->Name = L"txtPenalizaciones";
			this->txtPenalizaciones->Size = System::Drawing::Size(487, 39);
			this->txtPenalizaciones->TabIndex = 98;
			// 
			// txtTiempoEstadia
			// 
			this->txtTiempoEstadia->BackColor = System::Drawing::Color::Silver;
			this->txtTiempoEstadia->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtTiempoEstadia->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtTiempoEstadia->Location = System::Drawing::Point(477, 545);
			this->txtTiempoEstadia->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtTiempoEstadia->Name = L"txtTiempoEstadia";
			this->txtTiempoEstadia->ReadOnly = true;
			this->txtTiempoEstadia->Size = System::Drawing::Size(487, 39);
			this->txtTiempoEstadia->TabIndex = 97;
			// 
			// txtOwner
			// 
			this->txtOwner->BackColor = System::Drawing::Color::Silver;
			this->txtOwner->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtOwner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtOwner->Location = System::Drawing::Point(1350, 892);
			this->txtOwner->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtOwner->Name = L"txtOwner";
			this->txtOwner->ReadOnly = true;
			this->txtOwner->Size = System::Drawing::Size(487, 39);
			this->txtOwner->TabIndex = 96;
			// 
			// txtIDOwner
			// 
			this->txtIDOwner->BackColor = System::Drawing::Color::White;
			this->txtIDOwner->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtIDOwner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtIDOwner->Location = System::Drawing::Point(1350, 803);
			this->txtIDOwner->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtIDOwner->Name = L"txtIDOwner";
			this->txtIDOwner->Size = System::Drawing::Size(487, 39);
			this->txtIDOwner->TabIndex = 95;
			this->txtIDOwner->TextChanged += gcnew System::EventHandler(this, &frmBuscarPlaca::txtIDOwner_TextChanged);
			// 
			// cboTipo
			// 
			this->cboTipo->BackColor = System::Drawing::Color::White;
			this->cboTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTipo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->cboTipo->FormattingEnabled = true;
			this->cboTipo->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Automovil", L"Motocicleta" });
			this->cboTipo->Location = System::Drawing::Point(477, 451);
			this->cboTipo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboTipo->Name = L"cboTipo";
			this->cboTipo->Size = System::Drawing::Size(320, 40);
			this->cboTipo->TabIndex = 94;
			// 
			// txtModelo
			// 
			this->txtModelo->BackColor = System::Drawing::Color::White;
			this->txtModelo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtModelo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtModelo->Location = System::Drawing::Point(477, 269);
			this->txtModelo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtModelo->Name = L"txtModelo";
			this->txtModelo->Size = System::Drawing::Size(487, 39);
			this->txtModelo->TabIndex = 92;
			// 
			// txtMarca
			// 
			this->txtMarca->BackColor = System::Drawing::Color::White;
			this->txtMarca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtMarca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtMarca->Location = System::Drawing::Point(477, 187);
			this->txtMarca->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtMarca->Name = L"txtMarca";
			this->txtMarca->Size = System::Drawing::Size(487, 39);
			this->txtMarca->TabIndex = 91;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::White;
			this->label11->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(1116, 803);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(148, 33);
			this->label11->TabIndex = 90;
			this->label11->Text = L"ID Dueño:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::White;
			this->label10->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(129, 31);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(177, 33);
			this->label10->TabIndex = 89;
			this->label10->Text = L"ID Vehículo:";
			// 
			// panel5
			// 
			this->panel5->Location = System::Drawing::Point(4, 1122);
			this->panel5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(2049, 52);
			this->panel5->TabIndex = 88;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(1116, 892);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(112, 33);
			this->label9->TabIndex = 36;
			this->label9->Text = L"Dueño:";
			// 
			// morePenalizaciones
			// 
			this->morePenalizaciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->morePenalizaciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->morePenalizaciones->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"morePenalizaciones.Image")));
			this->morePenalizaciones->Location = System::Drawing::Point(1018, 913);
			this->morePenalizaciones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->morePenalizaciones->Name = L"morePenalizaciones";
			this->morePenalizaciones->Size = System::Drawing::Size(42, 40);
			this->morePenalizaciones->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->morePenalizaciones->TabIndex = 72;
			this->morePenalizaciones->TabStop = false;
			// 
			// txtPlaca
			// 
			this->txtPlaca->BackColor = System::Drawing::Color::White;
			this->txtPlaca->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPlaca->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtPlaca->Location = System::Drawing::Point(477, 104);
			this->txtPlaca->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtPlaca->Name = L"txtPlaca";
			this->txtPlaca->Size = System::Drawing::Size(487, 39);
			this->txtPlaca->TabIndex = 56;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel4->Location = System::Drawing::Point(51, 31);
			this->panel4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(15, 1030);
			this->panel4->TabIndex = 55;
			// 
			// moreAnotaciones
			// 
			this->moreAnotaciones->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->moreAnotaciones->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->moreAnotaciones->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"moreAnotaciones.Image")));
			this->moreAnotaciones->Location = System::Drawing::Point(970, 1002);
			this->moreAnotaciones->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->moreAnotaciones->Name = L"moreAnotaciones";
			this->moreAnotaciones->Size = System::Drawing::Size(42, 40);
			this->moreAnotaciones->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->moreAnotaciones->TabIndex = 54;
			this->moreAnotaciones->TabStop = false;
			// 
			// txtIDVehiculo
			// 
			this->txtIDVehiculo->BackColor = System::Drawing::Color::Silver;
			this->txtIDVehiculo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtIDVehiculo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F));
			this->txtIDVehiculo->Location = System::Drawing::Point(477, 29);
			this->txtIDVehiculo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtIDVehiculo->Name = L"txtIDVehiculo";
			this->txtIDVehiculo->ReadOnly = true;
			this->txtIDVehiculo->Size = System::Drawing::Size(487, 39);
			this->txtIDVehiculo->TabIndex = 37;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::White;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(129, 1009);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(192, 33);
			this->label8->TabIndex = 35;
			this->label8->Text = L"Anotaciones:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(129, 919);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(227, 33);
			this->label7->TabIndex = 34;
			this->label7->Text = L"Penalizaciones:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(129, 547);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(234, 33);
			this->label6->TabIndex = 33;
			this->label6->Text = L"Tiempo Estadia:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(129, 269);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 33);
			this->label5->TabIndex = 32;
			this->label5->Text = L"Modelo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(129, 356);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(98, 33);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Color:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(129, 187);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(109, 33);
			this->label3->TabIndex = 30;
			this->label3->Text = L"Marca:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::White;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(129, 451);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(248, 33);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Tipo (Auto/Moto):";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(129, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 33);
			this->label1->TabIndex = 28;
			this->label1->Text = L"Placa:";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->btnGuardarEdit);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 762);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1270, 99);
			this->panel3->TabIndex = 20;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::Color::Teal;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(504, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(267, 48);
			this->button2->TabIndex = 94;
			this->button2->Text = L"Ver Historial";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &frmBuscarPlaca::button2_Click);
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(188, 29);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(267, 48);
			this->btnGuardarEdit->TabIndex = 93;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmBuscarPlaca::btnGuardarEdit_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(818, 29);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(249, 48);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmBuscarPlaca::button1_Click);
			// 
			// frmBuscarPlaca
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 861);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmBuscarPlaca";
			this->Text = L"frmBuscarPlaca";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MoreOwner))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->morePenalizaciones))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moreAnotaciones))->EndInit();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

public:
	event System::EventHandler^ OnRegresar;
	event System::EventHandler^ OnVerDueno;

//----------------------------------------------------------------------------------------------

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
	OnRegresar(this, e);
}

private: String^ limpiar(String^ s) { // evita que un ';' o salto de línea rompa el .txt
	if (s == nullptr) return String::Empty;
	return s->Replace(";", ",")->Replace("\r", " ")->Replace("\n", " ")->Trim();
}

private: void mostrarEstadoDueno(String^ texto, Color fondo) {
	this->txtOwner->Text = texto;
	this->txtOwner->BackColor = fondo;
}

	   // FASE 2: aquí se llenará con RegistroAcceso (estado, estadía, ingreso, espacio, monto) y Penalizacion.
private: void mostrarSinDatosOperativos() {
	this->lblEstado->Text = "Sin datos";
	this->pnlEstadoColor->BackColor = Color::Silver;
	this->txtTiempoEstadia->Text = "-";
	this->txtHoraIngreso->Text = "-";
	this->txtEspacioOcupado->Text = "-";
	this->txtMontonAcumulado->Text = "-";
	this->txtPenalizaciones->Text = "-";
}

private: System::Void txtIDOwner_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	this->clienteDueno = nullptr;
	String^ txt = this->txtIDOwner->Text->Trim();

	if (txt->Length == 0) { mostrarEstadoDueno("", Color::Silver); return; }

	int id;
	if (!Int32::TryParse(txt, id)) { mostrarEstadoDueno("ID inválido (solo números)", Color::LightCoral); return; }

	Cliente^ c = (gcnew ClienteController())->buscarxIdArchivo(id);
	if (c == nullptr) { mostrarEstadoDueno("Cliente inexistente", Color::LightCoral); return; }

	this->clienteDueno = c;
	mostrarEstadoDueno(c->getNombres() + " " + c->getApellidos(), Color::LightGreen);
}

private: System::Void MoreOwner_Click(System::Object^ sender, System::EventArgs^ e) { //Abre la ficha del dueño
	if (this->clienteDueno == nullptr) {
		MessageBox::Show("Ingrese un ID de dueño válido para ver su ficha.", "Dueño no válido", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	this->idDuenoSelect = this->clienteDueno->getIdPersona();
	OnVerDueno(this, e);
}

private: System::Void btnGuardarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Guardar
	if (String::IsNullOrWhiteSpace(this->txtPlaca->Text) || String::IsNullOrWhiteSpace(this->txtMarca->Text) ||
		String::IsNullOrWhiteSpace(this->txtModelo->Text) || String::IsNullOrWhiteSpace(this->txtIDOwner->Text) ||
		this->cboColor->SelectedIndex < 0 || this->cboTipo->SelectedIndex < 0) {
		MessageBox::Show("Por favor, complete todos los campos obligatorios.", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (this->clienteDueno == nullptr) {
		MessageBox::Show("El ID del dueño no corresponde a ningún cliente registrado.", "Cliente inexistente", MessageBoxButtons::OK, MessageBoxIcon::Error);
		this->txtIDOwner->Focus();
		return;
	}

	try {
		VehiculoController^ controller = gcnew VehiculoController();
		Vehiculo^ v = controller->buscarxIdArchivo(this->idVehiculoVisualizar);
		if (v == nullptr) {
			MessageBox::Show("El vehículo ya no existe en el sistema.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ placa = limpiar(this->txtPlaca->Text)->ToUpper();
		Vehiculo^ otro = controller->buscarxPlacaArchivo(placa);
		if (otro != nullptr && otro->getIdVehiculo() != this->idVehiculoVisualizar) {
			MessageBox::Show("Ya existe otro vehículo registrado con esta placa.", "Error de Duplicidad", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		v->setPlaca(placa);
		v->setMarca(limpiar(this->txtMarca->Text));
		v->setModelo(limpiar(this->txtModelo->Text));
		v->setColor(this->cboColor->Text);
		v->setAnotaciones(limpiar(this->txtAnotaciones->Text));
		v->setTipo((this->cboTipo->SelectedIndex == 0) ? TipoVehiculo::automovil : TipoVehiculo::motocicleta);
		v->setCliente(this->clienteDueno);

		controller->modificarArchivo(v);

		this->txtPlaca->Text = placa; // refleja la normalización
		MessageBox::Show("Vehículo actualizado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		// No se cierra: esta pantalla vive dentro del panel del dashboard.
	}
	catch (Exception^ ex) {
		MessageBox::Show("Ocurrió un error al guardar los cambios: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { //Historial
	//Por ahora no hace nada
}

//Cambio de imagen queda pendiente

//---------------------------------------------------------------------------------
};
}
