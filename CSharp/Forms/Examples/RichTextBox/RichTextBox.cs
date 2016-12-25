using System;
using System.Windows.Forms;

namespace RichTextBoxExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "RichTextBox example";
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);

      this.text.Parent = this;
      this.text.Font = new System.Drawing.Font(System.Drawing.FontFamily.GenericMonospace, 10);
      System.Windows.Forms.Screen[] screens = System.Windows.Forms.Screen.AllScreens;
      for (int i = 0; i < screens.Length; ++i)
        this.text.Text += string.Format("Device {0} :\n  - Primary = {1}\n  - Name = {2}\n  - Screen = {3}\n  - Area = {4}\n\n", i, screens[i].Primary, screens[i].DeviceName, screens[i].Bounds, screens[i].WorkingArea);
      this.text.Bounds = new System.Drawing.Rectangle(0, 0, this.Width, this.Height);
      this.text.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
    }

    private RichTextBox text = new RichTextBox();
    }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
