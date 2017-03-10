#include <Pcf/System/BitConverter.h>
#include <Pcf/System/Drawing/Graphics.h>
#include <Pcf/System/Drawing/SolidBrush.h>
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Form.h"
#include "../../../../__OS/FormsApi.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

System::Collections::Generic::Dictionary<intptr, Reference<Control>> Control::handles;

namespace {
  struct ShowDebugTrace {
    static constexpr bool AllWindowMessages = false;
    static constexpr bool MouseWindowMessage = false;
    static constexpr bool WindowMessage = false;
  };

  MouseButtons MessageToMouseButtons(Message message) {
    //constexpr int MK_XBUTTON1 = 0x0020;
    constexpr int MK_XBUTTON2 = 0x0040;

    if (message.Msg == WM_LBUTTONDBLCLK || message.Msg == WM_LBUTTONDOWN || message.Msg == WM_RBUTTONUP)
      return MouseButtons::Left;
    else if (message.Msg == WM_RBUTTONDBLCLK || message.Msg == WM_RBUTTONDOWN || message.Msg == WM_RBUTTONUP)
      return MouseButtons::Right;
    else if (message.Msg == WM_MBUTTONDBLCLK || message.Msg == WM_MBUTTONDOWN || message.Msg == WM_MBUTTONUP)
      return MouseButtons::Middle;
    else if (message.Msg == WM_XBUTTONDBLCLK || message.Msg == WM_XBUTTONDOWN || message.Msg == WM_XBUTTONUP)
      return (message.WParam() & MK_XBUTTON2) == MK_XBUTTON2 ? MouseButtons::XButton2 : MouseButtons::XButton1;
    return MouseButtons::None;
  }

  System::Drawing::Point MakePoint(intptr lParam) {
    Array<byte> bytes = BitConverter::GetBytes(lParam);
    return System::Drawing::Point(BitConverter::ToInt16(bytes, 0), BitConverter::ToInt16(bytes, 2));
  }
}

Reference<Control> Control::controlEntered;

