#include "../../../include/Switch/System/Uri.hpp"

using namespace System;

_property<string, _readonly> Uri::SchemeDelimiter {
  [] {return "://";}
};

_property<string, _readonly> Uri::UriSchemeFile {
  [] {return "file";}
};

_property<string, _readonly> Uri::UriSchemeFtp {
  [] {return "ftp";}
};

_property<string, _readonly> Uri::UriSchemeGopher {
  [] {return "gopher";}
};

_property<string, _readonly> Uri::UriSchemeHttp {
  [] {return "http";}
};

_property<string, _readonly> Uri::UriSchemeHttps {
  [] {return "https";}
};

_property<string, _readonly> Uri::UriSchemeMailto {
  [] {return "mailto";}
};

_property<string, _readonly> Uri::UriSchemeNetPipe {
  [] {return "net.pipe";}
};

_property<string, _readonly> Uri::UriSchemeNetTcp {
  [] {return "net.tcp";}
};

_property<string, _readonly> Uri::UriSchemeNews {
  [] {return "news";}
};

_property<string, _readonly> Uri::UriSchemeNntp {
  [] {return "nntp";}
};
