using System;
using System.Windows.Forms;

namespace CheckedListBoxExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "CheckedListBox example";
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(200, 240);

      this.checkedlistBox.Parent = this;
      this.checkedlistBox.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.checkedlistBox.Bounds = new System.Drawing.Rectangle(20, 20, 160, 200);

      for (int i = 1; i <= 1000; ++i)
        this.checkedlistBox.Items.Add(string.Format("Item {0}", i), i % 2 != 0);
    }

    private CheckedListBox checkedlistBox = new CheckedListBox();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
