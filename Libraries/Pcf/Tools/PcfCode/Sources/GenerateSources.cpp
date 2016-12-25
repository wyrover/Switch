#include <Core/Foreach.h>
#include "../Includes/GenerateSources.h"

using namespace Pcf;
using namespace Pcf::System;
using namespace Pcf::System::Drawing;
using namespace Pcf::System::Windows;
using namespace Pcf::System::Windows::Forms;
using namespace Pcf::PcfCode;
using namespace Pcf::PcfCode::Generation;

struct CommonParam : public object {
  CommonParam(const string& type, const string& name, const System::Drawing::Rectangle& bounds, const string& text) : Type(type), Name(name), Bounds(bounds), Text(text) {}
  CommonParam(const CommonParam& cp) : Type(cp.Type), Name(cp.Name), Bounds(cp.Bounds), Text(cp.Text) {}
  string Type;
  string Name;
  System::Drawing::Rectangle Bounds;
  string Text;
};

CppFileWriter::CppFileWriter(const System::Collections::Generic::IEnumerable<Sp<System::Windows::Forms::Control> >& controls) : controls(controls) {
}

string CppFileWriter::Generate() {
  System::Collections::Generic::List<CommonParam> commonParams;
  System::Collections::Generic::List<string> instances;
  System::Collections::Generic::List<string> variables;

  foreach(Sp<System::Windows::Forms::Control>, control, this->controls) {
    commonParams.Add(CommonParam(control->GetType().ToString(), control->Name(), control->Bounds(), control->Text()));
    variables.Add(string::Format("Up<{0}> {1};", control->GetType(), control->Name()));
    instances.Add(string::Format("this->{0} = new {1}();", control->Name(), control->GetType()));

    if (Is<System::Windows::Forms::Button>(*control)) {
      PropertiesReader<Pcf::System::Windows::Forms::Button> pr(To<System::Windows::Forms::Button>(*control));
    }
  }

  this->content = "#pragma PcfGeneratingCode\n\nprivate:\n  void InitializeComponent() {\n";
  foreach(CommonParam, cp, commonParams) {
    this->content = string::Format("{0}    this->{1} = new {2}();\n", this->content, cp.Name, cp.Type);
    this->content = string::Format("{0}    this->{1}->Name(\"{1}\");\n", this->content, cp.Name);
    this->content = string::Format("{0}    this->{1}->Bounds({2}, {3}, {4}, {5});\n", this->content, cp.Name, cp.Bounds.X(), cp.Bounds.Y(), cp.Bounds.Width(), cp.Bounds.Height());
    this->content = string::Format("{0}    this->{1}->Text(\"{2}\");\n", this->content, cp.Name, cp.Text);

    this->content = string::Format("{0}\n", this->content);
  }
  
  this->content = string::Format("{0}  }}\n\n", this->content);
 
  foreach(string, var, variables)
    this->content = string::Format("{0}  {1}\n", this->content, var);

  this->content = string::Format("{0}\n#pragma EndPcfGeneratingCode\n\n", this->content);
  return this->content;
}


CppFileWriter CppFileWriter::FromControls(const System::Collections::Generic::IEnumerable<Sp<System::Windows::Forms::Control> >& controls) {
  CppFileWriter writer(controls);
  
  return writer;
}