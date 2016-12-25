#include "../Includes/LanguageParam.h"

using namespace CountsLines;

const LanguageParam LanguageParam::Asp = LanguageParam({ ".vbs" }, { "'" }, { "/*" }, { "*/" }, { "\"" }, {});
const LanguageParam LanguageParam::Batch = LanguageParam({ ".bat" }, { "rem", "REM" }, {}, {}, { "\"" }, { "\\" });
const LanguageParam LanguageParam::COBOL = LanguageParam({ ".cbl", ".cob" }, { "*>" }, {}, {}, { "\"", "'" }, {});
const LanguageParam LanguageParam::C = LanguageParam({ ".c", ".h" }, {}, { "/*" }, { "*/" }, { "\"" }, { "\\" });
const LanguageParam LanguageParam::CPlusPlus = LanguageParam({ ".c", ".cc", ".cpp", ".cxx", ".h", ".hpp", ".hxx" }, { "//" }, { "/*" }, { "*/" }, { "\"" }, { "\\" });
const LanguageParam LanguageParam::CSharp = LanguageParam({ ".cs" }, { "//" }, { "/*" }, { "*/" }, { "\"" }, { "\\" });
const LanguageParam LanguageParam::CSS = LanguageParam({ ".css" }, { "//" }, { "/*" }, { "*/" }, { "\"", "'" }, { "\\" });
const LanguageParam LanguageParam::DelphiPascal = LanguageParam({ ".pas" }, { "//" }, { "{", "(*" }, { "}", "*)" }, { "'" }, {});
const LanguageParam LanguageParam::Fortran = LanguageParam({ ".f", ".f90", ".f95", ".for" }, { "C", "!" }, {}, {}, { "'" }, { "\\" });
const LanguageParam LanguageParam::HTML = LanguageParam({ ".asp", ".cfm", ".htm", ".html", ".hta", ".htt", ".htx", ".jsp", ".phtml", ".shtml", ".tmpl" }, {}, {"<!-", "<!-"}, {"->", "- >"}, {}, {});
const LanguageParam LanguageParam::Java = LanguageParam({ ".jav", ".java" }, { "//" }, { "/*" }, { "*/" }, { "\"" }, { "\\" });
const LanguageParam LanguageParam::JavaScript = LanguageParam({ ".js" }, { "//" }, { "/*" }, { "*/" }, { "\"", "'" }, { "\\" });
const LanguageParam LanguageParam::MetaQuotesLanguage = LanguageParam({ ".mq4", ".mq5", ".mqh" }, { "//" }, { "/*" }, { "*/" }, { "\"" }, { "\\" });
const LanguageParam LanguageParam::Modula = LanguageParam({ ".mod" }, {}, { "(*" }, { "*)" }, { "\"", "'" }, {});
const LanguageParam LanguageParam::MySQL = LanguageParam({ ".sql" }, {"#", "-"}, { "/*" }, { "*/" }, { "\"" }, {"\\"});
const LanguageParam LanguageParam::Pascal = LanguageParam({ ".pas" }, { "//" }, { "{", "(*" }, { "}", "*)" }, { "'" }, {});
const LanguageParam LanguageParam::Perl = LanguageParam({ ".cgi", ".pl", ".plx", ".pm" }, { "#" }, { "=pod" }, { "=cut" }, { "\"" }, { "\\" });
const LanguageParam LanguageParam::PHP = LanguageParam({ ".inc", ".php", ".php3", ".php4", ".php5" }, { "//", "#" }, { "/*" }, { "*/" }, { "\"", "'" }, { "\\" });
const LanguageParam LanguageParam::Prolog = LanguageParam({ ".pl" }, { "%" }, { "/*" }, { "*/" }, { "'" }, {});
const LanguageParam LanguageParam::Python = LanguageParam({ ".py" }, { "#" }, {}, {}, { "\"", "'" }, { "\\" });
const LanguageParam LanguageParam::Ruby = LanguageParam({ ".rb", ".rbw" }, { "#" }, { "=begin" }, { "=end" }, { "\"", "'" }, { "\\" });
const LanguageParam LanguageParam::VBScript = LanguageParam({ ".vbs" }, { "'" }, { "/*" }, { "*/" }, { "\"" }, {});
const LanguageParam LanguageParam::VisualBasic = LanguageParam({ ".vb" }, { "'" }, {}, {}, { "\"" }, {});
const LanguageParam LanguageParam::XML = LanguageParam({ ".wsdl", ".xml", ".xsd", ".xsl", ".xslt", ".xul" }, {}, { "<!-", "<!-" }, { "->", "- >" }, {}, {});
