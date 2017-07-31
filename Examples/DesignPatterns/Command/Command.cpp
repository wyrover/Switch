// Command pattern -- Behavioral example

#include <Pcf/Pcf>

using namespace System;

namespace DesignPatterns {
  namespace Behavioral {
    // The 'Receiver' class
    class Receiver : public object {
    public:
      void Action() const {Console::WriteLine("Called Receiver.Action()");}
    };
    
    // The 'Command' abstract class
    class Command pcf_abstract {
    public:
      // Constructor
      Command(refptr<Receiver> receiver) : receiver(receiver) {}
      
      virtual void Execute() const =0;

    protected:
      refptr<Receiver> receiver;
    };
    
    // The 'ConcreteCommand' class
    class ConcreteCommand : public Command {
    public:
      // Constructor
      ConcreteCommand(refptr<Receiver> receiver) : Command(receiver) {}
      
      void Execute() const override {
        receiver->Action();
      }
    };
    
    // The 'Invoker' class
    class Invoker : public object {
    public:
      void SetCommand(refptr<Command> command) {this->command = command;}
      
      void ExecuteCommand() const {this->command->Execute();}
      
    private:
      refptr<Command> command;
    };
    
    // MainApp startup class for Behavioral
    // Command Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create receiver, command, and invoker
        refptr<Receiver> receiver = pcf_new<Receiver>();
        refptr<Command> command = pcf_new<ConcreteCommand>(receiver);
        refptr<Invoker> invoker = pcf_new<Invoker>();
        
        // Set and execute command
        invoker->SetCommand(command);
        invoker->ExecuteCommand();
      }
    };
  }
}

// Specify the Main entry point to System
pcf_startup (DesignPatterns::Behavioral::MainApp)

// This code produces the following output:
//
// Called Receiver.Action()