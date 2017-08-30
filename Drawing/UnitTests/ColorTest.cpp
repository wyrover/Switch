#include <Switch/System/Drawing/Color.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Drawing;
using namespace TUnit;

namespace SwitchUnitTests {
  class Color : public TestFixture {
  public:
    void Ctor() {
      Drawing::Color color;
      Assert::AreEqual(0x00, color.A(), sw_current_information);
      Assert::AreEqual(0x00, color.R(), sw_current_information);
      Assert::AreEqual(0x00, color.G(), sw_current_information);
      Assert::AreEqual(0x00, color.B(), sw_current_information);
      Assert::IsTrue(color.IsEmpty(), sw_current_information);
      Assert::IsFalse(color.IsKnownColor(), sw_current_information);
      Assert::IsFalse(color.IsNamedColor, sw_current_information);
      Assert::IsFalse(color.IsSystemColor(), sw_current_information);
      Assert::AreEqual("0", color.Name(), sw_current_information);
      Assert::AreEqual("Color [Empty]", color.ToString(), sw_current_information);
    }
    
    void FromKnownColor() {
      Assert::AreEqual(0xFF, Drawing::Color::FromKnownColor(KnownColor::Black).A(), sw_current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).R(), sw_current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).G(), sw_current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).B(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsSystemColor(), sw_current_information);
      Assert::AreEqual("Black", Drawing::Color::FromKnownColor(KnownColor::Black).Name(), sw_current_information);
      Assert::AreEqual("Color [Black]", Drawing::Color::FromKnownColor(KnownColor::Black).ToString(), sw_current_information);
      
