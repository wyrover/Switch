#include <Pcf/Toolbox>
#include "../Includes/SourceFilesAnalyzer.h"

using namespace System;

namespace CountsLines {
  class Program : public object {
  public:
    static int Main(const Array<string>& args) {
      System::Diagnostics::Stopwatch sw = System::Diagnostics::Stopwatch::StartNew();
      Console::WriteLine("CountsLines version {0}", Version(1, 0, 0));
      Console::WriteLine("Analyzing please wait...");

      string projectPath;
      LanguageParam languageParam;
      if (ProcessArguments(args, projectPath, languageParam) == false) {
        Console::WriteLine(GetUsage());
        return -1;
      }
     
      SourceFilesAnalyzer sourceFilesAnalyzer(projectPath, languageParam);
      
      sourceFilesAnalyzer.AnalyzedFile += [](const object& sender, SourceFilesAnalyzerEventArgs& e) {
        Console::WriteLine("({0,3}%) {1} analyzed...", Convert::ToInt32(Convert::ToDouble(e.Index()) / e.Count * 100), e.FullName);
      };

      SourceFilesReport report = sourceFilesAnalyzer.Counts();

      Console::WriteLine();
      Console::WriteLine("{0} analyzed files", report.FileReports().Count);
      Console::WriteLine("For a total of {0} lines :", report.Counts().Line);
      Console::WriteLine(" - {0} code lines ({1}%)", report.Counts().Code, report.Counts().Line == 0 ? 0 : Convert::ToInt32(Convert::ToDouble(report.Counts().Code()) / report.Counts().Line * 100));
      Console::WriteLine(" - {0} blank lines ({1}%)", report.Counts().Blank, report.Counts().Line == 0 ? 0 : Convert::ToInt32(Convert::ToDouble(report.Counts().Blank()) / report.Counts().Line * 100));
      Console::WriteLine(" - {0} comment lines ({1}%)", report.Counts().Comment, report.Counts().Line == 0 ? 0 : Convert::ToInt32(Convert::ToDouble(report.Counts().Comment()) / report.Counts().Line * 100));
      Console::WriteLine(" - {0} mixed lines ({1}%)", report.Counts().Mixed, report.Counts().Line == 0 ? 0 : Convert::ToInt32(Convert::ToDouble(report.Counts().Mixed()) / report.Counts().Line * 100));
      Console::WriteLine("Duration {0}", sw.Elapsed);
      return 0;
    }

    static bool ProcessArguments(const Array<string>& args, string& projectPath, LanguageParam& languageParam) {
      string language;
      if (args.Length == 2 && (args[1] == "-h" || args[1] == "--help"))
        return false;

      if (args.Length != 4)
        return false;

      for (int i = 0; i < args.Length; i += 2) {
        if (args[i] == "-p" || args[i] == "--project_path")
          projectPath = args[i + 1];
        else if (args[i] == "-l" || args[i] == "--language")
          language = args[i + 1];
        else
          return false;
      }

      if (projectPath.IsEmpty())
        return false;

      if (language.Equals("Asp", true))
        languageParam = LanguageParam::Asp;
      else if (language.Equals("Batch", true))
        languageParam = LanguageParam::Batch;
      else if (language.Equals("COBOL", true))
        languageParam = LanguageParam::COBOL;
      else if (language.Equals("C", true))
        languageParam = LanguageParam::C;
      else if (language.Equals("CPlusPlus", true) || language.Equals("C++", true))
        languageParam = LanguageParam::CPlusPlus;
      else if (language.Equals("CSharp", true) || language.Equals("C#", true))
        languageParam = LanguageParam::CSharp;
      else if (language.Equals("CSS", true))
        languageParam = LanguageParam::CSS;
      else if (language.Equals("DelphiPascal", true))
        languageParam = LanguageParam::DelphiPascal;
      else if (language.Equals("Fortran", true))
        languageParam = LanguageParam::Fortran;
      else if (language.Equals("HTML", true))
        languageParam = LanguageParam::HTML;
      else if (language.Equals("Java", true))
        languageParam = LanguageParam::Java;
      else if (language.Equals("JavaScript", true))
        languageParam = LanguageParam::JavaScript;
      else if (language.Equals("MetaQuotesLanguage", true))
        languageParam = LanguageParam::MetaQuotesLanguage;
      else if (language.Equals("Modula", true))
        languageParam = LanguageParam::Modula;
      else if (language.Equals("MySQL", true))
        languageParam = LanguageParam::MySQL;
      else if (language.Equals("Pascal", true))
        languageParam = LanguageParam::Pascal;
      else if (language.Equals("Perl", true))
        languageParam = LanguageParam::Perl;
      else if (language.Equals("PHP", true))
        languageParam = LanguageParam::PHP;
      else if (language.Equals("Prolog", true))
        languageParam = LanguageParam::Prolog;
      else if (language.Equals("Python", true))
        languageParam = LanguageParam::Python;
      else if (language.Equals("Ruby", true))
        languageParam = LanguageParam::Ruby;
      else if (language.Equals("VBScript", true))
        languageParam = LanguageParam::VBScript;
      else if (language.Equals("VisualBasic", true))
        languageParam = LanguageParam::VisualBasic;
      else if (language.Equals("XML", true))
        languageParam = LanguageParam::XML;
      else
        return false;

      return true;
    }

    static string GetUsage() {
      return "Usage\n"
        "\n"
        "  CountsLines --project_path ProjectPath [--language Language]\n"
        "\n"
        "-p, --project_path      : The path of the project that you want count.\n"
        "-l, --language          : The project language; Specifie one these Languages:\n"
        "                            * Asp\n"
        "                            * Batch\n"
        "                            * COBOL\n"
        "                            * C\n"
        "                            * CPlusPlus | C++\n"
        "                            * CSharp | C#\n"
        "                            * CSS\n"
        "                            * DelphiPascal\n"
        "                            * Fortran\n"
        "                            * HTML\n"
        "                            * Java\n"
        "                            * JavaScript\n"
        "                            * MetaQuotesLanguage\n"
        "                            * Modula\n"
        "                            * MySQL\n"
        "                            * Pascal\n"
        "                            * Perl\n"
        "                            * PHP\n"
        "                            * Prolog\n"
        "                            * Python\n"
        "                            * Ruby\n"
        "                            * VBScript\n"
        "                            * VisualBasic\n"
        "                            * XML\n"
        "-h, --help              : Show this help page.\n";
    }
  };
}

pcf_startup(CountsLines::Program)
