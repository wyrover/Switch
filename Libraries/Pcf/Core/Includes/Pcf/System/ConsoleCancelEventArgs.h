/// @file
/// @brief Contains Pcf::System::ConsoleCancelEventArgs class.
#pragma once

#include "ConsoleSpecialKey.h"
#include "EventArgs.h"
#include "../Property.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides data for the Console::CancelKeyPress event. This class cannot be inherited.
    /// @remarks A user can interrupt a console application process by simultaneously pressing the Control modifier key and the C console key (Ctrl+C), or the Control modifier key and the Break console key (Ctrl+Break). The Pcf consequently provides a ConsoleCancelEventArgs object to the event handler for the Console.CancelKeyPress event to specify whether the process should be cancelled.
    /// @remarks If the Cancel property is set to true in the event handler, the process is resumed; otherwise, the process is terminated. By default, the value of the ConsoleCancelEventArgs property is false, and the process terminates.
    class ConsoleCancelEventArgs final : public EventArgs {
    public:
      /// @brief Initializes a new instance of the GiveFeedbackEventArgs class.
      ConsoleCancelEventArgs() {}
      
      /// @brief Initializes a new instance of the GiveFeedbackEventArgs class.
      /// @param effects The type of drag-and-drop operation. Possible values are obtained by applying the bitwise OR (|) operation to the constants defined in the DragDropEffects.
      /// @param true if default pointers are used; otherwise, false.
      ConsoleCancelEventArgs(bool cancel, ConsoleSpecialKey specialKey) : cancel(cancel), specialKey(specialKey) {}

      /// @cond
      ConsoleCancelEventArgs(const ConsoleCancelEventArgs& consoleCancelSpecialEventArgs) : cancel(consoleCancelSpecialEventArgs.cancel), specialKey(consoleCancelSpecialEventArgs.specialKey) {}
      ConsoleCancelEventArgs& operator =(const ConsoleCancelEventArgs& consoleCancelSpecialEventArgs) {
        this->cancel = consoleCancelSpecialEventArgs.cancel;
        this->specialKey = consoleCancelSpecialEventArgs.specialKey;
        return *this;
      }
      /// @endcond
      
      /// @brief Gets or sets a value that indicates whether simultaneously pressing the Control modifier key and the C console key (Ctrl+C) or the Ctrl+Break keys terminates the current process. The default is false, which terminates the current process.
      /// @return true if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
      Property<bool> Cancel {
        pcf_get {return this->cancel;},
        pcf_set {this->cancel = value;}
      };
      
      /// @brief Gets the combination of modifier and console keys that interrupted the current process.
      /// @return One of the enumeration values that specifies the key combination that interrupted the current process. There is no default value.
      Property<ConsoleSpecialKey, ReadOnly> SpecialKey {
        pcf_get {return this->specialKey;}
      };
      
    private:
      bool cancel = true;
      ConsoleSpecialKey specialKey = static_cast<ConsoleSpecialKey>(0);
    };
  }
}

using namespace Pcf;
