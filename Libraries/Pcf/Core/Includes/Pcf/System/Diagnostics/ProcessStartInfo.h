/// @file
/// @brief Contains Pcf::System::Diagnostics::ProcessStartInfo class.
#pragma once

#include "../../Property.h"
#include "../../Types.h"
#include "../Object.h"
#include "../String.h"
#include "../Collections/Generic/Dictionary.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @brief Specifies a set of values that are used when you start a process.
      class ProcessStartInfo : public Object {
      public:
        /// @brief Initializes a new instance of the ProcessStartInfo class without specifying a file name with which to start the process.
        /// @remarks You must set at least the SetFileName() property before you start the process. The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
        /// @remarks Optionally, you can also set other properties before you start the process. The SetVerb() property supplies actions to take, such as "print", with the file indicated in the FileName property. The SetArguments() property supplies a way to pass command-line arguments to the file when the system opens it.
        ProcessStartInfo() : createNoWindow(false) {}

        /// @brief Initializes a new instance of the ProcessStartInfo class and specifies a file name such as an application or document with which to start the process.
        /// @param fileName An application or document with which to start a process.
        /// @remarks The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
        /// @remarks You can change the FileName property after you call this constructor, up to the time that the process starts. After you start the process, changing these values has no effect.
        ProcessStartInfo(const String& fileName) : fileName(fileName), createNoWindow(false) {}

        /// @brief Initializes a new instance of the ProcessStartInfo class, specifies an application file name with which to start the process, and specifies a set of command-line arguments to pass to the application.
        /// @param fileName  An application with which to start a process.
        /// @param arguments Command-line arguments to pass to the application when the process starts.
        /// @remarks The file name is any application or document. In this case, a document is defined to be any file type that has an open or default action associated with it. You can view registered file types and their associated applications for your computer by using the Folder Options dialog box, which is available through the operating system. The Advanced button leads to a dialog box that shows whether there is an open action associated with a specific registered file type.
        /// @remarks You can change the FileName or Arguments properties after you call this constructor, up to the time that the process starts. After you start the process, changing these values has no effect.
        ProcessStartInfo(const String& fileName, const String& arguments) : fileName(fileName), arguments(arguments), createNoWindow(false) {}

        /// @brief Sets or Gets the set of command-line arguments to use when starting the application.
        /// @return string File type–specific arguments that the system can associate with the application specified in the FileName property. The default is an empty string (""). On Windows Vista and earlier versions of the Windows operating system, the length of the arguments added to the length of the full path to the process must be less than 2080. On Windows 7 and later versions, the length must be less than 32699.
        Property<const String&> Arguments {
          pcf_get->const string& {return this->arguments;},
          pcf_set {this->arguments = value;}
        };

        /// @brief Gets a value indicating whether to start the process in a new window.
        /// @param createWindow true if the process should be started without creating a new window to contain it; otherwise, false. The default is false.
        /// @return Boolean true if the process should be started without creating a new window to contain it; otherwise, false. The default is false.
        /// @remarks If the UseShellExecute property is true or the UserName and Password properties are not null, the CreateNoWindow property value is ignored and a new window is created.
        Property<bool> CreateNoWindow {
          pcf_get {return this->createNoWindow;},
          pcf_set {this->createNoWindow = value;}
        };

        /// @brief Gets a value that identifies the domain to use when starting the process.
        /// @return string The Active Directory domain to use when starting the process. The domain property is primarily of interest to users within enterprise environments that use Active Directory.
        Property<const String&> Domain {
          pcf_get->const string& {return this->domain;},
          pcf_set {this->domain = value;}
        };

        /// @brief Gets search paths for files, directories for temporary files, application-specific options, and other similar information.
        /// @return Dictionary<string, string> A string dictionary that provides environment variables that apply to this process and child processes. The default is empty.
        /// @remarks Although you cannot set the EnvironmentVariables property, you can modify the StringDictionary returned by the property. For example, the following code adds a TempPath environment variable: myProcess.StartInfo.EnvironmentVariables.Add("TempPath", "C:\\Temp"). You must set the UseShellExecute property to false to start the process after changing the EnvironmentVariables property. If UseShellExecute is true, an InvalidOperationException is thrown when the Start method is called.
        Property<const Collections::Generic::Dictionary<String, String>&> EnvironmentVariables {
          pcf_get->const Collections::Generic::Dictionary<String, String>& {return this->environmentVariables;},
          pcf_set {this->environmentVariables = value;}
        };

        /// @brief Gets the application or document to start.
        Property<const String&> FileName {
          pcf_get->const string& {return this->fileName;},
          pcf_set {this->fileName = value;}
        };

        String ToString() const {return String::Format("{0}{1}{2}", this->fileName, String::IsNullOrEmpty(this->arguments) ? "" :  " ", this->arguments);}

      private:
        String fileName;
        String arguments;
        bool createNoWindow;
        String domain;
        Collections::Generic::Dictionary<String, String> environmentVariables;
      };
    }
  }
}

using namespace Pcf;
