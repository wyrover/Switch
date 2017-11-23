#include <Switch/System/Collections/Generic/HashSet.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {
  HashSet<char> cset(const char* s) {
    HashSet<char> set;
    int len = static_cast<int>(strlen(s));
    for (int i = 0; i < len; i++)
      set.Add(s[i]);
    return set;
  }
  
  class Person : public Object, public IComparable {
  public:
    Person() {}
    Person(const string& n, const string& sn) : name(n), surname(sn) {}
    Person(const string& p) { *this = p; }
    
    Person& operator =(const Person& p) {
      this->name = p.name;
      this->surname = p.surname;
      return *this;
    }
    
    virtual ~Person() { }
    
    int32 GetHashCode() const override { return this->name.GetHashCode() ^ this->surname.GetHashCode(); }
    
    const string& GetName() const { return this->name; }
    const string& GetSurname() const { return this->surname; }
    
    // surname compare
    int32 CompareTo(const IComparable& obj) const override {
      if (!is<Person>(obj))
        return 1;
      const Person& p = as<Person>(obj);
      int32 r = this->surname.CompareTo(p.surname);
      if (r != 0) return r;
      return this->name.CompareTo(p.name);
    }
    
    bool Equals(const object& obj) const override {
      if (!is<Person>(obj))
        return false;
        
      const Person& p = as<Person>(obj);
      return this->name == p.name && this->surname == p.surname;
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
  
  
  TEST(HashSet, SimpleConstructor) {
    HashSet<int> set1;
    HashSet<int> set2;
  }
  
  TEST(HashSet, ConstructorIEnumerable) {
    List<string> list;
    HashSet<string> empty(list);
    EXPECT_EQ(0, empty.Count);
    
    list.Add("28 mm 1.4D");
    list.Add("50mm 1.2 AIS");
    list.Add("135mm 2D");
    list.Add("105mm 2.8D");
    HashSet<string> set(list);
    
    EXPECT_TRUE(set.Contains("105mm 2.8D"));
    EXPECT_TRUE(set.Contains("135mm 2D"));
    EXPECT_TRUE(set.Contains("28 mm 1.4D"));
    EXPECT_TRUE(set.Contains("50mm 1.2 AIS"));
  }
  
  TEST(HashSet, Add) {
    HashSet<int> set;
    HashSet<int> second_set;
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
  
  TEST(HashSet, Clear) {
    HashSet<int> set;
    EXPECT_TRUE(set.Add(5));
    EXPECT_TRUE(set.Add(89));
    EXPECT_TRUE(set.Add(42));
    EXPECT_FALSE(set.Add(89));
    EXPECT_FALSE(set.Add(5));
    EXPECT_FALSE(set.Add(42));
    
    EXPECT_EQ(3, set.Count);
    set.Clear();
    EXPECT_EQ(0, set.Count);
    
    HashSet<string> set2;
    EXPECT_EQ(0, set2.Count);
    set2.Clear();
    EXPECT_EQ(0, set2.Count);
    set2.Clear();
    EXPECT_EQ(0, set2.Count);
  }
  
  TEST(HashSet, Contains) {
    HashSet<int> set;
    HashSet<int> second_set;
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
  
  TEST(HashSet, CopyToExceptions) {
    // Create List<T> to used with Contains function
    HashSet<string> dinosaurs;
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
  
  TEST(HashSet, SetEquals) {
    HashSet<Person> set1;
    set1.Add(Person("Peter", "PARKER"));
    set1.Add(Person("Gwen", "STACY"));
    set1.Add(Person("Mary Jane", "WATSON"));
    set1.Add(Person("Harry", "OSBORN"));
    
    HashSet<Person> set2;
    set2.Add(Person("Peter", "PARKER"));
    set2.Add(Person("Gwen", "STACY"));
    set2.Add(Person("Mary Jane", "WATSON"));
    
    HashSet<Person> set3(new NameComparer());
    set3.Add(Person("Peter", "PARKER"));
    set3.Add(Person("Gwen", "STACY"));
    set3.Add(Person("Mary Jane", "WATSON"));
    
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
  
  TEST(HashSet, ExceptWith) {
    HashSet<int> odds;
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
  
  TEST(HashSet, Remove) {
    HashSet<int> numbers;
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
  
  TEST(HashSet, GetViewBetween) {
    HashSet<int32> _1_100;
    for (int i = 1; i <= 100; i++)
      _1_100.Add(i);
      
    HashSet<int32> _100_1(_1_100, new ReversedIntegerComparer());
    int32 test[51];
    int k = 0;
    for (int i = 75; i >= 25; i--)
      test[k++] = i;
      
    HashSet<int32> _75_25 = _100_1.GetViewBetween(25, 75);
    int i = 0;
    for (int32 x : _75_25)
      EXPECT_EQ(test[i++], x);
      
    HashSet<int32> one = _100_1.GetViewBetween(56, 56);
    EXPECT_EQ(1, one.Count);
    for (int32 x : one)
      EXPECT_EQ(56, x);
  }
  
  TEST(HashSet, IntersectWith) {
    HashSet<int32> _1_10;
    HashSet<int32> _5_15;
    for (int i = 1; i < 15; i++) {
      if (i <= 10) _1_10.Add(i);
      if (i >= 5)  _5_15.Add(i);
    }
    
    _1_10.IntersectWith(_5_15);
    for (int32 x : _1_10) {
      EXPECT_LE(x, 10);
      EXPECT_GE(x, 5);
    }
  }
  
  TEST(HashSet, IsSubsetOf) {
    // empty is a subset of any set
    EXPECT_TRUE(cset("").IsSubsetOf(cset("")));
    EXPECT_TRUE(cset("").IsSubsetOf(cset("1")));
    EXPECT_TRUE(cset("").IsSubsetOf(cset("1654987")));
    EXPECT_FALSE(cset("25465").IsSubsetOf(cset("")));
    HashSet<char> empty;
    EXPECT_TRUE(empty.IsSubsetOf(cset("123")));
    EXPECT_FALSE(cset("123456").IsSubsetOf(empty));
    
    EXPECT_TRUE(cset("abc").IsSubsetOf(cset("abcd")));
    EXPECT_TRUE(cset("abcd").IsSubsetOf(cset("abcd")));
    EXPECT_FALSE(cset("abcd").IsSubsetOf(cset("abc")));
  }
  
  TEST(HashSet, IsProperSubsetOf) {
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
    
    HashSet<char> test = cset("123456");
    EXPECT_FALSE(test.IsProperSubsetOf(test));
    
    HashSet<char> empty;
    EXPECT_TRUE(empty.IsProperSubsetOf(cset("123")));
    EXPECT_FALSE(cset("123456").IsProperSubsetOf(empty));
  }
  
  TEST(HashSet, IsSupersetOf) {
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
  
  TEST(HashSet, IsProperSupersetOf) {
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
    
    HashSet<char> test = cset("123456");
    EXPECT_FALSE(test.IsProperSupersetOf(test));
    
    HashSet<char> empty;
    EXPECT_FALSE(empty.IsProperSupersetOf(cset("123")));
    EXPECT_TRUE(cset("123456").IsProperSupersetOf(empty));
  }
  
  TEST(HashSet, Overlaps) {
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
  
  TEST(HashSet, SymmetricExceptWith) {
    {
      HashSet<char> s(cset("123"));
      s.SymmetricExceptWith(cset("234"));
      EXPECT_TRUE(s.SetEquals(cset("14")));
      EXPECT_FALSE(s.SetEquals(cset("132")));
    }
    
    {
      HashSet<char> s(cset("abcdefgh"));
      s.SymmetricExceptWith(cset("acegik"));
      EXPECT_TRUE(s.SetEquals(cset("bdfhik")));
      EXPECT_FALSE(s.SetEquals(cset("abcdefgh")));
    }
    
    {
      HashSet<char> s(cset(""));
      s.SymmetricExceptWith(cset("123"));
      EXPECT_TRUE(s.SetEquals(cset("123")));
      EXPECT_FALSE(s.SetEquals(cset("")));
    }
    
    {
      HashSet<char> s(cset("abc"));
      s.SymmetricExceptWith(cset(""));
      EXPECT_TRUE(s.SetEquals(cset("abc")));
      EXPECT_FALSE(s.SetEquals(cset("")));
    }
    
    {
      HashSet<char> s(cset("123"));
      s.SymmetricExceptWith(cset("456"));
      EXPECT_TRUE(s.SetEquals(cset("123456")));
      EXPECT_FALSE(s.SetEquals(cset("123")));
    }
    
    {
      HashSet<char> s(cset(""));
      s.SymmetricExceptWith(cset(""));
      EXPECT_TRUE(s.SetEquals(cset("")));
    }
  }
  
  TEST(HashSet, UnionWith_Empty) {
    HashSet<char> s(cset(""));
    s.UnionWith(cset(""));
    EXPECT_TRUE(s.SetEquals(cset("")));
  }
  
  TEST(HashSet, UnionWith_NoOverlap)  {
    HashSet<char> s(cset("123"));
    s.UnionWith(cset("456"));
    EXPECT_TRUE(s.SetEquals(cset("123456")));
  }
  
  
  TEST(HashSet, UnionWith_Overlap) {
    HashSet<char> s(cset("123"));
    s.UnionWith(cset("345"));
    EXPECT_TRUE(s.SetEquals(cset("12345")));
  }
  
  TEST(HashSet, UnionWith_EmptyAndNotEmpty) {
    HashSet<char> s(cset(""));
    s.UnionWith(cset("123"));
    EXPECT_TRUE(s.SetEquals(cset("123")));
  }
  
  TEST(HashSet, UnionWith_NotEmptyAndEmpty) {
    HashSet<char> s(cset("123"));
    s.UnionWith(cset(""));
    EXPECT_TRUE(s.SetEquals(cset("123")));
  }
  
  TEST(HashSet, UnionWith_WithComparer) {
    HashSet<Person> set(new NameOnlyComparer());
    set.Add(Person("Mary Jane", "WATSON"));
    set.Add(Person("Peter", "PARKER"));
    set.Add(Person("Gwen", "STACY"));
    set.Add(Person("Harry", "OSBORN"));
    
    HashSet<Person> set2(new NameOnlyComparer());
    set.Add(Person("Ben", "PARKER"));
    set.Add(Person("Norman", "OSBORN"));
    set.Add(Person("May", "PARKER"));
    
    set.UnionWith(set2);
    for (Person p : set) {
      if (p.GetName().Equals("Gwen"))
        EXPECT_TRUE(string("STACY").Equals(p.GetSurname()));
    }
  }
  
  TEST(HashSet, Enumerator_Empty) {
    HashSet<char> s(cset(""));
    HashSet<char>::Enumerator e(s);
    while (e.MoveNext())
      EXPECT_FALSE(true);
  }
  
  TEST(HashSet, Enumerator) {
    HashSet<char> s(cset("123"));
    HashSet<char>::Enumerator e(s);
    
    int32 count[4] = { 0, 0, 0, 0 };
    
    while (e.MoveNext()) {
      int i = e.Current() - '0';
      ASSERT_LE(0, i);
      ASSERT_GT(4, i);
      count[i]++;
    }
    
    EXPECT_EQ(0, count[0]);
    EXPECT_EQ(1, count[1]);
    EXPECT_EQ(1, count[2]);
    EXPECT_EQ(1, count[3]);
  }
  
  TEST(HashSet, EnumeratorCopy) {
    int32 count[4] = { 0, 0, 0, 0 };
    HashSet<char> s(cset("123"));
    HashSet<char>::Enumerator e1(s);
    
    EXPECT_TRUE(e1.MoveNext());
    int i = e1.Current() - '0';
    ASSERT_LE(0, i);
    ASSERT_GT(4, i);
    count[i]++;
    
    HashSet<char>::Enumerator e2(e1);
    
    while (e2.MoveNext()) {
      int i = e2.Current() - '0';
      ASSERT_LE(0, i);
      ASSERT_GT(4, i);
      count[i]++;
    }
    
    EXPECT_EQ(0, count[0]);
    EXPECT_EQ(1, count[1]);
    EXPECT_EQ(1, count[2]);
    EXPECT_EQ(1, count[3]);
  }
  
}
