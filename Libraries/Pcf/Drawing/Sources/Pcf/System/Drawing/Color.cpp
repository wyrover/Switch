#include "../../../../Includes/Pcf/System/Drawing/Color.h"

using namespace System;
using namespace System::Drawing;

Color::KnownColors Color::knownColors {
  {(int32)KnownColor::ActiveBorder, (int32)0xFFB4B4B4},
  {(int32)KnownColor::ActiveCaption, (int32)0xFF99B4D1},
  {(int32)KnownColor::ActiveCaptionText, (int32)0xFF000000},
  {(int32)KnownColor::AppWorkspace, (int32)0xFFABABAB},
  {(int32)KnownColor::Control, (int32)0xFFF0F0F0},
  {(int32)KnownColor::ControlDark, (int32)0xFFA0A0A0},
  {(int32)KnownColor::ControlDarkDark, (int32)0xFF696969},
  {(int32)KnownColor::ControlLight, (int32)0xFFE3E3E3},
  {(int32)KnownColor::ControlLightLight, (int32)0xFFFFFFFF},
  {(int32)KnownColor::ControlText, (int32)0xFF000000},
  {(int32)KnownColor::Desktop, (int32)0xFF0076A3},
  {(int32)KnownColor::GrayText, (int32)0xFF6D6D6D},
  {(int32)KnownColor::Highlight, (int32)0xFF3399FF},
  {(int32)KnownColor::HighlightText, (int32)0xFFFFFFFF},
  {(int32)KnownColor::HotTrack, (int32)0xFF0066CC},
  {(int32)KnownColor::InactiveBorder, (int32)0xFFF4F7FC},
  {(int32)KnownColor::InactiveCaption, (int32)0xFFBFCDDB},
  {(int32)KnownColor::InactiveCaptionText, (int32)0xFF434E54},
  {(int32)KnownColor::Info, (int32)0xFFFFFFE1},
  {(int32)KnownColor::InfoText, (int32)0xFF000000},
  {(int32)KnownColor::Menu, (int32)0xFFF0F0F0},
  {(int32)KnownColor::MenuText, (int32)0xFF000000},
  {(int32)KnownColor::ScrollBar, (int32)0xFFC8C8C8},
  {(int32)KnownColor::Window, (int32)0xFFFFFFFF},
  {(int32)KnownColor::WindowFrame, (int32)0xFF646464},
  {(int32)KnownColor::WindowText, (int32)0xFF000000},
  {(int32)KnownColor::Transparent, (int32)0x00FFFFFF},
  {(int32)KnownColor::AliceBlue, (int32)0xFFF0F8FF},
  {(int32)KnownColor::AntiqueWhite, (int32)0xFFFAEBD7},
  {(int32)KnownColor::Aqua, (int32)0xFF00FFFF},
  {(int32)KnownColor::Aquamarine, (int32)0xFF7FFFD4},
  {(int32)KnownColor::Azure, (int32)0xFFF0FFFF},
  {(int32)KnownColor::Beige, (int32)0xFFF5F5DC},
  {(int32)KnownColor::Bisque, (int32)0xFFFFE4C4},
  {(int32)KnownColor::Black, (int32)0xFF000000},
  {(int32)KnownColor::BlanchedAlmond, (int32)0xFFFFEBCD},
  {(int32)KnownColor::Blue, (int32)0xFF0000FF},
  {(int32)KnownColor::BlueViolet, (int32)0xFF8A2BE2},
  {(int32)KnownColor::Brown, (int32)0xFFA52A2A},
  {(int32)KnownColor::BurlyWood, (int32)0xFFDEB887},
  {(int32)KnownColor::CadetBlue, (int32)0xFF5F9EA0},
  {(int32)KnownColor::Chartreuse, (int32)0xFF7FFF00},
  {(int32)KnownColor::Chocolate, (int32)0xFFD2691E},
  {(int32)KnownColor::Coral, (int32)0xFFFF7F50},
  {(int32)KnownColor::CornflowerBlue, (int32)0xFF6495ED},
  {(int32)KnownColor::Cornsilk, (int32)0xFFFFF8DC},
  {(int32)KnownColor::Crimson, (int32)0xFFDC143C},
  {(int32)KnownColor::Cyan, (int32)0xFF00FFFF},
  {(int32)KnownColor::DarkBlue, (int32)0xFF00008B},
  {(int32)KnownColor::DarkCyan, (int32)0xFF008B8B},
  {(int32)KnownColor::DarkGoldenrod, (int32)0xFFB8860B},
  {(int32)KnownColor::DarkGray, (int32)0xFFA9A9A9},
  {(int32)KnownColor::DarkGreen, (int32)0xFF006400},
  {(int32)KnownColor::DarkKhaki, (int32)0xFFBDB76B},
  {(int32)KnownColor::DarkMagenta, (int32)0xFF8B008B},
  {(int32)KnownColor::DarkOliveGreen, (int32)0xFF556B2F},
  {(int32)KnownColor::DarkOrange, (int32)0xFFFF8C00},
  {(int32)KnownColor::DarkOrchid, (int32)0xFF9932CC},
  {(int32)KnownColor::DarkRed, (int32)0xFF8B0000},
  {(int32)KnownColor::DarkSalmon, (int32)0xFFE9967A},
  {(int32)KnownColor::DarkSeaGreen, (int32)0xFF8FBC8B},
  {(int32)KnownColor::DarkSlateBlue, (int32)0xFF483D8B},
  {(int32)KnownColor::DarkSlateGray, (int32)0xFF2F4F4F},
  {(int32)KnownColor::DarkTurquoise, (int32)0xFF00CED1},
  {(int32)KnownColor::DarkViolet, (int32)0xFF9400D3},
  {(int32)KnownColor::DeepPink, (int32)0xFFFF1493},
  {(int32)KnownColor::DeepSkyBlue, (int32)0xFF00BFFF},
  {(int32)KnownColor::DimGray, (int32)0xFF696969},
  {(int32)KnownColor::DodgerBlue, (int32)0xFF1E90FF},
  {(int32)KnownColor::Firebrick, (int32)0xFFB22222},
  {(int32)KnownColor::FloralWhite, (int32)0xFFFFFAF0},
  {(int32)KnownColor::ForestGreen, (int32)0xFF228B22},
  {(int32)KnownColor::Fuchsia, (int32)0xFFFF00FF},
  {(int32)KnownColor::Gainsboro, (int32)0xFFDCDCDC},
  {(int32)KnownColor::GhostWhite, (int32)0xFFF8F8FF},
  {(int32)KnownColor::Gold, (int32)0xFFFFD700},
  {(int32)KnownColor::Goldenrod, (int32)0xFFDAA520},
  {(int32)KnownColor::Gray, (int32)0xFF808080},
  {(int32)KnownColor::Green, (int32)0xFF008000},
  {(int32)KnownColor::GreenYellow, (int32)0xFFADFF2F},
  {(int32)KnownColor::Honeydew, (int32)0xFFF0FFF0},
  {(int32)KnownColor::HotPink, (int32)0xFFFF69B4},
  {(int32)KnownColor::IndianRed, (int32)0xFFCD5C5C},
  {(int32)KnownColor::Indigo, (int32)0xFF4B0082},
  {(int32)KnownColor::Ivory, (int32)0xFFFFFFF0},
  {(int32)KnownColor::Khaki, (int32)0xFFF0E68C},
  {(int32)KnownColor::Lavender, (int32)0xFFE6E6FA},
  {(int32)KnownColor::LavenderBlush, (int32)0xFFFFF0F5},
  {(int32)KnownColor::LawnGreen, (int32)0xFF7CFC00},
  {(int32)KnownColor::LemonChiffon, (int32)0xFFFFFACD},
  {(int32)KnownColor::LightBlue, (int32)0xFFADD8E6},
  {(int32)KnownColor::LightCoral, (int32)0xFFF08080},
  {(int32)KnownColor::LightCyan, (int32)0xFFE0FFFF},
  {(int32)KnownColor::LightGoldenrodYellow, (int32)0xFFFAFAD2},
  {(int32)KnownColor::LightGray, (int32)0xFFD3D3D3},
  {(int32)KnownColor::LightGreen, (int32)0xFF90EE90},
  {(int32)KnownColor::LightPink, (int32)0xFFFFB6C1},
  {(int32)KnownColor::LightSalmon, (int32)0xFFFFA07A},
  {(int32)KnownColor::LightSeaGreen, (int32)0xFF20B2AA},
  {(int32)KnownColor::LightSkyBlue, (int32)0xFF87CEFA},
  {(int32)KnownColor::LightSlateGray, (int32)0xFF778899},
  {(int32)KnownColor::LightSteelBlue, (int32)0xFFB0C4DE},
  {(int32)KnownColor::LightYellow, (int32)0xFFFFFFE0},
  {(int32)KnownColor::Lime, (int32)0xFF00FF00},
  {(int32)KnownColor::LimeGreen, (int32)0xFF32CD32},
  {(int32)KnownColor::Linen, (int32)0xFFFAF0E6},
  {(int32)KnownColor::Magenta, (int32)0xFFFF00FF},
  {(int32)KnownColor::Maroon, (int32)0xFF800000},
  {(int32)KnownColor::MediumAquamarine, (int32)0xFF66CDAA},
  {(int32)KnownColor::MediumBlue, (int32)0xFF0000CD},
  {(int32)KnownColor::MediumOrchid, (int32)0xFFBA55D3},
  {(int32)KnownColor::MediumPurple, (int32)0xFF9370DB},
  {(int32)KnownColor::MediumSeaGreen, (int32)0xFF3CB371},
  {(int32)KnownColor::MediumSlateBlue, (int32)0xFF7B68EE},
  {(int32)KnownColor::MediumSpringGreen, (int32)0xFF00FA9A},
  {(int32)KnownColor::MediumTurquoise, (int32)0xFF48D1CC},
  {(int32)KnownColor::MediumVioletRed, (int32)0xFFC71585},
  {(int32)KnownColor::MidnightBlue, (int32)0xFF191970},
  {(int32)KnownColor::MintCream, (int32)0xFFF5FFFA},
  {(int32)KnownColor::MistyRose, (int32)0xFFFFE4E1},
  {(int32)KnownColor::Moccasin, (int32)0xFFFFE4B5},
  {(int32)KnownColor::NavajoWhite, (int32)0xFFFFDEAD},
  {(int32)KnownColor::Navy, (int32)0xFF000080},
  {(int32)KnownColor::OldLace, (int32)0xFFFDF5E6},
  {(int32)KnownColor::Olive, (int32)0xFF808000},
  {(int32)KnownColor::OliveDrab, (int32)0xFF6B8E23},
  {(int32)KnownColor::Orange, (int32)0xFFFFA500},
  {(int32)KnownColor::OrangeRed, (int32)0xFFFF4500},
  {(int32)KnownColor::Orchid, (int32)0xFFDA70D6},
  {(int32)KnownColor::PaleGoldenrod, (int32)0xFFEEE8AA},
  {(int32)KnownColor::PaleGreen, (int32)0xFF98FB98},
  {(int32)KnownColor::PaleTurquoise, (int32)0xFFAFEEEE},
  {(int32)KnownColor::PaleVioletRed, (int32)0xFFDB7093},
  {(int32)KnownColor::PapayaWhip, (int32)0xFFFFEFD5},
  {(int32)KnownColor::PeachPuff, (int32)0xFFFFDAB9},
  {(int32)KnownColor::Peru, (int32)0xFFCD853F},
  {(int32)KnownColor::Pink, (int32)0xFFFFC0CB},
  {(int32)KnownColor::Plum, (int32)0xFFDDA0DD},
  {(int32)KnownColor::PowderBlue, (int32)0xFFB0E0E6},
  {(int32)KnownColor::Purple, (int32)0xFF800080},
  {(int32)KnownColor::Red, (int32)0xFFFF0000},
  {(int32)KnownColor::RosyBrown, (int32)0xFFBC8F8F},
  {(int32)KnownColor::RoyalBlue, (int32)0xFF4169E1},
  {(int32)KnownColor::SaddleBrown, (int32)0xFF8B4513},
  {(int32)KnownColor::Salmon, (int32)0xFFFA8072},
  {(int32)KnownColor::SandyBrown, (int32)0xFFF4A460},
  {(int32)KnownColor::SeaGreen, (int32)0xFF2E8B57},
  {(int32)KnownColor::SeaShell, (int32)0xFFFFF5EE},
  {(int32)KnownColor::Sienna, (int32)0xFFA0522D},
  {(int32)KnownColor::Silver, (int32)0xFFC0C0C0},
  {(int32)KnownColor::SkyBlue, (int32)0xFF87CEEB},
  {(int32)KnownColor::SlateBlue, (int32)0xFF6A5ACD},
  {(int32)KnownColor::SlateGray, (int32)0xFF708090},
  {(int32)KnownColor::Snow, (int32)0xFFFFFAFA},
  {(int32)KnownColor::SpringGreen, (int32)0xFF00FF7F},
  {(int32)KnownColor::SteelBlue, (int32)0xFF4682B4},
  {(int32)KnownColor::Tan, (int32)0xFFD2B48C},
  {(int32)KnownColor::Teal, (int32)0xFF008080},
  {(int32)KnownColor::Thistle, (int32)0xFFD8BFD8},
  {(int32)KnownColor::Tomato, (int32)0xFFFF6347},
  {(int32)KnownColor::Turquoise, (int32)0xFF40E0D0},
  {(int32)KnownColor::Violet, (int32)0xFFEE82EE},
  {(int32)KnownColor::Wheat, (int32)0xFFF5DEB3},
  {(int32)KnownColor::White, (int32)0xFFFFFFFF},
  {(int32)KnownColor::WhiteSmoke, (int32)0xFFF5F5F5},
  {(int32)KnownColor::Yellow, (int32)0xFFFFFF00},
  {(int32)KnownColor::YellowGreen, (int32)0xFF9ACD32},
  {(int32)KnownColor::ButtonFace, (int32)0xFFEDEDED},
  {(int32)KnownColor::ButtonHighlight, (int32)0xFFFFFFFF},
  {(int32)KnownColor::ButtonShadow, (int32)0xFFACA899},
  {(int32)KnownColor::GradientActiveCaption, (int32)0xFF3D95FF},
  {(int32)KnownColor::GradientInactiveCaption, (int32)0xFF9DB9EB},
  {(int32)KnownColor::MenuBar, (int32)0xFFEDEDED},
  {(int32)KnownColor::MenuHighlight, (int32)0xFF316AC5}
};

