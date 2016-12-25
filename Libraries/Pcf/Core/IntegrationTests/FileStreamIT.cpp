#include <Pcf/System/IO/FileStream.h>
#include <Pcf/System/IO/FileNotFoundException.h>
#include <Pcf/System/IO/Directory.h>
#include <Pcf/System/IO/File.h>
#include <Pcf/System/IO/Path.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

// To use a test fixture, derive a class from testing::Test.  
class FileStream : public testing::Test {  

protected: 
  void SetUp() override {
    mPathWorkDir = IO::Path::Combine(IO::Directory::GetCurrentDirectory(), "FileStreamTest");
    if (IO::Directory::Exists(mPathWorkDir))
      IO::Directory::Delete(mPathWorkDir, true);
    IO::Directory::CreateDirectory(mPathWorkDir);
    mFileName = IO::Path::Combine(mPathWorkDir ,"TestFile.txt");
    mDoesNotExistFile = IO::Path::Combine(mPathWorkDir,"doesnotexist.txt");
    mExistingFile = IO::Path::Combine(mPathWorkDir,"exist.txt");

    mLine1 = "Test jmi"; 
    mLine2 = "Test Yfi"; 
    mLine3 = "Test jmi appended"; 
    mLine4 = "Test Byte operation\n"; 

    mShare = IO::FileShare::None;

    if (IO::File::Exists(mDoesNotExistFile))
      IO::File::Delete(mDoesNotExistFile);
  }    

  void TearDown() override {
    IO::Directory::Delete(mPathWorkDir, true);
    if (IO::File::Exists(mExistingFile))
      IO::File::Delete(mExistingFile);
  }

  void CreateExistingFile()  {
    std::fstream str;
    str.open(mExistingFile.ToCCharArray().Data(), std::fstream::binary | std::fstream::out);
    ASSERT_TRUE(str.is_open());
    str << "test";
    str.close();
  }


  void CreateExistingFile2Lines()  {
    std::fstream str;
    str.open(mExistingFile.ToCCharArray().Data(), std::fstream::binary | std::fstream::out);
    ASSERT_TRUE(str.is_open());
    str << "test\n" << "second line";
    str.close();
  }

  static void TestSizeAndDispose(const String& file, Sp<IO::FileStream>& fs, int64_t size) {
    int64_t fsSize = fs->Length();
    fs->Close();
    fs = Sp<IO::FileStream>::Null();
    EXPECT_TRUE(IO::File::Exists(file));
    std::fstream str;
    str.open(file.ToCCharArray().Data(), std::fstream::binary | std::fstream::in);
    str.seekg(0, std::ios::end);
    EXPECT_GE(str.tellg(),size);
    EXPECT_GE(fsSize,size);
    str.close();
  }


  static void TestAndDelete(const String& file, Sp<IO::FileStream>& fs) {
    fs->Close();
    fs = Sp<IO::FileStream>::Null();
    EXPECT_TRUE(IO::File::Exists(file));
    IO::File::Delete(file);
  }

  static void CreateNotEmptyTextFile( String fileName) {
    Up<IO::StreamWriter> streamWriter = IO::File::CreateText(fileName);
    streamWriter.Reset();
  }

  static void TestProperties(const Sp<IO::FileStream>& fs, bool seek, bool read, bool write, bool closed) {
    EXPECT_EQ(seek, fs->CanSeek());
    EXPECT_EQ(read, fs->CanRead());
    EXPECT_EQ(write, fs->CanWrite());
    EXPECT_EQ(closed, fs->IsClosed());
  }

  static void DumpBytes(const String& file, byte* bytes, int32 size) {
    std::fstream str;
    str.open(file.ToCCharArray().Data(), std::fstream::binary | std::fstream::out);
    ASSERT_TRUE(str.is_open());
    str.write((const char*)bytes,size);
    str.close();
  }

