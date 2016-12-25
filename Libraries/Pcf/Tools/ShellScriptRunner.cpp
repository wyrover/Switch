#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace ShellScriptRunner {
  class Program {
  public:
    static void Main() {
      UniquePointer<Process> process = Process::Start(Path::Combine(Path::GetDirectoryName(Environment::GetCommandLineArgs()[0]), "Script.sh"));
      File::WriteAllText(Path::Combine(Path::GetDirectoryName(Environment::GetCommandLineArgs()[0]), "ShellScriptRunner.output"), StreamReader(process->StandardOutput()).ReadToEnd());
      process->WaitForExit();
    }
  };
}

pcf_startup (ShellScriptRunner::Program)
