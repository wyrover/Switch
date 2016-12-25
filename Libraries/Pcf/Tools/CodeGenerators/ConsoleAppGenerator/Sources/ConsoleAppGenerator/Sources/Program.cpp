#include <Pcf/Pcf>

using namespace System;

namespace ConsoleAppGenerator {
  class Program : public object {
  public:
    static int Main(const Array<string>& args) {
      Console::WriteLine("Console application generator version {0}", GetVersion());
      Console::WriteLine();
      
      string name;
      string path;
      if (ProcessArguments(args, name, path) == false) {
        Console::WriteLine(GetUsage());
        return -1;
      }
      
      string fullPath = IO::Path::Combine(path, name);
      string sourcePath = IO::Path::Combine(fullPath, "Sources");
      string projectPath = IO::Path::Combine(sourcePath, name);
      string projectSourcesPath = IO::Path::Combine(projectPath, "Sources");
      
      if (IO::Directory::Exists(fullPath)) {
        Console::WriteLine("Project \"{0}\" already exists!", fullPath);
        Console::WriteLine("Aborted.");
        return -2;
      }
      
      IO::Directory::CreateDirectory(projectSourcesPath);
      IO::File::WriteAllText(IO::Path::Combine(sourcePath, "CMakeLists.txt"), GetSourcePathCMakeLists(name));
      IO::File::WriteAllText(IO::Path::Combine(sourcePath, "Dependences.cmake"), GetSourcePathDependances());
      IO::File::WriteAllText(IO::Path::Combine(projectPath, "CMakeLists.txt"), GetProjectPathCMakeLists(name));
      IO::File::WriteAllText(IO::Path::Combine(projectSourcesPath, "program.cpp"), GetProjectSourcesPathProgram());
      Console::WriteLine("Project \"{0}\" created in \"{1}\".", name, fullPath);
      Console::WriteLine("Done.");
      return 0;
    }
    
    static bool ProcessArguments(const Array<string>& args, string& projectName, string& projectPath) {
      if (args.Length == 2 && (args[1] == "-h" || args[1] == "--help"))
        return false;
      
      if (args.Length != 3 && args.Length != 5)
        return false;
      
      for (int i = 1; i < args.Length; i += 2) {
        if (args[i] == "-n" || args[i] == "--project_name")
          projectName = args[i + 1];
        else if (args[i] == "-p" || args[i] == "--project_path")
          projectPath = args[i + 1];
        else if (args[i] == "-h" || args[i] == "--help")
          return false;
        else
          return false;
      }
      
      if (projectPath.IsEmpty())
        projectPath = IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Projects");
      
      if (projectName.IsEmpty())
        return false;
      return true;
    }
    
    static string GetUsage() {
      return "Usage\n"
      "\n"
      "  ConsoleAppGenerator --project_name ProjectName [--project_path Project/Path]\n"
      "\n"
      "-n, --project_name      : The name of the project that you want create.\n"
      "-p, --project_path      : The path of the project that you want create; if no specified, is equals to \"~/Projects\".\n"
      "-h, --help              : Show this help page.\n";
    }
    
    static string GetSourcePathCMakeLists(const string& name) {
      return string::Format("cmake_minimum_required(VERSION 3.0.2)\n"
                            "include(Common NO_POLICY_SCOPE)\n"
                            "set_property(GLOBAL PROPERTY USE_FOLDERS ON)\n"
                            "\n"
                            "project({0} VERSION 1.0.0)\n"
                            "enable_testing()\n"
                            "add_subdirectory(\"{0}\")\n",
                            name);
    }
    
    static string GetSourcePathDependances() {
      return "include(Common NO_POLICY_SCOPE)\n"
      "\n"
      "#FindOrInstallPackageFromFtp(MyLib 1.0.0)\n";
    }
    
    static string GetProjectPathCMakeLists(const string& name) {
      return string::Format("include(Common NO_POLICY_SCOPE)\n"
                            "AddTargetPlatformDefinitions()\n"
                            "\n"
                            "# Add include files here:\n"
                            "set(includeFiles)\n"
                            "\n"
                            "# Add source files here:\n"
                            "set(sourceFiles ./Sources/Program.cpp)\n"
                            "\n"
                            "#Add includes directories here:\n"
                            "include_directories()\n"
                            "\n"
                            "#Add source groups here:\n"
                            "source_group(Includes REGULAR_EXPRESSION \"/Includes/[-_,A-Za-z0-9]+\\\\.h*\")\n"
                            "source_group(Sources REGULAR_EXPRESSION \"/Sources/[-_,A-Za-z0-9]+\\\\.c*\")\n"
                            "\n"
                            "add_executable({0} ${{includeFiles}} ${{sourceFiles}})\n"
                            "target_link_libraries({0})\n",
                            name);
    }
    
    static string GetProjectSourcesPathProgram() {
      return "#include <iostream>\n"
      "\n"
      "using namespace std;\n"
      "\n"
      "/// @brief The main entry point for the application\n"
      "int main(int argc, char* argv[]) {\n"
      "  cout << \"Hello, World!\" << endl;\n"
      "  return 0;\n"
      "}\n";
    }
  };
}

pcf_startup (ConsoleAppGenerator::Program);
