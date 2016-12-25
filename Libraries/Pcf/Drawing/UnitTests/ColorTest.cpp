#include <Pcf/System/Drawing/Color.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Drawing;
using namespace TUnit;

namespace PcfUnitTests {
  class Color : public TestFixture {
  public:
    void Ctor() {
      Drawing::Color color;
      Assert::AreEqual(0x00, color.A(), pcf_current_information);
      Assert::AreEqual(0x00, color.R(), pcf_current_information);
      Assert::AreEqual(0x00, color.G(), pcf_current_information);
      Assert::AreEqual(0x00, color.B(), pcf_current_information);
      Assert::IsTrue(color.IsEmpty(), pcf_current_information);
      Assert::IsFalse(color.IsKnownColor(), pcf_current_information);
      Assert::IsFalse(color.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(color.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("0", color.Name(), pcf_current_information);
      Assert::AreEqual("Color [Empty]", color.ToString(), pcf_current_information);
    }
    
    void FromKnownColor() {
      Assert::AreEqual(0xFF, Drawing::Color::FromKnownColor(KnownColor::Black).A(), pcf_current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).R(), pcf_current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).G(), pcf_current_information);
      Assert::AreEqual(0x00, Drawing::Color::FromKnownColor(KnownColor::Black).B(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::FromKnownColor(KnownColor::Black).IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FromKnownColor(KnownColor::Black).IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Black", Drawing::Color::FromKnownColor(KnownColor::Black).Name(), pcf_current_information);
      Assert::AreEqual("Color [Black]", Drawing::Color::FromKnownColor(KnownColor::Black).ToString(), pcf_current_information);
      
      Assert::Throws<ArgumentException>(pcf_delegate {Drawing::Color::FromKnownColor((KnownColor)34544);}, pcf_current_information);
    }
    
    void FromArgb() {
      Assert::AreEqual(0x12, Drawing::Color::FromArgb(0x12345678).A(), pcf_current_information);
      Assert::AreEqual(0x34, Drawing::Color::FromArgb(0x12345678).R(), pcf_current_information);
      Assert::AreEqual(0x56, Drawing::Color::FromArgb(0x12345678).G(), pcf_current_information);
      Assert::AreEqual(0x78, Drawing::Color::FromArgb(0x12345678).B(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsEmpty(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsKnownColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FromArgb(0x12345678).IsSystemColor(), pcf_current_information);
      Assert::AreEqual("12345678", Drawing::Color::FromArgb(0x12345678).Name(), pcf_current_information);
      Assert::AreEqual("Color [A=18, R=52, G=86, B=120]", Drawing::Color::FromArgb(0x12345678).ToString(), pcf_current_information);
    }
    
    void FromName() {
      Drawing::Color colorAliceBlue = Drawing::Color::FromName("AliceBlue");
      Assert::AreEqual(0xFF, colorAliceBlue.A(), pcf_current_information);
      Assert::AreEqual(0xF0, colorAliceBlue.R(), pcf_current_information);
      Assert::AreEqual(0xF8, colorAliceBlue.G(), pcf_current_information);
      Assert::AreEqual(0xFF, colorAliceBlue.B(), pcf_current_information);
      Assert::IsFalse(colorAliceBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(colorAliceBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(colorAliceBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(colorAliceBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("AliceBlue", colorAliceBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [AliceBlue]", colorAliceBlue.ToString(), pcf_current_information);
    }
    
    void Transparent() {
      Assert::AreEqual(0x00FFFFFF, Drawing::Color::Transparent.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Transparent.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Transparent.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Transparent.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Transparent.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Transparent", Drawing::Color::Transparent.Name(), pcf_current_information);
      Assert::AreEqual("Color [Transparent]", Drawing::Color::Transparent.ToString(), pcf_current_information);
    }
    
    void AliceBlue() {
      Assert::AreEqual(0xFFF0F8FFu, (unsigned)Drawing::Color::AliceBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::AliceBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::AliceBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::AliceBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::AliceBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("AliceBlue", Drawing::Color::AliceBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [AliceBlue]", Drawing::Color::AliceBlue.ToString(), pcf_current_information);
    }
    
    void AntiqueWhite() {
      Assert::AreEqual(0xFFFAEBD7u, (unsigned)Drawing::Color::AntiqueWhite.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::AntiqueWhite.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::AntiqueWhite.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::AntiqueWhite.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::AntiqueWhite.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("AntiqueWhite", Drawing::Color::AntiqueWhite.Name(), pcf_current_information);
      Assert::AreEqual("Color [AntiqueWhite]", Drawing::Color::AntiqueWhite.ToString(), pcf_current_information);
    }
    
    void Aqua() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Aqua.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Aqua.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Aqua.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Aqua.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Aqua.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Aqua", Drawing::Color::Aqua.Name(), pcf_current_information);
      Assert::AreEqual("Color [Aqua]", Drawing::Color::Aqua.ToString(), pcf_current_information);
    }
    
    void Aquamarine() {
      Assert::AreEqual(0xFF7FFFD4u, (unsigned)Drawing::Color::Aquamarine.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Aquamarine.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Aquamarine.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Aquamarine.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Aquamarine.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Aquamarine", Drawing::Color::Aquamarine.Name(), pcf_current_information);
      Assert::AreEqual("Color [Aquamarine]", Drawing::Color::Aquamarine.ToString(), pcf_current_information);
    }
    
    void Azure() {
      Assert::AreEqual(0xFFF0FFFFu, (unsigned)Drawing::Color::Azure.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Azure.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Azure.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Azure.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Azure.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Azure", Drawing::Color::Azure.Name(), pcf_current_information);
      Assert::AreEqual("Color [Azure]", Drawing::Color::Azure.ToString(), pcf_current_information);
    }
    
    void Beige() {
      Assert::AreEqual(0xFFF5F5DCu, (unsigned)Drawing::Color::Beige.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Beige.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Beige.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Beige.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Beige.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Beige", Drawing::Color::Beige.Name(), pcf_current_information);
      Assert::AreEqual("Color [Beige]", Drawing::Color::Beige.ToString(), pcf_current_information);
    }
    
    void Bisque() {
      Assert::AreEqual(0xFFFFE4C4u, (unsigned)Drawing::Color::Bisque.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Bisque.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Bisque.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Bisque.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Bisque.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Bisque", Drawing::Color::Bisque.Name(), pcf_current_information);
      Assert::AreEqual("Color [Bisque]", Drawing::Color::Bisque.ToString(), pcf_current_information);
    }
    
    void Black() {
      Assert::AreEqual(0xFF000000u, (unsigned)Drawing::Color::Black.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Black.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Black.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Black.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Black.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Black", Drawing::Color::Black.Name(), pcf_current_information);
      Assert::AreEqual("Color [Black]", Drawing::Color::Black.ToString(), pcf_current_information);
    }
    
    void BlanchedAlmond() {
      Assert::AreEqual(0xFFFFEBCDu, (unsigned)Drawing::Color::BlanchedAlmond.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::BlanchedAlmond.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::BlanchedAlmond.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("BlanchedAlmond", Drawing::Color::BlanchedAlmond.Name(), pcf_current_information);
      Assert::AreEqual("Color [BlanchedAlmond]", Drawing::Color::BlanchedAlmond.ToString(), pcf_current_information);
    }
    
    void Blue() {
      Assert::AreEqual(0xFF0000FFu, (unsigned)Drawing::Color::Blue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Blue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Blue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Blue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Blue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Blue", Drawing::Color::Blue.Name(), pcf_current_information);
      Assert::AreEqual("Color [Blue]", Drawing::Color::Blue.ToString(), pcf_current_information);
    }
    
    void BlueViolet() {
      Assert::AreEqual(0xFF8A2BE2u, (unsigned)Drawing::Color::BlueViolet.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::BlueViolet.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::BlueViolet.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::BlueViolet.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::BlueViolet.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("BlueViolet", Drawing::Color::BlueViolet.Name(), pcf_current_information);
      Assert::AreEqual("Color [BlueViolet]", Drawing::Color::BlueViolet.ToString(), pcf_current_information);
    }
    
    void Brown() {
      Assert::AreEqual(0xFFA52A2Au, (unsigned)Drawing::Color::Brown.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Brown.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Brown.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Brown.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Brown.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Brown", Drawing::Color::Brown.Name(), pcf_current_information);
      Assert::AreEqual("Color [Brown]", Drawing::Color::Brown.ToString(), pcf_current_information);
    }
    
    void BurlyWood() {
      Assert::AreEqual(0xFFDEB887u, (unsigned)Drawing::Color::BurlyWood.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::BurlyWood.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::BurlyWood.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::BurlyWood.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::BurlyWood.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("BurlyWood", Drawing::Color::BurlyWood.Name(), pcf_current_information);
      Assert::AreEqual("Color [BurlyWood]", Drawing::Color::BurlyWood.ToString(), pcf_current_information);
    }
    
    void CadetBlue() {
      Assert::AreEqual(0xFF5F9EA0u, (unsigned)Drawing::Color::CadetBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::CadetBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::CadetBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::CadetBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::CadetBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("CadetBlue", Drawing::Color::CadetBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [CadetBlue]", Drawing::Color::CadetBlue.ToString(), pcf_current_information);
    }
    
    void Chartreuse() {
      Assert::AreEqual(0xFF7FFF00u, (unsigned)Drawing::Color::Chartreuse.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Chartreuse.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Chartreuse.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Chartreuse.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Chartreuse.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Chartreuse", Drawing::Color::Chartreuse.Name(), pcf_current_information);
      Assert::AreEqual("Color [Chartreuse]", Drawing::Color::Chartreuse.ToString(), pcf_current_information);
    }
    
    void Chocolate() {
      Assert::AreEqual(0xFFD2691Eu, (unsigned)Drawing::Color::Chocolate.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Chocolate.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Chocolate.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Chocolate.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Chocolate.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Chocolate", Drawing::Color::Chocolate.Name(), pcf_current_information);
      Assert::AreEqual("Color [Chocolate]", Drawing::Color::Chocolate.ToString(), pcf_current_information);
    }
    
    void Coral() {
      Assert::AreEqual(0xFFFF7F50u, (unsigned)Drawing::Color::Coral.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Coral.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Coral.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Coral.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Coral.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Coral", Drawing::Color::Coral.Name(), pcf_current_information);
      Assert::AreEqual("Color [Coral]", Drawing::Color::Coral.ToString(), pcf_current_information);
    }
    
    void CornflowerBlue() {
      Assert::AreEqual(0xFF6495EDu, (unsigned)Drawing::Color::CornflowerBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::CornflowerBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::CornflowerBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::CornflowerBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::CornflowerBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("CornflowerBlue", Drawing::Color::CornflowerBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [CornflowerBlue]", Drawing::Color::CornflowerBlue.ToString(), pcf_current_information);
    }
    
    void Cornsilk() {
      Assert::AreEqual(0xFFFFF8DCu, (unsigned)Drawing::Color::Cornsilk.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Cornsilk.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Cornsilk.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Cornsilk.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Cornsilk.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Cornsilk", Drawing::Color::Cornsilk.Name(), pcf_current_information);
      Assert::AreEqual("Color [Cornsilk]", Drawing::Color::Cornsilk.ToString(), pcf_current_information);
    }
    
    void Crimson() {
      Assert::AreEqual(0xFFDC143Cu, (unsigned)Drawing::Color::Crimson.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Crimson.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Crimson.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Crimson.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Crimson.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Crimson", Drawing::Color::Crimson.Name(), pcf_current_information);
      Assert::AreEqual("Color [Crimson]", Drawing::Color::Crimson.ToString(), pcf_current_information);
    }
    
    void Cyan() {
      Assert::AreEqual(0xFF00FFFFu, (unsigned)Drawing::Color::Cyan.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Cyan.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Cyan.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Cyan.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Cyan.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Cyan", Drawing::Color::Cyan.Name(), pcf_current_information);
      Assert::AreEqual("Color [Cyan]", Drawing::Color::Cyan.ToString(), pcf_current_information);
    }
    
    void DarkBlue() {
      Assert::AreEqual(0xFF00008Bu, (unsigned)Drawing::Color::DarkBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkBlue", Drawing::Color::DarkBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkBlue]", Drawing::Color::DarkBlue.ToString(), pcf_current_information);
    }
    
    void DarkCyan() {
      Assert::AreEqual(0xFF008B8Bu, (unsigned)Drawing::Color::DarkCyan.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkCyan.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkCyan.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkCyan.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkCyan.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkCyan", Drawing::Color::DarkCyan.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkCyan]", Drawing::Color::DarkCyan.ToString(), pcf_current_information);
    }
    
    void DarkGoldenrod() {
      Assert::AreEqual(0xFFB8860Bu, (unsigned)Drawing::Color::DarkGoldenrod.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkGoldenrod.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkGoldenrod.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkGoldenrod", Drawing::Color::DarkGoldenrod.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkGoldenrod]", Drawing::Color::DarkGoldenrod.ToString(), pcf_current_information);
    }
    
    void DarkGray() {
      Assert::AreEqual(0xFFA9A9A9u, (unsigned)Drawing::Color::DarkGray.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkGray.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkGray.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkGray.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkGray.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkGray", Drawing::Color::DarkGray.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkGray]", Drawing::Color::DarkGray.ToString(), pcf_current_information);
    }
    
    void DarkGreen() {
      Assert::AreEqual(0xFF006400u, (unsigned)Drawing::Color::DarkGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkGreen", Drawing::Color::DarkGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkGreen]", Drawing::Color::DarkGreen.ToString(), pcf_current_information);
    }
    
    void DarkKhaki() {
      Assert::AreEqual(0xFFBDB76Bu, (unsigned)Drawing::Color::DarkKhaki.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkKhaki.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkKhaki.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkKhaki.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkKhaki.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkKhaki", Drawing::Color::DarkKhaki.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkKhaki]", Drawing::Color::DarkKhaki.ToString(), pcf_current_information);
    }
    
    void DarkMagenta() {
      Assert::AreEqual(0xFF8B008Bu, (unsigned)Drawing::Color::DarkMagenta.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkMagenta.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkMagenta.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkMagenta.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkMagenta.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkMagenta", Drawing::Color::DarkMagenta.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkMagenta]", Drawing::Color::DarkMagenta.ToString(), pcf_current_information);
    }
    
    void DarkOliveGreen() {
      Assert::AreEqual(0xFF556B2Fu, (unsigned)Drawing::Color::DarkOliveGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkOliveGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkOliveGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkOliveGreen", Drawing::Color::DarkOliveGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkOliveGreen]", Drawing::Color::DarkOliveGreen.ToString(), pcf_current_information);
    }
    
    void DarkOrange() {
      Assert::AreEqual(0xFFFF8C00u, (unsigned)Drawing::Color::DarkOrange.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrange.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrange.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrange.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrange.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkOrange", Drawing::Color::DarkOrange.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkOrange]", Drawing::Color::DarkOrange.ToString(), pcf_current_information);
    }
    
    void DarkOrchid() {
      Assert::AreEqual(0xFF9932CCu, (unsigned)Drawing::Color::DarkOrchid.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrchid.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrchid.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkOrchid.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkOrchid.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkOrchid", Drawing::Color::DarkOrchid.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkOrchid]", Drawing::Color::DarkOrchid.ToString(), pcf_current_information);
    }
    
    void DarkRed() {
      Assert::AreEqual(0xFF8B0000u, (unsigned)Drawing::Color::DarkRed.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkRed.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkRed.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkRed.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkRed.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkRed", Drawing::Color::DarkRed.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkRed]", Drawing::Color::DarkRed.ToString(), pcf_current_information);
    }
    
    void DarkSalmon() {
      Assert::AreEqual(0xFFE9967Au, (unsigned)Drawing::Color::DarkSalmon.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSalmon.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSalmon.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSalmon.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSalmon.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkSalmon", Drawing::Color::DarkSalmon.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkSalmon]", Drawing::Color::DarkSalmon.ToString(), pcf_current_information);
    }
    
    void DarkSeaGreen() {
      Assert::AreEqual(0xFF8FBC8Bu, (unsigned)Drawing::Color::DarkSeaGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSeaGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSeaGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkSeaGreen", Drawing::Color::DarkSeaGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkSeaGreen]", Drawing::Color::DarkSeaGreen.ToString(), pcf_current_information);
    }
    
    void DarkSlateBlue() {
      Assert::AreEqual(0xFF483D8Bu, (unsigned)Drawing::Color::DarkSlateBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkSlateBlue", Drawing::Color::DarkSlateBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkSlateBlue]", Drawing::Color::DarkSlateBlue.ToString(), pcf_current_information);
    }
    
    void DarkSlateGray() {
      Assert::AreEqual(0xFF2F4F4Fu, (unsigned)Drawing::Color::DarkSlateGray.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateGray.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateGray.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkSlateGray.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkSlateGray.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkSlateGray", Drawing::Color::DarkSlateGray.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkSlateGray]", Drawing::Color::DarkSlateGray.ToString(), pcf_current_information);
    }
    
    void DarkTurquoise() {
      Assert::AreEqual(0xFF00CED1u, (unsigned)Drawing::Color::DarkTurquoise.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkTurquoise.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkTurquoise.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkTurquoise.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkTurquoise.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkTurquoise", Drawing::Color::DarkTurquoise.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkTurquoise]", Drawing::Color::DarkTurquoise.ToString(), pcf_current_information);
    }
    
    void DarkViolet() {
      Assert::AreEqual(0xFF9400D3u, (unsigned)Drawing::Color::DarkViolet.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkViolet.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkViolet.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DarkViolet.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DarkViolet.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DarkViolet", Drawing::Color::DarkViolet.Name(), pcf_current_information);
      Assert::AreEqual("Color [DarkViolet]", Drawing::Color::DarkViolet.ToString(), pcf_current_information);
    }
    
    void DeepPink() {
      Assert::AreEqual(0xFFFF1493u, (unsigned)Drawing::Color::DeepPink.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DeepPink.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DeepPink.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DeepPink.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DeepPink.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DeepPink", Drawing::Color::DeepPink.Name(), pcf_current_information);
      Assert::AreEqual("Color [DeepPink]", Drawing::Color::DeepPink.ToString(), pcf_current_information);
    }
    
    void DeepSkyBlue() {
      Assert::AreEqual(0xFF00BFFFu, (unsigned)Drawing::Color::DeepSkyBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DeepSkyBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DeepSkyBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DeepSkyBlue", Drawing::Color::DeepSkyBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [DeepSkyBlue]", Drawing::Color::DeepSkyBlue.ToString(), pcf_current_information);
    }
    
    void DimGray() {
      Assert::AreEqual(0xFF696969u, (unsigned)Drawing::Color::DimGray.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DimGray.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DimGray.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DimGray.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DimGray.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DimGray", Drawing::Color::DimGray.Name(), pcf_current_information);
      Assert::AreEqual("Color [DimGray]", Drawing::Color::DimGray.ToString(), pcf_current_information);
    }
    
    void DodgerBlue() {
      Assert::AreEqual(0xFF1E90FFu, (unsigned)Drawing::Color::DodgerBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DodgerBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DodgerBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::DodgerBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::DodgerBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("DodgerBlue", Drawing::Color::DodgerBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [DodgerBlue]", Drawing::Color::DodgerBlue.ToString(), pcf_current_information);
    }
    
    void Firebrick() {
      Assert::AreEqual(0xFFB22222u, (unsigned)Drawing::Color::Firebrick.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Firebrick.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Firebrick.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Firebrick.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Firebrick.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Firebrick", Drawing::Color::Firebrick.Name(), pcf_current_information);
      Assert::AreEqual("Color [Firebrick]", Drawing::Color::Firebrick.ToString(), pcf_current_information);
    }
    
    void FloralWhite() {
      Assert::AreEqual(0xFFFFFAF0u, (unsigned)Drawing::Color::FloralWhite.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FloralWhite.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::FloralWhite.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::FloralWhite.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::FloralWhite.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("FloralWhite", Drawing::Color::FloralWhite.Name(), pcf_current_information);
      Assert::AreEqual("Color [FloralWhite]", Drawing::Color::FloralWhite.ToString(), pcf_current_information);
    }
    
    void ForestGreen() {
      Assert::AreEqual(0xFF228B22u, (unsigned)Drawing::Color::ForestGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::ForestGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::ForestGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::ForestGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::ForestGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("ForestGreen", Drawing::Color::ForestGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [ForestGreen]", Drawing::Color::ForestGreen.ToString(), pcf_current_information);
    }
    
    void Fuchsia() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Fuchsia.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Fuchsia.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Fuchsia.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Fuchsia.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Fuchsia.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Fuchsia", Drawing::Color::Fuchsia.Name(), pcf_current_information);
      Assert::AreEqual("Color [Fuchsia]", Drawing::Color::Fuchsia.ToString(), pcf_current_information);
    }
    
    void Gainsboro() {
      Assert::AreEqual(0xFFDCDCDCu, (unsigned)Drawing::Color::Gainsboro.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Gainsboro.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Gainsboro.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Gainsboro.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Gainsboro.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Gainsboro", Drawing::Color::Gainsboro.Name(), pcf_current_information);
      Assert::AreEqual("Color [Gainsboro]", Drawing::Color::Gainsboro.ToString(), pcf_current_information);
    }
    
    void GhostWhite() {
      Assert::AreEqual(0xFFF8F8FFu, (unsigned)Drawing::Color::GhostWhite.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::GhostWhite.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::GhostWhite.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::GhostWhite.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::GhostWhite.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("GhostWhite", Drawing::Color::GhostWhite.Name(), pcf_current_information);
      Assert::AreEqual("Color [GhostWhite]", Drawing::Color::GhostWhite.ToString(), pcf_current_information);
    }
    
    void Gold() {
      Assert::AreEqual(0xFFFFD700u, (unsigned)Drawing::Color::Gold.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Gold.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Gold.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Gold.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Gold.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Gold", Drawing::Color::Gold.Name(), pcf_current_information);
      Assert::AreEqual("Color [Gold]", Drawing::Color::Gold.ToString(), pcf_current_information);
    }
    
    void Goldenrod() {
      Assert::AreEqual(0xFFDAA520u, (unsigned)Drawing::Color::Goldenrod.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Goldenrod.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Goldenrod.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Goldenrod.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Goldenrod.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Goldenrod", Drawing::Color::Goldenrod.Name(), pcf_current_information);
      Assert::AreEqual("Color [Goldenrod]", Drawing::Color::Goldenrod.ToString(), pcf_current_information);
    }
    
    void Gray() {
      Assert::AreEqual(0xFF808080u, (unsigned)Drawing::Color::Gray.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Gray.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Gray.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Gray.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Gray.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Gray", Drawing::Color::Gray.Name(), pcf_current_information);
      Assert::AreEqual("Color [Gray]", Drawing::Color::Gray.ToString(), pcf_current_information);
    }
    
    void Green() {
      Assert::AreEqual(0xFF008000u, (unsigned)Drawing::Color::Green.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Green.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Green.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Green.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Green.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Green", Drawing::Color::Green.Name(), pcf_current_information);
      Assert::AreEqual("Color [Green]", Drawing::Color::Green.ToString(), pcf_current_information);
    }
    
    void GreenYellow() {
      Assert::AreEqual(0xFFADFF2Fu, (unsigned)Drawing::Color::GreenYellow.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::GreenYellow.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::GreenYellow.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::GreenYellow.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::GreenYellow.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("GreenYellow", Drawing::Color::GreenYellow.Name(), pcf_current_information);
      Assert::AreEqual("Color [GreenYellow]", Drawing::Color::GreenYellow.ToString(), pcf_current_information);
    }
    
    void Honeydew() {
      Assert::AreEqual(0xFFF0FFF0u, (unsigned)Drawing::Color::Honeydew.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Honeydew.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Honeydew.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Honeydew.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Honeydew.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Honeydew", Drawing::Color::Honeydew.Name(), pcf_current_information);
      Assert::AreEqual("Color [Honeydew]", Drawing::Color::Honeydew.ToString(), pcf_current_information);
    }
    
    void HotPink() {
      Assert::AreEqual(0xFFFF69B4u, (unsigned)Drawing::Color::HotPink.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::HotPink.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::HotPink.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::HotPink.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::HotPink.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("HotPink", Drawing::Color::HotPink.Name(), pcf_current_information);
      Assert::AreEqual("Color [HotPink]", Drawing::Color::HotPink.ToString(), pcf_current_information);
    }
    
    void IndianRed() {
      Assert::AreEqual(0xFFCD5C5Cu, (unsigned)Drawing::Color::IndianRed.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::IndianRed.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::IndianRed.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::IndianRed.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::IndianRed.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("IndianRed", Drawing::Color::IndianRed.Name(), pcf_current_information);
      Assert::AreEqual("Color [IndianRed]", Drawing::Color::IndianRed.ToString(), pcf_current_information);
    }
    
    void Indigo() {
      Assert::AreEqual(0xFF4B0082u, (unsigned)Drawing::Color::Indigo.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Indigo.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Indigo.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Indigo.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Indigo.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Indigo", Drawing::Color::Indigo.Name(), pcf_current_information);
      Assert::AreEqual("Color [Indigo]", Drawing::Color::Indigo.ToString(), pcf_current_information);
    }
    
    void Ivory() {
      Assert::AreEqual(0xFFFFFFF0u, (unsigned)Drawing::Color::Ivory.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Ivory.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Ivory.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Ivory.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Ivory.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Ivory", Drawing::Color::Ivory.Name(), pcf_current_information);
      Assert::AreEqual("Color [Ivory]", Drawing::Color::Ivory.ToString(), pcf_current_information);
    }
    
    void Khaki() {
      Assert::AreEqual(0xFFF0E68Cu, (unsigned)Drawing::Color::Khaki.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Khaki.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Khaki.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Khaki.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Khaki.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Khaki", Drawing::Color::Khaki.Name(), pcf_current_information);
      Assert::AreEqual("Color [Khaki]", Drawing::Color::Khaki.ToString(), pcf_current_information);
    }
    
    void Lavender() {
      Assert::AreEqual(0xFFE6E6FAu, (unsigned)Drawing::Color::Lavender.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Lavender.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Lavender.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Lavender.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Lavender.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Lavender", Drawing::Color::Lavender.Name(), pcf_current_information);
      Assert::AreEqual("Color [Lavender]", Drawing::Color::Lavender.ToString(), pcf_current_information);
    }
    
    void LavenderBlush() {
      Assert::AreEqual(0xFFFFF0F5u, (unsigned)Drawing::Color::LavenderBlush.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LavenderBlush.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LavenderBlush.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LavenderBlush.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LavenderBlush.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LavenderBlush", Drawing::Color::LavenderBlush.Name(), pcf_current_information);
      Assert::AreEqual("Color [LavenderBlush]", Drawing::Color::LavenderBlush.ToString(), pcf_current_information);
    }
    
    void LawnGreen() {
      Assert::AreEqual(0xFF7CFC00u, (unsigned)Drawing::Color::LawnGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LawnGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LawnGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LawnGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LawnGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LawnGreen", Drawing::Color::LawnGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [LawnGreen]", Drawing::Color::LawnGreen.ToString(), pcf_current_information);
    }
    
    void LemonChiffon() {
      Assert::AreEqual(0xFFFFFACDu, (unsigned)Drawing::Color::LemonChiffon.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LemonChiffon.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LemonChiffon.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LemonChiffon.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LemonChiffon.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LemonChiffon", Drawing::Color::LemonChiffon.Name(), pcf_current_information);
      Assert::AreEqual("Color [LemonChiffon]", Drawing::Color::LemonChiffon.ToString(), pcf_current_information);
    }
    
    void LightBlue() {
      Assert::AreEqual(0xFFADD8E6u, (unsigned)Drawing::Color::LightBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightBlue", Drawing::Color::LightBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightBlue]", Drawing::Color::LightBlue.ToString(), pcf_current_information);
    }
    
    void LightCoral() {
      Assert::AreEqual(0xFFF08080u, (unsigned)Drawing::Color::LightCoral.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightCoral.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightCoral.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightCoral.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightCoral.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightCoral", Drawing::Color::LightCoral.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightCoral]", Drawing::Color::LightCoral.ToString(), pcf_current_information);
    }
    
    void LightCyan() {
      Assert::AreEqual(0xFFE0FFFFu, (unsigned)Drawing::Color::LightCyan.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightCyan.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightCyan.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightCyan.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightCyan.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightCyan", Drawing::Color::LightCyan.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightCyan]", Drawing::Color::LightCyan.ToString(), pcf_current_information);
    }
    
    void LightGoldenrodYellow() {
      Assert::AreEqual(0xFFFAFAD2u, (unsigned)Drawing::Color::LightGoldenrodYellow.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightGoldenrodYellow.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightGoldenrodYellow.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightGoldenrodYellow", Drawing::Color::LightGoldenrodYellow.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightGoldenrodYellow]", Drawing::Color::LightGoldenrodYellow.ToString(), pcf_current_information);
    }
    
    void LightGray() {
      Assert::AreEqual(0xFFD3D3D3u, (unsigned)Drawing::Color::LightGray.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightGray.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightGray.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightGray.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightGray.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightGray", Drawing::Color::LightGray.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightGray]", Drawing::Color::LightGray.ToString(), pcf_current_information);
    }
    
    void LightGreen() {
      Assert::AreEqual(0xFF90EE90u, (unsigned)Drawing::Color::LightGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightGreen", Drawing::Color::LightGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightGreen]", Drawing::Color::LightGreen.ToString(), pcf_current_information);
    }
    
    void LightPink() {
      Assert::AreEqual(0xFFFFB6C1u, (unsigned)Drawing::Color::LightPink.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightPink.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightPink.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightPink.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightPink.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightPink", Drawing::Color::LightPink.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightPink]", Drawing::Color::LightPink.ToString(), pcf_current_information);
    }
    
    void LightSalmon() {
      Assert::AreEqual(0xFFFFA07Au, (unsigned)Drawing::Color::LightSalmon.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSalmon.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSalmon.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSalmon.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSalmon.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightSalmon", Drawing::Color::LightSalmon.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightSalmon]", Drawing::Color::LightSalmon.ToString(), pcf_current_information);
    }
    
    void LightSeaGreen() {
      Assert::AreEqual(0xFF20B2AAu, (unsigned)Drawing::Color::LightSeaGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSeaGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSeaGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSeaGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSeaGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightSeaGreen", Drawing::Color::LightSeaGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightSeaGreen]", Drawing::Color::LightSeaGreen.ToString(), pcf_current_information);
    }
    
    void LightSkyBlue() {
      Assert::AreEqual(0xFF87CEFAu, (unsigned)Drawing::Color::LightSkyBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSkyBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSkyBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSkyBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSkyBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightSkyBlue", Drawing::Color::LightSkyBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightSkyBlue]", Drawing::Color::LightSkyBlue.ToString(), pcf_current_information);
    }
    
    void LightSlateGray() {
      Assert::AreEqual(0xFF778899u, (unsigned)Drawing::Color::LightSlateGray.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSlateGray.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSlateGray.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSlateGray.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSlateGray.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightSlateGray", Drawing::Color::LightSlateGray.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightSlateGray]", Drawing::Color::LightSlateGray.ToString(), pcf_current_information);
    }
    
    void LightSteelBlue() {
      Assert::AreEqual(0xFFB0C4DEu, (unsigned)Drawing::Color::LightSteelBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSteelBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSteelBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightSteelBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightSteelBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightSteelBlue", Drawing::Color::LightSteelBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightSteelBlue]", Drawing::Color::LightSteelBlue.ToString(), pcf_current_information);
    }
    
    void LightYellow() {
      Assert::AreEqual(0xFFFFFFE0u, (unsigned)Drawing::Color::LightYellow.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightYellow.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightYellow.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LightYellow.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LightYellow.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LightYellow", Drawing::Color::LightYellow.Name(), pcf_current_information);
      Assert::AreEqual("Color [LightYellow]", Drawing::Color::LightYellow.ToString(), pcf_current_information);
    }
    
    void Lime() {
      Assert::AreEqual(0xFF00FF00u, (unsigned)Drawing::Color::Lime.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Lime.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Lime.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Lime.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Lime.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Lime", Drawing::Color::Lime.Name(), pcf_current_information);
      Assert::AreEqual("Color [Lime]", Drawing::Color::Lime.ToString(), pcf_current_information);
    }
    
    void LimeGreen() {
      Assert::AreEqual(0xFF32CD32u, (unsigned)Drawing::Color::LimeGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LimeGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LimeGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::LimeGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::LimeGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("LimeGreen", Drawing::Color::LimeGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [LimeGreen]", Drawing::Color::LimeGreen.ToString(), pcf_current_information);
    }
    
    void Linen() {
      Assert::AreEqual(0xFFFAF0E6u, (unsigned)Drawing::Color::Linen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Linen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Linen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Linen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Linen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Linen", Drawing::Color::Linen.Name(), pcf_current_information);
      Assert::AreEqual("Color [Linen]", Drawing::Color::Linen.ToString(), pcf_current_information);
    }
    
    void Magenta() {
      Assert::AreEqual(0xFFFF00FFu, (unsigned)Drawing::Color::Magenta.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Magenta.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Magenta.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Magenta.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Magenta.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Magenta", Drawing::Color::Magenta.Name(), pcf_current_information);
      Assert::AreEqual("Color [Magenta]", Drawing::Color::Magenta.ToString(), pcf_current_information);
    }
    
    void Maroon() {
      Assert::AreEqual(0xFF800000u, (unsigned)Drawing::Color::Maroon.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Maroon.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Maroon.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Maroon.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Maroon.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Maroon", Drawing::Color::Maroon.Name(), pcf_current_information);
      Assert::AreEqual("Color [Maroon]", Drawing::Color::Maroon.ToString(), pcf_current_information);
    }
    
    void MediumAquamarine() {
      Assert::AreEqual(0xFF66CDAAu, (unsigned)Drawing::Color::MediumAquamarine.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumAquamarine.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumAquamarine.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumAquamarine.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumAquamarine.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumAquamarine", Drawing::Color::MediumAquamarine.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumAquamarine]", Drawing::Color::MediumAquamarine.ToString(), pcf_current_information);
    }
    
    void MediumBlue() {
      Assert::AreEqual(0xFF0000CDu, (unsigned)Drawing::Color::MediumBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumBlue", Drawing::Color::MediumBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumBlue]", Drawing::Color::MediumBlue.ToString(), pcf_current_information);
    }
    
    void MediumOrchid() {
      Assert::AreEqual(0xFFBA55D3u, (unsigned)Drawing::Color::MediumOrchid.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumOrchid.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumOrchid.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumOrchid.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumOrchid.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumOrchid", Drawing::Color::MediumOrchid.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumOrchid]", Drawing::Color::MediumOrchid.ToString(), pcf_current_information);
    }
    
    void MediumPurple() {
      Assert::AreEqual(0xFF9370DBu, (unsigned)Drawing::Color::MediumPurple.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumPurple.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumPurple.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumPurple.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumPurple.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumPurple", Drawing::Color::MediumPurple.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumPurple]", Drawing::Color::MediumPurple.ToString(), pcf_current_information);
    }
    
    void MediumSeaGreen() {
      Assert::AreEqual(0xFF3CB371u, (unsigned)Drawing::Color::MediumSeaGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumSeaGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumSeaGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumSeaGreen", Drawing::Color::MediumSeaGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumSeaGreen]", Drawing::Color::MediumSeaGreen.ToString(), pcf_current_information);
    }
    
    void MediumSlateBlue() {
      Assert::AreEqual(0xFF7B68EEu, (unsigned)Drawing::Color::MediumSlateBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumSlateBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumSlateBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumSlateBlue", Drawing::Color::MediumSlateBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumSlateBlue]", Drawing::Color::MediumSlateBlue.ToString(), pcf_current_information);
    }
    
    void MediumSpringGreen() {
      Assert::AreEqual(0xFF00FA9Au, (unsigned)Drawing::Color::MediumSpringGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumSpringGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumSpringGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumSpringGreen", Drawing::Color::MediumSpringGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumSpringGreen]", Drawing::Color::MediumSpringGreen.ToString(), pcf_current_information);
    }
    
    void MediumTurquoise() {
      Assert::AreEqual(0xFF48D1CCu, (unsigned)Drawing::Color::MediumTurquoise.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumTurquoise.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumTurquoise.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumTurquoise.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumTurquoise.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumTurquoise", Drawing::Color::MediumTurquoise.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumTurquoise]", Drawing::Color::MediumTurquoise.ToString(), pcf_current_information);
    }
    
    void MediumVioletRed() {
      Assert::AreEqual(0xFFC71585u, (unsigned)Drawing::Color::MediumVioletRed.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumVioletRed.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumVioletRed.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MediumVioletRed.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MediumVioletRed.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MediumVioletRed", Drawing::Color::MediumVioletRed.Name(), pcf_current_information);
      Assert::AreEqual("Color [MediumVioletRed]", Drawing::Color::MediumVioletRed.ToString(), pcf_current_information);
    }
    
    void MidnightBlue() {
      Assert::AreEqual(0xFF191970u, (unsigned)Drawing::Color::MidnightBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MidnightBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MidnightBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MidnightBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MidnightBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MidnightBlue", Drawing::Color::MidnightBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [MidnightBlue]", Drawing::Color::MidnightBlue.ToString(), pcf_current_information);
    }
    
    void MintCream() {
      Assert::AreEqual(0xFFF5FFFAu, (unsigned)Drawing::Color::MintCream.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MintCream.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MintCream.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MintCream.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MintCream.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MintCream", Drawing::Color::MintCream.Name(), pcf_current_information);
      Assert::AreEqual("Color [MintCream]", Drawing::Color::MintCream.ToString(), pcf_current_information);
    }
    
    void MistyRose() {
      Assert::AreEqual(0xFFFFE4E1u, (unsigned)Drawing::Color::MistyRose.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MistyRose.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MistyRose.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::MistyRose.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::MistyRose.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("MistyRose", Drawing::Color::MistyRose.Name(), pcf_current_information);
      Assert::AreEqual("Color [MistyRose]", Drawing::Color::MistyRose.ToString(), pcf_current_information);
    }
    
    void Moccasin() {
      Assert::AreEqual(0xFFFFE4B5u, (unsigned)Drawing::Color::Moccasin.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Moccasin.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Moccasin.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Moccasin.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Moccasin.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Moccasin", Drawing::Color::Moccasin.Name(), pcf_current_information);
      Assert::AreEqual("Color [Moccasin]", Drawing::Color::Moccasin.ToString(), pcf_current_information);
    }
    
    void NavajoWhite() {
      Assert::AreEqual(0xFFFFDEADu, (unsigned)Drawing::Color::NavajoWhite.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::NavajoWhite.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::NavajoWhite.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::NavajoWhite.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::NavajoWhite.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("NavajoWhite", Drawing::Color::NavajoWhite.Name(), pcf_current_information);
      Assert::AreEqual("Color [NavajoWhite]", Drawing::Color::NavajoWhite.ToString(), pcf_current_information);
    }
    
    void Navy() {
      Assert::AreEqual(0xFF000080u, (unsigned)Drawing::Color::Navy.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Navy.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Navy.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Navy.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Navy.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Navy", Drawing::Color::Navy.Name(), pcf_current_information);
      Assert::AreEqual("Color [Navy]", Drawing::Color::Navy.ToString(), pcf_current_information);
    }
    
    void OldLace() {
      Assert::AreEqual(0xFFFDF5E6u, (unsigned)Drawing::Color::OldLace.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::OldLace.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::OldLace.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::OldLace.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::OldLace.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("OldLace", Drawing::Color::OldLace.Name(), pcf_current_information);
      Assert::AreEqual("Color [OldLace]", Drawing::Color::OldLace.ToString(), pcf_current_information);
    }
    
    void Olive() {
      Assert::AreEqual(0xFF808000u, (unsigned)Drawing::Color::Olive.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Olive.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Olive.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Olive.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Olive.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Olive", Drawing::Color::Olive.Name(), pcf_current_information);
      Assert::AreEqual("Color [Olive]", Drawing::Color::Olive.ToString(), pcf_current_information);
    }
    
    void OliveDrab() {
      Assert::AreEqual(0xFF6B8E23u, (unsigned)Drawing::Color::OliveDrab.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::OliveDrab.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::OliveDrab.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::OliveDrab.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::OliveDrab.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("OliveDrab", Drawing::Color::OliveDrab.Name(), pcf_current_information);
      Assert::AreEqual("Color [OliveDrab]", Drawing::Color::OliveDrab.ToString(), pcf_current_information);
    }
    
    void Orange() {
      Assert::AreEqual(0xFFFFA500u, (unsigned)Drawing::Color::Orange.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Orange.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Orange.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Orange.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Orange.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Orange", Drawing::Color::Orange.Name(), pcf_current_information);
      Assert::AreEqual("Color [Orange]", Drawing::Color::Orange.ToString(), pcf_current_information);
    }
    
    void OrangeRed() {
      Assert::AreEqual(0xFFFF4500u, (unsigned)Drawing::Color::OrangeRed.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::OrangeRed.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::OrangeRed.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::OrangeRed.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::OrangeRed.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("OrangeRed", Drawing::Color::OrangeRed.Name(), pcf_current_information);
      Assert::AreEqual("Color [OrangeRed]", Drawing::Color::OrangeRed.ToString(), pcf_current_information);
    }
    
    void Orchid() {
      Assert::AreEqual(0xFFDA70D6u, (unsigned)Drawing::Color::Orchid.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Orchid.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Orchid.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Orchid.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Orchid.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Orchid", Drawing::Color::Orchid.Name(), pcf_current_information);
      Assert::AreEqual("Color [Orchid]", Drawing::Color::Orchid.ToString(), pcf_current_information);
    }
    
    void PaleGoldenrod() {
      Assert::AreEqual(0xFFEEE8AAu, (unsigned)Drawing::Color::PaleGoldenrod.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleGoldenrod.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleGoldenrod.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("PaleGoldenrod", Drawing::Color::PaleGoldenrod.Name(), pcf_current_information);
      Assert::AreEqual("Color [PaleGoldenrod]", Drawing::Color::PaleGoldenrod.ToString(), pcf_current_information);
    }
    
    void PaleGreen() {
      Assert::AreEqual(0xFF98FB98u, (unsigned)Drawing::Color::PaleGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("PaleGreen", Drawing::Color::PaleGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [PaleGreen]", Drawing::Color::PaleGreen.ToString(), pcf_current_information);
    }
    
    void PaleTurquoise() {
      Assert::AreEqual(0xFFAFEEEEu, (unsigned)Drawing::Color::PaleTurquoise.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleTurquoise.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleTurquoise.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleTurquoise.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleTurquoise.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("PaleTurquoise", Drawing::Color::PaleTurquoise.Name(), pcf_current_information);
      Assert::AreEqual("Color [PaleTurquoise]", Drawing::Color::PaleTurquoise.ToString(), pcf_current_information);
    }
    
    void PaleVioletRed() {
      Assert::AreEqual(0xFFDB7093u, (unsigned)Drawing::Color::PaleVioletRed.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleVioletRed.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleVioletRed.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PaleVioletRed.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PaleVioletRed.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("PaleVioletRed", Drawing::Color::PaleVioletRed.Name(), pcf_current_information);
      Assert::AreEqual("Color [PaleVioletRed]", Drawing::Color::PaleVioletRed.ToString(), pcf_current_information);
    }
    
    void PapayaWhip() {
      Assert::AreEqual(0xFFFFEFD5u, (unsigned)Drawing::Color::PapayaWhip.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PapayaWhip.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PapayaWhip.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PapayaWhip.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PapayaWhip.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("PapayaWhip", Drawing::Color::PapayaWhip.Name(), pcf_current_information);
      Assert::AreEqual("Color [PapayaWhip]", Drawing::Color::PapayaWhip.ToString(), pcf_current_information);
    }
    
    void PeachPuff() {
      Assert::AreEqual(0xFFFFDAB9u, (unsigned)Drawing::Color::PeachPuff.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PeachPuff.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PeachPuff.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PeachPuff.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PeachPuff.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("PeachPuff", Drawing::Color::PeachPuff.Name(), pcf_current_information);
      Assert::AreEqual("Color [PeachPuff]", Drawing::Color::PeachPuff.ToString(), pcf_current_information);
    }
    
    void Peru() {
      Assert::AreEqual(0xFFCD853Fu, (unsigned)Drawing::Color::Peru.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Peru.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Peru.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Peru.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Peru.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Peru", Drawing::Color::Peru.Name(), pcf_current_information);
      Assert::AreEqual("Color [Peru]", Drawing::Color::Peru.ToString(), pcf_current_information);
    }
    
    void Pink() {
      Assert::AreEqual(0xFFFFC0CBu, (unsigned)Drawing::Color::Pink.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Pink.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Pink.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Pink.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Pink.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Pink", Drawing::Color::Pink.Name(), pcf_current_information);
      Assert::AreEqual("Color [Pink]", Drawing::Color::Pink.ToString(), pcf_current_information);
    }
    
    void Plum() {
      Assert::AreEqual(0xFFDDA0DDu, (unsigned)Drawing::Color::Plum.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Plum.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Plum.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Plum.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Plum.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Plum", Drawing::Color::Plum.Name(), pcf_current_information);
      Assert::AreEqual("Color [Plum]", Drawing::Color::Plum.ToString(), pcf_current_information);
    }
    
    void PowderBlue() {
      Assert::AreEqual(0xFFB0E0E6u, (unsigned)Drawing::Color::PowderBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PowderBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PowderBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::PowderBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::PowderBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("PowderBlue", Drawing::Color::PowderBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [PowderBlue]", Drawing::Color::PowderBlue.ToString(), pcf_current_information);
    }
    
    void Purple() {
      Assert::AreEqual(0xFF800080u, (unsigned)Drawing::Color::Purple.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Purple.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Purple.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Purple.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Purple.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Purple", Drawing::Color::Purple.Name(), pcf_current_information);
      Assert::AreEqual("Color [Purple]", Drawing::Color::Purple.ToString(), pcf_current_information);
    }
    
    void Red() {
      Assert::AreEqual(0xFFFF0000u, (unsigned)Drawing::Color::Red.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Red.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Red.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Red.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Red.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Red", Drawing::Color::Red.Name(), pcf_current_information);
      Assert::AreEqual("Color [Red]", Drawing::Color::Red.ToString(), pcf_current_information);
    }
    
    void RosyBrown() {
      Assert::AreEqual(0xFFBC8F8Fu, (unsigned)Drawing::Color::RosyBrown.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::RosyBrown.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::RosyBrown.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::RosyBrown.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::RosyBrown.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("RosyBrown", Drawing::Color::RosyBrown.Name(), pcf_current_information);
      Assert::AreEqual("Color [RosyBrown]", Drawing::Color::RosyBrown.ToString(), pcf_current_information);
    }
    
    void RoyalBlue() {
      Assert::AreEqual(0xFF4169E1u, (unsigned)Drawing::Color::RoyalBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::RoyalBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::RoyalBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::RoyalBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::RoyalBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("RoyalBlue", Drawing::Color::RoyalBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [RoyalBlue]", Drawing::Color::RoyalBlue.ToString(), pcf_current_information);
    }
    
    void SaddleBrown() {
      Assert::AreEqual(0xFF8B4513u, (unsigned)Drawing::Color::SaddleBrown.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SaddleBrown.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SaddleBrown.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SaddleBrown.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SaddleBrown.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SaddleBrown", Drawing::Color::SaddleBrown.Name(), pcf_current_information);
      Assert::AreEqual("Color [SaddleBrown]", Drawing::Color::SaddleBrown.ToString(), pcf_current_information);
    }
    
    void Salmon() {
      Assert::AreEqual(0xFFFA8072u, (unsigned)Drawing::Color::Salmon.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Salmon.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Salmon.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Salmon.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Salmon.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Salmon", Drawing::Color::Salmon.Name(), pcf_current_information);
      Assert::AreEqual("Color [Salmon]", Drawing::Color::Salmon.ToString(), pcf_current_information);
    }
    
    void SandyBrown() {
      Assert::AreEqual(0xFFF4A460u, (unsigned)Drawing::Color::SandyBrown.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SandyBrown.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SandyBrown.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SandyBrown.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SandyBrown.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SandyBrown", Drawing::Color::SandyBrown.Name(), pcf_current_information);
      Assert::AreEqual("Color [SandyBrown]", Drawing::Color::SandyBrown.ToString(), pcf_current_information);
    }
    
    void SeaGreen() {
      Assert::AreEqual(0xFF2E8B57u, (unsigned)Drawing::Color::SeaGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SeaGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SeaGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SeaGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SeaGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SeaGreen", Drawing::Color::SeaGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [SeaGreen]", Drawing::Color::SeaGreen.ToString(), pcf_current_information);
    }
    
    void SeaShell() {
      Assert::AreEqual(0xFFFFF5EEu, (unsigned)Drawing::Color::SeaShell.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SeaShell.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SeaShell.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SeaShell.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SeaShell.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SeaShell", Drawing::Color::SeaShell.Name(), pcf_current_information);
      Assert::AreEqual("Color [SeaShell]", Drawing::Color::SeaShell.ToString(), pcf_current_information);
    }
    
    void Sienna() {
      Assert::AreEqual(0xFFA0522Du, (unsigned)Drawing::Color::Sienna.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Sienna.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Sienna.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Sienna.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Sienna.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Sienna", Drawing::Color::Sienna.Name(), pcf_current_information);
      Assert::AreEqual("Color [Sienna]", Drawing::Color::Sienna.ToString(), pcf_current_information);
    }
    
    void Silver() {
      Assert::AreEqual(0xFFC0C0C0u, (unsigned)Drawing::Color::Silver.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Silver.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Silver.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Silver.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Silver.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Silver", Drawing::Color::Silver.Name(), pcf_current_information);
      Assert::AreEqual("Color [Silver]", Drawing::Color::Silver.ToString(), pcf_current_information);
    }
    
    void SkyBlue() {
      Assert::AreEqual(0xFF87CEEBu, (unsigned)Drawing::Color::SkyBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SkyBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SkyBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SkyBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SkyBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SkyBlue", Drawing::Color::SkyBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [SkyBlue]", Drawing::Color::SkyBlue.ToString(), pcf_current_information);
    }
    
    void SlateBlue() {
      Assert::AreEqual(0xFF6A5ACDu, (unsigned)Drawing::Color::SlateBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SlateBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SlateBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SlateBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SlateBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SlateBlue", Drawing::Color::SlateBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [SlateBlue]", Drawing::Color::SlateBlue.ToString(), pcf_current_information);
    }
    
    void SlateGray() {
      Assert::AreEqual(0xFF708090u, (unsigned)Drawing::Color::SlateGray.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SlateGray.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SlateGray.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SlateGray.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SlateGray.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SlateGray", Drawing::Color::SlateGray.Name(), pcf_current_information);
      Assert::AreEqual("Color [SlateGray]", Drawing::Color::SlateGray.ToString(), pcf_current_information);
    }
    
    void Snow() {
      Assert::AreEqual(0xFFFFFAFAu, (unsigned)Drawing::Color::Snow.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Snow.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Snow.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Snow.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Snow.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Snow", Drawing::Color::Snow.Name(), pcf_current_information);
      Assert::AreEqual("Color [Snow]", Drawing::Color::Snow.ToString(), pcf_current_information);
    }
    
    void SpringGreen() {
      Assert::AreEqual(0xFF00FF7Fu, (unsigned)Drawing::Color::SpringGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SpringGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SpringGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SpringGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SpringGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SpringGreen", Drawing::Color::SpringGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [SpringGreen]", Drawing::Color::SpringGreen.ToString(), pcf_current_information);
    }
    
    void SteelBlue() {
      Assert::AreEqual(0xFF4682B4u, (unsigned)Drawing::Color::SteelBlue.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SteelBlue.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SteelBlue.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::SteelBlue.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::SteelBlue.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("SteelBlue", Drawing::Color::SteelBlue.Name(), pcf_current_information);
      Assert::AreEqual("Color [SteelBlue]", Drawing::Color::SteelBlue.ToString(), pcf_current_information);
    }
    
    void Tan() {
      Assert::AreEqual(0xFFD2B48Cu, (unsigned)Drawing::Color::Tan.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Tan.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Tan.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Tan.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Tan.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Tan", Drawing::Color::Tan.Name(), pcf_current_information);
      Assert::AreEqual("Color [Tan]", Drawing::Color::Tan.ToString(), pcf_current_information);
    }
    
    void Teal() {
      Assert::AreEqual(0xFF008080u, (unsigned)Drawing::Color::Teal.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Teal.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Teal.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Teal.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Teal.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Teal", Drawing::Color::Teal.Name(), pcf_current_information);
      Assert::AreEqual("Color [Teal]", Drawing::Color::Teal.ToString(), pcf_current_information);
    }
    
    void Thistle() {
      Assert::AreEqual(0xFFD8BFD8u, (unsigned)Drawing::Color::Thistle.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Thistle.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Thistle.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Thistle.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Thistle.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Thistle", Drawing::Color::Thistle.Name(), pcf_current_information);
      Assert::AreEqual("Color [Thistle]", Drawing::Color::Thistle.ToString(), pcf_current_information);
    }
    
    void Tomato() {
      Assert::AreEqual(0xFFFF6347u, (unsigned)Drawing::Color::Tomato.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Tomato.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Tomato.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Tomato.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Tomato.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Tomato", Drawing::Color::Tomato.Name(), pcf_current_information);
      Assert::AreEqual("Color [Tomato]", Drawing::Color::Tomato.ToString(), pcf_current_information);
    }
    
    void Turquoise() {
      Assert::AreEqual(0xFF40E0D0u, (unsigned)Drawing::Color::Turquoise.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Turquoise.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Turquoise.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Turquoise.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Turquoise.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Turquoise", Drawing::Color::Turquoise.Name(), pcf_current_information);
      Assert::AreEqual("Color [Turquoise]", Drawing::Color::Turquoise.ToString(), pcf_current_information);
    }
    
    void Violet() {
      Assert::AreEqual(0xFFEE82EEu, (unsigned)Drawing::Color::Violet.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Violet.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Violet.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Violet.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Violet.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Violet", Drawing::Color::Violet.Name(), pcf_current_information);
      Assert::AreEqual("Color [Violet]", Drawing::Color::Violet.ToString(), pcf_current_information);
    }
    
    void Wheat() {
      Assert::AreEqual(0xFFF5DEB3u, (unsigned)Drawing::Color::Wheat.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Wheat.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Wheat.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Wheat.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Wheat.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Wheat", Drawing::Color::Wheat.Name(), pcf_current_information);
      Assert::AreEqual("Color [Wheat]", Drawing::Color::Wheat.ToString(), pcf_current_information);
    }
    
    void White() {
      Assert::AreEqual(0xFFFFFFFFu, (unsigned)Drawing::Color::White.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::White.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::White.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::White.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::White.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("White", Drawing::Color::White.Name(), pcf_current_information);
      Assert::AreEqual("Color [White]", Drawing::Color::White.ToString(), pcf_current_information);
    }
    
    void WhiteSmoke() {
      Assert::AreEqual(0xFFF5F5F5u, (unsigned)Drawing::Color::WhiteSmoke.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::WhiteSmoke.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::WhiteSmoke.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::WhiteSmoke.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::WhiteSmoke.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("WhiteSmoke", Drawing::Color::WhiteSmoke.Name(), pcf_current_information);
      Assert::AreEqual("Color [WhiteSmoke]", Drawing::Color::WhiteSmoke.ToString(), pcf_current_information);
    }
    
    void Yellow() {
      Assert::AreEqual(0xFFFFFF00u, (unsigned)Drawing::Color::Yellow.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Yellow.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Yellow.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::Yellow.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::Yellow.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("Yellow", Drawing::Color::Yellow.Name(), pcf_current_information);
      Assert::AreEqual("Color [Yellow]", Drawing::Color::Yellow.ToString(), pcf_current_information);
    }
    
    void YellowGreen() {
      Assert::AreEqual(0xFF9ACD32u, (unsigned)Drawing::Color::YellowGreen.ToArgb(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::YellowGreen.IsEmpty(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::YellowGreen.IsKnownColor(), pcf_current_information);
      Assert::IsTrue(Drawing::Color::YellowGreen.IsNamedColor(), pcf_current_information);
      Assert::IsFalse(Drawing::Color::YellowGreen.IsSystemColor(), pcf_current_information);
      Assert::AreEqual("YellowGreen", Drawing::Color::YellowGreen.Name(), pcf_current_information);
      Assert::AreEqual("Color [YellowGreen]", Drawing::Color::YellowGreen.ToString(), pcf_current_information);
    }
  };
  
  pcf_test(Color, Ctor);
  pcf_test(Color, FromKnownColor);
  pcf_test(Color, FromArgb);
  pcf_test(Color, FromName);
  pcf_test(Color, Transparent);
  pcf_test(Color, AliceBlue);
  pcf_test(Color, AntiqueWhite);
  pcf_test(Color, Aqua);
  pcf_test(Color, Aquamarine);
  pcf_test(Color, Azure);
  pcf_test(Color, Beige);
  pcf_test(Color, Bisque);
  pcf_test(Color, Black);
  pcf_test(Color, BlanchedAlmond);
  pcf_test(Color, Blue);
  pcf_test(Color, BlueViolet);
  pcf_test(Color, Brown);
  pcf_test(Color, BurlyWood);
  pcf_test(Color, CadetBlue);
  pcf_test(Color, Chartreuse);
  pcf_test(Color, Chocolate);
  pcf_test(Color, Coral);
  pcf_test(Color, CornflowerBlue);
  pcf_test(Color, Cornsilk);
  pcf_test(Color, Crimson);
  pcf_test(Color, Cyan);
  pcf_test(Color, DarkBlue);
  pcf_test(Color, DarkCyan);
  pcf_test(Color, DarkGoldenrod);
  pcf_test(Color, DarkGray);
  pcf_test(Color, DarkGreen);
  pcf_test(Color, DarkKhaki);
  pcf_test(Color, DarkMagenta);
  pcf_test(Color, DarkOliveGreen);
  pcf_test(Color, DarkOrange);
  pcf_test(Color, DarkOrchid);
  pcf_test(Color, DarkRed);
  pcf_test(Color, DarkSalmon);
  pcf_test(Color, DarkSeaGreen);
  pcf_test(Color, DarkSlateBlue);
  pcf_test(Color, DarkSlateGray);
  pcf_test(Color, DarkTurquoise);
  pcf_test(Color, DarkViolet);
  pcf_test(Color, DeepPink);
  pcf_test(Color, DeepSkyBlue);
  pcf_test(Color, DimGray);
  pcf_test(Color, DodgerBlue);
  pcf_test(Color, Firebrick);
  pcf_test(Color, FloralWhite);
  pcf_test(Color, ForestGreen);
  pcf_test(Color, Fuchsia);
  pcf_test(Color, Gainsboro);
  pcf_test(Color, GhostWhite);
  pcf_test(Color, Gold);
  pcf_test(Color, Goldenrod);
  pcf_test(Color, Gray);
  pcf_test(Color, Green);
  pcf_test(Color, GreenYellow);
  pcf_test(Color, Honeydew);
  pcf_test(Color, HotPink);
  pcf_test(Color, IndianRed);
  pcf_test(Color, Indigo);
  pcf_test(Color, Ivory);
  pcf_test(Color, Khaki);
  pcf_test(Color, Lavender);
  pcf_test(Color, LavenderBlush);
  pcf_test(Color, LawnGreen);
  pcf_test(Color, LemonChiffon);
  pcf_test(Color, LightBlue);
  pcf_test(Color, LightCoral);
  pcf_test(Color, LightCyan);
  pcf_test(Color, LightGoldenrodYellow);
  pcf_test(Color, LightGray);
  pcf_test(Color, LightGreen);
  pcf_test(Color, LightPink);
  pcf_test(Color, LightSalmon);
  pcf_test(Color, LightSeaGreen);
  pcf_test(Color, LightSkyBlue);
  pcf_test(Color, LightSlateGray);
  pcf_test(Color, LightSteelBlue);
  pcf_test(Color, LightYellow);
  pcf_test(Color, Lime);
  pcf_test(Color, LimeGreen);
  pcf_test(Color, Linen);
  pcf_test(Color, Magenta);
  pcf_test(Color, Maroon);
  pcf_test(Color, MediumAquamarine);
  pcf_test(Color, MediumBlue);
  pcf_test(Color, MediumOrchid);
  pcf_test(Color, MediumPurple);
  pcf_test(Color, MediumSeaGreen);
  pcf_test(Color, MediumSlateBlue);
  pcf_test(Color, MediumSpringGreen);
  pcf_test(Color, MediumTurquoise);
  pcf_test(Color, MediumVioletRed);
  pcf_test(Color, MidnightBlue);
  pcf_test(Color, MintCream);
  pcf_test(Color, MistyRose);
  pcf_test(Color, Moccasin);
  pcf_test(Color, NavajoWhite);
  pcf_test(Color, Navy);
  pcf_test(Color, OldLace);
  pcf_test(Color, Olive);
  pcf_test(Color, OliveDrab);
  pcf_test(Color, Orange);
  pcf_test(Color, OrangeRed);
  pcf_test(Color, Orchid);
  pcf_test(Color, PaleGoldenrod);
  pcf_test(Color, PaleGreen);
  pcf_test(Color, PaleTurquoise);
  pcf_test(Color, PaleVioletRed);
  pcf_test(Color, PapayaWhip);
  pcf_test(Color, PeachPuff);
  pcf_test(Color, Peru);
  pcf_test(Color, Pink);
  pcf_test(Color, Plum);
  pcf_test(Color, PowderBlue);
  pcf_test(Color, Purple);
  pcf_test(Color, Red);
  pcf_test(Color, RosyBrown);
  pcf_test(Color, RoyalBlue);
  pcf_test(Color, SaddleBrown);
  pcf_test(Color, Salmon);
  pcf_test(Color, SandyBrown);
  pcf_test(Color, SeaGreen);
  pcf_test(Color, SeaShell);
  pcf_test(Color, Sienna);
  pcf_test(Color, Silver);
  pcf_test(Color, SkyBlue);
  pcf_test(Color, SlateBlue);
  pcf_test(Color, SlateGray);
  pcf_test(Color, Snow);
  pcf_test(Color, SpringGreen);
  pcf_test(Color, SteelBlue);
  pcf_test(Color, Tan);
  pcf_test(Color, Teal);
  pcf_test(Color, Thistle);
  pcf_test(Color, Tomato);
  pcf_test(Color, Turquoise);
  pcf_test(Color, Violet);
  pcf_test(Color, Wheat);
  pcf_test(Color, White);
  pcf_test(Color, WhiteSmoke);
  pcf_test(Color, Yellow);
  pcf_test(Color, YellowGreen);
}
