#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      // Create and write into binary file stream.
      BinaryWriter bw(FileStream(Path::Combine(Path::GetTempPath(), "PcfTest.bin"), FileMode::Create));
      bw.Write(true);
      bw.Write(1.25);
      bw.Write(4);
      bw.Write(Array<byte> {10, 29, 32, 42});
      bw.Write("This is a test");
      bw.Close();
      
      // Open and read into binary file stream.
      BinaryReader br(FileStream(Path::Combine(Path::GetTempPath(), "PcfTest.bin"), FileMode::Open));
      Console::WriteLine("Boolean: {0}", br.ReadBoolean());
      Console::WriteLine("Double: {0}", br.ReadDouble());
      Console::WriteLine("Array<byte>: {{{0}}}", string::Join(", ", br.ReadBytes(br.ReadInt32())));
      Console::WriteLine("String: \"{0}\"", br.ReadString());
      br.Close();
      
      // Delete binary file stream.
      File::Delete(Path::Combine(Path::GetTempPath(), "PcfTest.bin"));
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Boolean: True
// Double: 1.25
// Array<byte>: {10, 29, 32, 42}
// String: "This is a test"
