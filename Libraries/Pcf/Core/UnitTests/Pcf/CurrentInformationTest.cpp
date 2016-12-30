#include <Pcf/Boxing.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class CurrentInformationTest : public TestFixture {
  protected:
    void CreateAnEmptyCurrentInformationThenToString() {
      CurrentInformation ci;
      Assert::AreEqual("{Empty}", ci.ToString());
    }
    
    void CreateAnEmptyCurrentInformationThenGetFileName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FileName);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFunctionName() {
      CurrentInformation ci;
      Assert::AreEqual("", ci.FunctionName);
    }
    
    void CreateAnEmptyCurrentInformationThenGetLine() {
      CurrentInformation ci;
      Assert::AreEqual(0, ci.Line);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenToString() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42}", ci.ToString());
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("MyFile.txt", ci.FileName);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual("", ci.FunctionName);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42);
      Assert::AreEqual(42, ci.Line);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString());
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("MyFile.txt", ci.FileName);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("void MyFunction()", ci.FunctionName);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine() {
      CurrentInformation ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual(42, ci.Line);
    }
    
    void CreateCurrentInformationByCopyConstructorThenToString() {
      CurrentInformation ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString());
    }
    
    void CreateCurrentInformationByCopyOperatorThenToString() {
      CurrentInformation ci;
      ci = CurrentInformation("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{File=\"MyFile.txt\", Line=42, Function=\"void MyFunction()\"}", ci.ToString());
    }
  };
  
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenToString);
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFileName);
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFunctionName);
  pcf_test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetLine);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenToString);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFileName);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFunctionName);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetLine);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName);
  pcf_test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine);
  pcf_test(CurrentInformationTest, CreateCurrentInformationByCopyConstructorThenToString);
  pcf_test(CurrentInformationTest, CreateCurrentInformationByCopyOperatorThenToString);
}
