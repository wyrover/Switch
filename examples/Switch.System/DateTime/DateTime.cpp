#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      int window = 10;
      int freq = 60 * 60 * 2; // 2 hours;

      DateTime d1 = DateTime::Now();

      DateTime d2 = d1.AddSeconds(2 * window);
      DateTime d3 = d1.AddSeconds(-2 * window);
      DateTime d4 = d1.AddSeconds(window / 2);
      DateTime d5 = d1.AddSeconds(-window / 2);

      DateTime d6 = (d1.AddHours(2)).AddSeconds(2 * window);
      DateTime d7 = (d1.AddHours(2)).AddSeconds(-2 * window);
      DateTime d8 = (d1.AddHours(2)).AddSeconds(window / 2);
      DateTime d9 = (d1.AddHours(2)).AddSeconds(-window / 2);

      Console::WriteLine("d1 ({0}) ~= d1 ({1}): {2}", d1, d1, RoughlyEquals(d1, d1, window, freq));
      Console::WriteLine("d1 ({0}) ~= d2 ({1}): {2}", d1, d2, RoughlyEquals(d1, d2, window, freq));
      Console::WriteLine("d1 ({0}) ~= d3 ({1}): {2}", d1, d3, RoughlyEquals(d1, d3, window, freq));
      Console::WriteLine("d1 ({0}) ~= d4 ({1}): {2}", d1, d4, RoughlyEquals(d1, d4, window, freq));
      Console::WriteLine("d1 ({0}) ~= d5 ({1}): {2}", d1, d5, RoughlyEquals(d1, d5, window, freq));

      Console::WriteLine("d1 ({0}) ~= d6 ({1}): {2}", d1, d6, RoughlyEquals(d1, d6, window, freq));
      Console::WriteLine("d1 ({0}) ~= d7 ({1}): {2}", d1, d7, RoughlyEquals(d1, d7, window, freq));
      Console::WriteLine("d1 ({0}) ~= d8 ({1}): {2}", d1, d8, RoughlyEquals(d1, d8, window, freq));
      Console::WriteLine("d1 ({0}) ~= d9 ({1}): {2}", d1, d9, RoughlyEquals(d1, d9, window, freq));
    }

  private:
    static bool RoughlyEquals(const DateTime& time, const DateTime& timeWithWindow, int windowInSeconds, int frequencyInSeconds) {
      int delta = Convert::ToInt32(TimeSpan(DateTime(timeWithWindow - time).Ticks()).TotalSeconds()) % frequencyInSeconds;

      delta = delta > windowInSeconds ? frequencyInSeconds - delta : delta;

      return Math::Abs(delta) < windowInSeconds;
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// d1 (4/03/2014 15:33:20) ~= d1 (4/03/2014 15:33:20): True
// d1 (4/03/2014 15:33:20) ~= d2 (4/03/2014 15:33:40): False
// d1 (4/03/2014 15:33:20) ~= d3 (4/03/2014 15:33:00): False
// d1 (4/03/2014 15:33:20) ~= d4 (4/03/2014 15:33:25): True
// d1 (4/03/2014 15:33:20) ~= d5 (4/03/2014 15:33:15): True
// d1 (4/03/2014 15:33:20) ~= d6 (4/03/2014 17:33:40): False
// d1 (4/03/2014 15:33:20) ~= d7 (4/03/2014 17:33:00): False
// d1 (4/03/2014 15:33:20) ~= d8 (4/03/2014 17:33:25): True
// d1 (4/03/2014 15:33:20) ~= d9 (4/03/2014 17:33:15): True
