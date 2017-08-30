#include <Switch/System/Random.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class RandomTest : public TestFixture {
  protected:
    void Next() {
      System::Collections::Generic::List<int> values(100);
      sw_using(Random rand(1)) {
        for(int i = 0; i < 100; i++) {
          int value = rand.Next();
          Assert::GreaterOrEqual(value, 0, sw_current_information);
          Assert::LessOrEqual(value, Int32::MaxValue), sw_current_information;
          values.Add(value);
        }
      }
      
      sw_using(Random rand(1)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(values[i], rand.Next(), sw_current_information);
      }
    }
    
    void NextWithRange0To10() {
      System::Collections::Generic::List<int> values(100);
      sw_using(Random rand(5)) {
        for(int i = 0; i < 100; i++) {
          int value = rand.Next(11);
          Assert::GreaterOrEqual(value, 0, sw_current_information);
          Assert::LessOrEqual(value, Int32::MaxValue), sw_current_information;
          values.Add(value);
        }
      }
      
      sw_using(Random rand(5)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(values[i], rand.Next(0, 11), sw_current_information);
      }
    }
    
    void NextBytes() {
      Array<byte> bytes(100);
      sw_using(Random rand(42))
        rand.NextBytes(bytes);
  
      sw_using(Random rand(42)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(bytes[i], rand.Next(Byte::MaxValue+1), sw_current_information);
      }
    }
  };
  
  sw_test(RandomTest, Next)
  sw_test(RandomTest, NextWithRange0To10)
  sw_test(RandomTest, NextBytes)
}
