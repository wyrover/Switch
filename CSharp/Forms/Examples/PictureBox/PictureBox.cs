using System;
using System.Windows.Forms;

namespace PictureBoxExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);
      this.Text = "PictureBox Example";
      this.BackColor = System.Drawing.Color.Black;

      this.pictureBox1.Parent = this;
      this.pictureBox1.SizeMode = PictureBoxSizeMode.CenterImage;
      this.pictureBox1.Dock = DockStyle.Fill;

      MenuItem[] fileMenu = new MenuItem[] {
        new MenuItem("Open...", new EventHandler(this.OnFileOpenSelected), Shortcut.CtrlO)
      };

      this.mainMenu.MenuItems.Add(new MenuItem("File", fileMenu));
      this.Menu = this.mainMenu;
    }

    private void OnFileOpenSelected(object sender, EventArgs e) {
      OpenFileDialog ofd = new OpenFileDialog();
      ofd.Title = "Open Image Files";
      ofd.Filter = "Bitmap Files|.bmp|Gif Files|.gif|Jpeg Files|.jpg;.jpeg|Png Files|.png|Tiff Files|.tif;.tiff|All Image Files|.bmp;.gif;.jpg;.jpeg;.png;.tif;.tiff";
      ofd.FilterIndex = 0;
      if (ofd.ShowDialog() == DialogResult.OK) {
        this.Text = string.Format("PictureBox Example [{0}]", System.IO.Path.GetFileName(ofd.FileName));
        this.pictureBox1.Image = new System.Drawing.Bitmap(ofd.FileName);
      }
    }

    private MainMenu mainMenu = new MainMenu();
    private PictureBox pictureBox1 = new PictureBox();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
