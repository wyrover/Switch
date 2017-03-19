#include <Pcf/System/Diagnostics/ConsoleTraceListener.h>
#include <Pcf/System/Windows/Forms/Application.h>
#include <Pcf/System/Windows/Forms/Button.h>
#include <Pcf/System/Windows/Forms/CheckBox.h>
#include <Pcf/System/Windows/Forms/Form.h>
#include <Pcf/System/Windows/Forms/Label.h>
#include <Pcf/System/Windows/Forms/MessageBox.h>
#include <Pcf/System/Windows/Forms/RadioButton.h>
#include <Pcf/System/Windows/Forms/SystemInformation.h>
#include <Pcf/Startup.h>

using namespace System;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Diagnostics::Debug::AutoFlush = true;
      System::Diagnostics::Debug::Listeners().Add(System::Diagnostics::ConsoleTraceListener());
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Name = "form1";
      //this->BackColor = System::Drawing::Color::SpringGreen;
      this->Text = "First Application";
      this->Location = System::Drawing::Point(200, 100);

      this->FormClosing += pcf_delegate(const object& sender, FormClosingEventArgs& e) {
        e.Cancel = MessageBox::Show("Do you want quit\napplication ?", "Program", MessageBoxButtons::YesNo, MessageBoxIcon::Question) != DialogResult::Yes;
      };
      
      this->button1.Parent = *this;
      //this->button1.BackColor = System::Drawing::Color::LawnGreen;
      this->button1.Name = "button1";
      this->button1.Text = "Button";
      this->button1.Location = System::Drawing::Point(10, 10);
      this->button1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        static int32 counter = 0;
        this->label1.Text = string::Format("Counter {0}", ++counter);
      };

      this->Paint += pcf_delegate(const object& sender, PaintEventArgs& e) {
        //System::Diagnostics::Debug::WriteLine("ClipRectangle = {0}", e.ClipRectangle);
        //e.Graphics().Clear(System::Drawing::Color::LawnGreen);
        //System::Drawing::Pen pen(System::Drawing::Color::DarkGreen, 1);
        //pen.DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
        //System::Drawing::Rectangle rectangle = e.ClipRectangle;
        //rectangle.Inflate(-10, -10);
        //e.Graphics().DrawRectangle(pen, rectangle);
        //e.Graphics().DrawRectangle(System::Drawing::Pen(System::Drawing::Color::DarkGreen, 2), { 5, 5, 200, 200 });
      };
      
      this->checkBox1.Parent = *this;
      this->checkBox1.Name = "checkBox1";
      this->checkBox1.Text = "CheckBox";
      //this->checkBox1.BackColor = System::Drawing::Color::SpringGreen;
      this->checkBox1.Location = System::Drawing::Point(10, 40);
      
      this->radioButton1.Parent = *this;
      this->radioButton1.Name = "radioButton1";
      this->radioButton1.Text = "RadioButton 1";
      //this->radioButton1.BackColor = System::Drawing::Color::SpringGreen;
      this->radioButton1.Location = System::Drawing::Point(10, 70);
      this->radioButton1.Size = System::Drawing::Size(120, 25);

      this->radioButton2.Parent = *this;
      this->radioButton2.Name = "radioButton2";
      this->radioButton2.Text = "RadioButton 2";
      //this->radioButton2.BackColor = System::Drawing::Color::SpringGreen;
      this->radioButton2.Location = System::Drawing::Point(10, 100);
      this->radioButton2.Size = System::Drawing::Size(120, 25);
      
      this->label1.Parent = *this;
      this->label1.Name = "label1";
      //this->label1.BackColor = System::Drawing::Color::SpringGreen;
      //this->label1.ForeColor = System::Drawing::Color::Green;
      this->label1.Text = "Text label";
      this->label1.Location = System::Drawing::Point(28, 132);
      this->label1.Size = System::Drawing::Size(100, 23);
    }
    
  private:
    Button button1;
    CheckBox checkBox1;
    RadioButton radioButton1;
    RadioButton radioButton2;
    Label label1;
  };
}

pcf_startup (PcfFormApp::Form1)
