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
      //Assert::AreEqual(0xFFB4B4B4u, (unsigned)Drawing::SystemColors::ActiveBorder().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveBorder().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ActiveBorder", Drawing::SystemColors::ActiveBorder().Name(), sw_current_information);
      Assert::AreEqual("Color [ActiveBorder]", Drawing::SystemColors::ActiveBorder().ToString(), sw_current_information);
    }
    
    void ActiveCaption() {
      //Assert::AreEqual(0xFF99B4D1u, (unsigned)Drawing::SystemColors::ActiveCaption().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaption().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ActiveCaption", Drawing::SystemColors::ActiveCaption().Name(), sw_current_information);
      Assert::AreEqual("Color [ActiveCaption]", Drawing::SystemColors::ActiveCaption().ToString(), sw_current_information);
    }
    
    void ActiveCaptionText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ActiveCaptionText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaptionText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ActiveCaptionText", Drawing::SystemColors::ActiveCaptionText().Name(), sw_current_information);
      Assert::AreEqual("Color [ActiveCaptionText]", Drawing::SystemColors::ActiveCaptionText().ToString(), sw_current_information);
    }
    
    void AppWorkspace() {
      //Assert::AreEqual(0xFFABABABu, (unsigned)Drawing::SystemColors::AppWorkspace().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::AppWorkspace().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace().IsSystemColor(), sw_current_information);
      Assert::AreEqual("AppWorkspace", Drawing::SystemColors::AppWorkspace().Name(), sw_current_information);
      Assert::AreEqual("Color [AppWorkspace]", Drawing::SystemColors::AppWorkspace().ToString(), sw_current_information);
    }
    
    void Control() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Control().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::Control().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Control().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Control().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Control().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Control", Drawing::SystemColors::Control().Name(), sw_current_information);
      Assert::AreEqual("Color [Control]", Drawing::SystemColors::Control().ToString(), sw_current_information);
    }
    
    void ControlDark() {
      //Assert::AreEqual(0xFFA0A0A0u, (unsigned)Drawing::SystemColors::ControlDark().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlDark().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ControlDark", Drawing::SystemColors::ControlDark().Name(), sw_current_information);
      Assert::AreEqual("Color [ControlDark]", Drawing::SystemColors::ControlDark().ToString(), sw_current_information);
    }
    
    void ControlDarkDark() {
      //Assert::AreEqual(0xFF696969u, (unsigned)Drawing::SystemColors::ControlDarkDark().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlDarkDark().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ControlDarkDark", Drawing::SystemColors::ControlDarkDark().Name(), sw_current_information);
      Assert::AreEqual("Color [ControlDarkDark]", Drawing::SystemColors::ControlDarkDark().ToString(), sw_current_information);
    }
    
    void ControlLight() {
      //Assert::AreEqual(0xFFE3E3E3u, (unsigned)Drawing::SystemColors::ControlLight().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlLight().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ControlLight", Drawing::SystemColors::ControlLight().Name(), sw_current_information);
      Assert::AreEqual("Color [ControlLight]", Drawing::SystemColors::ControlLight().ToString(), sw_current_information);
    }
    
    void ControlLightLight() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ControlLightLight().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlLightLight().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ControlLightLight", Drawing::SystemColors::ControlLightLight().Name(), sw_current_information);
      Assert::AreEqual("Color [ControlLightLight]", Drawing::SystemColors::ControlLightLight().ToString(), sw_current_information);
    }
    
    void ControlText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ControlText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ControlText", Drawing::SystemColors::ControlText().Name(), sw_current_information);
      Assert::AreEqual("Color [ControlText]", Drawing::SystemColors::ControlText().ToString(), sw_current_information);
    }
    
    void Desktop() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::Desktop().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::Desktop().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Desktop", Drawing::SystemColors::Desktop().Name(), sw_current_information);
      Assert::AreEqual("Color [Desktop]", Drawing::SystemColors::Desktop().ToString(), sw_current_information);
    }
    
    void GrayText() {
      //Assert::AreEqual(0xFF6D6D6Du, (unsigned)Drawing::SystemColors::GrayText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::GrayText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("GrayText", Drawing::SystemColors::GrayText().Name(), sw_current_information);
      Assert::AreEqual("Color [GrayText]", Drawing::SystemColors::GrayText().ToString(), sw_current_information);
    }
    
    void Highlight() {
      //Assert::AreEqual(0xFF3399FFu, (unsigned)Drawing::SystemColors::Highlight().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::Highlight().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Highlight", Drawing::SystemColors::Highlight().Name(), sw_current_information);
      Assert::AreEqual("Color [Highlight]", Drawing::SystemColors::Highlight().ToString(), sw_current_information);
    }
    
    void HighlightText() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::HighlightText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::HighlightText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("HighlightText", Drawing::SystemColors::HighlightText().Name(), sw_current_information);
      Assert::AreEqual("Color [HighlightText]", Drawing::SystemColors::HighlightText().ToString(), sw_current_information);
    }
    
    void HotTrack() {
      //Assert::AreEqual(0xFF0066CCu, (unsigned)Drawing::SystemColors::HotTrack().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::HotTrack().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack().IsSystemColor(), sw_current_information);
      Assert::AreEqual("HotTrack", Drawing::SystemColors::HotTrack().Name(), sw_current_information);
      Assert::AreEqual("Color [HotTrack]", Drawing::SystemColors::HotTrack().ToString(), sw_current_information);
    }
    
    void InactiveBorder() {
      //Assert::AreEqual(0xFFF4F7FCu, (unsigned)Drawing::SystemColors::InactiveBorder().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveBorder().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder().IsSystemColor(), sw_current_information);
      Assert::AreEqual("InactiveBorder", Drawing::SystemColors::InactiveBorder().Name(), sw_current_information);
      Assert::AreEqual("Color [InactiveBorder]", Drawing::SystemColors::InactiveBorder().ToString(), sw_current_information);
    }
    
    void InactiveCaption() {
      //Assert::AreEqual(0xFFBFCDDBu, (unsigned)Drawing::SystemColors::InactiveCaption().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaption().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption().IsSystemColor(), sw_current_information);
      Assert::AreEqual("InactiveCaption", Drawing::SystemColors::InactiveCaption().Name(), sw_current_information);
      Assert::AreEqual("Color [InactiveCaption]", Drawing::SystemColors::InactiveCaption().ToString(), sw_current_information);
    }
    
    void InactiveCaptionText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::InactiveCaptionText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaptionText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("InactiveCaptionText", Drawing::SystemColors::InactiveCaptionText().Name(), sw_current_information);
      Assert::AreEqual("Color [InactiveCaptionText]", Drawing::SystemColors::InactiveCaptionText().ToString(), sw_current_information);
    }
    
    void Info() {
      //Assert::AreEqual(0xFFFFFFE1u, (unsigned)Drawing::SystemColors::Info().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::Info().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Info().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Info().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Info().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Info", Drawing::SystemColors::Info().Name(), sw_current_information);
      Assert::AreEqual("Color [Info]", Drawing::SystemColors::Info().ToString(), sw_current_information);
    }
    
    void InfoText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::InfoText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::InfoText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("InfoText", Drawing::SystemColors::InfoText().Name(), sw_current_information);
      Assert::AreEqual("Color [InfoText]", Drawing::SystemColors::InfoText().ToString(), sw_current_information);
    }
    
    void Menu() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Menu().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::Menu().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Menu", Drawing::SystemColors::Menu().Name(), sw_current_information);
      Assert::AreEqual("Color [Menu]", Drawing::SystemColors::Menu().ToString(), sw_current_information);
    }
    
    void MenuText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::MenuText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MenuText", Drawing::SystemColors::MenuText().Name(), sw_current_information);
      Assert::AreEqual("Color [MenuText]", Drawing::SystemColors::MenuText().ToString(), sw_current_information);
    }
    
    void ScrollBar() {
      //Assert::AreEqual(0xFFC8C8C8u, (unsigned)Drawing::SystemColors::ScrollBar().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ScrollBar().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ScrollBar", Drawing::SystemColors::ScrollBar().Name(), sw_current_information);
      Assert::AreEqual("Color [ScrollBar]", Drawing::SystemColors::ScrollBar().ToString(), sw_current_information);
    }
    
    void Window() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::Window().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::Window().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Window().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Window().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::Window().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Window", Drawing::SystemColors::Window().Name(), sw_current_information);
      Assert::AreEqual("Color [Window]", Drawing::SystemColors::Window().ToString(), sw_current_information);
    }
    
    void WindowFrame() {
      //Assert::AreEqual(0xFF646464u, (unsigned)Drawing::SystemColors::WindowFrame().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::WindowFrame().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame().IsSystemColor(), sw_current_information);
      Assert::AreEqual("WindowFrame", Drawing::SystemColors::WindowFrame().Name(), sw_current_information);
      Assert::AreEqual("Color [WindowFrame]", Drawing::SystemColors::WindowFrame().ToString(), sw_current_information);
    }
    
    void WindowText() {
      //Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::WindowText().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::WindowText().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText().IsSystemColor(), sw_current_information);
      Assert::AreEqual("WindowText", Drawing::SystemColors::WindowText().Name(), sw_current_information);
      Assert::AreEqual("Color [WindowText]", Drawing::SystemColors::WindowText().ToString(), sw_current_information);
    }
    
    void ButtonFace() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonFace().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonFace().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ButtonFace", Drawing::SystemColors::ButtonFace().Name(), sw_current_information);
      Assert::AreEqual("Color [ButtonFace]", Drawing::SystemColors::ButtonFace().ToString(), sw_current_information);
    }
    
    void ButtonHighlight() {
      //Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ButtonHighlight().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonHighlight().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ButtonHighlight", Drawing::SystemColors::ButtonHighlight().Name(), sw_current_information);
      Assert::AreEqual("Color [ButtonHighlight]", Drawing::SystemColors::ButtonHighlight().ToString(), sw_current_information);
    }
    
    void ButtonShadow() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonShadow().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonShadow().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ButtonShadow", Drawing::SystemColors::ButtonShadow().Name(), sw_current_information);
      Assert::AreEqual("Color [ButtonShadow]", Drawing::SystemColors::ButtonShadow().ToString(), sw_current_information);
    }
    
    void GradientActiveCaption() {
      //Assert::AreEqual(0xFFB9D1EAu, (unsigned)Drawing::SystemColors::GradientActiveCaption().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::GradientActiveCaption().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption().IsSystemColor(), sw_current_information);
      Assert::AreEqual("GradientActiveCaption", Drawing::SystemColors::GradientActiveCaption().Name(), sw_current_information);
      Assert::AreEqual("Color [GradientActiveCaption]", Drawing::SystemColors::GradientActiveCaption().ToString(), sw_current_information);
    }
    
    void GradientInactiveCaption() {
      //Assert::AreEqual(0xFFD7E4F2u, (unsigned)Drawing::SystemColors::GradientInactiveCaption().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::GradientInactiveCaption().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption().IsSystemColor(), sw_current_information);
      Assert::AreEqual("GradientInactiveCaption", Drawing::SystemColors::GradientInactiveCaption().Name(), sw_current_information);
      Assert::AreEqual("Color [GradientInactiveCaption]", Drawing::SystemColors::GradientInactiveCaption().ToString(), sw_current_information);
    }
    
    void MenuBar() {
      //Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::MenuBar().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuBar().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MenuBar", Drawing::SystemColors::MenuBar().Name(), sw_current_information);
      Assert::AreEqual("Color [MenuBar]", Drawing::SystemColors::MenuBar().ToString(), sw_current_information);
    }
    
    void MenuHighlight() {
      //Assert::AreEqual(0xFF3399FFu, (unsigned)Drawing::SystemColors::MenuHighlight().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuHighlight().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsNamedColor(), sw_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MenuHighlight", Drawing::SystemColors::MenuHighlight().Name(), sw_current_information);
      Assert::AreEqual("Color [MenuHighlight]", Drawing::SystemColors::MenuHighlight().ToString(), sw_current_information);
    }
  };
  
  sw_test(SystemColors, ActiveBorder)
  sw_test(SystemColors, ActiveCaption)
  sw_test(SystemColors, ActiveCaptionText)
  sw_test(SystemColors, AppWorkspace)
  sw_test(SystemColors, Control)
  sw_test(SystemColors, ControlDark)
  sw_test(SystemColors, ControlDarkDark)
  sw_test(SystemColors, ControlLight)
  sw_test(SystemColors, ControlLightLight)
  sw_test(SystemColors, ControlText)
  sw_test(SystemColors, Desktop)
  sw_test(SystemColors, GrayText)
  sw_test(SystemColors, Highlight)
  sw_test(SystemColors, HighlightText)
  sw_test(SystemColors, HotTrack)
  sw_test(SystemColors, InactiveBorder)
  sw_test(SystemColors, InactiveCaption)
  sw_test(SystemColors, InactiveCaptionText)
  sw_test(SystemColors, Info)
  sw_test(SystemColors, InfoText)
  sw_test(SystemColors, Menu)
  sw_test(SystemColors, MenuText)
  sw_test(SystemColors, ScrollBar)
  sw_test(SystemColors, Window)
  sw_test(SystemColors, WindowFrame)
  sw_test(SystemColors, WindowText)
  sw_test(SystemColors, ButtonFace)
  sw_test(SystemColors, ButtonHighlight)
  sw_test(SystemColors, ButtonShadow)
  sw_test(SystemColors, GradientActiveCaption)
  sw_test(SystemColors, GradientInactiveCaption)
  sw_test(SystemColors, MenuBar)
  sw_test(SystemColors, MenuHighlight)
}
