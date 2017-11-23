/// @file
/// @brief Contains Switch::System::Drawing::SystemColors enum.
#pragma once

#include <Switch/Static.hpp>
#include "Color.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Each property of the System::Drawing::SystemColors class is a System::Drawing::Color structure that is the color of a Windows display element.
      /// @remarks Better performance is achieved by using the properties of the System::Drawing::SystemPens or System::Drawing::SystemBrushes classes rather than creating a new pen or brush based on a value from System::Drawing::SystemColors. For example, if you wanted to get a brush for the face color of a 3-D element, use the SystemBrushes.Control property because it gets a brush that already exists, whereas calling the SolidBrush.#ctor(Color) constructor with a parameter value of SystemColors::Control will create a new brush.
      /// @par Library
      /// Switch.System.Drawing
      class _export SystemColors _static {
      public:
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static _property<Color, _readonly> ActiveBorder;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF0054E3. This field is constant.
        static _property<Color, _readonly> ActiveCaption;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static _property<Color, _readonly> ActiveCaptionText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
        static _property<Color, _readonly> AppWorkspace;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static _property<Color, _readonly> Control;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static _property<Color, _readonly> ControlDark;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF716F64. This field is constant.
        static _property<Color, _readonly> ControlDarkDark;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF1EFE2. This field is constant.
        static _property<Color, _readonly> ControlLight;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static _property<Color, _readonly> ControlLightLight;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static _property<Color, _readonly> ControlText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF004E98. This field is constant.
        static _property<Color, _readonly> Desktop;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static _property<Color, _readonly> GrayText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
        static _property<Color, _readonly> Highlight;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static _property<Color, _readonly> HighlightText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
        static _property<Color, _readonly> HotTrack;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static _property<Color, _readonly> InactiveBorder;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7A96DF. This field is constant.
        static _property<Color, _readonly> InactiveCaption;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8E4F8. This field is constant.
        static _property<Color, _readonly> InactiveCaptionText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE1. This field is constant.
        static _property<Color, _readonly> Info;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static _property<Color, _readonly> InfoText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static _property<Color, _readonly> Menu;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static _property<Color, _readonly> MenuText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static _property<Color, _readonly> ScrollBar;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static _property<Color, _readonly> Window;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static _property<Color, _readonly> WindowFrame;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static _property<Color, _readonly> WindowText;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static _property<Color, _readonly> ButtonFace;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static _property<Color, _readonly> ButtonHighlight;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static _property<Color, _readonly> ButtonShadow;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF3D95FF. This field is constant.
        static _property<Color, _readonly> GradientActiveCaption;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9DB9EB. This field is constant.
        static _property<Color, _readonly> GradientInactiveCaption;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static _property<Color, _readonly> MenuBar;
        
        /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
        static _property<Color, _readonly> MenuHighlight;
      };
    }
  }
}
