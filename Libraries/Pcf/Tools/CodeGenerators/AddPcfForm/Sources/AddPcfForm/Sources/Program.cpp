#include <Pcf/Pcf>

using namespace System;

namespace AddPcfForm {
  class Program : public object {
  public:
    static int Main(const Array<string>& args) {
      Console::WriteLine("Add Pcf Form version {3}", GetVersion());
      Console::WriteLine();
      
      string projectName;
      string projectPath;
      string formName;
      if (ProcessArguments(args, projectName, projectPath, formName) == false) {
        Console::WriteLine(GetUsage());
        return -1;
      }
      
      string fullPath = IO::Path::Combine(projectPath, projectName);
      string fullSourcePath = IO::Path::Combine(fullPath, "Sources");
      string fullProjectPath = IO::Path::Combine(fullSourcePath, projectName);
      string fullProjectIncludesPath = IO::Path::Combine(fullProjectPath, "Includes");
      string fullProjectSourcesPath = IO::Path::Combine(fullProjectPath, "Sources");
      
      if (! IO::Directory::Exists(fullPath)) {
        Console::WriteLine("Project \"{0}\" not exists!", fullPath);
        Console::WriteLine("Aborted.");
        return -2;
      }
      
      if (! IO::Directory::Exists(fullProjectIncludesPath))
        IO::Directory::CreateDirectory(fullProjectIncludesPath);
      if (! IO::Directory::Exists(fullProjectSourcesPath))
        IO::Directory::CreateDirectory(fullProjectSourcesPath);
      
      if (IO::File::Exists(IO::Path::Combine(fullProjectIncludesPath, string::Format("{0}.h", formName))) || IO::File::Exists(IO::Path::Combine(fullProjectSourcesPath, string::Format("{0}.cpp", formName)))) {
        Console::WriteLine("Class \"{0}\" already exists! in {1}", formName, fullPath);
        Console::WriteLine("Aborted.");
        return -3;
      }

      IO::File::WriteAllText(IO::Path::Combine(fullProjectIncludesPath, string::Format("{0}.h", formName)), GetProjectIncludesPathForm(projectName, formName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectSourcesPath, string::Format("{0}.cpp", formName)), GetProjectSourcesPathForm(projectName, formName));
      IO::File::WriteAllText(IO::Path::Combine(fullProjectSourcesPath, string::Format("{0}.Designer.cpp", formName)), GetProjectSourcesPathFormDesigner(projectName, formName));
      
      string cmakefileText = IO::File::ReadAllText(IO::Path::Combine(fullProjectPath, "CMakeLists.txt"));

      int index = 0;
      
      if ((index = cmakefileText.IndexOf("set(includeFiles")) == -1 || (index = cmakefileText.IndexOf(")", index)) == -1) {
        Console::WriteLine("The file {0} has bad format.", IO::Path::Combine(fullProjectPath, "CMakeLists.txt"));
        Console::WriteLine("Aborted.");
        return -4;
      }
      cmakefileText = cmakefileText.Insert(index, string::Format(" ./Includes/{0}.h", formName));

      if ((index = cmakefileText.IndexOf("set(sourceFiles")) == -1 || (index = cmakefileText.IndexOf(")", index)) == -1) {
        Console::WriteLine("The file {0} has bad format.", IO::Path::Combine(fullProjectPath, "CMakeLists.txt"));
        Console::WriteLine("Aborted.");
        return -5;
      }
      cmakefileText = cmakefileText.Insert(index, string::Format(" ./Sources/{0}.cpp ./Sources/{0}.Designer.cpp", formName));
      
      IO::File::WriteAllText(IO::Path::Combine(fullProjectPath, "CMakeLists.txt"), cmakefileText);
    
      Console::WriteLine("Form \"{0}\" added to project \"{1}\" in \"{2}\".", formName, projectName, fullPath);
      Console::WriteLine("Done.");
      return 0;
    }
    
    static bool ProcessArguments(const Array<string>& args, string& projectName, string& projectPath, string& formName) {
      if (args.Length == 2 && (args[1] == "-h" || args[1] == "--help"))
        return false;
      
      if (args.Length != 3 && args.Length != 5 && args.Length != 7)
        return false;
      
      for (int i = 1; i < args.Length; i += 2) {
        if (args[i] == "-n" || args[i] == "--project_name")
          projectName = args[i + 1];
        else if (args[i] == "-p" || args[i] == "--project_path")
          projectPath = args[i + 1];
        else if (args[i] == "-f" || args[i] == "--form_name")
          formName = args[i + 1];
        else if (args[i] == "-h" || args[i] == "--help")
          return false;
        else
          return false;
      }
      
      if (projectName.IsEmpty())
        return false;

      if (projectPath.IsEmpty())
        projectPath = IO::Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Personal), "Projects");
      
