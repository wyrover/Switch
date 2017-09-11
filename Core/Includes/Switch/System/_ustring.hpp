/// @file
/// @brief Contains std::ustring class.
#pragma once

#include <cstddef>
#include <ostream>
#include <string>
#include <vector>

#include "../Export.hpp"

/// @cond
namespace std {
  class _export ustring {
  public:
    ustring();
    ustring(const char* str);
    ustring(const char32_t* str);
    ustring(const ustring& str);
    ustring(int length, char c);
    ustring(const char* str, int32_t startIndex, int32_t length = (int32_t)npos);
    ustring(const char32_t* str, int32_t startIndex, int32_t length = (int32_t)npos);
    ustring(ustring&& str) : string(std::move(str.string)), stringSize(str.stringSize) {str.stringSize = 0;}

    bool operator==(const ustring& str) const;
    char32_t operator[](int i) const;
    char32_t& operator[](int i);

    ustring substr(size_t pos = 0, size_t len = npos) const;
    ustring to_upper() const;
    ustring to_lower() const;
    size_t find (const ustring& s, size_t pos = npos, size_t count = npos) const;
    size_t find (char32_t code, size_t pos = npos, size_t count = npos) const;
    size_t find_any (const std::vector<char32_t>& any, size_t pos = npos, size_t count = npos) const;
    size_t rfind (const ustring& s, size_t pos = npos) const;
    size_t rfind (char32_t code, size_t pos = npos) const;
    size_t length() const { return this->stringSize; }
    bool ends_with(const ustring& s) const;
    size_t size() const { return length(); }
    size_t nb_bytes() const { return this->string.size(); }

    const char* data() const { return this->string.data(); }
    const char* c_str() const;

    int compare(const ustring& str) const;
    int compare_ignore_case(const ustring& str) const;

    ustring& operator =(const ustring& str);
    ustring& operator +=(const ustring& s);

    ustring& trim_end(const std::vector<char32_t>& toRemove);
    ustring& append(size_t n, char32_t c);
    ustring& append(const ustring& s);
    ustring& append(char32_t code);
    size_t capacity() const {return this->string.capacity();}
    ustring& insert(int32_t pos, const ustring& str);
    ustring& erase(size_t pos = 0, size_t len = npos);
    ustring& replace(size_t pos,  size_t len,  size_t n, char c);
    ustring& replace(size_t pos,  size_t len,  const ustring& str);
    void reserve(size_t value) {this->string.reserve(value);}

    class const_iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
      
      friend class ustring;
      
    private:
      const std::string* string_pointer;
      int position;
      uint8_t format;
      int index;
      
      const_iterator(const std::string* str, bool at_end = false);
      
    public:
      const_iterator(const const_iterator& it);
      const_iterator& operator ++();
      const_iterator operator ++(int);
      bool operator ==(const const_iterator& rhs) const;
      bool operator !=(const const_iterator& rhs) const;
      char32_t operator *() const;
      
      int get_byte_index() const { return this->position; }
      int get_format() const { return this->format; }
      int get_logical_index() const { return this->index; }
    };
    
    class iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
      
      friend class ustring;
      
    private:
      std::string* string_pointer;
      int position;
      uint8_t format;
      int index;
      
      iterator(std::string* str, bool at_end = false);
      
    public:
      iterator(const iterator& it);
      iterator& operator++();
      iterator operator++(int);
      bool operator==(const iterator& rhs) const;
      bool operator!=(const iterator& rhs) const;
      char32_t operator*() const;
      char32_t& operator *();
      
      int get_byte_index() const { return this->position; }
      int get_format() const { return this->format; }
      int get_logical_index() const { return this->index; }
    };
    
    class const_reverse_iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
      friend class ustring;
    private:
      const std::string* string_pointer;
      int position;
      uint8_t format;
      int index;
      
      const_reverse_iterator(const std::string* str, bool at_end = false);
      
    public:
      const_reverse_iterator(const const_reverse_iterator& it);
      const_reverse_iterator& operator++();
      const_reverse_iterator operator++(int);
      bool operator==(const const_reverse_iterator& rhs) const;
      bool operator!=(const const_reverse_iterator& rhs) const;
      char32_t operator*() const;
      
      int get_byte_index() const { return this->position; }
      int get_format() const { return this->format; }
      int get_logical_index() const { return this->index; }
    };
    
    class reverse_iterator : public std::iterator<std::forward_iterator_tag, char32_t> {
      friend class ustring;
    private:
      std::string* string_pointer;
      int position;
      uint8_t format;
      int index;
      
      reverse_iterator(std::string* str, bool at_end = false);
      
    public:
      reverse_iterator(const reverse_iterator& it);
      reverse_iterator& operator++();
      reverse_iterator operator++(int);
      bool operator==(const reverse_iterator& rhs) const;
      bool operator!=(const reverse_iterator& rhs) const;
      char32_t operator*() const;
      char32_t& operator*();
      
      int get_byte_index() const { return this->position; }
      int get_format() const { return this->format; }
      int get_logical_index() const { return this->index; }
    };
    
    const_iterator begin() const { return const_iterator(&this->string); }
    const_iterator end() const { return const_iterator(&this->string, true); }
    iterator begin() { return iterator(&this->string); }
    iterator end() { return iterator(&this->string, true); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(&this->string); }
    const_reverse_iterator rend() const { return const_reverse_iterator(&this->string, true); }
    reverse_iterator rbegin() { return reverse_iterator(&this->string); }
    reverse_iterator rend() { return reverse_iterator(&this->string, true); }

    static size_t npos;

  private:
    std::string string;
    size_t stringSize = 0;
  };
}
/// @endcond