  // Declares the variables your tests want to use.  
  String mDoesNotExistFile;
  String mExistingFile;
  String mPathWorkDir;
  String mFileName;
  String mLine1; 
  String mLine2; 
  String mLine3; 
  String mLine4; 
  IO::FileMode mMode;
  IO::FileAccess mAccess;
  IO::FileShare mShare;
};  


TEST_F(FileStream, Constructor_Append_Read_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::Append;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), ArgumentException);
}

TEST_F(FileStream, Constructor_Create_Read_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::Create;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare),ArgumentException);
}

TEST_F(FileStream, Constructor_CreateNew_Read_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::CreateNew;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare),ArgumentException);
}

TEST_F(FileStream, Constructor_Open_Read_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::Open;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), IO::FileNotFoundException);
}

TEST_F(FileStream, Constructor_OpenOrCreate_Read_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::OpenOrCreate;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, true, false, false);
  TestAndDelete(mDoesNotExistFile, fs);
}

TEST_F(FileStream, Constructor_Truncate_Read_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::Truncate;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), IO::FileNotFoundException);
}

TEST_F(FileStream, Constructor_Append_Write_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::Append;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, false, true, false);
  TestAndDelete(mDoesNotExistFile,fs);
}

TEST_F(FileStream, Constructor_Create_Write_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::Create;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, false, true, false);
  TestAndDelete(mDoesNotExistFile,fs);
}

TEST_F(FileStream, Constructor_CreateNew_Write_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::CreateNew;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, false, true, false);
  TestAndDelete(mDoesNotExistFile,fs);
}

TEST_F(FileStream, Constructor_Open_Write_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::Open;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), IO::FileNotFoundException);
}

TEST_F(FileStream, Constructor_OpenOrCreate_Write_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::OpenOrCreate;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, false, true, false);
  TestAndDelete(mDoesNotExistFile,fs);
}

TEST_F(FileStream, Constructor_Truncate_Write_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::Truncate;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), IO::FileNotFoundException);
}

TEST_F(FileStream, Constructor_Append_ReadWrite_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::Append;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), ArgumentException);
}

TEST_F(FileStream, Constructor_Create_ReadWrite_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;  
  mMode = IO::FileMode::Create;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, true, true, false);
  TestAndDelete(mDoesNotExistFile,fs);
}

TEST_F(FileStream, Constructor_CreateNew_ReadWrite_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::CreateNew;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, true, true, false);
  TestAndDelete(mDoesNotExistFile,fs);
}

TEST_F(FileStream, Constructor_Open_ReadWrite_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::Open;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), IO::FileNotFoundException);
}

TEST_F(FileStream, Constructor_OpenOrCreate_ReadWrite_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::OpenOrCreate;
  fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare);
  TestProperties(fs,true, true, true, false);
  TestAndDelete(mDoesNotExistFile,fs);
}

TEST_F(FileStream, Constructor_Truncate_ReadWrite_Unexisting_File) {
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::Truncate;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mDoesNotExistFile, mMode, mAccess, mShare), IO::FileNotFoundException);
}

TEST_F(FileStream, Constructor_Append_Read_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::Append;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare), ArgumentException);
}

TEST_F(FileStream, Constructor_Create_Read_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::Create;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare), ArgumentException);
}

TEST_F(FileStream, Constructor_CreateNew_Read_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::CreateNew;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare), ArgumentException);
}

TEST_F(FileStream, Constructor_Open_Read_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::Open;
  fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare);
  TestProperties(fs,true, true, false, false);
  TestSizeAndDispose(mExistingFile,fs,4L);
}

TEST_F(FileStream, Constructor_OpenOrCreate_Read_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Read;
  mMode = IO::FileMode::OpenOrCreate;
  fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare);
  TestProperties(fs,true, true, false, false);
  TestSizeAndDispose(mExistingFile, fs,4L);
}

