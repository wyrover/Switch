#include "../../../../Includes/Pcf/System/IO/TextWriter.hpp"
#include "../../../../Includes/Pcf/System/Environment.hpp"
#include "../../../../Includes/Pcf/System/Text/UTF8Encoding.hpp"

using namespace System;
using namespace System::IO;

namespace {
  Text::UTF8Encoding utf8Encoding(false);
}

TextWriter::TextWriter() : encoding(utf8Encoding) {
} 

Property<NullTextWriter&, ReadOnly> TextWriter::Null {
  []()->NullTextWriter& {
    static NullTextWriter textWriter;
    return textWriter;
  }
};


SynchronizedTextWriter TextWriter::Synchronised(TextWriter& writer) {
  return SynchronizedTextWriter(writer);
}

SynchronizedTextWriter::SynchronizedTextWriter(System::IO::TextWriter& writer) : TextWriter(writer.Encoding), writer(&writer) {
}

void SynchronizedTextWriter::Write(const string& value) {
  pcf_using(System::Threading::LockGuard lock(*this->writer))
    this->writer->Write(value);
}
