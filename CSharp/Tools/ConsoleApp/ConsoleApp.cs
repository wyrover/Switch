using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp {
  class Prgoram {
    public static void Main() {
      Console.WriteLine("Hello, World!");
      Console.ReadKey(true);
    }
  }

  class Program2 {
    public static void Main() {
      int counter = 0;
      Action action = delegate {
        Console.WriteLine("counter -> {0}", ++counter);
      };

      var t = Task.Factory.StartNew(action);
    }
  }
}