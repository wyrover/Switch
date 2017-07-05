#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace TimerExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Timer Example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 300);
      this->ClientSize = System::Drawing::Size(230, 130);
      
      this->label.Parent = *this;
      this->label.Text = string::Format("{0:N1}", as<double>(this->counter)/10);
      this->label.Location = System::Drawing::Point(10, 10);
      //this->label.AutoSize = true;
      //this->label.Font = System::Drawing::Font("Arial", 60, System::Drawing::FontStyle::Italic);
      this->label.ForeColor = System::Drawing::Color::DodgerBlue;
      
      this->timer.Interval = 100;
      this->timer.Tick += pcf_delegate(const object& sender, const EventArgs& e) {
        this->label.Text = string::Format("{0:N1}", as<double>(++this->counter)/10);
      };

      this->button.Parent = *this;
      this->button.Text = "Start";
      this->button.Location = System::Drawing::Point(10, 90);
      
      this->button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->timer.Enabled = !this->timer.Enabled;
        this->button.Text = this->timer.Enabled ? "Stop" : "Start";
      };
    }
    
  private:
    Label label;
    Button button;
    Timer timer;
    int counter = 0;
  };
}

pcf_startup (TimerExample::Form1)