const Color Color::Transparent = Color::FromKnownColor(KnownColor::Transparent);
const Color Color::AliceBlue = Color::FromKnownColor(KnownColor::AliceBlue);
const Color Color::AntiqueWhite = Color::FromKnownColor(KnownColor::AntiqueWhite);
const Color Color::Aqua = Color::FromKnownColor(KnownColor::Aqua);
const Color Color::Aquamarine = Color::FromKnownColor(KnownColor::Aquamarine);
const Color Color::Azure = Color::FromKnownColor(KnownColor::Azure);
const Color Color::Beige = Color::FromKnownColor(KnownColor::Beige);
const Color Color::Bisque = Color::FromKnownColor(KnownColor::Bisque);
const Color Color::Black = Color::FromKnownColor(KnownColor::Black);
const Color Color::BlanchedAlmond = Color::FromKnownColor(KnownColor::BlanchedAlmond);
const Color Color::Blue = Color::FromKnownColor(KnownColor::Blue);
const Color Color::BlueViolet = Color::FromKnownColor(KnownColor::BlueViolet);
const Color Color::Brown = Color::FromKnownColor(KnownColor::Brown);
const Color Color::BurlyWood = Color::FromKnownColor(KnownColor::BurlyWood);
const Color Color::CadetBlue = Color::FromKnownColor(KnownColor::CadetBlue);
const Color Color::Chartreuse = Color::FromKnownColor(KnownColor::Chartreuse);
const Color Color::Chocolate = Color::FromKnownColor(KnownColor::Chocolate);
const Color Color::Coral = Color::FromKnownColor(KnownColor::Coral);
const Color Color::CornflowerBlue = Color::FromKnownColor(KnownColor::CornflowerBlue);
const Color Color::Cornsilk = Color::FromKnownColor(KnownColor::Cornsilk);
const Color Color::Crimson = Color::FromKnownColor(KnownColor::Crimson);
const Color Color::Cyan = Color::FromKnownColor(KnownColor::Cyan);
const Color Color::DarkBlue = Color::FromKnownColor(KnownColor::DarkBlue);
const Color Color::DarkCyan = Color::FromKnownColor(KnownColor::DarkCyan);
const Color Color::DarkGoldenrod = Color::FromKnownColor(KnownColor::DarkGoldenrod);
const Color Color::DarkGray = Color::FromKnownColor(KnownColor::DarkGray);
const Color Color::DarkGreen = Color::FromKnownColor(KnownColor::DarkGreen);
const Color Color::DarkKhaki = Color::FromKnownColor(KnownColor::DarkKhaki);
const Color Color::DarkMagenta = Color::FromKnownColor(KnownColor::DarkMagenta);
const Color Color::DarkOliveGreen = Color::FromKnownColor(KnownColor::DarkOliveGreen);
const Color Color::DarkOrange = Color::FromKnownColor(KnownColor::DarkOrange);
const Color Color::DarkOrchid = Color::FromKnownColor(KnownColor::DarkOrchid);
const Color Color::DarkRed = Color::FromKnownColor(KnownColor::DarkRed);
const Color Color::DarkSalmon = Color::FromKnownColor(KnownColor::DarkSalmon);
const Color Color::DarkSeaGreen = Color::FromKnownColor(KnownColor::DarkSeaGreen);
const Color Color::DarkSlateBlue = Color::FromKnownColor(KnownColor::DarkSlateBlue);
const Color Color::DarkSlateGray = Color::FromKnownColor(KnownColor::DarkSlateGray);
const Color Color::DarkTurquoise = Color::FromKnownColor(KnownColor::DarkTurquoise);
const Color Color::DarkViolet = Color::FromKnownColor(KnownColor::DarkViolet);
const Color Color::DeepPink = Color::FromKnownColor(KnownColor::DeepPink);
const Color Color::DeepSkyBlue = Color::FromKnownColor(KnownColor::DeepSkyBlue);
const Color Color::DimGray = Color::FromKnownColor(KnownColor::DimGray);
const Color Color::DodgerBlue = Color::FromKnownColor(KnownColor::DodgerBlue);
const Color Color::Firebrick = Color::FromKnownColor(KnownColor::Firebrick);
const Color Color::FloralWhite = Color::FromKnownColor(KnownColor::FloralWhite);
const Color Color::ForestGreen = Color::FromKnownColor(KnownColor::ForestGreen);
const Color Color::Fuchsia = Color::FromKnownColor(KnownColor::Fuchsia);
const Color Color::Gainsboro = Color::FromKnownColor(KnownColor::Gainsboro);
const Color Color::GhostWhite = Color::FromKnownColor(KnownColor::GhostWhite);
const Color Color::Gold = Color::FromKnownColor(KnownColor::Gold);
const Color Color::Goldenrod = Color::FromKnownColor(KnownColor::Goldenrod);
const Color Color::Gray = Color::FromKnownColor(KnownColor::Gray);
const Color Color::Green = Color::FromKnownColor(KnownColor::Green);
const Color Color::GreenYellow = Color::FromKnownColor(KnownColor::GreenYellow);
const Color Color::Honeydew = Color::FromKnownColor(KnownColor::Honeydew);
const Color Color::HotPink = Color::FromKnownColor(KnownColor::HotPink);
const Color Color::IndianRed = Color::FromKnownColor(KnownColor::IndianRed);
const Color Color::Indigo = Color::FromKnownColor(KnownColor::Indigo);
const Color Color::Ivory = Color::FromKnownColor(KnownColor::Ivory);
const Color Color::Khaki = Color::FromKnownColor(KnownColor::Khaki);
const Color Color::Lavender = Color::FromKnownColor(KnownColor::Lavender);
const Color Color::LavenderBlush = Color::FromKnownColor(KnownColor::LavenderBlush);
const Color Color::LawnGreen = Color::FromKnownColor(KnownColor::LawnGreen);
const Color Color::LemonChiffon = Color::FromKnownColor(KnownColor::LemonChiffon);
const Color Color::LightBlue = Color::FromKnownColor(KnownColor::LightBlue);
const Color Color::LightCoral = Color::FromKnownColor(KnownColor::LightCoral);
const Color Color::LightCyan = Color::FromKnownColor(KnownColor::LightCyan);
const Color Color::LightGoldenrodYellow = Color::FromKnownColor(KnownColor::LightGoldenrodYellow);
const Color Color::LightGray = Color::FromKnownColor(KnownColor::LightGray);
const Color Color::LightGreen = Color::FromKnownColor(KnownColor::LightGreen);
const Color Color::LightPink = Color::FromKnownColor(KnownColor::LightPink);
const Color Color::LightSalmon = Color::FromKnownColor(KnownColor::LightSalmon);
const Color Color::LightSeaGreen = Color::FromKnownColor(KnownColor::LightSeaGreen);
const Color Color::LightSkyBlue = Color::FromKnownColor(KnownColor::LightSkyBlue);
const Color Color::LightSlateGray = Color::FromKnownColor(KnownColor::LightSlateGray);
const Color Color::LightSteelBlue = Color::FromKnownColor(KnownColor::LightSteelBlue);
const Color Color::LightYellow = Color::FromKnownColor(KnownColor::LightYellow);
const Color Color::Lime = Color::FromKnownColor(KnownColor::Lime);
const Color Color::LimeGreen = Color::FromKnownColor(KnownColor::LimeGreen);
const Color Color::Linen = Color::FromKnownColor(KnownColor::Linen);
const Color Color::Magenta = Color::FromKnownColor(KnownColor::Magenta);
const Color Color::Maroon = Color::FromKnownColor(KnownColor::Maroon);
const Color Color::MediumAquamarine = Color::FromKnownColor(KnownColor::MediumAquamarine);
const Color Color::MediumBlue = Color::FromKnownColor(KnownColor::MediumBlue);
const Color Color::MediumOrchid = Color::FromKnownColor(KnownColor::MediumOrchid);
const Color Color::MediumPurple = Color::FromKnownColor(KnownColor::MediumPurple);
const Color Color::MediumSeaGreen = Color::FromKnownColor(KnownColor::MediumSeaGreen);
const Color Color::MediumSlateBlue = Color::FromKnownColor(KnownColor::MediumSlateBlue);
const Color Color::MediumSpringGreen = Color::FromKnownColor(KnownColor::MediumSpringGreen);
const Color Color::MediumTurquoise = Color::FromKnownColor(KnownColor::MediumTurquoise);
const Color Color::MediumVioletRed = Color::FromKnownColor(KnownColor::MediumVioletRed);
const Color Color::MidnightBlue = Color::FromKnownColor(KnownColor::MidnightBlue);
const Color Color::MintCream = Color::FromKnownColor(KnownColor::MintCream);
const Color Color::MistyRose = Color::FromKnownColor(KnownColor::MistyRose);
const Color Color::Moccasin = Color::FromKnownColor(KnownColor::Moccasin);
const Color Color::NavajoWhite = Color::FromKnownColor(KnownColor::NavajoWhite);
const Color Color::Navy = Color::FromKnownColor(KnownColor::Navy);
const Color Color::OldLace = Color::FromKnownColor(KnownColor::OldLace);
const Color Color::Olive = Color::FromKnownColor(KnownColor::Olive);
const Color Color::OliveDrab = Color::FromKnownColor(KnownColor::OliveDrab);
const Color Color::Orange = Color::FromKnownColor(KnownColor::Orange);
const Color Color::OrangeRed = Color::FromKnownColor(KnownColor::OrangeRed);
const Color Color::Orchid = Color::FromKnownColor(KnownColor::Orchid);
const Color Color::PaleGoldenrod = Color::FromKnownColor(KnownColor::PaleGoldenrod);
const Color Color::PaleGreen = Color::FromKnownColor(KnownColor::PaleGreen);
const Color Color::PaleTurquoise = Color::FromKnownColor(KnownColor::PaleTurquoise);
const Color Color::PaleVioletRed = Color::FromKnownColor(KnownColor::PaleVioletRed);
const Color Color::PapayaWhip = Color::FromKnownColor(KnownColor::PapayaWhip);
const Color Color::PeachPuff = Color::FromKnownColor(KnownColor::PeachPuff);
const Color Color::Peru = Color::FromKnownColor(KnownColor::Peru);
const Color Color::Pink = Color::FromKnownColor(KnownColor::Pink);
const Color Color::Plum = Color::FromKnownColor(KnownColor::Plum);
const Color Color::PowderBlue = Color::FromKnownColor(KnownColor::PowderBlue);
const Color Color::Purple = Color::FromKnownColor(KnownColor::Purple);
const Color Color::Red = Color::FromKnownColor(KnownColor::Red);
const Color Color::RosyBrown = Color::FromKnownColor(KnownColor::RosyBrown);
const Color Color::RoyalBlue = Color::FromKnownColor(KnownColor::RoyalBlue);
const Color Color::SaddleBrown = Color::FromKnownColor(KnownColor::SaddleBrown);
const Color Color::Salmon = Color::FromKnownColor(KnownColor::Salmon);
const Color Color::SandyBrown = Color::FromKnownColor(KnownColor::SandyBrown);
const Color Color::SeaGreen = Color::FromKnownColor(KnownColor::SeaGreen);
const Color Color::SeaShell = Color::FromKnownColor(KnownColor::SeaShell);
const Color Color::Sienna = Color::FromKnownColor(KnownColor::Sienna);
const Color Color::Silver = Color::FromKnownColor(KnownColor::Silver);
const Color Color::SkyBlue = Color::FromKnownColor(KnownColor::SkyBlue);
const Color Color::SlateBlue = Color::FromKnownColor(KnownColor::SlateBlue);
const Color Color::SlateGray = Color::FromKnownColor(KnownColor::SlateGray);
const Color Color::Snow = Color::FromKnownColor(KnownColor::Snow);
const Color Color::SpringGreen = Color::FromKnownColor(KnownColor::SpringGreen);
const Color Color::SteelBlue = Color::FromKnownColor(KnownColor::SteelBlue);
const Color Color::Tan = Color::FromKnownColor(KnownColor::Tan);
const Color Color::Teal = Color::FromKnownColor(KnownColor::Teal);
const Color Color::Thistle = Color::FromKnownColor(KnownColor::Thistle);
const Color Color::Tomato = Color::FromKnownColor(KnownColor::Tomato);
const Color Color::Turquoise = Color::FromKnownColor(KnownColor::Turquoise);
const Color Color::Violet = Color::FromKnownColor(KnownColor::Violet);
const Color Color::Wheat = Color::FromKnownColor(KnownColor::Wheat);
const Color Color::White = Color::FromKnownColor(KnownColor::White);
const Color Color::WhiteSmoke = Color::FromKnownColor(KnownColor::WhiteSmoke);
const Color Color::Yellow = Color::FromKnownColor(KnownColor::Yellow);
const Color Color::YellowGreen = Color::FromKnownColor(KnownColor::YellowGreen);

