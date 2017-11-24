#include <Switch/Switch>

using namespace System;
using namespace Microsoft::Win32;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a new regiqstry sub key "HKEY_CURRENT_USER\SwitchRegistryTest" and add value
      _using(RegistryKey key = Registry::CurrentUser().CreateSubKey("SwitchRegistryTest")) {
        key.SetValue("MyKey", "MyValue");
      }
      
      Console::WriteLine("MyKey      = {0}", Registry::GetValue("HKEY_CURRENT_USER\\SwitchRegistryTest", "MyKey", "default"));
      Console::WriteLine("UnknownKey = {0}", Registry::GetValue("HKEY_CURRENT_USER\\SwitchRegistryTest", "UnknownKey", -1));
      
      // Remove the "HKEY_CURRENT_USER\SwitchRegistryTest" sub key
      Registry::CurrentUser().DeleteSubKeyTree("SwitchRegistryTest");
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// MyKey      = MyValue
// UnknownKey = -1
