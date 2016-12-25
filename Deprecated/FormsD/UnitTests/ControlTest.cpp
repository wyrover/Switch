#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>
#include <Pcf/System/Windows/Forms/Control.h>

using namespace System::Windows::FormsD;
using namespace TUnit;

namespace PcfUnitTests {
  class ControlTest : public TestFixture {
  protected:
    void GetAllowDropDefaultValue() {
      Assert::IsFalse(Control().AllowDrop(), pcf_current_information);
    }
    
    void GetAnchorDefaultValue() {
      Assert::AreEqual(AnchorStyles::Left | AnchorStyles::Top, Control().Anchor(), pcf_current_information);
    }
    
    void GetAutoScrollOffsetDefaultValue() {
      Assert::AreEqual(System::Drawing::Point(0, 0), System::Windows::FormsD::Control().AutoScrollOffset(), pcf_current_information);
    }

    void GetAutoSizeDefaultValue() {
      Assert::IsFalse(System::Windows::FormsD::Control().AutoSize(), pcf_current_information);
    }
    
    void GetBackColorDefaultValue() {
      Assert::AreEqual(System::Drawing::Color(), System::Windows::FormsD::Control().BackColor(), pcf_current_information);
    }
    
    /*
     void GetBackgroundImageDefaultValue() {
     Assert::AreEqual(System::Drawing::Image(), System::Windows::Forms::Control().BackgroundImage(), pcf_current_information);
     }
     */
    
    void GetBackgroundImageLayoutDefaultValue() {
      Assert::AreEqual(System::Windows::FormsD::ImageLayout(ImageLayout::None), System::Windows::FormsD::Control().BackgroundImageLayout(), pcf_current_information);
    }
    
    void GetBottomDefaultValue() {
      Assert::AreEqual(0, System::Windows::FormsD::Control().Bottom(), pcf_current_information);
    }
    
    void GetBoundsDefaultValue() {
      Assert::AreEqual(System::Drawing::Rectangle(0, 0, 0, 0), System::Windows::FormsD::Control().Bounds(), pcf_current_information);
    }
    
    void GetCanEnableImeDefaultValue() {
      Assert::IsTrue(System::Windows::FormsD::Control().CanEnableIme(), pcf_current_information);
    }
    
    void GetCanFocusDefaultValue() {
      Assert::IsTrue(System::Windows::FormsD::Control().CanFocus(), pcf_current_information);
    }
    
    void GetCanSelectDefaultValue() {
      Assert::IsTrue(System::Windows::FormsD::Control().CanSelect(), pcf_current_information);
    }
    
    void GetCausesValidationDefaultValue() {
      Assert::IsFalse(System::Windows::FormsD::Control().CausesValidation(), pcf_current_information);
    }
    
    void GetCursorDefaultValue() {
      Assert::AreEqual(System::Windows::FormsD::Cursors::Default, System::Windows::FormsD::Control().Cursor(), pcf_current_information);
    }
    
    void GetEnableDefaultValue() {
      Assert::IsTrue(System::Windows::FormsD::Control().Enabled(), pcf_current_information);
    }
    
    void GetForeColorDefaultValue() {
      Assert::AreEqual(System::Drawing::Color(), System::Windows::FormsD::Control().ForeColor(), pcf_current_information);
    }
    
    void GetHandleDefaultValue() {
      Assert::AreEqual(null, &System::Windows::FormsD::Control().Handle(), pcf_current_information);
    }
    
    void GetHeightDefaultValue() {
      Assert::AreEqual(0, System::Windows::FormsD::Control().Height(), pcf_current_information);
    }
    
    void GetLeftDefaultValue() {
      Assert::AreEqual(0, System::Windows::FormsD::Control().Left(), pcf_current_information);
    }
    
    void GetLocationDefaultValue() {
      Assert::AreEqual(System::Drawing::Point(0, 0), System::Windows::FormsD::Control().Location(), pcf_current_information);
    }
    
    void GetParentDefaultValue() {
      Assert::AreEqual(null, &System::Windows::FormsD::Control().Parent(), pcf_current_information);
    }
    
    void GetTextDefaultValue() {
      Assert::AreEqual("", System::Windows::FormsD::Control().Text(), pcf_current_information);
    }
    
