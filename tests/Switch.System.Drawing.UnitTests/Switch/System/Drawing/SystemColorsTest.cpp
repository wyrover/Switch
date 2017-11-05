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
      //Assert::AreEqual(0xFFB4B4B4u, (unsigned)Drawing::SystemColors::ActiveBorder().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ActiveBorder().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsSystemColor(), _caller);
      Assert::AreEqual("ActiveBorder", Drawing::SystemColors::ActiveBorder().Name(), _caller);
      Assert::AreEqual("Color [ActiveBorder]", Drawing::SystemColors::ActiveBorder().ToString(), _caller);
    }
    
    void ActiveCaption() {
      //Assert::AreEqual(0xFF99B4D1u, (unsigned)Drawing::SystemColors::ActiveCaption().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaption().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsSystemColor(), _caller);
      Assert::AreEqual("ActiveCaption", Drawing::SystemColors::ActiveCaption().Name(), _caller);
      Assert::AreEqual("Color [ActiveCaption]", Drawing::SystemColors::ActiveCaption().ToString(), _caller);
    }
    
    void ActiveCaptionText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ActiveCaptionText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaptionText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsSystemColor(), _caller);
      Assert::AreEqual("ActiveCaptionText", Drawing::SystemColors::ActiveCaptionText().Name(), _caller);
      Assert::AreEqual("Color [ActiveCaptionText]", Drawing::SystemColors::ActiveCaptionText().ToString(), _caller);
    }
    
    void AppWorkspace() {
      //Assert::AreEqual(0xFFABABABu, (unsigned)Drawing::SystemColors::AppWorkspace().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::AppWorkspace().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsSystemColor(), _caller);
      Assert::AreEqual("AppWorkspace", Drawing::SystemColors::AppWorkspace().Name(), _caller);
      Assert::AreEqual("Color [AppWorkspace]", Drawing::SystemColors::AppWorkspace().ToString(), _caller);
    }
    
    void Control() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Control().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::Control().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Control().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Control().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Control().IsSystemColor(), _caller);
      Assert::AreEqual("Control", Drawing::SystemColors::Control().Name(), _caller);
      Assert::AreEqual("Color [Control]", Drawing::SystemColors::Control().ToString(), _caller);
    }
    
    void ControlDark() {
      //Assert::AreEqual(0xFFA0A0A0u, (unsigned)Drawing::SystemColors::ControlDark().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ControlDark().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsSystemColor(), _caller);
      Assert::AreEqual("ControlDark", Drawing::SystemColors::ControlDark().Name(), _caller);
      Assert::AreEqual("Color [ControlDark]", Drawing::SystemColors::ControlDark().ToString(), _caller);
    }
    
    void ControlDarkDark() {
      //Assert::AreEqual(0xFF696969u, (unsigned)Drawing::SystemColors::ControlDarkDark().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ControlDarkDark().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsSystemColor(), _caller);
      Assert::AreEqual("ControlDarkDark", Drawing::SystemColors::ControlDarkDark().Name(), _caller);
      Assert::AreEqual("Color [ControlDarkDark]", Drawing::SystemColors::ControlDarkDark().ToString(), _caller);
    }
    
    void ControlLight() {
      //Assert::AreEqual(0xFFE3E3E3u, (unsigned)Drawing::SystemColors::ControlLight().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ControlLight().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsSystemColor(), _caller);
      Assert::AreEqual("ControlLight", Drawing::SystemColors::ControlLight().Name(), _caller);
      Assert::AreEqual("Color [ControlLight]", Drawing::SystemColors::ControlLight().ToString(), _caller);
    }
    
    void ControlLightLight() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ControlLightLight().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ControlLightLight().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsSystemColor(), _caller);
      Assert::AreEqual("ControlLightLight", Drawing::SystemColors::ControlLightLight().Name(), _caller);
      Assert::AreEqual("Color [ControlLightLight]", Drawing::SystemColors::ControlLightLight().ToString(), _caller);
    }
    
    void ControlText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ControlText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ControlText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsSystemColor(), _caller);
      Assert::AreEqual("ControlText", Drawing::SystemColors::ControlText().Name(), _caller);
      Assert::AreEqual("Color [ControlText]", Drawing::SystemColors::ControlText().ToString(), _caller);
    }
    
    void Desktop() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::Desktop().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::Desktop().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsSystemColor(), _caller);
      Assert::AreEqual("Desktop", Drawing::SystemColors::Desktop().Name(), _caller);
      Assert::AreEqual("Color [Desktop]", Drawing::SystemColors::Desktop().ToString(), _caller);
    }
    
    void GrayText() {
      //Assert::AreEqual(0xFF6D6D6Du, (unsigned)Drawing::SystemColors::GrayText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::GrayText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsSystemColor(), _caller);
      Assert::AreEqual("GrayText", Drawing::SystemColors::GrayText().Name(), _caller);
      Assert::AreEqual("Color [GrayText]", Drawing::SystemColors::GrayText().ToString(), _caller);
    }
    
    void Highlight() {
      //Assert::AreEqual(0xFF3399FFu, (unsigned)Drawing::SystemColors::Highlight().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::Highlight().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsSystemColor(), _caller);
      Assert::AreEqual("Highlight", Drawing::SystemColors::Highlight().Name(), _caller);
      Assert::AreEqual("Color [Highlight]", Drawing::SystemColors::Highlight().ToString(), _caller);
    }
    
    void HighlightText() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::HighlightText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::HighlightText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsSystemColor(), _caller);
      Assert::AreEqual("HighlightText", Drawing::SystemColors::HighlightText().Name(), _caller);
      Assert::AreEqual("Color [HighlightText]", Drawing::SystemColors::HighlightText().ToString(), _caller);
    }
    
    void HotTrack() {
      //Assert::AreEqual(0xFF0066CCu, (unsigned)Drawing::SystemColors::HotTrack().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::HotTrack().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsSystemColor(), _caller);
      Assert::AreEqual("HotTrack", Drawing::SystemColors::HotTrack().Name(), _caller);
      Assert::AreEqual("Color [HotTrack]", Drawing::SystemColors::HotTrack().ToString(), _caller);
    }
    
    void InactiveBorder() {
      //Assert::AreEqual(0xFFF4F7FCu, (unsigned)Drawing::SystemColors::InactiveBorder().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::InactiveBorder().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsSystemColor(), _caller);
      Assert::AreEqual("InactiveBorder", Drawing::SystemColors::InactiveBorder().Name(), _caller);
      Assert::AreEqual("Color [InactiveBorder]", Drawing::SystemColors::InactiveBorder().ToString(), _caller);
    }
    
    void InactiveCaption() {
      //Assert::AreEqual(0xFFBFCDDBu, (unsigned)Drawing::SystemColors::InactiveCaption().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaption().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsSystemColor(), _caller);
      Assert::AreEqual("InactiveCaption", Drawing::SystemColors::InactiveCaption().Name(), _caller);
      Assert::AreEqual("Color [InactiveCaption]", Drawing::SystemColors::InactiveCaption().ToString(), _caller);
    }
    
    void InactiveCaptionText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::InactiveCaptionText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaptionText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsSystemColor(), _caller);
      Assert::AreEqual("InactiveCaptionText", Drawing::SystemColors::InactiveCaptionText().Name(), _caller);
      Assert::AreEqual("Color [InactiveCaptionText]", Drawing::SystemColors::InactiveCaptionText().ToString(), _caller);
    }
    
    void Info() {
      //Assert::AreEqual(0xFFFFFFE1u, (unsigned)Drawing::SystemColors::Info().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::Info().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Info().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Info().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Info().IsSystemColor(), _caller);
      Assert::AreEqual("Info", Drawing::SystemColors::Info().Name(), _caller);
      Assert::AreEqual("Color [Info]", Drawing::SystemColors::Info().ToString(), _caller);
    }
    
    void InfoText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::InfoText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::InfoText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsSystemColor(), _caller);
      Assert::AreEqual("InfoText", Drawing::SystemColors::InfoText().Name(), _caller);
      Assert::AreEqual("Color [InfoText]", Drawing::SystemColors::InfoText().ToString(), _caller);
    }
    
    void Menu() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Menu().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::Menu().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsSystemColor(), _caller);
      Assert::AreEqual("Menu", Drawing::SystemColors::Menu().Name(), _caller);
      Assert::AreEqual("Color [Menu]", Drawing::SystemColors::Menu().ToString(), _caller);
    }
    
    void MenuText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::MenuText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::MenuText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsSystemColor(), _caller);
      Assert::AreEqual("MenuText", Drawing::SystemColors::MenuText().Name(), _caller);
      Assert::AreEqual("Color [MenuText]", Drawing::SystemColors::MenuText().ToString(), _caller);
    }
    
    void ScrollBar() {
      //Assert::AreEqual(0xFFC8C8C8u, (unsigned)Drawing::SystemColors::ScrollBar().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ScrollBar().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsSystemColor(), _caller);
      Assert::AreEqual("ScrollBar", Drawing::SystemColors::ScrollBar().Name(), _caller);
      Assert::AreEqual("Color [ScrollBar]", Drawing::SystemColors::ScrollBar().ToString(), _caller);
    }
    
    void Window() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::Window().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::Window().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Window().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Window().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::Window().IsSystemColor(), _caller);
      Assert::AreEqual("Window", Drawing::SystemColors::Window().Name(), _caller);
      Assert::AreEqual("Color [Window]", Drawing::SystemColors::Window().ToString(), _caller);
    }
    
    void WindowFrame() {
      //Assert::AreEqual(0xFF646464u, (unsigned)Drawing::SystemColors::WindowFrame().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::WindowFrame().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsSystemColor(), _caller);
      Assert::AreEqual("WindowFrame", Drawing::SystemColors::WindowFrame().Name(), _caller);
      Assert::AreEqual("Color [WindowFrame]", Drawing::SystemColors::WindowFrame().ToString(), _caller);
    }
    
    void WindowText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::WindowText().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::WindowText().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsSystemColor(), _caller);
      Assert::AreEqual("WindowText", Drawing::SystemColors::WindowText().Name(), _caller);
      Assert::AreEqual("Color [WindowText]", Drawing::SystemColors::WindowText().ToString(), _caller);
    }
    
    void ButtonFace() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonFace().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ButtonFace().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsSystemColor(), _caller);
      Assert::AreEqual("ButtonFace", Drawing::SystemColors::ButtonFace().Name(), _caller);
      Assert::AreEqual("Color [ButtonFace]", Drawing::SystemColors::ButtonFace().ToString(), _caller);
    }
    
    void ButtonHighlight() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ButtonHighlight().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ButtonHighlight().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsSystemColor(), _caller);
      Assert::AreEqual("ButtonHighlight", Drawing::SystemColors::ButtonHighlight().Name(), _caller);
      Assert::AreEqual("Color [ButtonHighlight]", Drawing::SystemColors::ButtonHighlight().ToString(), _caller);
    }
    
    void ButtonShadow() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonShadow().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::ButtonShadow().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsSystemColor(), _caller);
      Assert::AreEqual("ButtonShadow", Drawing::SystemColors::ButtonShadow().Name(), _caller);
      Assert::AreEqual("Color [ButtonShadow]", Drawing::SystemColors::ButtonShadow().ToString(), _caller);
    }
    
    void GradientActiveCaption() {
      //Assert::AreEqual(0xFFB9D1EAu, (unsigned)Drawing::SystemColors::GradientActiveCaption().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::GradientActiveCaption().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsSystemColor(), _caller);
      Assert::AreEqual("GradientActiveCaption", Drawing::SystemColors::GradientActiveCaption().Name(), _caller);
      Assert::AreEqual("Color [GradientActiveCaption]", Drawing::SystemColors::GradientActiveCaption().ToString(), _caller);
    }
    
    void GradientInactiveCaption() {
      //Assert::AreEqual(0xFFD7E4F2u, (unsigned)Drawing::SystemColors::GradientInactiveCaption().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::GradientInactiveCaption().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsSystemColor(), _caller);
      Assert::AreEqual("GradientInactiveCaption", Drawing::SystemColors::GradientInactiveCaption().Name(), _caller);
      Assert::AreEqual("Color [GradientInactiveCaption]", Drawing::SystemColors::GradientInactiveCaption().ToString(), _caller);
    }
    
    void MenuBar() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::MenuBar().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::MenuBar().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsSystemColor(), _caller);
      Assert::AreEqual("MenuBar", Drawing::SystemColors::MenuBar().Name(), _caller);
      Assert::AreEqual("Color [MenuBar]", Drawing::SystemColors::MenuBar().ToString(), _caller);
    }
    
    void MenuHighlight() {
      //Assert::AreEqual(0xFF3399FFu, (unsigned)Drawing::SystemColors::MenuHighlight().ToArgb(), _caller);
      Assert::IsFalse(Drawing::SystemColors::MenuHighlight().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsNamedColor(), _caller);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsSystemColor(), _caller);
      Assert::AreEqual("MenuHighlight", Drawing::SystemColors::MenuHighlight().Name(), _caller);
      Assert::AreEqual("Color [MenuHighlight]", Drawing::SystemColors::MenuHighlight().ToString(), _caller);
    }
  };
  
  _AddTest(SystemColors, ActiveBorder)
  _AddTest(SystemColors, ActiveCaption)
  _AddTest(SystemColors, ActiveCaptionText)
  _AddTest(SystemColors, AppWorkspace)
  _AddTest(SystemColors, Control)
  _AddTest(SystemColors, ControlDark)
  _AddTest(SystemColors, ControlDarkDark)
  _AddTest(SystemColors, ControlLight)
  _AddTest(SystemColors, ControlLightLight)
  _AddTest(SystemColors, ControlText)
  _AddTest(SystemColors, Desktop)
  _AddTest(SystemColors, GrayText)
  _AddTest(SystemColors, Highlight)
  _AddTest(SystemColors, HighlightText)
  _AddTest(SystemColors, HotTrack)
  _AddTest(SystemColors, InactiveBorder)
  _AddTest(SystemColors, InactiveCaption)
  _AddTest(SystemColors, InactiveCaptionText)
  _AddTest(SystemColors, Info)
  _AddTest(SystemColors, InfoText)
  _AddTest(SystemColors, Menu)
  _AddTest(SystemColors, MenuText)
  _AddTest(SystemColors, ScrollBar)
  _AddTest(SystemColors, Window)
  _AddTest(SystemColors, WindowFrame)
  _AddTest(SystemColors, WindowText)
  _AddTest(SystemColors, ButtonFace)
  _AddTest(SystemColors, ButtonHighlight)
  _AddTest(SystemColors, ButtonShadow)
  _AddTest(SystemColors, GradientActiveCaption)
  _AddTest(SystemColors, GradientInactiveCaption)
  _AddTest(SystemColors, MenuBar)
  _AddTest(SystemColors, MenuHighlight)
}
