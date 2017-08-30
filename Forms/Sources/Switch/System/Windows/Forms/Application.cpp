#include "../../../../__OS/FormsApi.hpp"
#include "../../../../../Includes/Switch/System/Windows/Forms/Application.hpp"

using namespace System;
using namespace System::Windows::Forms;

ref<Form> Application::mainForm;
EventHandler Application::Idle;

void Application::EnableVisualStyles() {
  __OS::FormsApi::Application::EnableVisualStyles();
}

void Application::Exit() {
  __OS::FormsApi::Application::Exit();
}

void Application::Start() {
  __OS::FormsApi::Application::Start();
}

void Application::MessageLoop() {
  __OS::FormsApi::Application::MessageLoop(mainForm(), Idle);
  Idle = EventHandler();
  __OS::FormsApi::Application::Stop();
}
