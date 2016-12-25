using System;
using System.Windows.Forms;

namespace MessageBoxExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(400, 200);
      this.Text = "MessageBox example";

      this.buttonShowMessage.Parent = this;
      this.buttonShowMessage.Bounds = new System.Drawing.Rectangle(10, 10, 100, 25);
      this.buttonShowMessage.Text = "MessageBox";
      this.buttonShowMessage.Click += delegate(object sender, EventArgs e) {
        DialogResult result = MessageBox.Show("Hello, World!", "Message", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
        labelDialogResult.Text = string.Format("DialogResult = {0}", result);
      };

      this.labelDialogResult.Parent = this;
      this.labelDialogResult.Bounds = new System.Drawing.Rectangle(10, 60, 200, 30);
    }

    private Button buttonShowMessage = new Button();
    private Label labelDialogResult = new Label();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
