#include <Switch/System/IO/MemoryStream.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  TEST(MemoryStreamTest, Ctor_Default) {
    IO::MemoryStream ms;
    ASSERT_EQ(0, ms.Length());
    ASSERT_EQ(0, ms.Position());
    ASSERT_TRUE(ms.CanRead());
    ASSERT_TRUE(ms.CanWrite());
    ASSERT_TRUE(ms.CanSeek());
    ASSERT_FALSE(ms.CanTimeout());
    ASSERT_EQ(0, ms.Capacity());
  }
  
  TEST(MemoryStreamTest, Ctor_Capacity) {
    IO::MemoryStream ms(10);
    ASSERT_EQ(0, ms.Length());
    ASSERT_EQ(0, ms.Position());
    ASSERT_TRUE(ms.CanRead());
    ASSERT_TRUE(ms.CanWrite());
    ASSERT_TRUE(ms.CanSeek());
    ASSERT_FALSE(ms.CanTimeout());
  }
  
  TEST(MemoryStreamTest, Ctor_Capacity_Exception) {
    ASSERT_THROW(IO::MemoryStream ms(-1), ArgumentOutOfRangeException);
  }
  
  TEST(MemoryStreamTest, Ctor_Buffer_CanWrite) {
    Array<byte> buffer(10);
    IO::MemoryStream ms(buffer, true);
    ASSERT_EQ(10, ms.Length());
    ASSERT_EQ(0, ms.Position());
    ASSERT_TRUE(ms.CanRead());
    ASSERT_TRUE(ms.CanWrite());
    ASSERT_TRUE(ms.CanSeek());
    ASSERT_FALSE(ms.CanTimeout());
    ASSERT_EQ(10, ms.Capacity());
  }
  
  TEST(MemoryStreamTest, Ctor_Buffer_CanNotWrite) {
    Array<byte> buffer(10);
    IO::MemoryStream ms(buffer, false);
    ASSERT_EQ(10, ms.Length());
    ASSERT_EQ(0, ms.Position());
    ASSERT_TRUE(ms.CanRead());
    ASSERT_FALSE(ms.CanWrite());
    ASSERT_TRUE(ms.CanSeek());
    ASSERT_FALSE(ms.CanTimeout());
    ASSERT_EQ(10, ms.Capacity());
  }
  
  TEST(MemoryStreamTest, GetData_NotDynamic) {
    Array<byte> buffer = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    IO::MemoryStream ms(buffer, false);
    ASSERT_EQ(buffer.Data(), ms.Buffer());
    for(int32 i = 0; i < ms.Length(); i++)
      ASSERT_EQ(buffer[i], ms.Buffer()[i]);
  }
  
  TEST(MemoryStreamTest, GetData_Dynamic) {
    IO::MemoryStream ms(10);
    ms.WriteByte(0);
    ms.WriteByte(1);
    ms.WriteByte(2);
    ms.WriteByte(3);
    ms.WriteByte(4);
    const byte* buffer = ms.Buffer();
    for(int32 i = 0; i < ms.Length(); i++)
      ASSERT_EQ(i, buffer[i]);
  }
  
  TEST(MemoryStreamTest, Read_NotDynamic) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    Array<byte> readBuffer(10);
    ASSERT_EQ(10, ms.Read(readBuffer, 0, 10));
    for(int32 i = 0; i < 10; i++)
      ASSERT_EQ(i, readBuffer[i]);
  }
  
  TEST(MemoryStreamTest, Read_NotDynamic_2) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    Array<byte> readBuffer(5);
    ASSERT_EQ(1, ms.Read(readBuffer, 0, 1)); // 0
    ASSERT_EQ(1, ms.Position());
    ASSERT_EQ(4, ms.Read(readBuffer, 1, 4)); // 0 1 2 3 4
    ASSERT_EQ(5, ms.Position());
    for(int32 i = 0; i < 5; i++)
      ASSERT_EQ(i, readBuffer[i]);
  }
  
  TEST(MemoryStreamTest, Read_NotDynamic_Offset) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Array<byte> reference = {2, 3, 4, 0, 1};
    IO::MemoryStream ms(buffer, false);
    Array<byte> readBuffer(5);
    ASSERT_EQ(2, ms.Read(readBuffer, 3, 2));
    ASSERT_EQ(2, ms.Position());
    ASSERT_EQ(3, ms.Read(readBuffer, 0, 3));
    ASSERT_EQ(5, ms.Position());
    for(int32 i = 0; i < 5; i++)
      ASSERT_EQ(reference[i], readBuffer[i]);
  }
  
  TEST(MemoryStreamTest, Read_NotDynamic_Offset_Exceptions) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    Array<byte> readBuffer(5);
    ASSERT_THROW(ms.Read(readBuffer, 3, 3), ArgumentException);
    ASSERT_EQ(0, ms.Position());
    ASSERT_EQ(2, ms.Seek(2, IO::SeekOrigin::Begin));
    ASSERT_THROW(ms.Read(readBuffer, 0, 6), ArgumentException);
    ASSERT_EQ(2, ms.Position());
  }
  
  TEST(MemoryStreamTest, Read_NotDynamic_Overflow) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Array<byte> refBuffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255, 255, 255, 255, 255};
    IO::MemoryStream ms(buffer, false);
    Array<byte> readBuffer = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
    ASSERT_EQ(5, ms.Read(readBuffer, 0, 5));
    ASSERT_EQ(5, ms.Position());
    ASSERT_EQ(5, ms.Read(readBuffer, 5, 10));
    ASSERT_EQ(10, ms.Position());
    ASSERT_EQ(0, ms.Read(readBuffer, 10, 5));
    ASSERT_EQ(10, ms.Position());
    for(int32 i = 0; i < 15; i++)
      ASSERT_EQ(refBuffer[i], readBuffer[i]);
  }
  
  TEST(MemoryStreamTest, Read_NotDynamic_Exception) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    Array<byte> readBuffer;
    ASSERT_THROW(ms.Read(readBuffer, 0, 6), ArgumentException);
    ASSERT_THROW(ms.Read(readBuffer, 1, 5), ArgumentException);
    ASSERT_THROW(ms.Read(readBuffer, -1, 5), ArgumentOutOfRangeException);
    ASSERT_THROW(ms.Read(readBuffer, 0, -5), ArgumentOutOfRangeException);
  }
  
  TEST(MemoryStreamTest, ReadByte_NotDynamic) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    for(int32 i = 0; i < 12; i++) {
      if(i < 10) ASSERT_EQ(i, ms.ReadByte());
      else ASSERT_EQ(-1, ms.ReadByte());
    }
  }
  
  TEST(MemoryStreamTest, Seek_NotDynamic_NotWritable) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    ASSERT_EQ(0, ms.Seek(0, IO::SeekOrigin::Begin));
    ASSERT_EQ(0, ms.Position());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(1, ms.Seek(1, IO::SeekOrigin::Begin));
    ASSERT_EQ(1, ms.Position());
    ASSERT_EQ(1, ms.ReadByte());
    ASSERT_EQ(9, ms.Seek(9, IO::SeekOrigin::Begin));
    ASSERT_EQ(9, ms.Position());
    ASSERT_EQ(9, ms.ReadByte());
    ASSERT_EQ(10, ms.Seek(10, IO::SeekOrigin::Begin));
    ASSERT_EQ(10, ms.Position());
    ASSERT_EQ(-1, ms.ReadByte());
    ASSERT_EQ(11, ms.Seek(11, IO::SeekOrigin::Begin));
    ASSERT_EQ(11, ms.Position());
    ASSERT_EQ(-1, ms.ReadByte());
    ASSERT_EQ(20, ms.Seek(20, IO::SeekOrigin::Begin));
    ASSERT_EQ(20, ms.Position());
    ASSERT_EQ(-1, ms.ReadByte());
    ASSERT_EQ(Int32::MaxValue, ms.Seek(Int32::MaxValue, IO::SeekOrigin::Begin));
    ASSERT_EQ(Int32::MaxValue, ms.Position());
    ASSERT_EQ(-1, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, Seek_NotDynamic_Exceptions) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    ASSERT_THROW(ms.Seek(-1, IO::SeekOrigin::Begin), IO::IOException);
    ASSERT_THROW(ms.Seek(-11, IO::SeekOrigin::End), IO::IOException);
    ASSERT_THROW(ms.Seek(static_cast<int64>(Int32::MaxValue) + 1, IO::SeekOrigin::Begin), ArgumentOutOfRangeException);
    ASSERT_THROW(ms.Seek(1, (IO::SeekOrigin) - 66), ArgumentException);
  }
  
  TEST(MemoryStreamTest, SetLength_NotDynamic_Writable_Twice_ReadByte) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, true);
    ms.Length = 5;
    ASSERT_EQ(5, ms.Length());
    ASSERT_EQ(10, ms.Capacity());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(1, ms.ReadByte());
    ASSERT_EQ(2, ms.ReadByte());
    ASSERT_EQ(3, ms.ReadByte());
    ASSERT_EQ(4, ms.ReadByte());
    ASSERT_EQ(-1, ms.ReadByte());
    ms.Length = 10;
    ASSERT_EQ(10, ms.Length());
    ASSERT_EQ(10, ms.Capacity());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(-1, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, SetLength_NotDynamic_Writable_Seek_ReadByte) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, true);
    ms.Length = 5;
    ASSERT_EQ(7, ms.Seek(7, IO::SeekOrigin::Begin));
    ASSERT_EQ(-1, ms.ReadByte());
    ASSERT_EQ(7, ms.Seek(2, IO::SeekOrigin::End));
    ASSERT_EQ(-1, ms.ReadByte());
    ASSERT_EQ(15, ms.Seek(15, IO::SeekOrigin::Begin));
    ASSERT_EQ(-1, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, SetLength_Dynamic_ZeroCapacity) {
    IO::MemoryStream ms;
    ms.Length = 5;
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(-1, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, SetLength_Dynamic_Capacity) {
    IO::MemoryStream ms(10);
    ASSERT_EQ(-1, ms.ReadByte());
    ms.Length = 5;
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(-1, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, ToArray_NotDynamic) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, false);
    Array<byte> array = ms.ToArray();
    ASSERT_EQ(10, array.Length);
    for(int32 i = 0; i < array.Length; i++)
      ASSERT_EQ(i, array[i]);
  }
  
  TEST(MemoryStreamTest, ToArray_NotDynamic_Empty) {
    Array<byte> buffer = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    IO::MemoryStream ms(buffer, true);
    ms.Length = 0;
    Array<byte> array = ms.ToArray();
    ASSERT_EQ(0, array.Length);
  }
  
  TEST(MemoryStreamTest, Write_Dynamic) {
    IO::MemoryStream ms(5);
    ms.Length = 5;
    ASSERT_EQ(5, ms.Seek(5, IO::SeekOrigin::Begin));
    ASSERT_EQ(5, ms.Position());
    Array<byte> bytes = { 0, 1, 2};
    ms.Write(bytes, 0, 3);
    ASSERT_EQ(8, ms.Position());
    ASSERT_EQ(0, ms.Seek(0, IO::SeekOrigin::Begin));
    ASSERT_EQ(0, ms.Position());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(1, ms.ReadByte());
    ASSERT_EQ(2, ms.ReadByte());
    ASSERT_EQ(-1, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, Write_Dynamic_ChangeCapacity) {
    IO::MemoryStream ms(10);
    ms.Length = 5;
    ASSERT_EQ(5, ms.Seek(5, IO::SeekOrigin::Begin));
    ASSERT_EQ(5, ms.Position());
    Array<byte> bytes = { 0, 1, 2};
    ms.Write(bytes, 0, 3);
    ASSERT_EQ(8, ms.Position());
  }
  
  TEST(MemoryStreamTest, Write_NotDynamic) {
    Array<byte> buffer(10);
    IO::MemoryStream ms(buffer, true);
    Array<byte> bytes = { 0, 1, 2, 3, 4};
    ms.Write(bytes, 0, 3);
    ASSERT_EQ(3, ms.Position());
    ms.Write(bytes, 2, 2);
    ASSERT_EQ(5, ms.Position());
    ms.Write(bytes, 0, 5);
    ASSERT_EQ(10, ms.Position());
    
    ASSERT_EQ(0, ms.Seek(-10, IO::SeekOrigin::Current));
    ms.Write({' '}, 0, 1);
    ASSERT_EQ(0, ms.Seek(-1, IO::SeekOrigin::Current));
    
    ASSERT_EQ(32, ms.ReadByte());
    ASSERT_EQ(1, ms.ReadByte());
    ASSERT_EQ(2, ms.ReadByte());
    
    ASSERT_EQ(2, ms.ReadByte());
    ASSERT_EQ(3, ms.ReadByte());
    
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(1, ms.ReadByte());
    ASSERT_EQ(2, ms.ReadByte());
    ASSERT_EQ(3, ms.ReadByte());
    ASSERT_EQ(4, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, WriteByte_Dynamic_ChangeCapacity) {
    IO::MemoryStream ms(10);
    ms.Length = 5;
    ASSERT_EQ(5, ms.Seek(5, IO::SeekOrigin::Begin));
    ASSERT_EQ(5, ms.Position());
    ms.WriteByte(0);
    ms.WriteByte(1);
    ms.WriteByte(2);
    ASSERT_EQ(8, ms.Position());
  }
  
  TEST(MemoryStreamTest, WriteByte_NotDynamic) {
    Array<byte> buffer(10);
    IO::MemoryStream ms(buffer, true);
    ms.WriteByte(0);
    ms.WriteByte(1);
    ms.WriteByte(2);
    ASSERT_EQ(3, ms.Position());
    ms.WriteByte(2);
    ms.WriteByte(3);
    ASSERT_EQ(5, ms.Position());
    ms.WriteByte(0);
    ms.WriteByte(1);
    ms.WriteByte(2);
    ms.WriteByte(3);
    ms.WriteByte(4);
    ASSERT_EQ(10, ms.Position());
    
    ASSERT_EQ(0, ms.Seek(-10, IO::SeekOrigin::Current));
    ms.WriteByte(32);
    ASSERT_EQ(0, ms.Seek(-1, IO::SeekOrigin::Current));
    
    ASSERT_EQ(32, ms.ReadByte());
    ASSERT_EQ(1, ms.ReadByte());
    ASSERT_EQ(2, ms.ReadByte());
    
    ASSERT_EQ(2, ms.ReadByte());
    ASSERT_EQ(3, ms.ReadByte());
    
    ASSERT_EQ(0, ms.ReadByte());
    ASSERT_EQ(1, ms.ReadByte());
    ASSERT_EQ(2, ms.ReadByte());
    ASSERT_EQ(3, ms.ReadByte());
    ASSERT_EQ(4, ms.ReadByte());
  }
  
  TEST(MemoryStreamTest, Write_NotDynamic_Empty) {
    Array<byte> buffer = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    IO::MemoryStream ms(buffer, true);
    Array<byte> source;
    ASSERT_NO_THROW(ms.Write(source, 0, 0));
    ASSERT_EQ(0, ms.Position());
  }
  
  TEST(MemoryStreamTest, Write_NotDynamic_Offset) {
    Array<byte> buffer = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    IO::MemoryStream ms(buffer, true);
    //                   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14   15
    Array<byte> source = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 32 };
    ms.Write(source, 0, 1);
    ms.Write(source, 2, 1);
    ms.Write(source, 4, 1);
    ms.Write(source, 15, 1);
    ms.Write(source, 7, 1);
    ms.Write(source, 4, 1);
    ms.Write(source, 11, 1);
    ms.Write(source, 11, 1);
    ms.Write(source, 14, 1);
    ASSERT_EQ(10, ms.Length());
    ASSERT_EQ("ace hello", String((const char*)buffer.Data()));
  }
  
  
  TEST(MemoryStreamTest, WriteTo) {
    Array<byte> source = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};
    Array<byte> buffer(7);
    IO::MemoryStream ms1;
    IO::MemoryStream ms2(buffer, true);
    
    ms1.Write(source, 0, 7);
    ms1.WriteTo(ms2);
    ms2.Seek(0, IO::SeekOrigin::Begin);
    
    ASSERT_EQ('b', ms2.ReadByte());
    ASSERT_EQ('o', ms2.ReadByte());
    ASSERT_EQ('n', ms2.ReadByte());
    ASSERT_EQ('j', ms2.ReadByte());
    ASSERT_EQ('o', ms2.ReadByte());
    ASSERT_EQ('u', ms2.ReadByte());
    ASSERT_EQ('r', ms2.ReadByte());
    ASSERT_EQ(-1, ms2.ReadByte());
  }
  
  TEST(MemoryStreamTest, ReadMsdn) {
    IO::MemoryStream s;
    for(int32 i = 0; i < 122; i++)
      s.WriteByte((byte)i);
    s.Position = 0;
    
    // Now read s into a byte buffer with a little padding.
    int32 bytesCount = Convert::ToInt32(s.Length()) + 10;
    Array<byte> bytes(bytesCount);
    int numBytesToRead = (int)s.Length();
    int numBytesRead = 0;
    do {
      // Read may return anything from 0 to 10.
      int n = s.Read(bytes, numBytesRead, 10);
      numBytesRead += n;
      numBytesToRead -= n;
    } while(numBytesToRead > 0);
    s.Close();
    ASSERT_EQ(0, numBytesToRead);
    ASSERT_EQ(122, numBytesRead);
    ASSERT_TRUE(s.IsClosed());
    ASSERT_THROW(s.ReadByte(), ObjectDisposedException);
    ASSERT_THROW(s.Read(bytes, 0, 1), ObjectDisposedException);
    ASSERT_THROW(s.Seek(0, IO::SeekOrigin::Begin), ObjectDisposedException);
    ASSERT_THROW(s.Capacity = 0, ObjectDisposedException);
    ASSERT_THROW(s.Position = 0, ObjectDisposedException);
    ASSERT_THROW(s.Write({'1', '4', '5'}, 0, 1), ObjectDisposedException);
    ASSERT_THROW(s.WriteByte(1), ObjectDisposedException);
  }
  
}
