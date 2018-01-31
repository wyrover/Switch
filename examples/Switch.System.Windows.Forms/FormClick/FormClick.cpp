#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace FormClickExample {
  class FormClick {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();

      Array<Color> colors = {Color::Pink, Color::LightBlue, Color::LightGreen, Color::LightYellow};
      int colorIndex = 0;;

      Form form;
      form.BackColor = colors[colorIndex];
      form.Click += delegate_(const object & sender, const EventArgs & e) {
        if (++colorIndex == colors.Length) colorIndex = 0;
        form.BackColor = colors[colorIndex];
      };

      Application::Run(form);
    }
  };
}

startup_(FormClickExample::FormClick);
