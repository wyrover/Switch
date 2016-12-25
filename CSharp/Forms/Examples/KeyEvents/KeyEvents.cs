using System;
using System.Windows.Forms;

namespace KeyEventsExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "KeyEvents example";
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);
      this.KeyPreview = true;

      this.KeyDown += delegate(object sender, KeyEventArgs e) {
        this.label1.Text = string.Format("[Form] Event = KeyDown\n") +
        String.Format("KeyData = {0}\n", e.KeyData) +
        String.Format("KeyValue = {0:X}\n", e.KeyValue) +
        String.Format("KeyCode = {0}\n", e.KeyCode) +
        String.Format("Modifiers = {0}\n", e.Modifiers) +
        String.Format("Shift = {0}\n", e.Shift) +
        String.Format("Control = {0}\n", e.Control) +
        String.Format("Alt = {0}\n\n", e.Alt);
      };

      this.KeyPress += delegate(object sender, KeyPressEventArgs e) {
        this.label1.Text += string.Format("[Form] Event = KeyPress\n") +
        String.Format("KeyChar = {0}\n", e.KeyChar) +
        String.Format("value = {0}\n\n", Convert.ToInt32(e.KeyChar));
      };

      this.KeyUp += delegate(object sender, KeyEventArgs e) {
        this.label1.Text += string.Format("[Form] Event = KeyUp\n") +
        String.Format("KeyData = {0}\n", e.KeyData) +
        String.Format("KeyValue = {0:X}\n", e.KeyValue) +
        String.Format("KeyCode = {0}\n", e.KeyCode) +
        String.Format("Modifiers = {0}\n", e.Modifiers) +
        String.Format("Shift = {0}\n", e.Shift) +
        String.Format("Control = {0}\n", e.Control) +
        String.Format("Alt = {0}\n\n", e.Alt);
      };

      this.label1.Parent = this;
      this.label1.AutoSize = false;
      this.label1.BorderStyle = BorderStyle.Fixed3D;
      this.label1.BackColor = System.Drawing.Color.White;
      this.label1.Dock = DockStyle.Fill;
      this.label1.KeyDown += delegate(object sender, KeyEventArgs e) {
        this.label1.Text = string.Format("[Label] Event = KeyDown\n") +
        String.Format("KeyData = {0}\n", e.KeyData) +
        String.Format("KeyValue = {0:X}\n", e.KeyValue) +
        String.Format("KeyCode = {0}\n", e.KeyCode) +
        String.Format("Modifiers = {0}\n", e.Modifiers) +
        String.Format("Shift = {0}\n", e.Shift) +
        String.Format("Control = {0}\n", e.Control) +
        String.Format("Alt = {0}\n", e.Alt);
      };
    }

    private Label label1 = new Label();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
