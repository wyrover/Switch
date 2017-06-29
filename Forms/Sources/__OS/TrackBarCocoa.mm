#if defined(__APPLE__)
#include "WindowProcedureCocoa.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

@interface SliderCocoa : NSSlider
- (IBAction) ValueChanged:(id)sender;
@end

@implementation SliderCocoa
- (IBAction) ValueChanged:(id)sender {
  Message event = Message::Create((intptr)sender, [self isVertical] ? WM_VSCROLL : WM_HSCROLL, 0, (intptr)sender, 0, 0);
  __OS::WindowProcedure::Controls[(intptr)sender]().Parent()().WndProc(event);
}
@end

intptr FormsApi::TrackBar::Create(const System::Windows::Forms::TrackBar& trackBar) {
  @autoreleasepool {
    SliderCocoa* handle = [[[SliderCocoa alloc] init] autorelease];
    [[(NSWindow*)trackBar.Parent()().Handle() contentView] addSubview: handle];
    __OS::WindowProcedure::Controls[(intptr)handle] = trackBar;
    [handle setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
    [handle setTarget:handle];
    [handle setAction:@selector(ValueChanged:)];

    //[handle setIndeterminate:trackBar.Style == ProgressBarStyle::Marquee];
    Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, IntPtr::Zero);
    const_cast<System::Windows::Forms::TrackBar&>(trackBar).WndProc(message);
    return (intptr)handle;
  }
}

void FormsApi::TrackBar::SetLargeChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void FormsApi::TrackBar::SetMaximum(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setMaxValue:trackBar.Maximum()];
}

void FormsApi::TrackBar::SetMinimum(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setMinValue:trackBar.Minimum()];
}

void FormsApi::TrackBar::SetOrientation(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setVertical:trackBar.Orientation == Orientation::Vertical];
}

void FormsApi::TrackBar::SetSmallChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void FormsApi::TrackBar::SetTickFrequency(const System::Windows::Forms::TrackBar& trackBar) {
  if (trackBar.Style != TickStyle::None)
    [(NSSlider*)trackBar.Handle() setNumberOfTickMarks:(trackBar.Maximum - trackBar.Minimum) / trackBar.TickFrequency];
}

void FormsApi::TrackBar::SetTickStyle(const System::Windows::Forms::TrackBar& trackBar) {
  if (trackBar.Style == TickStyle::TopLeft)
    [(NSSlider*)trackBar.Handle() setTickMarkPosition:NSTickMarkPositionAbove];
}

int32 FormsApi::TrackBar::GetValue(const System::Windows::Forms::TrackBar& trackBar) {
  return [(NSSlider*)trackBar.Handle() integerValue];
}

void FormsApi::TrackBar::SetValue(const System::Windows::Forms::TrackBar& trackBar) {
  [(NSSlider*)trackBar.Handle() setIntegerValue:trackBar.Value()];
}

#endif
