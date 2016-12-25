#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace CheckedListBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "CheckedListBox example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(200, 240);
      
      this->checkedlistBox.Parent = *this;
      this->checkedlistBox.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->checkedlistBox.Bounds = System::Drawing::Rectangle(20, 20, 160, 200);
      
      for (int i = 1; i <= 1000; ++i)
        this->checkedlistBox.Items().Add(string::Format("Item {0}", i), i % 2 != 0);
    }
    
  private:
    CheckedListBox checkedlistBox;
  };
}

pcf_startup (CheckedListBoxExample::Form1)
