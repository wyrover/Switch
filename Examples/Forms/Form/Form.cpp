#include <Switch/Switch>

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
      button.Text = "Close";
      button.Location = System::Drawing::Point(10, 10);
      button.Click += _delegate(const object& sender, const EventArgs& e) {
        this->Close();
      };
      
      this->Text = "Form example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->Size = System::Drawing::Size(640, 480);
      this->Controls().Add(button);
      this->FormClosing += _delegate(const object& sender, FormClosingEventArgs& e) {
        e.Cancel = MessageBox::Show("Do you really want to save and exit?", "Close Form", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question) ==  DialogResult::Cancel;
      };
    }
    
  private:
    Button button;
  };
}

startup (FormExample::Form1)
