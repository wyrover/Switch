#include <Pcf/System/Random.h>
#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  class RandomTest : public TestFixture {
  protected:
    void Next() {
      System::Collections::Generic::List<int> values(100);
      pcf_using(Random rand(1)) {
        for(int i = 0; i < 100; i++) {
          int value = rand.Next();
          Assert::GreaterOrEqual(value, 0, pcf_current_information);
          Assert::LessOrEqual(value, Int32::MaxValue), pcf_current_information;
          values.Add(value);
        }
      }
      
      pcf_using(Random rand(1)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(values[i], rand.Next(), pcf_current_information);
      }
    }
    
    void NextWithRange0To10() {
      System::Collections::Generic::List<int> values(100);
      pcf_using(Random rand(5)) {
        for(int i = 0; i < 100; i++) {
          int value = rand.Next(11);
          Assert::GreaterOrEqual(value, 0, pcf_current_information);
          Assert::LessOrEqual(value, Int32::MaxValue), pcf_current_information;
          values.Add(value);
        }
      }
      
      pcf_using(Random rand(5)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(values[i], rand.Next(0, 11), pcf_current_information);
      }
    }
    
    void NextBytes() {
      Array<byte> bytes(100);
      pcf_using(Random rand(42))
        rand.NextBytes(bytes);
  
      pcf_using(Random rand(42)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(bytes[i], rand.Next(Byte::MaxValue+1), pcf_current_information);
      }
    }
  };
  
  pcf_test(RandomTest, Next);
  pcf_test(RandomTest, NextWithRange0To10);
  pcf_test(RandomTest, NextBytes);
};