#include <Switch/System/Drawing/SystemColors.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(SystemColorTest, ActiveBorder) {
    //ASSERT_EQ(0xFFB4B4B4u, (unsigned)Drawing::SystemColors::ActiveBorder().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ActiveBorder().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ActiveBorder().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ActiveBorder().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ActiveBorder().IsSystemColor());
    ASSERT_EQ("ActiveBorder", Drawing::SystemColors::ActiveBorder().Name());
    ASSERT_EQ("Color [ActiveBorder]", Drawing::SystemColors::ActiveBorder().ToString());
  }

  TEST(SystemColorTest, ActiveCaption) {
    //ASSERT_EQ(0xFF99B4D1u, (unsigned)Drawing::SystemColors::ActiveCaption().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ActiveCaption().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ActiveCaption().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ActiveCaption().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ActiveCaption().IsSystemColor());
    ASSERT_EQ("ActiveCaption", Drawing::SystemColors::ActiveCaption().Name());
    ASSERT_EQ("Color [ActiveCaption]", Drawing::SystemColors::ActiveCaption().ToString());
  }

  TEST(SystemColorTest, ActiveCaptionText) {
    //ASSERT_EQ(0xFF000000u, (unsigned)Drawing::SystemColors::ActiveCaptionText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ActiveCaptionText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ActiveCaptionText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ActiveCaptionText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ActiveCaptionText().IsSystemColor());
    ASSERT_EQ("ActiveCaptionText", Drawing::SystemColors::ActiveCaptionText().Name());
    ASSERT_EQ("Color [ActiveCaptionText]", Drawing::SystemColors::ActiveCaptionText().ToString());
  }

  TEST(SystemColorTest, AppWorkspace) {
    //ASSERT_EQ(0xFFABABABu, (unsigned)Drawing::SystemColors::AppWorkspace().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::AppWorkspace().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::AppWorkspace().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::AppWorkspace().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::AppWorkspace().IsSystemColor());
    ASSERT_EQ("AppWorkspace", Drawing::SystemColors::AppWorkspace().Name());
    ASSERT_EQ("Color [AppWorkspace]", Drawing::SystemColors::AppWorkspace().ToString());
  }

  TEST(SystemColorTest, Control) {
    //ASSERT_EQ(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Control().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::Control().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::Control().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::Control().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::Control().IsSystemColor());
    ASSERT_EQ("Control", Drawing::SystemColors::Control().Name());
    ASSERT_EQ("Color [Control]", Drawing::SystemColors::Control().ToString());
  }

  TEST(SystemColorTest, ControlDark) {
    //ASSERT_EQ(0xFFA0A0A0u, (unsigned)Drawing::SystemColors::ControlDark().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ControlDark().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ControlDark().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlDark().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlDark().IsSystemColor());
    ASSERT_EQ("ControlDark", Drawing::SystemColors::ControlDark().Name());
    ASSERT_EQ("Color [ControlDark]", Drawing::SystemColors::ControlDark().ToString());
  }

  TEST(SystemColorTest, ControlDarkDark) {
    //ASSERT_EQ(0xFF696969u, (unsigned)Drawing::SystemColors::ControlDarkDark().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ControlDarkDark().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ControlDarkDark().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlDarkDark().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlDarkDark().IsSystemColor());
    ASSERT_EQ("ControlDarkDark", Drawing::SystemColors::ControlDarkDark().Name());
    ASSERT_EQ("Color [ControlDarkDark]", Drawing::SystemColors::ControlDarkDark().ToString());
  }

  TEST(SystemColorTest, ControlLight) {
    //ASSERT_EQ(0xFFE3E3E3u, (unsigned)Drawing::SystemColors::ControlLight().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ControlLight().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ControlLight().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlLight().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlLight().IsSystemColor());
    ASSERT_EQ("ControlLight", Drawing::SystemColors::ControlLight().Name());
    ASSERT_EQ("Color [ControlLight]", Drawing::SystemColors::ControlLight().ToString());
  }

  TEST(SystemColorTest, ControlLightLight) {
    //ASSERT_EQ(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ControlLightLight().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ControlLightLight().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ControlLightLight().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlLightLight().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlLightLight().IsSystemColor());
    ASSERT_EQ("ControlLightLight", Drawing::SystemColors::ControlLightLight().Name());
    ASSERT_EQ("Color [ControlLightLight]", Drawing::SystemColors::ControlLightLight().ToString());
  }

  TEST(SystemColorTest, ControlText) {
    //ASSERT_EQ(0xFF000000u, (unsigned)Drawing::SystemColors::ControlText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ControlText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ControlText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ControlText().IsSystemColor());
    ASSERT_EQ("ControlText", Drawing::SystemColors::ControlText().Name());
    ASSERT_EQ("Color [ControlText]", Drawing::SystemColors::ControlText().ToString());
  }

  TEST(SystemColorTest, Desktop) {
    //ASSERT_EQ(0xFF000000u, (unsigned)Drawing::SystemColors::Desktop().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::Desktop().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::Desktop().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::Desktop().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::Desktop().IsSystemColor());
    ASSERT_EQ("Desktop", Drawing::SystemColors::Desktop().Name());
    ASSERT_EQ("Color [Desktop]", Drawing::SystemColors::Desktop().ToString());
  }

  TEST(SystemColorTest, GrayText) {
    //ASSERT_EQ(0xFF6D6D6Du, (unsigned)Drawing::SystemColors::GrayText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::GrayText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::GrayText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::GrayText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::GrayText().IsSystemColor());
    ASSERT_EQ("GrayText", Drawing::SystemColors::GrayText().Name());
    ASSERT_EQ("Color [GrayText]", Drawing::SystemColors::GrayText().ToString());
  }

  TEST(SystemColorTest, Highlight) {
    //ASSERT_EQ(0xFF3399FFu, (unsigned)Drawing::SystemColors::Highlight().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::Highlight().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::Highlight().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::Highlight().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::Highlight().IsSystemColor());
    ASSERT_EQ("Highlight", Drawing::SystemColors::Highlight().Name());
    ASSERT_EQ("Color [Highlight]", Drawing::SystemColors::Highlight().ToString());
  }

  TEST(SystemColorTest, HighlightText) {
    //ASSERT_EQ(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::HighlightText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::HighlightText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::HighlightText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::HighlightText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::HighlightText().IsSystemColor());
    ASSERT_EQ("HighlightText", Drawing::SystemColors::HighlightText().Name());
    ASSERT_EQ("Color [HighlightText]", Drawing::SystemColors::HighlightText().ToString());
  }

  TEST(SystemColorTest, HotTrack) {
    //ASSERT_EQ(0xFF0066CCu, (unsigned)Drawing::SystemColors::HotTrack().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::HotTrack().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::HotTrack().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::HotTrack().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::HotTrack().IsSystemColor());
    ASSERT_EQ("HotTrack", Drawing::SystemColors::HotTrack().Name());
    ASSERT_EQ("Color [HotTrack]", Drawing::SystemColors::HotTrack().ToString());
  }

  TEST(SystemColorTest, InactiveBorder) {
    //ASSERT_EQ(0xFFF4F7FCu, (unsigned)Drawing::SystemColors::InactiveBorder().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::InactiveBorder().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::InactiveBorder().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::InactiveBorder().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::InactiveBorder().IsSystemColor());
    ASSERT_EQ("InactiveBorder", Drawing::SystemColors::InactiveBorder().Name());
    ASSERT_EQ("Color [InactiveBorder]", Drawing::SystemColors::InactiveBorder().ToString());
  }

  TEST(SystemColorTest, InactiveCaption) {
    //ASSERT_EQ(0xFFBFCDDBu, (unsigned)Drawing::SystemColors::InactiveCaption().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::InactiveCaption().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::InactiveCaption().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::InactiveCaption().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::InactiveCaption().IsSystemColor());
    ASSERT_EQ("InactiveCaption", Drawing::SystemColors::InactiveCaption().Name());
    ASSERT_EQ("Color [InactiveCaption]", Drawing::SystemColors::InactiveCaption().ToString());
  }

  TEST(SystemColorTest, InactiveCaptionText) {
    //ASSERT_EQ(0xFF000000u, (unsigned)Drawing::SystemColors::InactiveCaptionText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::InactiveCaptionText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::InactiveCaptionText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::InactiveCaptionText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::InactiveCaptionText().IsSystemColor());
    ASSERT_EQ("InactiveCaptionText", Drawing::SystemColors::InactiveCaptionText().Name());
    ASSERT_EQ("Color [InactiveCaptionText]", Drawing::SystemColors::InactiveCaptionText().ToString());
  }

  TEST(SystemColorTest, Info) {
    //ASSERT_EQ(0xFFFFFFE1u, (unsigned)Drawing::SystemColors::Info().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::Info().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::Info().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::Info().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::Info().IsSystemColor());
    ASSERT_EQ("Info", Drawing::SystemColors::Info().Name());
    ASSERT_EQ("Color [Info]", Drawing::SystemColors::Info().ToString());
  }

  TEST(SystemColorTest, InfoText) {
    //ASSERT_EQ(0xFF000000u, (unsigned)Drawing::SystemColors::InfoText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::InfoText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::InfoText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::InfoText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::InfoText().IsSystemColor());
    ASSERT_EQ("InfoText", Drawing::SystemColors::InfoText().Name());
    ASSERT_EQ("Color [InfoText]", Drawing::SystemColors::InfoText().ToString());
  }

  TEST(SystemColorTest, Menu) {
    //ASSERT_EQ(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::Menu().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::Menu().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::Menu().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::Menu().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::Menu().IsSystemColor());
    ASSERT_EQ("Menu", Drawing::SystemColors::Menu().Name());
    ASSERT_EQ("Color [Menu]", Drawing::SystemColors::Menu().ToString());
  }

  TEST(SystemColorTest, MenuText) {
    //ASSERT_EQ(0xFF000000u, (unsigned)Drawing::SystemColors::MenuText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::MenuText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::MenuText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::MenuText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::MenuText().IsSystemColor());
    ASSERT_EQ("MenuText", Drawing::SystemColors::MenuText().Name());
    ASSERT_EQ("Color [MenuText]", Drawing::SystemColors::MenuText().ToString());
  }

  TEST(SystemColorTest, ScrollBar) {
    //ASSERT_EQ(0xFFC8C8C8u, (unsigned)Drawing::SystemColors::ScrollBar().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ScrollBar().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ScrollBar().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ScrollBar().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ScrollBar().IsSystemColor());
    ASSERT_EQ("ScrollBar", Drawing::SystemColors::ScrollBar().Name());
    ASSERT_EQ("Color [ScrollBar]", Drawing::SystemColors::ScrollBar().ToString());
  }

  TEST(SystemColorTest, Window) {
    //ASSERT_EQ(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::Window().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::Window().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::Window().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::Window().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::Window().IsSystemColor());
    ASSERT_EQ("Window", Drawing::SystemColors::Window().Name());
    ASSERT_EQ("Color [Window]", Drawing::SystemColors::Window().ToString());
  }

  TEST(SystemColorTest, WindowFrame) {
    //ASSERT_EQ(0xFF646464u, (unsigned)Drawing::SystemColors::WindowFrame().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::WindowFrame().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::WindowFrame().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::WindowFrame().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::WindowFrame().IsSystemColor());
    ASSERT_EQ("WindowFrame", Drawing::SystemColors::WindowFrame().Name());
    ASSERT_EQ("Color [WindowFrame]", Drawing::SystemColors::WindowFrame().ToString());
  }

  TEST(SystemColorTest, WindowText) {
    //ASSERT_EQ(0xFF000000u, (unsigned)Drawing::SystemColors::WindowText().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::WindowText().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::WindowText().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::WindowText().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::WindowText().IsSystemColor());
    ASSERT_EQ("WindowText", Drawing::SystemColors::WindowText().Name());
    ASSERT_EQ("Color [WindowText]", Drawing::SystemColors::WindowText().ToString());
  }

  TEST(SystemColorTest, ButtonFace) {
    //ASSERT_EQ(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonFace().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ButtonFace().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ButtonFace().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ButtonFace().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ButtonFace().IsSystemColor());
    ASSERT_EQ("ButtonFace", Drawing::SystemColors::ButtonFace().Name());
    ASSERT_EQ("Color [ButtonFace]", Drawing::SystemColors::ButtonFace().ToString());
  }

  TEST(SystemColorTest, ButtonHighlight) {
    //ASSERT_EQ(0xFFFFFFFFu, (unsigned)Drawing::SystemColors::ButtonHighlight().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ButtonHighlight().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ButtonHighlight().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ButtonHighlight().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ButtonHighlight().IsSystemColor());
    ASSERT_EQ("ButtonHighlight", Drawing::SystemColors::ButtonHighlight().Name());
    ASSERT_EQ("Color [ButtonHighlight]", Drawing::SystemColors::ButtonHighlight().ToString());
  }

  TEST(SystemColorTest, ButtonShadow) {
    //ASSERT_EQ(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::ButtonShadow().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::ButtonShadow().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::ButtonShadow().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::ButtonShadow().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::ButtonShadow().IsSystemColor());
    ASSERT_EQ("ButtonShadow", Drawing::SystemColors::ButtonShadow().Name());
    ASSERT_EQ("Color [ButtonShadow]", Drawing::SystemColors::ButtonShadow().ToString());
  }

  TEST(SystemColorTest, GradientActiveCaption) {
    //ASSERT_EQ(0xFFB9D1EAu, (unsigned)Drawing::SystemColors::GradientActiveCaption().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::GradientActiveCaption().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::GradientActiveCaption().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::GradientActiveCaption().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::GradientActiveCaption().IsSystemColor());
    ASSERT_EQ("GradientActiveCaption", Drawing::SystemColors::GradientActiveCaption().Name());
    ASSERT_EQ("Color [GradientActiveCaption]", Drawing::SystemColors::GradientActiveCaption().ToString());
  }

  TEST(SystemColorTest, GradientInactiveCaption) {
    //ASSERT_EQ(0xFFD7E4F2u, (unsigned)Drawing::SystemColors::GradientInactiveCaption().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::GradientInactiveCaption().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::GradientInactiveCaption().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::GradientInactiveCaption().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::GradientInactiveCaption().IsSystemColor());
    ASSERT_EQ("GradientInactiveCaption", Drawing::SystemColors::GradientInactiveCaption().Name());
    ASSERT_EQ("Color [GradientInactiveCaption]", Drawing::SystemColors::GradientInactiveCaption().ToString());
  }

  TEST(SystemColorTest, MenuBar) {
    //ASSERT_EQ(0xFFF0F0F0u, (unsigned)Drawing::SystemColors::MenuBar().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::MenuBar().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::MenuBar().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::MenuBar().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::MenuBar().IsSystemColor());
    ASSERT_EQ("MenuBar", Drawing::SystemColors::MenuBar().Name());
    ASSERT_EQ("Color [MenuBar]", Drawing::SystemColors::MenuBar().ToString());
  }

  TEST(SystemColorTest, MenuHighlight) {
    //ASSERT_EQ(0xFF3399FFu, (unsigned)Drawing::SystemColors::MenuHighlight().ToArgb());
    ASSERT_FALSE(Drawing::SystemColors::MenuHighlight().IsEmpty());
    ASSERT_TRUE(Drawing::SystemColors::MenuHighlight().IsKnownColor());
    ASSERT_TRUE(Drawing::SystemColors::MenuHighlight().IsNamedColor());
    ASSERT_TRUE(Drawing::SystemColors::MenuHighlight().IsSystemColor());
    ASSERT_EQ("MenuHighlight", Drawing::SystemColors::MenuHighlight().Name());
    ASSERT_EQ("Color [MenuHighlight]", Drawing::SystemColors::MenuHighlight().ToString());
  }
}

