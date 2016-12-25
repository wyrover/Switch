#include <Pcf/System/IO/DriveInfo.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::IO;
using namespace System::Threading;
using namespace TUnit;

TEST(Drive, GetName) {
  Array<DriveInfo> drives = DriveInfo::GetDrives();
  EXPECT_TRUE(drives.Length > 0);
  for (int32 k = 0; k < drives.Length; k++) {
    EXPECT_TRUE(drives[k].DriveType != DriveType::Unknown);
    if (drives[k].DriveType == DriveType::CDRom) {
      EXPECT_FALSE(drives[k].IsReady);
      EXPECT_THROW(drives[k].VolumeLabel = "NewDriveLabel", UnauthorizedAccessException);
    } else if (drives[k].DriveType == DriveType::Removable) {
      //Removable drive can be ready, bad test
      //EXPECT_FALSE(isReady);
    } else {
      EXPECT_TRUE(drives[k].IsReady);
      string volumeLabel = drives[k].VolumeLabel;
      if (drives[k].DriveType == DriveType::Network) {
        EXPECT_THROW(drives[k].VolumeLabel = "NewDriveLabel", UnauthorizedAccessException);
      } else if (drives[k].DriveType == DriveType::Fixed) {
        drives[k].VolumeLabel = "NewLabelName";
        EXPECT_EQ("NewLabelName", drives[k].VolumeLabel());
        drives[k].VolumeLabel = volumeLabel;
        EXPECT_EQ(volumeLabel, drives[k].VolumeLabel);
      }
    }
  }
}

