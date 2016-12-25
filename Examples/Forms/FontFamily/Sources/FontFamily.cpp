#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace FontFamilyExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "FontFamily example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(400, 500);
      
      this->labelNbFontFamlies.Parent = *this;
      this->labelNbFontFamlies.AutoSize = true;
      this->labelNbFontFamlies.Location = System::Drawing::Point(20, 20);
      
      this->listBoxFontFamilies.Parent = *this;
      this->listBoxFontFamilies.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->listBoxFontFamilies.Bounds = System::Drawing::Rectangle(20, 60, 360, 420);
      //this->listBoxFontFamilies.Sorted = true;
      
      Array<Drawing::FontFamily> fontFamilies = Drawing::FontFamily::Families;
      this->labelNbFontFamlies.Text = string::Format("There are {0} FontFamilies :", fontFamilies.Length);
      for (Drawing::FontFamily fontFamily : fontFamilies)
        this->listBoxFontFamilies.Items().Add(fontFamily.Name());
    }
    
  private:
    Label labelNbFontFamlies;
    ListBox listBoxFontFamilies;
  };
}

pcf_startup (FontFamilyExample::Form1)
