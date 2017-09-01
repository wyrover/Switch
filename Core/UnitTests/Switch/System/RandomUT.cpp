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
      _using(Random rand(1)) {
        for(int i = 0; i < 100; i++) {
          int value = rand.Next();
          Assert::GreaterOrEqual(value, 0, _current_information);
          Assert::LessOrEqual(value, Int32::MaxValue), _current_information;
          values.Add(value);
        }
      }
      
      _using(Random rand(1)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(values[i], rand.Next(), _current_information);
      }
    }
    
    void NextWithRange0To10() {
      System::Collections::Generic::List<int> values(100);
      _using(Random rand(5)) {
        for(int i = 0; i < 100; i++) {
          int value = rand.Next(11);
          Assert::GreaterOrEqual(value, 0, _current_information);
          Assert::LessOrEqual(value, Int32::MaxValue), _current_information;
          values.Add(value);
        }
      }
      
      _using(Random rand(5)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(values[i], rand.Next(0, 11), _current_information);
      }
    }
    
    void NextBytes() {
      Array<byte> bytes(100);
      _using(Random rand(42))
        rand.NextBytes(bytes);
  
      _using(Random rand(42)) {
        for(int i = 0; i < 100; i++)
          Assert::AreEqual(bytes[i], rand.Next(Byte::MaxValue+1), _current_information);
      }
    }
  };
  
  _test(RandomTest, Next)
  _test(RandomTest, NextWithRange0To10)
  _test(RandomTest, NextBytes)
}
