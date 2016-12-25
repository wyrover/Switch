#include <Pcf/Pcf>

using namespace System;

namespace LibGenerator {
  class Program : public object {
  public:
    static int Main(const Array<string>& args) {
      Console::WriteLine("Console application generator version {3}");
      Console::WriteLine();
      
      string projectName;
      string projectPath;
      if (ProcessArguments(args, projectName, projectPath) == false) {
        Console::WriteLine(GetUsage());
        return -1;
      }
      
      string fullPath = IO::Path::Combine(projectPath, projectName);
      string fullSourcePath = IO::Path::Combine(fullPath, "Sources");
      string fullProjectPath = IO::Path::Combine(fullSourcePath, projectName);
      string fullProjectIncludesPath = IO::Path::Combine(fullProjectPath, "Includes");
      string fullProjectSourcesPath = IO::Path::Combine(fullProjectPath, "Sources");
      
      if (IO::Directory::Exists(fullPath)) {
        Console::WriteLine("Project \"{0}\" already exists!", fullPath);
        Console::WriteLine("Aborted.");
        return -2;
      }
      
      IO::Directory::CreateDirectory(fullProjectIncludesPath);
      IO::Directory::CreateDirectory(fullProjectSourcesPath);
      IO::File::WriteAllText(IO::Path::Combine(fullSourcePath, "CMakeLists.txt"), GetSourcePathCMakeLists(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullSourcePath, "Dependences.cmake"), GetSourcePathDependances());
      IO::File::WriteAllText(IO::Path::Combine(fullSourcePath, string::Format("{0}Config.cmake", projectName)), GetSourcePathConfigCMake(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectPath, "CMakeLists.txt"), GetProjectPathCMakeLists(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectIncludesPath, "Class1.h"), GetProjectIncludesPathClass1(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectSourcesPath, "Class1.cpp"), GetProjectSourcesPathClass1(projectName));
      Console::WriteLine("Project \"{0}\" created in \"{1}\".", projectName, fullPath);
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
      "  ConsoleAppGenerator --project_name ProjectName [--project_path ProjectPath]\n"
      "\n"
      "-n, --project_name      : The name of the project that you want create.\n"
      "-p, --project_path      : The path of the project that you want create; if no specified, is equals to \"~/Projects\".\n"
      "-h, --help              : Show this help page.\n";
    }
    
    static string GetSourcePathCMakeLists(const string& projectName) {
      return string::Format("cmake_minimum_required(VERSION 3.0.2)\n"
                            "include(Common NO_POLICY_SCOPE)\n"
                            "set_property(GLOBAL PROPERTY USE_FOLDERS ON)\n"
                            "\n"
                            "project({0} VERSION 1.0.0)\n"
                            "\n"
                            "enable_testing()\n"
                            "set(CMAKE_INSTALL_PREFIX \"${{CMAKE_INSTALL_PREFIX}}/${{PLATFORM_NAME}}/${{PROJECT_NAME}}/${{PROJECT_VERSION}}${{INSTALL_REV}}\")\n"
                            "add_subdirectory(\"{0}\")\n",
                            projectName);
    }
    
    static string GetSourcePathDependances() {
      return "include(Common NO_POLICY_SCOPE)\n"
      "\n"
      "#FindOrInstallPackageFromFtp(MyLib 1.0.0)\n";
    }
    
    static string GetSourcePathConfigCMake(const string& projectName) {
      return string::Format("include(Common NO_POLICY_SCOPE)\n"
                            "GetInstallCompilerSubdir(COMPILER_SUBDIR)\n"
                            "include(${{CMAKE_CURRENT_LIST_DIR}}${{COMPILER_SUBDIR}}/{0}.cmake)\n"
                            "include(${CMAKE_CURRENT_LIST_DIR}/Dependences.cmake)"
                            "set({0}_FOUND TRUE)"
                            "set({1}_FOUND TRUE)",
                            projectName, projectName.ToUpper());
    }
    
    static string GetProjectPathCMakeLists(const string& projectName) {
      return string::Format("include(Common NO_POLICY_SCOPE)\n"
                            "AddTargetPlatformDefinitions()\n"
                            "\n"
                            "# Add include files here:\n"
                            "set(includeFiles ./Includes/Class1.h)\n"
                            "\n"
                            "# Add source files here:\n"
                            "set(sourceFiles ./Sources/Class1.cpp)\n"
                            "\n"
                            "#Add includes directories here:\n"
                            "include_directories()\n"
                            "\n"
                            "#Add source groups here:\n"
                            "source_group(Includes REGULAR_EXPRESSION \"/Includes/[-_,A-Za-z0-9]+\\\\.h*\")\n"
                            "source_group(Sources REGULAR_EXPRESSION \"/Sources/[-_,A-Za-z0-9]+\\\\.c*\")\n"
                            "\n"
                            "add_library({0} STATIC ${{includeFiles}} ${{sourceFiles}})\n"
                            "target_link_libraries({0})\n"
                            "\n"
                            "GetInstallCompilerSubdir(COMPILER_SUBDIR)"
                            "install(EXPORT {0} DESTINATION cmake/${{COMPILER_SUBDIR}})"
                            "install(FILES {0}Config.cmake Dependences.cmake DESTINATION cmake)"
                            "install(TARGETS {0} EXPORT {0} DESTINATION lib/${COMPILER_SUBDIR})"
                            "install(DIRECTORY \"./Includes/.\" DESTINATION include PATTERN \".svn\" EXCLUDE)",
                            projectName);
    }
    
    static string GetProjectIncludesPathClass1(const string& projectName) {
      return string::Format("#pragma once\n"
                            "\n"
                            "namespace {0} {{\n"
                            "  class Class1 {{\n"
                            "  public:\n"
                            "    Class1();\n"
                            "  }};\n"
                            "}}\n", projectName);
    }
    
    static string GetProjectSourcesPathClass1(const string& projectName) {
      return string::Format("#include \"../Includes/Class1.h\"\n"
                            "\n"
                            "using namespace {0};\n"
                            "\n"
                            "Class1::Class1() {{\n"
                            "\n"
                            "}}\n", projectName);
    }
  };
}

pcf_startup (LibGenerator::Program)
