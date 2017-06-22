#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace FormExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->buttonBig.Parent = *this;
      this->buttonBig.Bounds = System::Drawing::Rectangle(10, 10, 200, 200);
      this->buttonBig.Text = "This is a very big button, that contains a lot of text...\n\nEnd more...";
      //this->buttonBig.UseWaitCursor = true;

      this->buttonTooSmallForText.Parent = *this;
      this->buttonTooSmallForText.Text = "Button too small For Text...";
      //this->buttonTooSmallForText.Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
      this->buttonTooSmallForText.Left = 35;
      this->buttonTooSmallForText.Top = 265;

      this->buttonNone.Parent = *this;
      this->buttonNone.Text = "None";
      //this->buttonNone.Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
      this->buttonNone.Left = 125;
      this->buttonNone.Top = 265;
      this->buttonNone.Enabled = false;
      //this->buttonNone.AutoSize = true;

      this->buttonClose.Parent = *this;
      this->buttonClose.Text = "Close";
      //this->buttonClose.Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
      this->buttonClose.Left = 215;
      this->buttonClose.Top = 265;
      this->buttonClose.Click += pcf_delegate(const object& sender, const EventArgs& args) {
        this->Close();
      };

      this->line.Parent = *this;
      this->line.BorderStyle = BorderStyle::FixedSingle;
      //this->line.Anchor = AnchorStyles::Left | AnchorStyles::Bottom | AnchorStyles::Right;
      this->line.Bounds = System::Drawing::Rectangle(10, 253, 280, 1);

      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->ClientSize = System::Drawing::Size(300, 300);
      this->Text = "Button example";
    }
    
  private:
    Panel line;
    Button buttonNone;
    Button buttonClose;
    Button buttonTooSmallForText;
    Button buttonBig;
  };
}

pcf_startup (FormExample::Form1)
