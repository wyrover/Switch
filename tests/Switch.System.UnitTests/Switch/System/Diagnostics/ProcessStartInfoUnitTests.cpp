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
      Assert::IsEmpty(psi.Arguments, _caller);
      Assert::IsFalse(psi.CreateNoWindow, _caller);
      Assert::IsEmpty(psi.Domain, _caller);
      Assert::IsEmpty(psi.EnvironmentVariables(), _caller);
      Assert::IsFalse(psi.ErrorDialog, _caller);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), _caller);
      Assert::IsEmpty(psi.FileName, _caller);
      Assert::IsFalse(psi.LoadUserProfile, _caller);
      Assert::IsEmpty(psi.PasswordInClearText, _caller);
      Assert::IsFalse(psi.RedirectStandardError, _caller);
      Assert::IsFalse(psi.RedirectStandardInput, _caller);
      Assert::IsFalse(psi.RedirectStandardOutput, _caller);
    }
    
    void ConstructorWithFileName() {
      ProcessStartInfo psi("FileName");
      Assert::IsEmpty(psi.Arguments, _caller);
      Assert::IsFalse(psi.CreateNoWindow, _caller);
      Assert::IsEmpty(psi.Domain, _caller);
      Assert::IsEmpty(psi.EnvironmentVariables(), _caller);
      Assert::IsFalse(psi.ErrorDialog, _caller);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), _caller);
      Assert::AreEqual("FileName", psi.FileName, _caller);
      Assert::IsFalse(psi.LoadUserProfile, _caller);
      Assert::IsEmpty(psi.PasswordInClearText, _caller);
      Assert::IsFalse(psi.RedirectStandardError, _caller);
      Assert::IsFalse(psi.RedirectStandardInput, _caller);
      Assert::IsFalse(psi.RedirectStandardOutput, _caller);
    }
    
    void ConstructorWithFileNameAndArgument() {
      ProcessStartInfo psi("FileName", "Arguments");
      Assert::AreEqual("Arguments", psi.Arguments, _caller);
      Assert::IsFalse(psi.CreateNoWindow, _caller);
      Assert::IsEmpty(psi.Domain, _caller);
      Assert::IsEmpty(psi.EnvironmentVariables(), _caller);
      Assert::IsFalse(psi.ErrorDialog), _caller;
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), _caller);
      Assert::AreEqual("FileName", psi.FileName, _caller);
      Assert::IsFalse(psi.LoadUserProfile, _caller);
      Assert::IsEmpty(psi.PasswordInClearText, _caller);
      Assert::IsFalse(psi.RedirectStandardError, _caller);
      Assert::IsFalse(psi.RedirectStandardInput, _caller);
      Assert::IsFalse(psi.RedirectStandardOutput, _caller);
    }
    
    void ConstructorByCopy() {
      ProcessStartInfo psiOriginal("FileName", "Arguments");
      ProcessStartInfo psi = psiOriginal;
      Assert::AreEqual(psiOriginal.Arguments, psi.Arguments, _caller);
      Assert::AreEqual(psiOriginal.CreateNoWindow, psi.CreateNoWindow, _caller);
      Assert::AreEqual(psiOriginal.Domain, psi.Domain, _caller);
      Assert::AreEqual(psiOriginal.EnvironmentVariables, psi.EnvironmentVariables, _caller);
      Assert::AreEqual(psiOriginal.ErrorDialog, psi.ErrorDialog, _caller);
      Assert::AreEqual(psiOriginal.ErrorDialogParamHandle, psi.ErrorDialogParamHandle, _caller);
      Assert::AreEqual(psiOriginal.FileName, psi.FileName, _caller);
    }
    
    void SetPasswordThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      char32 password[] = {'M', 'y', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd'};
      psi.Pasword = System::Security::SecureString(password, 11);
      Assert::AreEqual("My password", psi.PasswordInClearText, _caller);
    }
    
    void SetPasswordInClearTextThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      psi.PasswordInClearText = "My password";
      Assert::AreEqual("My password", psi.PasswordInClearText, _caller);
    }
  };
  
  _AddTest(ProcessStartInfoUnitTest, Constructor)
  _AddTest(ProcessStartInfoUnitTest, ConstructorWithFileName)
  _AddTest(ProcessStartInfoUnitTest, ConstructorWithFileNameAndArgument)
  _AddTest(ProcessStartInfoUnitTest, ConstructorByCopy)
  _AddTest(ProcessStartInfoUnitTest, SetPasswordThenCheckPasswordInClearText)
  _AddTest(ProcessStartInfoUnitTest, SetPasswordInClearTextThenCheckPasswordInClearText)
}
