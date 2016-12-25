#include <FL/Fltk.h>
#include <Pcf/System/Environment.h>
#include <Pcf/System/Threading/Thread.h>
#include "../../../../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Form.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Label.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/ListBox.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Panel.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/PictureBox.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/RichTextBox.h"

#include "Stop.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

Control* Application::control = null;

Application::IdleEventHandler Application::Idle;

namespace SystemInformation {
  enum class CompilatorID {
    Unknown = -1,
    MicrosoftVisualStudio,
    Gcc,
    Xcode,
  };
}

namespace SystemInformation {
  enum class CompilatorMode {
    Release,
    Debug,
  };
}

namespace SystemInformation {
  enum class LibcID {
    Unknown = -1,
    Cpp98,
    Cpp11,
    Cpp14,
    Cpp17,
  };
}

/// @cond
template<>
class EnumToStrings<SystemInformation::CompilatorID> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SystemInformation::CompilatorID::Unknown, "Unknown"}, {(int64)SystemInformation::CompilatorID::MicrosoftVisualStudio, "MicrosoftVisualStudio"}, {(int64)SystemInformation::CompilatorID::Gcc, "Gcc"}, {(int64)SystemInformation::CompilatorID::Xcode, "Xcode"}};
    flags = false;
  }
};

template<>
class EnumToStrings<SystemInformation::CompilatorMode> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SystemInformation::CompilatorMode::Release, "Release"}, {(int64)SystemInformation::CompilatorMode::Debug, "Debug"}};
    flags = false;
  }
};

template<>
class EnumToStrings<SystemInformation::LibcID> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)SystemInformation::LibcID::Unknown, "Unknown"}, {(int64)SystemInformation::LibcID::Cpp98, "Cpp98"}, {(int64)SystemInformation::LibcID::Cpp11, "Cpp11"}, {(int64)SystemInformation::LibcID::Cpp14, "Cpp14"}, {(int64)SystemInformation::LibcID::Cpp17, "Cpp17"}};
    flags = false;
  }
};
/// @endcond

namespace SystemInformation {
  class OperatingSystemInfo : public object {
  public:
    static string Name() {
      static System::Collections::Generic::SortedDictionary<PlatformID, string> names = {{PlatformID::Win32S, "Microsoft Win32S "}, {PlatformID::Win32Windows, "Microsoft Windows 98 "}, {PlatformID::Win32NT, "Microsoft Windows NT "}, {PlatformID::WinCE, "Microsoft Windows CE "}, {PlatformID::Unix, "Unix "}, {PlatformID::Xbox, "Xbox "}, {PlatformID::MacOSX, "Mac OS X "}, {PlatformID::IOs, "iOS "}, {PlatformID::Android, "Android "}, {PlatformID::Unknown, "<Unknown> "}};
      if (!names.ContainsKey(ID()))
        return "<Unknown>";
      return names[ID()];
    }
    
    static Pcf::System::Version Version() { return Environment::OSVersion().Version(); }
    
    static PlatformID ID() { return Environment::OSVersion().Platform(); }
    
    static OperatingSystem OSVersion() { return Environment::OSVersion(); }
    
    static bool Is32Bits() { return !Environment::Is64BitOperatingSystem(); }
    
    static bool Is64Bits() { return Environment::Is64BitOperatingSystem(); }
    
  private:
    OperatingSystemInfo() {}
  };
  
  class LibcInfo : public object {
  public:
    static string Name() {
      static System::Collections::Generic::SortedDictionary<LibcID, string> names = {{LibcID::Cpp98, "Lib C++ 98"}, {LibcID::Cpp11, "Lib C++ 11"}, {LibcID::Cpp14, "Lib C++ 14"}, {LibcID::Cpp17, "Lib C++ 17"}, {LibcID::Unknown, "<unknown>"}};
      if (!names.ContainsKey(ID()))
        return "<Unknown>";
      return names[ID()];
    }
    
    static const System::Version& Version() {
      static System::Version ver(__cplusplus/100, __cplusplus%100);
      return ver;
    }
    
