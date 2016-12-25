#include <Pcf/Pcf>

using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;

class Package : public object {
public:
  Package() {}
  Package(const string& company, double weight) : company(company), weight(weight) {}
  Package(const Package& package) : company(package.company), weight(package.weight) {}

  Property<string, ReadOnly> Company {
    [&] { return this->company; }
  };

  Property<double, ReadOnly> Weight {
    [&] { return this->weight; }
  };

  string ToString() const { return string::Format("{0} {1}", this->company, this->weight); }

private:
  string company;
  double weight = 0;
};

int main(int argc, char* argv[]) {
  List<Package> packages = {Package("Coho Vineyard", 25.2), Package("Clucerne Publishing", 18.7), Package("Wingtip Toys", 6.0), Package("Adventure Works", 33.8)};
  
  Array<Package> companies = packages.ToArray();
  
  for (Package item : companies)
    Console::WriteLine(item);
}

// This code produces the following output:
//
// Coho Vineyard 25.2
// Clucerne Publishing 18.7
// Wingtip Toys 6
// Adventure Works 33.8
