#include <cstring>

#include "../../../include/Switch/System/Buffer.hpp"

using namespace System;

int32 Buffer::BlockCompare(const void* blk1, int64 blk1Length, int64 blk1Offset, const void* blk2, int64 blk2Length, int64 blk2Offset, int64 count) {
  if (blk1 == null || blk2 == null)
    throw ArgumentNullException(_caller);
  if (blk2Offset < 0 || count < 0 || blk2Length < 0 || blk1Offset < 0 || blk1Length < 0)
    throw ArgumentOutOfRangeException(_caller);
  if (blk2Offset + count > blk2Length || blk1Offset + count > blk1Length)
    throw ArgumentException(_caller);
  
  if (sizeof(void*) == 4) // 32 bits build
    return memcmp(reinterpret_cast<const void*>((*(int32*)&blk1) + int32(blk1Offset)), reinterpret_cast<const void*>((*(int32*)&blk2) + int32(blk2Offset)), int32(count));
  return memcmp(reinterpret_cast<const void*>((int64)blk1 + blk1Offset), reinterpret_cast<const void*>((int64)blk2 + blk2Offset), (size_t)count);
}

void Buffer::BlockCopy(const void* src, int64 srcLength, int64 srcOffset, void* dst, int64 dstLenth, int64 dstOffset, int64 count) {
  if (src == null || dst == null)
    throw ArgumentNullException(_caller);
  if (dstOffset < 0 || count < 0 || dstLenth < 0 || srcOffset < 0 || srcLength < 0)
    throw ArgumentOutOfRangeException(_caller);
  if (dstOffset + count > dstLenth || srcOffset + count > srcLength)
    throw ArgumentException(_caller);

  if (sizeof(void*) == 4) // 32 bits build
    memmove(reinterpret_cast<void*>((*(int32*)&dst) + Convert::ToInt32(dstOffset)), reinterpret_cast<const void*>((*(int32*)&src) +  Convert::ToInt32(srcOffset)), Convert::ToInt32(count));
  else
    memmove(reinterpret_cast<void*>((int64)dst + dstOffset), reinterpret_cast<const void*>((int64)src + srcOffset), (size_t)count);
}

void Buffer::BlockFill(byte filler, void* dst, int64 dstLenth, int64 dstOffset, int64 count) {
  if (dst == null)
    throw ArgumentNullException(_caller);
  if (dstOffset < 0 || count < 0 || dstLenth < 0)
    throw ArgumentOutOfRangeException(_caller);
  if (dstOffset + count > dstLenth)
    throw ArgumentException(_caller);
  
  if (sizeof(void*) == 4) // 32 bits build
    memset(reinterpret_cast<void*>((*(int32*)&dst) + Convert::ToInt32(dstOffset)), filler,  Convert::ToInt32(count));
  else
    memset(reinterpret_cast<void*>((int64)dst + dstOffset), filler, (size_t)count);
}
