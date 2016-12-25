#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Form.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Screen.h"

#include <Pcf/System/EventArgs.h>
#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

using WidgetForm = Fltk::Widget<Fl_Double_Window>;

Form::Form() : ContainerControl(UniquePointer<IWidget>::Create<WidgetForm>()) {
  WidgetForm::ToWidget(this->widget()).end();
  // --> must be before set size
  this->borderWidth =  (WidgetForm::ToWidget(this->widget()).decorated_w() - WidgetForm::ToWidget(this->widget()).w()) / 2;
  this->titleHeight = WidgetForm::ToWidget(this->widget()).decorated_h() - WidgetForm::ToWidget(this->widget()).h() - (2 * this->borderWidth);
  // <--
  this->Location = System::Drawing::Point(0, 0);
  this->Size = this->DefaultSize;
  this->Visible = false;
  this->MaximizeBox = true;
  this->widget().Callback += pcf_delegate(const object&, const EventArgs& e) {
    this->dialogResult = DialogResult::Cancel;
    this->Close();
  };
}

void Form::SetAcceptButton(const Button& button) {
  this->acceptButton = button;
#if __APPLE__
  this->acceptButton().BackColor = SystemColors::Highlight;
  this->acceptButton().ForeColor = Color::White;
#endif
}

void Form::SetCancelButton(const Button& button) {
  this->cancelButton = button;
}

Drawing::Size Form::GetDecorationSize() const {
  this->borderWidth = (WidgetForm::ToWidget(const_cast<Form*>(this)->widget()).decorated_w() - WidgetForm::ToWidget(const_cast<Form*>(this)->widget()).w()) / 2;
  this->titleHeight = WidgetForm::ToWidget(const_cast<Form*>(this)->widget()).decorated_h() - WidgetForm::ToWidget(const_cast<Form*>(this)->widget()).h() - (2 * this->borderWidth);
  int32 menuHeight = 0; //System::Environment::OSVersion().Platform == System::PlatformID::Win32S || System::Environment::OSVersion().Platform == System::PlatformID::Win32Windows || System::Environment::OSVersion().Platform == System::PlatformID::Win32NT ? this->GetMenuHeight() : 0;
  System::Drawing::Size result = System::Drawing::Size(2 * this->borderWidth, this->titleHeight + (2 * this->borderWidth) + menuHeight);
  return result;
} 

bool Form::GetMaximizeBox() const {
  return WidgetForm::ToWidget(this->widget()).resizable() != null;
}

void Form::SetMaximizeBox(bool maximized) {
 WidgetForm::ToWidget(this->widget()).resizable(maximized ? &WidgetForm::ToWidget(this->widget()) : null);
}

MainMenu& Form::GetMenu() {
  return *this->menu;
}

void Form::SetMenu(MainMenu& menu) {
  this->menu = new MainMenu(*this);
  
  for (MenuItem menuItem : menu.MenuItems()) {
    this->menu->MenuItems().Add(menuItem);
  }

  //this->Size = System::Drawing::Size(this->Size().Width(), this->Size().Height()-this->GetMenuHeight());
}

int32 Form::GetMenuHeight() const {
  if (this->menu.IsNull())
    return 0;
  return this->menu->Size().Height();
}

bool Form::SetFocus(Control& control) {
  if (control.Controls().Count == 0 && control.CanFocus())
    return control.Focus();
  else {
    for (Reference<Control> item : control.Controls()) {
      if (item().Controls().Count == 0 && item().CanFocus()) {
        return item().Focus();
      } else {
        if (this->SetFocus(item()))
          return true;
      }
    }
  }
  return false;
}

void Form::SetStartPosition(FormStartPosition startPosition) {
  this->startPosition = startPosition;
}

void Form::SetText(const string& text) {
  Control::SetText(text);
  ((WidgetForm&)this->widget()).copy_label(text.Data());
}

void Form::CenterToParent() {
  if (this->parent != null)
    this->Bounds = System::Drawing::Rectangle((this->parent->Width - this->Width) / 2, (this->parent->Height - this->Height) / 2, this->Width, this->Height);
}

void Form::CenterToScreen() {
  this->Location = System::Drawing::Point((Screen::AllScreens()[0].WorkingArea().Width - this->Width) / 2, (Screen::AllScreens()[0].WorkingArea().Height - this->Height) / 2);
}

void Form::Close() {
  FormClosingEventArgs e;
  this->OnFormClosing(e);
  if (e.Cancel != true) {
    this->Visible(false);
    this->OnFormClosed(FormClosedEventArgs(e.CloseReason));
  }
}

void Form::Show() {
  static bool first = true;
  if (first) {
    switch (this->StartPosition()) {
      case FormStartPosition::WindowsDefaultLocation: ((WidgetForm&)this->widget()).FreePosition(true); break;
      case FormStartPosition::WindowsDefaultBounds: ((WidgetForm&)this->widget()).FreePosition(true); break;
      case FormStartPosition::CenterParent: this->CenterToParent(); break;
      case FormStartPosition::CenterScreen: this->CenterToScreen(); break;
      case FormStartPosition::Manual: break;
    }
    first = false;
  }
  
  this->Control::Show();
  this->SetFocus(*this);
}

DialogResult Form::ShowDialog() {
  switch(this->StartPosition()) {
  case FormStartPosition::WindowsDefaultLocation: WidgetForm::ToWidget(this->widget()).free_position(); break;
  case FormStartPosition::WindowsDefaultBounds: WidgetForm::ToWidget(this->widget()).free_position(); break;
  case FormStartPosition::CenterParent: this->CenterToParent(); break;
  case FormStartPosition::CenterScreen: this->CenterToScreen(); break;
  case FormStartPosition::Manual: break;
  }

  WidgetForm::ToWidget(this->widget()).set_modal();
  this->Control::Show();
  this->SetFocus(*this);

  while (this->Visible)
    Fl::wait();
  
  //WidgetForm::ToWidget(this->widget()).set_non_modal();
  return this->dialogResult;
}
