#include <Pcf/Pcf>

using namespace System;
using namespace Microsoft::Win32;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a new regiqstry sub key "HKEY_CURRENT_USER\PcfRegistryTest" and add value
      pcf_using(RegistryKey key = Registry::CurrentUser().CreateSubKey("PcfRegistryTest")) {
        key.SetValue("MyKey", "MyValue");
      }

      Console::WriteLine("MyKey      = {0}", Registry::GetValue("HKEY_CURRENT_USER\\PcfRegistryTest", "MyKey", "default"));
      Console::WriteLine("UnknownKey = {0}", Registry::GetValue("HKEY_CURRENT_USER\\PcfRegistryTest", "UnknownKey", -1));
      
      // Remove the "HKEY_CURRENT_USER\PcfRegistryTest" sub key
      Registry::CurrentUser().DeleteSubKeyTree("PcfRegistryTest");
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// MyKey      = MyValue
// UnknownKey = -1
