#if defined(_WIN32)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <windows.h>
#include <Pcf/Undef.hpp>
#include <Pcf/System/Diagnostics/Debug.hpp>

#include "FormsApi.hpp"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  PostQuitMessage(0);
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  ::MessageBeep((uint32)type);
}

void FormsApi::Application::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  while (true) {
    MSG msg;
    if (idle.IsEmpty() || PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE) != 0) {
      if (GetMessage(&msg, NULL, 0, 0) == 0) break;
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (msg.message == WM_QUIT) break;
    }
    idle(object(), EventArgs::Empty);
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return (DialogResult)MessageBox(GetActiveWindow(), message.w_str().c_str(), caption.w_str().c_str(), (uint32)buttons + (uint32)icon + (uint32)defaultButton + (uint32)options + (displayHelpButton ? 0x00004000L : 0));
}

void FormsApi::Application::Start() {
}

void FormsApi::Application::Stop() {
}

#endif
