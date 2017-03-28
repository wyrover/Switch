#include <Pcf/System/Collections/BitArray.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Collections;
using namespace TUnit;

namespace {

TEST(BitArray, Constructor) {
  EXPECT_THROW(Collections::BitArray falseBits(-1), ArgumentOutOfRangeException);
}

TEST(BitArray, Constructor_Size) {
  Collections::BitArray falseBits(33);
  EXPECT_EQ(33, falseBits.Count);
  for (int32 i = 0; i < falseBits.Length; i++)
    EXPECT_FALSE(falseBits[i]);
}

TEST(BitArray, Constructor_Size_True) {
  Collections::BitArray trueBits(Int32(33), true);
  EXPECT_EQ(trueBits.Count, 33);
  for (Int32 i = 0; i < trueBits.Length; i++)
    EXPECT_TRUE(trueBits[i]);
}

TEST(BitArray, Constructor_Copy) {
  Collections::BitArray falseBits(33);
  Collections::BitArray copyFalseBits(falseBits);
  EXPECT_EQ(copyFalseBits.Count, 33);
  for (Int32 i = 0; i < copyFalseBits.Length; i++)
    EXPECT_FALSE(copyFalseBits[i]);
  
  Collections::BitArray trueBits(Int32(33), true);
  Collections::BitArray copyTrueBits(trueBits);
  EXPECT_EQ(copyTrueBits.Count, 33);
  for (Int32 i = 0; i < copyTrueBits.Length; i++)
    EXPECT_TRUE(copyTrueBits[i]);
}

TEST(BitArray, Constructor_Array_Byte) {
  Array<byte> bytes = {0, 1, 2, 4, 8};    // 0        1        2        4        8
  Collections::BitArray bytesBits(bytes); // 00000000 10000000 01000000 00100000 00010000
  EXPECT_EQ(bytesBits.Count, 40);         //          |8        |17       |26       |35

  for (int32 i = 0; i<40 ; i++)
    if (i == 8 || i == 17 || i == 26 || i == 35)
      ASSERT_TRUE(bytesBits[i]);
    else
      ASSERT_FALSE(bytesBits[i]);
}

TEST(BitArray, Constructor_Array_Int32) {
  Array<int32> int32s = {2, 5};             // 2               5
  Collections::BitArray int32sBits(int32s); // 0100...         10  100...
  EXPECT_EQ(int32sBits.Count, 64);          //  |1             |32 |34

  for (int32 i = 0; i<64; i++)
    if (i == 1 || i == 32 || i == 34)
      ASSERT_TRUE(int32sBits[i]);
    else
      ASSERT_FALSE(int32sBits[i]);
}

TEST(BitArray, Length) {
  Collections::BitArray bits(254000);
  EXPECT_EQ(bits.Count, 254000);
  
  EXPECT_EQ(bits.Get(0), false);
  bits[0] = true;
  EXPECT_EQ(bits.Get(0), true);
  EXPECT_EQ(bits[0], true);
  
  bits[0] = false;
  EXPECT_EQ(bits.Get(0), false);
  EXPECT_EQ(bits[0], false);
  
  EXPECT_EQ(bits[10], false);
  bits[10] = true;
  EXPECT_EQ(bits.Get(10), true);
  EXPECT_EQ(bits[10], true);
  
  EXPECT_EQ(bits[24], false);
  bits.Set(24, true);
  EXPECT_EQ(bits.Get(24), true);
  EXPECT_EQ(bits[24], true);
  
  bits.Set(24, false);
  EXPECT_EQ(bits.Get(24), false);
  
  EXPECT_EQ(bits[31], false);
  bits[31] = true;
  EXPECT_EQ(bits.Get(31), true);
  EXPECT_EQ(bits[31], true);
  
  EXPECT_EQ(bits[253900], false);
  bits[253900] = true;
  EXPECT_EQ(bits.Get(253900), true);
  EXPECT_EQ(bits[253900], true);
}

}