    void GetSizeDefaultValue() {
      Assert::AreEqual(System::Drawing::Size(0, 0), System::Windows::FormsD::Control().Size(), pcf_current_information);
    }
    
    void GetTopDefaultValue() {
      Assert::AreEqual(0, System::Windows::FormsD::Control().Top(), pcf_current_information);
    }
    
    void GetVisibleDefaultValue() {
      Assert::IsTrue(System::Windows::FormsD::Control().Visible(), pcf_current_information);
    }
    
    void GetWidthDefaultValue() {
      Assert::AreEqual(0, System::Windows::FormsD::Control().Width(), pcf_current_information);
    }
    
    void SetAllowDropToTrue() {
      System::Windows::FormsD::Control c;
      c.AllowDrop(true);
      Assert::IsTrue(c.AllowDrop(), pcf_current_information);
    }
    
    void SetAllowDropToFalse() {
      System::Windows::FormsD::Control c;
      c.AllowDrop(true);
      c.AllowDrop(false);
      Assert::IsFalse(c.AllowDrop(), pcf_current_information);
    }
    
    void SetAnchorToLeft() {
      System::Windows::FormsD::Control c;
      c.Anchor(System::Windows::FormsD::AnchorStyles::Left);
      Assert::AreEqual(System::Windows::FormsD::AnchorStyles(System::Windows::FormsD::AnchorStyles::Left), c.Anchor(), pcf_current_information);
    }
    
    void SetAnchorToTop() {
      System::Windows::FormsD::Control c;
      c.Anchor(System::Windows::FormsD::AnchorStyles::Top);
      Assert::AreEqual(System::Windows::FormsD::AnchorStyles(System::Windows::FormsD::AnchorStyles::Top), c.Anchor(), pcf_current_information);
    }
    
    void SetAnchorToRight() {
      System::Windows::FormsD::Control c;
      c.Anchor(System::Windows::FormsD::AnchorStyles::Right);
      Assert::AreEqual(System::Windows::FormsD::AnchorStyles(System::Windows::FormsD::AnchorStyles::Right), c.Anchor(), pcf_current_information);
    }
    
    void SetAnchorToBottom() {
      System::Windows::FormsD::Control c;
      c.Anchor(System::Windows::FormsD::AnchorStyles::Bottom);
      Assert::AreEqual(System::Windows::FormsD::AnchorStyles(System::Windows::FormsD::AnchorStyles::Bottom), c.Anchor(), pcf_current_information);
    }
    
    void SetAnchorToLeftTop() {
      System::Windows::FormsD::Control c;
      c.Anchor(System::Windows::FormsD::AnchorStyles::Left | System::Windows::FormsD::AnchorStyles::Top);
      Assert::AreEqual(System::Windows::FormsD::AnchorStyles(System::Windows::FormsD::AnchorStyles::Left | System::Windows::FormsD::AnchorStyles::Top), c.Anchor(), pcf_current_information);
    }
    
    void SetAnchorToLRightBottom() {
      System::Windows::FormsD::Control c;
      c.Anchor(System::Windows::FormsD::AnchorStyles::Right | System::Windows::FormsD::AnchorStyles::Bottom);
      Assert::AreEqual(System::Windows::FormsD::AnchorStyles(System::Windows::FormsD::AnchorStyles::Right | System::Windows::FormsD::AnchorStyles::Bottom), c.Anchor(), pcf_current_information);
    }
    
    void SetAnchorToLeftTopRightBottom() {
      System::Windows::FormsD::Control c;
      c.Anchor(System::Windows::FormsD::AnchorStyles::Left | System::Windows::FormsD::AnchorStyles::Top | System::Windows::FormsD::AnchorStyles::Right | System::Windows::FormsD::AnchorStyles::Bottom);
      Assert::AreEqual(System::Windows::FormsD::AnchorStyles(System::Windows::FormsD::AnchorStyles::Left | System::Windows::FormsD::AnchorStyles::Top | System::Windows::FormsD::AnchorStyles::Right | System::Windows::FormsD::AnchorStyles::Bottom), c.Anchor(), pcf_current_information);
    }
    
