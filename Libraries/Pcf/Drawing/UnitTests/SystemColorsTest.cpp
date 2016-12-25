#include <Pcf/System/Drawing/SystemColors.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Drawing;
using namespace TUnit;

namespace PcfUnitTests {
  class SystemColors : public TestFixture {
  public:
    void ActiveBorder() {
      Assert::AreEqual(0xFFB4B4B4u, (unsigned)Drawing::SystemColors::ActiveBorder.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveBorder.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveBorder.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ActiveBorder", Drawing::SystemColors::ActiveBorder.Name(), pcf_current_information);
      Assert::AreEqual("Color [ActiveBorder]", Drawing::SystemColors::ActiveBorder.ToString(), pcf_current_information);
    }
    
    void ActiveCaption() {
      Assert::AreEqual(0xFF99B4D1u, (unsigned)Drawing::SystemColors::ActiveCaption.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaption.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaption.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ActiveCaption", Drawing::SystemColors::ActiveCaption.Name(), pcf_current_information);
      Assert::AreEqual("Color [ActiveCaption]", Drawing::SystemColors::ActiveCaption.ToString(), pcf_current_information);
    }
    
    void ActiveCaptionText() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ActiveCaptionText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ActiveCaptionText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ActiveCaptionText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ActiveCaptionText", Drawing::SystemColors::ActiveCaptionText.Name(), pcf_current_information);
      Assert::AreEqual("Color [ActiveCaptionText]", Drawing::SystemColors::ActiveCaptionText.ToString(), pcf_current_information);
    }
    
    void AppWorkspace() {
      Assert::AreEqual(0xFFABABABu, (unsigned)Drawing::SystemColors::AppWorkspace.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::AppWorkspace.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::AppWorkspace.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("AppWorkspace", Drawing::SystemColors::AppWorkspace.Name(), pcf_current_information);
      Assert::AreEqual("Color [AppWorkspace]", Drawing::SystemColors::AppWorkspace.ToString(), pcf_current_information);
    }
    
    void Control() {
      Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Control.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::Control.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Control.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Control.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Control.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Control", Drawing::SystemColors::Control.Name(), pcf_current_information);
      Assert::AreEqual("Color [Control]", Drawing::SystemColors::Control.ToString(), pcf_current_information);
    }
    
    void ControlDark() {
      Assert::AreEqual(0xFFA0A0A0u, (unsigned)Drawing::SystemColors::ControlDark.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlDark.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDark.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ControlDark", Drawing::SystemColors::ControlDark.Name(), pcf_current_information);
      Assert::AreEqual("Color [ControlDark]", Drawing::SystemColors::ControlDark.ToString(), pcf_current_information);
    }
    
    void ControlDarkDark() {
      Assert::AreEqual(0xFF696969u, (unsigned)Drawing::SystemColors::ControlDarkDark.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlDarkDark.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlDarkDark.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ControlDarkDark", Drawing::SystemColors::ControlDarkDark.Name(), pcf_current_information);
      Assert::AreEqual("Color [ControlDarkDark]", Drawing::SystemColors::ControlDarkDark.ToString(), pcf_current_information);
    }
    
    void ControlLight() {
      Assert::AreEqual(0xFFE3E3E3u, (unsigned)Drawing::SystemColors::ControlLight.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlLight.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLight.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ControlLight", Drawing::SystemColors::ControlLight.Name(), pcf_current_information);
      Assert::AreEqual("Color [ControlLight]", Drawing::SystemColors::ControlLight.ToString(), pcf_current_information);
    }
    
    void ControlLightLight() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ControlLightLight.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlLightLight.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlLightLight.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ControlLightLight", Drawing::SystemColors::ControlLightLight.Name(), pcf_current_information);
      Assert::AreEqual("Color [ControlLightLight]", Drawing::SystemColors::ControlLightLight.ToString(), pcf_current_information);
    }
    
    void ControlText() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::ControlText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ControlText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ControlText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ControlText", Drawing::SystemColors::ControlText.Name(), pcf_current_information);
      Assert::AreEqual("Color [ControlText]", Drawing::SystemColors::ControlText.ToString(), pcf_current_information);
    }
    
    void Desktop() {
      Assert::AreEqual(0xFF0076A3u, (unsigned)Drawing::SystemColors::Desktop.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::Desktop.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Desktop.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Desktop", Drawing::SystemColors::Desktop.Name(), pcf_current_information);
      Assert::AreEqual("Color [Desktop]", Drawing::SystemColors::Desktop.ToString(), pcf_current_information);
    }
    
    void GrayText() {
      Assert::AreEqual(0xFF6D6D6Du, (unsigned)Drawing::SystemColors::GrayText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::GrayText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GrayText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("GrayText", Drawing::SystemColors::GrayText.Name(), pcf_current_information);
      Assert::AreEqual("Color [GrayText]", Drawing::SystemColors::GrayText.ToString(), pcf_current_information);
    }
    
    void Highlight() {
      Assert::AreEqual(0xFF3399FFu, (unsigned)Drawing::SystemColors::Highlight.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::Highlight.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Highlight.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Highlight", Drawing::SystemColors::Highlight.Name(), pcf_current_information);
      Assert::AreEqual("Color [Highlight]", Drawing::SystemColors::Highlight.ToString(), pcf_current_information);
    }
    
    void HighlightText() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::HighlightText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::HighlightText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::HighlightText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("HighlightText", Drawing::SystemColors::HighlightText.Name(), pcf_current_information);
      Assert::AreEqual("Color [HighlightText]", Drawing::SystemColors::HighlightText.ToString(), pcf_current_information);
    }
    
    void HotTrack() {
      Assert::AreEqual(0xFF0066CCu, (unsigned)Drawing::SystemColors::HotTrack.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::HotTrack.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::HotTrack.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("HotTrack", Drawing::SystemColors::HotTrack.Name(), pcf_current_information);
      Assert::AreEqual("Color [HotTrack]", Drawing::SystemColors::HotTrack.ToString(), pcf_current_information);
    }
    
    void InactiveBorder() {
      Assert::AreEqual(0xFFF4F7FCu, (unsigned)Drawing::SystemColors::InactiveBorder.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveBorder.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveBorder.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("InactiveBorder", Drawing::SystemColors::InactiveBorder.Name(), pcf_current_information);
      Assert::AreEqual("Color [InactiveBorder]", Drawing::SystemColors::InactiveBorder.ToString(), pcf_current_information);
    }
    
    void InactiveCaption() {
      Assert::AreEqual(0xFFBFCDDBu, (unsigned)Drawing::SystemColors::InactiveCaption.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaption.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaption.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("InactiveCaption", Drawing::SystemColors::InactiveCaption.Name(), pcf_current_information);
      Assert::AreEqual("Color [InactiveCaption]", Drawing::SystemColors::InactiveCaption.ToString(), pcf_current_information);
    }
    
    void InactiveCaptionText() {
      Assert::AreEqual(0xFF434E54u, (unsigned)Drawing::SystemColors::InactiveCaptionText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::InactiveCaptionText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InactiveCaptionText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("InactiveCaptionText", Drawing::SystemColors::InactiveCaptionText.Name(), pcf_current_information);
      Assert::AreEqual("Color [InactiveCaptionText]", Drawing::SystemColors::InactiveCaptionText.ToString(), pcf_current_information);
    }
    
    void Info() {
      Assert::AreEqual(0xFFFFFFE1u, (unsigned)Drawing::SystemColors::Info.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::Info.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Info.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Info.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Info.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Info", Drawing::SystemColors::Info.Name(), pcf_current_information);
      Assert::AreEqual("Color [Info]", Drawing::SystemColors::Info.ToString(), pcf_current_information);
    }
    
    void InfoText() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::InfoText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::InfoText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::InfoText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("InfoText", Drawing::SystemColors::InfoText.Name(), pcf_current_information);
      Assert::AreEqual("Color [InfoText]", Drawing::SystemColors::InfoText.ToString(), pcf_current_information);
    }
    
    void Menu() {
      Assert::AreEqual(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Menu.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::Menu.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Menu.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Menu", Drawing::SystemColors::Menu.Name(), pcf_current_information);
      Assert::AreEqual("Color [Menu]", Drawing::SystemColors::Menu.ToString(), pcf_current_information);
    }
    
    void MenuText() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::MenuText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MenuText", Drawing::SystemColors::MenuText.Name(), pcf_current_information);
      Assert::AreEqual("Color [MenuText]", Drawing::SystemColors::MenuText.ToString(), pcf_current_information);
    }
    
    void ScrollBar() {
      Assert::AreEqual(0xFFC8C8C8u, (unsigned)Drawing::SystemColors::ScrollBar.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ScrollBar.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ScrollBar.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ScrollBar", Drawing::SystemColors::ScrollBar.Name(), pcf_current_information);
      Assert::AreEqual("Color [ScrollBar]", Drawing::SystemColors::ScrollBar.ToString(), pcf_current_information);
    }
    
    void Window() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::Window.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::Window.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Window.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Window.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::Window.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Window", Drawing::SystemColors::Window.Name(), pcf_current_information);
      Assert::AreEqual("Color [Window]", Drawing::SystemColors::Window.ToString(), pcf_current_information);
    }
    
    void WindowFrame() {
      Assert::AreEqual(0xFF646464u, (unsigned)Drawing::SystemColors::WindowFrame.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::WindowFrame.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowFrame.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("WindowFrame", Drawing::SystemColors::WindowFrame.Name(), pcf_current_information);
      Assert::AreEqual("Color [WindowFrame]", Drawing::SystemColors::WindowFrame.ToString(), pcf_current_information);
    }
    
    void WindowText() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::SystemColors::WindowText.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::WindowText.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::WindowText.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("WindowText", Drawing::SystemColors::WindowText.Name(), pcf_current_information);
      Assert::AreEqual("Color [WindowText]", Drawing::SystemColors::WindowText.ToString(), pcf_current_information);
    }
    
    void ButtonFace() {
      Assert::AreEqual(0xFFEDEDEDu, (unsigned)Drawing::SystemColors::ButtonFace.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonFace.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonFace.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ButtonFace", Drawing::SystemColors::ButtonFace.Name(), pcf_current_information);
      Assert::AreEqual("Color [ButtonFace]", Drawing::SystemColors::ButtonFace.ToString(), pcf_current_information);
    }
    
    void ButtonHighlight() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ButtonHighlight.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonHighlight.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonHighlight.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ButtonHighlight", Drawing::SystemColors::ButtonHighlight.Name(), pcf_current_information);
      Assert::AreEqual("Color [ButtonHighlight]", Drawing::SystemColors::ButtonHighlight.ToString(), pcf_current_information);
    }
    
    void ButtonShadow() {
      Assert::AreEqual(0xFFACA899u, (unsigned)Drawing::SystemColors::ButtonShadow.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::ButtonShadow.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::ButtonShadow.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ButtonShadow", Drawing::SystemColors::ButtonShadow.Name(), pcf_current_information);
      Assert::AreEqual("Color [ButtonShadow]", Drawing::SystemColors::ButtonShadow.ToString(), pcf_current_information);
    }
    
    void GradientActiveCaption() {
      Assert::AreEqual(0xFF3D95FFu, (unsigned)Drawing::SystemColors::GradientActiveCaption.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::GradientActiveCaption.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientActiveCaption.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("GradientActiveCaption", Drawing::SystemColors::GradientActiveCaption.Name(), pcf_current_information);
      Assert::AreEqual("Color [GradientActiveCaption]", Drawing::SystemColors::GradientActiveCaption.ToString(), pcf_current_information);
    }
    
    void GradientInactiveCaption() {
      Assert::AreEqual(0xFF9DB9EBu, (unsigned)Drawing::SystemColors::GradientInactiveCaption.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::GradientInactiveCaption.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::GradientInactiveCaption.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("GradientInactiveCaption", Drawing::SystemColors::GradientInactiveCaption.Name(), pcf_current_information);
      Assert::AreEqual("Color [GradientInactiveCaption]", Drawing::SystemColors::GradientInactiveCaption.ToString(), pcf_current_information);
    }
    
    void MenuBar() {
      Assert::AreEqual(0xFFEDEDEDu, (unsigned)Drawing::SystemColors::MenuBar.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuBar.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuBar.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MenuBar", Drawing::SystemColors::MenuBar.Name(), pcf_current_information);
      Assert::AreEqual("Color [MenuBar]", Drawing::SystemColors::MenuBar.ToString(), pcf_current_information);
    }
    
    void MenuHighlight() {
      Assert::AreEqual(0xFF316AC5u, (unsigned)Drawing::SystemColors::MenuHighlight.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::SystemColors::MenuHighlight.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight.IsNamedColor(), pcf_current_information);
      Assert::IsTrue(Drawing::SystemColors::MenuHighlight.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MenuHighlight", Drawing::SystemColors::MenuHighlight.Name(), pcf_current_information);
      Assert::AreEqual("Color [MenuHighlight]", Drawing::SystemColors::MenuHighlight.ToString(), pcf_current_information);
    }
  };
  
  pcf_test(SystemColors, ActiveBorder);
  pcf_test(SystemColors, ActiveCaption);
  pcf_test(SystemColors, ActiveCaptionText);
  pcf_test(SystemColors, AppWorkspace);
  pcf_test(SystemColors, Control);
  pcf_test(SystemColors, ControlDark);
  pcf_test(SystemColors, ControlDarkDark);
  pcf_test(SystemColors, ControlLight);
  pcf_test(SystemColors, ControlLightLight);
  pcf_test(SystemColors, ControlText);
  pcf_test(SystemColors, Desktop);
  pcf_test(SystemColors, GrayText);
  pcf_test(SystemColors, Highlight);
  pcf_test(SystemColors, HighlightText);
  pcf_test(SystemColors, HotTrack);
  pcf_test(SystemColors, InactiveBorder);
  pcf_test(SystemColors, InactiveCaption);
  pcf_test(SystemColors, InactiveCaptionText);
  pcf_test(SystemColors, Info);
  pcf_test(SystemColors, InfoText);
  pcf_test(SystemColors, Menu);
  pcf_test(SystemColors, MenuText);
  pcf_test(SystemColors, ScrollBar);
  pcf_test(SystemColors, Window);
  pcf_test(SystemColors, WindowFrame);
  pcf_test(SystemColors, WindowText);
  pcf_test(SystemColors, ButtonFace);
  pcf_test(SystemColors, ButtonHighlight);
  pcf_test(SystemColors, ButtonShadow);
  pcf_test(SystemColors, GradientActiveCaption);
  pcf_test(SystemColors, GradientInactiveCaption);
  pcf_test(SystemColors, MenuBar);
  pcf_test(SystemColors, MenuHighlight);
}
