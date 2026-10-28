#pragma once

#include "frmBalanceTurno.h"

using namespace SmartParkingSystemModel;
using namespace SmartParkingSystemController;

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmTurno
	/// </summary>
	public ref class frmTurno : public System::Windows::Forms::Form
	{

	private:
		bool seleccionarEmpleado()
		{
			// Si ya se identificó un empleado, no volver a pedirlo.
			if (empleadoAutenticado != nullptr)
				return true;

			EmpleadoController^ controller =
				gcnew EmpleadoController();

			List<Empleado^>^ empleados =
				controller->buscarTodosArchivo();

			if (empleados == nullptr || empleados->Count == 0)
			{
				MessageBox::Show(
					L"No hay empleados registrados.",
					L"Gestión de Turno",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return false;
			}

			Form^ ventana = gcnew Form();
			ventana->Text = L"Seleccionar empleado";
			ventana->Size = Drawing::Size(420, 200);
			ventana->StartPosition =
				FormStartPosition::CenterParent;
			ventana->FormBorderStyle =
				System::Windows::Forms::FormBorderStyle::FixedDialog;
			ventana->MaximizeBox = false;
			ventana->MinimizeBox = false;

			Label^ etiqueta = gcnew Label();
			etiqueta->Text = L"Seleccione el empleado responsable:";
			etiqueta->Location = Drawing::Point(20, 20);
			etiqueta->AutoSize = true;

			ComboBox^ combo = gcnew ComboBox();
			combo->Location = Drawing::Point(20, 50);
			combo->Width = 360;
			combo->DropDownStyle =
				ComboBoxStyle::DropDownList;

			// Mantener la misma posición en ambas listas.
			List<Empleado^>^ opciones =
				gcnew List<Empleado^>();

			for each (Empleado ^ empleado in empleados)
			{
				if (empleado == nullptr)
					continue;

				opciones->Add(empleado);

				combo->Items->Add(
					empleado->getCodigoEmpleado() +
					L" - " + empleado->getNombres() +
					L" " + empleado->getApellidos());
			}

			if (combo->Items->Count == 0)
				return false;

			combo->SelectedIndex = 0;

			Button^ aceptar = gcnew Button();
			aceptar->Text = L"Aceptar";
			aceptar->Location = Drawing::Point(95, 100);
			aceptar->DialogResult =
				System::Windows::Forms::DialogResult::OK;

			Button^ cancelar = gcnew Button();
			cancelar->Text = L"Cancelar";
			cancelar->Location = Drawing::Point(210, 100);
			cancelar->DialogResult =
				System::Windows::Forms::DialogResult::Cancel;

			ventana->Controls->Add(etiqueta);
			ventana->Controls->Add(combo);
			ventana->Controls->Add(aceptar);
			ventana->Controls->Add(cancelar);

			ventana->AcceptButton = aceptar;
			ventana->CancelButton = cancelar;

			if (ventana->ShowDialog(this) !=
				System::Windows::Forms::DialogResult::OK)
				return false;

			empleadoAutenticado =
				opciones[combo->SelectedIndex];

			return true;
		}

	private:
		TurnoCajaController^ turnoController;
		Empleado^ empleadoAutenticado;		

	private:
		void actualizarEstadoTurno()
		{
			TurnoCaja^ turno =
				turnoController->buscarTurnoAbierto();

			if (turno == nullptr)
			{
				textInfoCliente->Text =
					L"Gestión de Turno - Sin turno abierto";

				// Permitir seleccionar empleado al registrar inicio.
				Iniciobtn->Enabled = true;
				Salidabtn->Enabled = false;
			}
			else
			{
				textInfoCliente->Text =
					L"Gestión de Turno - Turno activo: " +
					turno->getIdTurno().ToString();

				Iniciobtn->Enabled = false;

				// Permitir recuperar y cerrar el turno existente.
				Salidabtn->Enabled = true;
			}
		}

	public:
		// Permite abrir el formulario sin recibir un empleado.
		frmTurno(void) : frmTurno(nullptr)
		{
		}

	public:
		frmTurno(Empleado^ empleado)
		{
			InitializeComponent();

			turnoController = gcnew TurnoCajaController();
			empleadoAutenticado = empleado;

			this->Text = L"Gestión de Turno";
			textInfoCliente->ReadOnly = true;

			try
			{
				// Recuperar el estado del turno existente.
				actualizarEstadoTurno();
			}
			catch (Exception^ ex)
			{
				// Mantener disponible el formulario.
				textInfoCliente->Text = L"Gestión de Turno";

				Iniciobtn->Enabled = false;
				Salidabtn->Enabled = false;

				MessageBox::Show(
					L"No se pudo recuperar el turno: " + ex->Message,
					L"Advertencia",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}			
		}

	private:
		bool solicitarSaldo(String^ titulo, double% saldo)
		{
			Form^ ventana = gcnew Form();
			ventana->Text = titulo;
			ventana->Size = Drawing::Size(370, 205);
			ventana->StartPosition = FormStartPosition::CenterParent;
			ventana->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			ventana->MaximizeBox = false;
			ventana->MinimizeBox = false;

			Label^ etiqueta = gcnew Label();
			etiqueta->Text = L"Ingrese el monto (S/):";
			etiqueta->Location = Drawing::Point(20, 20);
			etiqueta->AutoSize = true;

			NumericUpDown^ numero = gcnew NumericUpDown();
			numero->Location = Drawing::Point(20, 55);
			numero->Width = 310;
			numero->DecimalPlaces = 2;
			numero->Minimum = 0;
			numero->Maximum = 100000000;
			numero->ThousandsSeparator = true;

			Button^ aceptar = gcnew Button();
			aceptar->Text = L"Aceptar";
			aceptar->Location = Drawing::Point(75, 105);
			aceptar->DialogResult = System::Windows::Forms::DialogResult::OK;

			Button^ cancelar = gcnew Button();
			cancelar->Text = L"Cancelar";
			cancelar->Location = Drawing::Point(190, 105);
			cancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;

			ventana->Controls->Add(etiqueta);
			ventana->Controls->Add(numero);
			ventana->Controls->Add(aceptar);
			ventana->Controls->Add(cancelar);

			ventana->AcceptButton = aceptar;
			ventana->CancelButton = cancelar;

			if (ventana->ShowDialog(this) !=
				System::Windows::Forms::DialogResult::OK)
				return false;

			saldo = Decimal::ToDouble(numero->Value);
			return true;
		}

	private:
		bool solicitarObservacion(String^% observacion)
		{
			Form^ ventana = gcnew Form();
			ventana->Text = L"Observación del cierre";
			ventana->Size = Drawing::Size(440, 240);
			ventana->StartPosition = FormStartPosition::CenterParent;
			ventana->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			ventana->MaximizeBox = false;
			ventana->MinimizeBox = false;

			Label^ etiqueta = gcnew Label();
			etiqueta->Text = L"Observación (opcional):";
			etiqueta->Location = Drawing::Point(20, 15);
			etiqueta->AutoSize = true;

			TextBox^ entrada = gcnew TextBox();
			entrada->Location = Drawing::Point(20, 45);
			entrada->Size = Drawing::Size(380, 85);
			entrada->Multiline = true;
			entrada->MaxLength = 250;

			Button^ aceptar = gcnew Button();
			aceptar->Text = L"Aceptar";
			aceptar->Location = Drawing::Point(95, 145);
			aceptar->DialogResult = System::Windows::Forms::DialogResult::OK;

			Button^ cancelar = gcnew Button();
			cancelar->Text = L"Cancelar";
			cancelar->Location = Drawing::Point(215, 145);
			cancelar->DialogResult = System::Windows::Forms::DialogResult::Cancel;

			ventana->Controls->Add(etiqueta);
			ventana->Controls->Add(entrada);
			ventana->Controls->Add(aceptar);
			ventana->Controls->Add(cancelar);

			ventana->AcceptButton = aceptar;
			ventana->CancelButton = cancelar;

			if (ventana->ShowDialog(this) !=
				System::Windows::Forms::DialogResult::OK)
				return false;

			observacion = entrada->Text->Trim();

			if (observacion->Contains("|"))
			{
				MessageBox::Show(
					L"La observación no puede contener el carácter |.",
					L"Dato no válido",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
				return false;
			}

			return true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmTurno()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:













	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::TextBox^ textInfoCliente;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ Balanceturnobtn;

	private: System::Windows::Forms::Button^ Salidabtn;
	private: System::Windows::Forms::Button^ Iniciobtn;















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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Balanceturnobtn = (gcnew System::Windows::Forms::Button());
			this->Salidabtn = (gcnew System::Windows::Forms::Button());
			this->Iniciobtn = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textInfoCliente = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 85);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1270, 677);
			this->panel2->TabIndex = 19;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->groupBox1->Controls->Add(this->Balanceturnobtn);
			this->groupBox1->Controls->Add(this->Salidabtn);
			this->groupBox1->Controls->Add(this->Iniciobtn);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Arial", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(127, 75);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox1->Size = System::Drawing::Size(996, 535);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Hora Actual:";
			// 
			// Balanceturnobtn
			// 
			this->Balanceturnobtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Balanceturnobtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->Balanceturnobtn->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Balanceturnobtn->ForeColor = System::Drawing::Color::White;
			this->Balanceturnobtn->Location = System::Drawing::Point(338, 372);
			this->Balanceturnobtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Balanceturnobtn->Name = L"Balanceturnobtn";
			this->Balanceturnobtn->Size = System::Drawing::Size(274, 66);
			this->Balanceturnobtn->TabIndex = 70;
			this->Balanceturnobtn->Text = L"Balance Turno";
			this->Balanceturnobtn->UseVisualStyleBackColor = false;
			this->Balanceturnobtn->Click += gcnew System::EventHandler(this, &frmTurno::Balanceturnobtn_Click);
			// 
			// Salidabtn
			// 
			this->Salidabtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Salidabtn->BackColor = System::Drawing::Color::Firebrick;
			this->Salidabtn->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Salidabtn->ForeColor = System::Drawing::Color::White;
			this->Salidabtn->Location = System::Drawing::Point(541, 245);
			this->Salidabtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Salidabtn->Name = L"Salidabtn";
			this->Salidabtn->Size = System::Drawing::Size(274, 66);
			this->Salidabtn->TabIndex = 69;
			this->Salidabtn->Text = L"Registrar Salida";
			this->Salidabtn->UseVisualStyleBackColor = false;
			this->Salidabtn->Click += gcnew System::EventHandler(this, &frmTurno::Salidabtn_Click);
			// 
			// Iniciobtn
			// 
			this->Iniciobtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Iniciobtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Iniciobtn->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Iniciobtn->ForeColor = System::Drawing::Color::White;
			this->Iniciobtn->Location = System::Drawing::Point(163, 245);
			this->Iniciobtn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Iniciobtn->Name = L"Iniciobtn";
			this->Iniciobtn->Size = System::Drawing::Size(274, 66);
			this->Iniciobtn->TabIndex = 12;
			this->Iniciobtn->Text = L"Registrar Inicio";
			this->Iniciobtn->UseVisualStyleBackColor = false;
			this->Iniciobtn->Click += gcnew System::EventHandler(this, &frmTurno::Iniciobtn_Click);
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Black", 40.25F, System::Drawing::FontStyle::Bold));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label8->Location = System::Drawing::Point(224, 69);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(538, 114);
			this->label8->TabIndex = 68;
			this->label8->Text = L"3:00.00 AM";
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
			this->textInfoCliente->Size = System::Drawing::Size(811, 46);
			this->textInfoCliente->TabIndex = 0;
			this->textInfoCliente->Text = L"Gestion de Turno";
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
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Brown;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(487, 29);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(249, 48);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmTurno::button1_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 762);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1270, 99);
			this->panel3->TabIndex = 20;
			// 
			// frmTurno
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 861);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmTurno";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"frmTurno";
			this->panel2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { //Regresar
		this->DialogResult =
			System::Windows::Forms::DialogResult::Cancel;

		this->Close();
	}

	private: System::Void Iniciobtn_Click(System::Object^ sender, System::EventArgs^ e) { //Registrar Inicio
		try
		{
			if (!seleccionarEmpleado())
				return;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(
				L"No se pudo seleccionar al empleado: " + ex->Message,
				L"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
			return;
		}

		try
		{
			if (turnoController->buscarTurnoAbierto() != nullptr)
			{
				MessageBox::Show(
					L"Ya existe un turno abierto. Debe cerrarlo "
					L"antes de iniciar uno nuevo.",
					L"Turno activo",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);

				actualizarEstadoTurno();
				return;
			}

			double saldoInicial = 0.0;

			if (!solicitarSaldo(
				L"Iniciar turno - Saldo inicial",
				saldoInicial))
				return;

			bool registrado = turnoController->iniciarTurno(
				empleadoAutenticado,
				saldoInicial);

			if (!registrado)
			{
				MessageBox::Show(
					L"No se pudo iniciar el turno. "
					L"Verifique el empleado y el saldo inicial.",
					L"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}

			MessageBox::Show(
				L"Turno iniciado correctamente.",
				L"Registro exitoso",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);

			actualizarEstadoTurno();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(
				L"Error al iniciar el turno: " + ex->Message,
				L"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}

	private: System::Void Salidabtn_Click(System::Object^ sender, System::EventArgs^ e) { //Registrar Salida
		/*
		if (empleadoAutenticado == nullptr)
		{
			MessageBox::Show(
				L"No se ha identificado al empleado autenticado.",
				L"Acceso no autorizado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning);
			return;
		}
		*/
		try
		{
			TurnoCaja^ turno =
				turnoController->buscarTurnoAbierto();

			if (turno == nullptr)
			{
				MessageBox::Show(
					L"No existe un turno abierto para cerrar.",
					L"Sin turno activo",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);

				actualizarEstadoTurno();
				return;
			}

			// Recuperar al empleado responsable del turno abierto.
			if (turno->getEmpleado() == nullptr)
			{
				MessageBox::Show(
					L"El turno abierto no tiene un empleado asociado.",
					L"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}

			empleadoAutenticado = turno->getEmpleado();

			double saldoFinal = 0.0;
			String^ observacion = String::Empty;

			if (!solicitarSaldo(
				L"Cerrar turno - Saldo final",
				saldoFinal))
				return;

			if (!solicitarObservacion(observacion))
				return;

			auto respuesta = MessageBox::Show(
				L"¿Confirma el cierre del turno actual?",
				L"Confirmar cierre",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question);

			if (respuesta !=
				System::Windows::Forms::DialogResult::Yes)
				return;

			bool cerrado = turnoController->cerrarTurno(
				empleadoAutenticado->getCodigoEmpleado(),
				saldoFinal,
				observacion);

			if (!cerrado)
			{
				MessageBox::Show(
					L"No se pudo cerrar el turno. "
					L"Verifique que pertenezca al empleado autenticado.",
					L"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				return;
			}

			MessageBox::Show(
				L"Turno cerrado correctamente.",
				L"Cierre exitoso",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);

			actualizarEstadoTurno();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(
				L"Error al cerrar el turno: " + ex->Message,
				L"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}

	private: System::Void Balanceturnobtn_Click(System::Object^ sender, System::EventArgs^ e) { //Balance Turno
		try
		{
			frmBalanceTurno^ ventana =
				gcnew frmBalanceTurno();

			ventana->ShowDialog(this);

			actualizarEstadoTurno();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(
				L"No se pudo consultar el balance: " + ex->Message,
				L"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}	
};
}
