using System;
using System.Windows.Forms;

namespace TabControlExample {
  // The main entry point for the application.
  class Form1 : Form {
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }

    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);
      this.Text = "TabControl example";

      this.tabControl.Parent = this;
      this.tabControl.Bounds = new System.Drawing.Rectangle(10, 10, 620, 460);
      this.tabControl.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;

      this.tabPage1.Parent = this.tabControl;
      this.tabPage1.Text = "Page 1";
      this.tabPage1.UseVisualStyleBackColor = true;

      this.button1.Parent = this.tabPage1;
      this.button1.Location = new System.Drawing.Point(10, 40);
      this.button1.Text = "Button 1";

      this.button2.Parent = this.tabPage1;
      this.button2.Location = new System.Drawing.Point(10, 70);
      this.button2.Text = "Button 2";

      this.label1.Parent = this.tabPage1;
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(10, 10);
      this.label1.Text = "Page 1 say : Hello World!";

      this.textBox1.Parent = this.tabPage1;
      this.textBox1.Location = new System.Drawing.Point(10, 100);

      this.tabPage2.Parent = this.tabControl;
      this.tabPage2.Text = "This is the secong Page";
      this.tabPage2.UseVisualStyleBackColor = true;

      this.label2.Parent = this.tabPage2;
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(10, 40);
      this.label2.Text = "Page 2 say : Hello World, too!";

      this.tabPage3.Parent = this.tabControl;
      this.tabPage3.Text = "Page 3";
      this.tabPage3.UseVisualStyleBackColor = true;

      this.label3.Parent = this.tabPage3;
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(10, 70);
      this.label3.Text = "Page 3 say : Hello World, too as page 2!";

      this.label4.Parent = this.tabPage1;
      this.label4.Location = new System.Drawing.Point(500, 400);
      this.label4.Text = "The end...";
      this.label4.AutoSize = true;
      //this.label4.Anchor = AnchorStyles.Right | AnchorStyles.Bottom;
    }

    private TabControl tabControl = new TabControl();
    private TabPage tabPage1 = new TabPage();
    private TabPage tabPage2 = new TabPage();
    private TabPage tabPage3 = new TabPage();
    private Button button1 = new Button();
    private Button button2 = new Button();
    private Label label1 = new Label();
    private Label label2 = new Label();
    private Label label3 = new Label();
    private Label label4 = new Label();
    private TextBox textBox1 = new TextBox();
  }
}
