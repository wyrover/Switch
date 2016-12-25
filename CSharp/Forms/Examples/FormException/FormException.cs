using System;
using System.Windows.Forms;

namespace FormExceptionExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Exception example";
      this.Location = new System.Drawing.Point(300, 200);

      this.buttonHandledException.Parent = this;
      this.buttonHandledException.Text = "Handled Exception";
      this.buttonHandledException.Location = new System.Drawing.Point(10, 10);
      this.buttonHandledException.Size = new System.Drawing.Size(130, 25);
      this.buttonHandledException.Click += delegate(object sender, EventArgs e) {
        try {
          throw new InvalidOperationException();
        } catch (Exception exception) {
          MessageBox.Show(exception.Message, "Exception occured");
        }
      };

      this.buttonUnhandledException.Parent = this;
      this.buttonUnhandledException.Text = "Unhandled Exception";
      this.buttonUnhandledException.Location = new System.Drawing.Point(10, 40);
      this.buttonUnhandledException.Size = new System.Drawing.Size(130, 25);
      this.buttonUnhandledException.Click += delegate(object sender, EventArgs e) {
        throw new InvalidOperationException();
      };
    }

    private Button buttonHandledException = new Button();
    private Button buttonUnhandledException = new Button();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
