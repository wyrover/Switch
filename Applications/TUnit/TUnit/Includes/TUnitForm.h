#pragma once

#include <Pcf/Pcf>

#include "Test.h"
#include "TestCase.h"
#include "TestCaseCollection.h"
#include "TestCollection.h"

namespace TUnitApplication {
  class TUnitForm : public System::Windows::Forms::Form {
  public:
    TUnitForm();
    
  private:
    void InitRun();
    
    void GetParamsFromControls();
    
    void SetControlsFromParams();
    
    string ToGoogleParams() const;
    
    void EndRun();
    
    void Run(const TestCaseCollection& testCases);
    
    void Run(const TestCase& testCase);
    
    void Run(const Test& test);
    
    void Run();
    
    static TestCaseCollection GetTests(const string& processName);

    class Params {
    public:
      static const Params Default;
      
      Params() : xmlFileName(System::IO::Path::Combine(System::Environment::GetFolderPath(System::Environment::SpecialFolder::MyDocuments),  "TUnit.xml")) {}
      Params(const Params& params) : xmlFileName(params.XmlFileName), runIgnoredTests(params.runIgnoredTests), repeatCount(params.repeatCount), isRepeatForEver(params.isRepeatForEver), isShuffle(params.isShuffle), shuffleSeed(params.shuffleSeed), isThreadSafeDeathTestStyle(params.isThreadSafeDeathTestStyle), isThrowOnFailure(params.isThrowOnFailure) {}
      Params& operator =(const Params& params) {
        this->XmlFileName = params.XmlFileName;
        this->runIgnoredTests = params.runIgnoredTests;
        this->repeatCount = params.repeatCount;
        this->isRepeatForEver = params.isRepeatForEver;
        this->isShuffle = params.isShuffle;
        this->shuffleSeed = params.shuffleSeed;
        this->isThreadSafeDeathTestStyle = params.isThreadSafeDeathTestStyle;
        this->isThrowOnFailure = params.isThrowOnFailure;
        return *this;
      }
      
      static Params Load() {
        Params params;
        
        return params;
      }
      
      static void Save(const Params& params) {
      }
      
      bool operator ==(const Params& rhs) {return this->xmlFileName == rhs.xmlFileName && this->runIgnoredTests == rhs.runIgnoredTests && this->repeatCount == rhs.repeatCount && this->isRepeatForEver ==  rhs.isRepeatForEver && this->isShuffle == rhs.isShuffle && this->shuffleSeed == rhs.shuffleSeed && this->isThreadSafeDeathTestStyle == rhs.isThreadSafeDeathTestStyle && this->isThrowOnFailure == rhs.isThrowOnFailure;}
      
      bool operator !=(const Params& rhs) {return !this->operator==(rhs);}
      
      Property<string> XmlFileName {
        pcf_get {return this->xmlFileName;},
        pcf_set {this->xmlFileName = value;}
      };
      
      Property<bool> RunIgnoredTest {
        pcf_get {return this->runIgnoredTests;},
        pcf_set {this->runIgnoredTests = value;}
      };
      
      Property<int32> RepeatCount {
        pcf_get {return this->repeatCount;},
        pcf_set {
          if (value == 0)
            throw System::ArgumentOutOfRangeException(pcf_current_information);
          this->repeatCount = value;
        }
      };
      
      Property<bool> IsRepeatForEver {
        pcf_get {return this->isRepeatForEver;},
        pcf_set {this->isRepeatForEver = value;}
      };
      
      Property<bool> IsShuffle {
        pcf_get {return this->isShuffle;},
        pcf_set {this->isShuffle = value;}
      };
      
      Property<int32> ShuffleSeed {
        pcf_get {return this->shuffleSeed;},
        pcf_set {
          if (value < 0 || value > 99999)
            throw System::ArgumentOutOfRangeException(pcf_current_information);
          this->shuffleSeed = value;
        }
      };
      
      Property<bool> IsThreadSafeDeathTestStyle {
        pcf_get {return this->isThreadSafeDeathTestStyle;},
        pcf_set {this->isThreadSafeDeathTestStyle = value;}
      };
      
