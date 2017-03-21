#pragma once

#include <Pcf/Pcf>

namespace CountsLines {
  class LanguageParam : public object {
  public:
    static const LanguageParam Asp;
    static const LanguageParam Batch;
    static const LanguageParam COBOL;
    static const LanguageParam C;
    static const LanguageParam CPlusPlus;
    static const LanguageParam CSharp;
    static const LanguageParam CSS;
    static const LanguageParam DelphiPascal;
    static const LanguageParam Fortran;
    static const LanguageParam HTML;
    static const LanguageParam Java;
    static const LanguageParam JavaScript;
    static const LanguageParam MetaQuotesLanguage;
    static const LanguageParam Modula;
    static const LanguageParam MySQL;
    static const LanguageParam Pascal;
    static const LanguageParam Perl;
    static const LanguageParam PHP;
    static const LanguageParam Prolog;
    static const LanguageParam Python;
    static const LanguageParam Ruby;
    static const LanguageParam VBScript;
    static const LanguageParam VisualBasic;
    static const LanguageParam XML;
    
    LanguageParam() {}
    
    LanguageParam(const System::Array<string>& extensions, const System::Array<string>& singleLineComments, const System::Array<string>& blockCommentStarts, const System::Array<string>& blockCommentEnds, const System::Array<string>& stringEnclosers, const System::Array<string>& escapeCharacters) : extensions(extensions), singleLineComments(singleLineComments), blockCommentStarts(blockCommentStarts), blockCommentEnds(blockCommentEnds), stringEnclosers(stringEnclosers), escapeCharacters(escapeCharacters) {}
    
    /// @cond
    LanguageParam(const LanguageParam& languageParam) : extensions(languageParam.extensions), singleLineComments(languageParam.singleLineComments), blockCommentStarts(languageParam.blockCommentStarts), blockCommentEnds(languageParam.blockCommentEnds), stringEnclosers(languageParam.stringEnclosers), escapeCharacters(languageParam.escapeCharacters) {}
    LanguageParam& operator =(const LanguageParam& languageParam) {
      this->extensions = languageParam.extensions;
      this->singleLineComments = languageParam.singleLineComments;
      this->blockCommentStarts = languageParam.blockCommentStarts;
      this->blockCommentEnds = languageParam.blockCommentEnds;
      this->stringEnclosers = languageParam.stringEnclosers;
      this->escapeCharacters = languageParam.escapeCharacters;
      return *this;
    }
    /// @endcond
    
    Property<System::Array<string>, ReadOnly> Extensions {
      pcf_get {return this->extensions;}
    };
    
    Property<System::Array<string>, ReadOnly> SingleLineComments {
      pcf_get {return this->singleLineComments;}
    };
    
    Property<System::Array<string>, ReadOnly> BlockCommentStarts {
      pcf_get {return this->blockCommentStarts;}
    };
    
    Property<System::Array<string>, ReadOnly> BlockCommentEnds {
      pcf_get {return this->blockCommentEnds;}
    };
    
    Property<System::Array<string>, ReadOnly> StringEnclosers {
      pcf_get {return this->stringEnclosers;}
    };
    
    Property<System::Array<string>, ReadOnly> EscapeCharacters {
      pcf_get { return this->escapeCharacters; }
    };
    
  private:
    System::Array<string> extensions;
    System::Array<string> singleLineComments;
    System::Array<string> blockCommentStarts;
    System::Array<string> blockCommentEnds;
    System::Array<string> stringEnclosers;
    System::Array<string> escapeCharacters;
  };
}