Control::Control() {
  this->data->messageActions = {{WM_CAPTURECHANGED,{*this, &Control::WmCaptureChange}},{WM_CLOSE,{*this, &Control::WmClose}},{WM_COMMAND,{*this, &Control::WmCommand}},{WM_CONTEXTMENU,{*this, &Control::WmContextMenu}},{WM_CREATE,{*this, &Control::WmCreate}},{WM_CTLCOLOR,{*this, &Control::WmCtlColorControl}},{WM_CTLCOLORBTN,{*this, &Control::WmCtlColorControl}},{WM_CTLCOLORDLG,{*this, &Control::WmCtlColorControl}},{WM_CTLCOLORMSGBOX,{*this, &Control::WmCtlColorControl}},{WM_CTLCOLORSCROLLBAR,{*this, &Control::WmCtlColorControl}},{WM_CTLCOLOREDIT,{*this, &Control::WmCtlColorControl}},{WM_CTLCOLORLISTBOX,{*this, &Control::WmCtlColorControl}},{WM_CTLCOLORSTATIC,{*this, &Control::WmCtlColorControl}},{WM_DESTROY,{*this, &Control::WmDestroy}},{WM_DISPLAYCHANGE,{*this, &Control::WmDisplayChange}},{WM_DRAWITEM,{*this, &Control::WmDrawItem}},{WM_ERASEBKGND,{*this, &Control::WmEraseBkgnd}},{WM_EXITMENULOOP,{*this, &Control::WmExitMenuLoop}},{WM_GETOBJECT,{*this, &Control::WmGetObject}},{WM_HELP,{*this, &Control::WmHelp}},{WM_IME_CHAR,{*this, &Control::WmImeChar}},{WM_IME_NOTIFY,{*this, &Control::WmImeNotify}},{WM_IME_STARTCOMPOSITION,{*this, &Control::WmImeStartComposition}},{WM_INITMENUPOPUP,{*this, &Control::WmInitMenuPopup}},{WM_INPUTLANGCHANGE,{*this, &Control::WmInputLangChange}},{WM_INPUTLANGCHANGEREQUEST,{*this, &Control::WmInputLangChangeRequest}},{WM_CHAR,{*this, &Control::WmKeyChar}},{WM_KEYDOWN,{*this, &Control::WmKeyChar}},{WM_SYSKEYDOWN,{*this, &Control::WmKeyChar}},{WM_KEYUP,{*this, &Control::WmKeyChar}},{WM_SYSKEYUP,{*this, &Control::WmKeyChar}},{WM_KILLFOCUS,{*this, &Control::WmKillFocus}},{WM_MEASUREITEM,{*this, &Control::WmMeasureItem}},{WM_MENUCHAR,{*this, &Control::WmMenuChar}},{WM_MENUSELECT,{*this, &Control::WmMenuSelect}},{WM_LBUTTONDBLCLK,{*this, &Control::WmMouseDown}},{WM_LBUTTONDOWN,{*this, &Control::WmMouseDown}},{WM_MBUTTONDBLCLK,{*this, &Control::WmMouseDown}},{WM_MBUTTONDOWN,{*this, &Control::WmMouseDown}},{WM_XBUTTONDOWN,{*this, &Control::WmMouseDown}},{WM_XBUTTONDBLCLK,{*this, &Control::WmMouseDown}},{WM_RBUTTONDBLCLK,{*this, &Control::WmMouseDown}},{WM_RBUTTONDOWN,{*this, &Control::WmMouseDown}},{WM_MOUSEHOVER,{*this, &Control::WmMouseHover}},{WM_MOUSELEAVE,{*this, &Control::WmMouseLeave}},{WM_NCMOUSELEAVE,{*this, &Control::WmMouseLeave}},{WM_MOUSEMOVE,{*this, &Control::WmMouseMove}},{WM_LBUTTONUP,{*this, &Control::WmMouseUp}},{WM_MBUTTONUP,{*this, &Control::WmMouseUp}},{WM_XBUTTONUP,{*this, &Control::WmMouseUp}},{WM_RBUTTONUP,{*this, &Control::WmMouseUp}},{WM_MOUSEWHEEL,{*this, &Control::WmMouseWheel}},{WM_NOTIFY,{*this, &Control::WmNotify}},{WM_NOTIFYFORMAT,{*this, &Control::WmNotifyFormat}},{WM_PARENTNOTIFY,{*this, &Control::WmParentNotify}},{WM_PAINT,{*this, &Control::WmPaint}},{WM_PRINTCLIENT,{*this, &Control::WmPrintClient}},{WM_QUERYNEWPALETTE,{*this, &Control::WmQueryNewPalette}},{WM_SHOWWINDOW,{*this, &Control::WmShowWindow}},{WM_SETCURSOR,{*this, &Control::WmSetCursor}},{WM_SETFOCUS,{*this, &Control::WmSetFocus}},{WM_SYSCOMMAND,{*this, &Control::WmSysCommand}},{WM_UPDATEUISTATE,{*this, &Control::WmUpdateUIState}},{WM_WINDOWPOSCHANGED,{*this, &Control::WmWindowPosChanged}},{WM_WINDOWPOSCHANGING,{*this, &Control::WmWindowPosChanging}}};
  // For message : WM_CTLCOLOR, WM_CTLCOLORBTN, WM_CTLCOLORDLG, WM_CTLCOLORMSGBOX, WM_CTLCOLORSCROLLBAR, WM_CTLCOLOREDIT, WM_CTLCOLORLISTBOX, WM_CTLCOLORSTATIC do create reflect message internal ?
  // For message : WM_HSCROLL, WM_VSCROLL, WM_DELETEITEM, WM_VKEYTOITEM, WM_CHARTOITEM, WM_COMPAREITEM do create reflect message internal ?
  // For message : WM_NOTIFYFORMAT do create reflect message internal ?
  SetStyle(ControlStyles((int32)ControlStyles::AllPaintingInWmPaint | (int32)ControlStyles::UserPaint | (int32)ControlStyles::StandardClick | (int32)ControlStyles::StandardDoubleClick | (int32)ControlStyles::UseTextForAccessibility | (int32)ControlStyles::Selectable), true);
}

Property<System::Drawing::Color, ReadOnly> Control::DefaultBackColor {
  [] { return System::Drawing::SystemColors::Control(); }
};

Property<System::Drawing::Color, ReadOnly> Control::DefaultForeColor {
  [] { return System::Drawing::SystemColors::ControlText(); }
};

void Control::CreateHandle() {
  if (!this->data->handle)
    this->data->handle = __OS::FormsApi::Control::Create(*this);
  handles[this->data->handle] = *this;
}

void Control::DestroyHandle() {
  handles.Remove(this->data->handle);
  __OS::FormsApi::Control::Destroy(*this);
  this->data->handle = 0;
}

void Control::DefWndProc(Message& message) {
  __OS::FormsApi::Control::DefWndProc(message);
}

