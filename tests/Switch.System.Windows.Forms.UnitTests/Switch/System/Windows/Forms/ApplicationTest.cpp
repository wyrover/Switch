#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>
#include <Switch/System/Windows/Forms/Application.hpp>

using namespace System::Windows::Forms;
using namespace TUnit;

namespace SwitchUnitTests {
  class ApplicationTest : public TestFixture {
  protected:
    void EnableVisualStyles() {
    }
  };
  
  _add_test (ApplicationTest, EnableVisualStyles)
}
