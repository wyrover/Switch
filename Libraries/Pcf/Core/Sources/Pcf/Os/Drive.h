#pragma once

#include "../../../Includes/Pcf/Types.h"
#include "../../../Includes/Pcf/System/Array.h"
#include "../../../Includes/Pcf/System/String.h"
#include "../../../Includes/Pcf/System/IO/DriveType.h"

/// @cond
namespace Pcf {
  namespace Os {
    /// @brief Represents a Os object that provides the access drive API.
    /// This class cannot be inherited.
    /// Internal used only.
    class Drive final {
    public:
      /// @brief Retrieves the amount of free space on the disk in bytes
      /// Internal used only.
      /// @param rootPathName The root directory of the disk for which information is to be returned. If this parameter is null, the function uses the root of the current disk.
      /// @param freeBytes A pointer to a variable that receives the total number of free bytes on a disk that are available to the user who is associated with the calling thread. This parameter can be null.
      /// @param totalNumberOfBytes A pointer to a variable that receives the total number of bytes on a disk that are available to the user who is associated with the calling thread. This parameter can be null.
      /// @param totalNumberOfFreeBytes A pointer to a variable that receives the total number of free bytes on a disk. This parameter can be null.
      /// @return true it the function succeeded.
      static bool GetAvailableFreeSpace(const string& rootPathName, int64& freeBytes, int64& totalNumberOfBytes, int64& totalNumberOfFreeBytes);

      #undef GetDriveType
      /// @brief Retrieves the amount of free space on the disk in bytes
      /// Internal used only.
      /// @param rootPathName Pointer to a null-terminated string that specifies the root directory of the disk to return information about. A trailing backslash is required.
      /// @return The return value specifies the type of drive.
      static System::IO::DriveType GetDriveType(const string& rootPathName);

      #undef GetLogicalDriveStrings
      /// @brief Retrieves the drive names of all logical drives on a computer.
      /// Internal used only.
      /// @return infos the array filled with the file info
      static System::Array<string> GetDrives();

      #undef GetVolumeInformation
      /// @brief Retrieves information about the file system and volume associated with the specified root directory.
      /// Internal used only.
      /// @param rootPathName Pointer to a null-terminated string that specifies the root directory of the disk to return information about. A trailing backslash is required.
      /// @param volumeName A pointer to a buffer that receives the name of a specified volume.
      /// @param fileSystemName A pointer to a buffer that receives the name of the file system, for example, the FAT file system or the NTFS file system.
      /// @return If all the requested information is retrieved, the return value is nonzero.
      /// @return If not all the requested information is retrieved, the return value is zero (0).
      static bool GetVolumeInformation(const string& rootPathName, string& volumeName, string& fileSystemName);
      
      #undef SetVolumeLabel
      /// @brief Sets the label of a file system volume.
      /// Internal used only.
      /// @param rootPathName The root directory of a file system volume. This is the volume the function will label. A trailing backslash is required.
      /// @return If the function succeeds, the return value is nonzero.
      /// @return If the function fails, the return value is zero.
      static bool SetVolumeLabel(const string& rootPathName, const string& volumeName);

      private :
      Drive() = delete;
    };
  }
}

using namespace Pcf;
/// @endcond
