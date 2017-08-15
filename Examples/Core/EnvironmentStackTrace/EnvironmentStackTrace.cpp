#include <Pcf/Pcf>

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

pcf_startup (Examples::Program)

// This example produces results similar to the following:
//
//
// StackTrace: '   at Pcf::System::Environment::$_14::operator()() const [0x000BD780] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at __opaque_function_pointer__<Pcf::System::String, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t>::FunctorInvoker<Pcf::System::Environment::$_14>::Invoke(__opaque_inner_function_ptr__ const&, __opaque_inner_function_ptr__ const&) [0x000BD660] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at __opaque_function_pointer__<Pcf::System::String, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t, std::nullptr_t>::operator()() const [0x00002CB0] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at Pcf::Property<Pcf::System::String, Pcf::ReadOnly>::operator()() const [0x00002C40] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at __opaque_format_item__::__opaque_format_item__<Pcf::System::String, Pcf::ReadOnly>(Pcf::Property<Pcf::System::String, Pcf::ReadOnly> const&) [0x000026B0] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at Pcf::System::String Pcf::System::String::Format<Pcf::Property<Pcf::System::String, Pcf::ReadOnly> >(Pcf::System::String const&, Pcf::Property<Pcf::System::String, Pcf::ReadOnly> const&) [0x00002410] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at void Pcf::System::Console::WriteLine<Pcf::Property<Pcf::System::String, Pcf::ReadOnly> >(Pcf::System::String const&, Pcf::Property<Pcf::System::String, Pcf::ReadOnly> const&) [0x00002350] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at Examples::Program::Main() [0x00002210] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at main::Startup::operator()(void (*)(), Pcf::System::Array<Pcf::System::String, 1, std::__1::allocator<Pcf::System::String> > const&) [0x000021E0] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at main [0x00002140] in /Users/yves/Projects/Pcf/bin/Examples/Debug/EnvironmentStackTrace:0
//    at start [0x00005234] in /usr/lib/system/libdyld.dylib:0'
