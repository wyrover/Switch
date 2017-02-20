#include "../../../../Includes/Pcf/Types.h"
#include "../../../../Includes/Pcf/System/IO/FileInfo.h"
#include "../../../../Includes/Pcf/System/Security/SecurityException.h"
#include "../../../../Includes/Pcf/System/IO/DirectoryInfo.h"
#include "../../../../Includes/Pcf/System/IO/File.h"
#include "../../../../Includes/Pcf/System/IO/FileNotFoundException.h"
#include "../../../../Includes/Pcf/System/IO/Path.h"
#include "../../../__OS/CoreApi.h"

using namespace System;
using namespace System::IO;

Property<FileInfo, ReadOnly> FileInfo::Empty {
  [] {return FileInfo();}
};

FileInfo::FileInfo() : Directory(pcf_delegate {return this->GetDirectory();}) {
}

FileInfo::FileInfo(const string& fileName) : Directory(pcf_delegate {return this->GetDirectory();}) {
  this->fullPath = Path::GetFullPath(fileName);
}

FileInfo::FileInfo(const FileInfo& fileInfo) : FileSystemInfo(fileInfo), Directory(pcf_delegate {return this->GetDirectory();}) { }

bool FileInfo::GetExists() const {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  return (__OS::CoreApi::Directory::GetFileAttributes(this->fullPath.ToCCharArray().Data(), fileAttributes) == 0 && !Enum<FileAttributes>(fileAttributes).HasFlag(FileAttributes::Directory));
}

DirectoryInfo FileInfo::GetDirectory() const {
  return DirectoryInfo(DirectoryName());
}

string FileInfo::GetDirectoryName() const {
  return Path::Combine(Path::GetPathRoot(this->fullPath), Path::GetDirectoryName(this->fullPath));
}

string FileInfo::GetName() const {
  return Path::GetFileName(this->fullPath);
}

void FileInfo::Delete() {
  if (__OS::CoreApi::Directory::RemoveFile(this->fullPath.ToCCharArray().Data()) != 0)
    throw System::Security::SecurityException(pcf_current_information);
}

FileInfo FileInfo::CopyTo(const string& destFileName) {
  if (!Exists())
    throw FileNotFoundException(pcf_current_information);
  
  if (File::Exists(destFileName))
    throw IOException(pcf_current_information);
  
  string fullPathDestFileName = Path::GetFullPath(destFileName);
  
  FILE* source = fopen(this->fullPath.ToCCharArray().Data(), "rb");
  if (source == null)
    throw IOException(pcf_current_information);
  
  FILE* target = fopen(fullPathDestFileName.ToCCharArray().Data(), "wb");
  if (target == null) {
    fclose(source);
    throw IOException(pcf_current_information);
  }
  
  int32 count = 0;
  do {
    byte buffer[1024];
    count = Convert::ToInt32(fread(buffer, 1, 1024, source));
    if (count > 0)
      fwrite(buffer, 1, count, target);
  } while (count == 1024);
  
  fclose(source);
  fclose(target);
  
  return FileInfo(fullPathDestFileName);
}

FileInfo FileInfo::CopyTo(const string& destFileName, bool overwrite) {
  if (overwrite) {
    FileInfo DestFileInfo(destFileName);
    if (DestFileInfo.Exists())
      DestFileInfo.Delete();
  }
  return CopyTo(destFileName);
}

void FileInfo::MoveTo(const string& destFileName) {
  if (!Exists())
    throw FileNotFoundException(pcf_current_information);
  
  if (!Path::HasExtension(destFileName))
    throw ArgumentException(pcf_current_information);
  
  string fullPathDestFileName = Path::GetFullPath(destFileName);
  if (__OS::CoreApi::Directory::RenameFile(this->fullPath, fullPathDestFileName) != 0)
    throw IOException(pcf_current_information);
  
  this->fullPath = fullPathDestFileName;
}

int64 FileInfo::GetLength() const {
  return __OS::CoreApi::Directory::GetFileSize(this->fullPath);
}

FileStream FileInfo::Open(FileMode mode, FileAccess access) {
  return FileStream(this->fullPath, mode, access, FileShare(FileShare::None));
}

FileStream FileInfo::OpenRead() {
  return FileStream(this->fullPath, FileMode(FileMode::Open), FileAccess(FileAccess::Read), FileShare(FileShare::None));
}

FileStream FileInfo::OpenWrite() {
  return FileStream(this->fullPath, FileMode(FileMode::OpenOrCreate), FileAccess(FileAccess::Write), FileShare(FileShare::None));
}

bool FileInfo::Equals(const FileInfo& value) const {
  return this->fullPath.Equals(value.fullPath);
}

bool FileInfo::Equals(const object& obj) const noexcept {
  return is<FileInfo>(obj) && Equals((const FileInfo&)obj);
}

string FileInfo::ToString() const noexcept {
  return FullName();
}

