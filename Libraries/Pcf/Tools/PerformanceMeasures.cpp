#include <Pcf/Pcf>

#include "ArrayTests.h"
#include "ListTests.h"
#include "Measures.h"
#include "Operation.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace Tools {
  namespace Performance {
    class Program : public object {
    public:
      static void Main() {
        Tools::Performance::Program::RunArrayTests();
        Tools::Performance::Program::RunListTests();
        Console::ReadKey(true);
      }
    
      static const int length = 1000000;
      
      static int GetLength() {
        return Program::length;
      }
      
      static void DisplayInformation(const string& name) {
        Console::WriteLine("- {0} :", name);
        Console::WriteLine(string('=', name.Length()+4));
        Console::WriteLine();
        Console::WriteLine("   Each operation is performed with {0} items and the results are expressed in nanoseconds.", Program::GetLength());
        Console::WriteLine();
        
        Console::WriteLine("   {0,-15} {1,10} {2,10}     {3,-10}", "Operation", "std", "System", "Times slower");
        Console::WriteLine("   {0,-15} {1,10} {2,10}     {3,-10}", "---------", "---", "------", "------------");
      }
      
      static void DisplayOperation(const string& name, Operation operation) {
        Measures measures = operation();
        Console::WriteLine("   {0,-15} {1,10} {2,10} ==> {3:G2}", name, measures.Item1(), measures.Item2(), Convert::ToDouble(measures.Item2())/measures.Item1());
      }
      
      static void RunArrayTests() {
        ArrayTests arrayTests(length);
        DisplayInformation(arrayTests.ToString());
        DisplayOperation("Create", {arrayTests, &ArrayTests::Create});
        DisplayOperation("Destroy", {arrayTests, &ArrayTests::Destroy});
        DisplayOperation("LinearRead", {arrayTests, &ArrayTests::LinearRead});
        DisplayOperation("RandomRead", {arrayTests, &ArrayTests::RandomRead});
        DisplayOperation("LinearWrite", {arrayTests, &ArrayTests::LinearWrite});
        DisplayOperation("RandomWrite", {arrayTests, &ArrayTests::RandomWrite});
        DisplayOperation("Foreach", {arrayTests, &ArrayTests::Foreach});
        Console::WriteLine();
      }
      
      static void RunListTests() {
        ListTests listTests(length);
        DisplayInformation(listTests.ToString());
        DisplayOperation("Create", {listTests, &ListTests::Create});
        DisplayOperation("Destroy", {listTests, &ListTests::Destroy});
        DisplayOperation("Add", {listTests, &ListTests::Add});
        DisplayOperation("Insert", {listTests, &ListTests::Insert});
        DisplayOperation("RemoveLast", {listTests, &ListTests::RemoveLast});
        DisplayOperation("RemoveFirst", {listTests, &ListTests::RemoveFirst});
        DisplayOperation("RandomRemove", {listTests, &ListTests::RandomRemove});
        DisplayOperation("LinearRead", {listTests, &ListTests::LinearRead});
        DisplayOperation("RandomRead", {listTests, &ListTests::RandomRead});
        DisplayOperation("LinearWrite", {listTests, &ListTests::LinearWrite});
        DisplayOperation("RandomWrite", {listTests, &ListTests::RandomWrite});
        DisplayOperation("Enumerate", {listTests, &ListTests::Enumerate});
        DisplayOperation("Foreach", {listTests, &ListTests::Foreach});
        Console::WriteLine();
      }
    };
  }
}

pcf_startup (Tools::Performance::Program)
