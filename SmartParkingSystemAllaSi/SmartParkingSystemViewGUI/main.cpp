#include "frmLogin.h"

using namespace System;
using namespace System::Windows::Forms;

using namespace SmartParkingSystemViewGUI;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    // Configuración inicial de Windows Forms.
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);    

    // Inicia temporalmente el formulario de incio de sesión.
    Application::Run(gcnew frmLogin());

    return 0;
}