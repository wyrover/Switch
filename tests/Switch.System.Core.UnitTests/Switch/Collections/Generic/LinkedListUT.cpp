#include <Switch/System/Collections/Generic/LinkedList.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections;
using namespace TUnit;

namespace {

  class LinkedList : public testing::Test {
  protected:
    void SetUp() override {
      string names[] = {
        "Tyrannosaurus",  // 0
        "Compsognathus",  // 1
        "Amargasaurus",   // 2
        "Oviraptor",      // 3
        "Velociraptor",   // 4
        "Deinonychus",    // 5
        "Dilophosaurus",  // 6
        "Gallimimus",     // 7
        "Triceratops"     // 8
      };
      array = Array<string>(names);
    }
    
    Array<string> array;
  };
  
  
  template<typename T>
  void TestValues3(const Generic::LinkedList<T>& list, T v1, T v2, T v3) {
    int i = 0;
    for(T item : list) {
      if(i == 0)  EXPECT_EQ(v1, item);
      if(i == 1)  EXPECT_EQ(v2, item);
      if(i == 2)  EXPECT_EQ(v3, item);
      i++;
    }
  }
  
  TEST_F(LinkedList, SByte) {
    Generic::LinkedList<sbyte>  list;
    EXPECT_EQ(0, list.Count);
    list.Add(-1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<sbyte>(list, -1, 2, 3);
    
  }
  
  TEST_F(LinkedList, Int16) {
    Generic::LinkedList<int16>  list;
    EXPECT_EQ(0, list.Count);
    list.Add(-1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<int16>(list, -1, 2, 3);
  }
  
  TEST_F(LinkedList, Int32) {
    Generic::LinkedList<int32>  list;
    EXPECT_EQ(0, list.Count);
    list.Add(-1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<int32>(list, -1, 2, 3);
  }
  
  TEST_F(LinkedList, Int64) {
    Generic::LinkedList<int64>  list;
    EXPECT_EQ(0, list.Count);
    list.Add(-1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<int64>(list, -1, 2, 3);
  }
  
  TEST_F(LinkedList, Byte) {
    Generic::LinkedList<byte>   list;
    EXPECT_EQ(0, list.Count);
    list.Add(1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<byte>(list, 1, 2, 3);
  }
  
  TEST_F(LinkedList, UInt16) {
    Generic::LinkedList<uint16> list;
    EXPECT_EQ(0, list.Count);
    list.Add(1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<uint16>(list, 1, 2, 3);
  }
  
  TEST_F(LinkedList, UInt32) {
    Generic::LinkedList<uint32> list;
    EXPECT_EQ(0, list.Count);
    list.Add(1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<uint32>(list, 1, 2, 3);
  }
  
  TEST_F(LinkedList, UInt64) {
    Generic::LinkedList<uint64> list;
    EXPECT_EQ(0, list.Count);
    list.Add(1); list.Add(2); list.Add(3);
    EXPECT_EQ(3, list.Count);
    TestValues3<uint64>(list, 1, 2, 3);
  }
  
  TEST_F(LinkedList, Single) {
    Generic::LinkedList<float> list;
    EXPECT_EQ(0, list.Count);
    list.Add(-1.0f); list.Add(2.0f); list.Add(3.0f);
    EXPECT_EQ(3, list.Count);
    TestValues3<float>(list, -1.0f, 2.0f, 3.0f);
  }
  
  TEST_F(LinkedList, Double) {
    Generic::LinkedList<double> list;
    EXPECT_EQ(0, list.Count);
    list.Add(-1.0); list.Add(2.0); list.Add(3.0);
    EXPECT_EQ(3, list.Count);
    TestValues3<double>(list, -1.0, 2.0, 3.0);
  }
  
  TEST_F(LinkedList, String) {
    Generic::LinkedList<string> list;
    EXPECT_EQ(0, list.Count);
    list.Add("1"); list.Add("2"); list.Add("3");
    EXPECT_EQ(3, list.Count);
    TestValues3<string>(list, "1", "2", "3");
  }
  
  TEST_F(LinkedList, SpString) {
    Generic::LinkedList< refptr<String>> list;
    EXPECT_EQ(0, list.Count);
    list.Add(new String("1")); list.Add(new String("2")); list.Add(new String("3"));
    EXPECT_EQ(3, list.Count);
    int i = 0;
    for(refptr<string> item : list) {
      if(i == 0) EXPECT_EQ("1", *item);
      if(i == 1) EXPECT_EQ("2", *item);
      if(i == 2) EXPECT_EQ("3", *item);
      i++;
    }
  }
  
  TEST_F(LinkedList, CtorICollection) {
    Generic::LinkedList<string> list(array);
    EXPECT_EQ(9, list.Count);
    
    int i = 0;
    for(string s : list)
      EXPECT_TRUE(array[i++].Equals(s));
  }
  
  TEST_F(LinkedList, CtorCopy) {
    Generic::LinkedList<string> listOrig(array);
    Generic::LinkedList<string> list(listOrig);
    EXPECT_EQ(9, list.Count);
    
    int i = 0;
    for(string s : list)
      EXPECT_TRUE(array[i++].Equals(s));
  }
  
  TEST_F(LinkedList, AddRange) {
    string names[] = {"Tyrannosaurus", "Compsognathus", "Amargasaurus", "Oviraptor",
        "Velociraptor", "Deinonychus", "Dilophosaurus", "Gallimimus", "Triceratops"
      };
      
    Array<string> array1(names, 3);
    Array<string> array2(&names[3], 6);
    Generic::LinkedList<string> list(array1);
    list.AddRange(array2);
    
    EXPECT_EQ(9, list.Count);
    
    int i = 0;
    for(string s : list)
      EXPECT_TRUE(names[i++].Equals(s));
  }
  
  TEST_F(LinkedList, Contains) {
    Generic::LinkedList<string> list(array);
    for(string s : array)
      EXPECT_TRUE(list.Contains(s));
      
    EXPECT_FALSE(list.Contains(""));
    EXPECT_FALSE(list.Contains(" "));
    EXPECT_FALSE(list.Contains("ok"));
    EXPECT_FALSE(list.Contains("test"));
    EXPECT_FALSE(list.Contains("a long string to test 0000000000000000000000000000000000000000000000000000 !!!!!!!!"));
  }
  
  TEST_F(LinkedList, CopyTo1) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(9);
    list.CopyTo(dest);
    int i = 0;
    for(string s : list)
      EXPECT_TRUE(array[i++].Equals(s));
  }
  
  TEST_F(LinkedList, CopyTo2)  {
    Generic::LinkedList<string> list(array);
    Array<string> dest(8);
    EXPECT_THROW(list.CopyTo(dest), ArgumentException);
  }
  
  TEST_F(LinkedList, CopyTo3) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(10);
    list.CopyTo(dest);
    
    int i = 0;
    for(string s : list)
      EXPECT_TRUE(array[i++].Equals(s));
  }
  
  TEST_F(LinkedList, CopyTo4) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(10);
    dest[0] = "empty";
    list.CopyTo(dest, 1);
    EXPECT_EQ("empty", dest[0]);
    EXPECT_EQ("Tyrannosaurus", dest[1]);
    EXPECT_EQ("Compsognathus", dest[2]);
    EXPECT_EQ("Amargasaurus", dest[3]);
    EXPECT_EQ("Oviraptor", dest[4]);
    EXPECT_EQ("Velociraptor", dest[5]);
    EXPECT_EQ("Deinonychus", dest[6]);
    EXPECT_EQ("Dilophosaurus", dest[7]);
    EXPECT_EQ("Gallimimus", dest[8]);
    EXPECT_EQ("Triceratops", dest[9]);
  }
  
  TEST_F(LinkedList, CopyTo5) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(18);
    list.CopyTo(dest, 0);
    list.CopyTo(dest, 9);
    EXPECT_EQ("Tyrannosaurus", dest[0]);
    EXPECT_EQ("Compsognathus", dest[1]);
    EXPECT_EQ("Amargasaurus", dest[2]);
    EXPECT_EQ("Oviraptor", dest[3]);
    EXPECT_EQ("Velociraptor", dest[4]);
    EXPECT_EQ("Deinonychus", dest[5]);
    EXPECT_EQ("Dilophosaurus", dest[6]);
    EXPECT_EQ("Gallimimus", dest[7]);
    EXPECT_EQ("Triceratops", dest[8]);
    EXPECT_EQ("Tyrannosaurus", dest[9]);
    EXPECT_EQ("Compsognathus", dest[10]);
    EXPECT_EQ("Amargasaurus", dest[11]);
    EXPECT_EQ("Oviraptor", dest[12]);
    EXPECT_EQ("Velociraptor", dest[13]);
    EXPECT_EQ("Deinonychus", dest[14]);
    EXPECT_EQ("Dilophosaurus", dest[15]);
    EXPECT_EQ("Gallimimus", dest[16]);
    EXPECT_EQ("Triceratops", dest[17]);
  }
  
  TEST_F(LinkedList, CopyTo6) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(10);
    list.CopyTo(0, dest, 0, 9);
    
    EXPECT_EQ("Tyrannosaurus", dest[0]);
    EXPECT_EQ("Compsognathus", dest[1]);
    EXPECT_EQ("Amargasaurus", dest[2]);
    EXPECT_EQ("Oviraptor", dest[3]);
    EXPECT_EQ("Velociraptor", dest[4]);
    EXPECT_EQ("Deinonychus", dest[5]);
    EXPECT_EQ("Dilophosaurus", dest[6]);
    EXPECT_EQ("Gallimimus", dest[7]);
    EXPECT_EQ("Triceratops", dest[8]);
    EXPECT_EQ("", dest[9]);
  }
  
  TEST_F(LinkedList, CopyTo7) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(10);
    list.CopyTo(0, dest, 1, 9);
    
    EXPECT_EQ("Tyrannosaurus", dest[1]);
    EXPECT_EQ("Compsognathus", dest[2]);
    EXPECT_EQ("Amargasaurus", dest[3]);
    EXPECT_EQ("Oviraptor", dest[4]);
    EXPECT_EQ("Velociraptor", dest[5]);
    EXPECT_EQ("Deinonychus", dest[6]);
    EXPECT_EQ("Dilophosaurus", dest[7]);
    EXPECT_EQ("Gallimimus", dest[8]);
    EXPECT_EQ("Triceratops", dest[9]);
    EXPECT_EQ("", dest[0]);
  }
  
  TEST_F(LinkedList, CopyTo8) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(10);
    EXPECT_THROW(list.CopyTo(0, dest, 2, 9), ArgumentException);
    EXPECT_THROW(list.CopyTo(1, dest, 0, 9), ArgumentException);
  }
  