    void SetAutoScrollOffsetFromInt32() {
      System::Windows::FormsD::Control c;
      c.AutoScrollOffset = System::Drawing::Point(10, 20);
      Assert::AreEqual(System::Drawing::Point(10, 20), c.AutoScrollOffset(), pcf_current_information);
    }
    
    void SetAutoScrollOffsetFromPoint() {
      System::Windows::FormsD::Control c;
      c.AutoScrollOffset(System::Drawing::Point(10, 20));
      Assert::AreEqual(System::Drawing::Point(10, 20), c.AutoScrollOffset(), pcf_current_information);
    }
    
    void SetAutoSizeToTrue() {
      System::Windows::FormsD::Control c;
      c.AutoSize(true);
      Assert::IsTrue(c.AutoSize(), pcf_current_information);
    }
    
    void SetAutoSizeToFalse() {
      System::Windows::FormsD::Control c;
      c.AutoSize(true);
      c.AutoSize(false);
      Assert::IsFalse(c.AutoSize(), pcf_current_information);
    }
    
    void SetBackColor() {
      System::Windows::FormsD::Control c;
      c.BackColor(System::Drawing::Color::LightBlue);
      Assert::AreEqual(System::Drawing::Color::LightBlue, c.BackColor(), pcf_current_information);
    }
    
    /*
     void SetBackgroundImageDefaultValue() {
     System::Windows::Forms::Control c;
     c.BackgroundImage(...);
     Assert::AreEqual(System::Drawing::Image(...), c.BackgroundImage(), pcf_current_information);
     }
     */
    
    void SetBackgroundImageLayoutToTile() {
      System::Windows::FormsD::Control c;
      c.BackgroundImageLayout(System::Windows::FormsD::ImageLayout::Tile);
      Assert::AreEqual(System::Windows::FormsD::ImageLayout(System::Windows::FormsD::ImageLayout::Tile), c.BackgroundImageLayout(), pcf_current_information);
    }
    
    void SetBackgroundImageLayoutToCenter() {
      System::Windows::FormsD::Control c;
      c.BackgroundImageLayout(System::Windows::FormsD::ImageLayout::Center);
      Assert::AreEqual(System::Windows::FormsD::ImageLayout(System::Windows::FormsD::ImageLayout::Center), c.BackgroundImageLayout(), pcf_current_information);
    }
    
    void SetBackgroundImageLayoutToStretch() {
      System::Windows::FormsD::Control c;
      c.BackgroundImageLayout(System::Windows::FormsD::ImageLayout::Stretch);
      Assert::AreEqual(System::Windows::FormsD::ImageLayout(System::Windows::FormsD::ImageLayout::Stretch), c.BackgroundImageLayout(), pcf_current_information);
    }
    
    void SetBackgroundImageLayoutToZoom() {
      System::Windows::FormsD::Control c;
      c.BackgroundImageLayout(System::Windows::FormsD::ImageLayout::Zoom);
      Assert::AreEqual(System::Windows::FormsD::ImageLayout(System::Windows::FormsD::ImageLayout::Zoom), c.BackgroundImageLayout(), pcf_current_information);
    }
    
    void SetBackgroundImageLayoutToNone() {
      System::Windows::FormsD::Control c;
      c.BackgroundImageLayout(System::Windows::FormsD::ImageLayout::Zoom);
      c.BackgroundImageLayout(System::Windows::FormsD::ImageLayout::None);
      Assert::AreEqual(System::Windows::FormsD::ImageLayout(System::Windows::FormsD::ImageLayout::None), c.BackgroundImageLayout(), pcf_current_information);
    }
    
    void SetBoundsFromInt32() {
      System::Windows::FormsD::Control c;
      c.Bounds = System::Drawing::Rectangle(10, 20, 30, 40);
      Assert::AreEqual(System::Drawing::Rectangle(10, 20, 30, 40),c.Bounds(), pcf_current_information);
    }
    
    void SetBoundsFromRectangle() {
      System::Windows::FormsD::Control c;
      c.Bounds(System::Drawing::Rectangle(10, 20, 30, 40));
      Assert::AreEqual(System::Drawing::Rectangle(10, 20, 30, 40),c.Bounds(), pcf_current_information);
    }
    
    void SetCausesValidationToTrue() {
      System::Windows::FormsD::Control c;
      c.CausesValidation(true);
      Assert::IsTrue(c.CausesValidation(), pcf_current_information);
    }
    
