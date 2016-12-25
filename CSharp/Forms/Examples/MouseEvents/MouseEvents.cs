using System;
using System.Windows.Forms;

namespace MoueEventsExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "MouseEvents example";
      this.Location = new System.Drawing.Point(300, 50);
      this.ClientSize = new System.Drawing.Size(640, 825);

      this.panel1.Parent = this;
      this.panel1.BorderStyle = BorderStyle.Fixed3D;
      this.panel1.BackColor = System.Drawing.Color.White;
      this.panel1.Dock = DockStyle.Fill;

      this.panel1.KeyDown += delegate(object sender, KeyEventArgs e) {
        this.label1.Text = EventToString("panel1", "KeyDown", e);
      };
      this.panel1.KeyPress += delegate(object sender, KeyPressEventArgs e) {
        this.label1.Text += EventToString("panel1", "KeyPress", e);
      };
      this.panel1.KeyUp += delegate(object sender, KeyEventArgs e) {
        this.label1.Text += EventToString("panel1", "KeyUp", e);
      };
      this.panel1.MouseEnter += delegate(object sender, EventArgs e) {
        this.label1.Text += EventToString("panel1", "MouseEnter", e);
      };
      this.panel1.MouseDown += delegate(object sender, MouseEventArgs e) {
        this.label1.Text = EventToString("panel1", "MouseDown", e);
      };
      this.panel1.Click += delegate(object sender, EventArgs e) {
        this.label1.Text += EventToString("panel1", "Click", e);
      };
      this.panel1.MouseClick += delegate(object sender, MouseEventArgs e) {
        this.label1.Text += EventToString("panel1", "MouseClick", e);
      };
      this.panel1.DoubleClick += delegate(object sender, EventArgs e) {
        this.label1.Text += EventToString("panel1", "DoubleClick", e);
      };
      this.panel1.MouseDoubleClick += delegate(object sender, MouseEventArgs e) {
        this.label1.Text += EventToString("panel1", "MouseDoubleClick", e);
      };
      this.panel1.MouseUp += delegate(object sender, MouseEventArgs e) {
        this.label1.Text += EventToString("panel1", "MouseUp", e);
      };
      this.panel1.MouseWheel += delegate(object sender, MouseEventArgs e) {
        this.label1.Text = EventToString("panel1", "MouseWheel", e);
      };
      this.panel1.MouseLeave += delegate(object sender, EventArgs e) {
        this.label1.Text = EventToString("panel1", "MouseLeave", e);
      };

      this.label1.Parent = this;
      this.label1.AutoSize = false;
      this.label1.Size = new System.Drawing.Size(640, 780);
      this.label1.BorderStyle = BorderStyle.Fixed3D;
      this.label1.BackColor = System.Drawing.Color.White;
      this.label1.Dock = DockStyle.Top;

      this.label1.KeyDown += delegate(object sender, KeyEventArgs e) {
        this.label1.Text = EventToString("label1", "KeyDown", e);
      };
      this.label1.KeyPress += delegate(object sender, KeyPressEventArgs e) {
        this.label1.Text += EventToString("label1", "KeyPress", e);
      };
      this.label1.KeyUp += delegate(object sender, KeyEventArgs e) {
        this.label1.Text += EventToString("label1", "KeyUp", e);
      };
      this.label1.MouseEnter += delegate(object sender, EventArgs e) {
        this.label1.Text += EventToString("label1", "MouseEnter", e);
      };
      this.label1.MouseDown += delegate(object sender, MouseEventArgs e) {
        this.label1.Text = EventToString("label1", "MouseDown", e);
      };
      this.label1.Click += delegate(object sender, EventArgs e) {
        this.label1.Text += EventToString("label1", "Click", e);
      };
      this.label1.MouseClick += delegate(object sender, MouseEventArgs e) {
        this.label1.Text += EventToString("label1", "MouseClick", e);
      };
      this.label1.DoubleClick += delegate(object sender, EventArgs e) {
        this.label1.Text += EventToString("label1", "DoubleClick", e);
      };
      this.label1.MouseDoubleClick += delegate(object sender, MouseEventArgs e) {
        this.label1.Text += EventToString("label1", "MouseDoubleClick", e);
      };
      this.label1.MouseUp += delegate(object sender, MouseEventArgs e) {
        this.label1.Text += EventToString("label1", "MouseUp", e);
      };
      this.label1.MouseWheel += delegate(object sender, MouseEventArgs e) {
        this.label1.Text = EventToString("label1", "MouseWheel", e);
      };
      this.label1.MouseLeave += delegate(object sender, EventArgs e) {
        this.label1.Text = EventToString("label1", "MouseLeave", e);
      };

      this.button1.Parent = this.panel1;
      this.button1.Location = new System.Drawing.Point(10, 10);
      this.button1.Text = "Button";

      this.label2.Parent = this.panel1;
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(120, 10);

      this.MouseMove += this.OnMouseMove;
      this.label1.MouseMove += this.OnMouseMove;
      this.panel1.MouseMove += this.OnMouseMove;
      this.label2.MouseMove += this.OnMouseMove;
      this.button1.MouseMove += this.OnMouseMove;
    }

    private static string EventToString(string n, string e, KeyEventArgs a) {
      return string.Format("[{0}]\n", n) +
        string.Format("  Event = {0}\n", e) +
        String.Format("  KeyData = {0}\n", a.KeyData) +
        String.Format("  KeyValue = {0:X}\n", a.KeyValue) +
        String.Format("  KeyCode = {0}\n", a.KeyCode) +
        string.Format("  Modifiers = {0}\n", a.Modifiers) +
        String.Format("  Shift = {0}\n", a.Shift) +
        String.Format("  Control = {0}\n", a.Control) +
        String.Format("  Alt = {0}\n\n", a.Alt);
    }

    private static string EventToString(string n, string e, KeyPressEventArgs a) {
      return string.Format("[{0}]\n", n) +
        string.Format("  Event = {0}\n", e) +
        String.Format("  KeyChar = {0}\n", a.KeyChar) +
        String.Format("  value = {0}\n\n", Convert.ToInt32(a.KeyChar));
    }

    private static string EventToString(string n, string e, MouseEventArgs a) {
      return string.Format("[{0}]\n", n) +
        string.Format("  Event = {0}\n", e) +
        String.Format("  Button = {0}\n", a.Button) +
        String.Format("  Location = {0:X}\n", a.Location) +
        String.Format("  Clicks = {0}\n", a.Clicks) +
        String.Format("  Delta = {0}\n", a.Delta) +
        String.Format("  X = {0}\n", a.X) +
        String.Format("  Y = {0}\n\n", a.Y);
    }

    private static string EventToString(string n, string e, EventArgs a) {
      return string.Format("[{0}]\n", n) +
        string.Format("  Event = {0}\n", e);
    }

    private void OnMouseMove(object sender, MouseEventArgs e) {
      this.label2.Text = string.Format("Mouse Location {0}", e.Location);
    }

    private Label label1 = new Label();
    private Panel panel1 = new Panel();
    private Button button1 = new Button();
    private Label label2 = new Label();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
