/// @file
/// @brief Contains #sw_lock keyword.
#pragma once

#include "System/Threading/LockGuard.hpp"
#include "Using.hpp"

namespace Switch {
  /// @brief The sw_lock keyword marks a statement block as a critical section by obtaining the mutual-exclusion lock for a given object, executing a statement, and then releasing the lock. The following example includes a lock statement.
  /// @code
  /// class Account : public object {
  /// public:
  ///   void Withdraw(decimal amount) {
  ///     sw_lock (this->Lock) {
  ///       if (amount > balance)
  ///         throw new Exception("Insufficient funds");
  ///       balance -= amount;
  ///     }
  ///   }
  ///
  /// private:
  ///   decimal balance;
  ///   object lock;
  /// };
  /// @endcode
  /// For more information, see Thread Synchronization.
  /// @remarks The sw_lock keyword ensures that one thread does not enter a critical section of code while another thread is in the critical section. If another thread tries to enter a locked code, it will wait, block, until the object is released.
  /// @remarks The section Threading discusses threading.
  /// @remarks The sw_lock keyword calls Enter at the start of the block and Exit at the end of the block. A ThreadInterruptedException is thrown if Interrupt interrupts a thread that is waiting to enter a lock statement.
  /// @remarks In general, avoid locking on a public type, or instances beyond your code's control. The common constructs sw_lock (*this), sw_lock (sw_typeof<MyType>()), and sw_lock ("myLock"_s) violate this guideline:
  /// * sw_lock (this) is a problem if the instance can be accessed publicly.
  /// * sw_lock (sw_typeof<MyType>()) is a problem if MyType is publicly accessible.
  /// * sw_lock ("myLock"_s) is a problem because any other code in the process using the same string, will share the same lock.
  /// @remarks Best practice is to define a private object to lock on, or a private static object variable to protect data common to all instances.
  /// @remarks You can't use the sw_await keyword in the body of a sw_lock statement.
  /// @par Examples
  /// The following sample shows a simple use of threads without locking in C++.
  /// @code
  /// #include <Switch/Switch>
  ///
  /// using namespace System;
  /// using namespace System::Threading;
  ///
  /// class ThreadTest {
  /// public:
  ///   void RunMe() {
  ///     Console::WriteLine("RunMe called");
  ///   }
  ///
  ///   static void Main() {
  ///     ThreadTest b;
  ///     Thread t(ThreadStart(b, &ThreadTest::RunMe));
  ///     t.Start();
  ///   }
  /// };
  ///
  /// sw_startup (ThreadTest)
  ///
  /// // Output: RunMe called
  /// @endcode
  /// @par Examples
  /// The following sample uses threads and sw_lock. As long as the lock statement is present, the statement block is a critical section and balance will never become a negative number.
  /// @include Lock.cpp
  /// @ingroup Switch
  #define sw_lock(object)\
  sw_using (System::Threading::LockGuard __pcf_lock_guard__(object))
}

using namespace Switch;
