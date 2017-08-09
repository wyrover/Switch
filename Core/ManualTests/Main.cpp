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
      RegistryKey key = Registry::CurrentUser().OpenSubKey("UnitTests", true);
      if (key == RegistryKey::Null())
        key = Registry::CurrentUser().CreateSubKey("UnitTests");
      key.SetValue("Key1", "Value1");
      key.SetValue("Key2", "%PUBLIC%", RegistryValueKind::ExpandString);
      key.SetValue("Key3", Array<byte> {1, 2, 3, 4, 5}, RegistryValueKind::Binary);
      key.SetValue("Key4", 42);
      key.SetValue("Key5", Array<string> {"str1", "Str2", "str3"});
      key.SetValue("Key6", 42, RegistryValueKind::QWord);
      key.SetValue("Key7", Version(1, 2, 3));
      key.Flush();

      RegistryKey key2 = Registry::CurrentUser().OpenSubKey("UnitTests");
      Console::WriteLine("Key1 = {0}", key2.GetValue("Key1"));
      Console::WriteLine("Key2 = {0}", key2.GetValue("Key2"));
      Console::WriteLine("Key3 = {0}", string::Join(", ", as<Array<byte>>(key2.GetValue("Key3"))));
      Console::WriteLine("Key4 = {0}", key2.GetValue("Key4"));
      Console::WriteLine("Key5 = {0}", string::Join(", ", as<Array<string>>(key2.GetValue("Key5"))));
      Console::WriteLine("Key6 = {0}", Int64::Parse(key2.GetValue("Key6").ToString()));
      Console::WriteLine("Key7 = {0}", key2.GetValue("Key7"));
      Console::ReadKey(true);
    }
  };
}

pcf_startup (Examples::Program)
