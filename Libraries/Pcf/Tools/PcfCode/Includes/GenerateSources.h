#include <Corelib.h>
#include <Forms/System/Windows/Forms/Control.h>
#include <Forms/System/Windows/Forms/Button.h>

namespace Pcf {
  namespace PcfCode {
    namespace Generation {
      template <typename T>
      class PropertiesReader : public object {
      public:
        PropertiesReader(const T& value) {
        }
      };
      
      template <>
      class PropertiesReader<System::Windows::Forms::Control> : public object {
      public:
        PropertiesReader(const System::Windows::Forms::Control& value) : value(&value) {
        }
        
        string Name() const {return this->value->Name();}
        string Text() const {return this->value->Text();}

        const System::Windows::Forms::Control* value;
      };
      
      template<>
      class PropertiesReader<System::Windows::Forms::Button> : public PropertiesReader<System::Windows::Forms::Control> {
      public:
        PropertiesReader(const System::Windows::Forms::Button& value) : PropertiesReader<System::Windows::Forms::Control>(value) {
        }
      };
      
      class CppFileWriter : public object {
        CppFileWriter(const System::Collections::Generic::IEnumerable<Sp<System::Windows::Forms::Control> >& controls);
        
      public:
        static CppFileWriter FromControls(const System::Collections::Generic::IEnumerable<Sp<System::Windows::Forms::Control> >& controls);
        
        string Generate();
        
      private:
        System::Collections::Generic::List<Sp<System::Windows::Forms::Control> > controls;
        string content;
      };
    }
  }
}
