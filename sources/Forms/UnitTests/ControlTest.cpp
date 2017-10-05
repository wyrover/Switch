#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>
#include <Switch/System/Windows/Forms/Control.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace TUnit;

namespace SwitchUnitTests {
  class ControlTest : public TestFixture {
  protected:
    void DefaultConstructor() {
      Control control;
      Assert::AreEqual(Control::DefaultBackColor, control.BackColor);
      Assert::AreEqual(0, control.Bottom);
      Assert::AreEqual(Rectangle(0, 0, 0, 0), control.Bounds);
      Assert::AreEqual(Size(0, 0), control.ClientSize);
      Assert::IsEmpty(control.Controls());
      Assert::AreEqual(Control::DefaultForeColor, control.ForeColor);
      Assert::AreEqual(0, control.Height);
      Assert::AreEqual(0, control.Left);
      Assert::IsNull(control.Parent());
      Assert::IsEmpty(control.Text);
      Assert::AreEqual(0, control.Top);
      Assert::AreEqual(0, control.Width);
    }
    
    void SetBackColorToAColor() {
      Control control;
      Color newBackColor;
      control.BackColorChanged += _delegate(const object& sender, const EventArgs& e) {
        newBackColor = as<Control>(sender).BackColor;
      };
      
      control.BackColor = Color::SpringGreen;
      Assert::AreEqual(Color::SpringGreen, control.BackColor);
      
      Assert::AreEqual(Color::SpringGreen, newBackColor);
    }
    
    void SetForeColorToAColor() {
      Control control;
      Color newForeColor;
      control.ForeColorChanged += _delegate(const object& sender, const EventArgs& e) {
        newForeColor = as<Control>(sender).ForeColor;
      };
      
      control.ForeColor = Color::White;
      Assert::AreEqual(Color::White, control.ForeColor);
      Assert::AreEqual(Color::White, newForeColor);
    }
    
    /*
    void SetParentToControl() {
      Control parent;
      Control control;
      ref<Control> newParent;
      control.ParentChanged += _delegate(const object& sender, const EventArgs& e) {
        newParent = as<Control>(sender).Parent;
      };
      
      control.Parent = parent;
      Assert::AreEqual(parent, control.Parent);
      Assert::AreEqual(parent, newParent);
    }*/
  };
  
  _test (ControlTest, DefaultConstructor)
  _test (ControlTest, SetBackColorToAColor)
  _test (ControlTest, SetForeColorToAColor)
  //_test (ControlTest, SetParentToControl)
}
