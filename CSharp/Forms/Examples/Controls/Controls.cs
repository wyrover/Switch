using System;
using System.Windows.Forms;

namespace ControlsExample {
  class Form1 : Form {
    public Form1() {
      this.label.Location = new System.Drawing.Point(10, 10);
      this.label.AutoSize = true;
      this.label.Text = "label";

      this.button.Location = new System.Drawing.Point(10, 35);
      this.button.Text = "button";

      this.progressBar.Location = new System.Drawing.Point(10, 70);
      this.progressBar.Style = ProgressBarStyle.Continuous;
      this.progressBar.Value = 62;

      this.Controls.Add(this.label);
      this.Controls.Add(this.button);
      this.Controls.Add(this.progressBar);

      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(300, 200);
    }

    private Label label = new Label();
    private Button button = new Button();
    private ProgressBar progressBar = new ProgressBar();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
