// Composite pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections::Generic;

namespace DesignPatterns {
  namespace Structural {
    /// @brief The 'Component' abstract class
    class Component : public Abstract {
    public:
      // Constructor
      Component(const string& name) : name(name) {}
      
      virtual void Add(Sp<Component> c) =0;
      virtual void Remove(Sp<Component> c) =0;
      virtual void Display(int depth) const =0;

    protected:
      string name;
    };
    
    /// @brief The 'Composite' class
    class Composite : public Component {
    public:
      // Constructor
      Composite(string name) : Component(name) {}
      
      void Add(Sp<Component> component) override {this->children.Add(component);}
      
      void Remove(Sp<Component> component) override {this->children.Remove(component);}
      
      void Display(int depth) const override {
        Console::WriteLine(string('-', depth) + name);
        
        // Recursively display child nodes
        for (Sp<Component> component : this->children) {
          component->Display(depth + 2);
        }
      }

    private:
      List<Sp<Component>> children;
    };
    
    /// @brief The 'Leaf' class
    class Leaf : public Component {
    public:
      // Constructor
      Leaf(const string& name) : Component(name) {}
      
      void Display(int depth) const override {Console::WriteLine(string('-', depth) + name);}
      
    private:
      void Add(Sp<Component> c) override {throw InvalidOperationException("Cannot remove from a leaf");}
      void Remove(Sp<Component> c) override {throw InvalidOperationException("Cannot remove from a leaf");}
    };
  }
}

/// @brief Entry point into console application.
int main(int argc, char* argv[])  {
  using namespace DesignPatterns::Structural;
  
  // Create a tree structure
  Sp<Composite> root = new Composite("root");
  root->Add(new Leaf("Leaf A"));
  root->Add(new Leaf("Leaf B"));
  
  Sp<Composite> comp = new Composite("Composite X");
  comp->Add(new Leaf("Leaf XA"));
  comp->Add(new Leaf("Leaf XB"));
  
  root->Add(as<Component>(comp));
  root->Add(new Leaf("Leaf C"));
  
  // Add and remove a leaf
  Sp<Leaf> leaf = new Leaf("Leaf D");
  root->Add(as<Component>(leaf));
  root->Remove(as<Component>(leaf));
  
  // Recursively display tree
  root->Display(1);
}

// This code produces the following output:
//
// -root
// ---Leaf A
// ---Leaf B
// ---Composite X
// -----Leaf XA
// -----Leaf XB
// ---Leaf C
