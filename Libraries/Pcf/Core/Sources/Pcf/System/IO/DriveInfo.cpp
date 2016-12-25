#include <cstring>

#include "../../../../Includes/Pcf/System/UnauthorizedAccessException.h"
#include "../../../../Includes/Pcf/System/IO/DriveInfo.h"
#include "../../../../Includes/Pcf/System/IO/IOException.h"
#include "../../Os/Drive.h"

using namespace System;
using namespace System::IO;

DriveInfo::DriveInfo(const String& name) {
  if (String::IsNullOrEmpty(name))
    throw ArgumentNullException(pcf_current_information);
  this->driveName = name;
}

int64 DriveInfo::GetAvailableFreeSpace() const {
  int64 freeBytes = 0, dummy;
  if (!Os::Drive::GetAvailableFreeSpace(this->driveName.Data(), freeBytes, dummy, dummy))
    throw IOException(pcf_current_information);
  
  return freeBytes;
}

String DriveInfo::GetDriveFormat() const {
  string volumeName, fileSystemName;
  if (!Os::Drive::GetVolumeInformation(this->driveName, volumeName, fileSystemName))
    throw IOException(pcf_current_information);
  
  return fileSystemName;
}

System::IO::DriveType DriveInfo::GetDriveType() const {
  return (System::IO::DriveType)Os::Drive::GetDriveType(this->driveName);
}

bool DriveInfo::GetIsReady() const {
  string volumeName, fileSystemName;
  return Pcf::Os::Drive::GetVolumeInformation(this->driveName, volumeName, fileSystemName);
}

String DriveInfo::GetName() const {
  return this->driveName;
}

DirectoryInfo DriveInfo::GetRootDirectory() const {
  return DirectoryInfo(this->driveName);
}

int64 DriveInfo::GetTotalFreeSpace() const {
  int64 totalNumberOfFreeBytes = 0, dummy;
  if (!Os::Drive::GetAvailableFreeSpace(this->driveName.Data(), dummy, dummy, totalNumberOfFreeBytes))
    throw IOException(pcf_current_information);
  
  return totalNumberOfFreeBytes;
}

int64 DriveInfo::GetTotalSize() const {
  int64 totalNumberOfBytes = 0, dummy;
  if (!Os::Drive::GetAvailableFreeSpace(this->driveName.Data(), dummy, totalNumberOfBytes, dummy))
    throw IOException(pcf_current_information);
  
  return totalNumberOfBytes;
}

string DriveInfo::GetVolumeLabel() const {
  string volumeName, fileSystemName;
  if (!Os::Drive::GetVolumeInformation(this->driveName, volumeName, fileSystemName))
    throw IOException(pcf_current_information);
  return volumeName;
}

void DriveInfo::SetVolumeLabel(const String& label) {
  System::IO::DriveType drive = DriveType();
  if (drive == System::IO::DriveType::CDRom || drive == System::IO::DriveType::Network)
    throw UnauthorizedAccessException(pcf_current_information);

  if (!Os::Drive::SetVolumeLabel(this->driveName.Data(), label.Data()))
    throw IOException(pcf_current_information);
}

Array<DriveInfo> DriveInfo::GetDrives() {
  System::Collections::Generic::List<DriveInfo> drives;
  for (string drive : Os::Drive::GetDrives())
    drives.Add(DriveInfo(drive));
  return drives.ToArray();
}

String DriveInfo::ToString() const {
  return this->driveName;
}

