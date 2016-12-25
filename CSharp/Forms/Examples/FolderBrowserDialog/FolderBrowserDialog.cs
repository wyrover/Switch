using System;
using System.Windows.Forms;

namespace FolderBrowserDialogExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "FolderBrowserDialog example";
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 350);
      this.MaximizeBox = false;

      this.buttonOpenImageFile.Location = new System.Drawing.Point(10, 10);
      this.buttonOpenImageFile.Size = new System.Drawing.Size(150, 23);
      this.buttonOpenImageFile.Parent = this;
      this.buttonOpenImageFile.Text = "Open Images Folder";
      this.buttonOpenImageFile.Click += delegate(object sender, EventArgs e) {
        FolderBrowserDialog fbd = new FolderBrowserDialog();

        DialogResult result = fbd.ShowDialog();
        labelResult.Text = string.Format("DialogResult = {0}", result);

        if (result == DialogResult.OK) {
          labelFolderPath.Text = fbd.SelectedPath;
        }
      };

      this.labelResult.Location = new System.Drawing.Point(170, 13);
      this.labelResult.AutoSize = true;
      this.labelResult.Parent = this;

      this.labelFolderPath.Location = new System.Drawing.Point(10, 50);
      this.labelFolderPath.AutoSize = true;
      this.labelFolderPath.Parent = this;
    }

    private Button buttonOpenImageFile = new Button();
    private Label labelResult = new Label();
    private Label labelFolderPath = new Label();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
