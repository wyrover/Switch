#include <Switch/Switch>

using namespace System::Windows::Forms;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::Run(Form());
    }
  };
};

_startup(Examples::Program);
