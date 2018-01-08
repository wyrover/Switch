[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

# Definition

Given a language, define a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.

Usage     ![Usage](Pictures/Usage1.png)     Low

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/interpreter.gif)

# Sample code

This structural code demonstrates the Interpreter patterns, which using a defined grammer, provides the interpreter that processes parsed statements.

```c++
// Interpreter pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
using namespace System::Collections;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'Context' class
    class Context: public object {
    };
    
    // The 'AbstractExpression' abstract class
    class AbstractExpression abstract_ {
    public:
      virtual void Interpret(const Context& context) const =0;
    };
    
    // The 'TerminalExpression' class
    class TerminalExpression : public AbstractExpression {
    public:
      void Interpret(const Context& context) const override {Console::WriteLine("Called Terminal.Interpret()");}
    };
    
    // The 'NonterminalExpression' class
    class NonterminalExpression : public AbstractExpression {
    public:
      void Interpret(const Context& context) const override {Console::WriteLine("Called Nonterminal.Interpret()");}
    };
    
    // MainApp startup class for Behavioral
    // Interpreter Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        Context context;
        
        // Usually a tree
        ArrayList list;
        
        // Populate 'abstract syntax tree'
        list.Add(TerminalExpression());
        list.Add(NonterminalExpression());
        list.Add(TerminalExpression());
        list.Add(TerminalExpression());
        
        // Interpret
        for (auto exp : list) {
          as<AbstractExpression&>(exp).Interpret(context);
        }
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
Called Terminal.Interpret()
Called Nonterminal.Interpret()
Called Terminal.Interpret()
Called Terminal.Interpret()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
