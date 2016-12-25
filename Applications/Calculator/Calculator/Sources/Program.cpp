#include "../Includes/Form1.h"

using namespace System;
using namespace System::Windows::Forms;

// The main entry point for the application
int main(int argc, char* argv[]) {
  Application::EnableVisualStyles();
  Application::Run(Calculator::Form1());
}
