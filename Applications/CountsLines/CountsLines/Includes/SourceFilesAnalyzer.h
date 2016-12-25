#pragma once

#include <Pcf/Pcf>
#include "LanguageParam.h"
#include "SourceFilesAnalyzerEventHandler.h"
#include "SourceFilesReport.h"

namespace CountsLines {
  class SourceFilesAnalyzer : public object {
  public:
    SourceFilesAnalyzer(const string& path, const LanguageParam& languageParam) : fileBrowser(path, languageParam.Extensions()), languageParam(languageParam) {
      this->fileBrowser.BrowsedFile += {*this, &SourceFilesAnalyzer::OnBrowsedFile};
    }
    
    SourceFilesAnalyzerEventHandler AnalyzedFile;
    
    SourceFilesReport Counts() {
      this->fileBrowser.Browse();
      return SourceFilesReport({this->lineCount, this->blankLineCount, this->codeLineCount, this->commentLineCount, this->mixedLineCount}, this->fileReports);
    }
    
  private:
    void OnBrowsedFile(const object& sender, Toolbox::IO::FileBrowsedEventArgs& e) {
      FileReport fileReport = AnalyseFile(e.FileInfo, this->languageParam);
      this->lineCount += fileReport.Counts().Line;
      this->blankLineCount += fileReport.Counts().Blank;
      this->codeLineCount += fileReport.Counts().Code;
      this->commentLineCount += fileReport.Counts().Comment;
      this->mixedLineCount += fileReport.Counts().Mixed;
      this->fileReports.Add(fileReport);
      SourceFilesAnalyzerEventArgs countsLinesEventArgs(e, fileReport);
      this->AnalyzedFile.Invoke(*this, countsLinesEventArgs);
      e.Cancel = countsLinesEventArgs.Cancel;
    }
    
    static FileReport AnalyseFile(const System::IO::FileInfo& fileInfo, const LanguageParam& languageParam) {
      int lineCount = 0, blankLineCount = 0, codeLineCount = 0, commentLineCount = 0, mixedLineCount = 0;
      bool isBlank = true, isEndLine = false, isComment = false;
      string text = System::IO::File::ReadAllText(fileInfo.FullName());
      const string endLine = "\n";
      
      for (string::iterator iterator = text.begin(); iterator != text.end(); ++iterator) {
        for (string singleLineComment : languageParam.SingleLineComments()) {
          if (iterator != text.end() && !singleLineComment.IsEmpty() && Contains(iterator, singleLineComment)) {
            isComment = true;
            while (++iterator != text.end() && !Contains(iterator, endLine));
          }
        }
        
        for (int index = 0; index < languageParam.BlockCommentStarts().Count(); index++) {
          if (iterator != text.end() && !languageParam.BlockCommentStarts()[index].IsEmpty() && !languageParam.BlockCommentEnds()[index].IsEmpty() && Contains(iterator, languageParam.BlockCommentStarts()[index])) {
            isComment = true;
            while (++iterator != text.end() && !Contains(iterator, languageParam.BlockCommentEnds()[index])) {
              if (Contains(iterator, endLine)) {
                if (isBlank) ++commentLineCount;
                else ++mixedLineCount;
                ++lineCount;
                isBlank = true;
              }
            }
            IncreaseIterator(iterator, languageParam.BlockCommentEnds()[index].Length());
          }
        }
        
        for (string stringEnlcoser : languageParam.StringEnclosers()) {
          if (iterator != text.end() && !stringEnlcoser.IsEmpty() && Contains(iterator, stringEnlcoser)) {
            IncreaseIterator(iterator, stringEnlcoser.Length());
            while (++iterator != text.end()) {
              for (string escapeCharacter : languageParam.EscapeCharacters()) {
                if (!escapeCharacter.IsEmpty() && Contains(iterator, escapeCharacter))
                  IncreaseIterator(iterator, escapeCharacter.Length() + 1);
              }
              if (Contains(iterator, stringEnlcoser))
                break;
            }
            IncreaseIterator(iterator, stringEnlcoser.Length());
          }
        }
        
        if (iterator != text.end() && *iterator != ' ' && *iterator != '\r' && *iterator != '\n' && *iterator != '\t')
          isBlank = false;
        
        isEndLine = false;
        if (iterator != text.end() && Contains(iterator, endLine)) {
          if (isComment == true) {
            if (isBlank) ++commentLineCount;
            else ++mixedLineCount;
          } else {
            if (isBlank) ++blankLineCount;
            else ++codeLineCount;
          }
          
          ++lineCount;
          isEndLine = isBlank = true;
          isComment = false;
        }
      }
      
      if (!isEndLine) {
        ++lineCount;
        if (isComment == true) {
          if (isBlank) ++commentLineCount;
          else ++mixedLineCount;
        } else {
          if (isBlank) ++blankLineCount;
          else ++codeLineCount;
        }
      }
      
      return FileReport(fileInfo, {lineCount, blankLineCount, codeLineCount, commentLineCount, mixedLineCount});
    }
    
    static bool Contains(string::iterator iterator, const string& tag) {
      for (char32 car : tag) {
        if (*iterator != car)
          return false;
        ++iterator;
      }
      return true;
    }
    
    static void IncreaseIterator(string::iterator& iterator, int count) {
      for (int i = 0; i < count; i++)
        ++iterator;
    }
    
    Toolbox::IO::FileBrowser fileBrowser;
    LanguageParam languageParam;
    int lineCount = 0;
    int blankLineCount = 0;
    int codeLineCount = 0;
    int commentLineCount = 0;
    int mixedLineCount = 0;
    FileReportCollection fileReports;
  };
}