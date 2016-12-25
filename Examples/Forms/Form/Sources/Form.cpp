#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace FormExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Form example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      
      button.Parent = *this;
      button.Text = "Close";
      button.Location = System::Drawing::Point(10, 10);
      button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->Close();
      };
      
      this->FormClosing += pcf_delegate(const object& sender, FormClosingEventArgs& e) {
        DialogResult dialogResult = MessageBox::Show("Do you really want to save and exit?", "Close Form", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
        e.Cancel = dialogResult == DialogResult::Cancel;
      };
    }
    
  private:
    Button button;
  };
}

pcf_startup (FormExample::Form1)
