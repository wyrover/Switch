#include "../../../../Includes/Pcf/System/IO/Directory.h"
#include "../../../../Includes/Pcf/System/IO/File.h"
#include "../../../../Includes/Pcf/System/IO/DirectoryNotFoundException.h"
#include "../../../../Includes/Pcf/System/IO/Path.h"
#include "../../../../Includes/Pcf/System/Security/SecurityException.h"
#include "../../../../Includes/Pcf/System/Text/StringBuilder.h"
#include "../../Os/Directory.h"

using namespace System;
using namespace System::IO;

const DirectoryInfo DirectoryInfo::Empty;

DirectoryInfo::DirectoryInfo(const string& path) {
  this->fullPath = Path::GetFullPath(path);
}

bool DirectoryInfo::GetExists() const {
  System::IO::FileAttributes fileAttributes = (System::IO::FileAttributes)0;
  return (Os::Directory::GetFileAttributes(this->fullPath.Data(), fileAttributes) == 0 && Enum<FileAttributes>(fileAttributes).HasFlag(FileAttributes::Directory));
}

string DirectoryInfo::GetName() const {
  Array<string> array = this->fullPath.Split(Path::DirectorySeparatorChar);
  if (array.Length == 0)
    return this->fullPath;
  return array[array.Length-1];
}

DirectoryInfo DirectoryInfo::GetParent() const {
  if (this->fullPath == Path::GetPathRoot(this->fullPath))
    return Empty;
  return DirectoryInfo(Path::Combine(this->fullPath, ".."));
}

DirectoryInfo DirectoryInfo::GetRoot() const {
  return DirectoryInfo(Path::GetPathRoot(this->fullPath));
}

void DirectoryInfo::Create() {
  if (Os::Directory::CreateDirectory(this->fullPath) != 0)
    throw IOException(pcf_current_information);
}

DirectoryInfo DirectoryInfo::CreateSubdirectory(const string& path) {
  DirectoryInfo dirInfo(Path::Combine(this->fullPath, path));
  if (!dirInfo.Exists())
    dirInfo.Create();
  return dirInfo;
}

void DirectoryInfo::Delete(bool recursive) {
  if (!this->Exists())
    throw Security::SecurityException(pcf_current_information);
  
  if (recursive) {
    for (string item : Os::Directory::EnumerateFiles(this->fullPath, "*"))
      File::Delete(Path::Combine(this->fullPath, item));
    for (string item : Os::Directory::EnumerateDirectories(this->fullPath, "*"))
      Directory::Delete(Path::Combine(this->fullPath, item), true);
  }
  
  if (Os::Directory::RemoveDirectory(this->fullPath) != 0)
    throw IOException(pcf_current_information);
}

Array<FileInfo> DirectoryInfo::GetFiles(const string& searchPattern) const {
  System::Collections::Generic::List<FileInfo> files;
  for (string item : Os::Directory::EnumerateFiles(this->fullPath, searchPattern))
    files.Add(FileInfo(Path::Combine(this->fullPath, item)));
  return files.ToArray();
}

Array<DirectoryInfo> DirectoryInfo::GetDirectories(const string& searchPattern) const {
  System::Collections::Generic::List<DirectoryInfo> directories;
  for (string item : Os::Directory::EnumerateDirectories(this->fullPath, searchPattern))
    directories.Add(DirectoryInfo(Path::Combine(this->fullPath, item)));
  return directories.ToArray();
}

void DirectoryInfo::MoveTo(const string& destDirName) {
  DirectoryInfo destDirInfo(destDirName);

  if (destDirName == "" || destDirInfo.Exists() || Equals(destDirInfo) || !Path::GetPathRoot(this->FullName).Equals(Path::GetPathRoot(destDirInfo.FullName)) || destDirInfo.FullName().StartsWith(this->FullName))
    throw IOException(pcf_current_information);
  
  if (!destDirInfo.Exists())
    throw DirectoryNotFoundException(pcf_current_information);
  
  string targetDirName = Path::Combine(destDirName, this->fullPath.Substring(this->fullPath.LastIndexOf(Path::DirectorySeparatorChar) + 1));
  Directory::CreateDirectory(targetDirName);
  
  for (string item : Os::Directory::EnumerateFiles(this->fullPath, "*"))
    File::Move(Path::Combine(this->fullPath, item), Path::Combine(targetDirName, item));
  for (string item : Os::Directory::EnumerateDirectories(this->fullPath, "*"))
    Directory::Move(Path::Combine(this->fullPath, item), Path::Combine(targetDirName, item));

  Delete();
  this->fullPath = targetDirName;
}