  TEST_F(LinkedList, CopyTo9) {
    Generic::LinkedList<string> list(array);
    Array<string> dest(10);
    list.CopyTo(3, dest, 0, 3);
    list.CopyTo(0, dest, 3, 3);
    list.CopyTo(6, dest, 6, 3);
    
    EXPECT_EQ("Tyrannosaurus", dest[3]);
    EXPECT_EQ("Compsognathus", dest[4]);
    EXPECT_EQ("Amargasaurus", dest[5]);
    EXPECT_EQ("Oviraptor", dest[0]);
    EXPECT_EQ("Velociraptor", dest[1]);
    EXPECT_EQ("Deinonychus", dest[2]);
    EXPECT_EQ("Dilophosaurus", dest[6]);
    EXPECT_EQ("Gallimimus", dest[7]);
    EXPECT_EQ("Triceratops", dest[8]);
  }
  
  using MatcherSignature = bool (*)(const string& s);
  
  bool Match(const string& s) {
    return s.Length() > 1 && s[0] == 'D';
  }
  
  bool MatchNegative(const string& s) {
    return s.Length() > 1 && s[0] == 'Z';
  }
  
  struct Matcher : public Object {
  public:
    bool MemberMatch(const string& s) {
      return s.Length() > 1 && s[0] == 'O';
    }
    
