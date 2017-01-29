#pragma once

#include <Pcf/Pcf>
#include "FileReportCollection.h"

namespace CountsLines {
  class SourceFilesReport : public object {
  public:
    SourceFilesReport() {}
    
    SourceFilesReport(const CountsLines::Counts& counts, const CountsLines::FileReportCollection& fileReports) : counts(counts), fileReports(fileReports) {}
    
    /// @cond
    SourceFilesReport(const SourceFilesReport& filesReport) : counts(filesReport.counts), fileReports(filesReport.fileReports) {}
    SourceFilesReport& operator =(const SourceFilesReport& filesReport) {
      this->counts = filesReport.counts;
      this->fileReports = filesReport.fileReports;
      return *this;
    }
    /// @endcond
    
    Property<CountsLines::Counts, ReadOnly> Counts {
      pcf_get {return this->counts;}
    };
    
    Property<CountsLines::FileReportCollection, ReadOnly> FileReports {
      pcf_get {return this->fileReports;}
    };
    
  private:
    CountsLines::Counts counts;
    CountsLines::FileReportCollection fileReports;
  };
}