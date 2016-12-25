#include "../../../Includes/Pcf/TUnit/ConsoleEventListener.h"
#include <Pcf/System/Console.h>
#include <Pcf/System/Environment.h>
#include <Pcf/System/String.h>

using namespace TUnit;
using namespace System;

namespace {
#if _WIN32
  static bool Isatty(FILE* file) { return _isatty(_fileno(file)) != 0; }
#else
  static bool Isatty(FILE* file) {return isatty(fileno(file));}
#endif
  
  static bool UseColor() {
    String gtestColor(testing::FLAGS_gtest_color);
    if (gtestColor.Equals("auto", true)) {
      if (System::Environment::OSVersion().Platform() == PlatformID::Win32NT || System::Environment::OSVersion().Platform() == PlatformID::Win32S || System::Environment::OSVersion().Platform() == PlatformID::Win32Windows || System::Environment::OSVersion().Platform() == PlatformID::WinCE)
        return Isatty(stdout);
      else {
        String term = System::Environment::GetEnvironmentVariable("TERM");
        return Isatty(stdout) && (term.Equals("xterm") || term.Equals("xterm-color") || term.Equals("xterm-256color") || term.Equals("screen") || term.Equals("screen-256color") || term.Equals("linux") || term.Equals("cygwin"));
      }
    }
    
    return gtestColor.Equals("yes", true) || gtestColor.Equals("true", true) || gtestColor.Equals(gtestColor, "t", true) || gtestColor.Equals("1");
  }
}

ConsoleEventListener::ConsoleEventListener() {
}

void ConsoleEventListener::OnTestProgramStart(const testing::UnitTest& unitTest) {
}

void ConsoleEventListener::OnTestIterationStart(const testing::UnitTest& unitTest, int iteration) {
  if (testing::FLAGS_gtest_repeat != 1)
    WriteLine(String::Format("{1}Repeating all tests (iteration {0}) . . .{1}", iteration + 1, System::Environment::NewLine));
  
  if (!String(testing::FLAGS_gtest_filter).Equals("*"))
    WriteLine(ConsoleColor::DarkMagenta, String::Format("Note: TUnit filter = {0}", testing::FLAGS_gtest_filter.c_str()));

  if (testing::FLAGS_gtest_shuffle)
    WriteLine(ConsoleColor::DarkMagenta, String::Format("Note: Randomizing tests' orders with a seed of {0}.", unitTest.random_seed()));

  WriteLine(String::Format("Start {0} {1} from {2} {3}", unitTest.test_to_run_count(), unitTest.test_to_run_count() == 1 ? "test" : "tests", unitTest.test_case_to_run_count(), unitTest.test_case_to_run_count() == 1 ? "test case" : "test cases"));
}

void ConsoleEventListener::OnEnvironmentsSetUpStart(const testing::UnitTest& unitTest) {
}

void ConsoleEventListener::OnEnvironmentsSetUpEnd(const testing::UnitTest& unitTest) {
}

void ConsoleEventListener::OnTestCaseStart(const testing::TestCase& testCase) {
  Write(String::Format("  Start {0} {1} from {2}", testCase.test_to_run_count(), testCase.test_to_run_count() == 1 ? "test" : "tests", testCase.name()));
  if (testCase.type_param() == null)
    WriteLine();
  else
    WriteLine(String::Format(", where TypeParam = {0}", testCase.type_param()));
}

void ConsoleEventListener::OnTestStart(const testing::TestInfo& testInfo) {
}

void ConsoleEventListener::OnTestPartResult(const testing::TestPartResult& testPartResult) {
  switch(testPartResult.type()) {
    case testing::TestPartResult::kSuccess: return;
    case testing::TestPartResult::kFatalFailure:
    case testing::TestPartResult::kNonFatalFailure:
      WriteLine(testPartResult.message());
      if (testPartResult.line_number() > 0)
        WriteLine(ConsoleColor::DarkMagenta, String::Format("error: {0}:{1} ", testPartResult.file_name() == null ? "unknown file" : testPartResult.file_name(), testPartResult.line_number()));
      break;
    default: WriteLine("Unknown result type");
  }
}

void ConsoleEventListener::OnTestEnd(const testing::TestInfo& testInfo) {
  if (testInfo.result()->Passed()) {
    Write(ConsoleColor::DarkGreen, "    PASSED ");
  } else {
    Write(ConsoleColor::DarkRed,   "*** FAILED ");
  }
  Write(String::Format("{0}.{1}", testInfo.test_case_name(), testInfo.name()));
  if (testInfo.result()->Failed()) {
    const char* const type_param = testInfo.type_param();
    const char* const value_param = testInfo.value_param();
    
    if (type_param != null || value_param != null) {
      Write(", where ");
      if (type_param != null)
        Write(String::Format("TypeParam = {0}", type_param));
      if (type_param != null && value_param != null)
        Write(" and ");
      if (value_param != null)
        Write(String::Format("GetParam() = {0}", value_param));
    }
  }
  if (testing::FLAGS_gtest_print_time)
    Write(String::Format(" ({0} ms)", (int64)testInfo.result()->elapsed_time()));
  WriteLine();
}

