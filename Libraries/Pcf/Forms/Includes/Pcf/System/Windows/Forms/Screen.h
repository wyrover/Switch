/// @file
/// @brief Contains Pcf::System::Windows::Forms::Screen class.
#pragma once

#include <Pcf/System/Object.h>
#include <Pcf/Property.h>
#include <Pcf/System/Array.h>
#include <Pcf/System/Drawing/Rectangle.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        class Screen : public object {
        public:
          static Property<System::Array<Screen>, ReadOnly> AllScreens;

          Property<int32, ReadOnly> BitsPerPixel {
            pcf_get {return this->bitsPerPixel;}
          };

          Property<const System::Drawing::Rectangle&, ReadOnly> Bounds {
            pcf_get->const System::Drawing::Rectangle& {return this->bounds;}
          };

          Property<const string&, ReadOnly> DeviceName {
            pcf_get->const string& {return this->deviceName;}
          };

          Property<bool, ReadOnly> Primary {
            pcf_get {return this->primary;}
          };

          Property<const System::Drawing::Rectangle&, ReadOnly> WorkingArea {
            pcf_get->const System::Drawing::Rectangle& {return this->workingArea;}
          };

          /// @cond
          static System::Array<Screen> __AllScreens__();
          /// @endcond

        protected:
          friend class Array<Screen>;
          friend class Allocator<Screen>;
          Screen() {}
          Screen(const Screen& screen) : bitsPerPixel(screen.bitsPerPixel), bounds(screen.bounds), deviceName(screen.deviceName), primary(screen.primary), workingArea(screen.workingArea) {}

          int32 bitsPerPixel = 0;
          System::Drawing::Rectangle bounds;
          string deviceName;
          bool primary = false;
          System::Drawing::Rectangle workingArea;
        };
      }
    }
  }
}
