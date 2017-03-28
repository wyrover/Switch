#include "../../../../Includes/Pcf/System/BitConverter.h"
#include "../../../../Includes/Pcf/System/IO/BinaryReader.h"
#include "../../../../Includes/Pcf/System/IO/EndOfStreamException.h"

using namespace System;
using namespace System::IO;

BinaryReader::BinaryReader() : stream(Stream::Null) {
}

BinaryReader::BinaryReader(Stream& stream) : stream(stream) {
  if (!this->stream.CanRead())
    throw ArgumentException(pcf_current_information);
}

BinaryReader::~BinaryReader() {
  Close();
}

Stream& BinaryReader::GetBaseStream() const {
  return this->stream;
}

void BinaryReader::Close() {
}

int32 BinaryReader::PeekChar() {
  int32 value = -1; 
  if (this->stream.CanRead() && this->stream.CanSeek()) {
    value = this->stream.ReadByte();
    if (value != -1)
      this->stream.Seek(-1, SeekOrigin::Current);
  }
  return value;
}

int32 BinaryReader::Read() {
  int32 value = -1;
  if (this->stream.CanRead() && this->stream.CanSeek())
    value = this->stream.ReadByte();
  return value;
}

int32 BinaryReader::Read(Array<byte>& buffer, int32 index, int32 count) {
  if (this->stream.CanRead())
    return this->stream.Read(buffer, index, count);
  else
    return -1;
}

bool BinaryReader::ReadBoolean() {
  return BitConverter::ToBoolean(ReadBytes(sizeof(bool)), 0);
}

byte BinaryReader::ReadByte() {
  return ReadBytes(1)[0];
}

Array<byte> BinaryReader::ReadBytes(int32 count) {
  Array<byte> values(count);
  if (Read(values, 0, count) != count)
    throw EndOfStreamException(pcf_current_information);
  return values;
}

char32 BinaryReader::ReadChar() {
  return BitConverter::ToChar(ReadBytes(sizeof(char32)), 0);
}

Array<char32> BinaryReader::ReadChars(int32 count) {
  Array<char32> values(count);
  for (int i = 0; i < count; i++)
    values[i] = BitConverter::ToChar(ReadBytes(sizeof(char32)), 0);
  return values;
}

double BinaryReader::ReadDouble() {
  return BitConverter::ToDouble(ReadBytes(sizeof(double)), 0);
}

int16 BinaryReader::ReadInt16() {
  return BitConverter::ToInt16(ReadBytes(sizeof(int16)), 0);
}

int32 BinaryReader::ReadInt32() {
  return BitConverter::ToInt32(ReadBytes(sizeof(int32)), 0);
}

int64 BinaryReader::ReadInt64() {
  return BitConverter::ToInt64(ReadBytes(sizeof(int64)), 0);
}

sbyte BinaryReader::ReadSByte() {
  return (sbyte)ReadBytes(1)[0];
}

float BinaryReader::ReadSingle() {
  return BitConverter::ToSingle(ReadBytes(sizeof(float)), 0);
}

string BinaryReader::ReadString() {
  int32 length = BitConverter::ToInt32(ReadBytes(sizeof(int32)), 0);
  return string((char*)ReadBytes(length).Data(), length);
}

uint16 BinaryReader::ReadUInt16() {
  return BitConverter::ToUInt16(ReadBytes(sizeof(uint16)), 0);;
}

uint32 BinaryReader::ReadUInt32() {
  return BitConverter::ToUInt32(ReadBytes(sizeof(uint32)), 0);
}

uint64 BinaryReader::ReadUInt64() {
  return BitConverter::ToUInt64(ReadBytes(sizeof(uint64)), 0);
}

