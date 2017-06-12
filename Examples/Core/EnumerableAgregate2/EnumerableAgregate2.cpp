#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<int> ints = {4, 8, 8, 3, 9, 0, 7, 8, 2};
      
      // Count the even numbers in the array, using a seed value of 0.
      int numEven = ints.Agregate<int>(0, pcf_delegate(const int& total, const int& next) {
        return next % 2 == 0 ? total + 1 : total;
      });
      
      Console::WriteLine("The number of even integers is: {0}", numEven);
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// The number of even integers is: 6
//
