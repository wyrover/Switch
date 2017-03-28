#include "../Includes/Form1.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Threading;
using namespace System::Windows::Forms;

namespace HelloWorld {
  class Program {
  public:
    // The main entry point for the application
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(HelloWorld::Form1());
    }
  };
}

pcf_startup(HelloWorld::Program)
