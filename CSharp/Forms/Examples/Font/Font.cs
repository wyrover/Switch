using System;
using System.Windows.Forms;

namespace FontExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Font example";
      this.Location = new System.Drawing.Point(200, 200);
      this.ClientSize = new System.Drawing.Size(680, 440);

      this.panelSample.Parent = this;
      this.panelSample.BorderStyle = BorderStyle.Fixed3D;
      this.panelSample.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right;
      this.panelSample.Bounds = new System.Drawing.Rectangle(20, 20, 640, 160);
      this.panelSample.BackColor = System.Drawing.Color.White;

      this.labelSample.Parent = this.panelSample;
      this.labelSample.AutoSize = true;
      this.labelSample.Location = new System.Drawing.Point(5, 5);
      //this.labelSample.Dock = DockStyle.Fill;

      this.labelFontFamlies.Parent = this;
      this.labelFontFamlies.AutoSize = true;
      this.labelFontFamlies.Location = new System.Drawing.Point(20, 200);
      this.labelFontFamlies.Text = "Font:";

      this.listBoxFontFamilies.Parent = this;
      this.listBoxFontFamilies.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.listBoxFontFamilies.Bounds = new System.Drawing.Rectangle(20, 220, 380, 200);
      this.listBoxFontFamilies.Click += this.OnFontClick;

      this.labelFontStyle.Parent = this;
      this.labelFontStyle.AutoSize = true;
      this.labelFontStyle.Anchor = AnchorStyles.Top | AnchorStyles.Right;
      this.labelFontStyle.Location = new System.Drawing.Point(410, 200);
      this.labelFontStyle.Text = "Font style:";

      this.listBoxFontStyle.Parent = this;
      this.listBoxFontStyle.Anchor = AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.listBoxFontStyle.Bounds = new System.Drawing.Rectangle(410, 220, 120, 200);
      this.listBoxFontStyle.Click += this.OnFontClick;

      this.labelFontSize.Parent = this;
      this.labelFontSize.AutoSize = true;
      this.labelFontSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
      this.labelFontSize.Location = new System.Drawing.Point(540, 200);
      this.labelFontSize.Text = "Size:";

      this.listBoxSize.Parent = this;
      this.listBoxSize.Anchor = AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.listBoxSize.Bounds = new System.Drawing.Rectangle(540, 220, 120, 200);
      this.listBoxSize.Click += this.OnFontClick;

      foreach (System.Drawing.FontFamily family in System.Drawing.FontFamily.Families) {
        this.listBoxFontFamilies.Items.Add(string.Format("{0}", family.Name));
      }
      this.listBoxFontFamilies.SelectedIndex = 30;

      this.listBoxFontStyle.Items.Add("Regular");
      this.listBoxFontStyle.Items.Add("Bold");
      this.listBoxFontStyle.Items.Add("Italic");
      this.listBoxFontStyle.Items.Add("Bold, Italic");
      this.listBoxFontStyle.SelectedIndex = 0;

      this.listBoxSize.Items.AddRange(new string [] {"8", "9", "10", "11", "12", "14", "16", "18", "20", "22", "24", "26", "28", "36", "48", "72"});
      this.listBoxSize.SelectedIndex = 4;

      this.labelSample.Text = "The quick brown fox jumps over the lazy dog.\nTHE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n0123456789+-/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\nàçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n\u04ea0\u04ea1\u04ea2\u04ea3\u04ea4\u04ea5\u04ea6\u04ea7\u04ea8\u04ea9\u04eaa\u04eab\u04eac\u04ead\u04eae\u04eaf\n\u04eb0\u04eb1\u04eb2\u04eb3\u04eb4\u04eb5\u04eb6\u04eb7\u04eb8\u04eb9\u04eba\u04ebb\u04ebc\u04ebd\u04ebe\u04ebf"; //"\n\U0001F428";
    }

    void OnFontClick(object sender, EventArgs e) {
      string fontName = (this.listBoxFontFamilies.SelectedItem as string);
      System.Drawing.FontStyle fontStyle = (System.Drawing.FontStyle)Enum.Parse(typeof(System.Drawing.FontStyle), (this.listBoxFontStyle.SelectedItem as string));
      float size = Single.Parse(this.listBoxSize.SelectedItem as string);
      this.labelSample.Font = new System.Drawing.Font(fontName, size, fontStyle);
    }

    private Panel panelSample = new Panel();
    private Label labelSample = new Label();
    private Label labelFontFamlies = new Label();
    private Label labelFontStyle = new Label();
    private Label labelFontSize = new Label();
    private ListBox listBoxFontFamilies = new ListBox();
    private ListBox listBoxFontStyle = new ListBox();
    private ListBox listBoxSize = new ListBox();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