void ConsoleEventListener::OnTestCaseEnd(const testing::TestCase& testCase) {
  Write(String::Format("  End {0} {1} from {2}", testCase.test_to_run_count(), testCase.test_to_run_count() == 1 ? "test" : "tests", testCase.name()));
  if (testing::FLAGS_gtest_print_time)
    Write(String::Format(" ({0} ms total)", (int64)testCase.elapsed_time()));
  WriteLine();
  WriteLine();
}

void ConsoleEventListener::OnEnvironmentsTearDownStart(const testing::UnitTest& unitTest) {
}

void ConsoleEventListener::OnEnvironmentsTearDownEnd(const testing::UnitTest& unitTest) {
}

void ConsoleEventListener::OnTestIterationEnd(const testing::UnitTest& unitTest, int iteration) {
  WriteLine("  Summary :");
  Write(ConsoleColor::DarkGreen, "    PASSED ");
  WriteLine(String::Format("{0} {1}.", unitTest.successful_test_count(), unitTest.successful_test_count() == 1 ? "test" : "tests"));
  
  int numFailures = unitTest.failed_test_count();
  if (!unitTest.Passed()) {
    const int failedTestCount = unitTest.failed_test_count();
    Write(ConsoleColor::DarkRed, "*** FAILED ");
    WriteLine(String::Format("{0} {1}, listed below:", failedTestCount,  failedTestCount == 1 ? "test" : "tests"));
    
    if (numFailures > 0) {
      for (int i = 0; i < unitTest.total_test_case_count(); ++i) {
        const testing::TestCase& testCase = *unitTest.GetTestCase(i);
        
        if (!testCase.should_run() || (testCase.failed_test_count() == 0))
          continue;
        
        for (int j = 0; j < testCase.total_test_count(); ++j) {
          const testing::TestInfo& testInfo = *testCase.GetTestInfo(j);
          
          if (!testInfo.should_run() || testInfo.result()->Passed())
            continue;
          
          Write(ConsoleColor::DarkRed, "*** FAILED ");
          Write(String::Format("{0}.{1}", testCase.name(), testInfo.name()));
          
          const char* const typeParam = testInfo.type_param();
          const char* const valueParam = testInfo.value_param();
          if (typeParam != null || valueParam != null) {
            Write(", where ");
            if (typeParam != null) {
              Write(String::Format("TypeParam = {0}", typeParam));
              if (valueParam != null)
                Write(" and ");
            }
            if (valueParam != null)
              Write(String::Format("GetParam() = {0}", valueParam));
          }
          WriteLine();
        }
      }
    }
    WriteLine();
    WriteLine(String::Format("{0} FAILED {1}", numFailures, numFailures == 1 ? "TEST" : "TESTS"));
  }
  Write(String::Format("End {0} {1} from {2} {3} ran.", unitTest.test_to_run_count(), unitTest.test_to_run_count() == 1 ? "test" : "tests", unitTest.test_case_to_run_count(), unitTest.test_case_to_run_count() == 1 ? "test case" : "test cases"));
  if (testing::FLAGS_gtest_print_time)
    Write(String::Format(" ({0} ms total)", (int64)unitTest.elapsed_time()));
  WriteLine();
  WriteLine();
  
  int numIgnored = unitTest.reportable_disabled_test_count();
  if (numIgnored && !testing::FLAGS_gtest_also_run_disabled_tests) {
    if (numIgnored == 1)
      WriteLine(ConsoleColor::DarkMagenta, "You have 1 ignored test");
    else
      WriteLine(ConsoleColor::DarkMagenta, String::Format("You have {0} ignored tests", numIgnored));
    WriteLine();
  }
}

void ConsoleEventListener::OnTestProgramEnd(const testing::UnitTest& unitTest) {
}

testing::TestEventListeners& ConsoleEventListener::ReplaceDefaultGTestListener() {
  testing::TestEventListeners& listeners = AddToGTestListener();
  delete listeners.Release(listeners.default_result_printer());
  return listeners;
}

testing::TestEventListeners& ConsoleEventListener::AddToGTestListener() {
  testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();
  listeners.Append(new ConsoleEventListener());
  return listeners;
}

