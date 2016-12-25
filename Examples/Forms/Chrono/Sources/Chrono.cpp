#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows::FormsD;

namespace Chrono {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Chrono";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->ClientSize = System::Drawing::Size(300, 115);
      
      Array<MenuItem> actionMenu = {
        {"Start", {*this, &Form1::OnStartStopClick}, Shortcut::CmdS},
        {"Pause", {*this, &Form1::OnPauseResumeClick}, Shortcut::CmdP},
        {"Reset", {*this, &Form1::OnResetClick}, Shortcut::CmdR}
      };
      
      this->mainMenu.MenuItems().Add(MenuItem("Action", actionMenu));
      this->Menu = this->mainMenu;
      
      this->chrono.Parent = *this;
      this->chrono.BorderStyle = BorderStyle::Fixed3D;
      this->chrono.Bounds = System::Drawing::Rectangle(87, 10, 100, 50);
      this->chrono.BackColor = Drawing::Color::LightGreen;
      this->chrono.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->chrono.Text = "00:00:00.000";
      
      this->startStop.Parent = *this;
      this->startStop.Location = System::Drawing::Point(10, 80);
      this->startStop.Text = "Start";
      this->startStop.Click += {*this, &Form1::OnStartStopClick};
      
      this->pauseResume.Parent = *this;
      this->pauseResume.Location = System::Drawing::Point(100, 80);
      this->pauseResume.Text = "Pause";
      this->pauseResume.Enabled = false;
      this->pauseResume.Click += {*this, &Form1::OnPauseResumeClick};
      
      this->reset.Parent = *this;
      this->reset.Location = System::Drawing::Point(190, 80);
      this->reset.Text = "Reset";
      this->reset.Enabled = false;
      this->reset.Click += {*this, &Form1::OnResetClick};
      
      this->timer.Interval = 31;
      this->timer.Tick += {*this, &Form1::OnTimerTick};
    }
    
  private:
    void OnStartStopClick(const object& sender, const EventArgs& e) {
      if (this->stopwatch.IsRunning)
        this->stopwatch.Stop();
      else
        this->stopwatch.Start();
      
      this->timer.Enabled = true;
      this->pauseResume.Enabled = this->stopwatch.IsRunning;
      this->startStop.Text = this->stopwatch.IsRunning ? "Stop" : "Start";
      this->reset.Enabled = !this->timer.Enabled || !this->stopwatch.IsRunning;
    }
    
    void OnPauseResumeClick(const object& sender, const EventArgs& e) {
      this->timer.Enabled = !this->timer.Enabled;
      this->pauseResume.Text = this->timer.Enabled ? "Pause" : "Resume";
      this->startStop.Enabled = this->timer.Enabled;
      this->reset.Enabled = !this->timer.Enabled || !this->stopwatch.IsRunning;
    }
    
    void OnResetClick(const object& sender, const EventArgs& e) {
      this->timer.Enabled = false;
      this->stopwatch.Reset();
      this->chrono.Text = "00:00:00.000";
      this->startStop.Enabled = true;
      this->pauseResume.Enabled = false;
      this->reset.Enabled = false;
      this->startStop.Text = "Start";
      this->pauseResume.Text = "Pause";
    }
    
    void OnTimerTick(const object& sender, const EventArgs& e) {
      TimeSpan ts = this->stopwatch.Elapsed;
      this->chrono.Text = String::Format("{0:D2}:{1:D2}:{2:D2}:{3:D3}", ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds);
    }
    
    MainMenu mainMenu;
    Stopwatch stopwatch;
    Label chrono;
    Button startStop;
    Button pauseResume;
    Button reset;
    Timer timer;
  };
}

pcf_startup (Chrono::Form1)
