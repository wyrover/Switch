#include <csignal>
#include <cstring>

#include <Pcf/Pcf>

using namespace System;
using namespace System::Threading;

enum class Signal {
  Unknown = 0,
  Interrupt = SIGINT, // 2
  IllegalInstruction = SIGILL, // 4
  Abort = SIGABRT, // 6 (22 on windows)
  FloatingPointException = SIGFPE, // 8
  SegmentationViolation = SIGSEGV, // 11
  Terminate = SIGTERM, // 15
};

/// @cond
template<>
class EnumToStrings<Signal> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Signal::Unknown, "Unknown"}, {(int64)Signal::Interrupt, "Interrupt"}, {(int64)Signal::IllegalInstruction, "IllegalInstruction"}, {(int64)Signal::Abort, "Abort"}, {(int64)Signal::FloatingPointException, "FloatingPointException"}, {(int64)Signal::SegmentationViolation, "SegmentationViolation"}, {(int64)Signal::Terminate, "Terminate"}};
    flags = false;
  }
};
/// @endcond

class SignalEventArgs : public System::EventArgs {
public:
  SignalEventArgs(const Signal& signal, const Up<System::Exception>& exception, const Up<System::Diagnostics::StackTrace>& stackTrace) : signal(signal), exception(exception), stackTrace(stackTrace) { }

  const ::Signal& Signal() const { return this->signal; }

  const System::Exception& Exception() const { return *this->exception; }

  const System::Diagnostics::StackTrace& StackTrace() const { return *this->stackTrace; }

private:
  ::Signal signal;
  Up<System::Exception> exception;
  Up<System::Diagnostics::StackTrace> stackTrace;
};

using SignalEventHandler = TEventHandler<const SignalEventArgs&>;

class SignalHandler : public object {
public:
  static SignalEventHandler SignalEvent;

  static Sp<SignalHandler> GetInstance() {
    static Sp<SignalHandler> signalHandler;

    if (Sp<SignalHandler>::IsNullOrInvalid(signalHandler))
      signalHandler = Sp<SignalHandler>::Create(thisSignalHandler);

    return signalHandler;
  }

  ~SignalHandler() {
    signal((int32)Signal::Interrupt, SIG_DFL);
    signal((int32)Signal::IllegalInstruction, SIG_DFL);
    signal((int32)Signal::Abort, SIG_DFL);
    signal((int32)Signal::FloatingPointException, SIG_DFL);
    signal((int32)Signal::SegmentationViolation, SIG_DFL);
    signal((int32)Signal::Terminate, SIG_DFL);
  }

  static void Raise(const Signal& signal) { raise((int32)signal); }

private:
  SignalHandler() {
    signal((int32)Signal::Interrupt, Handle);
    signal((int32)Signal::IllegalInstruction, Handle);
    signal((int32)Signal::Abort, Handle);
    signal((int32)Signal::FloatingPointException, Handle);
    signal((int32)Signal::SegmentationViolation, Handle);
    signal((int32)Signal::Terminate, Handle);
  }

  static void Handle(int32 sig) {
    Signal signal = (Signal)sig;
    Up<System::Exception> exception;
    Up<System::Diagnostics::StackTrace> stackTrace = Up<System::Diagnostics::StackTrace>::Create();

    switch (signal) {
      case Signal::Interrupt : exception = Up<System::Exception>::Create<System::Threading::ThreadInterruptedException>(pcf_current_information); break;
      case Signal::Abort : exception = Up<System::Exception>::Create<System::Threading::ThreadAbortException>(pcf_current_information); break;
      case Signal::Terminate :  exception = Up<System::Exception>::Create<System::Threading::ThreadInterruptedException>(pcf_current_information); break;
      case Signal::IllegalInstruction :  exception = Up<System::Exception>::Create<System::InvalidProgramException>(pcf_current_information); break;
      case Signal::FloatingPointException :  exception = Up<System::Exception>::Create<System::ArithmeticException>(pcf_current_information); break;
      case Signal::SegmentationViolation :  exception = Up<System::Exception>::Create<System::AccessViolationException>(pcf_current_information); break;
      default: exception = Up<System::Exception>::Create(pcf_current_information); break;
    }

    SignalEvent(Enum<Signal>(signal), SignalEventArgs(signal, exception, stackTrace));
    if (signal == Signal::IllegalInstruction || signal == Signal::FloatingPointException || signal == Signal::SegmentationViolation)
      Environment::Exit((int32)signal);
  }

  static SignalHandler thisSignalHandler;
};

SignalEventHandler SignalHandler::SignalEvent;

SignalHandler SignalHandler::thisSignalHandler;

class SignalHandlerTest : public object {
public:
  static void OnSignalEvent(const Object& /*sender*/, const SignalEventArgs& event) {
    Console::WriteLine("Signal : ");
    Console::WriteLine("{0} ({1})", (int32)event.Signal(), event.Signal());
    Console::WriteLine("Exception : ");
    Console::WriteLine(event.Exception());
    Console::WriteLine("Stack trace :");
    Console::WriteLine(event.StackTrace());
  }

  static void GenerateSegmentationViolation() {
    Console::WriteLine("Genereate {0}", Signal::SegmentationViolation);

    void* nullPointer = null;
    memcpy(nullPointer, "Test null pointer.", 18);
  }

  static void GenerateFloatingPointException() {
    Console::WriteLine("Genereate {0}", Signal::FloatingPointException);

    int dividend = 12;
    int divisor = 0;
    Console::WriteLine("result = {0}", dividend / divisor);
  }
};

int main(int argc, char* argv[]) {
  SignalHandler::GetInstance()->SignalEvent += SignalEventHandler(&SignalHandlerTest::OnSignalEvent);
  
  if (argc == 2) {
    Signal signal = (Signal)Enum<Signal>::Parse(argv[1]);
    Console::WriteLine("Genereate {0}", signal);
    SignalHandler::Raise(signal);
  }
  else {
    for ( ; ; ) {
      Console::WriteLine("Wait something...");
      Thread::Sleep(1000);
    }
  }
  
  SignalHandler::GetInstance()->SignalEvent -= SignalEventHandler(&SignalHandlerTest::OnSignalEvent);
}

// This code produces the following output if FloatingPointException is entered on command line:
//
// Genereate FloatingPointException
// Signal :
// 8 (FloatingPointException)
// Exception :
// System::ArithmeticException: Overflow or underflow in the arithmetic operation.
// at SignalHandle::Handle(int) [0x000BF6C6] in /home/yves/Projects/Pcf/System/Examples/SignalHandler.cpp:149
// at __kernel_sigreturn
// at __kernel_vsyscall
// at raise [0x0000EDA0] in /lib/i386-linux-gnu/libpthread.so.0:0
// at SignalHandle::Raise(Signal const&) [0x000BF5EE] in ./SignalHandler:0
// at main(System::Array<System::string, 1> const&) [0x000BFE60] in ./SignalHandler:0
// at main [0x000BBECC] in ./SignalHandler:0
// at __libc_start_main [0x000193E0] in /lib/i386-linux-gnu/libc.so.6:0
//
// Stack trace :
// at SignalHandle::Handle(int)
// at __kernel_sigreturn
// at __kernel_vsyscall
// at raise
// at SignalHandle::Raise(Signal const&)
// at main(System::Array<System::string, 1> const&)
// at main
// at __libc_start_main
