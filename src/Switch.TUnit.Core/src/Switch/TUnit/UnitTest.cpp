#include <Switch/TUnit/UnitTest.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/System/Environment.hpp>
#include <Switch/System/String.hpp>
#include <Switch/Startup.hpp>
#include <gtest/gtest.h>
#include "ConsoleEventListener.hpp"

using namespace TUnit;

UnitTest::UnitTest(const System::Array<System::String>& args) {
  this->args = ConvertParam(args);

  int32 argc = args.Length;
  char* argv[128] = {0};
  for (int i = 0; i < argc; i++)
    argv[i + 1] = (char*)this->args[i].Data();
  testing::InitGoogleTest(&++argc, argv);
  TUnit::ConsoleEventListener::ReplaceDefaultGTestListener();

  if (this->args.Contains("--tunit_help")) {
    TUnit::ConsoleEventListener::ShowHelp();
    System::Environment::Exit(0);
  }

  if (this->args.Contains("--tunit_version")) {
    TUnit::ConsoleEventListener::ShowVersion();
    System::Environment::Exit(0);
  }
}

int32 UnitTest::Run() {
  System::Exception::StackTraceEnabled = false;
  int32 result = RUN_ALL_TESTS();
  if (this->args.Contains("--tunit_pause")) {
    System::Console::WriteLine("Press any key...");
    System::Console::ReadKey(true);
  }
  return result;
}

System::Array<System::String> UnitTest::ConvertParam(const System::Array<System::String>& args) {
  System::Array<System::String> convertedArgs(args.Length);
  for (int32 index = 0; index < args.Length; ++index) {
    if (args[index].Equals("--help"))
      convertedArgs[index] = "--tunit_help";
    else if (args[index].Equals("--tunit_help"))
      convertedArgs[index] = args[index];
    else if (args[index].Equals("--version"))
      convertedArgs[index] = "--tunit_version";
    else if (args[index].Equals("--tunit_version"))
      convertedArgs[index] = args[index];
    else if (args[index].Equals("--tunit_list_tests"))
      convertedArgs[index] = args[index].Replace("--tunit_list_tests", "--gtest_list_tests");
    else if (args[index].StartsWith("--tunit_filter"))
      convertedArgs[index] = args[index].Replace("--tunit_filter", "--gtest_filter");
    else if (args[index].Equals("--tunit_also_run_ignored_tests"))
      convertedArgs[index] = args[index].Replace("--tunit_also_run_ignored_tests", "--gtest_also_run_disabled_tests");
    else if (args[index].StartsWith("--tunit_repeat"))
      convertedArgs[index] = args[index].Replace("--tunit_repeat", "--gtest_repeat");
    else if (args[index].Equals("--tunit_shuffle"))
      convertedArgs[index] = args[index].Replace("--tunit_shuffle", "--gtest_shuffle");
    else if (args[index].StartsWith("--tunit_random_seed"))
      convertedArgs[index] = args[index].Replace("--tunit_random_seed", "--gtest_random_seed");
    else if (args[index].StartsWith("--tunit_color"))
      convertedArgs[index] = args[index].Replace("--tunit_color", "--gtest_color");
    else if (args[index].StartsWith("--tunit_print_time"))
      convertedArgs[index] = args[index].Replace("--tunit_print_time", "--gtest_print_time");
    else if (args[index].StartsWith("--tunit_output"))
      convertedArgs[index] = args[index].Replace("--tunit_output", "--gtest_output");
    else if (args[index].StartsWith("--tunit_death_test_style"))
      convertedArgs[index] = args[index].Replace("--tunit_death_test_style", "--gtest_death_test_style");
    else if (args[index].Equals("--tunit_break_on_failure"))
      convertedArgs[index] = args[index].Replace("--tunit_break_on_failure", "--gtest_break_on_failure");
    else if (args[index].Equals("--tunit_throw_on_failure"))
      convertedArgs[index] = args[index].Replace("--tunit_throw_on_failure", "--gtest_throw_on_failure");
    else if (args[index].StartsWith("--tunit_catch_exceptions"))
      convertedArgs[index] = args[index].Replace("--tunit_catch_exceptions", "--gtest_catch_exceptions");
    else if (args[index].StartsWith("--tunit_pause"))
      convertedArgs[index] = args[index];
    else if (args[index].StartsWith("--gtest_"))
      convertedArgs[index] = args[index];
    else if (args[index].StartsWith("--tunit_"))
      convertedArgs[index] = "--tunit_help";
  }

  return convertedArgs;
}
