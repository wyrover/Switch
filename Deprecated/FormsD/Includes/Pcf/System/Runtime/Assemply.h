#pragma once

#nclude <Corelib.h>

namespace Pcf {
  namespace System {
    namespace Runtime {
      class Assembly : public object {
      public:

        string GetTitle() const {
          return this->title;
        }

        string GetDescription() const {
          return this->description;
        }

        string GetConfiguration() const {
          return this->configuration;
        }

        string
      private:
        string title;
        string description;
        string configuration;
        string company;
        string product;
        string copyright;
        string trademark;
        string culture;
        Version version;
      };
    }
  }
}
