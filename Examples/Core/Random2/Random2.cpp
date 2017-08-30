#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Instantiate random number generator using system-supplied value as seed.
      Random rand;
      
      // Generate and display 5 random byte (integer) values.
      Array<byte> bytes(4);
      rand.NextBytes(bytes);
      
      Console::WriteLine("Five random byte values:");
      for (byte byteValue : bytes)
        Console::Write("{0, 5}", byteValue);
      Console::WriteLine();
      
      // Generate and display 5 random integers.
      Console::WriteLine("Five random integer values:");
      for (int ctr = 0; ctr <= 4; ctr++)
        Console::Write("{0, 15}", rand.Next());
      Console::WriteLine();
      
      // Generate and display 5 random integers between 0 and 100.//
      Console::WriteLine("Five random integers between 0 and 100:");
      for (int ctr = 0; ctr <= 4; ctr++)
        Console::Write("{0, 10}", rand.Next(101));
      Console::WriteLine();
      
      // Generate and display 5 random integers from 50 to 100.
      Console::WriteLine("Five random integers between 50 and 100:");
      for (int ctr = 0; ctr <= 4; ctr++)
        Console::Write("{0, 10}", rand.Next(50, 101));
      Console::WriteLine();
      
      // Generate and display 5 random floating point values from 0 to 1.
      Console::WriteLine("Five Doubles.");
      for (int ctr = 0; ctr <= 4; ctr++)
        Console::Write("{0, 10}", rand.NextDouble());
      Console::WriteLine();
      
      // Generate and display 5 random floating point values from 0 to 5.
      Console::WriteLine("Five Doubles between 0 and 5.");
      for (int ctr = 0; ctr <= 4; ctr++)
        Console::Write("{0, 10}", rand.NextDouble() * 5);
      Console::WriteLine();
    }
  };
}

sw_startup (Examples::Program)

// This code produces the following output:
//
// Five random byte values:
//   217   19  208    0
// Five random integer values:
//        42111834     1251474175     1071620507     1927997407      471669866
// Five random integers between 0 and 100:
//         46        91         6        26        48
// Five random integers between 50 and 100:
//         53        92        51        86        99
// Five Doubles.
//   0.500364  0.611498  0.451463  0.739825  0.237592
// Five Doubles between 0 and 5.
//    1.05285  0.268477   2.29327   3.06932    1.0676