TEST_F(FileStream, Constructor_Truncate_Write_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::Truncate;
  fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare);
  TestProperties(fs, true, false, true, false);
  TestSizeAndDispose(mExistingFile,fs,0L);
}


TEST_F(FileStream, Constructor_Append_ReadWrite_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::Append;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare), ArgumentException);
}

TEST_F(FileStream, Constructor_Create_ReadWrite_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::Create;
  fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare);
  TestProperties(fs, true, true, true, false);
  TestSizeAndDispose(mExistingFile,fs,0L);
}

TEST_F(FileStream, Constructor_CreateNew_ReadWrite_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::CreateNew;
  EXPECT_THROW(fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare), IO::IOException);
}

TEST_F(FileStream, Constructor_Open_ReadWrite_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::Open;
  fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare);
  TestProperties(fs, true, true, true, false);
  TestSizeAndDispose(mExistingFile,fs,4L);
}

TEST_F(FileStream, Constructor_OpenOrCreate_ReadWrite_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::OpenOrCreate;
  fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare);
  TestProperties(fs, true, true, true, false);
  TestSizeAndDispose(mExistingFile,fs,4L);
}

TEST_F(FileStream, Constructor_Truncate_ReadWrite_Existing_File) {
  CreateExistingFile();
  Sp<IO::FileStream> fs;
  mAccess = IO::FileAccess::ReadWrite;
  mMode = IO::FileMode::Truncate;
  fs = Sp<IO::FileStream>::Create(mExistingFile, mMode, mAccess, mShare);
  TestProperties(fs, true, true, true, false);
  TestSizeAndDispose(mExistingFile,fs,0L);
}


TEST_F(FileStream, StreamReader_FileStream_Peek_Read) {
  CreateExistingFile();
  mMode = IO::FileMode::Open;
  mAccess = IO::FileAccess::Read;

  Sp<IO::StreamReader> sr = new IO::StreamReader(new IO::FileStream(mExistingFile, mMode, mAccess));
  EXPECT_EQ('t', sr->Peek());
  EXPECT_EQ('t', sr->Read());
  EXPECT_EQ('e', sr->Peek());
  EXPECT_EQ('e', sr->Read());
  EXPECT_EQ('s', sr->Read());
  EXPECT_EQ('t', sr->Peek());
  EXPECT_EQ('t', sr->Read());
  EXPECT_EQ( -1, sr->Peek());
  EXPECT_EQ( -1, sr->Read());
  EXPECT_EQ( -1, sr->Peek());
}

TEST_F(FileStream, StreamReader_FileStream_ReadLine) {
  mMode = IO::FileMode::Open;
  mAccess = IO::FileAccess::Read;

  CreateExistingFile2Lines();
  Sp<IO::StreamReader> sr = new IO::StreamReader(new IO::FileStream(mExistingFile, mMode, mAccess));

  EXPECT_TRUE(sr->ReadLine().Equals("test"));
  EXPECT_TRUE(sr->ReadLine().Equals("second line"));
  EXPECT_TRUE(sr->ReadLine().Equals(""));
}


TEST_F(FileStream, FileStreamMethods) {
  mMode = IO::FileMode::CreateNew;
  IO::FileStream Stream(mFileName, mMode);
  EXPECT_TRUE(Stream.CanWrite());
  EXPECT_TRUE(Stream.CanSeek());

  char buffer[] = {'a','b','c','d','e','f','g','h','i','j'};
  Stream.Write((uint8_t*)buffer, sizeof(buffer), 0, sizeof(buffer));
  Stream.Flush();
  EXPECT_EQ(Stream.Length(), (int32_t)sizeof(buffer));
  EXPECT_EQ(Stream.Position(), (int32_t)sizeof(buffer));

  Stream.WriteByte((uint8_t)'k');
  Stream.Flush();
  EXPECT_EQ(Stream.Length(), (int32_t)sizeof(buffer)+1);
  EXPECT_EQ(Stream.Position(), (int32_t)sizeof(buffer)+1);

  int64 offset = 3;
  Stream.Position = offset;
  EXPECT_EQ(Stream.Position(),offset);
  EXPECT_EQ(buffer[Convert::ToInt32(offset)],Stream.ReadByte());
  EXPECT_EQ(Stream.Position(),offset+1);

  Stream.Position = 0;
  EXPECT_EQ(Stream.Position(),0);
  char readBuffer[100];
  memset(readBuffer, 0, sizeof(readBuffer));
  EXPECT_EQ(Stream.Read((uint8_t*)readBuffer, sizeof(readBuffer), 0, sizeof(buffer)), (int32_t)sizeof(buffer));
  for (int32_t k = 0; k < (int32_t)sizeof(buffer); k++)
    EXPECT_EQ(readBuffer[k],buffer[k]);
  Stream.Close();
}


