using System;
using System.Windows.Forms;

namespace ListBoxExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "ListBox example";
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(360, 240);

      this.listBox1.Parent = this;
      this.listBox1.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Bottom;
      this.listBox1.Bounds = new System.Drawing.Rectangle(20, 20, 150, 200);
      this.listBox1.DoubleClick += delegate(object sender, EventArgs e) {
        if (this.listBox1.SelectedIndex != -1) {
          this.listBox2.Items.Add(this.listBox1.SelectedItem);
          this.listBox2.SelectedIndex = this.listBox2.Items.Count-1;
          this.listBox1.Items.Remove(this.listBox1.SelectedItem);
        }
      };

      this.listBox2.Parent = this;
      this.listBox2.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Bottom | AnchorStyles.Right;
      this.listBox2.Bounds = new System.Drawing.Rectangle(190, 20, 150, 200);
      this.listBox2.DoubleClick += delegate(object sender, EventArgs e) {
        if (this.listBox2.SelectedIndex != -1) {
          this.listBox1.Items.Add(this.listBox2.SelectedItem);
          this.listBox1.SelectedIndex = this.listBox1.Items.Count-1;
          this.listBox2.Items.Remove(this.listBox2.SelectedItem);
        }
      };

      this.listBox1.Items.AddRange(new string[] {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"});
    }

    private ListBox listBox1 = new ListBox();
    private ListBox listBox2 = new ListBox();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
