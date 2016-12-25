#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace ColorsExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Colors example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 420);
      
      this->panelKnownColors.Parent = *this;
      this->panelKnownColors.Location = System::Drawing::Point(10, 10);
      this->panelKnownColors.Size = System::Drawing::Size(300, 400);
      this->panelKnownColors.BorderStyle = BorderStyle::Fixed3D;
      this->panelKnownColors.BackColor = System::Drawing::SystemColors::Window;
      
      int index = 0;
      for (System::Drawing::KnownColor knownColor : Enum<System::Drawing::KnownColor>::GetValues()) {
        sp<Panel> panelKnownColor = sp<Panel>::Create();
        items.Add(as<Control>(panelKnownColor));
        panelKnownColor->Parent = this->panelKnownColors;
        panelKnownColor->Bounds = System::Drawing::Rectangle(10, index * 30, 100, 30);
        panelKnownColor->BackColor = System::Drawing::Color::FromKnownColor(knownColor);
        panelKnownColor->Click += {*this, &Form1::OnKnownColorClick};
        
        sp<Label> labelKnownColorName = sp<Label>::Create();
        items.Add(as<Control>(labelKnownColorName));
        labelKnownColorName->Parent = this->panelKnownColors;
        labelKnownColorName->AutoSize = true;
        labelKnownColorName->Location = System::Drawing::Point(120, index * 30 + 10);
        labelKnownColorName->Text = Enum<System::Drawing::KnownColor>(knownColor).ToString();
        labelKnownColorName->Click += {*this, &Form1::OnKnownColorNameClick};
        ++index;
      }
      
      this->panelUserDefinedColor.Parent = *this;
      this->panelUserDefinedColor.Location = System::Drawing::Point(330, 10);
      this->panelUserDefinedColor.Size = System::Drawing::Size(300, 400);
      this->panelUserDefinedColor.BorderStyle = BorderStyle::Fixed3D;
      
      this->labelRed.Parent = this->panelUserDefinedColor;
      this->labelRed.Location = System::Drawing::Point(90, 35);
      this->labelRed.AutoSize = true;
      this->labelRed.Text = "Red";
      
      this->numericUpDownRed.Parent = this->panelUserDefinedColor;
      this->numericUpDownRed.Bounds = System::Drawing::Rectangle(150, 32, 50, 20);
      this->numericUpDownRed.Minimum = 0;
      this->numericUpDownRed.Maximum = 255;
      this->numericUpDownRed.ValueChanged += {*this, &Form1::OnArgbChanged};
      
      this->labelGreen.Parent = this->panelUserDefinedColor;
      this->labelGreen.Location = System::Drawing::Point(90, 65);
      this->labelGreen.AutoSize = true;
      this->labelGreen.Text = "Green";
      
      this->numericUpDownGreen.Parent = this->panelUserDefinedColor;
      this->numericUpDownGreen.Minimum = 0;
      this->numericUpDownGreen.Maximum = 255;
      this->numericUpDownGreen.Bounds = System::Drawing::Rectangle(150, 62, 50, 20);
      this->numericUpDownGreen.ValueChanged += {*this, &Form1::OnArgbChanged};
      
      this->labelBlue.Parent = this->panelUserDefinedColor;
      this->labelBlue.Location = System::Drawing::Point(90, 95);
      this->labelBlue.AutoSize = true;
      this->labelBlue.Text = "Blue";
      
      this->numericUpDownBlue.Parent = this->panelUserDefinedColor;
      this->numericUpDownBlue.Minimum = 0;
      this->numericUpDownBlue.Maximum = 255;
      this->numericUpDownBlue.Bounds = System::Drawing::Rectangle(150, 92, 50, 20);
      this->numericUpDownBlue.ValueChanged += {*this, &Form1::OnArgbChanged};
      
      this->panelColorBox.Parent = this->panelUserDefinedColor;
      this->panelColorBox.Bounds = System::Drawing::Rectangle(50, 150, 200, 200);
      this->panelColorBox.BackColor = System::Drawing::Color::FromArgb(255, this->numericUpDownRed.Value, this->numericUpDownGreen.Value, this->numericUpDownBlue.Value);
      this->panelColorBox.BorderStyle = BorderStyle::Fixed3D;
    }
    
    void OnKnownColorClick(const object& sender, const EventArgs& e) {
      System::Drawing::Color color = as<Panel>(sender).BackColor;
      this->numericUpDownRed.Value = color.R;
      this->numericUpDownGreen.Value = color.G;
      this->numericUpDownBlue.Value = color.B;
    }
    
    void OnKnownColorNameClick(const object& sender, const EventArgs& e) {
      System::Drawing::Color color = System::Drawing::Color::FromName(as<Label>(sender).Text);
      this->numericUpDownRed.Value = color.R;
      this->numericUpDownGreen.Value = color.G;
      this->numericUpDownBlue.Value = color.B;
    }
    
    void OnArgbChanged(const object& sender, const EventArgs& e) {
      this->panelColorBox.BackColor = System::Drawing::Color::FromArgb(255, this->numericUpDownRed.Value, this->numericUpDownGreen.Value, this->numericUpDownBlue.Value);
    }
    
  private:
    Panel panelKnownColors;
    System::Collections::Generic::List<sp<Control>> items;
    Panel panelUserDefinedColor;
    Label labelRed;
    Label labelGreen;
    Label labelBlue;
    NumericUpDown numericUpDownRed;
    NumericUpDown numericUpDownGreen;
    NumericUpDown numericUpDownBlue;
    Panel panelColorBox;
  };
}

pcf_startup (ColorsExample::Form1)
