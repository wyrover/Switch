#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Threading/Thread.hpp>
#include <Switch/System/Random.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;

namespace {
  class AbstractListHelper : public object {

  protected:
    AbstractListHelper() {}
    AbstractListHelper(int32 value, const string& name) : value(value), name(name) {}

  public:
    virtual String ToString() const {return string::Format("{0} {1}", this->value, this->name);}

  private:
    int32 value;
    string name;
  };

  class ListHelper : public AbstractListHelper {

  public:
    ListHelper() {}
    ListHelper(int32 value, const string& name) : AbstractListHelper(value, name) {}
  };

  class Dinosaur : public object {
  public:
    Dinosaur(const string& name, int32 numberOfLegsUsedToWalk) : name(name), numberOfLegsUsedToWalk(numberOfLegsUsedToWalk) {}

    Dinosaur(const Dinosaur& dinosaur) : name(dinosaur.name), numberOfLegsUsedToWalk(dinosaur.numberOfLegsUsedToWalk) {}

    Dinosaur& operator=(const Dinosaur& dinasaure) {
      name = dinasaure.name;
      numberOfLegsUsedToWalk = dinasaure.numberOfLegsUsedToWalk;
      return *this;
    }

    String ToString() const override { return this->name; }
    const string& GetName() const { return this->name; }

    bool Equals(const object& obj) const override {
      if (!is<Dinosaur>(obj))
        return false;

      const Dinosaur* that = (const Dinosaur*)&obj;
      return this->name.Equals(that->name) && this->numberOfLegsUsedToWalk == that->numberOfLegsUsedToWalk;
    }

  private:
    string name;
    int32  numberOfLegsUsedToWalk;
  };

  class DinosaurComparer : public System::Collections::Generic::IComparer<Dinosaur> {
  public:
    DinosaurComparer() {}

    virtual int32 Compare(const Dinosaur& d1, const Dinosaur& d2) const {
      return d1.GetName().CompareTo(d2.GetName());
    }
  };

  TEST(ListTest, DefaultConstructor) {
    // Create List<T> with default Capacity (IDataList<T>::MaxCapacity)
    List<string> strings;
    EXPECT_LE(0, strings.Capacity);
    ASSERT_EQ(0, strings.Count);
    ASSERT_FALSE(strings.IsFixedSize);
    ASSERT_FALSE(strings.IsReadOnly);
  }

  TEST(ListTest, ConstructorWithCapacityEqualTo25) {
    List<Boolean> booleans(25);
    EXPECT_LE(25, booleans.Capacity);
    ASSERT_EQ(0, booleans.Count);
    ASSERT_FALSE(booleans.IsFixedSize);
    ASSERT_FALSE(booleans.IsReadOnly);
  }

  TEST(ListTest, ConstructorWithCapacityEqualTo0) {
    List<Int32> int32s(0);
    EXPECT_LE(0, int32s.Capacity);
    ASSERT_EQ(0, int32s.Count);
    ASSERT_FALSE(int32s.IsFixedSize);
    ASSERT_FALSE(int32s.IsReadOnly);
  }

  TEST(ListTest, ConstructorWithArray) {
    Array<Int64> int64Items = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    List<Int64> int64s(int64Items);
    EXPECT_LE(19, int64s.Capacity);
    ASSERT_EQ(19, int64s.Count);
    ASSERT_FALSE(int64s.IsFixedSize);
    ASSERT_FALSE(int64s.IsReadOnly);

    List< refptr<ListHelper>> myList;
    myList.Add(new ListHelper(1, "YFI"));
    myList.Add(new ListHelper(2, "VLE"));

    ASSERT_EQ(string("1 YFI"), myList[0]->ToString());
    ASSERT_EQ(string("2 VLE"), myList[1]->ToString());

    // Create List<T> with a Capacity less than 0
    ASSERT_THROW(List<Int16>(-1), ArgumentException);
  }

  TEST(ListTest, NoDynamicAllocation) {
    Array<string> stringItems = {"Tyrannosaurus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"};
    // Create List<T> with a Capacity equal to 5)
    List<string> dinosaurs(stringItems);

    EXPECT_LE(5, dinosaurs.Capacity);
    ASSERT_EQ(5, dinosaurs.Count);

    dinosaurs.Add("null");
    EXPECT_LE(6, dinosaurs.Capacity);
    ASSERT_EQ(6, dinosaurs.Count);

    // Add a 6th item
    dinosaurs.Add("Mamenchisaurus");
    EXPECT_LE(7, dinosaurs.Capacity);
    ASSERT_EQ(7, dinosaurs.Count);
  }

  TEST(ListTest, Add) {
    // Create List<T> with a Capacity equal to 5)
    List<string> dinosaurs(5);

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    EXPECT_LE(5, dinosaurs.Capacity);
    ASSERT_EQ(5, dinosaurs.Count);

    dinosaurs.Add("null");
    EXPECT_LE(6, dinosaurs.Capacity);
    ASSERT_EQ(6, dinosaurs.Count);

    // Add a 6th item
    dinosaurs.Add("Mamenchisaurus");
    EXPECT_LE(7, dinosaurs.Capacity);
    ASSERT_EQ(7, dinosaurs.Count);

    // Delete all items
    dinosaurs.Clear();
  }

