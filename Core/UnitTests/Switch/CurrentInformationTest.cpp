#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class CurrentInformationTest : public TestFixture {
  protected:
    void CreateAnEmptyCurrentInformationThenToString() {
      Caller ci;
      Assert::AreEqual("{Empty}", ci.ToString(), _caller);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFileName() {
      Caller ci;
      Assert::AreEqual("", ci.FilePath, _caller);
    }
    
    void CreateAnEmptyCurrentInformationThenGetFunctionName() {
      Caller ci;
      Assert::AreEqual("", ci.MemberNamne, _caller);
    }
    
    void CreateAnEmptyCurrentInformationThenGetLine() {
      Caller ci;
      Assert::AreEqual(0, ci.LineNumber);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenToString() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual("{FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString(), _caller);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFileName() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual("MyFile.txt", ci.FilePath, _caller);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetFunctionName() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual("", ci.MemberNamne, _caller);
    }
    
    void CreateCurrentInformationWithFileNameAndLineThenGetLine() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual(42, ci.LineNumber, _caller);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString() {
      Caller ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{FilePath=\"MyFile.txt\", LineNumber=42, MemberName=\"void MyFunction()\"}", ci.ToString(), _caller);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName() {
      Caller ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("MyFile.txt", ci.FilePath, _caller);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName() {
      Caller ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("void MyFunction()", ci.MemberNamne, _caller);
    }
    
    void CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine() {
      Caller ci("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual(42, ci.LineNumber, _caller);
    }
    
    void CreateCurrentInformationByCopyConstructorThenToString() {
      Caller ci = Caller("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{FilePath=\"MyFile.txt\", LineNumber=42, MemberName=\"void MyFunction()\"}", ci.ToString(), _caller);
    }
    
    void CreateCurrentInformationByCopyOperatorThenToString() {
      Caller ci;
      ci = Caller("MyFile.txt", 42, "void MyFunction()");
      Assert::AreEqual("{FilePath=\"MyFile.txt\", LineNumber=42, MemberName=\"void MyFunction()\"}", ci.ToString(), _caller);
    }
  };
  
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenToString)
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFileName)
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetFunctionName)
  _test(CurrentInformationTest, CreateAnEmptyCurrentInformationThenGetLine)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenToString)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFileName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetFunctionName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameAndLineThenGetLine)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenToString)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFileName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetFunctionName)
  _test(CurrentInformationTest, CreateCurrentInformationWithFileNameLineAndFunctionNameThenGetLine)
  _test(CurrentInformationTest, CreateCurrentInformationByCopyConstructorThenToString)
  _test(CurrentInformationTest, CreateCurrentInformationByCopyOperatorThenToString)
}
