#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace RichTextBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "RichTextBox example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      
      this->text.Parent = *this;
      this->text.Font = System::Drawing::Font(System::Drawing::FontFamily::GenericMonospace);
      System::Array<System::Windows::FormsD::Screen> screens = System::Windows::FormsD::Screen::AllScreens;
      for (int i = 0; i < screens.Length; ++i)
        this->text.Text += string::Format("Device {0} :\n  - Primary = {1}\n  - Name = {2}\n  - Screen = {3}\n  - Area = {4}\n\n", i, screens[i].Primary, screens[i].DeviceName, screens[i].Bounds, screens[i].WorkingArea);
      this->text.Bounds = System::Drawing::Rectangle(0, 0, this->Width, this->Height);
      this->text.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
    }
    
  private:
    RichTextBox text;
  };
}

pcf_startup (RichTextBoxExample::Form1)
