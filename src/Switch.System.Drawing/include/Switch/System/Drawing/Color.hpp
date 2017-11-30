/// @file
/// @brief Contains Switch::System::Drawing::Color class.
#pragma once

#include <Switch/System/Object.hpp>
#include <Switch/System/IComparable.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>

#include "KnownColor.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Represents an ARGB (alpha, red, green, blue) color.
      /// @par Library
      /// Switch.System.Drawing
      class _export Color : public object, public IComparable {
      public:
        /// @brief Gets a system-defined color that has an ARGB value of 0x00FFFFFF. This field is constant.
        static _property<Color, _readonly> Transparent;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0F8FF. This field is constant.
        static _property<Color, _readonly> AliceBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAEBD7. This field is constant.
        static _property<Color, _readonly> AntiqueWhite;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
        static _property<Color, _readonly> Aqua;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFFD4. This field is constant.
        static _property<Color, _readonly> Aquamarine;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFFF. This field is constant.
        static _property<Color, _readonly> Azure;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5DC. This field is constant.
        static _property<Color, _readonly> Beige;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4C4. This field is constant.
        static _property<Color, _readonly> Bisque;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static _property<Color, _readonly> Black;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEBCD. This field is constant.
        static _property<Color, _readonly> BlanchedAlmond;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000FF. This field is constant.
        static _property<Color, _readonly> Blue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8A2BE2. This field is constant.
        static _property<Color, _readonly> BlueViolet;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFA52A2A. This field is constant.
        static _property<Color, _readonly> Brown;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDEB887. This field is constant.
        static _property<Color, _readonly> BurlyWood;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF5F9EA0. This field is constant.
        static _property<Color, _readonly> CadetBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7FFF00. This field is constant.
        static _property<Color, _readonly> Chartreuse;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2691E. This field is constant.
        static _property<Color, _readonly> Chocolate;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF7F50. This field is constant.
        static _property<Color, _readonly> Coral;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF6495ED. This field is constant.
        static _property<Color, _readonly> CornflowerBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF8DC. This field is constant.
        static _property<Color, _readonly> Cornsilk;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDC143C. This field is constant.
        static _property<Color, _readonly> Crimson;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FFFF. This field is constant.
        static _property<Color, _readonly> Cyan;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00008B. This field is constant.
        static _property<Color, _readonly> DarkBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF008B8B. This field is constant.
        static _property<Color, _readonly> DarkCyan;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB8860B. This field is constant.
        static _property<Color, _readonly> DarkGoldenrod;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFA9A9A9. This field is constant.
        static _property<Color, _readonly> DarkGray;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF006400. This field is constant.
        static _property<Color, _readonly> DarkGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFBDB76B. This field is constant.
        static _property<Color, _readonly> DarkKhaki;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B008B. This field is constant.
        static _property<Color, _readonly> DarkMagenta;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF556B2F. This field is constant.
        static _property<Color, _readonly> DarkOliveGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF8C00. This field is constant.
        static _property<Color, _readonly> DarkOrange;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9932CC. This field is constant.
        static _property<Color, _readonly> DarkOrchid;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B0000. This field is constant.
        static _property<Color, _readonly> DarkRed;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFE9967A. This field is constant.
        static _property<Color, _readonly> DarkSalmon;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8FBC8B. This field is constant.
        static _property<Color, _readonly> DarkSeaGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF483D8B. This field is constant.
        static _property<Color, _readonly> DarkSlateBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF2F4F4F. This field is constant.
        static _property<Color, _readonly> DarkSlateGray;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00CED1. This field is constant.
        static _property<Color, _readonly> DarkTurquoise;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9400D3. This field is constant.
        static _property<Color, _readonly> DarkViolet;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF1493. This field is constant.
        static _property<Color, _readonly> DeepPink;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00BFFF. This field is constant.
        static _property<Color, _readonly> DeepSkyBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF696969. This field is constant.
        static _property<Color, _readonly> DimGray;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF1E90FF. This field is constant.
        static _property<Color, _readonly> DodgerBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB22222. This field is constant.
        static _property<Color, _readonly> Firebrick;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAF0. This field is constant.
        static _property<Color, _readonly> FloralWhite;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF228B22. This field is constant.
        static _property<Color, _readonly> ForestGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
        static _property<Color, _readonly> Fuchsia;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDCDCDC. This field is constant.
        static _property<Color, _readonly> Gainsboro;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF8F8FF. This field is constant.
        static _property<Color, _readonly> GhostWhite;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFD700. This field is constant.
        static _property<Color, _readonly> Gold;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDAA520. This field is constant.
        static _property<Color, _readonly> Goldenrod;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
        static _property<Color, _readonly> Gray;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF008000. This field is constant.
        static _property<Color, _readonly> Green;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFADFF2F. This field is constant.
        static _property<Color, _readonly> GreenYellow;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0FFF0. This field is constant.
        static _property<Color, _readonly> Honeydew;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF69B4. This field is constant.
        static _property<Color, _readonly> HotPink;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD5C5C. This field is constant.
        static _property<Color, _readonly> IndianRed;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF4B0082. This field is constant.
        static _property<Color, _readonly> Indigo;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFF0. This field is constant.
        static _property<Color, _readonly> Ivory;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF0E68C. This field is constant.
        static _property<Color, _readonly> Khaki;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFE6E6FA. This field is constant.
        static _property<Color, _readonly> Lavender;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF0F5. This field is constant.
        static _property<Color, _readonly> LavenderBlush;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7CFC00. This field is constant.
        static _property<Color, _readonly> LawnGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFACD. This field is constant.
        static _property<Color, _readonly> LemonChiffon;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFADD8E6. This field is constant.
        static _property<Color, _readonly> LightBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF08080. This field is constant.
        static _property<Color, _readonly> LightCoral;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFE0FFFF. This field is constant.
        static _property<Color, _readonly> LightCyan;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAFAD2. This field is constant.
        static _property<Color, _readonly> LightGoldenrodYellow;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD3D3D3. This field is constant.
        static _property<Color, _readonly> LightGray;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF90EE90. This field is constant.
        static _property<Color, _readonly> LightGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFB6C1. This field is constant.
        static _property<Color, _readonly> LightPink;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA07A. This field is constant.
        static _property<Color, _readonly> LightSalmon;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF20B2AA. This field is constant.
        static _property<Color, _readonly> LightSeaGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEFA. This field is constant.
        static _property<Color, _readonly> LightSkyBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF778899. This field is constant.
        static _property<Color, _readonly> LightSlateGray;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0C4DE. This field is constant.
        static _property<Color, _readonly> LightSteelBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE0. This field is constant.
        static _property<Color, _readonly> LightYellow;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF00. This field is constant.
        static _property<Color, _readonly> Lime;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF32CD32. This field is constant.
        static _property<Color, _readonly> LimeGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFAF0E6. This field is constant.
        static _property<Color, _readonly> Linen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF00FF. This field is constant.
        static _property<Color, _readonly> Magenta;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF800000. This field is constant.
        static _property<Color, _readonly> Maroon;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF66CDAA. This field is constant.
        static _property<Color, _readonly> MediumAquamarine;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF0000CD. This field is constant.
        static _property<Color, _readonly> MediumBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFBA55D3. This field is constant.
        static _property<Color, _readonly> MediumOrchid;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9370DB. This field is constant.
        static _property<Color, _readonly> MediumPurple;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF3CB371. This field is constant.
        static _property<Color, _readonly> MediumSeaGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7B68EE. This field is constant.
        static _property<Color, _readonly> MediumSlateBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FA9A. This field is constant.
        static _property<Color, _readonly> MediumSpringGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF48D1CC. This field is constant.
        static _property<Color, _readonly> MediumTurquoise;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFC71585. This field is constant.
        static _property<Color, _readonly> MediumVioletRed;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF191970. This field is constant.
        static _property<Color, _readonly> MidnightBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5FFFA. This field is constant.
        static _property<Color, _readonly> MintCream;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4E1. This field is constant.
        static _property<Color, _readonly> MistyRose;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFE4B5. This field is constant.
        static _property<Color, _readonly> Moccasin;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDEAD. This field is constant.
        static _property<Color, _readonly> NavajoWhite;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
        static _property<Color, _readonly> Navy;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFDF5E6. This field is constant.
        static _property<Color, _readonly> OldLace;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF808000. This field is constant.
        static _property<Color, _readonly> Olive;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF6B8E23. This field is constant.
        static _property<Color, _readonly> OliveDrab;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFA500. This field is constant.
        static _property<Color, _readonly> Orange;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF4500. This field is constant.
        static _property<Color, _readonly> OrangeRed;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDA70D6. This field is constant.
        static _property<Color, _readonly> Orchid;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFEEE8AA. This field is constant.
        static _property<Color, _readonly> PaleGoldenrod;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF98FB98. This field is constant.
        static _property<Color, _readonly> PaleGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFAFEEEE. This field is constant.
        static _property<Color, _readonly> PaleTurquoise;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDB7093. This field is constant.
        static _property<Color, _readonly> PaleVioletRed;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFEFD5. This field is constant.
        static _property<Color, _readonly> PapayaWhip;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFDAB9. This field is constant.
        static _property<Color, _readonly> PeachPuff;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFCD853F. This field is constant.
        static _property<Color, _readonly> Peru;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFC0CB. This field is constant.
        static _property<Color, _readonly> Pink;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFDDA0DD. This field is constant.
        static _property<Color, _readonly> Plum;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFB0E0E6. This field is constant.
        static _property<Color, _readonly> PowderBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF800080. This field is constant.
        static _property<Color, _readonly> Purple;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF0000. This field is constant.
        static _property<Color, _readonly> Red;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFBC8F8F. This field is constant.
        static _property<Color, _readonly> RosyBrown;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF4169E1. This field is constant.
        static _property<Color, _readonly> RoyalBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF8B4513. This field is constant.
        static _property<Color, _readonly> SaddleBrown;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFA8072. This field is constant.
        static _property<Color, _readonly> Salmon;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF4A460. This field is constant.
        static _property<Color, _readonly> SandyBrown;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF2E8B57. This field is constant.
        static _property<Color, _readonly> SeaGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFF5EE. This field is constant.
        static _property<Color, _readonly> SeaShell;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFA0522D. This field is constant.
        static _property<Color, _readonly> Sienna;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFC0C0C0. This field is constant.
        static _property<Color, _readonly> Silver;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF87CEEB. This field is constant.
        static _property<Color, _readonly> SkyBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF6A5ACD. This field is constant.
        static _property<Color, _readonly> SlateBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF708090. This field is constant.
        static _property<Color, _readonly> SlateGray;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFAFA. This field is constant.
        static _property<Color, _readonly> Snow;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF00FF7F. This field is constant.
        static _property<Color, _readonly> SpringGreen;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF4682B4. This field is constant.
        static _property<Color, _readonly> SteelBlue;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD2B48C. This field is constant.
        static _property<Color, _readonly> Tan;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF008080. This field is constant.
        static _property<Color, _readonly> Teal;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8BFD8. This field is constant.
        static _property<Color, _readonly> Thistle;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFF6347. This field is constant.
        static _property<Color, _readonly> Tomato;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF40E0D0. This field is constant.
        static _property<Color, _readonly> Turquoise;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFEE82EE. This field is constant.
        static _property<Color, _readonly> Violet;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5DEB3. This field is constant.
        static _property<Color, _readonly> Wheat;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static _property<Color, _readonly> White;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF5F5F5. This field is constant.
        static _property<Color, _readonly> WhiteSmoke;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFF00. This field is constant.
        static _property<Color, _readonly> Yellow;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9ACD32. This field is constant.
        static _property<Color, _readonly> YellowGreen;
        
        /// @brief Create a new instance of class Color. The default value is Black.
        Color() = default;
        
        /// @cond
        Color(const Color& color) : argb(color.argb), knownColor(color.knownColor) {}
        Color& operator =(const Color& color) {
          this->argb = color.argb;
          this->knownColor = color.knownColor;
          return *this;
        }
        /// @endcond
        
        /// @brief Gets the alpha component value of this Color class.
        /// @return byte The alpha component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        _property<byte, _readonly> A {
          _get {return byte((this->argb & 0xFF000000) >> 24);}
        };
        
        /// @brief Gets the blue component value of this Color class.
        /// @return byte The blue component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        _property<byte, _readonly> B {
          _get {return byte(this->argb & 0x000000FF);}
        };
        
        /// @brief Gets the green component value of this Color class.
        /// @return byte The green component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        _property<byte, _readonly> G {
          _get {return byte((this->argb & 0x0000FF00) >> 8);}
        };
        
        /// @brief Gets the red component value of this Color class.
        /// @return byte The red component value of this Color.
        /// @remarks The color of each pixel is represented as a 32-bit number: 8 bits each for alpha, red, green, and blue (ARGB). The alpha component specifies the transparency of the color: 0 is fully transparent, and 255 is fully opaque. Likewise, an A value of 255 represents an opaque color. An A value from 1 through 254 represents a semitransparent color. The color becomes more opaque as A approaches 255.
        _property<byte, _readonly> R {
          _get {return byte((this->argb & 0x00FF0000) >> 16);}
        };
        
        /// @brief Gets the name of this Color.
        /// @return string The name of this Color.
        _property<string, _readonly> Name {
          _get {return this->GetName();}
        };
        
        /// @brief Specifies whether this Color class is uninitialized.
        /// @return bool Returns true if this color is uninitialized; otherwise, false.
        _property<bool, _readonly> IsEmpty {
          _get {return this->argb == 0 && this->knownColor == (KnownColor)0;}
        };
        
        /// @brief Gets a value indicating whether this Color structure is a predefined color. Predefined colors are represented by the elements of the KnownColor enumeration.
        /// @return bool Returns true if this Color was created from a predefined color by using either the FromName method or the FromKnownColor method; otherwise, false.
        _property<bool, _readonly> IsKnownColor {
          _get {return this->knownColor != (KnownColor)0;}
        };
        
        /// @brief Gets a value indicating whether this Color structure is a named color or a member of the KnownColor enumeration.
        /// @return bool Returns true if this Color was created by using either the FromName method or the FromKnownColor method; otherwise, false.
        _property<bool, _readonly> IsNamedColor {
          _get {return this->knownColor != (KnownColor)0;}
        };
        
        /// @brief Gets a value indicating whether this Color structure is a system color. A system color is a color that is used in a Windows display element. System colors are represented by elements of the KnownColor enumeration.
        /// @return bool Returns true if this Color was created from a system color by using either the FromName method or the FromKnownColor method; otherwise, false.
        _property<bool, _readonly> IsSystemColor {
          _get {return this->GetIsSystemColor();}
        };
        
        /// @brief Creates a Color class from a 32-bit ARGB value.
        /// @param argb A value specifying the 32-bit ARGB value
        /// @return Color The Color structure that this method creates.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromArgb(int32 argb) { return Color(argb); }
        
        /// @brief Creates a Color class from the specified name of a predefined color.
        /// @param name A string that is the name of a predefined color. Valid names are the same as the names of the elements of the KnownColor enumeration.
        /// @return Color The Color structure that this method creates.
        /// @remarks A predefined color is also called a known color and is represented by an element of the KnownColor enumeration. If the name parameter is not the valid name of a predefined color, the FromName method creates a Color structure that has an ARGB value of 0 (that is, all ARGB components are 0).
        static Color FromName(const string& name);
        
        /// @brief Creates a Color class from the specified Color structure, but with the new specified alpha value. Although this method allows a 32-bit value to be passed for the alpha value, the value is limited to 8 bits.
        /// @param alpha The alpha value for the new Color. Valid values are 0 through 255.
        /// @param baseColor The Color from which to create the new Color.
        /// @return Color The Color structure that this method creates.
        /// @exception ArgumentException alpha is less than 0 or greater than 255.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromArgb(int32 alpha, const Color& baseColor);
        
        /// @brief Creates a Color class from the four ARGB component (alpha, red, green, and blue) values. Although this method allows a 32-bit value to be passed for each component, the value of each component is limited to 8 bits.
        /// @param alpha The alpha value for the new Color. Valid values are 0 through 255.
        /// @param red The red component. Valid values are 0 through 255.
        /// @param green The green component. Valid values are 0 through 255.
        /// @param blue The blue component. Valid values are 0 through 255.
        /// @return Color The Color structure that this method creates.
        /// @exception ArgumentException alpha, red, green or blue is less than 0 or greater than 255.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromArgb(int32 alpha, int32 red, int32 green, int32 blue);
        
        /// @brief Creates a Color class from the four ARGB component (alpha, red, green, and blue) values. Although this method allows a 32-bit value to be passed for each component, the value of each component is limited to 8 bits.
        /// @param alpha The alpha value for the new Color. Valid values are 0 through 255.
        /// @param red The red component. Valid values are 0 through 255.
        /// @param green The green component. Valid values are 0 through 255.
        /// @param blue The blue component. Valid values are 0 through 255.
        /// @return Color The Color structure that this method creates.
        /// @exception ArgumentException alpha is less than 0 or greater than 255.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        static Color FromKnownColor(KnownColor color);
        
        /// @brief Gets the 32-bit ARGB value of this Color class.
        /// @return int32 The 32-bit ARGB value of this Color.
        /// @remarks The byte-ordering of the 32-bit ARGB value is AARRGGBB. The most significant byte (MSB), represented by AA, is the alpha component value. The second, third, and fourth bytes, represented by RR, GG, and BB, respectively, are the color components red, green, and blue, respectively.
        int32 ToArgb() const { return this->argb; }
        
        /// @brief Gets the KnownColor value of this Color class.
        /// @return KnownColor An element of the KnownColor enumeration, if the Color is created from a predefined color by using either the FromName method or the FromKnownColor method; otherwise, 0.
        /// @remarks A predefined color is also called a known color and is represented by an element of the KnownColor enumeration. When the ToKnownColor method is applied to a Color structure that is created by using the FromArgb method, ToKnownColor returns 0, even if the ARGB value matches the ARGB value of a predefined color. ToKnownColor also returns 0 when it is applied to a Color structure that is created by using the FromName method with a string name that is not valid.
        KnownColor ToKnownColor() const { return this->knownColor; }
        
        /// @brief Determines whether this instance of Int32 and a specified object, which must also be a Int32 object, have the same value.
        /// @param value The Int32 to compare with the current object.
        /// @return bool true if the specified value is equal to the current object. otherwise, false.
        bool Equals(const Color& value) const;
        
        /// @brief Determines whether this instance of Int32 and a specified object, which must also be a Int32 object, have the same value.
        /// @param obj The object to compare with the current object.
        /// @return bool true if the specified object is equal to the current object. otherwise, false.
        bool Equals(const object& obj) const override;
        
        /// @brief reates a human-readable string that represents this Size class.
        /// @return string A string that represents this Size.
        String ToString() const override;
        
        int32 CompareTo(const IComparable& obj) const override {
          if (!is<Color>(obj))
            return 1;
            
          return CompareTo(as<Color>(obj));
        }
        
        int32 CompareTo(const Color& color) const {return Int32(this->argb).CompareTo(color);}
        
        int32 GetHashCode() const override { return this->argb; }
        
      private :
        Color(int32 argb) : argb(argb), knownColor((KnownColor)0) {}
        Color(int32 argb, const KnownColor& color) : argb(argb), knownColor(color) {}
        
        bool GetIsSystemColor() const;
        string GetName() const;
        
        int32 argb = 0;
        KnownColor knownColor = (KnownColor)0;
      };
    }
  }
}
