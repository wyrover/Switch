#include <Switch/Switch>

using namespace System;
using namespace System::IO;

namespace Examples {
  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      for (auto file : Directory::GetFiles(Environment::GetFolderPath(Environment::SpecialFolder::Personal))) {
        FileInfo fileInfo(file);
        Console::WriteLine("Name: \"{0}\", attibute: [{1}], creation time: {2}", fileInfo.Name, fileInfo.Attributes, fileInfo.CreationTime);
      }
    }
  };
}

startup_(Examples::Program);

// This code produces output similar to the following:
//
// Name: "Informations.txt", attibute: [Archive, Normal], creation time: 03/02/2018 22:11:59
// Name: "Boot.jpeg", attibute: [ReadOnly, Archive, Normal], creation time: 21/01/2017 16:54:00

