/// @file
/// @brief Contains Pcf::System::Environment class.
#pragma once

#include "../Property.hpp"
#include "../Static.hpp"
#include "../Types.hpp"
#include "Array.hpp"
#include "Enum.hpp"
#include "OperatingSystem.hpp"
#include "String.hpp"
#include "Version.hpp"
#include "Collections/Generic/Dictionary.hpp"
#include "Collections/Specialized/StringDictionary.hpp"
#include "Threading/Thread.hpp"

class __start_up__;

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides information about, and means to manipulate, the current environment
    /// and platform. This class cannot be inherited.
    /// @remarks Use the Environment class to retrieve information such as command-line arguments, the exit code, environment variable settings, contents of the call stack, time since last system boot, and the version of the Pcf.
    /// @par Examples
    /// The following example demonstrates displays a list of information about the current environment.
    /// @include Environment.cpp
    class pcf_public Environment pcf_static {
    public:
      /// @enum SpecialFolder
      /// @brief Specifies enumerated constants used to retrieve directory paths to system special folders.
      /// @remarks The system special folders are folders such as Program Files, Programs, System, or Startup, which contain common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows::
      /// @remarks The GetFolderPath method returns the locations associated with this enumeration. The locations of these folders can have different values on different operating systems, the user can change some of the locations, and the locations are localized.
      /// @remarks For more information about special folders, see the KNOWNFOLDERID constants in the Windows documentation.
      /// @see Environment
      enum class SpecialFolder {
        /// @brief The logical Desktop rather than the physical file system location.
        Desktop = 0,
        /// @brief The directory that contains the user's program groups.
        Programs = 2,
        /// @brief The My Documents folder.
        /// This member is equivalent to Personal.
        MyDocuments = 5,
        /// @brief The directory that serves as a common repository for documents.
        /// This member is equivalent to MyDocuments.
        Personal = 5,
        /// @brief The directory that serves as a common repository for the user's favorite items.
        Favorites = 6,
        /// @brief The directory that corresponds to the user's Startup program group.
        /// The system starts these programs whenever a user logs on or starts Windows NT or later, or starts Windows 98.
        Startup = 7,
        /// @brief The directory that contains the user's most recently used documents.
        Recent = 8,
        /// @brief The directory that contains the Send To menu items.
        SendTo = 9,
        /// @brief The directory that contains the Start menu items.
        StartMenu = 11,
        /// @brief The My Music folder.
        MyMusic = 13,
        /// @brief The file system directory that serves as a repository for videos that belong to a user.
        MyVideos = 14,
        /// @brief The directory used to physically store file objects on the desktop.
        /// Do not confuse this directory with the desktop folder itself, which is a virtual folder.
        DesktopDirectory = 16,
        /// @brief The My Computer folder.
        /// The MyComputer constant always yields the empty string ("") because no path is defined for the My Computer folder.
        MyComputer = 17,
        /// @brief A file system directory that contains the link objects that may exist in the My Network Places virtual folder.
        NetworkShortcuts = 19,
        /// @brief A virtual folder that contains fonts.
        Fonts = 20,
        /// @brief The directory that serves as a common repository for document templates.
        Templates = 21,
        /// @brief The file system directory that contains the programs and folders that appear on the Start menu for all users. This special folder is valid only for Windows NT systems.
        CommonStartMenu = 22,
        /// @brief A folder for components that are shared across applications. This special folder is valid only for Windows NT, Windows 2000, and Windows XP systems.
        CommonPrograms = 23,
        /// @brief The file system directory that contains the programs that appear in the Startup folder for all users. This special folder is valid only for Windows NT systems.
        CommonStartup = 24,
        /// @brief The file system directory that contains files and folders that appear on the desktop for all users. This special folder is valid only for Windows NT systems.
        CommonDesktopDirectory = 25,
        /// @brief The directory that serves as a common repository for application-specific data for the current roaming user.
        /// A roaming user works on more than one computer on a network. A roaming user's profile is kept on a server on the network and is loaded onto a system when the user logs on.
        ApplicationData = 26,
        /// @brief The file system directory that contains the link objects that can exist in the Printers virtual folder.
        PrinterShortcuts = 27,
        /// @brief The directory that serves as a common repository for application-specific data that is used by the current, non-roaming user.
        LocalApplicationData = 28,
        /// @brief The directory that serves as a common repository for temporary Internet files.
        InternetCache = 32,
        /// @brief The directory that serves as a common repository for Internet cookies.
        Cookies = 33,
        /// @brief The directory that serves as a common repository for Internet history items.
        History = 34,
        /// @brief The directory that serves as a common repository for application-specific data that is used by all users.
        CommonApplicationData = 35,
        /// @brief The Windows directory or SYSROOT. This corresponds to the %windir% or %SYSTEMROOT% environment variables.
        Windows = 36,
        /// @brief The System directory.
        System = 37,
        /// @brief The program files directory.On a non-x86 system, passing ProgramFiles to the GetFolderPath method returns the path for non-x86 programs. To get the x86 program files directory on a non-x86 system, use the ProgramFilesX86 member.
        ProgramFiles = 38,
        /// @brief The My Pictures folder.
        MyPictures = 39,
        /// @brief The user's profile folder. Applications should not create files or folders at this level; they should put their data under the locations referred to by ApplicationData.
        UserProfile = 40,
        /// @brief The Windows System folder.
        SystemX86 = 41,
        /// @brief The Program Files folder On an x86 system, passing the ProgramFilesX86 member to the Environment.GetFolderPath method returns string.Empty; use the ProgramFiles member instead. You can determine whether Windows is a 32-bit operating system by calling the Environment.Is64BitOperatingSystem property.
        ProgramFilesX86 = 42,
        /// @brief The directory for components that are shared across applications.To get the x86 common program files directory on a non-x86 system, use the ProgramFilesX86 member.
        CommonProgramFiles = 43,
        /// @brief The Program Files folder.
        CommonProgramFilesX86 = 44,
        /// @brief The file system directory that contains the templates that are available to all users. This special folder is valid only for Windows NT systems.
        CommonTemplates = 45,
        /// @brief The file system directory that contains documents that are common to all users. This special folder is valid for Windows NT systems, Windows 95, and Windows 98 systems with Shfolder.dll installed.
        CommonDocuments = 46,
        /// @brief The file system directory that contains administrative tools for all users of the computer.
        CommonAdminTools = 47,
        /// @brief The file system directory that is used to store administrative tools for an individual user. The Microsoft Management Console (MMC) will save customized consoles to this directory, and it will roam with the user.
        AdminTools = 48,
        /// @brief The file system directory that serves as a repository for music files common to all users.
        CommonMusic = 53,
        /// @brief The file system directory that serves as a repository for image files common to all users.
        CommonPictures = 54,
        /// @brief The file system directory that serves as a repository for video files common to all users.
        CommonVideos = 55,
        /// @brief The file system directory that contains resource data.
        Resources = 56,
        /// @brief The file system directory that contains localized resource data.
        LocalizedResources = 57,
        /// @brief This value is recognized in Windows Vista for backward compatibility, but the special folder itself is no longer used.
        CommonOemLinks = 58,
        /// @brief The file system directory that acts as a staging area for files waiting to be written to a CD.
        CDBurning = 59
      };
      
      /// @brief Gets the command line for this process.
      /// @return string A string represented the command line for this process.
      /// @remarks This property provides access to the program name and any arguments specified on the command line when the current process was started.
      /// @remarks The program name can include path information, but is not required to do so. Use the GetCommandLineArgs method to retrieve the command-line information parsed and stored in an array of strings.
      /// @remarks The maximum size of the command-line buffer is not set to a specific number of characters; it varies depending on the Windows operating system that is running on the computer.
      /// @par Example
      /// The following example displays its own command line.
      /// @include EnvironmentCommandLine.cpp
      static Property<String, ReadOnly> CommandLine;
      
      /// @brief Gets or sets the current working directory.
      /// @param The current working directory. An empty string return value indicates an error,
      /// @exception IO::IOError An I/O error occurred.
      /// @exception ArgumentException Attempted to set to an empty string ("").
      /// @exception ArgumentNullException Attempted to set to null.
      /// @exception IOException An I/O error occurred.
      /// @exception DirectoryNotFoundException Attempted to set a local path that cannot be found.
      /// @exception SecurityException The caller does not have the appropriate permission.
      /// @remarks By definition, if this process starts in the root directory of a local or network drive, the value of this property is the drive name followed by a trailing slash (for example, "C:\"). If this process starts in a subdirectory, the value of this property is the drive and subdirectory path, without a trailing slash (for example, "C:\mySubDirectory").
      /// @par Example
      /// The following example demonstrates setting the CurrentDirectory property.
      /// @include EnvironmentCurrentDirectory.cpp
      static Property<string> CurrentDirectory;
      
      /// @brief Gets a unique identifier for the current managed thread.
      /// @return int32 An integer that represents a unique identifier for this managed thread.
      static Property<int32, ReadOnly> CurrentManagedThreadId;
      
      /// @brief Gets or sets the exit code of the process.
      /// @return Int32 A 32-bit signed integer containing the exit code. The default value is zero.
      /// @remarks If the Main method returns void, you can use this property to set the exit code that will be returned to the calling environment. If Main does not return void, this property is ignored. The initial value of this property is zero.
      /// @warning The ExitCode property is a signed 32-bit integer. To prevent the property from returning a negative exit code, you should not use values greater than or equal to 0x80000000.
      /// @remarks Use a non-zero number to indicate an error. In your application, you can define your own error codes in an enumeration, and return the appropriate error code based on the scenario. For example, return a value of 1 to indicate that the required file is not present and a value of 2 to indicate that the file is in the wrong format. For a list of exit codes used by the Windows operating system, see System Error Codes in the Windows documentation.
      /// @par Example
      /// The following is a simple app named Double.exe that doubles an integer value passed to it as a command-line argument. The value assigns error codes to the ExitCode property to indicate error conditions. Note that you must add a reference to the System.Numerics.dll assembly to successfully compile the example.
      /// @include EnvironmentExitCode.cpp
      /// The example can then be invoked on Windows from a batch file such as the following, which makes its error codes accessible by using the ERRORLEVEL command.
      /// @code
      /// echo off
      /// EnvironmentExitCode.exe %1
      ///
      /// if ERRORLEVEL 89 echo Missing argument
      /// if ERRORLEVEL 34 echo Arithmetic overflow
      /// if ERRORLEVEL 22 echo Invalid argument
      /// if ERRORLEVEL 0 echo Completed Successfully
      /// @endcode
      /// The example can then be invoked on macOS or linux from a batch file such as the following, which makes its error codes accessible by using the $? command.
      /// @code
      /// ./EnvironmentExitCode $1
      ///
      /// case $? in
      ///   89) echo "Missing argument";;
      ///   34) echo "Arithmetic overflow";;
      ///   22) echo "Invalid argument";;
      ///   0) echo "Completed Successfully";;
      /// esac
      /// @endcode
      static Property<int32> ExitCode;
      
      /// @brief Gets a value that indicates whether the current application domain is shutting down.
      /// @return bool true if the current application domain is shutting down; otherwise, false.
      /// @remarks At this time the return value is always false;
      static Property<bool, ReadOnly> HasShutdownStarted;
      
      /// @brief Determines whether the current operating system is a 64-bit operating system.
      /// @return bool true if the operating system is 64-bit; otherwise, false.
      static Property<bool, ReadOnly>  Is64BitOperatingSystem;
      
      /// @brief Determines whether the current process is a 64-bit process.
      /// @return bool true if the process is 64-bit; otherwise, false.
      static Property<bool, ReadOnly>  Is64BitProcess;
      
      /// @brief Gets the NetBIOS name of this local computer.
      /// @return string A string containing the name of this computer.
      /// @exception InvalidOperationException The name of this computer cannot be obtained.
      static Property<String, ReadOnly>  MachineName;
      
      /// @brief Gets the newline string defined for this environment.
      /// @return string A string containing "\r\n" for non-Unix platforms, or a string containing "\n" for Unix platforms.
      static Property<String, ReadOnly> NewLine;
      
      /// @brief Gets an OperatingSystem object that contains the current platform identifier and version number.
      /// @return OperatingSystem An object that contains the platform identifier and version number.
      static Property<const OperatingSystem&, ReadOnly> OSVersion;
      
      /// @brief Gets the number of processors on the current machine.
      /// @return int32 The 32-bit signed integer that specifies the number of processors on the current machine. There is no default. If the current machine contains multiple processor groups, this property returns the number of logical processors.
      /// @remarks For more information about processor groups and logical processors, see Processor Groups.
      static Property<int32, ReadOnly> ProcessorCount;
      
      /// @brief Gets current stack trace information.
      /// @return string A string containing stack trace information. This value can be string.Empty.
      static Property<String, ReadOnly> StackTrace;
      
      /// @brief Gets the fully qualified path of the system directory.
      /// @return string A string containing a directory path.
      /// @remarks An example of the value returned is the string "C:\WinNT\System32".
      /// @par Example
      /// The following example displays the system directory of the computer that runs the code example. (The system directory is omitted from the example output for security reasons.)
      /// @include EnvironmentsystemDirectory.cpp
      static Property<String, ReadOnly> SystemDirectory;
      
      /// @brief Gets the number of milliseconds elapsed since the system started.
      /// @return Int32 A 32-bit signed integer containing the amount of time in milliseconds that has passed since the last time the computer was started.
      /// @remarks The value of this property is derived from the system timer and is stored as a 32-bit signed integer. Consequently, if the system runs continuously, TickCount will increment from zero to Int32.MaxValue for approximately 24.9 days, then jump to Int32.MinValue, which is a negative number, then increment back to zero during the next 24.9 days.
      /// @remarks TickCount is different from the Ticks property, which is the number of 100-nanosecond intervals that have elapsed since 1/1/0001, 12:00am.
      /// @remarks Use the DateTime::Now property to obtain the current local date and time on this computer.
      static Property<int32, ReadOnly> TickCount;
      
      /// @brief Gets the network domain name associated with the current user.
      /// @return string The network domain name associated with the current user.
      static Property<String, ReadOnly> UserDomainName;
      
      /// @brief Gets a value indicating whether the current process is running in user interactive mode.
      /// @return bool true if the current process is running in user interactive mode; otherwise, false.
      /// @remarks The UserInteractive property reports false for a Os process or a service like IIS that runs without a user interface. If this property is false, do not display modal dialogs or message boxes because there is no graphical user interface for the user to interact with.
      static Property<bool, ReadOnly> UserInteractive;
      
      /// @brief Gets the user name of the person who is currently logged on to the Windows operating system.
      /// @return string The user name of the person who is logged on to Windows/Linux/macOS/... .
      /// @remarks You can use the UserName property to identify the user on the current thread, to the system and application for security or access purposes. It can also be used to customize a particular application for each user.
      /// @remarks The domain account credentials for a user are formatted as the user's domain name, the '\' character, and user name. Use the UserDomainName property to obtain the user's domain name and the UserName property to obtain the user name. A user name is typically an abbreviated combination of the user's first and last names.
      static Property<String, ReadOnly> UserName;
      
      /// @brief Gets a Version object that describes the major, minor, build, and revision numbers of the System core.
      static Property<const System::Version&, ReadOnly> Version;
      
      /// @brief Gets the amount of physical memory mapped to the process context.
      /// @return Int64 A 64-bit signed integer containing the number of bytes of physical memory mapped to the process context.
      /// @remarks Windows 98, Windows Millennium Edition, Linux, macOS, Android,... Platform Note: This property always returns zero.
      static Property<int64, ReadOnly> WorkingSet;
      
      /// @brief Terminates this process and gives the underlying operating system the specified exit code.
      /// @param exitCode Exit code to be given to the operating system.
      static void Exit(int32 exitCode);
      
      /// @brief Replaces the name of each environment variable embedded in the specified string with the string equivalent of the value of the variable, then returns the resulting string.
      /// @param name A string containing the names of zero or more environment variables. Each environment variable is quoted with the percent sign character (%).
      /// @return A string with each environment variable replaced by its value.
      /// @exception ArgumentNullException name is null.
      static String ExpandEnvironmentVariables(const String& name);
      
      /// @brief Returns a string array containing the command-line arguments for the current process.
      /// @return Array<string> An array of string where each element contains a command-line argument. The first element is the executable file name, and the following zero or more elements contain the remaining command-line arguments.
      static const Array<String>& GetCommandLineArgs();
      
      /// @brief Initailize CommandLineArgs with specified command line arguments.
      /// @remarks This methode must be call only once in main.
      /// @param argv Command line arguments.
      /// @param argc Number of command line arguments.
      /// @return Array<string> A string array that contains the arguments without the command line.
      /// @exception InvalidOperationException Call more than once. CommandeLine has already been set and is not empty.
      static Array<string> SetCommandLineArgs(char* argv[], int argc);
      
      /// @brief Retrieves all environment variable names and their values from the current process.
      /// @return Collections::Generic::IDictionary<string, string> A dictionary that contains all environment variable names and their values; otherwise, an empty dictionary if no environment variables are found.
      /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned IDictionary.
      static const Collections::Generic::IDictionary<String, String>& GetEnvironmentVariables();
      
      /// @brief Retrieves the value of an environment variable from the current process.
      /// @param variable The name of the environment variable.
      /// @return tring The value of the environment variable specified by variable, or null if the environment variable is not found.
      static String GetEnvironmentVariable(const String& variable);
      
      /// @brief Creates, modifies, or deletes an environment variable stored in the current process.
      /// @param name The name of an environment variable.
      /// @param value A value to assign to variable.
      /// @exception ArgumentNullException name is null.
      /// @exception ArgumentException An error occurred during the execution of this operation.
      static void SetEnvironmentVariable(const String& name, const String& value);
      
      /// @brief Gets the path to the system special folder that is identified by the specified enumeration.
      /// @param folder An enumerated constant that identifies a system special folder.
      /// @return string The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
      /// @remarks A folder will not physically exist if the operating system did not create it, the existing folder was deleted, or the folder is a virtual directory, such as My Computer, which does not correspond to a physical path.
      /// @remarks This method retrieves the path to a system special folder, such as Program Files, Programs, System, or Startup, which can be used to access common information. Special folders are set by default by the system, or explicitly by the user, when installing a version of Windows::
      /// @remarks The folder parameter designates the special folder to retrieve and must be one of the values in the Environment.SpecialFolder enumeration; any other value throws an exception.
      /// @remarks For more information about special folders, see the CSIDL values topic.
      static String GetFolderPath(Environment::SpecialFolder folder);
      
      /// @brief Returns an array of string containing the names of the logical drives on the current computer.
      /// @return Array<string> An array of strings where each element contains the name of a logical drive. For example, if the computer's hard drive is the first logical drive, the first element returned is "C:\".
      static Array<String> GetLogicalDrives();
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::Environment::SpecialFolder> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Environment::SpecialFolder::Desktop, "Desktop"}, {(int64)System::Environment::SpecialFolder::Programs, "Programs"}, {(int64)System::Environment::SpecialFolder::MyDocuments, "MyDocuments"}, /*{(int64)System::Environment::SpecialFolder::Personal, "Personal"},*/ {(int64)System::Environment::SpecialFolder::Favorites, "Favorites"}, {(int64)System::Environment::SpecialFolder::Startup, "Startup"}, {(int64)System::Environment::SpecialFolder::Recent, "Recent"}, {(int64)System::Environment::SpecialFolder::SendTo, "SendTo"}, {(int64)System::Environment::SpecialFolder::StartMenu, "StartMenu"}, {(int64)System::Environment::SpecialFolder::MyMusic, "MyMusic"}, {(int64)System::Environment::SpecialFolder::MyVideos, "MyVideos"}, {(int64)System::Environment::SpecialFolder::DesktopDirectory, "DesktopDirectory"}, {(int64)System::Environment::SpecialFolder::MyComputer, "MyComputer"}, {(int64)System::Environment::SpecialFolder::NetworkShortcuts, "NetworkShortcuts"}, {(int64)System::Environment::SpecialFolder::Fonts, "Fonts"}, {(int64)System::Environment::SpecialFolder::Templates, "Templates"}, {(int64)System::Environment::SpecialFolder::CommonStartMenu, "CommonStartMenu"}, {(int64)System::Environment::SpecialFolder::CommonPrograms, "CommonPrograms"}, {(int64)System::Environment::SpecialFolder::CommonStartup, "CommonStartup"}, {(int64)System::Environment::SpecialFolder::CommonDesktopDirectory, "CommonDesktopDirectory"}, {(int64)System::Environment::SpecialFolder::ApplicationData, "ApplicationData"}, {(int64)System::Environment::SpecialFolder::PrinterShortcuts, "PrinterShortcuts"}, {(int64)System::Environment::SpecialFolder::LocalApplicationData, "LocalApplicationData"}, {(int64)System::Environment::SpecialFolder::InternetCache, "InternetCache"}, {(int64)System::Environment::SpecialFolder::Cookies, "Cookies"}, {(int64)System::Environment::SpecialFolder::History, "History"}, {(int64)System::Environment::SpecialFolder::CommonApplicationData, "CommonApplicationData"}, {(int64)System::Environment::SpecialFolder::Windows, "Windows"}, {(int64)System::Environment::SpecialFolder::System, "System"}, {(int64)System::Environment::SpecialFolder::ProgramFiles, "ProgramFiles"}, {(int64)System::Environment::SpecialFolder::MyPictures, "MyPictures"}, {(int64)System::Environment::SpecialFolder::UserProfile, "UserProfile"}, {(int64)System::Environment::SpecialFolder::SystemX86, "SystemX86"}, {(int64)System::Environment::SpecialFolder::ProgramFilesX86, "ProgramFilesX86"}, {(int64)System::Environment::SpecialFolder::CommonProgramFiles, "CommonProgramFiles"}, {(int64)System::Environment::SpecialFolder::CommonProgramFilesX86, "CommonProgramFilesX86"}, {(int64)System::Environment::SpecialFolder::CommonTemplates, "CommonTemplates"}, {(int64)System::Environment::SpecialFolder::CommonDocuments, "CommonDocuments"}, {(int64)System::Environment::SpecialFolder::CommonAdminTools, "CommonAdminTools"}, {(int64)System::Environment::SpecialFolder::AdminTools, "AdminTools"}, {(int64)System::Environment::SpecialFolder::CommonMusic, "CommonMusic"}, {(int64)System::Environment::SpecialFolder::CommonPictures, "CommonPictures"}, {(int64)System::Environment::SpecialFolder::CommonVideos, "CommonVideos"}, {(int64)System::Environment::SpecialFolder::Resources, "Resources"}, {(int64)System::Environment::SpecialFolder::LocalizedResources, "LocalizedResources"}, {(int64)System::Environment::SpecialFolder::CommonOemLinks, "CommonOemLinks"}, {(int64)System::Environment::SpecialFolder::CDBurning, "CDBurning"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;

