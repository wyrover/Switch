using System;
using System.Windows.Forms;

namespace DockedControlsExample {
  class Form1 : Form {
    public Form1() {
      this.Layout += delegate (object sender, LayoutEventArgs e) {
        Console.WriteLine("Layout on  {{{0} - {1} - {2}}}", e.AffectedComponent, e.AffectedControl, e.AffectedProperty);
      };

      //this.SuspendLayout();
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);
      this.Text = "Docked controls example";

      this.panel4.Parent = this;
      this.panel4.BackColor = System.Drawing.SystemColors.ControlLightLight;
      this.panel4.AutoScroll = true;
      this.panel4.Dock = DockStyle.Fill;

      this.panel3.Parent = this;
      this.panel3.BackColor = System.Drawing.SystemColors.ControlLight;
      this.panel3.Dock = DockStyle.Left;
      this.panel3.Width = 150;

      this.panel2.Parent = this;
      this.panel2.BackColor = System.Drawing.SystemColors.ControlDark;
      this.panel2.Dock = DockStyle.Left;
      this.panel2.Width = 120;

      this.panel1.Parent = this;
      this.panel1.BackColor = System.Drawing.SystemColors.Control;
      this.panel1.Dock = DockStyle.Top;
      this.panel1.Height = 32;

      for (int i = buttons.Length-1; i >= 0; i--) {
        this.buttons[i] = new Button();
        this.buttons[i].Parent = this.panel1;
        this.buttons[i].Text = string.Format("{0}", i+1);
        this.buttons[i].Width = 28;
        this.buttons[i].Dock = DockStyle.Left;
      }

      for (int i =  labels.Length-1; i >= 0; i--) {
        this.labels[i] = new Label();
        this.labels[i].Parent = this.panel4;
        this.labels[i].Text = string.Format("label {0}", i+1);
        this.labels[i].Dock = DockStyle.Top;
      }
      //this.ResumeLayout(false);
      //this.PerformLayout();
    }

    private Panel panel1 = new Panel();
    private Button[] buttons  = new Button[20];
    private Panel panel2 = new Panel();
    private Panel panel3 = new Panel();
    private Panel panel4 = new Panel();
    private Label[] labels = new Label[40];
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
