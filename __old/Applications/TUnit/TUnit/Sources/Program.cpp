#include "../Includes/TUnitForm.h"

using namespace System;
using namespace System::Windows::Forms;

namespace TUnit {
  class Program {
  public:
    /// @brief The main entry point for the application
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(TUnitApplication::TUnitForm());
    }
  };
}

pcf_startup(::TUnit::Program)
