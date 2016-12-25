using System;
using System.Windows.Forms;

namespace FormTimerExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Timer Example";
      this.Location = new System.Drawing.Point(400, 300);
      this.ClientSize = new System.Drawing.Size(300, 165);

      this.label.Parent = this;
      this.label.Text = string.Format("{0}", this.count);
      this.label.Location = new System.Drawing.Point(10, 10);

      this.timer.Interval = 100;
      this.timer.Tick += delegate(object sender, EventArgs e) {
        this.label.Text = string.Format("{0}", ++this.count);
      };

      this.button.Parent = this;
      this.button.Text = "Start";
      this.button.Location = new System.Drawing.Point(10, 100);

      this.button.Click += delegate(object sender, EventArgs e) {
        this.timer.Enabled = !this.timer.Enabled;
        this.button.Text = this.timer.Enabled ? "Stop" : "Start";
      };
    }

    private Label label = new Label();
    private Button button = new Button();
    private Timer timer = new Timer();
    private int count = 0;
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
