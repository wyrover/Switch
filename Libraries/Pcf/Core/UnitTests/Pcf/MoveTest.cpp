#include <Pcf/Lock.h>
#include <Pcf/System/Diagnostics/Stopwatch.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace TUnit;

namespace PcfUnitTests {
  class MoveTest : public TestFixture {
  protected:
    void MoveString() {
      string s1 = "Original String";
      string s2 = Move(s1);
      Assert::AreEqual("", s1, pcf_current_information);
      Assert::AreEqual("Original String", s2, pcf_current_information);
    }
    
    void MoveArray() {
      Array<int32> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      Array<int32> a2 = Move(a1);
      Assert::AreEqual(0, a1.Length, pcf_current_information);
      Assert::AreEqual(10, a2.Length, pcf_current_information);
    }
    
    void MoveList() {
      List<int32> l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      List<int32> l2 = Move(l1);
      Assert::AreEqual(0, l1.Count, pcf_current_information);
      Assert::AreEqual(10, l2.Count, pcf_current_information);
    }
    
    void MoveDictionary() {
      Dictionary<string, int32> d1 = {{"One", 1}, {"Two", 2}, {"Three", 3}, {"Four", 4}, {"Five", 5}, {"Six", 6}, {"Seven", 7}, {"Eigth", 8}, {"Nine", 9}, {"Ten", 10}};
      Dictionary<string, int32> d2 = Move(d1);
      Assert::AreEqual(0, d1.Count, pcf_current_information);
      Assert::AreEqual(10, d2.Count, pcf_current_information);
    }
  };
  
  pcf_test(MoveTest, MoveString)
  pcf_test(MoveTest, MoveArray)
  pcf_test(MoveTest, MoveList)
  pcf_test(MoveTest, MoveDictionary)
}
