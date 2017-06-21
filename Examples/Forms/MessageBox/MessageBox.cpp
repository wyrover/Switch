#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace MessageBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->buttonShowMessage.Location = System::Drawing::Point(10, 10);
      this->buttonShowMessage.Width = 100;
      this->buttonShowMessage.Text = "MessageBox";
      this->buttonShowMessage.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        DialogResult result = MessageBox::Show("Hello, World!", "Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
        labelDialogResult.Text = string::Format("DialogResult = {0}", result);
      };
      
      this->labelDialogResult.Location = System::Drawing::Point(10, 45);
      this->labelDialogResult.Width = 200;

      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->Text = "MessageBox example";
      this->Controls().AddRange({this->buttonShowMessage, this->labelDialogResult});
    }
    
  private:
    Button buttonShowMessage;
    Label labelDialogResult;
  };
}

pcf_startup (MessageBoxExample::Form1)
