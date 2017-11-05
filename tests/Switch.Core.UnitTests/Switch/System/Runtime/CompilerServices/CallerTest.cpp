#include <Switch/Boxing.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Runtime::CompilerServices;
using namespace TUnit;

namespace SwitchUnitTests {
  class CallerTest : public TestFixture {
  protected:
    void CreateAnEmptyCallerThenToString() {
      Caller ci;
      Assert::AreEqual("{Empty}", ci.ToString(), _caller);
    }
    
    void CreateAnEmptyCallerThenGetFileName() {
      Caller ci;
      Assert::AreEqual("", ci.FilePath, _caller);
    }
    
    void CreateAnEmptyCallerThenGetFunctionName() {
      Caller ci;
      Assert::AreEqual("", ci.MemberNamne, _caller);
    }
    
    void CreateAnEmptyCallerThenGetLine() {
      Caller ci;
      Assert::AreEqual(0, ci.LineNumber);
    }
    
    void CreateCallerWithFileNameAndLineThenToString() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual("{FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString(), _caller);
    }
    
    void CreateCallerWithFileNameAndLineThenGetFileName() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual("MyFile.txt", ci.FilePath, _caller);
    }
    
    void CreateCallerWithFileNameAndLineThenGetFunctionName() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual("", ci.MemberNamne, _caller);
    }
    
    void CreateCallerWithFileNameAndLineThenGetLine() {
      Caller ci("MyFile.txt", 42);
      Assert::AreEqual(42, ci.LineNumber, _caller);
    }
    
    void CreateCallerWithFileNameLineAndFunctionNameThenToString() {
      Caller ci("void MyFunction()", "MyFile.txt", 42);
      Assert::AreEqual("{MemberName=\"void MyFunction()\", FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString(), _caller);
    }
    
    void CreateCallerWithFileNameLineAndFunctionNameThenGetFileName() {
      Caller ci("void MyFunction()", "MyFile.txt", 42);
      Assert::AreEqual("MyFile.txt", ci.FilePath, _caller);
    }
    
    void CreateCallerWithFileNameLineAndFunctionNameThenGetFunctionName() {
      Caller ci("void MyFunction()", "MyFile.txt", 42);
      Assert::AreEqual("void MyFunction()", ci.MemberNamne, _caller);
    }
    
    void CreateCallerWithFileNameLineAndFunctionNameThenGetLine() {
      Caller ci("void MyFunction()", "MyFile.txt", 42);
      Assert::AreEqual(42, ci.LineNumber, _caller);
    }
    
    void CreateCallerByCopyConstructorThenToString() {
      Caller ci = Caller("void MyFunction()", "MyFile.txt", 42);
      Assert::AreEqual("{MemberName=\"void MyFunction()\", FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString(), _caller);
    }
    
    void CreateCallerByCopyOperatorThenToString() {
      Caller ci;
      ci = Caller("void MyFunction()", "MyFile.txt", 42);
      Assert::AreEqual("{MemberName=\"void MyFunction()\", FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString(), _caller);
    }
  };
  
  _AddTest(CallerTest, CreateAnEmptyCallerThenToString)
  _AddTest(CallerTest, CreateAnEmptyCallerThenGetFileName)
  _AddTest(CallerTest, CreateAnEmptyCallerThenGetFunctionName)
  _AddTest(CallerTest, CreateAnEmptyCallerThenGetLine)
  _AddTest(CallerTest, CreateCallerWithFileNameAndLineThenToString)
  _AddTest(CallerTest, CreateCallerWithFileNameAndLineThenGetFileName)
  _AddTest(CallerTest, CreateCallerWithFileNameAndLineThenGetFunctionName)
  _AddTest(CallerTest, CreateCallerWithFileNameAndLineThenGetLine)
  _AddTest(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenToString)
  _AddTest(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenGetFileName)
  _AddTest(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenGetFunctionName)
  _AddTest(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenGetLine)
  _AddTest(CallerTest, CreateCallerByCopyConstructorThenToString)
  _AddTest(CallerTest, CreateCallerByCopyOperatorThenToString)
}
