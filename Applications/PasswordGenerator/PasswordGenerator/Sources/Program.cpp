#include "../Includes/FormPasswordGenerator.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Threading;
using namespace System::Windows::Forms;

namespace PasswordGenerator {
  class Program {
  public:
    // The main entry point for the application
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(PasswordGenerator::FormPasswordGenerator());
    }
  };
}

pcf_startup(PasswordGenerator::Program)
