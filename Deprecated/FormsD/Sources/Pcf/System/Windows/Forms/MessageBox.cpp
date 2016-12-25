#include "../../../../../Includes/Pcf/System/Media/SystemSounds.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/MessageBox.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/MessageBox.h"

#include <Pcf/System/Drawing/SystemColors.h>

#include "Exclamation.h"
#include "Information.h"
#include "Question.h"
#include "Stop.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Media;
using namespace System::Windows::FormsD;

MessageBox::MessageBox() {
  this->MaximizeBox(false);
}

DialogResult MessageBox::Show(const string& message) {
  return MessageBox::Show(message, "", MessageBoxButtons::OK, MessageBoxIcon::None);
}

DialogResult MessageBox::Show(const string& message, const string& caption) {
  return Show(message, caption, MessageBoxButtons::OK, MessageBoxIcon::None);
}

DialogResult MessageBox::Show(const string& message, const string& caption, MessageBoxButtons buttons) {
  return Show(message, caption, buttons, MessageBoxIcon::None);
}

DialogResult MessageBox::Show(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon) {
  UniquePointer<MessageBox> messageBox = new MessageBox();
  messageBox->Text = caption;
  messageBox->panel = new Panel();
  messageBox->panel->Parent(*messageBox);
  messageBox->panel->BackColor = SystemColors::Window;
  messageBox->message = new Label();
  messageBox->message->Parent = *messageBox->panel;
  messageBox->message->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
  messageBox->message->AutoSize = true;
  messageBox->message->Text = message;
  messageBox->message->Location = System::Drawing::Point(10, 10);
  messageBox->buttons = buttons;
  
  if (icon != MessageBoxIcon::None) {
    messageBox->message->Location = System::Drawing::Point(50, 10);
    messageBox->icon = new PictureBox();
    messageBox->icon->Parent(*messageBox);
    messageBox->icon->Bounds = System::Drawing::Rectangle(10, 20, 40, 40);

    switch (icon) {
      case MessageBoxIcon::None: break;
      case MessageBoxIcon::Asterisk: messageBox->icon->Image(*Image::FromData(Information)); break;
      case MessageBoxIcon::Error: messageBox->icon->Image(*Image::FromData(Stop)); break;
      case MessageBoxIcon::Exclamation: messageBox->icon->Image(*Image::FromData(Exclamation)); break;
      case MessageBoxIcon::Hand: messageBox->icon->Image(*Image::FromData(Stop)); break;
      case MessageBoxIcon::Information: messageBox->icon->Image(*Image::FromData(Information)); break;
      case MessageBoxIcon::Question: messageBox->icon->Image(*Image::FromData(Question)); break;
      case MessageBoxIcon::Stop: messageBox->icon->Image(*Image::FromData(Stop)); break;
      case MessageBoxIcon::Warning: messageBox->icon->Image(*Image::FromData(Exclamation)); break;
    }
  }
  
  messageBox->ClientSize = ComputeSize(*messageBox);
  messageBox->StartPosition = FormStartPosition::CenterScreen;
  
  CreateButtons(*messageBox);

  messageBox->panel->Bounds = System::Drawing::Rectangle(0, 0, messageBox->ClientSize().Width(), messageBox->ClientSize().Height() - 10 - 23 - 10);
  
  int32 buttonTop = messageBox->ClientSize().Height() - 23 - 10;
  int32 buttonOne = messageBox->ClientSize().Width() - (75 + 10);
  int32 buttonTwo = messageBox->ClientSize().Width() - ((75 + 10)*2);
  int32 buttonThree = messageBox->ClientSize().Width() - ((75 + 10)*3);
  
  if (buttons == MessageBoxButtons::AbortRetryIgnore)
    messageBox->buttonAbort->Location = System::Drawing::Point(buttonThree, buttonTop);
  
  if (buttons == MessageBoxButtons::OKCancel || buttons == MessageBoxButtons::RetryCancel || buttons == MessageBoxButtons::YesNoCancel)
    messageBox->buttonCancel->Location = System::Drawing::Point(buttonOne, buttonTop);
  
  if (buttons == MessageBoxButtons::AbortRetryIgnore)
    messageBox->buttonIgnore->Location = System::Drawing::Point(buttonOne, buttonTop);
  
  if (buttons == MessageBoxButtons::YesNo)
    messageBox->buttonNo->Location = System::Drawing::Point(buttonOne, buttonTop);
  
  if (buttons == MessageBoxButtons::YesNoCancel)
    messageBox->buttonNo->Location = System::Drawing::Point(buttonTwo, buttonTop);
  
  if (buttons == MessageBoxButtons::OK)
    messageBox->buttonOk->Location = System::Drawing::Point(buttonOne, buttonTop);
  
  if (buttons == MessageBoxButtons::OKCancel)
    messageBox->buttonOk->Location = System::Drawing::Point(buttonTwo, buttonTop);
  
  if (buttons == MessageBoxButtons::RetryCancel || buttons == MessageBoxButtons::AbortRetryIgnore)
    messageBox->buttonRetry->Location = System::Drawing::Point(buttonTwo, buttonTop);
  
  if (buttons == MessageBoxButtons::YesNo)
    messageBox->buttonYes->Location = System::Drawing::Point(buttonTwo, buttonTop);
  
  if (buttons == MessageBoxButtons::YesNoCancel)
    messageBox->buttonYes->Location = System::Drawing::Point(buttonThree, buttonTop);
  
  SystemSounds::Beep.Play();
  messageBox->ShowDialog();
  return messageBox->dialogResult;
}

