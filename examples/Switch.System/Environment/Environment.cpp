#include <Switch/Switch>

using namespace System;
using namespace System::Collections;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      string str;
      string nl = Environment::NewLine;
      //
      Console::WriteLine();
      Console::WriteLine("-- Environment members --");
      
      //  Invoke this sample with an arbitrary set of command line arguments.
      Console::WriteLine("CommandLine: {0}", Environment::CommandLine);
      
      const Array<string>& arguments = Environment::GetCommandLineArgs();
      Console::WriteLine("GetCommandLineArgs: {0}", string::Join(", ", arguments));
      
      //  <-- Keep this information secure! -->
      Console::WriteLine("CurrentDirectory: {0}", Environment::CurrentDirectory);
      
      Console::WriteLine("ExitCode: {0}", Environment::ExitCode);
      
      Console::WriteLine("HasShutdownStarted: {0}", Environment::HasShutdownStarted);
      
      //  <-- Keep this information secure! -->
      Console::WriteLine("MachineName: {0}", Environment::MachineName);
      
      Console::WriteLine("NewLine: {0}  first line{0}  second line{0}  third line", Environment::NewLine);
      
      Console::WriteLine("OSVersion: {0}", Environment::OSVersion);
      
      Console::WriteLine("StackTrace: '{0}'", Environment::StackTrace);
      
      //  <-- Keep this information secure! -->
      Console::WriteLine("SystemDirectory: {0}", Environment::SystemDirectory);
      
      Console::WriteLine("TickCount: {0}", Environment::TickCount);
      
      //  <-- Keep this information secure! -->
      Console::WriteLine("UserDomainName: {0}", Environment::UserDomainName);
      
      Console::WriteLine("UserInteractive: {0}", Environment::UserInteractive);
      
      //  <-- Keep this information secure! -->
      Console::WriteLine("UserName: {0}", Environment::UserName);
      
      Console::WriteLine("Version: {0}", Environment::Version);
      
      Console::WriteLine("WorkingSet: {0}", Environment::WorkingSet);
      
      //  No example for Exit(exitCode) because doing so would terminate this example.
      
      //  <-- Keep this information secure! -->
      string query = "My home folder is %HOME% and user is %USER%";
      str = Environment::ExpandEnvironmentVariables(query);
      Console::WriteLine("ExpandEnvironmentVariables: {0}  {1}",  nl, str);
      
      Console::WriteLine("GetEnvironmentVariable: {0}  My temporary directory is {1}.", nl,  Environment::GetEnvironmentVariable("TEMP"));
      
      Console::WriteLine("GetEnvironmentVariables: ");
      const Generic::IDictionary<string, string>& environmentVariables = Environment::GetEnvironmentVariables();
      for (Generic::KeyValuePair<string, string> de : environmentVariables) {
        Console::WriteLine(" {0} = {1}", de.Key(), de.Value());
      }
      
      Console::WriteLine("GetFolderPath: {0}", Environment::GetFolderPath(Environment::SpecialFolder::System));
      
      Array<string> drives = Environment::GetLogicalDrives();
      Console::WriteLine("GetLogicalDrives: {0}", string::Join(", ", drives));
    }
  };
}

_startup(Examples::Program);

// This example produces results similar to the following:
// (Any result that is lengthy or reveals information that should remain
// secure has been omitted and marked "!---OMITTED---!".)
//
// -- Environment members --
// CommandLine: Environment.exe ARBITRARY TEXT
// GetCommandLineArgs: Environment.exe, ARBITRARY, TEXT
// CurrentDirectory: F:\Projects\Switch\Bin\VS2012Win64\Debug
// ExitCode: 0
// HasShutdownStarted: False
// MachineName: !---OMITTED---!
// NewLine:
//   first line
//   second line
//   third line
// OSVersion: Microsoft Windows NT 6.1.7601 Service Pack 1
// StackTrace: '   at main
//   at __tmainCRTStartup
//   at mainCRTStartup
//
// SystemDirectory: C:\Windows\system32
// TickCount: 0
// UserDomainName: !---OMITTED---!
// UserInteractive: False
// UserName: !---OMITTED---!
// Version: !---OMITTED---!
// WorkingSet: 0
// ExpandEnvironmentVariables:
//   My system drive is %SystemDrive% and my system root is %SystemRoot%
// GetEnvironmentVariable:
//   My temporary directory is C:\Users\!---OMITTED---!\AppData\Local\Temp.
// GetEnvironmentVariables:
//  !---OMITTED---!
// GetFolderPath: C:\Windows\system32
// GetLogicalDrives: C:\, D:\, E:\, F:\, G:\, L:\, M:\, P:\, S:\, T:\
//

