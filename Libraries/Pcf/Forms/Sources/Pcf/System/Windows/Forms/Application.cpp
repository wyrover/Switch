#include "../../../../__OS/FormsApi.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

UniquePointer<Form> Application::mainForm;
bool Application::enableVisualStyles = false;
EventHandler Application::Idle;

void Application::Exit() {
  FormsApi::Application::Exit();
}

void Application::Run() {
  FormsApi::Application::RegisterClasses();
  if (enableVisualStyles)
    FormsApi::Application::EnableVisualStyles();
  if (!mainForm.IsNull()) {
    mainForm().Visible = true;
    mainForm().FormClosed += pcf_delegate(const object& sender, const FormClosedEventArgs& e) {
      Exit();
    };
  }
  FormsApi::Application::MessageLoop(Idle);
  FormsApi::Application::UnregisterClasses();
}
