#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace Calculator {
  class FormMain : public Form {
    enum class Operator {
      None = -1,
      Divide,
      Multiply,
      Subtract,
      Add,
      Equal
    };

  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(FormMain());
    }

    FormMain() {
      this->Text = "Calculator";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(325, 220);
      this->BackColor = System::Drawing::Color::Gray;
      this->KeyPreview = true;
      this->KeyPress += KeyPressEventHandler(*this, &FormMain::FormMainKeyPress);

      this->result.Parent = *this;
      this->result.Bounds = System::Drawing::Rectangle(5, 5, 315, 60);
      this->result.Font = System::Drawing::Font(System::Drawing::FontFamily::GenericMonospace().Name, 36, System::Drawing::FontStyle::Regular);
      this->result.TextAlign = System::Drawing::ContentAlignment::MiddleRight;
      this->result.ForeColor = System::Drawing::Color::White;
      this->result.Text = "0";
      
      this->buttonClear.Parent = *this;
      this->buttonClear.Location = System::Drawing::Point(5, 70);
      this->buttonClear.BackColor = System::Drawing::Color::LightGray;
      this->buttonClear.Text = "AC";
      this->buttonClear.Click += EventHandler(*this, &FormMain::ButtonClearClick);
      
      this->buttonPlusMinus.Parent = *this;
      this->buttonPlusMinus.Location = System::Drawing::Point(85, 70);
      this->buttonPlusMinus.BackColor = System::Drawing::Color::LightGray;
      this->buttonPlusMinus.Text = "±";
      this->buttonPlusMinus.Click += EventHandler(*this, &FormMain::ButtonPlusMinusClick);
      
      this->buttonPercent.Parent = *this;
      this->buttonPercent.Location = System::Drawing::Point(165, 70);
      this->buttonPercent.BackColor = System::Drawing::Color::LightGray;
      this->buttonPercent.Text = "%";
      this->buttonPercent.Click += EventHandler(*this, &FormMain::ButtonPercentClick);
      
      this->buttonDecimal.Parent = *this;
      this->buttonDecimal.Location = System::Drawing::Point(165, 190);
      this->buttonDecimal.BackColor = System::Drawing::Color::Gainsboro;
      this->buttonDecimal.Text = ",";
      this->buttonDecimal.Click += EventHandler(*this, &FormMain::ButtonNumberClick);
      
      Array<System::Drawing::Point> buttonNumberLocations = {{5, 190}, {5, 160}, {85, 160}, {165, 160}, {5, 130}, {85, 130}, {165, 130}, {5, 100}, {85, 100}, {165, 100}};
      for (int i = 0; i < this->buttonNumbers.Count; i++) {
        this->buttonNumbers[i].Parent = *this;
        this->buttonNumbers[i].BackColor = System::Drawing::Color::Gainsboro;
        this->buttonNumbers[i].Text = string::Format("{0}", i);
        this->buttonNumbers[i].Location = buttonNumberLocations[i];
        this->buttonNumbers[i].Click += EventHandler(*this, &FormMain::ButtonNumberClick);
      }
      this->buttonNumbers[0].Width = 155;
      
      Array<string> buttonOperatorTexts = {"/", "X", "-", "+", "="};
      Array<System::Drawing::Point> buttonOperatorLocations = {{245, 70}, {245, 100}, {245, 130}, {245, 160}, {245, 190}};
      for (int i = 0; i < this->buttonOperators.Count; i++) {
        this->buttonOperators[i].Parent = *this;
        this->buttonOperators[i].BackColor = System::Drawing::Color::DarkOrange;
        this->buttonOperators[i].ForeColor = System::Drawing::Color::White;
        this->buttonOperators[i].Text = buttonOperatorTexts[i];
        this->buttonOperators[i].Location = buttonOperatorLocations[i];
        this->buttonOperators[i].Click += EventHandler(*this, &FormMain::ButtonOperatorClick);
      }
    }
    
    void FormMainKeyPress(const object& sender, KeyPressEventArgs& e) {
      if (e.KeyChar >= '0' && e.KeyChar <= '9') {
        this->ButtonNumberClick(this->buttonNumbers[e.KeyChar - '0'], e);
        e.Handled = true;
        return;
      }
      switch (e.KeyChar) {
        case 'c' : this->ButtonClearClick(this->buttonClear, e); e.Handled = true; break;
        case 'C' : this->ButtonClearClick(this->buttonClear, e); e.Handled = true; break;
        case '%' : this->ButtonPercentClick(this->buttonPercent, e); e.Handled = true; break;
        case ',' : this->ButtonNumberClick(this->buttonDecimal,e); e.Handled = true; break;
        case '.' : this->ButtonNumberClick(this->buttonDecimal, e); e.Handled = true; break;
        case '/' : this->ButtonOperatorClick(this->buttonOperators[(int)Operator::Divide], e); e.Handled = true; break;
        case '*' : this->ButtonOperatorClick(this->buttonOperators[(int)Operator::Multiply], e); e.Handled = true; break;
        case '-' : this->ButtonOperatorClick(this->buttonOperators[(int)Operator::Subtract], e); e.Handled = true; break;
        case '+' : this->ButtonOperatorClick(this->buttonOperators[(int)Operator::Add], e); e.Handled = true; break;
        case '=' : this->ButtonOperatorClick(this->buttonOperators[(int)Operator::Equal], e); e.Handled = true; break;
        case 13 : this->ButtonOperatorClick(this->buttonOperators[(int)Operator::Equal], e); e.Handled = true; break;
        case 127 : this->BackSpaceKeyPress(this->buttonOperators[(int)Operator::Equal], e); e.Handled = true; break;
      }
    }
    
    void BackSpaceKeyPress(const object& sender, const EventArgs& e) {
      if (this->result.Text().Length > 0)
        this->result.Text = this->result.Text().Remove(this->result.Text().Length-1);
      if (this->result.Text().Length == 0 || this->result.Text == "-")
        ButtonClearClick(sender, e);
    }
    
    void ButtonClearClick(const object& sender, const EventArgs& e) {
      this->result.Text = "0";
      this->firstOperand = .0f;
      this->operation = Operator::None;
      this->resetResult = true;
    }
    
    void ButtonPercentClick(const object& sender, const EventArgs& e) {
      this->result.Text = Double(Double::Parse(this->result.Text().Replace(',', '.')) / 100).ToString().Replace('.', ',');
    }
    
    void ButtonPlusMinusClick(const object& sender, const EventArgs& e) {
      this->result.Text = Double(-Double::Parse(this->result.Text().Replace(',', '.'))).ToString().Replace('.', ',');
    }
    
    void ButtonNumberClick(const object& sender, const EventArgs& e) {
      if (object::ReferenceEquals(sender, this->buttonDecimal) && this->result.Text().Contains(","))
        return;
      if (object::ReferenceEquals(sender, this->buttonNumbers[0]) && !this->result.Text().Contains(",") && Double::Parse(this->result.Text) == 0)
        return;
      if (this->resetResult) {
        this->resetResult = false;
        if (!object::ReferenceEquals(sender, this->buttonDecimal))
          this->result.Text = "";
      }
      if (is<Control>(sender))
        this->result.Text += as<Control>(sender).Text;
    }
    
    void ButtonOperatorClick(const object& sender, const EventArgs& e) {
      this->resetResult = true;
      if (this->operation == Operator::None) {
        this->firstOperand = Double::Parse(this->result.Text().Replace(',', '.'));
      } else {
        switch (this->operation) {
          case Operator::Divide: this->result.Text = Double(this->firstOperand / Double::Parse(this->result.Text().Replace(',', '.'))).ToString().Replace('.', ','); break;
          case Operator::Multiply: this->result.Text = Double(this->firstOperand * Double::Parse(this->result.Text().Replace(',', '.'))).ToString().Replace('.', ','); break;
          case Operator::Subtract: this->result.Text = Double(this->firstOperand - Double::Parse(this->result.Text().Replace(',', '.'))).ToString().Replace('.', ','); break;
          case Operator::Add: this->result.Text = Double(this->firstOperand + Double::Parse(this->result.Text().Replace(',', '.'))).ToString().Replace('.', ','); break;
          default: break;
        }
        this->firstOperand = Double::Parse(this->result.Text);
      }

      switch (as<Control>(sender).Text()[0]) {
        case '/': this->operation = Operator::Divide; break;
        case 'X': this->operation = Operator::Multiply; break;
        case '-': this->operation = Operator::Subtract; break;
        case '+': this->operation = Operator::Add; break;
        case '=': break;
        default: this->operation = Operator::None; break;
      }
    }
    
  private:
    Label result;
    Button buttonClear;
    Button buttonPlusMinus;
    Button buttonPercent;
    Button buttonDecimal;
    Array<Button> buttonNumbers {10};
    Array<Button> buttonOperators {5};
    double firstOperand = .0f;
    bool resetResult = true;
    Operator operation = Operator::None;
  };
}

pcf_startup (Calculator::FormMain)
