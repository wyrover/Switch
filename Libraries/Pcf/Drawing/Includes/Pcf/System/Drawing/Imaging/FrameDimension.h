/// @file
/// @brief Contains Pcf::System::Drawing::Imaging::FrameDimension class.
#pragma once

#include <Pcf/System/Object.h>
#include <Pcf/System/String.h>
#include <Pcf/System/Guid.h>

namespace Pcf {
  namespace System {
    namespace Drawing {
      namespace Imaging {
        class FrameDimension : public object {
        public:
          static Property<FrameDimension, ReadOnly> Page;
          
          static Property<FrameDimension, ReadOnly> Resolution;
          
          static Property<FrameDimension, ReadOnly> Time;
          
          FrameDimension(const Guid& guid) : guid(guid) {}
          FrameDimension(const Guid& guid, const string name) : guid(guid), name(name) {}
          FrameDimension(const string& guid, const string name) : guid(guid), name(name) {}
          FrameDimension(const FrameDimension& fd) : guid(fd.guid), name(fd.name) {}
          
          Property<System::Guid, ReadOnly> Guid {
            pcf_get {return this->guid;}
          };
          
          Property<string, ReadOnly> Name {
            pcf_get {return this->name;}
          };

        private:
          System::Guid guid;
          string name;
        };
      }
    }
  }
}
