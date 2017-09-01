#include <Switch/System/Diagnostics/ProcessStartInfo.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Diagnostics;
using namespace TUnit;

namespace UnitTests {
  class ProcessStartInfoUnitTest : public TUnit::TestFixture {
  protected:
    void Constructor() {
      ProcessStartInfo psi;
      Assert::IsEmpty(psi.Arguments, _current_information);
      Assert::IsFalse(psi.CreateNoWindow, _current_information);
      Assert::IsEmpty(psi.Domain, _current_information);
      Assert::IsEmpty(psi.EnvironmentVariables(), _current_information);
      Assert::IsFalse(psi.ErrorDialog, _current_information);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), _current_information);
      Assert::IsEmpty(psi.FileName, _current_information);
      Assert::IsFalse(psi.LoadUserProfile, _current_information);
      Assert::IsEmpty(psi.PasswordInClearText, _current_information);
      Assert::IsFalse(psi.RedirectStandardError, _current_information);
      Assert::IsFalse(psi.RedirectStandardInput, _current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, _current_information);
    }
    
    void ConstructorWithFileName() {
      ProcessStartInfo psi("FileName");
      Assert::IsEmpty(psi.Arguments, _current_information);
      Assert::IsFalse(psi.CreateNoWindow, _current_information);
      Assert::IsEmpty(psi.Domain, _current_information);
      Assert::IsEmpty(psi.EnvironmentVariables(), _current_information);
      Assert::IsFalse(psi.ErrorDialog, _current_information);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), _current_information);
      Assert::AreEqual("FileName", psi.FileName, _current_information);
      Assert::IsFalse(psi.LoadUserProfile, _current_information);
      Assert::IsEmpty(psi.PasswordInClearText, _current_information);
      Assert::IsFalse(psi.RedirectStandardError, _current_information);
      Assert::IsFalse(psi.RedirectStandardInput, _current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, _current_information);
    }
    
    void ConstructorWithFileNameAndArgument() {
      ProcessStartInfo psi("FileName", "Arguments");
      Assert::AreEqual("Arguments", psi.Arguments, _current_information);
      Assert::IsFalse(psi.CreateNoWindow, _current_information);
      Assert::IsEmpty(psi.Domain, _current_information);
      Assert::IsEmpty(psi.EnvironmentVariables(), _current_information);
      Assert::IsFalse(psi.ErrorDialog), _current_information;
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), _current_information);
      Assert::AreEqual("FileName", psi.FileName, _current_information);
      Assert::IsFalse(psi.LoadUserProfile, _current_information);
      Assert::IsEmpty(psi.PasswordInClearText, _current_information);
      Assert::IsFalse(psi.RedirectStandardError, _current_information);
      Assert::IsFalse(psi.RedirectStandardInput, _current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, _current_information);
    }
    
    void ConstructorByCopy() {
      ProcessStartInfo psiOriginal("FileName", "Arguments");
      ProcessStartInfo psi = psiOriginal;
      Assert::AreEqual(psiOriginal.Arguments, psi.Arguments, _current_information);
      Assert::AreEqual(psiOriginal.CreateNoWindow, psi.CreateNoWindow, _current_information);
      Assert::AreEqual(psiOriginal.Domain, psi.Domain, _current_information);
      Assert::AreEqual(psiOriginal.EnvironmentVariables, psi.EnvironmentVariables, _current_information);
      Assert::AreEqual(psiOriginal.ErrorDialog, psi.ErrorDialog, _current_information);
      Assert::AreEqual(psiOriginal.ErrorDialogParamHandle, psi.ErrorDialogParamHandle, _current_information);
      Assert::AreEqual(psiOriginal.FileName, psi.FileName, _current_information);
    }
    
    void SetPasswordThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      char32 password[] = {'M', 'y', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd'};
      psi.Pasword = System::Security::SecureString(password, 11);
      Assert::AreEqual("My password", psi.PasswordInClearText, _current_information);
    }
    
    void SetPasswordInClearTextThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      psi.PasswordInClearText = "My password";
      Assert::AreEqual("My password", psi.PasswordInClearText, _current_information);
    }
  };
  
  _test(ProcessStartInfoUnitTest, Constructor)
  _test(ProcessStartInfoUnitTest, ConstructorWithFileName)
  _test(ProcessStartInfoUnitTest, ConstructorWithFileNameAndArgument)
  _test(ProcessStartInfoUnitTest, ConstructorByCopy)
  _test(ProcessStartInfoUnitTest, SetPasswordThenCheckPasswordInClearText)
  _test(ProcessStartInfoUnitTest, SetPasswordInClearTextThenCheckPasswordInClearText)
}