  TEST(ListTest, AddRange) {
    // Create List<T> to used in addRange function
    List<string> dinosaurs;

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");

    // Create List<T> with default Capacity (IDataList<T>::MaxCapacity)
    List<string> dinosaursCopy;

    // AddRange items
    dinosaursCopy.AddRange(dinosaurs);
    EXPECT_LE(0, dinosaursCopy.Capacity);
    ASSERT_EQ(5, dinosaursCopy.Count);

    dinosaursCopy.Clear();

    // Create List<T> with a Capacity equal to 4)
    List<string> dinosaursCopy2(4);

    // AddRange 5 items in List of 4 items
    dinosaursCopy2.AddRange(dinosaurs);
    EXPECT_LE(5, dinosaursCopy2.Capacity);
    ASSERT_EQ(5, dinosaursCopy2.Count);

    // AddRange null items
    // List<string> *listNull = null;
    // ASSERT_THROW(dinosaursCopy2->AddRange(*listNull), ArgumentNullException);
    EXPECT_LE(5, dinosaursCopy2.Capacity);
    ASSERT_EQ(5, dinosaursCopy2.Count);
  }

  TEST(ListTest, RemoveRange) {
    // Create List<T> to used in addRange function
    List<string> dinosaurs;

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");

    ASSERT_TRUE(dinosaurs[2].Equals(string("Mamenchisaurus")));
    dinosaurs.RemoveRange(2, 2);
    ASSERT_EQ(3, dinosaurs.Count);
    ASSERT_TRUE(dinosaurs[2].Equals(string("Compsognathus")));
  }

  TEST(ListTest, InsertAt) {
    // Create List<T> to used in addRange function
    List<string> dinosaurs;

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");

    ASSERT_EQ(3, dinosaurs.Count);
    ASSERT_TRUE(dinosaurs[0].Equals(string("Tyrannosaurus")));
    ASSERT_TRUE(dinosaurs[1].Equals(string("Amargasaurus")));
    ASSERT_TRUE(dinosaurs[2].Equals(string("Mamenchisaurus")));

    dinosaurs.Insert(2, string("Deinonychus"));

    ASSERT_EQ(4, dinosaurs.Count);
    ASSERT_TRUE(dinosaurs[0].Equals(string("Tyrannosaurus")));
    ASSERT_TRUE(dinosaurs[1].Equals(string("Amargasaurus")));
    ASSERT_TRUE(dinosaurs[2].Equals(string("Deinonychus")));
    ASSERT_TRUE(dinosaurs[3].Equals(string("Mamenchisaurus")));

    dinosaurs.Insert(2, "Compsognathus");

    ASSERT_EQ(5, dinosaurs.Count);
    ASSERT_TRUE(dinosaurs[0].Equals(string("Tyrannosaurus")));
    ASSERT_TRUE(dinosaurs[1].Equals(string("Amargasaurus")));
    ASSERT_TRUE(dinosaurs[2].Equals(string("Compsognathus")));
    ASSERT_TRUE(dinosaurs[3].Equals(string("Deinonychus")));
    ASSERT_TRUE(dinosaurs[4].Equals(string("Mamenchisaurus")));
  }


  TEST(ListTest, Clear) {
    // Create List<T> to used with Clear function
    List<string> dinosaurs;
    EXPECT_LE(0, dinosaurs.Capacity);
    ASSERT_EQ(0, dinosaurs.Count);

    // Clear an empty List
    dinosaurs.Clear();
    EXPECT_LE(0, dinosaurs.Capacity);
    ASSERT_EQ(0, dinosaurs.Count);

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");

    EXPECT_LE(5, dinosaurs.Capacity);
    ASSERT_EQ(5, dinosaurs.Count);

    // Clear items in List
    dinosaurs.Clear();
    EXPECT_LE(0, dinosaurs.Capacity);
    ASSERT_EQ(0, dinosaurs.Count);

    // Create List<T> to used with Clear function
    List<string> dinosaurs2(5);
    EXPECT_LE(5, dinosaurs2.Capacity);
    ASSERT_EQ(0, dinosaurs2.Count);

    // Clear an empty List
    dinosaurs2.Clear();
    EXPECT_LE(5, dinosaurs2.Capacity);
    ASSERT_EQ(0, dinosaurs2.Count);

    // Add 5 items
    dinosaurs2.Add("Tyrannosaurus");
    dinosaurs2.Add("Amargasaurus");
    dinosaurs2.Add("Mamenchisaurus");
    dinosaurs2.Add("Deinonychus");
    dinosaurs2.Add("Compsognathus");

    EXPECT_LE(5, dinosaurs2.Capacity);
    ASSERT_EQ(5, dinosaurs2.Count);

    // Clear items in List
    dinosaurs2.Clear();
    EXPECT_LE(5, dinosaurs2.Capacity);
    ASSERT_EQ(0, dinosaurs2.Count);
  }

  TEST(ListTest, Contains) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Test contains
    ASSERT_FALSE(dinosaurs.Contains("Deinonychus"));

    // Add 6 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Mamenchisaurus");

