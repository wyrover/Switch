#include "../../../../Includes/Pcf/System/IO/Directory.h"
#include "../../../../Includes/Pcf/System/IO/DirectoryInfo.h"
#include "../../../../Includes/Pcf/System/Environment.h"
#include "../../../../Includes/Pcf/System/IO/File.h"
#include "../../../../Includes/Pcf/System/IO/Path.h"
#include "../../Os/Directory.h"

using namespace System;
using namespace System::IO;

const DirectoryInfo Directory::CreateDirectory(const string& path) {
  DirectoryInfo dirInfo(path);
  if (!dirInfo.Exists()) {
    if (!dirInfo.Parent().FullName().IsEmpty())
      Directory::CreateDirectory(dirInfo.Parent().FullName());
    dirInfo.Create();
  }
  return dirInfo;
}

void Directory::Delete(const string& path) {
  DirectoryInfo(path).Delete();
}

void Directory::Delete(const string& path, bool recursive) {
  DirectoryInfo(path).Delete(recursive);
}

System::Collections::Generic::Enumerator<string> Directory::EnumerateDirectories(const string& path) {
  return Os::Directory::EnumerateDirectories(path, "*");
}

System::Collections::Generic::Enumerator<string> Directory::EnumerateDirectories(const string& path, const string& pattern) {
  return Os::Directory::EnumerateDirectories(path, pattern);
}

System::Collections::Generic::Enumerator<string> Directory::EnumerateFiles(const string& path) {
  return Os::Directory::EnumerateFiles(path, "*");
}

System::Collections::Generic::Enumerator<string> Directory::EnumerateFiles(const string& path, const string& pattern) {
  return Os::Directory::EnumerateFiles(path, pattern);
}

bool Directory::Exists(const string& path) {
  try {
    return DirectoryInfo(path).Exists();
  } catch (const Exception& ) {
    return false;
  }
}

DateTime Directory::GetCreationTime(const string& path) {
  return DirectoryInfo(path).CreationTime();
}

DateTime Directory::GetCreationTimeUtc(const string& path) {
  return GetCreationTime(path).ToUniversalTime();
}

System::Array<string> Directory::GetDirectories(const string& path) {
  System::Collections::Generic::List<string> directories;
  for (const auto& item : EnumerateDirectories(path))
    directories.Add(item);
  return directories.ToArray();
}

System::Array<string> Directory::GetDirectories(const string& path, const string& pattern) {
  System::Collections::Generic::List<string> directories;
  for (const auto& item : EnumerateDirectories(path, pattern))
    directories.Add(item);
  return directories.ToArray();
}

System::Array<string> Directory::GetFiles(const string& path) {
  System::Collections::Generic::List<string> files;
  for (const auto& item : EnumerateDirectories(path))
    files.Add(item);
  return files.ToArray();
}

System::Array<string> Directory::GetFiles(const string& path, const string& pattern) {
  System::Collections::Generic::List<string> files;
  for (const auto& item : EnumerateDirectories(path, pattern))
    files.Add(item);
  return files.ToArray();
}

DateTime Directory::GetLastAccessTime(const string& path) {
  return DirectoryInfo(path).LastAccessTime();
}

DateTime Directory::GetLastWriteTime(const string& path) {
  return DirectoryInfo(path).LastWriteTime();
}

const string Directory::GetCurrentDirectory() {
  return Environment::CurrentDirectory();
}

const DirectoryInfo Directory::GetParent(const string& path) {
  return DirectoryInfo(path).Parent();
}

void Directory::Move(const string& src, const string& dst) {
  if (Path::HasExtension(src)) {
    File::Move(src, dst);
  } else {
    DirectoryInfo(src).MoveTo(dst);
  }
}

