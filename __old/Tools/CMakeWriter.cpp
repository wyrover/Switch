#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace Tools {
  namespace CMakeWriter {
    class CMakeWriter : public object {
      class Content : public object {
      public:
        Content(const string path, const Collections::Generic::IEnumerable<string>& files) : path(path), files(files) {}

        const string& GetPath() const { return this->path; }
      
        string GetGroupName() const {
          if (String::IsNullOrEmpty(this->path))
            return "sources_files";
        
          return this->path.Replace("/", "_") + "_files";
        }
      
        string GetGroupFiles() const {
          string groupFiles = string::Format("Set({0}\n", GetGroupName());
          for (string file : this->files) {
            groupFiles += string::Format("  ./{0}/{1}\n", this->path, file);
          }
          groupFiles += string::Format(")\n");

          return groupFiles;
        }

        string GetSourcesGroup() const { return string::Format("source_group({0} REGULAR_EXPRESSION \"/{1}/[-_,A-Za-z0-9]+\\\\.(c|C|h|H)*\")\n", this->path.Replace("/", "\\\\"), this->path); }

        const Collections::Generic::IEnumerable<string>& GetFiles() const { return this->files; }

      private:
        const Collections::Generic::IEnumerable<string>& GetFiles() { return this->files; }

        string path;
        Collections::Generic::List<string> files;
      };

    public:
      static int Main(const Array<string>& args) {
        if (args.Length != 1) {
          Console::WriteLine("Usage : CMakeWriter ProjectPath");
          Console::WriteLine("  ProjectPath : absolute or relative path of the project to write CMakeLists.txt");
          return 1;
        }
        
        Tools::CMakeWriter::CMakeWriter cmakeWriter(args[0]);
        cmakeWriter.WriteContent();
        return 0;
      }
      
      CMakeWriter(const string& path) : path(Path::GetFullPath(path)) {
        StreamWriter sw(this->path + Char(Path::DirectorySeparatorChar).ToString() + "CMakeLists.txt", false);
        Console::SetOut(sw);
        if (! this->path.EndsWith(Path::DirectorySeparatorChar))
          this->path += Path::DirectorySeparatorChar;
        ReadDirectories(this->path);
      }
    
      virtual ~CMakeWriter() {
        Console::SetOut(Console::Out);
      }
    
      void WriteContent() const {
        Console::WriteLine(GetCmakeFileTemplate().Replace("<AddProjectName>", GetProjectName()).Replace("<AddGroupFiles>", GetGroupsFiles()).Replace("<AddSourcesGroups>", GetSourcesGroups()).Replace("<AddIncludeDirectories>", GetIncludeDirectories()).Replace("<AddLibrary>", GetLibrary()));
      }
    
    private:
      void ReadDirectories(const string& path) {
        Array<DirectoryInfo> directories = DirectoryInfo(path).GetDirectories();
        for (DirectoryInfo directory : directories) {
          if (! directory.FullName().EndsWith(".svn"))
            ReadDirectories(directory.FullName());
        }

        ReadSourceFiles(path);
      }
    
     void ReadSourceFiles(const string& path) {
       Array<FileInfo> files = DirectoryInfo(path).GetFiles();
       Array<string> fileExtensions = {".h", ".hpp", ".c", ".cpp"};
        Collections::Generic::List<string> fileNames;
       for (FileInfo file : files)
          if (fileExtensions.Contains(file.Extension()))
            fileNames.Add(file.Name());

        if (fileNames.Count != 0)
          this->contents.Add(Content(path.Replace(this->path, "").Replace(Char(Path::DirectorySeparatorChar).ToString(), "/"), fileNames));
      }

    string GetCmakeFileTemplate() const {
      return 
      "cmake_minimum_required(VERSION 2.8.11)\n"
      "\n"
      "SET(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX ../../cmake/CxxFlagsOverride.cmake)\n"
      "\n"
      "include(../../cmake/Os.cmake)\n"
      "\n"
      "project(<AddProjectName>)\n"
      "\n"
      "<AddGroupFiles>\n
      "\n"
      "#Add group for sources\n"
      "<AddSourcesGroups>\n"
      "\n"
      "<AddIncludeDirectories>\n"
      "\n"
      "<AddLibrary>\n"
      "\n"
      "target_link_libraries(\n"
      "  <AddProjectName>\n"
      "  ${ThreadLib}\n"
      "  ${RtLib}\n"
      "  ${DlLib}\n"
      "  ${SocketLib}\n"
      "  ${IphlpapiLib}\n"
      "  ${RpcLib}\n"
      ")\n"
      "\n"
      "#add_dependencies(\n"
      "#  <AddProjectName>\n"
      "#)\n"
      "\n";
     }
    
      string GetGroupsFiles() const {
        string groupsFiles;
        for (Content content : this->contents)
          groupsFiles += string::Format("{0}\n", content.GetGroupFiles());
        return groupsFiles.Remove(groupsFiles.Length()-2);
      }
    
      string GetSourcesGroups() const {
        string sourcesGroups;
        for (Content content : this->contents)
          sourcesGroups += string::Format("{0}", content.GetSourcesGroup());
        return sourcesGroups.Remove(sourcesGroups.Length()-1);
      }
    
      string GetProjectName() const {
        Array<string> paths = this->path.Split(Path::DirectorySeparatorChar);
        return paths.GetValue(paths.Length-1);
      }
    
      string GetIncludeDirectories() const {
        string includeDirectories = "include_directories(\n";
        for (Content content : this->contents)
          includeDirectories += string::Format("  {0}\n", content.GetPath());
        includeDirectories += ")";
        return includeDirectories;
      }
    
      string GetLibrary() const {
        string library = string::Format("add_library(\n  {0} STATIC\n", GetProjectName());
        for (Content content : this->contents)
          library += string::Format("  ${{{0}}}\n", content.GetGroupName());
        library += ")";
        return library;
      }

      string path;
      Collections::Generic::List<Content> contents;
    };
  }
}

pcf_startup (Tools::CMakeWriter::CMakeWriter)
