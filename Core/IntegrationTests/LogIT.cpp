#include <Pcf/Pcf>

using namespace System;
using namespace System::IO;
using namespace System::LogStreams;

namespace {

class Log : public testing::Test {  
protected: 

  string mLogPath;

  virtual void SetUp() {
    mLogPath="LogUnitTest.log";
    FileInfo logFile(mLogPath);
    if (logFile.Exists())
      logFile.Delete();
  }

  virtual void TearDown() {

  }

  void FillLog(LogStream& log,const int32 size) {
    int32 curSize = 0;
    static int32_t count = 0;
    LogStreamChannel Channel("FillLog");
    string line(" Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam quis massa sed dolor condimentum mattis.");
    while (curSize < size) {
      log.WriteLine(Channel,LogStreamLevel(LogStreamLevel::Debug),Int32(count).ToString() + line);
      curSize += line.Length();
      count++;
    }
  }
};


TEST_F(Log, CreateLog) {
  LogStream log(mLogPath,LogStreamLevel(LogStreamLevel::Debug),"Pcf","Pcf","LogUnittTest");
  LogStreamChannel Channel("CreateLog");
  log.WriteLine(Channel,LogStreamLevel(LogStreamLevel::Debug),"Log created");
  log.Close();
  FileInfo logFile(mLogPath);
  EXPECT_GT(logFile.GetLength(),0);
}


TEST_F(Log,AppendLog) {
  LogStreamChannel Channel("AppendLog");
  LogStream log(mLogPath,LogStreamLevel(LogStreamLevel::Debug),"Pcf","Pcf","LogUnittTest");
  log.WriteLine(Channel,LogStreamLevel(LogStreamLevel::Debug),"Log created");
  log.Close();
  FileInfo logFile(mLogPath);
  int64 sizeCreated = logFile.GetLength();
  LogStream log1(mLogPath,LogStreamLevel(LogStreamLevel::Debug),"Pcf","Pcf","LogUnittTest");
  log1.WriteLine(Channel,LogStreamLevel(LogStreamLevel::Debug),"Log append");
  log1.Close();

  EXPECT_GT(logFile.GetLength(),sizeCreated);
}


TEST_F(Log,LevelLog) {
  LogStreamChannel Channel("LevelLog");
  LogStream log(mLogPath,LogStreamLevel(LogStreamLevel::Critical),"Pcf","Pcf","LogUnittTest");
  log.WriteLine(Channel,LogStreamLevel(LogStreamLevel::Critical),"Log created");
  FileInfo logFile(mLogPath);
  int64 sizeCreated = logFile.GetLength();
  log.WriteLine(Channel,LogStreamLevel(LogStreamLevel::Debug),"Not logged");
  EXPECT_EQ(logFile.GetLength(),sizeCreated);
  log.Close();
}


TEST_F(Log, SplitLog) {
  LogStreamChannel Channel("SpitLog");
  LogStream log(mLogPath,LogStreamLevel(LogStreamLevel::Debug),"Pcf","Pcf","LogUnittTest");
  string backupPath = Path::Combine(Path::GetDirectoryName(mLogPath),Path::GetFileNameWithoutExtension(mLogPath)+".bak");
  log.SetMaxStreamSize(5 * 1024);
  log.SetMaxNumberOfBackupFiles(4);
  FillLog(log, 20 * 1024);
  log.Close();
  for (int32 i = 0; i < log.GetMaxNumberOfBackupFiles(); i++) {
    FileInfo logFile((i == 0) ? backupPath : backupPath + i);
    EXPECT_TRUE(logFile.Exists());
    if (logFile.Exists())
      logFile.Delete();
  }
}


TEST_F(Log, NoSplitLog) {
  LogStreamChannel Channel("NoSpitLog");
  LogStream log(mLogPath,LogStreamLevel(LogStreamLevel::Debug),"Pcf","Pcf","LogUnittTest");
  //log.SetMaxNumberOfBackupFiles(0); todo JVI
  log.SetMaxNumberOfBackupFiles(1);
  FillLog(log, 5 * 1024);
  log.Close();
  FileInfo logFile(mLogPath + 1);
  EXPECT_FALSE(logFile.Exists());
}

}