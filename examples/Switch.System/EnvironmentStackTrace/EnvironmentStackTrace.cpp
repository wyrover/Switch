#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::WriteLine();
      Console::WriteLine("StackTrace: '{0}'", Environment::StackTrace);
    }
  };
}

startup_(Examples::Program);

// This example produces results similar to the following:
//
//
// StackTrace: '   at Switch::System::Environment::$_14::operator()() const [0x000BD780] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at __opaque_function_pointer__<Switch::System::String, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t>::FunctorInvoker<Switch::System::Environment::$_14>::Invoke(__opaque_inner_function_ptr__ const&, __opaque_inner_function_ptr__ const&) [0x000BD660] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at __opaque_function_pointer__<Switch::System::String, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t>::operator()() const [0x00002CB0] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at Switch::property_<Switch::System::String, Switch::readonly_>::operator()() const [0x00002C40] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at __opaque_format_item__::__opaque_format_item__<Switch::System::String, Switch::readonly_>(Switch::property_<Switch::System::String, Switch::readonly_> const&) [0x000026B0] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at Switch::System::String Switch::System::String::Format<Switch::property_<Switch::System::String, Switch::readonly_> >(Switch::System::String const&, Switch::property_<Switch::System::String, Switch::readonly_> const&) [0x00002410] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at void Switch::System::Console::WriteLine<Switch::property_<Switch::System::String, Switch::readonly_> >(Switch::System::String const&, Switch::property_<Switch::System::String, Switch::readonly_> const&) [0x00002350] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at Examples::Program::Main() [0x00002210] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at main::Startup::operator()(void (*)(), Switch::System::Array<Switch::System::String, 1, std::__1::allocator<Switch::System::String> > const&) [0x000021E0] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at main [0x00002140] in /Users/yves/Projects/Switch/bin/Examples/Debug/EnvironmentStackTrace:0
//    at start [0x00005234] in /usr/lib/system/libdyld.dylib:0'
