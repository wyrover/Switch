using System;
using System.Windows.Forms;

namespace OpenFileExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "OpenFileDialog example";
      this.Bounds = new System.Drawing.Rectangle(300, 200, 650, 375);

      this.buttonOpenImageFile.Location = new System.Drawing.Point(10, 10);
      this.buttonOpenImageFile.Size = new System.Drawing.Size(150, 23);
      this.buttonOpenImageFile.Parent = this;
      this.buttonOpenImageFile.Text = "Open Image File";
      this.buttonOpenImageFile.Click += this.OnButtonOpentTextFileClick;

      this.labelResult.Location = new System.Drawing.Point(170, 13);
      this.labelResult.AutoSize = true;
      this.labelResult.Parent = this;

      this.listBoxFileNames.Location = new System.Drawing.Point(10, 40);
      this.listBoxFileNames.Size = new System.Drawing.Size(620, 300);
      this.listBoxFileNames.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.listBoxFileNames.Parent = this;
    }

    private void OnButtonOpentTextFileClick(object sender, EventArgs e) {
      OpenFileDialog ofd = new OpenFileDialog();

      ofd.Title = "Open Image Files";
      ofd.Filter = "Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff";
      ofd.Multiselect = true;
      DialogResult result = ofd.ShowDialog();
      labelResult.Text = string.Format("DialogResult = {0}", result);

      if (result == DialogResult.OK) {
        foreach (string fileName in ofd.FileNames)
          listBoxFileNames.Items.Add(fileName);
      } else {
        listBoxFileNames.Items.Clear();
      }
    }

    private Button buttonOpenImageFile = new Button();
    private Label labelResult = new Label();
    private ListBox listBoxFileNames = new ListBox();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