TEST_F(FileStream, StreamReaderWriterConstructor) {
  {
    EXPECT_THROW(IO::StreamReader streamReader(mFileName), IO::FileNotFoundException);
  }
  {
    IO::StreamWriter streamWriter(mFileName, false);
    Sp<IO::Stream> stream = streamWriter.BaseStream();
    EXPECT_TRUE(stream->CanWrite());
    EXPECT_FALSE(streamWriter.AutoFlush());
    streamWriter.WriteLine(mLine1);
    //EXPECT_TRUE(stream->GetLength() == 0);
    streamWriter.AutoFlush = true;
    EXPECT_TRUE(streamWriter.AutoFlush());
    streamWriter.WriteLine(mLine1);
    EXPECT_TRUE(stream->Length() > 0);
    streamWriter.Close();
  }
  {
    IO::StreamWriter streamWriter(mFileName, true);
    Sp<IO::Stream> stream = streamWriter.BaseStream();
    EXPECT_TRUE(stream->CanWrite());
    streamWriter.Close();
  }
  {
    IO::StreamReader streamReader(mFileName);
    Sp<IO::Stream> stream = streamReader.BaseStream();
    EXPECT_TRUE(stream->CanRead());
    streamReader.Close();
  }
  {
    IO::StreamReader streamReader(mFileName);
    String lineR;
    while (!streamReader.EndOfStream())
    {
      lineR=streamReader.ReadLine();
    }
    streamReader.Close();
    EXPECT_EQ(lineR,mLine1);
  }
}


TEST_F(FileStream, StreamReaderWriterOperations) {
  pcf_using(Up<IO::StreamWriter> streamWriter1 = IO::File::CreateText(mFileName)) {
    streamWriter1->WriteLine(mLine1);
    streamWriter1->WriteLine(mLine2);
  }

  pcf_using(Up<IO::StreamWriter> streamWriter2 = IO::File::AppendText(mFileName)) {
    streamWriter2->WriteLine(mLine3);
    // Test Byte operation
    for (int32_t k=0; k<mLine4.Length(); k++)
      streamWriter2->Write(mLine4[k]);
  }

  pcf_using(Up<IO::StreamReader> streamReader = IO::File::OpenText(mFileName)) {
    String readLine = streamReader->ReadLine();
    EXPECT_EQ(mLine1, readLine);
    readLine = streamReader->ReadLine();
    EXPECT_EQ(mLine2, readLine);
    readLine = streamReader->ReadLine();
    EXPECT_EQ(mLine3, readLine);
    
    char buffer[2048];
    int32_t charRead = 0;
    int32_t k=0;
    for (; k<mLine4.Length() && (charRead = streamReader->Read()) >= 0; k++)
      buffer[k] = (char)charRead;
    buffer[k] = 0;
    readLine = buffer;
    EXPECT_EQ(mLine4, readLine);
    
    readLine = streamReader->ReadLine();
    EXPECT_EQ(String::Empty, readLine);
    EXPECT_TRUE(streamReader->EndOfStream());
  }
}

