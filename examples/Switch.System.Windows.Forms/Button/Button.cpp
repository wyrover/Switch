#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace ButtonExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->button1.Parent = *this;
      this->button1.Text = "button1";
      this->button1.Location = System::Drawing::Point(50, 50);
      this->button1.Click += delegate_(const object & sender, const EventArgs & e) {
        this->label1.Text = string::Format("button1 clicked {0} times", ++this->button1Clicked);
      };

      this->button2.Parent = *this;
      this->button2.Text = "button2";
      this->button2.Location = System::Drawing::Point(50, 100);
      this->button2.Size = System::Drawing::Size(200, 75);
      this->button2.Click += delegate_(const object & sender, const EventArgs & e) {
        this->label2.Text = string::Format("button2 clicked {0} times", ++this->button2Clicked);
      };

      this->label1.Parent = *this;
      this->label1.Text = "button1 clicked 0 times";
      this->label1.Location = System::Drawing::Point(50, 200);
      this->label1.Width = 200;

      this->label2.Parent = *this;
      this->label2.Text = "button2 clicked 0 times";
      this->label2.Location = System::Drawing::Point(50, 230);
      this->label2.Width = 200;
    }

  private:
    Button button1;
    Button button2;
    Label label1;
    Label label2;
    int button1Clicked = 0;
    int button2Clicked = 0;
  };
}

startup_(ButtonExample::Form1);
