#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Form.h"

#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/Drawing/SystemColors.h>
#include <Pcf/System/Text/UTF8Encoding.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  using Widget = Fltk::Widget<Fl_Widget>;
}

Property<System::Drawing::Color, ReadOnly> Control::DefaultBackColor {
  [] {return System::Drawing::SystemColors::Control;}
};

Property<System::Drawing::Color, ReadOnly> Control::DefaultForeColor {
  [] {return System::Drawing::SystemColors::ControlText;}
};

//const System::Drawing::Font Control::DefaultFont = System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Regular);
Property<System::Drawing::Font, ReadOnly> Control::DefaultFont {
  [] {return System::Drawing::Font("Arial", 12, System::Drawing::FontStyle::Regular);}
};

void Control::ControlCollection::AddControl(Control& control) {
  if (control.parent != this->parent) {
    control.oldParent = control.parent;
    if (control.parent != null)
      control.parent->controls.Remove(control);
    ((Fl_Group&)Widget::ToWidget(this->parent->widget())).add(Widget::ToWidget(control.widget()));
    //Widget::ToWidget(this->parent->widget()).redraw();
    Pcf::System::Collections::Generic::List<Reference<Control>>::Insert(0, Reference<Control>(control));
    control.parent = this->parent;
    this->parent->ControlAdded(*this->parent, ControlEventArgs(control));
    control.parent->PerformLayoutIfNotSuspend();
    control.OnParentChanged(EventArgs());
  }
}

bool Control::ControlCollection::RemoveControl(Control& control) {
  bool result = false;
  if (control.parent == this->parent) {
    if (Widget::ToWidget(control.widget()).parent() != null)
      ((Fl_Group&)Widget::ToWidget(this->parent->widget())).remove(Widget::ToWidget(control.widget()));
    control.oldParent = control.parent;
    result = Pcf::System::Collections::Generic::List<Reference<Control>>::Remove(Reference<Control>(control));
    control.parent = null;
    this->parent->ControlRemoved(*this->parent, ControlEventArgs(control));
    control.oldParent->PerformLayoutIfNotSuspend();
    control.PerformLayoutIfNotSuspend();
    control.OnParentChanged(EventArgs());
  }
  return result;
}

const object* Control::dragDropData = null;
DragDropEffects Control::dragDropAllowedEffects = DragDropEffects::None;
DragDropEffects Control::dragDropEffects = DragDropEffects::None;

Control::Control() : Control(UniquePointer<IWidget>::Create<Fltk::Widget<Fl_Group>>()) {
  dynamic_cast<Fl_Group&>(this->widget()).end();
  Widget::ToWidget(this->widget()).labeltype(FL_NO_LABEL);
  Widget::ToWidget(this->widget()).box(FL_NO_BOX);
}

Control::Control(UniquePointer<IWidget> widget) {
  this->Register(widget);
  this->BackColor = DefaultBackColor;
  this->ForeColor = DefaultForeColor;
  //Widget::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(DefaultBackColor));
  this->Font = DefaultFont;
  this->Size = this->GetDefaultSize();
}

Control::~Control() {
  this->Unregister();
  this->HandleDestroyed(*this, EventArgs());
}

DragDropEffects Control::DoDragDrop(const Reference<object>& data, DragDropEffects allowedEffects) {
  if (data.IsNull())
    return DragDropEffects::None;
  Fl::copy((const char*)data.ToPointer(), sizeof(data()), 0);
  Fl::dnd();
  System::Windows::Forms::Control::dragDropData = data.ToPointer();
  this->dragDropEffects = allowedEffects;
  /*
  if (!this->allowDrop)
    return DragDropEffects::None;
   */
  return allowedEffects;
}

void Control::Invalidate() {
  Widget::ToWidget(this->widget()).redraw();
}

void Control::Invoke(const MethodInvoker& method) {
  this->invoker = method;
  Fl::awake(&Control::InvokeMethod, (void*)this);
}

