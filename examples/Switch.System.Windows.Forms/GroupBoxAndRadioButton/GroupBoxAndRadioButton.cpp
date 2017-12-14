#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace RadioButtonExample {
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
      this->Text = "GroupBox and RadioButton example";

      this->groupBox1.Parent = *this;
      this->groupBox1.Text = "Group 1";
      this->groupBox1.Bounds = System::Drawing::Rectangle(10, 10, 135, 140);

      this->radio1.Parent = this->groupBox1;
      this->radio1.Location = System::Drawing::Point(10, 30);
      this->radio1.Text = "radio button 1";
      this->radio1.Checked = true;

      this->radio2.Parent = this->groupBox1;
      this->radio2.Location = System::Drawing::Point(10, 60);
      this->radio2.Text = "radio button 2";

      this->radio3.Parent = this->groupBox1;
      this->radio3.Location = System::Drawing::Point(10, 90);
      this->radio3.Text = "radio button 3";

      this->groupBox2.Parent = *this;
      this->groupBox2.Text = "Group 2";
      this->groupBox2.Bounds = System::Drawing::Rectangle(155, 10, 130, 140);

      this->radio4.Parent = this->groupBox2;
      this->radio4.Location = System::Drawing::Point(10, 30);
      this->radio4.Text = "radio button 4";

      this->radio5.Parent = this->groupBox2;
      this->radio5.Location = System::Drawing::Point(10, 60);
      this->radio5.Text = "radio button 5";
      this->radio5.Checked = true;

      this->radio6.Parent = this->groupBox2;
      this->radio6.Location = System::Drawing::Point(10, 90);
      this->radio6.Text = "radio button 6";
    }

  private:
    GroupBox groupBox1;
    GroupBox groupBox2;
    RadioButton radio1;
    RadioButton radio2;
    RadioButton radio3;
    RadioButton radio4;
    RadioButton radio5;
    RadioButton radio6;
  };
}

_startup(RadioButtonExample::Form1);


