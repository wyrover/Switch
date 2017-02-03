#pragma once

#include <Pcf/Pcf>
#include "SourceFilesAnalyzerEventArgs.h"

namespace CountsLines {
  typedef System::TEventHandler<SourceFilesAnalyzerEventArgs&> SourceFilesAnalyzerEventHandler;
}