void Control::Register(UniquePointer<IWidget> widget) {
  this->widget = widget;
  this->ClientSize = System::Drawing::Size(Widget::ToWidget(*this->widget).w(), Widget::ToWidget(*this->widget).h());
  this->widget->Paint += pcf_delegate(const object&, const EventArgs& e) {
    if (is<Form>(this))
      this->graphics.Offset(PointToForm(System::Drawing::Point(0, 0)));
    else
      this->graphics.Offset(PointToForm(this->Location));
    PaintEventArgs eventArgs(System::Drawing::Rectangle(System::Drawing::Point(0, 0), this->ClientSize()), this->graphics);
    this->OnPaint(eventArgs);
  };
  
  this->widget->EventHandled += pcf_delegate(const object&, IWidget::WidgetEventArgs& e) {
    //In the future i will modifiy fltk event to receive Resize event...
    if (dynamic_cast<Form*>(this) != null && this->Location != System::Drawing::Point(Widget::ToWidget(this->widget()).x(), Widget::ToWidget(this->widget()).y()))
      this->__OnFormMove__();

    if (dynamic_cast<Form*>(this) != null && this->ClientSize != System::Drawing::Size(Widget::ToWidget(this->widget()).w(), Widget::ToWidget(this->widget()).h()))
      this->__OnFormSizeChange__();

    switch (e.Event) {
      case FL_NO_EVENT: this->__OnNoEvent__(); break;
      case FL_ENTER: this->__OnEnter__(); break;
      case FL_MOVE: this->__OnMove__(); break;
      case FL_PUSH: this->__OnPush__(); break;
      case FL_RELEASE: this->__OnRelease__(); break;
      case FL_MOUSEWHEEL: this->__OnMouseWheel__(); break;
      case FL_LEAVE: this->__OnLeave__(); break;
      case FL_DRAG: this->__OnDrag__(); break;
      case FL_FOCUS: e.IsHandled = this->__OnFocus__(); break;
      case FL_UNFOCUS: this->__OnUnfocus__(); break;
      case FL_KEYDOWN: this->__OnKeyDown__(); break;
      case FL_KEYUP: this->__OnKeyUp__(); break;
      case FL_CLOSE: this->__OnClose__(); break;
      case FL_SHORTCUT: this->__OnShortcut__(); break;
      case FL_DEACTIVATE: this->__OnDeactivate__(); break;
      case FL_ACTIVATE: this->__OnActivate__(); break;
      case FL_HIDE: this->__OnHide__(); break;
      case FL_SHOW: this->__OnShow__(); break;
      case FL_PASTE: this->__OnPaste__(); break;
      case FL_SELECTIONCLEAR: this->__OnSelectionClear__(); break;
      case FL_DND_ENTER: e.IsHandled = this->__OnDndEnter__(); break;
      case FL_DND_DRAG: e.IsHandled = this->__OnDndDrag__(); break;
      case FL_DND_RELEASE: e.IsHandled = this->__OnDndRelease__(); break;
      case FL_DND_LEAVE: e.IsHandled = this->__OnDndLeave__(); break;
      case FL_SCREEN_CONFIGURATION_CHANGED: this->__OnScreenConfiguartionChange__(); break;
      case FL_FULLSCREEN: this->__OnFullscreen__(); break;
      default: System::Console::WriteLine("Event {0} unknown !!!", e.Event);
    }
    //Console::WriteLine("Event = {0}, Handled = {1}", e.Event, e.IsHandled);
  };
}

void Control::__OnNoEvent__() {
}

void Control::__OnEnter__() {
  fl_cursor((Fl_Cursor)(int32)as<Int32>(this->useWaitCursor ? Cursors::WaitCursor.Tag() : this->cursor.Tag()));
  this->hover = true;
  if (this->Enabled)
    this->OnMouseEnter(EventArgs());
}

void Control::__OnMove__() {
  this->OnMouseMove(MouseEventArgs(Fltk::Helper::GetMouseButton(), Fl::event_x() - this->Left(), Fl::event_y() - this->Top(), Fl::event_clicks() ? 2 : 1, 0));
  if (this->hover)
    this->OnMouseHover(EventArgs());
}

void Control::__OnPush__() {
  if (this->CanFocus() == true)
    this->Focus();
  this->OnMouseDown(MouseEventArgs(Fltk::Helper::GetMouseButton(), Fl::event_x() - this->Left(), Fl::event_y() - this->Top(), Fl::event_clicks() ? 2 : 1, 0));
}

void Control::__OnRelease__() {
  Fl_Widget* belowWidget = Fl::belowmouse();
  Fl_Widget* widget = &Widget::ToWidget(this->widget());
  if (widget != belowWidget)
    return;
  MouseEventArgs mouseEventArgs(Fltk::Helper::GetMouseButton(), Fl::event_x() - this->Left(), Fl::event_y() - this->Top(), Fl::event_clicks() ? 2 : 1, 0);
  if (Fl::event_clicks() == 0 || this->HasClickReplaceDoubleClick(Fltk::Helper::GetMouseButton())) {
    if (this->Visible && this->Enabled)
      this->OnClick(EventArgs());
    this->OnMouseClick(mouseEventArgs);
  } else {
    if (this->Visible && this->Enabled)
      this->OnDoubleClick(EventArgs());
    this->OnMouseDoubleClick(mouseEventArgs);
  }
  this->OnMouseUp(mouseEventArgs);
}

