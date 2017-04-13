#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      BinaryWriter bw(FileStream(Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Desktop), "Test.bin"), FileMode::Create));
      bw.Write(true);
      bw.Write(4);
      bw.Write(Array<byte> {10, 29, 32, 42});
      bw.Write("This is a test");
      bw.Close();
      
      BinaryReader br(FileStream(Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::Desktop), "Test.bin"), FileMode::Open));
      Console::WriteLine(br.ReadBoolean());
      Console::WriteLine("{{{0}}}", string::Join(", ", br.ReadBytes(br.ReadInt32())));
      Console::WriteLine(br.ReadString());
      br.Close();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// True
// {10, 29, 32, 42}
// This is a test
