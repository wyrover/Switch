#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace PanelExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->panel1.BorderStyle = BorderStyle::FixedSingle;
      //this->panel1.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Bottom;
      this->panel1.Bounds = System::Drawing::Rectangle(10, 10, 305, 460);
      
      this->panel2.BorderStyle = BorderStyle::Fixed3D;
      //this->panel2.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->panel2.Bounds = System::Drawing::Rectangle(325, 10, 305, 460);

      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      this->Text = "Panel example";
      this->Controls().AddRange({panel1, panel2});
    }
    
  private:
    Panel panel1;
    Panel panel2;
  };
}

sw_startup (PanelExample::Form1)
