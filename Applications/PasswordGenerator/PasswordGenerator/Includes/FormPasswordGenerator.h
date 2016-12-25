#pragma once

#include <Pcf/Pcf>

namespace PasswordGenerator {
  class FormPasswordGenerator : public System::Windows::Forms::Form {
  public:
    FormPasswordGenerator();

  private:
    void OnCheckBoxChecked(const object& sender, const System::EventArgs& e);
    void OnButtonGenerateClick(const object& sender, const System::EventArgs& e);

  #pragma region Pcf Form Designer generated code
  #define PcfGeneratingCode
  private:
    /// @brief Required method for Designer support - do not modify the contents of this method with the editor.
    void InitializeComponent();

    System::Windows::Forms::Panel panel;
    System::Windows::Forms::Label labelPasswordLength;
    System::Windows::Forms::NumericUpDown numericUpdDownPasswordLength;
    System::Windows::Forms::CheckBox checkBoxIncludeSymbols;
    System::Windows::Forms::CheckBox checkBoxIncludeNumbers;
    System::Windows::Forms::CheckBox checkBoxIncludeLowercaseCharacters;
    System::Windows::Forms::CheckBox checkBoxIncludeUppercaseCharacters;
    System::Windows::Forms::CheckBox checkBoxExcludeSimilarCharacters;
    System::Windows::Forms::CheckBox checkBoxExcludeAmbigousCharacters;
    System::Windows::Forms::Label labelPasswordsNumber;
    System::Windows::Forms::NumericUpDown numericUpdDownPasswordsNumber;
    System::Windows::Forms::Button buttonGenerate;
    System::Windows::Forms::ListBox listBoxPasswords;
  #undef PcfGeneratingCode
  #pragma endregion
  };
}
