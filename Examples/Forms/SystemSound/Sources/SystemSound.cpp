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
      this->Text = "SystemSounds example";
      
      this->buttonAsterisk.Parent = *this;
      this->buttonAsterisk.Bounds = System::Drawing::Rectangle(60, 50, 180, 30);
      this->buttonAsterisk.Text = "SystemSounds::Asterisk";
      this->buttonAsterisk.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Asterisk.Play();
      };
      
      this->buttonBeep.Parent = *this;
      this->buttonBeep.Bounds = System::Drawing::Rectangle(60, 90, 180, 30);
      this->buttonBeep.Text = "SystemSounds::Beep";
      this->buttonBeep.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Beep.Play();
      };
      
      this->buttonExclamation.Parent = *this;
      this->buttonExclamation.Bounds = System::Drawing::Rectangle(60, 130, 180, 30);
      this->buttonExclamation.Text = "SystemSounds::Exclamation";
      this->buttonExclamation.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Exclamation.Play();
      };
      
      this->buttonHand.Parent = *this;
      this->buttonHand.Bounds = System::Drawing::Rectangle(60, 170, 180, 30);
      this->buttonHand.Text = "SystemSounds::Hand";
      this->buttonHand.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Hand.Play();
      };
      
      this->buttonQuestion.Parent = *this;
      this->buttonQuestion.Bounds = System::Drawing::Rectangle(60, 210, 180, 30);
      this->buttonQuestion.Text = "SystemSounds::Question";
      this->buttonQuestion.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        SystemSounds::Question.Play();
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
