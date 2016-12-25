#pragma once

#include <Pcf/Pcf>

#define pcf_language_C89 0x0001
#define pcf_language_C90 0x0002
#define pcf_language_C94 0x0003
#define pcf_language_C99 0x0004
#define pcf_language_C11 0x0005
#define pcf_language_Cpp98 0x0101
#define pcf_language_Cpp11 0x0102
#define pcf_language_Cpp14 0x0103
#define pcf_language_CppCLI 0x0201
#define pcf_language_ECpp 0x0301
#define pcf_language_SDP_C 0x0000

#if __cplusplus
#  if (__cplusplus == 201402L)
#    define pcf_language pcf_language_Cpp14
#  elif (__cplusplus == 201103L)
#    define pcf_language pcf_language_Cpp11
#  else
#    define pcf_language pcf_language_Cpp98
#  endif
#elif __embedded_cplusplus
#  define pcf_language pcf_language_ECpp9
#elif __STDC__
#  if __STDC_VERSION__
#    if __STDC_VERSION__ == 201112L
#      define pcf_language pcf_language_C11
#    elif __STDC_VERSION__ == 199901L
#      define pcf_language pcf_language_C99
#    else
#      define pcf_language pcf_language_C94
#    endif
#  elsif
#    define pcf_language pcf_language_C89
#  endif
#else
#define pcf_language = pcf_language_SDP_C;
#endif


namespace Pcf {
  namespace Toolbox {
    namespace SystemInformation {
      /// @brief Language standards
      enum class Language {
        /// @brief ANSI X3.159-1989
        C89,
        /// @brief ISO/IEC 9899:1990
        C90,
        /// @brief ISO/IEC 9899-1:1994
        C94,
        /// @brief ISO/IEC 9899:1999
        C99,
        /// @brief ISO/IEC 9899:2011
        C11,
        /// @brief ISO/IEC 14882:1998
        Cpp98,
        /// @brief ISO/IEC 14882:2011
        Cpp11,
        /// @brief ISO/IEC 14882:2014
        Cpp14,
        /// @brief ECMA-372
        CppCLI,
        /// @brief Embedded C++
        ECpp,
        /// @brief ISO/IEC JTC1/SC22 WG14/N854
        DSP_C
      };
      
      class LanguageInformation : public object {
      public:
        static Language Id() {
#if __cplusplus
          if (__cplusplus == 201402L)
            return Language::Cpp14;
          
          if (__cplusplus == 201103L)
            return Language::Cpp11;
          
          return Language::Cpp98;
#elif __embedded_cplusplus
          return Language::ECpp;
#elif __STDC__
#if __STDC_VERSION__
          if (__STDC_VERSION__ == 201112L)
            return Language::C11;
          
          if (__STDC_VERSION__ == 199901L)
            return Language::C99;
          
          return Language::C94;
#else
          return Language::C89;
#endif
#else
          return Language::DSP_C;
#endif
        }
        
        static bool IsCppSupported() {
          return Id() == Language::Cpp98 || Id() == Language::Cpp11 || Id() == Language::Cpp14 || Id() == Language::CppCLI || Id() == Language::ECpp;
        }
        
        static string Name() {
          switch (Id()) {
            case Language::C89: return "C89";
            case Language::C90: return "C90";
            case Language::C94: return "C94";
            case Language::C99: return "C99";
            case Language::C11: return "C11";
            case Language::Cpp98: return "C++98";
            case Language::Cpp11: return "C++11";
            case Language::Cpp14: return "C++14";
            case Language::CppCLI: return "C++/CLI";
            case Language::ECpp: return "EC++";
            case Language::DSP_C: return "DSP-C";
          }
          return "<Unknown>";
        }
        
        static System::Version Version() {
#if __cplusplus
          return System::Version(__cplusplus/100, __cplusplus%100);
#elif __embedded_cplusplus
          return System::Version();
#elif __STDC_VERSION__
          return System::Version(__STDC_VERSION__/100, __STDC_VERSION__%100);
#else
          return System::Version();
#endif
        }
        
      private:
        LanguageInformation() {}
      };
    }
  }
}
template <>
class EnumToStrings<Toolbox::SystemInformation::Language> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values[(int32)Toolbox::SystemInformation::Language::C89] = "C89";
    values[(int32)Toolbox::SystemInformation::Language::C90] = "C90";
    values[(int32)Toolbox::SystemInformation::Language::C94] = "C94";
    values[(int32)Toolbox::SystemInformation::Language::C99] = "C99";
    values[(int32)Toolbox::SystemInformation::Language::C11] = "C11";
    values[(int32)Toolbox::SystemInformation::Language::Cpp98] = "Cpp98";
    values[(int32)Toolbox::SystemInformation::Language::Cpp11] = "Cpp11";
    values[(int32)Toolbox::SystemInformation::Language::Cpp14] = "Cpp14";
    values[(int32)Toolbox::SystemInformation::Language::CppCLI] = "CppCLI";
    values[(int32)Toolbox::SystemInformation::Language::ECpp] = "ECpp";
    values[(int32)Toolbox::SystemInformation::Language::DSP_C] = "DSP_C";
  }
};