void ConsoleEventListener::ShowHelp() {
  WriteLine("This program contains tests written using TUnit. You can use the");
  WriteLine("following command line flags to control its behavior:");
  WriteLine();
  WriteLine("Test Selection:");
  WriteLine(System::ConsoleColor::DarkMagenta, "  --tunit_list_tests");
  WriteLine("      List the names of all tests instead of running them.");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_filter=");
  Write(System::ConsoleColor::DarkCyan, "POSTIVE_PATTERNS[");
  Write(System::ConsoleColor::DarkMagenta, "-");
  WriteLine(System::ConsoleColor::DarkCyan, "NAGATIVE_PATTERNS]");
  WriteLine("      Run only the tests whose name matches one of the positive patterns but");
  WriteLine("      none of the negative patterns. '?' matches any single character; '*'");
  WriteLine("      matches any substring; ':' separates two patterns.");
  WriteLine(System::ConsoleColor::DarkMagenta, "  --tunit_also_run_ignored_tests");
  WriteLine("      Run all ignored tests too.");
  WriteLine();
  WriteLine("Test Execution:");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_repeat=");
  WriteLine(System::ConsoleColor::DarkCyan, "[COUNT]");
  WriteLine("      Run the tests repeatedly; use a negative count to repeat forever.");
  WriteLine(System::ConsoleColor::DarkMagenta, "  --tunit_shuffle");
  WriteLine("      Randomize tests' orders on every iteration.");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_random_seed=");
  WriteLine(System::ConsoleColor::DarkCyan, "[NUMBER]");
  WriteLine("      Random number seed to use for shuffling test orders (between 1 and");
  WriteLine("      99999, or 0 to use a seed based on the current time).");
  WriteLine();
  WriteLine("Test Output:");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_color=");
  Write(System::ConsoleColor::DarkCyan, "(");
  Write(System::ConsoleColor::DarkMagenta, "yes");
  Write(System::ConsoleColor::DarkCyan, "|");
  Write(System::ConsoleColor::DarkMagenta, "no");
  Write(System::ConsoleColor::DarkCyan, "|");
  Write(System::ConsoleColor::DarkMagenta, "auto");
  WriteLine(System::ConsoleColor::DarkCyan, ")");
  Write("      Enable/disable colored output. The default is ");
  Write(System::ConsoleColor::DarkMagenta, "auto");
  WriteLine(".");
  WriteLine(System::ConsoleColor::DarkMagenta, "  --tunit_print_time=0");
  WriteLine("      Don't print the elapsed time of each test.");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_output=xml");
  Write(System::ConsoleColor::DarkCyan, "[");
  Write(System::ConsoleColor::DarkMagenta, ":");
  Write(System::ConsoleColor::DarkCyan, "DIRECTORY_PATH");
  Write(System::ConsoleColor::DarkMagenta, "/");
  Write(System::ConsoleColor::DarkCyan, "|");
  Write(System::ConsoleColor::DarkMagenta, ":");
  WriteLine(System::ConsoleColor::DarkCyan, "FILE_PATH]");
  WriteLine("      Generate an XML report in the given directory or with the given file");
  Write("      name. ");
  Write(System::ConsoleColor::DarkCyan, "FILE_PATH");
  Write(" defaults to ");
  Write(System::ConsoleColor::DarkMagenta, "test_details.xml");
  WriteLine(".");
  WriteLine();
  WriteLine("Assertion Behavior:");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_death_test_style=");
  Write(System::ConsoleColor::DarkCyan, "(");
  Write(System::ConsoleColor::DarkMagenta, "fast");
  Write(System::ConsoleColor::DarkCyan, "|");
  Write(System::ConsoleColor::DarkMagenta, "threadsafe");
  WriteLine(System::ConsoleColor::DarkCyan, ")");
  WriteLine("      Set the default death test style.");
  WriteLine(System::ConsoleColor::DarkMagenta, "  --tunit_break_on_failure");
  WriteLine("      Turn assertion failures into debugger break-points.");
  WriteLine(System::ConsoleColor::DarkMagenta, "  --tunit_throw_on_failure");
  WriteLine("      Turn assertion failures into C++ exceptions.");
  WriteLine(System::ConsoleColor::DarkMagenta, "  --tunit_catch_exceptions=0");
  WriteLine("      Do not report exceptions as test failures. Instead, allow them");
  WriteLine("      to crash the program or throw a pop-up (on Windows).");
  WriteLine();
  WriteLine("Misc:");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_help");
  Write(System::ConsoleColor::DarkCyan, "|");
  WriteLine(System::ConsoleColor::DarkMagenta, "--help");
  WriteLine("      Show this TUnit help page.");
  Write(System::ConsoleColor::DarkMagenta, "  --tunit_version");
  Write(System::ConsoleColor::DarkCyan, "|");
  WriteLine(System::ConsoleColor::DarkMagenta, "--version");
  WriteLine("      Show TUnit version.");
  WriteLine();
}

void ConsoleEventListener::ShowVersion() {
  WriteLine("TUnit version 0.1.0");
  WriteLine();
}

void ConsoleEventListener::Write(ConsoleColor color, const String& value) {
  static bool useColor = UseColor();
  if (!useColor) {
    Console::Write(value);
    return;
  }
  
  static System::ConsoleColor originalForegroundColor = Console::ForegroundColor;
  Console::ForegroundColor = color;
  Console::Write(value);
  Console::ForegroundColor = originalForegroundColor;
}

void ConsoleEventListener::WriteLine(ConsoleColor color, const String& value) {
  Write(color, String::Format("{0}{1}", value, System::Environment::NewLine));
}

void ConsoleEventListener::Write(const String& value) {
  Console::Write(value);
}

void ConsoleEventListener::WriteLine(const String& value) {
  Console::WriteLine(value);
}

void ConsoleEventListener::WriteLine() {
  Console::WriteLine();
}
