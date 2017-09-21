#include "../../../Includes/Switch/System/__opaque_unicode_string__.hpp"
#include "../../../Includes/Switch/System/Array.hpp"
#include "../../../Includes/Switch/System/ArgumentNullException.hpp"
#include "../../../Includes/Switch/System/ArgumentOutOfRangeException.hpp"
#include "../../__OS/CoreApi.hpp"

size_t __opaque_unicode_string__::npos = std::string::npos;

__opaque_unicode_string__::__opaque_unicode_string__() {
}

__opaque_unicode_string__::__opaque_unicode_string__(const char* str) : string(str), stringSize(__OS::CoreApi::UnicodeEncodings::UTF8::GetLength(string)) {
}

__opaque_unicode_string__::__opaque_unicode_string__(const char32_t* str) {
  int i = 0;
  while (str[i] != 0)
  this->append(str[i++]);
}

__opaque_unicode_string__::__opaque_unicode_string__(const __opaque_unicode_string__& str) {
  *this = str;
}

__opaque_unicode_string__::__opaque_unicode_string__(int length, char c) {
  this->stringSize = length;
  while (length--)
  this->string.push_back(c);
}

__opaque_unicode_string__::__opaque_unicode_string__(const char* str, int32_t startIndex, int32_t length) {
  if (str == null)
  throw System::ArgumentNullException(_caller);
  
  __opaque_unicode_string__ other(str);
  
  int32_t count = static_cast<int32_t>((static_cast<size_t>(length) == npos) ? other.size() : length);
  if (startIndex + count > static_cast<int32_t>(other.size()))
  count = static_cast<int32_t>(other.size()) - startIndex;
  
  if (startIndex == static_cast<int32_t>(other.size())) {
    this->stringSize = 0;
    return;
  }
  
  int32_t begin = -1, end = -1;
  
  for (__opaque_unicode_string__::const_iterator it = ((const __opaque_unicode_string__&)other).begin(); it != ((const __opaque_unicode_string__&)other).end(); it++) {
    if (startIndex == it.get_logical_index())
    begin = it.get_byte_index();
    
    if (it.get_logical_index() == (startIndex + count))
    end = it.get_byte_index();
  }
  
  if (begin == -1)
  throw System::ArgumentOutOfRangeException(_caller);
  
  if (end == -1) {
    this->string = other.string.substr(begin);
    this->stringSize = other.size() - startIndex;
  } else {
    this->string = other.string.substr(begin, end - begin);
    this->stringSize = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(this->string);
  }
}
// todo clean code and optimize size calculation
/*__opaque_unicode_string__::__opaque_unicode_string__(const char* str, int32_t startIndex, int32_t length) {
 if (str == null) throw System::ArgumentNullException(_caller);
 if ((size_t(length) != npos && length < 0) || startIndex < 0) throw System::ArgumentOutOfRangeException(_caller);
 
 std::string other(str);
 int wanted = length;
 std::string::iterator begin = other.end();
 std::string::iterator end = other.begin();
 
 int abstractIndex = 0;
 StringForeach(index, other) {
 if (abstractIndex == startIndex)
 begin = other.begin() + index;
 
 if (abstractIndex >= startIndex) { // we are reading wanted section
 if (wanted == 0) { // if section is finished
 end += index;
 this->string.append(begin, end);
 this->size = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(this->string);
 return;
 }
 if (size_t(length) != npos) wanted -= 1;
 }
 abstractIndex += 1;
 }
 
 if (abstractIndex == startIndex) {
 this->size = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(this->string);
 return;
 }
 
 if (begin == other.end()) // it has not begun
 throw System::ArgumentOutOfRangeException(_caller);
 
 if (end == other.begin()) { // is has not finished
 this->string.append(begin, other.end());
 this->size = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(this->string);
 return;
 }
 
 throw System::ArgumentOutOfRangeException(_caller);
 }*/

__opaque_unicode_string__::__opaque_unicode_string__(const char32_t* str, int32_t startIndex, int32_t length) {
  if (startIndex < 0 || length < 0)
  throw System::ArgumentOutOfRangeException(_caller);
  this->stringSize = 0;
  for (int i = 0; i < length; i++)
    append(str[i]);
}


