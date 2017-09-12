#define TRACE
#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Diagnostics/Trace.hpp>

using namespace System;

namespace Examples {
  class Program {
  public:
    class Data {
    public:
      Data() = default;
      Data(const Data& data) : items(data.items) {};
      
      _property<Array<int>> Items {
        _get {return this->items;},
        _set {this->items = value;}
      };
      
    private:
      Array<int> items = Array<>::CreateInstance<int>(8);
    };
    
    static void TraceMessage(string message, const System::Runtime::CompilerServices::Caller& caller) {
      System::Diagnostics::Trace::WriteLine("message: "_s + message);
      System::Diagnostics::Trace::WriteLine("member name: "_s + caller.MemberNamne);
      System::Diagnostics::Trace::WriteLine("source file path: "_s + caller.FilePath);
      System::Diagnostics::Trace::WriteLine("source line number: "_s + caller.LineNumber);
    }
    
    static void TraceMessage(string message, const string& memberNamne, const string& filePath, int lineNumber) {
      System::Diagnostics::Trace::WriteLine("message: "_s + message);
      System::Diagnostics::Trace::WriteLine("member name: "_s + memberNamne);
      System::Diagnostics::Trace::WriteLine("source file path: "_s + filePath);
      System::Diagnostics::Trace::WriteLine("source line number: "_s + lineNumber);
    }

    // The main entry point for the application.
    static void Main() {
      Data data;
      data.Items = {12, 24, 48};
      Console::WriteLine("{0} = {{{1}}}", _nameof(data.Items), _typeof(data.Items()));
      Console::WriteLine("{0} = {{{1}}}", _nameof(data.Items), string::Join(", ", data.Items()));
      TraceMessage("Something happened.", _caller);
      TraceMessage("Other thing happened.", __func__, __FILE__, __LINE__);
    }
  };
}

_startup (Examples::Program)

