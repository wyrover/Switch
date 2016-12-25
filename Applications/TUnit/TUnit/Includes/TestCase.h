#pragma once

#include "TestCollection.h"

namespace TUnitApplication {
  class TestCase : public object {
  public:
    TestCase() {}
    TestCase(const TestCase& test) : name(test.name), tests(test.tests) {}
    TestCase& operator =(const TestCase& test) {
      this->name = test.name;
      this->tests = test.tests;
      return *this;
    }
    explicit TestCase(const string& name) : name(name) {}
    explicit TestCase(const string& name, const System::Collections::Generic::IEnumerable<Test>& tests) : name(name), tests(tests) {}
    
    Property<string> Name {
      pcf_get {return this->name;},
      pcf_set {this->name = value;}
    };
    
    Property<TestCollection&> Tests {
      [&]()->TestCollection& {return this->tests;},
      [&](TestCollection& value) {this->tests = value;}
    };
    
  private:
    string name;
    TestCollection tests;
  };
}