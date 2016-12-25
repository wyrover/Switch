#pragma once

#include <Pcf/Pcf>
#include "Count.h"

namespace CountsLines {
  class FileReport : public object {
  public:
    FileReport() {}
    FileReport(const System::IO::FileInfo& fileInfo, const CountsLines::Counts& counts) : fileInfo(fileInfo), counts(counts) {}
    
    /// @cond
    FileReport(const FileReport& fr) : fileInfo(fr.fileInfo), counts(fr.counts) {}
    FileReport& operator =(const FileReport& fr) {
      this->fileInfo = fr.fileInfo;
      this->counts = fr.counts;
      return *this;
    }
    /// @endcond
    
    Property<System::IO::FileInfo, ReadOnly> FileInfo {
      pcf_get {return this->fileInfo;}
    };
    
    Property<string, ReadOnly> FullName {
      pcf_get {return this->fileInfo.FullName();}
    };
  
    Property<CountsLines::Counts, ReadOnly> Counts {
      pcf_get {return this->counts;}
    };
  
private:
  System::IO::FileInfo fileInfo;
  CountsLines::Counts counts;
};
}