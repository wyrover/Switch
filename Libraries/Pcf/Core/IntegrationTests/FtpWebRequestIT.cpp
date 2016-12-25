#include <Pcf/System/Net/FtpWebRequest.h>
#include <Pcf/System/Net/WebRequestMethods.h>
#include <Pcf/System/IO/DirectoryInfo.h>
#include <Pcf/System/IO/StreamReader.h>
#include <Pcf/System/Console.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace TUnit;

TEST(FtpWebRequestIT, DISABLED_ServerUnreachable) {
  Up<FtpWebRequest> request=WebRequest::Create("ftp://users.skynet.be/Test.txt").ChangeType<FtpWebRequest>();
  
  request->Method = WebRequestMethods::Ftp::DownloadFile;
  request->Credentials = NetworkCredential("yfi","yfi!");
  request->UseBinary = false;
  request->Timeout = 10000;

  EXPECT_THROW(request->GetResponse(), TimeoutException);  
}

TEST(FtpWebRequestIT, DISABLED_FtpDownloadNotFound) {
  Up<FtpWebRequest> request=WebRequest::Create("ftp://users.skynet.be/Test.txt").ChangeType<FtpWebRequest>();
  
  request->Method = WebRequestMethods::Ftp::DownloadFile;
  request->Credentials = NetworkCredential("yfi","yfi!");
  request->UseBinary = false;
  
  FtpWebResponse& response=(FtpWebResponse&)request->GetResponse();
  Sp<Stream> stream=response.GetResponseStream();
  
  Sp<StreamReader> streamReader= new StreamReader(stream);
  int32 i=0;
  while (!streamReader->EndOfStream()) {
    streamReader->ReadLine();
    i++;
    //Console::WriteLine(i++ + " : " +streamReader->ReadLine());
  }
  EXPECT_EQ(i,0);
  
  streamReader->Close();
  stream->Close();
  EXPECT_EQ(response.StatusCode, FtpStatusCode::ActionNotTakenFileUnavailable);
  Console::WriteLine("Status: {0}", response.StatusDescription);
  Console::WriteLine("Content length: {0}", response.ContentLength);
  Console::WriteLine("Content Type: {0}", response.ContentType);
}

TEST(FtpWebRequestIT, DISABLED_FtpDownload) {
  Up<FtpWebRequest> request=WebRequest::Create("ftp://users.skynet.be/Test.txt").ChangeType<FtpWebRequest>();
  
  request->Method = WebRequestMethods::Ftp::DownloadFile;
  request->Credentials = NetworkCredential("yfi","yfi!");
  request->UseBinary = false;
  
  FtpWebResponse& response=(FtpWebResponse&)request->GetResponse();
  Sp<Stream> stream=response.GetResponseStream();
  
  Sp<StreamReader> streamReader= new StreamReader(stream);
  int32 i=0;
  while (!streamReader->EndOfStream())
  {
    streamReader->ReadLine();
    //Console::WriteLine(i + " : " +streamReader->ReadLine());
    i++;
    
  }
  EXPECT_GT(i,0);
  
  streamReader->Close();
  stream->Close();
  EXPECT_EQ(response.StatusCode, FtpStatusCode::ClosingData);
  Console::WriteLine("Status: {0}", response.StatusDescription);
  Console::WriteLine("Content length: {0}", response.ContentLength);
  Console::WriteLine("Content Type: {0}", response.ContentType);
}

TEST(FtpWebRequestIT, DISABLED_FtpList) {
  Up<FtpWebRequest> request=WebRequest::Create(Uri("ftp://users.skynet.be/")).ChangeType<FtpWebRequest>();
  request->Method = WebRequestMethods::Ftp::ListDirectory;
  request->Credentials = NetworkCredential("yfi","yfi!");
  
  FtpWebResponse& response=(FtpWebResponse&)request->GetResponse();
  Sp<Stream> stream=response.GetResponseStream();
  
  Sp<StreamReader> streamReader=new StreamReader(stream);
  string file=streamReader->ReadLine();
  while (!string::IsNullOrEmpty(file)) {
    file=streamReader->ReadLine();
    
  }
  EXPECT_EQ(response.StatusCode, FtpStatusCode::ClosingData);
  Console::WriteLine("Status: {0}", response.StatusDescription);
  Console::WriteLine("Content length: {0}", response.ContentLength);
  Console::WriteLine("Content Type: {0}", response.ContentType);
}

