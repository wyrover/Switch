#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace NumericUpDownExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->Text = "NumericUpDown Example";
      
      this->numericUpDown1.Parent = *this;
      this->numericUpDown1.Location = System::Drawing::Point(100, 50);
      
      this->numericUpDown2.Parent = *this;
      this->numericUpDown2.Location = System::Drawing::Point(100, 100);
      this->numericUpDown2.Minimum = 10.0;
      this->numericUpDown2.Maximum = 11.0;
      this->numericUpDown2.Increment = 0.01;
      this->numericUpDown2.DecimalPlaces = 2;
    }
    
  private:
    NumericUpDown numericUpDown1;
    NumericUpDown numericUpDown2;
  };
}

pcf_startup (NumericUpDownExample::Form1)
