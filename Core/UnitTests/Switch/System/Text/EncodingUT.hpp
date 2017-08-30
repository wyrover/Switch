#include <Switch/System/Array.hpp>
#include <Switch/System/Collections/Generic/List.hpp>
#include <Switch/System/Text/Encoding.hpp>

using namespace System;

namespace EncodingUT {
  using Bytes = System::Array<byte>;
  using Chars = System::Array<char32>;

  void CheckErrorsGetBytes(const System::Text::Encoding& encoding);
  void CheckErrorsGetByteCount(const System::Text::Encoding& encoding);
  void CheckErrorsGetCharCount(const System::Text::Encoding& encoding);
  void CheckErrorsGetChars(const System::Text::Encoding& encoding);
  void CheckErrorsString(const System::Text::Encoding& encoding);
  void GetByteCountTest(refptr<System::Text::Encoding> encoding, int charByteSize, int piByteSize, int sigmaByteSize, int koalaByteSize);
  void GetBytesTest(refptr<System::Text::Encoding>, int, int , int, int, const string&, const string&, const string&, const string&);
  void ConvertTest(const System::Text::Encoding& srcEncoding, const System::Text::Encoding& dstEncoding, const Bytes& bytes, const string& reference);

  void EXPECT_CHARS(const char32 expected[], int32 size, const char32 actual[]);
  void EXPECT_CHARS(const char32 expected[], int32 size, System::Array<char32> actual);
  void EXPECT_BYTES(const byte expected[], int32 size, System::Array<byte> actual);
  void EXPECT_BYTES(const byte expected[], int32 size, const byte actual[]);

  int32 ConcatBytes(byte destBytes[], int32 index, const byte bytes[], int32 size);

  class UnicodeSequence;
  class UnicodeCharacter {
  public:
    UnicodeCharacter() { }
    explicit UnicodeCharacter(char32 c, const byte b[], int32 byteCount) {
      character = c;
      for(int32 i = 0; i < byteCount; i += 1)
        bytes.Add(b[i]);
      if(byteCount == 1 && b[0] == Switch::System::Text::Encoding::Unknown())
        decodedCharacter = Switch::System::Text::Encoding::Unknown();
      else
        decodedCharacter = character;
    }

    UnicodeCharacter(const UnicodeCharacter& e) {
      character = e.character;
      bytes = e.bytes;
      decodedCharacter = e.decodedCharacter;
    }

    UnicodeSequence operator+(const UnicodeCharacter& info) const;

    bool operator==(const UnicodeCharacter& c) const;

    Switch::System::String ToString() const {
      return string() + character;
    }

    const byte* Bytes() const { return bytes.Data(); }
    int32 Size() const { return bytes.Count; }

    char32 Character() const { return character; }
    char32 DecodedCharacter() const { return decodedCharacter; }

    const char32* Chars() const { return &character; }
    const char32* DecodedChars() const { return &decodedCharacter; }
    int32 Count() const { return 1; }

  protected:
    char32 character;
    char32 decodedCharacter;
    Switch::System::Collections::Generic::List<byte> bytes;
  };

  class UnicodeSequence {
  public:
    UnicodeSequence() { }

    UnicodeSequence(const UnicodeCharacter& c) {
      chars.Add(c.Character());
      for(int32  i = 0; i < c.Size(); i += 1) {
        bytes.Add(c.Bytes()[i]);
      }
      decodedChars.Add(c.DecodedCharacter());
    }

    UnicodeSequence(const Switch::System::Array<UnicodeCharacter>& chars) { 
      for(int32 i = 0; i < chars.Length; i++)
        *this += chars[i];
    }

    UnicodeSequence(const UnicodeSequence& e) {
      chars = e.chars;
      bytes = e.bytes;
      decodedChars = e.decodedChars;
    }

    UnicodeSequence operator+(const UnicodeSequence& info) const;
    UnicodeSequence& operator+=(const UnicodeSequence& info);

    Switch::System::String ToString() const {
      return Switch::System::String(chars.Data(), chars.Count);
    }

    const byte* Bytes() const { return bytes.Data(); }
    int32 Size() const { return bytes.Count; }

    const char32* Chars() const { return chars.Data(); }
    const char32* DecodedChars() const { return decodedChars.Data(); }
    int32 Count() const { return chars.Count; }

  protected:
    Switch::System::Collections::Generic::List<char32> chars;
    Switch::System::Collections::Generic::List<char32> decodedChars;
    Switch::System::Collections::Generic::List<byte> bytes;
  };
}
