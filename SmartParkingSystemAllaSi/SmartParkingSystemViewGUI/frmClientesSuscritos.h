#pragma once

#include "frmGestionSuscripcion.h"

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
	/// Resumen de frmClientesSuscritos
	/// </summary>
	public ref class frmClientesSuscritos : public System::Windows::Forms::Form
	{
	private:
		SmartParkingSystemController::MembresiaController^ membresiaController;

		// Muestra en el DataGridView las membresías de una lista determinada.
	private:
		void mostrarMembresias(List<Membresia^>^ membresias)
		{
			// Limpia los registros mostrados anteriormente.
			dgvClientesSuscritos->Rows->Clear();

			for each (Membresia ^ membresia in membresias)
			{
				// Busca el cliente relacionado con la membresía.
				Cliente^ cliente =
					membresiaController->buscarClientePorId(
						membresia->getIdCliente()
					);

				// Si no encuentra al cliente, omite el registro.
				if (cliente == nullptr)
				{
					continue;
				}

				String^ nombreCompleto =
					cliente->getNombres() + " " +
					cliente->getApellidos();

				String^ estado =
					membresiaController->obtenerEstadoMembresia(
						membresia
					);

				// Muestra la información de la suscripción.
				dgvClientesSuscritos->Rows->Add(
					membresia->getIdMembresia(),
					nombreCompleto,
					cliente->getDocumento(),
					membresia->getTipo().ToString(),
					membresia->getFechaInicio().ToString("dd/MM/yyyy"),
					membresia->getFechaFin().ToString("dd/MM/yyyy"),
					estado
				);
			}

			// Evita que quede seleccionada automáticamente la primera fila.
			dgvClientesSuscritos->ClearSelection();
		}

		// Carga todas las suscripciones registradas.
	private:
		void cargarClientesSuscritos()
		{
			List<Membresia^>^ membresias =
				membresiaController->listarMembresias();

			mostrarMembresias(membresias);
		}

	public:
		frmClientesSuscritos(void)
		{
			InitializeComponent();

			// Inicializa el controlador de membresías.
			membresiaController =
				gcnew SmartParkingSystemController::MembresiaController();

			// Carga las suscripciones registradas.
			cargarClientesSuscritos();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmClientesSuscritos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnlInfo;
	private: System::Windows::Forms::GroupBox^ gbBusqueda;
	protected:

	private: System::Windows::Forms::DataGridView^ dgvClientesSuscritos;




















	private: System::Windows::Forms::Panel^ pnlTitulo;
	private: System::Windows::Forms::Label^ lblTitulo;
	private: System::Windows::Forms::Label^ lblBuscar;
	private: System::Windows::Forms::Button^ btnCancelarSuscripcion;











	private: System::Windows::Forms::Button^ btnEditarSuscripcion;

	private: System::Windows::Forms::Button^ btnNuevaSuscripcion;

	private: System::Windows::Forms::Button^ btnMostrarTodos;

	private: System::Windows::Forms::Button^ btnBuscar;

	private: System::Windows::Forms::TextBox^ txtBuscar;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colIdMembresia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCliente;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colDocumento;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipoMembresia;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFechaInicio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colFechaFin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;









	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->pnlInfo = (gcnew System::Windows::Forms::Panel());
			this->gbBusqueda = (gcnew System::Windows::Forms::GroupBox());
			this->btnCancelarSuscripcion = (gcnew System::Windows::Forms::Button());
			this->btnEditarSuscripcion = (gcnew System::Windows::Forms::Button());
			this->btnNuevaSuscripcion = (gcnew System::Windows::Forms::Button());
			this->btnMostrarTodos = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtBuscar = (gcnew System::Windows::Forms::TextBox());
			this->dgvClientesSuscritos = (gcnew System::Windows::Forms::DataGridView());
			this->colIdMembresia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCliente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDocumento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipoMembresia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFechaInicio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFechaFin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lblBuscar = (gcnew System::Windows::Forms::Label());
			this->pnlTitulo = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->pnlInfo->SuspendLayout();
			this->gbBusqueda->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientesSuscritos))->BeginInit();
			this->pnlTitulo->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlInfo
			// 
			this->pnlInfo->BackColor = System::Drawing::Color::White;
			this->pnlInfo->Controls->Add(this->gbBusqueda);
			this->pnlInfo->Controls->Add(this->pnlTitulo);
			this->pnlInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlInfo->Location = System::Drawing::Point(0, 0);
			this->pnlInfo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pnlInfo->Name = L"pnlInfo";
			this->pnlInfo->Size = System::Drawing::Size(1126, 548);
			this->pnlInfo->TabIndex = 15;
			// 
			// gbBusqueda
			// 
			this->gbBusqueda->BackColor = System::Drawing::SystemColors::Control;
			this->gbBusqueda->Controls->Add(this->btnCancelarSuscripcion);
			this->gbBusqueda->Controls->Add(this->btnEditarSuscripcion);
			this->gbBusqueda->Controls->Add(this->btnNuevaSuscripcion);
			this->gbBusqueda->Controls->Add(this->btnMostrarTodos);
			this->gbBusqueda->Controls->Add(this->btnBuscar);
			this->gbBusqueda->Controls->Add(this->txtBuscar);
			this->gbBusqueda->Controls->Add(this->dgvClientesSuscritos);
			this->gbBusqueda->Controls->Add(this->lblBuscar);
			this->gbBusqueda->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gbBusqueda->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbBusqueda->Location = System::Drawing::Point(0, 65);
			this->gbBusqueda->Name = L"gbBusqueda";
			this->gbBusqueda->Size = System::Drawing::Size(1126, 483);
			this->gbBusqueda->TabIndex = 57;
			this->gbBusqueda->TabStop = false;
			this->gbBusqueda->Text = L"Buscar cliente";
			// 
			// btnCancelarSuscripcion
			// 
			this->btnCancelarSuscripcion->AutoSize = true;
			this->btnCancelarSuscripcion->BackColor = System::Drawing::Color::Red;
			this->btnCancelarSuscripcion->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelarSuscripcion->ForeColor = System::Drawing::Color::White;
			this->btnCancelarSuscripcion->Location = System::Drawing::Point(730, 400);
			this->btnCancelarSuscripcion->Margin = System::Windows::Forms::Padding(4);
			this->btnCancelarSuscripcion->Name = L"btnCancelarSuscripcion";
			this->btnCancelarSuscripcion->Size = System::Drawing::Size(310, 53);
			this->btnCancelarSuscripcion->TabIndex = 82;
			this->btnCancelarSuscripcion->Text = L"Cancelar suscripción";
			this->btnCancelarSuscripcion->UseVisualStyleBackColor = false;
			this->btnCancelarSuscripcion->Click += gcnew System::EventHandler(this, &frmClientesSuscritos::btnCancelarSuscripcion_Click);
			// 
			// btnEditarSuscripcion
			// 
			this->btnEditarSuscripcion->AutoSize = true;
			this->btnEditarSuscripcion->BackColor = System::Drawing::Color::DarkOrange;
			this->btnEditarSuscripcion->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditarSuscripcion->ForeColor = System::Drawing::Color::White;
			this->btnEditarSuscripcion->Location = System::Drawing::Point(412, 400);
			this->btnEditarSuscripcion->Margin = System::Windows::Forms::Padding(4);
			this->btnEditarSuscripcion->Name = L"btnEditarSuscripcion";
			this->btnEditarSuscripcion->Size = System::Drawing::Size(270, 53);
			this->btnEditarSuscripcion->TabIndex = 81;
			this->btnEditarSuscripcion->Text = L"Editar suscripción";
			this->btnEditarSuscripcion->UseVisualStyleBackColor = false;
			this->btnEditarSuscripcion->Click += gcnew System::EventHandler(this, &frmClientesSuscritos::btnEditarSuscripcion_Click);
			// 
			// btnNuevaSuscripcion
			// 
			this->btnNuevaSuscripcion->AutoSize = true;
			this->btnNuevaSuscripcion->BackColor = System::Drawing::Color::ForestGreen;
			this->btnNuevaSuscripcion->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevaSuscripcion->ForeColor = System::Drawing::Color::White;
			this->btnNuevaSuscripcion->Location = System::Drawing::Point(88, 400);
			this->btnNuevaSuscripcion->Margin = System::Windows::Forms::Padding(4);
			this->btnNuevaSuscripcion->Name = L"btnNuevaSuscripcion";
			this->btnNuevaSuscripcion->Size = System::Drawing::Size(274, 53);
			this->btnNuevaSuscripcion->TabIndex = 80;
			this->btnNuevaSuscripcion->Text = L"Nueva suscripción";
			this->btnNuevaSuscripcion->UseVisualStyleBackColor = false;
			this->btnNuevaSuscripcion->Click += gcnew System::EventHandler(this, &frmClientesSuscritos::btnNuevaSuscripcion_Click);
			// 
			// btnMostrarTodos
			// 
			this->btnMostrarTodos->AutoSize = true;
			this->btnMostrarTodos->BackColor = System::Drawing::Color::Blue;
			this->btnMostrarTodos->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMostrarTodos->ForeColor = System::Drawing::Color::White;
			this->btnMostrarTodos->Location = System::Drawing::Point(874, 40);
			this->btnMostrarTodos->Margin = System::Windows::Forms::Padding(4);
			this->btnMostrarTodos->Name = L"btnMostrarTodos";
			this->btnMostrarTodos->Size = System::Drawing::Size(212, 53);
			this->btnMostrarTodos->TabIndex = 79;
			this->btnMostrarTodos->Text = L"Mostrar todos";
			this->btnMostrarTodos->UseVisualStyleBackColor = false;
			this->btnMostrarTodos->Click += gcnew System::EventHandler(this, &frmClientesSuscritos::btnMostrarTodos_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->AutoSize = true;
			this->btnBuscar->BackColor = System::Drawing::Color::Gray;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::Color::White;
			this->btnBuscar->Location = System::Drawing::Point(727, 40);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(119, 53);
			this->btnBuscar->TabIndex = 78;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmClientesSuscritos::btnBuscar_Click);
			// 
			// txtBuscar
			// 
			this->txtBuscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBuscar->Location = System::Drawing::Point(491, 44);
			this->txtBuscar->Margin = System::Windows::Forms::Padding(4);
			this->txtBuscar->Name = L"txtBuscar";
			this->txtBuscar->Size = System::Drawing::Size(206, 42);
			this->txtBuscar->TabIndex = 77;
			// 
			// dgvClientesSuscritos
			// 
			this->dgvClientesSuscritos->AllowUserToAddRows = false;
			this->dgvClientesSuscritos->AllowUserToDeleteRows = false;
			this->dgvClientesSuscritos->AllowUserToResizeRows = false;
			this->dgvClientesSuscritos->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvClientesSuscritos->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvClientesSuscritos->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvClientesSuscritos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvClientesSuscritos->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->colIdMembresia,
					this->colCliente, this->colDocumento, this->colTipoMembresia, this->colFechaInicio, this->colFechaFin, this->colEstado
			});
			this->dgvClientesSuscritos->EnableHeadersVisualStyles = false;
			this->dgvClientesSuscritos->Location = System::Drawing::Point(41, 121);
			this->dgvClientesSuscritos->Margin = System::Windows::Forms::Padding(4);
			this->dgvClientesSuscritos->MultiSelect = false;
			this->dgvClientesSuscritos->Name = L"dgvClientesSuscritos";
			this->dgvClientesSuscritos->ReadOnly = true;
			this->dgvClientesSuscritos->RowHeadersVisible = false;
			this->dgvClientesSuscritos->RowHeadersWidth = 51;
			this->dgvClientesSuscritos->RowTemplate->Height = 24;
			this->dgvClientesSuscritos->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvClientesSuscritos->Size = System::Drawing::Size(1045, 250);
			this->dgvClientesSuscritos->TabIndex = 76;
			// 
			// colIdMembresia
			// 
			this->colIdMembresia->FillWeight = 40.10694F;
			this->colIdMembresia->HeaderText = L"ID";
			this->colIdMembresia->MinimumWidth = 6;
			this->colIdMembresia->Name = L"colIdMembresia";
			this->colIdMembresia->ReadOnly = true;
			// 
			// colCliente
			// 
			this->colCliente->FillWeight = 114.9732F;
			this->colCliente->HeaderText = L"Cliente";
			this->colCliente->MinimumWidth = 6;
			this->colCliente->Name = L"colCliente";
			this->colCliente->ReadOnly = true;
			// 
			// colDocumento
			// 
			this->colDocumento->FillWeight = 114.9732F;
			this->colDocumento->HeaderText = L"Documento";
			this->colDocumento->MinimumWidth = 6;
			this->colDocumento->Name = L"colDocumento";
			this->colDocumento->ReadOnly = true;
			// 
			// colTipoMembresia
			// 
			this->colTipoMembresia->FillWeight = 114.9732F;
			this->colTipoMembresia->HeaderText = L"Membresía";
			this->colTipoMembresia->MinimumWidth = 6;
			this->colTipoMembresia->Name = L"colTipoMembresia";
			this->colTipoMembresia->ReadOnly = true;
			// 
			// colFechaInicio
			// 
			this->colFechaInicio->FillWeight = 114.9732F;
			this->colFechaInicio->HeaderText = L"Inicio";
			this->colFechaInicio->MinimumWidth = 6;
			this->colFechaInicio->Name = L"colFechaInicio";
			this->colFechaInicio->ReadOnly = true;
			// 
			// colFechaFin
			// 
			this->colFechaFin->HeaderText = L"Fin";
			this->colFechaFin->MinimumWidth = 6;
			this->colFechaFin->Name = L"colFechaFin";
			this->colFechaFin->ReadOnly = true;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// lblBuscar
			// 
			this->lblBuscar->AutoSize = true;
			this->lblBuscar->BackColor = System::Drawing::SystemColors::Control;
			this->lblBuscar->Font = (gcnew System::Drawing::Font(L"Gadugi", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBuscar->Location = System::Drawing::Point(35, 49);
			this->lblBuscar->Name = L"lblBuscar";
			this->lblBuscar->Size = System::Drawing::Size(435, 34);
			this->lblBuscar->TabIndex = 61;
			this->lblBuscar->Text = L"Nombre, apellido o documento:";
			// 
			// pnlTitulo
			// 
			this->pnlTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->pnlTitulo->Controls->Add(this->lblTitulo);
			this->pnlTitulo->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitulo->Location = System::Drawing::Point(0, 0);
			this->pnlTitulo->Name = L"pnlTitulo";
			this->pnlTitulo->Size = System::Drawing::Size(1126, 65);
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
			this->lblTitulo->Size = System::Drawing::Size(289, 40);
			this->lblTitulo->TabIndex = 57;
			this->lblTitulo->Text = L"Clientes Suscritos";
			this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// frmClientesSuscritos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1126, 548);
			this->Controls->Add(this->pnlInfo);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"frmClientesSuscritos";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Clientes Suscritos";
			this->Load += gcnew System::EventHandler(this, &frmClientesSuscritos::frmClientesSuscritos_Load);
			this->pnlInfo->ResumeLayout(false);
			this->gbBusqueda->ResumeLayout(false);
			this->gbBusqueda->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvClientesSuscritos))->EndInit();
			this->pnlTitulo->ResumeLayout(false);
			this->pnlTitulo->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmClientesSuscritos_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Obtiene el criterio escrito por el administrador.
		String^ criterio =
			txtBuscar->Text->Trim()->ToLower();

		// Si no se escribió nada, muestra todos los registros.
		if (String::IsNullOrWhiteSpace(criterio))
		{
			cargarClientesSuscritos();
			return;
		}

		// Obtiene todos los clientes registrados.
		List<Cliente^>^ clientes =
			membresiaController->listarClientes();

		// Lista donde se reunirán las membresías encontradas.
		List<Membresia^>^ membresiasEncontradas =
			gcnew List<Membresia^>();

		// Recorre los clientes registrados.
		for each (Cliente ^ cliente in clientes)
		{
			bool coincideCliente = false;
			bool coincideDocumento = false;

			String^ nombres =
				cliente->getNombres()->ToLower();

			String^ apellidos =
				cliente->getApellidos()->ToLower();

			String^ documento =
				cliente->getDocumento()->ToLower();

			// Separa nombres y apellidos para comprobar cada palabra.
			array<String^>^ palabrasNombres =
				nombres->Split(' ');

			array<String^>^ palabrasApellidos =
				apellidos->Split(' ');

			// Comprueba los nombres desde sus caracteres iniciales.
			for each (String ^ nombre in palabrasNombres)
			{
				if (nombre->StartsWith(criterio))
				{
					coincideCliente = true;
					break;
				}
			}

			// Si todavía no existe coincidencia,
			// comprueba también los apellidos.
			if (!coincideCliente)
			{
				for each (String ^ apellido in palabrasApellidos)
				{
					if (apellido->StartsWith(criterio))
					{
						coincideCliente = true;
						break;
					}
				}
			}

			// El documento admite coincidencias parciales
			// únicamente desde sus primeros dígitos.
			coincideDocumento =
				documento->StartsWith(criterio);

			// Si coincide el cliente, obtiene todas
			// las suscripciones de dicho cliente.
			if (coincideCliente || coincideDocumento)
			{
				List<Membresia^>^ membresiasCliente =
					membresiaController->listarMembresiasPorCliente(
						cliente->getIdPersona()
					);

				for each (Membresia ^ membresia in membresiasCliente)
				{
					membresiasEncontradas->Add(membresia);
				}
			}
		}

		// Muestra únicamente las coincidencias.
		mostrarMembresias(membresiasEncontradas);

		// Informa cuando no existen resultados.
		if (membresiasEncontradas->Count == 0)
		{
			MessageBox::Show(
				"No se encontraron clientes suscritos con el criterio ingresado.",
				"Resultados de búsqueda",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}
	}
	private: System::Void btnMostrarTodos_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Limpia el criterio de búsqueda.
		txtBuscar->Clear();

		// Vuelve a mostrar todas las suscripciones.
		cargarClientesSuscritos();

		// Devuelve el cursor al cuadro de búsqueda.
		txtBuscar->Focus();
	}
	private: System::Void btnNuevaSuscripcion_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Crea el formulario para registrar una nueva suscripción.
		frmGestionSuscripcion^ formulario =
			gcnew frmGestionSuscripcion();

		// Abre el formulario como ventana modal.
		System::Windows::Forms::DialogResult resultado =
			formulario->ShowDialog();

		// Si se registró correctamente,
		// actualiza inmediatamente el DataGridView.
		if (resultado ==
			System::Windows::Forms::DialogResult::OK)
		{
			cargarClientesSuscritos();
		}
	}
	private: System::Void btnEditarSuscripcion_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Verifica que el administrador haya seleccionado
		// una suscripción del DataGridView.
		if (dgvClientesSuscritos->SelectedRows->Count == 0)
		{
			MessageBox::Show(
				"Debe seleccionar una suscripción para editar.",
				"Editar suscripción",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			return;
		}

		// Obtiene el ID de la membresía seleccionada.
		// La columna 0 corresponde al ID.
		int idMembresia =
			Convert::ToInt32(
				dgvClientesSuscritos
				->SelectedRows[0]
				->Cells[0]
				->Value
			);

		// Recupera la membresía seleccionada.
		Membresia^ membresia =
			membresiaController->buscarMembresiaPorId(
				idMembresia
			);

		// Verifica que la membresía exista.
		if (membresia == nullptr)
		{
			MessageBox::Show(
				"No se encontró la suscripción seleccionada.",
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);

			return;
		}

		// Una suscripción cancelada forma parte del historial
		// y ya no puede volver a modificarse.
		if (!membresia->getActivo())
		{
			MessageBox::Show(
				"La suscripción seleccionada ya se encuentra cancelada y no puede modificarse.",
				"Suscripción cancelada",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			return;
		}

		// Abre el formulario en modo edición.
		frmGestionSuscripcion^ formulario =
			gcnew frmGestionSuscripcion(idMembresia);

		// Muestra el formulario como ventana modal.
		System::Windows::Forms::DialogResult resultado =
			formulario->ShowDialog();

		// Si la modificación fue correcta,
		// actualiza nuevamente el DataGridView.
		if (resultado ==
			System::Windows::Forms::DialogResult::OK)
		{
			cargarClientesSuscritos();
		}
	}
	private: System::Void btnCancelarSuscripcion_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Verifica que el administrador haya seleccionado
		// una suscripción del DataGridView.
		if (dgvClientesSuscritos->SelectedRows->Count == 0)
		{
			MessageBox::Show(
				"Debe seleccionar una suscripción para cancelar.",
				"Cancelar suscripción",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			return;
		}

		// Obtiene el ID de la membresía seleccionada.
		int idMembresia =
			Convert::ToInt32(
				dgvClientesSuscritos
				->SelectedRows[0]
				->Cells[0]
				->Value
			);

		// Recupera la membresía seleccionada.
		Membresia^ membresia =
			membresiaController->buscarMembresiaPorId(
				idMembresia
			);

		// Verifica que la membresía exista.
		if (membresia == nullptr)
		{
			MessageBox::Show(
				"No se encontró la suscripción seleccionada.",
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);

			return;
		}

		// Evita cancelar nuevamente una suscripción inactiva.
		if (!membresia->getActivo())
		{
			MessageBox::Show(
				"La suscripción seleccionada ya se encuentra cancelada.",
				"Suscripción cancelada",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			return;
		}

		// Solicita confirmación antes de cancelar.
		System::Windows::Forms::DialogResult respuesta =
			MessageBox::Show(
				"¿Está seguro de que desea cancelar la suscripción seleccionada?",
				"Confirmar cancelación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);

		// Si el administrador elige No,
		// no se realiza ninguna modificación.
		if (respuesta !=
			System::Windows::Forms::DialogResult::Yes)
		{
			return;
		}

		// Cancela la membresía sin eliminarla del historial.
		bool cancelada =
			membresiaController->cancelarMembresia(
				idMembresia
			);

		if (cancelada)
		{
			MessageBox::Show(
				"La suscripción fue cancelada correctamente.",
				"Operación exitosa",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			// Actualiza la información mostrada.
			cargarClientesSuscritos();
		}
		else
		{
			MessageBox::Show(
				"No se pudo cancelar la suscripción.",
				"Error del sistema",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}
	};
}
