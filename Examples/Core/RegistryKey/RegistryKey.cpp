#include <Pcf/Pcf>

using namespace System;
using namespace Microsoft::Win32;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create environment variale PCF_REGISTRY_KEY_TEST to validate registry expand string
      Environment::SetEnvironmentVariable("PCF_REGISTRY_KEY_TEST", "My Environment Variable");
      
      // Create a new regiqstry sub key "HKEY_CURRENT_USER\PcfRegistryKeyTest" and add values
      pcf_using(RegistryKey key = Registry::CurrentUser().CreateSubKey("PcfRegistryKeyTest")) {
        key.SetValue("Key1", "Value1");
        key.SetValue("Key2", "%PCF_REGISTRY_KEY_TEST%", RegistryValueKind::ExpandString);
        key.SetValue("Key3", Array<byte> {1, 2, 3, 4, 5}, RegistryValueKind::Binary);
        key.SetValue("Key4", 42);
        key.SetValue("Key5", Array<string> {"str1", "Str2", "str3"});
        key.SetValue("Key6", 42, RegistryValueKind::QWord);
        key.SetValue("Key7", Version(1, 2, 3));
      }
      
      // Open sub key HKEY_CURRENT_USER\PcfRegistryKeyTest in read mode and read values
      RegistryKey key = Registry::CurrentUser().OpenSubKey("PcfRegistryKeyTest");
      Console::WriteLine("Key1 = {0}", key.GetValue("Key1"));
      Console::WriteLine("Key2 = {0}", key.GetValue("Key2"));
      Console::WriteLine("Key3 = {0}", string::Join(", ", as<Array<byte>>(key.GetValue("Key3"))));
      Console::WriteLine("Key4 = {0}", key.GetValue("Key4"));
      Console::WriteLine("Key5 = {0}", string::Join(", ", as<Array<string>>(key.GetValue("Key5"))));
      Console::WriteLine("Key6 = {0}", Int64::Parse(key.GetValue("Key6").ToString()));
      Console::WriteLine("Key7 = {0}", Version::Parse(key.GetValue("Key7").ToString()));
      Console::WriteLine("Key8 = {0}", key.GetValue("Key8", -1));
      
      // Write a value on read only sub key
      try {
        key.SetValue("key9", -1);
      } catch (const UnauthorizedAccessException&) {
        Console::WriteLine("Unauthorized access !");
      }

      // Remove the "HKEY_CURRENT_USER\PcfRegistryKeyTest" sub key
      Registry::CurrentUser().DeleteSubKeyTree("PcfRegistryKeyTest");
      
      // Remove environment variale PCF_REGISTRY_KEY_TEST
      Environment::SetEnvironmentVariable("PCF_REGISTRY_KEY_TEST", "");
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Key1 = Value1
// Key2 = My Environment Variable
// Key3 = 1, 2, 3, 4, 5
// Key4 = 42
// Key5 = str1, Str2, str3
// Key6 = 42
// Key7 = 1.2.3
// Key8 = -1
// Unauthorized access !