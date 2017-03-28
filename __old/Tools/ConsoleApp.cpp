#include <cstdint>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]) {
  //cout << "Hello, World!" << endl;

  auto start = high_resolution_clock::now();
  vector<int> values;
  for (int value = 0; value < 1000000; value++)
    values.push_back(value);
  auto d = high_resolution_clock::now() - start;

  cout << "duration = "<< d.count() / 100 << endl;
  cout << "count = " << values.size() << endl;

  cin.ignore();
}
