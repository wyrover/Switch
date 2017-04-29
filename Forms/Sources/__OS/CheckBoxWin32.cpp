#if defined(_WIN32) && defined(__use_native_interface__)

#include <Windows.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  PostMessage((HWND)checkBox.Handle(), BM_SETCHECK, checkBox.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

#endif
