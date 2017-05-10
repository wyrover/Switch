#include "../../../../__OS/FormsApi.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

//refptr<Form> Application::mainForm;
ref<Form> Application::mainForm;
bool Application::enableVisualStyles = false;
EventHandler Application::Idle;

void Application::Exit() {
  FormsApi::Application::Exit();
}

void Application::Start() {
  if (enableVisualStyles)
    FormsApi::Application::EnableVisualStyles();
  FormsApi::Application::Start();
}

void Application::MessageLoop() {
  FormsApi::Application::MessageLoop(mainForm(), Idle);
  Idle = EventHandler();
  FormsApi::Application::Stop();
}
