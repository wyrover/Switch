#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;

namespace Tools {
  class FileBrowsedEventArgs : public EventArgs {
  public:
    FileBrowsedEventArgs(const string& fullName) : cancel(false), fullName(fullName) {}
    FileBrowsedEventArgs(const FileBrowsedEventArgs& fbe) : cancel(fbe.cancel), fullName(fbe.fullName) {}
    
    bool Cancel() const {return this->cancel;}
    void Cancel(bool cancel) {this->cancel = cancel;}
    const string& FullName() const {return this->fullName;}
    
  private:
    bool cancel;
    string fullName;
  };
  
  using FileBrowsedEventHandler = System::TEventHandler<FileBrowsedEventArgs&>;
  
  class FileBrowser : public object {
  public:
    FileBrowser(const string& path) : cancel(false), path(Path::GetFullPath(path)), fileExtensionsFilter({".*"}) {}
    FileBrowser(const string& path, const Array<string>& fileExtensionsFilter) : cancel(false), path(Path::GetFullPath(path)), fileExtensionsFilter(fileExtensionsFilter) {}
    
    const string& Path() const {return this->path;}
    
    const Array<string>& FileExtensionsFilter() const {return this->fileExtensionsFilter;}
    
    FileBrowsedEventHandler& FileBrowsed() {return this->fileBrowsed;}
    
    void Browse() {ReadDirectories(this->path);}
    
  private:
    void ReadDirectories(const string& path) {
      this->cancel = false;
      Array<DirectoryInfo> directories = DirectoryInfo(path).GetDirectories();
      for (DirectoryInfo directory : directories) {
        ReadDirectories(directory.FullName());
        if (this->cancel)
          return;
      }
      
      ReadFiles(path);
    }
    
    void ReadFiles(const string& path) {
      Array<FileInfo> files = DirectoryInfo(path).GetFiles();
      for (FileInfo file : files) {
        if (fileExtensionsFilter.Contains(".*") || fileExtensionsFilter.Contains(file.Extension())) {
          FileBrowsedEventArgs fileBrowsedEventArgs(Path::Combine(path, file.Name()));
          this->fileBrowsed.Invoke(*this, fileBrowsedEventArgs);
          this->cancel = fileBrowsedEventArgs.Cancel();
          if (this->cancel)
            return;
        }
      }
    }
    
    bool cancel;
    string path;
    Array<string> fileExtensionsFilter;
    FileBrowsedEventHandler fileBrowsed;
  };
  
  namespace DoxygenCommentConverter {
    class DoxygenCommentConverter : public object {
    public:
      static int Main(const Array<string>& args) {
        if (args.Length != 1) {
          Console::WriteLine("Usage : DoxygenCommentConverter ProjectPath");
          Console::WriteLine("  ProjectPath : absolute or relative path of the project to convert Doxygen comment");
          return 1;
        }
        
        DoxygenCommentConverter(args[0]).Convert();
        return 0;
      }
      
      DoxygenCommentConverter(const string& path) : fileBrowser(path, {".h", ".hpp"}), countFileConverted(0), cancel(false) {
        this->fileBrowser.FileBrowsed() += FileBrowsedEventHandler(*this, &DoxygenCommentConverter::OnFileBrowsed);
      }
      
      void Convert() {
        fileBrowser.Browse();
        Console::WriteLine("{0} files converted", this->countFileConverted);
      }
      
    private:
      void OnFileBrowsed(const object& sender, FileBrowsedEventArgs& e) {
        this->countFileConverted++;
        Console::WriteLine("Convert {0}...", e.FullName());
        System::Collections::Generic::List<string> lines(File::ReadAllLines(e.FullName()));
        File::WriteAllLines(e.FullName(), ConvertText(lines));
        if (this->cancel)
          e.Cancel(true);
      }
      
