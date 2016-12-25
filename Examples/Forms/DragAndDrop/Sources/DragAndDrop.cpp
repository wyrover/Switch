#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace DragAndDropExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "Drag and Drop example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 480);
      this->Name = "form";
      
      this->panelFill.Parent = *this;
      this->panelFill.BackColor = Drawing::SystemColors::ControlLightLight;
      this->panelFill.BorderStyle = BorderStyle::Fixed3D;
      this->panelFill.Dock = DockStyle::Fill;
      this->panelFill.Name = "panelFill";
      
      this->panelLeft.Parent = *this;
      //this->panelLeft.BorderStyle = BorderStyle::None;
      this->panelLeft.Name = "panelLeft";
      this->panelLeft.Dock = DockStyle::Left;
      
      this->panelForm.Parent = this->panelFill;
      this->panelForm.Name = "panelForm";
      this->panelForm.BackColor = Drawing::SystemColors::Control;
      this->panelForm.BorderStyle = BorderStyle::FixedSingle;
      this->panelForm.Bounds = System::Drawing::Rectangle(10, 10, 300, 300);
      this->panelForm.AllowDrop = true;
      this->panelForm.DragEnter += {*this, &Form1::OnPanelFormControlDragEnter};
      this->panelForm.DragOver += {*this, &Form1::OnPanelFormControlDragOver};
      this->panelForm.DragDrop += {*this, &Form1::OnPanelFormControlDragDrop};
      this->panelForm.DragLeave += {*this, &Form1::OnPanelFormControlDragLeave};
      
      this->listBoxControl.Parent = this->panelLeft;
      this->listBoxControl.BorderStyle = BorderStyle::Fixed3D;
      this->listBoxControl.Dock = DockStyle::Fill;
      this->listBoxControl.Items().AddRange(Array<string> {"Button", "CheckBox", "CheckedListBox", "Label", "ListBox", "MaskedTextBox", "PictureBox", "ProgressBar", "RadioButton", "RichTextBox", "TextBox"});
      this->listBoxControl.SelectedIndex = 0;
      this->listBoxControl.MouseDown += {*this, &Form1::OnListBoxControlMouseDown};
      this->listBoxControl.Name = "listBoxControl";
    }
    
  private:
    void OnListBoxControlMouseDown(const object& sender, const MouseEventArgs& e) {
      this->listBoxControl.DoDragDrop(*this->listBoxControl.SelectedItem(), DragDropEffects::Copy);
    }
    
    sp<Control> CreateButton() {
      sp<Button> control = up<Button>::Create();
      control->Text = string::Format("button {0}", this->cptButton++);
      return as<Control>(control);
    }
    
    sp<Control> CreateCheckBox() {
      sp<CheckBox> control = up<CheckBox>::Create();
      control->Text = string::Format("CheckBox {0}", this->cptCheckBox++);
      return as<Control>(control);
    }
    
    sp<Control> CreateCheckedListBox() {
      sp<CheckedListBox> control = new CheckedListBox();
      control->Text = string::Format("CheckedListBox {0}", this->cptCheckedListBox++);
      control->Items().Add("Item 1");
      return as<Control>(control);
    }
    
    sp<Control> CreateLabel() {
      sp<Label> control = up<Label>::Create();
      control->BackColor = Drawing::SystemColors::Control;
      control->AutoSize = true;
      control->Text = string::Format("Label {0}", this->cptLabel++);
      return as<Control>(control);
    }
    
    sp<Control> CreateListBox() {
      sp<ListBox> control = up<ListBox>::Create();
      control->Text = string::Format("ListBox {0}", this->cptListBox++);
      control->Items().Add("Item 1");
      return as<Control>(control);
    }
    
    sp<Control> CreateMaskedTextBox() {
      sp<MaskedTextBox> control = up<MaskedTextBox>::Create();
      control->Text = string::Format("MaskedTextBox {0}", this->cptMaskedTextBox++);
      return as<Control>(control);
    }
    
    sp<Control> CreatePictureBox() {
      sp<PictureBox> control = up<PictureBox>::Create();
      control->Text = string::Format("PictureBox {0}", this->cptPictureBox++);
      control->BorderStyle = BorderStyle::FixedSingle;
      return as<Control>(control);
    }
    
    sp<Control> CreateProgressBar() {
      sp<ProgressBar> control = up<ProgressBar>::Create();
      control->Value = 50;
      return as<Control>(control);
    }
    
    sp<Control> CreateRadioButton() {
      sp<RadioButton> control = up<RadioButton>::Create();
      control->BackColor = Drawing::SystemColors::Control;
      control->Text = string::Format("radioButton {0}", this->cptRadioButton++);
      return as<Control>(control);
    }
    
    sp<Control> CreateRichTextBox() {
      sp<RichTextBox> control = up<RichTextBox>::Create();
      control->Text = string::Format("RichTextBox {0}", this->cptRichTextBox++);
      return as<Control>(control);
    }
    
    sp<Control> CreateTextBox() {
      sp<TextBox> control = up<TextBox>::Create();
      control->Text = string::Format("TextBox {0}", this->cptTextBox++);
      return as<Control>(control);
    }
    
    void OnPanelFormControlDragEnter(const object& sender, DragEventArgs& e) {
      e.Effect = DragDropEffects::Copy;
      if (this->controlDrop == null) {
        string str = as<String>(e.Data());
        if (str == "Button")
          this->controlDrop = CreateButton();
        if (str == "CheckBox")
          this->controlDrop = CreateCheckBox();
        if (str == "CheckedListBox")
          this->controlDrop = CreateCheckedListBox();
        if (str == "Label")
          this->controlDrop = CreateLabel();
        if (str == "ListBox")
          this->controlDrop = CreateListBox();
        if (str == "MaskedTextBox")
          this->controlDrop = CreateMaskedTextBox();
        if (str == "PictureBox")
          this->controlDrop = CreatePictureBox();
        if (str == "ProgressBar")
          this->controlDrop = CreateProgressBar();
        if (str == "RadioButton")
          this->controlDrop = CreateRadioButton();
        if (str == "RichTextBox")
          this->controlDrop = CreateRichTextBox();
        if (str == "TextBox")
          this->controlDrop = CreateTextBox();
      }
    }
    
    void OnPanelFormControlDragOver(const object& sender, DragEventArgs& e) {
      if (this->controlDrop != null) {
        this->controlDrop->Parent = this->panelForm;
        this->controlDrop->Location = this->panelForm.PointToClient(Drawing::Point(e.X+1, e.Y+1));
        Application::DoEvent();
      }
    }
    
    void OnPanelFormControlDragDrop(const object& sender, DragEventArgs& e) {
      if (this->controlDrop != null){
        this->controlDrop->Parent = this->panelForm;
        this->controlDrop->Location = this->panelForm.PointToClient(Drawing::Point(e.X+1, e.Y+1));
        this->controls.Add(this->controlDrop);
        this->controlDrop = null;
      }
    }
    
    void OnPanelFormControlDragLeave(const object& sender, const EventArgs& e) {
      if (this->controlDrop != null) {
        this->controlDrop->Location = System::Drawing::Point(-1, -1);
        this->controlDrop = null;
      }
    }
    
    Panel panelLeft;
    Panel panelFill;
    Panel panelForm;
    ListBox listBoxControl;
    sp<Control> controlDrop = null;
    System::Collections::Generic::List<sp<Control>> controls;
    
    int cptButton = 1;
    int cptCheckBox = 1;
    int cptCheckedListBox = 1;
    int cptLabel = 1;
    int cptListBox = 1;
    int cptMaskedTextBox = 1;
    int cptPictureBox = 1;
    int cptRadioButton = 1;
    int cptRichTextBox = 1;
    int cptTextBox = 1;
  };
}

pcf_startup (DragAndDropExample::Form1)
