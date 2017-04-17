#if defined(_WIN32)

#include <windows.h>
#include "../../Includes/Pcf/Undef.h"

#include "CoreApi.h"
#include "../../Includes/Pcf/System/Collections/Generic/List.h"

bool __OS::CoreApi::Drive::GetAvailableFreeSpace(const string& rootPathName, int64& freeBytes, int64& totalNumberOfBytes, int64& totalNumberOfFreeBytes) {
  bool retValue = false;
  WCHAR rootPathNameName[MAX_PATH];
  if (rootPathName.Length()+1 <= MAX_PATH) {
    ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, rootPathName.Data(), -1, rootPathNameName, sizeof(rootPathNameName)/sizeof(rootPathNameName[0]));
    retValue = ::GetDiskFreeSpaceExW(rootPathNameName, (PULARGE_INTEGER)&freeBytes, (PULARGE_INTEGER)&totalNumberOfBytes, (PULARGE_INTEGER)&totalNumberOfFreeBytes) != FALSE;
  }
  return retValue;
}

System::IO::DriveType __OS::CoreApi::Drive::GetDriveType(const string& rootPathName) {
  return (System::IO::DriveType)::GetDriveTypeA(rootPathName.Data());
}

System::Array<string> __OS::CoreApi::Drive::GetDrives() {
  char buffer[MAX_PATH];
  int32 bufferLenght = MAX_PATH;
  if (::GetLogicalDriveStringsA(bufferLenght, buffer) <= 0)
    return {};
  System::Collections::Generic::List<string> drives;
  for(const char* drive = buffer; drive[0] != 0; drive += strlen(drive) + 1)
    drives.Add(drive);
  return drives.ToArray();
}

bool __OS::CoreApi::Drive::GetVolumeInformation(const string& rootPathName, string& volumeName, string& fileSystemName) {
  DWORD fileSystemFlags = 0;
  char volume[MAX_PATH];
  char fileSystem[MAX_PATH];
  if (::GetVolumeInformationA(rootPathName.Data(), volume, MAX_PATH, null, null, &fileSystemFlags, fileSystem, MAX_PATH) == FALSE)
    return false;
  
  volumeName = volume;
  fileSystemName = fileSystem;
  
  return true;
}

bool __OS::CoreApi::Drive::SetVolumeLabel(const string& rootPathName, const string& volumeName) {
  return ::SetVolumeLabelA(rootPathName.Data(), volumeName.Data()) > 0;
}

#endif