      Array<string> ConvertText(System::Collections::Generic::List<string>& lines) {
        System::Collections::Generic::List<int> linesToRemoved;
        int lineIndex = 0;
        bool isComment = false;
        string tag;
        
        for (string& line : lines) {
          line = line.TrimEnd(' ');
          
          if (line.EndsWith("/**")) {
            isComment = true;
            tag = "@brief";
            linesToRemoved.Add(lineIndex++);
            continue;
          } else if (isComment && line.EndsWith("*/")) {
            isComment = false;
            linesToRemoved.Add(lineIndex++);
            continue;
          } else if (line.EndsWith("@note")) {
            tag = "@note";
            linesToRemoved.Add(lineIndex++);
            continue;
          } else if (line.EndsWith("@warning")) {
            tag = "@warning";
            linesToRemoved.Add(lineIndex++);
            continue;
          } else if (line.EndsWith("@remarks")) {
            tag = "@remarks";
            linesToRemoved.Add(lineIndex++);
            continue;
          } else if (line.EndsWith("@return")) {
            tag = "@return";
            linesToRemoved.Add(lineIndex++);
            continue;
          } else if (line.EndsWith("@param")) {
            tag = "@param";
            linesToRemoved.Add(lineIndex++);
            continue;
          }
          
          if (isComment) {
            if (line.EndsWith(" *"))
              linesToRemoved.Add(lineIndex);
            else if (line.Contains(" * |"))
              line = string::Format("{0}/// |{1}", string(' ', line.IndexOf(" * |")), line.Substring(line.IndexOf(" * |")+4));
            else if (line.Contains(" * *"))
              line = string::Format("{0}/// *{1}", string(' ', line.IndexOf(" * *")), line.Substring(line.IndexOf(" * *")+4));
            else if (line.Contains(" * -"))
              line = string::Format("{0}/// -{1}", string(' ', line.IndexOf(" * -")), line.Substring(line.IndexOf(" * -")+4));
            else if (line.Contains(" *  -"))
              line = string::Format("{0}///  -{1}", string(' ', line.IndexOf(" *  -")), line.Substring(line.IndexOf(" *  -")+5));
            else if (line.Contains(" *   -"))
              line = string::Format("{0}///   -{1}", string(' ', line.IndexOf(" *   -")), line.Substring(line.IndexOf(" *   -")+6));
            else if (line.Contains(" *    -"))
              line = string::Format("{0}///    -{1}", string(' ', line.IndexOf(" *    -")), line.Substring(line.IndexOf(" *    -")+7));
            else if (line.Contains(" *     -"))
              line = string::Format("{0}///     -{1}", string(' ', line.IndexOf(" *     -")), line.Substring(line.IndexOf(" *     -")+8));
            else if (line.Contains(" *      -"))
              line = string::Format("{0}///      -{1}", string(' ', line.IndexOf(" *      -")), line.Substring(line.IndexOf(" *      -")+9));
            else if (tag != string::Empty  && line.Contains(" * "))
              line = string::Format("{0}/// {1} {2}", string(' ', line.IndexOf(" * ")), tag, line.Substring(line.IndexOf(" * ")+3));
            else if (tag != string::Empty  && line.Contains(" *"))
              line = string::Format("{0}/// {1} {2}", string(' ', line.IndexOf(" *")), tag, line.Substring(line.IndexOf(" *")+2));
            else if (line.Contains(" *"))
              line = string::Format("{0}///{1}", string(' ', line.IndexOf(" *")), line.Substring(line.IndexOf(" *")+2));
            
            if (tag == "@brief")
              tag = "";
          }
          
          if (line.Contains("/// @cond DEV"))
            line = line.Remove(line.IndexOf(" DEV"));
          
          lineIndex++;
        }
        
        if (linesToRemoved.Count > 0)
          for(int i = linesToRemoved.Count-1; i >= 0; --i) {
            lines.RemoveAt(linesToRemoved[i]);
          }
        
        return lines.ToArray();
      }
      
      FileBrowser fileBrowser;
      int countFileConverted;
      bool cancel;
    };
  }
}

pcf_startup (Tools::DoxygenCommentConverter::DoxygenCommentConverter)
