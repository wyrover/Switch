#if defined(_WIN32) && defined(__use_native_interface__)
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include <Windows.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

extern HINSTANCE __instance;

namespace {
  void RegisterClassControl() {
    WNDCLASSEX wndClass;
    wndClass.cbSize = sizeof(WNDCLASSEX);
    wndClass.style = CS_GLOBALCLASS;
    wndClass.lpfnWndProc = DefWindowProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = __instance;
    wndClass.hIcon = NULL;
    wndClass.hCursor = NULL;
    wndClass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = L"Control";
    wndClass.hIconSm = NULL;

    if (RegisterClassEx(&wndClass) == NULL)
      throw InvalidOperationException(string::Format("FormsApi::Application::RegisterClasses(\"Control\") failed with code = {0}", GetLastError()), pcf_current_information);
  }
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  PostQuitMessage(0);
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  ::MessageBeep((uint32)type);
}

/*
void FormsApi::Application::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  bool messageLoopRunning = true;
  while (messageLoopRunning) {
    MSG msg;
    int32 result = idle.IsEmpty() ? GetMessage(&msg, NULL, 0, 0) : PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
    while (result != 0) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (msg.message == WM_QUIT) {
        messageLoopRunning = false;
        break;
      }
      result = idle.IsEmpty() ? GetMessage(&msg, NULL, 0, 0) : PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
      if (idle.IsEmpty() && !result)
        messageLoopRunning = false;
    }
    idle(object(), EventArgs::Empty);
  }
}
*/

void FormsApi::Application::MessageLoop(const System::Windows::Forms::Form& mainForm, EventHandler idle) {
  for (;;) {
    MSG msg;
    if (idle.IsEmpty() ? GetMessage(&msg, NULL, 0, 0) : PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (msg.message == WM_QUIT) return;
    } else {
      if (idle.IsEmpty()) return;
      idle(object(), EventArgs::Empty);
    }
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return (DialogResult)MessageBox(GetActiveWindow(), message.w_str().c_str(), caption.w_str().c_str(), (uint32)buttons + (uint32)icon + (uint32)defaultButton + (uint32)options + (displayHelpButton ? 0x00004000L : 0));
}

void FormsApi::Application::Start() {
  RegisterClassControl();
}

void FormsApi::Application::Stop() {
  UnregisterClass(L"Control", NULL);
}

#endif