TEST_F(FileStream, ReadToEnd) {
  pcf_using(Up<IO::StreamWriter> streamWriter = IO::File::CreateText(mFileName)) {
    streamWriter->WriteLine(mLine1);
    streamWriter->WriteLine(mLine2);
  }

  pcf_using(Up<IO::StreamReader> streamReader = IO::File::OpenText(mFileName)) {
    String allContent = streamReader->ReadToEnd();
    EXPECT_TRUE(allContent.Contains(mLine1) && allContent.Contains(mLine2));
  }
}

TEST_F(FileStream, FileSize) {
  pcf_using(Up<IO::StreamWriter> streamWriter = IO::File::CreateText(mFileName)) {
    streamWriter->AutoFlush = true;
    streamWriter->Write(mLine1);
    Sp<IO::Stream> stream = streamWriter->BaseStream();
    EXPECT_EQ(mLine1.Length(), stream->Length());
  }
}

// todo JVI ?
/*TEST_F(FileStream, GetFilePosition)
{
  Sp<IO::StreamWriter> streamWriter = IO::File::CreateText(mFileName);
  streamWriter->SetAutoFlush(true);
  streamWriter->Write(mLine1);
  streamWriter.Release();

  char buffer[64];
  Int32 position = 3;
  Sp<IO::StreamReader> streamReader = IO::File::OpenText(mFileName);
  streamReader->ReadBlock(buffer, sizeof(buffer), 0, position);
  Sp<IO::Stream> stream = streamReader->GetBaseStream();
  Int64 streamPos = stream->GetPosition();
  EXPECT_EQ(position,streamPos);
  streamReader.Release();
}*/

TEST_F(FileStream, SetFilePosition) {
  String str("This a test of file position");
  int64 position = 10;

  // Write the line in the file
  pcf_using(Up<IO::StreamWriter> streamWriter = IO::File::CreateText(mFileName)) {
    streamWriter->WriteLine(str);
  }

  // Open a read stream, set file position et check the read character
  IO::FileStream fileStream(mFileName, IO::FileMode(IO::FileMode::Open), IO::FileAccess(IO::FileAccess::ReadWrite), IO::FileShare(IO::FileShare::None));
  fileStream.Position = position;
  EXPECT_TRUE(position == fileStream.Position());
  uint32_t readChar = fileStream.ReadByte();
  EXPECT_TRUE(str[(uint32_t)position] == readChar);
  fileStream.Close();
}

TEST_F(FileStream, FileCopyMove) {
  CreateNotEmptyTextFile(mFileName);
  EXPECT_TRUE(IO::File::Exists(mFileName));

  // File copy
  IO::FileInfo FileInfo(mFileName);
  String destPath = IO::Path::Combine(FileInfo.DirectoryName(), String("FileCopy") + IO::Path::GetExtension(mFileName));
  String path = IO::Path::Combine(mPathWorkDir,"TestDummy.txt");
  EXPECT_THROW(IO::File::Copy(path, destPath), IO::FileNotFoundException);

  IO::File::Copy(mFileName, destPath);

  // Check File existence
  EXPECT_TRUE(IO::File::Exists(destPath));
  // Overwrite
  IO::File::Copy(mFileName, destPath, true);

  // Copy if dest. file already exist => throw IOExceptionError
  EXPECT_THROW(IO::File::Copy(mFileName, destPath), IO::IOException);
  EXPECT_THROW(IO::File::Copy(mFileName, destPath, false), IO::IOException);
  EXPECT_THROW(IO::File::Copy(mFileName, mPathWorkDir), IO::IOException);

  // Move
  String movedPath = IO::Path::Combine(FileInfo.DirectoryName(), String("FileMoved") + IO::Path::GetExtension(mFileName));

  // Source file is a directory => throw FileNotFoundException
  EXPECT_THROW(IO::File::Move(mPathWorkDir, movedPath), IO::FileNotFoundException);
  IO::File::Move(mFileName, movedPath);
  EXPECT_FALSE(IO::File::Exists(mFileName));
  EXPECT_TRUE(IO::File::Exists(movedPath));
  // Destination file already exists => throw IOExceptionError
  EXPECT_THROW(IO::File::Move(destPath, movedPath), IO::IOException);
}

