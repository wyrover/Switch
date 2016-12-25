#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {
  
  TEST(SortedDictionaryTest, Constructor) {
    SortedDictionary<string,int32> dic;
    EXPECT_EQ(0, dic.Count);
  }
  
  TEST(SortedDictionaryTest, ConstructorIDictionary) {
    Dictionary<string, int32> source;
    source["tic et tac"] = 2;
    source["les nains"] = 7;
    source["tortues ninja"] = 4;
    source["mousquetaires"] = 3;
    SortedDictionary<string,int32> dic(source);
    EXPECT_EQ(4,dic.Count);
    EXPECT_EQ(2,dic["tic et tac"]);
    EXPECT_EQ(7,dic["les nains"]);
    EXPECT_EQ(4,dic["tortues ninja"]);
    EXPECT_EQ(3,dic["mousquetaires"]);
  }
  
  TEST(SortedDictionaryTest, ConstructorIDictionaryEmpty) {
    SortedDictionary<string, int32> source;
    SortedDictionary<string, int32> dic(source);
    EXPECT_EQ(0, dic.Count);
  }
  
  TEST(SortedDictionaryTest, AddKVP) {
    SortedDictionary<string,string> dic;
    dic.Add(KeyValuePair<string,string>("un","one"));
    dic.Add(KeyValuePair<string,string>("deux","two"));
    dic.Add(KeyValuePair<string,string>("trois","three"));
    dic.Add(KeyValuePair<string,string>("quatre","four"));
    dic.Add(KeyValuePair<string,string>("cinq","five"));
    
    EXPECT_TRUE(dic["un"].Equals("one"));
    EXPECT_TRUE(dic["deux"].Equals("two"));
    EXPECT_TRUE(dic["trois"].Equals("three"));
    EXPECT_TRUE(dic["quatre"].Equals("four"));
    EXPECT_TRUE(dic["cinq"].Equals("five"));
  }
  
  TEST(SortedDictionaryTest, GetValues) {
    string sorted[5] = {"five","two", "four","three","one"};
    SortedDictionary<string,string> dic;
    
    SortedDictionary<string, string>::ValueCollection values_empty = dic.Values;
    EXPECT_EQ(0,values_empty.Count);
    
    dic.Add("quatre","four");
    dic.Add("deux","two");
    dic.Add("un","one");
    dic.Add("trois","three");
    dic.Add("cinq","five");
    
    SortedDictionary<string, string>::ValueCollection values = dic.Values;
    EXPECT_EQ(5,values.Count);
    
    int k=0;
    for (string s : values)
      EXPECT_TRUE(sorted[k++].Equals(s));
  }
  
  TEST(SortedDictionaryTest, GetKeys) {
    string sorted[5] = {"cinq","deux","quatre","trois","un"};
    SortedDictionary<string,string> dic;
    
    SortedDictionary<string, string>::KeyCollection keys_empty = dic.Keys;
    EXPECT_EQ(0,keys_empty.Count);
    
    dic.Add("quatre","four");
    dic.Add("deux","two");
    dic.Add("un","one");
    dic.Add("trois","three");
    dic.Add("cinq","five");
    
    SortedDictionary<string, string>::KeyCollection keys = dic.Keys;
    EXPECT_EQ(5,keys.Count);
    
    int k=0;
    for (string s : keys)
      EXPECT_TRUE(sorted[k++].Equals(s));
  }
  
  TEST(SortedDictionaryTest, Enumerator) {
    string sorted[5] = {"cinq","deux","quatre","trois","un"};
    SortedDictionary<string,string> dic;
    
    dic.Add("quatre","four");
    dic.Add("deux","two");
    dic.Add("un","one");
    dic.Add("trois","three");
    dic.Add("cinq","five");
    
    int k=0;
    SortedDictionary<string,string>::Enumerator e(dic);
    while (e.MoveNext()) {
      KeyValuePair<string,string> pair(e.Current);
      EXPECT_EQ(sorted[k++], pair.Key());
    }
  }
  
  TEST(SortedDictionaryTest, Enumerator_Empty) {
    SortedDictionary<string,string> dic;
    
    SortedDictionary<string,string>::Enumerator e(dic);
    while (e.MoveNext()) {
      EXPECT_FALSE(true);
    }
  }
  
  TEST(SortedDictionaryTest, Enumerator_Copy) {
    string sorted[5] = {"cinq","deux","quatre","trois","un"};
    SortedDictionary<string,string> dic;
    
    dic.Add("quatre","four");
    dic.Add("deux","two");
    dic.Add("un","one");
    dic.Add("trois","three");
    dic.Add("cinq","five");
    
    SortedDictionary<string,string>::Enumerator e1(dic);
    e1.MoveNext();
    SortedDictionary<string,string>::Enumerator e2(e1);
    
    int k=1;
    while (e1.MoveNext()) {
      KeyValuePair<string,string> pair(e1.Current);
      EXPECT_EQ(sorted[k++], pair.Key());
    }
    
    k=1;
    while (e2.MoveNext()) {
      KeyValuePair<string,string> pair(e2.Current);
      EXPECT_EQ(sorted[k++], pair.Key());
    }
  }
  
  
  class SortedDictionaryUT2 : public testing::Test {
    
  protected:
    SortedDictionary<string, string> dic;
    
    void SetUp() override {
      dic.Add("un","one");
      dic.Add("deux","two");
      dic.Add("trois","three");
      dic.Add("quatre","four");
      dic.Add("cinq","five");
    }
    
    void TearDown() override {
    }
  };
  
  TEST_F(SortedDictionaryUT2, AddKV) {
    EXPECT_TRUE(dic["un"].Equals("one"));
    EXPECT_TRUE(dic["deux"].Equals("two"));
    EXPECT_TRUE(dic["trois"].Equals("three"));
    EXPECT_TRUE(dic["quatre"].Equals("four"));
    EXPECT_TRUE(dic["cinq"].Equals("five"));
  }
  
  TEST_F(SortedDictionaryUT2, Clear) {
    dic.Clear();
    EXPECT_EQ(0, dic.Count);
    EXPECT_NE(1, dic.Count);
  }
  
  TEST_F(SortedDictionaryUT2, ContainsKVP) {
    EXPECT_TRUE(dic.Contains(KeyValuePair<string, string>("un","one") ));
    EXPECT_TRUE(dic.Contains(KeyValuePair<string, string>("deux","two") ));
    EXPECT_TRUE(dic.Contains(KeyValuePair<string, string>("trois","three") ));
    EXPECT_TRUE(dic.Contains(KeyValuePair<string, string>("quatre","four") ));
    EXPECT_TRUE(dic.Contains(KeyValuePair<string, string>("cinq","five") ));
    
    EXPECT_FALSE(dic.Contains(KeyValuePair<string, string>("un","five") ));
    EXPECT_FALSE(dic.Contains(KeyValuePair<string, string>("deux","three") ));
    EXPECT_FALSE(dic.Contains(KeyValuePair<string, string>("coco","five") ));
  }
  
  TEST_F(SortedDictionaryUT2, TryGetValue) {
    string s1 = "nothing";
    string s2 = "nothing";
    
    dic.TryGetValue("deux",s1);
    EXPECT_TRUE(s1.Equals("two"));
    dic.TryGetValue("dos",s2);
    EXPECT_TRUE(s2.Equals(string()));
  }
  
  TEST_F(SortedDictionaryUT2, Remove) {
    EXPECT_TRUE(dic.Remove("deux"));
    EXPECT_FALSE(dic.Remove("deux"));
    EXPECT_FALSE(dic.Remove(""));
    EXPECT_FALSE(dic.Remove("ni ! ni !"));
  }
  
  TEST_F(SortedDictionaryUT2, RemoveKVP) {
    EXPECT_TRUE(dic.Remove(KeyValuePair<string, string>("deux","two")));
    EXPECT_FALSE(dic.Remove(KeyValuePair<string, string>("deux","two")));
    EXPECT_FALSE(dic.Remove(KeyValuePair<string, string>("deux","duo")));
    EXPECT_FALSE(dic.Remove(KeyValuePair<string, string>("ni !","two")));
    EXPECT_FALSE(dic.Remove(KeyValuePair<string, string>("","")));
    EXPECT_FALSE(dic.Remove(KeyValuePair<string, string>()));
  }
  
  TEST_F(SortedDictionaryUT2, Properties) {
    EXPECT_FALSE(dic.IsSynchronized);
  }
  
}