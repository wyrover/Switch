#include "../../../../Includes/Switch/System/Net/WebRequestMethods.hpp"

using namespace System;
using namespace System::Net;

property<string, readonly> WebRequestMethods::File::DownloadFile {
  [] {return "GET";}
};

property<string, readonly> WebRequestMethods::File::UploadFile {
  [] {return "PUT";}
};

property<string, readonly> WebRequestMethods::Ftp::DownloadFile {
  [] {return "FtpDownloadFile";}
};

property<string, readonly> WebRequestMethods::Ftp::UploadFile {
  [] {return "FtpUploadFile";}
};

property<string, readonly> WebRequestMethods::Ftp::ListDirectory {
  [] {return "ListDirectory";}
};

property<string, readonly> WebRequestMethods::Ftp::ListDirectoryDetails {
  [] {return "ListDirectoryDetails";}
};

property<string, readonly> WebRequestMethods::Ftp::MakeDirectory {
  [] {return "MakeDirectory";}
};

property<string, readonly> WebRequestMethods::Http::Get {
  [] {return "GET";}
};

property<string, readonly> WebRequestMethods::Http::Head {
  [] {return "HEAD";}
};

property<string, readonly> WebRequestMethods::Http::Post {
  [] {return "POST";}
};

property<string, readonly> WebRequestMethods::Http::Put {
  [] {return "PUT";}
};

property<string, readonly> WebRequestMethods::Http::Delete {
  [] {return "DELETE";}
};

property<string, readonly> WebRequestMethods::Http::Trace {
  [] {return "TRACE";}
};

property<string, readonly> WebRequestMethods::Http::Options {
  [] {return "OPTIONS";}
};
