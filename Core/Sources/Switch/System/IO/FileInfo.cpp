#include "../../../../Includes/Switch/Types.hpp"
#include "../../../../Includes/Switch/System/IO/FileInfo.hpp"
#include "../../../../Includes/Switch/System/Security/SecurityException.hpp"
#include "../../../../Includes/Switch/System/IO/DirectoryInfo.hpp"
#include "../../../../Includes/Switch/System/IO/File.hpp"
#include "../../../../Includes/Switch/System/IO/FileNotFoundException.hpp"
#include "../../../../Includes/Switch/System/IO/Path.hpp"
#include "../../../__OS/CoreApi.hpp"

using namespace System;
using namespace System::IO;

property<FileInfo, readonly> FileInfo::Empty {
  [] {return FileInfo();}
};

FileInfo::FileInfo() : Directory(_delegate {return this->GetDirectory();}) {
}

FileInfo::FileInfo(const string& fileName) : Directory(_delegate {return this->GetDirectory();}) {
  this->fullPath = Path::GetFullPath(fileName);
}

FileInfo::FileInfo(const FileInfo& fileInfo) : FileSystemInfo(fileInfo), Directory(_delegate {return this->GetDirectory();}) { }

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
    throw System::Security::SecurityException(_current_information);
}

FileInfo FileInfo::CopyTo(const string& destFileName) {
  if (!Exists())
    throw FileNotFoundException(_current_information);
  
  if (File::Exists(destFileName))
    throw IOException(_current_information);
  
  string fullPathDestFileName = Path::GetFullPath(destFileName);
  
  FILE* source = fopen(this->fullPath.ToCCharArray().Data(), "rb");
  if (source == null)
    throw IOException(_current_information);
  
  FILE* target = fopen(fullPathDestFileName.ToCCharArray().Data(), "wb");
  if (target == null) {
    fclose(source);
    throw IOException(_current_information);
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
    throw FileNotFoundException(_current_information);
  
  if (!Path::HasExtension(destFileName))
    throw ArgumentException(_current_information);
  
  string fullPathDestFileName = Path::GetFullPath(destFileName);
  if (__OS::CoreApi::Directory::RenameFile(this->fullPath, fullPathDestFileName) != 0)
    throw IOException(_current_information);
  
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

bool FileInfo::Equals(const object& obj) const {
  return is<FileInfo>(obj) && Equals((const FileInfo&)obj);
}

string FileInfo::ToString() const {
  return FullName();
}

