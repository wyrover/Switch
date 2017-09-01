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
      Assert::AreEqual(0x00, color.A(), _current_information);
      Assert::AreEqual(0x00, color.R(), _current_information);
      Assert::AreEqual(0x00, color.G(), _current_information);
      Assert::AreEqual(0x00, color.B(), _current_information);
      Assert::IsTrue(color.IsEmpty(), _current_information);
      Assert::IsFalse(color.IsKnownColor(), _current_information);
      Assert::IsFalse(color.IsNamedColor, _current_information);
      Assert::IsFalse(color.IsSystemColor(), _current_information);
      Assert::AreEqual("0", color.Name(), _current_information);
      Assert::AreEqual("Color [Empty]", color.ToString(), _current_information);
    }
    
    void FromKnownColor() {
      Assert::AreEqual(0xFF, Drawing::Color::FromKnownColor(KnownColor::Black).A(), _current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).R(), _current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).G(), _current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).B(), _current_information);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsSystemColor(), _current_information);
      Assert::AreEqual("Black", Drawing::Color::FromKnownColor(KnownColor::Black).Name(), _current_information);
      Assert::AreEqual("Color [Black]", Drawing::Color::FromKnownColor(KnownColor::Black).ToString(), _current_information);
      
      Assert::Throws<ArgumentException>(_delegate {Drawing::Color::FromKnownColor((KnownColor)34544);}, _current_information);
    }
    
    void FromArgb() {
      Assert::AreEqual(0x12, Drawing::Color::FromArgb(0x12345678).A(), _current_information);
      Assert::AreEqual(0x34, Drawing::Color::FromArgb(0x12345678).R(), _current_information);
      Assert::AreEqual(0x56, Drawing::Color::FromArgb(0x12345678).G(), _current_information);
      Assert::AreEqual(0x78, Drawing::Color::FromArgb(0x12345678).B(), _current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsEmpty(), _current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsKnownColor(), _current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsSystemColor(), _current_information);
      Assert::AreEqual("12345678", Drawing::Color::FromArgb(0x12345678).Name(), _current_information);
      Assert::AreEqual("Color [A=18, R=52, G=86, B=120]", Drawing::Color::FromArgb(0x12345678).ToString(), _current_information);
    }
    
    void FromName() {
      Drawing::Color colorAliceBlue = Drawing::Color::FromName("AliceBlue");
      Assert::AreEqual(0xFF, colorAliceBlue.A(), _current_information);
      Assert::AreEqual(0xF0, colorAliceBlue.R(), _current_information);
      Assert::AreEqual(0xF8, colorAliceBlue.G(), _current_information);
      Assert::AreEqual(0xFF, colorAliceBlue.B(), _current_information);
      Assert::IsFalse(colorAliceBlue.IsEmpty(), _current_information);
      Assert::IsTrue(colorAliceBlue.IsKnownColor(), _current_information);
      Assert::IsTrue(colorAliceBlue.IsNamedColor(), _current_information);
      Assert::IsFalse(colorAliceBlue.IsSystemColor(), _current_information);
      Assert::AreEqual("AliceBlue", colorAliceBlue.Name(), _current_information);
      Assert::AreEqual("Color [AliceBlue]", colorAliceBlue.ToString(), _current_information);
    }
    
    void Transparent() {
      Assert::AreEqual(0x00FFFFFF, Drawing::Color::Transparent().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Transparent().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Transparent().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Transparent().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Transparent().IsSystemColor(), _current_information);
      Assert::AreEqual("Transparent", Drawing::Color::Transparent().Name(), _current_information);
      Assert::AreEqual("Color [Transparent]", Drawing::Color::Transparent().ToString(), _current_information);
    }
    
    void AliceBlue() {
      Assert::AreEqual(0xFFF0F8FFu, (unsigned)Drawing::Color::AliceBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::AliceBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::AliceBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::AliceBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::AliceBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("AliceBlue", Drawing::Color::AliceBlue().Name(), _current_information);
      Assert::AreEqual("Color [AliceBlue]", Drawing::Color::AliceBlue().ToString(), _current_information);
    }
    
    void AntiqueWhite() {
      Assert::AreEqual(0xFFFAEBD7u, (unsigned)Drawing::Color::AntiqueWhite().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::AntiqueWhite().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::AntiqueWhite().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::AntiqueWhite().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::AntiqueWhite().IsSystemColor(), _current_information);
      Assert::AreEqual("AntiqueWhite", Drawing::Color::AntiqueWhite().Name(), _current_information);
      Assert::AreEqual("Color [AntiqueWhite]", Drawing::Color::AntiqueWhite().ToString(), _current_information);
    }
    
    void Aqua() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Aqua().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Aqua().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Aqua().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Aqua().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Aqua().IsSystemColor(), _current_information);
      Assert::AreEqual("Aqua", Drawing::Color::Aqua().Name(), _current_information);
      Assert::AreEqual("Color [Aqua]", Drawing::Color::Aqua().ToString(), _current_information);
    }
    
    void Aquamarine() {
      Assert::AreEqual(0xFF7FFFD4u, (unsigned)Drawing::Color::Aquamarine().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Aquamarine().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Aquamarine().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Aquamarine().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Aquamarine().IsSystemColor(), _current_information);
      Assert::AreEqual("Aquamarine", Drawing::Color::Aquamarine().Name(), _current_information);
      Assert::AreEqual("Color [Aquamarine]", Drawing::Color::Aquamarine().ToString(), _current_information);
    }
    
    void Azure() {
      Assert::AreEqual(0xFFF0FFFFu, (unsigned)Drawing::Color::Azure().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Azure().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Azure().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Azure().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Azure().IsSystemColor(), _current_information);
      Assert::AreEqual("Azure", Drawing::Color::Azure().Name(), _current_information);
      Assert::AreEqual("Color [Azure]", Drawing::Color::Azure().ToString(), _current_information);
    }
    
    void Beige() {
      Assert::AreEqual(0xFFF5F5DCu, (unsigned)Drawing::Color::Beige().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Beige().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Beige().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Beige().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Beige().IsSystemColor(), _current_information);
      Assert::AreEqual("Beige", Drawing::Color::Beige().Name(), _current_information);
      Assert::AreEqual("Color [Beige]", Drawing::Color::Beige().ToString(), _current_information);
    }
    
    void Bisque() {
      Assert::AreEqual(0xFFFFE4C4u, (unsigned)Drawing::Color::Bisque().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Bisque().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Bisque().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Bisque().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Bisque().IsSystemColor(), _current_information);
      Assert::AreEqual("Bisque", Drawing::Color::Bisque().Name(), _current_information);
      Assert::AreEqual("Color [Bisque]", Drawing::Color::Bisque().ToString(), _current_information);
    }
    
    void Black() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::Color::Black().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Black().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Black().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Black().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Black().IsSystemColor(), _current_information);
      Assert::AreEqual("Black", Drawing::Color::Black().Name(), _current_information);
      Assert::AreEqual("Color [Black]", Drawing::Color::Black().ToString(), _current_information);
    }
    
    void BlanchedAlmond() {
      Assert::AreEqual(0xFFFFEBCDu, (unsigned)Drawing::Color::BlanchedAlmond().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond().IsSystemColor(), _current_information);
      Assert::AreEqual("BlanchedAlmond", Drawing::Color::BlanchedAlmond().Name(), _current_information);
      Assert::AreEqual("Color [BlanchedAlmond]", Drawing::Color::BlanchedAlmond().ToString(), _current_information);
    }
    
    void Blue() {
      Assert::AreEqual(0xFF0000FFu, (unsigned)Drawing::Color::Blue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Blue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Blue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Blue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Blue().IsSystemColor(), _current_information);
      Assert::AreEqual("Blue", Drawing::Color::Blue().Name(), _current_information);
      Assert::AreEqual("Color [Blue]", Drawing::Color::Blue().ToString(), _current_information);
    }
    
    void BlueViolet() {
      Assert::AreEqual(0xFF8A2BE2u, (unsigned)Drawing::Color::BlueViolet().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::BlueViolet().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::BlueViolet().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::BlueViolet().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::BlueViolet().IsSystemColor(), _current_information);
      Assert::AreEqual("BlueViolet", Drawing::Color::BlueViolet().Name(), _current_information);
      Assert::AreEqual("Color [BlueViolet]", Drawing::Color::BlueViolet().ToString(), _current_information);
    }
    
    void Brown() {
      Assert::AreEqual(0xFFA52A2Au, (unsigned)Drawing::Color::Brown().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Brown().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Brown().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Brown().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Brown().IsSystemColor(), _current_information);
      Assert::AreEqual("Brown", Drawing::Color::Brown().Name(), _current_information);
      Assert::AreEqual("Color [Brown]", Drawing::Color::Brown().ToString(), _current_information);
    }
    
    void BurlyWood() {
      Assert::AreEqual(0xFFDEB887u, (unsigned)Drawing::Color::BurlyWood().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::BurlyWood().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::BurlyWood().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::BurlyWood().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::BurlyWood().IsSystemColor(), _current_information);
      Assert::AreEqual("BurlyWood", Drawing::Color::BurlyWood().Name(), _current_information);
      Assert::AreEqual("Color [BurlyWood]", Drawing::Color::BurlyWood().ToString(), _current_information);
    }
    
    void CadetBlue() {
      Assert::AreEqual(0xFF5F9EA0u, (unsigned)Drawing::Color::CadetBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::CadetBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::CadetBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::CadetBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::CadetBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("CadetBlue", Drawing::Color::CadetBlue().Name(), _current_information);
      Assert::AreEqual("Color [CadetBlue]", Drawing::Color::CadetBlue().ToString(), _current_information);
    }
    
    void Chartreuse() {
      Assert::AreEqual(0xFF7FFF00u, (unsigned)Drawing::Color::Chartreuse().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Chartreuse().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Chartreuse().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Chartreuse().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Chartreuse().IsSystemColor(), _current_information);
      Assert::AreEqual("Chartreuse", Drawing::Color::Chartreuse().Name(), _current_information);
      Assert::AreEqual("Color [Chartreuse]", Drawing::Color::Chartreuse().ToString(), _current_information);
    }
    
    void Chocolate() {
      Assert::AreEqual(0xFFD2691Eu, (unsigned)Drawing::Color::Chocolate().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Chocolate().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Chocolate().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Chocolate().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Chocolate().IsSystemColor(), _current_information);
      Assert::AreEqual("Chocolate", Drawing::Color::Chocolate().Name(), _current_information);
      Assert::AreEqual("Color [Chocolate]", Drawing::Color::Chocolate().ToString(), _current_information);
    }
    
    void Coral() {
      Assert::AreEqual(0xFFFF7F50u, (unsigned)Drawing::Color::Coral().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Coral().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Coral().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Coral().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Coral().IsSystemColor(), _current_information);
      Assert::AreEqual("Coral", Drawing::Color::Coral().Name(), _current_information);
      Assert::AreEqual("Color [Coral]", Drawing::Color::Coral().ToString(), _current_information);
    }
    
    void CornflowerBlue() {
      Assert::AreEqual(0xFF6495EDu, (unsigned)Drawing::Color::CornflowerBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::CornflowerBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::CornflowerBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::CornflowerBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::CornflowerBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("CornflowerBlue", Drawing::Color::CornflowerBlue().Name(), _current_information);
      Assert::AreEqual("Color [CornflowerBlue]", Drawing::Color::CornflowerBlue().ToString(), _current_information);
    }
    
    void Cornsilk() {
      Assert::AreEqual(0xFFFFF8DCu, (unsigned)Drawing::Color::Cornsilk().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Cornsilk().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Cornsilk().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Cornsilk().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Cornsilk().IsSystemColor(), _current_information);
      Assert::AreEqual("Cornsilk", Drawing::Color::Cornsilk().Name(), _current_information);
      Assert::AreEqual("Color [Cornsilk]", Drawing::Color::Cornsilk().ToString(), _current_information);
    }
    
    void Crimson() {
      Assert::AreEqual(0xFFDC143Cu, (unsigned)Drawing::Color::Crimson().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Crimson().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Crimson().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Crimson().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Crimson().IsSystemColor(), _current_information);
      Assert::AreEqual("Crimson", Drawing::Color::Crimson().Name(), _current_information);
      Assert::AreEqual("Color [Crimson]", Drawing::Color::Crimson().ToString(), _current_information);
    }
    
    void Cyan() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Cyan().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Cyan().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Cyan().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Cyan().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Cyan().IsSystemColor(), _current_information);
      Assert::AreEqual("Cyan", Drawing::Color::Cyan().Name(), _current_information);
      Assert::AreEqual("Color [Cyan]", Drawing::Color::Cyan().ToString(), _current_information);
    }
    
    void DarkBlue() {
      Assert::AreEqual(0xFF00008Bu, (unsigned)Drawing::Color::DarkBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkBlue", Drawing::Color::DarkBlue().Name(), _current_information);
      Assert::AreEqual("Color [DarkBlue]", Drawing::Color::DarkBlue().ToString(), _current_information);
    }
    
    void DarkCyan() {
      Assert::AreEqual(0xFF008B8Bu, (unsigned)Drawing::Color::DarkCyan().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkCyan().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkCyan().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkCyan().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkCyan().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkCyan", Drawing::Color::DarkCyan().Name(), _current_information);
      Assert::AreEqual("Color [DarkCyan]", Drawing::Color::DarkCyan().ToString(), _current_information);
    }
    
    void DarkGoldenrod() {
      Assert::AreEqual(0xFFB8860Bu, (unsigned)Drawing::Color::DarkGoldenrod().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkGoldenrod", Drawing::Color::DarkGoldenrod().Name(), _current_information);
      Assert::AreEqual("Color [DarkGoldenrod]", Drawing::Color::DarkGoldenrod().ToString(), _current_information);
    }
    
    void DarkGray() {
      Assert::AreEqual(0xFFA9A9A9u, (unsigned)Drawing::Color::DarkGray().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkGray().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkGray().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkGray().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkGray().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkGray", Drawing::Color::DarkGray().Name(), _current_information);
      Assert::AreEqual("Color [DarkGray]", Drawing::Color::DarkGray().ToString(), _current_information);
    }
    
    void DarkGreen() {
      Assert::AreEqual(0xFF006400u, (unsigned)Drawing::Color::DarkGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkGreen", Drawing::Color::DarkGreen().Name(), _current_information);
      Assert::AreEqual("Color [DarkGreen]", Drawing::Color::DarkGreen().ToString(), _current_information);
    }
    
    void DarkKhaki() {
      Assert::AreEqual(0xFFBDB76Bu, (unsigned)Drawing::Color::DarkKhaki().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkKhaki().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkKhaki().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkKhaki().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkKhaki().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkKhaki", Drawing::Color::DarkKhaki().Name(), _current_information);
      Assert::AreEqual("Color [DarkKhaki]", Drawing::Color::DarkKhaki().ToString(), _current_information);
    }
    
    void DarkMagenta() {
      Assert::AreEqual(0xFF8B008Bu, (unsigned)Drawing::Color::DarkMagenta().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkMagenta().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkMagenta().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkMagenta().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkMagenta().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkMagenta", Drawing::Color::DarkMagenta().Name(), _current_information);
      Assert::AreEqual("Color [DarkMagenta]", Drawing::Color::DarkMagenta().ToString(), _current_information);
    }
    
    void DarkOliveGreen() {
      Assert::AreEqual(0xFF556B2Fu, (unsigned)Drawing::Color::DarkOliveGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkOliveGreen", Drawing::Color::DarkOliveGreen().Name(), _current_information);
      Assert::AreEqual("Color [DarkOliveGreen]", Drawing::Color::DarkOliveGreen().ToString(), _current_information);
    }
    
    void DarkOrange() {
      Assert::AreEqual(0xFFFF8C00u, (unsigned)Drawing::Color::DarkOrange().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkOrange().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkOrange().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkOrange().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkOrange().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkOrange", Drawing::Color::DarkOrange().Name(), _current_information);
      Assert::AreEqual("Color [DarkOrange]", Drawing::Color::DarkOrange().ToString(), _current_information);
    }
    
    void DarkOrchid() {
      Assert::AreEqual(0xFF9932CCu, (unsigned)Drawing::Color::DarkOrchid().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkOrchid().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkOrchid().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkOrchid().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkOrchid().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkOrchid", Drawing::Color::DarkOrchid().Name(), _current_information);
      Assert::AreEqual("Color [DarkOrchid]", Drawing::Color::DarkOrchid().ToString(), _current_information);
    }
    
    void DarkRed() {
      Assert::AreEqual(0xFF8B0000u, (unsigned)Drawing::Color::DarkRed().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkRed().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkRed().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkRed().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkRed().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkRed", Drawing::Color::DarkRed().Name(), _current_information);
      Assert::AreEqual("Color [DarkRed]", Drawing::Color::DarkRed().ToString(), _current_information);
    }
    
    void DarkSalmon() {
      Assert::AreEqual(0xFFE9967Au, (unsigned)Drawing::Color::DarkSalmon().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSalmon().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSalmon().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSalmon().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSalmon().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkSalmon", Drawing::Color::DarkSalmon().Name(), _current_information);
      Assert::AreEqual("Color [DarkSalmon]", Drawing::Color::DarkSalmon().ToString(), _current_information);
    }
    
    void DarkSeaGreen() {
      Assert::AreEqual(0xFF8FBC8Bu, (unsigned)Drawing::Color::DarkSeaGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkSeaGreen", Drawing::Color::DarkSeaGreen().Name(), _current_information);
      Assert::AreEqual("Color [DarkSeaGreen]", Drawing::Color::DarkSeaGreen().ToString(), _current_information);
    }
    
    void DarkSlateBlue() {
      Assert::AreEqual(0xFF483D8Bu, (unsigned)Drawing::Color::DarkSlateBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkSlateBlue", Drawing::Color::DarkSlateBlue().Name(), _current_information);
      Assert::AreEqual("Color [DarkSlateBlue]", Drawing::Color::DarkSlateBlue().ToString(), _current_information);
    }
    
    void DarkSlateGray() {
      Assert::AreEqual(0xFF2F4F4Fu, (unsigned)Drawing::Color::DarkSlateGray().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateGray().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateGray().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateGray().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateGray().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkSlateGray", Drawing::Color::DarkSlateGray().Name(), _current_information);
      Assert::AreEqual("Color [DarkSlateGray]", Drawing::Color::DarkSlateGray().ToString(), _current_information);
    }
    
    void DarkTurquoise() {
      Assert::AreEqual(0xFF00CED1u, (unsigned)Drawing::Color::DarkTurquoise().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkTurquoise().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkTurquoise().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkTurquoise().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkTurquoise().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkTurquoise", Drawing::Color::DarkTurquoise().Name(), _current_information);
      Assert::AreEqual("Color [DarkTurquoise]", Drawing::Color::DarkTurquoise().ToString(), _current_information);
    }
    
    void DarkViolet() {
      Assert::AreEqual(0xFF9400D3u, (unsigned)Drawing::Color::DarkViolet().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkViolet().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkViolet().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DarkViolet().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DarkViolet().IsSystemColor(), _current_information);
      Assert::AreEqual("DarkViolet", Drawing::Color::DarkViolet().Name(), _current_information);
      Assert::AreEqual("Color [DarkViolet]", Drawing::Color::DarkViolet().ToString(), _current_information);
    }
    
    void DeepPink() {
      Assert::AreEqual(0xFFFF1493u, (unsigned)Drawing::Color::DeepPink().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DeepPink().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DeepPink().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DeepPink().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DeepPink().IsSystemColor(), _current_information);
      Assert::AreEqual("DeepPink", Drawing::Color::DeepPink().Name(), _current_information);
      Assert::AreEqual("Color [DeepPink]", Drawing::Color::DeepPink().ToString(), _current_information);
    }
    
    void DeepSkyBlue() {
      Assert::AreEqual(0xFF00BFFFu, (unsigned)Drawing::Color::DeepSkyBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("DeepSkyBlue", Drawing::Color::DeepSkyBlue().Name(), _current_information);
      Assert::AreEqual("Color [DeepSkyBlue]", Drawing::Color::DeepSkyBlue().ToString(), _current_information);
    }
    
    void DimGray() {
      Assert::AreEqual(0xFF696969u, (unsigned)Drawing::Color::DimGray().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DimGray().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DimGray().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DimGray().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DimGray().IsSystemColor(), _current_information);
      Assert::AreEqual("DimGray", Drawing::Color::DimGray().Name(), _current_information);
      Assert::AreEqual("Color [DimGray]", Drawing::Color::DimGray().ToString(), _current_information);
    }
    
    void DodgerBlue() {
      Assert::AreEqual(0xFF1E90FFu, (unsigned)Drawing::Color::DodgerBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::DodgerBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::DodgerBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::DodgerBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::DodgerBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("DodgerBlue", Drawing::Color::DodgerBlue().Name(), _current_information);
      Assert::AreEqual("Color [DodgerBlue]", Drawing::Color::DodgerBlue().ToString(), _current_information);
    }
    
    void Firebrick() {
      Assert::AreEqual(0xFFB22222u, (unsigned)Drawing::Color::Firebrick().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Firebrick().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Firebrick().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Firebrick().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Firebrick().IsSystemColor(), _current_information);
      Assert::AreEqual("Firebrick", Drawing::Color::Firebrick().Name(), _current_information);
      Assert::AreEqual("Color [Firebrick]", Drawing::Color::Firebrick().ToString(), _current_information);
    }
    
    void FloralWhite() {
      Assert::AreEqual(0xFFFFFAF0u, (unsigned)Drawing::Color::FloralWhite().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::FloralWhite().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::FloralWhite().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::FloralWhite().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::FloralWhite().IsSystemColor(), _current_information);
      Assert::AreEqual("FloralWhite", Drawing::Color::FloralWhite().Name(), _current_information);
      Assert::AreEqual("Color [FloralWhite]", Drawing::Color::FloralWhite().ToString(), _current_information);
    }
    
    void ForestGreen() {
      Assert::AreEqual(0xFF228B22u, (unsigned)Drawing::Color::ForestGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::ForestGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::ForestGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::ForestGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::ForestGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("ForestGreen", Drawing::Color::ForestGreen().Name(), _current_information);
      Assert::AreEqual("Color [ForestGreen]", Drawing::Color::ForestGreen().ToString(), _current_information);
    }
    
    void Fuchsia() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Fuchsia().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Fuchsia().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Fuchsia().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Fuchsia().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Fuchsia().IsSystemColor(), _current_information);
      Assert::AreEqual("Fuchsia", Drawing::Color::Fuchsia().Name(), _current_information);
      Assert::AreEqual("Color [Fuchsia]", Drawing::Color::Fuchsia().ToString(), _current_information);
    }
    
    void Gainsboro() {
      Assert::AreEqual(0xFFDCDCDCu, (unsigned)Drawing::Color::Gainsboro().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Gainsboro().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Gainsboro().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Gainsboro().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Gainsboro().IsSystemColor(), _current_information);
      Assert::AreEqual("Gainsboro", Drawing::Color::Gainsboro().Name(), _current_information);
      Assert::AreEqual("Color [Gainsboro]", Drawing::Color::Gainsboro().ToString(), _current_information);
    }
    
    void GhostWhite() {
      Assert::AreEqual(0xFFF8F8FFu, (unsigned)Drawing::Color::GhostWhite().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::GhostWhite().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::GhostWhite().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::GhostWhite().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::GhostWhite().IsSystemColor(), _current_information);
      Assert::AreEqual("GhostWhite", Drawing::Color::GhostWhite().Name(), _current_information);
      Assert::AreEqual("Color [GhostWhite]", Drawing::Color::GhostWhite().ToString(), _current_information);
    }
    
    void Gold() {
      Assert::AreEqual(0xFFFFD700u, (unsigned)Drawing::Color::Gold().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Gold().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Gold().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Gold().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Gold().IsSystemColor(), _current_information);
      Assert::AreEqual("Gold", Drawing::Color::Gold().Name(), _current_information);
      Assert::AreEqual("Color [Gold]", Drawing::Color::Gold().ToString(), _current_information);
    }
    
    void Goldenrod() {
      Assert::AreEqual(0xFFDAA520u, (unsigned)Drawing::Color::Goldenrod().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Goldenrod().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Goldenrod().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Goldenrod().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Goldenrod().IsSystemColor(), _current_information);
      Assert::AreEqual("Goldenrod", Drawing::Color::Goldenrod().Name(), _current_information);
      Assert::AreEqual("Color [Goldenrod]", Drawing::Color::Goldenrod().ToString(), _current_information);
    }
    
    void Gray() {
      Assert::AreEqual(0xFF808080u, (unsigned)Drawing::Color::Gray().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Gray().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Gray().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Gray().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Gray().IsSystemColor(), _current_information);
      Assert::AreEqual("Gray", Drawing::Color::Gray().Name(), _current_information);
      Assert::AreEqual("Color [Gray]", Drawing::Color::Gray().ToString(), _current_information);
    }
    
    void Green() {
      Assert::AreEqual(0xFF008000u, (unsigned)Drawing::Color::Green().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Green().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Green().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Green().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Green().IsSystemColor(), _current_information);
      Assert::AreEqual("Green", Drawing::Color::Green().Name(), _current_information);
      Assert::AreEqual("Color [Green]", Drawing::Color::Green().ToString(), _current_information);
    }
    
    void GreenYellow() {
      Assert::AreEqual(0xFFADFF2Fu, (unsigned)Drawing::Color::GreenYellow().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::GreenYellow().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::GreenYellow().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::GreenYellow().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::GreenYellow().IsSystemColor(), _current_information);
      Assert::AreEqual("GreenYellow", Drawing::Color::GreenYellow().Name(), _current_information);
      Assert::AreEqual("Color [GreenYellow]", Drawing::Color::GreenYellow().ToString(), _current_information);
    }
    
    void Honeydew() {
      Assert::AreEqual(0xFFF0FFF0u, (unsigned)Drawing::Color::Honeydew().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Honeydew().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Honeydew().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Honeydew().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Honeydew().IsSystemColor(), _current_information);
      Assert::AreEqual("Honeydew", Drawing::Color::Honeydew().Name(), _current_information);
      Assert::AreEqual("Color [Honeydew]", Drawing::Color::Honeydew().ToString(), _current_information);
    }
    
    void HotPink() {
      Assert::AreEqual(0xFFFF69B4u, (unsigned)Drawing::Color::HotPink().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::HotPink().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::HotPink().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::HotPink().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::HotPink().IsSystemColor(), _current_information);
      Assert::AreEqual("HotPink", Drawing::Color::HotPink().Name(), _current_information);
      Assert::AreEqual("Color [HotPink]", Drawing::Color::HotPink().ToString(), _current_information);
    }
    
    void IndianRed() {
      Assert::AreEqual(0xFFCD5C5Cu, (unsigned)Drawing::Color::IndianRed().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::IndianRed().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::IndianRed().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::IndianRed().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::IndianRed().IsSystemColor(), _current_information);
      Assert::AreEqual("IndianRed", Drawing::Color::IndianRed().Name(), _current_information);
      Assert::AreEqual("Color [IndianRed]", Drawing::Color::IndianRed().ToString(), _current_information);
    }
    
    void Indigo() {
      Assert::AreEqual(0xFF4B0082u, (unsigned)Drawing::Color::Indigo().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Indigo().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Indigo().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Indigo().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Indigo().IsSystemColor(), _current_information);
      Assert::AreEqual("Indigo", Drawing::Color::Indigo().Name(), _current_information);
      Assert::AreEqual("Color [Indigo]", Drawing::Color::Indigo().ToString(), _current_information);
    }
    
    void Ivory() {
      Assert::AreEqual(0xFFFFFFF0u, (unsigned)Drawing::Color::Ivory().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Ivory().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Ivory().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Ivory().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Ivory().IsSystemColor(), _current_information);
      Assert::AreEqual("Ivory", Drawing::Color::Ivory().Name(), _current_information);
      Assert::AreEqual("Color [Ivory]", Drawing::Color::Ivory().ToString(), _current_information);
    }
    
    void Khaki() {
      Assert::AreEqual(0xFFF0E68Cu, (unsigned)Drawing::Color::Khaki().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Khaki().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Khaki().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Khaki().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Khaki().IsSystemColor(), _current_information);
      Assert::AreEqual("Khaki", Drawing::Color::Khaki().Name(), _current_information);
      Assert::AreEqual("Color [Khaki]", Drawing::Color::Khaki().ToString(), _current_information);
    }
    
    void Lavender() {
      Assert::AreEqual(0xFFE6E6FAu, (unsigned)Drawing::Color::Lavender().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Lavender().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Lavender().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Lavender().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Lavender().IsSystemColor(), _current_information);
      Assert::AreEqual("Lavender", Drawing::Color::Lavender().Name(), _current_information);
      Assert::AreEqual("Color [Lavender]", Drawing::Color::Lavender().ToString(), _current_information);
    }
    
    void LavenderBlush() {
      Assert::AreEqual(0xFFFFF0F5u, (unsigned)Drawing::Color::LavenderBlush().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LavenderBlush().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LavenderBlush().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LavenderBlush().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LavenderBlush().IsSystemColor(), _current_information);
      Assert::AreEqual("LavenderBlush", Drawing::Color::LavenderBlush().Name(), _current_information);
      Assert::AreEqual("Color [LavenderBlush]", Drawing::Color::LavenderBlush().ToString(), _current_information);
    }
    
    void LawnGreen() {
      Assert::AreEqual(0xFF7CFC00u, (unsigned)Drawing::Color::LawnGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LawnGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LawnGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LawnGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LawnGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("LawnGreen", Drawing::Color::LawnGreen().Name(), _current_information);
      Assert::AreEqual("Color [LawnGreen]", Drawing::Color::LawnGreen().ToString(), _current_information);
    }
    
    void LemonChiffon() {
      Assert::AreEqual(0xFFFFFACDu, (unsigned)Drawing::Color::LemonChiffon().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LemonChiffon().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LemonChiffon().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LemonChiffon().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LemonChiffon().IsSystemColor(), _current_information);
      Assert::AreEqual("LemonChiffon", Drawing::Color::LemonChiffon().Name(), _current_information);
      Assert::AreEqual("Color [LemonChiffon]", Drawing::Color::LemonChiffon().ToString(), _current_information);
    }
    
    void LightBlue() {
      Assert::AreEqual(0xFFADD8E6u, (unsigned)Drawing::Color::LightBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("LightBlue", Drawing::Color::LightBlue().Name(), _current_information);
      Assert::AreEqual("Color [LightBlue]", Drawing::Color::LightBlue().ToString(), _current_information);
    }
    
    void LightCoral() {
      Assert::AreEqual(0xFFF08080u, (unsigned)Drawing::Color::LightCoral().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightCoral().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightCoral().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightCoral().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightCoral().IsSystemColor(), _current_information);
      Assert::AreEqual("LightCoral", Drawing::Color::LightCoral().Name(), _current_information);
      Assert::AreEqual("Color [LightCoral]", Drawing::Color::LightCoral().ToString(), _current_information);
    }
    
    void LightCyan() {
      Assert::AreEqual(0xFFE0FFFFu, (unsigned)Drawing::Color::LightCyan().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightCyan().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightCyan().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightCyan().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightCyan().IsSystemColor(), _current_information);
      Assert::AreEqual("LightCyan", Drawing::Color::LightCyan().Name(), _current_information);
      Assert::AreEqual("Color [LightCyan]", Drawing::Color::LightCyan().ToString(), _current_information);
    }
    
    void LightGoldenrodYellow() {
      Assert::AreEqual(0xFFFAFAD2u, (unsigned)Drawing::Color::LightGoldenrodYellow().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow().IsSystemColor(), _current_information);
      Assert::AreEqual("LightGoldenrodYellow", Drawing::Color::LightGoldenrodYellow().Name(), _current_information);
      Assert::AreEqual("Color [LightGoldenrodYellow]", Drawing::Color::LightGoldenrodYellow().ToString(), _current_information);
    }
    
    void LightGray() {
      Assert::AreEqual(0xFFD3D3D3u, (unsigned)Drawing::Color::LightGray().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightGray().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightGray().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightGray().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightGray().IsSystemColor(), _current_information);
      Assert::AreEqual("LightGray", Drawing::Color::LightGray().Name(), _current_information);
      Assert::AreEqual("Color [LightGray]", Drawing::Color::LightGray().ToString(), _current_information);
    }
    
    void LightGreen() {
      Assert::AreEqual(0xFF90EE90u, (unsigned)Drawing::Color::LightGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("LightGreen", Drawing::Color::LightGreen().Name(), _current_information);
      Assert::AreEqual("Color [LightGreen]", Drawing::Color::LightGreen().ToString(), _current_information);
    }
    
    void LightPink() {
      Assert::AreEqual(0xFFFFB6C1u, (unsigned)Drawing::Color::LightPink().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightPink().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightPink().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightPink().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightPink().IsSystemColor(), _current_information);
      Assert::AreEqual("LightPink", Drawing::Color::LightPink().Name(), _current_information);
      Assert::AreEqual("Color [LightPink]", Drawing::Color::LightPink().ToString(), _current_information);
    }
    
    void LightSalmon() {
      Assert::AreEqual(0xFFFFA07Au, (unsigned)Drawing::Color::LightSalmon().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSalmon().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSalmon().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSalmon().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSalmon().IsSystemColor(), _current_information);
      Assert::AreEqual("LightSalmon", Drawing::Color::LightSalmon().Name(), _current_information);
      Assert::AreEqual("Color [LightSalmon]", Drawing::Color::LightSalmon().ToString(), _current_information);
    }
    
    void LightSeaGreen() {
      Assert::AreEqual(0xFF20B2AAu, (unsigned)Drawing::Color::LightSeaGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSeaGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSeaGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSeaGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSeaGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("LightSeaGreen", Drawing::Color::LightSeaGreen().Name(), _current_information);
      Assert::AreEqual("Color [LightSeaGreen]", Drawing::Color::LightSeaGreen().ToString(), _current_information);
    }
    
    void LightSkyBlue() {
      Assert::AreEqual(0xFF87CEFAu, (unsigned)Drawing::Color::LightSkyBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSkyBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSkyBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSkyBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSkyBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("LightSkyBlue", Drawing::Color::LightSkyBlue().Name(), _current_information);
      Assert::AreEqual("Color [LightSkyBlue]", Drawing::Color::LightSkyBlue().ToString(), _current_information);
    }
    
    void LightSlateGray() {
      Assert::AreEqual(0xFF778899u, (unsigned)Drawing::Color::LightSlateGray().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSlateGray().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSlateGray().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSlateGray().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSlateGray().IsSystemColor(), _current_information);
      Assert::AreEqual("LightSlateGray", Drawing::Color::LightSlateGray().Name(), _current_information);
      Assert::AreEqual("Color [LightSlateGray]", Drawing::Color::LightSlateGray().ToString(), _current_information);
    }
    
    void LightSteelBlue() {
      Assert::AreEqual(0xFFB0C4DEu, (unsigned)Drawing::Color::LightSteelBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSteelBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSteelBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightSteelBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightSteelBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("LightSteelBlue", Drawing::Color::LightSteelBlue().Name(), _current_information);
      Assert::AreEqual("Color [LightSteelBlue]", Drawing::Color::LightSteelBlue().ToString(), _current_information);
    }
    
    void LightYellow() {
      Assert::AreEqual(0xFFFFFFE0u, (unsigned)Drawing::Color::LightYellow().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LightYellow().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LightYellow().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LightYellow().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LightYellow().IsSystemColor(), _current_information);
      Assert::AreEqual("LightYellow", Drawing::Color::LightYellow().Name(), _current_information);
      Assert::AreEqual("Color [LightYellow]", Drawing::Color::LightYellow().ToString(), _current_information);
    }
    
    void Lime() {
      Assert::AreEqual(0xFF00FF00u, (unsigned)Drawing::Color::Lime().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Lime().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Lime().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Lime().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Lime().IsSystemColor(), _current_information);
      Assert::AreEqual("Lime", Drawing::Color::Lime().Name(), _current_information);
      Assert::AreEqual("Color [Lime]", Drawing::Color::Lime().ToString(), _current_information);
    }
    
    void LimeGreen() {
      Assert::AreEqual(0xFF32CD32u, (unsigned)Drawing::Color::LimeGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::LimeGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::LimeGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::LimeGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::LimeGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("LimeGreen", Drawing::Color::LimeGreen().Name(), _current_information);
      Assert::AreEqual("Color [LimeGreen]", Drawing::Color::LimeGreen().ToString(), _current_information);
    }
    
    void Linen() {
      Assert::AreEqual(0xFFFAF0E6u, (unsigned)Drawing::Color::Linen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Linen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Linen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Linen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Linen().IsSystemColor(), _current_information);
      Assert::AreEqual("Linen", Drawing::Color::Linen().Name(), _current_information);
      Assert::AreEqual("Color [Linen]", Drawing::Color::Linen().ToString(), _current_information);
    }
    
    void Magenta() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Magenta().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Magenta().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Magenta().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Magenta().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Magenta().IsSystemColor(), _current_information);
      Assert::AreEqual("Magenta", Drawing::Color::Magenta().Name(), _current_information);
      Assert::AreEqual("Color [Magenta]", Drawing::Color::Magenta().ToString(), _current_information);
    }
    
    void Maroon() {
      Assert::AreEqual(0xFF800000u, (unsigned)Drawing::Color::Maroon().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Maroon().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Maroon().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Maroon().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Maroon().IsSystemColor(), _current_information);
      Assert::AreEqual("Maroon", Drawing::Color::Maroon().Name(), _current_information);
      Assert::AreEqual("Color [Maroon]", Drawing::Color::Maroon().ToString(), _current_information);
    }
    
    void MediumAquamarine() {
      Assert::AreEqual(0xFF66CDAAu, (unsigned)Drawing::Color::MediumAquamarine().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumAquamarine().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumAquamarine().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumAquamarine().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumAquamarine().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumAquamarine", Drawing::Color::MediumAquamarine().Name(), _current_information);
      Assert::AreEqual("Color [MediumAquamarine]", Drawing::Color::MediumAquamarine().ToString(), _current_information);
    }
    
    void MediumBlue() {
      Assert::AreEqual(0xFF0000CDu, (unsigned)Drawing::Color::MediumBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumBlue", Drawing::Color::MediumBlue().Name(), _current_information);
      Assert::AreEqual("Color [MediumBlue]", Drawing::Color::MediumBlue().ToString(), _current_information);
    }
    
    void MediumOrchid() {
      Assert::AreEqual(0xFFBA55D3u, (unsigned)Drawing::Color::MediumOrchid().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumOrchid().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumOrchid().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumOrchid().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumOrchid().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumOrchid", Drawing::Color::MediumOrchid().Name(), _current_information);
      Assert::AreEqual("Color [MediumOrchid]", Drawing::Color::MediumOrchid().ToString(), _current_information);
    }
    
    void MediumPurple() {
      Assert::AreEqual(0xFF9370DBu, (unsigned)Drawing::Color::MediumPurple().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumPurple().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumPurple().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumPurple().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumPurple().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumPurple", Drawing::Color::MediumPurple().Name(), _current_information);
      Assert::AreEqual("Color [MediumPurple]", Drawing::Color::MediumPurple().ToString(), _current_information);
    }
    
    void MediumSeaGreen() {
      Assert::AreEqual(0xFF3CB371u, (unsigned)Drawing::Color::MediumSeaGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumSeaGreen", Drawing::Color::MediumSeaGreen().Name(), _current_information);
      Assert::AreEqual("Color [MediumSeaGreen]", Drawing::Color::MediumSeaGreen().ToString(), _current_information);
    }
    
    void MediumSlateBlue() {
      Assert::AreEqual(0xFF7B68EEu, (unsigned)Drawing::Color::MediumSlateBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumSlateBlue", Drawing::Color::MediumSlateBlue().Name(), _current_information);
      Assert::AreEqual("Color [MediumSlateBlue]", Drawing::Color::MediumSlateBlue().ToString(), _current_information);
    }
    
    void MediumSpringGreen() {
      Assert::AreEqual(0xFF00FA9Au, (unsigned)Drawing::Color::MediumSpringGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumSpringGreen", Drawing::Color::MediumSpringGreen().Name(), _current_information);
      Assert::AreEqual("Color [MediumSpringGreen]", Drawing::Color::MediumSpringGreen().ToString(), _current_information);
    }
    
    void MediumTurquoise() {
      Assert::AreEqual(0xFF48D1CCu, (unsigned)Drawing::Color::MediumTurquoise().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumTurquoise().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumTurquoise().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumTurquoise().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumTurquoise().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumTurquoise", Drawing::Color::MediumTurquoise().Name(), _current_information);
      Assert::AreEqual("Color [MediumTurquoise]", Drawing::Color::MediumTurquoise().ToString(), _current_information);
    }
    
    void MediumVioletRed() {
      Assert::AreEqual(0xFFC71585u, (unsigned)Drawing::Color::MediumVioletRed().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumVioletRed().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumVioletRed().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MediumVioletRed().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MediumVioletRed().IsSystemColor(), _current_information);
      Assert::AreEqual("MediumVioletRed", Drawing::Color::MediumVioletRed().Name(), _current_information);
      Assert::AreEqual("Color [MediumVioletRed]", Drawing::Color::MediumVioletRed().ToString(), _current_information);
    }
    
    void MidnightBlue() {
      Assert::AreEqual(0xFF191970u, (unsigned)Drawing::Color::MidnightBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MidnightBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MidnightBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MidnightBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MidnightBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("MidnightBlue", Drawing::Color::MidnightBlue().Name(), _current_information);
      Assert::AreEqual("Color [MidnightBlue]", Drawing::Color::MidnightBlue().ToString(), _current_information);
    }
    
    void MintCream() {
      Assert::AreEqual(0xFFF5FFFAu, (unsigned)Drawing::Color::MintCream().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MintCream().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MintCream().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MintCream().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MintCream().IsSystemColor(), _current_information);
      Assert::AreEqual("MintCream", Drawing::Color::MintCream().Name(), _current_information);
      Assert::AreEqual("Color [MintCream]", Drawing::Color::MintCream().ToString(), _current_information);
    }
    
    void MistyRose() {
      Assert::AreEqual(0xFFFFE4E1u, (unsigned)Drawing::Color::MistyRose().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::MistyRose().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::MistyRose().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::MistyRose().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::MistyRose().IsSystemColor(), _current_information);
      Assert::AreEqual("MistyRose", Drawing::Color::MistyRose().Name(), _current_information);
      Assert::AreEqual("Color [MistyRose]", Drawing::Color::MistyRose().ToString(), _current_information);
    }
    
    void Moccasin() {
      Assert::AreEqual(0xFFFFE4B5u, (unsigned)Drawing::Color::Moccasin().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Moccasin().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Moccasin().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Moccasin().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Moccasin().IsSystemColor(), _current_information);
      Assert::AreEqual("Moccasin", Drawing::Color::Moccasin().Name(), _current_information);
      Assert::AreEqual("Color [Moccasin]", Drawing::Color::Moccasin().ToString(), _current_information);
    }
    
    void NavajoWhite() {
      Assert::AreEqual(0xFFFFDEADu, (unsigned)Drawing::Color::NavajoWhite().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::NavajoWhite().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::NavajoWhite().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::NavajoWhite().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::NavajoWhite().IsSystemColor(), _current_information);
      Assert::AreEqual("NavajoWhite", Drawing::Color::NavajoWhite().Name(), _current_information);
      Assert::AreEqual("Color [NavajoWhite]", Drawing::Color::NavajoWhite().ToString(), _current_information);
    }
    
    void Navy() {
      Assert::AreEqual(0xFF000080u, (unsigned)Drawing::Color::Navy().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Navy().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Navy().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Navy().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Navy().IsSystemColor(), _current_information);
      Assert::AreEqual("Navy", Drawing::Color::Navy().Name(), _current_information);
      Assert::AreEqual("Color [Navy]", Drawing::Color::Navy().ToString(), _current_information);
    }
    
    void OldLace() {
      Assert::AreEqual(0xFFFDF5E6u, (unsigned)Drawing::Color::OldLace().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::OldLace().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::OldLace().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::OldLace().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::OldLace().IsSystemColor(), _current_information);
      Assert::AreEqual("OldLace", Drawing::Color::OldLace().Name(), _current_information);
      Assert::AreEqual("Color [OldLace]", Drawing::Color::OldLace().ToString(), _current_information);
    }
    
    void Olive() {
      Assert::AreEqual(0xFF808000u, (unsigned)Drawing::Color::Olive().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Olive().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Olive().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Olive().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Olive().IsSystemColor(), _current_information);
      Assert::AreEqual("Olive", Drawing::Color::Olive().Name(), _current_information);
      Assert::AreEqual("Color [Olive]", Drawing::Color::Olive().ToString(), _current_information);
    }
    
    void OliveDrab() {
      Assert::AreEqual(0xFF6B8E23u, (unsigned)Drawing::Color::OliveDrab().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::OliveDrab().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::OliveDrab().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::OliveDrab().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::OliveDrab().IsSystemColor(), _current_information);
      Assert::AreEqual("OliveDrab", Drawing::Color::OliveDrab().Name(), _current_information);
      Assert::AreEqual("Color [OliveDrab]", Drawing::Color::OliveDrab().ToString(), _current_information);
    }
    
    void Orange() {
      Assert::AreEqual(0xFFFFA500u, (unsigned)Drawing::Color::Orange().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Orange().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Orange().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Orange().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Orange().IsSystemColor(), _current_information);
      Assert::AreEqual("Orange", Drawing::Color::Orange().Name(), _current_information);
      Assert::AreEqual("Color [Orange]", Drawing::Color::Orange().ToString(), _current_information);
    }
    
    void OrangeRed() {
      Assert::AreEqual(0xFFFF4500u, (unsigned)Drawing::Color::OrangeRed().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::OrangeRed().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::OrangeRed().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::OrangeRed().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::OrangeRed().IsSystemColor(), _current_information);
      Assert::AreEqual("OrangeRed", Drawing::Color::OrangeRed().Name(), _current_information);
      Assert::AreEqual("Color [OrangeRed]", Drawing::Color::OrangeRed().ToString(), _current_information);
    }
    
    void Orchid() {
      Assert::AreEqual(0xFFDA70D6u, (unsigned)Drawing::Color::Orchid().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Orchid().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Orchid().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Orchid().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Orchid().IsSystemColor(), _current_information);
      Assert::AreEqual("Orchid", Drawing::Color::Orchid().Name(), _current_information);
      Assert::AreEqual("Color [Orchid]", Drawing::Color::Orchid().ToString(), _current_information);
    }
    
    void PaleGoldenrod() {
      Assert::AreEqual(0xFFEEE8AAu, (unsigned)Drawing::Color::PaleGoldenrod().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod().IsSystemColor(), _current_information);
      Assert::AreEqual("PaleGoldenrod", Drawing::Color::PaleGoldenrod().Name(), _current_information);
      Assert::AreEqual("Color [PaleGoldenrod]", Drawing::Color::PaleGoldenrod().ToString(), _current_information);
    }
    
    void PaleGreen() {
      Assert::AreEqual(0xFF98FB98u, (unsigned)Drawing::Color::PaleGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("PaleGreen", Drawing::Color::PaleGreen().Name(), _current_information);
      Assert::AreEqual("Color [PaleGreen]", Drawing::Color::PaleGreen().ToString(), _current_information);
    }
    
    void PaleTurquoise() {
      Assert::AreEqual(0xFFAFEEEEu, (unsigned)Drawing::Color::PaleTurquoise().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleTurquoise().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleTurquoise().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleTurquoise().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleTurquoise().IsSystemColor(), _current_information);
      Assert::AreEqual("PaleTurquoise", Drawing::Color::PaleTurquoise().Name(), _current_information);
      Assert::AreEqual("Color [PaleTurquoise]", Drawing::Color::PaleTurquoise().ToString(), _current_information);
    }
    
    void PaleVioletRed() {
      Assert::AreEqual(0xFFDB7093u, (unsigned)Drawing::Color::PaleVioletRed().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleVioletRed().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleVioletRed().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::PaleVioletRed().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::PaleVioletRed().IsSystemColor(), _current_information);
      Assert::AreEqual("PaleVioletRed", Drawing::Color::PaleVioletRed().Name(), _current_information);
      Assert::AreEqual("Color [PaleVioletRed]", Drawing::Color::PaleVioletRed().ToString(), _current_information);
    }
    
    void PapayaWhip() {
      Assert::AreEqual(0xFFFFEFD5u, (unsigned)Drawing::Color::PapayaWhip().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::PapayaWhip().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::PapayaWhip().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::PapayaWhip().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::PapayaWhip().IsSystemColor(), _current_information);
      Assert::AreEqual("PapayaWhip", Drawing::Color::PapayaWhip().Name(), _current_information);
      Assert::AreEqual("Color [PapayaWhip]", Drawing::Color::PapayaWhip().ToString(), _current_information);
    }
    
    void PeachPuff() {
      Assert::AreEqual(0xFFFFDAB9u, (unsigned)Drawing::Color::PeachPuff().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::PeachPuff().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::PeachPuff().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::PeachPuff().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::PeachPuff().IsSystemColor(), _current_information);
      Assert::AreEqual("PeachPuff", Drawing::Color::PeachPuff().Name(), _current_information);
      Assert::AreEqual("Color [PeachPuff]", Drawing::Color::PeachPuff().ToString(), _current_information);
    }
    
    void Peru() {
      Assert::AreEqual(0xFFCD853Fu, (unsigned)Drawing::Color::Peru().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Peru().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Peru().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Peru().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Peru().IsSystemColor(), _current_information);
      Assert::AreEqual("Peru", Drawing::Color::Peru().Name(), _current_information);
      Assert::AreEqual("Color [Peru]", Drawing::Color::Peru().ToString(), _current_information);
    }
    
    void Pink() {
      Assert::AreEqual(0xFFFFC0CBu, (unsigned)Drawing::Color::Pink().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Pink().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Pink().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Pink().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Pink().IsSystemColor(), _current_information);
      Assert::AreEqual("Pink", Drawing::Color::Pink().Name(), _current_information);
      Assert::AreEqual("Color [Pink]", Drawing::Color::Pink().ToString(), _current_information);
    }
    
    void Plum() {
      Assert::AreEqual(0xFFDDA0DDu, (unsigned)Drawing::Color::Plum().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Plum().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Plum().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Plum().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Plum().IsSystemColor(), _current_information);
      Assert::AreEqual("Plum", Drawing::Color::Plum().Name(), _current_information);
      Assert::AreEqual("Color [Plum]", Drawing::Color::Plum().ToString(), _current_information);
    }
    
    void PowderBlue() {
      Assert::AreEqual(0xFFB0E0E6u, (unsigned)Drawing::Color::PowderBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::PowderBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::PowderBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::PowderBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::PowderBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("PowderBlue", Drawing::Color::PowderBlue().Name(), _current_information);
      Assert::AreEqual("Color [PowderBlue]", Drawing::Color::PowderBlue().ToString(), _current_information);
    }
    
    void Purple() {
      Assert::AreEqual(0xFF800080u, (unsigned)Drawing::Color::Purple().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Purple().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Purple().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Purple().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Purple().IsSystemColor(), _current_information);
      Assert::AreEqual("Purple", Drawing::Color::Purple().Name(), _current_information);
      Assert::AreEqual("Color [Purple]", Drawing::Color::Purple().ToString(), _current_information);
    }
    
    void Red() {
      Assert::AreEqual(0xFFFF0000u, (unsigned)Drawing::Color::Red().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Red().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Red().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Red().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Red().IsSystemColor(), _current_information);
      Assert::AreEqual("Red", Drawing::Color::Red().Name(), _current_information);
      Assert::AreEqual("Color [Red]", Drawing::Color::Red().ToString(), _current_information);
    }
    
    void RosyBrown() {
      Assert::AreEqual(0xFFBC8F8Fu, (unsigned)Drawing::Color::RosyBrown().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::RosyBrown().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::RosyBrown().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::RosyBrown().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::RosyBrown().IsSystemColor(), _current_information);
      Assert::AreEqual("RosyBrown", Drawing::Color::RosyBrown().Name(), _current_information);
      Assert::AreEqual("Color [RosyBrown]", Drawing::Color::RosyBrown().ToString(), _current_information);
    }
    
    void RoyalBlue() {
      Assert::AreEqual(0xFF4169E1u, (unsigned)Drawing::Color::RoyalBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::RoyalBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::RoyalBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::RoyalBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::RoyalBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("RoyalBlue", Drawing::Color::RoyalBlue().Name(), _current_information);
      Assert::AreEqual("Color [RoyalBlue]", Drawing::Color::RoyalBlue().ToString(), _current_information);
    }
    
    void SaddleBrown() {
      Assert::AreEqual(0xFF8B4513u, (unsigned)Drawing::Color::SaddleBrown().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SaddleBrown().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SaddleBrown().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SaddleBrown().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SaddleBrown().IsSystemColor(), _current_information);
      Assert::AreEqual("SaddleBrown", Drawing::Color::SaddleBrown().Name(), _current_information);
      Assert::AreEqual("Color [SaddleBrown]", Drawing::Color::SaddleBrown().ToString(), _current_information);
    }
    
    void Salmon() {
      Assert::AreEqual(0xFFFA8072u, (unsigned)Drawing::Color::Salmon().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Salmon().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Salmon().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Salmon().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Salmon().IsSystemColor(), _current_information);
      Assert::AreEqual("Salmon", Drawing::Color::Salmon().Name(), _current_information);
      Assert::AreEqual("Color [Salmon]", Drawing::Color::Salmon().ToString(), _current_information);
    }
    
    void SandyBrown() {
      Assert::AreEqual(0xFFF4A460u, (unsigned)Drawing::Color::SandyBrown().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SandyBrown().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SandyBrown().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SandyBrown().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SandyBrown().IsSystemColor(), _current_information);
      Assert::AreEqual("SandyBrown", Drawing::Color::SandyBrown().Name(), _current_information);
      Assert::AreEqual("Color [SandyBrown]", Drawing::Color::SandyBrown().ToString(), _current_information);
    }
    
    void SeaGreen() {
      Assert::AreEqual(0xFF2E8B57u, (unsigned)Drawing::Color::SeaGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SeaGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SeaGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SeaGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SeaGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("SeaGreen", Drawing::Color::SeaGreen().Name(), _current_information);
      Assert::AreEqual("Color [SeaGreen]", Drawing::Color::SeaGreen().ToString(), _current_information);
    }
    
    void SeaShell() {
      Assert::AreEqual(0xFFFFF5EEu, (unsigned)Drawing::Color::SeaShell().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SeaShell().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SeaShell().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SeaShell().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SeaShell().IsSystemColor(), _current_information);
      Assert::AreEqual("SeaShell", Drawing::Color::SeaShell().Name(), _current_information);
      Assert::AreEqual("Color [SeaShell]", Drawing::Color::SeaShell().ToString(), _current_information);
    }
    
    void Sienna() {
      Assert::AreEqual(0xFFA0522Du, (unsigned)Drawing::Color::Sienna().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Sienna().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Sienna().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Sienna().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Sienna().IsSystemColor(), _current_information);
      Assert::AreEqual("Sienna", Drawing::Color::Sienna().Name(), _current_information);
      Assert::AreEqual("Color [Sienna]", Drawing::Color::Sienna().ToString(), _current_information);
    }
    
    void Silver() {
      Assert::AreEqual(0xFFC0C0C0u, (unsigned)Drawing::Color::Silver().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Silver().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Silver().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Silver().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Silver().IsSystemColor(), _current_information);
      Assert::AreEqual("Silver", Drawing::Color::Silver().Name(), _current_information);
      Assert::AreEqual("Color [Silver]", Drawing::Color::Silver().ToString(), _current_information);
    }
    
    void SkyBlue() {
      Assert::AreEqual(0xFF87CEEBu, (unsigned)Drawing::Color::SkyBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SkyBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SkyBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SkyBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SkyBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("SkyBlue", Drawing::Color::SkyBlue().Name(), _current_information);
      Assert::AreEqual("Color [SkyBlue]", Drawing::Color::SkyBlue().ToString(), _current_information);
    }
    
    void SlateBlue() {
      Assert::AreEqual(0xFF6A5ACDu, (unsigned)Drawing::Color::SlateBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SlateBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SlateBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SlateBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SlateBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("SlateBlue", Drawing::Color::SlateBlue().Name(), _current_information);
      Assert::AreEqual("Color [SlateBlue]", Drawing::Color::SlateBlue().ToString(), _current_information);
    }
    
    void SlateGray() {
      Assert::AreEqual(0xFF708090u, (unsigned)Drawing::Color::SlateGray().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SlateGray().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SlateGray().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SlateGray().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SlateGray().IsSystemColor(), _current_information);
      Assert::AreEqual("SlateGray", Drawing::Color::SlateGray().Name(), _current_information);
      Assert::AreEqual("Color [SlateGray]", Drawing::Color::SlateGray().ToString(), _current_information);
    }
    
    void Snow() {
      Assert::AreEqual(0xFFFFFAFAu, (unsigned)Drawing::Color::Snow().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Snow().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Snow().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Snow().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Snow().IsSystemColor(), _current_information);
      Assert::AreEqual("Snow", Drawing::Color::Snow().Name(), _current_information);
      Assert::AreEqual("Color [Snow]", Drawing::Color::Snow().ToString(), _current_information);
    }
    
    void SpringGreen() {
      Assert::AreEqual(0xFF00FF7Fu, (unsigned)Drawing::Color::SpringGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SpringGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SpringGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SpringGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SpringGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("SpringGreen", Drawing::Color::SpringGreen().Name(), _current_information);
      Assert::AreEqual("Color [SpringGreen]", Drawing::Color::SpringGreen().ToString(), _current_information);
    }
    
    void SteelBlue() {
      Assert::AreEqual(0xFF4682B4u, (unsigned)Drawing::Color::SteelBlue().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::SteelBlue().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::SteelBlue().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::SteelBlue().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::SteelBlue().IsSystemColor(), _current_information);
      Assert::AreEqual("SteelBlue", Drawing::Color::SteelBlue().Name(), _current_information);
      Assert::AreEqual("Color [SteelBlue]", Drawing::Color::SteelBlue().ToString(), _current_information);
    }
    
    void Tan() {
      Assert::AreEqual(0xFFD2B48Cu, (unsigned)Drawing::Color::Tan().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Tan().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Tan().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Tan().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Tan().IsSystemColor(), _current_information);
      Assert::AreEqual("Tan", Drawing::Color::Tan().Name(), _current_information);
      Assert::AreEqual("Color [Tan]", Drawing::Color::Tan().ToString(), _current_information);
    }
    
    void Teal() {
      Assert::AreEqual(0xFF008080u, (unsigned)Drawing::Color::Teal().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Teal().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Teal().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Teal().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Teal().IsSystemColor(), _current_information);
      Assert::AreEqual("Teal", Drawing::Color::Teal().Name(), _current_information);
      Assert::AreEqual("Color [Teal]", Drawing::Color::Teal().ToString(), _current_information);
    }
    
    void Thistle() {
      Assert::AreEqual(0xFFD8BFD8u, (unsigned)Drawing::Color::Thistle().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Thistle().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Thistle().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Thistle().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Thistle().IsSystemColor(), _current_information);
      Assert::AreEqual("Thistle", Drawing::Color::Thistle().Name(), _current_information);
      Assert::AreEqual("Color [Thistle]", Drawing::Color::Thistle().ToString(), _current_information);
    }
    
    void Tomato() {
      Assert::AreEqual(0xFFFF6347u, (unsigned)Drawing::Color::Tomato().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Tomato().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Tomato().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Tomato().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Tomato().IsSystemColor(), _current_information);
      Assert::AreEqual("Tomato", Drawing::Color::Tomato().Name(), _current_information);
      Assert::AreEqual("Color [Tomato]", Drawing::Color::Tomato().ToString(), _current_information);
    }
    
    void Turquoise() {
      Assert::AreEqual(0xFF40E0D0u, (unsigned)Drawing::Color::Turquoise().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Turquoise().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Turquoise().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Turquoise().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Turquoise().IsSystemColor(), _current_information);
      Assert::AreEqual("Turquoise", Drawing::Color::Turquoise().Name(), _current_information);
      Assert::AreEqual("Color [Turquoise]", Drawing::Color::Turquoise().ToString(), _current_information);
    }
    
    void Violet() {
      Assert::AreEqual(0xFFEE82EEu, (unsigned)Drawing::Color::Violet().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Violet().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Violet().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Violet().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Violet().IsSystemColor(), _current_information);
      Assert::AreEqual("Violet", Drawing::Color::Violet().Name(), _current_information);
      Assert::AreEqual("Color [Violet]", Drawing::Color::Violet().ToString(), _current_information);
    }
    
    void Wheat() {
      Assert::AreEqual(0xFFF5DEB3u, (unsigned)Drawing::Color::Wheat().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Wheat().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Wheat().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Wheat().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Wheat().IsSystemColor(), _current_information);
      Assert::AreEqual("Wheat", Drawing::Color::Wheat().Name(), _current_information);
      Assert::AreEqual("Color [Wheat]", Drawing::Color::Wheat().ToString(), _current_information);
    }
    
    void White() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::Color::White().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::White().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::White().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::White().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::White().IsSystemColor(), _current_information);
      Assert::AreEqual("White", Drawing::Color::White().Name(), _current_information);
      Assert::AreEqual("Color [White]", Drawing::Color::White().ToString(), _current_information);
    }
    
    void WhiteSmoke() {
      Assert::AreEqual(0xFFF5F5F5u, (unsigned)Drawing::Color::WhiteSmoke().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::WhiteSmoke().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::WhiteSmoke().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::WhiteSmoke().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::WhiteSmoke().IsSystemColor(), _current_information);
      Assert::AreEqual("WhiteSmoke", Drawing::Color::WhiteSmoke().Name(), _current_information);
      Assert::AreEqual("Color [WhiteSmoke]", Drawing::Color::WhiteSmoke().ToString(), _current_information);
    }
    
    void Yellow() {
      Assert::AreEqual(0xFFFFFF00u, (unsigned)Drawing::Color::Yellow().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::Yellow().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::Yellow().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::Yellow().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::Yellow().IsSystemColor(), _current_information);
      Assert::AreEqual("Yellow", Drawing::Color::Yellow().Name(), _current_information);
      Assert::AreEqual("Color [Yellow]", Drawing::Color::Yellow().ToString(), _current_information);
    }
    
    void YellowGreen() {
      Assert::AreEqual(0xFF9ACD32u, (unsigned)Drawing::Color::YellowGreen().ToArgb(), _current_information);
      Assert::IsFalse(Drawing::Color::YellowGreen().IsEmpty(), _current_information);
      Assert::IsTrue(Drawing::Color::YellowGreen().IsKnownColor(), _current_information);
      Assert::IsTrue(Drawing::Color::YellowGreen().IsNamedColor(), _current_information);
      Assert::IsFalse(Drawing::Color::YellowGreen().IsSystemColor(), _current_information);
      Assert::AreEqual("YellowGreen", Drawing::Color::YellowGreen().Name(), _current_information);
      Assert::AreEqual("Color [YellowGreen]", Drawing::Color::YellowGreen().ToString(), _current_information);
    }
  };
  
  _test(Color, Ctor)
  _test(Color, FromKnownColor)
  _test(Color, FromArgb)
  _test(Color, FromName)
  _test(Color, Transparent)
  _test(Color, AliceBlue)
  _test(Color, AntiqueWhite)
  _test(Color, Aqua)
  _test(Color, Aquamarine)
  _test(Color, Azure)
  _test(Color, Beige)
  _test(Color, Bisque)
  _test(Color, Black)
  _test(Color, BlanchedAlmond)
  _test(Color, Blue)
  _test(Color, BlueViolet)
  _test(Color, Brown)
  _test(Color, BurlyWood)
  _test(Color, CadetBlue)
  _test(Color, Chartreuse)
  _test(Color, Chocolate)
  _test(Color, Coral)
  _test(Color, CornflowerBlue)
  _test(Color, Cornsilk)
  _test(Color, Crimson)
  _test(Color, Cyan)
  _test(Color, DarkBlue)
  _test(Color, DarkCyan)
  _test(Color, DarkGoldenrod)
  _test(Color, DarkGray)
  _test(Color, DarkGreen)
  _test(Color, DarkKhaki)
  _test(Color, DarkMagenta)
  _test(Color, DarkOliveGreen)
  _test(Color, DarkOrange)
  _test(Color, DarkOrchid)
  _test(Color, DarkRed)
  _test(Color, DarkSalmon)
  _test(Color, DarkSeaGreen)
  _test(Color, DarkSlateBlue)
  _test(Color, DarkSlateGray)
  _test(Color, DarkTurquoise)
  _test(Color, DarkViolet)
  _test(Color, DeepPink)
  _test(Color, DeepSkyBlue)
  _test(Color, DimGray)
  _test(Color, DodgerBlue)
  _test(Color, Firebrick)
  _test(Color, FloralWhite)
  _test(Color, ForestGreen)
  _test(Color, Fuchsia)
  _test(Color, Gainsboro)
  _test(Color, GhostWhite)
  _test(Color, Gold)
  _test(Color, Goldenrod)
  _test(Color, Gray)
  _test(Color, Green)
  _test(Color, GreenYellow)
  _test(Color, Honeydew)
  _test(Color, HotPink)
  _test(Color, IndianRed)
  _test(Color, Indigo)
  _test(Color, Ivory)
  _test(Color, Khaki)
  _test(Color, Lavender)
  _test(Color, LavenderBlush)
  _test(Color, LawnGreen)
  _test(Color, LemonChiffon)
  _test(Color, LightBlue)
  _test(Color, LightCoral)
  _test(Color, LightCyan)
  _test(Color, LightGoldenrodYellow)
  _test(Color, LightGray)
  _test(Color, LightGreen)
  _test(Color, LightPink)
  _test(Color, LightSalmon)
  _test(Color, LightSeaGreen)
  _test(Color, LightSkyBlue)
  _test(Color, LightSlateGray)
  _test(Color, LightSteelBlue)
  _test(Color, LightYellow)
  _test(Color, Lime)
  _test(Color, LimeGreen)
  _test(Color, Linen)
  _test(Color, Magenta)
  _test(Color, Maroon)
  _test(Color, MediumAquamarine)
  _test(Color, MediumBlue)
  _test(Color, MediumOrchid)
  _test(Color, MediumPurple)
  _test(Color, MediumSeaGreen)
  _test(Color, MediumSlateBlue)
  _test(Color, MediumSpringGreen)
  _test(Color, MediumTurquoise)
  _test(Color, MediumVioletRed)
  _test(Color, MidnightBlue)
  _test(Color, MintCream)
  _test(Color, MistyRose)
  _test(Color, Moccasin)
  _test(Color, NavajoWhite)
  _test(Color, Navy)
  _test(Color, OldLace)
  _test(Color, Olive)
  _test(Color, OliveDrab)
  _test(Color, Orange)
  _test(Color, OrangeRed)
  _test(Color, Orchid)
  _test(Color, PaleGoldenrod)
  _test(Color, PaleGreen)
  _test(Color, PaleTurquoise)
  _test(Color, PaleVioletRed)
  _test(Color, PapayaWhip)
  _test(Color, PeachPuff)
  _test(Color, Peru)
  _test(Color, Pink)
  _test(Color, Plum)
  _test(Color, PowderBlue)
  _test(Color, Purple)
  _test(Color, Red)
  _test(Color, RosyBrown)
  _test(Color, RoyalBlue)
  _test(Color, SaddleBrown)
  _test(Color, Salmon)
  _test(Color, SandyBrown)
  _test(Color, SeaGreen)
  _test(Color, SeaShell)
  _test(Color, Sienna)
  _test(Color, Silver)
  _test(Color, SkyBlue)
  _test(Color, SlateBlue)
  _test(Color, SlateGray)
  _test(Color, Snow)
  _test(Color, SpringGreen)
  _test(Color, SteelBlue)
  _test(Color, Tan)
  _test(Color, Teal)
  _test(Color, Thistle)
  _test(Color, Tomato)
  _test(Color, Turquoise)
  _test(Color, Violet)
  _test(Color, Wheat)
  _test(Color, White)
  _test(Color, WhiteSmoke)
  _test(Color, Yellow)
  _test(Color, YellowGreen)
}
