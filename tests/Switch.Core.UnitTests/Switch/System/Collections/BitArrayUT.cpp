#include <Switch/System/Collections/BitArray.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Collections;

namespace {

  TEST(BitArrayTest, Constructor) {
    ASSERT_THROW(Collections::BitArray falseBits(-1), ArgumentOutOfRangeException);
  }
  
  TEST(BitArrayTest, Constructor_Size) {
    Collections::BitArray falseBits(33);
    ASSERT_EQ(33, falseBits.Count);
    for (int32 index = 0; index < falseBits.Length; index++)
      ASSERT_FALSE(falseBits[index]);
  }
  
  TEST(BitArrayTest, Constructor_Size_True) {
    Collections::BitArray trueBits(Int32(33), true);
    ASSERT_EQ(trueBits.Count, 33);
    for (Int32 index = 0; index < trueBits.Length; index++)
      ASSERT_TRUE(trueBits[index]);
  }
  
  TEST(BitArrayTest, Constructor_Copy) {
    Collections::BitArray falseBits(33);
    Collections::BitArray copyFalseBits(falseBits);
    ASSERT_EQ(copyFalseBits.Count, 33);
    for (Int32 index = 0; index < copyFalseBits.Length; index++)
      ASSERT_FALSE(copyFalseBits[index]);
      
    Collections::BitArray trueBits(Int32(33), true);
    Collections::BitArray copyTrueBits(trueBits);
    ASSERT_EQ(copyTrueBits.Count, 33);
    for (Int32 index = 0; index < copyTrueBits.Length; index++)
      ASSERT_TRUE(copyTrueBits[index]);
  }
  
  TEST(BitArrayTest, Constructor_Array_Byte) {
    Array<byte> bytes = {0, 1, 2, 4, 8};    // 0        1        2        4        8
    Collections::BitArray bytesBits(bytes); // 00000000 10000000 01000000 00100000 00010000
    ASSERT_EQ(bytesBits.Count, 40);         //          |8        |17       |26       |35
    
    for (int32 index = 0; index < 40 ; index++)
      if (index == 8 || index == 17 || index == 26 || index == 35)
        ASSERT_TRUE(bytesBits[index]);
      else
        ASSERT_FALSE(bytesBits[index]);
  }
  
  TEST(BitArrayTest, Constructor_Array_Int32) {
    Array<int32> int32s = {2, 5};             // 2               5
    Collections::BitArray int32sBits(int32s); // 0100...         10  100...
    ASSERT_EQ(int32sBits.Count, 64);          //  |1             |32 |34
    
    for (int32 index = 0; index < 64; index++)
      if (index == 1 || index == 32 || index == 34)
        ASSERT_TRUE(int32sBits[index]);
      else
        ASSERT_FALSE(int32sBits[index]);
  }
  
  TEST(BitArrayTest, Length) {
    Collections::BitArray bits(254000);
    ASSERT_EQ(bits.Count, 254000);
    
    ASSERT_EQ(bits.Get(0), false);
    bits[0] = true;
    ASSERT_EQ(bits.Get(0), true);
    ASSERT_EQ(bits[0], true);
    
    bits[0] = false;
    ASSERT_EQ(bits.Get(0), false);
    ASSERT_EQ(bits[0], false);
    
    ASSERT_EQ(bits[10], false);
    bits[10] = true;
    ASSERT_EQ(bits.Get(10), true);
    ASSERT_EQ(bits[10], true);
    
    ASSERT_EQ(bits[24], false);
    bits.Set(24, true);
    ASSERT_EQ(bits.Get(24), true);
    ASSERT_EQ(bits[24], true);
    
    bits.Set(24, false);
    ASSERT_EQ(bits.Get(24), false);
    
    ASSERT_EQ(bits[31], false);
    bits[31] = true;
    ASSERT_EQ(bits.Get(31), true);
    ASSERT_EQ(bits[31], true);
    
    ASSERT_EQ(bits[253900], false);
    bits[253900] = true;
    ASSERT_EQ(bits.Get(253900), true);
    ASSERT_EQ(bits[253900], true);
  }
  
}
