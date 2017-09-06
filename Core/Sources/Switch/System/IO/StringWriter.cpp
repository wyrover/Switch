#include "../../../../Includes/Switch/System/ObjectClosedException.hpp"
#include "../../../../Includes/Switch/System/IO/StringWriter.hpp"
#include "../../../../Includes/Switch/System/IO/File.hpp"
#include "../../../../Includes/Switch/System/IO/FileStream.hpp"
#include "../../../../Includes/Switch/System/Text/UTF8Encoding.hpp"

using namespace System;
using namespace System::IO;

namespace {
  Text::UTF8Encoding utf8Encoding(false);
}

property<StringWriter, readonly> StringWriter::Null {
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
    throw ObjectClosedException(_current_information);
  this->data->str += value;
  
}

string StringWriter::ToString() const {
  return this->data->str;
}
