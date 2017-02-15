#include "../../../Includes/Pcf/System/Version.h"

using namespace System;

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

int32 Version::GetHashCode() const {
  int32 hash = this->major ^ this->minor;
  if (this->build != -1)
    hash = hash ^ this->build;
  if (this->revision != -1)
    hash = hash ^ this->revision;
  return hash;
}

void Version::GetObjectData(System::Runtime::Serialization::SerializationInfo& info) const {
  info.AddValue("Major", this->major);
  info.AddValue("Minor", this->minor);
  info.AddValue("Build", this->build);
  info.AddValue("Revision", this->revision);
}
