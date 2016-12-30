#include <Pcf/Types.h>
#include <Pcf/System/Buffer.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace {
  
  TEST(Buffer, BlockCompare) {
    char block1[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVW";
    char block2[] = "0123456789BACDEFGHIJKLMNOPQRSTUVW";
    
    EXPECT_LT(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, sizeof(block1)), 0);
    EXPECT_EQ(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, 10), 0);
    EXPECT_GT(Buffer::BlockCompare(block2, sizeof(block2), 0, block1, sizeof(block1), 0, sizeof(block2)), 0);
    EXPECT_EQ(Buffer::BlockCompare(block1, sizeof(block1), 2, block2, sizeof(block2), 2, 5), 0);
    EXPECT_LT(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 2, 8), 0);
    EXPECT_GT(Buffer::BlockCompare(block1, sizeof(block1), 2, block2, sizeof(block2), 0, 8), 0);
    
    EXPECT_THROW(Buffer::BlockCompare(null, sizeof(block1), 0, block2, sizeof(block2), 0, 10), ArgumentNullException);
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, null, sizeof(block2), 0, 10), ArgumentNullException);
    
    EXPECT_THROW(Buffer::BlockCompare(block1, -1, 0, block2, sizeof(block2), 0, 10), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), -1, block2, sizeof(block2), 0, 10), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, -1, 0, 10), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), -1, 10), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, -1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 1, block2, sizeof(block2), 0, sizeof(block1)), ArgumentException);
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 1, sizeof(block1)), ArgumentException);
    EXPECT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, sizeof(block1)+1), ArgumentException);
  }
  
  TEST(Buffer, BlockCopy) {
    Array<int32> a1 = {10, 20, 30, 40, 50, 60, 70, 80, 100};
    Array<byte> a2 = {1, 2, 3, 4, 5, 6};
    
    EXPECT_EQ(30, a1[2]);
    Buffer::BlockCopy(a2, 1, a1, 8, 4);
    EXPECT_EQ(0x05040302, a1[2]);
    
    char source[48];
    for (Int32 index = 0; index < 48; index++)
      source[index]= 0x10 + static_cast<sbyte>(index);
    char target[48];
    for (Int32 index = 0; index < 48; index++)
      target[index]= 0x01;
    
    for (Int32 index = 0; index < 48; index++)
      EXPECT_EQ(source[index], 0x10 + index);
    for (Int32 index = 0; index < 48; index++)
      EXPECT_EQ(target[index], 0x01);
    
    Buffer::BlockCopy(source, 48, 0, target, 48, 0, 1);
    EXPECT_EQ(target[0], 0x10);
    
    Buffer::BlockCopy(source, 48, 0, target, 48, 5, 1);
    EXPECT_EQ(target[4], 0x01);
    EXPECT_EQ(target[5], 0x10);
    EXPECT_EQ(target[6], 0x01);
    
    Buffer::BlockCopy(source, 48, 5, target, 48, 10, 1);
    EXPECT_EQ(target[9], 0x01);
    EXPECT_EQ(target[10], 0x15);
    EXPECT_EQ(target[11], 0x01);
    
    Buffer::BlockCopy(source, 48, 0, target, 48, 0, 48);
    for (Int32 index = 0; index < 48; index++)
      EXPECT_EQ(target[index], 0x10 + index);
    
    EXPECT_THROW(Buffer::BlockCopy(null, 48, 0, target, 48, 0, 48), ArgumentNullException);
    EXPECT_THROW(Buffer::BlockCopy(source, 48, 0, null, 48, 0, 48), ArgumentNullException);
    
    EXPECT_THROW(Buffer::BlockCopy(source, -1, 0, target, 48, 0, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCopy(source, 48, -1, target, 48, 0, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCopy(source, 48, 0, target, -1, 0, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, -1, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, 0, -1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(Buffer::BlockCopy(source, 48, 1, target, 48, 0, 48), ArgumentException);
    EXPECT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, 1, 48), ArgumentException);
    EXPECT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, 0, 49), ArgumentException);
  }
  
  TEST(Buffer, BlockFill) {
    char mem[48];
    for (Int32 index = 0; index < 48; index++)
      mem[index]= 0x10;
    for (Int32 index = 0; index < 48; index++)
      EXPECT_EQ(mem[index], 0x10);
    
    Buffer::BlockFill(0x24, mem, 48, 0, 1);
    EXPECT_EQ(mem[0], 0x24);
    EXPECT_EQ(mem[1], 0x10);
    
    Buffer::BlockFill(0x24, mem, 48, 10, 1);
    EXPECT_EQ(mem[9], 0x10);
    EXPECT_EQ(mem[10], 0x24);
    EXPECT_EQ(mem[11], 0x10);
    
    Buffer::BlockFill(0x24, mem, 48, 20, 2);
    EXPECT_EQ(mem[19], 0x10);
    EXPECT_EQ(mem[20], 0x24);
    EXPECT_EQ(mem[21], 0x24);
    EXPECT_EQ(mem[22], 0x10);
    
    Buffer::BlockFill(0x24, mem, 48, 0, 48);
    for (Int32 index = 0; index < 48; index++)
      EXPECT_EQ(mem[index], 0x24);
    
    EXPECT_THROW(Buffer::BlockFill(0x24, null, 48, 0, 48), ArgumentNullException);
    
    EXPECT_THROW(Buffer::BlockFill(0x24, mem, -1, 0, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockFill(0x24, mem, 48, -1, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockFill(0x24, mem, 48, 0, -1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(Buffer::BlockFill(0x24, mem, 48, 0, 49), ArgumentException);
    EXPECT_THROW(Buffer::BlockFill(0x24, mem, 48, 1, 48), ArgumentException);
  }
  
  TEST(Buffer, BlockZero) {
    char mem[48];
    for (Int32 index = 0; index < 48; index++)
      mem[index]= 0x10;
    for (Int32 index = 0; index < 48; index++)
      EXPECT_EQ(mem[index], 0x10);
    
    Buffer::BlockZero(mem, 48, 0, 1);
    EXPECT_EQ(mem[0], 0);
    EXPECT_EQ(mem[1], 0x10);
    
    Buffer::BlockZero(mem, 48, 10, 1);
    EXPECT_EQ(mem[9], 0x10);
    EXPECT_EQ(mem[10], 0);
    EXPECT_EQ(mem[11], 0x10);
    
    Buffer::BlockZero(mem, 48, 20, 2);
    EXPECT_EQ(mem[19], 0x10);
    EXPECT_EQ(mem[20], 0);
    EXPECT_EQ(mem[21], 0);
    EXPECT_EQ(mem[22], 0x10);
    
    Buffer::BlockZero(mem, 48, 0, 48);
    for (Int32 index = 0; index < 48; index++)
      EXPECT_EQ(mem[index], 0);
    
    EXPECT_THROW(Buffer::BlockZero(null, 48, 0, 48), ArgumentNullException);
    
    EXPECT_THROW(Buffer::BlockZero(mem, -1, 0, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockZero(mem, 48, -1, 48), ArgumentOutOfRangeException);
    EXPECT_THROW(Buffer::BlockZero(mem, 48, 0, -1), ArgumentOutOfRangeException);
    
    EXPECT_THROW(Buffer::BlockZero(mem, 48, 0, 49), ArgumentException);
    EXPECT_THROW(Buffer::BlockZero(mem, 48, 1, 48), ArgumentException);
  }
  
  TEST(Buffer, ByteLength) {
    EXPECT_EQ(10, Buffer::ByteLength(Array<byte> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_EQ(20, Buffer::ByteLength(Array<int16> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_EQ(40, Buffer::ByteLength(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_EQ(80, Buffer::ByteLength(Array<int64> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_EQ(10, Buffer::ByteLength(Array<sbyte> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_EQ(20, Buffer::ByteLength(Array<uint16> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_EQ(40, Buffer::ByteLength(Array<uint32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_EQ(80, Buffer::ByteLength(Array<uint64> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    EXPECT_THROW(Buffer::ByteLength(Array<DateTime>(3)), ArgumentException);
  }
  
  TEST(Buffer, GetByte) {
    EXPECT_EQ(1, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 0));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3));
    EXPECT_EQ(2, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 7));
    EXPECT_EQ(3, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 8));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 11));
    EXPECT_EQ(4, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 12));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 13));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 14));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 15));
    EXPECT_EQ(5, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 16));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 17));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 18));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 19));
    EXPECT_EQ(6, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 20));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 21));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 22));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 23));
    EXPECT_EQ(7, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 24));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 25));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 26));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 27));
    EXPECT_EQ(8, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 28));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 29));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 30));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 31));
    EXPECT_EQ(9, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 32));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 33));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 34));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 35));
    EXPECT_EQ(10, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 36));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 37));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 38));
    EXPECT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 39));
    EXPECT_THROW(Buffer::ByteLength(Array<DateTime>(3)), ArgumentException);
  }
  
  TEST(Buffer, SetByte) {
    Array<int32> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    EXPECT_NO_THROW(Buffer::SetByte(array, 0, 24));
    EXPECT_NO_THROW(Buffer::SetByte(array, 12, 32));
    EXPECT_EQ(24, array[0]);
    EXPECT_EQ(32, array[3]);
  }
}