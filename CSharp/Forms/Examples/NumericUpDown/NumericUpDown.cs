using System;
using System.Windows.Forms;

namespace NumericUpDownExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(300, 200);
      this.Text = "NumericUpDown Example";

      this.numericUpDown1.Parent = this;
      this.numericUpDown1.Location = new System.Drawing.Point(100, 50);

      this.numericUpDown2.Parent = this;
      this.numericUpDown2.Location = new System.Drawing.Point(100, 100);
      this.numericUpDown2.Minimum = 10.0m;
      this.numericUpDown2.Maximum = 11.0m;
      this.numericUpDown2.Increment = 0.01m;
      this.numericUpDown2.DecimalPlaces = 2;
    }

    private NumericUpDown numericUpDown1 = new NumericUpDown();
    private NumericUpDown numericUpDown2 = new NumericUpDown();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
