#include <Pcf/Pcf>

using namespace System;

namespace PcfFormsAppGenerator {
  class Program : public object {
  public:
    static int Main(const Array<string>& args) {
      Console::WriteLine("Pcf Forms application generator version {0}", GetVersion());
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
      IO::File::WriteAllText(IO::Path::Combine(fullProjectPath, "CMakeLists.txt"), GetProjectPathCMakeLists(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectIncludesPath, "Form1.h"), GetProjectIncludesPathForm1(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectSourcesPath, "Form1.cpp"), GetProjectSourcesPathForm1(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectSourcesPath, "Form1.Designer.cpp"), GetProjectSourcesPathForm1Designer(projectName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectSourcesPath, "program.cpp"), GetProjectSourcesPathProgram(projectName));
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
      "  ConsoleAppGenerator --project_name ProjectName [--project_path Project/Path]\n"
      "\n"
      "-n, --project_name      : The name of the project that you want create.\n"
      "-p, --project_path      : The path of the project that you want create; if no specified, is equals to \"~/Projects\".\n"
      "-h, --help              : Show this help page.\n";
    }
    
    static string GetSourcePathCMakeLists(const string& projectPath) {
      return string::Format("cmake_minimum_required(VERSION 3.0.2)\n"
                            "include(Common NO_POLICY_SCOPE)\n"
                            "set_property(GLOBAL PROPERTY USE_FOLDERS ON)\n"
                            "\n"
                            "project({0} VERSION 1.0.0)\n"
                            "include(Dependences.cmake)\n"
                            "\n"
                            "enable_testing()\n"
                            "AddTargetPlatformDefinitions()\n"
                            "GetInstallDirectory({0} {0}_INSTALL_DIR)\n"
                            "GetInstallCompilerSubdir(COMPILER_SUBDIR)\n"
                            "endif()\n"
                            "  set({0}_INSTALL_LIB_DIR  \"${{{0}_INSTALL_DIR}}/bin/${{COMPILER_SUBDIR}}\")\n"
                            "\n"
                            "add_subdirectory(\"{0}\")\n",
                            projectPath);
    }
    
    static string GetSourcePathDependances() {
      return string::Format("include(Common NO_POLICY_SCOPE)\n"
                            "\n"
                            "FindOrInstallPackageFromFtp(PcfFramework {0})\n",
                            GetVersion());
    }
    
    static string GetProjectPathCMakeLists(const string& projectPath) {
      return string::Format("include(Common NO_POLICY_SCOPE)\n"
                            "AddTargetPlatformDefinitions()\n"
                            "AddGuiLinkerDefinitions()\n"
                            "\n"
                            "# Add include files here:\n"
                            "set(includeFiles ./Includes/Form1.h)\n"
                            "\n"
                            "# Add source files here:\n"
                            "set(sourceFiles ./Sources/Form1.cpp ./Sources/Form1.Designer.cpp ./Sources/Program.cpp)\n"
                            "\n"
                            "#Add includes directories here:\n"
                            "include_directories(${{PCFFORMS_INCLUDE_DIRS}})\n"
                            "\n"
                            "#Add source groups here:\n"
                            "source_group(Includes REGULAR_EXPRESSION \"/Includes/[-_,A-Za-z0-9]+\\\\.h*\")\n"
                            "source_group(Sources REGULAR_EXPRESSION \"/Sources/[-_,A-Za-z0-9]+\\\\.c*\")\n"
                            "\n"
                            "add_executable({0} WIN32 ${{includeFiles}} ${{sourceFiles}})\n"
                            "target_link_libraries({0} ${{PCFFORMS_LIBRARIES}})\n",
                            projectPath);
    }
    
    static string GetProjectIncludesPathForm1(const string& projectName) {
      return string::Format("#pragma once\n"
                            "\n"
                            "#include <Pcf/Pcf>\n"
                            "\n"
                            "namespace {0} {{\n"
                            "  class Form1 : public System::Windows::Forms::Form {{\n"
                            "  public:\n"
                            "    Form1();\n"
                            "\n"
                            "  private:\n"
                            "\n"
                            "#define PcfGeneratingCode\n"
                            "  private:\n"
                            "    /// @method InitializeComponent\n"
                            "    /// @brief\n"
                            "    /// Required method for Designer support - do not modify\n"
                            "    /// the contents of this method with the editor.\n"
                            "    void InitializeComponent();\n"
                            "\n"
                            "    System::Windows::Forms::Label label1;\n"
                            "#undef EndPcfGeneratingCode\n"
                            "  }};\n"
                            "}}\n",
                            projectName);
    }
    
    static string GetProjectSourcesPathForm1(const string& projectName) {
      return string::Format("#include \"../Includes/Form1.h\"\n"
                            "\n"
                            "using namespace System;\n"
                            "using namespace System::Collections::Generic;\n"
                            "using namespace System::Linq;\n"
                            "using namespace System::Threading;\n"
                            "using namespace System::Windows::Forms;\n"
                            "\n"
                            "namespace {0} {{\n"
                            "  Form1::Form1() : Form() {{\n"
                            "    InitializeComponent();\n"
                            "  }}\n"
                            "}}\n",
                            projectName);
    }
    
    static string GetProjectSourcesPathForm1Designer(const string& projectName) {
      return string::Format("#include \"../Includes/Form1.h\"\n"
                            "\n"
                            "namespace {0} {{\n"
                            "  /// @brief\n"
                            "  /// Required method for Designer support - do not modify\n"
                            "  /// the contents of this method with the editor.\n"
                            "  void Form1::InitializeComponent() {{\n"
                            "    this->SuspendLayout();\n"
                            "    //\n"
                            "    // label1\n"
                            "    //\n"
                            "    this->label1.Parent = *this;\n"
                            "    this->label1.Text = \"Hello, World!\";\n"
                            "    this->label1.Font = System::Drawing::Font(\"Arial\", 46, System::Drawing::FontStyle::Bold|System::Drawing::FontStyle::Italic);\n",
                            "    this->label1.Location = System::Drawing::Point(10, 10);\n"
                            "    //\n"
                            "    // Form1\n"
                            "    //\n"
                            "    this->Location = System::Drawing::Point(400, 200);\n"
                            "    this->Text = \"Form1\";\n"
                            "    this->ResumeLayout(false);\n"
                            "  }}\n"
                            "}}\n",
                            projectName);
    }
    
    static string GetProjectSourcesPathProgram(const string& projectName) {
      return string::Format("#include \"../Includes/Form1.h\"\n"
                            "\n"
                            "using namespace System;\n"
                            "using namespace System::Collections::Generic;\n"
                            "using namespace System::Linq;\n"
                            "using namespace System::Threading;\n"
                            "using namespace System::Windows::Forms;\n"
                            "\n"
                            "namespace {0} {\n"
                            "  class Program {\n"
                            "  public:\n"
                            "    /// @brief The main entry point for the application\n"
                            "    static void Main() {{\n"
                            "      Application::EnableVisualStyles();\n"
                            "      Application::Run({0}::Form1());\n"
                            "    }}\n",
                            "  }};\n",
                            "}}\n",
                            "\n",
                            "pcf_startup ({0}::Program)\n",
                            projectName);
    }
  };
}

pcf_startup (PcfFormsAppGenerator::Program)
