#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>
#include <Pcf/System/Windows/Forms/Application.h>

using namespace System::Windows::FormsD;
using namespace TUnit;

namespace PcfUnitTests {
  class ApplicationTest : public TestFixture {
  protected:
    void EnableVisualStyles() {
      Assert::DoesNotThrows([] {Application::EnableVisualStyles();}, pcf_current_information);
    }
  };
  
  pcf_test(ApplicationTest, EnableVisualStyles)
}
