using System;
using System.Windows.Forms;

namespace FormExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Form Example";
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);

      this.button.Parent = this;
      this.button.Text = "Close";
      this.button.Location = new System.Drawing.Point(10, 10);
      this.button.Click += delegate(object sender, EventArgs e) {
        this.Close();
      };

      this.FormClosing += delegate(object sender, FormClosingEventArgs e) {
        DialogResult dialogResult = MessageBox.Show("Do you really want to save and exit?", "Close Form", MessageBoxButtons.YesNoCancel, MessageBoxIcon.Question);
        e.Cancel = dialogResult == DialogResult.Cancel;
      };
    }


    private Button button = new Button();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
