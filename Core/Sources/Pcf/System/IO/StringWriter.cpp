#include "../../../../Includes/Pcf/System/ObjectClosedException.hpp"
#include "../../../../Includes/Pcf/System/IO/StringWriter.hpp"
#include "../../../../Includes/Pcf/System/IO/File.hpp"
#include "../../../../Includes/Pcf/System/IO/FileStream.hpp"
#include "../../../../Includes/Pcf/System/Text/UTF8Encoding.hpp"

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

string StringWriter::ToString() const {
  return this->data->str;
}
