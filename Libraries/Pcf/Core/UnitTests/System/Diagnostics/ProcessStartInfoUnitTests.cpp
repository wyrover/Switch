#include <Pcf/System/Diagnostics/ProcessStartInfo.h>
#include <Pcf/System/Console.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Diagnostics;
using namespace TUnit;

namespace UnitTests {
  class ProcessStartInfoUnitTest : public TUnit::TestFixture {
  protected:
    void Constructor() {
      ProcessStartInfo psi;
      Assert::IsEmpty(psi.Arguments, pcf_current_information);
      Assert::IsFalse(psi.CreateNoWindow, pcf_current_information);
      Assert::IsEmpty(psi.Domain, pcf_current_information);
      Assert::IsNotEmpty(psi.EnvironmentVariables(), pcf_current_information);
      Assert::IsFalse(psi.ErrorDialog, pcf_current_information);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), pcf_current_information);
      Assert::IsEmpty(psi.FileName, pcf_current_information);
      Assert::IsFalse(psi.LoadUserProfile, pcf_current_information);
      Assert::IsEmpty(psi.PasswordInClearText, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardError, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardInput, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, pcf_current_information);
    }
    
    void ConstructorWithFileName() {
      ProcessStartInfo psi("FileName");
      Assert::IsEmpty(psi.Arguments, pcf_current_information);
      Assert::IsFalse(psi.CreateNoWindow, pcf_current_information);
      Assert::IsEmpty(psi.Domain, pcf_current_information);
      Assert::IsNotEmpty(psi.EnvironmentVariables(), pcf_current_information);
      Assert::IsFalse(psi.ErrorDialog, pcf_current_information);
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), pcf_current_information);
      Assert::AreEqual("FileName", psi.FileName, pcf_current_information);
      Assert::IsFalse(psi.LoadUserProfile, pcf_current_information);
      Assert::IsEmpty(psi.PasswordInClearText, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardError, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardInput, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, pcf_current_information);
    }
    
    void ConstructorWithFileNameAndArgument() {
      ProcessStartInfo psi("FileName", "Arguments");
      Assert::AreEqual("Arguments", psi.Arguments, pcf_current_information);
      Assert::IsFalse(psi.CreateNoWindow, pcf_current_information);
      Assert::IsEmpty(psi.Domain, pcf_current_information);
      Assert::IsNotEmpty(psi.EnvironmentVariables(), pcf_current_information);
      Assert::IsFalse(psi.ErrorDialog), pcf_current_information;
      Assert::AreEqual(0, psi.ErrorDialogParamHandle(), pcf_current_information);
      Assert::AreEqual("FileName", psi.FileName, pcf_current_information);
      Assert::IsFalse(psi.LoadUserProfile, pcf_current_information);
      Assert::IsEmpty(psi.PasswordInClearText, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardError, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardInput, pcf_current_information);
      Assert::IsFalse(psi.RedirectStandardOutput, pcf_current_information);
    }
    
    void ConstructorByCopy() {
      ProcessStartInfo psiOriginal("FileName", "Arguments");
      ProcessStartInfo psi = psiOriginal;
      Assert::AreEqual(psiOriginal.Arguments, psi.Arguments, pcf_current_information);
      Assert::AreEqual(psiOriginal.CreateNoWindow, psi.CreateNoWindow, pcf_current_information);
      Assert::AreEqual(psiOriginal.Domain, psi.Domain, pcf_current_information);
      Assert::AreEqual(psiOriginal.EnvironmentVariables, psi.EnvironmentVariables, pcf_current_information);
      Assert::AreEqual(psiOriginal.ErrorDialog, psi.ErrorDialog, pcf_current_information);
      Assert::AreEqual(psiOriginal.ErrorDialogParamHandle, psi.ErrorDialogParamHandle, pcf_current_information);
      Assert::AreEqual(psiOriginal.FileName, psi.FileName, pcf_current_information);
    }
    
    void SetPasswordThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      char32 password[] = {'M', 'y', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd'};
      psi.Pasword = System::Security::SecureString(password, 11);
      Assert::AreEqual("My password", psi.PasswordInClearText, pcf_current_information);
    }
    
    void SetPasswordInClearTextThenCheckPasswordInClearText() {
      ProcessStartInfo psi;
      psi.PasswordInClearText = "My password";
      Assert::AreEqual("My password", psi.PasswordInClearText, pcf_current_information);
    }
  };
  
  pcf_test(ProcessStartInfoUnitTest, Constructor);
  pcf_test(ProcessStartInfoUnitTest, ConstructorWithFileName);
  pcf_test(ProcessStartInfoUnitTest, ConstructorWithFileNameAndArgument);
  pcf_test(ProcessStartInfoUnitTest, ConstructorByCopy);
  pcf_test(ProcessStartInfoUnitTest, SetPasswordThenCheckPasswordInClearText);
  pcf_test(ProcessStartInfoUnitTest, SetPasswordInClearTextThenCheckPasswordInClearText);
}
