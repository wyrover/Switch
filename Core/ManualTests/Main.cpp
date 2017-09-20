#define TRACE
#include <Switch/Nameof.hpp>
#include <Switch/Startup.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/IO/StreamReader.hpp>
#include <Switch/System/Net/WebResponse.hpp>
#include <Switch/System/Net/WebRequest.hpp>

using namespace System;
using namespace System::IO;
using namespace System::Net;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      /*
      refptr<WebRequest> httpWebRequest = WebRequest::Create("https://sourceforge.net/projects/switchpro/files/stats/json?start_date=2017-01-01&end_date=2017-09-17");
      string result = StreamReader(httpWebRequest->GetResponse().GetResponseStream()).ReadToEnd();
      Console::WriteLine(result);
       */
      
      auto a = Array<>::CreateInstance<string>(3);
      a[0] = "One";
      a[1] = "Two";
      a[2] = "Three";
      
      for (auto b : a)
        Console::WriteLine(b);
    }
  };
}

_startup (Examples::Program)

