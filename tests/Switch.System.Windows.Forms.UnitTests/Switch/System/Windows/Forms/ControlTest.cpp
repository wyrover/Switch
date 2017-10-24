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
      Assert::AreEqual(Control::DefaultBackColor, control.BackColor, _caller);
      Assert::AreEqual(0, control.Bottom, _caller);
      Assert::AreEqual(Rectangle(0, 0, 0, 0), control.Bounds, _caller);
      Assert::AreEqual(Size(0, 0), control.ClientSize, _caller);
      Assert::IsEmpty(control.Controls(), _caller);
      Assert::AreEqual(Control::DefaultForeColor, control.ForeColor, _caller);
      Assert::AreEqual(0, control.Height, _caller);
      Assert::AreEqual(0, control.Left, _caller);
      Assert::IsNull(control.Parent(), _caller);
      Assert::IsEmpty(control.Text, _caller);
      Assert::AreEqual(0, control.Top, _caller);
      Assert::AreEqual(0, control.Width, _caller);
    }
    
    void SetBackColorToAColor() {
      Control control;
      Color newBackColor;
      control.BackColorChanged += _delegate(const object& sender, const EventArgs& e) {
        newBackColor = as<Control>(sender).BackColor;
      };
      
      control.BackColor = Color::SpringGreen;
      Assert::AreEqual(Color::SpringGreen(), control.BackColor, _caller);
      
      Assert::AreEqual(Color::SpringGreen(), newBackColor, _caller);
    }
    
    void SetForeColorToAColor() {
      Control control;
      Color newForeColor;
      control.ForeColorChanged += _delegate(const object& sender, const EventArgs& e) {
        newForeColor = as<Control>(sender).ForeColor;
      };
      
      control.ForeColor = Color::White;
      Assert::AreEqual(Color::White, control.ForeColor, _caller);
      Assert::AreEqual(Color::White(), newForeColor, _caller);
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
