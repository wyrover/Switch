#include <Pcf/Forms.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      ProgressBar progressBar;
      progressBar.Location = System::Drawing::Point(10, 10);

      Label label;
      label.Name = "label";
      label.Text = "Label";
      label.Location = Point(10, 40);
      label.Width = 150;

      CheckBox checkBox1;
      checkBox1.Name = "checkBox1";
      checkBox1.Text = "Check 1";
      checkBox1.Location = Point(10, 70);
      checkBox1.Checked = true;
      checkBox1.Focus();

      CheckBox checkBox2;
      checkBox2.Name = "checkBox2";
      checkBox2.Text = "Check 2";
      checkBox2.Location = Point(10, 100);

      RadioButton radioButton1;
      radioButton1.Name = "radioButton1";
      radioButton1.Text = "Radio 1";
      radioButton1.Location = Point(10, 130);
      radioButton1.Checked = true;

      RadioButton radioButton2;
      radioButton2.Name = "radioButton2";
      radioButton2.Text = "Radio 2";
      radioButton2.Location = Point(10, 160);

      RadioButton radioButton3;
      radioButton3.Name = "radioButton3";
      radioButton3.Text = "Radio 3";
      radioButton3.Location = Point(10, 190);

      Button button;
      button.Name = "button";
      button.Text = "Click me";
      button.Location = Point(10, 220);
      button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World !", "Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Hand);
      };

      Panel panel;
      panel.Name = "panel";
      panel.Text = "Panel";
      panel.Bounds = Rectangle(10, 10, 280, 280);
      panel.Controls().AddRange({ progressBar, label, checkBox1, checkBox2, radioButton1, radioButton2, radioButton3, button });
      panel.BackColor = Color::White;

      Form form;
      form.Name = "form";
      form.Controls().Add(panel);
      form.ClientSize = Size(300, 300);
      //form.StartPosition = FormStartPosition::Manual;
      //form.Location = Point(10, 10);

      int counter = 0;
      Application::Idle += pcf_delegate(const object& sender, const EventArgs& e) {
        if (checkBox1.Checked && checkBox2.Checked)
          progressBar.Value = 100;
        else if (checkBox1.Checked)
          progressBar.Value = 30;
        else if (checkBox2.Checked)
          progressBar.Value = 70;
        else
          progressBar.Value = 0;

        if (radioButton1.Checked)
          panel.BorderStyle = BorderStyle::None;
        if (radioButton2.Checked)
          panel.BorderStyle = BorderStyle::FixedSingle;
        if (radioButton3.Checked)
          panel.BorderStyle = BorderStyle::Fixed3D;

        label.Text = string::Format("counter = {0}", counter++);
      };

      Application::EnableVisualStyles();
      Application::Run(form);
    }
  };
}

pcf_startup(PcfFormApp::Program)
