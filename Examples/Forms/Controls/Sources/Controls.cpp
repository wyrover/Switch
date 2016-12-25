#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace ControlExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->label.Location = System::Drawing::Point(10, 10);
      this->label.AutoSize = true;
      this->label.Text = "label";
      
      this->button.Location = System::Drawing::Point(10, 35);
      this->button.Text = "button";
      
      this->progressBar.Location = System::Drawing::Point(10, 70);
      this->progressBar.Value = 62;
      
      this->Controls().Add(this->label);
      this->Controls().Add(this->button);
      this->Controls().Add(this->progressBar);
      
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
    }
    
  private:
    Label label;
    Button button;
    ProgressBar progressBar;
  };
}

pcf_startup (ControlExample::Form1)