      Assert::Throws<ArgumentException>(sw_delegate {Drawing::Color::FromKnownColor((KnownColor)34544);}, sw_current_information);
    }
    
    void FromArgb() {
      Assert::AreEqual(0x12, Drawing::Color::FromArgb(0x12345678).A(), sw_current_information);
      Assert::AreEqual(0x34, Drawing::Color::FromArgb(0x12345678).R(), sw_current_information);
      Assert::AreEqual(0x56, Drawing::Color::FromArgb(0x12345678).G(), sw_current_information);
      Assert::AreEqual(0x78, Drawing::Color::FromArgb(0x12345678).B(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsEmpty(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsKnownColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsSystemColor(), sw_current_information);
      Assert::AreEqual("12345678", Drawing::Color::FromArgb(0x12345678).Name(), sw_current_information);
      Assert::AreEqual("Color [A=18, R=52, G=86, B=120]", Drawing::Color::FromArgb(0x12345678).ToString(), sw_current_information);
    }
    
    void FromName() {
      Drawing::Color colorAliceBlue = Drawing::Color::FromName("AliceBlue");
      Assert::AreEqual(0xFF, colorAliceBlue.A(), sw_current_information);
      Assert::AreEqual(0xF0, colorAliceBlue.R(), sw_current_information);
      Assert::AreEqual(0xF8, colorAliceBlue.G(), sw_current_information);
      Assert::AreEqual(0xFF, colorAliceBlue.B(), sw_current_information);
      Assert::IsFalse(colorAliceBlue.IsEmpty(), sw_current_information);
      Assert::IsTrue(colorAliceBlue.IsKnownColor(), sw_current_information);
      Assert::IsTrue(colorAliceBlue.IsNamedColor(), sw_current_information);
      Assert::IsFalse(colorAliceBlue.IsSystemColor(), sw_current_information);
      Assert::AreEqual("AliceBlue", colorAliceBlue.Name(), sw_current_information);
      Assert::AreEqual("Color [AliceBlue]", colorAliceBlue.ToString(), sw_current_information);
    }
    
    void Transparent() {
      Assert::AreEqual(0x00FFFFFF, Drawing::Color::Transparent().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Transparent().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Transparent().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Transparent().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Transparent().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Transparent", Drawing::Color::Transparent().Name(), sw_current_information);
      Assert::AreEqual("Color [Transparent]", Drawing::Color::Transparent().ToString(), sw_current_information);
    }
    
    void AliceBlue() {
      Assert::AreEqual(0xFFF0F8FFu, (unsigned)Drawing::Color::AliceBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::AliceBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::AliceBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::AliceBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::AliceBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("AliceBlue", Drawing::Color::AliceBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [AliceBlue]", Drawing::Color::AliceBlue().ToString(), sw_current_information);
    }
    
    void AntiqueWhite() {
      Assert::AreEqual(0xFFFAEBD7u, (unsigned)Drawing::Color::AntiqueWhite().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::AntiqueWhite().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::AntiqueWhite().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::AntiqueWhite().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::AntiqueWhite().IsSystemColor(), sw_current_information);
      Assert::AreEqual("AntiqueWhite", Drawing::Color::AntiqueWhite().Name(), sw_current_information);
      Assert::AreEqual("Color [AntiqueWhite]", Drawing::Color::AntiqueWhite().ToString(), sw_current_information);
    }
    
    void Aqua() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Aqua().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Aqua().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Aqua().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Aqua().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Aqua().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Aqua", Drawing::Color::Aqua().Name(), sw_current_information);
      Assert::AreEqual("Color [Aqua]", Drawing::Color::Aqua().ToString(), sw_current_information);
    }
    
    void Aquamarine() {
      Assert::AreEqual(0xFF7FFFD4u, (unsigned)Drawing::Color::Aquamarine().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Aquamarine().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Aquamarine().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Aquamarine().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Aquamarine().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Aquamarine", Drawing::Color::Aquamarine().Name(), sw_current_information);
      Assert::AreEqual("Color [Aquamarine]", Drawing::Color::Aquamarine().ToString(), sw_current_information);
    }
    
    void Azure() {
      Assert::AreEqual(0xFFF0FFFFu, (unsigned)Drawing::Color::Azure().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Azure().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Azure().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Azure().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Azure().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Azure", Drawing::Color::Azure().Name(), sw_current_information);
      Assert::AreEqual("Color [Azure]", Drawing::Color::Azure().ToString(), sw_current_information);
    }
    
    void Beige() {
      Assert::AreEqual(0xFFF5F5DCu, (unsigned)Drawing::Color::Beige().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Beige().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Beige().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Beige().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Beige().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Beige", Drawing::Color::Beige().Name(), sw_current_information);
      Assert::AreEqual("Color [Beige]", Drawing::Color::Beige().ToString(), sw_current_information);
    }
    
    void Bisque() {
      Assert::AreEqual(0xFFFFE4C4u, (unsigned)Drawing::Color::Bisque().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Bisque().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Bisque().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Bisque().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Bisque().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Bisque", Drawing::Color::Bisque().Name(), sw_current_information);
      Assert::AreEqual("Color [Bisque]", Drawing::Color::Bisque().ToString(), sw_current_information);
    }
    
    void Black() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::Color::Black().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Black().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Black().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Black().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Black().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Black", Drawing::Color::Black().Name(), sw_current_information);
      Assert::AreEqual("Color [Black]", Drawing::Color::Black().ToString(), sw_current_information);
    }
    
    void BlanchedAlmond() {
      Assert::AreEqual(0xFFFFEBCDu, (unsigned)Drawing::Color::BlanchedAlmond().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond().IsSystemColor(), sw_current_information);
      Assert::AreEqual("BlanchedAlmond", Drawing::Color::BlanchedAlmond().Name(), sw_current_information);
      Assert::AreEqual("Color [BlanchedAlmond]", Drawing::Color::BlanchedAlmond().ToString(), sw_current_information);
    }
    
    void Blue() {
      Assert::AreEqual(0xFF0000FFu, (unsigned)Drawing::Color::Blue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Blue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Blue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Blue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Blue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Blue", Drawing::Color::Blue().Name(), sw_current_information);
      Assert::AreEqual("Color [Blue]", Drawing::Color::Blue().ToString(), sw_current_information);
    }
    
    void BlueViolet() {
      Assert::AreEqual(0xFF8A2BE2u, (unsigned)Drawing::Color::BlueViolet().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::BlueViolet().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::BlueViolet().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::BlueViolet().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::BlueViolet().IsSystemColor(), sw_current_information);
      Assert::AreEqual("BlueViolet", Drawing::Color::BlueViolet().Name(), sw_current_information);
      Assert::AreEqual("Color [BlueViolet]", Drawing::Color::BlueViolet().ToString(), sw_current_information);
    }
    
    void Brown() {
      Assert::AreEqual(0xFFA52A2Au, (unsigned)Drawing::Color::Brown().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Brown().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Brown().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Brown().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Brown().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Brown", Drawing::Color::Brown().Name(), sw_current_information);
      Assert::AreEqual("Color [Brown]", Drawing::Color::Brown().ToString(), sw_current_information);
    }
    
    void BurlyWood() {
      Assert::AreEqual(0xFFDEB887u, (unsigned)Drawing::Color::BurlyWood().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::BurlyWood().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::BurlyWood().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::BurlyWood().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::BurlyWood().IsSystemColor(), sw_current_information);
      Assert::AreEqual("BurlyWood", Drawing::Color::BurlyWood().Name(), sw_current_information);
      Assert::AreEqual("Color [BurlyWood]", Drawing::Color::BurlyWood().ToString(), sw_current_information);
    }
    
    void CadetBlue() {
      Assert::AreEqual(0xFF5F9EA0u, (unsigned)Drawing::Color::CadetBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::CadetBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::CadetBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::CadetBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::CadetBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("CadetBlue", Drawing::Color::CadetBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [CadetBlue]", Drawing::Color::CadetBlue().ToString(), sw_current_information);
    }
    
    void Chartreuse() {
      Assert::AreEqual(0xFF7FFF00u, (unsigned)Drawing::Color::Chartreuse().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Chartreuse().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Chartreuse().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Chartreuse().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Chartreuse().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Chartreuse", Drawing::Color::Chartreuse().Name(), sw_current_information);
      Assert::AreEqual("Color [Chartreuse]", Drawing::Color::Chartreuse().ToString(), sw_current_information);
    }
    
    void Chocolate() {
      Assert::AreEqual(0xFFD2691Eu, (unsigned)Drawing::Color::Chocolate().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Chocolate().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Chocolate().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Chocolate().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Chocolate().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Chocolate", Drawing::Color::Chocolate().Name(), sw_current_information);
      Assert::AreEqual("Color [Chocolate]", Drawing::Color::Chocolate().ToString(), sw_current_information);
    }
    
    void Coral() {
      Assert::AreEqual(0xFFFF7F50u, (unsigned)Drawing::Color::Coral().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Coral().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Coral().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Coral().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Coral().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Coral", Drawing::Color::Coral().Name(), sw_current_information);
      Assert::AreEqual("Color [Coral]", Drawing::Color::Coral().ToString(), sw_current_information);
    }
    
    void CornflowerBlue() {
      Assert::AreEqual(0xFF6495EDu, (unsigned)Drawing::Color::CornflowerBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::CornflowerBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::CornflowerBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::CornflowerBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::CornflowerBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("CornflowerBlue", Drawing::Color::CornflowerBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [CornflowerBlue]", Drawing::Color::CornflowerBlue().ToString(), sw_current_information);
    }
    
    void Cornsilk() {
      Assert::AreEqual(0xFFFFF8DCu, (unsigned)Drawing::Color::Cornsilk().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Cornsilk().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Cornsilk().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Cornsilk().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Cornsilk().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Cornsilk", Drawing::Color::Cornsilk().Name(), sw_current_information);
      Assert::AreEqual("Color [Cornsilk]", Drawing::Color::Cornsilk().ToString(), sw_current_information);
    }
    
    void Crimson() {
      Assert::AreEqual(0xFFDC143Cu, (unsigned)Drawing::Color::Crimson().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Crimson().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Crimson().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Crimson().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Crimson().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Crimson", Drawing::Color::Crimson().Name(), sw_current_information);
      Assert::AreEqual("Color [Crimson]", Drawing::Color::Crimson().ToString(), sw_current_information);
    }
    
    void Cyan() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Cyan().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Cyan().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Cyan().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Cyan().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Cyan().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Cyan", Drawing::Color::Cyan().Name(), sw_current_information);
      Assert::AreEqual("Color [Cyan]", Drawing::Color::Cyan().ToString(), sw_current_information);
    }
    
    void DarkBlue() {
      Assert::AreEqual(0xFF00008Bu, (unsigned)Drawing::Color::DarkBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkBlue", Drawing::Color::DarkBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkBlue]", Drawing::Color::DarkBlue().ToString(), sw_current_information);
    }
    
    void DarkCyan() {
      Assert::AreEqual(0xFF008B8Bu, (unsigned)Drawing::Color::DarkCyan().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkCyan().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkCyan().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkCyan().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkCyan().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkCyan", Drawing::Color::DarkCyan().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkCyan]", Drawing::Color::DarkCyan().ToString(), sw_current_information);
    }
    
    void DarkGoldenrod() {
      Assert::AreEqual(0xFFB8860Bu, (unsigned)Drawing::Color::DarkGoldenrod().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkGoldenrod", Drawing::Color::DarkGoldenrod().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkGoldenrod]", Drawing::Color::DarkGoldenrod().ToString(), sw_current_information);
    }
    
    void DarkGray() {
      Assert::AreEqual(0xFFA9A9A9u, (unsigned)Drawing::Color::DarkGray().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkGray().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkGray().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkGray().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkGray().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkGray", Drawing::Color::DarkGray().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkGray]", Drawing::Color::DarkGray().ToString(), sw_current_information);
    }
    
    void DarkGreen() {
      Assert::AreEqual(0xFF006400u, (unsigned)Drawing::Color::DarkGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkGreen", Drawing::Color::DarkGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkGreen]", Drawing::Color::DarkGreen().ToString(), sw_current_information);
    }
    
    void DarkKhaki() {
      Assert::AreEqual(0xFFBDB76Bu, (unsigned)Drawing::Color::DarkKhaki().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkKhaki().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkKhaki().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkKhaki().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkKhaki().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkKhaki", Drawing::Color::DarkKhaki().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkKhaki]", Drawing::Color::DarkKhaki().ToString(), sw_current_information);
    }
    
    void DarkMagenta() {
      Assert::AreEqual(0xFF8B008Bu, (unsigned)Drawing::Color::DarkMagenta().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkMagenta().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkMagenta().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkMagenta().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkMagenta().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkMagenta", Drawing::Color::DarkMagenta().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkMagenta]", Drawing::Color::DarkMagenta().ToString(), sw_current_information);
    }
    
    void DarkOliveGreen() {
      Assert::AreEqual(0xFF556B2Fu, (unsigned)Drawing::Color::DarkOliveGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkOliveGreen", Drawing::Color::DarkOliveGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkOliveGreen]", Drawing::Color::DarkOliveGreen().ToString(), sw_current_information);
    }
    
    void DarkOrange() {
      Assert::AreEqual(0xFFFF8C00u, (unsigned)Drawing::Color::DarkOrange().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrange().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrange().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrange().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrange().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkOrange", Drawing::Color::DarkOrange().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkOrange]", Drawing::Color::DarkOrange().ToString(), sw_current_information);
    }
    
    void DarkOrchid() {
      Assert::AreEqual(0xFF9932CCu, (unsigned)Drawing::Color::DarkOrchid().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrchid().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrchid().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrchid().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrchid().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkOrchid", Drawing::Color::DarkOrchid().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkOrchid]", Drawing::Color::DarkOrchid().ToString(), sw_current_information);
    }
    
    void DarkRed() {
      Assert::AreEqual(0xFF8B0000u, (unsigned)Drawing::Color::DarkRed().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkRed().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkRed().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkRed().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkRed().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkRed", Drawing::Color::DarkRed().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkRed]", Drawing::Color::DarkRed().ToString(), sw_current_information);
    }
    
    void DarkSalmon() {
      Assert::AreEqual(0xFFE9967Au, (unsigned)Drawing::Color::DarkSalmon().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSalmon().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSalmon().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSalmon().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSalmon().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkSalmon", Drawing::Color::DarkSalmon().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkSalmon]", Drawing::Color::DarkSalmon().ToString(), sw_current_information);
    }
    
    void DarkSeaGreen() {
      Assert::AreEqual(0xFF8FBC8Bu, (unsigned)Drawing::Color::DarkSeaGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkSeaGreen", Drawing::Color::DarkSeaGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkSeaGreen]", Drawing::Color::DarkSeaGreen().ToString(), sw_current_information);
    }
    
    void DarkSlateBlue() {
      Assert::AreEqual(0xFF483D8Bu, (unsigned)Drawing::Color::DarkSlateBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkSlateBlue", Drawing::Color::DarkSlateBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkSlateBlue]", Drawing::Color::DarkSlateBlue().ToString(), sw_current_information);
    }
    
    void DarkSlateGray() {
      Assert::AreEqual(0xFF2F4F4Fu, (unsigned)Drawing::Color::DarkSlateGray().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateGray().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateGray().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateGray().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateGray().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkSlateGray", Drawing::Color::DarkSlateGray().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkSlateGray]", Drawing::Color::DarkSlateGray().ToString(), sw_current_information);
    }
    
    void DarkTurquoise() {
      Assert::AreEqual(0xFF00CED1u, (unsigned)Drawing::Color::DarkTurquoise().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkTurquoise().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkTurquoise().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkTurquoise().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkTurquoise().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkTurquoise", Drawing::Color::DarkTurquoise().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkTurquoise]", Drawing::Color::DarkTurquoise().ToString(), sw_current_information);
    }
    
    void DarkViolet() {
      Assert::AreEqual(0xFF9400D3u, (unsigned)Drawing::Color::DarkViolet().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkViolet().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkViolet().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DarkViolet().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DarkViolet().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DarkViolet", Drawing::Color::DarkViolet().Name(), sw_current_information);
      Assert::AreEqual("Color [DarkViolet]", Drawing::Color::DarkViolet().ToString(), sw_current_information);
    }
    
    void DeepPink() {
      Assert::AreEqual(0xFFFF1493u, (unsigned)Drawing::Color::DeepPink().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DeepPink().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DeepPink().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DeepPink().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DeepPink().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DeepPink", Drawing::Color::DeepPink().Name(), sw_current_information);
      Assert::AreEqual("Color [DeepPink]", Drawing::Color::DeepPink().ToString(), sw_current_information);
    }
    
    void DeepSkyBlue() {
      Assert::AreEqual(0xFF00BFFFu, (unsigned)Drawing::Color::DeepSkyBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DeepSkyBlue", Drawing::Color::DeepSkyBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [DeepSkyBlue]", Drawing::Color::DeepSkyBlue().ToString(), sw_current_information);
    }
    
    void DimGray() {
      Assert::AreEqual(0xFF696969u, (unsigned)Drawing::Color::DimGray().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DimGray().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DimGray().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DimGray().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DimGray().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DimGray", Drawing::Color::DimGray().Name(), sw_current_information);
      Assert::AreEqual("Color [DimGray]", Drawing::Color::DimGray().ToString(), sw_current_information);
    }
    
    void DodgerBlue() {
      Assert::AreEqual(0xFF1E90FFu, (unsigned)Drawing::Color::DodgerBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DodgerBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DodgerBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::DodgerBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::DodgerBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("DodgerBlue", Drawing::Color::DodgerBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [DodgerBlue]", Drawing::Color::DodgerBlue().ToString(), sw_current_information);
    }
    
    void Firebrick() {
      Assert::AreEqual(0xFFB22222u, (unsigned)Drawing::Color::Firebrick().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Firebrick().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Firebrick().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Firebrick().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Firebrick().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Firebrick", Drawing::Color::Firebrick().Name(), sw_current_information);
      Assert::AreEqual("Color [Firebrick]", Drawing::Color::Firebrick().ToString(), sw_current_information);
    }
    
    void FloralWhite() {
      Assert::AreEqual(0xFFFFFAF0u, (unsigned)Drawing::Color::FloralWhite().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FloralWhite().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::FloralWhite().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::FloralWhite().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::FloralWhite().IsSystemColor(), sw_current_information);
      Assert::AreEqual("FloralWhite", Drawing::Color::FloralWhite().Name(), sw_current_information);
      Assert::AreEqual("Color [FloralWhite]", Drawing::Color::FloralWhite().ToString(), sw_current_information);
    }
    
    void ForestGreen() {
      Assert::AreEqual(0xFF228B22u, (unsigned)Drawing::Color::ForestGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::ForestGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::ForestGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::ForestGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::ForestGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("ForestGreen", Drawing::Color::ForestGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [ForestGreen]", Drawing::Color::ForestGreen().ToString(), sw_current_information);
    }
    
    void Fuchsia() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Fuchsia().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Fuchsia().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Fuchsia().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Fuchsia().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Fuchsia().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Fuchsia", Drawing::Color::Fuchsia().Name(), sw_current_information);
      Assert::AreEqual("Color [Fuchsia]", Drawing::Color::Fuchsia().ToString(), sw_current_information);
    }
    
    void Gainsboro() {
      Assert::AreEqual(0xFFDCDCDCu, (unsigned)Drawing::Color::Gainsboro().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Gainsboro().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Gainsboro().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Gainsboro().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Gainsboro().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Gainsboro", Drawing::Color::Gainsboro().Name(), sw_current_information);
      Assert::AreEqual("Color [Gainsboro]", Drawing::Color::Gainsboro().ToString(), sw_current_information);
    }
    
    void GhostWhite() {
      Assert::AreEqual(0xFFF8F8FFu, (unsigned)Drawing::Color::GhostWhite().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::GhostWhite().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::GhostWhite().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::GhostWhite().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::GhostWhite().IsSystemColor(), sw_current_information);
      Assert::AreEqual("GhostWhite", Drawing::Color::GhostWhite().Name(), sw_current_information);
      Assert::AreEqual("Color [GhostWhite]", Drawing::Color::GhostWhite().ToString(), sw_current_information);
    }
    
    void Gold() {
      Assert::AreEqual(0xFFFFD700u, (unsigned)Drawing::Color::Gold().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Gold().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Gold().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Gold().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Gold().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Gold", Drawing::Color::Gold().Name(), sw_current_information);
      Assert::AreEqual("Color [Gold]", Drawing::Color::Gold().ToString(), sw_current_information);
    }
    
    void Goldenrod() {
      Assert::AreEqual(0xFFDAA520u, (unsigned)Drawing::Color::Goldenrod().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Goldenrod().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Goldenrod().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Goldenrod().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Goldenrod().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Goldenrod", Drawing::Color::Goldenrod().Name(), sw_current_information);
      Assert::AreEqual("Color [Goldenrod]", Drawing::Color::Goldenrod().ToString(), sw_current_information);
    }
    
    void Gray() {
      Assert::AreEqual(0xFF808080u, (unsigned)Drawing::Color::Gray().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Gray().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Gray().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Gray().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Gray().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Gray", Drawing::Color::Gray().Name(), sw_current_information);
      Assert::AreEqual("Color [Gray]", Drawing::Color::Gray().ToString(), sw_current_information);
    }
    
    void Green() {
      Assert::AreEqual(0xFF008000u, (unsigned)Drawing::Color::Green().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Green().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Green().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Green().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Green().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Green", Drawing::Color::Green().Name(), sw_current_information);
      Assert::AreEqual("Color [Green]", Drawing::Color::Green().ToString(), sw_current_information);
    }
    
    void GreenYellow() {
      Assert::AreEqual(0xFFADFF2Fu, (unsigned)Drawing::Color::GreenYellow().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::GreenYellow().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::GreenYellow().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::GreenYellow().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::GreenYellow().IsSystemColor(), sw_current_information);
      Assert::AreEqual("GreenYellow", Drawing::Color::GreenYellow().Name(), sw_current_information);
      Assert::AreEqual("Color [GreenYellow]", Drawing::Color::GreenYellow().ToString(), sw_current_information);
    }
    
    void Honeydew() {
      Assert::AreEqual(0xFFF0FFF0u, (unsigned)Drawing::Color::Honeydew().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Honeydew().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Honeydew().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Honeydew().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Honeydew().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Honeydew", Drawing::Color::Honeydew().Name(), sw_current_information);
      Assert::AreEqual("Color [Honeydew]", Drawing::Color::Honeydew().ToString(), sw_current_information);
    }
    
    void HotPink() {
      Assert::AreEqual(0xFFFF69B4u, (unsigned)Drawing::Color::HotPink().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::HotPink().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::HotPink().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::HotPink().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::HotPink().IsSystemColor(), sw_current_information);
      Assert::AreEqual("HotPink", Drawing::Color::HotPink().Name(), sw_current_information);
      Assert::AreEqual("Color [HotPink]", Drawing::Color::HotPink().ToString(), sw_current_information);
    }
    
    void IndianRed() {
      Assert::AreEqual(0xFFCD5C5Cu, (unsigned)Drawing::Color::IndianRed().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::IndianRed().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::IndianRed().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::IndianRed().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::IndianRed().IsSystemColor(), sw_current_information);
      Assert::AreEqual("IndianRed", Drawing::Color::IndianRed().Name(), sw_current_information);
      Assert::AreEqual("Color [IndianRed]", Drawing::Color::IndianRed().ToString(), sw_current_information);
    }
    
    void Indigo() {
      Assert::AreEqual(0xFF4B0082u, (unsigned)Drawing::Color::Indigo().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Indigo().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Indigo().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Indigo().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Indigo().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Indigo", Drawing::Color::Indigo().Name(), sw_current_information);
      Assert::AreEqual("Color [Indigo]", Drawing::Color::Indigo().ToString(), sw_current_information);
    }
    
    void Ivory() {
      Assert::AreEqual(0xFFFFFFF0u, (unsigned)Drawing::Color::Ivory().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Ivory().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Ivory().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Ivory().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Ivory().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Ivory", Drawing::Color::Ivory().Name(), sw_current_information);
      Assert::AreEqual("Color [Ivory]", Drawing::Color::Ivory().ToString(), sw_current_information);
    }
    
    void Khaki() {
      Assert::AreEqual(0xFFF0E68Cu, (unsigned)Drawing::Color::Khaki().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Khaki().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Khaki().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Khaki().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Khaki().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Khaki", Drawing::Color::Khaki().Name(), sw_current_information);
      Assert::AreEqual("Color [Khaki]", Drawing::Color::Khaki().ToString(), sw_current_information);
    }
    
    void Lavender() {
      Assert::AreEqual(0xFFE6E6FAu, (unsigned)Drawing::Color::Lavender().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Lavender().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Lavender().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Lavender().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Lavender().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Lavender", Drawing::Color::Lavender().Name(), sw_current_information);
      Assert::AreEqual("Color [Lavender]", Drawing::Color::Lavender().ToString(), sw_current_information);
    }
    
    void LavenderBlush() {
      Assert::AreEqual(0xFFFFF0F5u, (unsigned)Drawing::Color::LavenderBlush().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LavenderBlush().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LavenderBlush().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LavenderBlush().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LavenderBlush().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LavenderBlush", Drawing::Color::LavenderBlush().Name(), sw_current_information);
      Assert::AreEqual("Color [LavenderBlush]", Drawing::Color::LavenderBlush().ToString(), sw_current_information);
    }
    
    void LawnGreen() {
      Assert::AreEqual(0xFF7CFC00u, (unsigned)Drawing::Color::LawnGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LawnGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LawnGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LawnGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LawnGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LawnGreen", Drawing::Color::LawnGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [LawnGreen]", Drawing::Color::LawnGreen().ToString(), sw_current_information);
    }
    
    void LemonChiffon() {
      Assert::AreEqual(0xFFFFFACDu, (unsigned)Drawing::Color::LemonChiffon().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LemonChiffon().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LemonChiffon().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LemonChiffon().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LemonChiffon().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LemonChiffon", Drawing::Color::LemonChiffon().Name(), sw_current_information);
      Assert::AreEqual("Color [LemonChiffon]", Drawing::Color::LemonChiffon().ToString(), sw_current_information);
    }
    
    void LightBlue() {
      Assert::AreEqual(0xFFADD8E6u, (unsigned)Drawing::Color::LightBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightBlue", Drawing::Color::LightBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [LightBlue]", Drawing::Color::LightBlue().ToString(), sw_current_information);
    }
    
    void LightCoral() {
      Assert::AreEqual(0xFFF08080u, (unsigned)Drawing::Color::LightCoral().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightCoral().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightCoral().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightCoral().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightCoral().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightCoral", Drawing::Color::LightCoral().Name(), sw_current_information);
      Assert::AreEqual("Color [LightCoral]", Drawing::Color::LightCoral().ToString(), sw_current_information);
    }
    
    void LightCyan() {
      Assert::AreEqual(0xFFE0FFFFu, (unsigned)Drawing::Color::LightCyan().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightCyan().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightCyan().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightCyan().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightCyan().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightCyan", Drawing::Color::LightCyan().Name(), sw_current_information);
      Assert::AreEqual("Color [LightCyan]", Drawing::Color::LightCyan().ToString(), sw_current_information);
    }
    
    void LightGoldenrodYellow() {
      Assert::AreEqual(0xFFFAFAD2u, (unsigned)Drawing::Color::LightGoldenrodYellow().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightGoldenrodYellow", Drawing::Color::LightGoldenrodYellow().Name(), sw_current_information);
      Assert::AreEqual("Color [LightGoldenrodYellow]", Drawing::Color::LightGoldenrodYellow().ToString(), sw_current_information);
    }
    
    void LightGray() {
      Assert::AreEqual(0xFFD3D3D3u, (unsigned)Drawing::Color::LightGray().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightGray().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightGray().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightGray().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightGray().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightGray", Drawing::Color::LightGray().Name(), sw_current_information);
      Assert::AreEqual("Color [LightGray]", Drawing::Color::LightGray().ToString(), sw_current_information);
    }
    
    void LightGreen() {
      Assert::AreEqual(0xFF90EE90u, (unsigned)Drawing::Color::LightGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightGreen", Drawing::Color::LightGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [LightGreen]", Drawing::Color::LightGreen().ToString(), sw_current_information);
    }
    
    void LightPink() {
      Assert::AreEqual(0xFFFFB6C1u, (unsigned)Drawing::Color::LightPink().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightPink().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightPink().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightPink().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightPink().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightPink", Drawing::Color::LightPink().Name(), sw_current_information);
      Assert::AreEqual("Color [LightPink]", Drawing::Color::LightPink().ToString(), sw_current_information);
    }
    
    void LightSalmon() {
      Assert::AreEqual(0xFFFFA07Au, (unsigned)Drawing::Color::LightSalmon().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSalmon().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSalmon().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSalmon().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSalmon().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightSalmon", Drawing::Color::LightSalmon().Name(), sw_current_information);
      Assert::AreEqual("Color [LightSalmon]", Drawing::Color::LightSalmon().ToString(), sw_current_information);
    }
    
    void LightSeaGreen() {
      Assert::AreEqual(0xFF20B2AAu, (unsigned)Drawing::Color::LightSeaGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSeaGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSeaGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSeaGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSeaGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightSeaGreen", Drawing::Color::LightSeaGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [LightSeaGreen]", Drawing::Color::LightSeaGreen().ToString(), sw_current_information);
    }
    
    void LightSkyBlue() {
      Assert::AreEqual(0xFF87CEFAu, (unsigned)Drawing::Color::LightSkyBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSkyBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSkyBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSkyBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSkyBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightSkyBlue", Drawing::Color::LightSkyBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [LightSkyBlue]", Drawing::Color::LightSkyBlue().ToString(), sw_current_information);
    }
    
    void LightSlateGray() {
      Assert::AreEqual(0xFF778899u, (unsigned)Drawing::Color::LightSlateGray().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSlateGray().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSlateGray().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSlateGray().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSlateGray().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightSlateGray", Drawing::Color::LightSlateGray().Name(), sw_current_information);
      Assert::AreEqual("Color [LightSlateGray]", Drawing::Color::LightSlateGray().ToString(), sw_current_information);
    }
    
    void LightSteelBlue() {
      Assert::AreEqual(0xFFB0C4DEu, (unsigned)Drawing::Color::LightSteelBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSteelBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSteelBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightSteelBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightSteelBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightSteelBlue", Drawing::Color::LightSteelBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [LightSteelBlue]", Drawing::Color::LightSteelBlue().ToString(), sw_current_information);
    }
    
    void LightYellow() {
      Assert::AreEqual(0xFFFFFFE0u, (unsigned)Drawing::Color::LightYellow().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightYellow().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightYellow().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LightYellow().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LightYellow().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LightYellow", Drawing::Color::LightYellow().Name(), sw_current_information);
      Assert::AreEqual("Color [LightYellow]", Drawing::Color::LightYellow().ToString(), sw_current_information);
    }
    
    void Lime() {
      Assert::AreEqual(0xFF00FF00u, (unsigned)Drawing::Color::Lime().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Lime().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Lime().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Lime().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Lime().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Lime", Drawing::Color::Lime().Name(), sw_current_information);
      Assert::AreEqual("Color [Lime]", Drawing::Color::Lime().ToString(), sw_current_information);
    }
    
    void LimeGreen() {
      Assert::AreEqual(0xFF32CD32u, (unsigned)Drawing::Color::LimeGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LimeGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LimeGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::LimeGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::LimeGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("LimeGreen", Drawing::Color::LimeGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [LimeGreen]", Drawing::Color::LimeGreen().ToString(), sw_current_information);
    }
    
    void Linen() {
      Assert::AreEqual(0xFFFAF0E6u, (unsigned)Drawing::Color::Linen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Linen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Linen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Linen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Linen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Linen", Drawing::Color::Linen().Name(), sw_current_information);
      Assert::AreEqual("Color [Linen]", Drawing::Color::Linen().ToString(), sw_current_information);
    }
    
    void Magenta() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Magenta().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Magenta().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Magenta().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Magenta().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Magenta().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Magenta", Drawing::Color::Magenta().Name(), sw_current_information);
      Assert::AreEqual("Color [Magenta]", Drawing::Color::Magenta().ToString(), sw_current_information);
    }
    
    void Maroon() {
      Assert::AreEqual(0xFF800000u, (unsigned)Drawing::Color::Maroon().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Maroon().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Maroon().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Maroon().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Maroon().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Maroon", Drawing::Color::Maroon().Name(), sw_current_information);
      Assert::AreEqual("Color [Maroon]", Drawing::Color::Maroon().ToString(), sw_current_information);
    }
    
    void MediumAquamarine() {
      Assert::AreEqual(0xFF66CDAAu, (unsigned)Drawing::Color::MediumAquamarine().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumAquamarine().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumAquamarine().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumAquamarine().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumAquamarine().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumAquamarine", Drawing::Color::MediumAquamarine().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumAquamarine]", Drawing::Color::MediumAquamarine().ToString(), sw_current_information);
    }
    
    void MediumBlue() {
      Assert::AreEqual(0xFF0000CDu, (unsigned)Drawing::Color::MediumBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumBlue", Drawing::Color::MediumBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumBlue]", Drawing::Color::MediumBlue().ToString(), sw_current_information);
    }
    
    void MediumOrchid() {
      Assert::AreEqual(0xFFBA55D3u, (unsigned)Drawing::Color::MediumOrchid().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumOrchid().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumOrchid().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumOrchid().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumOrchid().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumOrchid", Drawing::Color::MediumOrchid().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumOrchid]", Drawing::Color::MediumOrchid().ToString(), sw_current_information);
    }
    
    void MediumPurple() {
      Assert::AreEqual(0xFF9370DBu, (unsigned)Drawing::Color::MediumPurple().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumPurple().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumPurple().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumPurple().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumPurple().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumPurple", Drawing::Color::MediumPurple().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumPurple]", Drawing::Color::MediumPurple().ToString(), sw_current_information);
    }
    
    void MediumSeaGreen() {
      Assert::AreEqual(0xFF3CB371u, (unsigned)Drawing::Color::MediumSeaGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumSeaGreen", Drawing::Color::MediumSeaGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumSeaGreen]", Drawing::Color::MediumSeaGreen().ToString(), sw_current_information);
    }
    
    void MediumSlateBlue() {
      Assert::AreEqual(0xFF7B68EEu, (unsigned)Drawing::Color::MediumSlateBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumSlateBlue", Drawing::Color::MediumSlateBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumSlateBlue]", Drawing::Color::MediumSlateBlue().ToString(), sw_current_information);
    }
    
    void MediumSpringGreen() {
      Assert::AreEqual(0xFF00FA9Au, (unsigned)Drawing::Color::MediumSpringGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumSpringGreen", Drawing::Color::MediumSpringGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumSpringGreen]", Drawing::Color::MediumSpringGreen().ToString(), sw_current_information);
    }
    
    void MediumTurquoise() {
      Assert::AreEqual(0xFF48D1CCu, (unsigned)Drawing::Color::MediumTurquoise().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumTurquoise().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumTurquoise().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumTurquoise().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumTurquoise().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumTurquoise", Drawing::Color::MediumTurquoise().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumTurquoise]", Drawing::Color::MediumTurquoise().ToString(), sw_current_information);
    }
    
    void MediumVioletRed() {
      Assert::AreEqual(0xFFC71585u, (unsigned)Drawing::Color::MediumVioletRed().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumVioletRed().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumVioletRed().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MediumVioletRed().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MediumVioletRed().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MediumVioletRed", Drawing::Color::MediumVioletRed().Name(), sw_current_information);
      Assert::AreEqual("Color [MediumVioletRed]", Drawing::Color::MediumVioletRed().ToString(), sw_current_information);
    }
    
    void MidnightBlue() {
      Assert::AreEqual(0xFF191970u, (unsigned)Drawing::Color::MidnightBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MidnightBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MidnightBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MidnightBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MidnightBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MidnightBlue", Drawing::Color::MidnightBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [MidnightBlue]", Drawing::Color::MidnightBlue().ToString(), sw_current_information);
    }
    
    void MintCream() {
      Assert::AreEqual(0xFFF5FFFAu, (unsigned)Drawing::Color::MintCream().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MintCream().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MintCream().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MintCream().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MintCream().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MintCream", Drawing::Color::MintCream().Name(), sw_current_information);
      Assert::AreEqual("Color [MintCream]", Drawing::Color::MintCream().ToString(), sw_current_information);
    }
    
    void MistyRose() {
      Assert::AreEqual(0xFFFFE4E1u, (unsigned)Drawing::Color::MistyRose().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MistyRose().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MistyRose().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::MistyRose().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::MistyRose().IsSystemColor(), sw_current_information);
      Assert::AreEqual("MistyRose", Drawing::Color::MistyRose().Name(), sw_current_information);
      Assert::AreEqual("Color [MistyRose]", Drawing::Color::MistyRose().ToString(), sw_current_information);
    }
    
    void Moccasin() {
      Assert::AreEqual(0xFFFFE4B5u, (unsigned)Drawing::Color::Moccasin().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Moccasin().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Moccasin().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Moccasin().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Moccasin().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Moccasin", Drawing::Color::Moccasin().Name(), sw_current_information);
      Assert::AreEqual("Color [Moccasin]", Drawing::Color::Moccasin().ToString(), sw_current_information);
    }
    
    void NavajoWhite() {
      Assert::AreEqual(0xFFFFDEADu, (unsigned)Drawing::Color::NavajoWhite().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::NavajoWhite().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::NavajoWhite().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::NavajoWhite().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::NavajoWhite().IsSystemColor(), sw_current_information);
      Assert::AreEqual("NavajoWhite", Drawing::Color::NavajoWhite().Name(), sw_current_information);
      Assert::AreEqual("Color [NavajoWhite]", Drawing::Color::NavajoWhite().ToString(), sw_current_information);
    }
    
    void Navy() {
      Assert::AreEqual(0xFF000080u, (unsigned)Drawing::Color::Navy().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Navy().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Navy().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Navy().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Navy().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Navy", Drawing::Color::Navy().Name(), sw_current_information);
      Assert::AreEqual("Color [Navy]", Drawing::Color::Navy().ToString(), sw_current_information);
    }
    
    void OldLace() {
      Assert::AreEqual(0xFFFDF5E6u, (unsigned)Drawing::Color::OldLace().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::OldLace().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::OldLace().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::OldLace().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::OldLace().IsSystemColor(), sw_current_information);
      Assert::AreEqual("OldLace", Drawing::Color::OldLace().Name(), sw_current_information);
      Assert::AreEqual("Color [OldLace]", Drawing::Color::OldLace().ToString(), sw_current_information);
    }
    
    void Olive() {
      Assert::AreEqual(0xFF808000u, (unsigned)Drawing::Color::Olive().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Olive().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Olive().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Olive().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Olive().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Olive", Drawing::Color::Olive().Name(), sw_current_information);
      Assert::AreEqual("Color [Olive]", Drawing::Color::Olive().ToString(), sw_current_information);
    }
    
    void OliveDrab() {
      Assert::AreEqual(0xFF6B8E23u, (unsigned)Drawing::Color::OliveDrab().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::OliveDrab().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::OliveDrab().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::OliveDrab().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::OliveDrab().IsSystemColor(), sw_current_information);
      Assert::AreEqual("OliveDrab", Drawing::Color::OliveDrab().Name(), sw_current_information);
      Assert::AreEqual("Color [OliveDrab]", Drawing::Color::OliveDrab().ToString(), sw_current_information);
    }
    
    void Orange() {
      Assert::AreEqual(0xFFFFA500u, (unsigned)Drawing::Color::Orange().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Orange().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Orange().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Orange().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Orange().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Orange", Drawing::Color::Orange().Name(), sw_current_information);
      Assert::AreEqual("Color [Orange]", Drawing::Color::Orange().ToString(), sw_current_information);
    }
    
    void OrangeRed() {
      Assert::AreEqual(0xFFFF4500u, (unsigned)Drawing::Color::OrangeRed().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::OrangeRed().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::OrangeRed().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::OrangeRed().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::OrangeRed().IsSystemColor(), sw_current_information);
      Assert::AreEqual("OrangeRed", Drawing::Color::OrangeRed().Name(), sw_current_information);
      Assert::AreEqual("Color [OrangeRed]", Drawing::Color::OrangeRed().ToString(), sw_current_information);
    }
    
    void Orchid() {
      Assert::AreEqual(0xFFDA70D6u, (unsigned)Drawing::Color::Orchid().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Orchid().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Orchid().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Orchid().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Orchid().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Orchid", Drawing::Color::Orchid().Name(), sw_current_information);
      Assert::AreEqual("Color [Orchid]", Drawing::Color::Orchid().ToString(), sw_current_information);
    }
    
    void PaleGoldenrod() {
      Assert::AreEqual(0xFFEEE8AAu, (unsigned)Drawing::Color::PaleGoldenrod().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod().IsSystemColor(), sw_current_information);
      Assert::AreEqual("PaleGoldenrod", Drawing::Color::PaleGoldenrod().Name(), sw_current_information);
      Assert::AreEqual("Color [PaleGoldenrod]", Drawing::Color::PaleGoldenrod().ToString(), sw_current_information);
    }
    
    void PaleGreen() {
      Assert::AreEqual(0xFF98FB98u, (unsigned)Drawing::Color::PaleGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("PaleGreen", Drawing::Color::PaleGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [PaleGreen]", Drawing::Color::PaleGreen().ToString(), sw_current_information);
    }
    
    void PaleTurquoise() {
      Assert::AreEqual(0xFFAFEEEEu, (unsigned)Drawing::Color::PaleTurquoise().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleTurquoise().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleTurquoise().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleTurquoise().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleTurquoise().IsSystemColor(), sw_current_information);
      Assert::AreEqual("PaleTurquoise", Drawing::Color::PaleTurquoise().Name(), sw_current_information);
      Assert::AreEqual("Color [PaleTurquoise]", Drawing::Color::PaleTurquoise().ToString(), sw_current_information);
    }
    
    void PaleVioletRed() {
      Assert::AreEqual(0xFFDB7093u, (unsigned)Drawing::Color::PaleVioletRed().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleVioletRed().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleVioletRed().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PaleVioletRed().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PaleVioletRed().IsSystemColor(), sw_current_information);
      Assert::AreEqual("PaleVioletRed", Drawing::Color::PaleVioletRed().Name(), sw_current_information);
      Assert::AreEqual("Color [PaleVioletRed]", Drawing::Color::PaleVioletRed().ToString(), sw_current_information);
    }
    
    void PapayaWhip() {
      Assert::AreEqual(0xFFFFEFD5u, (unsigned)Drawing::Color::PapayaWhip().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PapayaWhip().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PapayaWhip().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PapayaWhip().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PapayaWhip().IsSystemColor(), sw_current_information);
      Assert::AreEqual("PapayaWhip", Drawing::Color::PapayaWhip().Name(), sw_current_information);
      Assert::AreEqual("Color [PapayaWhip]", Drawing::Color::PapayaWhip().ToString(), sw_current_information);
    }
    
    void PeachPuff() {
      Assert::AreEqual(0xFFFFDAB9u, (unsigned)Drawing::Color::PeachPuff().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PeachPuff().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PeachPuff().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PeachPuff().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PeachPuff().IsSystemColor(), sw_current_information);
      Assert::AreEqual("PeachPuff", Drawing::Color::PeachPuff().Name(), sw_current_information);
      Assert::AreEqual("Color [PeachPuff]", Drawing::Color::PeachPuff().ToString(), sw_current_information);
    }
    
    void Peru() {
      Assert::AreEqual(0xFFCD853Fu, (unsigned)Drawing::Color::Peru().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Peru().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Peru().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Peru().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Peru().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Peru", Drawing::Color::Peru().Name(), sw_current_information);
      Assert::AreEqual("Color [Peru]", Drawing::Color::Peru().ToString(), sw_current_information);
    }
    
    void Pink() {
      Assert::AreEqual(0xFFFFC0CBu, (unsigned)Drawing::Color::Pink().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Pink().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Pink().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Pink().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Pink().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Pink", Drawing::Color::Pink().Name(), sw_current_information);
      Assert::AreEqual("Color [Pink]", Drawing::Color::Pink().ToString(), sw_current_information);
    }
    
    void Plum() {
      Assert::AreEqual(0xFFDDA0DDu, (unsigned)Drawing::Color::Plum().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Plum().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Plum().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Plum().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Plum().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Plum", Drawing::Color::Plum().Name(), sw_current_information);
      Assert::AreEqual("Color [Plum]", Drawing::Color::Plum().ToString(), sw_current_information);
    }
    
    void PowderBlue() {
      Assert::AreEqual(0xFFB0E0E6u, (unsigned)Drawing::Color::PowderBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PowderBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PowderBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::PowderBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::PowderBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("PowderBlue", Drawing::Color::PowderBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [PowderBlue]", Drawing::Color::PowderBlue().ToString(), sw_current_information);
    }
    
    void Purple() {
      Assert::AreEqual(0xFF800080u, (unsigned)Drawing::Color::Purple().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Purple().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Purple().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Purple().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Purple().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Purple", Drawing::Color::Purple().Name(), sw_current_information);
      Assert::AreEqual("Color [Purple]", Drawing::Color::Purple().ToString(), sw_current_information);
    }
    
    void Red() {
      Assert::AreEqual(0xFFFF0000u, (unsigned)Drawing::Color::Red().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Red().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Red().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Red().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Red().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Red", Drawing::Color::Red().Name(), sw_current_information);
      Assert::AreEqual("Color [Red]", Drawing::Color::Red().ToString(), sw_current_information);
    }
    
    void RosyBrown() {
      Assert::AreEqual(0xFFBC8F8Fu, (unsigned)Drawing::Color::RosyBrown().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::RosyBrown().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::RosyBrown().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::RosyBrown().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::RosyBrown().IsSystemColor(), sw_current_information);
      Assert::AreEqual("RosyBrown", Drawing::Color::RosyBrown().Name(), sw_current_information);
      Assert::AreEqual("Color [RosyBrown]", Drawing::Color::RosyBrown().ToString(), sw_current_information);
    }
    
    void RoyalBlue() {
      Assert::AreEqual(0xFF4169E1u, (unsigned)Drawing::Color::RoyalBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::RoyalBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::RoyalBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::RoyalBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::RoyalBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("RoyalBlue", Drawing::Color::RoyalBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [RoyalBlue]", Drawing::Color::RoyalBlue().ToString(), sw_current_information);
    }
    
    void SaddleBrown() {
      Assert::AreEqual(0xFF8B4513u, (unsigned)Drawing::Color::SaddleBrown().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SaddleBrown().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SaddleBrown().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SaddleBrown().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SaddleBrown().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SaddleBrown", Drawing::Color::SaddleBrown().Name(), sw_current_information);
      Assert::AreEqual("Color [SaddleBrown]", Drawing::Color::SaddleBrown().ToString(), sw_current_information);
    }
    
    void Salmon() {
      Assert::AreEqual(0xFFFA8072u, (unsigned)Drawing::Color::Salmon().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Salmon().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Salmon().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Salmon().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Salmon().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Salmon", Drawing::Color::Salmon().Name(), sw_current_information);
      Assert::AreEqual("Color [Salmon]", Drawing::Color::Salmon().ToString(), sw_current_information);
    }
    
    void SandyBrown() {
      Assert::AreEqual(0xFFF4A460u, (unsigned)Drawing::Color::SandyBrown().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SandyBrown().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SandyBrown().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SandyBrown().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SandyBrown().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SandyBrown", Drawing::Color::SandyBrown().Name(), sw_current_information);
      Assert::AreEqual("Color [SandyBrown]", Drawing::Color::SandyBrown().ToString(), sw_current_information);
    }
    
    void SeaGreen() {
      Assert::AreEqual(0xFF2E8B57u, (unsigned)Drawing::Color::SeaGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SeaGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SeaGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SeaGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SeaGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SeaGreen", Drawing::Color::SeaGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [SeaGreen]", Drawing::Color::SeaGreen().ToString(), sw_current_information);
    }
    
    void SeaShell() {
      Assert::AreEqual(0xFFFFF5EEu, (unsigned)Drawing::Color::SeaShell().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SeaShell().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SeaShell().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SeaShell().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SeaShell().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SeaShell", Drawing::Color::SeaShell().Name(), sw_current_information);
      Assert::AreEqual("Color [SeaShell]", Drawing::Color::SeaShell().ToString(), sw_current_information);
    }
    
    void Sienna() {
      Assert::AreEqual(0xFFA0522Du, (unsigned)Drawing::Color::Sienna().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Sienna().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Sienna().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Sienna().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Sienna().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Sienna", Drawing::Color::Sienna().Name(), sw_current_information);
      Assert::AreEqual("Color [Sienna]", Drawing::Color::Sienna().ToString(), sw_current_information);
    }
    
    void Silver() {
      Assert::AreEqual(0xFFC0C0C0u, (unsigned)Drawing::Color::Silver().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Silver().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Silver().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Silver().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Silver().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Silver", Drawing::Color::Silver().Name(), sw_current_information);
      Assert::AreEqual("Color [Silver]", Drawing::Color::Silver().ToString(), sw_current_information);
    }
    
    void SkyBlue() {
      Assert::AreEqual(0xFF87CEEBu, (unsigned)Drawing::Color::SkyBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SkyBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SkyBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SkyBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SkyBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SkyBlue", Drawing::Color::SkyBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [SkyBlue]", Drawing::Color::SkyBlue().ToString(), sw_current_information);
    }
    
    void SlateBlue() {
      Assert::AreEqual(0xFF6A5ACDu, (unsigned)Drawing::Color::SlateBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SlateBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SlateBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SlateBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SlateBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SlateBlue", Drawing::Color::SlateBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [SlateBlue]", Drawing::Color::SlateBlue().ToString(), sw_current_information);
    }
    
    void SlateGray() {
      Assert::AreEqual(0xFF708090u, (unsigned)Drawing::Color::SlateGray().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SlateGray().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SlateGray().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SlateGray().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SlateGray().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SlateGray", Drawing::Color::SlateGray().Name(), sw_current_information);
      Assert::AreEqual("Color [SlateGray]", Drawing::Color::SlateGray().ToString(), sw_current_information);
    }
    
    void Snow() {
      Assert::AreEqual(0xFFFFFAFAu, (unsigned)Drawing::Color::Snow().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Snow().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Snow().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Snow().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Snow().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Snow", Drawing::Color::Snow().Name(), sw_current_information);
      Assert::AreEqual("Color [Snow]", Drawing::Color::Snow().ToString(), sw_current_information);
    }
    
    void SpringGreen() {
      Assert::AreEqual(0xFF00FF7Fu, (unsigned)Drawing::Color::SpringGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SpringGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SpringGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SpringGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SpringGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SpringGreen", Drawing::Color::SpringGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [SpringGreen]", Drawing::Color::SpringGreen().ToString(), sw_current_information);
    }
    
    void SteelBlue() {
      Assert::AreEqual(0xFF4682B4u, (unsigned)Drawing::Color::SteelBlue().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SteelBlue().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SteelBlue().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::SteelBlue().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::SteelBlue().IsSystemColor(), sw_current_information);
      Assert::AreEqual("SteelBlue", Drawing::Color::SteelBlue().Name(), sw_current_information);
      Assert::AreEqual("Color [SteelBlue]", Drawing::Color::SteelBlue().ToString(), sw_current_information);
    }
    
    void Tan() {
      Assert::AreEqual(0xFFD2B48Cu, (unsigned)Drawing::Color::Tan().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Tan().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Tan().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Tan().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Tan().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Tan", Drawing::Color::Tan().Name(), sw_current_information);
      Assert::AreEqual("Color [Tan]", Drawing::Color::Tan().ToString(), sw_current_information);
    }
    
    void Teal() {
      Assert::AreEqual(0xFF008080u, (unsigned)Drawing::Color::Teal().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Teal().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Teal().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Teal().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Teal().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Teal", Drawing::Color::Teal().Name(), sw_current_information);
      Assert::AreEqual("Color [Teal]", Drawing::Color::Teal().ToString(), sw_current_information);
    }
    
    void Thistle() {
      Assert::AreEqual(0xFFD8BFD8u, (unsigned)Drawing::Color::Thistle().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Thistle().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Thistle().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Thistle().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Thistle().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Thistle", Drawing::Color::Thistle().Name(), sw_current_information);
      Assert::AreEqual("Color [Thistle]", Drawing::Color::Thistle().ToString(), sw_current_information);
    }
    
    void Tomato() {
      Assert::AreEqual(0xFFFF6347u, (unsigned)Drawing::Color::Tomato().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Tomato().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Tomato().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Tomato().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Tomato().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Tomato", Drawing::Color::Tomato().Name(), sw_current_information);
      Assert::AreEqual("Color [Tomato]", Drawing::Color::Tomato().ToString(), sw_current_information);
    }
    
    void Turquoise() {
      Assert::AreEqual(0xFF40E0D0u, (unsigned)Drawing::Color::Turquoise().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Turquoise().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Turquoise().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Turquoise().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Turquoise().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Turquoise", Drawing::Color::Turquoise().Name(), sw_current_information);
      Assert::AreEqual("Color [Turquoise]", Drawing::Color::Turquoise().ToString(), sw_current_information);
    }
    
    void Violet() {
      Assert::AreEqual(0xFFEE82EEu, (unsigned)Drawing::Color::Violet().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Violet().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Violet().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Violet().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Violet().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Violet", Drawing::Color::Violet().Name(), sw_current_information);
      Assert::AreEqual("Color [Violet]", Drawing::Color::Violet().ToString(), sw_current_information);
    }
    
    void Wheat() {
      Assert::AreEqual(0xFFF5DEB3u, (unsigned)Drawing::Color::Wheat().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Wheat().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Wheat().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Wheat().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Wheat().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Wheat", Drawing::Color::Wheat().Name(), sw_current_information);
      Assert::AreEqual("Color [Wheat]", Drawing::Color::Wheat().ToString(), sw_current_information);
    }
    
    void White() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::Color::White().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::White().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::White().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::White().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::White().IsSystemColor(), sw_current_information);
      Assert::AreEqual("White", Drawing::Color::White().Name(), sw_current_information);
      Assert::AreEqual("Color [White]", Drawing::Color::White().ToString(), sw_current_information);
    }
    
    void WhiteSmoke() {
      Assert::AreEqual(0xFFF5F5F5u, (unsigned)Drawing::Color::WhiteSmoke().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::WhiteSmoke().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::WhiteSmoke().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::WhiteSmoke().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::WhiteSmoke().IsSystemColor(), sw_current_information);
      Assert::AreEqual("WhiteSmoke", Drawing::Color::WhiteSmoke().Name(), sw_current_information);
      Assert::AreEqual("Color [WhiteSmoke]", Drawing::Color::WhiteSmoke().ToString(), sw_current_information);
    }
    
    void Yellow() {
      Assert::AreEqual(0xFFFFFF00u, (unsigned)Drawing::Color::Yellow().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Yellow().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Yellow().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::Yellow().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::Yellow().IsSystemColor(), sw_current_information);
      Assert::AreEqual("Yellow", Drawing::Color::Yellow().Name(), sw_current_information);
      Assert::AreEqual("Color [Yellow]", Drawing::Color::Yellow().ToString(), sw_current_information);
    }
    
    void YellowGreen() {
      Assert::AreEqual(0xFF9ACD32u, (unsigned)Drawing::Color::YellowGreen().ToArgb(), sw_current_information);
      Assert::IsFalse(Drawing::Color::YellowGreen().IsEmpty(), sw_current_information);
      Assert::IsTrue(Drawing::Color::YellowGreen().IsKnownColor(), sw_current_information);
      Assert::IsTrue(Drawing::Color::YellowGreen().IsNamedColor(), sw_current_information);
      Assert::IsFalse(Drawing::Color::YellowGreen().IsSystemColor(), sw_current_information);
      Assert::AreEqual("YellowGreen", Drawing::Color::YellowGreen().Name(), sw_current_information);
      Assert::AreEqual("Color [YellowGreen]", Drawing::Color::YellowGreen().ToString(), sw_current_information);
    }
  };
  
  sw_test(Color, Ctor)
  sw_test(Color, FromKnownColor)
  sw_test(Color, FromArgb)
  sw_test(Color, FromName)
  sw_test(Color, Transparent)
  sw_test(Color, AliceBlue)
  sw_test(Color, AntiqueWhite)
  sw_test(Color, Aqua)
  sw_test(Color, Aquamarine)
  sw_test(Color, Azure)
  sw_test(Color, Beige)
  sw_test(Color, Bisque)
  sw_test(Color, Black)
  sw_test(Color, BlanchedAlmond)
  sw_test(Color, Blue)
  sw_test(Color, BlueViolet)
  sw_test(Color, Brown)
  sw_test(Color, BurlyWood)
  sw_test(Color, CadetBlue)
  sw_test(Color, Chartreuse)
  sw_test(Color, Chocolate)
  sw_test(Color, Coral)
  sw_test(Color, CornflowerBlue)
  sw_test(Color, Cornsilk)
  sw_test(Color, Crimson)
  sw_test(Color, Cyan)
  sw_test(Color, DarkBlue)
  sw_test(Color, DarkCyan)
  sw_test(Color, DarkGoldenrod)
  sw_test(Color, DarkGray)
  sw_test(Color, DarkGreen)
  sw_test(Color, DarkKhaki)
  sw_test(Color, DarkMagenta)
  sw_test(Color, DarkOliveGreen)
  sw_test(Color, DarkOrange)
  sw_test(Color, DarkOrchid)
  sw_test(Color, DarkRed)
  sw_test(Color, DarkSalmon)
  sw_test(Color, DarkSeaGreen)
  sw_test(Color, DarkSlateBlue)
  sw_test(Color, DarkSlateGray)
  sw_test(Color, DarkTurquoise)
  sw_test(Color, DarkViolet)
  sw_test(Color, DeepPink)
  sw_test(Color, DeepSkyBlue)
  sw_test(Color, DimGray)
  sw_test(Color, DodgerBlue)
  sw_test(Color, Firebrick)
  sw_test(Color, FloralWhite)
  sw_test(Color, ForestGreen)
  sw_test(Color, Fuchsia)
  sw_test(Color, Gainsboro)
  sw_test(Color, GhostWhite)
  sw_test(Color, Gold)
  sw_test(Color, Goldenrod)
  sw_test(Color, Gray)
  sw_test(Color, Green)
  sw_test(Color, GreenYellow)
  sw_test(Color, Honeydew)
  sw_test(Color, HotPink)
  sw_test(Color, IndianRed)
  sw_test(Color, Indigo)
  sw_test(Color, Ivory)
  sw_test(Color, Khaki)
  sw_test(Color, Lavender)
  sw_test(Color, LavenderBlush)
  sw_test(Color, LawnGreen)
  sw_test(Color, LemonChiffon)
  sw_test(Color, LightBlue)
  sw_test(Color, LightCoral)
  sw_test(Color, LightCyan)
  sw_test(Color, LightGoldenrodYellow)
  sw_test(Color, LightGray)
  sw_test(Color, LightGreen)
  sw_test(Color, LightPink)
  sw_test(Color, LightSalmon)
  sw_test(Color, LightSeaGreen)
  sw_test(Color, LightSkyBlue)
  sw_test(Color, LightSlateGray)
  sw_test(Color, LightSteelBlue)
  sw_test(Color, LightYellow)
  sw_test(Color, Lime)
  sw_test(Color, LimeGreen)
  sw_test(Color, Linen)
  sw_test(Color, Magenta)
  sw_test(Color, Maroon)
  sw_test(Color, MediumAquamarine)
  sw_test(Color, MediumBlue)
  sw_test(Color, MediumOrchid)
  sw_test(Color, MediumPurple)
  sw_test(Color, MediumSeaGreen)
  sw_test(Color, MediumSlateBlue)
  sw_test(Color, MediumSpringGreen)
  sw_test(Color, MediumTurquoise)
  sw_test(Color, MediumVioletRed)
  sw_test(Color, MidnightBlue)
  sw_test(Color, MintCream)
  sw_test(Color, MistyRose)
  sw_test(Color, Moccasin)
  sw_test(Color, NavajoWhite)
  sw_test(Color, Navy)
  sw_test(Color, OldLace)
  sw_test(Color, Olive)
  sw_test(Color, OliveDrab)
  sw_test(Color, Orange)
  sw_test(Color, OrangeRed)
  sw_test(Color, Orchid)
  sw_test(Color, PaleGoldenrod)
  sw_test(Color, PaleGreen)
  sw_test(Color, PaleTurquoise)
  sw_test(Color, PaleVioletRed)
  sw_test(Color, PapayaWhip)
  sw_test(Color, PeachPuff)
  sw_test(Color, Peru)
  sw_test(Color, Pink)
  sw_test(Color, Plum)
  sw_test(Color, PowderBlue)
  sw_test(Color, Purple)
  sw_test(Color, Red)
  sw_test(Color, RosyBrown)
  sw_test(Color, RoyalBlue)
  sw_test(Color, SaddleBrown)
  sw_test(Color, Salmon)
  sw_test(Color, SandyBrown)
  sw_test(Color, SeaGreen)
  sw_test(Color, SeaShell)
  sw_test(Color, Sienna)
  sw_test(Color, Silver)
  sw_test(Color, SkyBlue)
  sw_test(Color, SlateBlue)
  sw_test(Color, SlateGray)
  sw_test(Color, Snow)
  sw_test(Color, SpringGreen)
  sw_test(Color, SteelBlue)
  sw_test(Color, Tan)
  sw_test(Color, Teal)
  sw_test(Color, Thistle)
  sw_test(Color, Tomato)
  sw_test(Color, Turquoise)
  sw_test(Color, Violet)
  sw_test(Color, Wheat)
  sw_test(Color, White)
  sw_test(Color, WhiteSmoke)
  sw_test(Color, Yellow)
  sw_test(Color, YellowGreen)
}
