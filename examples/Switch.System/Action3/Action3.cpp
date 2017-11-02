#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Action<const string&> messageTarget;
      
      if (Environment::GetCommandLineArgs().Length > 1)
        messageTarget = _delegate(const string& s) { MessageBox::Show(s); };
      else
        messageTarget = _delegate(const string& s) { Console::WriteLine(s); };
      
      messageTarget("Hello, World!");
    }
  };
}

_startup(Examples::Program)
