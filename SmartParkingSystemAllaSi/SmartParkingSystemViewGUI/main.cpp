#include "frmLogin.h"

using namespace SmartParkingSystemViewGUI;
using namespace System::Windows::Forms;
using namespace System;

void main(array<String^>^ args)
{

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    frmLogin ventana;

    Application::Run(% ventana);
}