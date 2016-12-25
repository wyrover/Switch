#include <Core/Foreach.h>
#include <Drawing/System/Drawing/SystemColors.h>
#include <Forms/System/Windows/Forms/Application.h>
#include <Forms/System/Windows/Forms/Button.h>
#include <Forms/System/Windows/Forms/CheckBox.h>
#include <Forms/System/Windows/Forms/CheckedListBox.h>
#include <Forms/System/Windows/Forms/Form.h>
#include <Forms/System/Windows/Forms/GroupBox.h>
#include <Forms/System/Windows/Forms/ListBox.h>
#include <Forms/System/Windows/Forms/MaskedTextBox.h>
#include <Forms/System/Windows/Forms/NumericUpDown.h>
#include <Forms/System/Windows/Forms/Label.h>
#include <Forms/System/Windows/Forms/Panel.h>
#include <Forms/System/Windows/Forms/PictureBox.h>
#include <Forms/System/Windows/Forms/ProgressBar.h>
#include <Forms/System/Windows/Forms/RadioButton.h>
#include <Forms/System/Windows/Forms/RichTextBox.h>
#include <Forms/System/Windows/Forms/TabControl.h>
#include <Forms/System/Windows/Forms/TabPage.h>
#include <Forms/System/Windows/Forms/TextBox.h>

#include "../Includes/MainForm.h"

using namespace Pcf;
using namespace Pcf::System;
using namespace Pcf::System::Drawing;
using namespace Pcf::System::Windows::Forms;
using namespace Pcf::PcfCode;

MainForm::MainForm() : Form() {
  InitializeComponent();

  this->cptButton = 1;
  this->cptCheckBox = 1;
  this->cptCheckedListBox = 1;
  this->cptLabel = 1;
  this->cptListBox = 1;
  this->cptMaskedTextBox = 1;
  this->cptNumericUpDown = 1;
  this->cptPictureBox = 1;
  this->cptProgressBar = 1;
  this->cptRadioButton = 1;
  this->cptRichTextBox = 1;
  this->cptTextBox = 1;
  this->cptGroupBox = 1;
  this->cptPanel = 1;
  this->cptTabControl = 1;
  
  this->controlSelected = this->panelForm.ChangeType<Control>();
}

void MainForm::InitializeComponent() {
  this->Name("mainForm");
  this->Text("Pcf Code");
  this->Bounds(300, 200, 640, 480);
  
  this->panelLeft = new Panel();
  this->panelLeft->Name("panelLeft");
  this->panelLeft->Parent(*this);
  this->panelLeft->BorderStyle(BorderStyle::Fixed3D);
  this->panelLeft->Dock(DockStyle::Left);
  
  this->tabControlFill = new TabControl();
  this->tabControlFill->Name("tabControlFill");
  this->tabControlFill->Parent(*this);
  this->tabControlFill->Dock(DockStyle::Fill);
  
  this->tabPageDesigner = new TabPage();
  this->tabPageDesigner->Name("tabPageDesigner");
  this->tabPageDesigner->Parent(*this->tabControlFill);
  this->tabPageDesigner->Text("Test.cpp [Design]");
  this->tabPageDesigner->Paint += {*this, &MainForm::OnTabPageDesignerPaint};
  
  this->tabPageGeneratedSource = new TabPage();
  this->tabPageGeneratedSource->Name("tabPageGeneratedSource");
  this->tabPageGeneratedSource->Parent(*this->tabControlFill);
  this->tabPageGeneratedSource->Text("Test.cpp");
  
  this->panelForm = new Panel();
  this->panelForm->Name("panelForm");
  this->panelForm->Parent(*this->tabPageDesigner);
  this->panelForm->BackColor(SystemColors::Control());
  this->panelForm->BorderStyle(BorderStyle::FixedSingle);
  this->panelForm->Bounds(20, 20, 300, 300);
  this->panelForm->AllowDrop(true);
  this->panelForm->DragEnter += {*this, &MainForm::OnPanelFormDragEnter};
  this->panelForm->DragOver += {*this, &MainForm::OnPanelFormDragOver};
  this->panelForm->DragDrop += {*this, &MainForm::OnPanelFormDragDrop};
  this->panelForm->DragLeave += {*this, &MainForm::OnPanelFormDragLeave};
  this->panelForm->MouseDown += {*this, &MainForm::OnControlMouseDown};
  
  this->listBoxControl = new ListBox();
  this->listBoxControl->Name("listBoxControl");
  this->listBoxControl->Parent(*this->panelLeft);
  this->listBoxControl->BorderStyle(BorderStyle::None);
  //this->listBoxControl->Dock(DockStyle::Fill);
  this->listBoxControl->Bounds(2, 2, 196, 476);
  this->listBoxControl->Anchor(AnchorStyles::Left|AnchorStyles::Top|AnchorStyles::Right|AnchorStyles::Bottom);
  this->listBoxControl->Items.AddRange(Array<string>::Build("Button", "CheckBox", "CheckedListBox", "Label", "ListBox", "MaskedTextBox", "NumericUpDown", "PictureBox", "ProgressBar", "RadioButton", "RichTextBox", "TextBox", "GroupBox", "Panel", "TabControl"));
  this->listBoxControl->MouseDown += MouseEventHandler(*this, &MainForm::OnListBoxControlMouseDown);
  
  this->richTextBoxGeneratedSource = new RichTextBox();
  this->richTextBoxGeneratedSource->Name("richTextBoxGeneratedSource");
  this->richTextBoxGeneratedSource->Parent(*this->tabPageGeneratedSource);
  //this->richTextBoxGeneratedSource->Dock(DockStyle::Fill);
  this->richTextBoxGeneratedSource->Bounds(5, 15, 430, 440);
  this->richTextBoxGeneratedSource->Anchor(AnchorStyles::Left|AnchorStyles::Top|AnchorStyles::Right|AnchorStyles::Bottom);
  this->richTextBoxGeneratedSource->BorderStyle(BorderStyle::None);
  this->richTextBoxGeneratedSource->Font(Drawing::Font(Drawing::FontFamily::GenericMonospace()));
}