bool Color::GetIsSystemColor() const {
  return this->knownColor != (KnownColor)0 && (this->knownColor <= KnownColor::WindowText || this->knownColor >= KnownColor::ButtonFace);
}

string Color::GetName() const {
  if (this->knownColor == (KnownColor)0 && this->argb == 0)
    return "0";
  
  if (this->knownColor != (KnownColor)0 || this->argb == 0)
    return Enum<KnownColor>(this->knownColor).GetName();
 
  return string::Format("{0:X8}", this->argb);
}

Color Color::FromName(const string& name) {
  return Color::FromKnownColor((KnownColor)Enum<KnownColor>::Parse(name));
}

Color Color::FromArgb(int32 alpha, const Color& baseColor) {
  if (alpha < 0 || alpha > 255)
    throw ArgumentException(pcf_current_information);
  
  return Color((alpha << 24) + (baseColor.argb & 0x00FFFFFF));
}

Color Color::FromArgb(int32 alpha, int32 red, int32 green, int32 blue) {
  if (alpha < 0 || alpha > 255 || red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
    throw ArgumentException(pcf_current_information);
  
  return Color((alpha << 24) + (red << 16) + (green << 8) + blue);
}

Color Color::FromKnownColor(KnownColor color) {
  if (!knownColors.ContainsKey((int32)color))
    throw ArgumentException(pcf_current_information);
  
  return Color(color);
}

bool Color::Equals(const Color& value) const {
  return this->argb == value.argb && this->knownColor == value.knownColor;
}

bool Color::Equals(const object& obj) const {
  return is<Color>(obj) && Equals((const Color&)obj);
}

string Color::ToString() const {
  if (this->knownColor == (KnownColor)0 &&this->argb == 0)
    return "Color [Empty]";
  
  if (this->knownColor != (KnownColor)0 || this->argb == 0)
    return string::Format("Color [{0}]", Name());
  
  return string::Format("Color [A={0}, R={1}, G={2}, B={3}]", A(), R(), G(), B());
}

