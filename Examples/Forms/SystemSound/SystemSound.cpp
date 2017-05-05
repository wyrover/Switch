#include <Pcf/Pcf>

using namespace System;
using namespace System::Media;
using namespace System::Windows::Forms;

namespace SystemSoundExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->ClientSize = System::Drawing::Size(300, 300);
      this->Text = "SystemSounds example";
      
      this->buttonAsterisk.Parent = *this;
      this->buttonAsterisk.Bounds = System::Drawing::Rectangle(60, 50, 180, 40);
      this->buttonAsterisk.Text = "Asterisk";
      this->buttonAsterisk.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Asterisk().Play();
      };
      
      this->buttonBeep.Parent = *this;
      this->buttonBeep.Bounds = System::Drawing::Rectangle(60, 90, 180, 40);
      this->buttonBeep.Text = "Beep";
      this->buttonBeep.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Beep().Play();
      };
      
      this->buttonExclamation.Parent = *this;
      this->buttonExclamation.Bounds = System::Drawing::Rectangle(60, 130, 180, 40);
      this->buttonExclamation.Text = "Exclamation";
      this->buttonExclamation.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Exclamation().Play();
      };
      
      this->buttonHand.Parent = *this;
      this->buttonHand.Bounds = System::Drawing::Rectangle(60, 170, 180, 40);
      this->buttonHand.Text = "Hand";
      this->buttonHand.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Hand().Play();
      };
      
      this->buttonQuestion.Parent = *this;
      this->buttonQuestion.Bounds = System::Drawing::Rectangle(60, 210, 180, 40);
      this->buttonQuestion.Text = "Question";
      this->buttonQuestion.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Question().Play();
      };
    }
    
  private:
    Button buttonAsterisk;
    Button buttonBeep;
    Button buttonExclamation;
    Button buttonHand;
    Button buttonQuestion;
  };
}

pcf_startup (SystemSoundExample::Form1)
