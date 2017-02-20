#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/System/Threading/Thread.h>
#include <Pcf/System/Random.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace TUnit;

namespace {
  class AbstractListHelper : public object {
    
  protected:
    AbstractListHelper() {}
    AbstractListHelper(int32 value, const string& name) : value(value), name(name) {}
    
  public:
    virtual string ToString() const {return string::Format("{0} {1}", this->value, this->name);}
    
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
    
    Dinosaur& operator =(const Dinosaur& dinasaure) {
      name = dinasaure.name;
      numberOfLegsUsedToWalk = dinasaure.numberOfLegsUsedToWalk;
      return *this;
    }
    
    string ToString() const override { return this->name; }
    const string& GetName() const { return this->name; }
    
    bool Equals(const object& obj) const noexcept override {
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
  
  TEST(List, DefaultConstructor) {
    // Create List<T> with default Capacity (IDataList<T>::MaxCapacity)
    List<string> strings;
    EXPECT_LE(0, strings.Capacity);
    EXPECT_EQ(0, strings.Count);
    EXPECT_FALSE(strings.IsFixedSize);
    EXPECT_FALSE(strings.IsReadOnly);
  }
  
  TEST(List, ConstructorWithCapacityEqualTo25) {
    List<Boolean> booleans(25);
    EXPECT_LE(25, booleans.Capacity);
    EXPECT_EQ( 0, booleans.Count);
    EXPECT_FALSE(booleans.IsFixedSize);
    EXPECT_FALSE(booleans.IsReadOnly);
  }

  TEST(List, ConstructorWithCapacityEqualTo0) {
    List<Int32> int32s(0);
    EXPECT_LE(0, int32s.Capacity);
    EXPECT_EQ(0, int32s.Count);
    EXPECT_FALSE(int32s.IsFixedSize);
    EXPECT_FALSE(int32s.IsReadOnly);
  }
  
  TEST(List, ConstructorWithArray) {
    Array<Int64> int64Items = {1, 2, 3, 4,5 , 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    List<Int64> int64s(int64Items);
    EXPECT_LE(19, int64s.Capacity);
    EXPECT_EQ(19, int64s.Count);
    EXPECT_FALSE(int64s.IsFixedSize);
    EXPECT_FALSE(int64s.IsReadOnly);
    
    List< SharedPointer<ListHelper>> myList;
    myList.Add(new ListHelper(1, "YFI"));
    myList.Add(new ListHelper(2, "VLE"));
    
    EXPECT_EQ(string("1 YFI"), myList[0]->ToString());
    EXPECT_EQ(string("2 VLE"), myList[1]->ToString());
    
    // Create List<T> with a Capacity less than 0
    EXPECT_THROW(List<Int16>(-1), ArgumentException);
  }
  
  TEST(List, NoDynamicAllocation) {
    Array<string> stringItems = {"Tyrannosaurus", "Amargasaurus", "Mamenchisaurus", "Deinonychus", "Compsognathus"};
    // Create List<T> with a Capacity equal to 5)
    List<string> dinosaurs(stringItems);
    
    EXPECT_LE(5, dinosaurs.Capacity);
    EXPECT_EQ(5, dinosaurs.Count);
    
    dinosaurs.Add("null");
    EXPECT_LE(6, dinosaurs.Capacity);
    EXPECT_EQ(6, dinosaurs.Count);
    
    // Add a 6th item
    dinosaurs.Add("Mamenchisaurus");
    EXPECT_LE(7, dinosaurs.Capacity);
    EXPECT_EQ(7, dinosaurs.Count);
  }
  
  TEST(List, Add) {
    // Create List<T> with a Capacity equal to 5)
    List<string> dinosaurs(5);
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    EXPECT_LE(5, dinosaurs.Capacity);
    EXPECT_EQ(5, dinosaurs.Count);
    
    dinosaurs.Add("null");
    EXPECT_LE(6, dinosaurs.Capacity);
    EXPECT_EQ(6, dinosaurs.Count);
    
    // Add a 6th item
    dinosaurs.Add("Mamenchisaurus");
    EXPECT_LE(7, dinosaurs.Capacity);
    EXPECT_EQ(7, dinosaurs.Count);
    
    // Delete all items
    dinosaurs.Clear();
  }
  
  TEST(List, AddRange) {
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
    EXPECT_EQ(5, dinosaursCopy.Count);
    
    dinosaursCopy.Clear();
    
    // Create List<T> with a Capacity equal to 4)
    List<string> dinosaursCopy2(4);
    
    // AddRange 5 items in List of 4 items
    dinosaursCopy2.AddRange(dinosaurs);
    EXPECT_LE(5, dinosaursCopy2.Capacity);
    EXPECT_EQ(5, dinosaursCopy2.Count);
    
    // AddRange null items
    // List<string> *listNull = null;
    // EXPECT_THROW(dinosaursCopy2->AddRange(*listNull), ArgumentNullException);
    EXPECT_LE(5, dinosaursCopy2.Capacity);
    EXPECT_EQ(5, dinosaursCopy2.Count);
  }
  
  TEST(List, RemoveRange) {
    // Create List<T> to used in addRange function
    List<string> dinosaurs;
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    EXPECT_TRUE(dinosaurs[2].Equals(string("Mamenchisaurus")));
    dinosaurs.RemoveRange(2,2);
    EXPECT_EQ(3, dinosaurs.Count);
    EXPECT_TRUE(dinosaurs[2].Equals(string("Compsognathus")));
  }
  
  TEST(List, InsertAt) {
    // Create List<T> to used in addRange function
    List<string> dinosaurs;
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    
    EXPECT_EQ(3, dinosaurs.Count);
    EXPECT_TRUE(dinosaurs[0].Equals(string("Tyrannosaurus")));
    EXPECT_TRUE(dinosaurs[1].Equals(string("Amargasaurus")));
    EXPECT_TRUE(dinosaurs[2].Equals(string("Mamenchisaurus")));
    
    dinosaurs.Insert(2,string("Deinonychus"));
    
    EXPECT_EQ(4, dinosaurs.Count);
    EXPECT_TRUE(dinosaurs[0].Equals(string("Tyrannosaurus")));
    EXPECT_TRUE(dinosaurs[1].Equals(string("Amargasaurus")));
    EXPECT_TRUE(dinosaurs[2].Equals(string("Deinonychus")));
    EXPECT_TRUE(dinosaurs[3].Equals(string("Mamenchisaurus")));
    
    dinosaurs.Insert(2,"Compsognathus");
    
    EXPECT_EQ(5, dinosaurs.Count);
    EXPECT_TRUE(dinosaurs[0].Equals(string("Tyrannosaurus")));
    EXPECT_TRUE(dinosaurs[1].Equals(string("Amargasaurus")));
    EXPECT_TRUE(dinosaurs[2].Equals(string("Compsognathus")));
    EXPECT_TRUE(dinosaurs[3].Equals(string("Deinonychus")));
    EXPECT_TRUE(dinosaurs[4].Equals(string("Mamenchisaurus")));
  }
  
  
  TEST(List, Clear) {
    // Create List<T> to used with Clear function
    List<string> dinosaurs;
    EXPECT_LE(0, dinosaurs.Capacity);
    EXPECT_EQ(0, dinosaurs.Count);
    
    // Clear an empty List
    dinosaurs.Clear();
    EXPECT_LE(0, dinosaurs.Capacity);
    EXPECT_EQ(0, dinosaurs.Count);
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    EXPECT_LE(5, dinosaurs.Capacity);
    EXPECT_EQ(5, dinosaurs.Count);
    
    // Clear items in List
    dinosaurs.Clear();
    EXPECT_LE(0, dinosaurs.Capacity);
    EXPECT_EQ(0, dinosaurs.Count);
    
    // Create List<T> to used with Clear function
    List<string> dinosaurs2 (5);
    EXPECT_LE(5, dinosaurs2.Capacity);
    EXPECT_EQ(0, dinosaurs2.Count);
    
    // Clear an empty List
    dinosaurs2.Clear();
    EXPECT_LE(5, dinosaurs2.Capacity);
    EXPECT_EQ(0, dinosaurs2.Count);
    
    // Add 5 items
    dinosaurs2.Add("Tyrannosaurus");
    dinosaurs2.Add("Amargasaurus");
    dinosaurs2.Add("Mamenchisaurus");
    dinosaurs2.Add("Deinonychus");
    dinosaurs2.Add("Compsognathus");
    
    EXPECT_LE(5, dinosaurs2.Capacity);
    EXPECT_EQ(5, dinosaurs2.Count);
    
    // Clear items in List
    dinosaurs2.Clear();
    EXPECT_LE(5, dinosaurs2.Capacity);
    EXPECT_EQ(0, dinosaurs2.Count);
  }
  
  TEST(List, Contains) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    
    // Test contains
    EXPECT_FALSE(dinosaurs.Contains("Deinonychus"));
    
    // Add 6 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    dinosaurs.Add("Mamenchisaurus");
    
    // Test contains
    EXPECT_TRUE(dinosaurs.Contains("Mamenchisaurus"));
    EXPECT_FALSE(dinosaurs.Contains("Snowcat"));
  }
  
  TEST(List, CopyTo) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    Array<string> array(20);
    
    // Test contains
    EXPECT_FALSE(dinosaurs.Contains("Deinonychus"));
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    // Test CopyTo
    dinosaurs.CopyTo(array);
    EXPECT_EQ(array[0], "Tyrannosaurus");
    EXPECT_EQ(array[1], "Amargasaurus");
    EXPECT_EQ(array[2], "Mamenchisaurus");
    EXPECT_EQ(array[3], "Deinonychus");
    EXPECT_EQ(array[4], "Compsognathus");
    
    dinosaurs.CopyTo(array, 6);
    EXPECT_EQ(array[0], "Tyrannosaurus");
    EXPECT_EQ(array[1], "Amargasaurus");
    EXPECT_EQ(array[2], "Mamenchisaurus");
    EXPECT_EQ(array[3], "Deinonychus");
    EXPECT_EQ(array[4], "Compsognathus");
    EXPECT_EQ(array[5], "");
    EXPECT_EQ(array[6], "Tyrannosaurus");
    EXPECT_EQ(array[7], "Amargasaurus");
    EXPECT_EQ(array[8], "Mamenchisaurus");
    EXPECT_EQ(array[9], "Deinonychus");
    EXPECT_EQ(array[10], "Compsognathus");
    
    dinosaurs.CopyTo(2, array, 12, 3);
    EXPECT_EQ(array[0], "Tyrannosaurus");
    EXPECT_EQ(array[1], "Amargasaurus");
    EXPECT_EQ(array[2], "Mamenchisaurus");
    EXPECT_EQ(array[3], "Deinonychus");
    EXPECT_EQ(array[4], "Compsognathus");
    EXPECT_EQ(array[5], "");
    EXPECT_EQ(array[6], "Tyrannosaurus");
    EXPECT_EQ(array[7], "Amargasaurus");
    EXPECT_EQ(array[8], "Mamenchisaurus");
    EXPECT_EQ(array[9], "Deinonychus");
    EXPECT_EQ(array[10], "Compsognathus");
    EXPECT_EQ(array[11], "");
    EXPECT_EQ(array[12], "Mamenchisaurus");
    EXPECT_EQ(array[13], "Deinonychus");
    EXPECT_EQ(array[14], "Compsognathus");
    EXPECT_EQ(array[15], "");
  }
  
