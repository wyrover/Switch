#include <Pcf/Is.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  class PcfLockTest : public TestFixture {
  protected:
    void Thread() {
      string s;
      std::thread t1(pcf_delegate {
        pcf_lock(s) {
          for (int i = 0; i < 500; i++)
            s += '1';
        }
      });
      std::thread t2(pcf_delegate {
        pcf_lock(s) {
          for (int i = 0; i < 500; i++)
            s += '2';
        }
      });
      
      if (t1.joinable())
        t1.join();
      if (t2.joinable())
        t2.join();
      
      char32 o = 0;
      int32 i = 0;
      for (char32 c : s) {
        if (o == 0) o = c;
        Assert::IsFalse(++i < 500 && o != c, pcf_current_information);
      }
      
    }
  };
  
  pcf_test(PcfLockTest, Thread)
}
