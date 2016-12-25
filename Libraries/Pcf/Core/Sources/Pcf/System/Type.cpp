#include <cstdlib>
#include <cstddef>
#include <cstring>

#include "../../../Includes/Pcf/System/Array.h"
#include "../../../Includes/Pcf/System/Type.h"

using namespace System;

#if _WIN32
#pragma warning(push)
#pragma warning(disable:4996)
  
namespace {
  std::string demangle(const char* str) {
    const std::string types[4] = {"enum ", "class ", "union ", "struct "};
    std::string demangledStr = str;
    
    for(std::string item : types) {
      size_t pos = std::string::npos;
      while((pos = demangledStr.find(item)) != std::string::npos) {
        demangledStr.replace(pos, item.length(), "");
      }
    }
    
    return demangledStr;
  }
}

#pragma warning(pop)
  
#else
#include <cxxabi.h>
  
namespace {
  std::string demangle(const char* str) {
    int status = 0;
    char* tmp = abi::__cxa_demangle(str, 0, 0, &status);
    std::string demangledStr = tmp;
    free(tmp);
    tmp = null;
    return demangledStr;
  }
}
  
#endif

Type::Type(const Type& type) : FullName(pcf_delegate {return this->GetFullName();}),  Name(pcf_delegate {return this->GetName();}), Namespace(pcf_delegate {return this->GetNamespace();}), type(type.type) {
}

Type::Type() : FullName(pcf_delegate {return this->GetFullName();}),  Name(pcf_delegate {return this->GetName();}), Namespace(pcf_delegate {return this->GetNamespace();}), type(typeid(*this)) {
}

Type::Type(const ::type& type) : FullName(pcf_delegate {return this->GetFullName();}),  Name(pcf_delegate {return this->GetName();}), Namespace(pcf_delegate {return this->GetNamespace();}), type(type) {
}

Type& Type::operator =(const Type& type) {memcpy((void*)&this->type, (void*)&type.type, sizeof(type.type)); return *this;}
bool Type::Equals(const Object& obj) const {
  return is<Type>(obj) && Equals(static_cast<const Type&>(obj));
}

bool Type::Equals(const Type& type) const {
  return this->type == type.type;
}

String Type::GetFullName() const {
  String fullName = demangle(this->type.name()).c_str();
  Array<string> containsNullPtrTypes = {"Pcf::Fp", "System::Action", "System::Delegate", "System::Func", "std::tuple"};
  for (string item : containsNullPtrTypes) {
    if (fullName.StartsWith(item)) {
      fullName = fullName.Replace(", std::nullptr_t", "");
      break;
    }
  }
  Array<string> containsNullTypeTypes = {"System::Tuple"};
  for (string item : containsNullTypeTypes) {
    if (fullName.StartsWith(item)) {
      fullName = fullName.Replace(", System::NullType", "");
      break;
    }
  }
  return fullName.TrimEnd('*').Replace(" const", "").Replace("const ", "");
}

String Type::GetName() const {
  String fullName = GetFullName();
  int length = fullName.LastIndexOf("<");
  if (length == -1)
    length = fullName.Length;
  if (fullName.LastIndexOf("::", 0, length) == -1)
    return fullName;
  return fullName.Substring(fullName.LastIndexOf("::", 0, length) + 2);
}

String Type::GetNamespace() const {
  String fullName = GetFullName();
  int length = fullName.LastIndexOf("<");
  if (length == -1)
    length = fullName.Length;
  if (fullName.LastIndexOf("::", 0, length) == -1)
    return fullName;
  return fullName.Remove(fullName.LastIndexOf("::", 0, length));
}

String Type::ToString() const {
  return FullName;
}
