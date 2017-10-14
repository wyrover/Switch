/// @file
/// @brief Contains Switch::System::Threading::ThreadState enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Threading namespace provides classes and interfaces that enable multithreaded programming.
    /// In addition to classes for synchronizing thread activities and access to data ( Mutex, Monitor, Interlocked, AutoResetEvent, and so on), this namespace includes a ThreadPool class that allows you to use a pool of system-supplied threads, and a Timer class that executes callback methods on thread pool threads.
    namespace Threading {
      /// @brief Specifies the execution states of a System::Threading::Thread.
      /// @see FileStream
      enum class ThreadState {
        /// @brief The thread has been started, it is not blocked, and there is no pending System::Threading::ThreadAbortException.
        Running = 0x0000,
        /// @brief The thread is being requested to stop. This is for internal use only.
        StopRequested = 0x0001,
        /// @brief The thread is being requested to suspend.
        SuspendRequested = 0x0002,
        /// @brief The thread is being executed as a background thread, as opposed to a foreground thread. This state is controlled by setting the System::Threading::Thread.IsBackground property.
        Background = 0x0004,
        /// @brief The System::Threading::Thread.Start() method has not been invoked on the thread.
        Unstarted = 0x0008,
        /// @brief The thread has stopped.
        Stopped = 0x0010,
        /// @brief The thread is blocked. This could be the result of calling System::Threading::Thread.Sleep(System::Int32) or System::Threading::Thread.Join(), of requesting a lock � for example, by calling System::Threading::Monitor.Enter(System::object) or System::Threading::Monitor.Wait(System::object,System::Int32,System::Boolean) or of waiting on a thread synchronization object such as System::Threading::ManualResetEvent.
        WaitSleepJoin = 0x0020,
        /// @brief The thread has been suspended.
        Suspended = 0x0040,
        /// @brief The System::Threading::Thread.Abort(System::object) method has been invoked on the thread, but the thread has not yet received the pending System::Threading::ThreadAbortException that will attempt to terminate it.
        AbortRequested = 0x0080,
        /// @brief The thread state includes System::Threading::ThreadState.AbortRequested and the thread is now dead, but its state has not yet changed to System::Threading::ThreadState.Stopped.
        Aborted = 0x0100
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Threading::ThreadState> : public TrueType {};

template<>
class EnumToStrings<System::Threading::ThreadState> {
public:
  void operator ()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Threading::ThreadState::Running, "Running"}, {(int64)System::Threading::ThreadState::StopRequested, "StopRequested"}, {(int64)System::Threading::ThreadState::SuspendRequested, "SuspendRequested"}, {(int64)System::Threading::ThreadState::Background, "Background"}, {(int64)System::Threading::ThreadState::Unstarted, "Unstarted"}, {(int64)System::Threading::ThreadState::Stopped, "Stopped"}, {(int64)System::Threading::ThreadState::WaitSleepJoin, "WaitSleepJoin"}, {(int64)System::Threading::ThreadState::Suspended, "Suspended"}, {(int64)System::Threading::ThreadState::AbortRequested, "AbortRequested"}, {(int64)System::Threading::ThreadState::Aborted, "Aborted"}};
    flags = true;
  }
};
/// @endcond

using namespace Switch;