__opaque_unicode_string__& __opaque_unicode_string__::append(const __opaque_unicode_string__& other) {
  this->string.append(other.string);
  this->stringSize += other.stringSize;
  return *this;
}

const char* __opaque_unicode_string__::c_str() const {
  return this->string.c_str();
}

__opaque_unicode_string__& __opaque_unicode_string__::operator =(const __opaque_unicode_string__& str) {
  this->string = str.string;
  this->stringSize = str.stringSize;
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::operator +=(const __opaque_unicode_string__& s) {
  this->string.append(s.string);
  this->stringSize += s.stringSize;
  return *this;
}

char32_t __opaque_unicode_string__::operator [](int i) const {
  if (i<0)
  throw System::ArgumentOutOfRangeException(_caller);
  
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++)
    if (it.get_logical_index() == i)
      return *it;
  
  throw System::ArgumentOutOfRangeException(_caller);
}

char32_t& __opaque_unicode_string__::operator [](int i) {
  if (i<0)
  throw System::ArgumentOutOfRangeException(_caller);
  
  for (__opaque_unicode_string__::iterator it = (*this).begin(); it != (*this).end(); it++)
    if (it.get_logical_index() == i)
      return *it;
  
  throw System::ArgumentOutOfRangeException(_caller);
}

//pos
//  Position of the first character to be erased.
//  If this is greater than the String length, it throws out_of_range.
//  Note: The first character in str is denoted by a value of 0 (not 1).
//len
//  Number of characters to erase (if the String is shorter, as many characters as possible are erased).
//  A value of String::npos indicates all characters until the end of the String.
__opaque_unicode_string__& __opaque_unicode_string__::erase(size_t pos, size_t len) {
  int byteIndexIn = -1;
  __opaque_unicode_string__::iterator it = begin();
  
  if (len == 0) return *this;
  
  // find byte index of first element to remove
  for ( ; it != end(); it++) {
    if (static_cast<size_t>(it.get_logical_index()) == pos && byteIndexIn == -1) {
      byteIndexIn = it.get_byte_index();
      break;
    }
  }
  
  if (byteIndexIn == -1)
  throw System::ArgumentOutOfRangeException(_caller);
  
  // if erase all from pos
  if (len == npos) {
    this->string.erase(byteIndexIn);
    this->stringSize = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(this->string);
    return *this;
  }
  
  // find (if possible) byte index of last element to remove
  int byteIndexOut = static_cast<int>(this->string.size());
  for ( ; it != end(); it++) {
    if (--len == 0) {
      int next = __OS::CoreApi::UnicodeEncodings::UTF8::GetNextCodeIndex(this->string, it.get_byte_index());
      if (next != -1)
      byteIndexOut = next;
    }
  }
  
  this->string.erase(byteIndexIn, byteIndexOut-byteIndexIn);
  this->stringSize = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(this->string);
  return *this;
}

// Replaces the portion of the String that begins at pos and
// and spans len characters by new contents (character c repeated n times)
__opaque_unicode_string__& __opaque_unicode_string__::replace(size_t pos,  size_t len,  size_t n, char c) {
  __opaque_unicode_string__ str(static_cast<int32_t>(n),c);
  return replace(pos, len, str);
}

