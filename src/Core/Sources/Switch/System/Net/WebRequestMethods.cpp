#include "../../../../Includes/Switch/System/Net/WebRequestMethods.hpp"

using namespace System;
using namespace System::Net;

_property<string, _readonly> WebRequestMethods::File::DownloadFile {
  [] {return "GET";}
};

_property<string, _readonly> WebRequestMethods::File::UploadFile {
  [] {return "PUT";}
};

_property<string, _readonly> WebRequestMethods::Ftp::DownloadFile {
  [] {return "FtpDownloadFile";}
};

_property<string, _readonly> WebRequestMethods::Ftp::UploadFile {
  [] {return "FtpUploadFile";}
};

_property<string, _readonly> WebRequestMethods::Ftp::ListDirectory {
  [] {return "ListDirectory";}
};

_property<string, _readonly> WebRequestMethods::Ftp::ListDirectoryDetails {
  [] {return "ListDirectoryDetails";}
};

_property<string, _readonly> WebRequestMethods::Ftp::MakeDirectory {
  [] {return "MakeDirectory";}
};

_property<string, _readonly> WebRequestMethods::Http::Get {
  [] {return "GET";}
};

_property<string, _readonly> WebRequestMethods::Http::Head {
  [] {return "HEAD";}
};

_property<string, _readonly> WebRequestMethods::Http::Post {
  [] {return "POST";}
};

_property<string, _readonly> WebRequestMethods::Http::Put {
  [] {return "PUT";}
};

_property<string, _readonly> WebRequestMethods::Http::Delete {
  [] {return "DELETE";}
};

_property<string, _readonly> WebRequestMethods::Http::Trace {
  [] {return "TRACE";}
};

_property<string, _readonly> WebRequestMethods::Http::Options {
  [] {return "OPTIONS";}
};