      if (formName.IsEmpty())
        formName = GetFirstFreeFormName(projectPath, projectName);
      
      return true;
    }
    
    static string GetFirstFreeFormName(const string& projectPath, const string& projectName) {
      string fullProjectIncludesPath = IO::Path::Combine(IO::Path::Combine(IO::Path::Combine(IO::Path::Combine(projectPath, projectName), "Sources"), projectName), "Includes");
      string fullProjectSourcesPath = IO::Path::Combine(IO::Path::Combine(IO::Path::Combine(IO::Path::Combine(projectPath, projectName), "Sources"), projectName), "Sources");
      
      int index = 0;
      string formName;
      
      do {
        formName = string::Format("Form{0}", ++index);
      } while (System::IO::File::Exists(System::IO::Path::Combine(fullProjectIncludesPath, string::Format("{0}.h", formName))) || System::IO::File::Exists(System::IO::Path::Combine(fullProjectSourcesPath, string::Format("{0}.cpp", formName))));
      
      return formName;
    }
    
    static string GetUsage() {
      return "Usage\n"
      "\n"
      "  ConsoleAppGenerator --project_name ProjectName [--project_path ProjectPath] [--form_name FormName]\n"
      "\n"
      "-n, --project_name      : The name of the project that you want create.\n"
      "-p, --project_path      : The path of the project that you want create; if no specified, is equals to \"~/Projects\".\n"
      "-f, --form_name         : The name of the form that you want adds; if no specified, is equals to \"Form1\".\n"
      "-h, --help              : Show this help page.\n";
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
                            "target_link_libraries({0})\n",
                            projectName);
    }
    
    static string GetProjectIncludesPathForm(const string& projectName, const string& formName) {
      return string::Format("#pragma once\n"
                            "\n"
                            "#include <Pcf/Pcf>\n"
                            "\n"
                            "namespace {0} {{\n"
                            "  class {1} : public System::Windows::Forms::Form {{\n"
                            "  public:\n"
                            "    {1}();\n"
                            "\n"
                            "  private:\n"
                            "\n"
                            "#pragma PcfGeneratingCode\n"
                            "  private:\n"
                            "    /// @method InitializeComponent\n"
                            "    /// @brief\n"
                            "    /// Required method for Designer support - do not modify\n"
                            "    /// the contents of this method with the editor.\n"
                            "    void InitializeComponent();\n"
                            "\n"
                            "    SharedPointer<System::Windows::Forms::Label> label1;\n"
                            "#pragma EndPcfGeneratingCode\n"
                            "  }};\n"
                            "}}\n",
                            projectName, formName);
    }
    
    static string GetProjectSourcesPathForm(const string& projectName, const string& formName) {
      return string::Format("#include \"../Includes/{1}.h\"\n"
                            "\n"
                            "using namespace System;\n"
                            "using namespace System::Collections::Generic;\n"
                            "using namespace System::Linq;\n"
                            "using namespace System::Threading;\n"
                            "using namespace System::Windows::Forms;\n"
                            "\n"
                            "namespace {0} {{\n"
                            "  {1}::{1}() : Form() {{\n"
                            "    InitializeComponent();\n"
                            "  }}\n"
                            "}}\n",
                            projectName, formName);
   }
    
    static string GetProjectSourcesPathFormDesigner(const string& projectName, const string& formName) {
      return string::Format("#include \"../Includes/{1}.h\"\n"
                            "\n"
                            "namespace {0} {{\n"
                            "  /// @brief Required method for Designer support - do not modify the contents of this method with the editor.\n"
                            "  void {1}::InitializeComponent() {{\n"
                            "    this->label1 = new System::Windows::Forms::Label();\n"
                            "    this->SuspendLayout();\n"
                            "    //\n"
                            "    // label1\n"
                            "    //\n"
                            "    this->label1->Parent(*this);\n"
                            "    this->label1->Text(\"Hello, World!\");\n"
                            "    this->label1->Location(10, 10);\n"
                            "    //\n"
                            "    // {1}\n"
                            "    //\n"
                            "    this->Location(400, 200);\n"
                            "    this->Text(\"{1}\");\n"
                            "    this->ResumeLayout(false);\n"
                            "  }}\n"
                            "}}\n",
                            projectName, formName);
    }
  };
}

pcf_startup (AddPcfForm::Program)

