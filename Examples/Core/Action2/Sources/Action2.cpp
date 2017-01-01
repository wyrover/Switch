#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace Examples {
  class Program {
  public:
    static void Main() {
      Action<const string&> messageTarget;
      
      if (Environment::GetCommandLineArgs().Length > 1)
        messageTarget = ShowWindowsMessage;
      else
        messageTarget = WriteLine;
      
      messageTarget("Hello, World!");
    }
    
  private:
    static void ShowWindowsMessage(const string& message) {
      //MessageBox::Show(message);
    }
    
    static void WriteLine(const string& message) {
      Console::WriteLine(message);
    }
  };
}

pcf_startup (Examples::Program)
