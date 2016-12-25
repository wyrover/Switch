#include <Pcf/System/Net/HttpWebRequest.h>
#include <Pcf/System/IO/StreamReader.h>
#include <Pcf/System/IO/StreamWriter.h>
#include <Pcf/System/Console.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace System::Net;
using namespace System::IO;
using namespace TUnit;

TEST(HttpWebRequestIT, DISABLED_Get) {
  //int32 nbRead;
  
    Up<HttpWebRequest> request=WebRequest::Create("http://httpbin.org/get").ChangeType<HttpWebRequest>();
  
  HttpWebResponse& response=(HttpWebResponse&)request->GetResponse();
  Sp<Stream> stream=response.GetResponseStream();
  
  Sp<StreamReader> streamReader= new StreamReader(stream);
  Int32 i=0;
  while (!streamReader->EndOfStream())
    Console::WriteLine("{0} : {1}", i++, streamReader->ReadLine());
  streamReader->Close();
  
  
  Console::WriteLine("Status {0}: {1}", (int32)response.StatusCode(),  response.StatusDescription);
  Console::WriteLine("Content length: {0}", response.ContentLength);
  Console::WriteLine("Content Type: {0}", response.ContentType);
}

TEST(HttpWebRequestIT, DISABLED_Put) {
 // int32 nbRead;
  string data="Send data to server through http put method";
  Up<HttpWebRequest> request=WebRequest::Create("http://httpbin.org/put").ChangeType<HttpWebRequest>();
  request->Method = "PUT";
  request->ContentType = "text/plain";
  request->ContentLength = data.Length();
  request->Timeout = 10000;

  Sp<Stream> stream=request->GetRequestStream();
  Sp<StreamWriter> streamWriter= new StreamWriter(stream);
  streamWriter->WriteLine(data);
  streamWriter->Close();  

  HttpWebResponse& response=(HttpWebResponse&)request->GetResponse();  
  Console::WriteLine("Status {0}: {1}", (int32)response.StatusCode(),  response.StatusDescription);
  Console::WriteLine("Content length: {0}", response.ContentLength);
  Console::WriteLine("Content Type: {0}", response.ContentType);
}

TEST(HttpWebRequestIT, DISABLED_Post) {
 // int32 nbRead;
  string data="Field1=test1&Field2=test2";
  Up<HttpWebRequest> request=WebRequest::Create("http://httpbin.org/post").ChangeType<HttpWebRequest>();
  request->Timeout = 10000;
  request->Method = "POST";
  request->ContentType = "application/x-www-form-urlencoded";
  request->ContentLength = data.Length();
  
  Sp<Stream> stream=request->GetRequestStream();
  Sp<StreamWriter> streamWriter= new StreamWriter(stream);
  streamWriter->WriteLine(data);
  streamWriter->Close();
  
  HttpWebResponse& response=(HttpWebResponse&)request->GetResponse();  
  Sp<Stream> responseStream=response.GetResponseStream();
  Sp<StreamReader> streamReader= new StreamReader(responseStream);
  Int32 i=0;
  while (!streamReader->EndOfStream())
    Console::WriteLine(i++ + " : " +streamReader->ReadLine());
  streamReader->Close();
  
  Console::WriteLine("Status {0}: {1}", (int32)response.StatusCode(),  response.StatusDescription);
  Console::WriteLine("Content length: {0}", response.ContentLength);
  Console::WriteLine("Content Type: {0}", response.ContentType);
}

