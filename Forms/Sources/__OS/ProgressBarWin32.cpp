#if defined(_WIN32) && defined(__use_native_interface__)

#include <Windows.h>
#include <Uxtheme.h>
#include <Pcf/Undef.h>

#include "FormsApi.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace __OS;

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.Handle(), PBM_SETRANGE32, progressBar.Minimum(), progressBar.Maximum());
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  PostMessage((HWND)progressBar.Handle(), PBM_SETPOS, progressBar.Value(), 0);
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  PostMessage((HWND)radioButton.Handle(), BM_SETCHECK, radioButton.Checked ? BST_CHECKED : BST_UNCHECKED, 0);
}

#endif
