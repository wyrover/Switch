using System;
using System.Windows.Forms;

namespace FontFamilyExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "FontFamily example";
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(400, 500);

      this.labelNbFontFamlies.Parent = this;
      this.labelNbFontFamlies.AutoSize = true;
      this.labelNbFontFamlies.Location = new System.Drawing.Point(20, 20);

      this.listBoxFontFamilies.Parent = this;
      this.listBoxFontFamilies.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.listBoxFontFamilies.Bounds = new System.Drawing.Rectangle(20, 60, 360, 420);
      this.listBoxFontFamilies.Sorted = true;

      System.Drawing.FontFamily[] fontFamilies = System.Drawing.FontFamily.Families;
      this.labelNbFontFamlies.Text = string.Format("There are {0} FontFamilies :", fontFamilies.Length);
      foreach (System.Drawing.FontFamily fontFamily in fontFamilies)
        this.listBoxFontFamilies.Items.Add(fontFamily.Name);
    }

    private Label labelNbFontFamlies = new Label();
    private ListBox listBoxFontFamilies = new ListBox();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
