#include "../../../../Includes/Pcf/System/Diagnostics/StackTrace.h"
#include "../../../../Includes/Pcf/System/Environment.h"

using namespace System;
using namespace System::Diagnostics;

int32 StackTrace::FrameCount() const {
  return this->frames.Count;
}

void StackTrace::FillFrames(int32 skipFrames, bool needFileInfo) {
  this->stackTrace = new stacktrace::call_stack();
  FillFrames(this->stackTrace.ToPointer(), skipFrames, needFileInfo);
}

void StackTrace::FillFrames(const String& str, int32 skipFrames, bool needFileInfo) {
  if (skipFrames < 0 )
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  this->stackTrace = UniquePointer<stacktrace::call_stack>::Create();

  int32 skipFramesBeforeStr = 0;
  for (int32 index = 0; index < StackFrame::GetFrameCount(this->stackTrace.ToPointer()); index++) {
    if (StackFrame(this->stackTrace.ToPointer(), index, needFileInfo).GetMethod().StartsWith(str))
      skipFramesBeforeStr = index;
  }

  FillFrames(this->stackTrace.ToPointer(), skipFrames + skipFramesBeforeStr, needFileInfo);
}

void StackTrace::FillFrames(void* stackTrace, int32 skipFrames, bool needFileInfo) {
  if (skipFrames < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);

  int32 length = skipFrames < StackFrame::GetFrameCount(stackTrace) ? StackFrame::GetFrameCount(stackTrace)-skipFrames : 0;
  for (int32 index = 0; index  < length; index++) {
    if (!StackFrame(stackTrace, index + skipFrames, needFileInfo).GetMethod().StartsWith("Pcf::FunctionPointer<") && !StackFrame(stackTrace, index + skipFrames, needFileInfo).GetMethod().StartsWith("System::Delegate<"))
      this->frames.Add(new StackFrame(stackTrace, index + skipFrames, needFileInfo));
  }
}

String StackTrace::ToString() const {
  String str;
  bool first = true;
  for (SharedPointer<StackFrame> item : this->frames) {
    if (!first) str += Environment::NewLine;
    str += "   at "_s + item->GetMethod() ;
    if (!String::IsNullOrEmpty(item->GetFileName())) {
      str+= " [0x"_s + Int32(item->GetOffset()).ToString("X8") + "] in "_s + item->GetFileName() + ":"_s + item->GetFileLineNumber();
    }
    first = false;
  }
  return  str;
}

