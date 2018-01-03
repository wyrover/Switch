#define TRACE

#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      TraceMessage("Something happened.", caller_);
    }

    static void TraceMessage(const string& message, const System::Runtime::CompilerServices::Caller& caller) {
      System::Diagnostics::Trace::WriteLine("message: "_s + message);
      System::Diagnostics::Trace::WriteLine("member name: "_s + caller.MemberNamne);
      System::Diagnostics::Trace::WriteLine("source file path: "_s + caller.FilePath);
      System::Diagnostics::Trace::WriteLine("source line number: "_s + caller.LineNumber);
    }
  };
}

startup_(Examples::Program);

// This code produces the following output:
//
// 2017-09-12 12:09:35.202642+0200 Caller[66005:982055] message: Something happened.
// 2017-09-12 12:09:35.202857+0200 Caller[66005:982055] member name: Main
// 2017-09-12 12:09:35.202924+0200 Caller[66005:982055] source file path: /Users/UserName/Projects/Switch/Examples/Core/Caller/Caller.cpp
// 2017-09-12 12:09:35.203016+0200 Caller[66005:982055] source line number: 19
