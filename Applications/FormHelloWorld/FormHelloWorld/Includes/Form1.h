#pragma once

#include <Pcf/Pcf>

namespace HelloWorld {
  class Form1 : public System::Windows::Forms::Form {
  public:
   Form1();
   
  private:
    
  #pragma region Pcf Form Designer generated code
  #define PcfGeneratingCode
  private:
    /// @brief Required method for Designer support - do not modify the contents of this method with the editor.
    void InitializeComponent();
    
    System::Windows::Forms::Label label1;
  #undef PcfGeneratingCode
  #pragma endregion
  };
}
