![Switch Header](Images/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Definition

Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

# UML class diagram

![AbstractFactory](Images/DesignPatterns/composite.gif)

# Sample code

This structural code demonstrates the Composite pattern which allows the creation of a tree structure in which individual nodes are accessed uniformly whether they are leaf nodes or branch (composite) nodes.

```c++
// Composite pattern -- Structural example
 
#include <Switch/Switch>
 
using namespace System;
using namespace System::Collections::Generic;
 
namespace DesignPatterns {
  namespace Structural {
    // The 'Component' abstract class
    class Component _abstract {
    public:
      // Constructor
      Component(const string& name) : name(name) {}
      
      virtual void Add(refptr<Component> c) = 0;
      virtual void Remove(refptr<Component> c) = 0;
      virtual void Display(int depth) const = 0;
 
    protected:
      string name;
    };
    
    // The 'Composite' class
    class Composite : public Component {
    public:
      // Constructor
      Composite(string name) : Component(name) {}
      
      void Add(refptr<Component> component) override {this->children.Add(component);}
      
      void Remove(refptr<Component> component) override {this->children.Remove(component);}
      
      void Display(int depth) const override {
        Console::WriteLine(string('-', depth) + name);
        
        // Recursively display child nodes
        for (refptr<Component> component : this->children)
          component->Display(depth + 2);
      }
 
    private:
      List<refptr<Component>> children;
    };
    
    // The 'Leaf' class
    class Leaf : public Component {
    public:
      // Constructor
      Leaf(const string& name) : Component(name) {}
      
      void Display(int depth) const override {Console::WriteLine(string('-', depth) + name);}
      
    private:
      void Add(refptr<Component> c) override {throw InvalidOperationException("Cannot remove from a leaf");}
      void Remove(refptr<Component> c) override {throw InvalidOperationException("Cannot remove from a leaf");}
    };
    
    // MainApp startup class for Structural
    // Composite Design Pattern.
    class MainApp {
    public:
      // Entry point into console application.
      static void Main() {
        // Create a tree structure
        refptr<Composite> root = ref_new<Composite>("root");
        root->Add(ref_new<Leaf>("Leaf A"));
        root->Add(ref_new<Leaf>("Leaf B"));
        
        refptr<Composite> comp = ref_new<Composite>("Composite X");
        comp->Add(ref_new<Leaf>("Leaf XA"));
        comp->Add(ref_new<Leaf>("Leaf XB"));
        
        root->Add(as<Component>(comp));
        root->Add(ref_new<Leaf>("Leaf C"));
        
        // Add and remove a leaf
        refptr<Leaf> leaf = ref_new<Leaf>("Leaf D");
        root->Add(as<Component>(leaf));
        root->Remove(as<Component>(leaf));
        
        // Recursively display tree
        root->Display(1);
      }
    };
  }
}
 
// Specify the Main entry point to System
_startup (DesignPatterns::Structural::MainApp)
```

# Output

```
-root
---Leaf A
---Leaf B
---Composite X
-----Leaf XA
-----Leaf XB
---Leaf C
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Common Design Patterns](CommonDesignPatterns.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
