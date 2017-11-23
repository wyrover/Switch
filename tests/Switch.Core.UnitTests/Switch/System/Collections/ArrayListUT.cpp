#include <Switch/System/Collections/ArrayList.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections;

namespace {
  TEST(ArrayListTest, DefaultConstructor) {
    ArrayList arrayList;
    
    ASSERT_EQ(0, arrayList.Count);
    ASSERT_EQ(0, arrayList.Capacity);
  }
  
  TEST(ArrayListTest, ConstructorFromCapacityTo0) {
    int32 capacity = 0;
    
    ArrayList arrayList(capacity);
    
    ASSERT_EQ(0, arrayList.Count);
    ASSERT_EQ(0, arrayList.Capacity);
  }
  
  TEST(ArrayListTest, ConstructorFromCapacityTo25) {
    int32 capacity = 25;
    
    ArrayList arrayList(capacity);
    
    ASSERT_EQ(0, arrayList.Count);
    ASSERT_EQ(25, arrayList.Capacity);
  }
  
  TEST(ArrayListTest, ConstructorFromCapacityToNegative) {
    int32 capacity = -10;
    
    ASSERT_THROW({ArrayList arrayList(capacity);}, ArgumentException);
  }
  
  TEST(ArrayListTest, ConstructorFromGenericIEnumerable) {
    Array<Any> array = {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")};
    Generic::IEnumerable<Any>& enumerable = array;
    
    ArrayList arrayList(enumerable);
    
    ASSERT_EQ(3, arrayList.Count);
    ASSERT_NE(0, arrayList.Capacity);
    ASSERT_EQ("Tyrannosaurus", as<String>(arrayList[0]));
    ASSERT_EQ("Compsognathus", as<String>(arrayList[1]));
    ASSERT_EQ("Amargasaurus", as<String>(arrayList[2]));
  }
  
  TEST(ArrayListTest, ConstructorFromIEnumerable) {
    ArrayList array(Array<Any> {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")});
    IEnumerable& enumerable = array;
    
    ArrayList arrayList(enumerable);
    
    ASSERT_EQ(3, arrayList.Count);
    ASSERT_NE(0, arrayList.Capacity);
    ASSERT_EQ("Tyrannosaurus", as<String>(arrayList[0]));
    ASSERT_EQ("Compsognathus", as<String>(arrayList[1]));
    ASSERT_EQ("Amargasaurus", as<String>(arrayList[2]));
  }
  
  TEST(ArrayListTest, AddSpObject) {
    ArrayList arrayList;
    
    arrayList.Add(String("Tyrannosaurus"));
    arrayList.Add(String("Amargasaurus"));
    arrayList.Add(String("Mamenchisaurus"));
    arrayList.Add(String("Deinonychus"));
    arrayList.Add(String("Compsognathus"));
    
    ASSERT_EQ(5, arrayList.Count);
    ASSERT_EQ("Tyrannosaurus", as<String>(arrayList[0]));
    ASSERT_EQ("Amargasaurus", as<String>(arrayList[1]));
    ASSERT_EQ("Mamenchisaurus", as<String>(arrayList[2]));
    ASSERT_EQ("Deinonychus", as<String>(arrayList[3]));
    ASSERT_EQ("Compsognathus", as<String>(arrayList[4]));
  }
  
  TEST(ArrayListTest, AddSpString) {
    ArrayList arrayList;
    
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_EQ(5, arrayList.Count);
    ASSERT_EQ("Tyrannosaurus", as<String>(arrayList[0]));
    ASSERT_EQ("Amargasaurus", as<String>(arrayList[1]));
    ASSERT_EQ("Mamenchisaurus", as<String>(arrayList[2]));
    ASSERT_EQ("Deinonychus", as<String>(arrayList[3]));
    ASSERT_EQ("Compsognathus", as<String>(arrayList[4]));
  }
  
  TEST(ArrayListTest, AddNewObject) {
    ArrayList arrayList;
    
    arrayList.Add(String("Tyrannosaurus"));
    arrayList.Add(String("Amargasaurus"));
    arrayList.Add(String("Mamenchisaurus"));
    arrayList.Add(String("Deinonychus"));
    arrayList.Add(String("Compsognathus"));
    
    ASSERT_EQ(5, arrayList.Count);
    ASSERT_EQ("Tyrannosaurus", as<String>(arrayList[0]));
    ASSERT_EQ("Amargasaurus", as<String>(arrayList[1]));
    ASSERT_EQ("Mamenchisaurus", as<String>(arrayList[2]));
    ASSERT_EQ("Deinonychus", as<String>(arrayList[3]));
    ASSERT_EQ("Compsognathus", as<String>(arrayList[4]));
  }
  
  TEST(ArrayListTest, AddObject) {
    ArrayList arrayList;
    
    arrayList.Add(String("Tyrannosaurus"));
    arrayList.Add(String("Amargasaurus"));
    arrayList.Add(String("Mamenchisaurus"));
    arrayList.Add(String("Deinonychus"));
    arrayList.Add(String("Compsognathus"));
    
    ASSERT_EQ(5, arrayList.Count);
    ASSERT_EQ("Tyrannosaurus", as<String>(arrayList[0]));
    ASSERT_EQ("Amargasaurus", as<String>(arrayList[1]));
    ASSERT_EQ("Mamenchisaurus", as<String>(arrayList[2]));
    ASSERT_EQ("Deinonychus", as<String>(arrayList[3]));
    ASSERT_EQ("Compsognathus", as<String>(arrayList[4]));
  }
  
  TEST(ArrayListTest, AddValueType) {
    ArrayList arrayList;
    
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_EQ(5, arrayList.Count);
    ASSERT_EQ("Tyrannosaurus", as<String>(arrayList[0]));
    ASSERT_EQ("Amargasaurus", as<String>(arrayList[1]));
    ASSERT_EQ("Mamenchisaurus", as<String>(arrayList[2]));
    ASSERT_EQ("Deinonychus", as<String>(arrayList[3]));
    ASSERT_EQ("Compsognathus", as<String>(arrayList[4]));
  }
  
  TEST(ArrayListTest, AddRangeGenericIEnumerable) {
    Array<Any> array = {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")};
    ArrayList added;
    
    added.AddRange(array);
    
    ASSERT_EQ(3, added.Count);
    ASSERT_EQ("Tyrannosaurus", as<String>(added[0]));
    ASSERT_EQ("Compsognathus", as<String>(added[1]));
    ASSERT_EQ("Amargasaurus", as<String>(added[2]));
  }
  
  TEST(ArrayListTest, AddRangeIEnumerable) {
    ArrayList arrayList(Array<Any> {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")});
    ArrayList added;
    
    added.AddRange(arrayList);
    
    ASSERT_EQ(3, added.Count);
    ASSERT_EQ("Tyrannosaurus", as<String>(added[0]));
    ASSERT_EQ("Compsognathus", as<String>(added[1]));
    ASSERT_EQ("Amargasaurus", as<String>(added[2]));
  }
  
  TEST(ArrayListTest, Clear) {
    ArrayList arrayList(Array<Any> {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")});
    ASSERT_EQ(3, arrayList.Count);
    
    arrayList.Clear();
    
    ASSERT_EQ(0, arrayList.Count);
  }
  
  TEST(ArrayListTest, ContainsSpObjectFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Any value = "Tyrannosaurus";
    ASSERT_TRUE(arrayList.Contains(value));
  }
  
  TEST(ArrayListTest, ContainsSpObjectNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Any value = "Snowcat";
    ASSERT_FALSE(arrayList.Contains(value));
  }
  
  TEST(ArrayListTest, ContainsSpStringFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    String value = "Tyrannosaurus";
    ASSERT_TRUE(arrayList.Contains(value));
  }
  
  TEST(ArrayListTest, ContainsSpStringNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    String value = "Snowcat";
    ASSERT_FALSE(arrayList.Contains(value));
  }
  
  TEST(ArrayListTest, ContainsNewStringFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_TRUE(arrayList.Contains(String("Tyrannosaurus")));
  }
  
  TEST(ArrayListTest, ContainsNewStringNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_FALSE(arrayList.Contains(String("Snowcat")));
  }
  
  TEST(ArrayListTest, ContainsObjectFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_TRUE(arrayList.Contains(String("Tyrannosaurus")));
  }
  
  TEST(ArrayListTest, ContainsObjectNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_FALSE(arrayList.Contains(String("Snowcat")));
  }
  
  TEST(ArrayListTest, ContainsValueTypeFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_TRUE(arrayList.Contains("Tyrannosaurus"));
  }
  
  TEST(ArrayListTest, ContainsValueTypeNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_FALSE(arrayList.Contains("Snowcat"));
  }
  
  TEST(ArrayListTest, CopyAllToArray) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count);
    arrayList.CopyTo(array);
    
    ASSERT_EQ("Tyrannosaurus", as<String>(array[0]));
    ASSERT_EQ("Amargasaurus", as<String>(array[1]));
    ASSERT_EQ("Mamenchisaurus", as<String>(array[2]));
    ASSERT_EQ("Deinonychus", as<String>(array[3]));
    ASSERT_EQ("Compsognathus", as<String>(array[4]));
  }
  
  TEST(ArrayListTest, CopyAllToArrayTooSmall) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count - 1);
    ASSERT_THROW({arrayList.CopyTo(array);}, ArgumentException);
  }
  
  TEST(ArrayListTest, CopyAllToArrayAtIndexSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count + 10);
    arrayList.CopyTo(array, 5);
    
    ASSERT_FALSE(array[0].HasValue());
    ASSERT_FALSE(array[1].HasValue());
    ASSERT_FALSE(array[2].HasValue());
    ASSERT_FALSE(array[3].HasValue());
    ASSERT_FALSE(array[4].HasValue());
    ASSERT_EQ("Tyrannosaurus", as<String>(array[5]));
    ASSERT_EQ("Amargasaurus", as<String>(array[6]));
    ASSERT_EQ("Mamenchisaurus", as<String>(array[7]));
    ASSERT_EQ("Deinonychus", as<String>(array[8]));
    ASSERT_EQ("Compsognathus", as<String>(array[9]));
    ASSERT_FALSE(array[10].HasValue());
    ASSERT_FALSE(array[11].HasValue());
    ASSERT_FALSE(array[12].HasValue());
    ASSERT_FALSE(array[13].HasValue());
    ASSERT_FALSE(array[14].HasValue());
  }
  
  TEST(ArrayListTest, CopyAllToArrayAtIndexTooBigSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count + 10);
    ASSERT_THROW({arrayList.CopyTo(array, 15);}, ArgumentException);
  }
  
  TEST(ArrayListTest, CopyAllToArrayAtNegativeIndexSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count + 10);
    ASSERT_THROW({arrayList.CopyTo(array, -1);}, ArgumentException);
  }
  
  TEST(ArrayListTest, CopyAllToArrayAtIndexSpecifiedAndCountSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count + 10);
    arrayList.CopyTo(2, array, 5, 2);
    
    ASSERT_FALSE(array[0].HasValue());
    ASSERT_FALSE(array[1].HasValue());
    ASSERT_FALSE(array[2].HasValue());
    ASSERT_FALSE(array[3].HasValue());
    ASSERT_FALSE(array[4].HasValue());
    ASSERT_EQ("Mamenchisaurus", as<String>(array[5]));
    ASSERT_EQ("Deinonychus", as<String>(array[6]));
    ASSERT_FALSE(array[7].HasValue());
    ASSERT_FALSE(array[8].HasValue());
    ASSERT_FALSE(array[9].HasValue());
    ASSERT_FALSE(array[10].HasValue());
    ASSERT_FALSE(array[11].HasValue());
    ASSERT_FALSE(array[12].HasValue());
    ASSERT_FALSE(array[13].HasValue());
    ASSERT_FALSE(array[14].HasValue());
  }
  
  TEST(ArrayListTest, GetEnumerator) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    const char* array[] = {"Tyrannosaurus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"};
    int32 index = 0;
    
    Enumerator enumerator = arrayList.GetEnumerator();
    while(enumerator.MoveNext())
      ASSERT_EQ(array[index++], as<String>(enumerator.Current()));
    ASSERT_EQ(5, index);
  }
  
  TEST(ArrayListTest, Foreach) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    const char* array[] = {"Tyrannosaurus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"};
    int32 index = 0;
    for(auto item : arrayList)
      ASSERT_EQ(array[index++], as<String>(item));
    ASSERT_EQ(5, index);
  }
  
}
