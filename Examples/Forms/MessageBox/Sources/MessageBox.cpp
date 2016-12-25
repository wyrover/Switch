#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace MessageBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->Text = "MessageBox example";
      
      this->buttonShowMessage.Parent = *this;
      this->buttonShowMessage.Bounds = System::Drawing::Rectangle(10, 10, 100, 25);
      this->buttonShowMessage.Text = "MessageBox";
      this->buttonShowMessage.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        DialogResult result = MessageBox::Show("Hello, World!", "Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Information);
        labelDialogResult.Text = string::Format("DialogResult = {0}", result);
      };
      
      this->labelDialogResult.Parent = *this;
      this->labelDialogResult.Bounds = System::Drawing::Rectangle(10, 60, 200, 30);
    }
    
  private:
    Button buttonShowMessage;
    Label labelDialogResult;
  };
}

pcf_startup (MessageBoxExample::Form1)
