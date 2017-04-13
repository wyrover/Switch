#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace MaskedTextBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "MaskedTextBox example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      
      this->labelUser.Parent = *this;
      this->labelUser.AutoSize = true;
      this->labelUser.Text = "User";
      this->labelUser.Location = System::Drawing::Point(10, 20);
      
      this->labelPassword.Parent = *this;
      this->labelPassword.AutoSize = true;
      this->labelPassword.Text = "Password";
      this->labelPassword.Location = System::Drawing::Point(10, 50);
      
      this->textUser.Parent = *this;
      this->textUser.Text = "john.doe@anonymous.com";
      this->textUser.Bounds = System::Drawing::Rectangle(100, 16, 180, 25);
      
      this->labelTextPassword.Parent = *this;
      this->labelTextPassword.AutoSize = true;
      this->labelTextPassword.Bounds = System::Drawing::Rectangle(100, 76, 180, 25);
      
      this->textPassword.Parent = *this;
      this->textPassword.TextChanged += pcf_delegate(const object& sender, const EventArgs& e) {
        labelTextPassword.Text = this->textPassword.Text();
      };
      this->textPassword.Text = "grandmother";
      this->textPassword.UseSystemPasswordChar = true;
      this->textPassword.Font = System::Drawing::Font(DefaultFont().Name, 24, System::Drawing::FontStyle::Regular);
      this->textPassword.Bounds = System::Drawing::Rectangle(100, 46, 180, 25);
    }
    
  private:
    Label labelUser;
    Label labelPassword;
    TextBox textUser;
    TextBox textPassword;
    Label labelTextPassword;
  };
}

pcf_startup (MaskedTextBoxExample::Form1)
