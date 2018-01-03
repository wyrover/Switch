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
      this->radioButton1.Text = "radioButton 1";
      this->radioButton1.Location = System::Drawing::Point(30, 30);
      this->radioButton1.Checked = true;

      this->radioButton2.Text = "radioButton 2";
      this->radioButton2.Location = System::Drawing::Point(30, 60);

      this->radioButton3.Text = "radioButton 3";
      this->radioButton3.Location = System::Drawing::Point(30, 90);

      this->Text = "RadioButton example";
      this->Controls().AddRange({this->radioButton1, this->radioButton2, this->radioButton3});
    }

  private:
    RadioButton radioButton1;
    RadioButton radioButton2;
    RadioButton radioButton3;
  };
}

startup_(FormExample::Form1);
