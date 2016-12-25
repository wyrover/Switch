#pragma once

#include "../../../Includes/Pcf/Types.h"
#include "../../../Includes/Pcf/System/Array.h"
#include "../../../Includes/Pcf/System/Environment.h"
#include "../../../Includes/Pcf/System/String.h"
#include "../../../Includes/Pcf/System/IO/FileAttributes.h"

/// @cond
namespace Pcf {
  namespace Os {
    /// @brief Represents a Os object that provides the access Directory API.
    /// @remarks This class cannot be inherited.
    /// @remarks Internal used only.
    class Directory final {
    public:
      /// @brief Provides a platform-specific alternate character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @remarks Internal used only.
      static char32 AltDirectorySeparatorChar();
      
      /// @brief Provides a platform-specific character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @remarks Internal used only.
      static char32 DirectorySeparatorChar();
      
      /// @brief A character array of invalid path characters for the current platform.
      /// @remarks Internal used only.
      static System::Array<char32> InvalidPathChars();
      
      /// @brief A platform-specific separator character used to separate path strings in environment variables.
      /// @remarks Internal used only.
      static char32 PathSeparator();
      
      /// @brief Provides a platform-specific volume separator character.
      /// @remarks Internal used only.
      static char32 VolumeSeparator();

      /// @brief Returns a directory list from the specified directory.
      /// @remarks Internal used only.
      /// @param fullPath The target directory.
      /// @param pattern The search string, such as "System*", used to search for all files beginning with the word "System".
      /// @return An array of directory name string.
      static System::Collections::Generic::Enumerator<string> EnumerateDirectories(const string& path, const string& pattern);
      
      /// @brief Returns a file list from the specified directory.
      /// @remarks Internal used only.
      /// @param fullPath The target directory.
      /// @param pattern The search string, such as "System*", used to search for all files beginning with the word "System".
      /// @return An array of file name string.
      static System::Collections::Generic::Enumerator<string> EnumerateFiles(const string& path, const string& pattern);
      
      #undef GetFileAttributes
      /// @brief Return the file attributes
      /// @remarks Internal used only.
      /// @param path the path of existing file or directory.
      /// @return Returns 0 if the file-attributes information is obtained. A return value of -1 indicates an error
      static int32 GetFileAttributes(const string& path, System::IO::FileAttributes& attributes);

      /// @brief Return the creation, last access et last modified time of the file
      /// @remarks Internal used only.
      /// @param path the path of existing file or directory.
      /// @param creationTime File creation time
      /// @param lastAccessTime File last access time
      /// @param lastWriteTime File last write time
      /// @return Returns 0 if the file-time information is obtained. A return value of -1 indicates an error
      static int32 GetFileTime(const string& path, int64& creationTime, int64& lastAccessTime, int64& lastWriteTime);

      /// @brief Creates an absolute or full path name for the specified relative path name.
      /// @remarks Internal used only.
      /// @param absPath Pointer to a buffer containing the absolute or full path name, or null.
      /// @param relPath Relative path name.
      /// @param maxLength Maximum length of the absolute path name buffer (absPath).
      /// @return a pointer to a buffer containing the absolute path name (absPath).
      /// @remarks If there is an error (for example, if the value passed in relPath includes a drive letter that is not valid or cannot be found, or if the length of the created absolute path name (absPath) is greater than maxLength), the function returns null.
      static string GetFullPath(const string& relativePath);

      #undef GetCurrentDirectory
      /// @brief Gets the current working directory.
      /// @remarks Internal used only.
      /// @return The current working directory. An empty string return value indicates an error.
      static string GetCurrentDirectory();
      
      #undef SetCurrentDirectory
      /// @brief Changes the current working directory.
      /// @remarks Internal used only.
      /// @param directoryName Path of new working directory.
      /// @return 0 if successful. A return value of -1 indicates failure.
      static int32 SetCurrentDirectory(const string& directoryName);

      /// @brief Get size information on a file.
      /// @remarks Internal used only.
      /// @param path Get size information on a file.
      /// @param size Size of the file in bytes;
      /// @return returns 0 if the file-status information is obtained. A return value of -1 indicates an error
      static int64 GetFileSize(const string& path);

      #undef CreateDirectory
      /// @brief Creates a new directory.
      /// @remarks Internal used only.
      /// @param directoryName Path for a new directory
      /// @return returns the value 0 if the new directory was created. On an error, the function returns -1.
      static int32 CreateDirectory(const string& directoryName);

      #undef RemoveDirectory
      /// @brief Deletes a directory.
      /// @remarks Internal used only.
      /// Path of the directory to be removed.
      /// @return returns 0 if the directory is successfully deleted. A return value of -1 indicates an error
      static int32 RemoveDirectory(const string& directoryName);

      /// @brief Delete a file.
      /// @remarks Internal used only.
      /// @param file Path of file to be removed.
      /// @return 0 if the file is successfully deleted. Otherwise, it returns -1.
      static int32 RemoveFile(const string& file);

      /// @brief Rename a file or directory.
      /// @remarks Internal used only.
      /// @param oldPath old name.
      /// @param newPath new name.
      /// @return If successful, returns 0. Otherwise, it returns -1
      static int32 RenameFile(const string& oldPath, const string& newPath);
      
      /// @brief Retrieves the full path of a known folder identified by the folder's Id
      /// @remarks Internal used only.
      /// @param id The Id that identifies the folder
      /// @return A pointer to a null-terminated Unicode string that specifies the path of the known folder.
      static string GetKnowFolderPath(System::Environment::SpecialFolder id);

      #undef GetTempPath
      /// @brief Returns the path of the current user's temporary folder.
      /// @return string The path to the temporary folder, ending with a backslash.
      /// @remarks This method checks for the existence of environment variables in the following order and uses the first path found:
      /// * The path specified by the TMP environment variable.
      /// * The path specified by the TEMP environment variable.
      /// * The path specified by the USERPROFILE environment variable.
      /// * The Windows directory.
      static string GetTempPath();
      
    private:
      Directory() = delete;
    };
  }
}

using namespace Pcf;
/// @endcond
