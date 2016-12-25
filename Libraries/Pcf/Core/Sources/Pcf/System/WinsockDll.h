#if _WIN32

#pragma warning(disable:4201)
#include <winsock2.h>
#pragma warning(default:4201)

namespace {
  class WinsockDll {
  public:
    WinsockDll() {
      WORD versionRequested = MAKEWORD(2, 2);
      WSADATA wsaData = { 0 };
      WSAStartup(versionRequested, &wsaData);
    }

    ~WinsockDll() {
      WSACleanup();
    }
  };

  static WinsockDll __winsock__Dll;
}

#endif