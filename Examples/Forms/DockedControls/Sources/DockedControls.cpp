#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace DockedControlsExample {
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
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      this->Text = "Docked controls example";
      
      this->panel4.Parent = *this;
      this->panel4.BackColor = System::Drawing::SystemColors::ControlLightLight;
      this->panel4.Dock = DockStyle::Fill;
      
      this->panel3.Parent = *this;
      this->panel3.BackColor = System::Drawing::SystemColors::ControlLight;
      this->panel3.Dock = DockStyle::Left;
      this->panel3.Width = 150;
      
      this->panel2.Parent = *this;
      this->panel2.BackColor = System::Drawing::SystemColors::ControlDark;
      this->panel2.Dock = DockStyle::Left;
      this->panel2.Width = 120;
      
      this->panel1.Parent = *this;
      this->panel1.BackColor = System::Drawing::SystemColors::Control;
      this->panel1.Dock = DockStyle::Top;
      this->panel1.Height = 32;
      
      for (int i = buttons.Length-1; i >= 0; i--) {
        this->buttons[i] = sp<Button>::Create();
        this->buttons[i]->Parent = this->panel1;
        this->buttons[i]->Text = string::Format("{0}", i+1);
        this->buttons[i]->Width = 28;
        this->buttons[i]->Dock = DockStyle::Left;
      }
      
      for (int i =  labels.Length-1; i >= 0; i--) {
        this->labels[i] = sp<Label>::Create();
        this->labels[i]->Parent = this->panel4;
        this->labels[i]->Text = string::Format("label {0}", i+1);
        this->labels[i]->Dock = DockStyle::Top;
      }
      this->ResumeLayout(false);
      this->PerformLayout();
    }
    
  private:
    Panel panel1;
    Array<sp<Button>> buttons {20};
    Panel panel2;
    Panel panel3;
    Panel panel4;
    Array<sp<Label>> labels {40};
  };
}

pcf_startup (DockedControlsExample::Form1)
