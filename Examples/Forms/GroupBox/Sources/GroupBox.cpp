#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace GroupBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->SuspendLayout();
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      this->Text = "GroupBox example";
      
      this->groupBox1.Parent = *this;
      this->groupBox1.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Bottom;
      this->groupBox1.Bounds = System::Drawing::Rectangle(10, 10, 305, 460);
      
      this->groupBox2.Parent = *this;
      this->groupBox2.Text = "Group 2";
      this->groupBox2.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->groupBox2.Bounds = System::Drawing::Rectangle(325, 10, 305, 460);
      this->ResumeLayout();
    }
    
  private:
    GroupBox groupBox1;
    GroupBox groupBox2;
  };
}

pcf_startup (GroupBoxExample::Form1)
