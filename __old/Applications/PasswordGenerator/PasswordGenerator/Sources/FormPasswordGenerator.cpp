#include "../Includes/FormPasswordGenerator.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Threading;
using namespace System::Windows::Forms;

namespace PasswordGenerator {
  FormPasswordGenerator::FormPasswordGenerator() : Form() {
    this->InitializeComponent();
  }

  void FormPasswordGenerator::OnCheckBoxChecked(const object& sender, const EventArgs& e) {
    this->buttonGenerate.Enabled = this->checkBoxIncludeSymbols.Checked || this->checkBoxIncludeNumbers.Checked || this->checkBoxIncludeLowercaseCharacters.Checked || this->checkBoxIncludeUppercaseCharacters.Checked;
  }

  void FormPasswordGenerator::OnButtonGenerateClick(const object& sender, const EventArgs& e) {
    this->listBoxPasswords.Items().Clear();
    Random random;
    for (int number = 0; number < this->numericUpdDownPasswordsNumber.Value; ++number) {
      string password = "";
      for (int index = 0; index < this->numericUpdDownPasswordLength.Value; ++index) {
        char32 character;
        bool valid = false;
        do {
          character = random.Next(33, 126);
          if (this->checkBoxIncludeSymbols.Checked && Char::IsLetterOrDigit(character) == false)
            valid = true;
          if (this->checkBoxIncludeNumbers.Checked && Char::IsDigit(character))
            valid = true;
          if (this->checkBoxIncludeLowercaseCharacters.Checked && Char::IsLetter(character) && Char::IsLower(character))
            valid = true;
          if (this->checkBoxIncludeUppercaseCharacters.Checked && Char::IsLetter(character) && Char::IsUpper(character))
            valid = true;
          if (this->checkBoxExcludeSimilarCharacters.Checked && string("1iIlL2zZ5sS6G8B0oO").IndexOf(character) != -1)
            valid = false;
          if (this->checkBoxExcludeAmbigousCharacters.Checked && string("{}[]()/\\'\"`~,;:.<>").IndexOf(character) != -1)
            valid = false;
        } while (valid == false);
        password += character;
      }
      this->listBoxPasswords.Items().Add(password);
    }
  }
}
