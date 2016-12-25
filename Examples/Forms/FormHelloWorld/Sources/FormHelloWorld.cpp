#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace HelloWorld {
  class MainForm : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(MainForm());
    }
    
    MainForm() {
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->ClientSize = System::Drawing::Size(300, 300);
      this->Text = "My first application";
      
      this->label.Parent = *this;
      this->label.Text = "Hello, World!";
      this->label.AutoSize = true;
      this->label.Font = System::Drawing::Font("Arial", 46, System::Drawing::FontStyle::Bold|System::Drawing::FontStyle::Italic);
      this->label.ForeColor = System::Drawing::Color::Green;
      this->label.Location = System::Drawing::Point(5, 100);
    }
    
  private:
    Label label;
  };
}

pcf_startup (HelloWorld::MainForm)
