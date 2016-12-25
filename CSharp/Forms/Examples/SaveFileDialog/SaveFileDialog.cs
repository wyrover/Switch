using System;
using System.Windows.Forms;

namespace SaveFileDialogExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "SaveFileDialog example";
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 350);
      this.MaximizeBox = false;

      this.buttonSaveImageFile.Location = new System.Drawing.Point(10, 10);
      this.buttonSaveImageFile.Size = new System.Drawing.Size(150, 23);
      this.buttonSaveImageFile.Parent = this;
      this.buttonSaveImageFile.Text = "Save Image File";
      this.buttonSaveImageFile.Click += this.OnButtonOpentTextFileClick;

      this.labelResult.Location = new System.Drawing.Point(170, 13);
      this.labelResult.AutoSize = true;
      this.labelResult.Parent = this;

      this.labelFileName.Location = new System.Drawing.Point(10, 50);
      this.labelFileName.AutoSize = true;
      this.labelFileName.Parent = this;
    }

    private void OnButtonOpentTextFileClick(object sender, EventArgs e) {
      SaveFileDialog sfd = new SaveFileDialog();

      sfd.Title = "Save Image Files";
      sfd.Filter = "Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff";
      DialogResult result = sfd.ShowDialog();
      this.labelResult.Text = string.Format("DialogResult = {0}", result);
      if (result == DialogResult.OK) {
        this.labelFileName.Text = sfd.FileName;
      } else
        this.labelFileName.Text = "";
    }

    private Button buttonSaveImageFile = new Button();
    private Label labelResult = new Label();
    private Label labelFileName = new Label();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
