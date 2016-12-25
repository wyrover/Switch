#include "../../../../Includes/Pcf/System/ObjectClosedException.h"
#include "../../../../Includes/Pcf/System/IO/StringWriter.h"
#include "../../../../Includes/Pcf/System/IO/File.h"
#include "../../../../Includes/Pcf/System/IO/FileStream.h"
#include "../../../../Includes/Pcf/System/Text/UTF8Encoding.h"

using namespace System;
using namespace System::IO;

namespace {
  Text::UTF8Encoding utf8Encoding(false);
}

const StringWriter StringWriter::Null;

StringWriter::StringWriter() : TextWriter(utf8Encoding) {
}

StringWriter::~StringWriter() {
  Close();
}

void StringWriter::Close() {
  if (this->close == false) {
    this->close = true;
    this->str = "";
  }
}

void StringWriter::Write(const String& value) {
  if (this->close)
    throw ObjectClosedException(pcf_current_information);
  this->str += value;
  
}

string StringWriter::ToString() const {
  return this->str;
}