    static LibcID ID() {
      int32 cpp = __cplusplus;
      if (cpp >= 201103L)
        return LibcID::Cpp11;
      
      if (cpp >= 199711L)
        return LibcID::Cpp98;
      
      return LibcID::Unknown;
    }
    
    static bool IsCppSupported() { return ID() == LibcID::Cpp98 || ID() == LibcID::Cpp11; }
    
    static int32 GetYear() { return __cplusplus / 100; }
    
    static int32 GetMonth() { return __cplusplus % 100; }
    
  private:
    LibcInfo() {}
  };
  
  class CompilatorInfo : public object {
  public:
    static string Name() {
      static System::Collections::Generic::SortedDictionary<CompilatorID, string> names = {{CompilatorID::MicrosoftVisualStudio, "Microsoft Visual Studio"}, {CompilatorID::Gcc, "Gcc"}, {CompilatorID::Xcode, "Xcode"}, {CompilatorID::Unknown, "<Unknown>"}};
      if (!names.ContainsKey(ID()))
        return "<Unknown>";
      return names[ID()];
    }

#if __GNUC__
    static System::Version Version() {return System::Version(__GNUC__ , __GNUC_MINOR__, __GNUC_PATCHLEVEL__);}
#elif _MSC_VER
    static System::Version Version() {return System::Version(_MSC_VER/100, _MSC_VER%100, 0);}
#else
    static System::Version Version() {return System::Version(0, 0, 0);}
#endif
    
#if __APPLE__
    static CompilatorID ID() {return CompilatorID::Xcode;}
#elif __GNUC__
    static CompilatorID ID() {return CompilatorID::Gcc;}
#elif _MSC_VER
    static CompilatorID ID() {return CompilatorID::MicrosoftVisualStudio;}
#else
    static CompilatorID ID() {return CompilatorID::Unknown;}
#endif
    
#if DEBUG || NDEBUG
    static CompilatorMode Mode() {return CompilatorMode::Debug;}
#else
    static CompilatorMode Mode() {return CompilatorMode::Release;}
#endif
    
    static bool IsDebugMode() { return Mode() == CompilatorMode::Debug; }
    
    static bool IsReleaseMode() { return Mode() == CompilatorMode::Release; }
    
    static bool Is32Bits() { return !Environment::Is64BitProcess(); }
    
    static bool Is64Bits() { return Environment::Is64BitProcess(); }
    
  private:
    CompilatorInfo() {}
  };
}

namespace {
  class ExceptionDialog : public Form {
  public:
    static DialogResult Show(const string& title, const Exception& exception) {
      ExceptionDialog dialog(title, exception);
      return dialog.ShowDialog();
    }
    
  private:
    ExceptionDialog(const string& title, const Exception& exception) : Form() {
      this->title = title;
      this->exception = &exception;
      this->expanded = false;
      InitializeComponent();
    }
    
    void InitializeComponent() {
      this->Text = this->title;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(450, 140);
      this->MaximizeBox(false);
      this->StartPosition = FormStartPosition::CenterScreen;
      
      this->panel.Parent = *this;
      this->panel.BackColor = Color::White;
      this->panel.Bounds = System::Drawing::Rectangle(0, 0, 450, 100);
      
      this->icon.Parent = this->panel;
      this->icon.Bounds = System::Drawing::Rectangle(10, 20, 40, 40);
      this->icon.Image(*Image::FromData(Stop));
      
      this->label.Parent = this->panel;
      this->label.AutoSize = false;
      this->label.Bounds = System::Drawing::Rectangle(60, 5, 380, 90);
      this->label.Text = string::Format("Unhandled exception has occured in your application. If you click Continue, the application will ignore this error and attempt to continue. If you click Quit, the application will close immediately.\n\n{0}", this->exception->Message());
      
      this->buttonDetails.Parent = *this;
      this->buttonDetails.Text = "@> Details";
      this->buttonDetails.Location = System::Drawing::Point(10, 110);
      this->buttonDetails.Click += EventHandler(*this, &ExceptionDialog::OnButtonDetailsClick);
      
      this->buttonContinue.Parent = *this;
      this->buttonContinue.Text = "Continue";
      this->buttonContinue.Location = System::Drawing::Point(285, 110);
      this->buttonContinue.Click += EventHandler(*this, &ExceptionDialog::OnButtonContinueClick);
      
      this->buttonQuit.Parent = *this;
      this->buttonQuit.Text = "Quit";
      this->buttonQuit.Location = System::Drawing::Point(365, 110);
      this->buttonQuit.Click += EventHandler(*this, &ExceptionDialog::OnButtonQuitClick);
      
      this->messages.Parent = *this;
      this->messages.Location = System::Drawing::Point(10, 140);
      this->messages.Size = System::Drawing::Size(430, 0);
      this->messages.Font(System::Drawing::Font(FontFamily::GenericMonospace().Name(), 12));
      this->messages.Text = ExceptionDialog::GetReport(*this->exception);
    }
    
