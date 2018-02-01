#include <Switch/Switch>

using namespace System::Windows::Forms;

namespace SomeControls {
  class MainForm : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(MainForm());
    }

    MainForm() {
      this->button.Text = "Button";
      this->button.Location = System::Drawing::Point(10, 10);

      this->label.Text = "こんにちは世界！";
      this->label.Location = System::Drawing::Point(100, 13);
      this->label.Width = 200;

      this->radioButton1.Text = "RadioButton1";
      this->radioButton1.Location = System::Drawing::Point(10, 40);
      this->radioButton1.Checked = true;

      this->radioButton2.Text = "RadioButton2";
      this->radioButton2.Location = System::Drawing::Point(10, 70);

      this->radioButton3.Text = "RadioButton3";
      this->radioButton3.Location = System::Drawing::Point(10, 100);

      this->groupBox.Text = "GroupBox";
      this->groupBox.Location = System::Drawing::Point(10, 60);
      this->groupBox.Size = System::Drawing::Size(200, 150);
      this->groupBox.Controls().AddRange({this->radioButton1, this->radioButton2, this->radioButton3});

      this->checkBox1.Text = "Checked";
      this->checkBox1.Location = System::Drawing::Point(10, 10);
      this->checkBox1.CheckState = CheckState::Checked;

      this->checkBox2.Text = "Unchecked";
      this->checkBox2.Location = System::Drawing::Point(10, 40);
      this->checkBox2.CheckState = CheckState::Unchecked;

      this->checkBox3.Text = "Indeterminate";
      this->checkBox3.Location = System::Drawing::Point(10, 70);
      this->checkBox3.CheckState = CheckState::Indeterminate;

      this->panel.Location = System::Drawing::Point(220, 60);
      this->panel.Size = System::Drawing::Size(200, 150);
      this->panel.BorderStyle = BorderStyle::Fixed3D;
      this->panel.Controls().AddRange({this->checkBox1, this->checkBox2, this->checkBox3});

      this->progressBar.Location = System::Drawing::Point(10, 240);
      this->progressBar.Width = 410;
      this->progressBar.Value = 40;

      this->Text = "Some Controls";
      this->ClientSize = System::Drawing::Size(430, 280);
      this->Controls().AddRange({this->button, this->label, this->groupBox, this->panel, this->progressBar});
    }

  private:
    Button button;
    Label label;
    RadioButton radioButton1, radioButton2, radioButton3;
    GroupBox groupBox;
    CheckBox checkBox1, checkBox2, checkBox3;
    Panel panel;
    ProgressBar progressBar;
  };
}

startup_(SomeControls::MainForm);
