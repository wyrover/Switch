#include <Pcf/System/Collections/ArrayList.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections;
using namespace TUnit;

namespace {
  TEST(ArrayList, DefaultConstructor) {
    ArrayList arrayList;
    
    Assert::AreEqual(0, arrayList.Count, pcf_current_information);
    Assert::AreEqual(0, arrayList.Capacity, pcf_current_information);
  }
  
  TEST(ArrayList, ConstructorFromCapacityTo0) {
    int32 capacity = 0;
    
    ArrayList arrayList(capacity);
    
    Assert::AreEqual(0, arrayList.Count, pcf_current_information);
    Assert::AreEqual(0, arrayList.Capacity, pcf_current_information);
  }
  
  TEST(ArrayList, ConstructorFromCapacityTo25) {
    int32 capacity = 25;
    
    ArrayList arrayList(capacity);
    
    Assert::AreEqual(0, arrayList.Count, pcf_current_information);
    Assert::AreEqual(25, arrayList.Capacity, pcf_current_information);
  }
  
  TEST(ArrayList, ConstructorFromCapacityToNegative) {
    int32 capacity = -10;
    
    ASSERT_THROW({ArrayList arrayList(capacity);}, ArgumentException);
  }
  
  TEST(ArrayList, ConstructorFromGenericIEnumerable) {
    Array<Any> array = {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")};
    Generic::IEnumerable<Any>& enumerable = array;

    ArrayList arrayList(enumerable);
    
    Assert::AreEqual(3, arrayList.Count, pcf_current_information);
    ASSERT_NE(0, arrayList.Capacity);
    Assert::AreEqual("Tyrannosaurus", as<String>(arrayList[0]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(arrayList[1]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(arrayList[2]), pcf_current_information);
  }
  
  TEST(ArrayList, ConstructorFromIEnumerable) {
    ArrayList array(Array<Any> {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")});
    IEnumerable& enumerable = array;

    ArrayList arrayList(enumerable);
    
    Assert::AreEqual(3, arrayList.Count, pcf_current_information);
    ASSERT_NE(0, arrayList.Capacity);
    Assert::AreEqual("Tyrannosaurus", as<String>(arrayList[0]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(arrayList[1]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(arrayList[2]), pcf_current_information);
  }
  
  TEST(ArrayList, AddSpObject) {
    ArrayList arrayList;

    arrayList.Add(String("Tyrannosaurus"));
    arrayList.Add(String("Amargasaurus"));
    arrayList.Add(String("Mamenchisaurus"));
    arrayList.Add(String("Deinonychus"));
    arrayList.Add(String("Compsognathus"));
    
    Assert::AreEqual(5, arrayList.Count, pcf_current_information);
    Assert::AreEqual("Tyrannosaurus", as<String>(arrayList[0]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(arrayList[1]), pcf_current_information);
    Assert::AreEqual("Mamenchisaurus", as<String>(arrayList[2]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(arrayList[3]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(arrayList[4]), pcf_current_information);
  }
  
  TEST(ArrayList, AddSpString) {
    ArrayList arrayList;

    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Assert::AreEqual(5, arrayList.Count, pcf_current_information);
    Assert::AreEqual("Tyrannosaurus", as<String>(arrayList[0]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(arrayList[1]), pcf_current_information);
    Assert::AreEqual("Mamenchisaurus", as<String>(arrayList[2]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(arrayList[3]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(arrayList[4]), pcf_current_information);
  }
  
  TEST(ArrayList, AddNewObject) {
    ArrayList arrayList;

    arrayList.Add(String("Tyrannosaurus"));
    arrayList.Add(String("Amargasaurus"));
    arrayList.Add(String("Mamenchisaurus"));
    arrayList.Add(String("Deinonychus"));
    arrayList.Add(String("Compsognathus"));
    
    Assert::AreEqual(5, arrayList.Count, pcf_current_information);
    Assert::AreEqual("Tyrannosaurus", as<String>(arrayList[0]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(arrayList[1]), pcf_current_information);
    Assert::AreEqual("Mamenchisaurus", as<String>(arrayList[2]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(arrayList[3]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(arrayList[4]), pcf_current_information);
  }
  
  TEST(ArrayList, AddObject) {
    ArrayList arrayList;

    arrayList.Add(String("Tyrannosaurus"));
    arrayList.Add(String("Amargasaurus"));
    arrayList.Add(String("Mamenchisaurus"));
    arrayList.Add(String("Deinonychus"));
    arrayList.Add(String("Compsognathus"));
    
    Assert::AreEqual(5, arrayList.Count, pcf_current_information);
    Assert::AreEqual("Tyrannosaurus", as<String>(arrayList[0]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(arrayList[1]), pcf_current_information);
    Assert::AreEqual("Mamenchisaurus", as<String>(arrayList[2]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(arrayList[3]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(arrayList[4]), pcf_current_information);
  }
  
  TEST(ArrayList, AddValueType) {
    ArrayList arrayList;

    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Assert::AreEqual(5, arrayList.Count, pcf_current_information);
    Assert::AreEqual("Tyrannosaurus", as<String>(arrayList[0]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(arrayList[1]), pcf_current_information);
    Assert::AreEqual("Mamenchisaurus", as<String>(arrayList[2]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(arrayList[3]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(arrayList[4]), pcf_current_information);
  }
  
  TEST(ArrayList, AddRangeGenericIEnumerable) {
    Array<Any> array = {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")};
    ArrayList added;
    
    added.AddRange(array);
    
    Assert::AreEqual(3, added.Count, pcf_current_information);
    Assert::AreEqual("Tyrannosaurus", as<String>(added[0]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(added[1]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(added[2]), pcf_current_information);
  }
  
  TEST(ArrayList, AddRangeIEnumerable) {
    ArrayList arrayList(Array<Any> {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")});
    ArrayList added;
    
    added.AddRange(arrayList);
    
    Assert::AreEqual(3, added.Count, pcf_current_information);
    Assert::AreEqual("Tyrannosaurus", as<String>(added[0]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(added[1]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(added[2]), pcf_current_information);
  }
  
  TEST(ArrayList, Clear) {
    ArrayList arrayList(Array<Any> {String("Tyrannosaurus"), String("Compsognathus"), String("Amargasaurus")});
    Assert::AreEqual(3, arrayList.Count, pcf_current_information);
    
    arrayList.Clear();
    
    Assert::AreEqual(0, arrayList.Count, pcf_current_information);
  }
  
  TEST(ArrayList, ContainsSpObjectFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Any value = "Tyrannosaurus";
    ASSERT_TRUE(arrayList.Contains(value));
  }
  
  TEST(ArrayList, ContainsSpObjectNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Any value = "Snowcat";
    ASSERT_FALSE(arrayList.Contains(value));
  }
  
  TEST(ArrayList, ContainsSpStringFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    String value = "Tyrannosaurus";
    ASSERT_TRUE(arrayList.Contains(value));
  }
  
  TEST(ArrayList, ContainsSpStringNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    String value = "Snowcat";
    ASSERT_FALSE(arrayList.Contains(value));
  }
  
  TEST(ArrayList, ContainsNewStringFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_TRUE(arrayList.Contains(String("Tyrannosaurus")));
  }
  
  TEST(ArrayList, ContainsNewStringNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_FALSE(arrayList.Contains(new String("Snowcat")));
  }
  
  TEST(ArrayList, ContainsObjectFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_TRUE(arrayList.Contains(String("Tyrannosaurus")));
  }
  
  TEST(ArrayList, ContainsObjectNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_FALSE(arrayList.Contains(String("Snowcat")));
  }
  
  TEST(ArrayList, ContainsValueTypeFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_TRUE(arrayList.Contains("Tyrannosaurus"));
  }
  
  TEST(ArrayList, ContainsValueTypeNotFound) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    ASSERT_FALSE(arrayList.Contains("Snowcat"));
  }
  
  TEST(ArrayList, CopyAllToArray) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count);
    arrayList.CopyTo(array);
    
    Assert::AreEqual("Tyrannosaurus", as<String>(array[0]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(array[1]), pcf_current_information);
    Assert::AreEqual("Mamenchisaurus", as<String>(array[2]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(array[3]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(array[4]), pcf_current_information);
  }
  
  TEST(ArrayList, CopyAllToArrayTooSmall) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count-1);
    ASSERT_THROW({arrayList.CopyTo(array);}, ArgumentException);
  }
  
  TEST(ArrayList, CopyAllToArrayAtIndexSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count+10);
    arrayList.CopyTo(array, 5);
    
    ASSERT_FALSE(array[0].HasValue());
    ASSERT_FALSE(array[1].HasValue());
    ASSERT_FALSE(array[2].HasValue());
    ASSERT_FALSE(array[3].HasValue());
    ASSERT_FALSE(array[4].HasValue());
    Assert::AreEqual("Tyrannosaurus", as<String>(array[5]), pcf_current_information);
    Assert::AreEqual("Amargasaurus", as<String>(array[6]), pcf_current_information);
    Assert::AreEqual("Mamenchisaurus", as<String>(array[7]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(array[8]), pcf_current_information);
    Assert::AreEqual("Compsognathus", as<String>(array[9]), pcf_current_information);
    ASSERT_FALSE(array[10].HasValue());
    ASSERT_FALSE(array[11].HasValue());
    ASSERT_FALSE(array[12].HasValue());
    ASSERT_FALSE(array[13].HasValue());
    ASSERT_FALSE(array[14].HasValue());
  }
  
  TEST(ArrayList, CopyAllToArrayAtIndexTooBigSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count+10);
    ASSERT_THROW({arrayList.CopyTo(array, 15);}, ArgumentException);
  }
  
  TEST(ArrayList, CopyAllToArrayAtNegativeIndexSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count+10);
    ASSERT_THROW({arrayList.CopyTo(array, -1);}, ArgumentException);
  }
  
  TEST(ArrayList, CopyAllToArrayAtIndexSpecifiedAndCountSpecified) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    Array<Any> array(arrayList.Count+10);
    arrayList.CopyTo(2, array, 5, 2);
    
    ASSERT_FALSE(array[0].HasValue());
    ASSERT_FALSE(array[1].HasValue());
    ASSERT_FALSE(array[2].HasValue());
    ASSERT_FALSE(array[3].HasValue());
    ASSERT_FALSE(array[4].HasValue());
    Assert::AreEqual("Mamenchisaurus", as<String>(array[5]), pcf_current_information);
    Assert::AreEqual("Deinonychus", as<String>(array[6]), pcf_current_information);
    ASSERT_FALSE(array[7].HasValue());
    ASSERT_FALSE(array[8].HasValue());
    ASSERT_FALSE(array[9].HasValue());
    ASSERT_FALSE(array[10].HasValue());
    ASSERT_FALSE(array[11].HasValue());
    ASSERT_FALSE(array[12].HasValue());
    ASSERT_FALSE(array[13].HasValue());
    ASSERT_FALSE(array[14].HasValue());
  }
  
  TEST(ArrayList, GetEnumerator) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    const char* array[] = {"Tyrannosaurus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"};
    int32 index = 0;

    Enumerator enumerator = arrayList.GetEnumerator();
    while (enumerator.MoveNext()) {
      Assert::AreEqual(array[index++], as<String>(enumerator.Current()), pcf_current_information);
    }
    Assert::AreEqual(5, index, pcf_current_information);
  }
  
  TEST(ArrayList, Foreach) {
    ArrayList arrayList;
    arrayList.Add("Tyrannosaurus");
    arrayList.Add("Amargasaurus");
    arrayList.Add("Mamenchisaurus");
    arrayList.Add("Deinonychus");
    arrayList.Add("Compsognathus");
    
    const char* array[] = {"Tyrannosaurus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"};
    int32 index = 0;
    for (auto item : arrayList) {
      Assert::AreEqual(array[index++], as<String>(item), pcf_current_information);
    }
    Assert::AreEqual(5, index, pcf_current_information);
  }
  
}