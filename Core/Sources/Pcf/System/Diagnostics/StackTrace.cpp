#include <call_stack/call_stack.hpp>
#include "../../../../Includes/Pcf/System/Diagnostics/StackTrace.h"
#include "../../../../Includes/Pcf/System/Environment.h"

using namespace System;
using namespace System::Diagnostics;

StackTrace::CallStack::CallStack() {
  this->handle = (intptr)new stacktrace::call_stack();
}

StackTrace::CallStack::~CallStack() {
  delete (stacktrace::call_stack*)this->handle;
}

int32 StackTrace::FrameCount() const {
  return this->frames.Count;
}

void StackTrace::FillFrames(int32 skipFrames, bool needFileInfo) {
  this->stackTrace = SharedPointer<CallStack>::Create();
  FillFrames(((stacktrace::call_stack*)this->stackTrace->handle), skipFrames, needFileInfo);
}

void StackTrace::FillFrames(const String& str, int32 skipFrames, bool needFileInfo) {
  if (skipFrames < 0 )
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  this->stackTrace = SharedPointer<CallStack>::Create();

  int32 skipFramesBeforeStr = 0;
  for (int32 index = 0; index < StackFrame::GetFrameCount(((stacktrace::call_stack*)this->stackTrace->handle)); index++) {
    if (StackFrame(((stacktrace::call_stack*)this->stackTrace->handle), index, needFileInfo).GetMethod().StartsWith(str))
      skipFramesBeforeStr = index;
  }

  FillFrames(((stacktrace::call_stack*)this->stackTrace->handle), skipFrames + skipFramesBeforeStr, needFileInfo);
}

void StackTrace::FillFrames(void* stackTrace, int32 skipFrames, bool needFileInfo) {
  if (skipFrames < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);

  int32 length = skipFrames < StackFrame::GetFrameCount(stackTrace) ? StackFrame::GetFrameCount(stackTrace)-skipFrames : 0;
  for (int32 index = 0; index  < length; index++) {
    if (!StackFrame(stackTrace, index + skipFrames, needFileInfo).GetMethod().StartsWith("System::Delegate<"))
      this->frames.Add(new StackFrame(stackTrace, index + skipFrames, needFileInfo));
  }
}

String StackTrace::ToString() const noexcept {
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