void MainForm::OnListBoxControlMouseDown(const object& sender, const MouseEventArgs& e) {
  this->listBoxControl->DoDragDrop(this->listBoxControl->SelectedItem(), DragDropEffects::Copy);
}

Sp<Control> MainForm::CreateButton() {
  Up<Button> control = new Button();
  control->BackColor(SystemColors::Control());
  control->Name(string::Format("button{0}", this->cptButton));
  control->Text(string::Format("button{0}", this->cptButton++));
  return control.Release();
}

Sp<Control> MainForm::CreateCheckBox() {
  Up<CheckBox> control = new CheckBox();
  control->BackColor(SystemColors::Control());
  control->Name(string::Format("checkBox{0}", this->cptCheckBox));
  control->Text(string::Format("checkBox{0}", this->cptCheckBox++));
  return control.Release();
}

Sp<Control> MainForm::CreateCheckedListBox() {
  Up<CheckedListBox> control = new CheckedListBox();
  control->Name(string::Format("checkedListBox{0}", this->cptCheckedListBox));
  control->Text(string::Format("checkedListBox{0}", this->cptCheckedListBox++));
  control->Items.Add("Item 1");
  return control.Release();
}

Sp<Control> MainForm::CreateLabel() {
  Up<Label> control = new Label();
  control->BackColor(SystemColors::Control());
  control->Name(string::Format("label{0}", this->cptLabel));
  control->Text(string::Format("label{0}", this->cptLabel++));
  return control.Release();
}

Sp<Control> MainForm::CreateListBox() {
  Up<ListBox> control = new ListBox();
  control->Name(string::Format("listBox{0}", this->cptListBox));
  control->Text(string::Format("listBox{0}", this->cptListBox++));
  control->Items.Add("Item 1");
  return control.Release();
}

Sp<Control> MainForm::CreateMaskedTextBox() {
  Up<MaskedTextBox> control = new MaskedTextBox();
  control->Name(string::Format("maskedTextBox{0}", this->cptMaskedTextBox++));
  return control.Release();
}

Sp<Control> MainForm::CreateNumericUpDown() {
  Up<NumericUpDown> control = new NumericUpDown();
  control->Name(string::Format("numericUpDown{0}", this->cptNumericUpDown++));
  return control.Release();
}

Sp<Control> MainForm::CreatePictureBox() {
  Up<PictureBox> control = new PictureBox();
  control->Name(string::Format("pictureBox{0}", this->cptPictureBox));
  control->Text(string::Format("pictureBox{0}", this->cptPictureBox++));
  control->BorderStyle(BorderStyle::FixedSingle);
  return control.Release();
}

Sp<Control> MainForm::CreateProgressBar() {
  Up<ProgressBar> control = new ProgressBar();
  control->Name(string::Format("progressBar{0}", this->cptProgressBar++));
  control->Text("50%");
  control->Value(50);
  return control.Release();
}

