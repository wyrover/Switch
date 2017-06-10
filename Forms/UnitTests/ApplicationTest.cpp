#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>
#include <Pcf/System/Windows/Forms/Application.hpp>

using namespace System::Windows::Forms;
using namespace TUnit;

namespace PcfUnitTests {
  class ApplicationTest : public TestFixture {
  protected:
    void EnableVisualStyles() {
    }
  };
  
  pcf_test (ApplicationTest, EnableVisualStyles)
}