    void OnButtonDetailsClick(const object& sender, const EventArgs& e) {
      this->expanded = ! this->expanded;
      this->ClientSize = System::Drawing::Size(this->ClientSize().Width, this->expanded ? 310 : 140);
      this->messages.Height(this->expanded ? 160 : 0);
      this->buttonDetails.Text = this->expanded ? "@2> Details" : "@> Details";
    }
    
    void OnButtonQuitClick(const object& sender, const EventArgs& e) {
      this->dialogResult = DialogResult::Cancel;
      this->Close();
    }
    
    void OnButtonContinueClick(const object& sender, const EventArgs& e) {
      this->dialogResult = DialogResult::OK;
      this->Close();
    }
    
  private:
    static string GetReport(const Exception& exception) {
      string report;
      report += string::Format("Use try and catch to handle Pcf::System::Exception instead{0}", Environment::NewLine());
      report += string::Format("of this dialog box. For more information see documentation.{0}", Environment::NewLine());
      report += string::Format("{0}", Environment::NewLine());
      report += string::Format("{0} Exception Text {0}{1}", string('*', 14), Environment::NewLine());
      report += string::Format("{0}{1}", exception, Environment::NewLine());
      report += string::Format("{0}", Environment::NewLine());
      report += string::Format("{0} Libraries {0}{1}", string('*', 14), Environment::NewLine());
      report += string::Format("Pcf::System{0}", Environment::NewLine());
      report += string::Format("    Name: Pcf.Core.lib{0}", Environment::NewLine());
      report += string::Format("    Version: {0}{1}", Pcf::System::Environment::Version(), Environment::NewLine());
      report += string::Format("{0}{1}", string('-', 40), Environment::NewLine());
      report += string::Format("Pcf::System::Drawing{0}", Environment::NewLine());
      report += string::Format("    Name: Pcf.Drawing::lib{0}", Environment::NewLine());
      report += string::Format("    Version: {0}{1}", Version(1, 0, 0), Environment::NewLine());
      report += string::Format("{0}{1}", string('-', 40), Environment::NewLine());
      report += string::Format("Pcf::System::Windows::Forms{0}", Environment::NewLine());
      report += string::Format("    Name: Pcf.Forms::lib{0}", Environment::NewLine());
      report += string::Format("    Version: {0}{1}", Version(1, 0, 0), Environment::NewLine());
      report += string::Format("{0}{1}", string('-', 40), Environment::NewLine());
      report += string::Format("{0}", Environment::NewLine());
      report += string::Format("{0} Operating System {0}{1}", string('*', 14), Environment::NewLine());
      report += string::Format("{0}{1}", SystemInformation::OperatingSystemInfo::Name(), Environment::NewLine());
      report += string::Format("    Version : {0}{1}", SystemInformation::OperatingSystemInfo::Version(), Environment::NewLine());
      report += string::Format("    ID : {0}{1}", SystemInformation::OperatingSystemInfo::ID(), Environment::NewLine());
      report += string::Format("    OS Version : {0}{1}", SystemInformation::OperatingSystemInfo::OSVersion(), Environment::NewLine());
      report += string::Format("    Is 64 bits : {0}{1}", SystemInformation::OperatingSystemInfo::Is64Bits(), Environment::NewLine());
      report += string::Format("{0}", Environment::NewLine());
      report += string::Format("{0} Lib C {0}{1}", string('*', 14), Environment::NewLine());
      report += string::Format("{0}{1}", SystemInformation::LibcInfo::Name(), Environment::NewLine());
      report += string::Format("    Version : {0}{1}", SystemInformation::LibcInfo::Version(), Environment::NewLine());
      report += string::Format("    ID : {0}{1}", SystemInformation::LibcInfo::ID(), Environment::NewLine());
      report += string::Format("    Is supported : {0}{1}", SystemInformation::LibcInfo::IsCppSupported(), Environment::NewLine());
      report += string::Format("{0}", Environment::NewLine());
      report += string::Format("{0} Compiler {0}{1}", string('*', 14), Environment::NewLine());
      report += string::Format("{0}{1}", SystemInformation::CompilatorInfo::Name(), Environment::NewLine());
      report += string::Format("    Version : {0}{1}", SystemInformation::CompilatorInfo::Version(), Environment::NewLine());
      report += string::Format("    ID : {0}{1}", SystemInformation::CompilatorInfo::ID(), Environment::NewLine());
      report += string::Format("    Mode : {0}{1}", SystemInformation::CompilatorInfo::Mode(), Environment::NewLine());
      report += string::Format("    Is 64 bits : {0}{1}", SystemInformation::CompilatorInfo::Is64Bits(), Environment::NewLine());
      return report;
    }
    
