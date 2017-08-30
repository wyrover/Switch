﻿#if defined(_WIN32)

#include <windows.h>
#include <Windowsx.h>
#include <Uxtheme.h>
#include <Switch/Undef.hpp>

#include "FormsApi.hpp"
#include "WindowProcedureWin32.hpp"
#include "../../Includes/Switch/System/Windows/Forms/Control.hpp"
#include "../../Includes/Switch/System/Windows/Forms/Message.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace __OS;

Dictionary<intptr, WNDPROC> WindowProcedure::DefWindowProcs;

void WindowProcedure::SetWindowTheme(HWND handle) {
  if (!FormsApi::Application::HasVisualStylesEnabled())
    ::SetWindowTheme(handle, L"", L"");
}

LRESULT CALLBACK WindowProcedure::WndProc(HWND hwnd, uint32 msg, WPARAM wParam, LPARAM lParam) {
  Message message = Message::Create((intptr)hwnd, msg, wParam, lParam, 0);
  Control::FromHandle(message.HWnd)().WndProc(message);
  return message.Result;
}

#endif
