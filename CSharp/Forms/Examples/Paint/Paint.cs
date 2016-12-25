using System;
using System.Windows.Forms;

namespace PaintExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Paint example";
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);

      this.Paint += delegate(object sender, PaintEventArgs e) {
        e.Graphics.Clear(System.Drawing.Color.LightYellow);
        e.Graphics.DrawRectangle(new System.Drawing.Pen(System.Drawing.Color.LightPink, 10), e.ClipRectangle);

        e.Graphics.DrawLine(new System.Drawing.Pen(System.Drawing.Color.LightSteelBlue, 5), 20, 60, 400, 60);
        e.Graphics.DrawString("Pcf draw graphics", new System.Drawing.Font("Arial", 36, System.Drawing.FontStyle.Regular), new System.Drawing.SolidBrush(System.Drawing.Color.LightGreen), 20, 0);

        e.Graphics.DrawEllipse(new System.Drawing.Pen(System.Drawing.Color.LightSkyBlue, 10), 60, 80, 200, 200);
        e.Graphics.FillPie(new System.Drawing.SolidBrush(System.Drawing.Color.Green), 80, 100, 160, 160, 45.0f, 270.0f);
        e.Graphics.FillPie(new System.Drawing.SolidBrush(System.Drawing.Color.LightGreen), 80, 100, 160, 160, 270.0f, 180.0f);

        e.Graphics.FillRectangle(new System.Drawing.SolidBrush(System.Drawing.Color.LightBlue), 50, 300, 400, 50);
        e.Graphics.FillRectangle(new System.Drawing.SolidBrush(System.Drawing.Color.LightSeaGreen), 400, 70, 100, 200);
        e.Graphics.DrawArc(new System.Drawing.Pen(System.Drawing.Color.Black, 10), 400, 70, 100, 200, 45.0f, 270.0f);
        //e.Graphics.DrawBezier(new System.Drawing.Pen(System.Drawing.Color.Black), 100, 100, 150, 150, 200, 100, 250, 50);
      };
    }
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