// Replaces the portion of the String that begins at pos and
// and spans len characters by new contents (string str)
__opaque_unicode_string__& __opaque_unicode_string__::replace(size_t pos,  size_t len,  const __opaque_unicode_string__& str) {
  __opaque_unicode_string__ before = substr(0,pos);
  __opaque_unicode_string__ after = substr(pos).erase(0,len);
  this->string = before.string.append(str.string).append(after.string);
  this->stringSize = before.stringSize + str.stringSize + after.stringSize;
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::trim_end(const std::vector<char32_t>& toRemove) {
  int byteIndex = -1;
  for (__opaque_unicode_string__::reverse_iterator rit = (*this).rbegin(); rit != (*this).rend(); rit++) {
    bool matched = false;
    for (uint32 i = 0; i < toRemove.size(); i++) {
      if (*rit == toRemove[i]) {
        byteIndex = rit.get_byte_index();
        matched = true;
      }
    }
    if (!matched)
    rit = rend();
  }
  
  if (byteIndex == -1)
  return *this;
  
  this->string.erase(byteIndex);
  this->stringSize = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(this->string);
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::append(size_t n, char32_t code) {
  for (size_t i = 0; i < n; i++)
    __OS::CoreApi::UnicodeEncodings::UTF8::Encode(code, string);
  this->stringSize += n;
  return *this;
}

__opaque_unicode_string__& __opaque_unicode_string__::append(char32_t code) {
  __OS::CoreApi::UnicodeEncodings::UTF8::Encode(code, string);
  this->stringSize += 1;
  return *this;
}

bool __opaque_unicode_string__::operator==(const __opaque_unicode_string__& str) const {
  if (this->stringSize != str.stringSize)
  return false;
  return this->string == str.string;
}

bool __opaque_unicode_string__::equals(__opaque_unicode_string__::const_iterator src, const __opaque_unicode_string__::const_iterator& src_end, __opaque_unicode_string__::const_iterator match, const __opaque_unicode_string__::const_iterator& match_end) {
  for ( ;match != match_end; match++, src++) {
    if (src == src_end)
      return false;
    if (*src != *match)
      return false;
  }
  return true;
}

//pos
//Position of the last character in the String to be considered as the beginning of a match.
//Any value greater or equal than the String length (including npos) means that the entire String is searched.
//Note: The first character is denoted by a value of 0 (not 1).
size_t __opaque_unicode_string__::rfind(const __opaque_unicode_string__& match, size_t pos) const {
  size_t foundIndex = npos;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    if ((pos != npos) && ((size_t)it.get_logical_index() > pos))
    return foundIndex;
    
    if (equals(it, end(), match.begin(), match.end()))
    foundIndex = it.get_logical_index();
  }
  return foundIndex;
}

size_t __opaque_unicode_string__::rfind(char32_t match, size_t pos) const {
  size_t foundIndex = npos;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    if ((pos != npos) && ((size_t)it.get_logical_index() > pos))
    return foundIndex;
    
    if (*it == match)
    foundIndex = it.get_logical_index();
  }
  return foundIndex;
}

// Inserts additional characters into the String right before the character indicated by pos
__opaque_unicode_string__& __opaque_unicode_string__::insert(int32_t pos, const __opaque_unicode_string__& str) {
  __opaque_unicode_string__ before = substr(0,pos);
  __opaque_unicode_string__ after = substr(pos);
  this->string = before.string;
  this->string.append(str.string);
  this->string.append(after.string);
  this->stringSize = before.stringSize + str.stringSize + after.stringSize;
  return *this;
}

//Returns a newly constructed String object with its value initialized to a copy of a substring of this object.
//The substring is the portion of the object that starts at character position pos and
//spans len characters (or until the end of the String, whichever comes first).
__opaque_unicode_string__ __opaque_unicode_string__::substr(size_t pos, size_t len) const {
  return __opaque_unicode_string__(this->string.c_str(), static_cast<int32_t>(pos), static_cast<int32_t>(len));
}

//Searches the String for the first occurrence of the sequence specified by its arguments.
//When pos is specified, the search only includes characters at or after position pos,
//ignoring any possible occurrences that include characters before pos.
size_t __opaque_unicode_string__::find(const __opaque_unicode_string__& match, size_t pos, size_t count) const {
  size_t len = 0;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    len += 1;
    if ((pos != npos) && ((size_t)it.get_logical_index() < pos))
    continue;
    
    if ((pos != npos) && (count != npos) && ((size_t)it.get_logical_index() >= pos + count))
    return npos;
    
    if (equals(it, end(), match.begin(), match.end()))
    return it.get_logical_index();
  }
  if (pos != npos && pos > len)
  throw System::ArgumentOutOfRangeException(_caller);
  return npos;
}

