/// @file
/// @brief Contains Pcf::System::IAsyncResult interface.
#pragma once

#include "../Interface.hpp"
#include "../Property.hpp"
#include "Object.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    namespace Threading {
      class WaitHandle;
    }
    /// @endcond

    /// @interface IAsyncResult
    /// @brief Represents the status of an asynchronous operation.
    class pcf_public IAsyncResult pcf_interface {
    public:
      /// @brief Gets a user-defined object that qualifies or contains information about an asynchronous operation.
      /// @return A user-defined object that qualifies or contains information about an asynchronous operation.
      Property<const Object&, ReadOnly> AsyncState {
        pcf_get->const object& {return this->GetAsyncState();}
      };

      /// @brief Gets a WaitHandle that is used to wait for an asynchronous operation to complete.
      /// @return A WaitHandle that is used to wait for an asynchronous operation to complete.
      Property<const System::Threading::WaitHandle&,ReadOnly> AsyncWaitHandle {
        pcf_get->const System::Threading::WaitHandle& {return this->GetAsyncWaitHandle();}
      };

      /// @brief Gets an indication of whether the asynchronous operation completed synchronously.
      /// @return true if the asynchronous operation completed synchronously; otherwise, false.
      Property<bool, ReadOnly> CompletedSynchronously {
        pcf_get {return this->GetCompletedSynchronously();}
      };

      /// @brief Gets an indication whether the asynchronous operation has completed.
      /// @return true if the operation is complete; otherwise, false.
      Property<bool, ReadOnly> IsCompleted {
        pcf_get {return this->GetIsCompleted();}
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

using namespace Pcf;