void Control::__OnMouseWheel__() {
#if !WHEEL_DELTA
  static const int32 WHEEL_DELTA = 40;
#endif
  this->OnMouseWheel(MouseEventArgs(Fltk::Helper::GetMouseButton(), Fl::event_x() - this->Left(), Fl::event_y() - this->Top(), Fl::event_clicks() ? 2 : 1, -Fl::event_dy() * WHEEL_DELTA));
}

void Control::__OnLeave__() {
  if (this->parent)
    fl_cursor((Fl_Cursor)(int32)as<Int32>(this->parent->Cursor().Tag()));
  else
    fl_cursor((Fl_Cursor)(int32)as<Int32>(Cursors::Default.Tag()));
  this->hover = false;
  if (this->Enabled)
    this->OnMouseLeave(EventArgs());
}

void Control::__OnDrag__() {
}

bool Control::__OnFocus__() {
  if (this->CanFocus() == false)
    return false;
  this->OnEnter(EventArgs());
  this->Invalidate();
  return true;
}

void Control::__OnUnfocus__() {
  this->OnLeave(EventArgs());
  this->Invalidate();
}

void Control::__OnKeyDown__() {
  KeyEventArgs keyEventArgs(Fltk::Helper::GetKeyCode());
  this->OnKeyDown(keyEventArgs);
  KeyPressEventArgs keyPressEventArgs(Fltk::Helper::GetKeyChar());
  if (keyPressEventArgs.KeyChar != (char32)0)
    this->OnKeyPress(keyPressEventArgs);
}

void Control::__OnKeyUp__() {
  KeyEventArgs keyEventArgs(Fltk::Helper::GetKeyCode());
  this->OnKeyUp(keyEventArgs);
}

void Control::__OnClose__() {
}

void Control::__OnShortcut__() {
}

void Control::__OnDeactivate__() {
}

void Control::__OnActivate__() {
}

void Control::__OnHide__() {
  this->OnMouseLeave(EventArgs());
}

void Control::__OnShow__() {
}

void Control::__OnPaste__() {
}

void Control::__OnSelectionClear__() {
}

bool Control::__OnDndEnter__() {
  if (!this->allowDrop || dragDropData == null)
    return false;

  if (this->Name == "panelForm")
    Console::WriteLine("OnDragEnter : {0} {1}", this->allowDrop, (intptr)dragDropData);

  System::Drawing::Point screenXY = this->PointToScreen(System::Drawing::Point(Fl::event_x() - this->Left(), Fl::event_y() - this->Top()));
  DragEventArgs args(*dragDropData, this->dragDropAllowedEffects, this->dragDropEffects, Fltk::Helper::GetKeyState(), screenXY.X(), screenXY.Y());
  this->OnDragEnter(args);
  dragDropData = &args.Data();
  dragDropEffects = args.Effect();
  return true;
}

bool Control::__OnDndDrag__() {
  if (this->Name == "panelForm")
    Console::WriteLine("OnDragOver : {0} {1}", this->allowDrop, (intptr)dragDropData);
  
  if (!this->allowDrop || dragDropData == null)
    return false;

  System::Drawing::Point screenXY = this->PointToScreen(System::Drawing::Point(Fl::event_x() - this->Left(), Fl::event_y() - this->Top()));
  DragEventArgs args(*dragDropData, this->dragDropAllowedEffects, this->dragDropEffects, Fltk::Helper::GetKeyState(), screenXY.X(), screenXY.Y());
  this->OnDragOver(args);
  this->dragDropEffects = args.Effect();
  return true;
}

bool Control::__OnDndRelease__() {
  if (!this->allowDrop || dragDropData == null)
    return false;
  
  if (this->Name == "panelForm")
    Console::WriteLine("OnDragDrop : {0} {1}", this->allowDrop, (intptr)dragDropData);

  System::Drawing::Point screenXY = this->PointToScreen(System::Drawing::Point(Fl::event_x() - this->Left(), Fl::event_y() - this->Top()));
  DragEventArgs args(*dragDropData, this->dragDropAllowedEffects, this->dragDropEffects, Fltk::Helper::GetKeyState(), screenXY.X(), screenXY.Y());
  this->OnDragDrop(args);
  this->dragDropEffects = DragDropEffects::None;
  this->dragDropData = null;
  return true;
}

