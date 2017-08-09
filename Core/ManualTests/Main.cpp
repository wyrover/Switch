#include <Pcf/Microsoft/Win32/Registry.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace Microsoft::Win32;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create environment variale PCF_REGISTRY_TEST to validate registry expand string
      Environment::SetEnvironmentVariable("PCF_REGISTRY_TEST", "my environment variable");
      
      // Create a new regiqstry sub key "HKEY_CURRENT_USER\PcfRegistryTest" and add values
      pcf_using(RegistryKey key = Registry::CurrentUser().CreateSubKey("PcfRegistryTest")) {
        key.SetValue("Key1", "Value1");
        key.SetValue("Key2", "%PCF_REGISTRY_TEST%", RegistryValueKind::ExpandString);
        key.SetValue("Key3", Array<byte> {1, 2, 3, 4, 5}, RegistryValueKind::Binary);
        key.SetValue("Key4", 42);
        key.SetValue("Key5", Array<string> {"str1", "Str2", "str3"});
        key.SetValue("Key6", 42, RegistryValueKind::QWord);
        key.SetValue("Key7", Version(1, 2, 3));
      }

      // Open sub key HKEY_CURRENT_USER\PcfRegistryTest in read mode and read values
      RegistryKey key = Registry::CurrentUser().OpenSubKey("PcfRegistryTest");
      Console::WriteLine("Key1 = {0}", key.GetValue("Key1"));
      Console::WriteLine("Key2 = {0}", key.GetValue("Key2"));
      Console::WriteLine("Key3 = {0}", string::Join(", ", as<Array<byte>>(key.GetValue("Key3"))));
      Console::WriteLine("Key4 = {0}", key.GetValue("Key4"));
      Console::WriteLine("Key5 = {0}", string::Join(", ", as<Array<string>>(key.GetValue("Key5"))));
      Console::WriteLine("Key6 = {0}", Int64::Parse(key.GetValue("Key6").ToString()));
      Console::WriteLine("Key7 = {0}", key.GetValue("Key7"));
      try {
        key.SetValue("key8", -1);
      } catch (const UnauthorizedAccessException&) {
        Console::WriteLine("Unauthorized access");
      }
      
      // Remove the "HKEY_CURRENT_USER\PcfRegistryTest" sub key
      Registry::CurrentUser().DeleteSubKeyTree("PcfRegistryTest");
      
      // Remove environment variale PCF_REGISTRY_TEST
      Environment::SetEnvironmentVariable("PCF_REGISTRY_TEST", "");
      
      Console::WriteLine(Environment::GetEnvironmentVariable("TERM"));
    }
  };
}

pcf_startup (Examples::Program)

