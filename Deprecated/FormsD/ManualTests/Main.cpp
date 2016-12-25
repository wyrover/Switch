#include <TUnitlib.h>
#include <Corelib.h>

#if _WIN32_WCE

int Main(int argc, char* argv[], char** /*env[]*/) {
  try {
    testing::InitGoogleTest(&argc, argv);
    int rc = RUN_ALL_TESTS();
    
    for(int i = 0; i <argc; i++) {
      if (!strcmp(argv[i], "--test_wait=true") || !strcmp(argv[i], "--tw")) {
        System::Console::WriteLine("Press ENTER to exit...");
        System::Console::ReadKey(true);
      }
    }
    return rc;
  } catch(const std::exception& e) {
    System::Console::WriteLine(e.what());
    return -1;
  }
}

void Main(const System::Array<string>& args) {
  delete testing::UnitTest::GetInstance()->listeners().Release(testing::UnitTest::GetInstance()->listeners().default_result_printer());
  testing::UnitTest::GetInstance()->listeners().Append(new GTestPcfPrinter());
  
  Up<char*[]> argv = new char*[args.GetLength()];
  for (int i = 0; i < args.GetLength(); i++)
    argv[i] = const_cast<char*>(args[i].GetData());
  System::Environment::SetExitCode(Main(args.GetLength(), argv.ToPointer(), null));
}

InitMain(&Main);

#else

int main(int argc, char* argv[], char** /*env[]*/) {
  try {
    testing::InitGoogleTest(&argc, argv);
    int rc = RUN_ALL_TESTS();
    
    for(int i = 0; i <argc; i++) {
      if (!strcmp(argv[i], "--test_wait=true") || !strcmp(argv[i], "--tw")) {
        std::cout << "Press ENTER to exit..." << std::endl;
        getchar();
      }
    }
    return rc;
  } catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
}

#endif

