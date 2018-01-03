/// @file
/// @brief Contains Switch::TUnit::Expect class.
#pragma once

#include "AssertionException.hpp"
#include "AssertionResult.hpp"
#include "Is.hpp"
#include "TestFixture.hpp"
#include <Switch/System/BitConverter.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Environment.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/SystemException.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #AddTest_ method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #AddTest_ method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The Expect class contains a collection of static methods that implement the most common assertions used in Switch::TUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include Expect.cpp
    class export_ Expect : private object {
    public:
      /// @brief Verifies that two type are equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreEqual(24, int32(24)); // test ok
      /// TUnit::Expect::AreEqual(23, int32(24)); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual) {AreEqual(expected, actual, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that two type are equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreEqual(24, int32(24), "User message..."); // test ok
      /// TUnit::Expect::AreEqual(23, int32(24), "User message..."); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual, const string& message) {AreEqual(expected, actual, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that two type are equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreEqual(24, int32(24), caller_); // test ok
      /// TUnit::Expect::AreEqual(23, int32(24), caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual, const System::Runtime::CompilerServices::Caller& caller) {AreEqual(expected, actual, "", caller);}

      /// @brief Verifies that two type are equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param caller Contains information about current file and current line.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreEqual(24, int32(24), caller_, "User message..."); // test ok
      /// TUnit::Expect::AreEqual(23, int32(24), caller_, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (actual == expected)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, caller);
      }

      /// @brief Verifies that two type are not equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreNotEqual(23, int32(24)); // test ok
      /// TUnit::Expect::AreNotEqual(24, int32(24)); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual) {AreNotEqual(expected, actual, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that two type are not equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreNotEqual(23, int32(24), "User message...", caller_); // test ok
      /// TUnit::Expect::AreNotEqual(24, int32(24), "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual, const string& message) {AreNotEqual(expected, actual, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that two type are not equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreNotEqual(23, int32(24), "User message...", caller_); // test ok
      /// TUnit::Expect::AreNotEqual(24, int32(24), "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual, const System::Runtime::CompilerServices::Caller& caller) {AreNotEqual(expected, actual, "", caller);}

      /// @brief Verifies that two type are not equal. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::AreNotEqual(23, int32(24), "User message...", caller_); // test ok
      /// TUnit::Expect::AreNotEqual(24, int32(24), "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (actual != expected)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: not {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, caller);
      }

      /// @brief Expect that two objects do refer to differents objects. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AreNotSame(c, a); // test ok
      /// TUnit::Expectt::AreNotSame(b, a); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual) {AreNotSame(expected, actual, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that two objects do refer to differents objects. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AreNotSame(c, a, "User message...", caller_); // test ok
      /// TUnit::Expectt::AreNotSame(b, a, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual, const string& message) {AreNotSame(expected, actual, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that two objects do refer to differents objects. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AreNotSame(c, a, "User message...", caller_); // test ok
      /// TUnit::Expectt::AreNotSame(b, a, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual, const System::Runtime::CompilerServices::Caller& caller) {AreNotSame(expected, actual, "", caller);}

      /// @brief Expect that two objects do refer to differents objects. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AreNotSame(c, a, "User message...", caller_); // test ok
      /// TUnit::Expectt::AreNotSame(b, a, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (&actual != &expected)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: not same as {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, caller);
      }

      /// @brief Expect that two objects do refer to the same object. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AretSame(b, a); // test ok
      /// TUnit::Expectt::AretSame(c, a); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual) {AreSame(expected, actual, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that two objects do refer to the same object. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AreSame(b, a, "User message...", caller_); // test ok
      /// TUnit::Expectt::AreSame(c, a, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual, const string& message) {AreSame(expected, actual, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that two objects do refer to the same object. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AreSame(b, a, "User message...", caller_); // test ok
      /// TUnit::Expectt::AreSame(c, a, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual, const System::Runtime::CompilerServices::Caller& caller) {AreSame(expected, actual, "", caller);}

      /// @brief Expect that two objects do refer to the same object. If they are, then an error message is show.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Expectt::AreSame(b, a, "User message...", caller_); // test ok
      /// TUnit::Expectt::AreSame(c, a, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (&actual == &expected)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: same as {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, caller);
      }

      /// @brief Verifies that two type are equal. If they are not, then a message is shown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Expectt::Contains(2, a1); // test ok
      /// TUnit::Expectt::Contains(4, a1); // test shows an error message.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection) {Contains(item, collection, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that two type are equal. If they are not, then a message is shown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Expectt::Contains(2, a1, "User message..."); // test ok
      /// TUnit::Expectt::Contains(4, a1, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection, const string& message) {Contains(item, collection, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that two type are equal. If they are not, then a message is shown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Expectt::Contains(2, a1, caller_); // test ok
      /// TUnit::Expectt::Contains(4, a1, caller_); // test shows an error message.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection, const System::Runtime::CompilerServices::Caller& caller) {Contains(item, collection, "", caller);}

      /// @brief Verifies that two type are equal. If they are not, then a message is shown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param caller Contains information about current file and current line.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Expectt::Contains(2, a1, "User message...", caller_); // test ok
      /// TUnit::Expectt::Contains(4, a1, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (collection.Contains(item))
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: collection containing {0}{1}But was:  < {2} >", ValueToString(item), System::Environment::NewLine, string::Join(", ", collection)), message, caller);
      }

      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::DoesNotThrows(delegate_ {a[2];}); // test ok
      /// Expect::DoesNotThrows(delegate_ {a[5];}); // test shows an error message.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement) {DoesNotThrows(statement, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::DoesNotThrows(delegate_ {a[2];}, "User message..."); // test ok
      /// Expect::DoesNotThrows(delegate_ {a[5];}, "User message..."); // test shows an error message.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement, const string& message) {DoesNotThrows(statement, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::DoesNotThrows(delegate_ {a[2];}, caller_); // test ok
      /// Expect::DoesNotThrows(delegate_ {a[5];}, caller_); // test shows an error message.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement, const System::Runtime::CompilerServices::Caller& caller) {DoesNotThrows(statement, "", caller);}

      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::DoesNotThrows(delegate_ {a[2];}, "User message...", caller_); // test ok
      /// Expect::DoesNotThrows(delegate_ {a[5];}, "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        try {
          statement();
          Succeed(message, caller);
        } catch (const AssertionException&) {
          throw;
        } catch (const System::Exception& exception) {
          Fail(string::Format("Expected: No Exception to be thrown{0}But was:  <{1}>", System::Environment::NewLine, exception.GetType().FullName()), message, caller);
        } catch (...) {
          Fail(string::Format("Expected: No Exception to be thrown{0}But was:  <exception>", System::Environment::NewLine), message, caller);
        }
      }

      /// @brief The Equals method throws an Switch::TUnit::AssertionException. This is done to make sure there is no mistake by calling this function.
      static inline bool Equals(const Object&, const Object&) { throw AssertionException(caller_); }

      /// @brief Show a message. This is used by the other Expectt functions.
      static inline void Fail() {Fail("", "", System::Runtime::CompilerServices::Caller());}

      /// @brief Show a message. This is used by the other Expectt functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      static inline void Fail(const string& message) {Fail("", message, System::Runtime::CompilerServices::Caller());}

      /// @brief Show a message. This is used by the other Expectt functions.
      /// @param caller Contains information about current file and current line.
      static inline void Fail(const System::Runtime::CompilerServices::Caller& caller) {Fail("", "", caller);}

      /// @brief Show a message. This is used by the other Expectt functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      static inline void Fail(const string& error, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (!string::IsNullOrEmpty(message))
          System::Console::WriteLine(message);
        //::testing::internal::AssertHelper(::testing::TestPartResult::kFatalFailure, caller.FilePath().Data, caller.Line, error.Data) = ::testing::Message(message.Data);
        ::testing::internal::AssertHelper(::testing::TestPartResult::kFatalFailure, caller.FilePath().Data, caller.LineNumber, error.Data) = ::testing::Message();
      }

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::False(String::IsNullOrEmpty(s1)); // test ok
      /// Expect::False(String::IsNullOrEmpty(s2)); // test shows an error message.
      /// @endcode
      static inline void False(bool condition) {return IsFalse(condition, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::False(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Expect::False(String::IsNullOrEmpty(s2), "User message..."); // test shows an error message.
      /// @endcode
      static inline void False(bool condition, const string& message) {IsFalse(condition, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::False(String::IsNullOrEmpty(s1), caller_); // test ok
      /// Expect::False(String::IsNullOrEmpty(s2), caller_); // test shows an error message.
      /// @endcode
      static inline void False(bool condition, const System::Runtime::CompilerServices::Caller& caller) {IsFalse(condition, "", caller);}

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::False(String::IsNullOrEmpty(s1), "User message...", caller_); // test ok
      /// Expect::False(String::IsNullOrEmpty(s2), "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void False(bool condition, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsFalse(condition, message, caller);}

      /// @brief Verifies that the first value is greater than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Greater(24, 12); // test ok
      /// TUnit::Expect::Greater(24, 48); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Greater(const TValue1& val1, const TValue2& val2) {Greater(val1, val2, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is greater than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Greater(24, 12, "User message..."); // test ok
      /// TUnit::Expect::Greater(24, 48, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Greater(const TValue1& val1, const TValue2& val2, const string& message) {Greater(val1, val2, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is greater than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Greater(24, 12, caller_); // test ok
      /// TUnit::Expect::Greater(24, 48, caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Greater(const TValue1& val1, const TValue2& val2, const System::Runtime::CompilerServices::Caller& caller) {Greater(val1, val2, "", caller);}

      /// @brief Verifies that the first value is greater than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Greater(24, 12, "User message...", caller_); // test ok
      /// TUnit::Expect::Greater(24, 48, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Greater(const TValue1& val1, const TValue2& val2, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (val1 > val2)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: greater than {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, caller);
      }

      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::GreaterOrEqual(24, 12); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 24); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 48); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2) {GreaterOrEqual(val1, val2, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Expect::GreaterOrEqual(24, 12, "User message..."); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 24, "User message..."); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 48, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2, const string& message) {GreaterOrEqual(val1, val2, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::GreaterOrEqual(24, 12, caller_); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 24, caller_); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 48, caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2, const System::Runtime::CompilerServices::Caller& caller) {GreaterOrEqual(val1, val2, "", caller);}

      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::GreaterOrEqual(24, 12, "User message...", caller_); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 24, "User message...", caller_); // test ok
      /// TUnit::Expect::GreaterOrEqual(24, 48, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (val1 >= val2)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: greater than or equal to {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, caller);
      }

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Expect::IsEmpty(v1); // test ok
      /// Expect::IsEmpty(v2); // test shows an error message.
      /// @endcode
      static inline void IsEmpty(const System::String& value) {IsEmpty(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Expect::IsEmpty(v1, "User message..."); // test ok
      /// Expect::IsEmpty(v2, "User message..."); // test shows an error message.
      /// @endcode
      static inline void IsEmpty(const System::String& value, const string& message) {IsEmpty(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Expect::IsEmpty(v1, caller_); // test ok
      /// Expect::IsEmpty(v2, caller_); // test shows an error message.
      /// @endcode
      static inline void IsEmpty(const string& value, const System::Runtime::CompilerServices::Caller& caller) {IsEmpty(value, "", caller);}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Expect::IsEmpty(v1, "User message...", caller_); // test ok
      /// Expect::IsEmpty(v2, "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void IsEmpty(const string& value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (string::IsNullOrEmpty(value))
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: <Empty>{0}But was:  {1}", System::Environment::NewLine, ValueToString(value)), message, caller);
      }

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> v2 = {0, 1, 2};
      /// Expect::IsEmpty(c1); // test ok
      /// Expect::IsEmpty(c2); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection) {IsEmpty(collection, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> v2 = {0, 1, 2};
      /// Expect::IsEmpty(c1, "User message..."); // test ok
      /// Expect::IsEmpty(c2, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message) {IsEmpty(collection, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> c2 = {0, 1, 2};
      /// Expect::IsEmpty(c1, caller_); // test ok
      /// Expect::IsEmpty(c2, caller_); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const System::Runtime::CompilerServices::Caller& caller) {IsEmpty(collection, "", caller);}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> c2 = {0, 1, 2};
      /// Expect::IsEmpty(c1, "User message...", caller_); // test ok
      /// Expect::IsEmpty(c2, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (collection.GetEnumerator().MoveNext() == false)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: <empty>{0}But was:  < {1} >", System::Environment::NewLine, string::Join(", ", collection)), message, caller);
      }

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::IsFalse(String::IsNullOrEmpty(s1)); // test ok
      /// Expect::IsFalse(String::IsNullOrEmpty(s2)); // test shows an error message.
      /// @endcode
      static inline void IsFalse(bool condition) {return IsFalse(condition, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::IsFalse(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Expect::IsFalse(String::IsNullOrEmpty(s2), "User message..."); // test shows an error message.
      /// @endcode
      static inline void IsFalse(bool condition, const string& message) {IsFalse(condition, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::IsFalse(String::IsNullOrEmpty(s1), caller_); // test ok
      /// Expect::IsFalse(String::IsNullOrEmpty(s2), caller_); // test shows an error message.
      /// @endcode
      static inline void IsFalse(bool condition, const System::Runtime::CompilerServices::Caller& caller) {IsFalse(condition, "", caller);}

      /// @brief Expect that a condition is false. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Expect::IsFalse(String::IsNullOrEmpty(s1), "User message...", caller_); // test ok
      /// Expect::IsFalse(String::IsNullOrEmpty(s2), "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void IsFalse(bool condition, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (condition == false)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: False{0}But was:  True", System::Environment::NewLine), message, caller);
      }

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOf<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value) {IsInstanceOf<TT>(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOf<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value, const string& message) {IsInstanceOf<TT>(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOf<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value, const System::Runtime::CompilerServices::Caller& caller) {IsInstanceOf<TT>(value, "", caller);}

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOf<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOf<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (is<TT>(value))
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: instance of <{0}>{1}But was:  <{2}>", typeof_(value), System::Environment::NewLine, typeof_<TT>()), message, caller);
      }

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value) {IsInstanceOf<TT>(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value, const string& message) {IsInstanceOf<TT>(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value, const System::Runtime::CompilerServices::Caller& caller) {IsInstanceOf<TT>(value, "", caller);}

      /// @brief Expect that an object is of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Expect::IsInstanceOfType<Int32>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsInstanceOf<TT, TValue>(value, message, caller);}

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Expect::IsNaN(v1); // test ok
      /// Expect::IsNaN(v2); // test shows an error message.
      /// @endcode
      static inline void IsNaN(double value) {IsNaN(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Expect::IsNaN(v1, "User message..."); // test ok
      /// Expect::IsNaN(v2, "User message..."); // test shows an error message.
      /// @endcode
      static inline void IsNaN(double value, const string& message) {IsNaN(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Expect::IsNaN(v1, caller_); // test ok
      /// Expect::IsNaN(v2, caller_); // test shows an error message.
      /// @endcode
      static inline void IsNaN(double value, const System::Runtime::CompilerServices::Caller& caller) {IsNaN(value, "", caller);}

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Expect::IsNaN(v1, "User message...", caller_); // test ok
      /// Expect::IsNaN(v2, "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void IsNaN(double value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (System::Double::IsNaN(value))
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: NaN{0}But was:  {1}", System::Environment::NewLine, ValueToString(value)), message, caller);
      }

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Expect::IsNaN(v1); // test ok
      /// Expect::IsNaN(v2); // test shows an error message.
      /// @endcode
      static inline void IsNaN(float value) {IsNaN(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Expect::IsNaN(v1, "User message..."); // test ok
      /// Expect::IsNaN(v2, "User message..."); // test shows an error message.
      /// @endcode
      static inline void IsNaN(float value, const string& message) {IsNaN(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Expect::IsNaN(v1, caller_); // test ok
      /// Expect::IsNaN(v2, caller_); // test shows an error message.
      /// @endcode
      static inline void IsNaN(float value, const System::Runtime::CompilerServices::Caller& caller) {IsNaN(value, "", caller);}

      /// @brief Expect that a value is NaN. If the value is not NaN the method show an error message.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Expect::IsNaN(v1, "User message...", caller_); // test ok
      /// Expect::IsNaN(v2, "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void IsNaN(float value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (System::Double::IsNaN(value))
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: NaN{0}But was:  {1}", System::Environment::NewLine, ValueToString(value)), message, caller);
      }

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Expect::IsNotEmpty(v1); // test ok
      /// Expect::IsNotEmpty(v2); // test shows an error message.
      /// @endcode
      static inline void IsNotEmpty(const System::String& value) {IsNotEmpty(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Expect::IsNotEmpty(v1, "User message..."); // test ok
      /// Expect::IsNotEmpty(v2, "User message..."); // test shows an error message.
      /// @endcode
      static inline void IsNotEmpty(const System::String& value, const string& message) {IsNotEmpty(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Expect::IsNotEmpty(v1, caller_); // test ok
      /// Expect::IsNotEmpty(v2, caller_); // test shows an error message.
      /// @endcode
      static inline void IsNotEmpty(const string& value, const System::Runtime::CompilerServices::Caller& caller) {IsNotEmpty(value, "", caller);}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Expect::IsNotEmpty(v1, "User message...", caller_); // test ok
      /// Expect::IsNotEmpty(v2, "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void IsNotEmpty(const string& value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (!string::IsNullOrEmpty(value))
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: not <empty>{0}But was:  <empty>", System::Environment::NewLine), message, caller);
      }

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> v2;
      /// Expect::IsNotEmpty(c1); // test ok
      /// Expect::IsNotEmpty(c2); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection) {IsNotEmpty(collection, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> v2;
      /// Expect::IsNotEmpty(c1, "User message..."); // test ok
      /// Expect::IsNotEmpty(c2, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message) {IsNotEmpty(collection, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> c2;
      /// Expect::IsNotEmpty(c1, caller_); // test ok
      /// Expect::IsNotEmpty(c2, caller_); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const System::Runtime::CompilerServices::Caller& caller) {IsNotEmpty(collection, "", caller);}

      /// @brief Expect that a value is empty. If the value is not Empty the method show an error message.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> c2;
      /// Expect::IsNotEmpty(c1, "User message...", caller_); // test ok
      /// Expect::IsNotEmpty(c2, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (collection.GetEnumerator().MoveNext() == true)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: not <empty>{0}But was:  <empty>", System::Environment::NewLine), message, caller);
      }

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOf<Int32>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOf<string>(str); // test shows an error message.
      /// TUnit::Expect::IsNotInstanceOf<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(const TValue& value) {IsNotInstanceOf<TT>(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOf<Int32>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOf<string>(str); // test shows an error message.
      /// TUnit::Expect::IsNotInstanceOf<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(const TValue& value, const string& message) {IsNotInstanceOf<TT>(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOf<string>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOf<IHashable>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOf<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(const TValue& value, const System::Runtime::CompilerServices::Caller& caller) {IsNotInstanceOf<TT>(value, "", caller);}

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOf<Int32>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOf<string>(str); // test shows an error message.
      /// TUnit::Expect::IsNotInstanceOf<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(const TValue& value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (!is<TT>(value))
          return;
      }

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOfType<string>(str); // test shows an error message.
      /// TUnit::Expect::IsNotInstanceOfType<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(const TValue& value) {IsNotInstanceOfType<TT>(value, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOfType<string>(str); // test shows an error message.
      /// TUnit::Expect::IsNotInstanceOfType<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(const TValue& value, const string& message) {IsNotInstanceOfType<TT>(value, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOfType<string>(str); // test shows an error message.
      /// TUnit::Expect::IsNotInstanceOfType<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(const TValue& value, const System::Runtime::CompilerServices::Caller& caller) {IsNotInstanceOfType<TT>(value, "", caller);}

      /// @brief Expect that an object is not of the type supplied or a derived type. If they are not, then a message is shown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Expect::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Expect::IsNotInstanceOfType<string>(str); // test shows an error message.
      /// TUnit::Expect::IsNotInstanceOfType<IHashable>(str); // test shows an error message.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(const TValue& value, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsNotInstanceOf<TT>(value, message, caller);}

      /// @cond
      static inline void IsNotNull(NullPtr pointer) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void IsNotNull(NullPtr pointer, const string& message) {IsNotNull(pointer, message, System::Runtime::CompilerServices::Caller());}
      static inline void IsNotNull(NullPtr pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void IsNotNull(NullPtr pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {Fail(string::Format("Expected: not null{0}But was:  null", System::Environment::NewLine), message, caller);}
      /// @endcond

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::IsNotNull(s1); // test ok
      /// Expect::IsNotNull(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::IsNotNull(s1, "User message...")); // test ok
      /// Expect::IsNotNull(s2, "User message...")); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer, const string& message) {IsNotNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::IsNotNull(s1, caller_); // test ok
      /// Expect::IsNotNull(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, "", caller);}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::IsNotNull(s1, "User message..."), caller_); // test ok
      /// Expect::IsNotNull(s2, "User message..."), caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (pointer != null)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: not null{0}But was:  null", System::Environment::NewLine), message, caller);
      }

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::IsNotNull(s1); // test ok
      /// Expect::IsNotNull(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::IsNotNull(s1, "User message..."); // test ok
      /// Expect::IsNotNull(s2, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer, const string& message) {IsNotNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::IsNotNull(s1, caller_); // test ok
      /// Expect::IsNotNull(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, "", caller);}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::IsNotNull(s1, "User message...", caller_); // test ok
      /// Expect::IsNotNull(s2, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (pointer != null)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: not null{0}But was:  null", System::Environment::NewLine), message, caller);
      }

      /// @cond
      static inline void IsNull(NullPtr pointer) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void IsNull(NullPtr pointer, const string& message) {IsNull(pointer, message, System::Runtime::CompilerServices::Caller());}
      static inline void IsNull(NullPtr pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void IsNull(NullPtr pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {Succeed(message, caller);}
      /// @endcond

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::IsNull(s1); // test ok
      /// Expect::IsNull(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::IsNull(s1, "User message...")); // test ok
      /// Expect::IsNull(s2, "User message...")); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer, const string& message) {IsNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::IsNull(s1, caller_); // test ok
      /// Expect::IsNull(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, "", caller);}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::IsNull(s1, "User message..."), caller_); // test ok
      /// Expect::IsNull(s2, "User message..."), caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (pointer == null)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: null{0}But was:  {1}", System::Environment::NewLine, ValueToString(*pointer)), message, caller);
      }

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::IsNull(s1); // test ok
      /// Expect::IsNull(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::IsNull(s1, "User message..."); // test ok
      /// Expect::IsNull(s2, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer, const string& message) {IsNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::IsNull(s1, caller_); // test ok
      /// Expect::IsNull(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, "", caller);}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::IsNull(s1, "User message...", caller_); // test ok
      /// Expect::IsNull(s2, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (pointer == null)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: null{0}But was:  {1}", System::Environment::NewLine, ValueToString(*pointer)), message, caller);
      }

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::IsTrue(String::IsNullOrEmpty(s1)); // test ok
      /// Expect::IsTrue(String::IsNullOrEmpty(s2)); // test shows an error message.
      /// @endcode
      static inline void IsTrue(bool condition) {return IsTrue(condition, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::IsTrue(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Expect::IsTrue(String::IsNullOrEmpty(s2), "User message..."); // test shows an error message.
      /// @endcode
      static inline void IsTrue(bool condition, const string& message) {IsTrue(condition, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::IsTrue(String::IsNullOrEmpty(s1), caller_); // test ok
      /// Expect::IsTrue(String::IsNullOrEmpty(s2), caller_); // test shows an error message.
      /// @endcode
      static inline void IsTrue(bool condition, const System::Runtime::CompilerServices::Caller& caller) {IsTrue(condition, "", caller);}

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::IsTrue(String::IsNullOrEmpty(s1), "User message...", caller_); // test ok
      /// Expect::IsTrue(String::IsNullOrEmpty(s2), "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void IsTrue(bool condition, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (condition == true)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: True{0}But was:  False", System::Environment::NewLine), message, caller);
      }

      /// @brief Verifies that the first value is less than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Less(12, 24); // test ok
      /// TUnit::Expect::Less(48, 24); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2) {Less(val1, val2, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is less than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Less(24, 12, "User message..."); // test ok
      /// TUnit::Expect::Less(24, 48, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2, const string& message) {Less(val1, val2, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is less than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Less(12, 24, caller_); // test ok
      /// TUnit::Expect::Less(48, 24, caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2, const System::Runtime::CompilerServices::Caller& caller) {Less(val1, val2, "", caller);}

      /// @brief Verifies that the first value is less than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::Less(24, 12, "User message...", caller_); // test ok
      /// TUnit::Expect::Less(24, 48, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (val1 < val2)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: less than {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, caller);
      }

      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Expect::LessOrEqual(12, 24); // test ok
      /// TUnit::Expect::LessOrEqual(24, 24); // test ok
      /// TUnit::Expect::LessOrEqual(48, 24); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2) {LessOrEqual(val1, val2, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Expect::LessOrEqual(24, 12, "User message..."); // test ok
      /// TUnit::Expect::LessOrEqual(24, 24, "User message..."); // test ok
      /// TUnit::Expect::LessOrEqual(24, 48, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2, const string& message) {LessOrEqual(val1, val2, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::LessOrEqual(12, 24, caller_); // test ok
      /// TUnit::Expect::LessOrEqual(24, 24, caller_); // test ok
      /// TUnit::Expect::LessOrEqual(48, 24, caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2, const System::Runtime::CompilerServices::Caller& caller) {LessOrEqual(val1, val2, "", caller);}

      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then a message is shown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Expect::LessOrEqual(12, 24, "User message...", caller_); // test ok
      /// TUnit::Expect::LessOrEqual(24, 24, "User message...", caller_); // test ok
      /// TUnit::Expect::LessOrEqual(48, 24, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        if (val1 <= val2)
          Succeed(message, caller);
        else
          Fail(string::Format("Expected: less than or equal to {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, caller);
      }

      /// @cond
      static inline void NotNull(NullPtr pointer) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void NotNull(NullPtr pointer, const string& message) {IsNotNull(pointer, message, System::Runtime::CompilerServices::Caller());}
      static inline void NotNull(NullPtr pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void NotNull(NullPtr pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {Fail(string::Format("Expected: not null{0}But was:  null", System::Environment::NewLine), message, caller);}
      /// @endcond

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::NotNull(s1); // test ok
      /// Expect::NotNull(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::NotNull(s1, "User message...")); // test ok
      /// Expect::NotNull(s2, "User message...")); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer, const string& message) {IsNotNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::NotNull(s1, caller_); // test ok
      /// Expect::NotNull(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, "", caller);}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Expect::NotNull(s1, "User message..."), caller_); // test ok
      /// Expect::NotNull(s2, "User message..."), caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, message, caller);}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::IsNotNull(s1); // test ok
      /// Expect::IsNotNull(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer) {IsNotNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::NotNull(s1, "User message..."); // test ok
      /// Expect::NotNull(s2, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer, const string& message) {IsNotNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::NotNull(s1, caller_); // test ok
      /// Expect::NotNull(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, "", caller);}

      /// @brief Expect that the pointer is not null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Expect::NotNull(s1, "User message...", caller_); // test ok
      /// Expect::NotNull(s2, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsNotNull(pointer, message, caller);}

      /// @cond
      static inline void Null(NullPtr pointer) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void Null(NullPtr pointer, const string& message) {IsNull(pointer, message, System::Runtime::CompilerServices::Caller());}
      static inline void Null(NullPtr pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}
      static inline void Null(NullPtr pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {Succeed(message, caller);}
      /// @endcond

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::Null(s1); // test ok
      /// Expect::Null(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::Null(s1, "User message...")); // test ok
      /// Expect::Null(s2, "User message...")); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer, const string& message) {IsNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::Null(s1, caller_); // test ok
      /// Expect::Null(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, "", caller);}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Expect::Null(s1, "User message..."), caller_); // test ok
      /// Expect::Null(s2, "User message..."), caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, message, caller);}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::Null(s1); // test ok
      /// Expect::Null(s2); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer) {IsNull(pointer, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::Null(s1, "User message..."); // test ok
      /// Expect::Null(s2, "User message..."); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer, const string& message) {IsNull(pointer, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::Null(s1, caller_); // test ok
      /// Expect::Null(s2, caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, "", caller);}

      /// @brief Expect that the pointer is null. If the pointer is null the method show an error message.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Expect::Null(s1, "User message...", caller_); // test ok
      /// Expect::Null(s2, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsNull(pointer, message, caller);}

      /// @brief The ReferenceEquals method throws an Switch::TUnit::AssertionException. This is done to make sure there is no mistake by calling this function.
      static inline bool ReferenceEquals(const Object&, const Object&) { throw AssertionException(caller_); }

      /// @brief Generates a success with a generic message. This is used by the other Expectt functions.
      static inline void Succeed() {Succeed("", System::Runtime::CompilerServices::Caller());}

      /// @brief Generates a success with a generic message. This is used by the other Expectt functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      static inline void Succeed(const string& message) {Succeed(message, System::Runtime::CompilerServices::Caller());}

      /// @brief Generates a success with a generic message. This is used by the other Expectt functions.
      /// @param caller Contains information about current file and current line.
      static inline void Succeed(const System::Runtime::CompilerServices::Caller& caller) {Succeed("", caller); }

      /// @brief Generates a success with a generic message. This is used by the other Expectt functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      static inline void Succeed(const string& message, const System::Runtime::CompilerServices::Caller& caller) {::testing::internal::AssertHelper(::testing::TestPartResult::kSuccess, caller.FilePath().Data, caller.LineNumber, "Succeeded") = ::testing::Message(message.Data);}

      template<typename TValue>
      static void That(const TValue& actual, const Constraints::Constraint& constraint) {That(actual, constraint, "", System::Runtime::CompilerServices::Caller());}

      template<typename TValue>
      static void That(const TValue& actual, const Constraints::Constraint& constraint, const string message) {That(actual, constraint, message, System::Runtime::CompilerServices::Caller());}

      template<typename TValue>
      static void That(const TValue& actual, const Constraints::Constraint& constraint, const System::Runtime::CompilerServices::Caller& caller) {That(actual, constraint, "", caller);}

      template<typename TValue>
      static void That(const TValue& actual, const Constraints::Constraint& constraint, const string message, const System::Runtime::CompilerServices::Caller& caller) {
        const_cast<Constraints::Constraint&>(constraint).Actual = actual;
        const_cast<Constraints::Constraint&>(constraint).Message = message;
        const_cast<Constraints::Constraint&>(constraint).Caller = caller;
        if (constraint.Verify(actual))
          Succeed(message, caller);
        else
          Fail(constraint.Error, constraint.Message, constraint.Caller);
      }

      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[5];}); // test ok
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[2];}); // test shows an error message.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement) {Throws<ExceptionType>(statement, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[5];}, "User message..."); // test ok
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[2];}, "User message..."); // test shows an error message.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement, const string& message) {Throws<ExceptionType>(statement, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[5];}, caller_); // test ok
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[2];}, caller_); // test shows an error message.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement, const System::Runtime::CompilerServices::Caller& caller) {Throws<ExceptionType>(statement, "", caller);}

      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[5];}, "User message...", caller_); // test ok
      /// Expect::Throws<ArgumentOutOfRangeException>(delegate_ {a[2];}, "User message...", caller_); // test shows an error message.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        try {
          statement();
          Fail(string::Format("Expected: <{0}>{1}But was:  <nothing>",  typeof_<ExceptionType>().FullName(), System::Environment::NewLine), message, caller);
        } catch (const AssertionException&) {
          throw;
        } catch (const ExceptionType&) {
          Succeed(message, caller);
        } catch (const System::Exception& exception) {
          Fail(string::Format("Expected: <{0}>{1}But was:  <{2}>",  typeof_<ExceptionType>().FullName(), System::Environment::NewLine, exception.GetType().FullName()), message, caller);
        } catch (...) {
          Fail(string::Format("Expected: <{0}>{1}But was:  <exception>",  typeof_<ExceptionType>().FullName(), System::Environment::NewLine), message, caller);
        }
      }

      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::ThrowsAny(delegate_ {a[5];}); // test ok
      /// Expect::ThrowsAny(delegate_ {a[2];}); // test shows an error message.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement) {ThrowsAny(statement, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::ThrowsAny(delegate_ {a[5];}, "User message..."); // test ok
      /// Expect::ThrowsAny(delegate_ {a[2];}, "User message..."); // test shows an error message.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement, const string& message) {ThrowsAny(statement, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::ThrowsAny(delegate_ {a[5];}, caller_); // test ok
      /// Expect::ThrowsAny(delegate_ {a[2];}, caller_); // test shows an error message.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement, const System::Runtime::CompilerServices::Caller& caller) {ThrowsAny(statement, "", caller);}

      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Expect::ThrowsAny(delegate_ {a[5];}, "User message...", caller_); // test ok
      /// Expect::ThrowsAny(delegate_ {a[2];}, "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement, const string& message, const System::Runtime::CompilerServices::Caller& caller) {
        try {
          statement();
          Fail(string::Format("Expected: <exception>{0}But was:  <nothing>", System::Environment::NewLine), message, caller);
        } catch (const AssertionException&) {
          throw;
        } catch (...) {
          Succeed(message, caller);
        }
      }

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::True(String::IsNullOrEmpty(s1)); // test ok
      /// Expect::True(String::IsNullOrEmpty(s2)); // test shows an error message.
      /// @endcode
      static inline void True(bool condition) {return IsTrue(condition, "", System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::True(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Expect::True(String::IsNullOrEmpty(s2), "User message..."); // test shows an error message.
      /// @endcode
      static inline void True(bool condition, const string& message) {IsTrue(condition, message, System::Runtime::CompilerServices::Caller());}

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::True(String::IsNullOrEmpty(s1), caller_); // test ok
      /// Expect::True(String::IsNullOrEmpty(s2), caller_); // test shows an error message.
      /// @endcode
      static inline void True(bool condition, const System::Runtime::CompilerServices::Caller& caller) {IsTrue(condition, "", caller);}

      /// @brief Expect that a condition is true. If they are, then an error message is show.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param caller Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Expect::True(String::IsNullOrEmpty(s1), "User message...", caller_); // test ok
      /// Expect::True(String::IsNullOrEmpty(s2), "User message...", caller_); // test shows an error message.
      /// @endcode
      static inline void True(bool condition, const string& message, const System::Runtime::CompilerServices::Caller& caller) {IsTrue(condition, message, caller);}

    protected:
      Expect() = delete;

      template<typename TValue>
      static string ToString(const string& operation, const TValue& value) {
        return string::Format("Expected:{0}{1}But was:  {2}", string::IsNullOrEmpty(operation) ? "" : string::Format(" {0}", operation), System::Environment::NewLine, ValueToString(value));
      }

      template<typename TExpected, typename TActual>
      static string ToString(const string& operation, const TExpected& expected, const TActual& actual) {
        return string::Format("Expected:{0} {1} {2}But was:  {3}", string::IsNullOrEmpty(operation) ? "" : string::Format(" {0}", operation), ValueToString(expected), System::Environment::NewLine, ValueToString(actual));
      }

      static System::String ValueToString(bool value) {return string::Format("{0}", value);}
      static System::String String(byte value) {return string::Format("{0}", value);}
      static System::String ValueToString(char value) {return string::Format("{0}", value);}
      static System::String ValueToString(unsigned char value) {return string::Format("{0}", value);}
      static System::String ValueToString(char16 value) {return string::Format("{0}", value);}
      static System::String ValueToString(char32 value) {return string::Format("{0}", value);}
      static System::String ValueToString(wchar value) {return string::Format("{0}", value);}
      static System::String ValueToString(int16 value) {return string::Format("{0}", value);}
      static System::String ValueToString(int32 value) {return string::Format("{0}", value);}
      static System::String ValueToString(int64 value) {return System::Int64(value).ToString();}
      static System::String ValueToString(const llong& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const void* value) {return string::Format("0x{0:X}", value);}
      static System::String ValueToString(void* value) {return string::Format("0x{0:X}", value);}
      static System::String ValueToString(sbyte value) {return string::Format("{0}", value);}
      static System::String ValueToString(float value) {return string::Format("{0}", value);}
      static System::String ValueToString(const char* value) {return ValueToString(string(value));}
      static System::String ValueToString(const char16* value) {return ValueToString(string(value));}
      static System::String ValueToString(const char32* value) {return ValueToString(string(value));}
      static System::String ValueToString(const wchar* value) {return ValueToString(string(value));}
      static System::String ValueToString(uint16 value) {return string::Format("{0}", value);}
      static System::String ValueToString(uint32 value) {return string::Format("{0}", value);}
      static System::String ValueToString(uint64 value) {return string::Format("{0}", value);}
      static System::String ValueToString(const ullong& value) {return string::Format("{0}", value);}

      static System::String ValueToString(const System::Boolean& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::Byte& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::Char& value) {return string::Format("{0}", value);}
      static System::String ValueToString(double value) {return System::Double(value).ToString();}
      static System::String ValueToString(const System::Double& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::Int16& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::Int32& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::Int64& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::IntPtr& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::SByte& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::Single& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::UInt16& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::UInt32& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::UInt64& value) {return string::Format("{0}", value);}
      static System::String ValueToString(const System::Object& value) {return string::Format("<{0}>", value);}
      static System::String ValueToString(const string& value) {
        if (string::IsNullOrEmpty(value)) return "<string::Empty>";
        return string::Format("\"{0}\"", value);
      }

      struct StringerFromObject {
        template <typename O>
        string operator()(const O& value) {return string::Format("<{0}>", value);}
      };

      struct StringerFromOther {
        template <typename O>
        string operator()(const O& value) {
          size_t size = sizeof(O) > 32 ? 32 : sizeof(O);
          return string::Format("{0}-byte object <{1}{2}>", static_cast<int32>(sizeof(O)), System::BitConverter::ToString(System::Array<byte>((byte*)&value, static_cast<int32>(size))), size < sizeof(O) ? "-..." : "");
        }
      };

      template<typename TValue>
      static System::String ValueToString(const TValue& value) {
        using Stringer = typename std::conditional<std::is_base_of<object, TValue>::value, StringerFromObject, StringerFromOther>::type;
        Stringer stringer;
        return stringer(value);
      }

      template<typename TValue, typename TAttribute>
      static System::String ValueToString(const property_<TValue, TAttribute>& value) {return ValueToString(value());}

      template<typename TValue>
      static System::String ValueToString(const ref<TValue>& value) {return ValueToString(value());}

      template<typename TValue>
      static System::String ValueToString(const TValue* value) {return ValueToString((const void*)value);}
    };
  }
}

using namespace Switch;
