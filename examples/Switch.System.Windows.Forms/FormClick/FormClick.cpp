#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace FormClickExample {
  class FormClick {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<KnownColor> colors  = Enum<KnownColor>::GetValues();
      int colorIndex = 26; // 26 = KnowColor::Transparent index...
      Application::EnableVisualStyles();
      Form form;
      form.Click += delegate_(const object & sender, const EventArgs & e) {
        if (++colorIndex >= colors.Length) colorIndex = 0;
        form.BackColor = Color::FromKnownColor(colors[colorIndex]);
      };
      Application::Run(form);
    }
  };
}

startup_(FormClickExample::FormClick);
