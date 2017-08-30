#include "../../../../Includes/Pcf/System/Net/WebRequestMethods.hpp"

using namespace System;
using namespace System::Net;

Property<string, ReadOnly> WebRequestMethods::File::DownloadFile {
  [] {return "GET";}
};

Property<string, ReadOnly> WebRequestMethods::File::UploadFile {
  [] {return "PUT";}
};

Property<string, ReadOnly> WebRequestMethods::Ftp::DownloadFile {
  [] {return "FtpDownloadFile";}
};

Property<string, ReadOnly> WebRequestMethods::Ftp::UploadFile {
  [] {return "FtpUploadFile";}
};

Property<string, ReadOnly> WebRequestMethods::Ftp::ListDirectory {
  [] {return "ListDirectory";}
};

Property<string, ReadOnly> WebRequestMethods::Ftp::ListDirectoryDetails {
  [] {return "ListDirectoryDetails";}
};

Property<string, ReadOnly> WebRequestMethods::Ftp::MakeDirectory {
  [] {return "MakeDirectory";}
};

Property<string, ReadOnly> WebRequestMethods::Http::Get {
  [] {return "GET";}
};

Property<string, ReadOnly> WebRequestMethods::Http::Head {
  [] {return "HEAD";}
};

Property<string, ReadOnly> WebRequestMethods::Http::Post {
  [] {return "POST";}
};

Property<string, ReadOnly> WebRequestMethods::Http::Put {
  [] {return "PUT";}
};

Property<string, ReadOnly> WebRequestMethods::Http::Delete {
  [] {return "DELETE";}
};

Property<string, ReadOnly> WebRequestMethods::Http::Trace {
  [] {return "TRACE";}
};

Property<string, ReadOnly> WebRequestMethods::Http::Options {
  [] {return "OPTIONS";}
};
