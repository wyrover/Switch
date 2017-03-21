#include "../../../../Includes/Pcf/System/Net/IPHostEntry.h"

using namespace System;
using namespace System::Net;

const Array<IPAddress>& IPHostEntry::GetAddressList() const {
  return this->addresses;
}

const Array<string>& IPHostEntry::GetAliases() const {
  return this->aliases;
}

const string& IPHostEntry::GetHostName() const {
  return this->hostName;
}

