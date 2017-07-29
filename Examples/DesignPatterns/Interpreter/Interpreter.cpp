// Interpreter pattern -- Behavorial example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Context' class
    class Context: public object {
    };
    
    // The 'AbstractExpression' abstract class
    class AbstractExpression pcf_abstract {
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
pcf_startup (DesignPatterns::Behavioral::MainApp)

// This code produces the following output:
//
// Called Terminal.Interpret()
// Called Nonterminal.Interpret()
// Called Terminal.Interpret()
// Called Terminal.Interpret()