      Property<bool> IsThrowOnFailure {
        pcf_get {return this->isThrowOnFailure;},
        pcf_set {this->isThrowOnFailure = value;}
      };
      
    private:
      string xmlFileName;
      bool runIgnoredTests = false;
      int repeatCount = 1;
      bool isRepeatForEver = false;
      bool isShuffle = false;
      int shuffleSeed = 0;
      bool isThreadSafeDeathTestStyle = false;
      bool isThrowOnFailure = false;
    } params;
    
    class TestResult : public object {
    public:
      TestResult() {}
      TestResult(const TestResult& testResult) : tests(testResult.tests), testCases(testResult.testCases), failures(testResult.failures), ignored(testResult.ignored), errors(testResult.errors), time(testResult.time), message(testResult.message) {}
      TestResult& operator =(const TestResult& testResult) {
        this->tests = testResult.tests;
        this->testCases = testResult.testCases;
        this->failures = testResult.failures;
        this->ignored = testResult.ignored;
        this->errors = testResult.errors;
        this->time = testResult.time;
        this->message = testResult.message;
        return *this;
      }

      void Clear() {
        this->tests = 0;
        this->testCases = 0;
        this->failures = 0;
        this->ignored = 0;
        this->errors = 0;
        this->time = 0;
        this->message = "";
      }
      
      TestResult& operator +=(const TestResult& rhs) {
        this->tests += rhs.tests;
        this->testCases += rhs.testCases;
        this->failures += rhs.failures;
        this->ignored += rhs.ignored;
        this->errors += rhs.errors;
        this->time += rhs.time;
        this->message += rhs.message;
        return *this;
      }
      
      Property<int> Tests {
        pcf_get {return this->tests;},
        pcf_set {this->tests = value;}
      };
      
      Property<int> TestCases {
        pcf_get {return this->testCases;},
        pcf_set {this->testCases = value;}
      };
      
      Property<int, ReadOnly> Passed {
        pcf_get{return this->tests - this->failures;}
      };
      
      Property<int> Failures {
        pcf_get {return this->failures;},
        pcf_set {this->failures = value;}
      };
      
      Property<int> Ignored {
        pcf_get {return this->ignored;},
        pcf_set {this->ignored = value;}
      };
      
      Property<int> Errors {
        pcf_get {return this->errors;},
        pcf_set {this->errors = value;}
      };
      
      Property<int> Time {
        pcf_get {return this->time;},
        pcf_set {this->time = value;}
      };
      
      Property<string> Message {
        pcf_get {return this->message;},
        pcf_set {this->message = value;}
      };
      
      string ToString() const override {
        return string::Format("Tests: {0,-5} From: {1,-5} Passed: {2,-5} Failures: {3,-5} Ignored: {4,-5} Time: {5} ms", this->Tests(), this->TestCases(), this->Passed(), this->Failures(), this->Ignored(), this->Time());
      }

    private:
      int tests = 0;
      int testCases = 0;
      int failures = 0;
      int ignored = 0;
      int errors = 0;
      int time = 0;
      string message;
    } testResult;
    
    static TestResult XmlToTestResult(const string& xml);
    
    bool running = false;
    TestCaseCollection testCases;
    System::Threading::Thread runner;
    
  #pragma region Pcf Form Designer generated code
  #define PcfGeneratingCode
  private:
    TUnitForm(const TUnitForm&) = delete;
    TUnitForm& operator =(const TUnitForm&) = delete;
    /// @brief Required method for Designer support - do not modify the contents of this method with the editor.
    void InitializeComponent();
    
