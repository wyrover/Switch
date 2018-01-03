#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Get the date and time for the current moment, adjusted
      // to the local time zone.

      DateTime saveNow = DateTime::Now();

      // Get the date and time for the current moment expressed
      // as coordinated universal time (UTC).

      DateTime saveUtcNow = DateTime::UtcNow();
      DateTime myDt;

      // Display the value and Kind property of the current moment
      // expressed as UTC and local time.

      DisplayNow("UtcNow: ..........", saveUtcNow);
      DisplayNow("Now: .............", saveNow);
      Console::WriteLine();

      // Change the Kind property of the current moment to
      // DateTimeKind.Utc and display the result.

      myDt = DateTime::SpecifyKind(saveNow, DateTimeKind::Utc);
      Display("Utc: .............", myDt);

      // Change the Kind property of the current moment to
      // DateTimeKind.Local and display the result.

      myDt = DateTime::SpecifyKind(saveNow, DateTimeKind::Local);
      Display("Local: ...........", myDt);

      // Change the Kind property of the current moment to
      // DateTimeKind.Unspecified and display the result.

      myDt = DateTime::SpecifyKind(saveNow, DateTimeKind::Unspecified);
      Display("Unspecified: .....", myDt);
    }

  private:
    // Display the value and Kind property for DateTime.Now and DateTime.UtcNow.
    static void DisplayNow(const string& title, const DateTime& inputDt) {
      string dtString = inputDt.ToString(datePatt);
      Console::WriteLine("{0} {1}, Kind = {2}", title, dtString, Enum<DateTimeKind>(inputDt.Kind));
    }

    // Display the value and Kind property of a DateTime structure, the
    // DateTime structure converted to local time, and the DateTime
    // structure converted to universal time.
    static void Display(const string& title, const DateTime& inputDt) {
      DateTime dispDt = inputDt;
      string dtString;

      // Display the original DateTime.

      dtString = dispDt.ToString(datePatt);
      Console::WriteLine("{0} {1}, Kind = {2}", title, dtString, Enum<DateTimeKind>(dispDt.Kind));

      // Convert inputDt to local time and display the result.
      // If inputDt.Kind is DateTimeKind.Utc, the conversion is performed.
      // If inputDt.Kind is DateTimeKind.Local, the conversion is not performed.
      // If inputDt.Kind is DateTimeKind.Unspecified, the conversion is
      // performed as if inputDt was universal time.

      dispDt = inputDt.ToLocalTime();
      dtString = dispDt.ToString(datePatt);
      Console::WriteLine("  ToLocalTime:     {0}, Kind = {1}", dtString, Enum<DateTimeKind>(dispDt.Kind));

      // Convert inputDt to universal time and display the result.
      // If inputDt.Kind is DateTimeKind.Utc, the conversion is not performed.
      // If inputDt.Kind is DateTimeKind.Local, the conversion is performed.
      // If inputDt.Kind is DateTimeKind.Unspecified, the conversion is
      // performed as if inputDt was local time.

      dispDt = inputDt.ToUniversalTime();
      dtString = dispDt.ToString(datePatt);
      Console::WriteLine("  ToUniversalTime: {0}, Kind = {1}", dtString, Enum<DateTimeKind>(dispDt.Kind));
      Console::WriteLine();
    }

    static const string datePatt;
  };

  const string Program::datePatt = "%m/%d/%Y %r";
}

startup_(Examples::Program);

// This code produces the following output:
//
// UtcNow: .......... 10-26-2015 06:56:54 PM, Kind = Utc
// Now: ............. 10-26-2015 07:56:54 PM, Kind = Local
//
// Utc: ............. 10-26-2015 07:56:54 PM, Kind = Utc
//   ToLocalTime:     10-26-2015 08:56:54 PM, Kind = Local
//   ToUniversalTime: 10-26-2015 07:56:54 PM, Kind = Utc
//
// Local: ........... 10-26-2015 07:56:54 PM, Kind = Local
//   ToLocalTime:     10-26-2015 07:56:54 PM, Kind = Local
//   ToUniversalTime: 10-26-2015 06:56:54 PM, Kind = Utc
//
// Unspecified: ..... 10-26-2015 07:56:54 PM, Kind = Unspecified
//   ToLocalTime:     10-26-2015 08:56:54 PM, Kind = Local
//   ToUniversalTime: 10-26-2015 06:56:54 PM, Kind = Utc
