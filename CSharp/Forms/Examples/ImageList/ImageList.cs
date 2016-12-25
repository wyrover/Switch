using System;
using System.Windows.Forms;

namespace ImageListExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(300, 250);
      this.Text = "ImageList Example";
      this.MaximizeBox = false;

      this.pictureBox.Parent = this;
      this.pictureBox.BorderStyle = BorderStyle.Fixed3D;
      this.pictureBox.BackColor = System.Drawing.Color.White;
      this.pictureBox.Bounds = new System.Drawing.Rectangle(75, 25, 152, 152);
      this.pictureBox.SizeMode = PictureBoxSizeMode.CenterImage;

      this.buttonPrevious.Parent = this;
      this.buttonPrevious.Text = "<";
      this.buttonPrevious.Location = new System.Drawing.Point(75, 200);
      this.buttonPrevious.Click += delegate(object sender, EventArgs e) {
        if (this.currentImageIndex > 0) {
          this.currentImageIndex--;
          this.pictureBox.Image = this.imageList.Images[currentImageIndex];
        }
        this.buttonPrevious.Enabled = this.currentImageIndex > 0;
        this.buttonNext.Enabled = this.currentImageIndex < this.imageList.Images.Count - 1;
      };

      this.buttonNext.Parent = this;
      this.buttonNext.Text = ">";
      this.buttonNext.Location = new System.Drawing.Point(152, 200);
      this.buttonNext.Click += delegate(object sender, EventArgs e) {
        if (this.currentImageIndex < this.imageList.Images.Count - 1) {
          this.currentImageIndex++;
          this.pictureBox.Image = this.imageList.Images[currentImageIndex];
        }
        this.buttonPrevious.Enabled = this.currentImageIndex > 0;
        this.buttonNext.Enabled = this.currentImageIndex < this.imageList.Images.Count - 1;
      };

      this.imageList.ImageSize = new System.Drawing.Size(128, 128);
      this.imageList.ColorDepth = ColorDepth.Depth32Bit;
      FolderBrowserDialog fbd = new FolderBrowserDialog();
      if (fbd.ShowDialog() == DialogResult.OK) {
        System.IO.DirectoryInfo directoryInfo = new System.IO.DirectoryInfo(fbd.SelectedPath);
        System.IO.FileInfo[] files = directoryInfo.GetFiles("*.jpg");
        foreach (System.IO.FileInfo file in files) {
          string fileName = System.IO.Path.Combine(fbd.SelectedPath, System.IO.Path.GetFileName(file.Name));
          this.imageList.Images.Add(new System.Drawing.Bitmap(fileName));
        }
      }

      this.buttonPrevious.Enabled = false;
      this.buttonNext.Enabled = this.imageList.Images.Count != 0;

      if (this.imageList.Images.Count != 0)
        this.pictureBox.Image = this.imageList.Images[0];
    }

    private ImageList imageList = new ImageList();
    private PictureBox pictureBox = new PictureBox();
    private Button buttonPrevious = new Button();
    private Button buttonNext = new Button();
    private int currentImageIndex = 0;
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