Sp<Control> MainForm::CreateRadioButton() {
  Up<RadioButton> control = new RadioButton();
  control->BackColor(SystemColors::Control());
  control->Name(string::Format("radioButton{0}", this->cptRadioButton));
  control->Text(string::Format("radioButton{0}", this->cptRadioButton++));
  return control.Release();
}

Sp<Control> MainForm::CreateRichTextBox() {
  Up<RichTextBox> control = new RichTextBox();
  control->Name(string::Format("richTextBox{0}", this->cptRichTextBox));
  control->Text(string::Format("richTextBox{0}", this->cptRichTextBox++));
  return control.Release();
}

Sp<Control> MainForm::CreateTextBox() {
  Up<TextBox> control = new TextBox();
  control->Name(string::Format("textBox{0}", this->cptTextBox));
  control->Text(string::Format("textBox{0}", this->cptTextBox++));
  return control.Release();
}

Sp<Control> MainForm::CreateGroupBox() {
  Up<GroupBox> control = new GroupBox();
  control->Name(string::Format("groupBox{0}", this->cptGroupBox));
  control->Text(string::Format("groupBox{0}", this->cptGroupBox++));
  return control.Release();
}

Sp<Control> MainForm::CreatePanel() {
  Up<Panel> control = new Panel();
  control->Name(string::Format("panel{0}", this->cptPanel++));
  control->BorderStyle(BorderStyle::Fixed3D);
  return control.Release();
}

Sp<Control> MainForm::CreateTabControl() {
  Up<TabControl> control = new TabControl();
  control->Name(string::Format("tabControl{0}", this->cptTabControl++));
  return control.Release();
}

void MainForm::OnPanelFormDragEnter(const object& sender, DragEventArgs& e) {
  this->offsetMouse = Point(0, 0);
  if (this->controlDrop.IsNull()) {
    string str = ToD<String>(e.Data());
    if (str == "Button")
      this->controlDrop = CreateButton();
    else if (str == "CheckBox")
      this->controlDrop = CreateCheckBox();
    else if (str == "CheckedListBox")
      this->controlDrop = CreateCheckedListBox();
    else if (str == "Label")
      this->controlDrop = CreateLabel();
    else if (str == "ListBox")
      this->controlDrop = CreateListBox();
    else if (str == "MaskedTextBox")
      this->controlDrop = CreateMaskedTextBox();
    else if (str == "NumericUpDown")
      this->controlDrop = CreateNumericUpDown();
    else if (str == "PictureBox")
      this->controlDrop = CreatePictureBox();
    else if (str == "ProgressBar")
      this->controlDrop = CreateProgressBar();
    else if (str == "RadioButton")
      this->controlDrop = CreateRadioButton();
    else if (str == "RichTextBox")
      this->controlDrop = CreateRichTextBox();
    else if (str == "TextBox")
      this->controlDrop = CreateTextBox();
    else if (str == "GroupBox")
      this->controlDrop = CreateGroupBox();
    else if (str == "Panel")
      this->controlDrop = CreatePanel();
    else if (str == "TabControl")
      this->controlDrop = CreateTabControl();
  }
}

void MainForm::OnPanelFormDragOver(const object& sender, DragEventArgs& e) {
  if (!this->controlDrop.IsNull()) {
    this->controlDrop->Parent(*this->panelForm);
    this->controlDrop->Location(this->panelForm->PointToClient(Point(e.X(), e.Y())) - this->offsetMouse);
    Application::DoEvent();
    this->tabControlFill->Invalidate();
  }
}

void MainForm::OnPanelFormDragDrop(const object& sender, DragEventArgs& e) {
  if (!this->controlDrop.IsNull()) {
    if (e.Effect() == DragDropEffects::Copy) {
      this->controls.Add(this->controlDrop);
      if (Is<TabControl>(*this->controlDrop)) {
        Sp<Control> page1 = new TabPage();
        page1->Name(string::Format("{0}page1", this->controlDrop->Name()));
        page1->Text("page1");
        page1->Parent(*this->controlDrop);
        this->controls.Add(page1);
        Sp<Control> page2 = new TabPage();
        page2->Name(string::Format("{0}page2", this->controlDrop->Name()));
        page2->Text("page2");
        page2->Parent(*this->controlDrop);
        this->controls.Add(page2);
      }
      //this->controlDrop->Focus();
      this->controlSelected = this->controlDrop;
      Application::DoEvent();
      this->tabControlFill->Invalidate();
    }
    
    this->controlSelected->Parent(*this->panelForm);
    this->controlSelected->Location(this->panelForm->PointToClient(Point(e.X(), e.Y())) - this->offsetMouse);
    Generation::CppFileWriter cfw = Generation::CppFileWriter::FromControls(this->controls);
    this->richTextBoxGeneratedSource->Text(cfw.Generate());
    this->controlDrop.Reset();
  }
}

