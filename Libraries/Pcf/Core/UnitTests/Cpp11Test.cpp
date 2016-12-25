#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class Cpp11Test : public TestFixture {
  protected:
    void Version() {
#if !_WIN32
      Assert::GreaterOrEqual(__cplusplus, 201103, pcf_current_information);
#else
      Assert::GreaterOrEqual(__cplusplus, 199711L, pcf_current_information);
#endif
    }
    
    void Auto() {
      String str = "Test string";
      const char chars[] = "Test string";
      
      int32 i = 0;
      for (auto c : str) {
        Assert::AreEqual(c, (unsigned)chars[i++], pcf_current_information);
      }
    }
  };
  
  pcf_test(Cpp11Test, Version);
  pcf_test(Cpp11Test, Auto);
}
