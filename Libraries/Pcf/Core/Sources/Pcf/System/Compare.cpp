#include "../../../Includes/Pcf/System/Compare.h"

using namespace System;

bool Compare::Equals(const void* e1, const void* e2) {
  return e1 == e2;
}

bool Compare::Equals(const Object& e1, const Object& e2) {
  return e1.Equals(e2);
}

bool Compare::Equals(const NullType&, const NullType&) {
  return true;
}

bool Compare::Equals(bool e1, bool e2) {
  return e1 == e2;
}

bool Compare::Equals(char e1, char e2) {
  return e1 == e2;
}

bool Compare::Equals(sbyte e1, sbyte e2) {
  return e1 == e2;
}

bool Compare::Equals(int16 e1, int16 e2) {
  return e1 == e2;
}

bool Compare::Equals(int32 e1, int32 e2) {
  return e1 == e2;
}

bool Compare::Equals(int64 e1, int64 e2) {
  return e1 == e2;
}

bool Compare::Equals(byte e1, byte e2) {
  return e1 == e2;
}

bool Compare::Equals(uint16 e1, uint16 e2) {
  return e1 == e2;
}

bool Compare::Equals(uint32 e1, uint32 e2) {
  return e1 == e2;
}

bool Compare::Equals(double e1, double e2) {
  return e1 == e2;
}

bool Compare::Equals(float e1, float e2) {
  return e1 == e2;
}

bool Compare::Equals(uint64 e1, uint64 e2) {
  return e1 == e2;
}

int32 Compare::CompareTo(const IComparable& e1, const IComparable& e2) {
  return e1.CompareTo(e2);
}

int32 Compare::CompareTo(const NullType&, const NullType&) {
  return 0;
}

int32 Compare::CompareTo(bool e1, bool e2) {
  return e1-e2;
}

int32 Compare::CompareTo(char e1, char e2) {
  return e1-e2;
}

int32 Compare::CompareTo(sbyte e1, sbyte e2) {
  return e1-e2;
}

int32 Compare::CompareTo(int16 e1, int16 e2) {
  return e1-e2;
}

int32 Compare::CompareTo(int32 e1, int32 e2) {
  return e1-e2;
}

int32 Compare::CompareTo(int64 e1, int64 e2) {
  return (e1<e2)?-1:((e1 == e2)?0:1);
}

int32 Compare::CompareTo(byte e1, byte e2) {
  return e1-e2;
}

int32 Compare::CompareTo(uint16 e1, uint16 e2) {
  return e1-e2;
}

int32 Compare::CompareTo(uint32 e1, uint32 e2) {
  return e1-e2;
}

int32 Compare::CompareTo(uint64 e1, uint64 e2) {
  return (e1<e2)?-1:((e1 == e2)?0:1);
}

int32 Compare::CompareTo(double e1, double e2) {
  return (e1<e2)?-1:((e1 == e2)?0:1);
}

int32 Compare::CompareTo(float e1, float e2) {
  return (e1<e2)?-1:((e1 == e2)?0:1);
}


int32 Compare::CompareTo(const void* e1, const void* e2) {
  return (e1<e2)?-1:((e1 == e2)?0:1);
}


