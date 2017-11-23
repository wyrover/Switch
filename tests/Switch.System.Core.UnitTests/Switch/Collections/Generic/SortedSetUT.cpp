#include <Switch/System/Collections/Generic/SortedSet.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {
  SortedSet<char> cset(const char* s) {
    SortedSet<char> set;
    int len = static_cast<int>(strlen(s));
    for (int i = 0; i < len; i++)
      set.Add(s[i]);
    return set;
  }
  
  class Person : public object, public IComparable {
  public:
    Person() {}
    Person(const string& n, const string& sn) : name(n), surname(sn) {}
    Person(const string& p) { *this = p; }
    
    Person& operator =(const Person& p) {
      this->name = p.name;
      this->surname = p.surname;
      return *this;
    }
    
    const string& GetName() const { return this->name; }
    const string& GetSurname() const { return this->surname; }
    
    int32 CompareTo(const IComparable& obj) const override {
      if (!is<Person>(obj))
        return 1;
      const Person* p = as<Person>(&obj);
      int32 r = this->surname.CompareTo(p->surname);
      if (r != 0) return r;
      return this->name.CompareTo(p->name);
    }
    
    bool Equals(const object& obj) const override {
      if (!is<Person>(obj))
        return false;
        
      const Person* p = as<Person>(&obj);
      return this->name == p->name && this->surname == p->surname;
    }
    
    String ToString() const override { return this->name + " " + this->surname; }
    
  private:
    string name, surname;
  };
  
  class NameComparer : public IComparer<Person>  {
    virtual int32 Compare(const Person& x, const Person& y) const {
      int32 r = x.GetName().CompareTo(y.GetName());
      if (r != 0) return r;
      return x.GetSurname().CompareTo(y.GetSurname());
    }
  };
  
  class NameOnlyComparer : public IComparer<Person> {
    virtual int32 Compare(const Person& x, const Person& y) const {
      return x.GetName().CompareTo(y.GetName());
    }
  };
  
  class ReversedIntegerComparer : public IComparer<int32> {
    virtual int32 Compare(const int32& x, const int32& y) const {
      if (x < y) return 1;
      if (x == y) return 0;
      return -1;
    }
  };
  
  TEST(SortedSet, Constructor) {
    SortedSet<int> set1;
    SortedSet<int> set2;
  }
  
  TEST(SortedSet, ConstructorIEnumerable) {
    List<string> list;
    SortedSet<string> empty(list);
    EXPECT_EQ(0, empty.Count);
    
    list.Add("28 mm 1.4D");
    list.Add("50mm 1.2 AIS");
    list.Add("135mm 2D");
    list.Add("105mm 2.8D");
    SortedSet<string> set(list);
    
    string olds[4] = {"105mm 2.8D", "135mm 2D", "28 mm 1.4D", "50mm 1.2 AIS"};
    
    int i = 0;
    for (string s : set)
      EXPECT_EQ(olds[i++], s);
  }
  
  TEST(SortedSet, ConstructorIComparer) {
    SortedSet<Person> set_sn;
    SortedSet<Person> set_n(new NameComparer());
    set_sn.Add(Person("Peter", "PARKER"));
    set_sn.Add(Person("Gwen", "STACY"));
    set_sn.Add(Person("Mary Jane", "WATSON"));
    set_sn.Add(Person("Harry", "OSBORN"));
    
    set_n.Add(Person("Peter", "PARKER"));
    set_n.Add(Person("Gwen", "STACY"));
    set_n.Add(Person("Mary Jane", "WATSON"));
    set_n.Add(Person("Harry", "OSBORN"));
    
    string by_surname[4] = {"Harry OSBORN", "Peter PARKER", "Gwen STACY", "Mary Jane WATSON"};
    string by_name[4] = {"Gwen STACY", "Harry OSBORN", "Mary Jane WATSON", "Peter PARKER"};
    
    int i = 0;
    for (Person p : set_sn)
      EXPECT_EQ(by_surname[i++], p.ToString());
      
    i = 0;
    for (Person p : set_n)
      EXPECT_EQ(by_name[i++], p.ToString());
  }
  
  TEST(SortedSet, ConstructorIEnumerableIComparer) {
    List<Person> list;
    list.Add(Person("Peter", "PARKER"));
    list.Add(Person("Gwen", "STACY"));
    list.Add(Person("Mary Jane", "WATSON"));
    list.Add(Person("Harry", "OSBORN"));
    SortedSet<Person> set_n(list, new NameComparer());
    string by_name[4] = {"Gwen STACY", "Harry OSBORN", "Mary Jane WATSON", "Peter PARKER"};
    int i = 0;
    for (Person p : set_n)
      EXPECT_EQ(by_name[i++], p.ToString());
  }
  
  TEST(SortedSet, Add) {
    SortedSet<int> set;
    SortedSet<int> second_set;
    EXPECT_TRUE(set.Add(5));
    EXPECT_TRUE(second_set.Add(5));
    EXPECT_TRUE(set.Add(89));
    EXPECT_TRUE(second_set.Add(100));
    EXPECT_TRUE(set.Add(42));
    EXPECT_TRUE(second_set.Add(42));
    EXPECT_FALSE(set.Add(89));
    EXPECT_TRUE(second_set.Add(89));
    EXPECT_FALSE(set.Add(5));
    EXPECT_FALSE(second_set.Add(5));
    EXPECT_FALSE(set.Add(42));
  }
  
  TEST(SortedSet, Clear) {
    SortedSet<int> set;
    EXPECT_TRUE(set.Add(5));
    EXPECT_TRUE(set.Add(89));
    EXPECT_TRUE(set.Add(42));
    EXPECT_FALSE(set.Add(89));
    EXPECT_FALSE(set.Add(5));
    EXPECT_FALSE(set.Add(42));
    
    EXPECT_EQ(3, set.Count);
    set.Clear();
    EXPECT_EQ(0, set.Count);
    
    SortedSet<string> set2;
    EXPECT_EQ(0, set2.Count);
    set2.Clear();
    EXPECT_EQ(0, set2.Count);
    set2.Clear();
    EXPECT_EQ(0, set2.Count);
  }
  
  TEST(SortedSet, Contains) {
    SortedSet<int> set;
    SortedSet<int> second_set;
    EXPECT_TRUE(set.Add(5));
    EXPECT_TRUE(second_set.Add(5));
    EXPECT_TRUE(set.Add(89));
    EXPECT_TRUE(second_set.Add(100));
    EXPECT_TRUE(set.Add(42));
    EXPECT_TRUE(second_set.Add(42));
    EXPECT_FALSE(set.Add(89));
    EXPECT_TRUE(second_set.Add(89));
    EXPECT_FALSE(set.Add(5));
    EXPECT_FALSE(second_set.Add(5));
    EXPECT_FALSE(set.Add(42));
    
    EXPECT_TRUE(set.Contains(42));
    EXPECT_FALSE(set.Contains(987));
    EXPECT_TRUE(second_set.Contains(89));
    EXPECT_TRUE(second_set.Contains(5));
    EXPECT_TRUE(second_set.Contains(42));
    EXPECT_FALSE(second_set.Contains(987));
  }
  
  TEST(SortedSet, CopyTo) {
    SortedSet<string> dinosaurs;
    Array<string> array(20);
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    // Test CopyTo
    dinosaurs.CopyTo(array);
    EXPECT_EQ(array[0], "Amargasaurus");
    EXPECT_EQ(array[1], "Compsognathus");
    EXPECT_EQ(array[2], "Deinonychus");
    EXPECT_EQ(array[3], "Mamenchisaurus");
    EXPECT_EQ(array[4], "Tyrannosaurus");
    
    dinosaurs.CopyTo(array, 6);
    EXPECT_EQ(array[0], "Amargasaurus");
    EXPECT_EQ(array[1], "Compsognathus");
    EXPECT_EQ(array[2], "Deinonychus");
    EXPECT_EQ(array[3], "Mamenchisaurus");
    EXPECT_EQ(array[4], "Tyrannosaurus");
    EXPECT_EQ(array[5], "");
    EXPECT_EQ(array[6], "Amargasaurus");
    EXPECT_EQ(array[7], "Compsognathus");
    EXPECT_EQ(array[8], "Deinonychus");
    EXPECT_EQ(array[9], "Mamenchisaurus");
    EXPECT_EQ(array[10], "Tyrannosaurus");
    
    dinosaurs.CopyTo(2, array, 12, 3);
    EXPECT_EQ(array[0], "Amargasaurus");
    EXPECT_EQ(array[1], "Compsognathus");
    EXPECT_EQ(array[2], "Deinonychus");
    EXPECT_EQ(array[3], "Mamenchisaurus");
    EXPECT_EQ(array[4], "Tyrannosaurus");
    EXPECT_EQ(array[5], "");
    EXPECT_EQ(array[6], "Amargasaurus");
    EXPECT_EQ(array[7], "Compsognathus");
    EXPECT_EQ(array[8], "Deinonychus");
    EXPECT_EQ(array[9], "Mamenchisaurus");
    EXPECT_EQ(array[10], "Tyrannosaurus");
    EXPECT_EQ(array[11], "");
    EXPECT_EQ(array[12], "Deinonychus");
    EXPECT_EQ(array[13], "Mamenchisaurus");
    EXPECT_EQ(array[14], "Tyrannosaurus");
    EXPECT_EQ(array[15], "");
  }
  
  TEST(SortedSet, CopyToExceptions) {
    // Create List<T> to used with Contains function
    SortedSet<string> dinosaurs;
    Array<string> array(20);
    
    // Add 5 items
    dinosaurs.Add("Tyrannosaurus");
    dinosaurs.Add("Amargasaurus");
    dinosaurs.Add("Mamenchisaurus");
    dinosaurs.Add("Deinonychus");
    dinosaurs.Add("Compsognathus");
    
    EXPECT_THROW(dinosaurs.CopyTo(array, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.CopyTo(-1, array,  0, 5), ArgumentOutOfRangeException);
    EXPECT_THROW(dinosaurs.CopyTo(0, array,  0, -1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(dinosaurs.CopyTo(array,  20), ArgumentException);
    EXPECT_THROW(dinosaurs.CopyTo(0, array,  0, 6), ArgumentException);
    EXPECT_THROW(dinosaurs.CopyTo(1, array,  0, 5), ArgumentException);
    
    Array<string> small_array(3);
    EXPECT_THROW(dinosaurs.CopyTo(small_array), ArgumentException);
  }
  
  TEST(SortedSet, SetEquals) {
    SortedSet<Person> set1;
    set1.Add(Person("Peter", "PARKER"));
    set1.Add(Person("Gwen", "STACY"));
    set1.Add(Person("Mary Jane", "WATON"));
    set1.Add(Person("Harry", "OSBORN"));
    
    SortedSet<Person> set2;
    set2.Add(Person("Peter", "PARKER"));
    set2.Add(Person("Gwen", "STACY"));
    set2.Add(Person("Mary Jane", "WATON"));
    
    SortedSet<Person> set3(new NameComparer());
    set3.Add(Person("Peter", "PARKER"));
    set3.Add(Person("Gwen", "STACY"));
    set3.Add(Person("Mary Jane", "WATON"));
    
    EXPECT_FALSE(set1.SetEquals(set2));
    EXPECT_FALSE(set2.SetEquals(set1));
    EXPECT_FALSE(set1.SetEquals(set3));
    EXPECT_FALSE(set3.SetEquals(set1));
    
    EXPECT_TRUE(set2.SetEquals(set3));
    EXPECT_TRUE(set3.SetEquals(set2));
    
    set2.Add(Person("Harry", "OSBORN"));
    
    EXPECT_TRUE(set1.SetEquals(set2));
    EXPECT_TRUE(set2.SetEquals(set1));
    
    set3.Add(Person("Harry", "OSBORN"));
    EXPECT_TRUE(set1.SetEquals(set3));
    EXPECT_TRUE(set3.SetEquals(set1));
    EXPECT_TRUE(set2.SetEquals(set3));
    EXPECT_TRUE(set3.SetEquals(set2));
  }
  
  
  TEST(SortedSet, GetEnumerator) {
    SortedSet<string> set1;
    SortedSet<string> set2;
    EXPECT_TRUE(set1.Add("Tintin"));
    EXPECT_TRUE(set1.Add("Milou"));
    EXPECT_TRUE(set1.Add("Tournesol"));
    
    string sorted_1[3] = {"Milou", "Tintin", "Tournesol"};
    
    EXPECT_TRUE(set2.Add("Wonderwoman"));
    EXPECT_TRUE(set2.Add("Batman"));
    EXPECT_TRUE(set2.Add("Spiderman"));
    EXPECT_TRUE(set2.Add("Superman"));
    
    string sorted_2[4] = {"Batman", "Spiderman", "Superman", "Wonderwoman"};
    
    Enumerator<string> enum1 = set1.GetEnumerator();
    Enumerator<string> enum1b = set1.GetEnumerator();
    Enumerator<string> enum2 = set2.GetEnumerator();
    
    EXPECT_THROW(enum1.Current(), InvalidOperationException);
    enum1b.MoveNext();
    int i = 0;
    while (enum1.MoveNext()) {
      EXPECT_EQ(sorted_1[i++], enum1.Current);
      EXPECT_EQ(sorted_1[0], enum1b.Current);
    }
    
    EXPECT_THROW(enum2.Current(), InvalidOperationException);
    i = 0;
    while (enum2.MoveNext())
      EXPECT_EQ(sorted_2[i++], enum2.Current);
  }
  
  TEST(SortedSet, ExceptWith) {
    SortedSet<int> odds;
    List<int> evens;
    for (int i = 0; i < 20; i++) {
      odds.Add(i);
      if (i % 2 == 0)
        evens.Add(i);
    }
    
    odds.ExceptWith(evens);
    EXPECT_EQ(10, odds.Count);
    
    for (int x : odds)
      EXPECT_EQ(1, x % 2);
      
    odds.ExceptWith(odds);
    EXPECT_EQ(0, odds.Count);
  }
  
  TEST(SortedSet, Remove) {
    SortedSet<int> numbers;
    for (int i = 0; i < 10; i++)
      numbers.Add(i);
      
    EXPECT_TRUE(numbers.Remove(0));
    EXPECT_FALSE(numbers.Remove(0));
    EXPECT_TRUE(numbers.Remove(2));
    EXPECT_TRUE(numbers.Remove(4));
    EXPECT_TRUE(numbers.Remove(6));
    EXPECT_TRUE(numbers.Remove(8));
    EXPECT_FALSE(numbers.Remove(105));
    
    EXPECT_EQ(5, numbers.Count);
    for (int x : numbers)
      EXPECT_EQ(1, x % 2);
  }
  
  TEST(SortedSet, GetViewBetween) {
    SortedSet<int32> _1_100;
    int32 test1[51];
    for (int i = 1; i <= 100; i++) {
      _1_100.Add(i);
      if (i >= 25 && i <= 75)
        test1[i - 25] = i;
    }
    
    SortedSet<int32> _25_75 = _1_100.GetViewBetween(25, 75);
    {
      int i = 0;
      for (int32 x : _25_75)
        EXPECT_EQ(test1[i++], x);
    }
    
    SortedSet<int32> _100_1(_1_100, new ReversedIntegerComparer());
    int32 test2[51];
    int k = 0;
    for (int i = 75; i >= 25; i--)
      test2[k++] = i;
      
    SortedSet<int32> _75_25 = _100_1.GetViewBetween(25, 75);
    {
      int i = 0;
      for (int32 x : _75_25)
        EXPECT_EQ(test2[i++], x);
    }
    
    SortedSet<int32> one = _100_1.GetViewBetween(56, 56);
    EXPECT_EQ(1, one.Count);
    for (int32 x : one)
      EXPECT_EQ(56, x);
  }
  
  TEST(SortedSet, IntersectWith) {
    SortedSet<int32> _1_10;
    SortedSet<int32> _5_15;
    for (int i = 1; i < 15; i++) {
      if (i <= 10)
        _1_10.Add(i);
      if (i >= 5)
        _5_15.Add(i);
    }
    
    _1_10.IntersectWith(_5_15);
    for (int32 x : _1_10) {
      EXPECT_LE(x, 10);
      EXPECT_GE(x, 5);
    }
  }
  
  TEST(SortedSet, IsSubsetOf) {
    // empty is a subset of any set
    EXPECT_TRUE(cset("").IsSubsetOf(cset("")));
    EXPECT_TRUE(cset("").IsSubsetOf(cset("1")));
    EXPECT_TRUE(cset("").IsSubsetOf(cset("1654987")));
    EXPECT_FALSE(cset("25465").IsSubsetOf(cset("")));
    SortedSet<char> empty;
    EXPECT_TRUE(empty.IsSubsetOf(cset("123")));
    EXPECT_FALSE(cset("123456").IsSubsetOf(empty));
    
    EXPECT_TRUE(cset("abc").IsSubsetOf(cset("abcd")));
    EXPECT_TRUE(cset("abcd").IsSubsetOf(cset("abcd")));
    EXPECT_FALSE(cset("abcd").IsSubsetOf(cset("abc")));
  }
  
  TEST(SortedSet, IsProperSubsetOf) {
    EXPECT_FALSE(cset("").IsProperSubsetOf(cset("")));
    EXPECT_FALSE(cset("a").IsProperSubsetOf(cset("")));
    EXPECT_TRUE(cset("").IsProperSubsetOf(cset("a")));
    EXPECT_TRUE(cset("").IsProperSubsetOf(cset("ab")));
    EXPECT_FALSE(cset("abc").IsProperSubsetOf(cset("")));
    
    EXPECT_TRUE(cset("bc").IsProperSubsetOf(cset("abc")));
    EXPECT_TRUE(cset("ab").IsProperSubsetOf(cset("abc")));
    EXPECT_TRUE(cset("a").IsProperSubsetOf(cset("abc")));
    EXPECT_TRUE(cset("b").IsProperSubsetOf(cset("bac")));
    EXPECT_TRUE(cset("c").IsProperSubsetOf(cset("abc")));
    EXPECT_FALSE(cset("ad").IsProperSubsetOf(cset("abc")));
    
    EXPECT_TRUE(cset("1356").IsProperSubsetOf(cset("123456")));
    EXPECT_TRUE(cset("456").IsProperSubsetOf(cset("123456")));
    EXPECT_FALSE(cset("123456").IsProperSubsetOf(cset("123456")));
    
    SortedSet<char> test = cset("123456");
    EXPECT_FALSE(test.IsProperSubsetOf(test));
    
    SortedSet<char> empty;
    EXPECT_TRUE(empty.IsProperSubsetOf(cset("123")));
    EXPECT_FALSE(cset("123456").IsProperSubsetOf(empty));
  }
  
  TEST(SortedSet, IsSupersetOf) {
    EXPECT_TRUE(cset("").IsSupersetOf(cset("")));
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("")));
    
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("1")));
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("2")));
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("3")));
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("12")));
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("23")));
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("13")));
    EXPECT_TRUE(cset("123").IsSupersetOf(cset("123")));
    
    EXPECT_TRUE(cset("123456").IsSupersetOf(cset("1346")));
    EXPECT_FALSE(cset("123").IsSupersetOf(cset("7")));
    EXPECT_FALSE(cset("123").IsSupersetOf(cset("1237")));
    EXPECT_FALSE(cset("123").IsSupersetOf(cset("1234567")));
  }
  
  TEST(SortedSet, IsProperSupersetOf) {
    EXPECT_FALSE(cset("").IsProperSupersetOf(cset("")));
    EXPECT_TRUE(cset("a").IsProperSupersetOf(cset("")));
    EXPECT_TRUE(cset("abc").IsProperSupersetOf(cset("")));
    
    EXPECT_TRUE(cset("abc").IsProperSupersetOf(cset("bc")));
    EXPECT_TRUE(cset("abc").IsProperSupersetOf(cset("ab")));
    EXPECT_TRUE(cset("abc").IsProperSupersetOf(cset("a")));
    EXPECT_TRUE(cset("abc").IsProperSupersetOf(cset("b")));
    EXPECT_TRUE(cset("abc").IsProperSupersetOf(cset("c")));
    EXPECT_FALSE(cset("abc").IsProperSupersetOf(cset("ad")));
    EXPECT_FALSE(cset("abc").IsProperSupersetOf(cset("d")));
    
    EXPECT_TRUE(cset("123456").IsProperSupersetOf(cset("1345")));
    EXPECT_TRUE(cset("123456").IsProperSupersetOf(cset("456")));
    EXPECT_FALSE(cset("123456").IsProperSupersetOf(cset("123456")));
    
    SortedSet<char> test = cset("123456");
    EXPECT_FALSE(test.IsProperSupersetOf(test));
    
    SortedSet<char> empty;
    EXPECT_FALSE(empty.IsProperSupersetOf(cset("123")));
    EXPECT_TRUE(cset("123456").IsProperSupersetOf(empty));
  }
  
  TEST(SortedSet, Overlaps) {
    EXPECT_TRUE(cset("abc").Overlaps(cset("a")));
    EXPECT_TRUE(cset("abc").Overlaps(cset("b")));
    EXPECT_TRUE(cset("abc").Overlaps(cset("c")));
    EXPECT_TRUE(cset("abc").Overlaps(cset("ab")));
    EXPECT_TRUE(cset("abc").Overlaps(cset("bc")));
    EXPECT_TRUE(cset("abc").Overlaps(cset("ac")));
    
    EXPECT_TRUE(cset("a").Overlaps(cset("abc")));
    EXPECT_TRUE(cset("b").Overlaps(cset("abc")));
    EXPECT_TRUE(cset("c").Overlaps(cset("abc")));
    EXPECT_TRUE(cset("ab").Overlaps(cset("abc")));
    EXPECT_TRUE(cset("bc").Overlaps(cset("abc")));
    EXPECT_TRUE(cset("ac").Overlaps(cset("abc")));
    
    EXPECT_TRUE(cset("abc").Overlaps(cset("abc")));
    
    EXPECT_TRUE(cset("abcd").Overlaps(cset("bcde")));
    EXPECT_TRUE(cset("abc").Overlaps(cset("bcd")));
    EXPECT_TRUE(cset("ab").Overlaps(cset("bc")));
    EXPECT_TRUE(cset("a").Overlaps(cset("a")));
    
    EXPECT_FALSE(cset("").Overlaps(cset("bc")));
    EXPECT_FALSE(cset("").Overlaps(cset("")));
    EXPECT_FALSE(cset("ad").Overlaps(cset("")));
    EXPECT_FALSE(cset("123").Overlaps(cset("456")));
    EXPECT_FALSE(cset("123").Overlaps(cset("abc")));
  }
  
  TEST(SortedSet, SymmetricExceptWith) {
    {
      SortedSet<char> s(cset("123"));
      s.SymmetricExceptWith(cset("234"));
      EXPECT_TRUE(s.SetEquals(cset("14")));
      EXPECT_FALSE(s.SetEquals(cset("132")));
    }
    
    {
      SortedSet<char> s(cset("abcdefgh"));
      s.SymmetricExceptWith(cset("acegik"));
      EXPECT_TRUE(s.SetEquals(cset("bdfhik")));
      EXPECT_FALSE(s.SetEquals(cset("abcdefgh")));
    }
    
    {
      SortedSet<char> s(cset(""));
      s.SymmetricExceptWith(cset("123"));
      EXPECT_TRUE(s.SetEquals(cset("123")));
      EXPECT_FALSE(s.SetEquals(cset("")));
    }
    
    {
      SortedSet<char> s(cset("abc"));
      s.SymmetricExceptWith(cset(""));
      EXPECT_TRUE(s.SetEquals(cset("abc")));
      EXPECT_FALSE(s.SetEquals(cset("")));
    }
    
    {
      SortedSet<char> s(cset("123"));
      s.SymmetricExceptWith(cset("456"));
      EXPECT_TRUE(s.SetEquals(cset("123456")));
      EXPECT_FALSE(s.SetEquals(cset("123")));
    }
    
    {
      SortedSet<char> s(cset(""));
      s.SymmetricExceptWith(cset(""));
      EXPECT_TRUE(s.SetEquals(cset("")));
    }
  }
  
  TEST(SortedSet, UnionWith_Empty) {
    SortedSet<char> s(cset(""));
    s.UnionWith(cset(""));
    EXPECT_TRUE(s.SetEquals(cset("")));
  }
  
  TEST(SortedSet, UnionWith_NoOverlap) {
    SortedSet<char> s(cset("123"));
    s.UnionWith(cset("456"));
    EXPECT_TRUE(s.SetEquals(cset("123456")));
  }
  
  TEST(SortedSet, UnionWith_Overlap) {
    SortedSet<char> s(cset("123"));
    s.UnionWith(cset("345"));
    EXPECT_TRUE(s.SetEquals(cset("12345")));
  }
  
  TEST(SortedSet, UnionWith_EmptyAndNotEmpty) {
    SortedSet<char> s(cset(""));
    s.UnionWith(cset("123"));
    EXPECT_TRUE(s.SetEquals(cset("123")));
  }
  
  TEST(SortedSet, UnionWith_NotEmptyAndEmpty) {
    SortedSet<char> s(cset("123"));
    s.UnionWith(cset(""));
    EXPECT_TRUE(s.SetEquals(cset("123")));
  }
  
  TEST(SortedSet, UnionWith_WithComparer) {
    SortedSet<Person> set(new NameOnlyComparer());
    set.Add(Person("Gwen", "STACY"));
    set.Add(Person("Mary Jane", "WATON"));
    set.Add(Person("Harry", "OSBORN"));
    set.Add(Person("Peter", "PARKER"));
    
    SortedSet<Person> set2(new NameOnlyComparer());
    set.Add(Person("May", "PARKER"));
    set.Add(Person("Ben", "PARKER"));
    set.Add(Person("George", "STACY"));
    
    set.UnionWith(set2);
    for (Person p : set) {
      if (p.GetName().Equals("Ben"))
        EXPECT_TRUE(string("PARKER").Equals(p.GetSurname()));
    }
    
  }
  
  TEST(SortedSet, Enumerator) {
    SortedSet<int32> set;
    set.Add(3);
    set.Add(4);
    set.Add(1);
    set.Add(2);
    
    int32 expected = 1;
    SortedSet<int32>::Enumerator e(set);
    while (e.MoveNext())
      EXPECT_EQ(expected++, e.Current);
  }
  
  TEST(SortedSet, Enumerator_Empty) {
    SortedSet<int32> set;
    SortedSet<int32>::Enumerator e(set);
    while (e.MoveNext())
      EXPECT_FALSE(true);
  }
  
  TEST(SortedSet, Enumerator_Copy) {
    SortedSet<int32> set;
    set.Add(3);
    set.Add(4);
    set.Add(1);
    set.Add(2);
    
    SortedSet<int32>::Enumerator e1(set);
    EXPECT_TRUE(e1.MoveNext());
    SortedSet<int32>::Enumerator e2(e1);
    
    int32 expected = 2;
    while (e1.MoveNext())
      EXPECT_EQ(expected++, e1.Current);
      
    expected = 2;
    while (e2.MoveNext())
      EXPECT_EQ(expected++, e2.Current);
  }
  
  TEST(SortedSet, ReverseEnumerator) {
    SortedSet<int32> set;
    set.Add(3);
    set.Add(4);
    set.Add(1);
    set.Add(2);
    
    int32 expected = 4;
    SortedSet<int32>::ReverseEnumerator e(set);
    while (e.MoveNext())
      EXPECT_EQ(expected--, e.Current);
  }
  
  TEST(SortedSet, ReverseEnumerator_Empty) {
    SortedSet<int32> set;
    SortedSet<int32>::ReverseEnumerator e(set);
    while (e.MoveNext())
      EXPECT_FALSE(true);
  }
  
  TEST(SortedSet, ReverseEnumerator_Copy) {
    SortedSet<int32> set;
    set.Add(3);
    set.Add(4);
    set.Add(1);
    set.Add(2);
    
    SortedSet<int32>::ReverseEnumerator e1(set);
    EXPECT_TRUE(e1.MoveNext());
    SortedSet<int32>::ReverseEnumerator e2(e1);
    
    int32 expected = 3;
    while (e1.MoveNext())
      EXPECT_EQ(expected--, e1.Current);
      
    expected = 3;
    while (e2.MoveNext())
      EXPECT_EQ(expected--, e2.Current);
  }
  
  
}
