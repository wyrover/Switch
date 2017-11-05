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
      Assert::AreEqual(0x00, color.A(), _caller);
      Assert::AreEqual(0x00, color.R(), _caller);
      Assert::AreEqual(0x00, color.G(), _caller);
      Assert::AreEqual(0x00, color.B(), _caller);
      Assert::IsTrue(color.IsEmpty(), _caller);
      Assert::IsFalse(color.IsKnownColor(), _caller);
      Assert::IsFalse(color.IsNamedColor, _caller);
      Assert::IsFalse(color.IsSystemColor(), _caller);
      Assert::AreEqual("0", color.Name(), _caller);
      Assert::AreEqual("Color [Empty]", color.ToString(), _caller);
    }
    
    void FromKnownColor() {
      Assert::AreEqual(0xFF, Drawing::Color::FromKnownColor(KnownColor::Black).A(), _caller);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).R(), _caller);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).G(), _caller);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).B(), _caller);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsSystemColor(), _caller);
      Assert::AreEqual("Black", Drawing::Color::FromKnownColor(KnownColor::Black).Name(), _caller);
      Assert::AreEqual("Color [Black]", Drawing::Color::FromKnownColor(KnownColor::Black).ToString(), _caller);
      
      Assert::Throws<ArgumentException>(_delegate {Drawing::Color::FromKnownColor((KnownColor)34544);}, _caller);
    }
    
    void FromArgb() {
      Assert::AreEqual(0x12, Drawing::Color::FromArgb(0x12345678).A(), _caller);
      Assert::AreEqual(0x34, Drawing::Color::FromArgb(0x12345678).R(), _caller);
      Assert::AreEqual(0x56, Drawing::Color::FromArgb(0x12345678).G(), _caller);
      Assert::AreEqual(0x78, Drawing::Color::FromArgb(0x12345678).B(), _caller);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsEmpty(), _caller);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsKnownColor(), _caller);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsSystemColor(), _caller);
      Assert::AreEqual("12345678", Drawing::Color::FromArgb(0x12345678).Name(), _caller);
      Assert::AreEqual("Color [A=18, R=52, G=86, B=120]", Drawing::Color::FromArgb(0x12345678).ToString(), _caller);
    }
    
    void FromName() {
      Drawing::Color colorAliceBlue = Drawing::Color::FromName("AliceBlue");
      Assert::AreEqual(0xFF, colorAliceBlue.A(), _caller);
      Assert::AreEqual(0xF0, colorAliceBlue.R(), _caller);
      Assert::AreEqual(0xF8, colorAliceBlue.G(), _caller);
      Assert::AreEqual(0xFF, colorAliceBlue.B(), _caller);
      Assert::IsFalse(colorAliceBlue.IsEmpty(), _caller);
      Assert::IsTrue(colorAliceBlue.IsKnownColor(), _caller);
      Assert::IsTrue(colorAliceBlue.IsNamedColor(), _caller);
      Assert::IsFalse(colorAliceBlue.IsSystemColor(), _caller);
      Assert::AreEqual("AliceBlue", colorAliceBlue.Name(), _caller);
      Assert::AreEqual("Color [AliceBlue]", colorAliceBlue.ToString(), _caller);
    }
    
    void Transparent() {
      Assert::AreEqual(0x00FFFFFF, Drawing::Color::Transparent().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Transparent().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Transparent().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Transparent().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Transparent().IsSystemColor(), _caller);
      Assert::AreEqual("Transparent", Drawing::Color::Transparent().Name(), _caller);
      Assert::AreEqual("Color [Transparent]", Drawing::Color::Transparent().ToString(), _caller);
    }
    
    void AliceBlue() {
      Assert::AreEqual(0xFFF0F8FFu, (unsigned)Drawing::Color::AliceBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::AliceBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::AliceBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::AliceBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::AliceBlue().IsSystemColor(), _caller);
      Assert::AreEqual("AliceBlue", Drawing::Color::AliceBlue().Name(), _caller);
      Assert::AreEqual("Color [AliceBlue]", Drawing::Color::AliceBlue().ToString(), _caller);
    }
    
    void AntiqueWhite() {
      Assert::AreEqual(0xFFFAEBD7u, (unsigned)Drawing::Color::AntiqueWhite().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::AntiqueWhite().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::AntiqueWhite().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::AntiqueWhite().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::AntiqueWhite().IsSystemColor(), _caller);
      Assert::AreEqual("AntiqueWhite", Drawing::Color::AntiqueWhite().Name(), _caller);
      Assert::AreEqual("Color [AntiqueWhite]", Drawing::Color::AntiqueWhite().ToString(), _caller);
    }
    
    void Aqua() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Aqua().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Aqua().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Aqua().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Aqua().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Aqua().IsSystemColor(), _caller);
      Assert::AreEqual("Aqua", Drawing::Color::Aqua().Name(), _caller);
      Assert::AreEqual("Color [Aqua]", Drawing::Color::Aqua().ToString(), _caller);
    }
    
    void Aquamarine() {
      Assert::AreEqual(0xFF7FFFD4u, (unsigned)Drawing::Color::Aquamarine().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Aquamarine().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Aquamarine().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Aquamarine().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Aquamarine().IsSystemColor(), _caller);
      Assert::AreEqual("Aquamarine", Drawing::Color::Aquamarine().Name(), _caller);
      Assert::AreEqual("Color [Aquamarine]", Drawing::Color::Aquamarine().ToString(), _caller);
    }
    
    void Azure() {
      Assert::AreEqual(0xFFF0FFFFu, (unsigned)Drawing::Color::Azure().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Azure().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Azure().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Azure().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Azure().IsSystemColor(), _caller);
      Assert::AreEqual("Azure", Drawing::Color::Azure().Name(), _caller);
      Assert::AreEqual("Color [Azure]", Drawing::Color::Azure().ToString(), _caller);
    }
    
    void Beige() {
      Assert::AreEqual(0xFFF5F5DCu, (unsigned)Drawing::Color::Beige().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Beige().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Beige().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Beige().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Beige().IsSystemColor(), _caller);
      Assert::AreEqual("Beige", Drawing::Color::Beige().Name(), _caller);
      Assert::AreEqual("Color [Beige]", Drawing::Color::Beige().ToString(), _caller);
    }
    
    void Bisque() {
      Assert::AreEqual(0xFFFFE4C4u, (unsigned)Drawing::Color::Bisque().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Bisque().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Bisque().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Bisque().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Bisque().IsSystemColor(), _caller);
      Assert::AreEqual("Bisque", Drawing::Color::Bisque().Name(), _caller);
      Assert::AreEqual("Color [Bisque]", Drawing::Color::Bisque().ToString(), _caller);
    }
    
    void Black() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::Color::Black().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Black().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Black().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Black().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Black().IsSystemColor(), _caller);
      Assert::AreEqual("Black", Drawing::Color::Black().Name(), _caller);
      Assert::AreEqual("Color [Black]", Drawing::Color::Black().ToString(), _caller);
    }
    
    void BlanchedAlmond() {
      Assert::AreEqual(0xFFFFEBCDu, (unsigned)Drawing::Color::BlanchedAlmond().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond().IsSystemColor(), _caller);
      Assert::AreEqual("BlanchedAlmond", Drawing::Color::BlanchedAlmond().Name(), _caller);
      Assert::AreEqual("Color [BlanchedAlmond]", Drawing::Color::BlanchedAlmond().ToString(), _caller);
    }
    
    void Blue() {
      Assert::AreEqual(0xFF0000FFu, (unsigned)Drawing::Color::Blue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Blue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Blue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Blue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Blue().IsSystemColor(), _caller);
      Assert::AreEqual("Blue", Drawing::Color::Blue().Name(), _caller);
      Assert::AreEqual("Color [Blue]", Drawing::Color::Blue().ToString(), _caller);
    }
    
    void BlueViolet() {
      Assert::AreEqual(0xFF8A2BE2u, (unsigned)Drawing::Color::BlueViolet().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::BlueViolet().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::BlueViolet().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::BlueViolet().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::BlueViolet().IsSystemColor(), _caller);
      Assert::AreEqual("BlueViolet", Drawing::Color::BlueViolet().Name(), _caller);
      Assert::AreEqual("Color [BlueViolet]", Drawing::Color::BlueViolet().ToString(), _caller);
    }
    
    void Brown() {
      Assert::AreEqual(0xFFA52A2Au, (unsigned)Drawing::Color::Brown().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Brown().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Brown().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Brown().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Brown().IsSystemColor(), _caller);
      Assert::AreEqual("Brown", Drawing::Color::Brown().Name(), _caller);
      Assert::AreEqual("Color [Brown]", Drawing::Color::Brown().ToString(), _caller);
    }
    
    void BurlyWood() {
      Assert::AreEqual(0xFFDEB887u, (unsigned)Drawing::Color::BurlyWood().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::BurlyWood().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::BurlyWood().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::BurlyWood().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::BurlyWood().IsSystemColor(), _caller);
      Assert::AreEqual("BurlyWood", Drawing::Color::BurlyWood().Name(), _caller);
      Assert::AreEqual("Color [BurlyWood]", Drawing::Color::BurlyWood().ToString(), _caller);
    }
    
    void CadetBlue() {
      Assert::AreEqual(0xFF5F9EA0u, (unsigned)Drawing::Color::CadetBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::CadetBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::CadetBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::CadetBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::CadetBlue().IsSystemColor(), _caller);
      Assert::AreEqual("CadetBlue", Drawing::Color::CadetBlue().Name(), _caller);
      Assert::AreEqual("Color [CadetBlue]", Drawing::Color::CadetBlue().ToString(), _caller);
    }
    
    void Chartreuse() {
      Assert::AreEqual(0xFF7FFF00u, (unsigned)Drawing::Color::Chartreuse().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Chartreuse().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Chartreuse().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Chartreuse().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Chartreuse().IsSystemColor(), _caller);
      Assert::AreEqual("Chartreuse", Drawing::Color::Chartreuse().Name(), _caller);
      Assert::AreEqual("Color [Chartreuse]", Drawing::Color::Chartreuse().ToString(), _caller);
    }
    
    void Chocolate() {
      Assert::AreEqual(0xFFD2691Eu, (unsigned)Drawing::Color::Chocolate().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Chocolate().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Chocolate().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Chocolate().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Chocolate().IsSystemColor(), _caller);
      Assert::AreEqual("Chocolate", Drawing::Color::Chocolate().Name(), _caller);
      Assert::AreEqual("Color [Chocolate]", Drawing::Color::Chocolate().ToString(), _caller);
    }
    
    void Coral() {
      Assert::AreEqual(0xFFFF7F50u, (unsigned)Drawing::Color::Coral().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Coral().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Coral().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Coral().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Coral().IsSystemColor(), _caller);
      Assert::AreEqual("Coral", Drawing::Color::Coral().Name(), _caller);
      Assert::AreEqual("Color [Coral]", Drawing::Color::Coral().ToString(), _caller);
    }
    
    void CornflowerBlue() {
      Assert::AreEqual(0xFF6495EDu, (unsigned)Drawing::Color::CornflowerBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::CornflowerBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::CornflowerBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::CornflowerBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::CornflowerBlue().IsSystemColor(), _caller);
      Assert::AreEqual("CornflowerBlue", Drawing::Color::CornflowerBlue().Name(), _caller);
      Assert::AreEqual("Color [CornflowerBlue]", Drawing::Color::CornflowerBlue().ToString(), _caller);
    }
    
    void Cornsilk() {
      Assert::AreEqual(0xFFFFF8DCu, (unsigned)Drawing::Color::Cornsilk().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Cornsilk().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Cornsilk().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Cornsilk().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Cornsilk().IsSystemColor(), _caller);
      Assert::AreEqual("Cornsilk", Drawing::Color::Cornsilk().Name(), _caller);
      Assert::AreEqual("Color [Cornsilk]", Drawing::Color::Cornsilk().ToString(), _caller);
    }
    
    void Crimson() {
      Assert::AreEqual(0xFFDC143Cu, (unsigned)Drawing::Color::Crimson().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Crimson().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Crimson().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Crimson().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Crimson().IsSystemColor(), _caller);
      Assert::AreEqual("Crimson", Drawing::Color::Crimson().Name(), _caller);
      Assert::AreEqual("Color [Crimson]", Drawing::Color::Crimson().ToString(), _caller);
    }
    
    void Cyan() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Cyan().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Cyan().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Cyan().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Cyan().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Cyan().IsSystemColor(), _caller);
      Assert::AreEqual("Cyan", Drawing::Color::Cyan().Name(), _caller);
      Assert::AreEqual("Color [Cyan]", Drawing::Color::Cyan().ToString(), _caller);
    }
    
    void DarkBlue() {
      Assert::AreEqual(0xFF00008Bu, (unsigned)Drawing::Color::DarkBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkBlue().IsSystemColor(), _caller);
      Assert::AreEqual("DarkBlue", Drawing::Color::DarkBlue().Name(), _caller);
      Assert::AreEqual("Color [DarkBlue]", Drawing::Color::DarkBlue().ToString(), _caller);
    }
    
    void DarkCyan() {
      Assert::AreEqual(0xFF008B8Bu, (unsigned)Drawing::Color::DarkCyan().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkCyan().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkCyan().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkCyan().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkCyan().IsSystemColor(), _caller);
      Assert::AreEqual("DarkCyan", Drawing::Color::DarkCyan().Name(), _caller);
      Assert::AreEqual("Color [DarkCyan]", Drawing::Color::DarkCyan().ToString(), _caller);
    }
    
    void DarkGoldenrod() {
      Assert::AreEqual(0xFFB8860Bu, (unsigned)Drawing::Color::DarkGoldenrod().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod().IsSystemColor(), _caller);
      Assert::AreEqual("DarkGoldenrod", Drawing::Color::DarkGoldenrod().Name(), _caller);
      Assert::AreEqual("Color [DarkGoldenrod]", Drawing::Color::DarkGoldenrod().ToString(), _caller);
    }
    
    void DarkGray() {
      Assert::AreEqual(0xFFA9A9A9u, (unsigned)Drawing::Color::DarkGray().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkGray().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkGray().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkGray().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkGray().IsSystemColor(), _caller);
      Assert::AreEqual("DarkGray", Drawing::Color::DarkGray().Name(), _caller);
      Assert::AreEqual("Color [DarkGray]", Drawing::Color::DarkGray().ToString(), _caller);
    }
    
    void DarkGreen() {
      Assert::AreEqual(0xFF006400u, (unsigned)Drawing::Color::DarkGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkGreen().IsSystemColor(), _caller);
      Assert::AreEqual("DarkGreen", Drawing::Color::DarkGreen().Name(), _caller);
      Assert::AreEqual("Color [DarkGreen]", Drawing::Color::DarkGreen().ToString(), _caller);
    }
    
    void DarkKhaki() {
      Assert::AreEqual(0xFFBDB76Bu, (unsigned)Drawing::Color::DarkKhaki().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkKhaki().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkKhaki().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkKhaki().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkKhaki().IsSystemColor(), _caller);
      Assert::AreEqual("DarkKhaki", Drawing::Color::DarkKhaki().Name(), _caller);
      Assert::AreEqual("Color [DarkKhaki]", Drawing::Color::DarkKhaki().ToString(), _caller);
    }
    
    void DarkMagenta() {
      Assert::AreEqual(0xFF8B008Bu, (unsigned)Drawing::Color::DarkMagenta().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkMagenta().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkMagenta().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkMagenta().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkMagenta().IsSystemColor(), _caller);
      Assert::AreEqual("DarkMagenta", Drawing::Color::DarkMagenta().Name(), _caller);
      Assert::AreEqual("Color [DarkMagenta]", Drawing::Color::DarkMagenta().ToString(), _caller);
    }
    
    void DarkOliveGreen() {
      Assert::AreEqual(0xFF556B2Fu, (unsigned)Drawing::Color::DarkOliveGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen().IsSystemColor(), _caller);
      Assert::AreEqual("DarkOliveGreen", Drawing::Color::DarkOliveGreen().Name(), _caller);
      Assert::AreEqual("Color [DarkOliveGreen]", Drawing::Color::DarkOliveGreen().ToString(), _caller);
    }
    
    void DarkOrange() {
      Assert::AreEqual(0xFFFF8C00u, (unsigned)Drawing::Color::DarkOrange().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkOrange().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkOrange().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkOrange().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkOrange().IsSystemColor(), _caller);
      Assert::AreEqual("DarkOrange", Drawing::Color::DarkOrange().Name(), _caller);
      Assert::AreEqual("Color [DarkOrange]", Drawing::Color::DarkOrange().ToString(), _caller);
    }
    
    void DarkOrchid() {
      Assert::AreEqual(0xFF9932CCu, (unsigned)Drawing::Color::DarkOrchid().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkOrchid().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkOrchid().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkOrchid().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkOrchid().IsSystemColor(), _caller);
      Assert::AreEqual("DarkOrchid", Drawing::Color::DarkOrchid().Name(), _caller);
      Assert::AreEqual("Color [DarkOrchid]", Drawing::Color::DarkOrchid().ToString(), _caller);
    }
    
    void DarkRed() {
      Assert::AreEqual(0xFF8B0000u, (unsigned)Drawing::Color::DarkRed().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkRed().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkRed().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkRed().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkRed().IsSystemColor(), _caller);
      Assert::AreEqual("DarkRed", Drawing::Color::DarkRed().Name(), _caller);
      Assert::AreEqual("Color [DarkRed]", Drawing::Color::DarkRed().ToString(), _caller);
    }
    
    void DarkSalmon() {
      Assert::AreEqual(0xFFE9967Au, (unsigned)Drawing::Color::DarkSalmon().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSalmon().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSalmon().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSalmon().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSalmon().IsSystemColor(), _caller);
      Assert::AreEqual("DarkSalmon", Drawing::Color::DarkSalmon().Name(), _caller);
      Assert::AreEqual("Color [DarkSalmon]", Drawing::Color::DarkSalmon().ToString(), _caller);
    }
    
    void DarkSeaGreen() {
      Assert::AreEqual(0xFF8FBC8Bu, (unsigned)Drawing::Color::DarkSeaGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen().IsSystemColor(), _caller);
      Assert::AreEqual("DarkSeaGreen", Drawing::Color::DarkSeaGreen().Name(), _caller);
      Assert::AreEqual("Color [DarkSeaGreen]", Drawing::Color::DarkSeaGreen().ToString(), _caller);
    }
    
    void DarkSlateBlue() {
      Assert::AreEqual(0xFF483D8Bu, (unsigned)Drawing::Color::DarkSlateBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue().IsSystemColor(), _caller);
      Assert::AreEqual("DarkSlateBlue", Drawing::Color::DarkSlateBlue().Name(), _caller);
      Assert::AreEqual("Color [DarkSlateBlue]", Drawing::Color::DarkSlateBlue().ToString(), _caller);
    }
    
    void DarkSlateGray() {
      Assert::AreEqual(0xFF2F4F4Fu, (unsigned)Drawing::Color::DarkSlateGray().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSlateGray().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSlateGray().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkSlateGray().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkSlateGray().IsSystemColor(), _caller);
      Assert::AreEqual("DarkSlateGray", Drawing::Color::DarkSlateGray().Name(), _caller);
      Assert::AreEqual("Color [DarkSlateGray]", Drawing::Color::DarkSlateGray().ToString(), _caller);
    }
    
    void DarkTurquoise() {
      Assert::AreEqual(0xFF00CED1u, (unsigned)Drawing::Color::DarkTurquoise().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkTurquoise().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkTurquoise().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkTurquoise().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkTurquoise().IsSystemColor(), _caller);
      Assert::AreEqual("DarkTurquoise", Drawing::Color::DarkTurquoise().Name(), _caller);
      Assert::AreEqual("Color [DarkTurquoise]", Drawing::Color::DarkTurquoise().ToString(), _caller);
    }
    
    void DarkViolet() {
      Assert::AreEqual(0xFF9400D3u, (unsigned)Drawing::Color::DarkViolet().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DarkViolet().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DarkViolet().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DarkViolet().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DarkViolet().IsSystemColor(), _caller);
      Assert::AreEqual("DarkViolet", Drawing::Color::DarkViolet().Name(), _caller);
      Assert::AreEqual("Color [DarkViolet]", Drawing::Color::DarkViolet().ToString(), _caller);
    }
    
    void DeepPink() {
      Assert::AreEqual(0xFFFF1493u, (unsigned)Drawing::Color::DeepPink().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DeepPink().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DeepPink().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DeepPink().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DeepPink().IsSystemColor(), _caller);
      Assert::AreEqual("DeepPink", Drawing::Color::DeepPink().Name(), _caller);
      Assert::AreEqual("Color [DeepPink]", Drawing::Color::DeepPink().ToString(), _caller);
    }
    
    void DeepSkyBlue() {
      Assert::AreEqual(0xFF00BFFFu, (unsigned)Drawing::Color::DeepSkyBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue().IsSystemColor(), _caller);
      Assert::AreEqual("DeepSkyBlue", Drawing::Color::DeepSkyBlue().Name(), _caller);
      Assert::AreEqual("Color [DeepSkyBlue]", Drawing::Color::DeepSkyBlue().ToString(), _caller);
    }
    
    void DimGray() {
      Assert::AreEqual(0xFF696969u, (unsigned)Drawing::Color::DimGray().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DimGray().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DimGray().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DimGray().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DimGray().IsSystemColor(), _caller);
      Assert::AreEqual("DimGray", Drawing::Color::DimGray().Name(), _caller);
      Assert::AreEqual("Color [DimGray]", Drawing::Color::DimGray().ToString(), _caller);
    }
    
    void DodgerBlue() {
      Assert::AreEqual(0xFF1E90FFu, (unsigned)Drawing::Color::DodgerBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::DodgerBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::DodgerBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::DodgerBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::DodgerBlue().IsSystemColor(), _caller);
      Assert::AreEqual("DodgerBlue", Drawing::Color::DodgerBlue().Name(), _caller);
      Assert::AreEqual("Color [DodgerBlue]", Drawing::Color::DodgerBlue().ToString(), _caller);
    }
    
    void Firebrick() {
      Assert::AreEqual(0xFFB22222u, (unsigned)Drawing::Color::Firebrick().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Firebrick().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Firebrick().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Firebrick().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Firebrick().IsSystemColor(), _caller);
      Assert::AreEqual("Firebrick", Drawing::Color::Firebrick().Name(), _caller);
      Assert::AreEqual("Color [Firebrick]", Drawing::Color::Firebrick().ToString(), _caller);
    }
    
    void FloralWhite() {
      Assert::AreEqual(0xFFFFFAF0u, (unsigned)Drawing::Color::FloralWhite().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::FloralWhite().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::FloralWhite().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::FloralWhite().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::FloralWhite().IsSystemColor(), _caller);
      Assert::AreEqual("FloralWhite", Drawing::Color::FloralWhite().Name(), _caller);
      Assert::AreEqual("Color [FloralWhite]", Drawing::Color::FloralWhite().ToString(), _caller);
    }
    
    void ForestGreen() {
      Assert::AreEqual(0xFF228B22u, (unsigned)Drawing::Color::ForestGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::ForestGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::ForestGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::ForestGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::ForestGreen().IsSystemColor(), _caller);
      Assert::AreEqual("ForestGreen", Drawing::Color::ForestGreen().Name(), _caller);
      Assert::AreEqual("Color [ForestGreen]", Drawing::Color::ForestGreen().ToString(), _caller);
    }
    
    void Fuchsia() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Fuchsia().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Fuchsia().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Fuchsia().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Fuchsia().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Fuchsia().IsSystemColor(), _caller);
      Assert::AreEqual("Fuchsia", Drawing::Color::Fuchsia().Name(), _caller);
      Assert::AreEqual("Color [Fuchsia]", Drawing::Color::Fuchsia().ToString(), _caller);
    }
    
    void Gainsboro() {
      Assert::AreEqual(0xFFDCDCDCu, (unsigned)Drawing::Color::Gainsboro().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Gainsboro().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Gainsboro().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Gainsboro().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Gainsboro().IsSystemColor(), _caller);
      Assert::AreEqual("Gainsboro", Drawing::Color::Gainsboro().Name(), _caller);
      Assert::AreEqual("Color [Gainsboro]", Drawing::Color::Gainsboro().ToString(), _caller);
    }
    
    void GhostWhite() {
      Assert::AreEqual(0xFFF8F8FFu, (unsigned)Drawing::Color::GhostWhite().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::GhostWhite().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::GhostWhite().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::GhostWhite().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::GhostWhite().IsSystemColor(), _caller);
      Assert::AreEqual("GhostWhite", Drawing::Color::GhostWhite().Name(), _caller);
      Assert::AreEqual("Color [GhostWhite]", Drawing::Color::GhostWhite().ToString(), _caller);
    }
    
    void Gold() {
      Assert::AreEqual(0xFFFFD700u, (unsigned)Drawing::Color::Gold().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Gold().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Gold().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Gold().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Gold().IsSystemColor(), _caller);
      Assert::AreEqual("Gold", Drawing::Color::Gold().Name(), _caller);
      Assert::AreEqual("Color [Gold]", Drawing::Color::Gold().ToString(), _caller);
    }
    
    void Goldenrod() {
      Assert::AreEqual(0xFFDAA520u, (unsigned)Drawing::Color::Goldenrod().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Goldenrod().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Goldenrod().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Goldenrod().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Goldenrod().IsSystemColor(), _caller);
      Assert::AreEqual("Goldenrod", Drawing::Color::Goldenrod().Name(), _caller);
      Assert::AreEqual("Color [Goldenrod]", Drawing::Color::Goldenrod().ToString(), _caller);
    }
    
    void Gray() {
      Assert::AreEqual(0xFF808080u, (unsigned)Drawing::Color::Gray().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Gray().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Gray().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Gray().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Gray().IsSystemColor(), _caller);
      Assert::AreEqual("Gray", Drawing::Color::Gray().Name(), _caller);
      Assert::AreEqual("Color [Gray]", Drawing::Color::Gray().ToString(), _caller);
    }
    
    void Green() {
      Assert::AreEqual(0xFF008000u, (unsigned)Drawing::Color::Green().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Green().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Green().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Green().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Green().IsSystemColor(), _caller);
      Assert::AreEqual("Green", Drawing::Color::Green().Name(), _caller);
      Assert::AreEqual("Color [Green]", Drawing::Color::Green().ToString(), _caller);
    }
    
    void GreenYellow() {
      Assert::AreEqual(0xFFADFF2Fu, (unsigned)Drawing::Color::GreenYellow().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::GreenYellow().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::GreenYellow().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::GreenYellow().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::GreenYellow().IsSystemColor(), _caller);
      Assert::AreEqual("GreenYellow", Drawing::Color::GreenYellow().Name(), _caller);
      Assert::AreEqual("Color [GreenYellow]", Drawing::Color::GreenYellow().ToString(), _caller);
    }
    
    void Honeydew() {
      Assert::AreEqual(0xFFF0FFF0u, (unsigned)Drawing::Color::Honeydew().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Honeydew().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Honeydew().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Honeydew().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Honeydew().IsSystemColor(), _caller);
      Assert::AreEqual("Honeydew", Drawing::Color::Honeydew().Name(), _caller);
      Assert::AreEqual("Color [Honeydew]", Drawing::Color::Honeydew().ToString(), _caller);
    }
    
    void HotPink() {
      Assert::AreEqual(0xFFFF69B4u, (unsigned)Drawing::Color::HotPink().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::HotPink().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::HotPink().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::HotPink().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::HotPink().IsSystemColor(), _caller);
      Assert::AreEqual("HotPink", Drawing::Color::HotPink().Name(), _caller);
      Assert::AreEqual("Color [HotPink]", Drawing::Color::HotPink().ToString(), _caller);
    }
    
    void IndianRed() {
      Assert::AreEqual(0xFFCD5C5Cu, (unsigned)Drawing::Color::IndianRed().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::IndianRed().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::IndianRed().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::IndianRed().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::IndianRed().IsSystemColor(), _caller);
      Assert::AreEqual("IndianRed", Drawing::Color::IndianRed().Name(), _caller);
      Assert::AreEqual("Color [IndianRed]", Drawing::Color::IndianRed().ToString(), _caller);
    }
    
    void Indigo() {
      Assert::AreEqual(0xFF4B0082u, (unsigned)Drawing::Color::Indigo().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Indigo().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Indigo().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Indigo().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Indigo().IsSystemColor(), _caller);
      Assert::AreEqual("Indigo", Drawing::Color::Indigo().Name(), _caller);
      Assert::AreEqual("Color [Indigo]", Drawing::Color::Indigo().ToString(), _caller);
    }
    
    void Ivory() {
      Assert::AreEqual(0xFFFFFFF0u, (unsigned)Drawing::Color::Ivory().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Ivory().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Ivory().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Ivory().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Ivory().IsSystemColor(), _caller);
      Assert::AreEqual("Ivory", Drawing::Color::Ivory().Name(), _caller);
      Assert::AreEqual("Color [Ivory]", Drawing::Color::Ivory().ToString(), _caller);
    }
    
    void Khaki() {
      Assert::AreEqual(0xFFF0E68Cu, (unsigned)Drawing::Color::Khaki().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Khaki().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Khaki().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Khaki().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Khaki().IsSystemColor(), _caller);
      Assert::AreEqual("Khaki", Drawing::Color::Khaki().Name(), _caller);
      Assert::AreEqual("Color [Khaki]", Drawing::Color::Khaki().ToString(), _caller);
    }
    
    void Lavender() {
      Assert::AreEqual(0xFFE6E6FAu, (unsigned)Drawing::Color::Lavender().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Lavender().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Lavender().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Lavender().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Lavender().IsSystemColor(), _caller);
      Assert::AreEqual("Lavender", Drawing::Color::Lavender().Name(), _caller);
      Assert::AreEqual("Color [Lavender]", Drawing::Color::Lavender().ToString(), _caller);
    }
    
    void LavenderBlush() {
      Assert::AreEqual(0xFFFFF0F5u, (unsigned)Drawing::Color::LavenderBlush().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LavenderBlush().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LavenderBlush().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LavenderBlush().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LavenderBlush().IsSystemColor(), _caller);
      Assert::AreEqual("LavenderBlush", Drawing::Color::LavenderBlush().Name(), _caller);
      Assert::AreEqual("Color [LavenderBlush]", Drawing::Color::LavenderBlush().ToString(), _caller);
    }
    
    void LawnGreen() {
      Assert::AreEqual(0xFF7CFC00u, (unsigned)Drawing::Color::LawnGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LawnGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LawnGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LawnGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LawnGreen().IsSystemColor(), _caller);
      Assert::AreEqual("LawnGreen", Drawing::Color::LawnGreen().Name(), _caller);
      Assert::AreEqual("Color [LawnGreen]", Drawing::Color::LawnGreen().ToString(), _caller);
    }
    
    void LemonChiffon() {
      Assert::AreEqual(0xFFFFFACDu, (unsigned)Drawing::Color::LemonChiffon().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LemonChiffon().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LemonChiffon().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LemonChiffon().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LemonChiffon().IsSystemColor(), _caller);
      Assert::AreEqual("LemonChiffon", Drawing::Color::LemonChiffon().Name(), _caller);
      Assert::AreEqual("Color [LemonChiffon]", Drawing::Color::LemonChiffon().ToString(), _caller);
    }
    
    void LightBlue() {
      Assert::AreEqual(0xFFADD8E6u, (unsigned)Drawing::Color::LightBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightBlue().IsSystemColor(), _caller);
      Assert::AreEqual("LightBlue", Drawing::Color::LightBlue().Name(), _caller);
      Assert::AreEqual("Color [LightBlue]", Drawing::Color::LightBlue().ToString(), _caller);
    }
    
    void LightCoral() {
      Assert::AreEqual(0xFFF08080u, (unsigned)Drawing::Color::LightCoral().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightCoral().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightCoral().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightCoral().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightCoral().IsSystemColor(), _caller);
      Assert::AreEqual("LightCoral", Drawing::Color::LightCoral().Name(), _caller);
      Assert::AreEqual("Color [LightCoral]", Drawing::Color::LightCoral().ToString(), _caller);
    }
    
    void LightCyan() {
      Assert::AreEqual(0xFFE0FFFFu, (unsigned)Drawing::Color::LightCyan().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightCyan().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightCyan().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightCyan().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightCyan().IsSystemColor(), _caller);
      Assert::AreEqual("LightCyan", Drawing::Color::LightCyan().Name(), _caller);
      Assert::AreEqual("Color [LightCyan]", Drawing::Color::LightCyan().ToString(), _caller);
    }
    
    void LightGoldenrodYellow() {
      Assert::AreEqual(0xFFFAFAD2u, (unsigned)Drawing::Color::LightGoldenrodYellow().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow().IsSystemColor(), _caller);
      Assert::AreEqual("LightGoldenrodYellow", Drawing::Color::LightGoldenrodYellow().Name(), _caller);
      Assert::AreEqual("Color [LightGoldenrodYellow]", Drawing::Color::LightGoldenrodYellow().ToString(), _caller);
    }
    
    void LightGray() {
      Assert::AreEqual(0xFFD3D3D3u, (unsigned)Drawing::Color::LightGray().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightGray().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightGray().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightGray().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightGray().IsSystemColor(), _caller);
      Assert::AreEqual("LightGray", Drawing::Color::LightGray().Name(), _caller);
      Assert::AreEqual("Color [LightGray]", Drawing::Color::LightGray().ToString(), _caller);
    }
    
    void LightGreen() {
      Assert::AreEqual(0xFF90EE90u, (unsigned)Drawing::Color::LightGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightGreen().IsSystemColor(), _caller);
      Assert::AreEqual("LightGreen", Drawing::Color::LightGreen().Name(), _caller);
      Assert::AreEqual("Color [LightGreen]", Drawing::Color::LightGreen().ToString(), _caller);
    }
    
    void LightPink() {
      Assert::AreEqual(0xFFFFB6C1u, (unsigned)Drawing::Color::LightPink().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightPink().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightPink().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightPink().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightPink().IsSystemColor(), _caller);
      Assert::AreEqual("LightPink", Drawing::Color::LightPink().Name(), _caller);
      Assert::AreEqual("Color [LightPink]", Drawing::Color::LightPink().ToString(), _caller);
    }
    
    void LightSalmon() {
      Assert::AreEqual(0xFFFFA07Au, (unsigned)Drawing::Color::LightSalmon().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightSalmon().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightSalmon().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightSalmon().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightSalmon().IsSystemColor(), _caller);
      Assert::AreEqual("LightSalmon", Drawing::Color::LightSalmon().Name(), _caller);
      Assert::AreEqual("Color [LightSalmon]", Drawing::Color::LightSalmon().ToString(), _caller);
    }
    
    void LightSeaGreen() {
      Assert::AreEqual(0xFF20B2AAu, (unsigned)Drawing::Color::LightSeaGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightSeaGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightSeaGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightSeaGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightSeaGreen().IsSystemColor(), _caller);
      Assert::AreEqual("LightSeaGreen", Drawing::Color::LightSeaGreen().Name(), _caller);
      Assert::AreEqual("Color [LightSeaGreen]", Drawing::Color::LightSeaGreen().ToString(), _caller);
    }
    
    void LightSkyBlue() {
      Assert::AreEqual(0xFF87CEFAu, (unsigned)Drawing::Color::LightSkyBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightSkyBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightSkyBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightSkyBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightSkyBlue().IsSystemColor(), _caller);
      Assert::AreEqual("LightSkyBlue", Drawing::Color::LightSkyBlue().Name(), _caller);
      Assert::AreEqual("Color [LightSkyBlue]", Drawing::Color::LightSkyBlue().ToString(), _caller);
    }
    
    void LightSlateGray() {
      Assert::AreEqual(0xFF778899u, (unsigned)Drawing::Color::LightSlateGray().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightSlateGray().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightSlateGray().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightSlateGray().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightSlateGray().IsSystemColor(), _caller);
      Assert::AreEqual("LightSlateGray", Drawing::Color::LightSlateGray().Name(), _caller);
      Assert::AreEqual("Color [LightSlateGray]", Drawing::Color::LightSlateGray().ToString(), _caller);
    }
    
    void LightSteelBlue() {
      Assert::AreEqual(0xFFB0C4DEu, (unsigned)Drawing::Color::LightSteelBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightSteelBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightSteelBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightSteelBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightSteelBlue().IsSystemColor(), _caller);
      Assert::AreEqual("LightSteelBlue", Drawing::Color::LightSteelBlue().Name(), _caller);
      Assert::AreEqual("Color [LightSteelBlue]", Drawing::Color::LightSteelBlue().ToString(), _caller);
    }
    
    void LightYellow() {
      Assert::AreEqual(0xFFFFFFE0u, (unsigned)Drawing::Color::LightYellow().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LightYellow().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LightYellow().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LightYellow().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LightYellow().IsSystemColor(), _caller);
      Assert::AreEqual("LightYellow", Drawing::Color::LightYellow().Name(), _caller);
      Assert::AreEqual("Color [LightYellow]", Drawing::Color::LightYellow().ToString(), _caller);
    }
    
    void Lime() {
      Assert::AreEqual(0xFF00FF00u, (unsigned)Drawing::Color::Lime().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Lime().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Lime().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Lime().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Lime().IsSystemColor(), _caller);
      Assert::AreEqual("Lime", Drawing::Color::Lime().Name(), _caller);
      Assert::AreEqual("Color [Lime]", Drawing::Color::Lime().ToString(), _caller);
    }
    
    void LimeGreen() {
      Assert::AreEqual(0xFF32CD32u, (unsigned)Drawing::Color::LimeGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::LimeGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::LimeGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::LimeGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::LimeGreen().IsSystemColor(), _caller);
      Assert::AreEqual("LimeGreen", Drawing::Color::LimeGreen().Name(), _caller);
      Assert::AreEqual("Color [LimeGreen]", Drawing::Color::LimeGreen().ToString(), _caller);
    }
    
    void Linen() {
      Assert::AreEqual(0xFFFAF0E6u, (unsigned)Drawing::Color::Linen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Linen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Linen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Linen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Linen().IsSystemColor(), _caller);
      Assert::AreEqual("Linen", Drawing::Color::Linen().Name(), _caller);
      Assert::AreEqual("Color [Linen]", Drawing::Color::Linen().ToString(), _caller);
    }
    
    void Magenta() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Magenta().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Magenta().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Magenta().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Magenta().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Magenta().IsSystemColor(), _caller);
      Assert::AreEqual("Magenta", Drawing::Color::Magenta().Name(), _caller);
      Assert::AreEqual("Color [Magenta]", Drawing::Color::Magenta().ToString(), _caller);
    }
    
    void Maroon() {
      Assert::AreEqual(0xFF800000u, (unsigned)Drawing::Color::Maroon().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Maroon().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Maroon().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Maroon().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Maroon().IsSystemColor(), _caller);
      Assert::AreEqual("Maroon", Drawing::Color::Maroon().Name(), _caller);
      Assert::AreEqual("Color [Maroon]", Drawing::Color::Maroon().ToString(), _caller);
    }
    
    void MediumAquamarine() {
      Assert::AreEqual(0xFF66CDAAu, (unsigned)Drawing::Color::MediumAquamarine().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumAquamarine().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumAquamarine().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumAquamarine().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumAquamarine().IsSystemColor(), _caller);
      Assert::AreEqual("MediumAquamarine", Drawing::Color::MediumAquamarine().Name(), _caller);
      Assert::AreEqual("Color [MediumAquamarine]", Drawing::Color::MediumAquamarine().ToString(), _caller);
    }
    
    void MediumBlue() {
      Assert::AreEqual(0xFF0000CDu, (unsigned)Drawing::Color::MediumBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumBlue().IsSystemColor(), _caller);
      Assert::AreEqual("MediumBlue", Drawing::Color::MediumBlue().Name(), _caller);
      Assert::AreEqual("Color [MediumBlue]", Drawing::Color::MediumBlue().ToString(), _caller);
    }
    
    void MediumOrchid() {
      Assert::AreEqual(0xFFBA55D3u, (unsigned)Drawing::Color::MediumOrchid().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumOrchid().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumOrchid().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumOrchid().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumOrchid().IsSystemColor(), _caller);
      Assert::AreEqual("MediumOrchid", Drawing::Color::MediumOrchid().Name(), _caller);
      Assert::AreEqual("Color [MediumOrchid]", Drawing::Color::MediumOrchid().ToString(), _caller);
    }
    
    void MediumPurple() {
      Assert::AreEqual(0xFF9370DBu, (unsigned)Drawing::Color::MediumPurple().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumPurple().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumPurple().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumPurple().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumPurple().IsSystemColor(), _caller);
      Assert::AreEqual("MediumPurple", Drawing::Color::MediumPurple().Name(), _caller);
      Assert::AreEqual("Color [MediumPurple]", Drawing::Color::MediumPurple().ToString(), _caller);
    }
    
    void MediumSeaGreen() {
      Assert::AreEqual(0xFF3CB371u, (unsigned)Drawing::Color::MediumSeaGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen().IsSystemColor(), _caller);
      Assert::AreEqual("MediumSeaGreen", Drawing::Color::MediumSeaGreen().Name(), _caller);
      Assert::AreEqual("Color [MediumSeaGreen]", Drawing::Color::MediumSeaGreen().ToString(), _caller);
    }
    
    void MediumSlateBlue() {
      Assert::AreEqual(0xFF7B68EEu, (unsigned)Drawing::Color::MediumSlateBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue().IsSystemColor(), _caller);
      Assert::AreEqual("MediumSlateBlue", Drawing::Color::MediumSlateBlue().Name(), _caller);
      Assert::AreEqual("Color [MediumSlateBlue]", Drawing::Color::MediumSlateBlue().ToString(), _caller);
    }
    
    void MediumSpringGreen() {
      Assert::AreEqual(0xFF00FA9Au, (unsigned)Drawing::Color::MediumSpringGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen().IsSystemColor(), _caller);
      Assert::AreEqual("MediumSpringGreen", Drawing::Color::MediumSpringGreen().Name(), _caller);
      Assert::AreEqual("Color [MediumSpringGreen]", Drawing::Color::MediumSpringGreen().ToString(), _caller);
    }
    
    void MediumTurquoise() {
      Assert::AreEqual(0xFF48D1CCu, (unsigned)Drawing::Color::MediumTurquoise().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumTurquoise().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumTurquoise().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumTurquoise().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumTurquoise().IsSystemColor(), _caller);
      Assert::AreEqual("MediumTurquoise", Drawing::Color::MediumTurquoise().Name(), _caller);
      Assert::AreEqual("Color [MediumTurquoise]", Drawing::Color::MediumTurquoise().ToString(), _caller);
    }
    
    void MediumVioletRed() {
      Assert::AreEqual(0xFFC71585u, (unsigned)Drawing::Color::MediumVioletRed().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MediumVioletRed().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MediumVioletRed().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MediumVioletRed().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MediumVioletRed().IsSystemColor(), _caller);
      Assert::AreEqual("MediumVioletRed", Drawing::Color::MediumVioletRed().Name(), _caller);
      Assert::AreEqual("Color [MediumVioletRed]", Drawing::Color::MediumVioletRed().ToString(), _caller);
    }
    
    void MidnightBlue() {
      Assert::AreEqual(0xFF191970u, (unsigned)Drawing::Color::MidnightBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MidnightBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MidnightBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MidnightBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MidnightBlue().IsSystemColor(), _caller);
      Assert::AreEqual("MidnightBlue", Drawing::Color::MidnightBlue().Name(), _caller);
      Assert::AreEqual("Color [MidnightBlue]", Drawing::Color::MidnightBlue().ToString(), _caller);
    }
    
    void MintCream() {
      Assert::AreEqual(0xFFF5FFFAu, (unsigned)Drawing::Color::MintCream().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MintCream().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MintCream().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MintCream().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MintCream().IsSystemColor(), _caller);
      Assert::AreEqual("MintCream", Drawing::Color::MintCream().Name(), _caller);
      Assert::AreEqual("Color [MintCream]", Drawing::Color::MintCream().ToString(), _caller);
    }
    
    void MistyRose() {
      Assert::AreEqual(0xFFFFE4E1u, (unsigned)Drawing::Color::MistyRose().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::MistyRose().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::MistyRose().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::MistyRose().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::MistyRose().IsSystemColor(), _caller);
      Assert::AreEqual("MistyRose", Drawing::Color::MistyRose().Name(), _caller);
      Assert::AreEqual("Color [MistyRose]", Drawing::Color::MistyRose().ToString(), _caller);
    }
    
    void Moccasin() {
      Assert::AreEqual(0xFFFFE4B5u, (unsigned)Drawing::Color::Moccasin().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Moccasin().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Moccasin().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Moccasin().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Moccasin().IsSystemColor(), _caller);
      Assert::AreEqual("Moccasin", Drawing::Color::Moccasin().Name(), _caller);
      Assert::AreEqual("Color [Moccasin]", Drawing::Color::Moccasin().ToString(), _caller);
    }
    
    void NavajoWhite() {
      Assert::AreEqual(0xFFFFDEADu, (unsigned)Drawing::Color::NavajoWhite().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::NavajoWhite().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::NavajoWhite().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::NavajoWhite().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::NavajoWhite().IsSystemColor(), _caller);
      Assert::AreEqual("NavajoWhite", Drawing::Color::NavajoWhite().Name(), _caller);
      Assert::AreEqual("Color [NavajoWhite]", Drawing::Color::NavajoWhite().ToString(), _caller);
    }
    
    void Navy() {
      Assert::AreEqual(0xFF000080u, (unsigned)Drawing::Color::Navy().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Navy().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Navy().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Navy().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Navy().IsSystemColor(), _caller);
      Assert::AreEqual("Navy", Drawing::Color::Navy().Name(), _caller);
      Assert::AreEqual("Color [Navy]", Drawing::Color::Navy().ToString(), _caller);
    }
    
    void OldLace() {
      Assert::AreEqual(0xFFFDF5E6u, (unsigned)Drawing::Color::OldLace().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::OldLace().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::OldLace().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::OldLace().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::OldLace().IsSystemColor(), _caller);
      Assert::AreEqual("OldLace", Drawing::Color::OldLace().Name(), _caller);
      Assert::AreEqual("Color [OldLace]", Drawing::Color::OldLace().ToString(), _caller);
    }
    
    void Olive() {
      Assert::AreEqual(0xFF808000u, (unsigned)Drawing::Color::Olive().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Olive().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Olive().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Olive().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Olive().IsSystemColor(), _caller);
      Assert::AreEqual("Olive", Drawing::Color::Olive().Name(), _caller);
      Assert::AreEqual("Color [Olive]", Drawing::Color::Olive().ToString(), _caller);
    }
    
    void OliveDrab() {
      Assert::AreEqual(0xFF6B8E23u, (unsigned)Drawing::Color::OliveDrab().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::OliveDrab().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::OliveDrab().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::OliveDrab().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::OliveDrab().IsSystemColor(), _caller);
      Assert::AreEqual("OliveDrab", Drawing::Color::OliveDrab().Name(), _caller);
      Assert::AreEqual("Color [OliveDrab]", Drawing::Color::OliveDrab().ToString(), _caller);
    }
    
    void Orange() {
      Assert::AreEqual(0xFFFFA500u, (unsigned)Drawing::Color::Orange().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Orange().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Orange().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Orange().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Orange().IsSystemColor(), _caller);
      Assert::AreEqual("Orange", Drawing::Color::Orange().Name(), _caller);
      Assert::AreEqual("Color [Orange]", Drawing::Color::Orange().ToString(), _caller);
    }
    
    void OrangeRed() {
      Assert::AreEqual(0xFFFF4500u, (unsigned)Drawing::Color::OrangeRed().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::OrangeRed().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::OrangeRed().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::OrangeRed().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::OrangeRed().IsSystemColor(), _caller);
      Assert::AreEqual("OrangeRed", Drawing::Color::OrangeRed().Name(), _caller);
      Assert::AreEqual("Color [OrangeRed]", Drawing::Color::OrangeRed().ToString(), _caller);
    }
    
    void Orchid() {
      Assert::AreEqual(0xFFDA70D6u, (unsigned)Drawing::Color::Orchid().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Orchid().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Orchid().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Orchid().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Orchid().IsSystemColor(), _caller);
      Assert::AreEqual("Orchid", Drawing::Color::Orchid().Name(), _caller);
      Assert::AreEqual("Color [Orchid]", Drawing::Color::Orchid().ToString(), _caller);
    }
    
    void PaleGoldenrod() {
      Assert::AreEqual(0xFFEEE8AAu, (unsigned)Drawing::Color::PaleGoldenrod().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod().IsSystemColor(), _caller);
      Assert::AreEqual("PaleGoldenrod", Drawing::Color::PaleGoldenrod().Name(), _caller);
      Assert::AreEqual("Color [PaleGoldenrod]", Drawing::Color::PaleGoldenrod().ToString(), _caller);
    }
    
    void PaleGreen() {
      Assert::AreEqual(0xFF98FB98u, (unsigned)Drawing::Color::PaleGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::PaleGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::PaleGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::PaleGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::PaleGreen().IsSystemColor(), _caller);
      Assert::AreEqual("PaleGreen", Drawing::Color::PaleGreen().Name(), _caller);
      Assert::AreEqual("Color [PaleGreen]", Drawing::Color::PaleGreen().ToString(), _caller);
    }
    
    void PaleTurquoise() {
      Assert::AreEqual(0xFFAFEEEEu, (unsigned)Drawing::Color::PaleTurquoise().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::PaleTurquoise().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::PaleTurquoise().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::PaleTurquoise().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::PaleTurquoise().IsSystemColor(), _caller);
      Assert::AreEqual("PaleTurquoise", Drawing::Color::PaleTurquoise().Name(), _caller);
      Assert::AreEqual("Color [PaleTurquoise]", Drawing::Color::PaleTurquoise().ToString(), _caller);
    }
    
    void PaleVioletRed() {
      Assert::AreEqual(0xFFDB7093u, (unsigned)Drawing::Color::PaleVioletRed().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::PaleVioletRed().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::PaleVioletRed().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::PaleVioletRed().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::PaleVioletRed().IsSystemColor(), _caller);
      Assert::AreEqual("PaleVioletRed", Drawing::Color::PaleVioletRed().Name(), _caller);
      Assert::AreEqual("Color [PaleVioletRed]", Drawing::Color::PaleVioletRed().ToString(), _caller);
    }
    
    void PapayaWhip() {
      Assert::AreEqual(0xFFFFEFD5u, (unsigned)Drawing::Color::PapayaWhip().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::PapayaWhip().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::PapayaWhip().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::PapayaWhip().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::PapayaWhip().IsSystemColor(), _caller);
      Assert::AreEqual("PapayaWhip", Drawing::Color::PapayaWhip().Name(), _caller);
      Assert::AreEqual("Color [PapayaWhip]", Drawing::Color::PapayaWhip().ToString(), _caller);
    }
    
    void PeachPuff() {
      Assert::AreEqual(0xFFFFDAB9u, (unsigned)Drawing::Color::PeachPuff().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::PeachPuff().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::PeachPuff().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::PeachPuff().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::PeachPuff().IsSystemColor(), _caller);
      Assert::AreEqual("PeachPuff", Drawing::Color::PeachPuff().Name(), _caller);
      Assert::AreEqual("Color [PeachPuff]", Drawing::Color::PeachPuff().ToString(), _caller);
    }
    
    void Peru() {
      Assert::AreEqual(0xFFCD853Fu, (unsigned)Drawing::Color::Peru().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Peru().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Peru().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Peru().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Peru().IsSystemColor(), _caller);
      Assert::AreEqual("Peru", Drawing::Color::Peru().Name(), _caller);
      Assert::AreEqual("Color [Peru]", Drawing::Color::Peru().ToString(), _caller);
    }
    
    void Pink() {
      Assert::AreEqual(0xFFFFC0CBu, (unsigned)Drawing::Color::Pink().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Pink().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Pink().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Pink().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Pink().IsSystemColor(), _caller);
      Assert::AreEqual("Pink", Drawing::Color::Pink().Name(), _caller);
      Assert::AreEqual("Color [Pink]", Drawing::Color::Pink().ToString(), _caller);
    }
    
    void Plum() {
      Assert::AreEqual(0xFFDDA0DDu, (unsigned)Drawing::Color::Plum().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Plum().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Plum().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Plum().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Plum().IsSystemColor(), _caller);
      Assert::AreEqual("Plum", Drawing::Color::Plum().Name(), _caller);
      Assert::AreEqual("Color [Plum]", Drawing::Color::Plum().ToString(), _caller);
    }
    
    void PowderBlue() {
      Assert::AreEqual(0xFFB0E0E6u, (unsigned)Drawing::Color::PowderBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::PowderBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::PowderBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::PowderBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::PowderBlue().IsSystemColor(), _caller);
      Assert::AreEqual("PowderBlue", Drawing::Color::PowderBlue().Name(), _caller);
      Assert::AreEqual("Color [PowderBlue]", Drawing::Color::PowderBlue().ToString(), _caller);
    }
    
    void Purple() {
      Assert::AreEqual(0xFF800080u, (unsigned)Drawing::Color::Purple().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Purple().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Purple().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Purple().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Purple().IsSystemColor(), _caller);
      Assert::AreEqual("Purple", Drawing::Color::Purple().Name(), _caller);
      Assert::AreEqual("Color [Purple]", Drawing::Color::Purple().ToString(), _caller);
    }
    
    void Red() {
      Assert::AreEqual(0xFFFF0000u, (unsigned)Drawing::Color::Red().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Red().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Red().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Red().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Red().IsSystemColor(), _caller);
      Assert::AreEqual("Red", Drawing::Color::Red().Name(), _caller);
      Assert::AreEqual("Color [Red]", Drawing::Color::Red().ToString(), _caller);
    }
    
    void RosyBrown() {
      Assert::AreEqual(0xFFBC8F8Fu, (unsigned)Drawing::Color::RosyBrown().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::RosyBrown().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::RosyBrown().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::RosyBrown().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::RosyBrown().IsSystemColor(), _caller);
      Assert::AreEqual("RosyBrown", Drawing::Color::RosyBrown().Name(), _caller);
      Assert::AreEqual("Color [RosyBrown]", Drawing::Color::RosyBrown().ToString(), _caller);
    }
    
    void RoyalBlue() {
      Assert::AreEqual(0xFF4169E1u, (unsigned)Drawing::Color::RoyalBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::RoyalBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::RoyalBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::RoyalBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::RoyalBlue().IsSystemColor(), _caller);
      Assert::AreEqual("RoyalBlue", Drawing::Color::RoyalBlue().Name(), _caller);
      Assert::AreEqual("Color [RoyalBlue]", Drawing::Color::RoyalBlue().ToString(), _caller);
    }
    
    void SaddleBrown() {
      Assert::AreEqual(0xFF8B4513u, (unsigned)Drawing::Color::SaddleBrown().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SaddleBrown().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SaddleBrown().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SaddleBrown().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SaddleBrown().IsSystemColor(), _caller);
      Assert::AreEqual("SaddleBrown", Drawing::Color::SaddleBrown().Name(), _caller);
      Assert::AreEqual("Color [SaddleBrown]", Drawing::Color::SaddleBrown().ToString(), _caller);
    }
    
    void Salmon() {
      Assert::AreEqual(0xFFFA8072u, (unsigned)Drawing::Color::Salmon().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Salmon().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Salmon().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Salmon().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Salmon().IsSystemColor(), _caller);
      Assert::AreEqual("Salmon", Drawing::Color::Salmon().Name(), _caller);
      Assert::AreEqual("Color [Salmon]", Drawing::Color::Salmon().ToString(), _caller);
    }
    
    void SandyBrown() {
      Assert::AreEqual(0xFFF4A460u, (unsigned)Drawing::Color::SandyBrown().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SandyBrown().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SandyBrown().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SandyBrown().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SandyBrown().IsSystemColor(), _caller);
      Assert::AreEqual("SandyBrown", Drawing::Color::SandyBrown().Name(), _caller);
      Assert::AreEqual("Color [SandyBrown]", Drawing::Color::SandyBrown().ToString(), _caller);
    }
    
    void SeaGreen() {
      Assert::AreEqual(0xFF2E8B57u, (unsigned)Drawing::Color::SeaGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SeaGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SeaGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SeaGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SeaGreen().IsSystemColor(), _caller);
      Assert::AreEqual("SeaGreen", Drawing::Color::SeaGreen().Name(), _caller);
      Assert::AreEqual("Color [SeaGreen]", Drawing::Color::SeaGreen().ToString(), _caller);
    }
    
    void SeaShell() {
      Assert::AreEqual(0xFFFFF5EEu, (unsigned)Drawing::Color::SeaShell().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SeaShell().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SeaShell().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SeaShell().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SeaShell().IsSystemColor(), _caller);
      Assert::AreEqual("SeaShell", Drawing::Color::SeaShell().Name(), _caller);
      Assert::AreEqual("Color [SeaShell]", Drawing::Color::SeaShell().ToString(), _caller);
    }
    
    void Sienna() {
      Assert::AreEqual(0xFFA0522Du, (unsigned)Drawing::Color::Sienna().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Sienna().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Sienna().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Sienna().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Sienna().IsSystemColor(), _caller);
      Assert::AreEqual("Sienna", Drawing::Color::Sienna().Name(), _caller);
      Assert::AreEqual("Color [Sienna]", Drawing::Color::Sienna().ToString(), _caller);
    }
    
    void Silver() {
      Assert::AreEqual(0xFFC0C0C0u, (unsigned)Drawing::Color::Silver().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Silver().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Silver().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Silver().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Silver().IsSystemColor(), _caller);
      Assert::AreEqual("Silver", Drawing::Color::Silver().Name(), _caller);
      Assert::AreEqual("Color [Silver]", Drawing::Color::Silver().ToString(), _caller);
    }
    
    void SkyBlue() {
      Assert::AreEqual(0xFF87CEEBu, (unsigned)Drawing::Color::SkyBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SkyBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SkyBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SkyBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SkyBlue().IsSystemColor(), _caller);
      Assert::AreEqual("SkyBlue", Drawing::Color::SkyBlue().Name(), _caller);
      Assert::AreEqual("Color [SkyBlue]", Drawing::Color::SkyBlue().ToString(), _caller);
    }
    
    void SlateBlue() {
      Assert::AreEqual(0xFF6A5ACDu, (unsigned)Drawing::Color::SlateBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SlateBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SlateBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SlateBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SlateBlue().IsSystemColor(), _caller);
      Assert::AreEqual("SlateBlue", Drawing::Color::SlateBlue().Name(), _caller);
      Assert::AreEqual("Color [SlateBlue]", Drawing::Color::SlateBlue().ToString(), _caller);
    }
    
    void SlateGray() {
      Assert::AreEqual(0xFF708090u, (unsigned)Drawing::Color::SlateGray().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SlateGray().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SlateGray().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SlateGray().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SlateGray().IsSystemColor(), _caller);
      Assert::AreEqual("SlateGray", Drawing::Color::SlateGray().Name(), _caller);
      Assert::AreEqual("Color [SlateGray]", Drawing::Color::SlateGray().ToString(), _caller);
    }
    
    void Snow() {
      Assert::AreEqual(0xFFFFFAFAu, (unsigned)Drawing::Color::Snow().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Snow().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Snow().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Snow().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Snow().IsSystemColor(), _caller);
      Assert::AreEqual("Snow", Drawing::Color::Snow().Name(), _caller);
      Assert::AreEqual("Color [Snow]", Drawing::Color::Snow().ToString(), _caller);
    }
    
    void SpringGreen() {
      Assert::AreEqual(0xFF00FF7Fu, (unsigned)Drawing::Color::SpringGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SpringGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SpringGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SpringGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SpringGreen().IsSystemColor(), _caller);
      Assert::AreEqual("SpringGreen", Drawing::Color::SpringGreen().Name(), _caller);
      Assert::AreEqual("Color [SpringGreen]", Drawing::Color::SpringGreen().ToString(), _caller);
    }
    
    void SteelBlue() {
      Assert::AreEqual(0xFF4682B4u, (unsigned)Drawing::Color::SteelBlue().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::SteelBlue().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::SteelBlue().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::SteelBlue().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::SteelBlue().IsSystemColor(), _caller);
      Assert::AreEqual("SteelBlue", Drawing::Color::SteelBlue().Name(), _caller);
      Assert::AreEqual("Color [SteelBlue]", Drawing::Color::SteelBlue().ToString(), _caller);
    }
    
    void Tan() {
      Assert::AreEqual(0xFFD2B48Cu, (unsigned)Drawing::Color::Tan().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Tan().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Tan().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Tan().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Tan().IsSystemColor(), _caller);
      Assert::AreEqual("Tan", Drawing::Color::Tan().Name(), _caller);
      Assert::AreEqual("Color [Tan]", Drawing::Color::Tan().ToString(), _caller);
    }
    
    void Teal() {
      Assert::AreEqual(0xFF008080u, (unsigned)Drawing::Color::Teal().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Teal().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Teal().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Teal().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Teal().IsSystemColor(), _caller);
      Assert::AreEqual("Teal", Drawing::Color::Teal().Name(), _caller);
      Assert::AreEqual("Color [Teal]", Drawing::Color::Teal().ToString(), _caller);
    }
    
    void Thistle() {
      Assert::AreEqual(0xFFD8BFD8u, (unsigned)Drawing::Color::Thistle().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Thistle().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Thistle().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Thistle().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Thistle().IsSystemColor(), _caller);
      Assert::AreEqual("Thistle", Drawing::Color::Thistle().Name(), _caller);
      Assert::AreEqual("Color [Thistle]", Drawing::Color::Thistle().ToString(), _caller);
    }
    
    void Tomato() {
      Assert::AreEqual(0xFFFF6347u, (unsigned)Drawing::Color::Tomato().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Tomato().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Tomato().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Tomato().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Tomato().IsSystemColor(), _caller);
      Assert::AreEqual("Tomato", Drawing::Color::Tomato().Name(), _caller);
      Assert::AreEqual("Color [Tomato]", Drawing::Color::Tomato().ToString(), _caller);
    }
    
    void Turquoise() {
      Assert::AreEqual(0xFF40E0D0u, (unsigned)Drawing::Color::Turquoise().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Turquoise().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Turquoise().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Turquoise().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Turquoise().IsSystemColor(), _caller);
      Assert::AreEqual("Turquoise", Drawing::Color::Turquoise().Name(), _caller);
      Assert::AreEqual("Color [Turquoise]", Drawing::Color::Turquoise().ToString(), _caller);
    }
    
    void Violet() {
      Assert::AreEqual(0xFFEE82EEu, (unsigned)Drawing::Color::Violet().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Violet().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Violet().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Violet().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Violet().IsSystemColor(), _caller);
      Assert::AreEqual("Violet", Drawing::Color::Violet().Name(), _caller);
      Assert::AreEqual("Color [Violet]", Drawing::Color::Violet().ToString(), _caller);
    }
    
    void Wheat() {
      Assert::AreEqual(0xFFF5DEB3u, (unsigned)Drawing::Color::Wheat().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Wheat().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Wheat().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Wheat().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Wheat().IsSystemColor(), _caller);
      Assert::AreEqual("Wheat", Drawing::Color::Wheat().Name(), _caller);
      Assert::AreEqual("Color [Wheat]", Drawing::Color::Wheat().ToString(), _caller);
    }
    
    void White() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::Color::White().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::White().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::White().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::White().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::White().IsSystemColor(), _caller);
      Assert::AreEqual("White", Drawing::Color::White().Name(), _caller);
      Assert::AreEqual("Color [White]", Drawing::Color::White().ToString(), _caller);
    }
    
    void WhiteSmoke() {
      Assert::AreEqual(0xFFF5F5F5u, (unsigned)Drawing::Color::WhiteSmoke().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::WhiteSmoke().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::WhiteSmoke().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::WhiteSmoke().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::WhiteSmoke().IsSystemColor(), _caller);
      Assert::AreEqual("WhiteSmoke", Drawing::Color::WhiteSmoke().Name(), _caller);
      Assert::AreEqual("Color [WhiteSmoke]", Drawing::Color::WhiteSmoke().ToString(), _caller);
    }
    
    void Yellow() {
      Assert::AreEqual(0xFFFFFF00u, (unsigned)Drawing::Color::Yellow().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::Yellow().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::Yellow().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::Yellow().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::Yellow().IsSystemColor(), _caller);
      Assert::AreEqual("Yellow", Drawing::Color::Yellow().Name(), _caller);
      Assert::AreEqual("Color [Yellow]", Drawing::Color::Yellow().ToString(), _caller);
    }
    
    void YellowGreen() {
      Assert::AreEqual(0xFF9ACD32u, (unsigned)Drawing::Color::YellowGreen().ToArgb(), _caller);
      Assert::IsFalse(Drawing::Color::YellowGreen().IsEmpty(), _caller);
      Assert::IsTrue(Drawing::Color::YellowGreen().IsKnownColor(), _caller);
      Assert::IsTrue(Drawing::Color::YellowGreen().IsNamedColor(), _caller);
      Assert::IsFalse(Drawing::Color::YellowGreen().IsSystemColor(), _caller);
      Assert::AreEqual("YellowGreen", Drawing::Color::YellowGreen().Name(), _caller);
      Assert::AreEqual("Color [YellowGreen]", Drawing::Color::YellowGreen().ToString(), _caller);
    }
  };
  
  _AddTest(Color, Ctor)
  _AddTest(Color, FromKnownColor)
  _AddTest(Color, FromArgb)
  _AddTest(Color, FromName)
  _AddTest(Color, Transparent)
  _AddTest(Color, AliceBlue)
  _AddTest(Color, AntiqueWhite)
  _AddTest(Color, Aqua)
  _AddTest(Color, Aquamarine)
  _AddTest(Color, Azure)
  _AddTest(Color, Beige)
  _AddTest(Color, Bisque)
  _AddTest(Color, Black)
  _AddTest(Color, BlanchedAlmond)
  _AddTest(Color, Blue)
  _AddTest(Color, BlueViolet)
  _AddTest(Color, Brown)
  _AddTest(Color, BurlyWood)
  _AddTest(Color, CadetBlue)
  _AddTest(Color, Chartreuse)
  _AddTest(Color, Chocolate)
  _AddTest(Color, Coral)
  _AddTest(Color, CornflowerBlue)
  _AddTest(Color, Cornsilk)
  _AddTest(Color, Crimson)
  _AddTest(Color, Cyan)
  _AddTest(Color, DarkBlue)
  _AddTest(Color, DarkCyan)
  _AddTest(Color, DarkGoldenrod)
  _AddTest(Color, DarkGray)
  _AddTest(Color, DarkGreen)
  _AddTest(Color, DarkKhaki)
  _AddTest(Color, DarkMagenta)
  _AddTest(Color, DarkOliveGreen)
  _AddTest(Color, DarkOrange)
  _AddTest(Color, DarkOrchid)
  _AddTest(Color, DarkRed)
  _AddTest(Color, DarkSalmon)
  _AddTest(Color, DarkSeaGreen)
  _AddTest(Color, DarkSlateBlue)
  _AddTest(Color, DarkSlateGray)
  _AddTest(Color, DarkTurquoise)
  _AddTest(Color, DarkViolet)
  _AddTest(Color, DeepPink)
  _AddTest(Color, DeepSkyBlue)
  _AddTest(Color, DimGray)
  _AddTest(Color, DodgerBlue)
  _AddTest(Color, Firebrick)
  _AddTest(Color, FloralWhite)
  _AddTest(Color, ForestGreen)
  _AddTest(Color, Fuchsia)
  _AddTest(Color, Gainsboro)
  _AddTest(Color, GhostWhite)
  _AddTest(Color, Gold)
  _AddTest(Color, Goldenrod)
  _AddTest(Color, Gray)
  _AddTest(Color, Green)
  _AddTest(Color, GreenYellow)
  _AddTest(Color, Honeydew)
  _AddTest(Color, HotPink)
  _AddTest(Color, IndianRed)
  _AddTest(Color, Indigo)
  _AddTest(Color, Ivory)
  _AddTest(Color, Khaki)
  _AddTest(Color, Lavender)
  _AddTest(Color, LavenderBlush)
  _AddTest(Color, LawnGreen)
  _AddTest(Color, LemonChiffon)
  _AddTest(Color, LightBlue)
  _AddTest(Color, LightCoral)
  _AddTest(Color, LightCyan)
  _AddTest(Color, LightGoldenrodYellow)
  _AddTest(Color, LightGray)
  _AddTest(Color, LightGreen)
  _AddTest(Color, LightPink)
  _AddTest(Color, LightSalmon)
  _AddTest(Color, LightSeaGreen)
  _AddTest(Color, LightSkyBlue)
  _AddTest(Color, LightSlateGray)
  _AddTest(Color, LightSteelBlue)
  _AddTest(Color, LightYellow)
  _AddTest(Color, Lime)
  _AddTest(Color, LimeGreen)
  _AddTest(Color, Linen)
  _AddTest(Color, Magenta)
  _AddTest(Color, Maroon)
  _AddTest(Color, MediumAquamarine)
  _AddTest(Color, MediumBlue)
  _AddTest(Color, MediumOrchid)
  _AddTest(Color, MediumPurple)
  _AddTest(Color, MediumSeaGreen)
  _AddTest(Color, MediumSlateBlue)
  _AddTest(Color, MediumSpringGreen)
  _AddTest(Color, MediumTurquoise)
  _AddTest(Color, MediumVioletRed)
  _AddTest(Color, MidnightBlue)
  _AddTest(Color, MintCream)
  _AddTest(Color, MistyRose)
  _AddTest(Color, Moccasin)
  _AddTest(Color, NavajoWhite)
  _AddTest(Color, Navy)
  _AddTest(Color, OldLace)
  _AddTest(Color, Olive)
  _AddTest(Color, OliveDrab)
  _AddTest(Color, Orange)
  _AddTest(Color, OrangeRed)
  _AddTest(Color, Orchid)
  _AddTest(Color, PaleGoldenrod)
  _AddTest(Color, PaleGreen)
  _AddTest(Color, PaleTurquoise)
  _AddTest(Color, PaleVioletRed)
  _AddTest(Color, PapayaWhip)
  _AddTest(Color, PeachPuff)
  _AddTest(Color, Peru)
  _AddTest(Color, Pink)
  _AddTest(Color, Plum)
  _AddTest(Color, PowderBlue)
  _AddTest(Color, Purple)
  _AddTest(Color, Red)
  _AddTest(Color, RosyBrown)
  _AddTest(Color, RoyalBlue)
  _AddTest(Color, SaddleBrown)
  _AddTest(Color, Salmon)
  _AddTest(Color, SandyBrown)
  _AddTest(Color, SeaGreen)
  _AddTest(Color, SeaShell)
  _AddTest(Color, Sienna)
  _AddTest(Color, Silver)
  _AddTest(Color, SkyBlue)
  _AddTest(Color, SlateBlue)
  _AddTest(Color, SlateGray)
  _AddTest(Color, Snow)
  _AddTest(Color, SpringGreen)
  _AddTest(Color, SteelBlue)
  _AddTest(Color, Tan)
  _AddTest(Color, Teal)
  _AddTest(Color, Thistle)
  _AddTest(Color, Tomato)
  _AddTest(Color, Turquoise)
  _AddTest(Color, Violet)
  _AddTest(Color, Wheat)
  _AddTest(Color, White)
  _AddTest(Color, WhiteSmoke)
  _AddTest(Color, Yellow)
  _AddTest(Color, YellowGreen)
}