    bool MemberMatchNegative(const string& s) {
      return s.Length() > 1 && s[0] == 'Y';
    }
  };
  
  TEST_F(LinkedList, Exists) {
    Generic::LinkedList<string> list(array);
    EXPECT_TRUE(list.Exists(Match));
    EXPECT_FALSE(list.Exists(MatchNegative));
    
    EXPECT_TRUE(list.Exists(Predicate<const string&>(Matcher(), &Matcher::MemberMatch)));
    EXPECT_FALSE(list.Exists(Predicate<const string&>(Matcher(), &Matcher::MemberMatchNegative)));
  }
  
  TEST_F(LinkedList, Find) {
    Generic::LinkedList<string> list(array);
    EXPECT_EQ("Deinonychus", list.Find(Match));
    EXPECT_EQ("", list.Find(MatchNegative));
    
    EXPECT_EQ("Oviraptor", list.Find(Predicate<const string&>(Matcher(), &Matcher::MemberMatch)));
    EXPECT_EQ("", list.Find(Predicate<const string&>(Matcher(), &Matcher::MemberMatchNegative)));
  }
  
  TEST_F(LinkedList, FindAll) {
    Generic::LinkedList<string> list(array);
    Generic::LinkedList<string> results;
    results = list.FindAll(Match);
    EXPECT_EQ(2, results.Count);
    int i = 0;
    for(string s : results) {
      if(i == 0) EXPECT_EQ("Deinonychus", s);
      if(i == 1) EXPECT_EQ("Dilophosaurus", s);
      i++;
    }
    
    results = list.FindAll(MatchNegative);
    EXPECT_EQ(0, results.Count);
    
    results = list.FindAll(Predicate<const string&>(Matcher(), &Matcher::MemberMatch));
    EXPECT_EQ(1, results.Count);
    for(string s : results)
      EXPECT_EQ("Oviraptor", s);
      
    results = list.FindAll(Predicate<const string&>(Matcher(), &Matcher::MemberMatchNegative));
    EXPECT_EQ(0, results.Count);
  }
  