size_t __opaque_unicode_string__::find(char32_t match, size_t pos, size_t count) const {
  size_t len = 0;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    len += 1;
    if ((pos != npos) && ((size_t)it.get_logical_index() < pos))
    continue;
    
    if ((pos != npos) && (count != npos) && ((size_t)it.get_logical_index() >= pos + count))
    return npos;
    
    if (*it == match)
    return it.get_logical_index();
  }
  if (pos != npos && pos > len)
  throw System::ArgumentOutOfRangeException(_caller);
  return npos;
}

size_t __opaque_unicode_string__::find_any(const std::vector<char32_t>& any, size_t pos, size_t count) const {
  size_t len = 0;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++) {
    len += 1;
    if ((pos != npos) && ((size_t)it.get_logical_index() < pos))
    continue;
    
    if ((pos != npos) && (count != npos) && ((size_t)it.get_logical_index() >= pos + count))
    return npos;
    
    for (size_t i = 0; i < any.size(); i++)
    if (*it == any[i])
    return it.get_logical_index();
  }
  if (pos != npos && pos > len)
  throw System::ArgumentOutOfRangeException(_caller);
  return npos;
}

//todo use reverse iterator
bool __opaque_unicode_string__::ends_with(const __opaque_unicode_string__& s) const {
  if (s.string.size() > this->string.size())
  return false;
  
  return this->string.substr(this->string.size() - s.string.size()) == s.string;
}

__opaque_unicode_string__ __opaque_unicode_string__::to_lower() const {
  __opaque_unicode_string__ lower;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++)
    lower.append(__OS::CoreApi::UnicodeEncodings::to_lower(*it));
  return lower;
}

__opaque_unicode_string__ __opaque_unicode_string__::to_upper() const {
  __opaque_unicode_string__ upper;
  for (__opaque_unicode_string__::const_iterator it = (*this).begin(); it != (*this).end(); it++)
    upper.append(__OS::CoreApi::UnicodeEncodings::to_upper(*it));
  return upper;
}

int __opaque_unicode_string__::compare(const __opaque_unicode_string__& str)  const {
  __opaque_unicode_string__::const_iterator it2 = str.begin();
  for (__opaque_unicode_string__::const_iterator it1 = (*this).begin(); it1 != (*this).end(); it1++) {
    if (it2 == str.end()) // str is a prefix of *this
    return 1;
    
    if (*it1 < *it2)
    return -1;
    if (*it1 > *it2)
    return 1;
    
    it2++;
  }
  
  if (it2 != str.end()) // *this is a prefix of str
  return -1;
  
  return 0;
}

int __opaque_unicode_string__::compare_ignore_case(const __opaque_unicode_string__& str) const {
  __opaque_unicode_string__ left_op(to_lower());
  __opaque_unicode_string__ right_op(str.to_lower());
  return left_op.compare(right_op);
}

//_____________________________________________________________________________
//                                                    __opaque_unicode_string__ :: const_iterator

__opaque_unicode_string__::const_iterator::const_iterator(const std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = this->position = 0;
    this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
  }
}

