#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace CheckBoxExample {
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
      this->ClientSize = System::Drawing::Size(300, 160);
      this->Text = "CheckBox example";
      
      this->group1.Parent = *this;
      this->group1.Text = "Group 1";
      this->group1.Bounds = System::Drawing::Rectangle(10, 10, 135, 140);
      
      this->check1.Parent = this->group1;
      this->check1.AutoSize = true;
      this->check1.Location = System::Drawing::Point(10, 30);
      this->check1.Text = "check 1";
      
      this->check2.Parent = this->group1;
      this->check2.AutoSize = true;
      this->check2.Location = System::Drawing::Point(10, 60);
      this->check2.Text = "check 2";
      this->check2.Checked = true;
      
      this->check3.Parent = this->group1;
      this->check3.AutoSize = true;
      this->check3.Location = System::Drawing::Point(10, 90);
      this->check3.Text = "check 3";
      
      this->group2.Parent = *this;
      this->group2.Text = "Group 2";
      this->group2.Bounds = System::Drawing::Rectangle(155, 10, 135, 140);
      
      this->check4.Parent = this->group2;
      this->check4.AutoSize = true;
      this->check4.Location = System::Drawing::Point(10, 30);
      this->check4.Text = "check 4";
      
      this->check5.Parent = this->group2;
      this->check5.AutoSize = true;
      this->check5.Location = System::Drawing::Point(10, 60);
      this->check5.Text = "check 5";
      
      this->check6.Parent = this->group2;
      this->check6.AutoSize = true;
      this->check6.Location = System::Drawing::Point(10, 90);
      this->check6.Text = "check 6";
      this->check6.Checked = true;
    }
    
  private:
    GroupBox group1;
    GroupBox group2;
    CheckBox check1;
    CheckBox check2;
    CheckBox check3;
    CheckBox check4;
    CheckBox check5;
    CheckBox check6;
  };
}

pcf_startup (CheckBoxExample::Form1)
