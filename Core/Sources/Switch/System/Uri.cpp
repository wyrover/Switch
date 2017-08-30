#include "../../../Includes/Switch/System/Uri.hpp"

using namespace System;

Property<string, ReadOnly> Uri::SchemeDelimiter {
  [] {return "://";}
};

Property<string, ReadOnly> Uri::UriSchemeFile {
  [] {return "file";}
};

Property<string, ReadOnly> Uri::UriSchemeFtp {
  [] {return "ftp";}
};

Property<string, ReadOnly> Uri::UriSchemeGopher {
  [] {return "gopher";}
};

Property<string, ReadOnly> Uri::UriSchemeHttp {
  [] {return "http";}
};

Property<string, ReadOnly> Uri::UriSchemeHttps {
  [] {return "https";}
};

Property<string, ReadOnly> Uri::UriSchemeMailto {
  [] {return "mailto";}
};

Property<string, ReadOnly> Uri::UriSchemeNetPipe {
  [] {return "net.pipe";}
};

Property<string, ReadOnly> Uri::UriSchemeNetTcp {
  [] {return "net.tcp";}
};

Property<string, ReadOnly> Uri::UriSchemeNews {
  [] {return "news";}
};

Property<string, ReadOnly> Uri::UriSchemeNntp {
  [] {return "nntp";}
};
