#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace PcfFormApp {
  class UserControl : public Control {
  public:
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
      this->Name = "form1";
      this->Text = "First Application";
      this->Location = System::Drawing::Point(200, 100);
      //this->Size = System::Drawing::Size(640, 480);
      this->MouseClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("form1 Clicked at {0}", e.Location);
      };
      this->MouseWheel += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("Form::MouseWheel Location={0}, Delta={1}", e.Location, e.Delta);
      };

      this->button1.Parent = *this;
      this->button1.Name = "button1";
      this->button1.Text = "Button";
      this->button1.Location = System::Drawing::Point(10, 10);
      this->button1.MouseClick += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("Button::MouseClick at {0}", e.Location);
        this->label1.Text = this->button1.PointToScreen(e.Location).ToString();
      };
      this->button1.MouseWheel += pcf_delegate(const object& sender, const MouseEventArgs& e) {
        System::Diagnostics::Debug::WriteLine("Button::MouseWheel Location={0}, Delta={1}", e.Location, e.Delta);
      };
      
      this->checkBox1.Parent = *this;
      this->checkBox1.Name = "checkBox1";
      this->checkBox1.Text = "CheckBox";
      this->checkBox1.Location = System::Drawing::Point(10, 40);
      
      this->radioButton1.Parent = *this;
      this->radioButton1.Name = "radioButton1";
      this->radioButton1.Text = "RadioButton";
      this->radioButton1.Location = System::Drawing::Point(10, 70);
      
      this->radioButton2.Parent = *this;
      this->radioButton2.Name = "radioButton2";
      this->radioButton2.Text = "RadioButton 2";
      this->radioButton2.Location = System::Drawing::Point(10, 100);
      this->radioButton2.Size = System::Drawing::Size(120, 25);

      this->label1.Parent = *this;
      this->label1.Name = "label1";
      this->label1.Text = "Text label";
      this->label1.Location = System::Drawing::Point(10, 130);
      this->label1.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        System::Diagnostics::Debug::WriteLine("this->label1 Clicked !");
      };

      this->userControl1.Parent = *this;
      this->userControl1.Name = "userControl1";
      this->userControl1.Bounds = System::Drawing::Rectangle(10, 160, 200, 200);

      //this->FormBorderStyle = FormBorderStyle::None;
      
      //Application::Idle += pcf_delegate(const object sender, const EventArgs e) {
      //  this->button1.Text = string::Format("{0}", ++counter);
      //};

      System::Diagnostics::Debug::WriteLine("ActiveWindowTrackingDelay = {0}", SystemInformation::ActiveWindowTrackingDelay, null);
      System::Diagnostics::Debug::WriteLine("ArrangeDirection = {0}", SystemInformation::ArrangeDirection, null);
      System::Diagnostics::Debug::WriteLine("ArrangeStartingPosition = {0}", SystemInformation::ArrangeStartingPosition, null);
      System::Diagnostics::Debug::WriteLine("BootMode = {0}", SystemInformation::BootMode, null);
      System::Diagnostics::Debug::WriteLine("Border3DSize = {0}", SystemInformation::Border3DSize, null);
      System::Diagnostics::Debug::WriteLine("BorderMultiplierFactor = {0}", SystemInformation::BorderMultiplierFactor, null);
      System::Diagnostics::Debug::WriteLine("BorderSize = {0}", SystemInformation::BorderSize, null);
      System::Diagnostics::Debug::WriteLine("CaptionButtonSize  = {0}", SystemInformation::CaptionButtonSize, null);
      System::Diagnostics::Debug::WriteLine("CaptionHeight = {0}", SystemInformation::CaptionHeight, null);
      System::Diagnostics::Debug::WriteLine("CaretBlinkTime = {0}", SystemInformation::CaretBlinkTime, null);
      System::Diagnostics::Debug::WriteLine("CaretWidth = {0}", SystemInformation::CaretWidth, null);
      System::Diagnostics::Debug::WriteLine("ComputerName = {0}", SystemInformation::ComputerName, null);
      System::Diagnostics::Debug::WriteLine("CursorSize = {0}", SystemInformation::CursorSize, null);
      System::Diagnostics::Debug::WriteLine("DbcsEnabled = {0}", SystemInformation::DbcsEnabled, null);
      System::Diagnostics::Debug::WriteLine("DebugOS = {0}", SystemInformation::DebugOS, null);
      System::Diagnostics::Debug::WriteLine("DoubleClickSize = {0}", SystemInformation::DoubleClickSize, null);
      System::Diagnostics::Debug::WriteLine("DoubleClickTime = {0}", SystemInformation::DoubleClickTime, null);
      System::Diagnostics::Debug::WriteLine("DragFullWindows = {0}", SystemInformation::DragFullWindows, null);
      System::Diagnostics::Debug::WriteLine("DragSize = {0}", SystemInformation::DragSize, null);
      System::Diagnostics::Debug::WriteLine("FixedFrameBorderSize = {0}", SystemInformation::FixedFrameBorderSize, null);
      System::Diagnostics::Debug::WriteLine("FontSmoothingContrast = {0}", SystemInformation::FontSmoothingContrast, null);
      System::Diagnostics::Debug::WriteLine("FontSmoothingType = {0}", SystemInformation::FontSmoothingType, null);
      System::Diagnostics::Debug::WriteLine("FrameBorderSize = {0}", SystemInformation::FrameBorderSize, null);
      System::Diagnostics::Debug::WriteLine("HighContrast = {0}", SystemInformation::HighContrast, null);
      System::Diagnostics::Debug::WriteLine("HorizontalFocusThickness = {0}", SystemInformation::HorizontalFocusThickness, null);
      System::Diagnostics::Debug::WriteLine("HorizontalResizeBorderThickness = {0}", SystemInformation::HorizontalResizeBorderThickness, null);
      System::Diagnostics::Debug::WriteLine("HorizontalScrollBarArrowWidth = {0}", SystemInformation::HorizontalScrollBarArrowWidth, null);
      System::Diagnostics::Debug::WriteLine("HorizontalScrollBarHeight = {0}", SystemInformation::HorizontalScrollBarHeight, null);
      System::Diagnostics::Debug::WriteLine("HorizontalScrollBarThumbWidth = {0}", SystemInformation::HorizontalScrollBarThumbWidth, null);
      System::Diagnostics::Debug::WriteLine("IconHorizontalSpacing = {0}", SystemInformation::IconHorizontalSpacing, null);
      System::Diagnostics::Debug::WriteLine("IconSize = {0}", SystemInformation::IconSize, null);
      System::Diagnostics::Debug::WriteLine("IconSpacingSize = {0}", SystemInformation::IconSpacingSize, null);
      System::Diagnostics::Debug::WriteLine("IconVerticalSpacing = {0}", SystemInformation::IconVerticalSpacing, null);
      System::Diagnostics::Debug::WriteLine("IsActiveWindowTrackingEnabled = {0}", SystemInformation::IsActiveWindowTrackingEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsComboBoxAnimationEnabled = {0}", SystemInformation::IsComboBoxAnimationEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsDropShadowEnabled = {0}", SystemInformation::IsDropShadowEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsFlatMenuEnabled = {0}", SystemInformation::IsFlatMenuEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsFontSmoothingEnabled = {0}", SystemInformation::IsFontSmoothingEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsHotTrackingEnabled = {0}", SystemInformation::IsHotTrackingEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsIconTitleWrappingEnabled = {0}", SystemInformation::IsIconTitleWrappingEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsKeyboardPreferred = {0}", SystemInformation::IsKeyboardPreferred, null);
      System::Diagnostics::Debug::WriteLine("IsListBoxSmoothScrollingEnabled  = {0}", SystemInformation::IsListBoxSmoothScrollingEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsMenuAnimationEnabled  = {0}", SystemInformation::IsMenuAnimationEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsMenuFadeEnabled  = {0}", SystemInformation::IsMenuFadeEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsMinimizeRestoreAnimationEnabled = {0}", SystemInformation::IsMinimizeRestoreAnimationEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsSelectionFadeEnabled = {0}", SystemInformation::IsSelectionFadeEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsSnapToDefaultEnabled = {0}", SystemInformation::IsSnapToDefaultEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsTitleBarGradientEnabled = {0}", SystemInformation::IsTitleBarGradientEnabled, null);
      System::Diagnostics::Debug::WriteLine("IsToolTipAnimationEnabled = {0}", SystemInformation::IsToolTipAnimationEnabled, null);
      System::Diagnostics::Debug::WriteLine("KanjiWindowHeight = {0}", SystemInformation::KanjiWindowHeight, null);
      System::Diagnostics::Debug::WriteLine("KeyboardDelay = {0}", SystemInformation::KeyboardDelay, null);
      System::Diagnostics::Debug::WriteLine("KeyboardSpeed = {0}", SystemInformation::KeyboardSpeed, null);
      System::Diagnostics::Debug::WriteLine("MaxWindowTrackSize = {0}", SystemInformation::MaxWindowTrackSize, null);
      System::Diagnostics::Debug::WriteLine("MenuAccessKeysUnderlined = {0}", SystemInformation::MenuAccessKeysUnderlined, null);
      System::Diagnostics::Debug::WriteLine("MenuBarButtonSize = {0}", SystemInformation::MenuBarButtonSize, null);
      System::Diagnostics::Debug::WriteLine("MenuButtonSize = {0}", SystemInformation::MenuButtonSize, null);
      System::Diagnostics::Debug::WriteLine("MenuCheckSize = {0}", SystemInformation::MenuCheckSize, null);
      System::Diagnostics::Debug::WriteLine("MenuFont = {0}", SystemInformation::MenuFont, null);
      System::Diagnostics::Debug::WriteLine("MenuHeight = {0}", SystemInformation::MenuHeight, null);
      System::Diagnostics::Debug::WriteLine("_________________________________________________________________________________________________________");
      Array<System::Drawing::FontFamily> families = System::Drawing::FontFamily::Families;
      int count = 0;
	    for(auto family : families)
        System::Diagnostics::Debug::WriteLine("System::Drawing::FontFamily::Familes[{0}].Name={1}", count++, family.Name);
      System::Diagnostics::Debug::WriteLine("_________________________________________________________________________________________________________");
      System::Diagnostics::Debug::WriteLine("System::Drawing::FontFamily(\"Consolas\")={0}", System::Drawing::FontFamily("Consolas").Name, null);
      System::Diagnostics::Debug::WriteLine("System::Drawing::FontFamily::GenericMonospace().Name={0}", System::Drawing::FontFamily::GenericMonospace().Name, null);
      System::Diagnostics::Debug::WriteLine("System::Drawing::FontFamily::GenericSansSerif().Name={0}", System::Drawing::FontFamily::GenericSansSerif().Name, null);
      System::Diagnostics::Debug::WriteLine("System::Drawing::FontFamily::GenericSerif().Name={0}", System::Drawing::FontFamily::GenericSerif().Name, null);
    }

    /// @cond
    Form1(const Form1& form) = default;
    int counter = 0;
    /// @endcond

  private:
    Button button1;
    CheckBox checkBox1;
    RadioButton radioButton1;
    RadioButton radioButton2;
    Label label1;
    UserControl userControl1;
  };
}

pcf_startup (PcfFormApp::Form1)