  TEST(List, CopyTo2) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    Array<string> array(20);
    
    // Test contains
    EXPECT_FALSE(dinosaurs.Contains("Deinonychus"));
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    EXPECT_THROW(dinosaurs.CopyTo(array, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.CopyTo(-1, array,  0, 5), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.CopyTo(0, array,  0, -1), ArgumentOutOfRangeException);
  }
  
  TEST(List, CopyTo3) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    Array<string> array(20);
    
    // Test contains
    EXPECT_FALSE(dinosaurs.Contains("Deinonychus"));
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    EXPECT_THROW(dinosaurs.CopyTo(array,  20), ArgumentException);
    EXPECT_THROW(dinosaurs.CopyTo(0, array,  0, 6), ArgumentException);
    EXPECT_THROW(dinosaurs.CopyTo(1, array,  0, 5), ArgumentException);
  }
  
  TEST(List, CopyTo4) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    
    // Test contains
    EXPECT_FALSE(dinosaurs.Contains("Deinonychus"));
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    Array<string> array(3);
    EXPECT_THROW(dinosaurs.CopyTo(array), ArgumentException);
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
  
  TEST(List, Exists) {
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
    
    EXPECT_TRUE(dinosaurs.Exists(&TestList::EndsWithSaurus));
    EXPECT_TRUE(dinosaurs.Exists(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)));
    EXPECT_FALSE(dinosaurs.Exists(&TestList::StartsWithCat));
    EXPECT_FALSE(dinosaurs.Exists(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)));
  }
  
  TEST(List, RemoveAll) {
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
    
    EXPECT_EQ(dinosaurs.RemoveAll(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)),3);
    EXPECT_EQ(dinosaurs.Count, 6);
    EXPECT_EQ(dinosaurs[0], "Compsognathus");
    EXPECT_EQ(dinosaurs[1], "Oviraptor");
    EXPECT_EQ(dinosaurs[2], "Velociraptor");
    EXPECT_EQ(dinosaurs[3], "Deinonychus");
    EXPECT_EQ(dinosaurs[4], "Gallimimus");
    EXPECT_EQ(dinosaurs[5], "Triceratops");
  }
  
  TEST(List, Reverse) {
    // Create List<T> to used with Contains function
    List<int32> dinosaurs;
    
    // Add 9 items
    for (int32 i = 0; i < 9; i += 1)
      dinosaurs.Add(i);
    dinosaurs.Reverse();
    
    for (int32 i = 0; i < 9; i += 1)
      EXPECT_EQ(dinosaurs[i], 8-i);
    
    dinosaurs.Reverse(3, 4);
    EXPECT_EQ(dinosaurs[0], 8);
    EXPECT_EQ(dinosaurs[1], 7);
    EXPECT_EQ(dinosaurs[2], 6);
    EXPECT_EQ(dinosaurs[3], 2);
    EXPECT_EQ(dinosaurs[4], 3);
    EXPECT_EQ(dinosaurs[5], 4);
    EXPECT_EQ(dinosaurs[6], 5);
    EXPECT_EQ(dinosaurs[7], 1);
    EXPECT_EQ(dinosaurs[8], 0);
    
    EXPECT_THROW(dinosaurs.Reverse(-1, 1), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.Reverse(0, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.Reverse(7, 3), ArgumentException);
    
    dinosaurs.Reverse(7, 2);
    EXPECT_EQ(dinosaurs[0], 8);
    EXPECT_EQ(dinosaurs[1], 7);
    EXPECT_EQ(dinosaurs[2], 6);
    EXPECT_EQ(dinosaurs[3], 2);
    EXPECT_EQ(dinosaurs[4], 3);
    EXPECT_EQ(dinosaurs[5], 4);
    EXPECT_EQ(dinosaurs[6], 5);
    EXPECT_EQ(dinosaurs[7], 0);
    EXPECT_EQ(dinosaurs[8], 1);
    
    dinosaurs.Reverse(4, 1);
    EXPECT_EQ(dinosaurs[0], 8);
    EXPECT_EQ(dinosaurs[1], 7);
    EXPECT_EQ(dinosaurs[2], 6);
    EXPECT_EQ(dinosaurs[3], 2);
    EXPECT_EQ(dinosaurs[4], 3);
    EXPECT_EQ(dinosaurs[5], 4);
    EXPECT_EQ(dinosaurs[6], 5);
    EXPECT_EQ(dinosaurs[7], 0);
    EXPECT_EQ(dinosaurs[8], 1);
    
    dinosaurs.Clear();

    // Add many items
    for (int32 i = 0; i < 20000; i += 1)
      dinosaurs.Add(i);
    dinosaurs.Reverse(0, dinosaurs.Count);
  }
  
  TEST(List, Find) {
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
    
    EXPECT_EQ(dinosaurs.Find(&TestList::EndsWithSaurus), "Tyrannosaurus");
    EXPECT_EQ(dinosaurs.Find(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), "Tyrannosaurus");
    //EXPECT_EQ(*dinosaurs->Find(EndsWithValue), "Tyrannosaurus");
    EXPECT_EQ(dinosaurs.Find(&TestList::StartsWithCat), string::Empty);
    EXPECT_EQ(dinosaurs.Find(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), string::Empty);
  }
  
  TEST(List, FindIndex) {
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
    
    EXPECT_EQ(dinosaurs.FindIndex(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 0);
    EXPECT_EQ(dinosaurs.FindIndex(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), -1);
    EXPECT_EQ(dinosaurs.FindIndex(1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    EXPECT_EQ(dinosaurs.FindIndex(3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    EXPECT_EQ(dinosaurs.FindIndex(7, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    EXPECT_EQ(dinosaurs.FindIndex(3, 3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    EXPECT_EQ(dinosaurs.FindIndex(3, 4, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    
    EXPECT_THROW(dinosaurs.FindIndex(-1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.FindIndex(10, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.FindIndex(0, -1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    
    EXPECT_THROW(dinosaurs.FindIndex(10, 1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
    EXPECT_THROW(dinosaurs.FindIndex(0, 10, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
  }
  
  TEST(List, FindLast) {
    SharedPointer<string>::Empty();
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
    
    EXPECT_EQ(dinosaurs.FindLast(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), "Dilophosaurus");
    EXPECT_EQ(dinosaurs.FindLast(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), string::Empty);
  }
  
  TEST(List, FindLastIndex) {
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
    
    EXPECT_EQ(dinosaurs.FindLastIndex(Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    EXPECT_EQ(dinosaurs.FindLastIndex(Predicate<const string&>(TestList("Cat"), &TestList::StartsWithValue)), -1);
    
    EXPECT_EQ(dinosaurs.FindLastIndex(0,Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 0);
    EXPECT_EQ(dinosaurs.FindLastIndex(2,Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    EXPECT_EQ(dinosaurs.FindLastIndex(3,Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    EXPECT_EQ(dinosaurs.FindLastIndex(7,Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    EXPECT_THROW(dinosaurs.FindLastIndex(9,Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    
    EXPECT_EQ(dinosaurs.FindLastIndex(5, 3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    EXPECT_EQ(dinosaurs.FindLastIndex(8, 6, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 6);
    EXPECT_EQ(dinosaurs.FindLastIndex(2, 3, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    EXPECT_EQ(dinosaurs.FindLastIndex(2, 0, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), -1);
    EXPECT_EQ(dinosaurs.FindLastIndex(2, 1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), 2);
    EXPECT_THROW(dinosaurs.FindLastIndex(2,4,Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
    EXPECT_THROW(dinosaurs.FindLastIndex(9,2,Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.FindLastIndex(0, -1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    
    EXPECT_THROW(dinosaurs.FindLastIndex(10, 1, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.FindLastIndex(0, 10, Predicate<const string&>(TestList("saurus"), &TestList::EndsWithValue)), ArgumentException);
  }
  
  TEST(List, IndexOf) {
    List<string> dinosaurs;
    
    EXPECT_EQ(-1, dinosaurs.IndexOf("Siats meekerorum"));
    EXPECT_THROW(dinosaurs.IndexOf("Siats meekerorum", 0), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.IndexOf("Siats meekerorum", 0,0), ArgumentOutOfRangeException);
    
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
    
    EXPECT_EQ(0,  dinosaurs.IndexOf("Dilophosaurus"));
    EXPECT_EQ(-1, dinosaurs.IndexOf("Hello Kitty"));
    EXPECT_EQ(-1, dinosaurs.IndexOf("Hello Kitty",0));
    EXPECT_EQ(-1, dinosaurs.IndexOf("Hello Kitty",0,0));
    EXPECT_EQ(-1, dinosaurs.IndexOf("Hello Kitty",0,1));
    
    EXPECT_EQ(0, dinosaurs.IndexOf("Dilophosaurus", 0));
    EXPECT_EQ(8, dinosaurs.IndexOf("Triceratops"  , 8));
    EXPECT_EQ(2, dinosaurs.IndexOf("Dilophosaurus", 2));
    EXPECT_EQ(6, dinosaurs.IndexOf("Dilophosaurus", 3));
    EXPECT_EQ(-1,dinosaurs.IndexOf("Dilophosaurus", 7));
    EXPECT_THROW(dinosaurs.IndexOf("Dilophosaurus", 9), ArgumentOutOfRangeException);
    
    EXPECT_EQ(dinosaurs.IndexOf("Dilophosaurus", 5, 3), 6);
    EXPECT_EQ(dinosaurs.IndexOf("Dilophosaurus", 8, 1), -1);
    EXPECT_EQ(dinosaurs.IndexOf("Dilophosaurus", 6, 3), 6);
    EXPECT_EQ(dinosaurs.IndexOf("Dilophosaurus", 5, 3), 6);
    EXPECT_EQ(dinosaurs.IndexOf("Dilophosaurus", 2, 5), 2);
    EXPECT_THROW(dinosaurs.IndexOf("Dilophosaurus", 7,4), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.IndexOf("Dilophosaurus", 9,2), ArgumentOutOfRangeException);
    
    EXPECT_THROW(dinosaurs.IndexOf("Dilophosaurus", 0, -1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(dinosaurs.IndexOf("Dilophosaurus", 10, 1), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.IndexOf("Dilophosaurus", 0, 10), ArgumentOutOfRangeException);
  }
  
  TEST(List, LastIndexOf) {
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
    
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus"), 6);
    EXPECT_EQ(dinosaurs.LastIndexOf("Hello Kitty"), -1);
    
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 0), 0);
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2), 2);
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 3), 2);
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 7), 6);
    EXPECT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 9), ArgumentOutOfRangeException);
    
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 5, 3), -1);
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 8, 6), 6);
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2, 3), 2);
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2, 0), -1);
    EXPECT_EQ(dinosaurs.LastIndexOf("Dilophosaurus", 2, 1), 2);
    EXPECT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 2,4), ArgumentException);
    EXPECT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 9,2), ArgumentOutOfRangeException);
    
    EXPECT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 0, -1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 10, 1), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.LastIndexOf("Dilophosaurus", 0, 10), ArgumentException);
    
    List<string> emptyList;
    EXPECT_EQ(-1,emptyList.LastIndexOf("Catch me if you can"));
  }
  
  static void CheckDinosaur(const string& dinosaur) {
    EXPECT_FALSE(string::IsNullOrEmpty(dinosaur));
  }
  
  TEST(List, ForEach) {
    List<string> dinosaurs;
    
    // Test contains
    EXPECT_FALSE(dinosaurs.Contains("Deinonychus"));
    
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
      clipsAdded+= addCount;
      for (Int32 index = 0; index < addCount; index++)
        list.Add(Int32(rand.Next()));
      EXPECT_EQ(list.Count, clipsAdded - clipsRemoved);
      
      Int32 deleteCount = rand.Next(list.Count);
      clipsRemoved+= deleteCount;
      for (Int32 index = 0; index < deleteCount; index++) {
        list.RemoveAt(rand.Next(list.Count-1));
      }
      EXPECT_EQ(list.Count, clipsAdded - clipsRemoved);
    }
  }
  
  TEST(List, GetCapacityAndGetCount) {
    // Create List<T> with default Capacity)
    List<Int32> listMaxCapacity;
    EXPECT_EQ(listMaxCapacity.Capacity, 0);
    listMaxCapacity.Clear();
    
    // Create List<T> with a Capacity equal to 5)
    List<Int32> listCapacity5(5);
    EXPECT_EQ(listCapacity5.Capacity, 5);
    RandAddAndRemove(listCapacity5, 5);
    listCapacity5.Clear();
    
    // Create List<T> with a Capacity equal to 256)
    List<Int32> listCapacity256(256);
    EXPECT_EQ(listCapacity256.Capacity, 256);
    RandAddAndRemove(listCapacity256, 256);
    listCapacity256.Clear();
  }
  
  TEST(List, GetEnumerator) {
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
    
    UniquePointer<IEnumerator<string>> enumerators[50];
    
    for (Int32 index = 0; index < 50; index++) {
      enumerators[index] = new Enumerator<string>(dinosaurs.GetEnumerator());
      enumerators[index]->MoveNext();
      EXPECT_EQ("Tyrannosaurus", enumerators[index]->Current());
    }
    
    enumerators[0] = new Enumerator<string>(dinosaurs.GetEnumerator());
    enumerators[0]->MoveNext();
    EXPECT_EQ("Tyrannosaurus", enumerators[0]->Current());
  }
  
  static void MyThread(const Object& param) {
    List<string> *dinosaurs = &((List<string>&) param);
    
    LockGuard lock(dinosaurs->SyncRoot);
    // Add 9 items
    for (Int32 index = 1; index < 10; index++) {
      dinosaurs->Add("Line " + index);
      Thread::Sleep(0);
    }
  }

  TEST(List, GetSyncRoot) {
    // Create List<T> to used with Contains function
    List<string> dinosaurs;
    
    Thread myThread((ParameterizedThreadStart)MyThread);
    myThread.Start(dinosaurs);
    
    pcf_lock (dinosaurs.SyncRoot) {
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
      EXPECT_EQ("Line 1", dinosaurs[0]);
      EXPECT_EQ("Line 2", dinosaurs[1]);
      EXPECT_EQ("Line 3", dinosaurs[2]);
      EXPECT_EQ("Line 4", dinosaurs[3]);
      EXPECT_EQ("Line 5", dinosaurs[4]);
      EXPECT_EQ("Line 6", dinosaurs[5]);
      EXPECT_EQ("Line 7", dinosaurs[6]);
      EXPECT_EQ("Line 8", dinosaurs[7]);
      EXPECT_EQ("Line 9", dinosaurs[8]);
      EXPECT_EQ("Tyrannosaurus", dinosaurs[9]);
      EXPECT_EQ("Compsognathus", dinosaurs[10]);
      EXPECT_EQ("Amargasaurus", dinosaurs[11]);
      EXPECT_EQ("Oviraptor", dinosaurs[12]);
      EXPECT_EQ("Velociraptor", dinosaurs[13]);
      EXPECT_EQ("Deinonychus", dinosaurs[14]);
      EXPECT_EQ("Dilophosaurus", dinosaurs[15]);
      EXPECT_EQ("Gallimimus", dinosaurs[16]);
      EXPECT_EQ("Triceratops", dinosaurs[17]);
    } else {
      EXPECT_EQ(dinosaurs[0], "Tyrannosaurus");
      EXPECT_EQ(dinosaurs[1], "Compsognathus");
      EXPECT_EQ(dinosaurs[2], "Amargasaurus");
      EXPECT_EQ(dinosaurs[3], "Oviraptor");
      EXPECT_EQ(dinosaurs[4], "Velociraptor");
      EXPECT_EQ(dinosaurs[5], "Deinonychus");
      EXPECT_EQ(dinosaurs[6], "Dilophosaurus");
      EXPECT_EQ(dinosaurs[7], "Gallimimus");
      EXPECT_EQ(dinosaurs[8], "Triceratops");
      EXPECT_EQ(dinosaurs[9], "Line 1");
      EXPECT_EQ(dinosaurs[10], "Line 2");
      EXPECT_EQ(dinosaurs[11], "Line 3");
      EXPECT_EQ(dinosaurs[12], "Line 4");
      EXPECT_EQ(dinosaurs[13], "Line 5");
      EXPECT_EQ(dinosaurs[14], "Line 6");
      EXPECT_EQ(dinosaurs[15], "Line 7");
      EXPECT_EQ(dinosaurs[16], "Line 8");
      EXPECT_EQ(dinosaurs[17], "Line 9");
    }
  }
  
  TEST(List, ListOperatorEqual) {
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
    EXPECT_EQ(dinosaurs.Count, dinosaursBis.Count);
  }
  
  TEST(List, Sort) {
    int k;
    string names[9] = {"Tyrannosaurus","Compsognathus","Amargasaurus","Oviraptor","Velociraptor","Deinonychus","Dilophosaurus","Gallimimus","Triceratops"};
    string sortedNames[9] = {"Amargasaurus","Compsognathus","Deinonychus","Dilophosaurus","Gallimimus","Oviraptor","Triceratops","Tyrannosaurus","Velociraptor"};
    
    // First we test a sort function on IComparable objects (string in this case)
    
    List<string> dinosaurNames;
    for (int i = 0; i < 9; i++)
      dinosaurNames.Add(names[i]);
    
    EXPECT_EQ(9,dinosaurNames.Count);
    
    k=0;
    for (string s : dinosaurNames)
      EXPECT_TRUE(s.Equals(names[k++]));
    
    dinosaurNames.Sort();
    
    k=0;
    for (string s : dinosaurNames)
      EXPECT_TRUE(s.Equals(sortedNames[k++]));
    
    // Second we test a sort function on objects not implementing IComparable (Dinosaur in this case)
    // Thus we provide an IComparer (DinosaurComparer)
    // Create List<T> to used with Contains function
    List<Dinosaur> dinosaurs;
    
    // Add 6 items
    dinosaurs.Add(Dinosaur("Tyrannosaurus",2));
    dinosaurs.Add(Dinosaur("Compsognathus",2));
    dinosaurs.Add(Dinosaur("Amargasaurus",4));
    dinosaurs.Add(Dinosaur("Oviraptor",2));
    dinosaurs.Add(Dinosaur("Velociraptor",2));
    dinosaurs.Add(Dinosaur("Deinonychus",2));
    dinosaurs.Add(Dinosaur("Dilophosaurus",2));
    dinosaurs.Add(Dinosaur("Gallimimus",2));
    dinosaurs.Add(Dinosaur("Triceratops",4));
    
    k=0;
    for (Dinosaur d : dinosaurs)
      EXPECT_TRUE(d.GetName().Equals(names[k++]));
    
    dinosaurs.Sort(DinosaurComparer());
    
    k=0;
    for (Dinosaur d : dinosaurs)
      EXPECT_TRUE(d.GetName().Equals(sortedNames[k++]));
  }
  
  TEST(List, polymorphicList) {
    List<SharedPointer<ValueType>> polymorphicList;
    polymorphicList.Add(new Int32(1024));
    polymorphicList.Add(new string("Polymorphic"));
    polymorphicList.Add(new Boolean(true));
    polymorphicList.Add(new Char('P'));
    
    EXPECT_TRUE(is< Int32 >(*polymorphicList[0]));
    EXPECT_TRUE(is< String >(*polymorphicList[1]));
    EXPECT_TRUE(is< Boolean >(*polymorphicList[2]));
    EXPECT_TRUE(is< Char >(*polymorphicList[3]));
    
    EXPECT_EQ(string("1024"), polymorphicList[0]->ToString());
    EXPECT_EQ(string("Polymorphic"), polymorphicList[1]->ToString());
    EXPECT_EQ(string("True"), polymorphicList[2]->ToString());
    EXPECT_EQ(string("P"), polymorphicList[3]->ToString());
  }
  
  TEST(List, Remove) {
    List<int32> list;
    
    EXPECT_FALSE(list.Remove(5));
    EXPECT_THROW(list.RemoveAt(0), ArgumentOutOfRangeException);
    EXPECT_THROW(list.RemoveAt(-1), ArgumentOutOfRangeException);
    EXPECT_THROW(list.RemoveAt(1), ArgumentOutOfRangeException);
    
    list.Add(1);
    list.Add(22);
    list.Add(333);
    list.Add(4444);
    list.Add(55555);
    
    EXPECT_FALSE(list.Remove(5));
    EXPECT_THROW(list.RemoveAt(-1), ArgumentOutOfRangeException);
    EXPECT_THROW(list.RemoveAt(5), ArgumentOutOfRangeException);
    
    EXPECT_TRUE(list.Remove(22));
    list.RemoveAt(1);
    
    EXPECT_EQ(3,list.Count);
    EXPECT_EQ(1,     list[0]);
    EXPECT_EQ(4444,  list[1]);
    EXPECT_EQ(55555, list[2]);
  }
  
  TEST(List, RemoveAfterIteration) {
    List<Int32> testList;
    List<Int32> toRemove;
    
    testList.Add(172);
    testList.Add(573);
    testList.Add(14);
    testList.Add(16251);
    testList.Add(8);
    EXPECT_EQ(5, testList.Count);
    
    for (Int32 value : testList) {
      if (value % 2 == 0)
        toRemove.Add(value);
    }
    
    EXPECT_EQ(5, testList.Count);
    EXPECT_EQ(3, toRemove.Count);
    
    for (Int32 value : toRemove)
      testList.Remove(value);
    
    EXPECT_EQ(2, testList.Count);
  }
  
  TEST(List, Equals) {
    List<Dinosaur> dinosaurs;
    dinosaurs.Add(Dinosaur("Tyrannosaurus",2));
    dinosaurs.Add(Dinosaur("Compsognathus",2));
    dinosaurs.Add(Dinosaur("Amargasaurus",4));
    dinosaurs.Add(Dinosaur("Oviraptor",2));
    dinosaurs.Add(Dinosaur("Velociraptor",2));
    dinosaurs.Add(Dinosaur("Deinonychus",2));
    dinosaurs.Add(Dinosaur("Dilophosaurus",2));
    dinosaurs.Add(Dinosaur("Gallimimus",2));
    dinosaurs.Add(Dinosaur("Triceratops",4));
    
    List<Dinosaur> dinosaurs2; // same
    dinosaurs2.Add(Dinosaur("Tyrannosaurus",2));
    dinosaurs2.Add(Dinosaur("Compsognathus",2));
    dinosaurs2.Add(Dinosaur("Amargasaurus",4));
    dinosaurs2.Add(Dinosaur("Oviraptor",2));
    dinosaurs2.Add(Dinosaur("Velociraptor",2));
    dinosaurs2.Add(Dinosaur("Deinonychus",2));
    dinosaurs2.Add(Dinosaur("Dilophosaurus",2));
    dinosaurs2.Add(Dinosaur("Gallimimus",2));
    dinosaurs2.Add(Dinosaur("Triceratops",4));
    
    List<Dinosaur> dinosaurs3; // Deinnonychus has zero legs
    dinosaurs3.Add(Dinosaur("Tyrannosaurus",2));
    dinosaurs3.Add(Dinosaur("Compsognathus",2));
    dinosaurs3.Add(Dinosaur("Amargasaurus",4));
    dinosaurs3.Add(Dinosaur("Oviraptor",2));
    dinosaurs3.Add(Dinosaur("Velociraptor",2));
    dinosaurs3.Add(Dinosaur("Deinonychus",0));
    dinosaurs3.Add(Dinosaur("Dilophosaurus",2));
    dinosaurs3.Add(Dinosaur("Gallimimus",2));
    dinosaurs3.Add(Dinosaur("Triceratops",4));
    
    List<Dinosaur> dinosaurs4; // two triceratops
    dinosaurs4.Add(Dinosaur("Tyrannosaurus",2));
    dinosaurs4.Add(Dinosaur("Compsognathus",2));
    dinosaurs4.Add(Dinosaur("Amargasaurus",4));
    dinosaurs4.Add(Dinosaur("Oviraptor",2));
    dinosaurs4.Add(Dinosaur("Velociraptor",2));
    dinosaurs4.Add(Dinosaur("Deinonychus",0));
    dinosaurs4.Add(Dinosaur("Dilophosaurus",2));
    dinosaurs4.Add(Dinosaur("Gallimimus",2));
    dinosaurs4.Add(Dinosaur("Triceratops",4));
    dinosaurs4.Add(Dinosaur("Triceratops",18));
    
    List<Dinosaur> dinosaurs5; // one element
    dinosaurs5.Add(Dinosaur("Tyrannosaurus",2));
    
    List<Dinosaur> dinosaurs6; //empty
    
    EXPECT_EQ(dinosaurs, dinosaurs2);
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
