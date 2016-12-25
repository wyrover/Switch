using System;
using System.Windows.Forms;

namespace HelloWorld {
  class MainForm : Form {
    public MainForm() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(400, 200);
      this.ClientSize = new System.Drawing.Size(300, 300);
      this.Text = "My first application";

      this.label.Parent = this;
      this.label.Text = "Hello, World!";
      this.label.AutoSize = true;
      this.label.Font = new System.Drawing.Font("Arial", 34, System.Drawing.FontStyle.Bold|System.Drawing.FontStyle.Italic);
      this.label.ForeColor = System.Drawing.Color.Green;
      this.label.Location = new System.Drawing.Point(5, 100);
    }

    private Label label = new Label();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new MainForm());
    }
  }
}
