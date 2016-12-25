using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp {
  class Prgoram {
    public static void Main() {
      System.Security.SecureString password = new System.Security.SecureString();
      password.AppendChar('M');
      password.AppendChar('y');
      password.AppendChar(' ');
      password.AppendChar('P');
      password.AppendChar('a');
      password.AppendChar('s');
      password.AppendChar('s');
      password.AppendChar('w');
      password.AppendChar('o');
      password.AppendChar('r');
      password.AppendChar('d');
      ProcessStartInfo si = new ProcessStartInfo();
      si.UseShellExecute = false;
      si.FileName = "C:\\WINDOWS\\system32\\Notepad.exe";
      //si.Arguments = "/C echo \"Hello, World!\"";
      Process process = Process.Start(si);
      process.WaitForExit();
      Console.ReadKey(true);
    }
  }
}