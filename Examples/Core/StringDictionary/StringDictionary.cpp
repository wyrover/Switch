#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Specialized;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Creates and initializes a new StringDictionary.
      StringDictionary myCol;
      myCol.Add("red", "rojo");
      myCol.Add("green", "verde");
      myCol.Add("blue", "azul");
      
      // Display the contents of the collection using foreach. This is the preferred method.
      Console::WriteLine("Displays the elements using foreach:");
      PrintKeysAndValues1( myCol );
      
      // Display the contents of the collection using the enumerator.
      Console::WriteLine("Displays the elements using the IEnumerator:");
      PrintKeysAndValues2(myCol);
      
      // Display the contents of the collection using the Keys, Values, Count, and Item properties.
      Console::WriteLine("Displays the elements using the Keys, Values, Count, and Item properties:");
      PrintKeysAndValues3(myCol);
      
      // Copies the StringDictionary to an array with DictionaryEntry elements.
      Array<StringKeyValuePair> myArr(myCol.Count);
      myCol.CopyTo(myArr, 0);
      
      // Displays the values in the array.
      Console::WriteLine("Displays the elements in the array:");
      Console::WriteLine("   KEY        VALUE");
      for (int i = 0; i < myArr.Length; i++)
        Console::WriteLine( "   {0,-10} {1}", myArr[i].Key(), myArr[i].Value());
      Console::WriteLine();
      
      // Searches for a value.
      if (myCol.ContainsValue("amarillo"))
        Console::WriteLine("The collection contains the value \"amarillo\".");
      else
        Console::WriteLine("The collection does not contain the value \"amarillo\".");
      Console::WriteLine();
      
      // Searches for a key and deletes it.
      if ( myCol.ContainsKey("green"))
        myCol.Remove("green");
      Console::WriteLine("The collection contains the following elements after removing \"green\":");
      PrintKeysAndValues1(myCol);
      
      // Clears the entire collection.
      myCol.Clear();
      Console::WriteLine("The collection contains the following elements after it is cleared:");
      PrintKeysAndValues1(myCol);
    }
    
  private:
    // Uses the foreach statement which hides the complexity of the enumerator.
    // NOTE: The foreach statement is the preferred way of enumerating the contents of a collection.
    static void PrintKeysAndValues1(const StringDictionary& myCol)  {
      Console::WriteLine("   KEY                       VALUE");
      for (StringKeyValuePair de : myCol ) {
        Console::WriteLine("   {0,-25} {1}",  de.Key(), de.Value());
      }
      Console::WriteLine();
    }
    
    // Uses the enumerator.
    // NOTE: The foreach statement is the preferred way of enumerating the contents of a collection.
    static void PrintKeysAndValues2(const StringDictionary& myCol)  {
      StringKeyValuePairEnumerator myEnumerator = myCol.GetEnumerator();
      StringKeyValuePair de;
      Console::WriteLine("   KEY                       VALUE");
      while (myEnumerator.MoveNext())  {
        de = myEnumerator.Current;
        Console::WriteLine("   {0,-25} {1}",  de.Key(), de.Value());
      }
      Console::WriteLine();
    }
    
    // Uses the Keys, Values, Count, and Item properties.
    static void PrintKeysAndValues3(const StringDictionary& myCol)  {
      Array<string> myKeys = myCol.Keys().ToArray();
      
      Console::WriteLine("   INDEX KEY                       VALUE");
      for (int i = 0; i < myCol.Count; i++) {
        Console::WriteLine("   {0:%-5d} {1,-25} {2}", i,  myKeys[i], myCol[myKeys[i]]);
      }
      Console::WriteLine();
    }
  };
}

startup (Examples::Program)

// This code example produces the following output:
//
// Displays the elements using foreach:
//    KEY                       VALUE
//    blue                      azul
//    green                     verde
//    red                       rojo
//
// Displays the elements using the IEnumerator:
//    KEY                       VALUE
//    blue                      azul
//    green                     verde
//    red                       rojo
//
// Displays the elements using the Keys, Values, Count, and Item properties:
//    INDEX KEY                       VALUE
//    0     blue                      azul
//    1     green                     verde
//    2     red                       rojo
//
// Displays the elements in the array:
//    KEY        VALUE
//    blue       azul
//    green      verde
//    red        rojo
//
// The collection does not contain the value "amarillo".
//
// The collection contains the following elements after removing "green":
//    KEY                       VALUE
//    blue                      azul
//    red                       rojo
//
// The collection contains the following elements after it is cleared:
//    KEY                       VALUE
//
