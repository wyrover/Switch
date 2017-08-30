#include <Switch/System/Uri.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class UriTest : public TestFixture {
    protected:
      void ConstructorWithAbsoluteUri() {
        Assert::DoesNotThrows(pcf_delegate{Uri("http://www.contoso.com");}, pcf_current_information);
      }

      void ConstructorWithAbsoluteUriAndUriKindRelativeOrAbsoluteSpecified() {
        Assert::DoesNotThrows(pcf_delegate{Uri("http://www.contoso.com", UriKind::RelativeOrAbsolute);}, pcf_current_information);
      }

      void ConstructorWithAbsoluteUriAndUriKindAbsoluteSpecified() {
        Assert::DoesNotThrows(pcf_delegate{Uri("http://www.contoso.com", UriKind::Absolute);}, pcf_current_information);
      }

      void ConstructorWithAbsoluteUriAndUriKindRelativeSpecified() {
        Assert::Throws<UriFormatException>(pcf_delegate{Uri("http://www.contoso.com", UriKind::Relative);}, pcf_current_information);
      }

      void ConstructorWithRelativeUri() {
        Assert::Throws<UriFormatException>(pcf_delegate{Uri("www.contoso.com");}, pcf_current_information);
      }

      void ConstructorWithRelativeUriAndUriKindRelativeOrAbsoluteSpecified() {
        Assert::DoesNotThrows(pcf_delegate{Uri("www.contoso.com", UriKind::RelativeOrAbsolute);}, pcf_current_information);
      }

      void ConstructorWithRelativeUriAndUriKindAbsoluteSpecified() {
        Assert::Throws<UriFormatException>(pcf_delegate{Uri("www.contoso.com", UriKind::Absolute);}, pcf_current_information);
      }

      void ConstructorWithRelativeUriAndUriKindRelativeSpecified() {
        Assert::DoesNotThrows(pcf_delegate{Uri("www.contoso.com", UriKind::Relative);}, pcf_current_information);
      }

      void ConstructorWithInvalidUri() {
        Assert::Throws<UriFormatException>(pcf_delegate{Uri("://www.contoso.com");}, pcf_current_information);
      }

  };

  pcf_test(UriTest, ConstructorWithAbsoluteUri)
  pcf_test(UriTest, ConstructorWithAbsoluteUriAndUriKindRelativeOrAbsoluteSpecified)
  pcf_test(UriTest, ConstructorWithAbsoluteUriAndUriKindAbsoluteSpecified)
  pcf_test(UriTest, ConstructorWithAbsoluteUriAndUriKindRelativeSpecified)
  pcf_test(UriTest, ConstructorWithRelativeUri)
  pcf_test(UriTest, ConstructorWithRelativeUriAndUriKindRelativeOrAbsoluteSpecified)
  pcf_test(UriTest, ConstructorWithRelativeUriAndUriKindAbsoluteSpecified)
  pcf_test(UriTest, ConstructorWithRelativeUriAndUriKindRelativeSpecified)
  pcf_test(UriTest, ConstructorWithInvalidUri)

  TEST(Uri, Constructor) {
    ASSERT_TRUE(Uri("http://www.contoso.com").IsAbsoluteUri());
    ASSERT_TRUE(Uri("http://www.contoso.com", UriKind::Absolute).IsAbsoluteUri());
    ASSERT_FALSE(Uri("www.contoso.com", UriKind::Relative).IsAbsoluteUri());
    ASSERT_FALSE(Uri("www.contoso.com", UriKind::RelativeOrAbsolute).IsAbsoluteUri());
    ASSERT_FALSE(Uri("http://www.contoso.com", UriKind::RelativeOrAbsolute).IsAbsoluteUri());
    ASSERT_TRUE(Uri(Uri("http://www.contoso.com"), "/path/file.ext").IsAbsoluteUri());
    ASSERT_TRUE(Uri(Uri("http://www.contoso.com"), Uri("/path/file.ext", UriKind::Relative)).IsAbsoluteUri());
  }

  TEST(Uri, CheckShemeName) {
    ASSERT_TRUE(Uri::CheckSchemeName("http"));
    ASSERT_TRUE(Uri::CheckSchemeName("news"));
    ASSERT_TRUE(Uri::CheckSchemeName("file"));
    ASSERT_TRUE(Uri::CheckSchemeName("f+ile"));
    ASSERT_TRUE(Uri::CheckSchemeName("fi-le"));
    ASSERT_TRUE(Uri::CheckSchemeName("fil.e"));

    ASSERT_FALSE(Uri::CheckSchemeName(""));
    ASSERT_FALSE(Uri::CheckSchemeName("!file"));
    ASSERT_FALSE(Uri::CheckSchemeName("f=ile"));
    ASSERT_FALSE(Uri::CheckSchemeName("fi le"));
    ASSERT_FALSE(Uri::CheckSchemeName("file*"));
  }

  TEST(Uri, EscapeDataString) {
    ASSERT_EQ(Uri::EscapeDataString("%20abc123XYZ<>%\"{}|\\^`[] =?:#@!"), "%20abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20%3D%3F%3A%23%40!");
  }

  TEST(Uri, EscapeUriString) {
    ASSERT_EQ(Uri::EscapeUriString("%20abc123XYZ<>%\"{}|\\^`[] =?:#@!"), "%20abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20=?:#@!");
  }

  TEST(Uri, Authority) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").Authority(), "yfi:MyPass@www.contoso.com:8080");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").Authority(), "www.contoso.com");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").Authority(), "www.contoso.com");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").Authority(), "user@contoso.com");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").Authority(), "news.contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").Authority(), "");
    ASSERT_EQ(Uri("file://server/filename.ext").Authority(), "server");
  }

  TEST(Uri, GetAbsolutePath) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").AbsolutePath(), "/C:a%20ta%20log/ShowNew.htm");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").AbsolutePath(), "/index.htm");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").AbsolutePath(), "/index.htm");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").AbsolutePath(), "");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").AbsolutePath(), "/123456@contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").AbsolutePath(), "123456@contoso.com");
    ASSERT_EQ(Uri("file://server/filename.ext").AbsolutePath(), "/filename.ext");
  }

  TEST(Uri, GetAbsoluteUri) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").AbsoluteUri(), "http://yfi:MyPass@www.contoso.com:8080/C:a%20ta%20log/ShowNew.htm?Date=ToDay#bOdy");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").AbsoluteUri(), "http://www.contoso.com/index.htm?date=today");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").AbsoluteUri(), "http://www.contoso.com/index.htm#main");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").AbsoluteUri(), "mailto:user@contoso.com?subject=uri");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").AbsoluteUri(), "nntp://news.contoso.com/123456@contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").AbsoluteUri(), "news:123456@contoso.com");
    ASSERT_EQ(Uri("file://server/filename.ext").AbsoluteUri(), "file://server/filename.ext");
  }

  TEST(Uri, GetComponents) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetComponents(UriComponents::Host, UriFormat::SafeUnescaped), "www.contoso.com");
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetComponents(UriComponents::Port, UriFormat::SafeUnescaped), "8080");
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetComponents(UriComponents::Port|UriComponents::KeepDelimiter, UriFormat::SafeUnescaped), ":8080");
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetComponents(UriComponents::Host|UriComponents::Port, UriFormat::SafeUnescaped), "www.contoso.com:8080");
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetComponents(UriComponents::HostAndPort, UriFormat::SafeUnescaped), "www.contoso.com:8080");
  }

  TEST(Uri, GetDnsSafeHost) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").DnsSafeHost(), "www.contoso.com");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").DnsSafeHost(), "www.contoso.com");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").DnsSafeHost(), "www.contoso.com");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").DnsSafeHost(), "contoso.com");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").DnsSafeHost(), "news.contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").DnsSafeHost(), "");
    ASSERT_EQ(Uri("file://server/filename.ext").DnsSafeHost(), "server");
  }

  TEST(Uri, GetFragment) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").Fragment(), "#bOdy");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").Fragment(), "");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").Fragment(), "#main");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").Fragment(), "");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").Fragment(), "");
    ASSERT_EQ(Uri("news:123456@contoso.com").Fragment(), "");
    ASSERT_EQ(Uri("file://server/filename.ext").Fragment(), "");
  }

  TEST(Uri, GetHost) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").Host(), "www.contoso.com");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").Host(), "www.contoso.com");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").Host(), "www.contoso.com");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").Host(), "contoso.com");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").Host(), "news.contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").Host(), "");
    ASSERT_EQ(Uri("file://server/filename.ext").Host(), "server");
    ASSERT_EQ(Uri("file://172.16.10.30/filename.ext").Host(), "172.16.10.30");
    //ASSERT_EQ(Uri("file://[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]/filename.ext").Host(), "[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]");
  }

  TEST(Uri, GetHostNameType) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").HostNameType(), UriHostNameType::Dns);
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").HostNameType(), UriHostNameType::Dns);
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").HostNameType(), UriHostNameType::Dns);
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").HostNameType(), UriHostNameType::Dns);
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").HostNameType(), UriHostNameType::Dns);
    ASSERT_EQ(Uri("news:123456@contoso.com").HostNameType(), UriHostNameType::Unknown);
    ASSERT_EQ(Uri("file://server/filename.ext").HostNameType(), UriHostNameType::Dns);
    ASSERT_EQ(Uri("file://172.16.10.30/filename.ext").HostNameType(), UriHostNameType::IPv4);
    //ASSERT_EQ(Uri("file://[2001:0:5ef5:73b8:2c2c:3028:2a4e:b283]/filename.ext").HostNameType(), UriHostNameType::IPv6);
  }

  TEST(Uri, GetLeftPart) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetLeftPart(UriPartial::Scheme), "http://");
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetLeftPart(UriPartial::Authority), "http://yfi:MyPass@www.contoso.com:8080");
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetLeftPart(UriPartial::Path), "http://yfi:MyPass@www.contoso.com:8080/C:a%20ta%20log/ShowNew.htm");
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").GetLeftPart(UriPartial::Query), "http://yfi:MyPass@www.contoso.com:8080/C:a%20ta%20log/ShowNew.htm?Date=ToDay");
  
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").GetLeftPart(UriPartial::Scheme), "http://");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").GetLeftPart(UriPartial::Authority), "http://www.contoso.com");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").GetLeftPart(UriPartial::Path), "http://www.contoso.com/index.htm");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").GetLeftPart(UriPartial::Query), "http://www.contoso.com/index.htm?date=today");
  
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").GetLeftPart(UriPartial::Scheme), "http://");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").GetLeftPart(UriPartial::Authority), "http://www.contoso.com");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").GetLeftPart(UriPartial::Path), "http://www.contoso.com/index.htm");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").GetLeftPart(UriPartial::Query), "http://www.contoso.com/index.htm");
  
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").GetLeftPart(UriPartial::Scheme), "mailto:");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").GetLeftPart(UriPartial::Authority), "mailto:user@contoso.com");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").GetLeftPart(UriPartial::Path), "mailto:user@contoso.com");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").GetLeftPart(UriPartial::Query), "mailto:user@contoso.com?subject=uri");
  
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").GetLeftPart(UriPartial::Scheme), "nntp://");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").GetLeftPart(UriPartial::Authority), "nntp://news.contoso.com");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").GetLeftPart(UriPartial::Path), "nntp://news.contoso.com/123456@contoso.com");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").GetLeftPart(UriPartial::Query), "nntp://news.contoso.com/123456@contoso.com");
  
    ASSERT_EQ(Uri("news:123456@contoso.com").GetLeftPart(UriPartial::Scheme), "news:");
    ASSERT_EQ(Uri("news:123456@contoso.com").GetLeftPart(UriPartial::Authority), "news:");
    ASSERT_EQ(Uri("news:123456@contoso.com").GetLeftPart(UriPartial::Path), "news:123456@contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").GetLeftPart(UriPartial::Query), "news:123456@contoso.com");
  
    ASSERT_EQ(Uri("file://server/filename.ext").GetLeftPart(UriPartial::Scheme), "file://");
    ASSERT_EQ(Uri("file://server/filename.ext").GetLeftPart(UriPartial::Authority), "file://server");
    ASSERT_EQ(Uri("file://server/filename.ext").GetLeftPart(UriPartial::Path), "file://server/filename.ext");
    ASSERT_EQ(Uri("file://server/filename.ext").GetLeftPart(UriPartial::Query), "file://server/filename.ext");
  }

  TEST(Uri, GetLocalPath) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").LocalPath(), Char(IO::Path::DirectorySeparatorChar) + "C:a ta log" + IO::Path::DirectorySeparatorChar + "ShowNew.htm");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").LocalPath(), Char(IO::Path::DirectorySeparatorChar) + "index.htm");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").LocalPath(), Char(IO::Path::DirectorySeparatorChar) + "index.htm");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").LocalPath(), "");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").LocalPath(), Char(IO::Path::DirectorySeparatorChar) + "123456@contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").LocalPath(), "123456@contoso.com");
    ASSERT_EQ(Uri("file://server/filename.ext").LocalPath(), Char(IO::Path::DirectorySeparatorChar) + "filename.ext");
  }

  TEST(Uri, GetOriginalString) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").OriginalString(), "  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").OriginalString(), "http://www.contoso.com/index.htm?date=today");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").OriginalString(), "http://www.contoso.com/index.htm#main");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").OriginalString(), "mailto:user@contoso.com?subject=uri");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").OriginalString(), "nntp://news.contoso.com/123456@contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").OriginalString(), "news:123456@contoso.com");
    ASSERT_EQ(Uri("file://server/filename.ext").OriginalString(), "file://server/filename.ext");
  }

  TEST(Uri, GetPathAndQuery) {
    Uri uri = Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ");
    String s = uri.PathAndQuery();
    ASSERT_EQ("/C:a%20ta%20log/ShowNew.htm?Date=ToDay", s);
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").PathAndQuery(), "/index.htm?date=today");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").PathAndQuery(), "/index.htm");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").PathAndQuery(), "?subject=uri");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").PathAndQuery(), "/123456@contoso.com");
    ASSERT_EQ(Uri("news:123456@contoso.com").PathAndQuery(), "123456@contoso.com");
    ASSERT_EQ(Uri("file://server/filename.ext").PathAndQuery(), "/filename.ext");
  }

  TEST(Uri, GetPort) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").Port(), 8080);
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").Port(), 80);
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").Port(), 80);
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").Port(), 25);
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").Port(), 119);
    ASSERT_EQ(Uri("news:123456@contoso.com").Port(), -1);
    ASSERT_EQ(Uri("file://server/filename.ext").Port(), -1);
  }

  TEST(Uri, GetQuery) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").Query(), "?Date=ToDay");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").Query(), "?date=today");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").Query(), "");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").Query(), "?subject=uri");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").Query(), "");
    ASSERT_EQ(Uri("news:123456@contoso.com").Query(), "");
    ASSERT_EQ(Uri("file://server/filename.ext").Query(), "");
  }

  TEST(Uri, GetScheme) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").Scheme(), "http");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").Scheme(), "http");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm#main").Scheme(), "http");
    ASSERT_EQ(Uri("mailto:user@contoso.com?subject=uri").Scheme(), "mailto");
    ASSERT_EQ(Uri("nntp://news.contoso.com/123456@contoso.com").Scheme(), "nntp");
    ASSERT_EQ(Uri("news:123456@contoso.com").Scheme(), "news");
    ASSERT_EQ(Uri("file://server/filename.ext").Scheme(), "file");
  }

  TEST(Uri, GetSegmens) {
    Array<string> Segments1 = Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").Segments();
    ASSERT_EQ(Segments1.Length, 3);
    ASSERT_EQ(Segments1[0], "/");
    ASSERT_EQ(Segments1[1], "C:a%20ta%20log/");
    ASSERT_EQ(Segments1[2], "ShowNew.htm");
  
    Array<string> Segments2 = Uri("http://www.contoso.com/index.htm?date=today").Segments();
    ASSERT_EQ(Segments2.Length, 2);
    ASSERT_EQ(Segments2[0], "/");
    ASSERT_EQ(Segments2[1], "index.htm");
  
    Array<string> Segments3 = Uri("http://www.contoso.com/index.htm#main").Segments();
    ASSERT_EQ(Segments3.Length, 2);
    ASSERT_EQ(Segments3[0], "/");
    ASSERT_EQ(Segments3[1], "index.htm");
  
    Array<string> Segments4 = Uri("mailto:user@contoso.com?subject=uri").Segments();
    ASSERT_EQ(Segments4.Length, 0);
  
    Array<string> Segments5 = Uri("nntp://news.contoso.com/123456@contoso.com").Segments();
    ASSERT_EQ(Segments5.Length, 2);
    ASSERT_EQ(Segments5[0], "/");
    ASSERT_EQ(Segments5[1], "123456@contoso.com");
  
    Array<string> Segments6 = Uri("news:123456@contoso.com").Segments();
    ASSERT_EQ(Segments6.Length, 1);
    ASSERT_EQ(Segments6[0], "123456@contoso.com");
  
    Array<string> Segments7 = Uri("file://server/filename.ext").Segments();
    ASSERT_EQ(Segments7.Length, 2);
    ASSERT_EQ(Segments7[0], "/");
    ASSERT_EQ(Segments7[1], "filename.ext");
  }

  TEST(Uri, GetUserInfo) {
    ASSERT_EQ(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").UserInfo(), "yfi:MyPass");
    ASSERT_EQ(Uri("http://www.contoso.com/index.htm?date=today").UserInfo(), "");
    ASSERT_EQ(Uri("http://1234567890@www.contoso.com/index.htm?date=today").UserInfo(), "1234567890");
  }

  TEST(Uri, HexUnescape) {
    int32 index = 0;
    ASSERT_EQ('<', Uri::HexUnescape("%3c", index));
    ASSERT_EQ(index, 3);
  }

  TEST(Uri, IsBaseOf) {
    ASSERT_TRUE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path/file/")));
    /*
    ASSERT_TRUE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path/#fragment")));
    ASSERT_TRUE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path/MoreDir/\"")));
    ASSERT_TRUE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path/OtherFile?Query")));
    ASSERT_TRUE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path/")));
    ASSERT_TRUE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path/file")));

    ASSERT_FALSE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path")));
    ASSERT_FALSE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path?query")));
    ASSERT_FALSE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path#Fragment")));
    ASSERT_FALSE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path2/")));
    ASSERT_FALSE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/path2/MoreDir")));
    ASSERT_FALSE(Uri("http://host/path/path/file?query").IsBasOf(Uri("http://host/path/File")));
  */
  }

  TEST(Uri, IsDefaultPort) {
    ASSERT_FALSE(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").IsDefaultPort());
    ASSERT_TRUE(Uri("http://www.contoso.com/index.htm?date=today").IsDefaultPort());
    ASSERT_TRUE(Uri("http://www.contoso.com:80/index.htm#main").IsDefaultPort());
    ASSERT_TRUE(Uri("mailto:user@contoso.com?subject=uri").IsDefaultPort());
    ASSERT_TRUE(Uri("nntp://news.contoso.com:119/123456@contoso.com").IsDefaultPort());
    ASSERT_TRUE(Uri("news:123456@contoso.com").IsDefaultPort());
    ASSERT_TRUE(Uri("file://server/filename.ext").IsDefaultPort());
  }

  TEST(Uri, IsFile) {
    ASSERT_FALSE(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").IsFile());
    ASSERT_FALSE(Uri("http://www.contoso.com/index.htm?date=today").IsFile());
    ASSERT_FALSE(Uri("http://www.contoso.com/index.htm#main").IsFile());
    ASSERT_FALSE(Uri("mailto:user@contoso.com?subject=uri").IsFile());
    ASSERT_FALSE(Uri("nntp://news.contoso.com/123456@contoso.com").IsFile());
    ASSERT_FALSE(Uri("news:123456@contoso.com").IsFile());
    ASSERT_TRUE(Uri("file://server/filename.ext").IsFile());
  }

  TEST(Uri, IsLoopback) {
    ASSERT_FALSE(Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").IsLoopback());
    ASSERT_FALSE(Uri("http://www.contoso.com/index.htm?date=today").IsLoopback());
    ASSERT_FALSE(Uri("http://www.contoso.com/index.htm#main").IsLoopback());
    ASSERT_FALSE(Uri("mailto:user@contoso.com?subject=uri").IsLoopback());
    ASSERT_FALSE(Uri("nntp://news.contoso.com/123456@contoso.com").IsLoopback());
    ASSERT_TRUE(Uri("news:123456@contoso.com").IsLoopback());
    ASSERT_FALSE(Uri("file://server/filename.ext").IsLoopback());
    ASSERT_TRUE(Uri("file://127.0.0.1/filename.ext").IsLoopback());
    //ASSERT_TRUE(Uri("file://[00:00:00:00:00:00:00:01]/filename.ext").IsLoopback());
    ASSERT_TRUE(Uri("file://loopback/filename.ext").IsLoopback());
    ASSERT_TRUE(Uri("file://localhost/filename.ext").IsLoopback());
  }

  TEST(Uri, ToString) {
    ASSERT_EQ("http://yfi:MyPass@www.contoso.com:8080/C:a ta log/ShowNew.htm?Date=ToDay#bOdy", Uri("  Http://yfi:MyPass@www.Contoso.com:8080/C:a ta%20log/ShowNew.htm?Date=ToDay#bOdy  ").ToString());
    ASSERT_EQ("http://www.contoso.com/index.htm?date=today", Uri("http://www.contoso.com/index.htm?date=today").ToString());
    ASSERT_EQ("http://www.contoso.com/index.htm#main", Uri("http://www.contoso.com/index.htm#main").ToString());
    ASSERT_EQ("mailto:user@contoso.com?subject=uri", Uri("mailto:user@contoso.com?subject=uri").ToString());
    ASSERT_EQ("nntp://news.contoso.com/123456@contoso.com", Uri("nntp://news.contoso.com/123456@contoso.com").ToString());
    ASSERT_EQ("news:123456@contoso.com", Uri("news:123456@contoso.com").ToString());
    ASSERT_EQ("file://server/filename.ext", Uri("file://server/filename.ext").ToString());
  }

  TEST(Uri, UnescapeDataString) {
    ASSERT_EQ(Uri::UnescapeDataString("abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20%3D%3F%3A%23%40!"), "abc123XYZ<>%\"{}|\\^`[] =?:#@!");
    ASSERT_EQ(Uri::UnescapeDataString("abc123XYZ%3C%3E%25%22%7B%7D%7C%5C%5E%60%5B%5D%20=?:#@!"), "abc123XYZ<>%\"{}|\\^`[] =?:#@!");
  }

}
