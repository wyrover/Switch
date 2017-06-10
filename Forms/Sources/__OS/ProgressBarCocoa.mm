#if defined(__APPLE__) && defined(__use_native_interface__)
#include "WindowProcedureCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  @autoreleasepool {
    NSProgressIndicator* handle = [[[NSProgressIndicator alloc] init] autorelease];
    [[(NSWindow*)progressBar.Parent()().Handle() contentView] addSubview: handle];
    
    __OS::WindowProcedure::Controls[(intptr)handle] = progressBar;
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setIndeterminate:false];
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::ProgressBar&>(progressBar).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setMaxValue:progressBar.Maximum()];
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setMinValue:progressBar.Minimum()];
}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar& progressBar) {
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  [(NSProgressIndicator*)progressBar.Handle() setDoubleValue:progressBar.Value()];
}

#endif