bool Control::__OnDndLeave__() {
  if (!this->allowDrop || dragDropData == null)
    return false;

  if (this->Name == "panelForm")
    Console::WriteLine("OnDragLeave : {0} {1}", this->allowDrop, (intptr)dragDropData);

  System::Drawing::Point screenXY = this->PointToScreen(System::Drawing::Point(Fl::event_x() - this->Left(), Fl::event_y() - this->Top()));
  DragEventArgs args(*dragDropData, this->dragDropAllowedEffects, this->dragDropEffects, Fltk::Helper::GetKeyState(), screenXY.X(), screenXY.Y());
  this->OnDragLeave(args);
  //this->dragDropEffects = DragDropEffects::None;
  //this->dragDropData = null;
  return true;
}

void Control::__OnScreenConfiguartionChange__() {
}

void Control::__OnFullscreen__() {
}

void Control::__OnFormSizeChange__() {
  this->ClientSize = System::Drawing::Size(Widget::ToWidget(this->widget()).w(), Widget::ToWidget(this->widget()).h());
}

void Control::__OnFormMove__() {
  this->location = System::Drawing::Point(dynamic_cast<Fl_Window&>(this->widget()).x() - this->GetDecorationSize().Width / 2, dynamic_cast<Fl_Window&>(this->widget()).y() - this->GetDecorationSize().Height + this->GetDecorationSize().Width / 2);
}

void Control::PerformLayout() {
  int32 top = 0;
  int32 left = 0;
  int32 right = (this->size - this->GetDecorationSize()).Width;
  int32 bottom = (this->size - this->GetDecorationSize()).Height;

  for(Reference<Control> control : this->controls) {
    if (control().suspendLayout != 0)
      continue;
    if (control().Dock == DockStyle::Fill) {
      control().location = System::Drawing::Point(left, top);
      control().size = System::Drawing::Size(right - left, bottom - top);
    } else if (control().Dock == DockStyle::Left) {
      control().location = System::Drawing::Point(left, top);
      control().size = System::Drawing::Size(control().Width, bottom - top);
      left += control().Width;
    } else if (control().Dock == DockStyle::Top) {
      control().location = System::Drawing::Point(left, top);
      control().size = System::Drawing::Size(right - left, control().Height);
      top += control().Height;
    } else if (control().Dock == DockStyle::Right) {
      control().location = System::Drawing::Point(right - control().Width, top);
      control().size = System::Drawing::Size(control().Width, bottom - top);
      right -= control().Width;
    } else if (control().Dock == DockStyle::Bottom) {
      control().location = System::Drawing::Point(left, bottom - control().Height);
      control().size = System::Drawing::Size(right - left, control().Height);
      bottom -= control().Height;
    } else if (this->previousClientSize != System::Drawing::Size::Empty) {
      if (Enum<AnchorStyles>(control().Anchor).HasFlag(AnchorStyles::Right)) {
        if (Enum<AnchorStyles>(control().anchor).HasFlag(AnchorStyles::Left))
          control().size += System::Drawing::Size(this->clientSize.Width - this->previousClientSize.Width, 0);
        else
          control().location += System::Drawing::Size(this->clientSize.Width - this->previousClientSize.Width, 0);
      }
      
      if (Enum<AnchorStyles>(control().anchor).HasFlag(AnchorStyles::Bottom)) {
        if (Enum<AnchorStyles>(control().anchor).HasFlag(AnchorStyles::Top))
          control().size += System::Drawing::Size(0, this->clientSize.Height - this->previousClientSize.Height);
        else
          control().location += System::Drawing::Size(0, this->clientSize.Height - this->previousClientSize.Height);
      }
    }

    control().previousClientSize = control().clientSize;
    control().clientSize = control().size - control().GetDecorationSize();
    control().PerformLayoutIfNotSuspend();
  }

  this->previousClientSize = this->clientSize;
  //System::Diagnostics::Debug::WriteLine(string::Format("{{Name={0}, Location={1}, Size={2}, ClientSize={3}, DecorationSize={4}}}", this->Name, this->Location, this->Size, this->ClientSize, this->GetDecorationSize()));
  Widget::ToWidget(this->widget()).position(this->PointToForm(this->location).X + this->GetDecorationSize().Width / 2, this->PointToForm(this->location).Y + this->GetDecorationSize().Height - this->GetDecorationSize().Width / 2);
  Widget::ToWidget(this->widget()).size(this->clientSize.Width, this->clientSize.Height);
  this->Invalidate();
}