void Control::Invalidate(bool invalidateChildren) {
  __OS::FormsApi::Control::Invalidate(*this, invalidateChildren);
  this->OnInvalidated(InvalidateEventArgs(this->GetClientRectangle()));
}

void Control::Invalidate(const System::Drawing::Rectangle& rect, bool invalidateChildren) {
  __OS::FormsApi::Control::Invalidate(*this, rect, invalidateChildren);
  this->OnInvalidated(InvalidateEventArgs(rect));
}

void Control::OnBackColorChanged(const EventArgs& e) {
  __OS::FormsApi::Control::SetBackColor(*this, this->BackColor);
  this->Invalidate();
  this->BackColorChanged(*this, e);
}

void Control::OnForeColorChanged(const EventArgs& e) {
  __OS::FormsApi::Control::SetBackColor(*this, this->ForeColor);
  this->Invalidate();
  this->ForeColorChanged(*this, e);
}

void Control::OnLocationChanged(const EventArgs& e) {
  __OS::FormsApi::Control::SetLocation(*this);
  this->LocationChanged(*this, e); 
}

void Control::OnSizeChanged(const EventArgs& e) {
  __OS::FormsApi::Control::SetSize(*this);
  this->SizeChanged(*this, e); 
}

void Control::OnTextChanged(const EventArgs& e) {
  __OS::FormsApi::Control::SetText(*this);
  this->TextChanged(*this, e); 
}

void Control::OnVisibleChanged(const EventArgs& e) {
  if (this->data->visible == true)
    CreateControl();
  __OS::FormsApi::Control::SetVisible(*this);
  this->VisibleChanged(*this, e);
}

System::Drawing::Point Control::PointToClient(System::Drawing::Point point) const {
  return __OS::FormsApi::Control::PointToClient(*this, point);
}

System::Drawing::Point Control::PointToScreen(System::Drawing::Point point) const {
  return __OS::FormsApi::Control::PointToScreen(*this, point);
}

bool Control::PreProcessMessage(const Message& msg) {
  return true;
}

void Control::WndProc(Message& message) {
  if (!this->GetState(State::WndProcRunning) && this->data->messageActions.ContainsKey(message.Msg)) {
    SetState(State::WndProcRunning, true);
    System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::AllWindowMessages, "Control::WndProc message=" + message + ", name=" + this->data->name);
    this->data->messageActions[message.Msg](message);
  } else {
    System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::AllWindowMessages, "DefWndProc message=" + message + ", name=" + this->data->name);
    this->DefWndProc(message);
  }
  SetState(State::WndProcRunning, false);
}

void Control::WmCaptureChange(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCaptureChange message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
  this->OnMouseCaptureChanged(EventArgs::Empty);
}

