#include "../../../../__OS/FormsApi.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

//UniquePointer<Form> Application::mainForm;
Reference<Form> Application::mainForm;
bool Application::enableVisualStyles = false;
EventHandler Application::Idle;

void Application::AddForm() {
  FormsApi::Application::AddForm(mainForm());
}

void Application::Exit() {
  FormsApi::Application::Exit();
}

void Application::Start() {
  if (enableVisualStyles)
    FormsApi::Application::EnableVisualStyles();
  FormsApi::Application::Start();
}

void Application::MessageLoop() {
  FormsApi::Application::MessageLoop(Idle);
  FormsApi::Application::Stop();
}
