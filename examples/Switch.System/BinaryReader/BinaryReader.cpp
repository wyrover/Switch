#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create and write into binary file stream.
      _using(BinaryWriter binaryWriter(FileStream(Path::Combine(Path::GetTempPath(), "SwitchTest.bin"), FileMode::Create))) {
        binaryWriter.Write(true);
        binaryWriter.Write(1.25);
        binaryWriter.Write(4);
        binaryWriter.Write(Array<byte> {10, 29, 32, 42});
        binaryWriter.Write("This is a test");
      }

      // Open and read from binary file stream.
      _using(BinaryReader binaryReader(FileStream(Path::Combine(Path::GetTempPath(), "SwitchTest.bin"), FileMode::Open))) {
        Console::WriteLine("Boolean: {0}", binaryReader.ReadBoolean());
        Console::WriteLine("Double: {0}", binaryReader.ReadDouble());
        Console::WriteLine("Array<byte>: {{{0}}}", string::Join(", ", binaryReader.ReadBytes(binaryReader.ReadInt32())));
        Console::WriteLine("String: \"{0}\"", binaryReader.ReadString());
      }

      // Delete binary file stream.
      File::Delete(Path::Combine(Path::GetTempPath(), "SwitchTest.bin"));
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Boolean: True
// Double: 1.25
// Array<byte>: {10, 29, 32, 42}
// String: "This is a test"
