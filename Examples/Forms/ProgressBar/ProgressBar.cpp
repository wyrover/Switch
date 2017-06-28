#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace ProgressBarExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "ProgressBar Example";
      
      this->progressBar1.Parent = *this;
      this->progressBar1.Location = System::Drawing::Point(50, 50);
      this->progressBar1.Width = 200;
      
      this->progressBar2.Parent = *this;
      this->progressBar2.Location = System::Drawing::Point(50, 80);
      this->progressBar2.Width = 200;
      this->progressBar2.Value = 50;
      
      this->progressBar3.Parent = *this;
      this->progressBar3.Location = System::Drawing::Point(50, 110);
      this->progressBar3.Width = 200;
      this->progressBar3.Maximum = 300;
      this->progressBar3.Value = 300;
      
      this->progressBar4.Parent = *this;
      this->progressBar4.Location = System::Drawing::Point(50, 140);
      this->progressBar4.Width = 200;
      this->progressBar4.Maximum = 140;
      
      this->progressBar5.Parent = *this;
      this->progressBar5.Location = System::Drawing::Point(50, 170);
      this->progressBar5.Width = 200;
      this->progressBar5.Style = ProgressBarStyle::Marquee;
      
      this->timer.Interval = 50;
      this->timer.Enabled = true;
      this->timer.Tick += pcf_delegate(const object& sender, const EventArgs& e) {
        this->progressBar4.Value = this->progressBar4.Value < this->progressBar4.Maximum ? this->progressBar4.Value + 1 : this->progressBar4.Minimum;
        if (this->progressBar4.Value == 110) this->timer.Enabled = false;
      };
    }
    
  private:
    ProgressBar progressBar1;
    ProgressBar progressBar2;
    ProgressBar progressBar3;
    ProgressBar progressBar4;
    ProgressBar progressBar5;
    Timer timer;
  };
}

pcf_startup (ProgressBarExample::Form1)
