#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;
using namespace System::Threading::Tasks;

namespace Examples {
  class Program {
  public:
    static void Main() {
      // Get a folder path whose directories should throw an UnauthorizedAccessException.
      string path = Directory::GetParent(Environment::GetFolderPath(Environment::SpecialFolder::UserProfile)).FullName;
      
      // Use this line to throw UnauthorizedAccessException, which we handle.
      //Task<Array<string>> task1 = Task<>::Factory().StartNew<Array<string>>(pcf_delegate {return GetAllFiles(path);});
      
      // Use this line to throw an exception that is not handled.
      Task<> task1 = Task<>::Factory().StartNew(pcf_delegate {throw new IndexOutOfRangeException();});
      try {
        task1.Wait();
      } catch (const AggregateException& ae) {
        ae.Handle(pcf_delegate(const Exception& x)->bool {
          if (is<UnauthorizedAccessException>(x)) {// This we know how to handle.
            Console::WriteLine("You do not have permission to access all folders in this path.");
            Console::WriteLine("See your network administrator or try another path.");
            return true;
          }
          return false; // Let anything else stop the application.
        });
      }
      
      Console::WriteLine("task1 Status: {0}{1}", task1.IsCompleted ? "Completed," : "", task1.Status);
    }
    
  private:
    static Array<string> GetAllFiles(const string& str) {
      // Should throw an UnauthorizedAccessException exception.
      //return System::IO::Directory::GetFiles(str, "*.txt", System::IO::SearchOption::AllDirectories);
      return System::IO::Directory::GetFiles(str, "*.txt");
    }
  };
}

pcf_startup (Examples::Program)
