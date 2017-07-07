#include <Pcf/Pcf>

using namespace System::Windows::Forms;

namespace ManualTests {
  class Program {
  public:
    static void Main() {

      Form form;

      Application::EnableVisualStyles();
      Application::Run(form);
    }
  };
}

pcf_startup(ManualTests::Program)
