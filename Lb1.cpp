#include "Lb1.h"

using namespace Project1;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project1::Lb1 form;
    Application::Run(% form);
    return 0;
}