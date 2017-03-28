#include <Pcf/System/Char.h>
#include <Pcf/System/IO/StreamReader.h>
#include <Pcf/System/Collections/Generic/HashSet.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfIntegrationTests {
  class UnicodeCharsTest : public TestFixture {
  protected:
    static void loadMap(const string& map, System::Collections::Generic::HashSet<uint32>& set) {
      System::IO::StreamReader sr(map);
      while (!sr.EndOfText()) {
        string line = sr.ReadLine();
        if (line != "")
          set.Add(Convert::ToUInt32(line));
      }
    }
    
    void IsLetterIsDigitIsPunct() {
      System::Collections::Generic::HashSet<uint32> isLetter;
      System::Collections::Generic::HashSet<uint32> isDigit;
      System::Collections::Generic::HashSet<uint32> isPunctuation;
      
      loadMap("isLetter.map", isLetter);
      loadMap("isDigit.map", isDigit);
      loadMap("isPunctuation.map", isPunctuation);

      for (char32 cp = 0; cp < Char::MaxValue; cp+=1) {
        Assert::AreEqual(Char::IsLetter(cp), isLetter.Contains(cp), pcf_current_information);
        Assert::AreEqual(Char::IsDigit(cp), isDigit.Contains(cp), pcf_current_information);
        Assert::AreEqual(Char::IsPunctuation(cp), isPunctuation.Contains(cp), pcf_current_information);
      }
    }
  };
  
  pcf_test(UnicodeCharsTest, IsLetterIsDigitIsPunct)
}
