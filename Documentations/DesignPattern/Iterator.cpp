// Iterator pattern -- Structural example

#include <Pcf/Pcf>

using namespace System;
using namespace System::Collections;

namespace DesignPatterns {
  namespace Behavioral {
    /// @brief The 'Iterator' abstract class
    class Iterator : public Abstract {
    public:
      virtual Sp<object> First() const abstract;
      virtual Sp<object> Next() const abstract;
      virtual bool IsDone() const abstract;
      virtual Sp<object> CurrentItem() const abstract;
    };
    
    /// @brief The 'ConcreteIterator' class
    class ConcreteIterator : public Iterator {
    public:
      // Constructor
      ConcreteIterator(const ConcreteAggregate& aggregate) : aggregate(aggregate) {}
      
      // Gets first iteration item
      Sp<object> First() const override {
        return this->aggregate[0];
      }
      
      // Gets next iteration item
      Sp<object> Next() const override {
        if (this->current < this->aggregate->Count - 1) {
          return this->aggregate[++this->current];
        }
        
        return null;
      }
      
      // Gets current iteration item
      Sp<object> CurrentItem() const override {
        return this->aggregate[this->current];
      }
      
      // Gets whether iterations are complete
      bool IsDone() const override {
        return this->current >= this->aggregate.Count;
      }
      
    private:
      const ConcreteAggregate& aggregate;
      int current = 0;
    };
    
    /// @brief The 'Aggregate' abstract class
    class Aggregate : public Abstract {
    public:
      virtual Up<Iterator> CreateIterator() abstract;
    };
    
    /// @brie The 'ConcreteAggregate' class
    class ConcreteAggregate : public Aggregate {
    public:
      Up<Iterator> CreateIterator() override {
        return new ConcreteIterator(*this);
      }
      
      // Gets item count
      Property<int, PublicGetterAttribute> Count {
        property_get { return this->items.Count; }
      };

      // Indexer
      Sp<object> operator [](int index) {
        return this->items[index];
      }
      
    private:
      ArrayList items;
    };
    
    /// <summary>
    /// MainApp startup class for Structural
    /// Iterator Design Pattern.
    /// </summary>
    class MainApp
    {
      /// <summary>
      /// Entry point into console application.
      /// </summary>
      static void Main()
      {
        ConcreteAggregate a = new ConcreteAggregate();
        a[0] = "Item A";
        a[1] = "Item B";
        a[2] = "Item C";
        a[3] = "Item D";
        
        // Create Iterator and provide aggregate
        ConcreteIterator i = new ConcreteIterator(a);
        
        Console.WriteLine("Iterating over collection:");
        
        object item = i.First();
        while (item != null)
        {
          Console.WriteLine(item);
          item = i.Next();
        }
        
        // Wait for user
        Console.ReadKey();
      }
    };
  }
}

// Specify the Main entry point to System
startup(&DesignPatterns::Behavioral::MainApp::Main);

// This code produces the following output:
//
// Iterating over collection:
// Item A
// Item B
// Item C
// Item D
