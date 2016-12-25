#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace LabelExample {
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
      this->Text = "Label example";
      
      this->label1.Parent = *this;
      this->label1.Text = "http://www.gammasoft.com";
      this->label1.AutoSize = true;
      this->label1.Location = System::Drawing::Point(10, 10);
      this->label1.Cursor = Cursors::Hand;
      
      this->label1.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.ForeColor = System::Drawing::Color::Blue;
      };
      
      this->label1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show(string::Format("The label \"{0}\" was clicked", this->label1.Text), "Message", MessageBoxButtons::OK);
      };
      
      this->label1.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label1.ForeColor = System::Drawing::Color::Black;
      };
    }
    
  private:
    Label label1;
  };
}

pcf_startup (LabelExample::Form1)
