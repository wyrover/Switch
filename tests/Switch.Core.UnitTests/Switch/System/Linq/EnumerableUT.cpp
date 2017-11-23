#include <Switch/System/Collections/ArrayList.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/Math.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace {
  static bool IsApproximatelyEquals(double value1, double value2, double epsilon) {
    // If they are equal anyway, just return True.
    if (value1 == value2)
      return true;
      
    // Handle NaN, Infinity.
    if (Double::IsInfinity(value1) || Double::IsNaN(value1))
      return value1 == value2;
    else if (Double::IsInfinity(value2) || Double::IsNaN(value2))
      return value1 == value2;
      
    // Handle zero to avoid division by zero
    double divisor = Math::Max(value1, value2);
    if (divisor == 0.0)
      divisor = Math::Min(value1, value2);
      
    return Math::Abs(value1 - value2) / divisor <= epsilon;
  }
  
  class Pet : public object, public IComparable {
  public:
    Pet() : age(0) {}
    Pet(const Pet& pet) : name(pet.name), age(pet.age), vaccinated(pet.vaccinated) {}
    Pet(const string& name, int age, bool vaccinated) : name(name), age(age), vaccinated(vaccinated) {}
    const string& Name() const { return name; }
    int Age() const { return age; }
    bool IsVaccinated() const { return vaccinated; }
    
    bool Equals(const object& other) const override {
      return is<Pet>(other) && name == as<Pet>(other).name && age == as<Pet>(other).age && vaccinated == as<Pet>(other).vaccinated;
    }
    
    int32 GetHashCode() const override {
      return name.GetHashCode() ^ age ^ (int)vaccinated;
    }
    
    int32 CompareTo(const IComparable& other) const override {
      if (!is<Pet>(other))
        return 1;
        
      int sumOther = as<Pet>(other).age + as<Pet>(other).name.Length();
      int sumThis = age + name.Length();
      
      if (sumOther > sumThis)
        return -1;
        
      if (sumOther == sumThis)
        return 0;
        
      return 1;
    }
    
    String ToString() const override {
      return String::Format("{{{0}, {1}, {2}}}", this->name, this->age, this - vaccinated);
    }
    
  private:
    string name;
    int age;
    bool vaccinated;
  };
  
  TEST(EnumerableTest, Agregate1) {
    ASSERT_EQ("dog lazy the over jumps fox brown quick the", string("the quick brown fox jumps over the lazy dog").Split(' ').Agregate([](const string & value, const string & next) { return next + " " + value; }));
  }
  
  TEST(EnumerableTest, Agregate2) {
    int32 result = Array<int32> {4, 8, 8, 3, 9, 0, 7, 8, 2} .Agregate<int32>(10, [](const int32 & total, const int32 & next) { return next % 2 == 0 ? total + 1 : total; });
    ASSERT_EQ(16, result);
  }
  
  TEST(EnumerableTest, Agregate3) {
    string result = Array<string> {"apple", "mango", "orange", "passionfruit", "grape"} .Agregate<string, string>(string("bananas"), [](const string & longest, const string & next) { return next.Length() > longest.Length() ? next : longest; }, [](const string & str) { return str.ToUpper(); });
    ASSERT_EQ("PASSIONFRUIT", result);
    result = Array<string> {"GREEN", "YELLOW", "BLUE", "BROWN", "MAGENTA"} .Agregate<string, string>(string("RED"), [](const string & shortest, const string & next) { return next.Length() < shortest.Length() ? next : shortest; }, [](const string & str) { return str.ToLower(); });
    ASSERT_EQ("red", result);
  }
  
  TEST(EnumerableTest, All) {
    ASSERT_FALSE(Array<Pet>({Pet("Barley", 8, true), Pet("Boots", 4, false), Pet("Whiskers", 1, false)}).All([](const Pet & pet) { return pet.Name().StartsWith("B"); }));
  }
  
  TEST(EnumerableTest, Any1) {
    ASSERT_TRUE(List<int32>({1, 2, 3, 4, 5}).Any());
  }
  
  TEST(EnumerableTest, Any2) {
    ASSERT_TRUE(Array<Pet>({Pet("Barley", 8, true), Pet("Boots", 4, false), Pet("Whiskers", 1, false)}).Any([](const Pet & pet) { return pet.IsVaccinated() == false && pet.Age() > 1; }));
    ASSERT_FALSE(Array<Pet>({Pet("Barley", 8, true), Pet("Boots", 4, false), Pet("Whiskers", 1, false)}).Any([](const Pet & pet) { return pet.IsVaccinated() == false && pet.Age() > 4; }));
  }
  
  TEST(EnumerableTest, AverageInt32) {
    ASSERT_TRUE(IsApproximatelyEquals(77.6f, Array<int>({78, 92, 100, 37, 81}).Average(), 0.1f));
  }
  
  TEST(EnumerableTest, Cast) {
    Collections::ArrayList al;
    al.Add("Barley");
    al.Add("Boots");
    al.Add("Whiskers");
    refptr<IEnumerable<String>> enumerable = al.Cast<String>();
    Enumerator<String> enumerator = enumerable->GetEnumerator();
    ASSERT_TRUE(enumerator.MoveNext());
    ASSERT_EQ("Barley", enumerator.Current());
    ASSERT_TRUE(enumerator.MoveNext());
    ASSERT_EQ("Boots", enumerator.Current());
    ASSERT_TRUE(enumerator.MoveNext());
    ASSERT_EQ("Whiskers", enumerator.Current());
  }
  
  TEST(EnumerableTest, Concat) {
    Array<int> a1 = {1, 2};
    Array<int> a2 = {3, 4};
    refptr<IEnumerable<int>> enumerable = a1.Concat(a2);
    Enumerator<int> enumerator = enumerable->GetEnumerator();
    ASSERT_TRUE(enumerator.MoveNext());
    ASSERT_EQ(1, enumerator.Current());
    ASSERT_TRUE(enumerator.MoveNext());
    ASSERT_EQ(2, enumerator.Current());
    ASSERT_TRUE(enumerator.MoveNext());
    ASSERT_EQ(3, enumerator.Current());
    ASSERT_TRUE(enumerator.MoveNext());
    ASSERT_EQ(4, enumerator.Current());
  }
  
  TEST(EnumerableTest, Max) {
    ASSERT_EQ("Barley", List<Pet>({Pet("Barley", 8, true), Pet("Boots", 4, false), Pet("Whiskers", 1, false)}).Max().Name());
  }
  
  TEST(EnumerableTest, Min) {
    ASSERT_EQ("Boots",  List<Pet>({Pet("Barley", 8, true), Pet("Boots", 4, false), Pet("Whiskers", 1, false)}).Min().Name());
  }
}

