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
      this->checkBox1.Text = "Checked";
      this->checkBox1.Location = System::Drawing::Point(30, 30);
      this->checkBox1.CheckState = System::Windows::Forms::CheckState::Checked;
      this->checkBox1.Parent = *this;
      
      this->checkBox2.Text = "Unchecked";
      this->checkBox2.Location = System::Drawing::Point(30, 60);
      this->checkBox2.CheckState = System::Windows::Forms::CheckState::Unchecked;
      this->checkBox2.Parent = *this;
      
      this->checkBox3.Text = "Indeterminate";
      this->checkBox3.Location = System::Drawing::Point(30, 90);
      this->checkBox3.CheckState = System::Windows::Forms::CheckState::Indeterminate;
      this->checkBox3.Parent = *this;
      
      this->Text = "CheckBox example";
    }
    
  private:
    CheckBox checkBox1;
    CheckBox checkBox2;
    CheckBox checkBox3;
  };
}

pcf_startup (FormExample::Form1)
