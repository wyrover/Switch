#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

int main(int argc, char* argv[]) {
  List<int> grades = {78, 92, 100, 37, 81};
  
  double average = grades.Average();
  
  Console::WriteLine("The average grade is {0}.", average);
}

// This code produces the following output:
//
// The average grade is 77.6.