System::Drawing::Point Control::PointToClient(const System::Drawing::Point point) const {
  System::Drawing::Point pointToClient = point - this->Location();
  Reference<Control> control = *this;
  while (control().parent != null && !is<Form>(control().parent)) {
    control = *control().parent;
    pointToClient -= control().Location();
  }
  
  if (control().parent != null)
    pointToClient -= control().parent->Location();

  return pointToClient;
}

System::Drawing::Point Control::PointToScreen(const System::Drawing::Point point) const {
  System::Drawing::Point pointToScreen = point + this->Location();
  Reference<Control> control = *this;
  while (control().parent != null && !is<Form>(control().parent)) {
    control = *control().parent;
    pointToScreen += control().Location();
  }
  
  if (control().parent != null)
    pointToScreen += control().parent->Location();
  
  return pointToScreen;
}

System::Drawing::Point Control::PointToForm(const System::Drawing::Point point) const {
  System::Drawing::Point pointToForm = point;
  Reference<Control> control = *this;
  while (control().parent != null && !is<Form>(control().parent)) {
    control = *control().parent;
    pointToForm += control().Location();
  }
  return pointToForm;
}

void Control::SetAccessibleDefaultActionDescription(const string& accessibleDefaultActionDescription) {
  this->accessibleDefaultActionDescription = accessibleDefaultActionDescription;
}

void Control::SetAccessibleDescription(const string& accessibleDescription) {
  this->accessibleDescription = accessibleDescription;
}

void Control::SetAccessibleName(const string& accessibleName) {
  this->accessibleName = accessibleName;
}

void Control::SetAllowDrop(bool allowDrop) {
  this->allowDrop = allowDrop;
}

void Control::SetAnchor(AnchorStyles anchor) {
  this->anchor = anchor;
}

void Control::SetAutoScrollOffset(const System::Drawing::Point& autoScrollOffset) {
  this->autoScrollOffset = autoScrollOffset;
}

void Control::SetAutoSize(bool autoSize) {
  this->autoSize = autoSize;
  if (this->parent)
    this->parent->PerformLayoutIfNotSuspend();
  else
    this->PerformLayoutIfNotSuspend();
  this->OnAutoSizeChanged(EventArgs());
}

void Control::SetBackColor(const System::Drawing::Color& color) {
  if (this->backColor != color) {
    this->backColor = color;
    Widget::ToWidget(this->widget()).color(Fltk::Helper::ToFlColor(color));
    Widget::ToWidget(this->widget()).redraw();
    this->OnBackColorChanged(EventArgs());
  }
}

const Drawing::Image& Control::GetBackgroundImage() const {
  return this->backgroundImage;
}

void Control::SetBackgroundImage(const Drawing::Image& backgroundImage) {
  this->backgroundImage = backgroundImage;
  this->BackgroundImageChanged(*this, EventArgs());
}

ImageLayout Control::GetBackgroundImageLayout() const {
  return this->backgroundImageLayout;
}

void Control::SetBackgroundImageLayout(ImageLayout backgroundImageLayout) {
  if (this->backgroundImageLayout != backgroundImageLayout) {
    this->backgroundImageLayout = backgroundImageLayout;
    this->BackgroundImageLayoutChanged(*this, EventArgs());
  }
}

bool Control::GetCanEnableIme() const {
  return true;
}

bool Control::GetCausesValidation() const {
  return this->causesValidation;
}

void Control::SetCausesValidation(bool causesValidation) {
  if (this->causesValidation != causesValidation) {
    this->causesValidation = causesValidation;
    this->CausesValidationChanged(*this, EventArgs());
  }
}

void Control::SetClientSize(const System::Drawing::Size& clientSize) {
  if (this->clientSize != clientSize) {
    this->previousClientSize = this->ClientSize;
    this->clientSize = clientSize;
    this->SetSize(this->clientSize + this->GetDecorationSize());
    if (this->parent)
      this->parent->PerformLayoutIfNotSuspend();
    else
      this->PerformLayoutIfNotSuspend();
    this->OnClientSizeChanged(EventArgs());
  }
}

const System::Windows::Forms::Cursor& Control::GetCursor() const {
  return this->cursor;
}

