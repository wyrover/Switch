// Command pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    /// @brief The 'Receiver' class
    class Receiver : public object {
    public:
      void Action() const {Console::WriteLine("Called Receiver.Action()");}
    };
    
    /// @brief The 'Command' abstract class
    class Command : public Abstract {
    public:
      // Constructor
      Command(Sp<Receiver> receiver) : receiver(receiver) {}
      
      virtual void Execute() const =0;

    protected:
      Sp<Receiver> receiver;
    };
    
    /// @brief The 'ConcreteCommand' class
    class ConcreteCommand : public Command {
    public:
      // Constructor
      ConcreteCommand(Sp<Receiver> receiver) : Command(receiver) {}
      
      void Execute() const override {
        receiver->Action();
      }
    };
    
    /// @brief The 'Invoker' class
    class Invoker : public object {
    public:
      void SetCommand(Sp<Command> command) {this->command = command;}
      
      void ExecuteCommand() const {this->command->Execute();}
      
    private:
      Sp<Command> command;
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[])  {
  using namespace DesignPatterns::Behavioral;
  
  // Create receiver, command, and invoker
  Sp<Receiver> receiver = new Receiver();
  Sp<Command> command = new ConcreteCommand(receiver);
  Sp<Invoker> invoker = new Invoker();
  
  // Set and execute command
  invoker->SetCommand(command);
  invoker->ExecuteCommand();
}

// This code produces the following output:
//
// Called Receiver.Action()
