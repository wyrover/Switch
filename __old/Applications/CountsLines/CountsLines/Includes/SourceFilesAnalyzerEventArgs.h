#pragma once

#include <Pcf/Toolbox>
#include "FileReport.h"

namespace CountsLines {
  class SourceFilesAnalyzerEventArgs : public Toolbox::IO::FileBrowsedEventArgs {
  public:
    SourceFilesAnalyzerEventArgs(const System::IO::FileInfo& fileInfo, int index, int count, const CountsLines::FileReport& fileReport) : Toolbox::IO::FileBrowsedEventArgs(fileInfo, index, count), fileReport(fileReport) {}
    
    SourceFilesAnalyzerEventArgs(Toolbox::IO::FileBrowsedEventArgs& fbe, const CountsLines::FileReport& fileReport) : Toolbox::IO::FileBrowsedEventArgs(fbe), fileReport(fileReport) {}
    
    SourceFilesAnalyzerEventArgs(const SourceFilesAnalyzerEventArgs& cea) : Toolbox::IO::FileBrowsedEventArgs(cea), fileReport(cea.fileReport) {}
    
    Property<CountsLines::FileReport, ReadOnly> FileReport {
      pcf_get {return this->fileReport;}
    };
    
  private:
    CountsLines::FileReport fileReport;
  };
}