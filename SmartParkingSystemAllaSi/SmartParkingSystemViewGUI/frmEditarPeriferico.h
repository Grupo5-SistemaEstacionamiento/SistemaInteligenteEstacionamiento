#pragma once

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
	/// Summary for frmEditarPeriferico
	/// </summary>
	public ref class frmEditarPeriferico : public System::Windows::Forms::Form
	{
	public:
		frmEditarPeriferico(int idPeriferico)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->idPerifericoEditar = idPeriferico;

			SmartParkingSystemController::PerifericoController^ controller = gcnew SmartParkingSystemController::PerifericoController();
			Periferico^ PerifericoEdit = controller->BuscarPerifericoxID(this->idPerifericoEditar);

			if (PerifericoEdit != nullptr) {

				this->textID->Text = Convert::ToString(PerifericoEdit->getIdPeriferico());
				//this->textID->Enabled = false; //esto ya se hace en Properties del frm con el ReadOnly
				this->textUbicacion->Text = PerifericoEdit->getUbicacion();
				this->dateTimePickerInstalacion->Value = PerifericoEdit->getFechaInstalacion();
				this->textEstado->Text = Convert::ToString(PerifericoEdit->getEstado());

				groupLED->Visible = false;
				groupServo->Visible = false;
				groupSensor->Visible = false;
				groupLectorRFID->Visible = false;
				groupBarrera->Visible = false;

				if (dynamic_cast<IndicadorLed^>(PerifericoEdit) != nullptr) { // ¿Es un LED?
					IndicadorLed^ led = dynamic_cast<IndicadorLed^>(PerifericoEdit); // Lo convertimos

					this->cboTipo->Text = "LED"; // Esto selecciona tu combobox visualmente
					groupLED->Visible = true;    // Encendemos su panel

					// Llenamos sus datos específicos
					this->cboLEDColor->Text = led->getColor();
					this->txtLEDIntensidad->Text = Convert::ToString(led->getIntesidad());
					this->txtLEDTipoLuz->Text = led->getTipoLuz();
					this->txtLEDModo->Text = led->getModoOperacion();
				}
				else if (dynamic_cast<ServoMotor^>(PerifericoEdit) != nullptr) { // ¿Es un Servo?
					ServoMotor^ servo = dynamic_cast<ServoMotor^>(PerifericoEdit);

					this->cboTipo->Text = "Servomotor";
					groupServo->Visible = true;

					this->txtServoAnguloMax->Text = Convert::ToString(servo->getAnguloMaxApertura());
					this->txtServoTorque->Text = Convert::ToString(servo->getTorque());
				}
				else if (dynamic_cast<SensorOcupacion^>(PerifericoEdit) != nullptr) { // ¿Es un Sensor?
					SensorOcupacion^ sensor = dynamic_cast<SensorOcupacion^>(PerifericoEdit);

					this->cboTipo->Text = "Sensor IR";
					groupSensor->Visible = true;

					this->txtSensorIRUmbral->Text = Convert::ToString(sensor->getUmbralDeteccion());
				}

				else if (dynamic_cast<LectorRFID^>(PerifericoEdit) != nullptr) { // ¿Es un Lector RFID?
					LectorRFID^ lector = dynamic_cast<LectorRFID^>(PerifericoEdit);

					this->cboTipo->Text = "Lector RFID";
					groupLectorRFID->Visible = true;

					this->txtLRFIDFrecuencia->Text = Convert::ToString(lector->getFrecOperacion());
					this->txtLRFIDDistancia->Text = Convert::ToString(lector->getDistanciaLecturaMax());
					this->txtLRFIDProtocolo->Text = lector->getProtocoloComunicacion();
					this->txtLRFIDPotencia->Text = Convert::ToString(lector->getPotenciaTransmicion());
					this->cboLRFIDUbicacion->Text = lector->getUbicacion();
				}

				else if (dynamic_cast<BarreraAcceso^>(PerifericoEdit) != nullptr) { // ¿Es una Tranquera?
					BarreraAcceso^ barrera = dynamic_cast<BarreraAcceso^>(PerifericoEdit);

					this->cboTipo->Text = "Barrera de Acceso";
					groupSensor->Visible = true;

					this->cboTipoBarrera->Text = barrera->getEsEntrada() ? "Carril de Entrada" : "Carril de Salida";
				}
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmEditarPeriferico()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtLEDTipoLuz;
	protected:
	private: int idPerifericoEditar; //Variable para guardar en todo el documento el id a editar
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ txtLRFIDPotencia;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtLRFIDProtocolo;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::ComboBox^ cboLRFIDUbicacion;
	private: System::Windows::Forms::TextBox^ txtLRFIDFrecuencia;
	private: System::Windows::Forms::TextBox^ txtLRFIDDistancia;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtLEDModo;
	private: System::Windows::Forms::ComboBox^ cboLEDColor;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ txtLEDIntensidad;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TextBox^ txtServoTorque;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::TextBox^ txtServoAnguloMax;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::GroupBox^ groupSensor;
	private: System::Windows::Forms::TextBox^ txtSensorIRUmbral;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::GroupBox^ groupBarrera;
	private: System::Windows::Forms::ComboBox^ cboTipoBarrera;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::GroupBox^ groupServo;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ btnRegresarEdit;
	private: System::Windows::Forms::Button^ btnGuardarEdit;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerInstalacion;
	private: System::Windows::Forms::ComboBox^ cboTipo;
	private: System::Windows::Forms::TextBox^ textID;
	private: System::Windows::Forms::TextBox^ textUbicacion;
	private: System::Windows::Forms::ComboBox^ textEstado;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupLectorRFID;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ pnlColorMuestra;
	private: System::Windows::Forms::GroupBox^ groupLED;

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
			this->txtLEDTipoLuz = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtLRFIDPotencia = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtLRFIDProtocolo = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->cboLRFIDUbicacion = (gcnew System::Windows::Forms::ComboBox());
			this->txtLRFIDFrecuencia = (gcnew System::Windows::Forms::TextBox());
			this->txtLRFIDDistancia = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtLEDModo = (gcnew System::Windows::Forms::TextBox());
			this->cboLEDColor = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->txtLEDIntensidad = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->txtServoTorque = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->txtServoAnguloMax = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->groupSensor = (gcnew System::Windows::Forms::GroupBox());
			this->txtSensorIRUmbral = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->groupBarrera = (gcnew System::Windows::Forms::GroupBox());
			this->cboTipoBarrera = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->groupServo = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->btnRegresarEdit = (gcnew System::Windows::Forms::Button());
			this->btnGuardarEdit = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->dateTimePickerInstalacion = (gcnew System::Windows::Forms::DateTimePicker());
			this->cboTipo = (gcnew System::Windows::Forms::ComboBox());
			this->textID = (gcnew System::Windows::Forms::TextBox());
			this->textUbicacion = (gcnew System::Windows::Forms::TextBox());
			this->textEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupLectorRFID = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->pnlColorMuestra = (gcnew System::Windows::Forms::Panel());
			this->groupLED = (gcnew System::Windows::Forms::GroupBox());
			this->groupSensor->SuspendLayout();
			this->groupBarrera->SuspendLayout();
			this->groupServo->SuspendLayout();
			this->panel2->SuspendLayout();
			this->grpBoxPrincipal->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupLectorRFID->SuspendLayout();
			this->groupLED->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtLEDTipoLuz
			// 
			this->txtLEDTipoLuz->BackColor = System::Drawing::Color::Silver;
			this->txtLEDTipoLuz->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtLEDTipoLuz->Location = System::Drawing::Point(468, 155);
			this->txtLEDTipoLuz->Margin = System::Windows::Forms::Padding(8);
			this->txtLEDTipoLuz->Name = L"txtLEDTipoLuz";
			this->txtLEDTipoLuz->ReadOnly = true;
			this->txtLEDTipoLuz->Size = System::Drawing::Size(322, 39);
			this->txtLEDTipoLuz->TabIndex = 49;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(21, 232);
			this->label16->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(278, 32);
			this->label16->TabIndex = 47;
			this->label16->Text = L"Modo de Operación: ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(21, 160);
			this->label14->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(170, 32);
			this->label14->TabIndex = 45;
			this->label14->Text = L"Tipo de Luz:";
			// 
			// txtLRFIDPotencia
			// 
			this->txtLRFIDPotencia->BackColor = System::Drawing::Color::White;
			this->txtLRFIDPotencia->Location = System::Drawing::Point(468, 306);
			this->txtLRFIDPotencia->Margin = System::Windows::Forms::Padding(8);
			this->txtLRFIDPotencia->Name = L"txtLRFIDPotencia";
			this->txtLRFIDPotencia->Size = System::Drawing::Size(421, 39);
			this->txtLRFIDPotencia->TabIndex = 42;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 306);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(345, 32);
			this->label1->TabIndex = 41;
			this->label1->Text = L"Potencia Transmisión [W]:";
			// 
			// txtLRFIDProtocolo
			// 
			this->txtLRFIDProtocolo->BackColor = System::Drawing::Color::White;
			this->txtLRFIDProtocolo->Location = System::Drawing::Point(468, 228);
			this->txtLRFIDProtocolo->Margin = System::Windows::Forms::Padding(8);
			this->txtLRFIDProtocolo->Name = L"txtLRFIDProtocolo";
			this->txtLRFIDProtocolo->Size = System::Drawing::Size(421, 39);
			this->txtLRFIDProtocolo->TabIndex = 40;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(21, 85);
			this->label13->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(421, 32);
			this->label13->TabIndex = 0;
			this->label13->Text = L"Frecuencia de Operación [MHz]:";
			// 
			// cboLRFIDUbicacion
			// 
			this->cboLRFIDUbicacion->BackColor = System::Drawing::Color::White;
			this->cboLRFIDUbicacion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboLRFIDUbicacion->FormattingEnabled = true;
			this->cboLRFIDUbicacion->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Entrada", L"Salida" });
			this->cboLRFIDUbicacion->Location = System::Drawing::Point(468, 377);
			this->cboLRFIDUbicacion->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboLRFIDUbicacion->Name = L"cboLRFIDUbicacion";
			this->cboLRFIDUbicacion->Size = System::Drawing::Size(320, 40);
			this->cboLRFIDUbicacion->TabIndex = 14;
			// 
			// txtLRFIDFrecuencia
			// 
			this->txtLRFIDFrecuencia->BackColor = System::Drawing::Color::White;
			this->txtLRFIDFrecuencia->Location = System::Drawing::Point(468, 85);
			this->txtLRFIDFrecuencia->Margin = System::Windows::Forms::Padding(8);
			this->txtLRFIDFrecuencia->Name = L"txtLRFIDFrecuencia";
			this->txtLRFIDFrecuencia->Size = System::Drawing::Size(421, 39);
			this->txtLRFIDFrecuencia->TabIndex = 13;
			// 
			// txtLRFIDDistancia
			// 
			this->txtLRFIDDistancia->BackColor = System::Drawing::Color::White;
			this->txtLRFIDDistancia->Location = System::Drawing::Point(468, 155);
			this->txtLRFIDDistancia->Margin = System::Windows::Forms::Padding(8);
			this->txtLRFIDDistancia->Name = L"txtLRFIDDistancia";
			this->txtLRFIDDistancia->Size = System::Drawing::Size(421, 39);
			this->txtLRFIDDistancia->TabIndex = 12;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(21, 382);
			this->label9->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(148, 32);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Ubicación:";
			// 
			// txtLEDModo
			// 
			this->txtLEDModo->BackColor = System::Drawing::Color::Silver;
			this->txtLEDModo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtLEDModo->Location = System::Drawing::Point(468, 232);
			this->txtLEDModo->Margin = System::Windows::Forms::Padding(8);
			this->txtLEDModo->Name = L"txtLEDModo";
			this->txtLEDModo->ReadOnly = true;
			this->txtLEDModo->Size = System::Drawing::Size(322, 39);
			this->txtLEDModo->TabIndex = 48;
			// 
			// cboLEDColor
			// 
			this->cboLEDColor->BackColor = System::Drawing::Color::Silver;
			this->cboLEDColor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboLEDColor->Enabled = false;
			this->cboLEDColor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cboLEDColor->FormattingEnabled = true;
			this->cboLEDColor->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Rojo", L"Verde", L"Azul", L"Amarillo" });
			this->cboLEDColor->Location = System::Drawing::Point(468, 75);
			this->cboLEDColor->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboLEDColor->Name = L"cboLEDColor";
			this->cboLEDColor->Size = System::Drawing::Size(320, 40);
			this->cboLEDColor->TabIndex = 44;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(21, 80);
			this->label15->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(90, 32);
			this->label15->TabIndex = 43;
			this->label15->Text = L"Color:";
			// 
			// txtLEDIntensidad
			// 
			this->txtLEDIntensidad->BackColor = System::Drawing::Color::White;
			this->txtLEDIntensidad->Location = System::Drawing::Point(468, 306);
			this->txtLEDIntensidad->Margin = System::Windows::Forms::Padding(8);
			this->txtLEDIntensidad->Name = L"txtLEDIntensidad";
			this->txtLEDIntensidad->Size = System::Drawing::Size(421, 39);
			this->txtLEDIntensidad->TabIndex = 12;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(21, 306);
			this->label17->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(202, 32);
			this->label17->TabIndex = 4;
			this->label17->Text = L"Intensidad [%]:";
			// 
			// txtServoTorque
			// 
			this->txtServoTorque->BackColor = System::Drawing::Color::White;
			this->txtServoTorque->Location = System::Drawing::Point(462, 155);
			this->txtServoTorque->Margin = System::Windows::Forms::Padding(8);
			this->txtServoTorque->Name = L"txtServoTorque";
			this->txtServoTorque->Size = System::Drawing::Size(421, 39);
			this->txtServoTorque->TabIndex = 14;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(15, 155);
			this->label18->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(220, 32);
			this->label18->TabIndex = 13;
			this->label18->Text = L"Torque [kg*cm]: ";
			// 
			// txtServoAnguloMax
			// 
			this->txtServoAnguloMax->BackColor = System::Drawing::Color::White;
			this->txtServoAnguloMax->Location = System::Drawing::Point(465, 74);
			this->txtServoAnguloMax->Margin = System::Windows::Forms::Padding(8);
			this->txtServoAnguloMax->Name = L"txtServoAnguloMax";
			this->txtServoAnguloMax->Size = System::Drawing::Size(421, 39);
			this->txtServoAnguloMax->TabIndex = 12;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(18, 74);
			this->label21->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(303, 32);
			this->label21->TabIndex = 4;
			this->label21->Text = L"Ángulo Máx. Apertura: ";
			// 
			// groupSensor
			// 
			this->groupSensor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupSensor->Controls->Add(this->txtSensorIRUmbral);
			this->groupSensor->Controls->Add(this->label20);
			this->groupSensor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupSensor->Location = System::Drawing::Point(34, 552);
			this->groupSensor->Margin = System::Windows::Forms::Padding(8);
			this->groupSensor->Name = L"groupSensor";
			this->groupSensor->Padding = System::Windows::Forms::Padding(8);
			this->groupSensor->Size = System::Drawing::Size(928, 185);
			this->groupSensor->TabIndex = 61;
			this->groupSensor->TabStop = false;
			this->groupSensor->Text = L"Inserte la Información del Sensor de Ocupación";
			// 
			// txtSensorIRUmbral
			// 
			this->txtSensorIRUmbral->BackColor = System::Drawing::Color::White;
			this->txtSensorIRUmbral->Location = System::Drawing::Point(468, 85);
			this->txtSensorIRUmbral->Margin = System::Windows::Forms::Padding(8);
			this->txtSensorIRUmbral->Name = L"txtSensorIRUmbral";
			this->txtSensorIRUmbral->Size = System::Drawing::Size(421, 39);
			this->txtSensorIRUmbral->TabIndex = 12;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(21, 85);
			this->label20->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(286, 32);
			this->label20->TabIndex = 4;
			this->label20->Text = L"Umbral de Detección:";
			// 
			// groupBarrera
			// 
			this->groupBarrera->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBarrera->Controls->Add(this->cboTipoBarrera);
			this->groupBarrera->Controls->Add(this->label12);
			this->groupBarrera->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBarrera->Location = System::Drawing::Point(34, 552);
			this->groupBarrera->Margin = System::Windows::Forms::Padding(8);
			this->groupBarrera->Name = L"groupBarrera";
			this->groupBarrera->Padding = System::Windows::Forms::Padding(8);
			this->groupBarrera->Size = System::Drawing::Size(928, 185);
			this->groupBarrera->TabIndex = 62;
			this->groupBarrera->TabStop = false;
			this->groupBarrera->Text = L"Inserte la Información de la Barrera de Acceso";
			// 
			// cboTipoBarrera
			// 
			this->cboTipoBarrera->BackColor = System::Drawing::Color::White;
			this->cboTipoBarrera->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTipoBarrera->FormattingEnabled = true;
			this->cboTipoBarrera->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Carrill de Entrada", L"Carril de Salida" });
			this->cboTipoBarrera->Location = System::Drawing::Point(309, 85);
			this->cboTipoBarrera->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboTipoBarrera->Name = L"cboTipoBarrera";
			this->cboTipoBarrera->Size = System::Drawing::Size(320, 40);
			this->cboTipoBarrera->TabIndex = 16;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(21, 85);
			this->label12->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(218, 32);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Tipo de Barrera:";
			// 
			// groupServo
			// 
			this->groupServo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupServo->Controls->Add(this->txtServoTorque);
			this->groupServo->Controls->Add(this->label18);
			this->groupServo->Controls->Add(this->txtServoAnguloMax);
			this->groupServo->Controls->Add(this->label21);
			this->groupServo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupServo->Location = System::Drawing::Point(34, 552);
			this->groupServo->Margin = System::Windows::Forms::Padding(8);
			this->groupServo->Name = L"groupServo";
			this->groupServo->Padding = System::Windows::Forms::Padding(8);
			this->groupServo->Size = System::Drawing::Size(928, 235);
			this->groupServo->TabIndex = 60;
			this->groupServo->TabStop = false;
			this->groupServo->Text = L"Inserte la Información del Servomotor";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(21, 155);
			this->label10->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(301, 32);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Dist. Máx. Lectura [cm]";
			// 
			// btnRegresarEdit
			// 
			this->btnRegresarEdit->BackColor = System::Drawing::Color::Brown;
			this->btnRegresarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegresarEdit->ForeColor = System::Drawing::Color::White;
			this->btnRegresarEdit->Location = System::Drawing::Point(508, 1040);
			this->btnRegresarEdit->Name = L"btnRegresarEdit";
			this->btnRegresarEdit->Size = System::Drawing::Size(249, 48);
			this->btnRegresarEdit->TabIndex = 55;
			this->btnRegresarEdit->Text = L"Cancelar";
			this->btnRegresarEdit->UseVisualStyleBackColor = false;
			this->btnRegresarEdit->Click += gcnew System::EventHandler(this, &frmEditarPeriferico::btnRegresarEdit_Click);
			// 
			// btnGuardarEdit
			// 
			this->btnGuardarEdit->BackColor = System::Drawing::Color::Green;
			this->btnGuardarEdit->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGuardarEdit->ForeColor = System::Drawing::Color::White;
			this->btnGuardarEdit->Location = System::Drawing::Point(158, 1040);
			this->btnGuardarEdit->Name = L"btnGuardarEdit";
			this->btnGuardarEdit->Size = System::Drawing::Size(267, 48);
			this->btnGuardarEdit->TabIndex = 57;
			this->btnGuardarEdit->Text = L"Guardar Cambios";
			this->btnGuardarEdit->UseVisualStyleBackColor = false;
			this->btnGuardarEdit->Click += gcnew System::EventHandler(this, &frmEditarPeriferico::btnGuardarEdit_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(0, 1128);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1024, 78);
			this->panel2->TabIndex = 54;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(30, 22);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(467, 27);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Advertencia: No deje ningún espacio vacío";
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->grpBoxPrincipal->Controls->Add(this->dateTimePickerInstalacion);
			this->grpBoxPrincipal->Controls->Add(this->cboTipo);
			this->grpBoxPrincipal->Controls->Add(this->textID);
			this->grpBoxPrincipal->Controls->Add(this->textUbicacion);
			this->grpBoxPrincipal->Controls->Add(this->textEstado);
			this->grpBoxPrincipal->Controls->Add(this->label8);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(34, 75);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(8);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(8);
			this->grpBoxPrincipal->Size = System::Drawing::Size(928, 462);
			this->grpBoxPrincipal->TabIndex = 56;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Inserte la Información del Periferico";
			// 
			// dateTimePickerInstalacion
			// 
			this->dateTimePickerInstalacion->CalendarMonthBackground = System::Drawing::Color::Gray;
			this->dateTimePickerInstalacion->CustomFormat = L"dd/MM/yyyy";
			this->dateTimePickerInstalacion->Enabled = false;
			this->dateTimePickerInstalacion->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerInstalacion->Location = System::Drawing::Point(309, 228);
			this->dateTimePickerInstalacion->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePickerInstalacion->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->dateTimePickerInstalacion->Name = L"dateTimePickerInstalacion";
			this->dateTimePickerInstalacion->Size = System::Drawing::Size(320, 39);
			this->dateTimePickerInstalacion->TabIndex = 15;
			this->dateTimePickerInstalacion->Value = System::DateTime(2005, 11, 24, 0, 0, 0, 0);
			// 
			// cboTipo
			// 
			this->cboTipo->BackColor = System::Drawing::Color::Silver;
			this->cboTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cboTipo->Enabled = false;
			this->cboTipo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cboTipo->FormattingEnabled = true;
			this->cboTipo->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Barrera de Acceso", L"Servomotor", L"Sensor IR",
					L"Lector RFID", L"LED"
			});
			this->cboTipo->Location = System::Drawing::Point(309, 306);
			this->cboTipo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cboTipo->Name = L"cboTipo";
			this->cboTipo->Size = System::Drawing::Size(320, 40);
			this->cboTipo->TabIndex = 14;
			// 
			// textID
			// 
			this->textID->BackColor = System::Drawing::Color::Silver;
			this->textID->Location = System::Drawing::Point(309, 80);
			this->textID->Margin = System::Windows::Forms::Padding(8);
			this->textID->Name = L"textID";
			this->textID->ReadOnly = true;
			this->textID->Size = System::Drawing::Size(580, 39);
			this->textID->TabIndex = 13;
			// 
			// textUbicacion
			// 
			this->textUbicacion->BackColor = System::Drawing::Color::White;
			this->textUbicacion->Location = System::Drawing::Point(309, 155);
			this->textUbicacion->Margin = System::Windows::Forms::Padding(8);
			this->textUbicacion->Name = L"textUbicacion";
			this->textUbicacion->Size = System::Drawing::Size(580, 39);
			this->textUbicacion->TabIndex = 12;
			// 
			// textEstado
			// 
			this->textEstado->BackColor = System::Drawing::Color::White;
			this->textEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->textEstado->FormattingEnabled = true;
			this->textEstado->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Activo", L"Inactivo", L"Averiado", L"Mantenimiento" });
			this->textEstado->Location = System::Drawing::Point(309, 394);
			this->textEstado->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textEstado->Name = L"textEstado";
			this->textEstado->Size = System::Drawing::Size(320, 40);
			this->textEstado->TabIndex = 11;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(21, 398);
			this->label8->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(111, 32);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Estado:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 306);
			this->label6->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 32);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Tipo:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 162);
			this->label5->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(148, 32);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Ubicación:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 228);
			this->label4->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(291, 32);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Fecha de Instalación: ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 85);
			this->label3->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(177, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = L"ID Periferico:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1024, 65);
			this->panel1->TabIndex = 53;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(12, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(241, 33);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Añadir Periferico";
			// 
			// groupLectorRFID
			// 
			this->groupLectorRFID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupLectorRFID->Controls->Add(this->txtLRFIDPotencia);
			this->groupLectorRFID->Controls->Add(this->label1);
			this->groupLectorRFID->Controls->Add(this->txtLRFIDProtocolo);
			this->groupLectorRFID->Controls->Add(this->label13);
			this->groupLectorRFID->Controls->Add(this->cboLRFIDUbicacion);
			this->groupLectorRFID->Controls->Add(this->txtLRFIDFrecuencia);
			this->groupLectorRFID->Controls->Add(this->txtLRFIDDistancia);
			this->groupLectorRFID->Controls->Add(this->label9);
			this->groupLectorRFID->Controls->Add(this->label10);
			this->groupLectorRFID->Controls->Add(this->label11);
			this->groupLectorRFID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupLectorRFID->Location = System::Drawing::Point(34, 552);
			this->groupLectorRFID->Margin = System::Windows::Forms::Padding(8);
			this->groupLectorRFID->Name = L"groupLectorRFID";
			this->groupLectorRFID->Padding = System::Windows::Forms::Padding(8);
			this->groupLectorRFID->Size = System::Drawing::Size(928, 454);
			this->groupLectorRFID->TabIndex = 58;
			this->groupLectorRFID->TabStop = false;
			this->groupLectorRFID->Text = L"Inserte la Información del Lector RFID";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(21, 228);
			this->label11->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(143, 32);
			this->label11->TabIndex = 3;
			this->label11->Text = L"Protocolo:";
			// 
			// pnlColorMuestra
			// 
			this->pnlColorMuestra->BackColor = System::Drawing::Color::Silver;
			this->pnlColorMuestra->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pnlColorMuestra->Location = System::Drawing::Point(800, 75);
			this->pnlColorMuestra->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pnlColorMuestra->Name = L"pnlColorMuestra";
			this->pnlColorMuestra->Size = System::Drawing::Size(43, 44);
			this->pnlColorMuestra->TabIndex = 50;
			// 
			// groupLED
			// 
			this->groupLED->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(110)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupLED->Controls->Add(this->pnlColorMuestra);
			this->groupLED->Controls->Add(this->txtLEDTipoLuz);
			this->groupLED->Controls->Add(this->txtLEDModo);
			this->groupLED->Controls->Add(this->label16);
			this->groupLED->Controls->Add(this->label14);
			this->groupLED->Controls->Add(this->cboLEDColor);
			this->groupLED->Controls->Add(this->label15);
			this->groupLED->Controls->Add(this->txtLEDIntensidad);
			this->groupLED->Controls->Add(this->label17);
			this->groupLED->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupLED->Location = System::Drawing::Point(34, 552);
			this->groupLED->Margin = System::Windows::Forms::Padding(8);
			this->groupLED->Name = L"groupLED";
			this->groupLED->Padding = System::Windows::Forms::Padding(8);
			this->groupLED->Size = System::Drawing::Size(928, 374);
			this->groupLED->TabIndex = 59;
			this->groupLED->TabStop = false;
			this->groupLED->Text = L"Inserte la Información del Indicador LED";
			// 
			// frmEditarPeriferico
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1024, 1206);
			this->Controls->Add(this->groupLED);
			this->Controls->Add(this->btnRegresarEdit);
			this->Controls->Add(this->btnGuardarEdit);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupSensor);
			this->Controls->Add(this->groupBarrera);
			this->Controls->Add(this->groupServo);
			this->Controls->Add(this->groupLectorRFID);
			this->Name = L"frmEditarPeriferico";
			this->Text = L"Editor de Periféricos";
			this->groupSensor->ResumeLayout(false);
			this->groupSensor->PerformLayout();
			this->groupBarrera->ResumeLayout(false);
			this->groupBarrera->PerformLayout();
			this->groupServo->ResumeLayout(false);
			this->groupServo->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupLectorRFID->ResumeLayout(false);
			this->groupLectorRFID->PerformLayout();
			this->groupLED->ResumeLayout(false);
			this->groupLED->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
