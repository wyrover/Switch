#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace PaintExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Paint example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      
      this->Paint += pcf_delegate(const object& sender, PaintEventArgs& e) {
        e.Graphics().Clear(Drawing::Color::LightYellow);
        e.Graphics().DrawRectangle(Drawing::Pen(Drawing::Color::LightPink, 10), e.ClipRectangle);

        e.Graphics().DrawLine(Drawing::Pen(Drawing::Color::LightSteelBlue, 5), 20, 60, 400, 60);
        e.Graphics().DrawString("Pcf draw graphics", Drawing::Font("Arial", 48, Drawing::FontStyle::Regular), Drawing::SolidBrush(Drawing::Color::LightGreen), 20, 0);

        e.Graphics().DrawEllipse(Drawing::Pen(Drawing::Color::LightSkyBlue, 10), 60, 80, 200, 200);
        e.Graphics().FillPie(Drawing::SolidBrush(Drawing::Color::Green), 80, 100, 160, 160, 45.0f, 270.0f);
        e.Graphics().FillPie(Drawing::SolidBrush(Drawing::Color::LightGreen), 80, 100, 160, 160, 270.0f, 180.0f);

        e.Graphics().FillRectangle(Drawing::SolidBrush(Drawing::Color::LightBlue), 50, 300, 400, 50);
        e.Graphics().FillRectangle(Drawing::SolidBrush(Drawing::Color::LightSeaGreen), 400, 70, 100, 200);
        e.Graphics().DrawArc(Drawing::Pen(Drawing::Color::Black, 10), 400, 70, 100, 200, 45.0f, 270.0f);
        //e.Graphics().DrawBezier(Drawing::Pen(Drawing::Color::Black), 100, 100, 150, 150, 200, 100, 250, 50);
      };
    }
  };
}

pcf_startup (PaintExample::Form1)
