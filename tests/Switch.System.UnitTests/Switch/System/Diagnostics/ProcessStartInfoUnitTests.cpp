#include <Switch/System/Diagnostics/ProcessStartInfo.hpp>
#include <Switch/System/Console.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Diagnostics;

namespace UnitTests {
  TEST(ProcessStartInfoUnitTest, Constructor) {
    ProcessStartInfo psi;
    ASSERT_EQ(string::Empty, psi.Arguments);
    ASSERT_FALSE(psi.CreateNoWindow);
    ASSERT_EQ(string::Empty, psi.Domain);
    ASSERT_EQ(0, psi.EnvironmentVariables().Count);
    ASSERT_FALSE(psi.ErrorDialog);
    ASSERT_EQ(0, psi.ErrorDialogParamHandle());
    ASSERT_EQ(string::Empty, psi.FileName);
    ASSERT_FALSE(psi.LoadUserProfile);
    ASSERT_EQ(string::Empty, psi.PasswordInClearText);
    ASSERT_FALSE(psi.RedirectStandardError);
    ASSERT_FALSE(psi.RedirectStandardInput);
    ASSERT_FALSE(psi.RedirectStandardOutput);
  }
  
  TEST(ProcessStartInfoUnitTest, ConstructorWithFileName) {
    ProcessStartInfo psi("FileName");
    ASSERT_EQ(string::Empty, psi.Arguments);
    ASSERT_FALSE(psi.CreateNoWindow);
    ASSERT_EQ(string::Empty, psi.Domain);
    ASSERT_EQ(0, psi.EnvironmentVariables().Count);
    ASSERT_FALSE(psi.ErrorDialog);
    ASSERT_EQ(0, psi.ErrorDialogParamHandle());
    ASSERT_EQ("FileName", psi.FileName);
    ASSERT_FALSE(psi.LoadUserProfile);
    ASSERT_EQ(string::Empty, psi.PasswordInClearText);
    ASSERT_FALSE(psi.RedirectStandardError);
    ASSERT_FALSE(psi.RedirectStandardInput);
    ASSERT_FALSE(psi.RedirectStandardOutput);
  }
  
  TEST(ProcessStartInfoUnitTest, ConstructorWithFileNameAndArgument) {
    ProcessStartInfo psi("FileName", "Arguments");
    ASSERT_EQ("Arguments", psi.Arguments);
    ASSERT_FALSE(psi.CreateNoWindow);
    ASSERT_EQ(string::Empty, psi.Domain);
    ASSERT_EQ(0, psi.EnvironmentVariables().Count);
    ASSERT_FALSE(psi.ErrorDialog);
    ASSERT_EQ(0, psi.ErrorDialogParamHandle());
    ASSERT_EQ("FileName", psi.FileName);
    ASSERT_FALSE(psi.LoadUserProfile);
    ASSERT_EQ(string::Empty, psi.PasswordInClearText);
    ASSERT_FALSE(psi.RedirectStandardError);
    ASSERT_FALSE(psi.RedirectStandardInput);
    ASSERT_FALSE(psi.RedirectStandardOutput);
  }
  
  TEST(ProcessStartInfoUnitTest, ConstructorByCopy) {
    ProcessStartInfo psiOriginal("FileName", "Arguments");
    ProcessStartInfo psi = psiOriginal;
    ASSERT_EQ(psiOriginal.Arguments, psi.Arguments);
    ASSERT_EQ(psiOriginal.CreateNoWindow, psi.CreateNoWindow);
    ASSERT_EQ(psiOriginal.Domain, psi.Domain);
    ASSERT_EQ(psiOriginal.EnvironmentVariables, psi.EnvironmentVariables);
    ASSERT_EQ(psiOriginal.ErrorDialog, psi.ErrorDialog);
    ASSERT_EQ(psiOriginal.ErrorDialogParamHandle, psi.ErrorDialogParamHandle);
    ASSERT_EQ(psiOriginal.FileName, psi.FileName);
  }
  
  TEST(ProcessStartInfoUnitTest, SetPasswordThenCheckPasswordInClearText) {
    ProcessStartInfo psi;
    char32 password[] = {'M', 'y', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd'};
    psi.Pasword = System::Security::SecureString(password, 11);
    ASSERT_EQ("My password", psi.PasswordInClearText);
  }
  
  TEST(ProcessStartInfoUnitTest, SetPasswordInClearTextThenCheckPasswordInClearText) {
    ProcessStartInfo psi;
    psi.PasswordInClearText = "My password";
    ASSERT_EQ("My password", psi.PasswordInClearText);
  }
}

