/// @file
/// @brief Contains Pcf::System::Drawing::SystemColors enum.
#pragma once

#include <Pcf/Static.h>
#include "Color.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief Each property of the System::Drawing::SystemColors class is a System::Drawing::Color structure that is the color of a Windows display element.
      /// @remarks Better performance is achieved by using the properties of the System::Drawing::SystemPens or System::Drawing::SystemBrushes classes rather than creating a new pen or brush based on a value from System::Drawing::SystemColors. For example, if you wanted to get a brush for the face color of a 3-D element, use the SystemBrushes.Control property because it gets a brush that already exists, whereas calling the SolidBrush.#ctor(Color) constructor with a parameter value of SystemColors::Control will create a new brush.
      class pcf_public SystemColors pcf_static {
      public:
        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static Property<Color, ReadOnly> ActiveBorder;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF0054E3. This field is constant.
        static Property<Color, ReadOnly> ActiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static Property<Color, ReadOnly> ActiveCaptionText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
        static Property<Color, ReadOnly> AppWorkspace;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static Property<Color, ReadOnly> Control;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static Property<Color, ReadOnly> ControlDark;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF716F64. This field is constant.
        static Property<Color, ReadOnly> ControlDarkDark;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFF1EFE2. This field is constant.
        static Property<Color, ReadOnly> ControlLight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static Property<Color, ReadOnly> ControlLightLight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static Property<Color, ReadOnly> ControlText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF004E98. This field is constant.
        static Property<Color, ReadOnly> Desktop;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static Property<Color, ReadOnly> GrayText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
        static Property<Color, ReadOnly> Highlight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static Property<Color, ReadOnly> HighlightText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
        static Property<Color, ReadOnly> HotTrack;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static Property<Color, ReadOnly> InactiveBorder;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF7A96DF. This field is constant.
        static Property<Color, ReadOnly> InactiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8E4F8. This field is constant.
        static Property<Color, ReadOnly> InactiveCaptionText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE1. This field is constant.
        static Property<Color, ReadOnly> Info;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static Property<Color, ReadOnly> InfoText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static Property<Color, ReadOnly> Menu;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static Property<Color, ReadOnly> MenuText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
        static Property<Color, ReadOnly> ScrollBar;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static Property<Color, ReadOnly> Window;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static Property<Color, ReadOnly> WindowFrame;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
        static Property<Color, ReadOnly> WindowText;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static Property<Color, ReadOnly> ButtonFace;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
        static Property<Color, ReadOnly> ButtonHighlight;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
        static Property<Color, ReadOnly> ButtonShadow;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF3D95FF. This field is constant.
        static Property<Color, ReadOnly> GradientActiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF9DB9EB. This field is constant.
        static Property<Color, ReadOnly> GradientInactiveCaption;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
        static Property<Color, ReadOnly> MenuBar;

        /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
        static Property<Color, ReadOnly> MenuHighlight;
      };
    }
  }
}