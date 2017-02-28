#include <Pcf/System/Windows/Forms/Application.h>
#include <Pcf/System/Windows/Forms/Button.h>
#include <Pcf/System/Windows/Forms/CheckBox.h>
#include <Pcf/System/Windows/Forms/Form.h>
#include <Pcf/System/Windows/Forms/Label.h>
#include <Pcf/System/Windows/Forms/RadioButton.h>
#include <Pcf/System/Windows/Forms/SystemInformation.h>
#include <Pcf/Startup.h>

using namespace System;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class UserControl : public Control {
  public:
  };
  
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Name = "form1";
      this->Text = "First Application";
      this->Location = System::Drawing::Point(200, 100);
      //this->Size = System::Drawing::Size(640, 480);
      this->MouseClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("form1 Clicked at {0}", e.Location);
      };
      this->MouseWheel += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("Form::MouseWheel Location={0}, Delta={1}", e.Location, e.Delta);
      };
      
      this->button1.Parent = *this;
      this->button1.Name = "button1";
      //this->button1.Text = "Button";
      this->button1.Text = U"こんにちは世界！";
      this->button1.Location = System::Drawing::Point(10, 10);
      this->button1.MouseClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("Button::MouseClick at {0}", e.Location);
        this->label1.Text = this->button1.PointToScreen(e.Location).ToString();
      };
      this->button1.MouseWheel += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("Button::MouseWheel Location={0}, Delta={1}", e.Location, e.Delta);
      };
      
      this->checkBox1.Parent = *this;
      this->checkBox1.Name = "checkBox1";
      this->checkBox1.Text = "CheckBox";
      this->checkBox1.Location = System::Drawing::Point(10, 40);
      
      this->radioButton1.Parent = *this;
      this->radioButton1.Name = "radioButton1";
      this->radioButton1.Text = "RadioButton";
      this->radioButton1.Location = System::Drawing::Point(10, 70);
      
      this->radioButton2.Parent = *this;
      this->radioButton2.Name = "radioButton2";
      this->radioButton2.Text = "RadioButton 2";
      this->radioButton2.Location = System::Drawing::Point(10, 100);
      this->radioButton2.Size = System::Drawing::Size(120, 25);
      
      this->label1.Parent = *this;
      this->label1.Name = "label1";
      //this->label1.Text = "Text label";
      this->label1.Text = U"こんにちは世界！";
      //this->label1.Text = U"Привет мир!";
      this->label1.Location = System::Drawing::Point(10, 130);
      this->label1.Size = System::Drawing::Size(200, 23);
      this->label1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLine("this->label1 Clicked !");
      };
      
      this->userControl1.Parent = *this;
      this->userControl1.Name = "userControl1";
      this->userControl1.Bounds = System::Drawing::Rectangle(10, 160, 200, 200);
      
      //this->FormBorderStyle = FormBorderStyle::None;
      
      //Application::Idle += pcf_delegate(const object sender, const EventArgs e) {
      //  this->button1.Text = string::Format("{0}", ++counter);
      //};
    }
    
    /// @cond
    Form1(const Form1& form) = default;
    int counter = 0;
    /// @endcond
    
  private:
    Button button1;
    CheckBox checkBox1;
    RadioButton radioButton1;
    RadioButton radioButton2;
    Label label1;
    UserControl userControl1;
  };
}

pcf_startup (PcfFormApp::Form1)
