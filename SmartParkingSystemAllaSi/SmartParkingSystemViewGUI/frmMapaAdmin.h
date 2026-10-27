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

			// Cargar imágenes de fondo y autos
			imgFondo = Image::FromFile("Piso1.png");
			imgAuto = Image::FromFile("autos.png");

			// Activar Double Buffering para evitar parpadeos al repintar
			this->SetStyle(ControlStyles::OptimizedDoubleBuffer |
				ControlStyles::AllPaintingInWmPaint |
				ControlStyles::UserPaint, true);

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
		Image^ imgFondo;
		Image^ imgAuto;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1049, 605);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMapaAdmin::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMapaAdmin::panel1_MouseClick);
			// 
			// frmMapaAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(1049, 605);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmMapaAdmin";
			this->Text = L"frmMapaAdmin";
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

			if (espacio->getEstaOcupado()) {
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

		// Restablecer la transformación al finalizar
		g->ResetTransform();
		
		// CÓDIGO TEMPORAL DE DIAGNÓSTICO: Dibujar los bordes de todos los espacios en rojo
		for each (EspacioEstacionamiento ^ espacio in listaEspacios) {
			g->DrawRectangle(Pens::Red, espacio->getArea());
		}
	}
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		bool huboCambio = controlador->ProcesarClic(e->X, e->Y, listaEspacios);

		if (huboCambio) {
			panel1->Invalidate();
		}
	}
	};
}