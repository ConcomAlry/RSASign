#include "MyForm.h"
#include <array>
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array < String^ > ^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    RSASign::MyForm form; //WinFormsTest - ��� ������ �������
    Application::Run(% form);
}