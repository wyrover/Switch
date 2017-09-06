#include "../../../../Includes/Switch/System/IO/Stream.hpp"
#include "../../../../Includes/Switch/System/Array.hpp"
#include "../../../../Includes/Switch/System/ObjectClosedException.hpp"

using namespace System;
using namespace System::IO;
using namespace System::Threading;

property<NullStream&, readonly> Stream::Null {
  []()->NullStream& {
    return Stream::__null__();
  }
};

int32 Stream::ReadByte() {
  if (this->closed) throw ObjectClosedException(_current_information);
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
  if (this->closed) throw ObjectClosedException(_current_information);
  Array<byte> b = {value};
  Write(b, 0, 1);
}

NullStream& Stream::__null__() {
  static NullStream nullStream;
  return nullStream;
}
