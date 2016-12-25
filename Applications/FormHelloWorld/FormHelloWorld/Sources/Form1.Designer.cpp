#include "../Includes/Form1.h"

#pragma region Pcf Form Designer generated code
// Do not modify the contents of this method with the editor.
void HelloWorld::Form1::InitializeComponent() {
  this->SuspendLayout();
  //
  // label1
  //
  this->label1.AutoSize = true;
  this->label1.Name = "label1";
  this->label1.Font = System::Drawing::Font("Arial", 46, System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic);
  this->label1.ForeColor = System::Drawing::Color::Green;
  this->label1.Location = System::Drawing::Point(5, 100);
  this->label1.Text = "Hello, World!";
  //
  // Form1
  //
  this->Location = System::Drawing::Point(400, 200);
  this->ClientSize = System::Drawing::Size(300, 300);
  this->BackColor = System::Drawing::Color::White;
  this->Controls().Add(this->label1);
  this->Text = "Form1";
  this->Name = "Form1";
  this->ResumeLayout(false);
}
#pragma endregion
