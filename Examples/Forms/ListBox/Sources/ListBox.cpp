#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace ListBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "ListBox example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(200, 200);
      this->ClientSize = System::Drawing::Size(360, 240);
      
      this->listBoxActionsLeft.Parent = *this;
      this->listBoxActionsLeft.Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Bottom;
      this->listBoxActionsLeft.Bounds = System::Drawing::Rectangle(20, 20, 150, 200);
      this->listBoxActionsLeft.DoubleClick += pcf_delegate(const object& sender, const EventArgs& e) {
        if (this->listBoxActionsLeft.SelectedIndex != -1) {
          this->listBoxActionsRight.Items().Add(this->listBoxActionsLeft.SelectedItem());
          this->listBoxActionsRight.SelectedIndex = this->listBoxActionsRight.Items().Count-1;
          this->listBoxActionsLeft.Items().Remove(this->listBoxActionsLeft.SelectedItem());
        }
      };
      
      this->listBoxActionsRight.Parent = *this;
      this->listBoxActionsRight.Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Bottom | AnchorStyles::Right;
      this->listBoxActionsRight.Bounds = System::Drawing::Rectangle(190, 20, 150, 200);
      this->listBoxActionsRight.DoubleClick += pcf_delegate(const object& sender, const EventArgs& e) {
        if (this->listBoxActionsRight.SelectedIndex != -1) {
          this->listBoxActionsLeft.Items().Add(this->listBoxActionsRight.SelectedItem());
          this->listBoxActionsLeft.SelectedIndex = this->listBoxActionsLeft.Items().Count-1;
          this->listBoxActionsRight.Items().Remove(this->listBoxActionsRight.SelectedItem());
        }
      };

      this->listBoxActionsLeft.Items().AddRange(Array<string> {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"});
    }
    
  private:
    ListBox listBoxActionsLeft;
    ListBox listBoxActionsRight;
  };
}

pcf_startup (ListBoxExample::Form1)
