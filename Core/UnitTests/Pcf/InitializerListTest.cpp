#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class InitializerListTest : public TestFixture {
  protected:
    void CreateCollectionWithInitializerList() {
      struct MyCollection {
        MyCollection(InitializerList<int> il) : values(il) {}
        Array<int> values;
      } collection = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      const int results[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
      
      int32 i = 0;
      for (const auto& value : collection.values)
        Assert::AreEqual(value, results[i++], pcf_current_information);
      Assert::AreEqual(10, i, pcf_current_information);
    }

    void CreateCollectionWithInitializerListThenIterateIt() {
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
        Assert::AreEqual(value, results[i++], pcf_current_information);
      Assert::AreEqual(10, i, pcf_current_information);
    }
  };
  
  pcf_test(InitializerListTest, CreateCollectionWithInitializerList)
  pcf_test(InitializerListTest, CreateCollectionWithInitializerListThenIterateIt)
}
