#include "../../../../Includes/Pcf/System/IO/BinaryWriter.h"
#include "../../../../Includes/Pcf/System/BitConverter.h"
#include "../../../../Includes/Pcf/System/IO/IOException.h"

using namespace System;
using namespace System::IO;


BinaryWriter::BinaryWriter() : stream(Stream::Null) {
}

BinaryWriter::BinaryWriter(Stream& stream) : stream(stream) {
  if (!stream.CanWrite())
    throw ArgumentException(pcf_current_information);
}

BinaryWriter::~BinaryWriter() {
  Close();
}

Stream& BinaryWriter::GetBaseStream() const {
  return this->stream;
}

void BinaryWriter::Close() {
}

void BinaryWriter::Flush() {
  this->stream.Flush();
}

int64 BinaryWriter::Seek(int32 offset, SeekOrigin origin) {
  return this->stream.Seek(Convert::ToInt64(offset), origin);
}

void BinaryWriter::Write(bool value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(byte value) {
  Write(Array<byte> {value});
}

void BinaryWriter::Write(const Array<byte>& value) {
  this->stream.Write(value, 0, value.Length);
}

void BinaryWriter::Write(Char value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(const Array<char32>& value) {
  for (char32 c : value)
    Write(BitConverter::GetBytes(c));
}

void BinaryWriter::Write(double value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(int16 value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(int32 value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(int64 value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(sbyte value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(float value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(const String& value) {
  int32 length = (int32)strlen(value.Data());
  Write(BitConverter::GetBytes(length));
  Write(Array<byte> {(byte*)value.Data(), length});
}

void BinaryWriter::Write(uint16 value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(uint32 value) {
  Write(BitConverter::GetBytes(value));
}

void BinaryWriter::Write(uint64 value) {
  Write(BitConverter::GetBytes(value));
}