__opaque_unicode_string__::const_iterator __opaque_unicode_string__::const_iterator::operator++(int) {
  const_iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::const_iterator::operator==(const const_iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::const_iterator::operator!=(const const_iterator& rhs) const{
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::const_iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return __OS::CoreApi::UnicodeEncodings::UTF8::GetCode(&data[this->position],format);
}

__opaque_unicode_string__::const_iterator::const_iterator(const const_iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  this->index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::const_iterator& __opaque_unicode_string__::const_iterator::operator++() {
  if (this->position == -1) return *this;
  for (size_t i = this->position+1; i < string_pointer->size() ; i += 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index += 1;
      this->position = (int)i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

//_____________________________________________________________________________
//                                                          __opaque_unicode_string__ :: iterator

__opaque_unicode_string__::iterator::iterator(std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = this->position = 0;
    this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
  }
}

__opaque_unicode_string__::iterator __opaque_unicode_string__::iterator::operator++(int) {
  iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::iterator::operator==(const iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::iterator::operator!=(const iterator& rhs) const{
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return __OS::CoreApi::UnicodeEncodings::UTF8::GetCode(&data[this->position],format);
}

char32_t& __opaque_unicode_string__::iterator::operator*() {
  //TODO If usicode length is greater than 1 byte, there are probably a crash
  uint8_t* data = (uint8_t*)string_pointer->data();
  static char32 value;
  value = __OS::CoreApi::UnicodeEncodings::UTF8::GetCode(&data[this->position],format);
  return value;
}

__opaque_unicode_string__::iterator::iterator(const iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  this->index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::iterator& __opaque_unicode_string__::iterator::operator++() {
  if (this->position == -1) return *this;
  for (size_t i = this->position+1; i < string_pointer->size() ; i += 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index += 1;
      this->position = (int)i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

//_____________________________________________________________________________
//                                            __opaque_unicode_string__ :: const_reverse_iterator

__opaque_unicode_string__::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::const_reverse_iterator::const_reverse_iterator(const std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(*str)-1;
    this->position = __OS::CoreApi::UnicodeEncodings::UTF8::GetLastIndex(*str);
    if (this->position == -1) {
      this->format = 0;
    } else {
      this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
    }
  }
}

__opaque_unicode_string__::const_reverse_iterator __opaque_unicode_string__::const_reverse_iterator::operator++(int) {
  const_reverse_iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::const_reverse_iterator::operator==(const const_reverse_iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::const_reverse_iterator::operator!=(const const_reverse_iterator& rhs) const {
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::const_reverse_iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return __OS::CoreApi::UnicodeEncodings::UTF8::GetCode(&data[this->position],format);
}

__opaque_unicode_string__::const_reverse_iterator& __opaque_unicode_string__::const_reverse_iterator::operator++() {
  if (this->position == -1) return *this;
  for (int32_t i = this->position-1 ; i >= 0 ; i -= 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index -= 1;
      this->position = i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

//_____________________________________________________________________________
//                                                  __opaque_unicode_string__ :: reverse_iterator

__opaque_unicode_string__::reverse_iterator::reverse_iterator(const reverse_iterator& it) {
  string_pointer = it.string_pointer;
  this->position = it.position;
  this->index = it.index;
  this->format = it.format;
}

__opaque_unicode_string__::reverse_iterator::reverse_iterator(std::string* str, bool at_end) {
  string_pointer = str;
  if (*str == "" || at_end) {
    this->position = -1;
    this->index = -1;
    this->format = 0;
  } else {
    this->index = __OS::CoreApi::UnicodeEncodings::UTF8::GetLength(*str)-1;
    this->position = __OS::CoreApi::UnicodeEncodings::UTF8::GetLastIndex(*str);
    if (this->position == -1) {
      this->format = 0;
    } else {
      this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat((uint8_t)string_pointer->operator[](this->position));
    }
  }
}

__opaque_unicode_string__::reverse_iterator __opaque_unicode_string__::reverse_iterator::operator++(int) {
  reverse_iterator temp_it(*this);
  operator++();
  return temp_it;
}

bool __opaque_unicode_string__::reverse_iterator::operator==(const reverse_iterator& rhs) const {
  return (string_pointer == rhs.string_pointer) && (this->position == rhs.position);
}

bool __opaque_unicode_string__::reverse_iterator::operator!=(const reverse_iterator& rhs) const {
  return !(*this == rhs);
}

char32_t __opaque_unicode_string__::reverse_iterator::operator*() const {
  const uint8_t* data = (const uint8_t*)string_pointer->data();
  return __OS::CoreApi::UnicodeEncodings::UTF8::GetCode(&data[this->position],format);
}

char32_t& __opaque_unicode_string__::reverse_iterator::operator*() {
  uint8_t* data = (uint8_t*)string_pointer->data();
  //TODO If usicode length is greater than 1 byte, there are probably a crash
  return (char32_t&)*data;
}

__opaque_unicode_string__::reverse_iterator& __opaque_unicode_string__::reverse_iterator::operator++() {
  if (this->position == -1) return *this;
  for (int32_t i = this->position-1 ; i >= 0 ; i -= 1) {
    uint8_t b = (uint8_t)(*string_pointer)[i];
    this->format = __OS::CoreApi::UnicodeEncodings::UTF8::GetFormat(b);
    if (this->format > 0) {
      this->index -= 1;
      this->position = i;
      return *this;
    }
  }
  this->position = -1;
  return *this;
}

