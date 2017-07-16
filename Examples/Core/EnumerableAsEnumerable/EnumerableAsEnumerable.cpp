#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  // Custom class.
  template<typename T>
  class Clump : public List<T> {
  public:
    Clump() {}
    Clump(InitializerList<string> il) : List<T>(il) {}
    // Custom implementation of Where().
    refptr<IEnumerable<T>> Where(Func<T, bool> predicate) {
      Console::WriteLine("In Clump's implementation of Where().");
      return Enumerable::Where<string>(*this, predicate);
    }
  };
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create a new Clump<T> object.
      Clump<string> fruitClump = { "apple", "passionfruit", "banana", "mango", "orange", "blueberry", "grape", "strawberry" };
      
      // First call to Where():
      // Call Clump's Where() method with a predicate.
      refptr<IEnumerable<string>> query1 = fruitClump.Where(pcf_delegate(string fruit) { return fruit.Contains("o");});
      
      Console::WriteLine("query1 has been created.\n");
      
      // Second call to Where():
      // First call AsEnumerable() to hide Clump's Where() method and thereby
      // force System::Linq::Enumerable's Where() method to be called.
      refptr<IEnumerable<string>> query2 = fruitClump.AsEnumerable()->Where(pcf_delegate(string fruit) { return fruit.Contains("o");});
      
      // Display the output.
      Console::WriteLine("query2 has been created.");
    }
  };
}

pcf_startup (Examples::Program)

// This code example produces the following output:
//
// In Clump's implementation of Where().
// query1 has been created.
//
// query2 has been created.


