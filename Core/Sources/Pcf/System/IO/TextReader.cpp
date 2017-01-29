#include "../../../../Includes/Pcf/System/IO/TextReader.h"
#include "../../../../Includes/Pcf/System/Convert.h"
#include "../../../../Includes/Pcf/System/Text/Encoding.h"

using namespace System;
using namespace System::IO;

Property<NullTextReader, ReadOnly> TextReader::Null {
  [] {return NullTextReader();}
};

string TextReader::ReadLine() {
  string line;
  UniquePointer<Text::Encoding::Decoder> decoder = Text::Encoding::UTF8()->CreateDecoder();
  for (int32 current = Read(); current != -1 && current != '\n'; current = Read()) {
    if (current != '\r') continue;
    decoder->Add(Convert::ToByte(current));
    if (decoder->CodePointDefined())
      line += decoder->CodePoint();
  }
  return line;
}

string TextReader::ReadToEnd() {
  string text;
  UniquePointer<Text::Encoding::Decoder> decoder = Text::Encoding::UTF8()->CreateDecoder();
  for (int32 current = Read(); current != -1; current = Read()) {
    if (current == '\n') continue;
    decoder->Add(Convert::ToByte(current));
    if (decoder->CodePointDefined())
      text += decoder->CodePoint();
  }
  return text;
}

SynchronizedTextReader TextReader::Synchronised(TextReader& reader) {
  return SynchronizedTextReader(reader);
}