TEST_F(FileStream, FileAttributes) {
  IO::FileAttributes fileAttributes = IO::File::GetAttributes(mPathWorkDir);
  EXPECT_TRUE(Enum<IO::FileAttributes>(fileAttributes).HasFlag(IO::FileAttributes::Directory));

  //  file does not exist exists => throw IOExceptionError
  EXPECT_THROW(IO::File::GetAttributes(mFileName), IO::IOException);

  CreateNotEmptyTextFile(mFileName);
  fileAttributes = IO::File::GetAttributes(mFileName);
  EXPECT_TRUE(Enum<IO::FileAttributes>(fileAttributes).HasFlag(IO::FileAttributes::Archive));
}

TEST_F(FileStream, OpenCloseWriteAppend) {
  mAccess = IO::FileAccess::Write;
  mMode = IO::FileMode::Append;
  Sp<IO::FileStream> fs = new IO::FileStream(mFileName, mMode, mAccess, mShare);
  
  pcf_using(Sp<IO::StreamWriter> sw = new IO::StreamWriter(fs.ChangeType<IO::Stream>())) {
    sw->WriteLine("first line");
    fs->Close();
    EXPECT_THROW(sw->WriteLine(String("Bad line")), ObjectClosedException);
    fs->Open();
    sw->WriteLine(String("second line"));
    fs->Close();
  }

  mMode = IO::FileMode::Open;
  mAccess = IO::FileAccess::Read;
  pcf_using(Sp<IO::StreamReader> sr = new IO::StreamReader(new IO::FileStream(mFileName, mMode, mAccess, mShare))) {
    EXPECT_EQ("first line", sr->ReadLine());
    EXPECT_EQ("second line", sr->ReadLine());
    EXPECT_TRUE(sr->EndOfStream());
  }
}

TEST_F(FileStream, OpenCloseWriteCreate) {
  mMode = IO::FileMode::Create;
  mAccess = IO::FileAccess::Write;
  Sp<IO::FileStream> fs = new IO::FileStream(mFileName, mMode, mAccess, mShare);
  
  pcf_using(Sp<IO::StreamWriter> sw = new IO::StreamWriter(fs.ChangeType<IO::Stream>())) {
    sw->WriteLine("first line");
    fs->Close();
    EXPECT_THROW(sw->WriteLine(String("Bad line")), ObjectClosedException);
    fs->Open();
    sw->WriteLine(String("second line"));
    fs->Close();
  }

  mMode = IO::FileMode::Open;
  mAccess = IO::FileAccess::Read;
  Sp<IO::StreamReader> sr = new IO::StreamReader(new IO::FileStream(mFileName, mMode, mAccess, mShare));
  EXPECT_EQ(sr->ReadLine(), "first line");
  EXPECT_EQ(sr->ReadLine(), "second line");
  EXPECT_TRUE(sr->EndOfStream());
}


TEST_F(FileStream, OpenCloseRead) {
  CreateExistingFile2Lines();
  mMode = IO::FileMode::Open;
  mAccess = IO::FileAccess::Read;
  Sp<IO::FileStream> fs = new IO::FileStream(mExistingFile, mMode,mAccess,mShare);
  IO::StreamReader sw(fs.ChangeType<IO::Stream>());

  String line;

  line = sw.ReadLine();
  EXPECT_EQ(line,"test");
  fs->Close();
  EXPECT_THROW(sw.ReadLine(), ObjectClosedException);
  fs->Open();
  line = sw.ReadLine();
  EXPECT_EQ(line,"second line");
  fs->Close();
}