TEST(FtpWebRequestIT, DISABLED_FtpUpload) {
  DirectoryInfo UploadDir(".");
  string url("ftp://users.skynet.be/Test.txt");
  if (UploadDir.Exists()) {
    Up<FtpWebRequest> createDirRequest=WebRequest::Create(url).ChangeType<FtpWebRequest>();
    createDirRequest->Credentials = NetworkCredential("yfi","yfi!");
    createDirRequest->Method = WebRequestMethods::Ftp::MakeDirectory;
    FtpWebResponse& createDirResponse = static_cast<FtpWebResponse&>(createDirRequest->GetResponse());
    if (createDirResponse.StatusCode != FtpStatusCode::ClosingData) {
      Console::WriteLine("Error created directory ({0}) {1}", createDirResponse.StatusCode, createDirResponse.StatusDescription);
    } else {
      static const int32_t bufferSize=16*1024;
      uint8_t buffer[bufferSize];
      Int32 nbRead=0;
      Sp<FileStream> fileStream;
      Up<FtpWebRequest> uploadRequest;
      Sp<Stream> stream;
      
      Array<FileInfo> filesToUpload = UploadDir.GetFiles();
      for (FileInfo file : filesToUpload) {
        Console::WriteLine("Start upload: " + file.FullName());
        
        //Upload each file
        uploadRequest=WebRequest::Create(url+file.Name()).ChangeType<FtpWebRequest>();
        uploadRequest->Method = WebRequestMethods::Ftp::UploadFile;
        uploadRequest->UseBinary = true;
        uploadRequest->Credentials = NetworkCredential("yfi","yfi!");
        
        fileStream= Sp<FileStream>::Create(file.FullName(),FileMode::Open);
        stream = uploadRequest->GetRequestStream();
        nbRead = fileStream->Read(buffer, bufferSize, 0, bufferSize);
        while (nbRead > 0) {
          stream->Write(buffer, bufferSize, 0, nbRead);
          nbRead = fileStream->Read(buffer, bufferSize, 0, bufferSize);
        }
        
        fileStream->Close();
        stream->Close();
        EXPECT_EQ(((FtpWebResponse&)uploadRequest->GetResponse()).StatusCode, FtpStatusCode::ClosingData);
        Console::WriteLine("File uploaded: {0} with status: {1}", file.Name(), ((FtpWebResponse&)uploadRequest->GetResponse()).StatusCode);
      }
    }
  } else {
    Console::WriteLine("Directory source not found");
  }
}

TEST(FtpWebRequestIT, DISABLED_MakeDir) {
  Up<FtpWebRequest> request=WebRequest::Create("ftp://users.skynet.be/Test.txt").ChangeType<FtpWebRequest>();
  request->Method = WebRequestMethods::Ftp::MakeDirectory;
  request->Credentials = NetworkCredential("yfi","yfi!");
  FtpWebResponse& response=(FtpWebResponse&)request->GetResponse();
  EXPECT_EQ(response.StatusCode, FtpStatusCode::ClosingData);
  Console::WriteLine("Status: {0}", response.StatusDescription);
}

TEST(FtpWebRequestIT, DISABLED_FtpListDetails) {
  Up<FtpWebRequest> request=WebRequest::Create("ftp://users.skynet.be/Test.txt").ChangeType<FtpWebRequest>();
  request->Method = WebRequestMethods::Ftp::ListDirectoryDetails;
  request->Credentials = NetworkCredential("yfi","yfi!");
  
  FtpWebResponse& response=(FtpWebResponse&)request->GetResponse();
  Sp<Stream> stream=response.GetResponseStream();
  
  Sp<StreamReader> streamReader=new StreamReader(stream);
  string fileDetails=streamReader->ReadLine();
  while (!string::IsNullOrEmpty(fileDetails)) {
    Console::WriteLine(fileDetails);
    if (Path::GetExtension(fileDetails).ToUpper().Equals(".APK")) {
      int32 index1 = fileDetails.LastIndexOf(" ");
      string fileName = fileDetails.Substring(index1 + 1);
      string dateAndFileSize = fileDetails.Substring(0, index1);
      int32 index2 = dateAndFileSize.LastIndexOf(" ");
      string fileSizeStr = dateAndFileSize.Substring(index2 + 1);
      int64 fileSize = Int64::Parse(fileSizeStr);
      Console::WriteLine("File name: " + fileName + ", file size: " + fileSize + " bytes");
    }
    fileDetails=streamReader->ReadLine();
  }
  EXPECT_EQ(response.StatusCode, FtpStatusCode::ClosingData);
  Console::WriteLine("Status: {0}", response.StatusDescription);
  Console::WriteLine("Content length: {0}", response.ContentLength);
  Console::WriteLine("Content Type: {0}", response.ContentType);
}
