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
      progressBar.Name = "progressBar";
      progressBar.Minimum = 0;
      progressBar.Maximum = 100;
      progressBar.Value = 50;

      Label label;
      label.Location = Point(10, 40);
      label.Width = 150;
      label.Name = "label";
      label.Text = "Label";
      //label.BackColor = Color::SpringGreen;

      CheckBox checkBox1;
      checkBox1.Name = "checkBox1";
      checkBox1.Text = "Check 1";
      checkBox1.Width = 200;
      checkBox1.Location = Point(10, 70);
      checkBox1.Checked = true;
      checkBox1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        if (checkBox1.Checked)
          progressBar.Value = 0;
      };
      
      CheckBox checkBox2;
      checkBox2.Name = "checkBox2";
      checkBox2.Text = "Check 2";
      checkBox2.Width = 200;
      checkBox2.Location = Point(10, 100);
      checkBox2.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        if (checkBox2.Checked)
          progressBar.Value = 25;
      };
      
      RadioButton radioButton1;
      radioButton1.Name = "radioButton1";
      radioButton1.Text = "Radio 1";
      radioButton1.Location = Point(10, 130);
      //radioButton1.Checked = true;
      radioButton1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        progressBar.Value = 50;
      };

      RadioButton radioButton2;
      radioButton2.Name = "radioButton2";
      radioButton2.Text = "Radio 2";
      radioButton2.Location = Point(10, 160);
      radioButton2.Checked = true;
      radioButton2.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        progressBar.Value = 100;
      };

      Button button;
      button.Name = "button";
      button.Text = "Click me";
      button.Location = Point(10, 190);
      button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World !", "Message", MessageBoxButtons::OKCancel, MessageBoxIcon::Hand);
      };

      Panel panel;
      panel.Name = "panel";
      panel.Text = "Panel";
      panel.Location = Point(10, 10);
      panel.Size = Size(280, 280);
      panel.BorderStyle = BorderStyle::Fixed3D;
      panel.Controls().AddRange({progressBar, label, checkBox1, checkBox2, radioButton1, radioButton2, button});

      Form form;
      form.Name = "form";
      form.Text = "Form";
      form.Controls().Add(panel);
      form.StartPosition = FormStartPosition::Manual;
      form.Location = Point(300, 200);
      form.ClientSize = Size(300, 300);
      //form.BackColor = Color::SpringGreen;
      
      int counter = 0;
      Application::Idle += pcf_delegate(const object& sender, const EventArgs& e) {
        label.Text = string::Format("counter = {0}", counter++);
      };

      Application::EnableVisualStyles();
      Application::Run(form);
    }
  };
}

pcf_startup (PcfFormApp::Program)
