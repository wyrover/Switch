/// @file
/// @brief Contains Switch::System::IO::DriveInfo class.
#pragma once

#include "../UnauthorizedAccessException.hpp"
#include "DirectoryInfo.hpp"
#include "DriveType.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief Provides instance methods for the creation, copying, deletion, moving, and
      /// opening of files, and aids in the creation of System::IO::FileStream objects.
      /// This class cannot be inherited.
      class _export DriveInfo final : public Object {
      public:
        /// @brief Provides access to information on drive.
        DriveInfo() { }

        /// @cond
        DriveInfo(const DriveInfo& driveInfo) : driveName(driveInfo.driveName) { }
        DriveInfo& operator =(const DriveInfo& driveInfo) {
          this->driveName = driveInfo.driveName;
          return *this;
        }
        /// @endcond

        /// @brief Provides access to information on the specified drive.
        /// @param driveName A valid drive path or drive letter. This can be either uppercase or lowercase, 'a' to 'z'. A null value is not valid.
        /// @exception ArgumentNullException driveName is null
        /// @exception ArgumentException The first letter of driveName is not an uppercase or lowercase letter from 'a' to 'z'.
        /// -or- driveName does not refer to a valid drive.
        DriveInfo(const String& driveName);

        /// @brief Indicates the amount of available free space on a drive.
        /// @return The amount of free space available on the drive, in bytes.
        /// @exception IO::IOException An I/O error occurred (for example, a disk error or a drive was not ready).
        property<int64, readonly> AvailableFreeSpace {
          _get {return this->GetAvailableFreeSpace();}
        };

        /// @brief Gets the name of the file system, such as NTFS or FAT32.
        /// @return The name of the file system on the specified drive.
        /// @exception IO::IOException An I/O error occurred (for example, a disk error or a drive was not ready).
        property<string, readonly> DriveFormat {
          _get {return this->GetDriveFormat();}
        };

        /// @brief Gets the drive type.
        /// @return One of the System::IO::DriveType values.
        /// @exception IO::IOException An I/O error occurred.
        property<System::IO::DriveType, readonly> DriveType {
          _get {return this->GetDriveType();}
        };

        /// @brief Gets a value indicating whether a drive is ready.
        /// @return true if the drive is ready; false if the drive is not ready.
        property<bool, readonly> IsReady {
          _get {return this->GetIsReady();}
        };

        /// @brief Gets the name of a drive.
        /// @return The name of the drive.
        property<String, readonly> Name {
          _get {return this->GetName();}
        };

        /// @brief Gets the root directory of a drive.
        /// @return A System::IO::DirectoryInfo object that contains the root directory of the drive.
        property<DirectoryInfo, readonly> RootDirectory {
          _get {return this->GetRootDirectory();}
        };

        /// @brief Gets the total amount of free space available on a drive.
        /// @return The total free space available on a drive, in bytes.
        /// @exception IO::IOException An I/O error occurred (for example, a disk error or a drive was not ready).
        property<int64, readonly> TotalFreeSpace {
          _get {return this->GetTotalFreeSpace();}
        };

        /// @brief Gets the total size of storage space on a drive.
        /// @return The total size of the drive, in bytes.
        /// @exception IO::IOException An I/O error occurred (for example, a disk error or a drive was not ready).
        property<int64, readonly> TotalSize {
          _get {return this->GetTotalSize();}
        };

        /// @brief Gets or sets the volume label of a drive.
        /// @param volumeLabel the volume label
        /// @return The volume label.
        /// @exception IO::IOException An I/O error occurred (for example, a disk error or a drive was not ready).
        /// @exception ArgumentNullException volumeLabel is null.
        /// @exception IO::IOException An I/O error occurred (for example, a disk error or a drive was not ready).
        /// @exception UnauthorizedAccessException The volume label is being set on a network or CD-ROM drive.
        property<string> VolumeLabel {
          _get {return this->GetVolumeLabel();},
          _set {this->SetVolumeLabel(value);}
        };

        /// @brief Retrieves the drive names of all logical drives on a computer.
        /// @return infos the array filled with the file info
        /// @exception IO::IOException An I/O error occurred (for example, a disk error or a drive was not ready).
        /// @exception UnauthorizedAccessException The caller does not have the required permission.
        static Array<DriveInfo> GetDrives();

        /// @brief Returns a drive name as a string.
        /// @return The name of the drive.
        virtual String ToString() const;

      protected:
        /// @cond
        int64 GetAvailableFreeSpace() const;
        string GetDriveFormat() const;
        System::IO::DriveType GetDriveType() const;
        bool GetIsReady() const;
        String GetName() const;
        DirectoryInfo GetRootDirectory() const;
        int64 GetTotalFreeSpace() const;
        int64 GetTotalSize() const;
        string GetVolumeLabel() const;
        void SetVolumeLabel(const String& volumeLabel);
        
        String driveName;
        /// @endcond
      };
    }
  }
}

using namespace Switch;
