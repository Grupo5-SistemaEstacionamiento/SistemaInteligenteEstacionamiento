#pragma once

using namespace SmartParkingSystemController;
using namespace SmartParkingSystemModel;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmTarifa
	/// </summary>
	public ref class frmTarifa : public System::Windows::Forms::Form
	{

	private:
		TarifaController^ tarifaController;

	public:
		frmTarifa(void)
		{
			InitializeComponent();

			tarifaController = gcnew TarifaController();
		}

	private:
		void cargarTarifas()
		{
			dgvTarifas->Rows->Clear();

			List<Tarifa^>^ lista =
				tarifaController->listarTarifas();

			for each (Tarifa ^ tarifa in lista)
			{
				dgvTarifas->Rows->Add(
					tarifa->getIdTarifa(),
					tarifa->getValorHora().ToString("F2"),
					tarifa->getValorFraccion15min().ToString("F2"),
					tarifa->getDescuentoMembresia().ToString("F2"),
					tarifa->getPenalizacionTicketPerdido().ToString("F2")
				);
			}

			dgvTarifas->ClearSelection();
		}

	private:
		void limpiarCampos()
		{
			// Muestra el siguiente ID disponible.
			txtIdTarifa->Text =
				tarifaController->obtenerSiguienteId().ToString();

			// Limpia los campos de entrada.
			txtValorHora->Clear();
			txtValorFraccion->Clear();
			txtDescuentoMembresia->Clear();
			txtPenalizacionTicket->Clear();

			// Quita cualquier selección de la tabla.
			dgvTarifas->ClearSelection();

			// Coloca el cursor en el primer campo.
			txtValorHora->Focus();
		}

	private:
		bool obtenerDatosTarifa(
		double% valorHora,
		double% valorFraccion15min,
		double% descuentoMembresia,
		double% penalizacionTicketPerdido)
		{
			// Verifica que todos los campos hayan sido completados.
			if (String::IsNullOrWhiteSpace(txtValorHora->Text) ||
				String::IsNullOrWhiteSpace(txtValorFraccion->Text) ||
				String::IsNullOrWhiteSpace(txtDescuentoMembresia->Text) ||
				String::IsNullOrWhiteSpace(txtPenalizacionTicket->Text))
			{
				MessageBox::Show(
					"Debe completar todos los campos.",
					"Datos incompletos",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				return false;
			}

			// Convierte los datos ingresados a valores numéricos.
			if (!Double::TryParse(txtValorHora->Text, valorHora))
			{
				MessageBox::Show(
					"El valor por hora debe ser un número válido.",
					"Dato incorrecto",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				txtValorHora->Focus();
				return false;
			}

			if (!Double::TryParse(txtValorFraccion->Text, valorFraccion15min))
			{
				MessageBox::Show(
					"El valor de la fracción de 15 minutos debe ser un número válido.",
					"Dato incorrecto",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				txtValorFraccion->Focus();
				return false;
			}

			if (!Double::TryParse(txtDescuentoMembresia->Text, descuentoMembresia))
			{
				MessageBox::Show(
					"El descuento de membresía debe ser un número válido.",
					"Dato incorrecto",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				txtDescuentoMembresia->Focus();
				return false;
			}

			if (!Double::TryParse(txtPenalizacionTicket->Text, penalizacionTicketPerdido))
			{
				MessageBox::Show(
					"La penalización por ticket perdido debe ser un número válido.",
					"Dato incorrecto",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning
				);

				txtPenalizacionTicket->Focus();
				return false;
			}

			return true;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmTarifa()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlInfo;
	protected:

	private: System::Windows::Forms::Panel^ pnlTitulo;
	protected:
























	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::GroupBox^ gbDatosTarifa;
	private: System::Windows::Forms::Label^ lblIdTarifa;
	private: System::Windows::Forms::TextBox^ txtPenalizacionTicket;


	private: System::Windows::Forms::Label^ lblPenalizacionTicket;
	private: System::Windows::Forms::TextBox^ txtDescuentoMembresia;


	private: System::Windows::Forms::Label^ lblDescuentoMembresia;
	private: System::Windows::Forms::TextBox^ txtValorFraccion;


	private: System::Windows::Forms::Label^ lblValorFraccion;
	private: System::Windows::Forms::TextBox^ txtValorHora;


	private: System::Windows::Forms::Label^ lblValorHora;
	private: System::Windows::Forms::TextBox^ txtIdTarifa;
	private: System::Windows::Forms::DataGridView^ dgvTarifas;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdTarifa;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colValorHora;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colValorFraccion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDescuento;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colPenalizacion;
private: System::Windows::Forms::Button^ btnLimpiar;

	private: System::Windows::Forms::Button^ btnEliminar;


	private: System::Windows::Forms::Button^ btnModificar;

	private: System::Windows::Forms::Button^ btnRegistrar;
















































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
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->gbDatosTarifa = (gcnew System::Windows::Forms::GroupBox());
			this->dgvTarifas = (gcnew System::Windows::Forms::DataGridView());
			this->colIdTarifa = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colValorHora = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colValorFraccion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDescuento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPenalizacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnModificar = (gcnew System::Windows::Forms::Button());
			this->btnRegistrar = (gcnew System::Windows::Forms::Button());
			this->txtPenalizacionTicket = (gcnew System::Windows::Forms::TextBox());
			this->lblPenalizacionTicket = (gcnew System::Windows::Forms::Label());
			this->txtDescuentoMembresia = (gcnew System::Windows::Forms::TextBox());
			this->lblDescuentoMembresia = (gcnew System::Windows::Forms::Label());
			this->txtValorFraccion = (gcnew System::Windows::Forms::TextBox());
			this->lblValorFraccion = (gcnew System::Windows::Forms::Label());
			this->txtValorHora = (gcnew System::Windows::Forms::TextBox());
			this->lblValorHora = (gcnew System::Windows::Forms::Label());
			this->txtIdTarifa = (gcnew System::Windows::Forms::TextBox());
			this->lblIdTarifa = (gcnew System::Windows::Forms::Label());
			this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->pnlInfo->SuspendLayout();
			this->gbDatosTarifa->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTarifas))->BeginInit();
			this->pnlTitulo->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlInfo
			// 
			this->pnlInfo->BackColor = System::Drawing::Color::White;
			this->pnlInfo->Controls->Add(this->gbDatosTarifa);
			this->pnlInfo->Controls->Add(this->pnlTitulo);
			this->pnlInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlInfo->Location = System::Drawing::Point(0, 0);
			this->pnlInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(1165, 720);
			this->pnlInfo->TabIndex = 14;
			// 
			// gbDatosTarifa
			// 
			this->gbDatosTarifa->Controls->Add(this->dgvTarifas);
			this->gbDatosTarifa->Controls->Add(this->btnLimpiar);
			this->gbDatosTarifa->Controls->Add(this->btnEliminar);
			this->gbDatosTarifa->Controls->Add(this->btnModificar);
			this->gbDatosTarifa->Controls->Add(this->btnRegistrar);
			this->gbDatosTarifa->Controls->Add(this->txtPenalizacionTicket);
			this->gbDatosTarifa->Controls->Add(this->lblPenalizacionTicket);
			this->gbDatosTarifa->Controls->Add(this->txtDescuentoMembresia);
			this->gbDatosTarifa->Controls->Add(this->lblDescuentoMembresia);
			this->gbDatosTarifa->Controls->Add(this->txtValorFraccion);
			this->gbDatosTarifa->Controls->Add(this->lblValorFraccion);
			this->gbDatosTarifa->Controls->Add(this->txtValorHora);
			this->gbDatosTarifa->Controls->Add(this->lblValorHora);
			this->gbDatosTarifa->Controls->Add(this->txtIdTarifa);
			this->gbDatosTarifa->Controls->Add(this->lblIdTarifa);
			this->gbDatosTarifa->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbDatosTarifa->Location = System::Drawing::Point(12, 71);
			this->gbDatosTarifa->Name = L"gbDatosTarifa";
			this->gbDatosTarifa->Size = System::Drawing::Size(1141, 642);
			this->gbDatosTarifa->TabIndex = 57;
			this->gbDatosTarifa->TabStop = false;
			this->gbDatosTarifa->Text = L"Datos de la tarifa";
			// 
			// dgvTarifas
			// 
			this->dgvTarifas->AllowUserToAddRows = false;
			this->dgvTarifas->AllowUserToDeleteRows = false;
			this->dgvTarifas->AllowUserToResizeRows = false;
			this->dgvTarifas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvTarifas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTarifas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colIdTarifa,
					this->colValorHora, this->colValorFraccion, this->colDescuento, this->colPenalizacion
			});
			this->dgvTarifas->Location = System::Drawing::Point(82, 382);
			this->dgvTarifas->Margin = System::Windows::Forms::Padding(4);
			this->dgvTarifas->MultiSelect = false;
			this->dgvTarifas->Name = L"dgvTarifas";
			this->dgvTarifas->ReadOnly = true;
			this->dgvTarifas->RowHeadersVisible = false;
			this->dgvTarifas->RowHeadersWidth = 51;
			this->dgvTarifas->RowTemplate->Height = 24;
			this->dgvTarifas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvTarifas->Size = System::Drawing::Size(980, 250);
			this->dgvTarifas->TabIndex = 76;
			this->dgvTarifas->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &frmTarifa::dgvTarifas_CellClick);
			// 
			// colIdTarifa
			// 
			this->colIdTarifa->FillWeight = 40.10694F;
			this->colIdTarifa->HeaderText = L"ID";
			this->colIdTarifa->MinimumWidth = 6;
			this->colIdTarifa->Name = L"colIdTarifa";
			this->colIdTarifa->ReadOnly = true;
			// 
			// colValorHora
			// 
			this->colValorHora->FillWeight = 114.9732F;
			this->colValorHora->HeaderText = L"Valor hora (S/)";
			this->colValorHora->MinimumWidth = 6;
			this->colValorHora->Name = L"colValorHora";
			this->colValorHora->ReadOnly = true;
			// 
			// colValorFraccion
			// 
			this->colValorFraccion->FillWeight = 114.9732F;
			this->colValorFraccion->HeaderText = L"Fracción 15 min (S/)";
			this->colValorFraccion->MinimumWidth = 6;
			this->colValorFraccion->Name = L"colValorFraccion";
			this->colValorFraccion->ReadOnly = true;
			// 
			// colDescuento
			// 
			this->colDescuento->FillWeight = 114.9732F;
			this->colDescuento->HeaderText = L"Descuento (%)";
			this->colDescuento->MinimumWidth = 6;
			this->colDescuento->Name = L"colDescuento";
			this->colDescuento->ReadOnly = true;
			// 
			// colPenalizacion
			// 
			this->colPenalizacion->FillWeight = 114.9732F;
			this->colPenalizacion->HeaderText = L"Penalización (S/)";
			this->colPenalizacion->MinimumWidth = 6;
			this->colPenalizacion->Name = L"colPenalizacion";
			this->colPenalizacion->ReadOnly = true;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->AutoSize = true;
			this->btnLimpiar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::Color::White;
			this->btnLimpiar->Location = System::Drawing::Point(192, 308);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(4);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(128, 53);
			this->btnLimpiar->TabIndex = 75;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmTarifa::btnLimpiar_Click);
			// 
			// btnEliminar
			// 
			this->btnEliminar->AutoSize = true;
			this->btnEliminar->BackColor = System::Drawing::Color::Red;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::Color::White;
			this->btnEliminar->Location = System::Drawing::Point(752, 308);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(138, 53);
			this->btnEliminar->TabIndex = 74;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmTarifa::btnEliminar_Click);
			// 
			// btnModificar
			// 
			this->btnModificar->AutoSize = true;
			this->btnModificar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnModificar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnModificar->ForeColor = System::Drawing::Color::White;
			this->btnModificar->Location = System::Drawing::Point(558, 308);
			this->btnModificar->Margin = System::Windows::Forms::Padding(4);
			this->btnModificar->Name = L"btnModificar";
			this->btnModificar->Size = System::Drawing::Size(152, 53);
			this->btnModificar->TabIndex = 73;
			this->btnModificar->Text = L"Modificar";
			this->btnModificar->UseVisualStyleBackColor = false;
			this->btnModificar->Click += gcnew System::EventHandler(this, &frmTarifa::btnModificar_Click);
			// 
			// btnRegistrar
			// 
			this->btnRegistrar->AutoSize = true;
			this->btnRegistrar->BackColor = System::Drawing::Color::MediumSlateBlue;
			this->btnRegistrar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegistrar->ForeColor = System::Drawing::Color::White;
			this->btnRegistrar->Location = System::Drawing::Point(366, 308);
			this->btnRegistrar->Margin = System::Windows::Forms::Padding(4);
			this->btnRegistrar->Name = L"btnRegistrar";
			this->btnRegistrar->Size = System::Drawing::Size(148, 53);
			this->btnRegistrar->TabIndex = 72;
			this->btnRegistrar->Text = L"Registrar";
			this->btnRegistrar->UseVisualStyleBackColor = false;
			this->btnRegistrar->Click += gcnew System::EventHandler(this, &frmTarifa::btnRegistrar_Click);
			// 
			// txtPenalizacionTicket
			// 
			this->txtPenalizacionTicket->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtPenalizacionTicket->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtPenalizacionTicket->Location = System::Drawing::Point(726, 244);
			this->txtPenalizacionTicket->Margin = System::Windows::Forms::Padding(4);
			this->txtPenalizacionTicket->Name = L"txtPenalizacionTicket";
			this->txtPenalizacionTicket->Size = System::Drawing::Size(164, 42);
			this->txtPenalizacionTicket->TabIndex = 70;
			// 
			// lblPenalizacionTicket
			// 
			this->lblPenalizacionTicket->AutoSize = true;
			this->lblPenalizacionTicket->BackColor = System::Drawing::Color::White;
			this->lblPenalizacionTicket->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPenalizacionTicket->Location = System::Drawing::Point(186, 249);
			this->lblPenalizacionTicket->Name = L"lblPenalizacionTicket";
			this->lblPenalizacionTicket->Size = System::Drawing::Size(487, 34);
			this->lblPenalizacionTicket->TabIndex = 69;
			this->lblPenalizacionTicket->Text = L"Penalización por ticket perdido (S/):";
			// 
			// txtDescuentoMembresia
			// 
			this->txtDescuentoMembresia->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtDescuentoMembresia->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtDescuentoMembresia->Location = System::Drawing::Point(726, 194);
			this->txtDescuentoMembresia->Margin = System::Windows::Forms::Padding(4);
			this->txtDescuentoMembresia->Name = L"txtDescuentoMembresia";
			this->txtDescuentoMembresia->Size = System::Drawing::Size(164, 42);
			this->txtDescuentoMembresia->TabIndex = 68;
			// 
			// lblDescuentoMembresia
			// 
			this->lblDescuentoMembresia->AutoSize = true;
			this->lblDescuentoMembresia->BackColor = System::Drawing::Color::White;
			this->lblDescuentoMembresia->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDescuentoMembresia->Location = System::Drawing::Point(186, 199);
			this->lblDescuentoMembresia->Name = L"lblDescuentoMembresia";
			this->lblDescuentoMembresia->Size = System::Drawing::Size(366, 34);
			this->lblDescuentoMembresia->TabIndex = 67;
			this->lblDescuentoMembresia->Text = L"Descuento membresía (%):";
			// 
			// txtValorFraccion
			// 
			this->txtValorFraccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtValorFraccion->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtValorFraccion->Location = System::Drawing::Point(726, 144);
			this->txtValorFraccion->Margin = System::Windows::Forms::Padding(4);
			this->txtValorFraccion->Name = L"txtValorFraccion";
			this->txtValorFraccion->Size = System::Drawing::Size(164, 42);
			this->txtValorFraccion->TabIndex = 66;
			// 
			// lblValorFraccion
			// 
			this->lblValorFraccion->AutoSize = true;
			this->lblValorFraccion->BackColor = System::Drawing::Color::White;
			this->lblValorFraccion->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblValorFraccion->Location = System::Drawing::Point(186, 149);
			this->lblValorFraccion->Name = L"lblValorFraccion";
			this->lblValorFraccion->Size = System::Drawing::Size(361, 34);
			this->lblValorFraccion->TabIndex = 65;
			this->lblValorFraccion->Text = L"Valor fracción 15 min (S/):";
			// 
			// txtValorHora
			// 
			this->txtValorHora->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtValorHora->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtValorHora->Location = System::Drawing::Point(726, 94);
			this->txtValorHora->Margin = System::Windows::Forms::Padding(4);
			this->txtValorHora->Name = L"txtValorHora";
			this->txtValorHora->Size = System::Drawing::Size(164, 42);
			this->txtValorHora->TabIndex = 64;
			// 
			// lblValorHora
			// 
			this->lblValorHora->AutoSize = true;
			this->lblValorHora->BackColor = System::Drawing::Color::White;
			this->lblValorHora->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblValorHora->Location = System::Drawing::Point(186, 99);
			this->lblValorHora->Name = L"lblValorHora";
			this->lblValorHora->Size = System::Drawing::Size(270, 34);
			this->lblValorHora->TabIndex = 63;
			this->lblValorHora->Text = L"Valor por hora (S/):";
			// 
			// txtIdTarifa
			// 
			this->txtIdTarifa->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtIdTarifa->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIdTarifa->Location = System::Drawing::Point(726, 44);
			this->txtIdTarifa->Margin = System::Windows::Forms::Padding(4);
			this->txtIdTarifa->Name = L"txtIdTarifa";
			this->txtIdTarifa->ReadOnly = true;
			this->txtIdTarifa->Size = System::Drawing::Size(164, 42);
			this->txtIdTarifa->TabIndex = 62;
			// 
			// lblIdTarifa
			// 
			this->lblIdTarifa->AutoSize = true;
			this->lblIdTarifa->BackColor = System::Drawing::Color::White;
			this->lblIdTarifa->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblIdTarifa->Location = System::Drawing::Point(186, 49);
			this->lblIdTarifa->Name = L"lblIdTarifa";
			this->lblIdTarifa->Size = System::Drawing::Size(137, 34);
			this->lblIdTarifa->TabIndex = 61;
			this->lblIdTarifa->Text = L"ID Tarifa:";
			// 
			// pnlTitulo
			// 
			this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnlTitulo->Controls->Add(this->lblTitulo);
			this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitulo->Location = System::Drawing::Point(0, 0);
			this->pnlTitulo->Name = L"pnlTitulo";
			this->pnlTitulo->Size = System::Drawing::Size(1165, 65);
			this->pnlTitulo->TabIndex = 56;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Gadugi", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitulo->ForeColor = System::Drawing::Color::White;
			this->lblTitulo->Location = System::Drawing::Point(12, 12);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(298, 40);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Configurar Tarifas";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// frmTarifa
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1165, 720);
			this->Controls->Add(this->pnlInfo);
			this->Name = L"frmTarifa";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Configurar Tarifas";
			this->Load += gcnew System::EventHandler(this, &frmTarifa::frmTarifa_Load);
			this->pnlInfo->ResumeLayout(false);
			this->gbDatosTarifa->ResumeLayout(false);
			this->gbDatosTarifa->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTarifas))->EndInit();
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textInfoCliente_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void frmTarifa_Load(
	System::Object^ sender,
	System::EventArgs^ e)
{
	cargarTarifas();
	limpiarCampos();
}
private: System::Void btnLimpiar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	limpiarCampos();
}
private: System::Void btnRegistrar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	double valorHora;
	double valorFraccion15min;
	double descuentoMembresia;
	double penalizacionTicketPerdido;

	// Obtiene y valida los datos ingresados.
	if (!obtenerDatosTarifa(
		valorHora,
		valorFraccion15min,
		descuentoMembresia,
		penalizacionTicketPerdido))
	{
		return;
	}

	// Valida las reglas correspondientes a la tarifa.
	if (!tarifaController->validarTarifa(
		valorHora,
		valorFraccion15min,
		descuentoMembresia,
		penalizacionTicketPerdido))
	{
		MessageBox::Show(
			"Verifique los datos ingresados.\n\n"
			"• El valor por hora debe ser mayor que cero.\n"
			"• El valor de la fracción debe ser mayor que cero.\n"
			"• El descuento debe estar entre 0% y 100%.\n"
			"• La penalización no puede ser negativa.",
			"Datos no válidos",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		return;
	}

	// Registra la tarifa mediante el Controller.
	bool registrado = tarifaController->registrarTarifa(
		valorHora,
		valorFraccion15min,
		descuentoMembresia,
		penalizacionTicketPerdido
	);

	if (registrado)
	{
		MessageBox::Show(
			"Tarifa registrada correctamente.",
			"Registro exitoso",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);

		// Actualiza la tabla con el nuevo registro.
		cargarTarifas();

		// Limpia los campos y genera el siguiente ID.
		limpiarCampos();
	}
	else
	{
		MessageBox::Show(
			"No se pudo registrar la tarifa.",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
private: System::Void dgvTarifas_CellClick(
	System::Object^ sender,
	System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	// Verifica que se haya seleccionado una fila válida.
	if (e->RowIndex < 0)
	{
		return;
	}

	DataGridViewRow^ fila =
		dgvTarifas->Rows[e->RowIndex];

	// Carga los datos seleccionados en los cuadros de texto.
	txtIdTarifa->Text =
		fila->Cells["colIdTarifa"]->Value->ToString();

	txtValorHora->Text =
		fila->Cells["colValorHora"]->Value->ToString();

	txtValorFraccion->Text =
		fila->Cells["colValorFraccion"]->Value->ToString();

	txtDescuentoMembresia->Text =
		fila->Cells["colDescuento"]->Value->ToString();

	txtPenalizacionTicket->Text =
		fila->Cells["colPenalizacion"]->Value->ToString();
}
private: System::Void btnModificar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	// Verifica que exista una tarifa seleccionada.
	if (dgvTarifas->SelectedRows->Count == 0)
	{
		MessageBox::Show(
			"Debe seleccionar una tarifa para modificar.",
			"Tarifa no seleccionada",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		return;
	}

	int idTarifa;
	double valorHora;
	double valorFraccion15min;
	double descuentoMembresia;
	double penalizacionTicketPerdido;

	// Obtiene el ID de la tarifa seleccionada.
	if (!Int32::TryParse(txtIdTarifa->Text, idTarifa))
	{
		MessageBox::Show(
			"El ID de la tarifa no es válido.",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);

		return;
	}

	// Obtiene y valida los datos de los TextBox.
	if (!obtenerDatosTarifa(
		valorHora,
		valorFraccion15min,
		descuentoMembresia,
		penalizacionTicketPerdido))
	{
		return;
	}

	// Valida las reglas correspondientes a la tarifa.
	if (!tarifaController->validarTarifa(
		valorHora,
		valorFraccion15min,
		descuentoMembresia,
		penalizacionTicketPerdido))
	{
		MessageBox::Show(
			"Verifique los datos ingresados.\n\n"
			"• El valor por hora debe ser mayor que cero.\n"
			"• El valor de la fracción debe ser mayor que cero.\n"
			"• El descuento debe estar entre 0% y 100%.\n"
			"• La penalización no puede ser negativa.",
			"Datos no válidos",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		return;
	}

	// Solicita confirmación antes de modificar.
	System::Windows::Forms::DialogResult respuesta =
		MessageBox::Show(
			"¿Está seguro de modificar la tarifa seleccionada?",
			"Confirmar modificación",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

	if (respuesta != System::Windows::Forms::DialogResult::Yes)
	{
		return;
	}

	// Solicita la modificación al Controller.
	bool modificado = tarifaController->modificarTarifa(
		idTarifa,
		valorHora,
		valorFraccion15min,
		descuentoMembresia,
		penalizacionTicketPerdido
	);

	if (modificado)
	{
		MessageBox::Show(
			"Tarifa modificada correctamente.",
			"Modificación exitosa",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);

		// Actualiza la información mostrada.
		cargarTarifas();

		// Limpia los campos y prepara el siguiente ID.
		limpiarCampos();
	}
	else
	{
		MessageBox::Show(
			"No se pudo modificar la tarifa.",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
private: System::Void btnEliminar_Click(
	System::Object^ sender,
	System::EventArgs^ e)
{
	// Verifica que exista una tarifa seleccionada.
	if (dgvTarifas->SelectedRows->Count == 0)
	{
		MessageBox::Show(
			"Debe seleccionar una tarifa para eliminar.",
			"Tarifa no seleccionada",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning
		);

		return;
	}

	int idTarifa;

	// Obtiene el ID de la tarifa seleccionada.
	if (!Int32::TryParse(txtIdTarifa->Text, idTarifa))
	{
		MessageBox::Show(
			"El ID de la tarifa no es válido.",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);

		return;
	}

	// Solicita confirmación antes de eliminar.
	System::Windows::Forms::DialogResult respuesta =
		MessageBox::Show(
			"¿Está seguro de eliminar la tarifa seleccionada?\n\n"
			"Esta acción no se puede deshacer.",
			"Confirmar eliminación",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Warning
		);

	// Si el administrador selecciona No, no realiza cambios.
	if (respuesta != System::Windows::Forms::DialogResult::Yes)
	{
		return;
	}

	// Solicita la eliminación al Controller.
	bool eliminado =
		tarifaController->eliminarTarifa(idTarifa);

	if (eliminado)
	{
		MessageBox::Show(
			"Tarifa eliminada correctamente.",
			"Eliminación exitosa",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);

		// Actualiza los registros mostrados.
		cargarTarifas();

		// Limpia los campos y prepara el siguiente ID.
		limpiarCampos();
	}
	else
	{
		MessageBox::Show(
			"No se pudo eliminar la tarifa.",
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
	}
}
};
}