void MessageBox::CreateButtons(MessageBox& messageBox) {
  if (messageBox.buttons == MessageBoxButtons::AbortRetryIgnore) {
    messageBox.buttonAbort = new Button();
    messageBox.buttonAbort->Parent(messageBox);
    messageBox.buttonAbort->Text = "Abort";
    messageBox.buttonAbort->Click += EventHandler(messageBox, &MessageBox::OnButtonAbortClick);
  }
  
  if (messageBox.buttons == MessageBoxButtons::OKCancel || messageBox.buttons == MessageBoxButtons::YesNoCancel || messageBox.buttons == MessageBoxButtons::RetryCancel) {
    messageBox.buttonCancel = new Button();
    messageBox.buttonCancel->Parent(messageBox);
    messageBox.buttonCancel->Text = "Cancel";
    messageBox.CancelButton = *messageBox.buttonCancel;
    messageBox.buttonCancel->Click += EventHandler(messageBox, &MessageBox::OnButtonCancelClick);
  }
  
  if (messageBox.buttons == MessageBoxButtons::AbortRetryIgnore) {
    messageBox.buttonIgnore = new Button();
    messageBox.buttonIgnore->Parent(messageBox);
    messageBox.buttonIgnore->Text = "Ignore";
    messageBox.buttonIgnore->Click += EventHandler(messageBox, &MessageBox::OnButtonIgnoreClick);
  }
  
  if (messageBox.buttons == MessageBoxButtons::YesNo || messageBox.buttons == MessageBoxButtons::YesNoCancel) {
    messageBox.buttonNo = new Button();
    messageBox.buttonNo->Parent(messageBox);
    messageBox.buttonNo->Text = "No";
    messageBox.buttonNo->Click += EventHandler(messageBox, &MessageBox::OnButtonNoClick);
  }
  
  if (messageBox.buttons == MessageBoxButtons::OK || messageBox.buttons == MessageBoxButtons::OKCancel) {
    messageBox.buttonOk = new Button();
    messageBox.buttonOk->Parent(messageBox);
    messageBox.buttonOk->Text = "Ok";
    messageBox.AcceptButton = *messageBox.buttonOk;
    messageBox.buttonOk->Click += EventHandler(messageBox, &MessageBox::OnButtonOkClick);
  }

  if (messageBox.buttons == MessageBoxButtons::AbortRetryIgnore || messageBox.buttons == MessageBoxButtons::RetryCancel) {
    messageBox.buttonRetry = new Button();
    messageBox.buttonRetry->Parent(messageBox);
    messageBox.buttonRetry->Text = "Retry";
    messageBox.buttonRetry->Click += EventHandler(messageBox, &MessageBox::OnButtonRetryClick);
  }

  if (messageBox.buttons == MessageBoxButtons::YesNo || messageBox.buttons == MessageBoxButtons::YesNoCancel) {
    messageBox.buttonYes = new Button();
    messageBox.buttonYes->Parent(messageBox);
    messageBox.buttonYes->Text = "Yes";
    messageBox.buttonYes->Click += EventHandler(messageBox, &MessageBox::OnButtonYesClick);
  }
}

System::Drawing::Size MessageBox::ComputeSize(MessageBox& messageBox) {
  int32 minHeight = 10 + 80 + 10 + 23 + 10;
  int32 minWidth = 10 + 60 + 3*75 + 3*10;
 
  int32 maxWidth = 480;
  
  int32 messageWidth = 10 + messageBox.message->Width() + 10;
  int32 messageHeight = 10 +  + 10 + 23 + 10;
  
  int32 width = minWidth;
  int32 height = minHeight;
  
  if (messageWidth > width)
    width = messageWidth;
  else
    messageBox.message->Location = System::Drawing::Point((messageBox.icon.IsNull() ? 10 : 50), (minHeight - messageHeight)/2);
  
  if (messageHeight > height)
    height = messageHeight;
  
  if (messageWidth > maxWidth) {
    messageBox.message->AutoSize(false);
    messageBox.message->Width(maxWidth - 20 - (messageBox.icon.IsNull() ? 0 : 40));
    messageBox.message->Height(messageBox.message->Height() * ((messageWidth / (maxWidth-20)) + (messageWidth / (maxWidth-20) ? 1 : 0)));
    width = maxWidth;
    height = 10 + messageBox.message->Height() + 10 + 23 + 10;
    if (height < minHeight) {
      height = minHeight;
      messageBox.message->Top((minHeight - messageHeight)/2);
    }
  }
  
  return System::Drawing::Size(width, height);
}

void MessageBox::OnButtonAbortClick(const object& sender, const EventArgs& e) {
  this->dialogResult = DialogResult::Abort;
  this->Close();
}

void MessageBox::OnButtonCancelClick(const object& sender, const EventArgs& e) {
  this->dialogResult = DialogResult::Cancel;
  this->Close();
}

void MessageBox::OnButtonIgnoreClick(const object& sender, const EventArgs& e) {
  this->dialogResult = DialogResult::Ignore;
  this->Close();
}

void MessageBox::OnButtonNoClick(const object& sender, const EventArgs& e) {
  this->dialogResult = DialogResult::No;
  this->Close();
}

void MessageBox::OnButtonOkClick(const object& sender, const EventArgs& e) {
  this->dialogResult = DialogResult::OK;
  this->Close();
}

void MessageBox::OnButtonRetryClick(const object& sender, const EventArgs& e) {
  this->dialogResult = DialogResult::Retry;
  this->Close();
}

void MessageBox::OnButtonYesClick(const object& sender, const EventArgs& e) {
  this->dialogResult = DialogResult::Yes;
  this->Close();
}
