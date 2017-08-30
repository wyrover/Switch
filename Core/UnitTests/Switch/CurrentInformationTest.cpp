#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class CurrentInformationTest : public TestFixture {
  protected:
    void CreateAnEmptyCurrentInformationThenToString() {
      CurrentInformation ci;
      Assert::AreEqual("{Empty}", ci.ToString(), sw_current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFileName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FileName, sw_current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFunctionName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FunctionName, sw_current_information);
    }
    
    void CreateAnEmptyCurrentInformationThenGetLine() {
      CurrentInformation ci;
      Assert::AreEqual(0, ci.Line);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenToString() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42}", ci.ToString(), sw_current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("MyFile.txt", ci.FileName, sw_current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("", ci.FunctionName, sw_current_information);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual(42, ci.Line, sw_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), sw_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("MyFile.txt", ci.FileName, sw_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("void MyFunction()", ci.FunctionName, sw_current_information);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual(42, ci.Line, sw_current_information);
    }
    
    void CreateCurrentInformationByCopyConstructorThenToString() {
      CurrentInformation ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), sw_current_information);
    }
    
    void CreateCurrentInformationByCopyOperatorThenToString() {
      CurrentInformation ci;
      ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString(), sw_current_information);
    }
  };
  
  sw_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenToString)
  sw_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFileName)
  sw_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFunctionName)
  sw_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetLine)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenToString)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFileName)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFunctionName)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetLine)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName)
  sw_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine)
  sw_test(CurrentInformationTest, CreateCurrentInformationByCopyConstructorThenToString)
  sw_test(CurrentInformationTest, CreateCurrentInformationByCopyOperatorThenToString)
}
