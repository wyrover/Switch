#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    using Write = delegate<void, const string&>;

    // The main entry point for the application.
    static void Main() {
      Program program;
      // Declare a function pointer on a static method
      Write function1 = Function1;
      function1("Function pointer on Static method");

      // Declare a function pointer on a member method
      Write function2 = {program, &Program::Function2};
      function2("Function pointer on Const Member Method");

      // Declare a function pointer on a member method
      Write function3 = {program, &Program::Function3};
      function3("Function pointer on Member Method");

      // Declare a function rpointer on a functor
      Write function4 = program;
      function4("Function pointer on Functor");

      // Declare a function pointer on a lambda expression
      Write function5 = pcf_delegate(const string& value) {
        Function1(value);
      };
      function5("Function pointer on Lambda expression");

      // Declare a function pointer on a lambda expression with this
      Write function6 = pcf_delegate(const string& value) {
        //this->Function2(value);
      };
      function6("Function pointer on Lambda expression with this");

      Write function7 = null;
      try {
        function7("null");
      } catch (const std::exception& e) {
        Console::WriteLine(e.what());
      }
    }
    
    Program() {}

    // Functor
    void operator() (const string& value) {
      Console::WriteLine(value);
    }

  private:
    // Static method
    static void Function1(const string& value) {
      Console::WriteLine(value);
    }

    // Member method
    void Function2(const string& value) const {
      Console::WriteLine(value);
    }

    // Member method
    void Function3(const string& value) {
      Console::WriteLine(value);
    }
  };
}

pcf_startup (Examples::Program)
