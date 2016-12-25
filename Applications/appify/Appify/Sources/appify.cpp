#include <Pcf/Pcf>

using namespace System;

namespace Pcf {
  namespace Appify {
    class AppleApplicationCreator : public object {
    public:
      static void Main(const Array<string>& args) {
        string applicationName, applicationFile, outputDirectory, iconFile;
        System::Collections::Generic::List<string> resourceFiles;
        
        ProcessArguments(args, applicationName, applicationFile, outputDirectory, iconFile, resourceFiles);
        CreatePackage(applicationName, applicationFile, outputDirectory, iconFile, resourceFiles.ToArray());
      }
      
    private:
      static void CreatePackage(const string& applicationName, const string& applicationFile, const string& outputDirectory, const string& iconFile, const Array<string>& resourceFiles) {
        string path = System::IO::Path::Combine(outputDirectory, string::Format("{0}.app", applicationName));
        if (System::IO::Directory::Exists(path))
          System::IO::Directory::Delete(path, true);
        System::IO::Directory::CreateDirectory(System::IO::Path::Combine(path, "Contents", "MacOS"));
        System::IO::Directory::CreateDirectory(System::IO::Path::Combine(path, "Contents", "Resources"));
        
        System::IO::File::WriteAllText(System::IO::Path::Combine(path, "Contents", "Info.plist"), ToPlist(System::IO::Path::GetFileName(applicationFile), System::IO::Path::GetFileName(iconFile)));
        
        System::IO::File::Copy(applicationFile, System::IO::Path::Combine(path, "Contents", "MacOS", System::IO::Path::GetFileName(applicationFile)));
        System::Diagnostics::Process::Start("chmod", string::Format("+x {0}", System::IO::Path::Combine(path, "Contents", "MacOS", System::IO::Path::GetFileName(applicationFile))));
        
        if (!iconFile.IsEmpty())
          System::IO::File::Copy(iconFile, System::IO::Path::Combine(path, "Contents", "Resources", System::IO::Path::GetFileName(iconFile)));
        
        for (string resourceFile : resourceFiles)
          System::IO::File::Copy(resourceFile, System::IO::Path::Combine(path, "Contents", "Resources", System::IO::Path::GetFileName(resourceFile)));
      }
      
      static void ProcessArguments(const Array<string>& args, string& applicationName, string& applicationFile, string& outputDirectory, string& iconFile, System::Collections::Generic::List<string>& resourceFiles) {
        if (args.Length == 1 && (args[0] == "-v" || args[0] == "--version"))
          ShowVersion();
        
        if ((args.Length == 1 && (args[0] == "-h" || args[0] == "--help")) || !(args.Length >= 4 && args.Length % 2 == 0) || !(args.Contains("-n") || args.Contains("--application_name")) || !(args.Contains("-a") || args.Contains("--application_file")))
          ShowUsage();
        
        for (int i = 0; i < args.Length; i += 2) {
          if (args[i] == "-n" || args[i] == "--application_name")
            applicationName = args[i + 1];
          else if (args[i] == "-a" || args[i] == "--application_file")
            applicationFile = System::IO::Path::GetFullPath(args[i + 1]);
          else if (args[i] == "-o" || args[i] == "--output_directory")
            outputDirectory = System::IO::Path::GetFullPath(args[i + 1]);
          else if (args[i] == "-i" || args[i] == "--icon_file")
            iconFile = System::IO::Path::GetFullPath(args[i + 1]);
          else if (args[i] == "-r" || args[i] == "--resource_file")
            resourceFiles.Add(System::IO::Path::GetFullPath(args[i + 1]));
          else
            ShowUsage();
        }
      }
      
      static void ShowUsage() {
        Console::WriteLine("Usage\n"
                           "\n"
                           "  appify --application_name ApplicationName --application_file ApplicationFile [--output_directory OutputDirectory] [--icon_file IconFile] [--resource_file ResourceFile1] [--resource_file ResourceFile2] [--resource_file ...]\n"
                           "\n"
                           "-n, --application_name    : The application name.\n"
                           "-a, --application_file    : The application to appify.\n"
                           "-o, --output_directory    : The output directory.\n"
                           "-i, --icon_file           : The icon filename.\n"
                           "-r, --resource_file       : The Additional files to bundle.\n"
                           "-h, --help                : Show this help page.\n"
                           "-v, --version             : Show appify version.\n");
        Environment::Exit(1);
      }
      
      static void ShowVersion() {
        Console::WriteLine("appify version 0.1.0, Copyright GAMMA Soft, 2016.\n");
        Environment::Exit(1);
      }

      static string ToPlist(const string& applicationFile, const string& iconFile) {
        return string::Format("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                              "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
                              "<plist version=\"1.0\">\n"
                              "<dict>\n"
                              "\t<key>CFBundleIdentifier</key>\n"
                              "\t<string>{0}</string>\n"
                              "\t<key>CFBundleExecutable</key>\n"
                              "\t<string>{0}</string>\n"
                              "\t<key>CFBundleIconFile</key>\n"
                              "\t<string>{1}</string>\n"
                              "</dict>\n"
                              "</plist>\n", applicationFile, iconFile);
      }
    };
  }
}

pcf_startup (Appify::AppleApplicationCreator)
