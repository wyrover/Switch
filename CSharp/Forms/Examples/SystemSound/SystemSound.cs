using System;
using System.Media;
using System.Windows.Forms;

namespace SystemSoundExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(400, 200);
      this.Text = "SystemSounds example";

      this.buttonAsterisk.Parent = this;
      this.buttonAsterisk.Bounds = new System.Drawing.Rectangle(60, 50, 180, 30);
      this.buttonAsterisk.Text = "SystemSounds.Asterisk";
      this.buttonAsterisk.Click += delegate(object sender, EventArgs e) {
        SystemSounds.Asterisk.Play();
      };

      this.buttonBeep.Parent = this;
      this.buttonBeep.Bounds = new System.Drawing.Rectangle(60, 90, 180, 30);
      this.buttonBeep.Text = "SystemSounds.Beep";
      this.buttonBeep.Click += delegate(object sender, EventArgs e) {
        SystemSounds.Beep.Play();
      };

      this.buttonExclamation.Parent = this;
      this.buttonExclamation.Bounds = new System.Drawing.Rectangle(60, 130, 180, 30);
      this.buttonExclamation.Text = "SystemSounds.Exclamation";
      this.buttonExclamation.Click += delegate(object sender, EventArgs e) {
        SystemSounds.Exclamation.Play();
      };

      this.buttonHand.Parent = this;
      this.buttonHand.Bounds = new System.Drawing.Rectangle(60, 170, 180, 30);
      this.buttonHand.Text = "SystemSounds.Hand";
      this.buttonHand.Click += delegate(object sender, EventArgs e) {
        SystemSounds.Hand.Play();
      };

      this.buttonQuestion.Parent = this;
      this.buttonQuestion.Bounds = new System.Drawing.Rectangle(60, 210, 180, 30);
      this.buttonQuestion.Text = "SystemSounds.Question";
      this.buttonQuestion.Click += delegate(object sender, EventArgs e) {
        SystemSounds.Question.Play();
      };
    }

    private Button buttonAsterisk = new Button();
    private Button buttonBeep = new Button();
    private Button buttonExclamation = new Button();
    private Button buttonHand = new Button();
    private Button buttonQuestion = new Button();
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