    void SetCausesValidationToFalse() {
      System::Windows::FormsD::Control c;
      c.CausesValidation(true);
      c.CausesValidation(false);
      Assert::IsFalse(c.CausesValidation(), pcf_current_information);
    }
    
    void SetCursorToCross() {
      System::Windows::FormsD::Control c;
      c.Cursor(System::Windows::FormsD::Cursors::Cross);
      Assert::AreEqual(System::Windows::FormsD::Cursors::Cross, c.Cursor(), pcf_current_information);
    }
    
    void SetCursorToHand() {
      System::Windows::FormsD::Control c;
      c.Cursor(System::Windows::FormsD::Cursors::Hand);
      Assert::AreEqual(System::Windows::FormsD::Cursors::Hand, c.Cursor(), pcf_current_information);
    }
    
    void SetCursorToDefault() {
      System::Windows::FormsD::Control c;
      c.Cursor(System::Windows::FormsD::Cursors::Hand);
      c.Cursor(System::Windows::FormsD::Cursors::Default);
      Assert::AreEqual(System::Windows::FormsD::Cursors::Default, c.Cursor(), pcf_current_information);
    }
    
    void SetEnableToFalse() {
      System::Windows::FormsD::Control c;
      c.Enabled(false);
      Assert::IsFalse(c.Enabled(), pcf_current_information);
    }
    
    void SetEnableToTrue() {
      System::Windows::FormsD::Control c;
      c.Enabled(false);
      c.Enabled(true);
      Assert::IsTrue(c.Enabled(), pcf_current_information);
    }
    
    void SetForeColor() {
      System::Windows::FormsD::Control c;
      c.ForeColor(System::Drawing::Color::LightBlue);
      Assert::AreEqual(System::Drawing::Color::LightBlue, c.ForeColor(), pcf_current_information);
    }
    
    void SetHeight() {
      System::Windows::FormsD::Control c;
      c.Height(10);
      Assert::AreEqual(10, c.Height(), pcf_current_information);
    }
    
    void SetLeft() {
      System::Windows::FormsD::Control c;
      c.Left(10);
      Assert::AreEqual(10, c.Left(), pcf_current_information);
    }
    
    void SetLocationFromInt32() {
      System::Windows::FormsD::Control c;
      c.Location = System::Drawing::Point(10, 20);
      Assert::AreEqual(System::Drawing::Point(10, 20), c.Location(), pcf_current_information);
    }
    
    void SetLocationFromPoint() {
      System::Windows::FormsD::Control c;
      c.Location(System::Drawing::Point(10, 20));
      Assert::AreEqual(System::Drawing::Point(10, 20), c.Location(), pcf_current_information);
    }
    
    void SetParent() {
      System::Windows::FormsD::Control p1;
      System::Windows::FormsD::Control p2;
      System::Windows::FormsD::Control c;
      c.Parent(p1);
      Assert::AreEqual(p1, c.Parent(), pcf_current_information);
      Assert::AreNotEqual(p2, c.Parent(), pcf_current_information);
    }
    
    void SetSizeFromInt32() {
      System::Windows::FormsD::Control c;
      c.Size = System::Drawing::Size(10, 20);
      Assert::AreEqual(System::Drawing::Size(10, 20), c.Size(), pcf_current_information);
    }
    
    void SetSizeFromSize() {
      System::Windows::FormsD::Control c;
      c.Size(System::Drawing::Size(10, 20));
      Assert::AreEqual(System::Drawing::Size(10, 20), c.Size(), pcf_current_information);
    }
    
    void SetText() {
      System::Windows::FormsD::Control c;
      c.Text = "Test";
      Assert::AreEqual("Test", c.Text(), pcf_current_information);
    }
    
    void SetTop() {
      System::Windows::FormsD::Control c;
      c.Top(10);
      Assert::AreEqual(10, c.Top(), pcf_current_information);
    }
    
    void SetVisibleToFalse() {
      System::Windows::FormsD::Control c;
      c.Visible(false);
      Assert::IsFalse(c.Visible(), pcf_current_information);
    }
    
