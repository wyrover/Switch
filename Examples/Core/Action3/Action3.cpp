#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Action<const string&> messageTarget;
      
      if (Environment::GetCommandLineArgs().Length > 1)
        messageTarget = _delegate(const string& s) { ShowWindowsMessage(s); };
      else
        messageTarget = _delegate(const string& s) { WriteLine(s); };
      
      messageTarget("Hello, World!");
    }
    
  private:
    static void ShowWindowsMessage(const string& message) {
      MessageBox::Show(message);
    }
    
    static void WriteLine(const string& message) {
      Console::WriteLine(message);
    }
  };
}

_startup (Examples::Program)