void MainForm::OnPanelFormDragLeave(const object& sender, const EventArgs& e) {
  if (!this->controlDrop.IsNull()) {
    this->controlDrop->Location(-1, -1);
    this->Controls().Remove(*this->controlDrop);
    this->controlDrop = null;
    Application::DoEvent();
  }
}

void MainForm::OnControlMouseDown(const object& sender, const MouseEventArgs& e) {
  this->controlSelected = Sp<Control>::Null();
  this->offsetMouse = Point(0, 0);
  
  foreach(Sp<Control>, control, this->controls) {
    if (control->Bounds().Contains(e.X(), e.Y())) {
      //control->Focus();
      this->controlSelected = control;
      this->controlDrop = control;
      this->offsetMouse = Point(e.Location() - this->controlDrop->Location());
      this->tabControlFill->DoDragDrop(control.ToObject(), DragDropEffects::Move);
      break;
    }
  }

  if (this->controlSelected.IsNull())
    this->controlSelected = this->panelForm.ChangeType<Control>();
  this->tabControlFill->Invalidate();
}


void MainForm::DrawSelectedBorder(System::Drawing::Graphics& graphics, const Sp<Control>& control) {
  if (control.IsNull())
    return;
  
  int32 width = 6;
  int32 height = 6;

  int32 left = this->panelForm->Left() + (control.ToPointer() == this->panelForm.ToPointer() ? 0 : control->Left()) - width;
  int32 top = this->panelForm->Top() + (control.ToPointer() == this->panelForm.ToPointer() ? 0 : control->Top()) - height;
  int32 right = this->panelForm->Left() + (control.ToPointer() == this->panelForm.ToPointer() ? 0 : control->Left()) + control->Width();
  int32 bottom = this->panelForm->Top() + (control.ToPointer() == this->panelForm.ToPointer() ? 0 : control->Top()) + control->Height();
  
  //Console::WriteLine("Left  = {0}", left);
  //Console::WriteLine("Right = {0}", right);
  //Console::WriteLine("Middle = {0}", left+((right-left)/2)-(width/2));
  
  graphics.FillRectangle(SolidBrush(Color::White()), left, top, width, height);
  graphics.FillRectangle(SolidBrush(Color::White()), left+((right-left)/2), top, width, height);
  graphics.FillRectangle(SolidBrush(Color::White()), left, top+((bottom-top)/2), width, height);
  graphics.FillRectangle(SolidBrush(Color::White()), right, top, width, height);
  graphics.FillRectangle(SolidBrush(Color::White()), left, bottom, width, height);
  graphics.FillRectangle(SolidBrush(Color::White()), left+((right-left)/2), bottom, width, height);
  graphics.FillRectangle(SolidBrush(Color::White()), right, top+((bottom-top)/2), width, height);
  graphics.FillRectangle(SolidBrush(Color::White()), right, bottom, width, height);
  
  graphics.DrawRectangle(Pen(Color::Black()), left, top, width, height);
  graphics.DrawRectangle(Pen(Color::Black()), left+((right-left)/2), top, width, height);
  graphics.DrawRectangle(Pen(Color::Black()), left, top+((bottom-top)/2), width, height);
  graphics.DrawRectangle(Pen(Color::Black()), right, top, width, height);
  graphics.DrawRectangle(Pen(Color::Black()), left, bottom, width, height);
  graphics.DrawRectangle(Pen(Color::Black()), left+((right-left)/2), bottom, width, height);
  graphics.DrawRectangle(Pen(Color::Black()), right, top+((bottom-top)/2), width, height);
  graphics.DrawRectangle(Pen(Color::Black()), right, bottom, width, height);
}

void MainForm::OnTabPageDesignerPaint(const object& sender, PaintEventArgs& e) {
  DrawSelectedBorder(e.Graphics(), this->controlSelected);
}

void MainForm::OnPanelFormMouseDown(const object& sender, const MouseEventArgs& e) {
}

