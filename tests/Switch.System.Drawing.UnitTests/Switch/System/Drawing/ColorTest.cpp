#include <Switch/System/Drawing/Color.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  TEST(ColorTest, Ctor) {
    Drawing::Color color;
    ASSERT_EQ(0x00, color.A());
    ASSERT_EQ(0x00, color.R());
    ASSERT_EQ(0x00, color.G());
    ASSERT_EQ(0x00, color.B());
    ASSERT_TRUE(color.IsEmpty());
    ASSERT_FALSE(color.IsKnownColor());
    ASSERT_FALSE(color.IsNamedColor);
    ASSERT_FALSE(color.IsSystemColor());
    ASSERT_EQ("0", color.Name());
    ASSERT_EQ("Color [Empty]", color.ToString());
  }
  
  TEST(ColorTest, FromKnownColor) {
    ASSERT_EQ(0xFF, Drawing::Color::FromKnownColor(KnownColor::Black).A());
    ASSERT_EQ(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).R());
    ASSERT_EQ(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).G());
    ASSERT_EQ(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).B());
    ASSERT_FALSE(Drawing::Color::FromKnownColor(KnownColor::Black).IsEmpty());
    ASSERT_TRUE(Drawing::Color::FromKnownColor(KnownColor::Black).IsKnownColor());
    ASSERT_TRUE(Drawing::Color::FromKnownColor(KnownColor::Black).IsNamedColor());
    ASSERT_FALSE(Drawing::Color::FromKnownColor(KnownColor::Black).IsSystemColor());
    ASSERT_EQ("Black", Drawing::Color::FromKnownColor(KnownColor::Black).Name());
    ASSERT_EQ("Color [Black]", Drawing::Color::FromKnownColor(KnownColor::Black).ToString());
    
    ASSERT_THROW(Drawing::Color::FromKnownColor((KnownColor)34544), ArgumentException);
  }
  
  TEST(ColorTest, FromArgb) {
    ASSERT_EQ(0x12, Drawing::Color::FromArgb(0x12345678).A());
    ASSERT_EQ(0x34, Drawing::Color::FromArgb(0x12345678).R());
    ASSERT_EQ(0x56, Drawing::Color::FromArgb(0x12345678).G());
    ASSERT_EQ(0x78, Drawing::Color::FromArgb(0x12345678).B());
    ASSERT_FALSE(Drawing::Color::FromArgb(0x12345678).IsEmpty());
    ASSERT_FALSE(Drawing::Color::FromArgb(0x12345678).IsKnownColor());
    ASSERT_FALSE(Drawing::Color::FromArgb(0x12345678).IsNamedColor());
    ASSERT_FALSE(Drawing::Color::FromArgb(0x12345678).IsSystemColor());
    ASSERT_EQ("12345678", Drawing::Color::FromArgb(0x12345678).Name());
    ASSERT_EQ("Color [A=18, R=52, G=86, B=120]", Drawing::Color::FromArgb(0x12345678).ToString());
  }
  
  TEST(ColorTest, FromName) {
    Drawing::Color colorAliceBlue = Drawing::Color::FromName("AliceBlue");
    ASSERT_EQ(0xFF, colorAliceBlue.A());
    ASSERT_EQ(0xF0, colorAliceBlue.R());
    ASSERT_EQ(0xF8, colorAliceBlue.G());
    ASSERT_EQ(0xFF, colorAliceBlue.B());
    ASSERT_FALSE(colorAliceBlue.IsEmpty());
    ASSERT_TRUE(colorAliceBlue.IsKnownColor());
    ASSERT_TRUE(colorAliceBlue.IsNamedColor());
    ASSERT_FALSE(colorAliceBlue.IsSystemColor());
    ASSERT_EQ("AliceBlue", colorAliceBlue.Name());
    ASSERT_EQ("Color [AliceBlue]", colorAliceBlue.ToString());
  }
  
  TEST(ColorTest, Transparent) {
    ASSERT_EQ(0x00FFFFFF, Drawing::Color::Transparent().ToArgb());
    ASSERT_FALSE(Drawing::Color::Transparent().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Transparent().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Transparent().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Transparent().IsSystemColor());
    ASSERT_EQ("Transparent", Drawing::Color::Transparent().Name());
    ASSERT_EQ("Color [Transparent]", Drawing::Color::Transparent().ToString());
  }
  
  TEST(ColorTest, AliceBlue) {
    ASSERT_EQ(0xFFF0F8FFu, (unsigned)Drawing::Color::AliceBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::AliceBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::AliceBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::AliceBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::AliceBlue().IsSystemColor());
    ASSERT_EQ("AliceBlue", Drawing::Color::AliceBlue().Name());
    ASSERT_EQ("Color [AliceBlue]", Drawing::Color::AliceBlue().ToString());
  }
  
  TEST(ColorTest, AntiqueWhite) {
    ASSERT_EQ(0xFFFAEBD7u, (unsigned)Drawing::Color::AntiqueWhite().ToArgb());
    ASSERT_FALSE(Drawing::Color::AntiqueWhite().IsEmpty());
    ASSERT_TRUE(Drawing::Color::AntiqueWhite().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::AntiqueWhite().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::AntiqueWhite().IsSystemColor());
    ASSERT_EQ("AntiqueWhite", Drawing::Color::AntiqueWhite().Name());
    ASSERT_EQ("Color [AntiqueWhite]", Drawing::Color::AntiqueWhite().ToString());
  }
  
  TEST(ColorTest, Aqua) {
    ASSERT_EQ(0xFF00FFFFu, (unsigned)Drawing::Color::Aqua().ToArgb());
    ASSERT_FALSE(Drawing::Color::Aqua().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Aqua().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Aqua().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Aqua().IsSystemColor());
    ASSERT_EQ("Aqua", Drawing::Color::Aqua().Name());
    ASSERT_EQ("Color [Aqua]", Drawing::Color::Aqua().ToString());
  }
  
  TEST(ColorTest, Aquamarine) {
    ASSERT_EQ(0xFF7FFFD4u, (unsigned)Drawing::Color::Aquamarine().ToArgb());
    ASSERT_FALSE(Drawing::Color::Aquamarine().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Aquamarine().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Aquamarine().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Aquamarine().IsSystemColor());
    ASSERT_EQ("Aquamarine", Drawing::Color::Aquamarine().Name());
    ASSERT_EQ("Color [Aquamarine]", Drawing::Color::Aquamarine().ToString());
  }
  
  TEST(ColorTest, Azure) {
    ASSERT_EQ(0xFFF0FFFFu, (unsigned)Drawing::Color::Azure().ToArgb());
    ASSERT_FALSE(Drawing::Color::Azure().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Azure().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Azure().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Azure().IsSystemColor());
    ASSERT_EQ("Azure", Drawing::Color::Azure().Name());
    ASSERT_EQ("Color [Azure]", Drawing::Color::Azure().ToString());
  }
  
  TEST(ColorTest, Beige) {
    ASSERT_EQ(0xFFF5F5DCu, (unsigned)Drawing::Color::Beige().ToArgb());
    ASSERT_FALSE(Drawing::Color::Beige().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Beige().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Beige().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Beige().IsSystemColor());
    ASSERT_EQ("Beige", Drawing::Color::Beige().Name());
    ASSERT_EQ("Color [Beige]", Drawing::Color::Beige().ToString());
  }
  
  TEST(ColorTest, Bisque) {
    ASSERT_EQ(0xFFFFE4C4u, (unsigned)Drawing::Color::Bisque().ToArgb());
    ASSERT_FALSE(Drawing::Color::Bisque().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Bisque().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Bisque().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Bisque().IsSystemColor());
    ASSERT_EQ("Bisque", Drawing::Color::Bisque().Name());
    ASSERT_EQ("Color [Bisque]", Drawing::Color::Bisque().ToString());
  }
  
  TEST(ColorTest, Black) {
    ASSERT_EQ(0xFF000000u, (unsigned)Drawing::Color::Black().ToArgb());
    ASSERT_FALSE(Drawing::Color::Black().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Black().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Black().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Black().IsSystemColor());
    ASSERT_EQ("Black", Drawing::Color::Black().Name());
    ASSERT_EQ("Color [Black]", Drawing::Color::Black().ToString());
  }
  
  TEST(ColorTest, BlanchedAlmond) {
    ASSERT_EQ(0xFFFFEBCDu, (unsigned)Drawing::Color::BlanchedAlmond().ToArgb());
    ASSERT_FALSE(Drawing::Color::BlanchedAlmond().IsEmpty());
    ASSERT_TRUE(Drawing::Color::BlanchedAlmond().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::BlanchedAlmond().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::BlanchedAlmond().IsSystemColor());
    ASSERT_EQ("BlanchedAlmond", Drawing::Color::BlanchedAlmond().Name());
    ASSERT_EQ("Color [BlanchedAlmond]", Drawing::Color::BlanchedAlmond().ToString());
  }
  
  TEST(ColorTest, Blue) {
    ASSERT_EQ(0xFF0000FFu, (unsigned)Drawing::Color::Blue().ToArgb());
    ASSERT_FALSE(Drawing::Color::Blue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Blue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Blue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Blue().IsSystemColor());
    ASSERT_EQ("Blue", Drawing::Color::Blue().Name());
    ASSERT_EQ("Color [Blue]", Drawing::Color::Blue().ToString());
  }
  
  TEST(ColorTest, BlueViolet) {
    ASSERT_EQ(0xFF8A2BE2u, (unsigned)Drawing::Color::BlueViolet().ToArgb());
    ASSERT_FALSE(Drawing::Color::BlueViolet().IsEmpty());
    ASSERT_TRUE(Drawing::Color::BlueViolet().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::BlueViolet().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::BlueViolet().IsSystemColor());
    ASSERT_EQ("BlueViolet", Drawing::Color::BlueViolet().Name());
    ASSERT_EQ("Color [BlueViolet]", Drawing::Color::BlueViolet().ToString());
  }
  
  TEST(ColorTest, Brown) {
    ASSERT_EQ(0xFFA52A2Au, (unsigned)Drawing::Color::Brown().ToArgb());
    ASSERT_FALSE(Drawing::Color::Brown().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Brown().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Brown().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Brown().IsSystemColor());
    ASSERT_EQ("Brown", Drawing::Color::Brown().Name());
    ASSERT_EQ("Color [Brown]", Drawing::Color::Brown().ToString());
  }
  
  TEST(ColorTest, BurlyWood) {
    ASSERT_EQ(0xFFDEB887u, (unsigned)Drawing::Color::BurlyWood().ToArgb());
    ASSERT_FALSE(Drawing::Color::BurlyWood().IsEmpty());
    ASSERT_TRUE(Drawing::Color::BurlyWood().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::BurlyWood().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::BurlyWood().IsSystemColor());
    ASSERT_EQ("BurlyWood", Drawing::Color::BurlyWood().Name());
    ASSERT_EQ("Color [BurlyWood]", Drawing::Color::BurlyWood().ToString());
  }
  
  TEST(ColorTest, CadetBlue) {
    ASSERT_EQ(0xFF5F9EA0u, (unsigned)Drawing::Color::CadetBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::CadetBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::CadetBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::CadetBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::CadetBlue().IsSystemColor());
    ASSERT_EQ("CadetBlue", Drawing::Color::CadetBlue().Name());
    ASSERT_EQ("Color [CadetBlue]", Drawing::Color::CadetBlue().ToString());
  }
  
  TEST(ColorTest, Chartreuse) {
    ASSERT_EQ(0xFF7FFF00u, (unsigned)Drawing::Color::Chartreuse().ToArgb());
    ASSERT_FALSE(Drawing::Color::Chartreuse().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Chartreuse().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Chartreuse().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Chartreuse().IsSystemColor());
    ASSERT_EQ("Chartreuse", Drawing::Color::Chartreuse().Name());
    ASSERT_EQ("Color [Chartreuse]", Drawing::Color::Chartreuse().ToString());
  }
  
  TEST(ColorTest, Chocolate) {
    ASSERT_EQ(0xFFD2691Eu, (unsigned)Drawing::Color::Chocolate().ToArgb());
    ASSERT_FALSE(Drawing::Color::Chocolate().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Chocolate().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Chocolate().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Chocolate().IsSystemColor());
    ASSERT_EQ("Chocolate", Drawing::Color::Chocolate().Name());
    ASSERT_EQ("Color [Chocolate]", Drawing::Color::Chocolate().ToString());
  }
  
  TEST(ColorTest, Coral) {
    ASSERT_EQ(0xFFFF7F50u, (unsigned)Drawing::Color::Coral().ToArgb());
    ASSERT_FALSE(Drawing::Color::Coral().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Coral().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Coral().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Coral().IsSystemColor());
    ASSERT_EQ("Coral", Drawing::Color::Coral().Name());
    ASSERT_EQ("Color [Coral]", Drawing::Color::Coral().ToString());
  }
  
  TEST(ColorTest, CornflowerBlue) {
    ASSERT_EQ(0xFF6495EDu, (unsigned)Drawing::Color::CornflowerBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::CornflowerBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::CornflowerBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::CornflowerBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::CornflowerBlue().IsSystemColor());
    ASSERT_EQ("CornflowerBlue", Drawing::Color::CornflowerBlue().Name());
    ASSERT_EQ("Color [CornflowerBlue]", Drawing::Color::CornflowerBlue().ToString());
  }
  
  TEST(ColorTest, Cornsilk) {
    ASSERT_EQ(0xFFFFF8DCu, (unsigned)Drawing::Color::Cornsilk().ToArgb());
    ASSERT_FALSE(Drawing::Color::Cornsilk().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Cornsilk().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Cornsilk().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Cornsilk().IsSystemColor());
    ASSERT_EQ("Cornsilk", Drawing::Color::Cornsilk().Name());
    ASSERT_EQ("Color [Cornsilk]", Drawing::Color::Cornsilk().ToString());
  }
  
  TEST(ColorTest, Crimson) {
    ASSERT_EQ(0xFFDC143Cu, (unsigned)Drawing::Color::Crimson().ToArgb());
    ASSERT_FALSE(Drawing::Color::Crimson().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Crimson().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Crimson().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Crimson().IsSystemColor());
    ASSERT_EQ("Crimson", Drawing::Color::Crimson().Name());
    ASSERT_EQ("Color [Crimson]", Drawing::Color::Crimson().ToString());
  }
  
  TEST(ColorTest, Cyan) {
    ASSERT_EQ(0xFF00FFFFu, (unsigned)Drawing::Color::Cyan().ToArgb());
    ASSERT_FALSE(Drawing::Color::Cyan().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Cyan().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Cyan().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Cyan().IsSystemColor());
    ASSERT_EQ("Cyan", Drawing::Color::Cyan().Name());
    ASSERT_EQ("Color [Cyan]", Drawing::Color::Cyan().ToString());
  }
  
  TEST(ColorTest, DarkBlue) {
    ASSERT_EQ(0xFF00008Bu, (unsigned)Drawing::Color::DarkBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkBlue().IsSystemColor());
    ASSERT_EQ("DarkBlue", Drawing::Color::DarkBlue().Name());
    ASSERT_EQ("Color [DarkBlue]", Drawing::Color::DarkBlue().ToString());
  }
  
  TEST(ColorTest, DarkCyan) {
    ASSERT_EQ(0xFF008B8Bu, (unsigned)Drawing::Color::DarkCyan().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkCyan().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkCyan().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkCyan().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkCyan().IsSystemColor());
    ASSERT_EQ("DarkCyan", Drawing::Color::DarkCyan().Name());
    ASSERT_EQ("Color [DarkCyan]", Drawing::Color::DarkCyan().ToString());
  }
  
  TEST(ColorTest, DarkGoldenrod) {
    ASSERT_EQ(0xFFB8860Bu, (unsigned)Drawing::Color::DarkGoldenrod().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkGoldenrod().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkGoldenrod().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkGoldenrod().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkGoldenrod().IsSystemColor());
    ASSERT_EQ("DarkGoldenrod", Drawing::Color::DarkGoldenrod().Name());
    ASSERT_EQ("Color [DarkGoldenrod]", Drawing::Color::DarkGoldenrod().ToString());
  }
  
  TEST(ColorTest, DarkGray) {
    ASSERT_EQ(0xFFA9A9A9u, (unsigned)Drawing::Color::DarkGray().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkGray().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkGray().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkGray().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkGray().IsSystemColor());
    ASSERT_EQ("DarkGray", Drawing::Color::DarkGray().Name());
    ASSERT_EQ("Color [DarkGray]", Drawing::Color::DarkGray().ToString());
  }
  
  TEST(ColorTest, DarkGreen) {
    ASSERT_EQ(0xFF006400u, (unsigned)Drawing::Color::DarkGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkGreen().IsSystemColor());
    ASSERT_EQ("DarkGreen", Drawing::Color::DarkGreen().Name());
    ASSERT_EQ("Color [DarkGreen]", Drawing::Color::DarkGreen().ToString());
  }
  
  TEST(ColorTest, DarkKhaki) {
    ASSERT_EQ(0xFFBDB76Bu, (unsigned)Drawing::Color::DarkKhaki().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkKhaki().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkKhaki().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkKhaki().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkKhaki().IsSystemColor());
    ASSERT_EQ("DarkKhaki", Drawing::Color::DarkKhaki().Name());
    ASSERT_EQ("Color [DarkKhaki]", Drawing::Color::DarkKhaki().ToString());
  }
  
  TEST(ColorTest, DarkMagenta) {
    ASSERT_EQ(0xFF8B008Bu, (unsigned)Drawing::Color::DarkMagenta().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkMagenta().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkMagenta().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkMagenta().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkMagenta().IsSystemColor());
    ASSERT_EQ("DarkMagenta", Drawing::Color::DarkMagenta().Name());
    ASSERT_EQ("Color [DarkMagenta]", Drawing::Color::DarkMagenta().ToString());
  }
  
  TEST(ColorTest, DarkOliveGreen) {
    ASSERT_EQ(0xFF556B2Fu, (unsigned)Drawing::Color::DarkOliveGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkOliveGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkOliveGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkOliveGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkOliveGreen().IsSystemColor());
    ASSERT_EQ("DarkOliveGreen", Drawing::Color::DarkOliveGreen().Name());
    ASSERT_EQ("Color [DarkOliveGreen]", Drawing::Color::DarkOliveGreen().ToString());
  }
  
  TEST(ColorTest, DarkOrange) {
    ASSERT_EQ(0xFFFF8C00u, (unsigned)Drawing::Color::DarkOrange().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkOrange().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkOrange().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkOrange().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkOrange().IsSystemColor());
    ASSERT_EQ("DarkOrange", Drawing::Color::DarkOrange().Name());
    ASSERT_EQ("Color [DarkOrange]", Drawing::Color::DarkOrange().ToString());
  }
  
  TEST(ColorTest, DarkOrchid) {
    ASSERT_EQ(0xFF9932CCu, (unsigned)Drawing::Color::DarkOrchid().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkOrchid().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkOrchid().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkOrchid().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkOrchid().IsSystemColor());
    ASSERT_EQ("DarkOrchid", Drawing::Color::DarkOrchid().Name());
    ASSERT_EQ("Color [DarkOrchid]", Drawing::Color::DarkOrchid().ToString());
  }
  
  TEST(ColorTest, DarkRed) {
    ASSERT_EQ(0xFF8B0000u, (unsigned)Drawing::Color::DarkRed().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkRed().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkRed().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkRed().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkRed().IsSystemColor());
    ASSERT_EQ("DarkRed", Drawing::Color::DarkRed().Name());
    ASSERT_EQ("Color [DarkRed]", Drawing::Color::DarkRed().ToString());
  }
  
  TEST(ColorTest, DarkSalmon) {
    ASSERT_EQ(0xFFE9967Au, (unsigned)Drawing::Color::DarkSalmon().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkSalmon().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkSalmon().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkSalmon().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkSalmon().IsSystemColor());
    ASSERT_EQ("DarkSalmon", Drawing::Color::DarkSalmon().Name());
    ASSERT_EQ("Color [DarkSalmon]", Drawing::Color::DarkSalmon().ToString());
  }
  
  TEST(ColorTest, DarkSeaGreen) {
    ASSERT_EQ(0xFF8FBC8Bu, (unsigned)Drawing::Color::DarkSeaGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkSeaGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkSeaGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkSeaGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkSeaGreen().IsSystemColor());
    ASSERT_EQ("DarkSeaGreen", Drawing::Color::DarkSeaGreen().Name());
    ASSERT_EQ("Color [DarkSeaGreen]", Drawing::Color::DarkSeaGreen().ToString());
  }
  
  TEST(ColorTest, DarkSlateBlue) {
    ASSERT_EQ(0xFF483D8Bu, (unsigned)Drawing::Color::DarkSlateBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkSlateBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkSlateBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkSlateBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkSlateBlue().IsSystemColor());
    ASSERT_EQ("DarkSlateBlue", Drawing::Color::DarkSlateBlue().Name());
    ASSERT_EQ("Color [DarkSlateBlue]", Drawing::Color::DarkSlateBlue().ToString());
  }
  
  TEST(ColorTest, DarkSlateGray) {
    ASSERT_EQ(0xFF2F4F4Fu, (unsigned)Drawing::Color::DarkSlateGray().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkSlateGray().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkSlateGray().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkSlateGray().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkSlateGray().IsSystemColor());
    ASSERT_EQ("DarkSlateGray", Drawing::Color::DarkSlateGray().Name());
    ASSERT_EQ("Color [DarkSlateGray]", Drawing::Color::DarkSlateGray().ToString());
  }
  
  TEST(ColorTest, DarkTurquoise) {
    ASSERT_EQ(0xFF00CED1u, (unsigned)Drawing::Color::DarkTurquoise().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkTurquoise().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkTurquoise().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkTurquoise().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkTurquoise().IsSystemColor());
    ASSERT_EQ("DarkTurquoise", Drawing::Color::DarkTurquoise().Name());
    ASSERT_EQ("Color [DarkTurquoise]", Drawing::Color::DarkTurquoise().ToString());
  }
  
  TEST(ColorTest, DarkViolet) {
    ASSERT_EQ(0xFF9400D3u, (unsigned)Drawing::Color::DarkViolet().ToArgb());
    ASSERT_FALSE(Drawing::Color::DarkViolet().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DarkViolet().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DarkViolet().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DarkViolet().IsSystemColor());
    ASSERT_EQ("DarkViolet", Drawing::Color::DarkViolet().Name());
    ASSERT_EQ("Color [DarkViolet]", Drawing::Color::DarkViolet().ToString());
  }
  
  TEST(ColorTest, DeepPink) {
    ASSERT_EQ(0xFFFF1493u, (unsigned)Drawing::Color::DeepPink().ToArgb());
    ASSERT_FALSE(Drawing::Color::DeepPink().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DeepPink().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DeepPink().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DeepPink().IsSystemColor());
    ASSERT_EQ("DeepPink", Drawing::Color::DeepPink().Name());
    ASSERT_EQ("Color [DeepPink]", Drawing::Color::DeepPink().ToString());
  }
  
  TEST(ColorTest, DeepSkyBlue) {
    ASSERT_EQ(0xFF00BFFFu, (unsigned)Drawing::Color::DeepSkyBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::DeepSkyBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DeepSkyBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DeepSkyBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DeepSkyBlue().IsSystemColor());
    ASSERT_EQ("DeepSkyBlue", Drawing::Color::DeepSkyBlue().Name());
    ASSERT_EQ("Color [DeepSkyBlue]", Drawing::Color::DeepSkyBlue().ToString());
  }
  
  TEST(ColorTest, DimGray) {
    ASSERT_EQ(0xFF696969u, (unsigned)Drawing::Color::DimGray().ToArgb());
    ASSERT_FALSE(Drawing::Color::DimGray().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DimGray().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DimGray().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DimGray().IsSystemColor());
    ASSERT_EQ("DimGray", Drawing::Color::DimGray().Name());
    ASSERT_EQ("Color [DimGray]", Drawing::Color::DimGray().ToString());
  }
  
  TEST(ColorTest, DodgerBlue) {
    ASSERT_EQ(0xFF1E90FFu, (unsigned)Drawing::Color::DodgerBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::DodgerBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::DodgerBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::DodgerBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::DodgerBlue().IsSystemColor());
    ASSERT_EQ("DodgerBlue", Drawing::Color::DodgerBlue().Name());
    ASSERT_EQ("Color [DodgerBlue]", Drawing::Color::DodgerBlue().ToString());
  }
  
  TEST(ColorTest, Firebrick) {
    ASSERT_EQ(0xFFB22222u, (unsigned)Drawing::Color::Firebrick().ToArgb());
    ASSERT_FALSE(Drawing::Color::Firebrick().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Firebrick().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Firebrick().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Firebrick().IsSystemColor());
    ASSERT_EQ("Firebrick", Drawing::Color::Firebrick().Name());
    ASSERT_EQ("Color [Firebrick]", Drawing::Color::Firebrick().ToString());
  }
  
  TEST(ColorTest, FloralWhite) {
    ASSERT_EQ(0xFFFFFAF0u, (unsigned)Drawing::Color::FloralWhite().ToArgb());
    ASSERT_FALSE(Drawing::Color::FloralWhite().IsEmpty());
    ASSERT_TRUE(Drawing::Color::FloralWhite().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::FloralWhite().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::FloralWhite().IsSystemColor());
    ASSERT_EQ("FloralWhite", Drawing::Color::FloralWhite().Name());
    ASSERT_EQ("Color [FloralWhite]", Drawing::Color::FloralWhite().ToString());
  }
  
  TEST(ColorTest, ForestGreen) {
    ASSERT_EQ(0xFF228B22u, (unsigned)Drawing::Color::ForestGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::ForestGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::ForestGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::ForestGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::ForestGreen().IsSystemColor());
    ASSERT_EQ("ForestGreen", Drawing::Color::ForestGreen().Name());
    ASSERT_EQ("Color [ForestGreen]", Drawing::Color::ForestGreen().ToString());
  }
  
  TEST(ColorTest, Fuchsia) {
    ASSERT_EQ(0xFFFF00FFu, (unsigned)Drawing::Color::Fuchsia().ToArgb());
    ASSERT_FALSE(Drawing::Color::Fuchsia().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Fuchsia().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Fuchsia().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Fuchsia().IsSystemColor());
    ASSERT_EQ("Fuchsia", Drawing::Color::Fuchsia().Name());
    ASSERT_EQ("Color [Fuchsia]", Drawing::Color::Fuchsia().ToString());
  }
  
  TEST(ColorTest, Gainsboro) {
    ASSERT_EQ(0xFFDCDCDCu, (unsigned)Drawing::Color::Gainsboro().ToArgb());
    ASSERT_FALSE(Drawing::Color::Gainsboro().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Gainsboro().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Gainsboro().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Gainsboro().IsSystemColor());
    ASSERT_EQ("Gainsboro", Drawing::Color::Gainsboro().Name());
    ASSERT_EQ("Color [Gainsboro]", Drawing::Color::Gainsboro().ToString());
  }
  
  TEST(ColorTest, GhostWhite) {
    ASSERT_EQ(0xFFF8F8FFu, (unsigned)Drawing::Color::GhostWhite().ToArgb());
    ASSERT_FALSE(Drawing::Color::GhostWhite().IsEmpty());
    ASSERT_TRUE(Drawing::Color::GhostWhite().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::GhostWhite().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::GhostWhite().IsSystemColor());
    ASSERT_EQ("GhostWhite", Drawing::Color::GhostWhite().Name());
    ASSERT_EQ("Color [GhostWhite]", Drawing::Color::GhostWhite().ToString());
  }
  
  TEST(ColorTest, Gold) {
    ASSERT_EQ(0xFFFFD700u, (unsigned)Drawing::Color::Gold().ToArgb());
    ASSERT_FALSE(Drawing::Color::Gold().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Gold().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Gold().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Gold().IsSystemColor());
    ASSERT_EQ("Gold", Drawing::Color::Gold().Name());
    ASSERT_EQ("Color [Gold]", Drawing::Color::Gold().ToString());
  }
  
  TEST(ColorTest, Goldenrod) {
    ASSERT_EQ(0xFFDAA520u, (unsigned)Drawing::Color::Goldenrod().ToArgb());
    ASSERT_FALSE(Drawing::Color::Goldenrod().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Goldenrod().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Goldenrod().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Goldenrod().IsSystemColor());
    ASSERT_EQ("Goldenrod", Drawing::Color::Goldenrod().Name());
    ASSERT_EQ("Color [Goldenrod]", Drawing::Color::Goldenrod().ToString());
  }
  
  TEST(ColorTest, Gray) {
    ASSERT_EQ(0xFF808080u, (unsigned)Drawing::Color::Gray().ToArgb());
    ASSERT_FALSE(Drawing::Color::Gray().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Gray().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Gray().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Gray().IsSystemColor());
    ASSERT_EQ("Gray", Drawing::Color::Gray().Name());
    ASSERT_EQ("Color [Gray]", Drawing::Color::Gray().ToString());
  }
  
  TEST(ColorTest, Green) {
    ASSERT_EQ(0xFF008000u, (unsigned)Drawing::Color::Green().ToArgb());
    ASSERT_FALSE(Drawing::Color::Green().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Green().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Green().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Green().IsSystemColor());
    ASSERT_EQ("Green", Drawing::Color::Green().Name());
    ASSERT_EQ("Color [Green]", Drawing::Color::Green().ToString());
  }
  
  TEST(ColorTest, GreenYellow) {
    ASSERT_EQ(0xFFADFF2Fu, (unsigned)Drawing::Color::GreenYellow().ToArgb());
    ASSERT_FALSE(Drawing::Color::GreenYellow().IsEmpty());
    ASSERT_TRUE(Drawing::Color::GreenYellow().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::GreenYellow().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::GreenYellow().IsSystemColor());
    ASSERT_EQ("GreenYellow", Drawing::Color::GreenYellow().Name());
    ASSERT_EQ("Color [GreenYellow]", Drawing::Color::GreenYellow().ToString());
  }
  
  TEST(ColorTest, Honeydew) {
    ASSERT_EQ(0xFFF0FFF0u, (unsigned)Drawing::Color::Honeydew().ToArgb());
    ASSERT_FALSE(Drawing::Color::Honeydew().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Honeydew().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Honeydew().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Honeydew().IsSystemColor());
    ASSERT_EQ("Honeydew", Drawing::Color::Honeydew().Name());
    ASSERT_EQ("Color [Honeydew]", Drawing::Color::Honeydew().ToString());
  }
  
  TEST(ColorTest, HotPink) {
    ASSERT_EQ(0xFFFF69B4u, (unsigned)Drawing::Color::HotPink().ToArgb());
    ASSERT_FALSE(Drawing::Color::HotPink().IsEmpty());
    ASSERT_TRUE(Drawing::Color::HotPink().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::HotPink().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::HotPink().IsSystemColor());
    ASSERT_EQ("HotPink", Drawing::Color::HotPink().Name());
    ASSERT_EQ("Color [HotPink]", Drawing::Color::HotPink().ToString());
  }
  
  TEST(ColorTest, IndianRed) {
    ASSERT_EQ(0xFFCD5C5Cu, (unsigned)Drawing::Color::IndianRed().ToArgb());
    ASSERT_FALSE(Drawing::Color::IndianRed().IsEmpty());
    ASSERT_TRUE(Drawing::Color::IndianRed().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::IndianRed().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::IndianRed().IsSystemColor());
    ASSERT_EQ("IndianRed", Drawing::Color::IndianRed().Name());
    ASSERT_EQ("Color [IndianRed]", Drawing::Color::IndianRed().ToString());
  }
  
  TEST(ColorTest, Indigo) {
    ASSERT_EQ(0xFF4B0082u, (unsigned)Drawing::Color::Indigo().ToArgb());
    ASSERT_FALSE(Drawing::Color::Indigo().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Indigo().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Indigo().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Indigo().IsSystemColor());
    ASSERT_EQ("Indigo", Drawing::Color::Indigo().Name());
    ASSERT_EQ("Color [Indigo]", Drawing::Color::Indigo().ToString());
  }
  
  TEST(ColorTest, Ivory) {
    ASSERT_EQ(0xFFFFFFF0u, (unsigned)Drawing::Color::Ivory().ToArgb());
    ASSERT_FALSE(Drawing::Color::Ivory().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Ivory().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Ivory().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Ivory().IsSystemColor());
    ASSERT_EQ("Ivory", Drawing::Color::Ivory().Name());
    ASSERT_EQ("Color [Ivory]", Drawing::Color::Ivory().ToString());
  }
  
  TEST(ColorTest, Khaki) {
    ASSERT_EQ(0xFFF0E68Cu, (unsigned)Drawing::Color::Khaki().ToArgb());
    ASSERT_FALSE(Drawing::Color::Khaki().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Khaki().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Khaki().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Khaki().IsSystemColor());
    ASSERT_EQ("Khaki", Drawing::Color::Khaki().Name());
    ASSERT_EQ("Color [Khaki]", Drawing::Color::Khaki().ToString());
  }
  
  TEST(ColorTest, Lavender) {
    ASSERT_EQ(0xFFE6E6FAu, (unsigned)Drawing::Color::Lavender().ToArgb());
    ASSERT_FALSE(Drawing::Color::Lavender().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Lavender().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Lavender().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Lavender().IsSystemColor());
    ASSERT_EQ("Lavender", Drawing::Color::Lavender().Name());
    ASSERT_EQ("Color [Lavender]", Drawing::Color::Lavender().ToString());
  }
  
  TEST(ColorTest, LavenderBlush) {
    ASSERT_EQ(0xFFFFF0F5u, (unsigned)Drawing::Color::LavenderBlush().ToArgb());
    ASSERT_FALSE(Drawing::Color::LavenderBlush().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LavenderBlush().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LavenderBlush().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LavenderBlush().IsSystemColor());
    ASSERT_EQ("LavenderBlush", Drawing::Color::LavenderBlush().Name());
    ASSERT_EQ("Color [LavenderBlush]", Drawing::Color::LavenderBlush().ToString());
  }
  
  TEST(ColorTest, LawnGreen) {
    ASSERT_EQ(0xFF7CFC00u, (unsigned)Drawing::Color::LawnGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::LawnGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LawnGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LawnGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LawnGreen().IsSystemColor());
    ASSERT_EQ("LawnGreen", Drawing::Color::LawnGreen().Name());
    ASSERT_EQ("Color [LawnGreen]", Drawing::Color::LawnGreen().ToString());
  }
  
  TEST(ColorTest, LemonChiffon) {
    ASSERT_EQ(0xFFFFFACDu, (unsigned)Drawing::Color::LemonChiffon().ToArgb());
    ASSERT_FALSE(Drawing::Color::LemonChiffon().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LemonChiffon().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LemonChiffon().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LemonChiffon().IsSystemColor());
    ASSERT_EQ("LemonChiffon", Drawing::Color::LemonChiffon().Name());
    ASSERT_EQ("Color [LemonChiffon]", Drawing::Color::LemonChiffon().ToString());
  }
  
  TEST(ColorTest, LightBlue) {
    ASSERT_EQ(0xFFADD8E6u, (unsigned)Drawing::Color::LightBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightBlue().IsSystemColor());
    ASSERT_EQ("LightBlue", Drawing::Color::LightBlue().Name());
    ASSERT_EQ("Color [LightBlue]", Drawing::Color::LightBlue().ToString());
  }
  
  TEST(ColorTest, LightCoral) {
    ASSERT_EQ(0xFFF08080u, (unsigned)Drawing::Color::LightCoral().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightCoral().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightCoral().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightCoral().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightCoral().IsSystemColor());
    ASSERT_EQ("LightCoral", Drawing::Color::LightCoral().Name());
    ASSERT_EQ("Color [LightCoral]", Drawing::Color::LightCoral().ToString());
  }
  
  TEST(ColorTest, LightCyan) {
    ASSERT_EQ(0xFFE0FFFFu, (unsigned)Drawing::Color::LightCyan().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightCyan().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightCyan().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightCyan().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightCyan().IsSystemColor());
    ASSERT_EQ("LightCyan", Drawing::Color::LightCyan().Name());
    ASSERT_EQ("Color [LightCyan]", Drawing::Color::LightCyan().ToString());
  }
  
  TEST(ColorTest, LightGoldenrodYellow) {
    ASSERT_EQ(0xFFFAFAD2u, (unsigned)Drawing::Color::LightGoldenrodYellow().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightGoldenrodYellow().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightGoldenrodYellow().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightGoldenrodYellow().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightGoldenrodYellow().IsSystemColor());
    ASSERT_EQ("LightGoldenrodYellow", Drawing::Color::LightGoldenrodYellow().Name());
    ASSERT_EQ("Color [LightGoldenrodYellow]", Drawing::Color::LightGoldenrodYellow().ToString());
  }
  
  TEST(ColorTest, LightGray) {
    ASSERT_EQ(0xFFD3D3D3u, (unsigned)Drawing::Color::LightGray().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightGray().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightGray().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightGray().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightGray().IsSystemColor());
    ASSERT_EQ("LightGray", Drawing::Color::LightGray().Name());
    ASSERT_EQ("Color [LightGray]", Drawing::Color::LightGray().ToString());
  }
  
  TEST(ColorTest, LightGreen) {
    ASSERT_EQ(0xFF90EE90u, (unsigned)Drawing::Color::LightGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightGreen().IsSystemColor());
    ASSERT_EQ("LightGreen", Drawing::Color::LightGreen().Name());
    ASSERT_EQ("Color [LightGreen]", Drawing::Color::LightGreen().ToString());
  }
  
  TEST(ColorTest, LightPink) {
    ASSERT_EQ(0xFFFFB6C1u, (unsigned)Drawing::Color::LightPink().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightPink().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightPink().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightPink().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightPink().IsSystemColor());
    ASSERT_EQ("LightPink", Drawing::Color::LightPink().Name());
    ASSERT_EQ("Color [LightPink]", Drawing::Color::LightPink().ToString());
  }
  
  TEST(ColorTest, LightSalmon) {
    ASSERT_EQ(0xFFFFA07Au, (unsigned)Drawing::Color::LightSalmon().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightSalmon().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightSalmon().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightSalmon().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightSalmon().IsSystemColor());
    ASSERT_EQ("LightSalmon", Drawing::Color::LightSalmon().Name());
    ASSERT_EQ("Color [LightSalmon]", Drawing::Color::LightSalmon().ToString());
  }
  
  TEST(ColorTest, LightSeaGreen) {
    ASSERT_EQ(0xFF20B2AAu, (unsigned)Drawing::Color::LightSeaGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightSeaGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightSeaGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightSeaGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightSeaGreen().IsSystemColor());
    ASSERT_EQ("LightSeaGreen", Drawing::Color::LightSeaGreen().Name());
    ASSERT_EQ("Color [LightSeaGreen]", Drawing::Color::LightSeaGreen().ToString());
  }
  
  TEST(ColorTest, LightSkyBlue) {
    ASSERT_EQ(0xFF87CEFAu, (unsigned)Drawing::Color::LightSkyBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightSkyBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightSkyBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightSkyBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightSkyBlue().IsSystemColor());
    ASSERT_EQ("LightSkyBlue", Drawing::Color::LightSkyBlue().Name());
    ASSERT_EQ("Color [LightSkyBlue]", Drawing::Color::LightSkyBlue().ToString());
  }
  
  TEST(ColorTest, LightSlateGray) {
    ASSERT_EQ(0xFF778899u, (unsigned)Drawing::Color::LightSlateGray().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightSlateGray().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightSlateGray().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightSlateGray().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightSlateGray().IsSystemColor());
    ASSERT_EQ("LightSlateGray", Drawing::Color::LightSlateGray().Name());
    ASSERT_EQ("Color [LightSlateGray]", Drawing::Color::LightSlateGray().ToString());
  }
  
  TEST(ColorTest, LightSteelBlue) {
    ASSERT_EQ(0xFFB0C4DEu, (unsigned)Drawing::Color::LightSteelBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightSteelBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightSteelBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightSteelBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightSteelBlue().IsSystemColor());
    ASSERT_EQ("LightSteelBlue", Drawing::Color::LightSteelBlue().Name());
    ASSERT_EQ("Color [LightSteelBlue]", Drawing::Color::LightSteelBlue().ToString());
  }
  
  TEST(ColorTest, LightYellow) {
    ASSERT_EQ(0xFFFFFFE0u, (unsigned)Drawing::Color::LightYellow().ToArgb());
    ASSERT_FALSE(Drawing::Color::LightYellow().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LightYellow().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LightYellow().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LightYellow().IsSystemColor());
    ASSERT_EQ("LightYellow", Drawing::Color::LightYellow().Name());
    ASSERT_EQ("Color [LightYellow]", Drawing::Color::LightYellow().ToString());
  }
  
  TEST(ColorTest, Lime) {
    ASSERT_EQ(0xFF00FF00u, (unsigned)Drawing::Color::Lime().ToArgb());
    ASSERT_FALSE(Drawing::Color::Lime().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Lime().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Lime().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Lime().IsSystemColor());
    ASSERT_EQ("Lime", Drawing::Color::Lime().Name());
    ASSERT_EQ("Color [Lime]", Drawing::Color::Lime().ToString());
  }
  
  TEST(ColorTest, LimeGreen) {
    ASSERT_EQ(0xFF32CD32u, (unsigned)Drawing::Color::LimeGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::LimeGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::LimeGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::LimeGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::LimeGreen().IsSystemColor());
    ASSERT_EQ("LimeGreen", Drawing::Color::LimeGreen().Name());
    ASSERT_EQ("Color [LimeGreen]", Drawing::Color::LimeGreen().ToString());
  }
  
  TEST(ColorTest, Linen) {
    ASSERT_EQ(0xFFFAF0E6u, (unsigned)Drawing::Color::Linen().ToArgb());
    ASSERT_FALSE(Drawing::Color::Linen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Linen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Linen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Linen().IsSystemColor());
    ASSERT_EQ("Linen", Drawing::Color::Linen().Name());
    ASSERT_EQ("Color [Linen]", Drawing::Color::Linen().ToString());
  }
  
  TEST(ColorTest, Magenta) {
    ASSERT_EQ(0xFFFF00FFu, (unsigned)Drawing::Color::Magenta().ToArgb());
    ASSERT_FALSE(Drawing::Color::Magenta().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Magenta().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Magenta().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Magenta().IsSystemColor());
    ASSERT_EQ("Magenta", Drawing::Color::Magenta().Name());
    ASSERT_EQ("Color [Magenta]", Drawing::Color::Magenta().ToString());
  }
  
  TEST(ColorTest, Maroon) {
    ASSERT_EQ(0xFF800000u, (unsigned)Drawing::Color::Maroon().ToArgb());
    ASSERT_FALSE(Drawing::Color::Maroon().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Maroon().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Maroon().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Maroon().IsSystemColor());
    ASSERT_EQ("Maroon", Drawing::Color::Maroon().Name());
    ASSERT_EQ("Color [Maroon]", Drawing::Color::Maroon().ToString());
  }
  
  TEST(ColorTest, MediumAquamarine) {
    ASSERT_EQ(0xFF66CDAAu, (unsigned)Drawing::Color::MediumAquamarine().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumAquamarine().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumAquamarine().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumAquamarine().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumAquamarine().IsSystemColor());
    ASSERT_EQ("MediumAquamarine", Drawing::Color::MediumAquamarine().Name());
    ASSERT_EQ("Color [MediumAquamarine]", Drawing::Color::MediumAquamarine().ToString());
  }
  
  TEST(ColorTest, MediumBlue) {
    ASSERT_EQ(0xFF0000CDu, (unsigned)Drawing::Color::MediumBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumBlue().IsSystemColor());
    ASSERT_EQ("MediumBlue", Drawing::Color::MediumBlue().Name());
    ASSERT_EQ("Color [MediumBlue]", Drawing::Color::MediumBlue().ToString());
  }
  
  TEST(ColorTest, MediumOrchid) {
    ASSERT_EQ(0xFFBA55D3u, (unsigned)Drawing::Color::MediumOrchid().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumOrchid().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumOrchid().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumOrchid().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumOrchid().IsSystemColor());
    ASSERT_EQ("MediumOrchid", Drawing::Color::MediumOrchid().Name());
    ASSERT_EQ("Color [MediumOrchid]", Drawing::Color::MediumOrchid().ToString());
  }
  
  TEST(ColorTest, MediumPurple) {
    ASSERT_EQ(0xFF9370DBu, (unsigned)Drawing::Color::MediumPurple().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumPurple().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumPurple().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumPurple().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumPurple().IsSystemColor());
    ASSERT_EQ("MediumPurple", Drawing::Color::MediumPurple().Name());
    ASSERT_EQ("Color [MediumPurple]", Drawing::Color::MediumPurple().ToString());
  }
  
  TEST(ColorTest, MediumSeaGreen) {
    ASSERT_EQ(0xFF3CB371u, (unsigned)Drawing::Color::MediumSeaGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumSeaGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumSeaGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumSeaGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumSeaGreen().IsSystemColor());
    ASSERT_EQ("MediumSeaGreen", Drawing::Color::MediumSeaGreen().Name());
    ASSERT_EQ("Color [MediumSeaGreen]", Drawing::Color::MediumSeaGreen().ToString());
  }
  
  TEST(ColorTest, MediumSlateBlue) {
    ASSERT_EQ(0xFF7B68EEu, (unsigned)Drawing::Color::MediumSlateBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumSlateBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumSlateBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumSlateBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumSlateBlue().IsSystemColor());
    ASSERT_EQ("MediumSlateBlue", Drawing::Color::MediumSlateBlue().Name());
    ASSERT_EQ("Color [MediumSlateBlue]", Drawing::Color::MediumSlateBlue().ToString());
  }
  
  TEST(ColorTest, MediumSpringGreen) {
    ASSERT_EQ(0xFF00FA9Au, (unsigned)Drawing::Color::MediumSpringGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumSpringGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumSpringGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumSpringGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumSpringGreen().IsSystemColor());
    ASSERT_EQ("MediumSpringGreen", Drawing::Color::MediumSpringGreen().Name());
    ASSERT_EQ("Color [MediumSpringGreen]", Drawing::Color::MediumSpringGreen().ToString());
  }
  
  TEST(ColorTest, MediumTurquoise) {
    ASSERT_EQ(0xFF48D1CCu, (unsigned)Drawing::Color::MediumTurquoise().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumTurquoise().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumTurquoise().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumTurquoise().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumTurquoise().IsSystemColor());
    ASSERT_EQ("MediumTurquoise", Drawing::Color::MediumTurquoise().Name());
    ASSERT_EQ("Color [MediumTurquoise]", Drawing::Color::MediumTurquoise().ToString());
  }
  
  TEST(ColorTest, MediumVioletRed) {
    ASSERT_EQ(0xFFC71585u, (unsigned)Drawing::Color::MediumVioletRed().ToArgb());
    ASSERT_FALSE(Drawing::Color::MediumVioletRed().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MediumVioletRed().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MediumVioletRed().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MediumVioletRed().IsSystemColor());
    ASSERT_EQ("MediumVioletRed", Drawing::Color::MediumVioletRed().Name());
    ASSERT_EQ("Color [MediumVioletRed]", Drawing::Color::MediumVioletRed().ToString());
  }
  
  TEST(ColorTest, MidnightBlue) {
    ASSERT_EQ(0xFF191970u, (unsigned)Drawing::Color::MidnightBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::MidnightBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MidnightBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MidnightBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MidnightBlue().IsSystemColor());
    ASSERT_EQ("MidnightBlue", Drawing::Color::MidnightBlue().Name());
    ASSERT_EQ("Color [MidnightBlue]", Drawing::Color::MidnightBlue().ToString());
  }
  
  TEST(ColorTest, MintCream) {
    ASSERT_EQ(0xFFF5FFFAu, (unsigned)Drawing::Color::MintCream().ToArgb());
    ASSERT_FALSE(Drawing::Color::MintCream().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MintCream().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MintCream().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MintCream().IsSystemColor());
    ASSERT_EQ("MintCream", Drawing::Color::MintCream().Name());
    ASSERT_EQ("Color [MintCream]", Drawing::Color::MintCream().ToString());
  }
  
  TEST(ColorTest, MistyRose) {
    ASSERT_EQ(0xFFFFE4E1u, (unsigned)Drawing::Color::MistyRose().ToArgb());
    ASSERT_FALSE(Drawing::Color::MistyRose().IsEmpty());
    ASSERT_TRUE(Drawing::Color::MistyRose().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::MistyRose().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::MistyRose().IsSystemColor());
    ASSERT_EQ("MistyRose", Drawing::Color::MistyRose().Name());
    ASSERT_EQ("Color [MistyRose]", Drawing::Color::MistyRose().ToString());
  }
  
  TEST(ColorTest, Moccasin) {
    ASSERT_EQ(0xFFFFE4B5u, (unsigned)Drawing::Color::Moccasin().ToArgb());
    ASSERT_FALSE(Drawing::Color::Moccasin().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Moccasin().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Moccasin().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Moccasin().IsSystemColor());
    ASSERT_EQ("Moccasin", Drawing::Color::Moccasin().Name());
    ASSERT_EQ("Color [Moccasin]", Drawing::Color::Moccasin().ToString());
  }
  
  TEST(ColorTest, NavajoWhite) {
    ASSERT_EQ(0xFFFFDEADu, (unsigned)Drawing::Color::NavajoWhite().ToArgb());
    ASSERT_FALSE(Drawing::Color::NavajoWhite().IsEmpty());
    ASSERT_TRUE(Drawing::Color::NavajoWhite().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::NavajoWhite().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::NavajoWhite().IsSystemColor());
    ASSERT_EQ("NavajoWhite", Drawing::Color::NavajoWhite().Name());
    ASSERT_EQ("Color [NavajoWhite]", Drawing::Color::NavajoWhite().ToString());
  }
  
  TEST(ColorTest, Navy) {
    ASSERT_EQ(0xFF000080u, (unsigned)Drawing::Color::Navy().ToArgb());
    ASSERT_FALSE(Drawing::Color::Navy().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Navy().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Navy().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Navy().IsSystemColor());
    ASSERT_EQ("Navy", Drawing::Color::Navy().Name());
    ASSERT_EQ("Color [Navy]", Drawing::Color::Navy().ToString());
  }
  
  TEST(ColorTest, OldLace) {
    ASSERT_EQ(0xFFFDF5E6u, (unsigned)Drawing::Color::OldLace().ToArgb());
    ASSERT_FALSE(Drawing::Color::OldLace().IsEmpty());
    ASSERT_TRUE(Drawing::Color::OldLace().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::OldLace().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::OldLace().IsSystemColor());
    ASSERT_EQ("OldLace", Drawing::Color::OldLace().Name());
    ASSERT_EQ("Color [OldLace]", Drawing::Color::OldLace().ToString());
  }
  
  TEST(ColorTest, Olive) {
    ASSERT_EQ(0xFF808000u, (unsigned)Drawing::Color::Olive().ToArgb());
    ASSERT_FALSE(Drawing::Color::Olive().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Olive().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Olive().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Olive().IsSystemColor());
    ASSERT_EQ("Olive", Drawing::Color::Olive().Name());
    ASSERT_EQ("Color [Olive]", Drawing::Color::Olive().ToString());
  }
  
  TEST(ColorTest, OliveDrab) {
    ASSERT_EQ(0xFF6B8E23u, (unsigned)Drawing::Color::OliveDrab().ToArgb());
    ASSERT_FALSE(Drawing::Color::OliveDrab().IsEmpty());
    ASSERT_TRUE(Drawing::Color::OliveDrab().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::OliveDrab().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::OliveDrab().IsSystemColor());
    ASSERT_EQ("OliveDrab", Drawing::Color::OliveDrab().Name());
    ASSERT_EQ("Color [OliveDrab]", Drawing::Color::OliveDrab().ToString());
  }
  
  TEST(ColorTest, Orange) {
    ASSERT_EQ(0xFFFFA500u, (unsigned)Drawing::Color::Orange().ToArgb());
    ASSERT_FALSE(Drawing::Color::Orange().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Orange().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Orange().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Orange().IsSystemColor());
    ASSERT_EQ("Orange", Drawing::Color::Orange().Name());
    ASSERT_EQ("Color [Orange]", Drawing::Color::Orange().ToString());
  }
  
  TEST(ColorTest, OrangeRed) {
    ASSERT_EQ(0xFFFF4500u, (unsigned)Drawing::Color::OrangeRed().ToArgb());
    ASSERT_FALSE(Drawing::Color::OrangeRed().IsEmpty());
    ASSERT_TRUE(Drawing::Color::OrangeRed().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::OrangeRed().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::OrangeRed().IsSystemColor());
    ASSERT_EQ("OrangeRed", Drawing::Color::OrangeRed().Name());
    ASSERT_EQ("Color [OrangeRed]", Drawing::Color::OrangeRed().ToString());
  }
  
  TEST(ColorTest, Orchid) {
    ASSERT_EQ(0xFFDA70D6u, (unsigned)Drawing::Color::Orchid().ToArgb());
    ASSERT_FALSE(Drawing::Color::Orchid().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Orchid().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Orchid().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Orchid().IsSystemColor());
    ASSERT_EQ("Orchid", Drawing::Color::Orchid().Name());
    ASSERT_EQ("Color [Orchid]", Drawing::Color::Orchid().ToString());
  }
  
  TEST(ColorTest, PaleGoldenrod) {
    ASSERT_EQ(0xFFEEE8AAu, (unsigned)Drawing::Color::PaleGoldenrod().ToArgb());
    ASSERT_FALSE(Drawing::Color::PaleGoldenrod().IsEmpty());
    ASSERT_TRUE(Drawing::Color::PaleGoldenrod().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::PaleGoldenrod().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::PaleGoldenrod().IsSystemColor());
    ASSERT_EQ("PaleGoldenrod", Drawing::Color::PaleGoldenrod().Name());
    ASSERT_EQ("Color [PaleGoldenrod]", Drawing::Color::PaleGoldenrod().ToString());
  }
  
  TEST(ColorTest, PaleGreen) {
    ASSERT_EQ(0xFF98FB98u, (unsigned)Drawing::Color::PaleGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::PaleGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::PaleGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::PaleGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::PaleGreen().IsSystemColor());
    ASSERT_EQ("PaleGreen", Drawing::Color::PaleGreen().Name());
    ASSERT_EQ("Color [PaleGreen]", Drawing::Color::PaleGreen().ToString());
  }
  
  TEST(ColorTest, PaleTurquoise) {
    ASSERT_EQ(0xFFAFEEEEu, (unsigned)Drawing::Color::PaleTurquoise().ToArgb());
    ASSERT_FALSE(Drawing::Color::PaleTurquoise().IsEmpty());
    ASSERT_TRUE(Drawing::Color::PaleTurquoise().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::PaleTurquoise().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::PaleTurquoise().IsSystemColor());
    ASSERT_EQ("PaleTurquoise", Drawing::Color::PaleTurquoise().Name());
    ASSERT_EQ("Color [PaleTurquoise]", Drawing::Color::PaleTurquoise().ToString());
  }
  
  TEST(ColorTest, PaleVioletRed) {
    ASSERT_EQ(0xFFDB7093u, (unsigned)Drawing::Color::PaleVioletRed().ToArgb());
    ASSERT_FALSE(Drawing::Color::PaleVioletRed().IsEmpty());
    ASSERT_TRUE(Drawing::Color::PaleVioletRed().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::PaleVioletRed().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::PaleVioletRed().IsSystemColor());
    ASSERT_EQ("PaleVioletRed", Drawing::Color::PaleVioletRed().Name());
    ASSERT_EQ("Color [PaleVioletRed]", Drawing::Color::PaleVioletRed().ToString());
  }
  
  TEST(ColorTest, PapayaWhip) {
    ASSERT_EQ(0xFFFFEFD5u, (unsigned)Drawing::Color::PapayaWhip().ToArgb());
    ASSERT_FALSE(Drawing::Color::PapayaWhip().IsEmpty());
    ASSERT_TRUE(Drawing::Color::PapayaWhip().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::PapayaWhip().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::PapayaWhip().IsSystemColor());
    ASSERT_EQ("PapayaWhip", Drawing::Color::PapayaWhip().Name());
    ASSERT_EQ("Color [PapayaWhip]", Drawing::Color::PapayaWhip().ToString());
  }
  
  TEST(ColorTest, PeachPuff) {
    ASSERT_EQ(0xFFFFDAB9u, (unsigned)Drawing::Color::PeachPuff().ToArgb());
    ASSERT_FALSE(Drawing::Color::PeachPuff().IsEmpty());
    ASSERT_TRUE(Drawing::Color::PeachPuff().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::PeachPuff().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::PeachPuff().IsSystemColor());
    ASSERT_EQ("PeachPuff", Drawing::Color::PeachPuff().Name());
    ASSERT_EQ("Color [PeachPuff]", Drawing::Color::PeachPuff().ToString());
  }
  
  TEST(ColorTest, Peru) {
    ASSERT_EQ(0xFFCD853Fu, (unsigned)Drawing::Color::Peru().ToArgb());
    ASSERT_FALSE(Drawing::Color::Peru().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Peru().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Peru().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Peru().IsSystemColor());
    ASSERT_EQ("Peru", Drawing::Color::Peru().Name());
    ASSERT_EQ("Color [Peru]", Drawing::Color::Peru().ToString());
  }
  
  TEST(ColorTest, Pink) {
    ASSERT_EQ(0xFFFFC0CBu, (unsigned)Drawing::Color::Pink().ToArgb());
    ASSERT_FALSE(Drawing::Color::Pink().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Pink().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Pink().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Pink().IsSystemColor());
    ASSERT_EQ("Pink", Drawing::Color::Pink().Name());
    ASSERT_EQ("Color [Pink]", Drawing::Color::Pink().ToString());
  }
  
  TEST(ColorTest, Plum) {
    ASSERT_EQ(0xFFDDA0DDu, (unsigned)Drawing::Color::Plum().ToArgb());
    ASSERT_FALSE(Drawing::Color::Plum().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Plum().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Plum().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Plum().IsSystemColor());
    ASSERT_EQ("Plum", Drawing::Color::Plum().Name());
    ASSERT_EQ("Color [Plum]", Drawing::Color::Plum().ToString());
  }
  
  TEST(ColorTest, PowderBlue) {
    ASSERT_EQ(0xFFB0E0E6u, (unsigned)Drawing::Color::PowderBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::PowderBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::PowderBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::PowderBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::PowderBlue().IsSystemColor());
    ASSERT_EQ("PowderBlue", Drawing::Color::PowderBlue().Name());
    ASSERT_EQ("Color [PowderBlue]", Drawing::Color::PowderBlue().ToString());
  }
  
  TEST(ColorTest, Purple) {
    ASSERT_EQ(0xFF800080u, (unsigned)Drawing::Color::Purple().ToArgb());
    ASSERT_FALSE(Drawing::Color::Purple().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Purple().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Purple().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Purple().IsSystemColor());
    ASSERT_EQ("Purple", Drawing::Color::Purple().Name());
    ASSERT_EQ("Color [Purple]", Drawing::Color::Purple().ToString());
  }
  
  TEST(ColorTest, Red) {
    ASSERT_EQ(0xFFFF0000u, (unsigned)Drawing::Color::Red().ToArgb());
    ASSERT_FALSE(Drawing::Color::Red().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Red().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Red().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Red().IsSystemColor());
    ASSERT_EQ("Red", Drawing::Color::Red().Name());
    ASSERT_EQ("Color [Red]", Drawing::Color::Red().ToString());
  }
  
  TEST(ColorTest, RosyBrown) {
    ASSERT_EQ(0xFFBC8F8Fu, (unsigned)Drawing::Color::RosyBrown().ToArgb());
    ASSERT_FALSE(Drawing::Color::RosyBrown().IsEmpty());
    ASSERT_TRUE(Drawing::Color::RosyBrown().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::RosyBrown().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::RosyBrown().IsSystemColor());
    ASSERT_EQ("RosyBrown", Drawing::Color::RosyBrown().Name());
    ASSERT_EQ("Color [RosyBrown]", Drawing::Color::RosyBrown().ToString());
  }
  
  TEST(ColorTest, RoyalBlue) {
    ASSERT_EQ(0xFF4169E1u, (unsigned)Drawing::Color::RoyalBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::RoyalBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::RoyalBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::RoyalBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::RoyalBlue().IsSystemColor());
    ASSERT_EQ("RoyalBlue", Drawing::Color::RoyalBlue().Name());
    ASSERT_EQ("Color [RoyalBlue]", Drawing::Color::RoyalBlue().ToString());
  }
  
  TEST(ColorTest, SaddleBrown) {
    ASSERT_EQ(0xFF8B4513u, (unsigned)Drawing::Color::SaddleBrown().ToArgb());
    ASSERT_FALSE(Drawing::Color::SaddleBrown().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SaddleBrown().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SaddleBrown().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SaddleBrown().IsSystemColor());
    ASSERT_EQ("SaddleBrown", Drawing::Color::SaddleBrown().Name());
    ASSERT_EQ("Color [SaddleBrown]", Drawing::Color::SaddleBrown().ToString());
  }
  
  TEST(ColorTest, Salmon) {
    ASSERT_EQ(0xFFFA8072u, (unsigned)Drawing::Color::Salmon().ToArgb());
    ASSERT_FALSE(Drawing::Color::Salmon().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Salmon().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Salmon().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Salmon().IsSystemColor());
    ASSERT_EQ("Salmon", Drawing::Color::Salmon().Name());
    ASSERT_EQ("Color [Salmon]", Drawing::Color::Salmon().ToString());
  }
  
  TEST(ColorTest, SandyBrown) {
    ASSERT_EQ(0xFFF4A460u, (unsigned)Drawing::Color::SandyBrown().ToArgb());
    ASSERT_FALSE(Drawing::Color::SandyBrown().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SandyBrown().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SandyBrown().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SandyBrown().IsSystemColor());
    ASSERT_EQ("SandyBrown", Drawing::Color::SandyBrown().Name());
    ASSERT_EQ("Color [SandyBrown]", Drawing::Color::SandyBrown().ToString());
  }
  
  TEST(ColorTest, SeaGreen) {
    ASSERT_EQ(0xFF2E8B57u, (unsigned)Drawing::Color::SeaGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::SeaGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SeaGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SeaGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SeaGreen().IsSystemColor());
    ASSERT_EQ("SeaGreen", Drawing::Color::SeaGreen().Name());
    ASSERT_EQ("Color [SeaGreen]", Drawing::Color::SeaGreen().ToString());
  }
  
  TEST(ColorTest, SeaShell) {
    ASSERT_EQ(0xFFFFF5EEu, (unsigned)Drawing::Color::SeaShell().ToArgb());
    ASSERT_FALSE(Drawing::Color::SeaShell().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SeaShell().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SeaShell().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SeaShell().IsSystemColor());
    ASSERT_EQ("SeaShell", Drawing::Color::SeaShell().Name());
    ASSERT_EQ("Color [SeaShell]", Drawing::Color::SeaShell().ToString());
  }
  
  TEST(ColorTest, Sienna) {
    ASSERT_EQ(0xFFA0522Du, (unsigned)Drawing::Color::Sienna().ToArgb());
    ASSERT_FALSE(Drawing::Color::Sienna().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Sienna().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Sienna().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Sienna().IsSystemColor());
    ASSERT_EQ("Sienna", Drawing::Color::Sienna().Name());
    ASSERT_EQ("Color [Sienna]", Drawing::Color::Sienna().ToString());
  }
  
  TEST(ColorTest, Silver) {
    ASSERT_EQ(0xFFC0C0C0u, (unsigned)Drawing::Color::Silver().ToArgb());
    ASSERT_FALSE(Drawing::Color::Silver().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Silver().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Silver().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Silver().IsSystemColor());
    ASSERT_EQ("Silver", Drawing::Color::Silver().Name());
    ASSERT_EQ("Color [Silver]", Drawing::Color::Silver().ToString());
  }
  
  TEST(ColorTest, SkyBlue) {
    ASSERT_EQ(0xFF87CEEBu, (unsigned)Drawing::Color::SkyBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::SkyBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SkyBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SkyBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SkyBlue().IsSystemColor());
    ASSERT_EQ("SkyBlue", Drawing::Color::SkyBlue().Name());
    ASSERT_EQ("Color [SkyBlue]", Drawing::Color::SkyBlue().ToString());
  }
  
  TEST(ColorTest, SlateBlue) {
    ASSERT_EQ(0xFF6A5ACDu, (unsigned)Drawing::Color::SlateBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::SlateBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SlateBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SlateBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SlateBlue().IsSystemColor());
    ASSERT_EQ("SlateBlue", Drawing::Color::SlateBlue().Name());
    ASSERT_EQ("Color [SlateBlue]", Drawing::Color::SlateBlue().ToString());
  }
  
  TEST(ColorTest, SlateGray) {
    ASSERT_EQ(0xFF708090u, (unsigned)Drawing::Color::SlateGray().ToArgb());
    ASSERT_FALSE(Drawing::Color::SlateGray().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SlateGray().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SlateGray().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SlateGray().IsSystemColor());
    ASSERT_EQ("SlateGray", Drawing::Color::SlateGray().Name());
    ASSERT_EQ("Color [SlateGray]", Drawing::Color::SlateGray().ToString());
  }
  
  TEST(ColorTest, Snow) {
    ASSERT_EQ(0xFFFFFAFAu, (unsigned)Drawing::Color::Snow().ToArgb());
    ASSERT_FALSE(Drawing::Color::Snow().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Snow().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Snow().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Snow().IsSystemColor());
    ASSERT_EQ("Snow", Drawing::Color::Snow().Name());
    ASSERT_EQ("Color [Snow]", Drawing::Color::Snow().ToString());
  }
  
  TEST(ColorTest, SpringGreen) {
    ASSERT_EQ(0xFF00FF7Fu, (unsigned)Drawing::Color::SpringGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::SpringGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SpringGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SpringGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SpringGreen().IsSystemColor());
    ASSERT_EQ("SpringGreen", Drawing::Color::SpringGreen().Name());
    ASSERT_EQ("Color [SpringGreen]", Drawing::Color::SpringGreen().ToString());
  }
  
  TEST(ColorTest, SteelBlue) {
    ASSERT_EQ(0xFF4682B4u, (unsigned)Drawing::Color::SteelBlue().ToArgb());
    ASSERT_FALSE(Drawing::Color::SteelBlue().IsEmpty());
    ASSERT_TRUE(Drawing::Color::SteelBlue().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::SteelBlue().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::SteelBlue().IsSystemColor());
    ASSERT_EQ("SteelBlue", Drawing::Color::SteelBlue().Name());
    ASSERT_EQ("Color [SteelBlue]", Drawing::Color::SteelBlue().ToString());
  }
  
  TEST(ColorTest, Tan) {
    ASSERT_EQ(0xFFD2B48Cu, (unsigned)Drawing::Color::Tan().ToArgb());
    ASSERT_FALSE(Drawing::Color::Tan().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Tan().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Tan().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Tan().IsSystemColor());
    ASSERT_EQ("Tan", Drawing::Color::Tan().Name());
    ASSERT_EQ("Color [Tan]", Drawing::Color::Tan().ToString());
  }
  
  TEST(ColorTest, Teal) {
    ASSERT_EQ(0xFF008080u, (unsigned)Drawing::Color::Teal().ToArgb());
    ASSERT_FALSE(Drawing::Color::Teal().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Teal().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Teal().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Teal().IsSystemColor());
    ASSERT_EQ("Teal", Drawing::Color::Teal().Name());
    ASSERT_EQ("Color [Teal]", Drawing::Color::Teal().ToString());
  }
  
  TEST(ColorTest, Thistle) {
    ASSERT_EQ(0xFFD8BFD8u, (unsigned)Drawing::Color::Thistle().ToArgb());
    ASSERT_FALSE(Drawing::Color::Thistle().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Thistle().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Thistle().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Thistle().IsSystemColor());
    ASSERT_EQ("Thistle", Drawing::Color::Thistle().Name());
    ASSERT_EQ("Color [Thistle]", Drawing::Color::Thistle().ToString());
  }
  
  TEST(ColorTest, Tomato) {
    ASSERT_EQ(0xFFFF6347u, (unsigned)Drawing::Color::Tomato().ToArgb());
    ASSERT_FALSE(Drawing::Color::Tomato().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Tomato().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Tomato().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Tomato().IsSystemColor());
    ASSERT_EQ("Tomato", Drawing::Color::Tomato().Name());
    ASSERT_EQ("Color [Tomato]", Drawing::Color::Tomato().ToString());
  }
  
  TEST(ColorTest, Turquoise) {
    ASSERT_EQ(0xFF40E0D0u, (unsigned)Drawing::Color::Turquoise().ToArgb());
    ASSERT_FALSE(Drawing::Color::Turquoise().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Turquoise().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Turquoise().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Turquoise().IsSystemColor());
    ASSERT_EQ("Turquoise", Drawing::Color::Turquoise().Name());
    ASSERT_EQ("Color [Turquoise]", Drawing::Color::Turquoise().ToString());
  }
  
  TEST(ColorTest, Violet) {
    ASSERT_EQ(0xFFEE82EEu, (unsigned)Drawing::Color::Violet().ToArgb());
    ASSERT_FALSE(Drawing::Color::Violet().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Violet().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Violet().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Violet().IsSystemColor());
    ASSERT_EQ("Violet", Drawing::Color::Violet().Name());
    ASSERT_EQ("Color [Violet]", Drawing::Color::Violet().ToString());
  }
  
  TEST(ColorTest, Wheat) {
    ASSERT_EQ(0xFFF5DEB3u, (unsigned)Drawing::Color::Wheat().ToArgb());
    ASSERT_FALSE(Drawing::Color::Wheat().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Wheat().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Wheat().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Wheat().IsSystemColor());
    ASSERT_EQ("Wheat", Drawing::Color::Wheat().Name());
    ASSERT_EQ("Color [Wheat]", Drawing::Color::Wheat().ToString());
  }
  
  TEST(ColorTest, White) {
    ASSERT_EQ(0xFFFFFFFFu, (unsigned)Drawing::Color::White().ToArgb());
    ASSERT_FALSE(Drawing::Color::White().IsEmpty());
    ASSERT_TRUE(Drawing::Color::White().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::White().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::White().IsSystemColor());
    ASSERT_EQ("White", Drawing::Color::White().Name());
    ASSERT_EQ("Color [White]", Drawing::Color::White().ToString());
  }
  
  TEST(ColorTest, WhiteSmoke) {
    ASSERT_EQ(0xFFF5F5F5u, (unsigned)Drawing::Color::WhiteSmoke().ToArgb());
    ASSERT_FALSE(Drawing::Color::WhiteSmoke().IsEmpty());
    ASSERT_TRUE(Drawing::Color::WhiteSmoke().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::WhiteSmoke().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::WhiteSmoke().IsSystemColor());
    ASSERT_EQ("WhiteSmoke", Drawing::Color::WhiteSmoke().Name());
    ASSERT_EQ("Color [WhiteSmoke]", Drawing::Color::WhiteSmoke().ToString());
  }
  
  TEST(ColorTest, Yellow) {
    ASSERT_EQ(0xFFFFFF00u, (unsigned)Drawing::Color::Yellow().ToArgb());
    ASSERT_FALSE(Drawing::Color::Yellow().IsEmpty());
    ASSERT_TRUE(Drawing::Color::Yellow().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::Yellow().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::Yellow().IsSystemColor());
    ASSERT_EQ("Yellow", Drawing::Color::Yellow().Name());
    ASSERT_EQ("Color [Yellow]", Drawing::Color::Yellow().ToString());
  }
  
  TEST(ColorTest, YellowGreen) {
    ASSERT_EQ(0xFF9ACD32u, (unsigned)Drawing::Color::YellowGreen().ToArgb());
    ASSERT_FALSE(Drawing::Color::YellowGreen().IsEmpty());
    ASSERT_TRUE(Drawing::Color::YellowGreen().IsKnownColor());
    ASSERT_TRUE(Drawing::Color::YellowGreen().IsNamedColor());
    ASSERT_FALSE(Drawing::Color::YellowGreen().IsSystemColor());
    ASSERT_EQ("YellowGreen", Drawing::Color::YellowGreen().Name());
    ASSERT_EQ("Color [YellowGreen]", Drawing::Color::YellowGreen().ToString());
  }
}