  TEST_F(LinkedList, FindIndex) {
    Generic::LinkedList<string> list(array);
    EXPECT_EQ(5, list.FindIndex(Match));
    EXPECT_EQ(6, list.FindIndex(6, Match));
    EXPECT_EQ(-1, list.FindIndex(MatchNegative));
    EXPECT_EQ(-1, list.FindIndex(0, 4, Match));
    EXPECT_EQ(-1, list.FindIndex(1, 3, Match));
    EXPECT_EQ(-1, list.FindIndex(2, 2, Match));
    EXPECT_EQ(-1, list.FindIndex(3, 1, Match));
    
    EXPECT_EQ(3, list.FindIndex(Predicate<const string&>(Matcher(), &Matcher::MemberMatch)));
    EXPECT_THROW(list.FindIndex(-1, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentOutOfRangeException);
    EXPECT_THROW(list.FindIndex(0, -1, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentOutOfRangeException);
    EXPECT_THROW(list.FindIndex(1, 9, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(2, 8, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(3, 7, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(4, 6, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(5, 5, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(6, 4, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(7, 3, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(8, 2, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(9, 1, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_THROW(list.FindIndex(10, 0, Predicate<const string&>(Matcher(), &Matcher::MemberMatch)), ArgumentException);
    EXPECT_EQ(-1, list.FindIndex(Predicate<const string&>(Matcher(), &Matcher::MemberMatchNegative)));
  }
  
  TEST_F(LinkedList, FindLast) {
    Generic::LinkedList<string> list(array);
    EXPECT_EQ("Dilophosaurus", list.FindLast(Match));
    EXPECT_EQ("", list.FindLast(MatchNegative));
    
    EXPECT_EQ("Oviraptor", list.FindLast(Predicate<const string&>(Matcher(), &Matcher::MemberMatch)));
    EXPECT_EQ("", list.FindLast(Predicate<const string&>(Matcher(), &Matcher::MemberMatchNegative)));
  }
  
  TEST_F(LinkedList, FindLastIndex) {
    Generic::LinkedList<string> list(array);
    EXPECT_EQ(6, list.FindLastIndex(Match));
    EXPECT_EQ(6, list.FindLastIndex(6, Match));
    EXPECT_EQ(-1, list.FindLastIndex(MatchNegative));
    EXPECT_EQ(-1, list.FindLastIndex(3, 4, Match));
    EXPECT_EQ(-1, list.FindLastIndex(4, 3, Match));
    EXPECT_EQ(-1, list.FindLastIndex(3, 2, Match));
    EXPECT_EQ(-1, list.FindLastIndex(2, 1, Match));
  }
  
  Generic::List<string> actions;
  void Action(const string& s) {
    actions.Add(s);
  }
  
  TEST_F(LinkedList, ForEach) {
    Generic::LinkedList<string> list(array);
    list.ForEach(Action);
    EXPECT_EQ("Tyrannosaurus", actions[0]);
    EXPECT_EQ("Compsognathus", actions[1]);
    EXPECT_EQ("Amargasaurus", actions[2]);
    EXPECT_EQ("Oviraptor", actions[3]);
    EXPECT_EQ("Velociraptor", actions[4]);
    EXPECT_EQ("Deinonychus", actions[5]);
    EXPECT_EQ("Dilophosaurus", actions[6]);
    EXPECT_EQ("Gallimimus", actions[7]);
    EXPECT_EQ("Triceratops", actions[8]);
  }
  
  TEST_F(LinkedList, GetRange) {
    Generic::LinkedList<string> list(array);
    
    Generic::LinkedList<string> sub = list.GetRange(0, 3);
    EXPECT_EQ(3, sub.Count);
    EXPECT_EQ(0, sub.IndexOf("Tyrannosaurus"));
    EXPECT_EQ(1, sub.IndexOf("Compsognathus"));
    EXPECT_EQ(2, sub.IndexOf("Amargasaurus"));
    
    sub = list.GetRange(6, 3);
    EXPECT_EQ(3, sub.Count);
    EXPECT_EQ(0, sub.IndexOf("Dilophosaurus"));
    EXPECT_EQ(1, sub.IndexOf("Gallimimus"));
    EXPECT_EQ(2, sub.IndexOf("Triceratops"));
    
    sub = list.GetRange(8, 1);
    EXPECT_EQ(0, sub.IndexOf("Triceratops"));
    
    sub = list.GetRange(7, 1);
    EXPECT_EQ(0, sub.IndexOf("Gallimimus"));
    
    EXPECT_THROW(list.GetRange(-1, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(list.GetRange(0, -1), ArgumentOutOfRangeException);
    EXPECT_THROW(list.GetRange(1, 9), ArgumentException);
  }
  
  TEST_F(LinkedList, Propereties) {
    Generic::LinkedList<string> list(array);
    EXPECT_FALSE(list.IsSynchronized);
  }
  
  TEST_F(LinkedList, IndexOf) {
    Generic::LinkedList<string> list(array);
    EXPECT_EQ(-1, list.IndexOf("Zorro"));
    EXPECT_EQ(-1, list.IndexOf(""));
    EXPECT_EQ(0, list.IndexOf("Tyrannosaurus"));
    EXPECT_EQ(5, list.IndexOf("Deinonychus"));
    EXPECT_EQ(8, list.IndexOf("Triceratops"));
    
    EXPECT_THROW(list.IndexOf("Zorro", -1), ArgumentOutOfRangeException);
    EXPECT_EQ(-1, list.IndexOf("Zorro", 0));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 1));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 2));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 3));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 4));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 5));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 6));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 7));
    EXPECT_EQ(-1, list.IndexOf("Zorro", 8));
    EXPECT_THROW(list.IndexOf("Zorro", 9), ArgumentOutOfRangeException);
    
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 0));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 1));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 2));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 3));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 4));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 5));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 6));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 7));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 8));
    
    EXPECT_THROW(list.IndexOf("Zorro", 0, -1), ArgumentOutOfRangeException);
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 0, 1));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 0, 2));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 0, 3));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 0, 4));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 0, 5));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 0, 6));
    
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 1, 1));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 1, 2));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 1, 3));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 1, 4));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 1, 5));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 1, 6));
    
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 0, 1));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 1, 1));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 2, 1));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 3, 1));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 4, 1));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 5, 1));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 6, 1));
    
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 0, 0));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 1, 0));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 2, 0));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 3, 0));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 4, 0));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 5, 0));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 6, 0));
    
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 1));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 2));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 3));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 4));
    EXPECT_EQ(5, list.IndexOf("Deinonychus", 5));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 6));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 7));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus", 8));
    
  }
  
  TEST_F(LinkedList, Insert) {
    Generic::LinkedList<string> list(array);
    list.Insert(0, "Zorro");
    //"Zorro",          // 0
    //"Tyrannosaurus",  // 1
    //"Compsognathus",  // 2
    //"Amargasaurus",   // 3
    //"Oviraptor",      // 4
    //"Velociraptor",   // 5
    //"Deinonychus",    // 6
    //"Dilophosaurus",  // 7
    //"Gallimimus",     // 8
    //"Triceratops"     // 9
    
    EXPECT_EQ(10, list.Count);
    EXPECT_EQ(0, list.IndexOf("Zorro", 0));
    EXPECT_EQ(6, list.IndexOf("Deinonychus"));
    EXPECT_EQ(9, list.IndexOf("Triceratops"));
    
    list.Insert(5, "Derrick");
    //"Zorro",          // 0
    //"Tyrannosaurus",  // 1
    //"Compsognathus",  // 2
    //"Amargasaurus",   // 3
    //"Oviraptor",      // 4
    //"Derrick",        // 5
    //"Velociraptor",   // 6
    //"Deinonychus",    // 7
    //"Dilophosaurus",  // 8
    //"Gallimimus",     // 9
    //"Triceratops"     // 10
    
    EXPECT_EQ(11, list.Count);
    EXPECT_EQ(0, list.IndexOf("Zorro", 0));
    EXPECT_EQ(4, list.IndexOf("Oviraptor"));
    EXPECT_EQ(6, list.IndexOf("Velociraptor"));
    EXPECT_EQ(5, list.IndexOf("Derrick"));
    EXPECT_EQ(7, list.IndexOf("Deinonychus"));
    EXPECT_EQ(10, list.IndexOf("Triceratops"));
    
    list.Insert(11, "Last");
    EXPECT_EQ(10, list.IndexOf("Triceratops"));
    EXPECT_EQ(11, list.IndexOf("Last"));
    
    EXPECT_THROW(list.Insert(13, "Fail"), ArgumentOutOfRangeException);
  }
  
  TEST_F(LinkedList, InsertRange) {
    //todo
  }
  
  TEST_F(LinkedList, LastIndexOf) {
    //todo
  }
  
  TEST_F(LinkedList, Remove) {
    Generic::LinkedList<string> list(array);
    EXPECT_TRUE(list.Remove("Tyrannosaurus"));
    //"Compsognathus",  // 0
    //"Amargasaurus",   // 1
    //"Oviraptor",      // 2
    //"Velociraptor",   // 3
    //"Deinonychus",    // 4
    //"Dilophosaurus",  // 5
    //"Gallimimus",     // 6
    //"Triceratops"     // 7
    
    EXPECT_EQ(8, list.Count);
    EXPECT_EQ(0, list.IndexOf("Compsognathus"));
    EXPECT_EQ(4, list.IndexOf("Deinonychus"));
    EXPECT_EQ(7, list.IndexOf("Triceratops"));
    
    EXPECT_FALSE(list.Remove("Derrick"));
    
    EXPECT_TRUE(list.Remove("Dilophosaurus"));
    EXPECT_FALSE(list.Remove("Dilophosaurus"));
    //"Compsognathus",  // 0
    //"Amargasaurus",   // 1
    //"Oviraptor",      // 2
    //"Velociraptor",   // 3
    //"Deinonychus",    // 4
    //"Gallimimus",     // 5
    //"Triceratops"     // 6
    
    EXPECT_EQ(7, list.Count);
    EXPECT_EQ(-1, list.IndexOf("Dilophosaurus"));
    EXPECT_EQ(0, list.IndexOf("Compsognathus"));
    EXPECT_EQ(6, list.IndexOf("Triceratops"));
    EXPECT_EQ(3, list.IndexOf("Velociraptor"));
    
    EXPECT_TRUE(list.Remove("Triceratops"));
    EXPECT_EQ(6, list.Count);
    EXPECT_EQ(5, list.IndexOf("Gallimimus"));
  }
  
  TEST_F(LinkedList, Remove_PrimitiveType) {
    Generic::LinkedList<int32> list;
    list.Add(3);
    list.Add(-140);
    list.Add(554);
    
    EXPECT_EQ(3, list.Count);
    list.Remove(459);
    EXPECT_EQ(3, list.Count);
    list.Remove(-140);
    EXPECT_EQ(2, list.Count);
  }
  
  TEST_F(LinkedList, RemoveAll) {
    Generic::LinkedList<string> list(array);
    EXPECT_EQ(0, list.RemoveAll(MatchNegative));
    EXPECT_EQ(9, list.Count);
    
    EXPECT_EQ(2, list.RemoveAll(Match));
    //"Tyrannosaurus",  // 0
    //"Compsognathus",  // 1
    //"Amargasaurus",   // 2
    //"Oviraptor",      // 3
    //"Velociraptor",   // 4
    //"Gallimimus",     // 5
    //"Triceratops"     // 6
    EXPECT_EQ(7, list.Count);
    EXPECT_EQ(-1, list.IndexOf("Deinonychus"));
    EXPECT_EQ(-1, list.IndexOf("Dilophosaurus"));
    EXPECT_EQ(0, list.IndexOf("Tyrannosaurus"));
    EXPECT_EQ(4, list.IndexOf("Velociraptor"));
  }
  
  TEST_F(LinkedList, RemoveAt) {
    Generic::LinkedList<string> list(array);
    list.RemoveAt(0);
    //"Compsognathus",  // 0
    //"Amargasaurus",   // 1
    //"Oviraptor",      // 2
    //"Velociraptor",   // 3
    //"Deinonychus",    // 4
    //"Dilophosaurus",  // 5
    //"Gallimimus",     // 6
    //"Triceratops"     // 7
    EXPECT_EQ(8, list.Count);
    list.RemoveAt(7);
    EXPECT_EQ(7, list.Count);
    list.RemoveAt(4);
    EXPECT_EQ(6, list.Count);
    //"Compsognathus",  // 0
    //"Amargasaurus",   // 1
    //"Oviraptor",      // 2
    //"Velociraptor",   // 3
    //"Dilophosaurus",  // 4
    //"Gallimimus",     // 5
    EXPECT_EQ(0, list.IndexOf("Compsognathus"));
    EXPECT_EQ(5, list.IndexOf("Gallimimus"));
    EXPECT_EQ(-1, list.IndexOf("Tyrannosaurus"));
    EXPECT_EQ(-1, list.IndexOf("Deinonychus"));
    EXPECT_THROW(list.RemoveAt(6), ArgumentOutOfRangeException);
    EXPECT_THROW(list.RemoveAt(-1), ArgumentOutOfRangeException);
  }
  
  TEST_F(LinkedList, RemoveRange) {
    //todo
  }
  
  TEST_F(LinkedList, Reverse) {
    //todo
  }
  
  TEST_F(LinkedList, ToArray) {
    Generic::LinkedList<string> list(array);
    Array<string> array2 = list.ToArray();
    int i = 0;
    for(string s : array)
      EXPECT_TRUE(s.Equals(array2[i++]));
      
    list.Clear();
    array2 = list.ToArray();
    EXPECT_EQ(0, array2.Length);
  }
  
  TEST_F(LinkedList, Enumerator) {
    Generic::LinkedList<int32> ints;
    ints.Add(1);
    ints.Add(2);
    ints.Add(3);
    
    Generic::LinkedList<int32>::Enumerator e(ints);
    int expected = 1;
    while(e.MoveNext())
      EXPECT_EQ(expected++, e.Current);
  }
  
  TEST_F(LinkedList, Enumerator_Empty) {
    Generic::LinkedList<int32> ints;
    Generic::LinkedList<int32>::Enumerator e(ints);
    while(e.MoveNext())
      EXPECT_FALSE(true);
  }
  
  TEST_F(LinkedList, Enumerator_Copy) {
    Generic::LinkedList<int32> ints;
    ints.Add(1);
    ints.Add(2);
    ints.Add(3);
    ints.Add(4);
    
    Generic::LinkedList<int32>::Enumerator e1(ints);
    EXPECT_TRUE(e1.MoveNext());
    Generic::LinkedList<int32>::Enumerator e2(e1);
    int expected = 2;
    while(e1.MoveNext())
      EXPECT_EQ(expected++, e1.Current);
      
    expected = 2;
    while(e2.MoveNext())
      EXPECT_EQ(expected++, e2.Current);
  }
  
  
  TEST_F(LinkedList, ReverseEnumerator) {
    Generic::LinkedList<int32> ints;
    ints.Add(1);
    ints.Add(2);
    ints.Add(3);
    
    Generic::LinkedList<int32>::ReverseEnumerator e(ints);
    int expected = 3;
    while(e.MoveNext())
      EXPECT_EQ(expected--, e.Current);
  }
  
  TEST_F(LinkedList, ReverseEnumerator_Empty) {
    Generic::LinkedList<int32> ints;
    Generic::LinkedList<int32>::ReverseEnumerator e(ints);
    while(e.MoveNext())
      EXPECT_FALSE(true);
  }
  
  TEST_F(LinkedList, ReverseEnumerator_Copy) {
    Generic::LinkedList<int32> ints;
    ints.Add(1);
    ints.Add(2);
    ints.Add(3);
    ints.Add(4);
    
    Generic::LinkedList<int32>::ReverseEnumerator e1(ints);
    EXPECT_TRUE(e1.MoveNext());
    Generic::LinkedList<int32>::ReverseEnumerator e2(e1);
    int expected = 3;
    while(e1.MoveNext())
      EXPECT_EQ(expected--, e1.Current);
      
    expected = 3;
    while(e2.MoveNext())
      EXPECT_EQ(expected--, e2.Current);
  }
  
}
