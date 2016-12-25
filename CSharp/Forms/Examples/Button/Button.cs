using System;
using System.Windows.Forms;

namespace ButtonExample {
  class Form1 : Form {
    [STAThread]
    // The main entry point for the application.
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }

    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(400, 200);
      this.ClientSize = new System.Drawing.Size(300, 300);
      this.Text = "Button example";

      this.buttonNone.Parent = this;
      this.buttonNone.Text = "None";
      this.buttonNone.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
      this.buttonNone.Left = 125;
      this.buttonNone.Top = 265;
      this.buttonNone.Enabled = false;
      this.buttonNone.AutoSize = true;

      this.buttonClose.Parent = this;
      this.buttonClose.Text = "Close";
      this.buttonClose.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
      this.buttonClose.Left = 215;
      this.buttonClose.Top = 265;
      this.AcceptButton = this.buttonClose;
      this.buttonClose.Click += delegate(object sender, EventArgs e) {
        this.Close();
      };

      this.buttonTooSmallForText.Parent = this;
      this.buttonTooSmallForText.Text = "Button too small For Text...";
      this.buttonTooSmallForText.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
      this.buttonTooSmallForText.Left = 35;
      this.buttonTooSmallForText.Top = 265;

      this.line.Parent = this;
      this.line.BorderStyle = BorderStyle.Fixed3D;
      this.line.Anchor = AnchorStyles.Left | AnchorStyles.Bottom | AnchorStyles.Right;
      this.line.Bounds = new System.Drawing.Rectangle(10, 253, 280, 2);

      this.buttonBig.Parent = this;
      this.buttonBig.Bounds = new System.Drawing.Rectangle(10, 10, 200, 200);
      this.buttonBig.Text = "This is a very big button, that contains a lot of text...\n\nEnd more...";
      this.buttonBig.UseWaitCursor = true;
    }

    private Label line = new Label();
    private Button buttonNone = new Button();
    private Button buttonClose = new Button();
    private Button buttonTooSmallForText = new Button();
    private Button buttonBig = new Button();
  }
}
