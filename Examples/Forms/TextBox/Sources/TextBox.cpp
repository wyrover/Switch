#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace TextBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "TextBox example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      
      this->labelFirstName.Parent = *this;
      this->labelFirstName.Text = "First name";
      this->labelFirstName.Location = System::Drawing::Point(10, 20);
      
      this->labelLastName.Parent = *this;
      this->labelLastName.Text = "Last name";
      this->labelLastName.Location = System::Drawing::Point(10, 50);
      
      this->labelBirthday.Parent = *this;
      this->labelBirthday.Text = "Birthday";
      this->labelBirthday.Location = System::Drawing::Point(10, 80);
      
      this->textFirstName.Parent = *this;
      this->textFirstName.Text = "James";
      this->textFirstName.Bounds = System::Drawing::Rectangle(100, 16, 180, 25);
      
      this->textLastName.Parent = *this;
      this->textLastName.Text = "Bond";
      this->textLastName.Bounds = System::Drawing::Rectangle(100, 46, 180, 25);
      
      this->textBirthday.Parent = *this;
      this->textBirthday.Text = "05/01/1971";
      this->textBirthday.Bounds = System::Drawing::Rectangle(100, 76, 180, 25);
    }
    
  private:
    Label labelFirstName;
    Label labelLastName;
    Label labelBirthday;
    TextBox textFirstName;
    TextBox textLastName;
    TextBox textBirthday;
  };
}

pcf_startup (TextBoxExample::Form1)
