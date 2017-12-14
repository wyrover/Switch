#include "../../../../include/Switch/System/IO/MemoryStream.hpp"
#include "../../../../include/Switch/System/Convert.hpp"

using namespace System;
using namespace System::IO;

MemoryStream::MemoryStream() {
}

MemoryStream::MemoryStream(int32 capacity) {
  this->data->dynamicBuffer.Capacity = capacity;
}

MemoryStream::MemoryStream(Array<byte>& buffer, bool writable) {
  this->data->staticBuffer = &buffer;
  this->data->staticBufferCapacity = buffer.Length;
  this->data->writable = writable;
}

int64 MemoryStream::GetLength() const {
  if (IsClosed()) throw ObjectDisposedException(_caller);
  if (IsDynamic()) return this->data->dynamicBuffer.Count;
  return this->data->staticBuffer->Length;
}

void MemoryStream::SetLength(int64 value) {
  if (!CanWrite() || (!IsDynamic() && value > Capacity()))
    throw NotSupportedException(_caller);
  if (value < 0 || value > Int32::MaxValue)
    throw ArgumentOutOfRangeException(_caller);

  if (IsDynamic()) {
    if (static_cast<int32>(value) < this->data->dynamicBuffer.Count) {
      //todo
    } else {
      while (this->data->dynamicBuffer.Count < value)
        this->data->dynamicBuffer.Add(0);
    }
  } else
    System::Array<>::Resize(*this->data->staticBuffer, (int32)value);
}

int32 MemoryStream::GetCapacity() const {
  if (IsClosed()) throw ObjectDisposedException(_caller);
  if (IsDynamic())
    return this->data->dynamicBuffer.Capacity;
  return this->data->staticBufferCapacity;
}

void MemoryStream::SetCapacity(int32 newCapacity) {
  if (newCapacity < Length()) throw ArgumentOutOfRangeException(_caller);
  if (IsClosed()) throw ObjectDisposedException(_caller);
  if (!IsDynamic()) throw NotSupportedException(_caller);
  this->data->dynamicBuffer.Capacity = newCapacity;
}

const byte* MemoryStream::Buffer() const {
  if (IsDynamic())
    return this->data->dynamicBuffer.Data();
  else
    return this->data->staticBuffer->Data();
}

int32 MemoryStream::Read(Array<byte>& buffer, int32 offset, int32 count) {
  if (offset < 0 || count < 0)
    throw ArgumentOutOfRangeException(_caller);
  if (buffer.Length - offset < count)
    throw ArgumentException(_caller);
  if (IsClosed())
    throw ObjectDisposedException(_caller);

  int32 nbRead = Convert::ToInt32(Length()) - this->data->position;
  if (count < nbRead) nbRead = count;
  for (int32 iter = nbRead; iter > 0; iter -= 1)
    buffer[offset++] = AbstractReadByteUnChecked();
  return nbRead;
}

int32 MemoryStream::ReadByte() {
  if (IsClosed()) throw ObjectDisposedException(_caller);
  if (this->data->position >= Length()) return -1;
  return static_cast<int32>(AbstractReadByteUnChecked());
}

int64 MemoryStream::Seek(int64 offset, SeekOrigin origin) {
  if (IsClosed()) throw ObjectDisposedException(_caller);
  int64 newPosition = 0;
  bool invalidSeekOrigin = false; /* used in order to be able to have the same priorities of thrown exceptions (cf. .Net) */
  if (origin == SeekOrigin::Begin)
    newPosition = offset;
  else  if (origin == SeekOrigin::Current)
    newPosition = static_cast<int64>(this->data->position) + offset;
  else if (origin == SeekOrigin::End)
    newPosition = static_cast<int64>(Length()) + offset;
  else
    invalidSeekOrigin = true;

  if (newPosition < 0) throw IOException(_caller);
  if (offset > Int32::MaxValue || newPosition > Int32::MaxValue)
    throw ArgumentOutOfRangeException(_caller);
  if (invalidSeekOrigin) throw ArgumentException(_caller);
  this->data->position = static_cast<int32>(newPosition);
  return newPosition;
}

Array<byte> MemoryStream::ToArray() const {
  if (IsDynamic())
    return this->data->dynamicBuffer.ToArray();
  return *this->data->staticBuffer;
}

void MemoryStream::Write(const Array<byte>& buffer, int32 offset, int32 count) {
  if (IsClosed())
    throw ObjectDisposedException(_caller);
  if (!CanWrite())
    throw NotSupportedException(_caller);
  if (!IsDynamic() && (this->data->position + count > this->data->staticBufferCapacity))
    throw NotSupportedException(_caller);
  if (buffer.Length - offset < count)
    throw ArgumentException(_caller);
  if (offset < 0 || count < 0)
    throw ArgumentOutOfRangeException(_caller);

  while (count-- > 0) {
    byte b = buffer[offset++];
    AbstractWriteByteUnChecked(b);
  }
}

void MemoryStream::WriteByte(byte value) {
  if (IsClosed()) throw ObjectDisposedException(_caller);
  if (!CanWrite()) throw NotSupportedException(_caller);
  if (!IsDynamic() && (this->data->position + 1 > this->data->staticBufferCapacity)) throw NotSupportedException(_caller);
  AbstractWriteByteUnChecked(value);
}

void MemoryStream::WriteTo(Stream& stream) const {
  Array<byte> bytes = ToArray();
  stream.Write(bytes, 0, bytes.Length);
}

bool MemoryStream::IsDynamic() const {
  return this->data->staticBuffer == null;
}

byte MemoryStream::AbstractReadByteUnChecked() {
  if (IsDynamic()) return this->data->dynamicBuffer[this->data->position++];
  return (*this->data->staticBuffer)[this->data->position++];
}

void MemoryStream::AbstractWriteByteUnChecked(byte b) {
  if (IsDynamic()) {
    if (this->data->position < this->data->dynamicBuffer.Count)
      this->data->dynamicBuffer[this->data->position] = b;
    else
      this->data->dynamicBuffer.Add(b);
  } else
    (*this->data->staticBuffer)[this->data->position] = b;
  this->data->position += 1;
}
