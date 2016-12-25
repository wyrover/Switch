#include <Pcf.h>

#include "../Includes/MainForm.h"

using namespace Pcf;
using namespace Pcf::System;
using namespace Pcf::System::Windows::Forms;

namespace Pcf {
  namespace PcfCode {
    class Program : public object {
    public:
      static void Main() {
        Application::EnableVisualStyles();
        Application::Run(new MainForm());
      }
    };
  }
}

AddEntryPoint(&Pcf::PcfCode::Program::Main);
