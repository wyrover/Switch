
#include "../../Includes/System.h"

using namespace System;
using namespace System::IO;

const DriveType EnumDriveType::FromInt32(Int32 _Value_S32)
{
  DriveType retValue_E = DriveTypeUnknown;
  if (_Value_S32 <= DriveTypeRam)
    retValue_E = (DriveType)(S32)_Value_S32;
  else
    Throw(ArgumentException);
  return retValue_E;
}

const DriveType EnumDriveType::Parse(const String& _Value_c)
{
  DriveType retValue_E = DriveTypeUnknown;
  if (&_Value_c != null)
  {
    if (_Value_c == "Unknown")
      retValue_E = DriveTypeUnknown;
    else if (_Value_c == "NoRootDirectory")
      retValue_E = DriveTypeNoRootDirectory;
    else if (_Value_c == "Removable")
      retValue_E = DriveTypeRemovable;
    else if (_Value_c == "Fixed")
      retValue_E = DriveTypeFixed;
    else if (_Value_c == "Network")
      retValue_E = DriveTypeNetwork;
    else if (_Value_c == "CDRom")
      retValue_E = DriveTypeCDRom;
    else if (_Value_c == "Ram")
      retValue_E = DriveTypeRam;
    else
    {
      Throw(ArgumentException);
    }
  }
  else
    Throw(ArgumentNullException);
  return retValue_E;
}

String EnumDriveType::ToString(DriveType _Value_E)
{
  String retValue_c;
  switch (_Value_E)
  {
    case DriveTypeUnknown: retValue_c = "Unknown"; break;
    case DriveTypeNoRootDirectory: retValue_c = "NoRootDirectory"; break;
    case DriveTypeRemovable: retValue_c = "Removable"; break;
    case DriveTypeFixed: retValue_c = "Fixed"; break;
    case DriveTypeNetwork: retValue_c = "Network"; break;
    case DriveTypeCDRom: retValue_c = "CDRom"; break;
    case DriveTypeRam: retValue_c = "Ram"; break;
    default: retValue_c = EnumDriveType::ToInt32(_Value_E).ToString();
  }
  return retValue_c;
}

const Int32 EnumDriveType::ToInt32(DriveType _Value_E)
{
  return (S32)_Value_E;
}

