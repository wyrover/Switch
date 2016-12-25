#include <Pcf/Pcf>

using namespace System;

double ComputeMean(const Array<Tuple<string, int>>& scores, int& n) {
  n = 0;
  int sum = 0;
  for (Tuple<string, int> score : scores) {
    if (score.Item2 >= 0) {
      n += 1;
      sum += score.Item2;
    }
  }
  if (n > 0)
    return sum / (double) n;
  else
    return 0;
}

int main(int argc, char* argv[]) {
  Array<Tuple<string, int>> scores = {
    {"Jack", 78},
    {"Abbey", 92},
    {"Dave", 88},
    {"Sam", 91},
    {"Ed", -1},
    {"Penelope", 82},
    {"Linda", 99},
    {"Judith", 84}
  };
  int number = 0;
  double mean = ComputeMean(scores, number);
  Console::WriteLine("Average test score: {0:%02.00f} (n={1})", mean, number);
}

// This code produces the following output:
//        Average test score: 88 (n=7)
