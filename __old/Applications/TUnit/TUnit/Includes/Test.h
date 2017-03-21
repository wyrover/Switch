#pragma once

#include <Pcf/Pcf>

namespace TUnitApplication {
  /// @cond
  class TestCase;
  /// @endcond
  
  class Test : public object, public Pcf::System::IHashable, public Pcf::System::IComparable {
  public:
    Test() {}
    Test(const Test& test) : name(test.name), testCaseName(test.testCaseName) {}
    explicit Test(const string& name, const string& testCaseName) : name(name), testCaseName(testCaseName) {}
    Test& operator =(const Test& test) {
      this->name = test.name;
      this->testCaseName = test.testCaseName;
      return *this;
    }
    
    Property<string> Name {
      pcf_get {return this->name;},
      pcf_set {this->name = value;}
    };
    
    Property<string> TestCaseName {
      pcf_get {return this->testCaseName;},
      pcf_set {this->testCaseName = value;}
    };
    
    int32 GetHashCode() const override {return name.GetHashCode() ^ testCaseName.GetHashCode();}
    
    int32 CompareTo(const IComparable& rhs) const override {
      return &rhs != null && is<Test>(rhs) && CompareTo((const Test&)rhs);
    }
    
    int32 CompareTo(const Test& rhs) const {
      return &rhs != null && this->name.CompareTo(rhs.name);
    }
    
  private:
    string name;
    string testCaseName;
  };
}
