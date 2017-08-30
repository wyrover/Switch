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
      Assert::IsEmpty(psi.Arguments, sw_current_information);
      Assert::IsFalse(psi.CreateNoWindow, sw_current_information);
      Assert::IsEmpty(psi.Domain, sw_current_information);
      Assert::IsEmpty(psi.EnvironmentVariables(), sw_current_information);
      Assert::IsFalse(psi.ErrorDialog, sw_current_information);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), sw_current_information);
      Assert::IsEmpty(psi.FileName, sw_current_information);
      Assert::IsFalse(psi.LoadUserProfile, sw_current_information);
      Assert::IsEmpty(psi.PasswordInClearText, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardError, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardInput, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, sw_current_information);
    }
    
    void ConstructorWithFileName() {
      ProcessStartInfo psi("FileName");
      Assert::IsEmpty(psi.Arguments, sw_current_information);
      Assert::IsFalse(psi.CreateNoWindow, sw_current_information);
      Assert::IsEmpty(psi.Domain, sw_current_information);
      Assert::IsEmpty(psi.EnvironmentVariables(), sw_current_information);
      Assert::IsFalse(psi.ErrorDialog, sw_current_information);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), sw_current_information);
      Assert::AreEqual("FileName", psi.FileName, sw_current_information);
      Assert::IsFalse(psi.LoadUserProfile, sw_current_information);
      Assert::IsEmpty(psi.PasswordInClearText, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardError, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardInput, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, sw_current_information);
    }
    
    void ConstructorWithFileNameAndArgument() {
      ProcessStartInfo psi("FileName", "Arguments");
      Assert::AreEqual("Arguments", psi.Arguments, sw_current_information);
      Assert::IsFalse(psi.CreateNoWindow, sw_current_information);
      Assert::IsEmpty(psi.Domain, sw_current_information);
      Assert::IsEmpty(psi.EnvironmentVariables(), sw_current_information);
      Assert::IsFalse(psi.ErrorDialog), sw_current_information;
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), sw_current_information);
      Assert::AreEqual("FileName", psi.FileName, sw_current_information);
      Assert::IsFalse(psi.LoadUserProfile, sw_current_information);
      Assert::IsEmpty(psi.PasswordInClearText, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardError, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardInput, sw_current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, sw_current_information);
    }
    
    void ConstructorByCopy() {
      ProcessStartInfo psiOriginal("FileName", "Arguments");
      ProcessStartInfo psi = psiOriginal;
      Assert::AreEqual(psiOriginal.Arguments, psi.Arguments, sw_current_information);
      Assert::AreEqual(psiOriginal.CreateNoWindow, psi.CreateNoWindow, sw_current_information);
      Assert::AreEqual(psiOriginal.Domain, psi.Domain, sw_current_information);
      Assert::AreEqual(psiOriginal.EnvironmentVariables, psi.EnvironmentVariables, sw_current_information);
      Assert::AreEqual(psiOriginal.ErrorDialog, psi.ErrorDialog, sw_current_information);
      Assert::AreEqual(psiOriginal.ErrorDialogParamHandle, psi.ErrorDialogParamHandle, sw_current_information);
      Assert::AreEqual(psiOriginal.FileName, psi.FileName, sw_current_information);
    }
    
    void SetPasswordThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      char32 password[] = {'M', 'y', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd'};
      psi.Pasword = System::Security::SecureString(password, 11);
      Assert::AreEqual("My password", psi.PasswordInClearText, sw_current_information);
    }
    
    void SetPasswordInClearTextThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      psi.PasswordInClearText = "My password";
      Assert::AreEqual("My password", psi.PasswordInClearText, sw_current_information);
    }
  };
  
  sw_test(ProcessStartInfoUnitTest, Constructor)
  sw_test(ProcessStartInfoUnitTest, ConstructorWithFileName)
  sw_test(ProcessStartInfoUnitTest, ConstructorWithFileNameAndArgument)
  sw_test(ProcessStartInfoUnitTest, ConstructorByCopy)
  sw_test(ProcessStartInfoUnitTest, SetPasswordThenCheckPasswordInClearText)
  sw_test(ProcessStartInfoUnitTest, SetPasswordInClearTextThenCheckPasswordInClearText)
}
