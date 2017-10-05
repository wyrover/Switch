/// @file
/// @brief Contains Switch::System::IAsyncResult interface.
#pragma once

#include "../Interface.hpp"
#include "../Property.hpp"
#include "Object.hpp"

/// @cond
namespace Switch {
  namespace System {
    namespace Threading {
      class WaitHandle;
    }
  }
}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @interface IAsyncResult
    /// @brief Represents the status of an asynchronous operation.
    class _export IAsyncResult _interface {
    public:
      /// @brief Gets a user-defined object that qualifies or contains information about an asynchronous operation.
      /// @return A user-defined object that qualifies or contains information about an asynchronous operation.
      _property<const Object&, _readonly> AsyncState {
        _get->const object& {return this->GetAsyncState();}
      };

      /// @brief Gets a WaitHandle that is used to wait for an asynchronous operation to complete.
      /// @return A WaitHandle that is used to wait for an asynchronous operation to complete.
      _property<const System::Threading::WaitHandle&, _readonly> AsyncWaitHandle {
        _get->const System::Threading::WaitHandle& {return this->GetAsyncWaitHandle();}
      };

      /// @brief Gets an indication of whether the asynchronous operation completed synchronously.
      /// @return true if the asynchronous operation completed synchronously; otherwise, false.
      _property<bool, _readonly> CompletedSynchronously {
        _get {return this->GetCompletedSynchronously();}
      };

      /// @brief Gets an indication whether the asynchronous operation has completed.
      /// @return true if the operation is complete; otherwise, false.
      _property<bool, _readonly> IsCompleted {
        _get {return this->GetIsCompleted();}
      };
      
    protected:
      /// @brief Gets a user-defined object that qualifies or contains information about an asynchronous operation.
      /// @return A user-defined object that qualifies or contains information about an asynchronous operation.
      virtual const Object& GetAsyncState() const = 0;
      
      /// @brief Gets a WaitHandle that is used to wait for an asynchronous operation to complete.
      /// @return A WaitHandle that is used to wait for an asynchronous operation to complete.
      virtual const System::Threading::WaitHandle& GetAsyncWaitHandle() const = 0;
      
      /// @brief Gets an indication of whether the asynchronous operation completed synchronously.
      /// @return true if the asynchronous operation completed synchronously; otherwise, false.
      virtual bool GetCompletedSynchronously() const = 0;
      
      /// @brief Gets an indication whether the asynchronous operation has completed.
      /// @return true if the operation is complete; otherwise, false.
      virtual bool GetIsCompleted() const = 0;
    };
  }
}

using namespace Switch;
