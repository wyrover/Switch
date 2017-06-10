#include <Pcf/Boxing.hpp>
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class CurrentInformationTest : public TestFixture {
  protected:
    void CreateAnEmptyCurrentInformationThenToString() {
      CurrentInformation ci;
      Assert::AreEqual("{Empty}", ci.ToString(), pcf_current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFileName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FileName, pcf_current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFunctionName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FunctionName, pcf_current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetLine() {
      CurrentInformation ci;
      Assert::AreEqual(0, ci.Line);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenToString() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42}", ci.ToString(), pcf_current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("MyFile.txt", ci.FileName, pcf_current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("", ci.FunctionName, pcf_current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual(42, ci.Line, pcf_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), pcf_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("MyFile.txt", ci.FileName, pcf_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("void MyFunction()", ci.FunctionName, pcf_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual(42, ci.Line, pcf_current_information);
    }
    
    void CreateCurrentInformationByCopyConstructorThenToString() {
      CurrentInformation ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), pcf_current_information);
    }
    
    void CreateCurrentInformationByCopyOperatorThenToString() {
      CurrentInformation ci;
      ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), pcf_current_information);
    }
  };
  
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenToString)
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFileName)
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFunctionName)
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetLine)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenToString)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFileName)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFunctionName)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetLine)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName)
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine)
  pcf_test(CurrentInformationTest, CreateCurrentInformationByCopyConstructorThenToString)
  pcf_test(CurrentInformationTest, CreateCurrentInformationByCopyOperatorThenToString)
}