void Control::SetCursor(const System::Windows::Forms::Cursor& cursor) {
  if (this->cursor != cursor) {
    this->cursor = cursor;
    this->CursorChanged(*this, EventArgs());
  }
}

Drawing::Size Control::GetDecorationSize() const {
  return System::Drawing::Size(0, 0);
}

const System::Windows::Forms::Cursor& Control::GetDefaultCursor() const {
  return this->defaultCursor;
}
DockStyle Control::GetDock() const {
  return this->dock;
}

void Control::SetDock(DockStyle dock) {
  this->dock = dock;
  if (this->parent)
    this->parent->PerformLayoutIfNotSuspend();
  else
    this->PerformLayoutIfNotSuspend();
}

bool Control::GetEnabled() const {
  return this->enabled;
}

void Control::SetEnabled(bool enabled) {
  if (this->enabled != enabled) {
    this->enabled = enabled;
    if (this->enabled)
      Widget::ToWidget(this->widget()).activate();
    else
      Widget::ToWidget(this->widget()).deactivate();
    this->EnabledChanged(*this, EventArgs());
  }
}

bool Control::GetFocused() const {
  return Fl::focus() == &Widget::ToWidget(this->widget());
}

const System::Drawing::Font& Control::GetFont() const {
  return this->font;
}

void Control::SetFont(const System::Drawing::Font& font) {
  if (this->font != font) {
    this->font = font;
    Widget::ToWidget(this->widget()).labelfont((int32)this->font.ToHFont());
    Widget::ToWidget(this->widget()).labelsize(this->font.Size());

    if (this->autoSize)
      this->Size = this->GetComputeSize().ToSize();
    
    this->Invalidate();
    this->FontChanged(*this, EventArgs());
  }
}

void Control::SetForeColor(const System::Drawing::Color& color) {
  if (this->foreColor != color) {
    this->foreColor = color;
    Widget::ToWidget(this->widget()).labelcolor(Fltk::Helper::ToFlColor(color));
    Widget::ToWidget(this->widget()).redraw_label();
    this->OnForeColorChanged(EventArgs());
  }
}

const IWidget& Control::GetHandle() const {
  return this->widget();
}

void Control::SetLocation(const System::Drawing::Point& location) {
  if (this->location != location) {
    this->location = location;
    if (this->parent)
      this->parent->PerformLayoutIfNotSuspend();
    else
      this->PerformLayoutIfNotSuspend();
    this->OnLocationChanged(EventArgs());
  }
}

const string& Control::GetName() const {
  return this->name;
}

void Control::SetName(const string& name) {
  this->name = name;
}

const Control& Control::GetParent() const {
  return *this->parent;
}

void Control::SetParent(const Control& parent) {
  if (this->parent != null)
    this->parent->controls.Remove(*this);
  const_cast<Control&>(parent).controls.Add(*this);
}

/*
void Control::RemoveParent() {
  if (this->parent != null)
    this->parent->controls.Remove(*this);
}*/

void Control::SetSize(Drawing::Size size) {
  if (this->size != size) {
    this->size = size;
    this->SetClientSize(this->size - this->GetDecorationSize());
    if (this->parent)
      this->parent->PerformLayoutIfNotSuspend();
    else
      this->PerformLayoutIfNotSuspend();
    this->OnSizeChanged(EventArgs());
  }
}

string Control::GetText() const {
  return this->text;
}

void Control::SetText(const string& text) {
  if (text != this->text) {
    this->text = text;
    Widget::ToWidget(this->widget()).copy_label(this->text.Data());
    //Widget::ToWidget(this->widget()).redraw_label();
    this->OnTextChanged(EventArgs());
  }
}

bool Control::GetVisible() const {
  return this->visible;
}

void Control::SetVisible(bool visible) {
  if (this->visible != visible) {
    this->visible = visible;
    if (this->visible) {
      this->PerformLayoutIfNotSuspend();
      Widget::ToWidget(this->widget()).show();
    } else
      Widget::ToWidget(this->widget()).hide();
    this->VisibleChanged(*this, EventArgs());
  }
}

bool Control::Focus() {
  if (!this->CanFocus)
    return false;
  
  Fl::focus(&Widget::ToWidget(this->widget()));
  this->Invalidate();
  return true;
  //return Widget::ToWidget(this->widget()).take_focus() != 0;
}

SizeF Control::GetComputeSize() const {
  return this->graphics.MeasureString(this->Text(), this->Font());
}
