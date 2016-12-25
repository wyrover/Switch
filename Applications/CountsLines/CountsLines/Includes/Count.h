#pragma once

#include <Pcf/Pcf>

namespace CountsLines {
  class Counts : public object {
  public:
    Counts() {}
    Counts(int line, int blank, int code, int comment, int mixed) : line(line), blank(blank), code(code), comment(comment), mixed(mixed) {}
    
    /// @cond
    Counts(const Counts& counts) : line(counts.line), blank(counts.blank), code(counts.code), comment(counts.comment), mixed(counts.mixed) {}
    Counts& operator =(const Counts& counts) {
      this->line = counts.line;
      this->blank = counts.blank;
      this->code = counts.code;
      this->comment = counts.comment;
      this->mixed = counts.mixed;
      return *this;
    }
    /// @endcond
    
    Property<int, ReadOnly> Line {
      pcf_get {return this->line;}
    };
    
    Property<int, ReadOnly> Blank {
      pcf_get {return this->blank;}
    };
    
    Property<int, ReadOnly> Code {
      pcf_get {return this->code;}
    };
    
    Property<int, ReadOnly> Comment {
      pcf_get {return this->comment;}
    };
    
    Property<int, ReadOnly> Mixed {
      pcf_get {return this->mixed;}
    };
    
  private:
    int line = 0;
    int blank = 0;
    int code = 0;
    int comment = 0;
    int mixed = 0;
  };
}