public: 


private: System::Void btnGuardarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Guardar

	try {
	SmartParkingSystemController:PerifericoController^ Controller = gcnew PerifericoController();

		Periferico^ PerifericoEdit = Controller->BuscarPerifericoxID(idPerifericoEditar);

		if (PerifericoEdit != nullptr) {

			PerifericoEdit->setUbicacion(this->textUbicacion->Text);
			PerifericoEdit->setEstado((EstadoPeriferico)Enum::Parse(EstadoPeriferico::typeid, this->textEstado->Text));

			String^ tipoSeleccionado = this->cboTipo->Text;

			if (tipoSeleccionado == "LED") {
				IndicadorLed^ led = dynamic_cast<IndicadorLed^>(PerifericoEdit);
				if (led != nullptr) {
					// Solo seteamos lo que dejamos editable en el UI
					led->setIntesidad(Convert::ToInt32(this->txtLEDIntensidad->Text));
				}
			}
			else if (tipoSeleccionado == "Servomotor") {
				ServoMotor^ servo = dynamic_cast<ServoMotor^>(PerifericoEdit);
				if (servo != nullptr) {
					servo->setAnguloMaxApertura(Convert::ToDouble(this->txtServoAnguloMax->Text));
					// El torque lo bloqueamos, así que no necesitamos setearlo
				}
			}
			else if (tipoSeleccionado == "Sensor IR") {
				SensorOcupacion^ sensor = dynamic_cast<SensorOcupacion^>(PerifericoEdit);
				if (sensor != nullptr) {
					sensor->setUmbralDeteccion(Convert::ToDouble(this->txtSensorIRUmbral->Text));
				}
			}

			else if (tipoSeleccionado == "Lector RFID") {
				LectorRFID^ lector = dynamic_cast<LectorRFID^>(PerifericoEdit);
				if (lector != nullptr) {
					lector->setFrecOperacion(Convert::ToDouble(this->txtLRFIDFrecuencia->Text));
					lector->setDistanciaLecturaMax(Convert::ToDouble(this->txtLRFIDDistancia->Text));
					lector->setProtocoloComunicacion(this->txtLRFIDProtocolo->Text);
					lector->setPotenciaTransmicion(Convert::ToDouble(this->txtLRFIDPotencia->Text));
					lector->setUbicacion(this->cboLRFIDUbicacion->Text);
				}
			}

			else if (tipoSeleccionado == "Barrera de Acceso") {
				BarreraAcceso^ barrera = dynamic_cast<BarreraAcceso^>(PerifericoEdit);
				if (barrera != nullptr) {

					bool EsEntrada = (this->cboTipoBarrera->Text == "Carril de Entrada");

					barrera->setEsEntrada(EsEntrada);
				}
			}
			Controller->ModificarPeriferico(PerifericoEdit);

			MessageBox::Show("Periférico actualizado exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close();
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Por favor, asegúrese de llenar todos los campos numéricos correctamente y no dejar espacios vacíos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnRegresarEdit_Click(System::Object^ sender, System::EventArgs^ e) { //Cancelar
	this->Close();
}

	   private: System::Void cboLEDColor_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) { //Para cambiar el color segun el color de LED q se escoja

		   String^ colorSeleccionado = this->cboLEDColor->Text;

		   if (colorSeleccionado == "Rojo") {
			   this->pnlColorMuestra->BackColor = System::Drawing::Color::Red;
		   }
		   else if (colorSeleccionado == "Verde") {
			   this->pnlColorMuestra->BackColor = System::Drawing::Color::LimeGreen;
		   }
		   else if (colorSeleccionado == "Azul") {
			   this->pnlColorMuestra->BackColor = System::Drawing::Color::DodgerBlue;
		   }
		   else if (colorSeleccionado == "Amarillo") {
			   this->pnlColorMuestra->BackColor = System::Drawing::Color::Yellow;
		   }
	   }
};
}
