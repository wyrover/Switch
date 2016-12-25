using System;
using System.Windows.Forms;

namespace PanelExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);
      this.Text = "Panel example";

      this.panel1.Parent = this;
      this.panel1.BorderStyle = BorderStyle.Fixed3D;
      this.panel1.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Bottom;
      this.panel1.Bounds = new System.Drawing.Rectangle(10, 10, 305, 460);

      this.panel2.Parent = this;
      this.panel2.BorderStyle = BorderStyle.Fixed3D;
      this.panel2.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.panel2.Bounds = new System.Drawing.Rectangle(325, 10, 305, 460);
    }

    private Panel panel1 = new Panel();
    private Panel panel2 = new Panel();
    }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
