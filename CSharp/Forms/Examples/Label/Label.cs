using System;
using System.Windows.Forms;

namespace LabelExample {
  class Form1 : Form {
    [STAThread]
    // The main entry point for the application.
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }

    public Form1() {
      this.Text = "Form Example";
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(400, 200);

      this.label1.Parent = this;
      this.label1.Text = "http://www.gammasoft.com";
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(10, 10);
      this.label1.Cursor = Cursors.Hand;

      this.label1.MouseEnter += delegate(object sender, EventArgs e) {
        this.label1.ForeColor = System.Drawing.Color.Blue;
      };

      this.label1.Click += delegate(object sender, EventArgs e) {
        MessageBox.Show(string.Format("The label \"{0}\" was clicked", this.label1.Text), "Message", MessageBoxButtons.OK);
      };

      this.label1.MouseLeave += delegate(object sender, EventArgs e) {
        this.label1.ForeColor = System.Drawing.Color.Black;
      };
    }

    private Label label1 = new Label();
  }
}
