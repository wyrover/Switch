#include <Pcf/Pcf>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Form1 : public Form {
public:
  Form1() {
    this->Text = "Button Manual Tests";
    this->Left = 400;
    this->Top = 300;
    this->Width = 640;
    this->Height = 480;
    this->SizeChanged += [&](const object& sender, const EventArgs& args) {};
    
    this->buttonEnabled.Parent = *this;
    this->buttonEnabled.Enabled = true;
    this->buttonEnabled.Text = "Enabled";
    this->buttonEnabled.Left = 85;
    this->buttonEnabled.Top = 5;
    this->buttonEnabled.Click += [&](const object& sender, const EventArgs& args) {};
    
    this->buttonDisabled.Parent = *this;
    this->buttonDisabled.Enabled = false;
    this->buttonDisabled.Text = "Desabled";
    this->buttonDisabled.Left = 165;
    this->buttonDisabled.Top = 5;
    this->buttonEnabled.Click += [&](const object& sender, const EventArgs& args) {};

    this->buttonColored.Parent = *this;
    this->buttonColored.BackColor = SystemColors::Highlight;
    this->buttonColored.ForeColor = Color::White;
    this->buttonColored.Text = "Colored";
    this->buttonColored.Left = 245;
    this->buttonColored.Top = 5;
    
    this->buttonAutosizeActivated.Parent = *this;
    this->buttonAutosizeActivated.AutoSize = true;
    this->buttonAutosizeActivated.Text = "Auto size activated";
    this->buttonAutosizeActivated.Left = 325;
    this->buttonAutosizeActivated.Top = 5;
    
    this->buttonResized.Parent = *this;
    this->buttonResized.Text = "Resized with a very long message that contained in the current button";
    this->buttonResized.Left = 5;
    this->buttonResized.Top = 35;
    this->buttonResized.Width = this->buttonResized.Width * 2;
    this->buttonResized.Height = this->buttonResized.Height * 2;

    this->buttonWithAnchorTopBottomLRight.Parent = *this;
    this->buttonWithAnchorTopBottomLRight.Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Bottom | AnchorStyles::Right;
    this->buttonWithAnchorTopBottomLRight.Text = "AnchorTBLR\nA new Line";
    this->buttonWithAnchorTopBottomLRight.Left = 5;
    this->buttonWithAnchorTopBottomLRight.Top = 90;
    this->buttonWithAnchorTopBottomLRight.Width = 630;
    this->buttonWithAnchorTopBottomLRight.Height = 350;
    
    this->buttonWithAnchorTopLeft.Parent = *this;
    this->buttonWithAnchorTopLeft.Anchor = AnchorStyles::Top | AnchorStyles::Left;
    this->buttonWithAnchorTopLeft.Text = "AnchorTL";
    this->buttonWithAnchorTopLeft.Left = 5;
    this->buttonWithAnchorTopLeft.Top = 5;
    
    this->buttonWithAnchorTopRight.Parent = *this;
    this->buttonWithAnchorTopRight.Anchor = AnchorStyles::Top | AnchorStyles::Right;
    this->buttonWithAnchorTopRight.Text = "AnchorTR";
    this->buttonWithAnchorTopRight.Left = 560;
    this->buttonWithAnchorTopRight.Top = 5;
    
    this->buttonWithAnchorBottomLeft.Parent = *this;
    this->buttonWithAnchorBottomLeft.Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
    this->buttonWithAnchorBottomLeft.Text = "AnchorBL";
    this->buttonWithAnchorBottomLeft.Left = 5;
    this->buttonWithAnchorBottomLeft.Top = 447;
    
    this->buttonWithAnchorBottomRight.Parent = *this;
    this->buttonWithAnchorBottomRight.Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
    this->buttonWithAnchorBottomRight.Text = "AnchorBR";
    this->buttonWithAnchorBottomRight.Left = 560;
    this->buttonWithAnchorBottomRight.Top = 447;
  }
  
private:
  Button buttonEnabled;
  Button buttonDisabled;
  Button buttonColored;
  Button buttonAutosizeActivated;
  Button buttonResized;
  Button buttonWithAnchorTopBottomLRight;
  Button buttonWithAnchorTopLeft;
  Button buttonWithAnchorTopRight;
  Button buttonWithAnchorBottomLeft;
  Button buttonWithAnchorBottomRight;
};

int main(int argc, char* argv[]) {
  Application::EnableVisualStyles();
  Application::Run(Form1());
}

