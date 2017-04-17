#include "../../../../Includes/Pcf/System/IO/MemoryStream.h"
#include "../../../../Includes/Pcf/System/Convert.h"

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
  if (IsClosed()) throw ObjectClosedException(pcf_current_information);
  if (IsDynamic()) return this->data->dynamicBuffer.Count;
  return this->data->staticBuffer->Length;
}

void MemoryStream::SetLength(int64 value) {
  if (!CanWrite() || (!IsDynamic() && value > Capacity()))
    throw NotSupportedException(pcf_current_information);
  if (value < 0 || value > Int32::MaxValue)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  if (IsDynamic()) {
    if (static_cast<int32>(value) < this->data->dynamicBuffer.Count) {
      //todo
    } else {
      while (this->data->dynamicBuffer.Count < value)
        this->data->dynamicBuffer.Add(0);
    }
  } else {
    this->data->staticBuffer->Resize((int32)value);
  }
}

int32 MemoryStream::GetCapacity() const {
  if (IsClosed()) throw ObjectClosedException(pcf_current_information);
  if (IsDynamic())
    return this->data->dynamicBuffer.Capacity;
  return this->data->staticBufferCapacity;
}

void MemoryStream::SetCapacity(int32 newCapacity) {
  if (newCapacity < Length()) throw ArgumentOutOfRangeException(pcf_current_information);
  if (IsClosed()) throw ObjectClosedException(pcf_current_information);
  if (!IsDynamic()) throw NotSupportedException(pcf_current_information);
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
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (buffer.Length - offset < count)
    throw ArgumentException(pcf_current_information);
  if (IsClosed())
    throw ObjectClosedException(pcf_current_information);
  
  int32 nbRead = Convert::ToInt32(Length()) - this->data->position;
  if (count < nbRead) nbRead = count;
  for (int32 iter = nbRead; iter > 0; iter -= 1)
    buffer[offset++] = AbstractReadByteUnChecked();
  return nbRead;
}

int32 MemoryStream::ReadByte() {
  if (IsClosed()) throw ObjectClosedException(pcf_current_information);
  if (this->data->position >= Length()) return -1;
  return static_cast<int32>(AbstractReadByteUnChecked());
}

int64 MemoryStream::Seek(int64 offset, SeekOrigin origin) {
  if (IsClosed()) throw ObjectClosedException(pcf_current_information);
  int64 newPosition = 0;
  bool invalidSeekOrigin = false; /* used in order to be able to have the same priorities of thrown exceptions (cf. .Net) */
  if (origin == SeekOrigin::Begin) {
    newPosition = offset;
  } else  if (origin == SeekOrigin::Current) {
    newPosition = static_cast<int64>(this->data->position) + offset;
  } else if (origin == SeekOrigin::End) {
    newPosition = static_cast<int64>(Length()) + offset;
  } else {
    invalidSeekOrigin = true;
  }
  
  if (newPosition < 0) throw IOException(pcf_current_information);
  if (offset > Int32::MaxValue || newPosition > Int32::MaxValue)
    throw ArgumentOutOfRangeException(pcf_current_information);
  if (invalidSeekOrigin) throw ArgumentException(pcf_current_information);
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
    throw ObjectClosedException(pcf_current_information);
  if (!CanWrite())
    throw NotSupportedException(pcf_current_information);
  if (!IsDynamic() && (this->data->position + count > this->data->staticBufferCapacity))
    throw NotSupportedException(pcf_current_information);
  if (buffer.Length - offset < count)
    throw ArgumentException(pcf_current_information);
  if (offset < 0 || count < 0)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  while (count-- > 0) {
    byte b = buffer[offset++];
    AbstractWriteByteUnChecked(b);
  }
}

void MemoryStream::WriteByte(byte value) {
  if (IsClosed()) throw ObjectClosedException(pcf_current_information);
  if (!CanWrite()) throw NotSupportedException(pcf_current_information);
  if (!IsDynamic() && (this->data->position + 1 > this->data->staticBufferCapacity)) throw NotSupportedException(pcf_current_information);
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
  } else {
    (*this->data->staticBuffer)[this->data->position] = b;
  }
  this->data->position += 1;
}