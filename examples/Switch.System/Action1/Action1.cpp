#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class Program {
  public:
    using DisplayMessage = delegate<void, const string&>;

    static void Main() {
      DisplayMessage messageTarget;
      
      if (Environment::GetCommandLineArgs().Length > 1)
        messageTarget = ShowWindowsMessage;
      else
        messageTarget = WriteLine;
      
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

_startup(Examples::Program)
