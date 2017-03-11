#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Form.h"
#include "../../../../__OS/FormsApi.h"

#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

void Form::Close() {
  FormsApi::Control::Close(*this);
}

void Form::CreateHandle() {
  this->data->messageActions[WM_CLOSE] = {*this, &Form::WmClose};
  this->data->handle = FormsApi::Control::Create(*this);
  this->Control::CreateHandle();
}

void Form::WndProc(Message& message) {
  if (message.Msg == WM_CLOSE)
    this->data->messageActions[message.Msg](message);
  else
    this->Control::WndProc(message);
}

void Form::WmClose(Message& message) {
  FormClosingEventArgs e;
  this->OnFormClosing(e);
  if (e.Cancel != true)
    this->OnFormClosed(FormClosedEventArgs(e.CloseReason));
}


