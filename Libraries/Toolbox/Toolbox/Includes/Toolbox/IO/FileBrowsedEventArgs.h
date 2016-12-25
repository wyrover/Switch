#pragma once

#include <Pcf/Pcf>

namespace Pcf {
  namespace Toolbox {
    namespace IO {
      class FileBrowsedEventArgs : public System::EventArgs {
      public:
        FileBrowsedEventArgs(const System::IO::FileInfo& fileInfo, int32 index, int32 count) : fileInfo(fileInfo), index(index), count(count) {}
        
        /// @cond
        FileBrowsedEventArgs(const FileBrowsedEventArgs& fbe) : cancel(fbe.cancel), fileInfo(fbe.fileInfo), index(fbe.index), count(fbe.count) {}
        FileBrowsedEventArgs& operator =(const FileBrowsedEventArgs& fbe)  {
          this->cancel = fbe.cancel;
          this->fileInfo = fbe.fileInfo;
          this->index = fbe.index;
          this->count = fbe.count;
          return *this;
        }
        /// @endcond
        
        Property<bool> Cancel {
          pcf_get {return this->cancel;},
          pcf_set {this->cancel = value;}
        };
        
        Property<System::IO::FileInfo, ReadOnly> FileInfo {
          pcf_get {return this->fileInfo;}
        };
        
        Property<string, ReadOnly> FullName {
          pcf_get {return this->fileInfo.FullName();}
        };
        
        Property<int32, ReadOnly> Index {
          pcf_get {return this->index;}
        };
        
        Property<int32, ReadOnly> Count {
          pcf_get {return this->count;}
        };
        
      private:
        bool cancel = false;
        System::IO::FileInfo fileInfo;
        int32 index = 0;
        int32 count = 0;
      };
      
      typedef System::TEventHandler<FileBrowsedEventArgs&> FileBrowsedEventHandler;
      
      class FileBrowser : public object {
      public:
        FileBrowser(const string& path) : path(System::IO::Path::GetFullPath(path)) {}
        FileBrowser(const string& path, bool recursive) : path(System::IO::Path::GetFullPath(path)), recursive(recursive) {}
        FileBrowser(const string& path, const System::Array<string>& fileExtensionsFilter) : path(System::IO::Path::GetFullPath(path)), fileExtensionsFilter(fileExtensionsFilter) {}
        FileBrowser(const string& path, const System::Array<string>& fileExtensionsFilter, bool recursive) : path(System::IO::Path::GetFullPath(path)), fileExtensionsFilter(fileExtensionsFilter), recursive(recursive) {}
        
        Property<string, ReadOnly> Path {
          pcf_get {return this->path;}
        };
        
        Property<System::Array<string>, ReadOnly> FileExtensionsFilter {
          pcf_get {return this->fileExtensionsFilter;}
        };
        
        Property<bool, ReadOnly> IsRecursive {
          pcf_get {return this->recursive;}
        };
        
        FileBrowsedEventHandler BrowsedFile;
        
        void Browse() {
          this->cancel = false;
          this->count = Count();
          this->index = 0;
          ReadDirectories(this->path); }
        
        int32 Count() { return CountDirectories(this->path); }
        
      private:
        int32 count;
        int32 index;
        
        void ReadDirectories(const string& path) {
          if (this->recursive) {
            for (const string& directory : System::IO::Directory::EnumerateDirectories(path)) {
              ReadDirectories(directory);
              if (this->cancel)
                break;
            }
          }
          
          ReadFiles(path);
        }
        
        void ReadFiles(const string& path) {
          for (const string& file : System::IO::Directory::EnumerateFiles(path)) {
            if (fileExtensionsFilter.Contains(".*") || fileExtensionsFilter.Contains(System::IO::Path::GetExtension(file))) {
              FileBrowsedEventArgs fileBrowsedEventArgs(System::IO::FileInfo(file), ++this->index, this->count);
              this->BrowsedFile.Invoke(*this, fileBrowsedEventArgs);
              this->cancel = fileBrowsedEventArgs.Cancel();
              if (this->cancel)
                break;
            }
          }
        }
        
        int32 CountDirectories(const string& path) {
          int32 count = 0;
          if (this->recursive) {
            for(const string& directory : System::IO::Directory::EnumerateDirectories(path))
              count += CountDirectories(directory);
          }
          return count + CountFiles(path);
        }
        
        int32 CountFiles(const string& path) {
          int32 count = 0;
          for(const string& file : System::IO::Directory::EnumerateFiles(path)) {
            if (fileExtensionsFilter.Contains(".*") || fileExtensionsFilter.Contains(System::IO::Path::GetExtension(file)))
              count++;
          }
          return count;
        }
        
        
        bool cancel = false;
        string path;
        System::Array<string> fileExtensionsFilter {".*"};
        bool recursive = true;
      };
    }
  }
}
