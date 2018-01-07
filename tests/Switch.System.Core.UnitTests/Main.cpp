#include <Switch/System/Environment.hpp>
#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
  System::Environment::SetCommandLineArgs(argv, argc);
  System::Exception::StackTraceEnabled = false;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
