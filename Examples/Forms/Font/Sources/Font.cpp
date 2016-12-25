#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace FontExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Font example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(680, 440);
      
      this->panelSample.Parent = *this;
      this->panelSample.BorderStyle = BorderStyle::Fixed3D;
      this->panelSample.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right;
      this->panelSample.Bounds = System::Drawing::Rectangle(20, 20, 640, 160);
      this->panelSample.BackColor = Drawing::Color::White;
      
      this->labelSample.Parent = this->panelSample;
      this->labelSample.AutoSize = true;
      this->labelSample.Location = System::Drawing::Point(5, 5);
      
      this->labelFontFamlies.Parent = *this;
      this->labelFontFamlies.Location = System::Drawing::Point(20, 200);
      this->labelFontFamlies.Text = "Font:";
      
      this->listBoxFontFamilies.Parent = *this;
      this->listBoxFontFamilies.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->listBoxFontFamilies.Bounds = System::Drawing::Rectangle(20, 220, 380, 200);
      this->listBoxFontFamilies.Click += {*this, &Form1::OnFontClick};
      
      this->labelFontStyle.Parent = *this;
      this->labelFontStyle.Anchor = AnchorStyles::Top | AnchorStyles::Right;
      this->labelFontStyle.Location = System::Drawing::Point(410, 200);
      this->labelFontStyle.Text = "Font style:";
      
      this->listBoxFontStyle.Parent = *this;
      this->listBoxFontStyle.Anchor = AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->listBoxFontStyle.Bounds = System::Drawing::Rectangle(410, 220, 120, 200);
      this->listBoxFontStyle.Click += {*this, &Form1::OnFontClick};
      
      this->labelFontSize.Parent = *this;
      this->labelFontSize.Anchor = AnchorStyles::Top | AnchorStyles::Right;
      this->labelFontSize.Location = System::Drawing::Point(540, 200);
      this->labelFontSize.Text = "Size:";
      
      this->listBoxSize.Parent = *this;
      this->listBoxSize.Anchor = AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->listBoxSize.Bounds = System::Drawing::Rectangle(540, 220, 120, 200);
      this->listBoxSize.Click += {*this, &Form1::OnFontClick};
      
      for (Drawing::FontFamily family : Drawing::FontFamily::Families())
        this->listBoxFontFamilies.Items().Add(string::Format("@F{0}@.{1}", System::Drawing::Font(family).ToHFont(), family.Name));
      this->listBoxFontFamilies.SelectedIndex = 30;
      
      this->listBoxFontStyle.Items().Add("@.Regular");
      this->listBoxFontStyle.Items().Add("@b@.Bold");
      this->listBoxFontStyle.Items().Add("@i@.Italic");
      this->listBoxFontStyle.Items().Add("@b@i@.Bold, Italic");
      this->listBoxFontStyle.SelectedIndex = 0;
      
      this->listBoxSize.Items().AddRange({"8", "9", "10", "11", "12", "14", "16", "18", "20", "22", "24", "26", "28", "36", "48", "72"});
      this->listBoxSize.SelectedIndex = 4;
      
      this->labelSample.Text = string::Format("The quick brown fox jumps over the lazy dog.\n"
                                              "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
                                              "0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
                                              "àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
                                              "{u400}{u401}{u402}{u403}{u404}{u405}{u406}{u407}{u408}{u409}{u40a}{u40b}{u40c}{u40d}{u40e}{u40f}\n"
                                              "{u410}{u411}{u412}{u413}{u414}{u415}{u416}{u417}{u418}{u419}{u41a}{u41b}{u41c}{u41d}{u41e}{u41f}\n"
                                              "{u4ea0}{u4ea1}{u4ea2}{u4ea3}{u4ea4}{u4ea5}{u4ea6}{u4ea7}{u4ea8}{u4ea9}{u4eaa}{u4eab}{u4eac}{u4ead}{u4eae}{u4eaf}\n"
                                              "{u4eb0}{u4eb1}{u4eb2}{u4eb3}{u4eb4}{u4eb5}{u4eb6}{u4eb7}{u4eb8}{u4eb9}{u4eba}{u4ebb}{u4ebc}{u4ebd}{u4ebe}{u4ebf}\n"
                                              "{u1F428}");
    }
    
  private:
    void OnFontClick(const object& sender, const EventArgs& e) {
      string fontName = ((const string&)*this->listBoxFontFamilies.SelectedItem()).Remove(0, ((const string&)*this->listBoxFontFamilies.SelectedItem()).IndexOf("@.")+2);
      Drawing::FontStyle fontStyle = (System::Drawing::FontStyle)Enum<Drawing::FontStyle>::Parse(((const string&)*this->listBoxFontStyle.SelectedItem()).Remove(0, ((const string&)*this->listBoxFontStyle.SelectedItem()).IndexOf("@.")+2));
      float size = Single::Parse((const string&)*this->listBoxSize.SelectedItem());
      this->labelSample.Font = System::Drawing::Font(fontName, size, fontStyle);
    }
    
    Panel panelSample;
    Label labelSample;
    Label labelFontFamlies;
    Label labelFontStyle;
    Label labelFontSize;
    ListBox listBoxFontFamilies;
    ListBox listBoxFontStyle;
    ListBox listBoxSize;
  };
}

pcf_startup (FontExample::Form1)
