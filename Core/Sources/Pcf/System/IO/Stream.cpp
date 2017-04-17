#include "../../../../Includes/Pcf/System/IO/Stream.h"
#include "../../../../Includes/Pcf/System/Array.h"
#include "../../../../Includes/Pcf/System/ObjectClosedException.h"

using namespace System;
using namespace System::IO;
using namespace System::Threading;

Property<NullStream&, ReadOnly> Stream::Null {
  []()->NullStream& {
    return Stream::__null__();
  }
};

int32 Stream::ReadByte() {
  if (this->closed) throw ObjectClosedException(pcf_current_information);
  static Array<byte> b(1);
  if (Read(b, 0, 1) == 1)
    return int32(b[0]);
  return -1;
}

Stream& Stream::Synchronised(Stream& stream) {
  stream.lock = &stream;
  return stream;
}

void Stream::WriteByte(byte value) {
  if (this->closed) throw ObjectClosedException(pcf_current_information);
  Array<byte> b = {value};
  Write(b, 0, 1);
}

NullStream& Stream::__null__() {
  static NullStream nullStream;
  return nullStream;
}