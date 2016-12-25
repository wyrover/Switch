using System;
using System.Windows.Forms;

namespace ColorsExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Colors example";
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 420);

      this.panelKnownColors.Parent = this;
      this.panelKnownColors.Location = new System.Drawing.Point(10, 10);
      this.panelKnownColors.Size = new System.Drawing.Size(300, 400);
      this.panelKnownColors.BorderStyle = BorderStyle.Fixed3D;
      this.panelKnownColors.AutoScroll = true;
      this.panelKnownColors.BackColor = System.Drawing.SystemColors.Window;

      int index = 0;
      foreach (System.Drawing.KnownColor knownColor in Enum.GetValues(typeof(System.Drawing.KnownColor))) {
        Panel panelKnownColor = new Panel();
        items.Add(panelKnownColor);
        panelKnownColor.Parent = this.panelKnownColors;
        panelKnownColor.Bounds = new System.Drawing.Rectangle(10, index * 30, 100, 30);
        panelKnownColor.BackColor = System.Drawing.Color.FromKnownColor(knownColor);
        panelKnownColor.Click += this.OnKnownColorClick;

        Label labelKnownColorName = new Label();
        items.Add(labelKnownColorName);
        labelKnownColorName.Parent = this.panelKnownColors;
        labelKnownColorName.AutoSize = true;
        labelKnownColorName.Location = new System.Drawing.Point(120, index * 30 + 10);
        labelKnownColorName.Text = knownColor.ToString();
        labelKnownColorName.Click += this.OnKnownColorNameClick;
        ++index;
      }

      this.panelUserDefinedColor.Parent = this;
      this.panelUserDefinedColor.Location = new System.Drawing.Point(330, 10);
      this.panelUserDefinedColor.Size = new System.Drawing.Size(300, 400);
      this.panelUserDefinedColor.BorderStyle = BorderStyle.Fixed3D;

      this.labelRed.Parent = this.panelUserDefinedColor;
      this.labelRed.Location = new System.Drawing.Point(90, 35);
      this.labelRed.AutoSize = true;
      this.labelRed.Text = "Red";

      this.numericUpDownRed.Parent = this.panelUserDefinedColor;
      this.numericUpDownRed.Bounds = new System.Drawing.Rectangle(150, 32, 50, 20);
      this.numericUpDownRed.Minimum = 0;
      this.numericUpDownRed.Maximum = 255;
      this.numericUpDownRed.ValueChanged += this.OnArgbChanged;

      this.labelGreen.Parent = this.panelUserDefinedColor;
      this.labelGreen.Location = new System.Drawing.Point(90, 65);
      this.labelGreen.AutoSize = true;
      this.labelGreen.Text = "Green";

      this.numericUpDownGreen.Parent = this.panelUserDefinedColor;
      this.numericUpDownGreen.Minimum = 0;
      this.numericUpDownGreen.Maximum = 255;
      this.numericUpDownGreen.Bounds = new System.Drawing.Rectangle(150, 62, 50, 20);
      this.numericUpDownGreen.ValueChanged += this.OnArgbChanged;

      this.labelBlue.Parent = this.panelUserDefinedColor;
      this.labelBlue.Location = new System.Drawing.Point(90, 95);
      this.labelBlue.AutoSize = true;
      this.labelBlue.Text = "Blue";

      this.numericUpDownBlue.Parent = this.panelUserDefinedColor;
      this.numericUpDownBlue.Minimum = 0;
      this.numericUpDownBlue.Maximum = 255;
      this.numericUpDownBlue.Bounds = new System.Drawing.Rectangle(150, 92, 50, 20);
      this.numericUpDownBlue.ValueChanged += this.OnArgbChanged;

      this.panelColorBox.Parent = this.panelUserDefinedColor;
      this.panelColorBox.Bounds = new System.Drawing.Rectangle(50, 150, 200, 200);
      this.panelColorBox.BackColor = System.Drawing.Color.FromArgb(255, (int)this.numericUpDownRed.Value, (int)this.numericUpDownGreen.Value, (int)this.numericUpDownBlue.Value);
      this.panelColorBox.BorderStyle = BorderStyle.Fixed3D;
         }
      
    private void OnKnownColorClick(object sender, EventArgs e) {
      System.Drawing.Color color = (sender as Panel).BackColor;
      this.numericUpDownRed.Value = color.R;
      this.numericUpDownGreen.Value = color.G;
      this.numericUpDownBlue.Value = color.B;
    }

    private void OnKnownColorNameClick(object sender, EventArgs e) {
      System.Drawing.Color color = System.Drawing.Color.FromName((sender as Label).Text);
      this.numericUpDownRed.Value = color.R;
      this.numericUpDownGreen.Value = color.G;
      this.numericUpDownBlue.Value = color.B;
    }

    private void OnArgbChanged(object sender, EventArgs e) {
      this.panelColorBox.BackColor = System.Drawing.Color.FromArgb(255, (int)this.numericUpDownRed.Value, (int)this.numericUpDownGreen.Value, (int)this.numericUpDownBlue.Value);
    }

    private Panel panelKnownColors = new Panel();
    private System.Collections.ArrayList items = new System.Collections.ArrayList();
    private Panel panelUserDefinedColor = new Panel();
    private Label labelRed = new Label();
    private Label labelGreen = new Label();
    private Label labelBlue = new Label();
    private NumericUpDown numericUpDownRed = new NumericUpDown();
    private NumericUpDown numericUpDownGreen = new NumericUpDown();
    private NumericUpDown numericUpDownBlue = new NumericUpDown();
    private Panel panelColorBox = new Panel();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
