#include "../../../Includes/Pcf/System/Version.h"
#include "../../../Includes/Pcf/System/Array.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/String.h"
#include "../../../Includes/Pcf/System/StringSplitOptions.h"
#include "../../../Includes/Pcf/System/SystemException.h"

using namespace System;

Version::Version() {}

Version::Version(int32 major, int32 minor) : major(major), minor(minor) {
  if (major < 0 || minor < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
}

Version::Version(int32 major, int32 minor, int32 build) : major(major), minor(minor), build(build) {
  if (major < 0 || minor < 0 || build < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
}

Version::Version(int32 major, int32 minor, int32 build, int32 revision) : major(major), minor(minor), build(build), revision(revision) {
  if (major < 0 || minor < 0 || build < 0 || revision < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
}

up<object> Version::Clone() const {
  return new Version(*this);
}

int32 Version::CompareTo(const IComparable& obj) const {
  if (!is<Version>(obj))
    return 1;

  return CompareTo((const Version &)obj);
}

int32 Version::CompareTo(const Version& value) const {
  int32 localCmpBits = 0;
  int32 otherCmpBits = 0;
  
  if (this->major < value.major)
    otherCmpBits += 1<<3;
  else if (this->major > value.major)
    localCmpBits += 1<<3;
  
  if (this->minor < value.minor)
    otherCmpBits += 1<<2;
  else if (this->minor > value.minor)
    localCmpBits += 1<<2;
  
  if (this->build < value.build)
    otherCmpBits += 1<<1;
  else if (this->build > value.build)
    localCmpBits += 1<<1;
  
  if (this->revision < value.revision)
    otherCmpBits += 1<<0;
  else if (this->revision > value.revision)
    localCmpBits += 1<<0;
  
  return localCmpBits - otherCmpBits;
}

bool Version::Equals(const Version& value) const {
  return CompareTo(value) == 0;
}

bool Version::Equals(const object& obj) const {
  if (!is<Version>(obj))
    return false;
  return Equals((const Version&)obj);
}

int32 Version::GetHashCode() const {
  int32 hash = this->major;
  hash = hash ^ this->minor;
  if (this->build != -1)
    hash = hash ^ this->build;
  if (this->revision != -1)
    hash = hash ^ this->revision;

  return hash;
}

System::Version Version::Parse(const String& str) {
  Array<String> versions = str.Split('.', StringSplitOptions(StringSplitOptions::RemoveEmptyEntries));
  Version retVal;

  retVal.major = versions.Length > 0 ? Convert::ToInt32(versions[0]) : -1;
  retVal.minor = versions.Length > 1 ? Convert::ToInt32(versions[1]) : -1;
  retVal.build = versions.Length > 2 ? Convert::ToInt32(versions[2]) : -1;
  retVal.revision = versions.Length > 3 ? Convert::ToInt32(versions[3]) : -1;

  return retVal;
}

string Version::ToString() const {
  string retValue = string::Format("{0}.{1}", this->major, this->minor);

  if (this->build != -1)
    retValue += string::Format(".{0}", this->build);

  if (this->revision != -1)
    retValue += string::Format(".{0}", this->revision);

  return retValue;
}

void Version::GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const {
  info.AddValue("Major", this->major);
  info.AddValue("Minor", this->minor);
  info.AddValue("Build", this->build);
  info.AddValue("Revision", this->revision);
}