    void OnTUnitFormClosed(const object& sender, const System::EventArgs& e);
    void OnUpPanelSizeChangedForm(const object& sender, const System::EventArgs& e);
    void OnProjectPanelSizeChangedForm(const object& sender, const System::EventArgs& e);
    void OnFileOpenSelected(const object& sender, const System::EventArgs& e);
    void OnFileExportResultsSelected(const object& sender, const System::EventArgs& e);
    void OnFileExportXmlSelected(const object& sender, const System::EventArgs& e);
    void OnFileExportConsoleOutputSelected(const object& sender, const System::EventArgs& e);
    void OnFileCloseSelected(const object& sender, const System::EventArgs& e);
    void OnViewMiniGUISelected(const object& sender, const System::EventArgs& e);
    void OnViewFullGUISelected(const object& sender, const System::EventArgs& e);
    void OnProjectRunAllSelected(const object& sender, const System::EventArgs& e);
    void OnProjectRunSelected(const object& sender, const System::EventArgs& e);
    void OnProjectStopSelected(const object& sender, const System::EventArgs& e);
    void OnResetProjectButtonClick(const object& sender, const System::EventArgs& e);
    void OnRepeatNumericUpDownClick(const object& sender, const System::EventArgs& e);
    void OnRepeatForEverCheckBoxClick(const object& sender, const System::EventArgs& e);
    void OnShuffleCheckBoxClick(const object& sender, const System::EventArgs& e);
    void OnShuffleSeedNumericUpDownClick(const object& sender, const System::EventArgs& e);
    void OnFastDeathTestStyleRadioButtonClick(const object& sender, const System::EventArgs& e);
    void OnThreadSafeDeathTestStyleRadioButtonClick(const object& sender, const System::EventArgs& e);
    void OnThrowOnFailureCheckBoxClick(const object& sender, const System::EventArgs& e);
    void OnLeftPanelSizeChangedForm(const object& sender, const System::EventArgs& e);
    void OnRunAlsoIgnoredTestsCheckBoxClick(const object& sender, const System::EventArgs& e);
    
    System::Windows::Forms::MainMenu mainMenu;
    System::Windows::Forms::Panel upPanel;
    System::Windows::Forms::Panel projectPanel;
    System::Windows::Forms::Label projectLabel;
    System::Windows::Forms::TextBox projectTextBox;
    System::Windows::Forms::Button selectProjectButton;
    System::Windows::Forms::Label projectInfos;
    System::Windows::Forms::Button resetProjectButton;
    System::Windows::Forms::GroupBox executionGroupBox;
    System::Windows::Forms::Label repeatLabel;
    System::Windows::Forms::NumericUpDown repeatNumericUpDown;
    System::Windows::Forms::CheckBox repeatForEverCheckBox;
    System::Windows::Forms::CheckBox shuffleCheckBox;
    System::Windows::Forms::NumericUpDown shuffleSeedNumericUpDown;
    System::Windows::Forms::Label seedShuffleLabel;
    System::Windows::Forms::GroupBox assertionGroupBox;
    System::Windows::Forms::RadioButton fastDeathTestStyleRadioButton;
    System::Windows::Forms::RadioButton threadSafeDeathTestStyleRadioButton;
    System::Windows::Forms::CheckBox throwOnFailureCheckBox;
    System::Windows::Forms::Panel leftPanel;
    System::Windows::Forms::Panel treePanel;
    System::Windows::Forms::Panel rightPanel;
    System::Windows::Forms::Panel runningPanel;
    System::Windows::Forms::Button runAllButton;
    System::Windows::Forms::Button runButton;
    System::Windows::Forms::Button stopButton;
    System::Windows::Forms::CheckBox runAlsoIgnoredTestsCheckBox;
    System::Windows::Forms::Timer runningTimer;
    System::Windows::Forms::Label resultStatusLabel;
    System::Windows::Forms::ProgressBar progress;
    System::Windows::Forms::TabControl outputTabControl;
    System::Windows::Forms::TabPage resultsTabPage;
    System::Windows::Forms::RichTextBox resultsRichTextBox;
    System::Windows::Forms::TabPage xmlFilesTabPage;
    System::Windows::Forms::RichTextBox xmlFilesRichTextBox;
    System::Windows::Forms::TabPage consoleTabPage;
    System::Windows::Forms::RichTextBox consoleRichTextBox;
  #undef PcfGeneratingCode
  #pragma endregion
  };
}
