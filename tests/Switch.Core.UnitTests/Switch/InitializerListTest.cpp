#include <Switch/InitializerList.hpp>
#include <Switch/System/Array.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(InitializerListTest, CreateCollectionWithInitializerList) {
    struct MyCollection {
      MyCollection(InitializerList<int> il) : values(il) {}
      Array<int> values;
    } collection = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int32 i = 0;
    for (const auto& value : collection.values)
      ASSERT_EQ(value, results[i++]);
    ASSERT_EQ(10, i);
  }
  
  TEST(InitializerListTest, CreateCollectionWithInitializerListThenIterateIt) {
    struct MyCollection {
      MyCollection(InitializerList<int> il) {
        for (int value : il)
          this->values.Add(value);
      }
      System::Collections::Generic::List<int> values;
    } collection = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int32 i = 0;
    for (const auto& value : collection.values)
      ASSERT_EQ(value, results[i++]);
    ASSERT_EQ(10, i);
  }
}

