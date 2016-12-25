#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program : public object {
  public:
    using Writer = Delegate<void, const string&>;
    
    // Defines some methods to which the delegate can point.
    static void Main() {
      Program program;
      
      // Create writers delegate
      Writer writers;
      
      // Add static method to writers delegate
      writers += StaticMethod;

      // Add const member method to writers delegate
      writers += {program, &Program::ConstMemberMethod};

      // Add member method to writers delegate
      writers += {program, &Program::MemberMethod};

      // Add functor to delegate
      writers += Functor();

      // Add another functor to writers delegate
      writers += AnotherFunctor();

      // Add lambda expression to writers delegate
      writers += [](const string& value) {Console::WriteLine("Lambda expression write : {0}", value);};
      
      // Remove another functor from writers delegate
      writers -= AnotherFunctor();

      // Invoke writers delegate.
      writers("This example is beautyfull.");
    }
    
    Program() {}
    
  private:
    // Static method
    static void StaticMethod(const string& value) {Console::WriteLine("Static method write : {0}", value);}
    
    // Const member method
    void ConstMemberMethod(const string& value) const {Console::WriteLine("Const member method write : {0}", value);}
    
    // Member method
    void MemberMethod(const string& value) {Console::WriteLine("Member method write : {0}", value);}
    
    // Functor
    class Functor {
    public:
      void operator()(const string& value) {Console::WriteLine("Functor write : {0}", value);}
    };
    
    // Functor
    class AnotherFunctor {
    public:
      void operator()(const string& value) {Console::WriteLine("Another functor write : {0}", value);}
    };
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Static method write : This example is beautyfull.
// Const member method write : This example is beautyfull.
// Member method write : This example is beautyfull.
// Functor write : This example is beautyfull.
// Lambda expression write : This example is beautyfull.
