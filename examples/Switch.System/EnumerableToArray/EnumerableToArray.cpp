#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;

namespace Examples {
  class Program {
    class Package : public object {
    public:
      Package() {}
      Package(const string& company, double weight) : company(company), weight(weight) {}
      Package(const Package& package) : company(package.company), weight(package.weight) {}
      Package& operator=(const Package& package) {
        this->company = package.company;
        this->weight = package.weight;
        return *this;
      }

      _property<string, _readonly> Company {
        [&] { return this->company; }
      };

      _property<double, _readonly> Weight {
        [&] { return this->weight; }
      };

      string ToString() const { return string::Format("{0} {1}", this->company, this->weight); }

    private:
      string company;
      double weight = 0;
    };

  public:
    // The main entry point for the application.
    static void Main() {
      List<Package> packages = {Package("Coho Vineyard", 25.2), Package("Clucerne Publishing", 18.7), Package("Wingtip Toys", 6.0), Package("Adventure Works", 33.8)};

      Array<Package> companies = packages.ToArray();

      for (Package item : companies)
        Console::WriteLine(item);
    }
  };
}

_startup(Examples::Program);

// This code produces the following output:
//
// Coho Vineyard 25.2
// Clucerne Publishing 18.7
// Wingtip Toys 6
// Adventure Works 33.8
