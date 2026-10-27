#pragma once

namespace SmartParkingSystemViewGUI {

	using namespace System;
	using namespace SmartParkingSystemController;
	using namespace SmartParkingSystemModel;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for frmMapaAdmin
	/// </summary>
	public ref class frmMapaAdmin : public System::Windows::Forms::Form
	{
	public:
		frmMapaAdmin(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// Inicializar el nuevo controlador y obtener la lista de espacios
			controlador = gcnew EspacioEstacionamientoController();
			listaEspacios = controlador->ObtenerEspacios();

			imgPiso1 = Image::FromFile("Piso1.png");
			imgPiso2 = Image::FromFile("Piso2.png");
			imgPiso3 = Image::FromFile("Piso3.png");
			imgAuto = Image::FromFile("autos.png");

			// Llenar el ComboBox programáticamente
			cmbPisos->Items->Clear();
			cmbPisos->Items->Add("Piso 1");
			cmbPisos->Items->Add("Piso 2");
			cmbPisos->Items->Add("Piso 3");
			cmbPisos->SelectedIndex = 0; // Esto seleccionará "Piso 1" y mostrará el texto

			// Estado inicial
			imgFondo = imgPiso1;
			if (cmbPisos->Items->Count > 0) {
				cmbPisos->SelectedIndex = 0; // Selecciona "Piso 1"
			}

			// Activar Double Buffering para evitar parpadeos al repintar
			//this->SetStyle(ControlStyles::OptimizedDoubleBuffer |
			//	ControlStyles::AllPaintingInWmPaint |
			//	ControlStyles::UserPaint, true);

			// ACTIVAR DOUBLE BUFFERING ESPECÍFICAMENTE EN EL PANEL
			System::Reflection::PropertyInfo^ prop = panel1->GetType()->GetProperty(
				"DoubleBuffered",
				System::Reflection::BindingFlags::Instance | System::Reflection::BindingFlags::NonPublic
			);
			prop->SetValue(panel1, true, nullptr);

			panel1->Invalidate();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMapaAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		EspacioEstacionamientoController^ controlador;
		List<EspacioEstacionamiento^>^ listaEspacios;
		int pisoActual = 1;
		Image^ imgFondo;
		Image^ imgPiso1;
		Image^ imgPiso2;
		Image^ imgPiso3;
		Image^ imgAuto;
	private: System::Windows::Forms::Panel^ pnlSuperior;
	private: System::Windows::Forms::ComboBox^ cmbPisos;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pnlSuperior = (gcnew System::Windows::Forms::Panel());
			this->cmbPisos = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->pnlSuperior->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pnlSuperior);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1049, 650);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMapaAdmin::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMapaAdmin::panel1_MouseClick);
			// 
			// pnlSuperior
			// 
			this->pnlSuperior->Controls->Add(this->cmbPisos);
			this->pnlSuperior->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlSuperior->Location = System::Drawing::Point(0, 0);
			this->pnlSuperior->Name = L"pnlSuperior";
			this->pnlSuperior->Size = System::Drawing::Size(1049, 40);
			this->pnlSuperior->TabIndex = 0;
			// 
			// cmbPisos
			// 
			this->cmbPisos->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPisos->FormattingEnabled = true;
			this->cmbPisos->Location = System::Drawing::Point(725, 3);
			this->cmbPisos->Name = L"cmbPisos";
			this->cmbPisos->Size = System::Drawing::Size(121, 28);
			this->cmbPisos->TabIndex = 0;
			this->cmbPisos->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMapaAdmin::cmbPisos_SelectedIndexChanged);
			// 
			// frmMapaAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1049, 650);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmMapaAdmin";
			this->Text = L"frmMapaAdmin";
			this->panel1->ResumeLayout(false);
			this->pnlSuperior->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->InterpolationMode = InterpolationMode::NearestNeighbor;

		// 1. Calcular el margen sobrante para centrar la imagen nativa (1024x576) en el panel
		int offsetX = (panel1->Width - imgFondo->Width) / 2;
		int offsetY = (panel1->Height - imgFondo->Height) / 2;
		if (offsetX < 0) offsetX = 0;
		if (offsetY < 0) offsetY = 0;

		// 2. Mover el origen de dibujo (0,0) a la esquina superior izquierda de la imagen centrada
		g->TranslateTransform((float)offsetX, (float)offsetY);

		// 3. Dibujar el mapa en su tamaño nativo 1:1
		g->DrawImage(imgFondo, 0, 0, imgFondo->Width, imgFondo->Height);

		// 4. Medidas de los sprites
		int anchoAuto = imgAuto->Width / 2;
		int altoAuto = imgAuto->Height / 3;

		Rectangle autoAzulD = Rectangle(0, 0, anchoAuto, altoAuto);
		Rectangle autoAzulI = Rectangle(anchoAuto, 0, anchoAuto, altoAuto);
		Rectangle autoRojoD = Rectangle(0, altoAuto, anchoAuto, altoAuto);
		Rectangle autoRojoI = Rectangle(anchoAuto, altoAuto, anchoAuto, altoAuto);
		Rectangle autoVerdeD = Rectangle(0, altoAuto * 2, anchoAuto, altoAuto);
		Rectangle autoVerdeI = Rectangle(anchoAuto, altoAuto * 2, anchoAuto, altoAuto);

		// 5. Dibujar los vehículos sobre las coordenadas nativas
		for (int i = 0; i < listaEspacios->Count; i++) {
			EspacioEstacionamiento^ espacio = listaEspacios[i];
			int id = espacio->getIdEspacio();
			int pisoDelEspacio = ((id - 1) / 30) + 1; // 1-30=Piso1, 31-60=Piso2, 61-90=Piso3

			// SOLO dibujar si el espacio pertenece al piso seleccionado y está ocupado
			if (pisoDelEspacio == pisoActual && espacio->getEstaOcupado()) {
				Rectangle areaDestino = espacio->getArea();

				// Evaluar orientación respecto al centro de la imagen nativa (1024 / 2 = 512)
				bool esLadoIzquierdo = (areaDestino.X < imgFondo->Width / 2);

				Rectangle recorteAuto;
				switch (i % 3) {
				case 0: recorteAuto = esLadoIzquierdo ? autoAzulD : autoAzulI; break;
				case 1: recorteAuto = esLadoIzquierdo ? autoRojoD : autoRojoI; break;
				case 2: recorteAuto = esLadoIzquierdo ? autoVerdeD : autoVerdeI; break;
				}

				g->DrawImage(imgAuto, areaDestino, recorteAuto, GraphicsUnit::Pixel);
			}
		}
		// CÓDIGO TEMPORAL DE DIAGNÓSTICO: Dibujar los bordes de todos los espacios en rojo
		//for each (EspacioEstacionamiento ^ espacio in listaEspacios) {
		//	g->DrawRectangle(Pens::Red, espacio->getArea());
		//}

		// Restablecer la transformación al finalizar
		g->ResetTransform();
		
	}
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// 1. Calcular el mismo offset usado al dibujar
		int offsetX = (panel1->Width - imgFondo->Width) / 2;
		int offsetY = (panel1->Height - imgFondo->Height) / 2;
		if (offsetX < 0) offsetX = 0;
		if (offsetY < 0) offsetY = 0;

		// 2. Ajustar las coordenadas del clic restando el offset para que coincidan con la cuadrícula nativa
		int xRelativo = e->X - offsetX;
		int yRelativo = e->Y - offsetY;

		// 3. Enviar las coordenadas relativas corregidas y el piso actual al controlador
		bool huboCambio = controlador->ProcesarClic(xRelativo, yRelativo, listaEspacios, pisoActual);

		// 3. Enviar las coordenadas relativas corregidas al controlador
		//bool huboCambio = controlador->ProcesarClic(xRelativo, yRelativo, listaEspacios);

		if (huboCambio) {
			panel1->Invalidate();
		}
	}
	private: System::Void cmbPisos_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		pisoActual = cmbPisos->SelectedIndex + 1; // 0=Piso1, 1=Piso2, 2=Piso3

		if (pisoActual == 1) imgFondo = imgPiso1;
		else if (pisoActual == 2) imgFondo = imgPiso2;
		else if (pisoActual == 3) imgFondo = imgPiso3;

		panel1->Invalidate();
	}
};
}