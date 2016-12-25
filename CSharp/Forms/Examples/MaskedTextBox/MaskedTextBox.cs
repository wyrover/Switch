using System;
using System.Windows.Forms;

namespace MaskedTextBoxExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "MaskedTextBox example";
      this.Location = new System.Drawing.Point(300, 235);

      this.labelUser.Parent = this;
      this.labelUser.AutoSize = true;
      this.labelUser.Text = "User";
      this.labelUser.Location = new System.Drawing.Point(10, 20);

      this.labelPassword.Parent = this;
      this.labelPassword.AutoSize = true;
      this.labelPassword.Text = "Password";
      this.labelPassword.Location = new System.Drawing.Point(10, 50);

      this.textUser.Parent = this;
      this.textUser.Text = "john.doe@anonymous.com";
      this.textUser.Bounds = new System.Drawing.Rectangle(100, 16, 180, 25);

      this.labelTextPassword.Parent = this;
      this.labelTextPassword.AutoSize = true;
      this.labelTextPassword.Bounds = new System.Drawing.Rectangle(100, 76, 180, 25);

      this.textPassword.Parent = this;
      this.textPassword.TextChanged += delegate(object sender, EventArgs e) {
        labelTextPassword.Text = this.textPassword.Text;
      };
      this.textPassword.UseSystemPasswordChar = true;
      this.textPassword.Text = "grandmother";
      this.textPassword.Bounds = new System.Drawing.Rectangle(100, 46, 180, 25);
    }

    private Label labelUser = new Label();
    private Label labelPassword = new Label();
    private TextBox textUser = new TextBox();
    private TextBox textPassword = new TextBox();
    private Label labelTextPassword = new Label();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
