#include <Switch/Types.hpp>
#include <Switch/System/Buffer.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {

  TEST(BufferTest, BlockCompare) {
    char block1[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVW";
    char block2[] = "0123456789BACDEFGHIJKLMNOPQRSTUVW";
    
    EXPECT_LT(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, sizeof(block1)), 0);
    ASSERT_EQ(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, 10), 0);
    EXPECT_GT(Buffer::BlockCompare(block2, sizeof(block2), 0, block1, sizeof(block1), 0, sizeof(block2)), 0);
    ASSERT_EQ(Buffer::BlockCompare(block1, sizeof(block1), 2, block2, sizeof(block2), 2, 5), 0);
    EXPECT_LT(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 2, 8), 0);
    EXPECT_GT(Buffer::BlockCompare(block1, sizeof(block1), 2, block2, sizeof(block2), 0, 8), 0);
    
    ASSERT_THROW(Buffer::BlockCompare(null, sizeof(block1), 0, block2, sizeof(block2), 0, 10), ArgumentNullException);
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, null, sizeof(block2), 0, 10), ArgumentNullException);
    
    ASSERT_THROW(Buffer::BlockCompare(block1, -1, 0, block2, sizeof(block2), 0, 10), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), -1, block2, sizeof(block2), 0, 10), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, -1, 0, 10), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), -1, 10), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, -1), ArgumentOutOfRangeException);
    
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 1, block2, sizeof(block2), 0, sizeof(block1)), ArgumentException);
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 1, sizeof(block1)), ArgumentException);
    ASSERT_THROW(Buffer::BlockCompare(block1, sizeof(block1), 0, block2, sizeof(block2), 0, sizeof(block1) + 1), ArgumentException);
  }
  
  TEST(BufferTest, BlockCopy) {
    Array<int32> a1 = {10, 20, 30, 40, 50, 60, 70, 80, 100};
    Array<byte> a2 = {1, 2, 3, 4, 5, 6};
    
    ASSERT_EQ(30, a1[2]);
    Buffer::BlockCopy(a2, 1, a1, 8, 4);
    ASSERT_EQ(0x05040302, a1[2]);
    
    char source[48];
    for (Int32 index = 0; index < 48; index++)
      source[index] = 0x10 + static_cast<sbyte>(index);
    char target[48];
    for (Int32 index = 0; index < 48; index++)
      target[index] = 0x01;
      
    for (Int32 index = 0; index < 48; index++)
      ASSERT_EQ(source[index], 0x10 + index);
    for (Int32 index = 0; index < 48; index++)
      ASSERT_EQ(target[index], 0x01);
      
    Buffer::BlockCopy(source, 48, 0, target, 48, 0, 1);
    ASSERT_EQ(target[0], 0x10);
    
    Buffer::BlockCopy(source, 48, 0, target, 48, 5, 1);
    ASSERT_EQ(target[4], 0x01);
    ASSERT_EQ(target[5], 0x10);
    ASSERT_EQ(target[6], 0x01);
    
    Buffer::BlockCopy(source, 48, 5, target, 48, 10, 1);
    ASSERT_EQ(target[9], 0x01);
    ASSERT_EQ(target[10], 0x15);
    ASSERT_EQ(target[11], 0x01);
    
    Buffer::BlockCopy(source, 48, 0, target, 48, 0, 48);
    for (Int32 index = 0; index < 48; index++)
      ASSERT_EQ(target[index], 0x10 + index);
      
    ASSERT_THROW(Buffer::BlockCopy(null, 48, 0, target, 48, 0, 48), ArgumentNullException);
    ASSERT_THROW(Buffer::BlockCopy(source, 48, 0, null, 48, 0, 48), ArgumentNullException);
    
    ASSERT_THROW(Buffer::BlockCopy(source, -1, 0, target, 48, 0, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCopy(source, 48, -1, target, 48, 0, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCopy(source, 48, 0, target, -1, 0, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, -1, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, 0, -1), ArgumentOutOfRangeException);
    
    ASSERT_THROW(Buffer::BlockCopy(source, 48, 1, target, 48, 0, 48), ArgumentException);
    ASSERT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, 1, 48), ArgumentException);
    ASSERT_THROW(Buffer::BlockCopy(source, 48, 0, target, 48, 0, 49), ArgumentException);
  }
  
  TEST(BufferTest, BlockFill) {
    char mem[48];
    for (Int32 index = 0; index < 48; index++)
      mem[index] = 0x10;
    for (Int32 index = 0; index < 48; index++)
      ASSERT_EQ(mem[index], 0x10);
      
    Buffer::BlockFill(0x24, mem, 48, 0, 1);
    ASSERT_EQ(mem[0], 0x24);
    ASSERT_EQ(mem[1], 0x10);
    
    Buffer::BlockFill(0x24, mem, 48, 10, 1);
    ASSERT_EQ(mem[9], 0x10);
    ASSERT_EQ(mem[10], 0x24);
    ASSERT_EQ(mem[11], 0x10);
    
    Buffer::BlockFill(0x24, mem, 48, 20, 2);
    ASSERT_EQ(mem[19], 0x10);
    ASSERT_EQ(mem[20], 0x24);
    ASSERT_EQ(mem[21], 0x24);
    ASSERT_EQ(mem[22], 0x10);
    
    Buffer::BlockFill(0x24, mem, 48, 0, 48);
    for (Int32 index = 0; index < 48; index++)
      ASSERT_EQ(mem[index], 0x24);
      
    ASSERT_THROW(Buffer::BlockFill(0x24, null, 48, 0, 48), ArgumentNullException);
    
    ASSERT_THROW(Buffer::BlockFill(0x24, mem, -1, 0, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockFill(0x24, mem, 48, -1, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockFill(0x24, mem, 48, 0, -1), ArgumentOutOfRangeException);
    
    ASSERT_THROW(Buffer::BlockFill(0x24, mem, 48, 0, 49), ArgumentException);
    ASSERT_THROW(Buffer::BlockFill(0x24, mem, 48, 1, 48), ArgumentException);
  }
  
  TEST(BufferTest, BlockZero) {
    char mem[48];
    for (Int32 index = 0; index < 48; index++)
      mem[index] = 0x10;
    for (Int32 index = 0; index < 48; index++)
      ASSERT_EQ(mem[index], 0x10);
      
    Buffer::BlockZero(mem, 48, 0, 1);
    ASSERT_EQ(mem[0], 0);
    ASSERT_EQ(mem[1], 0x10);
    
    Buffer::BlockZero(mem, 48, 10, 1);
    ASSERT_EQ(mem[9], 0x10);
    ASSERT_EQ(mem[10], 0);
    ASSERT_EQ(mem[11], 0x10);
    
    Buffer::BlockZero(mem, 48, 20, 2);
    ASSERT_EQ(mem[19], 0x10);
    ASSERT_EQ(mem[20], 0);
    ASSERT_EQ(mem[21], 0);
    ASSERT_EQ(mem[22], 0x10);
    
    Buffer::BlockZero(mem, 48, 0, 48);
    for (Int32 index = 0; index < 48; index++)
      ASSERT_EQ(mem[index], 0);
      
    ASSERT_THROW(Buffer::BlockZero(null, 48, 0, 48), ArgumentNullException);
    
    ASSERT_THROW(Buffer::BlockZero(mem, -1, 0, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockZero(mem, 48, -1, 48), ArgumentOutOfRangeException);
    ASSERT_THROW(Buffer::BlockZero(mem, 48, 0, -1), ArgumentOutOfRangeException);
    
    ASSERT_THROW(Buffer::BlockZero(mem, 48, 0, 49), ArgumentException);
    ASSERT_THROW(Buffer::BlockZero(mem, 48, 1, 48), ArgumentException);
  }
  
  TEST(BufferTest, ByteLength) {
    ASSERT_EQ(10, Buffer::ByteLength(Array<byte> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_EQ(20, Buffer::ByteLength(Array<int16> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_EQ(40, Buffer::ByteLength(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_EQ(80, Buffer::ByteLength(Array<int64> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_EQ(10, Buffer::ByteLength(Array<sbyte> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_EQ(20, Buffer::ByteLength(Array<uint16> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_EQ(40, Buffer::ByteLength(Array<uint32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_EQ(80, Buffer::ByteLength(Array<uint64> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
    ASSERT_THROW(Buffer::ByteLength(Array<DateTime>(3)), ArgumentException);
  }
  
  TEST(BufferTest, GetByte) {
    ASSERT_EQ(1, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 0));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 2));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3));
    ASSERT_EQ(2, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 6));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 7));
    ASSERT_EQ(3, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 8));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 9));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 11));
    ASSERT_EQ(4, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 12));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 13));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 14));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 15));
    ASSERT_EQ(5, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 16));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 17));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 18));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 19));
    ASSERT_EQ(6, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 20));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 21));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 22));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 23));
    ASSERT_EQ(7, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 24));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 25));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 26));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 27));
    ASSERT_EQ(8, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 28));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 29));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 30));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 31));
    ASSERT_EQ(9, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 32));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 33));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 34));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 35));
    ASSERT_EQ(10, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 36));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 37));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 38));
    ASSERT_EQ(0, Buffer::GetByte(Array<int32> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 39));
    ASSERT_THROW(Buffer::ByteLength(Array<DateTime>(3)), ArgumentException);
  }
  
  TEST(BufferTest, SetByte) {
    Array<int32> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_NO_THROW(Buffer::SetByte(array, 0, 24));
    ASSERT_NO_THROW(Buffer::SetByte(array, 12, 32));
    ASSERT_EQ(24, array[0]);
    ASSERT_EQ(32, array[3]);
  }
}
