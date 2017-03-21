#if _WIN32

#pragma warning(disable:4201)
#include <winsock2.h>
#pragma warning(default:4201)

namespace {
  struct SocketInit {
    SocketInit() noexcept {WSAStartup(versionRequested, &wsaData);}
    ~SocketInit() noexcept {WSACleanup();}
    WORD versionRequested = MAKEWORD(2, 2);
    WSADATA wsaData = {0};
  };
}

#else

namespace {
  struct SocketInit {
    SocketInit() noexcept = default;
    ~SocketInit() noexcept = default;
  };
}

#endif
