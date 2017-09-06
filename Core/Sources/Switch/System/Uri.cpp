#include "../../../Includes/Switch/System/Uri.hpp"

using namespace System;

property<string, readonly> Uri::SchemeDelimiter {
  [] {return "://";}
};

property<string, readonly> Uri::UriSchemeFile {
  [] {return "file";}
};

property<string, readonly> Uri::UriSchemeFtp {
  [] {return "ftp";}
};

property<string, readonly> Uri::UriSchemeGopher {
  [] {return "gopher";}
};

property<string, readonly> Uri::UriSchemeHttp {
  [] {return "http";}
};

property<string, readonly> Uri::UriSchemeHttps {
  [] {return "https";}
};

property<string, readonly> Uri::UriSchemeMailto {
  [] {return "mailto";}
};

property<string, readonly> Uri::UriSchemeNetPipe {
  [] {return "net.pipe";}
};

property<string, readonly> Uri::UriSchemeNetTcp {
  [] {return "net.tcp";}
};

property<string, readonly> Uri::UriSchemeNews {
  [] {return "news";}
};

property<string, readonly> Uri::UriSchemeNntp {
  [] {return "nntp";}
};
