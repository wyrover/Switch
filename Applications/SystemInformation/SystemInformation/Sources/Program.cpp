#include <Pcf/Pcf>
#include <Pcf/Toolbox>

using namespace System;
using namespace Toolbox::SystemInformation;

namespace PcfConsoleApp {
  class Program : public object {
  public:
    /// @brief The main entry point for the application.
    static void Main() {
      Console::WriteLine("Language {0} ({1})", LanguageInformation::Name(), LanguageInformation::Version());
#if __llvm__
      Console::WriteLine("__llvm__ {0}", __llvm__);
#endif
    }
  };
}

startup(&PcfConsoleApp::Program::Main)
