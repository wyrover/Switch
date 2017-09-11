#include "../../../Includes/Switch/System/Exception.hpp"
#include "../../../Includes/Switch/System/Environment.hpp"
#include "../../../Includes/Switch/System/Diagnostics/StackTrace.hpp"
#include "__HResults.hpp"

using namespace System;

bool Exception::stackTraceEnabled = true;

const string& Exception::GetMessage() const {
  if (string::IsNullOrEmpty(this->message))
    const_cast<Exception*>(this)->message = GetDefaultMessage();
  return this->message;
}

string Exception::GetStackTrace() const {
  if (this->stackTrace == null || this->stackTrace().Length == 0)
    return "";
  
  return string::Join("\n", this->stackTrace());
}

Exception::Exception() : currentInformation(_current_information) {
  this->SetStackTrace(*this);
  this->SetHResult(__HResults::COR_E_EXCEPTION);
}

Exception::Exception(const CurrentInformation& information) : currentInformation(information) {
  this->SetStackTrace(*this);
  this->SetHResult(__HResults::COR_E_EXCEPTION);
}

Exception::Exception(const Exception& value) {
  this->message = value.message;
  this->helpLink = value.helpLink;
  this->currentInformation = value.currentInformation;
  this->innerException = value.innerException;
  this->hresult = value.hresult;
  this-> stackTrace = value.stackTrace;
}

Exception::Exception(const string& message) : message(message), currentInformation(_current_information) {
  this->SetStackTrace(*this);
  this->SetHResult(__HResults::COR_E_EXCEPTION);
}

Exception::Exception(const string& message, const CurrentInformation& information) : message(message), currentInformation(information) {
  this->SetStackTrace(*this);
  this->SetHResult(__HResults::COR_E_EXCEPTION);
}

Exception::Exception(const string& message, const Exception& innerExeption) : message(message), innerException(innerExeption) {
  this->SetStackTrace(*this);
  this->SetHResult(__HResults::COR_E_EXCEPTION);
}

Exception::Exception(const string& message, const Exception& innerExeption, const CurrentInformation& information) : message(message), currentInformation(information), innerException(innerExeption) {
  this->SetStackTrace(*this);
  this->SetHResult(__HResults::COR_E_EXCEPTION);
}

bool Exception::Equals(const Exception& value) const {
  return this->hresult == value.hresult && this->message == value.message && this->currentInformation == value.currentInformation && this->innerException == value.innerException;
}

bool Exception::Equals(const object& obj) const {
  return is<Exception>(obj) && Equals(static_cast<const Exception&>(obj));
}

string Exception::ToString() const {
  return string::Format("{0}: {1}{2}{3}", GetType(), GetMessage(), Environment::NewLine, GetStackTrace(GetType().ToString()));
}

Exception& Exception::operator =(const Exception& value) {
  this->message = value.message;
  this->helpLink = value.helpLink;
  this->currentInformation = value.currentInformation;
  this->innerException = value.innerException;
  this->hresult = value.hresult;
  this-> stackTrace = value.stackTrace;

  return *this;
}

string Exception::GetDefaultMessage() const {
  return string::Format("Exception of type '{0}' was thrown.", GetType());
}

void Exception::SetStackTrace(const Exception& exception) {
  if (Exception::stackTraceEnabled == false) {
    this->stackTrace = ref_new<Array<string>>(1);
    this->stackTrace()[0] = String::Format("  in {0}:{1}{2}", this->currentInformation.FilePath, this->currentInformation.LineNumber, Environment::NewLine);
    return;
  }
  
  Diagnostics::StackTrace stackTrace(1, true);
  this->stackTrace = ref_new<Array<string>>(stackTrace.FrameCount() + 1);

  if (stackTrace.FrameCount() == 0) {
    this->stackTrace()[0] = String::Format("  in {0}:{1}{2}", this->currentInformation.FilePath, this->currentInformation.LineNumber, Environment::NewLine);
  } else {
    this->stackTrace()[0] = String::Format("  at {0} [0x{1:X8}] in {2}:{3}{4}", stackTrace.GetFrame(0).GetMethod(), stackTrace.GetFrame(0).GetOffset(), this->currentInformation.FilePath, this->currentInformation.LineNumber, Environment::NewLine);
    for (int32 index = 0; index < stackTrace.FrameCount(); index++) {
      this->stackTrace()[index + 1] = String::Format("  at {0}", stackTrace.GetFrame(index).GetMethod());
      if (!string::IsNullOrEmpty(stackTrace.GetFrame(index).GetFileName()))
        this->stackTrace()[index + 1] += String::Format(" [0x{0:X8}] in {1}:{2}{3}", stackTrace.GetFrame(index).GetOffset(), stackTrace.GetFrame(index).GetFileName(), stackTrace.GetFrame(index).GetFileLineNumber(), Environment::NewLine);
    }
  }
}

const char* Exception::what() const noexcept {
  this->whatMessage = this->ToString();
  return this->whatMessage.c_str();
}

string Exception::GetStackTrace(const string& filter) const {
  if (this->stackTrace == null || this->stackTrace().Length == 0)
    return "";

  int32 startIndex= 0;
  for (int32 i = 0; i < this->stackTrace().Length; i++) {
    if (this->stackTrace()[i].Contains(filter))
      startIndex = i+1;
  }

  string output;
  for (int32 i = startIndex; i < this->stackTrace().Length; i++) {
    if (i == startIndex) {
      output = string::Format("{0} in {1}:{2}{3}", this->stackTrace()[i].Remove(this->stackTrace()[i].IndexOf(" in ")), this->currentInformation.FilePath, this->currentInformation.LineNumber, Environment::NewLine);
    } else {
      output += this->stackTrace()[i];
    }
  }
  return output;
}
