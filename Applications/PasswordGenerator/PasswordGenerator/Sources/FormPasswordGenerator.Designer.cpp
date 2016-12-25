#include "../Includes/FormPasswordGenerator.h"

#pragma region Pcf Form Designer generated code
// Do not modify the contents of this method with the editor.
void PasswordGenerator::FormPasswordGenerator::InitializeComponent() {
  this->SuspendLayout();
  //
  // panel
  //
  this->panel.Parent = *this;
  this->panel.Location = System::Drawing::Point(10, 10);
  this->panel.Size = System::Drawing::Size(380, 220);
  this->panel.BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
  //this->panel.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
  //
  // labelPasswordLength
  //
  this->labelPasswordLength.Parent = this->panel;
  this->labelPasswordLength.Text = "Password Length";
  this->labelPasswordLength.AutoSize = true;
  this->labelPasswordLength.Location = System::Drawing::Point(10, 14);
  //
  // numericUpdDownPasswordLength
  //
  this->numericUpdDownPasswordLength.Parent = this->panel;
  this->numericUpdDownPasswordLength.Location = System::Drawing::Point(130, 10);
  this->numericUpdDownPasswordLength.Width = 50;
  this->numericUpdDownPasswordLength.Minimum = 2;
  this->numericUpdDownPasswordLength.Maximum = 128;
  this->numericUpdDownPasswordLength.Value = 16;
  //
  // checkBoxIncludeSymbols
  //
  this->checkBoxIncludeSymbols.Parent = this->panel;
  this->checkBoxIncludeSymbols.Text = "Include symbols ( e.g. ##$% )";
  this->checkBoxIncludeSymbols.AutoSize = true;
  this->checkBoxIncludeSymbols.Location = System::Drawing::Point(10, 35);
  this->checkBoxIncludeSymbols.Click += {*this, &FormPasswordGenerator::OnCheckBoxChecked};
  //
  // checkBoxIncludeNumbers
  //
  this->checkBoxIncludeNumbers.Parent = this->panel;
  this->checkBoxIncludeNumbers.Text = "Include numbers ( e.g. 123456 )";
  this->checkBoxIncludeNumbers.AutoSize = true;
  this->checkBoxIncludeNumbers.Location = System::Drawing::Point(10, 60);
  this->checkBoxIncludeNumbers.Click += {*this, &FormPasswordGenerator::OnCheckBoxChecked};
  //
  // checkBoxIncludeLowercaseCharacters
  //
  this->checkBoxIncludeLowercaseCharacters.Parent = this->panel;
  this->checkBoxIncludeLowercaseCharacters.Text = "Include Lowercase Characters ( e.g. abcdefgh )";
  this->checkBoxIncludeLowercaseCharacters.AutoSize = true;
  this->checkBoxIncludeLowercaseCharacters.Location = System::Drawing::Point(10, 85);
  this->checkBoxIncludeLowercaseCharacters.Click += {*this, &FormPasswordGenerator::OnCheckBoxChecked};
  //
  // checkBoxIncludeUppercaseCharacters
  //
  this->checkBoxIncludeUppercaseCharacters.Parent = this->panel;
  this->checkBoxIncludeUppercaseCharacters.Text = "Include uppercase Characters ( e.g. ABCDEFGH )";
  this->checkBoxIncludeUppercaseCharacters.AutoSize = true;
  this->checkBoxIncludeUppercaseCharacters.Location = System::Drawing::Point(10, 110);
  this->checkBoxIncludeUppercaseCharacters.Click += {*this, &FormPasswordGenerator::OnCheckBoxChecked};
  //
  // checkBoxExcludeSimilarCharacters
  //
  this->checkBoxExcludeSimilarCharacters.Parent = this->panel;
  this->checkBoxExcludeSimilarCharacters.Text = "Exclude Similar Characters ( e.g. i, l, 1, L, o, 0, O )";
  this->checkBoxExcludeSimilarCharacters.AutoSize = true;
  this->checkBoxExcludeSimilarCharacters.Location = System::Drawing::Point(10, 135);
  //
  // checkBoxExcludeAmbigousCharacters
  //
  this->checkBoxExcludeAmbigousCharacters.Parent = this->panel;
  this->checkBoxExcludeAmbigousCharacters.Text = "Exclude Ambigous Characters ( { } [ ] ( ) / \\ ' \" ` ~ , ; : . < > )";
  this->checkBoxExcludeAmbigousCharacters.AutoSize = true;
  this->checkBoxExcludeAmbigousCharacters.Location = System::Drawing::Point(10, 160);
  //
  // labelPasswordLength
  //
  this->labelPasswordsNumber.Parent = this->panel;
  this->labelPasswordsNumber.Text = "Passwords Number";
  this->labelPasswordsNumber.AutoSize = true;
  this->labelPasswordsNumber.Location = System::Drawing::Point(10, 190);
  //
  // numericUpdDownPasswordsNumber
  //
  this->numericUpdDownPasswordsNumber.Parent = this->panel;
  this->numericUpdDownPasswordsNumber.Location = System::Drawing::Point(130, 185);
  this->numericUpdDownPasswordsNumber.Width = 50;
  this->numericUpdDownPasswordsNumber.Minimum = 1;
  this->numericUpdDownPasswordsNumber.Maximum = 999;
  this->numericUpdDownPasswordsNumber.Value = 1;
  //
  // buttonGenerate
  //
  this->buttonGenerate.Parent = *this;
  this->buttonGenerate.Text = "Generate";
  this->buttonGenerate.Location = System::Drawing::Point(10, 239);
  this->buttonGenerate.Size = System::Drawing::Size(380, 23);
  this->buttonGenerate.Enabled = false;
  //this->buttonGenerate.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
  this->buttonGenerate.Click += {*this, &FormPasswordGenerator::OnButtonGenerateClick};
  //
  // listBoxPasswords
  //
  this->listBoxPasswords.Parent = *this;
  this->listBoxPasswords.Location = System::Drawing::Point(10, 270);
  this->listBoxPasswords.Size = System::Drawing::Size(380, 220);
  //this->listBoxPasswords.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom;
  //
  // FormPasswordGenerator
  //
  this->Location = System::Drawing::Point(400, 200);
  this->ClientSize = System::Drawing::Size(400, 500);
  this->Text = "Secure Password Generator";
  this->MaximizeBox = false;
  this->ResumeLayout(false);
  this->PerformLayout();
}
#pragma endregion
