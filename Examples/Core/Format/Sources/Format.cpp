#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      System::Collections::Generic::KeyValuePair<TimeSpan, string> keyValue = {2_h + 2_min + 57_s, "Marathon world record (Dennis Kimetto, Kenya)"};
      string result = string::Format("{{key={0}, Value={1}}}", keyValue.Key, keyValue.Value);
      Console::WriteLine("Result {0}", result);
      Console::WriteLine("Format integer in decimal = {0:D}, hexa = {0:X} or {0:x}, in binary {0:B}", 0xDEAD);
      Console::WriteLine("args : {0}, {1}, {2}, {3}", 42, "Info", DateTime::Now, DayOfWeek::Wednesday);
      Console::WriteLine("args : {0}, {1}, {2}, {3}, {4}", Array<Reference<object>> {Box(42), string("Info"), DateTime::Now(), Box(.25), Tuple<string, Byte> {"item1", 255}});
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Result {key=02:02:57, Value=Marathon world record (Dennis Kimetto, Kenya)}
// Format integer in decimal = 57005, hexa = DEAD or dead, in binary 1101111010101101
// args : 42, Info, 26/08/2016 22:45:26, Wednesday
// args : 42, Info, 26/08/2016 22:45:26, 0.25, (item1, 255)
