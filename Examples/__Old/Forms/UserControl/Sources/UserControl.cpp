#include <Pcf/Pcf>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace UserControlExample {
  enum class OperationStatus {
    None,
    Running,
    Succeed,
    Failed
  };
  
  class Operation : public Control {
  public:
    Operation() {}
    
    Property<OperationStatus> Status {
      pcf_get {return this->status;},
      pcf_set {
        this->status = value;
        this->Control::Invalidate();
      }
    };
    
    void OnPaint(PaintEventArgs& e) override {
      e.Graphics().FillRectangle(SolidBrush(SystemColors::Control), 1, 1, 28, 28);
      e.Graphics().DrawLine(Pen(Color::DarkGray), Point(1, 1), Point(28, 1));
      e.Graphics().DrawLine(Pen(Color::DarkGray), Point(1, 1), Point(1, 28));
      e.Graphics().DrawLine(Pen(Color::White), Point(1, 28), Point(28, 28));
      e.Graphics().DrawLine(Pen(Color::White), Point(28, 1), Point(28, 28));
      switch (this->Status) {
        case UserControlExample::OperationStatus::None: break;
        case UserControlExample::OperationStatus::Running: e.Graphics().DrawString("☞", System::Drawing::Font(DefaultFont().Name, 20, FontStyle::Italic), SolidBrush(Color::Blue), 5, 5); break;
        case UserControlExample::OperationStatus::Succeed: e.Graphics().DrawString("√", System::Drawing::Font(DefaultFont().Name, 20, FontStyle::Italic), SolidBrush(Color::Green), 8, 5); break;
        case UserControlExample::OperationStatus::Failed: e.Graphics().DrawString("X", System::Drawing::Font(DefaultFont().Name, 20, FontStyle::Italic), SolidBrush(Color::Red), 8, 5); break;
      }
      e.Graphics().DrawString(this->Text, DefaultFont, SolidBrush(Color::Black), 35, 5);
      if (this->Focused)
        e.Graphics().DrawRectangle(Pen(Color::DarkGray), e.ClipRectangle);
      this->Control::OnPaint(e);
    }
    
    void OnClick(const EventArgs& e) override {
      switch (this->status) {
        case OperationStatus::None : this->Status = OperationStatus::Running; break;
        case OperationStatus::Running : this->Status = OperationStatus::Succeed; break;
        case OperationStatus::Succeed : this->Status = OperationStatus::Failed; break;
        case OperationStatus::Failed : this->Status = OperationStatus::None; break;
      }
      this->Control::OnClick(e);
    }

    bool GetCanFocus() const override {return true;}

    System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(100, 25);}
    
  private:
    OperationStatus status = OperationStatus::Running;
  };

  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Bounds = System::Drawing::Rectangle(300, 200, 200, 200);
      this->Text = "User control example";

      this->operations[0].Parent = *this;
      this->operations[0].Status = OperationStatus::Succeed;
      this->operations[0].Text = "First operation";
      this->operations[0].Bounds = System::Drawing::Rectangle(5, 5, 150, 30);
      this->operations[0].Name = "First";
      
      this->operations[1].Parent = *this;
      this->operations[1].Status = OperationStatus::Failed;
      this->operations[1].Text = "Second operation";
      this->operations[1].Bounds = System::Drawing::Rectangle(5, 35, 150, 30);
      
      this->operations[2].Parent = *this;
      this->operations[2].Status = OperationStatus::Running;
      this->operations[2].Text = "Third operation";
      this->operations[2].Bounds = System::Drawing::Rectangle(5, 65, 150, 30);
      
      this->operations[3].Parent = *this;
      this->operations[3].Status = OperationStatus::None;
      this->operations[3].Text = "Fourth operation";
      this->operations[3].Bounds = System::Drawing::Rectangle(5, 95, 150, 30);
      
      this->operations[4].Parent = *this;
      this->operations[4].Status = OperationStatus::None;
      this->operations[4].Text = "Fifth operation";
      this->operations[4].Bounds = System::Drawing::Rectangle(5, 125, 150, 30);
    }
    
  private:
    Array<Operation> operations {5};
  };
}

pcf_startup (UserControlExample::Form1)
