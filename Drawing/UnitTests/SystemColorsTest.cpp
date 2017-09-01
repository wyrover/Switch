#include <Switch/System/Drawing/SystemColors.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Drawing;
using namespace TUnit;

namespace SwitchUnitTests {
  class SystemColors : public TestFixture {
  public:
    void ActiveBorder() {
      //Assert::AreEqual(0xFFB4B4B4u, (unsigned)Drawing::SystemColors::ActiveBorder().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveBorder().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsSystemColor(), _current_information);
      Assert::AreEqual("ActiveBorder", Drawing::SystemColors::ActiveBorder().Name(), _current_information);
      Assert::AreEqual("Color [ActiveBorder]", Drawing::SystemColors::ActiveBorder().ToString(), _current_information);
    }
    
    void ActiveCaption() {
      //Assert::AreEqual(0xFF99B4D1u, (unsigned)Drawing::SystemColors::ActiveCaption().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaption().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsSystemColor(), _current_information);
      Assert::AreEqual("ActiveCaption", Drawing::SystemColors::ActiveCaption().Name(), _current_information);
      Assert::AreEqual("Color [ActiveCaption]", Drawing::SystemColors::ActiveCaption().ToString(), _current_information);
    }
    
    void ActiveCaptionText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ActiveCaptionText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaptionText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsSystemColor(), _current_information);
      Assert::AreEqual("ActiveCaptionText", Drawing::SystemColors::ActiveCaptionText().Name(), _current_information);
      Assert::AreEqual("Color [ActiveCaptionText]", Drawing::SystemColors::ActiveCaptionText().ToString(), _current_information);
    }
    
    void AppWorkspace() {
      //Assert::AreEqual(0xFFABABABu, (unsigned)Drawing::SystemColors::AppWorkspace().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::AppWorkspace().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsSystemColor(), _current_information);
      Assert::AreEqual("AppWorkspace", Drawing::SystemColors::AppWorkspace().Name(), _current_information);
      Assert::AreEqual("Color [AppWorkspace]", Drawing::SystemColors::AppWorkspace().ToString(), _current_information);
    }
    
    void Control() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Control().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::Control().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Control().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Control().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Control().IsSystemColor(), _current_information);
      Assert::AreEqual("Control", Drawing::SystemColors::Control().Name(), _current_information);
      Assert::AreEqual("Color [Control]", Drawing::SystemColors::Control().ToString(), _current_information);
    }
    
    void ControlDark() {
      //Assert::AreEqual(0xFFA0A0A0u, (unsigned)Drawing::SystemColors::ControlDark().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlDark().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsSystemColor(), _current_information);
      Assert::AreEqual("ControlDark", Drawing::SystemColors::ControlDark().Name(), _current_information);
      Assert::AreEqual("Color [ControlDark]", Drawing::SystemColors::ControlDark().ToString(), _current_information);
    }
    
    void ControlDarkDark() {
      //Assert::AreEqual(0xFF696969u, (unsigned)Drawing::SystemColors::ControlDarkDark().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlDarkDark().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsSystemColor(), _current_information);
      Assert::AreEqual("ControlDarkDark", Drawing::SystemColors::ControlDarkDark().Name(), _current_information);
      Assert::AreEqual("Color [ControlDarkDark]", Drawing::SystemColors::ControlDarkDark().ToString(), _current_information);
    }
    
    void ControlLight() {
      //Assert::AreEqual(0xFFE3E3E3u, (unsigned)Drawing::SystemColors::ControlLight().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlLight().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsSystemColor(), _current_information);
      Assert::AreEqual("ControlLight", Drawing::SystemColors::ControlLight().Name(), _current_information);
      Assert::AreEqual("Color [ControlLight]", Drawing::SystemColors::ControlLight().ToString(), _current_information);
    }
    
    void ControlLightLight() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ControlLightLight().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlLightLight().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsSystemColor(), _current_information);
      Assert::AreEqual("ControlLightLight", Drawing::SystemColors::ControlLightLight().Name(), _current_information);
      Assert::AreEqual("Color [ControlLightLight]", Drawing::SystemColors::ControlLightLight().ToString(), _current_information);
    }
    
    void ControlText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ControlText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsSystemColor(), _current_information);
      Assert::AreEqual("ControlText", Drawing::SystemColors::ControlText().Name(), _current_information);
      Assert::AreEqual("Color [ControlText]", Drawing::SystemColors::ControlText().ToString(), _current_information);
    }
    
    void Desktop() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::Desktop().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::Desktop().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsSystemColor(), _current_information);
      Assert::AreEqual("Desktop", Drawing::SystemColors::Desktop().Name(), _current_information);
      Assert::AreEqual("Color [Desktop]", Drawing::SystemColors::Desktop().ToString(), _current_information);
    }
    
    void GrayText() {
      //Assert::AreEqual(0xFF6D6D6Du, (unsigned)Drawing::SystemColors::GrayText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::GrayText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsSystemColor(), _current_information);
      Assert::AreEqual("GrayText", Drawing::SystemColors::GrayText().Name(), _current_information);
      Assert::AreEqual("Color [GrayText]", Drawing::SystemColors::GrayText().ToString(), _current_information);
    }
    
    void Highlight() {
      //Assert::AreEqual(0xFF3399FFu, (unsigned)Drawing::SystemColors::Highlight().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::Highlight().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsSystemColor(), _current_information);
      Assert::AreEqual("Highlight", Drawing::SystemColors::Highlight().Name(), _current_information);
      Assert::AreEqual("Color [Highlight]", Drawing::SystemColors::Highlight().ToString(), _current_information);
    }
    
    void HighlightText() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::HighlightText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::HighlightText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsSystemColor(), _current_information);
      Assert::AreEqual("HighlightText", Drawing::SystemColors::HighlightText().Name(), _current_information);
      Assert::AreEqual("Color [HighlightText]", Drawing::SystemColors::HighlightText().ToString(), _current_information);
    }
    
    void HotTrack() {
      //Assert::AreEqual(0xFF0066CCu, (unsigned)Drawing::SystemColors::HotTrack().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::HotTrack().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsSystemColor(), _current_information);
      Assert::AreEqual("HotTrack", Drawing::SystemColors::HotTrack().Name(), _current_information);
      Assert::AreEqual("Color [HotTrack]", Drawing::SystemColors::HotTrack().ToString(), _current_information);
    }
    
    void InactiveBorder() {
      //Assert::AreEqual(0xFFF4F7FCu, (unsigned)Drawing::SystemColors::InactiveBorder().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveBorder().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsSystemColor(), _current_information);
      Assert::AreEqual("InactiveBorder", Drawing::SystemColors::InactiveBorder().Name(), _current_information);
      Assert::AreEqual("Color [InactiveBorder]", Drawing::SystemColors::InactiveBorder().ToString(), _current_information);
    }
    
    void InactiveCaption() {
      //Assert::AreEqual(0xFFBFCDDBu, (unsigned)Drawing::SystemColors::InactiveCaption().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaption().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsSystemColor(), _current_information);
      Assert::AreEqual("InactiveCaption", Drawing::SystemColors::InactiveCaption().Name(), _current_information);
      Assert::AreEqual("Color [InactiveCaption]", Drawing::SystemColors::InactiveCaption().ToString(), _current_information);
    }
    
    void InactiveCaptionText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::InactiveCaptionText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaptionText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsSystemColor(), _current_information);
      Assert::AreEqual("InactiveCaptionText", Drawing::SystemColors::InactiveCaptionText().Name(), _current_information);
      Assert::AreEqual("Color [InactiveCaptionText]", Drawing::SystemColors::InactiveCaptionText().ToString(), _current_information);
    }
    
    void Info() {
      //Assert::AreEqual(0xFFFFFFE1u, (unsigned)Drawing::SystemColors::Info().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::Info().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Info().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Info().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Info().IsSystemColor(), _current_information);
      Assert::AreEqual("Info", Drawing::SystemColors::Info().Name(), _current_information);
      Assert::AreEqual("Color [Info]", Drawing::SystemColors::Info().ToString(), _current_information);
    }
    
    void InfoText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::InfoText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::InfoText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsSystemColor(), _current_information);
      Assert::AreEqual("InfoText", Drawing::SystemColors::InfoText().Name(), _current_information);
      Assert::AreEqual("Color [InfoText]", Drawing::SystemColors::InfoText().ToString(), _current_information);
    }
    
    void Menu() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Menu().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::Menu().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsSystemColor(), _current_information);
      Assert::AreEqual("Menu", Drawing::SystemColors::Menu().Name(), _current_information);
      Assert::AreEqual("Color [Menu]", Drawing::SystemColors::Menu().ToString(), _current_information);
    }
    
    void MenuText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::MenuText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsSystemColor(), _current_information);
      Assert::AreEqual("MenuText", Drawing::SystemColors::MenuText().Name(), _current_information);
      Assert::AreEqual("Color [MenuText]", Drawing::SystemColors::MenuText().ToString(), _current_information);
    }
    
    void ScrollBar() {
      //Assert::AreEqual(0xFFC8C8C8u, (unsigned)Drawing::SystemColors::ScrollBar().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ScrollBar().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsSystemColor(), _current_information);
      Assert::AreEqual("ScrollBar", Drawing::SystemColors::ScrollBar().Name(), _current_information);
      Assert::AreEqual("Color [ScrollBar]", Drawing::SystemColors::ScrollBar().ToString(), _current_information);
    }
    
    void Window() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::Window().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::Window().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Window().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Window().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::Window().IsSystemColor(), _current_information);
      Assert::AreEqual("Window", Drawing::SystemColors::Window().Name(), _current_information);
      Assert::AreEqual("Color [Window]", Drawing::SystemColors::Window().ToString(), _current_information);
    }
    
    void WindowFrame() {
      //Assert::AreEqual(0xFF646464u, (unsigned)Drawing::SystemColors::WindowFrame().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::WindowFrame().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsSystemColor(), _current_information);
      Assert::AreEqual("WindowFrame", Drawing::SystemColors::WindowFrame().Name(), _current_information);
      Assert::AreEqual("Color [WindowFrame]", Drawing::SystemColors::WindowFrame().ToString(), _current_information);
    }
    
    void WindowText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::WindowText().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::WindowText().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsSystemColor(), _current_information);
      Assert::AreEqual("WindowText", Drawing::SystemColors::WindowText().Name(), _current_information);
      Assert::AreEqual("Color [WindowText]", Drawing::SystemColors::WindowText().ToString(), _current_information);
    }
    
    void ButtonFace() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonFace().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonFace().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsSystemColor(), _current_information);
      Assert::AreEqual("ButtonFace", Drawing::SystemColors::ButtonFace().Name(), _current_information);
      Assert::AreEqual("Color [ButtonFace]", Drawing::SystemColors::ButtonFace().ToString(), _current_information);
    }
    
    void ButtonHighlight() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ButtonHighlight().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonHighlight().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsSystemColor(), _current_information);
      Assert::AreEqual("ButtonHighlight", Drawing::SystemColors::ButtonHighlight().Name(), _current_information);
      Assert::AreEqual("Color [ButtonHighlight]", Drawing::SystemColors::ButtonHighlight().ToString(), _current_information);
    }
    
    void ButtonShadow() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonShadow().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonShadow().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsSystemColor(), _current_information);
      Assert::AreEqual("ButtonShadow", Drawing::SystemColors::ButtonShadow().Name(), _current_information);
      Assert::AreEqual("Color [ButtonShadow]", Drawing::SystemColors::ButtonShadow().ToString(), _current_information);
    }
    
    void GradientActiveCaption() {
      //Assert::AreEqual(0xFFB9D1EAu, (unsigned)Drawing::SystemColors::GradientActiveCaption().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::GradientActiveCaption().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsSystemColor(), _current_information);
      Assert::AreEqual("GradientActiveCaption", Drawing::SystemColors::GradientActiveCaption().Name(), _current_information);
      Assert::AreEqual("Color [GradientActiveCaption]", Drawing::SystemColors::GradientActiveCaption().ToString(), _current_information);
    }
    
    void GradientInactiveCaption() {
      //Assert::AreEqual(0xFFD7E4F2u, (unsigned)Drawing::SystemColors::GradientInactiveCaption().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::GradientInactiveCaption().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsSystemColor(), _current_information);
      Assert::AreEqual("GradientInactiveCaption", Drawing::SystemColors::GradientInactiveCaption().Name(), _current_information);
      Assert::AreEqual("Color [GradientInactiveCaption]", Drawing::SystemColors::GradientInactiveCaption().ToString(), _current_information);
    }
    
    void MenuBar() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::MenuBar().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuBar().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsSystemColor(), _current_information);
      Assert::AreEqual("MenuBar", Drawing::SystemColors::MenuBar().Name(), _current_information);
      Assert::AreEqual("Color [MenuBar]", Drawing::SystemColors::MenuBar().ToString(), _current_information);
    }
    
    void MenuHighlight() {
      //Assert::AreEqual(0xFF3399FFu, (unsigned)Drawing::SystemColors::MenuHighlight().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuHighlight().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsNamedColor(), _current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsSystemColor(), _current_information);
      Assert::AreEqual("MenuHighlight", Drawing::SystemColors::MenuHighlight().Name(), _current_information);
      Assert::AreEqual("Color [MenuHighlight]", Drawing::SystemColors::MenuHighlight().ToString(), _current_information);
    }
  };
  
  _test(SystemColors, ActiveBorder)
  _test(SystemColors, ActiveCaption)
  _test(SystemColors, ActiveCaptionText)
  _test(SystemColors, AppWorkspace)
  _test(SystemColors, Control)
  _test(SystemColors, ControlDark)
  _test(SystemColors, ControlDarkDark)
  _test(SystemColors, ControlLight)
  _test(SystemColors, ControlLightLight)
  _test(SystemColors, ControlText)
  _test(SystemColors, Desktop)
  _test(SystemColors, GrayText)
  _test(SystemColors, Highlight)
  _test(SystemColors, HighlightText)
  _test(SystemColors, HotTrack)
  _test(SystemColors, InactiveBorder)
  _test(SystemColors, InactiveCaption)
  _test(SystemColors, InactiveCaptionText)
  _test(SystemColors, Info)
  _test(SystemColors, InfoText)
  _test(SystemColors, Menu)
  _test(SystemColors, MenuText)
  _test(SystemColors, ScrollBar)
  _test(SystemColors, Window)
  _test(SystemColors, WindowFrame)
  _test(SystemColors, WindowText)
  _test(SystemColors, ButtonFace)
  _test(SystemColors, ButtonHighlight)
  _test(SystemColors, ButtonShadow)
  _test(SystemColors, GradientActiveCaption)
  _test(SystemColors, GradientInactiveCaption)
  _test(SystemColors, MenuBar)
  _test(SystemColors, MenuHighlight)
}
