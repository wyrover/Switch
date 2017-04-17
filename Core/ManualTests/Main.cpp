#include <Pcf/Core.h>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    static void Main() {
      //Console::WriteLine("Hello, World!");

      pcf_using(BinaryWriter bw(FileStream(Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Desktop), "Test.bin"), FileMode::Create))) {
        bw.Write(true);
        bw.Write(4);
        bw.Write(Array<byte> {10, 29, 32, 42});
        bw.Write("This is the voice");
      }

      pcf_using(BinaryReader br(FileStream(Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Desktop), "Test.bin"), FileMode::Open))) {
        Console::WriteLine(br.ReadBoolean());
        Console::WriteLine("{{{0}}}", string::Join(", ", br.ReadBytes(br.ReadInt32())));
        Console::WriteLine(br.ReadString());
      }
    }
  };
}

pcf_startup (Examples::Program)
