using System;
using System.Windows.Forms;

namespace GroupBoxExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);
      this.Text = "GroupBox example";

      this.groupBox1.Parent = this;
      this.groupBox1.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Bottom;
      this.groupBox1.Bounds = new System.Drawing.Rectangle(10, 20, 305, 450);

      this.groupBox2.Parent = this;
      this.groupBox2.Text = "Group 2";
      this.groupBox2.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.groupBox2.Bounds = new System.Drawing.Rectangle(325, 20, 305, 450);
    }

    private GroupBox groupBox1 = new GroupBox();
    private GroupBox groupBox2 = new GroupBox();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
