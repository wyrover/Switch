/// @file
/// @brief Contains Pcf::System::Windows::Forms::ImageList class.
#pragma once

#include <Pcf/System/Tuple.h>
#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/System/Drawing/Image.h>

#include "../../ComponentModel/Component.h"
#include "Control.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        class ImageList : public System::ComponentModel::Component {
        public:
          using ImagePair = System::Tuple<Pcf::System::Drawing::Image, Pcf::System::Drawing::Image>;
          
          class ImageCollection {
          public:
            ImageCollection() {}

            virtual void Add(const Pcf::System::Drawing::Image& value) {this->AddImage(const_cast<Pcf::System::Drawing::Image&>(value));}

            virtual bool Remove(const Pcf::System::Drawing::Image& value) {return this->RemoveImage(const_cast<Pcf::System::Drawing::Image&>(value));}

            void AddImage(Pcf::System::Drawing::Image& image) {images.Add(ImagePair(image, image));}

            Property<int32, ReadOnly> Count {
              pcf_get {return this->images.Count();}
            };

            bool RemoveImage(Pcf::System::Drawing::Image& image) {return images.Remove(ImagePair(image, image));}

            const System::Drawing::Image& operator[](int32 index) const {return this->images[index].Item1;}

            Pcf::System::Collections::Generic::List<ImagePair> images;
          };

          ImageList();

          /// @cond
          ~ImageList();
          /// @endcond

          Property<ImageCollection&, ReadOnly> Images {
            pcf_get->ImageCollection& {return this->images;}
          };

        private:
          ImageCollection images;
          System::Drawing::Size size;
        };
      }
    }
  }
}
