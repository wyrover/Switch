#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>
#include <Pcf/System/Windows/Forms/Application.h>

using namespace System::Windows::Forms;
using namespace TUnit;

namespace PcfUnitTests {
  class ApplicationTest : public TestFixture {
  protected:
    void EnableVisualStyles() {
    }
  };
  
  pcf_test(ApplicationTest, EnableVisualStyles)
}
