#include "../../../Includes/Pcf/System/Exception.h"
#include "../../../Includes/Pcf/System/Environment.h"
#include "../../../Includes/Pcf/System/Diagnostics/StackTrace.h"

using namespace System;

bool Exception::stackTraceEnabled = true;

const string& Exception::GetMessage() const {
  if (string::IsNullOrEmpty(this->message))
    const_cast<Exception*>(this)->message = GetDefaultMessage();
  return this->message;
}

string Exception::GetStackTrace() const {
  if (this->stackTrace.IsNull() || this->stackTrace().Length == 0)
    return "";
  
  return string::Join("\n", this->stackTrace());
}

Exception::Exception() : currentInformation(pcf_current_information) {
  SetStackTrace(*this);
}

Exception::Exception(const Exception& value) {
  message = value.message;
  helpLink = value.helpLink;
  currentInformation = value.currentInformation;
  innerException = value.innerException;
  hresult = value.hresult;
  stackTrace = value.stackTrace;
}

Exception::Exception(const CurrentInformation& information) : currentInformation(information),
hresult(0) {
  SetStackTrace(*this);
}

Exception::Exception(const string& message) : message(message), currentInformation(pcf_current_information) {
  SetStackTrace(*this);
}

Exception::Exception(const string& message, const CurrentInformation& information) : message(message), currentInformation(information) {
  SetStackTrace(*this);
}

Exception::Exception(const string& message, const Exception& innerExeption, const CurrentInformation& information) : message(message), currentInformation(information), innerException(innerExeption) {
  SetStackTrace(*this);
}

Exception::~Exception() noexcept {
}

bool Exception::Equals(const Exception& value) const {
  return this->hresult == value.hresult && this->message == value.message && this->currentInformation == value.currentInformation && this->innerException == value.innerException;
}

bool Exception::Equals(const object& obj) const noexcept {
  return is<Exception>(obj) && Equals(static_cast<const Exception&>(obj));
}

string Exception::ToString() const noexcept {
  return string::Format("{0}: {1}{2}{3}", GetType(), GetMessage(), Environment::NewLine, GetStackTrace(GetType().ToString()));
}

Exception& Exception::operator =(const Exception& value) {
  message = value.message;
  currentInformation = value.currentInformation;
  innerException = value.innerException;
  hresult = value.hresult;

  return *this;
}

string Exception::GetDefaultMessage() const {
  return string::Format("Exception of type '{0}' was thrown.", GetType());
}

void Exception::SetStackTrace(const Exception& exception) {
  if (Exception::stackTraceEnabled == false) {
    this->stackTrace = SharedPointer<Array<string>>::Create(1);
    stackTrace()[0] = String::Format("  in {0}:{1}{2}", this->currentInformation.FileName, this->currentInformation.Line, Environment::NewLine);
    return;
  }
  
  Diagnostics::StackTrace st(1, true);
  this->stackTrace = SharedPointer<Array<string>>::Create(st.FrameCount() + 1);

  if (st.FrameCount() == 0) {
    this->stackTrace()[0] = String::Format("  in {0}:{1}{2}", this->currentInformation.FileName, this->currentInformation.Line, Environment::NewLine);
  } else {
    this->stackTrace()[0] = String::Format("  at {0} [0x{1:X8}] in {2}:{3}{4}", st.GetFrame(0).GetMethod(), st.GetFrame(0).GetOffset(), this->currentInformation.FileName, this->currentInformation.Line, Environment::NewLine);
    for (int32 index = 0; index < st.FrameCount(); index++) {
      this->stackTrace()[index + 1] = String::Format("  at {0}", st.GetFrame(index).GetMethod());
      if (!string::IsNullOrEmpty(st.GetFrame(index).GetFileName()))
        this->stackTrace()[index + 1] += String::Format(" [0x{0:X8}] in {1}:{2}{3}", st.GetFrame(index).GetOffset(), st.GetFrame(index).GetFileName(), st.GetFrame(index).GetFileLineNumber(), Environment::NewLine);
    }
  }
}

const char* Exception::what() const noexcept {
  const_cast<Exception&>(*this).whatMessage = ToString();
  return whatMessage.c_str();
}

string Exception::GetStackTrace(const string& filter) const {
  if (stackTrace.IsNull() || stackTrace().Length == 0)
    return "";

  int32 startIndex= 0;
  for (int32 i = 0; i < stackTrace().Length; i++) {
    if (stackTrace()[i].Contains(filter))
      startIndex = i+1;
  }

  string output;
  for (int32 i = startIndex; i < stackTrace().Length; i++) {
    if (i == startIndex) {
      output = string::Format("{0} in {1}:{2}{3}", stackTrace()[i].Remove(stackTrace()[i].IndexOf(" in ")), this->currentInformation.FileName, this->currentInformation.Line, Environment::NewLine);
    } else {
      output += stackTrace()[i];
    }
  }
  return output;
}
