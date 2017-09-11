#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Add double
      Add(Box(0.42));
      
      // Add const char*
      Add(Box("Hello"));
      
      // Add int
      Add(Box(42));
      
      // Add TimeSpan
      Add(Box(126_s));
      
      // Add bool
      Add(Box(true));
      
      // Add System::Collections::Generic::KeyValuePair<string, int>
      Add(Box(System::Collections::Generic::KeyValuePair<string, int>("Key", 84)));
      
      for (auto item : items)
        Console::WriteLine(*item);
    }
    
  private:
    // Add item of polymorphic objects
    template<typename T>
    static void Add(const T& obj) {
      items.Add(ref_new<T>(obj));
    }
    
    static System::Collections::Generic::List<refptr<object>> items;
  };
  
  // List of polymorphic objects
  System::Collections::Generic::List<refptr<object>> Program::items;
}

startup (Examples::Program)

// This code produces the following output:
//
// 0.42
// Hello
// 42
// 00:02:06
// True
// [Key, 84]