    Panel panel;
    PictureBox icon;
    Label label;
    Button buttonDetails;
    Button buttonContinue;
    Button buttonQuit;
    string title;
    const Exception* exception;
    RichTextBox messages;
    bool expanded;
    string report;
  };
}

bool Application::AllowQuit() {
  return true;
}

void Application::DoEvent() {
  Fl::awake();
}

void Application::EnableVisualStyles() {
 Fl::scheme("gtk+");
}

void Application::Exit() {
  System::Environment::Exit(0);
}

void Application::Run() {
  DialogResult result;
  do {
    try {
      result = DialogResult::Cancel;
      System::Environment::ExitCode = Fl::run();
    } catch(const Exception& e) {
      result = ExceptionDialog::Show("Exception", e);
    }
  } while (result != DialogResult::Cancel);
}

void Application::Run(const Form& form) {
  Run(const_cast<Form&>(form));
}

void Application::Run(Form& form) {
  DialogResult result;
  do {
    try {
      result = DialogResult::Cancel;
      Fl::get_system_colors();
      Application::control = &form;
      Fl_File_Icon::load_system_icons();
      Fl::add_handler(&Application::Handler);
      Fl::lock();
      form.Show();
      System::Environment::ExitCode = Fl::run();
      Fl::remove_handler(&Application::Handler);
    } catch(const Exception& e) {
      result = ExceptionDialog::Show("Exception", e);
    }
  } while (result != DialogResult::Cancel);
}

int Application::Handler(int event) {
  if (event == FL_SHORTCUT && Fl::event_key() == FL_Escape)
    return 1;
  return 0;
}

void Application::ApplicationIdle(void* idle) {
  reinterpret_cast<System::EventHandler*>(idle)->Invoke(object(), System::EventArgs());
}

void Application::RegisterIdle() {
  Fl::add_idle(&ApplicationIdle, &Application::Idle);
}

void Application::UnregisterIdle() {
  Fl::remove_idle(&Application::ApplicationIdle);
}

#if _WIN32 && !__GNUC__
#pragma warning(push)
#pragma warning(disable:4201)
#include <Windows.h>
#pragma warning(pop)

extern int main(int argc, char* argv[]);
extern int __argc;
extern char** __argv;
extern wchar** __wargv;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR commandLine, int cmdShow) {
  return main(__argc, __argv);
}
#endif
