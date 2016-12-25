// Interpreter pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections;

namespace DesignPatterns {
  namespace Behavioral {
    /// @brief The 'Context' class
    class Context: public object {
    };
    
    /// @brief The 'AbstractExpression' abstract class
    class AbstractExpression : public Abstract {
    public:
      virtual void Interpret(const Context& context) const =0;
    };
    
    /// @brief The 'TerminalExpression' class
    class TerminalExpression : public AbstractExpression {
    public:
      void Interpret(const Context& context) const override {Console::WriteLine("Called Terminal.Interpret()");}
    };
    
    /// @brief The 'NonterminalExpression' class
    class NonterminalExpression : public AbstractExpression {
    public:
      void Interpret(const Context& context) const override {Console::WriteLine("Called Nonterminal.Interpret()");}
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[]) {
  using namespace DesignPatterns::Behavioral;
  
  Context context;
  
  // Usually a tree
  ArrayList list;
  
  // Populate 'abstract syntax tree'
  list.Add(new TerminalExpression());
  list.Add(new NonterminalExpression());
  list.Add(new TerminalExpression());
  list.Add(new TerminalExpression());
  
  // Interpret
  for (Sp<object> exp : list) {
    as<AbstractExpression>(exp)->Interpret(context);
  }
}

// This code produces the following output:
//
// Called Terminal.Interpret()
// Called Nonterminal.Interpret()
// Called Terminal.Interpret()
// Called Terminal.Interpret()
