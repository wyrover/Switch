using System;
using System.Windows.Forms;

namespace FormApp {
  class Form1 : Form {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }

    Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(200, 100);
      Button c = new Button();
      System.Diagnostics.Debug.WriteLine("Name = {0}", c.Size, null);
 
      /*
      this.ClientSize = new System.Drawing.Size(200, 100);
      this.BackColor = System.Drawing.Color.Cyan;

      this.label.Parent = this;
      this.label.Text = "Hello, World!";
      this.label.Font = new System.Drawing.Font("Arial", 16);
      this.label.Location = new System.Drawing.Point(1, 1);
      this.label.Size = new System.Drawing.Size(198, 98);
      this.label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
      this.label.BackColor = System.Drawing.Color.Orange;
      */
    }

    //private Label label = new Label();
  }
}
