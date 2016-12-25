#include <Pcf/System/IO/BinaryWriter.h>
#include <Pcf/System/IO/BinaryReader.h>
#include <Pcf/System/IO/File.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::IO;
using namespace TUnit;

TEST(BinaryWriter, Ctor) {
  BinaryWriter writer(File::Open("TestBinary.dat", FileMode::Create, FileAccess::Write).Release());
}

TEST(BinaryWriter, ReadWrite) {

  pcf_using(up<BinaryWriter> binaryWriter = up<BinaryWriter>::Create(File::Open("TestBinary.dat", FileMode::Create, FileAccess::Write).Release())) {
    binaryWriter->Write(Boolean(true));
    binaryWriter->Write(Byte(0xF3));
    binaryWriter->Write(Char('Z'));
    binaryWriter->Write(Int16(759));
    binaryWriter->Write(Int32(3458));
    binaryWriter->Write(Box(Int64::MaxValue));
    binaryWriter->Write(SByte(0x24));
    binaryWriter->Write(Box(Single::Epsilon));
    binaryWriter->Write(string("Test for string"));
    binaryWriter->Write(UInt16(0xF012));
    binaryWriter->Write(UInt32(0xF0014578));
    binaryWriter->Write(UInt64(0xFFF0000012345678ULL));
  }

  pcf_using(up<BinaryReader> binaryReader = up<BinaryReader>::Create(File::Open("TestBinary.dat", FileMode::Open, FileAccess::Read).Release())) {
    EXPECT_EQ(true, binaryReader->ReadBoolean());
    EXPECT_EQ(0xF3, binaryReader->ReadByte());
    EXPECT_EQ('Z', binaryReader->ReadChar());
    EXPECT_EQ(759, binaryReader->ReadInt16());
    EXPECT_EQ(3458, binaryReader->ReadInt32());
    EXPECT_EQ(Int64::MaxValue, binaryReader->ReadInt64());
    EXPECT_EQ(0x24, binaryReader->ReadSByte());
    EXPECT_EQ(Single::Epsilon, binaryReader->ReadSingle());
    EXPECT_EQ("Test for string", binaryReader->ReadString());
    EXPECT_EQ(0xF012, binaryReader->ReadUInt16());
    EXPECT_EQ(0xF0014578, binaryReader->ReadUInt32());
    EXPECT_EQ(0xFFF0000012345678ULL, binaryReader->ReadUInt64());
  }
}

