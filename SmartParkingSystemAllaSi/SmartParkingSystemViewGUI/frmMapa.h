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
	/// Summary for frmMapa
	/// </summary>
	public ref class frmMapa : public System::Windows::Forms::Form
	{
	public:
		frmMapa(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// 1. Cargar datos
			controlador = gcnew EspacioEstacionamientoController();
			listaEspacios = controlador->ObtenerEspacios();

			// 2. Cargar imágenes
			imgPiso1 = Image::FromFile("Piso1.png");
			imgPiso2 = Image::FromFile("Piso2.png");
			imgPiso3 = Image::FromFile("Piso3.png");
			imgAuto = Image::FromFile("autos.png");
			imgFondo = imgPiso1;

			// 3. Configurar ComboBox
			cmbPisos->Items->Clear();
			cmbPisos->Items->Add("Piso 1");
			cmbPisos->Items->Add("Piso 2");
			cmbPisos->Items->Add("Piso 3");
			cmbPisos->SelectedIndex = 0;

			// 4. Activar DoubleBuffered para evitar parpadeos
			System::Reflection::PropertyInfo^ prop = panel1->GetType()->GetProperty("DoubleBuffered", System::Reflection::BindingFlags::Instance | System::Reflection::BindingFlags::NonPublic);
			prop->SetValue(panel1, true, nullptr);

			panel1->Invalidate();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMapa()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ pnlSuperior;
	private: System::Windows::Forms::ComboBox^ cmbPisos;
	private: System::Windows::Forms::Panel^ panel1;
	private:
		Image^ imgPiso1;
		Image^ imgPiso2;
		Image^ imgPiso3;
		Image^ imgFondo;
		Image^ imgAuto;
		EspacioEstacionamientoController^ controlador;
		List<EspacioEstacionamiento^>^ listaEspacios;
		int pisoActual = 1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pnlSuperior = (gcnew System::Windows::Forms::Panel());
			this->cmbPisos = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pnlSuperior->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(233, 172);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 82);
			this->label1->TabIndex = 0;
			this->label1->Click += gcnew System::EventHandler(this, &frmMapa::label1_Click);
			// 
			// pnlSuperior
			// 
			this->pnlSuperior->Controls->Add(this->cmbPisos);
			this->pnlSuperior->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlSuperior->Location = System::Drawing::Point(0, 0);
			this->pnlSuperior->Name = L"pnlSuperior";
			this->pnlSuperior->Size = System::Drawing::Size(1223, 40);
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
			this->cmbPisos->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMapa::cmbPisos_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pnlSuperior);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1223, 658);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmMapa::panel1_Paint);
			// 
			// frmMapa
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(1223, 658);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmMapa";
			this->Text = L"frmMapa";
			this->pnlSuperior->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->InterpolationMode = InterpolationMode::NearestNeighbor;

		int offsetX = (panel1->Width - imgFondo->Width) / 2;
		int offsetY = (panel1->Height - imgFondo->Height) / 2;
		if (offsetX < 0) offsetX = 0;
		if (offsetY < 0) offsetY = 0;

		g->TranslateTransform((float)offsetX, (float)offsetY);
		g->DrawImage(imgFondo, 0, 0, imgFondo->Width, imgFondo->Height);

		int anchoAuto = imgAuto->Width / 2;
		int altoAuto = imgAuto->Height / 3;
		Rectangle autoAzulD = Rectangle(0, 0, anchoAuto, altoAuto);
		Rectangle autoAzulI = Rectangle(anchoAuto, 0, anchoAuto, altoAuto);
		Rectangle autoRojoD = Rectangle(0, altoAuto, anchoAuto, altoAuto);
		Rectangle autoRojoI = Rectangle(anchoAuto, altoAuto, anchoAuto, altoAuto);
		Rectangle autoVerdeD = Rectangle(0, altoAuto * 2, anchoAuto, altoAuto);
		Rectangle autoVerdeI = Rectangle(anchoAuto, altoAuto * 2, anchoAuto, altoAuto);

		for (int i = 0; i < listaEspacios->Count; i++) {
			EspacioEstacionamiento^ espacio = listaEspacios[i];
			int id = espacio->getIdEspacio();
			int pisoDelEspacio = ((id - 1) / 30) + 1;

			if (pisoDelEspacio == pisoActual && espacio->getEstaOcupado()) {
				Rectangle areaDestino = espacio->getArea();
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
		g->ResetTransform();
	}
	private: System::Void cmbPisos_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		pisoActual = cmbPisos->SelectedIndex + 1;

		if (pisoActual == 1) imgFondo = imgPiso1;
		else if (pisoActual == 2) imgFondo = imgPiso2;
		else if (pisoActual == 3) imgFondo = imgPiso3;

		panel1->Invalidate();
	}
};
}
