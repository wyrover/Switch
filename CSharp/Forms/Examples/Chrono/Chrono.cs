using System;
using System.Diagnostics;
using System.Windows.Forms;

namespace Chrono {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Chrono";
      this.Location = new System.Drawing.Point(400, 200);
      this.ClientSize = new System.Drawing.Size(275, 115);

      MenuItem[] actionMenu = new MenuItem[] {
        new MenuItem("Start", this.OnStartStopClick, Shortcut.CtrlS),
        new MenuItem("Pause", this.OnPauseResumeClick, Shortcut.CtrlP),
        new MenuItem("Reset", this.OnResetClick, Shortcut.CtrlR)
      };

      this.mainMenu.MenuItems.Add(new MenuItem("Action", actionMenu));
      this.Menu = this.mainMenu;

      this.chrono.Parent = this;
      this.chrono.BorderStyle = BorderStyle.Fixed3D;
      this.chrono.Bounds = new System.Drawing.Rectangle(87, 10, 100, 50);
      this.chrono.BackColor = System.Drawing.Color.LightGreen;
      this.chrono.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      this.chrono.Text = "00:00:00:000";

      this.startStop.Parent = this;
      this.startStop.Location = new System.Drawing.Point(10, 80);
      this.startStop.Text = "Start";
      this.startStop.Click += this.OnStartStopClick;

      this.pauseResume.Parent = this;
      this.pauseResume.Location = new System.Drawing.Point(100, 80);
      this.pauseResume.Text = "Pause";
      this.pauseResume.Enabled = false;
      this.pauseResume.Click += this.OnPauseResumeClick;

      this.reset.Parent = this;
      this.reset.Location = new System.Drawing.Point(190, 80);
      this.reset.Text = "Reset";
      this.reset.Enabled = false;
      this.reset.Click += this.OnResetClick;

      this.timer.Interval = 31;
      this.timer.Tick += this.OnTimerTick;
    }

    private void OnStartStopClick(object sender, EventArgs e) {
      if (this.stopwatch.IsRunning)
        this.stopwatch.Stop();
      else
        this.stopwatch.Start();

      this.timer.Enabled = true;
      this.pauseResume.Enabled = this.stopwatch.IsRunning;
      this.startStop.Text = this.stopwatch.IsRunning ? "Stop" : "Start";
      this.reset.Enabled = !this.timer.Enabled || !this.stopwatch.IsRunning;
    }

    private void OnPauseResumeClick(object sender, EventArgs e) {
      this.timer.Enabled = !this.timer.Enabled;
      this.pauseResume.Text = this.timer.Enabled ? "Pause" : "Resume";
      this.startStop.Enabled = this.timer.Enabled;
      this.reset.Enabled = !this.timer.Enabled || !this.stopwatch.IsRunning;
    }

    private void OnResetClick(object sender, EventArgs e) {
      this.timer.Enabled = false;
      this.stopwatch.Reset();
      this.chrono.Text = "00:00:00:000";
      this.startStop.Enabled = true;
      this.pauseResume.Enabled = false;
      this.reset.Enabled = false;
      this.startStop.Text = "Start";
      this.pauseResume.Text = "Pause";
    }

    private void OnTimerTick(object sender, EventArgs e) {
      TimeSpan ts = this.stopwatch.Elapsed;
      this.chrono.Text = String.Format("{0:D2}:{1:D2}:{2:D2}:{3:D3}", ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds);
    }

    private MainMenu mainMenu = new MainMenu();
    private Stopwatch stopwatch = new Stopwatch();
    private Label chrono = new Label();
    private Button startStop = new Button();
    private Button pauseResume = new Button();
    private Button reset = new Button();
    private Timer timer = new Timer();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
