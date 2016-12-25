#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace ProgressBarExample {
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
      this->Text = "ProgressBar Example";
      
      this->progressBar1.Parent = *this;
      this->progressBar1.Location = System::Drawing::Point(100, 50);
      
      this->progressBar2.Parent = *this;
      this->progressBar2.Location = System::Drawing::Point(100, 80);
      this->progressBar2.Value = 50;
      
      this->progressBar3.Parent = *this;
      this->progressBar3.Location = System::Drawing::Point(100, 110);
      this->progressBar3.ForeColor = System::Drawing::Color::Red;
      this->progressBar3.Maximum = 200;
      this->progressBar3.Value = 200;
      
      this->progressBar4.Parent = *this;
      this->progressBar4.Bounds = System::Drawing::Rectangle(50, 150, 200, 15);
      this->progressBar4.ForeColor = System::Drawing::Color::LightPink;
      this->progressBar4.Maximum = 140;
      
      this->progressBar5.Parent = *this;
      this->progressBar5.Bounds = System::Drawing::Rectangle(50, 180, 200, 15);
      this->progressBar5.ForeColor = System::Drawing::Color::LightGreen;
      this->progressBar5.Value = 50;
      
      this->progressBar6.Parent = *this;
      this->progressBar6.Bounds = System::Drawing::Rectangle(50, 210, 200, 15);
      this->progressBar6.ForeColor = System::Drawing::Color::LightBlue;
      this->progressBar6.Maximum = 200;
      this->progressBar6.Value = 200;
      
      this->timer.Interval = 50;
      this->timer.Enabled = true;
      this->timer.Tick += pcf_delegate(const object& sender, const EventArgs& e) {
        this->progressBar1.Value = this->progressBar1.Value < this->progressBar1.Maximum ? this->progressBar1.Value+1 : this->progressBar1.Minimum;
        this->progressBar1.ForeColor = this->progressBar1.Value >= 50 ? Drawing::Color::Red : Drawing::Color::Green;
        this->progressBar4.Value = this->progressBar4.Value < this->progressBar4.Maximum ? this->progressBar4.Value+1 : this->progressBar4.Minimum;
      };
    }
    
  private:
    ProgressBar progressBar1;
    ProgressBar progressBar2;
    ProgressBar progressBar3;
    ProgressBar progressBar4;
    ProgressBar progressBar5;
    ProgressBar progressBar6;
    Timer timer;
  };
}

pcf_startup (ProgressBarExample::Form1)