    void SetVisibleToTrue() {
      System::Windows::FormsD::Control c;
      c.Visible(false);
      c.Visible(true);
      Assert::IsTrue(c.Visible(), pcf_current_information);
    }
    
    void SetWidth() {
      System::Windows::FormsD::Control c;
      c.Width(10);
      Assert::AreEqual(10, c.Width(), pcf_current_information);
    }
    
    void Hide() {
      System::Windows::FormsD::Control c;
      c.Hide();
      Assert::IsFalse(c.Visible(), pcf_current_information);
    }
    
    void Show() {
      System::Windows::FormsD::Control c;
      c.Hide();
      c.Show();
      Assert::IsTrue(c.Visible(), pcf_current_information);
    }
    
    int32 value;
    
    void OnAutoSizeChanged(const object& sender, const System::EventArgs& e) {
      this->value = 1;
    }
    
    void AutoSizeChanged() {
      value = 0;
      Assert::AreEqual(0, value, pcf_current_information);
      
      System::Windows::FormsD::Control c;
      c.AutoSizeChanged += System::EventHandler(*this, &ControlTest::OnAutoSizeChanged);
      c.AutoSize(true);
      
      Assert::AreEqual(1, value, pcf_current_information);
    }
    
    void OnBackColorChanged(const object& sender, const System::EventArgs& e) {
      value = 2;
    }
    
    void BackColorChanged() {
      value = 0;
      Assert::AreEqual(0, value, pcf_current_information);
      
      System::Windows::FormsD::Control c;
      c.BackColorChanged += System::EventHandler(*this, &ControlTest::OnBackColorChanged);
      c.BackColor(System::Drawing::Color::LightBlue);
      
      Assert::AreEqual(2, value, pcf_current_information);
    }
    
    /*
     void OnBackgroundImageChanged(const object& sender, const System::EventArgs& e() {
     value = 3;
     }
     
     void BackgroundImageChanged() {
     value = 0;
     Assert::AreEqual(0, value);
     
     System::Windows::Forms::Control c;
     c.BackgroundImageChanged += System::EventHandler(*this, &BackgroundImageChanged);
     c.BackgroundImage(...);
     
     Assert::AreEqual(3, value);
     }
     */
    
    void OnBackgroundImageLayoutChanged(const object& sender, const System::EventArgs& e) {
      value = 4;
    }
    
    void BackgroundImageLayoutChanged() {
      value = 0;
      Assert::AreEqual(0, value, pcf_current_information);
      
      System::Windows::FormsD::Control c;
      c.BackgroundImageLayoutChanged += System::EventHandler(*this, &ControlTest::OnBackgroundImageLayoutChanged);
      c.BackgroundImageLayout(System::Windows::FormsD::ImageLayout::Tile);
      
      Assert::AreEqual(4, value, pcf_current_information);
    }
    
    /*
     void OnBindingContextChanged(const object& sender, const System::EventArgs& e() {
     value = 5;
     }
     
     void BindingContextChanged() {
     value = 0;
     Assert::AreEqual(0, value);
     
     System::Windows::Forms::Control c;
     c.BindingContextChanged += System::EventHandler(*this, &OnBindingContextChanged);
     //c.Bind();
     
     Assert::AreEqual(5, value);
     }
     */
    
    void OnCausesValidationChanged(const object& sender, const System::EventArgs& e) {
      value = 6;
    }
    
    void CausesValidationChanged() {
      value = 0;
      Assert::AreEqual(0, value, pcf_current_information);
      
      System::Windows::FormsD::Control c;
      c.CausesValidationChanged += System::EventHandler(*this, &ControlTest::OnCausesValidationChanged);
      c.CausesValidation(true);
      
      Assert::AreEqual(6, value, pcf_current_information);
    }
  };

