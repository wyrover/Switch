#include "Api.hpp"

System::Version Native::EnvironmentApi::GetVersion() {
  return System::Version::Parse("0.5.0");
}