void Control::WmClose(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmClose message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmCommand(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCommand message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmContextMenu(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmContextMenu message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmCreate(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCreate message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
  OnHandleCreated(EventArgs::Empty);
}

#include <windows.h>

void Control::WmCtlColorControl(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmCtlColorControl message=" + message + ", name=" + this->data->name);
  //this->DefWndProc(message);
  //__OS::FormsApi::Control::SetBackColor(*this, this->BackColor);
  //__OS::FormsApi::Control::SetForeColor(*this, this->ForeColor);

  if (this->data->name != "label1") {
    this->DefWndProc(message);
    return;
  }
  
  SetBkColor((HDC)message.WParam(), RGB(this->BackColor().R(), this->BackColor().G(), this->BackColor().B()));
  SetTextColor((HDC)message.WParam(), RGB(this->ForeColor().R(), this->ForeColor().G(), this->ForeColor().B()));
  message.Result = (intptr)GetSysColorBrush(COLOR_BTNFACE);
}

void Control::WmDestroy(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmDestroy message=" + message + ", name=" + this->data->name);
  OnHandleDestroyed(EventArgs::Empty);
  this->DefWndProc(message);
}

void Control::WmDisplayChange(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmDisplayChange message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmDrawItem(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmDrawItem message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmEraseBkgnd(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmEraseBkgnd message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmExitMenuLoop(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmExitMenuLoop message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmGetObject(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmGetObject message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmHelp(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmHelp message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmImeChar(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmImeChar message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmImeNotify(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmImeNotify message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmImeStartComposition(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmImeStartComposition message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmInitMenuPopup(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmInitMenuPopup message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmInputLangChange(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmInputLangChange message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmInputLangChangeRequest(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmInputLangChangeRequest message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmKeyChar(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmKeyChar message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmKillFocus(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmKillFocus message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
  this->OnLostFocus(EventArgs::Empty);
}

void Control::WmMeasureItem(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmMeasureItem message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmMenuChar(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmMenuChar message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmMenuSelect(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmMenuSelect message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmMouseDown(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseDown message=" + message + ", name=" + this->data->name);
  SetState(State::DoubleClickFired, message.Msg == WM_LBUTTONDBLCLK || message.Msg == WM_RBUTTONDBLCLK || message.Msg == WM_MBUTTONDBLCLK || message.Msg == WM_XBUTTONDBLCLK);
  this->DefWndProc(message);
  this->OnMouseDown(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), this->GetState(State::DoubleClickFired) ? 2 : 1, 0));
}

void Control::WmMouseEnter(Message& message) {
  if (controlEntered && is<Form>(controlEntered)) {
    Message messageMouseLeave = Message::Create(controlEntered().Handle, WM_MOUSELEAVE, message.WParam, message.LParam, 0);
    controlEntered().WmMouseLeave(messageMouseLeave);
  }
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseEnter message=" + message + ", name=" + this->data->name);
  this->SetState(State::MouseEntered, true);
  controlEntered = *this;
  this->DefWndProc(message);
  this->OnMouseEnter(EventArgs::Empty);
}

void Control::WmMouseHover(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseHover message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
  this->OnMouseHover(EventArgs::Empty);
}

void Control::WmMouseLeave(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseLeave message=" + message + ", name=" + this->data->name);
  this->SetState(State::MouseEntered, false);
  controlEntered = null;
  this->DefWndProc(message);
  this->OnMouseLeave(EventArgs::Empty);
}

void Control::WmMouseMove(Message& message) {
  if (!this->GetState(State::MouseEntered)) {
    Message messageMouseEnter = Message::Create(message.HWnd, WM_MOUSEENTER, message.WParam, message.LParam, 0);
    this->WmMouseEnter(messageMouseEnter);
  }
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseMove message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
  this->OnMouseMove(MouseEventArgs(MouseButtons::None, MakePoint(message.LParam()), 0, 0));
}

void Control::WmMouseUp(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseUp message=" + message + ", name=" + this->data->name);
  if (this->GetState(State::DoubleClickFired)) {
    this->OnMouseDoubleClick(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), 2, 0));
    this->OnDoubleClick(EventArgs::Empty);
  } else {
    this->OnMouseClick(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), 1, 0));
    this->OnClick(EventArgs::Empty);
  }
  this->DefWndProc(message);
  this->OnMouseUp(MouseEventArgs(MessageToMouseButtons(message), MakePoint(message.LParam()), 1, 0));
}

void Control::WmMouseWheel(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::MouseWindowMessage, "Control::WmMouseWheel message=" + message + ", name=" + this->data->name);
  System::Drawing::Point point = this->PointToClient(MakePoint(message.LParam));
  Array<byte> bytes = BitConverter::GetBytes(message.WParam());
  this->DefWndProc(message);
  OnMouseWheel(MouseEventArgs(MouseButtons::None, point, 0, BitConverter::ToInt16(bytes, 2)));
}

void Control::WmNotify(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmNotify message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmNotifyFormat(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmNotifyFormat message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmPaint(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmPaint message=" + message + ", name=" + this->data->name);
  if (this->GetStyle(ControlStyles::UserPaint)) {
  } else {
    this->DefWndProc(message);
    Graphics graphics = Graphics::FromHwndInternal(this->data->handle);
    System::Drawing::Rectangle clipRectangle(graphics.ClipBounds().Left, graphics.ClipBounds().Top, graphics.ClipBounds().Right, graphics.ClipBounds().Bottom);
    PaintEventArgs paintEventArgs(clipRectangle, graphics);
    this->OnPaint(paintEventArgs);
  }
}

void Control::WmParentNotify(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmParentNotify message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmPrintClient(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmPrintClient message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmQueryNewPalette(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmQueryNewPalette message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmShowWindow(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmShowWindow message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmSetCursor(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmSetCursor message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmSetFocus(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmSetFocus message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmSysCommand(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmSysCommand message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmUpdateUIState(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmUpdateUIState message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmWindowPosChanged(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmWindowPosChanged message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

void Control::WmWindowPosChanging(Message& message) {
  System::Diagnostics::Debug::WriteLineIf(ShowDebugTrace::WindowMessage, "Control::WmWindowPosChanging message=" + message + ", name=" + this->data->name);
  this->DefWndProc(message);
}

System::Drawing::Rectangle Control::GetClientRectangle() const {
  return System::Drawing::Rectangle();
}