    // Test contains
    ASSERT_TRUE(dinosaurs.Contains("Mamenchisaurus"));
    ASSERT_FALSE(dinosaurs.Contains("Snowcat"));
  }

  TEST(ListTest, CopyTo) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    Array<string> array(20);

    // Test contains
    ASSERT_FALSE(dinosaurs.Contains("Deinonychus"));

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");

    // Test CopyTo
    dinosaurs.CopyTo(array);
    ASSERT_EQ(array[0], "Tyrannosaurus");
    ASSERT_EQ(array[1], "Amargasaurus");
    ASSERT_EQ(array[2], "Mamenchisaurus");
    ASSERT_EQ(array[3], "Deinonychus");
    ASSERT_EQ(array[4], "Compsognathus");

    dinosaurs.CopyTo(array, 6);
    ASSERT_EQ(array[0], "Tyrannosaurus");
    ASSERT_EQ(array[1], "Amargasaurus");
    ASSERT_EQ(array[2], "Mamenchisaurus");
    ASSERT_EQ(array[3], "Deinonychus");
    ASSERT_EQ(array[4], "Compsognathus");
    ASSERT_EQ(array[5], "");
    ASSERT_EQ(array[6], "Tyrannosaurus");
    ASSERT_EQ(array[7], "Amargasaurus");
    ASSERT_EQ(array[8], "Mamenchisaurus");
    ASSERT_EQ(array[9], "Deinonychus");
    ASSERT_EQ(array[10], "Compsognathus");

    dinosaurs.CopyTo(2, array, 12, 3);
    ASSERT_EQ(array[0], "Tyrannosaurus");
    ASSERT_EQ(array[1], "Amargasaurus");
    ASSERT_EQ(array[2], "Mamenchisaurus");
    ASSERT_EQ(array[3], "Deinonychus");
    ASSERT_EQ(array[4], "Compsognathus");
    ASSERT_EQ(array[5], "");
    ASSERT_EQ(array[6], "Tyrannosaurus");
    ASSERT_EQ(array[7], "Amargasaurus");
    ASSERT_EQ(array[8], "Mamenchisaurus");
    ASSERT_EQ(array[9], "Deinonychus");
    ASSERT_EQ(array[10], "Compsognathus");
    ASSERT_EQ(array[11], "");
    ASSERT_EQ(array[12], "Mamenchisaurus");
    ASSERT_EQ(array[13], "Deinonychus");
    ASSERT_EQ(array[14], "Compsognathus");
    ASSERT_EQ(array[15], "");
  }

  TEST(ListTest, CopyTo2) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    Array<string> array(20);

    // Test contains
    ASSERT_FALSE(dinosaurs.Contains("Deinonychus"));

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");

    ASSERT_THROW(dinosaurs.CopyTo(array, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.CopyTo(-1, array,  0, 5), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.CopyTo(0, array,  0, -1), ArgumentOutOfRangeException);
  }

  TEST(ListTest, CopyTo3) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    Array<string> array(20);

    // Test contains
    ASSERT_FALSE(dinosaurs.Contains("Deinonychus"));

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");

    ASSERT_THROW(dinosaurs.CopyTo(array,  20), ArgumentException);
    ASSERT_THROW(dinosaurs.CopyTo(0, array,  0, 6), ArgumentException);
    ASSERT_THROW(dinosaurs.CopyTo(1, array,  0, 5), ArgumentException);
  }

  TEST(ListTest, CopyTo4) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Test contains
    ASSERT_FALSE(dinosaurs.Contains("Deinonychus"));

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");

    Array<string> array(3);
    ASSERT_THROW(dinosaurs.CopyTo(array), ArgumentException);
  }

  class CompareString : public object {

  public:
    CompareString(const string& str) {
      mEndWith = str;
    }

    bool EndsWithSomething(string& dinosaur) {
      return dinosaur.EndsWith(mEndWith, true);
    }

  private :
    string mEndWith;
  };

  class TestList : public object {

  public:
    TestList(const string& value) {
      mValue = value;
    }

    bool EndsWithValue(const string& dinosaur) {
      return dinosaur.EndsWith(mValue, true);
    }

    bool StartsWithValue(const string& dinosaur) {
      return dinosaur.StartsWith(mValue, true);
    }

    static bool EndsWithSaurus(const string& dinosaur) {
      return dinosaur.EndsWith("saurus", true);
    }

    static bool StartsWithCat(const string& dinosaur) {
      return dinosaur.StartsWith("cat", true);
    }

    string mValue;
  };

  TEST(ListTest, Exists) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Oviraptor");
    dinosaurs.Add("Velociraptor");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Dilophosaurus");
    dinosaurs.Add("Gallimimus");
    dinosaurs.Add("Triceratops");

    ASSERT_TRUE(dinosaurs.Exists(&TestList::EndsWithSaurus));
    ASSERT_TRUE(dinosaurs.Exists(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)));
    ASSERT_FALSE(dinosaurs.Exists(&TestList::StartsWithCat));
    ASSERT_FALSE(dinosaurs.Exists(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)));
  }

  TEST(ListTest, RemoveAll) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Oviraptor");
    dinosaurs.Add("Velociraptor");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Dilophosaurus");
    dinosaurs.Add("Gallimimus");
    dinosaurs.Add("Triceratops");

    ASSERT_EQ(dinosaurs.RemoveAll(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 3);
    ASSERT_EQ(dinosaurs.Count, 6);
    ASSERT_EQ(dinosaurs[0], "Compsognathus");
    ASSERT_EQ(dinosaurs[1], "Oviraptor");
    ASSERT_EQ(dinosaurs[2], "Velociraptor");
    ASSERT_EQ(dinosaurs[3], "Deinonychus");
    ASSERT_EQ(dinosaurs[4], "Gallimimus");
    ASSERT_EQ(dinosaurs[5], "Triceratops");
  }

  TEST(ListTest, Reverse) {
    // Create List<T> to used with Contains function
    List<int32> dinosaurs;

    // Add 9 items
    for (int32 i = 0; i < 9; i += 1)
      dinosaurs.Add(i);
    dinosaurs.Reverse();

    for (int32 i = 0; i < 9; i += 1)
      ASSERT_EQ(dinosaurs[i], 8 - i);

    dinosaurs.Reverse(3, 4);
    ASSERT_EQ(dinosaurs[0], 8);
    ASSERT_EQ(dinosaurs[1], 7);
    ASSERT_EQ(dinosaurs[2], 6);
    ASSERT_EQ(dinosaurs[3], 2);
    ASSERT_EQ(dinosaurs[4], 3);
    ASSERT_EQ(dinosaurs[5], 4);
    ASSERT_EQ(dinosaurs[6], 5);
    ASSERT_EQ(dinosaurs[7], 1);
    ASSERT_EQ(dinosaurs[8], 0);

    ASSERT_THROW(dinosaurs.Reverse(-1, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.Reverse(0, -1), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.Reverse(7, 3), ArgumentException);

    dinosaurs.Reverse(7, 2);
    ASSERT_EQ(dinosaurs[0], 8);
    ASSERT_EQ(dinosaurs[1], 7);
    ASSERT_EQ(dinosaurs[2], 6);
    ASSERT_EQ(dinosaurs[3], 2);
    ASSERT_EQ(dinosaurs[4], 3);
    ASSERT_EQ(dinosaurs[5], 4);
    ASSERT_EQ(dinosaurs[6], 5);
    ASSERT_EQ(dinosaurs[7], 0);
    ASSERT_EQ(dinosaurs[8], 1);

    dinosaurs.Reverse(4, 1);
    ASSERT_EQ(dinosaurs[0], 8);
    ASSERT_EQ(dinosaurs[1], 7);
    ASSERT_EQ(dinosaurs[2], 6);
    ASSERT_EQ(dinosaurs[3], 2);
    ASSERT_EQ(dinosaurs[4], 3);
    ASSERT_EQ(dinosaurs[5], 4);
    ASSERT_EQ(dinosaurs[6], 5);
    ASSERT_EQ(dinosaurs[7], 0);
    ASSERT_EQ(dinosaurs[8], 1);

    dinosaurs.Clear();

    // Add many items
    for (int32 i = 0; i < 20000; i += 1)
      dinosaurs.Add(i);
    dinosaurs.Reverse(0, dinosaurs.Count);
  }

  TEST(ListTest, Find) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Oviraptor");
    dinosaurs.Add("Velociraptor");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Dilophosaurus");
    dinosaurs.Add("Gallimimus");
    dinosaurs.Add("Triceratops");

    ASSERT_EQ(dinosaurs.Find(&TestList::EndsWithSaurus), "Tyrannosaurus");
    ASSERT_EQ(dinosaurs.Find(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), "Tyrannosaurus");
    //ASSERT_EQ(*dinosaurs->Find(EndsWithValue), "Tyrannosaurus");
    ASSERT_EQ(dinosaurs.Find(&TestList::StartsWithCat), string::Empty);
    ASSERT_EQ(dinosaurs.Find(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), string::Empty);
  }

  TEST(ListTest, FindIndex) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Oviraptor");
    dinosaurs.Add("Velociraptor");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Dilophosaurus");
    dinosaurs.Add("Gallimimus");
    dinosaurs.Add("Triceratops");

    ASSERT_EQ(dinosaurs.FindIndex(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 0);
    ASSERT_EQ(dinosaurs.FindIndex(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), -1);
    ASSERT_EQ(dinosaurs.FindIndex(1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    ASSERT_EQ(dinosaurs.FindIndex(3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    ASSERT_EQ(dinosaurs.FindIndex(7, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    ASSERT_EQ(dinosaurs.FindIndex(3, 3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    ASSERT_EQ(dinosaurs.FindIndex(3, 4, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);

    ASSERT_THROW(dinosaurs.FindIndex(-1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.FindIndex(10, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.FindIndex(0, -1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);

    ASSERT_THROW(dinosaurs.FindIndex(10, 1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
    ASSERT_THROW(dinosaurs.FindIndex(0, 10, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
  }

  TEST(ListTest, FindLast) {
    refptr<string>::Empty();
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Oviraptor");
    dinosaurs.Add("Velociraptor");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Dilophosaurus");
    dinosaurs.Add("Gallimimus");
    dinosaurs.Add("Triceratops");

    ASSERT_EQ(dinosaurs.FindLast(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), "Dilophosaurus");
    ASSERT_EQ(dinosaurs.FindLast(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), string::Empty);
  }

  TEST(ListTest, FindLastIndex) {
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus"); // 0
    dinosaurs.Add("Compsognathus"); // 1
    dinosaurs.Add("Amargasaurus");  // 2
    dinosaurs.Add("Oviraptor");     // 3
    dinosaurs.Add("Velociraptor");  // 4
    dinosaurs.Add("Deinonychus");   // 5
    dinosaurs.Add("Dilophosaurus"); // 6
    dinosaurs.Add("Gallimimus");    // 7
    dinosaurs.Add("Triceratops");   // 8

    ASSERT_EQ(dinosaurs.FindLastIndex(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    ASSERT_EQ(dinosaurs.FindLastIndex(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), -1);

    ASSERT_EQ(dinosaurs.FindLastIndex(0, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 0);
    ASSERT_EQ(dinosaurs.FindLastIndex(2, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    ASSERT_EQ(dinosaurs.FindLastIndex(3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    ASSERT_EQ(dinosaurs.FindLastIndex(7, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    ASSERT_THROW(dinosaurs.FindLastIndex(9, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);

    ASSERT_EQ(dinosaurs.FindLastIndex(5, 3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    ASSERT_EQ(dinosaurs.FindLastIndex(8, 6, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    ASSERT_EQ(dinosaurs.FindLastIndex(2, 3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    ASSERT_EQ(dinosaurs.FindLastIndex(2, 0, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    ASSERT_EQ(dinosaurs.FindLastIndex(2, 1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    ASSERT_THROW(dinosaurs.FindLastIndex(2, 4, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
    ASSERT_THROW(dinosaurs.FindLastIndex(9, 2, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.FindLastIndex(0, -1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);

    ASSERT_THROW(dinosaurs.FindLastIndex(10, 1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.FindLastIndex(0, 10, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
  }

  TEST(ListTest, IndexOf) {
    List<string> dinosaurs;

    ASSERT_EQ(-1, dinosaurs.IndexOf("Siats meekerorum"));
    ASSERT_THROW(dinosaurs.IndexOf("Siats meekerorum", 0), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.IndexOf("Siats meekerorum", 0, 0), ArgumentOutOfRangeException);

    // Add 9 items
    dinosaurs.Add("Dilophosaurus"); // 0
    dinosaurs.Add("Compsognathus"); // 1
    dinosaurs.Add("Dilophosaurus");  // 2
    dinosaurs.Add("Oviraptor");     // 3
    dinosaurs.Add("Velociraptor");  // 4
    dinosaurs.Add("Deinonychus");   // 5
    dinosaurs.Add("Dilophosaurus"); // 6
    dinosaurs.Add("Gallimimus");    // 7
    dinosaurs.Add("Triceratops");   // 8

    ASSERT_EQ(0,  dinosaurs.IndexOf("Dilophosaurus"));
    ASSERT_EQ(-1, dinosaurs.IndexOf("Hello Kitty"));
    ASSERT_EQ(-1, dinosaurs.IndexOf("Hello Kitty", 0));
    ASSERT_EQ(-1, dinosaurs.IndexOf("Hello Kitty", 0, 0));
    ASSERT_EQ(-1, dinosaurs.IndexOf("Hello Kitty", 0, 1));

    ASSERT_EQ(0, dinosaurs.IndexOf("Dilophosaurus", 0));
    ASSERT_EQ(8, dinosaurs.IndexOf("Triceratops", 8));
    ASSERT_EQ(2, dinosaurs.IndexOf("Dilophosaurus", 2));
    ASSERT_EQ(6, dinosaurs.IndexOf("Dilophosaurus", 3));
    ASSERT_EQ(-1, dinosaurs.IndexOf("Dilophosaurus", 7));
    ASSERT_THROW(dinosaurs.IndexOf("Dilophosaurus", 9), ArgumentOutOfRangeException);

    ASSERT_EQ(dinosaurs.IndexOf("Dilophosaurus", 5, 3), 6);
    ASSERT_EQ(dinosaurs.IndexOf("Dilophosaurus", 8, 1), -1);
    ASSERT_EQ(dinosaurs.IndexOf("Dilophosaurus", 6, 3), 6);
    ASSERT_EQ(dinosaurs.IndexOf("Dilophosaurus", 5, 3), 6);
    ASSERT_EQ(dinosaurs.IndexOf("Dilophosaurus", 2, 5), 2);
    ASSERT_THROW(dinosaurs.IndexOf("Dilophosaurus", 7, 4), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.IndexOf("Dilophosaurus", 9, 2), ArgumentOutOfRangeException);

    ASSERT_THROW(dinosaurs.IndexOf("Dilophosaurus", 0, -1), ArgumentOutOfRangeException);

    ASSERT_THROW(dinosaurs.IndexOf("Dilophosaurus", 10, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.IndexOf("Dilophosaurus", 0, 10), ArgumentOutOfRangeException);
  }

  TEST(ListTest, LastIndexOf) {
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Dilophosaurus"); // 0
    dinosaurs.Add("Compsognathus"); // 1
    dinosaurs.Add("Dilophosaurus");  // 2
    dinosaurs.Add("Oviraptor");     // 3
    dinosaurs.Add("Velociraptor");  // 4
    dinosaurs.Add("Deinonychus");   // 5
    dinosaurs.Add("Dilophosaurus"); // 6
    dinosaurs.Add("Gallimimus");    // 7
    dinosaurs.Add("Triceratops");   // 8

    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus"), 6);
    ASSERT_EQ(dinosaurs.LastIndexOf("Hello Kitty"), -1);

    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 0), 0);
    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2), 2);
    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 3), 2);
    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 7), 6);
    ASSERT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 9), ArgumentOutOfRangeException);

    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 5, 3), -1);
    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 8, 6), 6);
    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2, 3), 2);
    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2, 0), -1);
    ASSERT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2, 1), 2);
    ASSERT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 2, 4), ArgumentException);
    ASSERT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 9, 2), ArgumentOutOfRangeException);

    ASSERT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 0, -1), ArgumentOutOfRangeException);

    ASSERT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 10, 1), ArgumentOutOfRangeException);
    ASSERT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 0, 10), ArgumentException);

    List<string> emptyList;
    ASSERT_EQ(-1, emptyList.LastIndexOf("Catch me if you can"));
  }

  static void CheckDinosaur(const string& dinosaur) {
    ASSERT_FALSE(string::IsNullOrEmpty(dinosaur));
  }

  TEST(ListTest, ForEach) {
    List<string> dinosaurs;

    // Test contains
    ASSERT_FALSE(dinosaurs.Contains("Deinonychus"));

    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Mamenchisaurus");

    dinosaurs.ForEach(&CheckDinosaur);
  }

  void RandAddAndRemove(List<Int32>& list, Int32 maxCapaicty) {
    System::Random rand;
    Int32 clipsAdded = 0;
    Int32 clipsRemoved = 0;
    int32 nbRepeat = rand.Next(1, 11);

    for (Int32 i = 0; i < nbRepeat; i++) {
      int32 addCount = rand.Next(list.Capacity - clipsAdded + clipsRemoved);
      clipsAdded += addCount;
      for (Int32 index = 0; index < addCount; index++)
        list.Add(Int32(rand.Next()));
      ASSERT_EQ(list.Count, clipsAdded - clipsRemoved);

      Int32 deleteCount = rand.Next(list.Count);
      clipsRemoved += deleteCount;
      for (Int32 index = 0; index < deleteCount; index++)
        list.RemoveAt(rand.Next(list.Count - 1));
      ASSERT_EQ(list.Count, clipsAdded - clipsRemoved);
    }
  }

  TEST(ListTest, GetCapacityAndGetCount) {
    // Create List<T> with default Capacity)
    List<Int32> listMaxCapacity;
    ASSERT_EQ(listMaxCapacity.Capacity, 0);
    listMaxCapacity.Clear();

    // Create List<T> with a Capacity equal to 5)
    List<Int32> listCapacity5(5);
    ASSERT_EQ(listCapacity5.Capacity, 5);
    RandAddAndRemove(listCapacity5, 5);
    listCapacity5.Clear();

    // Create List<T> with a Capacity equal to 256)
    List<Int32> listCapacity256(256);
    ASSERT_EQ(listCapacity256.Capacity, 256);
    RandAddAndRemove(listCapacity256, 256);
    listCapacity256.Clear();
  }

  TEST(ListTest, GetEnumerator) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Oviraptor");
    dinosaurs.Add("Velociraptor");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Dilophosaurus");
    dinosaurs.Add("Gallimimus");
    dinosaurs.Add("Triceratops");

    refptr<IEnumerator<string>> enumerators[50];

    for (Int32 index = 0; index < 50; index++) {
      enumerators[index] = ref_new<Enumerator<string>>(dinosaurs.GetEnumerator());
      enumerators[index]->MoveNext();
      ASSERT_EQ("Tyrannosaurus", enumerators[index]->Current());
    }

    enumerators[0] = new Enumerator<string>(dinosaurs.GetEnumerator());
    enumerators[0]->MoveNext();
    ASSERT_EQ("Tyrannosaurus", enumerators[0]->Current());
  }

  static void MyThread(const Object& param) {
    List<string>* dinosaurs = &((List<string>&) param);

    _lock(dinosaurs->SyncRoot) {
      // Add 9 items
      for (Int32 index = 1; index < 10; index++) {
        dinosaurs->Add("Line " + index);
        Thread::Sleep(0);
      }
    }
  }

  TEST(ListTest, GetSyncRoot) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    Thread myThread((ParameterizedThreadStart)MyThread);
    myThread.Start(dinosaurs);

    _lock(dinosaurs.SyncRoot) {
      // Add 9 items
      dinosaurs.Add("Tyrannosaurus");
      Thread::Sleep(0);
      dinosaurs.Add("Compsognathus");
      Thread::Sleep(0);
      dinosaurs.Add("Amargasaurus");
      Thread::Sleep(0);
      dinosaurs.Add("Oviraptor");
      Thread::Sleep(0);
      dinosaurs.Add("Velociraptor");
      Thread::Sleep(0);
      dinosaurs.Add("Deinonychus");
      Thread::Sleep(0);
      dinosaurs.Add("Dilophosaurus");
      Thread::Sleep(0);
      dinosaurs.Add("Gallimimus");
      Thread::Sleep(0);
      dinosaurs.Add("Triceratops");
      Thread::Sleep(0);
    }

    myThread.Join();

    if (dinosaurs[0] == "Line 1") {
      ASSERT_EQ("Line 1", dinosaurs[0]);
      ASSERT_EQ("Line 2", dinosaurs[1]);
      ASSERT_EQ("Line 3", dinosaurs[2]);
      ASSERT_EQ("Line 4", dinosaurs[3]);
      ASSERT_EQ("Line 5", dinosaurs[4]);
      ASSERT_EQ("Line 6", dinosaurs[5]);
      ASSERT_EQ("Line 7", dinosaurs[6]);
      ASSERT_EQ("Line 8", dinosaurs[7]);
      ASSERT_EQ("Line 9", dinosaurs[8]);
      ASSERT_EQ("Tyrannosaurus", dinosaurs[9]);
      ASSERT_EQ("Compsognathus", dinosaurs[10]);
      ASSERT_EQ("Amargasaurus", dinosaurs[11]);
      ASSERT_EQ("Oviraptor", dinosaurs[12]);
      ASSERT_EQ("Velociraptor", dinosaurs[13]);
      ASSERT_EQ("Deinonychus", dinosaurs[14]);
      ASSERT_EQ("Dilophosaurus", dinosaurs[15]);
      ASSERT_EQ("Gallimimus", dinosaurs[16]);
      ASSERT_EQ("Triceratops", dinosaurs[17]);
    } else {
      ASSERT_EQ(dinosaurs[0], "Tyrannosaurus");
      ASSERT_EQ(dinosaurs[1], "Compsognathus");
      ASSERT_EQ(dinosaurs[2], "Amargasaurus");
      ASSERT_EQ(dinosaurs[3], "Oviraptor");
      ASSERT_EQ(dinosaurs[4], "Velociraptor");
      ASSERT_EQ(dinosaurs[5], "Deinonychus");
      ASSERT_EQ(dinosaurs[6], "Dilophosaurus");
      ASSERT_EQ(dinosaurs[7], "Gallimimus");
      ASSERT_EQ(dinosaurs[8], "Triceratops");
      ASSERT_EQ(dinosaurs[9], "Line 1");
      ASSERT_EQ(dinosaurs[10], "Line 2");
      ASSERT_EQ(dinosaurs[11], "Line 3");
      ASSERT_EQ(dinosaurs[12], "Line 4");
      ASSERT_EQ(dinosaurs[13], "Line 5");
      ASSERT_EQ(dinosaurs[14], "Line 6");
      ASSERT_EQ(dinosaurs[15], "Line 7");
      ASSERT_EQ(dinosaurs[16], "Line 8");
      ASSERT_EQ(dinosaurs[17], "Line 9");
    }
  }

  TEST(ListTest, ListOperatorEqual) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;

    // Add 9 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Oviraptor");
    dinosaurs.Add("Velociraptor");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Dilophosaurus");
    dinosaurs.Add("Gallimimus");
    dinosaurs.Add("Triceratops");

    List<string> dinosaursBis;
    dinosaursBis = dinosaurs;
    ASSERT_EQ(dinosaurs.Count, dinosaursBis.Count);
  }

  TEST(ListTest, Sort) {
    int k;
    string names[9] = {"Tyrannosaurus", "Compsognathus", "Amargasaurus", "Oviraptor", "Velociraptor", "Deinonychus", "Dilophosaurus", "Gallimimus", "Triceratops"};
    string sortedNames[9] = {"Amargasaurus", "Compsognathus", "Deinonychus", "Dilophosaurus", "Gallimimus", "Oviraptor", "Triceratops", "Tyrannosaurus", "Velociraptor"};

    // First we test a sort function on IComparable objects (string in this case)

    List<string> dinosaurNames;
    for (int i = 0; i < 9; i++)
      dinosaurNames.Add(names[i]);

    ASSERT_EQ(9, dinosaurNames.Count);

    k = 0;
    for (string s : dinosaurNames)
      ASSERT_TRUE(s.Equals(names[k++]));

    dinosaurNames.Sort();

    k = 0;
    for (string s : dinosaurNames)
      ASSERT_TRUE(s.Equals(sortedNames[k++]));

    // Second we test a sort function on objects not implementing IComparable (Dinosaur in this case)
    // Thus we provide an IComparer (DinosaurComparer)
    // Create List<T> to used with Contains function
    List<Dinosaur> dinosaurs;

    // Add 6 items
    dinosaurs.Add(Dinosaur("Tyrannosaurus", 2));
    dinosaurs.Add(Dinosaur("Compsognathus", 2));
    dinosaurs.Add(Dinosaur("Amargasaurus", 4));
    dinosaurs.Add(Dinosaur("Oviraptor", 2));
    dinosaurs.Add(Dinosaur("Velociraptor", 2));
    dinosaurs.Add(Dinosaur("Deinonychus", 2));
    dinosaurs.Add(Dinosaur("Dilophosaurus", 2));
    dinosaurs.Add(Dinosaur("Gallimimus", 2));
    dinosaurs.Add(Dinosaur("Triceratops", 4));

    k = 0;
    for (Dinosaur d : dinosaurs)
      ASSERT_TRUE(d.GetName().Equals(names[k++]));

    dinosaurs.Sort(DinosaurComparer());

    k = 0;
    for (Dinosaur d : dinosaurs)
      ASSERT_TRUE(d.GetName().Equals(sortedNames[k++]));
  }

  TEST(ListTest, polymorphicList) {
    List<refptr<ValueType>> polymorphicList;
    polymorphicList.Add(new Int32(1024));
    polymorphicList.Add(new string("Polymorphic"));
    polymorphicList.Add(new Boolean(true));
    polymorphicList.Add(new Char('P'));

    ASSERT_TRUE(is< Int32 >(*polymorphicList[0]));
    ASSERT_TRUE(is< String >(*polymorphicList[1]));
    ASSERT_TRUE(is< Boolean >(*polymorphicList[2]));
    ASSERT_TRUE(is< Char >(*polymorphicList[3]));

    ASSERT_EQ(string("1024"), polymorphicList[0]->ToString());
    ASSERT_EQ(string("Polymorphic"), polymorphicList[1]->ToString());
    ASSERT_EQ(string("True"), polymorphicList[2]->ToString());
    ASSERT_EQ(string("P"), polymorphicList[3]->ToString());
  }

  TEST(ListTest, Remove) {
    List<int32> list;

    ASSERT_FALSE(list.Remove(5));
    ASSERT_THROW(list.RemoveAt(0), ArgumentOutOfRangeException);
    ASSERT_THROW(list.RemoveAt(-1), ArgumentOutOfRangeException);
    ASSERT_THROW(list.RemoveAt(1), ArgumentOutOfRangeException);

    list.Add(1);
    list.Add(22);
    list.Add(333);
    list.Add(4444);
    list.Add(55555);

    ASSERT_FALSE(list.Remove(5));
    ASSERT_THROW(list.RemoveAt(-1), ArgumentOutOfRangeException);
    ASSERT_THROW(list.RemoveAt(5), ArgumentOutOfRangeException);

    ASSERT_TRUE(list.Remove(22));
    list.RemoveAt(1);

    ASSERT_EQ(3, list.Count);
    ASSERT_EQ(1,     list[0]);
    ASSERT_EQ(4444,  list[1]);
    ASSERT_EQ(55555, list[2]);
  }

  TEST(ListTest, RemoveAfterIteration) {
    List<Int32> testList;
    List<Int32> toRemove;

    testList.Add(172);
    testList.Add(573);
    testList.Add(14);
    testList.Add(16251);
    testList.Add(8);
    ASSERT_EQ(5, testList.Count);

    for (Int32 value : testList) {
      if (value % 2 == 0)
        toRemove.Add(value);
    }

    ASSERT_EQ(5, testList.Count);
    ASSERT_EQ(3, toRemove.Count);

    for (Int32 value : toRemove)
      testList.Remove(value);

    ASSERT_EQ(2, testList.Count);
  }

  TEST(ListTest, Equals) {
    List<Dinosaur> dinosaurs;
    dinosaurs.Add(Dinosaur("Tyrannosaurus", 2));
    dinosaurs.Add(Dinosaur("Compsognathus", 2));
    dinosaurs.Add(Dinosaur("Amargasaurus", 4));
    dinosaurs.Add(Dinosaur("Oviraptor", 2));
    dinosaurs.Add(Dinosaur("Velociraptor", 2));
    dinosaurs.Add(Dinosaur("Deinonychus", 2));
    dinosaurs.Add(Dinosaur("Dilophosaurus", 2));
    dinosaurs.Add(Dinosaur("Gallimimus", 2));
    dinosaurs.Add(Dinosaur("Triceratops", 4));

    List<Dinosaur> dinosaurs2; // same
    dinosaurs2.Add(Dinosaur("Tyrannosaurus", 2));
    dinosaurs2.Add(Dinosaur("Compsognathus", 2));
    dinosaurs2.Add(Dinosaur("Amargasaurus", 4));
    dinosaurs2.Add(Dinosaur("Oviraptor", 2));
    dinosaurs2.Add(Dinosaur("Velociraptor", 2));
    dinosaurs2.Add(Dinosaur("Deinonychus", 2));
    dinosaurs2.Add(Dinosaur("Dilophosaurus", 2));
    dinosaurs2.Add(Dinosaur("Gallimimus", 2));
    dinosaurs2.Add(Dinosaur("Triceratops", 4));

    List<Dinosaur> dinosaurs3; // Deinnonychus has zero legs
    dinosaurs3.Add(Dinosaur("Tyrannosaurus", 2));
    dinosaurs3.Add(Dinosaur("Compsognathus", 2));
    dinosaurs3.Add(Dinosaur("Amargasaurus", 4));
    dinosaurs3.Add(Dinosaur("Oviraptor", 2));
    dinosaurs3.Add(Dinosaur("Velociraptor", 2));
    dinosaurs3.Add(Dinosaur("Deinonychus", 0));
    dinosaurs3.Add(Dinosaur("Dilophosaurus", 2));
    dinosaurs3.Add(Dinosaur("Gallimimus", 2));
    dinosaurs3.Add(Dinosaur("Triceratops", 4));

    List<Dinosaur> dinosaurs4; // two triceratops
    dinosaurs4.Add(Dinosaur("Tyrannosaurus", 2));
    dinosaurs4.Add(Dinosaur("Compsognathus", 2));
    dinosaurs4.Add(Dinosaur("Amargasaurus", 4));
    dinosaurs4.Add(Dinosaur("Oviraptor", 2));
    dinosaurs4.Add(Dinosaur("Velociraptor", 2));
    dinosaurs4.Add(Dinosaur("Deinonychus", 0));
    dinosaurs4.Add(Dinosaur("Dilophosaurus", 2));
    dinosaurs4.Add(Dinosaur("Gallimimus", 2));
    dinosaurs4.Add(Dinosaur("Triceratops", 4));
    dinosaurs4.Add(Dinosaur("Triceratops", 18));

    List<Dinosaur> dinosaurs5; // one element
    dinosaurs5.Add(Dinosaur("Tyrannosaurus", 2));

    List<Dinosaur> dinosaurs6; //empty

    ASSERT_EQ(dinosaurs, dinosaurs2);
    EXPECT_NE(dinosaurs, dinosaurs3);
    EXPECT_NE(dinosaurs, dinosaurs4);
    EXPECT_NE(dinosaurs, dinosaurs5);
    EXPECT_NE(dinosaurs, dinosaurs6);
    EXPECT_NE(dinosaurs3, dinosaurs);
    EXPECT_NE(dinosaurs4, dinosaurs);
    EXPECT_NE(dinosaurs5, dinosaurs);
    EXPECT_NE(dinosaurs6, dinosaurs);
  }
}
