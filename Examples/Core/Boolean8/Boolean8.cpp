#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<Boolean > hasServiceCharges = {true, false};
      double subtotal = 120.62;
      double shippingCharge = 2.50;
      double serviceCharge = 5.00;
      
      for (Boolean hasServiceCharge : hasServiceCharges) {
        double total = subtotal + shippingCharge + (hasServiceCharge ? serviceCharge : 0);
        Console::WriteLine("hasServiceCharge = {0}: The total is ${1}.", hasServiceCharge, total);
      }
    }
  };
}

sw_startup (Examples::Program)

// This code produces the following output:
//
// hasServiceCharge = True: The total is $128.12.
// hasServiceCharge = False: The total is $123.12.