  pcf_test(ControlTest, GetAllowDropDefaultValue);
  pcf_test(ControlTest, GetAnchorDefaultValue);
  pcf_test(ControlTest, GetAutoScrollOffsetDefaultValue);
  pcf_test(ControlTest, GetAutoSizeDefaultValue);
  pcf_test(ControlTest, GetBackColorDefaultValue);
  //pcf_test(ControlTest, GetBackgroundImageDefaultValue);
  pcf_test(ControlTest, GetBackgroundImageLayoutDefaultValue);
  pcf_test(ControlTest, GetBottomDefaultValue);
  pcf_test(ControlTest, GetBoundsDefaultValue);
  pcf_test(ControlTest, GetCanEnableImeDefaultValue);
  pcf_test(ControlTest, GetCanFocusDefaultValue);
  pcf_test(ControlTest, GetCanSelectDefaultValue);
  pcf_test(ControlTest, GetCausesValidationDefaultValue);
  pcf_test(ControlTest, GetCursorDefaultValue);
  pcf_test(ControlTest, GetEnableDefaultValue);
  pcf_test(ControlTest, GetForeColorDefaultValue);
  pcf_test(ControlTest, GetHandleDefaultValue);
  pcf_test(ControlTest, GetHeightDefaultValue);
  pcf_test(ControlTest, GetLeftDefaultValue);
  pcf_test(ControlTest, GetLocationDefaultValue);
  pcf_test(ControlTest, GetParentDefaultValue);
  pcf_test(ControlTest, GetTextDefaultValue);
  pcf_test(ControlTest, GetSizeDefaultValue);
  pcf_test(ControlTest, GetTopDefaultValue);
  pcf_test(ControlTest, GetVisibleDefaultValue);
  pcf_test(ControlTest, GetWidthDefaultValue);
  pcf_test(ControlTest, SetAllowDropToTrue);
  pcf_test(ControlTest, SetAllowDropToFalse);
  pcf_test(ControlTest, SetAnchorToLeft);
  pcf_test(ControlTest, SetAnchorToTop);
  pcf_test(ControlTest, SetAnchorToRight);
  pcf_test(ControlTest, SetAnchorToBottom);
  pcf_test(ControlTest, SetAnchorToLeftTop);
  pcf_test(ControlTest, SetAnchorToLRightBottom);
  pcf_test(ControlTest, SetAnchorToLeftTopRightBottom);
  pcf_test(ControlTest, SetAutoScrollOffsetFromInt32);
  pcf_test(ControlTest, SetAutoScrollOffsetFromPoint);
  pcf_test(ControlTest, SetAutoSizeToTrue);
  pcf_test(ControlTest, SetAutoSizeToFalse);
  pcf_test(ControlTest, SetBackColor);
  pcf_test(ControlTest, SetBackgroundImageLayoutToTile);
  pcf_test(ControlTest, SetBackgroundImageLayoutToCenter);
  pcf_test(ControlTest, SetBackgroundImageLayoutToStretch);
  pcf_test(ControlTest, SetBackgroundImageLayoutToZoom);
  pcf_test(ControlTest, SetBackgroundImageLayoutToNone);
  pcf_test(ControlTest, SetBoundsFromInt32);
  pcf_test(ControlTest, SetBoundsFromRectangle);
  pcf_test(ControlTest, SetCausesValidationToTrue);
  pcf_test(ControlTest, SetCausesValidationToFalse);
  pcf_test(ControlTest, SetCursorToCross);
  pcf_test(ControlTest, SetCursorToHand);
  pcf_test(ControlTest, SetCursorToDefault);
  pcf_test(ControlTest, SetEnableToFalse);
  pcf_test(ControlTest, SetEnableToTrue);
  pcf_test(ControlTest, SetForeColor);
  pcf_test(ControlTest, SetHeight);
  pcf_test(ControlTest, SetLeft);
  pcf_test(ControlTest, SetLocationFromInt32);
  pcf_test(ControlTest, SetLocationFromPoint);
  pcf_test(ControlTest, SetParent);
  pcf_test(ControlTest, SetSizeFromInt32);
  pcf_test(ControlTest, SetSizeFromSize);
  pcf_test(ControlTest, SetText);
  pcf_test(ControlTest, SetTop);
  pcf_test(ControlTest, SetVisibleToFalse);
  pcf_test(ControlTest, SetVisibleToTrue);
  pcf_test(ControlTest, SetWidth);
  pcf_test(ControlTest, Hide);
  pcf_test(ControlTest, Show);
  pcf_test(ControlTest, AutoSizeChanged);
  pcf_test(ControlTest, BackColorChanged);
  pcf_test(ControlTest, BackgroundImageLayoutChanged);
  pcf_test(ControlTest, CausesValidationChanged);
}
