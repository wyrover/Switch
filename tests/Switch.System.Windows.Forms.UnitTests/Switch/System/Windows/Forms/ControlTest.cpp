#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/Control.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(ControlTest, DefaultConstructor) {
    Control control;
    ASSERT_EQ(Control::DefaultBackColor, control.BackColor);
    ASSERT_EQ(0, control.Bottom);
    ASSERT_EQ(Rectangle(0, 0, 0, 0), control.Bounds());
    ASSERT_EQ(Size(0, 0), control.ClientSize());
    ASSERT_EQ(0, control.Controls().Count());
    ASSERT_EQ(Control::DefaultForeColor, control.ForeColor());
    ASSERT_EQ(0, control.Height());
    ASSERT_EQ(0, control.Left());
    ASSERT_TRUE(control.Parent == null);
    ASSERT_EQ(string::Empty, control.Text());
    ASSERT_EQ(0, control.Top());
    ASSERT_EQ(0, control.Width());
  }
  
  TEST(ControlTest, SetBackColorToAColor) {
    Control control;
    Color newBackColor;
    control.BackColorChanged += _delegate(const object & sender, const EventArgs & e) {
      newBackColor = as<Control>(sender).BackColor;
    };
    
    control.BackColor = Color::SpringGreen;
    ASSERT_EQ(Color::SpringGreen(), control.BackColor());
    
    ASSERT_EQ(Color::SpringGreen(), newBackColor);
  }
  
  TEST(ControlTest, SetForeColorToAColor) {
    Control control;
    Color newForeColor;
    control.ForeColorChanged += _delegate(const object & sender, const EventArgs & e) {
      newForeColor = as<Control>(sender).ForeColor;
    };
    
    control.ForeColor = Color::White;
    ASSERT_EQ(Color::White(), control.ForeColor());
    ASSERT_EQ(Color::White(), newForeColor);
  }
  
  /*
   TEST(ControlTest, SetParentToControl) {
   Control parent;
   Control control;
   ref<Control> newParent;
   control.ParentChanged += _delegate(const object& sender, const EventArgs& e) {
   newParent = as<Control>(sender).Parent;
   };
  
   control.Parent = parent;
   ASSERT_EQ(parent, control.Parent);
   ASSERT_EQ(parent, newParent);
   }*/
}

