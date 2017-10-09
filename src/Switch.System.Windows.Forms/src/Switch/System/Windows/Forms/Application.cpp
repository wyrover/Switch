#include "../../../../Native/FormsApi.hpp"
#include "../../../../../include/Switch/System/Windows/Forms/Application.hpp"

using namespace System;
using namespace System::Windows::Forms;

ref<Form> Application::mainForm;
EventHandler Application::Idle;

void Application::EnableVisualStyles() {
  Native::FormsApi::Application::EnableVisualStyles();
}

void Application::Exit() {
  Native::FormsApi::Application::Exit();
}

void Application::Start() {
  Native::FormsApi::Application::Start();
}

void Application::MessageLoop() {
  Native::FormsApi::Application::MessageLoop(mainForm(), Idle);
  Idle = EventHandler();
  Native::FormsApi::Application::Stop();
}
