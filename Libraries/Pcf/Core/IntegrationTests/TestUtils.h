#include <Pcf/System/Net/IPAddress.h>

class TestUtils {
public:
  static Pcf::System::Net::IPAddress GetLocalIPAddress();
  static Pcf::System::Net::IPAddress GetRemoteIPAddress();
  static Pcf::System::Net::IPAddress GetIPAddress(Pcf::System::String hostname);
  static Pcf::System::Array<byte> GetDataArray(Pcf::System::String data);

  static Pcf::System::String mRemoteHost;
  static int32 mPort;
};

