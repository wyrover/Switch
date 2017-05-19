/// @file
/// @brief Contains Pcf::TUnit::Assert class.
#pragma once

#include "AssertionException.h"
#include "AssertionResult.h"
#include "Is.h"
#include <Pcf/System/BitConverter.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/Environment.h>
#include <Pcf/System/Object.h>
#include <Pcf/System/String.h>
#include <Pcf/System/SystemException.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #pcf_test method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #pcf_test method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The Assert class contains a collection of static methods that implement the most common assertions used in Pcf::TUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include Assert.cpp
    class pcf_public Assert : private object {
    public:
      /// @brief Verifies that two type are equal. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreEqual(24, int32(24)); // test ok
      /// TUnit::Assert::AreEqual(23, int32(24)); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual) {AreEqual(expected, actual, "", CurrentInformation());}
      
      /// @brief Verifies that two type are equal. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreEqual(24, int32(24), "User message..."); // test ok
      /// TUnit::Assert::AreEqual(23, int32(24), "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual, const string& message) {AreEqual(expected, actual, message, CurrentInformation());}
      
      /// @brief Verifies that two type are equal. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreEqual(24, int32(24), pcf_current_information); // test ok
      /// TUnit::Assert::AreEqual(23, int32(24), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual, const CurrentInformation& currentInformation) {AreEqual(expected, actual, "", currentInformation);}
      
      /// @brief Verifies that two type are equal. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreEqual(24, int32(24), "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::AreEqual(23, int32(24), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreEqual(const TExpected& expected, const TActual& actual, const string& message, const CurrentInformation& currentInformation) {
        if (actual == expected)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, currentInformation);
      }
      
      /// @brief Verifies that two type are not equal. If they are, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreNotEqual(23, int32(24)); // test ok
      /// TUnit::Assert::AreNotEqual(24, int32(24)); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual) {AreNotEqual(expected, actual, "", CurrentInformation());}
      
      /// @brief Verifies that two type are not equal. If they are, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreNotEqual(23, int32(24), "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::AreNotEqual(24, int32(24), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual, const string& message) {AreNotEqual(expected, actual, message, CurrentInformation());}
      
      /// @brief Verifies that two type are not equal. If they are, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreNotEqual(23, int32(24), "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::AreNotEqual(24, int32(24), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual, const CurrentInformation& currentInformation) {AreNotEqual(expected, actual, "", currentInformation);}
      
      /// @brief Verifies that two type are not equal. If they are, then an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::AreNotEqual(23, int32(24), "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::AreNotEqual(24, int32(24), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotEqual(const TExpected& expected, const TActual& actual, const string& message, const CurrentInformation& currentInformation) {
        if (actual != expected)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, currentInformation);
      }
      
      /// @brief Asserts that two objects do refer to differents objects. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AreNotSame(c, a); // test ok
      /// TUnit::Assert::AreNotSame(b, a); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual) {AreNotSame(expected, actual, "", CurrentInformation());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AreNotSame(c, a, "User message..."); // test ok
      /// TUnit::Assert::AreNotSame(b, a, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual, const string& message) {AreNotSame(expected, actual, message, CurrentInformation());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AreNotSame(c, a, pcf_current_information); // test ok
      /// TUnit::Assert::AreNotSame(b, a, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual, const CurrentInformation& currentInformation) {AreNotSame(expected, actual, "", currentInformation);}

      /// @brief Asserts that two objects do refer to differents objects. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AreNotSame(c, a, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::AreNotSame(b, a, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreNotSame(const TExpected& expected, const TActual& actual, const string& message, const CurrentInformation& currentInformation) {
        if (&actual != &expected)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not same as {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, currentInformation);
      }
      
      /// @brief Asserts that two objects do refer to the same object. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AretSame(b, a); // test ok
      /// TUnit::Assert::AretSame(c, a); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual) {AreSame(expected, actual, "", CurrentInformation());}
      
      /// @brief Asserts that two objects do refer to the same object. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AreSame(b, a, "User message..."); // test ok
      /// TUnit::Assert::AreSame(c, a, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual, const string& message) {AreSame(expected, actual, message, CurrentInformation());}
      
      /// @brief Asserts that two objects do refer to the same object. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AreSame(b, a, pcf_current_information); // test ok
      /// TUnit::Assert::AreSame(c, a, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual, const CurrentInformation& currentInformation) {AreSame(expected, actual, "", currentInformation);}
      
      /// @brief Asserts that two objects do refer to the same object. If they are the same an Pcf::TUnit::AssertionException is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int32 a = 24;
      /// int32& b = a;
      /// int32 c=  24;
      /// TUnit::Assert::AreSame(b, a, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::AreSame(c, a, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void AreSame(const TExpected& expected, const TActual& actual, const string& message, const CurrentInformation& currentInformation) {
        if (&actual == &expected)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: same as {0}{1}But was:  {2}", ValueToString(expected), System::Environment::NewLine, ValueToString(actual)), message, currentInformation);
      }
      
      /// @brief Verifies that collection contains an item. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param item object to verify.
      /// @param collection ICollection that contains object.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Assert::Contains(2, a1); // test ok
      /// TUnit::Assert::Contains(4, a1); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection) {Contains(item, collection, "", CurrentInformation());}
      
      /// @brief Verifies that collection contains an item. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param item object to verify.
      /// @param collection ICollection that contains object.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Assert::Contains(2, a1, "User message..."); // test ok
      /// TUnit::Assert::Contains(4, a1, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection, const string& message) {Contains(item, collection, message, CurrentInformation());}
      
      /// @brief Verifies that collection contains an item. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param item object to verify.
      /// @param collection ICollection that contains object.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Assert::Contains(2, a1, pcf_current_information); // test ok
      /// TUnit::Assert::Contains(4, a1, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection, const CurrentInformation& currentInformation) {Contains(item, collection, "", currentInformation);}
      
      /// @brief Verifies that collection contains an item. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param item object to verify.
      /// @param collection ICollection that contains object.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> a1 = {0, 1, 2, 3};
      /// TUnit::Assert::Contains(2, a1, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::Contains(4, a1, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TItemCollection>
      static inline void Contains(const TItem& item, const System::Collections::Generic::ICollection<TItemCollection>& collection, const string& message, const CurrentInformation& currentInformation) {
        if (collection.Contains(item))
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: collection containing {0}{1}But was:  < {2} >", ValueToString(item), System::Environment::NewLine, string::Join(", ", collection)), message, currentInformation);
      }
      
      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::DoesNotThrows(pcf_delegate {a[2];}); // test ok
      /// Assert::DoesNotThrows(pcf_delegate {a[5];}); // test throws an AssertionException.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement) {DoesNotThrows(statement, "", CurrentInformation());}
      
      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::DoesNotThrows(pcf_delegate {a[2];}, "User message..."); // test ok
      /// Assert::DoesNotThrows(pcf_delegate {a[5];}, "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement, const string& message) {DoesNotThrows(statement, message, CurrentInformation());}
      
      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::DoesNotThrows(pcf_delegate {a[2];}, pcf_current_information); // test ok
      /// Assert::DoesNotThrows(pcf_delegate {a[5];}, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement, const CurrentInformation& currentInformation) {DoesNotThrows(statement, "", currentInformation);}
      
      /// @brief Verifies that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::DoesNotThrows(pcf_delegate {a[2];}, "User message...", pcf_current_information); // test ok
      /// Assert::DoesNotThrows(pcf_delegate {a[5];}, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void DoesNotThrows(const System::Delegate<void>& statement, const string& message, const CurrentInformation& currentInformation) {
        try {
          statement();
          Succeed(message, currentInformation);
        } catch (const AssertionException&) {
          throw;
        } catch(const System::Exception& exception) {
          Fail(string::Format("Expected: No Exception to be thrown{0}But was:  <{1}>", System::Environment::NewLine, exception.GetType().FullName()), message, currentInformation);
        } catch(...) {
          Fail(string::Format("Expected: No Exception to be thrown{0}But was:  <exception>", System::Environment::NewLine), message, currentInformation);
        }
      }

      /// @brief The Equals method throws an Pcf::TUnit::AssertionException. This is done to make sure there is no mistake by calling this function.
      static inline bool Equals(const Object&, const Object&) { throw AssertionException(pcf_current_information); }

      /// @brief Throws an Pcf::TUnit::AssertionException. This is used by the other Assert functions.
      static inline void Fail() {Fail("", "", CurrentInformation());}
      
      /// @brief Throws an Pcf::TUnit::AssertionException. This is used by the other Assert functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      static inline void Fail(const string& message) {Fail("", message, CurrentInformation());}
      
      /// @brief Throws an Pcf::TUnit::AssertionException. This is used by the other Assert functions.
      /// @param currentInformation Contains information about current file and current line.
      static inline void Fail(const CurrentInformation& currentInformation) {Fail("", "", currentInformation);}
      
      /// @brief Throws an Pcf::TUnit::AssertionException. This is used by the other Assert functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      static inline void Fail(const string& message, const CurrentInformation& currentInformation) {Fail("", message, currentInformation);}
      
      /// @brief Throws an Pcf::TUnit::AssertionException. This is used by the other Assert functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      static inline void Fail(const string& error, const string& message, const CurrentInformation& currentInformation) {
        if (!message.IsEmpty())
          System::Console::WriteLine(message);
        //::testing::internal::AssertHelper(::testing::TestPartResult::kFatalFailure, currentInformation.FileName().Data, currentInformation.Line, error.Data) = ::testing::Message(message.Data);
        ::testing::internal::AssertHelper(::testing::TestPartResult::kFatalFailure, currentInformation.FileName().Data, currentInformation.Line, error.Data) = ::testing::Message();
        throw AssertionException(message, CurrentInformation(currentInformation.FileName, currentInformation.Line));
      }
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::False(String::IsNullOrEmpty(s1)); // test ok
      /// Assert::False(String::IsNullOrEmpty(s2)); // test throws an AssertionException.
      /// @endcode
      static inline void False(bool condition) {return IsFalse(condition, "", CurrentInformation());}
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::False(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Assert::False(String::IsNullOrEmpty(s2), "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void False(bool condition, const string& message) {IsFalse(condition, message, CurrentInformation());}
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::False(String::IsNullOrEmpty(s1), pcf_current_information); // test ok
      /// Assert::False(String::IsNullOrEmpty(s2), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void False(bool condition, const CurrentInformation& currentInformation) {IsFalse(condition, "", currentInformation);}
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::False(String::IsNullOrEmpty(s1), "User message...", pcf_current_information); // test ok
      /// Assert::False(String::IsNullOrEmpty(s2), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void False(bool condition, const string& message, const CurrentInformation& currentInformation) {IsFalse(condition, message, currentInformation);}
      
      /// @brief Verifies that the first value is greater than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Greater(24, 12); // test ok
      /// TUnit::Assert::Greater(24, 48); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static inline void Greater(const TExpected& val1, const TActual& val2) {Greater(val1, val2, "", CurrentInformation());}
      
      /// @brief Verifies that the first value is greater than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Greater(24, 12, "User message..."); // test ok
      /// TUnit::Assert::Greater(24, 48, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Greater(const TValue1& val1, const TValue2& val2, const string& message) {Greater(val1, val2, message, CurrentInformation());}
      
      /// @brief Verifies that the first value is greater than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Greater(24, 12, pcf_current_information); // test ok
      /// TUnit::Assert::Greater(24, 48, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Greater(const TValue1& val1, const TValue2& val2, const CurrentInformation& currentInformation) {Greater(val1, val2, "", currentInformation);}
      
      /// @brief Verifies that the first value is greater than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Greater(24, 12, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::Greater(24, 48, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Greater(const TValue1& val1, const TValue2& val2, const string& message, const CurrentInformation& currentInformation) {
        if (val1 > val2)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: greater than {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, currentInformation);
      }
      
      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Assert::GreaterOrEqual(24, 12); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 24); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 48); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2) {GreaterOrEqual(val1, val2, "", CurrentInformation());}
      
      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Assert::GreaterOrEqual(24, 12, "User message..."); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 24, "User message..."); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 48, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2, const string& message) {GreaterOrEqual(val1, val2, message, CurrentInformation());}
      
      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::GreaterOrEqual(24, 12, pcf_current_information); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 24, pcf_current_information); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 48, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2, const CurrentInformation& currentInformation) {GreaterOrEqual(val1, val2, "", currentInformation);}
      
      /// @brief Verifies that the first value is greater or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::GreaterOrEqual(24, 12, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 24, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::GreaterOrEqual(24, 48, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void GreaterOrEqual(const TValue1& val1, const TValue2& val2, const string& message, const CurrentInformation& currentInformation) {
        if (val1 >= val2)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: greater than or equal to {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, currentInformation);
      }
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Assert::IsEmpty(v1); // test ok
      /// Assert::IsEmpty(v2); // test throws an AssertionException.
      /// @endcode
      static inline void IsEmpty(const System::String& value) {IsEmpty(value, "", CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Assert::IsEmpty(v1, "User message..."); // test ok
      /// Assert::IsEmpty(v2, "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void IsEmpty(const System::String& value, const string& message) {IsEmpty(value, message, CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Assert::IsEmpty(v1, pcf_current_information); // test ok
      /// Assert::IsEmpty(v2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsEmpty(const string& value, const CurrentInformation& currentInformation) {IsEmpty(value, "", currentInformation);}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1;
      /// string v2 = "Not empty";
      /// Assert::IsEmpty(v1, "User message...", pcf_current_information); // test ok
      /// Assert::IsEmpty(v2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsEmpty(const string& value, const string& message, const CurrentInformation& currentInformation) {
        if (value.IsEmpty())
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: <Empty>{0}But was:  {1}", System::Environment::NewLine, ValueToString(value)), message, currentInformation);
      }
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> v2 = {0, 1, 2};
      /// Assert::IsEmpty(c1); // test ok
      /// Assert::IsEmpty(c2); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection) {IsEmpty(collection, "", CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> v2 = {0, 1, 2};
      /// Assert::IsEmpty(c1, "User message..."); // test ok
      /// Assert::IsEmpty(c2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message) {IsEmpty(collection, message, CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> c2 = {0, 1, 2};
      /// Assert::IsEmpty(c1, pcf_current_information); // test ok
      /// Assert::IsEmpty(c2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const CurrentInformation& currentInformation) {IsEmpty(collection, "", currentInformation);}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1;
      /// Array<int> c2 = {0, 1, 2};
      /// Assert::IsEmpty(c1, "User message...", pcf_current_information); // test ok
      /// Assert::IsEmpty(c2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message, const CurrentInformation& currentInformation) {
        if (collection.GetEnumerator().MoveNext() == false)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: <empty>{0}But was:  < {1} >", System::Environment::NewLine, string::Join(", ", collection)), message, currentInformation);
      }
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::IsFalse(String::IsNullOrEmpty(s1)); // test ok
      /// Assert::IsFalse(String::IsNullOrEmpty(s2)); // test throws an AssertionException.
      /// @endcode
      static inline void IsFalse(bool condition) {return IsFalse(condition, "", CurrentInformation());}
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::IsFalse(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Assert::IsFalse(String::IsNullOrEmpty(s2), "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void IsFalse(bool condition, const string& message) {IsFalse(condition, message, CurrentInformation());}
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::IsFalse(String::IsNullOrEmpty(s1), pcf_current_information); // test ok
      /// Assert::IsFalse(String::IsNullOrEmpty(s2), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsFalse(bool condition, const CurrentInformation& currentInformation) {IsFalse(condition, "", currentInformation);}
      
      /// @brief Asserts that a condition is false. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1 = "Anything";
      /// string s2;
      /// Assert::IsFalse(String::IsNullOrEmpty(s1), "User message...", pcf_current_information); // test ok
      /// Assert::IsFalse(String::IsNullOrEmpty(s2), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsFalse(bool condition, const string& message, const CurrentInformation& currentInformation) {
        if (condition == false)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: False{0}But was:  True", System::Environment::NewLine), message, currentInformation);
      }
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOf<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value) {IsInstanceOf<TT>(value, "", CurrentInformation());}
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOf<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value, const string& message) {IsInstanceOf<TT>(value, message, CurrentInformation());}
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOf<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value, const CurrentInformation& currentInformation) {IsInstanceOf<TT>(value, "", currentInformation);}
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOf<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOf<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOf(const TValue& value, const string& message, const CurrentInformation& currentInformation) {
        if (is<TT>(value))
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: instance of <{0}>{1}But was:  <{2}>", pcf_typeof(value), System::Environment::NewLine, pcf_typeof<TT>()), message, currentInformation);
      }
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value) {IsInstanceOf<TT>(value, "", CurrentInformation());}
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value, const string& message) {IsInstanceOf<TT>(value, message, CurrentInformation());}
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value, const CurrentInformation& currentInformation) {IsInstanceOf<TT>(value, "", currentInformation);}
      
      /// @brief Verify that an object is of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsInstanceOfType<string>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<IHashable>(str); // test ok
      /// TUnit::Assert::IsInstanceOfType<Int32>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsInstanceOfType(const TValue& value, const string& message, const CurrentInformation& currentInformation) {IsInstanceOf<TT, TValue>(value, message, currentInformation);}
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Assert::IsNaN(v1); // test ok
      /// Assert::IsNaN(v2); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(double value) {IsNaN(value, "", CurrentInformation());}
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Assert::IsNaN(v1, "User message..."); // test ok
      /// Assert::IsNaN(v2, "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(double value, const string& message) {IsNaN(value, message, CurrentInformation());}
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Assert::IsNaN(v1, pcf_current_information); // test ok
      /// Assert::IsNaN(v2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(double value, const CurrentInformation& currentInformation) {IsNaN(value, "", currentInformation);}
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// double v1 = Double::NaN;
      /// double v2 = Math::PI;
      /// Assert::IsNaN(v1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNaN(v2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(double value, const string& message, const CurrentInformation& currentInformation) {
        if (System::Double::IsNaN(value))
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: NaN{0}But was:  {1}", System::Environment::NewLine, ValueToString(value)), message, currentInformation);
      }
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Assert::IsNaN(v1); // test ok
      /// Assert::IsNaN(v2); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(float value) {IsNaN(value, "", CurrentInformation());}
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Assert::IsNaN(v1, "User message..."); // test ok
      /// Assert::IsNaN(v2, "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(float value, const string& message) {IsNaN(value, message, CurrentInformation());}
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Assert::IsNaN(v1, pcf_current_information); // test ok
      /// Assert::IsNaN(v2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(float value, const CurrentInformation& currentInformation) {IsNaN(value, "", currentInformation);}
      
      /// @brief Asserts that a value is NaN. If the value is not NaN the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is NaN.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// float v1 = Single::NaN;
      /// float v2 = Math::PI;
      /// Assert::IsNaN(v1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNaN(v2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsNaN(float value, const string& message, const CurrentInformation& currentInformation) {
        if (System::Double::IsNaN(value))
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: NaN{0}But was:  {1}", System::Environment::NewLine, ValueToString(value)), message, currentInformation);
      }
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Assert::IsNotEmpty(v1); // test ok
      /// Assert::IsNotEmpty(v2); // test throws an AssertionException.
      /// @endcode
      static inline void IsNotEmpty(const System::String& value) {IsNotEmpty(value, "", CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Assert::IsNotEmpty(v1, "User message..."); // test ok
      /// Assert::IsNotEmpty(v2, "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void IsNotEmpty(const System::String& value, const string& message) {IsNotEmpty(value, message, CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Assert::IsNotEmpty(v1, pcf_current_information); // test ok
      /// Assert::IsNotEmpty(v2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsNotEmpty(const string& value, const CurrentInformation& currentInformation) {IsNotEmpty(value, "", currentInformation);}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string v1 = "Not empty";
      /// string v2;
      /// Assert::IsNotEmpty(v1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNotEmpty(v2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsNotEmpty(const string& value, const string& message, const CurrentInformation& currentInformation) {
        if (!value.IsEmpty())
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not <empty>{0}But was:  <empty>", System::Environment::NewLine), message, currentInformation);
      }
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> v2;
      /// Assert::IsNotEmpty(c1); // test ok
      /// Assert::IsNotEmpty(c2); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection) {IsNotEmpty(collection, "", CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> v2;
      /// Assert::IsNotEmpty(c1, "User message..."); // test ok
      /// Assert::IsNotEmpty(c2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message) {IsNotEmpty(collection, message, CurrentInformation());}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> c2;
      /// Assert::IsNotEmpty(c1, pcf_current_information); // test ok
      /// Assert::IsNotEmpty(c2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const CurrentInformation& currentInformation) {IsNotEmpty(collection, "", currentInformation);}
      
      /// @brief Asserts that a value is empty. If the value is not Empty the method throws an Pcf::TUnit::AssertionException.
      /// @param value The value to check is empty.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int> c1 = {0, 1, 2};
      /// Array<int> c2;
      /// Assert::IsNotEmpty(c1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNotEmpty(c2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TItem>
      static inline void IsNotEmpty(const System::Collections::Generic::IEnumerable<TItem>& collection, const string& message, const CurrentInformation& currentInformation) {
        if (collection.GetEnumerator().MoveNext() == true)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not <empty>{0}But was:  <empty>", System::Environment::NewLine), message, currentInformation);
      }
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOf<Int32>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOf<string>(str); // test throws an AssertionException.
      /// TUnit::Assert::IsNotInstanceOf<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(TValue value) {IsNotInstanceOf<TT>(value, "", CurrentInformation());}
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOf<Int32>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOf<string>(str); // test throws an AssertionException.
      /// TUnit::Assert::IsNotInstanceOf<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(TValue value, const string& message) {IsNotInstanceOf<TT>(value, message, CurrentInformation());}
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOf<string>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOf<IHashable>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOf<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(TValue value, const CurrentInformation& currentInformation) {IsNotInstanceOf<TT>(value, "", currentInformation);}
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOf<Int32>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOf<string>(str); // test throws an AssertionException.
      /// TUnit::Assert::IsNotInstanceOf<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOf(TValue value, const string& message, const CurrentInformation& currentInformation) {
        if (!is<TT>(value))
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not instance of <{0}>{1}But was:  <{2}>", pcf_typeof(value), System::Environment::NewLine, pcf_typeof<TT>()), message, currentInformation);
      }
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOfType<string>(str); // test throws an AssertionException.
      /// TUnit::Assert::IsNotInstanceOfType<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(TValue value) {IsNotInstanceOfType<TT>(value, "", CurrentInformation());}
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOfType<string>(str); // test throws an AssertionException.
      /// TUnit::Assert::IsNotInstanceOfType<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(TValue value, const string& message) {IsNotInstanceOfType<TT>(value, message, CurrentInformation());}
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOfType<string>(str); // test throws an AssertionException.
      /// TUnit::Assert::IsNotInstanceOfType<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(TValue value, const CurrentInformation& currentInformation) {IsNotInstanceOfType<TT>(value, "", currentInformation);}
      
      /// @brief Verify that an object is not of the type supplied or a derived type. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param value The object to verify
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str;
      /// TUnit::Assert::IsNotInstanceOfType<Int32>(str); // test ok
      /// TUnit::Assert::IsNotInstanceOfType<string>(str); // test throws an AssertionException.
      /// TUnit::Assert::IsNotInstanceOfType<IHashable>(str); // test throws an AssertionException.
      /// @endcode
      template<typename TT, typename TValue>
      static inline void IsNotInstanceOfType(TValue value, const string& message, const CurrentInformation& currentInformation) {IsNotInstanceOf<TT, TValue>(value, message, currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::IsNotNull(s1); // test ok
      /// Assert::IsNotNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer) {IsNotNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::IsNotNull(s1, "User message...")); // test ok
      /// Assert::IsNotNull(s2, "User message...")); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer, const string& message) {IsNotNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::IsNotNull(s1, pcf_current_information); // test ok
      /// Assert::IsNotNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer, const CurrentInformation& currentInformation) {IsNotNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::IsNotNull(s1, "User message..."), pcf_current_information); // test ok
      /// Assert::IsNotNull(s2, "User message..."), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const TPointer* pointer, const string& message, const CurrentInformation& currentInformation) {
        if (pointer != null)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not null{0}But was:  null", System::Environment::NewLine), message, currentInformation);
      }
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1); // test ok
      /// Assert::IsNotNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const UniquePtr<TPointer>& pointer) {IsNotNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1, "User message..."); // test ok
      /// Assert::IsNotNull(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const UniquePtr<TPointer>& pointer, const string& message) {IsNotNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1, pcf_current_information); // test ok
      /// Assert::IsNotNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const UniquePtr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNotNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNotNull(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const UniquePtr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {
        if (pointer != null)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not null{0}But was:  null", System::Environment::NewLine), message, currentInformation);
      }
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1); // test ok
      /// Assert::IsNotNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer) {IsNotNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1, "User message..."); // test ok
      /// Assert::IsNotNull(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer, const string& message) {IsNotNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1, pcf_current_information); // test ok
      /// Assert::IsNotNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNotNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNotNull(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNotNull(const refptr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {
        if (pointer != null)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: not null{0}But was:  null", System::Environment::NewLine), message, currentInformation);
      }
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::IsNull(s1); // test ok
      /// Assert::IsNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer) {IsNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::IsNull(s1, "User message...")); // test ok
      /// Assert::IsNull(s2, "User message...")); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer, const string& message) {IsNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::IsNull(s1, pcf_current_information); // test ok
      /// Assert::IsNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer, const CurrentInformation& currentInformation) {IsNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::IsNull(s1, "User message..."), pcf_current_information); // test ok
      /// Assert::IsNull(s2, "User message..."), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const TPointer* pointer, const string& message, const CurrentInformation& currentInformation) {
        if (pointer == null)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: null{0}But was:  {1}", System::Environment::NewLine, ValueToString(*pointer)), message, currentInformation);
      }
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::IsNull(s1); // test ok
      /// Assert::IsNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const UniquePtr<TPointer>& pointer) {IsNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, "User message..."); // test ok
      /// Assert::IsNull(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const UniquePtr<TPointer>& pointer, const string& message) {IsNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, pcf_current_information); // test ok
      /// Assert::IsNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const UniquePtr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNull(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const UniquePtr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {
        if (pointer == null)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: null{0}But was:  {1}", System::Environment::NewLine, ValueToString(*pointer)), message, currentInformation);
      }
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1); // test ok
      /// Assert::IsNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer) {IsNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, "User message..."); // test ok
      /// Assert::IsNull(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer, const string& message) {IsNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, pcf_current_information); // test ok
      /// Assert::IsNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNull(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const refptr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {
        if (pointer == null)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: null{0}But was:  {1}", System::Environment::NewLine, ValueToString(*pointer)), message, currentInformation);
      }
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1); // test ok
      /// Assert::IsNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const ref<TPointer>& pointer) {IsNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, "User message..."); // test ok
      /// Assert::IsNull(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const ref<TPointer>& pointer, const string& message) {IsNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, pcf_current_information); // test ok
      /// Assert::IsNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const ref<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::IsNull(s1, "User message...", pcf_current_information); // test ok
      /// Assert::IsNull(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void IsNull(const ref<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {
        if (pointer == null)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: null{0}But was:  {1}", System::Environment::NewLine, ValueToString(pointer)), message, currentInformation);
      }
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::IsTrue(String::IsNullOrEmpty(s1)); // test ok
      /// Assert::IsTrue(String::IsNullOrEmpty(s2)); // test throws an AssertionException.
      /// @endcode
      static inline void IsTrue(bool condition) {return IsTrue(condition, "", CurrentInformation());}
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::IsTrue(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Assert::IsTrue(String::IsNullOrEmpty(s2), "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void IsTrue(bool condition, const string& message) {IsTrue(condition, message, CurrentInformation());}
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::IsTrue(String::IsNullOrEmpty(s1), pcf_current_information); // test ok
      /// Assert::IsTrue(String::IsNullOrEmpty(s2), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsTrue(bool condition, const CurrentInformation& currentInformation) {IsTrue(condition, "", currentInformation);}
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::IsTrue(String::IsNullOrEmpty(s1), "User message...", pcf_current_information); // test ok
      /// Assert::IsTrue(String::IsNullOrEmpty(s2), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void IsTrue(bool condition, const string& message, const CurrentInformation& currentInformation) {
        if (condition == true)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: True{0}But was:  False", System::Environment::NewLine), message, currentInformation);
      }
      
      /// @brief Verifies that the first value is less than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Less(12, 24); // test ok
      /// TUnit::Assert::Less(48, 24); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2) {Less(val1, val2, "", CurrentInformation());}
      
      /// @brief Verifies that the first value is less than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Less(24, 12, "User message..."); // test ok
      /// TUnit::Assert::Less(24, 48, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2, const string& message) {Less(val1, val2, message, CurrentInformation());}
      
      /// @brief Verifies that the first value is less than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Less(12, 24, pcf_current_information); // test ok
      /// TUnit::Assert::Less(48, 24, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2, const CurrentInformation& currentInformation) {Less(val1, val2, "", currentInformation);}
      
      /// @brief Verifies that the first value is less than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::Less(24, 12, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::Less(24, 48, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void Less(const TValue1& val1, const TValue2& val2, const string& message, const CurrentInformation& currentInformation) {
        if (val1 < val2)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: less than {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, currentInformation);
      }
      
      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// TUnit::Assert::LessOrEqual(12, 24); // test ok
      /// TUnit::Assert::LessOrEqual(24, 24); // test ok
      /// TUnit::Assert::LessOrEqual(48, 24); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2) {LessOrEqual(val1, val2, "", CurrentInformation());}
      
      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// TUnit::Assert::LessOrEqual(24, 12, "User message..."); // test ok
      /// TUnit::Assert::LessOrEqual(24, 24, "User message..."); // test ok
      /// TUnit::Assert::LessOrEqual(24, 48, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2, const string& message) {LessOrEqual(val1, val2, message, CurrentInformation());}
      
      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::LessOrEqual(12, 24, pcf_current_information); // test ok
      /// TUnit::Assert::LessOrEqual(24, 24, pcf_current_information); // test ok
      /// TUnit::Assert::LessOrEqual(48, 24, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2, const CurrentInformation& currentInformation) {LessOrEqual(val1, val2, "", currentInformation);}
      
      /// @brief Verifies that the first value is less or equal than the second value. If they are not, then an Pcf::TUnit::AssertionException is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// TUnit::Assert::LessOrEqual(12, 24, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::LessOrEqual(24, 24, "User message...", pcf_current_information); // test ok
      /// TUnit::Assert::LessOrEqual(48, 24, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static inline void LessOrEqual(const TValue1& val1, const TValue2& val2, const string& message, const CurrentInformation& currentInformation) {
        if (val1 <= val2)
          Succeed(message, currentInformation);
        else
          Fail(string::Format("Expected: less than or equal to {0}{1}But was:  {2}", ValueToString(val2), System::Environment::NewLine, ValueToString(val1)), message, currentInformation);
      }
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::NotNull(s1); // test ok
      /// Assert::NotNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer) {IsNotNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::NotNull(s1, "User message...")); // test ok
      /// Assert::NotNull(s2, "User message...")); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer, const string& message) {IsNotNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::NotNull(s1, pcf_current_information); // test ok
      /// Assert::NotNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer, const CurrentInformation& currentInformation) {IsNotNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = &str;
      /// string* s2 = null;
      /// Assert::NotNull(s1, "User message..."), pcf_current_information); // test ok
      /// Assert::NotNull(s2, "User message..."), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const TPointer* pointer, const string& message, const CurrentInformation& currentInformation) {IsNotNull(pointer, message, currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::NotNull(s1); // test ok
      /// Assert::NotNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const UniquePtr<TPointer>& pointer) {IsNotNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::NotNull(s1, "User message..."); // test ok
      /// Assert::NotNull(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const UniquePtr<TPointer>& pointer, const string& message) {IsNotNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::NotNull(s1, pcf_current_information); // test ok
      /// Assert::NotNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const UniquePtr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNotNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1 = pcf_new<string>("A string");
      /// refptr<string> s2;
      /// Assert::NotNull(s1, "User message...", pcf_current_information); // test ok
      /// Assert::NotNull(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const UniquePtr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {IsNotNull(pointer, message, currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::IsNotNull(s1); // test ok
      /// Assert::IsNotNull(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer) {IsNotNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::NotNull(s1, "User message..."); // test ok
      /// Assert::NotNull(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer, const string& message) {IsNotNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::NotNull(s1, pcf_current_information); // test ok
      /// Assert::NotNull(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNotNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is not null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1(new string("A string"));
      /// refptr<string> s2;
      /// Assert::NotNull(s1, "User message...", pcf_current_information); // test ok
      /// Assert::NotNull(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void NotNull(const refptr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {IsNotNull(pointer, message, currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::Null(s1); // test ok
      /// Assert::Null(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer) {IsNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::Null(s1, "User message...")); // test ok
      /// Assert::Null(s2, "User message...")); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer, const string& message) {IsNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::Null(s1, pcf_current_information); // test ok
      /// Assert::Null(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer, const CurrentInformation& currentInformation) {IsNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string str = "Anything";
      /// ...
      /// string* s1 = null;
      /// string* s2 = &str;
      /// Assert::Null(s1, "User message..."), pcf_current_information); // test ok
      /// Assert::Null(s2, "User message..."), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const TPointer* pointer, const string& message, const CurrentInformation& currentInformation) {IsNull(pointer, message, currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::Null(s1); // test ok
      /// Assert::Null(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const UniquePtr<TPointer>& pointer) {IsNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::Null(s1, "User message..."); // test ok
      /// Assert::Null(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const UniquePtr<TPointer>& pointer, const string& message) {IsNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::Null(s1, pcf_current_information); // test ok
      /// Assert::Null(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const UniquePtr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// UniquePtr<string> s1;
      /// UniquePtr<string> s2(new string("A string"));
      /// Assert::Null(s1, "User message...", pcf_current_information); // test ok
      /// Assert::Null(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const UniquePtr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {IsNull(pointer, message, currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::Null(s1); // test ok
      /// Assert::Null(s2); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer) {IsNull(pointer, "", CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::Null(s1, "User message..."); // test ok
      /// Assert::Null(s2, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer, const string& message) {IsNull(pointer, message, CurrentInformation());}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::Null(s1, pcf_current_information); // test ok
      /// Assert::Null(s2, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer, const CurrentInformation& currentInformation) {IsNull(pointer, "", currentInformation);}
      
      /// @brief Asserts that the pointer is null. If the pointer is null the method throws an Pcf::TUnit::AssertionException.
      /// @param pointer The pointer to check is null.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// refptr<string> s1;
      /// refptr<string> s2(new string("A string"));
      /// Assert::Null(s1, "User message...", pcf_current_information); // test ok
      /// Assert::Null(s2, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename TPointer>
      static inline void Null(const refptr<TPointer>& pointer, const string& message, const CurrentInformation& currentInformation) {IsNull(pointer, message, currentInformation);}
      
      /// @brief The ReferenceEquals method throws an Pcf::TUnit::AssertionException. This is done to make sure there is no mistake by calling this function.
      static inline bool ReferenceEquals(const Object&, const Object&) { throw AssertionException(pcf_current_information); }
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      static inline void Succeed() {Succeed("", CurrentInformation());}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      static inline void Succeed(const string& message) {Succeed(message, CurrentInformation());}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param currentInformation Contains information about current file and current line.
      static inline void Succeed(const CurrentInformation& currentInformation) {Succeed("", currentInformation); }
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      static inline void Succeed(const string& message, const CurrentInformation& currentInformation) {::testing::internal::AssertHelper(::testing::TestPartResult::kSuccess, currentInformation.FileName().Data, currentInformation.Line, "Succeeded") = ::testing::Message(message.Data);}

      template<typename TActual>
      static void That(const TActual& actual, const Constraints::Constraint& constraint) {That(actual, constraint, "", CurrentInformation());}
      
      template<typename TActual>
      static void That(const TActual& actual, const Constraints::Constraint& constraint, const string message) {That(actual, constraint, message, CurrentInformation());}
      
      template<typename TActual>
      static void That(const TActual& actual, const Constraints::Constraint& constraint, const ::CurrentInformation& currentInformation) {That(actual, constraint, "", currentInformation);}
      
      template<typename TActual>
      static void That(const TActual& actual, const Constraints::Constraint& constraint, const string message, const ::CurrentInformation& currentInformation) {
        const_cast<Constraints::Constraint&>(constraint).Actual = actual;
        const_cast<Constraints::Constraint&>(constraint).Message = message;
        const_cast<Constraints::Constraint&>(constraint).CurrentInformation = currentInformation;
        if (constraint.Verify(actual))
          Succeed(message, currentInformation);
        else
          Fail(constraint.Error, constraint.Message, constraint.CurrentInformation);
      }
      
      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[5];}); // test ok
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[2];}); // test throws an AssertionException.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement) {Throws<ExceptionType>(statement, CurrentInformation());}
      
      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[5];}, "User message..."); // test ok
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[2];}, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement, const string& message) {Throws<ExceptionType>(statement, message, CurrentInformation());}
      
      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[5];}, pcf_current_information); // test ok
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[2];}, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement, const CurrentInformation& currentInformation) {Throws<ExceptionType>(statement, "", currentInformation);}
      
      /// @brief Verifies that the statement throws a particular exception when called.
      /// @param exceptionType The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[5];}, "User message...", pcf_current_information); // test ok
      /// Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[2];}, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      template<typename ExceptionType>
      static inline void Throws(const System::Delegate<void>& statement, const string& message, const CurrentInformation& currentInformation) {
        try {
          statement();
          Fail(string::Format("Expected: <{0}>{1}But was:  <nothing>", pcf_typeof<ExceptionType>().FullName(), System::Environment::NewLine), message, currentInformation);
        } catch (const AssertionException&) {
          throw;
        } catch(const ExceptionType&) {
          Succeed(message, currentInformation);
        } catch (const System::Exception& exception) {
          Fail(string::Format("Expected: <{0}>{1}But was:  <{2}>", pcf_typeof<ExceptionType>().FullName(), System::Environment::NewLine, exception.GetType().FullName()), message, currentInformation);
        } catch (...) {
          Fail(string::Format("Expected: <{0}>{1}But was:  <exception>", pcf_typeof<ExceptionType>().FullName(), System::Environment::NewLine), message, currentInformation);
        }
      }
      
      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::ThrowsAny(pcf_delegate {a[5];}); // test ok
      /// Assert::ThrowsAny(pcf_delegate {a[2];}); // test throws an AssertionException.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement) {ThrowsAny(statement, "", CurrentInformation());}
      
      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::ThrowsAny(pcf_delegate {a[5];}, "User message..."); // test ok
      /// Assert::ThrowsAny(pcf_delegate {a[2];}, "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement, const string& message) {ThrowsAny(statement, message, CurrentInformation());}
      
      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::ThrowsAny(pcf_delegate {a[5];}, pcf_current_information); // test ok
      /// Assert::ThrowsAny(pcf_delegate {a[2];}, pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement, const CurrentInformation& currentInformation) {ThrowsAny(statement, "", currentInformation);}
      
      /// @brief Verifies that the statement throws any exception when called.
      /// @param statement The statement that verify.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// Array<int32> a = {1, 2 ,3, 4};
      /// Assert::ThrowsAny(pcf_delegate {a[5];}, "User message...", pcf_current_information); // test ok
      /// Assert::ThrowsAny(pcf_delegate {a[2];}, "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void ThrowsAny(const System::Delegate<void>& statement, const string& message, const CurrentInformation& currentInformation) {
        try {
          statement();
          Fail(string::Format("Expected: <exception>{0}But was:  <nothing>", System::Environment::NewLine), message, currentInformation);
        } catch (const AssertionException&) {
          throw;
        } catch(...) {
          Succeed(message, currentInformation);
        }
      }
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::True(String::IsNullOrEmpty(s1)); // test ok
      /// Assert::True(String::IsNullOrEmpty(s2)); // test throws an AssertionException.
      /// @endcode
      static inline void True(bool condition) {return IsTrue(condition, "", CurrentInformation());}
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::True(String::IsNullOrEmpty(s1), "User message..."); // test ok
      /// Assert::True(String::IsNullOrEmpty(s2), "User message..."); // test throws an AssertionException.
      /// @endcode
      static inline void True(bool condition, const string& message) {IsTrue(condition, message, CurrentInformation());}
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::True(String::IsNullOrEmpty(s1), pcf_current_information); // test ok
      /// Assert::True(String::IsNullOrEmpty(s2), pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void True(bool condition, const CurrentInformation& currentInformation) {IsTrue(condition, "", currentInformation);}
      
      /// @brief Asserts that a condition is true. If the condition is true the method throws an Pcf::TUnit::AssertionException.
      /// @param condition The condition to check is false.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param currentInformation Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// string s1;
      /// string s2 = "Anything";
      /// Assert::True(String::IsNullOrEmpty(s1), "User message...", pcf_current_information); // test ok
      /// Assert::True(String::IsNullOrEmpty(s2), "User message...", pcf_current_information); // test throws an AssertionException.
      /// @endcode
      static inline void True(bool condition, const string& message, const CurrentInformation& currentInformation) {IsTrue(condition, message, currentInformation);}

    private:
      Assert() = delete;
      
      template<typename TValue>
      static string ToString(const string& operation, const TValue& value) {
        return string::Format("Expected:{0}{1}But was:  {2}", operation.IsEmpty() ? "" : string::Format(" {0}", operation), System::Environment::NewLine, ValueToString(value));
      }
      
      template<typename TExpected, typename TActual>
      static string ToString(const string& operation, const TExpected& expected, const TActual& actual) {
        return string::Format("Expected:{0} {1} {2}But was:  {3}", operation.IsEmpty() ? "" : string::Format(" {0}", operation), ValueToString(expected), System::Environment::NewLine, ValueToString(actual));
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
        if (value.IsEmpty()) return "<string::Empty>";
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
        typedef typename std::conditional<std::is_base_of<object, TValue>::value, StringerFromObject, StringerFromOther>::type Stringer;
        Stringer stringer;
        return stringer(value);
      }
      
      template<typename TValue, typename TAttribute>
      static System::String ValueToString(const Property<TValue, TAttribute>& value) {return ValueToString(value());}
      
      template<typename TValue>
      static System::String ValueToString(const TValue* value) {return ValueToString((const void*)value);}
    };
  }
}

using namespace Pcf;
