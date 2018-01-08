![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

# Definition

Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

Usage     ![Usage](Pictures/Usage4.png)     Medium high

# UML class diagram

![AbstractFactory](Pictures/DesignPatterns/command.gif)

# Sample code

This structural code demonstrates the Command pattern which stores requests as objects allowing clients to execute or playback the requests.

```c++
// Command pattern -- Behavioral example
 
#include <Switch/Switch>
 
using namespace System;
 
namespace DesignPatterns {
  namespace Behavioral {
    // The 'Receiver' class
    class Receiver : public object {
    public:
      void Action() const {Console::WriteLine("Called Receiver.Action()");}
    };
    
    // The 'Command' abstract class
    class Command abstract_ {
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
        refptr<Receiver> receiver = ref_new<Receiver>();
        refptr<Command> command = ref_new<ConcreteCommand>(receiver);
        refptr<Invoker> invoker = ref_new<Invoker>();
        
        // Set and execute command
        invoker->SetCommand(command);
        invoker->ExecuteCommand();
      }
    };
  }
}
 
// Specify the Main entry point to System
startup_(DesignPatterns::Behavioral::MainApp);
```

# Output

```
Called Receiver.Action()
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
