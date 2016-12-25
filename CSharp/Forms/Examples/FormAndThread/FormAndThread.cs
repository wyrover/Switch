using System;
using System.Diagnostics;
using System.Threading;
using System.Windows.Forms;

namespace FormAndThreadExample {
  class Form1 : Form {
    // The main entry point for the application.
    [STAThread]
    public static void Main() {
      Debug.WriteLine("ThreadId = {0}, Main", Thread.CurrentThread.ManagedThreadId);
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }

    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(300, 200);
      this.Text = "Form and thread";
      Debug.WriteLine("ThreadId = {0}, Form creation", Thread.CurrentThread.ManagedThreadId);
      this.FormClosing += delegate(object sender, FormClosingEventArgs e) {
        this.thread.Abort();
      };

      this.progressBar.Parent = this;
      this.progressBar.Style = ProgressBarStyle.Continuous;
      this.progressBar.Location = new System.Drawing.Point(100, 100);

      this.button.Parent = this;
      this.button.Text = "Reset";
      this.button.Location = new System.Drawing.Point(110, 150);
      this.button.Click += delegate(object sender, EventArgs e) {
        this.progressBar.Value = this.progressBar.Minimum;
      };

      this.thread = new Thread(new ThreadStart(delegate() {
        Thread.Sleep(1000);
        while (true) {
          this.Invoke(new MethodInvoker(delegate() {
            this.progressBar.Value = this.progressBar.Value < this.progressBar.Maximum ? this.progressBar.Value + 1 : this.progressBar.Value = this.progressBar.Minimum;
            Debug.WriteLine("ThreadId = {0}, progressBar.Value = {1}", Thread.CurrentThread.ManagedThreadId, this.progressBar.Value);
          }));
          Thread.Sleep(50);
        }
      }));
      thread.Start();
    }

    private ProgressBar progressBar = new ProgressBar();
    private Button button = new Button();
    private Thread thread;
  }
}
