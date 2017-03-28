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

Property<StringWriter, ReadOnly> StringWriter::Null {
  [] {return StringWriter();}
};

StringWriter::StringWriter() : TextWriter(utf8Encoding) {
}

StringWriter::~StringWriter() {
  Close();
}

void StringWriter::Close() {
  if (this->data->close == false) {
    this->data->close = true;
    this->data->str = "";
  }
}

void StringWriter::Write(const String& value) {
  if (this->data->close)
    throw ObjectClosedException(pcf_current_information);
  this->data->str += value;
  
}

string StringWriter::ToString() const noexcept {
  return this->data->str;
}
