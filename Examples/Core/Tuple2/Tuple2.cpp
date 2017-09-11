#include <Switch/Switch>

using namespace System;

namespace Test {
  class Program {
  public:
    static void Main() {
      Array<Tuple<string, Nullable<int>>> scores = {
        {"Jack", 78},
        {"Abbey", 92},
        {"Dave", 88},
        {"Sam", 91},
        {"Ed", null},
        {"Penelope", 82},
        {"Linda", 99},
        {"Judith", 84}
      };
      int number = 0;
      double mean = ComputeMean(scores, number);
      Console::WriteLine("Average test score: {0:G2} (n={1})", mean, number);
    }

  private:
    static double ComputeMean(const Array<Tuple<string, Nullable<int>>>& scores, int& n) {
      n = 0;
      int sum = 0;
      for (auto score : scores) {
        if (score.Item2().HasValue) {
          n += 1;
          sum += score.Item2().Value;
        }
      }
      if (n > 0)
        return sum / (double) n;
      else
        return 0;
    }
  };
}

startup (Test::Program)

// This code produces the following output:
//
// Average test score: 88 (n=7)
