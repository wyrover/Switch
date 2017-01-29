#include "../Includes/TUnitForm.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Linq;
using namespace System::Threading;
using namespace System::Windows::Forms;
using namespace TUnitApplication;

const TUnitForm::Params TUnitForm::Params::Default;

System::Collections::ArrayList items;

TUnitForm::TUnitForm() : Form(), params(Params::Load()), running(false) {
  InitializeComponent();
  SetControlsFromParams();
  
}

void TUnitForm::OnTUnitFormClosed(const object& sender, const EventArgs& e) {
  Params::Save(this->params);
  items.Clear();
}

void TUnitForm::OnUpPanelSizeChangedForm(const object& sender, const EventArgs& e) {
  this->leftPanel.Location = System::Drawing::Point(0, this->upPanel.Height);
  this->leftPanel.Height += this->upPanel.Height;
  this->runningPanel.Location = System::Drawing::Point(this->leftPanel.Width + 10, this->upPanel.Height + 10);
  this->runningPanel.Size = System::Drawing::Size(this->Width - this->leftPanel.Width - 20, this->Height - this->upPanel.Height - 20);
}

void TUnitForm::OnProjectPanelSizeChangedForm(const object& sender, const EventArgs& e) {
  this->executionGroupBox.Location = System::Drawing::Point(10, 80);
  this->executionGroupBox.Size = System::Drawing::Size((this->projectPanel.Width /2) - 15, 110);
  this->assertionGroupBox.Location = System::Drawing::Point((this->projectPanel.Width /2) + 5, 80);
  this->assertionGroupBox.Size = System::Drawing::Size((this->projectPanel.Width /2) - 15, 110);
  this->runButton.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom;
}

void TUnitForm::OnFileOpenSelected(const object& sender, const EventArgs& e) {
  int32 tests = 0;
  OpenFileDialog ofd;
  if (ofd.ShowDialog() == DialogResult::OK) {
    ofd.Close();
    try {
      this->testResult.Clear();
      this->projectTextBox.Text = ofd.FileName;
      this->Text = string::Format("{0} - TUnit", ofd.FileName);
      this->testCases = GetTests(this->projectTextBox.Text());
      
      int32 testCases = 0;
      for (TestCase testCase : this->testCases) {
        testCases++;
        tests += testCase.Tests().Count;
      }
    } catch(const Exception&) {
    }
    
    if (tests == 0)
      MessageBox::Show(string::Format("\"{0}\" is not a TUnit application.", ofd.FileName), "TUnit", MessageBoxButtons::OK, MessageBoxIcon::Error);
    else
      this->projectInfos.Text = string::Format("There are {0} tests from {1} test cases.", tests, this->testCases.Count);
    this->projectInfos.Enabled = tests != 0;
    this->executionGroupBox.Enabled = tests != 0;
    this->assertionGroupBox.Enabled = tests != 0;
    this->treePanel.Enabled = tests != 0;
    this->runningPanel.Enabled = tests != 0;
    
    items.Clear();
    System::Threading::Thread thread(ThreadStart([&] {
      if (tests != 0) {
        sp<Label> label = new Label();
        label->Parent = this->treePanel;
        label->AutoSize = true;
        label->Text = "@2>  TUnit";
        label->Location = System::Drawing::Point(10, 10);
        label->Click += [&](const object& sender, const EventArgs& e) {
          if (as<Label>(items[0]).Text == "@>  TUnit")
            as<Label>(items[0]).Text = "@2>  TUnit";
          else
            as<Label>(items[0]).Text = "@>  TUnit";
        };
        items.Add(label);
        
        int index = 0;
        for (TestCase testCase : this->testCases) {
          sp<Label> label = new Label();
          label->Parent = this->treePanel;
          label->AutoSize = true;
          label->Text = string::Format("@2>  {0}", testCase.Name);
          label->Location = System::Drawing::Point(20, 30 + (index * 20));
          items.Add(label);
          index++;
          
          for (Test test : testCase.Tests()) {
            sp<Label> label = new Label();
            label->Parent = this->treePanel;
            label->AutoSize = true;
            label->Text = string::Format("{0}", test.Name);
            label->Location = System::Drawing::Point(40, 30 + (index * 20));
            items.Add(label);
            index++;
          }
        }
      }
    }));
    thread.Start();
  }
}

void TUnitForm::OnFileExportResultsSelected(const object& sender, const EventArgs& e) {
}

void TUnitForm::OnFileExportXmlSelected(const object& sender, const EventArgs& e) {
}

void TUnitForm::OnFileExportConsoleOutputSelected(const object& sender, const EventArgs& e) {
}

void TUnitForm::OnFileCloseSelected(const object& sender, const EventArgs& e) {
  this->projectTextBox.Text = "";
  this->executionGroupBox.Enabled = false;
  this->assertionGroupBox.Enabled = false;
  this->treePanel.Enabled = false;
  this->runningPanel.Enabled = false;
  this->resultsRichTextBox.Text = "";
  this->consoleRichTextBox.Text = "";
  this->xmlFilesRichTextBox.Text = "";
}

void TUnitForm::OnViewMiniGUISelected(const object& sender, const EventArgs& e) {
  this->Location = System::Drawing::Point(300, 200);
  this->ClientSize = System::Drawing::Size(540, 250);
  this->upPanel.Size = System::Drawing::Size(this->Width, 0);
  this->leftPanel.Size = System::Drawing::Size(0, this->Height - this->upPanel.Height);
}

void TUnitForm::OnViewFullGUISelected(const object& sender, const EventArgs& e) {
  this->Location = System::Drawing::Point(300, 200);
  this->ClientSize = System::Drawing::Size(800, 600);
  this->upPanel.Size = System::Drawing::Size(this->Width, 210);
  this->leftPanel.Size = System::Drawing::Size(260, this->Height - this->upPanel.Height);
}

void TUnitForm::OnProjectRunAllSelected(const object& sender, const EventArgs& e) {
  this->Run();
}

void TUnitForm::OnProjectRunSelected(const object& sender, const EventArgs& e) {
  //this->Run(this->testCases);
  this->Run(this->testCases[0]);
  //this->Run(this->testCases[0].Tests()[0]);
}

void TUnitForm::OnProjectStopSelected(const object& sender, const EventArgs& e) {
  this->running = false;
  this->stopButton.Enabled = false;
}

void TUnitForm::OnResetProjectButtonClick(const object& sender, const System::EventArgs& e) {
  this->params = Params::Default;
  SetControlsFromParams();
}

void TUnitForm::OnRepeatNumericUpDownClick(const object& sender, const System::EventArgs& e) {
  this->params.RepeatCount = Convert::ToInt32(this->repeatNumericUpDown.Value);
  this->resetProjectButton.Enabled(this->params != Params::Default);
}

void TUnitForm::OnRepeatForEverCheckBoxClick(const object& sender, const System::EventArgs& e) {
  this->params.IsRepeatForEver = this->repeatForEverCheckBox.Checked;
  this->resetProjectButton.Enabled = this->params != Params::Default;
}

void TUnitForm::OnShuffleCheckBoxClick(const object& sender, const System::EventArgs& e) {
  this->params.IsShuffle = this->shuffleCheckBox.Checked;
  this->resetProjectButton.Enabled = this->params != Params::Default;
}

void TUnitForm::OnShuffleSeedNumericUpDownClick(const object& sender, const System::EventArgs& e) {
  this->params.ShuffleSeed = Convert::ToInt32(this->shuffleSeedNumericUpDown.Value);
  this->resetProjectButton.Enabled = this->params != Params::Default;
}

void TUnitForm::OnFastDeathTestStyleRadioButtonClick(const object& sender, const System::EventArgs& e) {
  this->params.IsThreadSafeDeathTestStyle = this->threadSafeDeathTestStyleRadioButton.Checked;
  this->resetProjectButton.Enabled = this->params != Params::Default;
}

void TUnitForm::OnThreadSafeDeathTestStyleRadioButtonClick(const object& sender, const System::EventArgs& e) {
  this->params.IsThreadSafeDeathTestStyle = this->threadSafeDeathTestStyleRadioButton.Checked;
  this->resetProjectButton.Enabled = this->params != Params::Default;
}

void TUnitForm::OnThrowOnFailureCheckBoxClick(const object& sender, const System::EventArgs& e) {
  this->params.IsThrowOnFailure = this->throwOnFailureCheckBox.Checked;
  this->resetProjectButton.Enabled(this->params != Params::Default);
}

void TUnitForm::OnLeftPanelSizeChangedForm(const object& sender, const EventArgs& e) {
  this->runningPanel.Location = System::Drawing::Point(this->leftPanel.Width + 10, this->upPanel.Height + 10);
  this->runningPanel.Size = System::Drawing::Size(this->Width - this->leftPanel.Width - 20, this->Height - this->upPanel.Height - 20);
}

void TUnitForm::OnRunAlsoIgnoredTestsCheckBoxClick(const object& sender, const System::EventArgs& e) {
  this->params.RunIgnoredTest = this->runAlsoIgnoredTestsCheckBox.Checked;
}

void TUnitForm::InitRun() {
  this->running = true;
  this->runButton.Enabled = false;
  this->runAllButton.Enabled = false;
  this->stopButton.Enabled = true;
  this->progress.ForeColor = Drawing::Color::Green;
  this->progress.Value = 0;
  this->progress.Maximum = this->testResult.Tests;
  this->progress.Text = "Running...";
  this->resultsRichTextBox.Text = "";
  this->consoleRichTextBox.Text = "";
  this->xmlFilesRichTextBox.Text = "";
  this->resultStatusLabel.Text = this->testResult.ToString();
}

void TUnitForm::GetParamsFromControls() {
  this->params.RunIgnoredTest = this->runAlsoIgnoredTestsCheckBox.Checked;
  this->params.RepeatCount = Convert::ToInt32(this->repeatNumericUpDown.Value);
  this->params.IsRepeatForEver = this->repeatForEverCheckBox.Checked;
  this->params.IsShuffle = this->shuffleCheckBox.Checked;
  this->params.ShuffleSeed = Convert::ToInt32(this->shuffleSeedNumericUpDown.Value);
  this->params.IsShuffle = this->shuffleCheckBox.Checked;
  this->params.IsThreadSafeDeathTestStyle = this->threadSafeDeathTestStyleRadioButton.Checked;
  this->params.IsThrowOnFailure = this->throwOnFailureCheckBox.Checked;
  this->resetProjectButton.Enabled = this->params != Params::Default;
}

void TUnitForm::SetControlsFromParams() {
  this->runAlsoIgnoredTestsCheckBox.Checked = this->params.RunIgnoredTest;
  this->repeatNumericUpDown.Value = this->params.RepeatCount;
  this->repeatForEverCheckBox.Checked = this->params.IsRepeatForEver();
  this->shuffleCheckBox.Checked = this->params.IsShuffle;
  this->shuffleSeedNumericUpDown.Value = this->params.ShuffleSeed;
  this->fastDeathTestStyleRadioButton.Checked = !this->params.IsThreadSafeDeathTestStyle;
  this->threadSafeDeathTestStyleRadioButton.Checked = this->params.IsThreadSafeDeathTestStyle;
  this->throwOnFailureCheckBox.Checked = this->params.IsThrowOnFailure;
  this->resetProjectButton.Enabled = this->params != Params::Default;
}

string TUnitForm::ToGoogleParams() const {
  string googleParams;
  
  if (this->params.RunIgnoredTest())
    googleParams += "--tunit_also_run_ignired_tests ";
  googleParams += string::Format("--tunit_output=xml:{0} ", this->params.XmlFileName);
  googleParams += string::Format("--tunit_repeat={0} ", this->params.IsRepeatForEver ? -1 : this->params.RepeatCount);
  if (this->params.IsShuffle)
    googleParams += "--tunit_shuffle ";
  googleParams += string::Format("--tunit_random_seed={0} ", this->params.ShuffleSeed);
  if (this->params.IsThreadSafeDeathTestStyle)
    googleParams += "--tunit_death_test_style=threadsafe ";
  if (this->params.IsThrowOnFailure)
    googleParams += "--tunit_throw_on_failure ";
  
  return googleParams;
}

void TUnitForm::EndRun() {
  this->running = false;
  this->runButton.Enabled = true;
  this->runAllButton.Enabled = true;
  this->stopButton.Enabled = false;
  this->progress.Text = "";
  //this->progress.Value = this->nbTests;
  this->resultStatusLabel.Text = this->testResult.ToString();
  this->Invalidate();
  Application::DoEvent();
}

void TUnitForm::Run(const TestCaseCollection& testCases) {
  GetParamsFromControls();
  this->testResult.Clear();
  this->testResult.TestCases = testCases.Count;
  this->testResult.Tests = 0;
  for (TestCase testCase : testCases) {
    this->testResult.Tests += testCase.Tests().Count * (this->params.IsRepeatForEver ? -1 : this->params.RepeatCount);
  }
  this->InitRun();
  this->testResult.Clear();
  this->runner = System::Threading::Thread(Threading::ParameterizedThreadStart([this](const object& testCases) {
    for(int32 repeat = 0; repeat < this->params.RepeatCount || this->params.IsRepeatForEver; ++repeat) {
      if (running == false)
        break;
      if (this->params.IsRepeatForEver)
        this->progress.Text = string::Format("Repeating all tests (iteration {0}) . . .", repeat+1);
      for (TestCase testCase : static_cast<const TestCaseCollection&>(testCases)) {
        if (running == false)
          break;
        up<System::Diagnostics::Process> process = System::Diagnostics::Process::Start(this->projectTextBox.Text, string::Format("{0} --tunit_filter={1}.*", ToGoogleParams(), testCase.Name));
        string consoleText = this->consoleRichTextBox.Text;
        if (this->params.RepeatCount != 1 || this->params.IsRepeatForEver)
          consoleText += string::Format("Repeating all tests (iteration {0}) . . .\n\n", repeat+1);
        consoleText += System::IO::StreamReader(process->StandardOutput()).ReadToEnd();
        consoleText += Environment::NewLine;
        this->consoleRichTextBox.Text = consoleText;
        string xmlText = this->xmlFilesRichTextBox.Text;
        xmlText += System::IO::StreamReader(this->params.XmlFileName()).ReadToEnd();
        xmlText += Environment::NewLine;
        this->xmlFilesRichTextBox.Text = xmlText;
        this->progress.Value += testCase.Tests().Count;
        this->Invalidate();
        Application::DoEvent();
      }
    }
    this->EndRun();
  }));
  this->runner.Start(testCases);
  this->runner.Join();
  this->EndRun();
}

void TUnitForm::Run(const TestCase& testCase) {
  GetParamsFromControls();
  this->testResult.Clear();
  this->testResult.TestCases = 1;
  this->testResult.Tests = testCase.Tests().Count * (this->params.IsRepeatForEver ? -1 : this->params.RepeatCount);
  this->InitRun();
  this->testResult.Clear();
  this->runner = System::Threading::Thread(Threading::ParameterizedThreadStart([this](const object& testCase) {
    for(int32 repeat = 0; repeat < this->params.RepeatCount() || this->params.IsRepeatForEver(); ++repeat) {
      if (running == false)
        break;
      if (this->params.IsRepeatForEver)
        this->progress.Text = string::Format("Repeating all tests (iteration {0}) . . .", repeat+1);
      up<System::Diagnostics::Process> process = System::Diagnostics::Process::Start(this->projectTextBox.Text(), string::Format("{0} --tunit_filter={1}.*", ToGoogleParams(), static_cast<const TestCase&>(testCase).Name()));
      string consoleText = this->consoleRichTextBox.Text;
      if (this->params.RepeatCount != 1 || this->params.IsRepeatForEver)
        consoleText += string::Format("Repeating all tests (iteration {0}) . . .\n\n", repeat+1);
      consoleText += System::IO::StreamReader(process->StandardOutput()).ReadToEnd();
      consoleText += Environment::NewLine;
      this->consoleRichTextBox.Text = consoleText;
      string xmlText = this->xmlFilesRichTextBox.Text;
      xmlText += System::IO::StreamReader(this->params.XmlFileName()).ReadToEnd();
      xmlText += Environment::NewLine;
      this->xmlFilesRichTextBox.Text = xmlText;
      this->testResult += TUnitForm::XmlToTestResult(xmlText);
      this->resultsRichTextBox.Text = this->testResult.Message;
      this->progress.ForeColor = this->testResult.Failures ? Drawing::Color::Red : Drawing::Color::Green;
      this->progress.Value += static_cast<const TestCase&>(testCase).Tests().Count;
      this->Pcf::System::Windows::Forms::Control::Invalidate();
      Application::DoEvent();
    }
    this->EndRun();
  }));
  this->runner.Start(testCase);
  this->runner.Join();
  this->EndRun();
}

void TUnitForm::Run(const Test& test) {
  GetParamsFromControls();
  this->testResult.Clear();
  this->testResult.TestCases = 1;
  this->testResult.Tests = 1 * (this->params.IsRepeatForEver ? -1 : this->params.RepeatCount);
  this->InitRun();
  this->testResult.Clear();
  this->runner = System::Threading::Thread(Threading::ParameterizedThreadStart([this](const object& test) {
    for(int32 repeat = 0; repeat < this->params.RepeatCount || this->params.IsRepeatForEver; ++repeat) {
      if (running == false)
        break;
      if (this->params.IsRepeatForEver)
        this->progress.Text = string::Format("Repeating all tests (iteration {0}) . . .", repeat+1);
      up<System::Diagnostics::Process> process = System::Diagnostics::Process::Start(this->projectTextBox.Text, string::Format("{0} --tunit_filter={1}.{2}", ToGoogleParams(), static_cast<const Test&>(test).TestCaseName, static_cast<const Test&>(test).Name));
      string consoleText = this->consoleRichTextBox.Text;
      if (this->params.RepeatCount != 1 || this->params.IsRepeatForEver)
        consoleText += string::Format("Repeating all tests (iteration {0}) . . .\n\n", repeat+1);
      consoleText += System::IO::StreamReader(process->StandardOutput()).ReadToEnd();
      consoleText += Environment::NewLine;
      this->consoleRichTextBox.Text = consoleText;
      string xmlText = this->xmlFilesRichTextBox.Text;
      xmlText += System::IO::StreamReader(this->params.XmlFileName()).ReadToEnd();
      xmlText += Environment::NewLine;
      this->xmlFilesRichTextBox.Text = xmlText;
      this->testResult += TUnitForm::XmlToTestResult(xmlText);
      this->resultsRichTextBox.Text = this->testResult.Message;
      this->progress.ForeColor = this->testResult.Failures() ? Drawing::Color::Red : Drawing::Color::Green;
      this->progress.Value += 1;
      this->Pcf::System::Windows::Forms::Control::Invalidate();
      Application::DoEvent();
    }
    this->EndRun();
  }));
  this->runner.Start(test);
  this->runner.Join();
  this->EndRun();
}

void TUnitForm::Run() {
  GetParamsFromControls();
  this->testResult.Clear();
  this->testResult.TestCases = 1;
  this->testResult.Tests = 1 * (this->params.IsRepeatForEver ? -1 : this->params.RepeatCount);
  this->InitRun();
  this->testResult.Clear();
  this->runner = System::Threading::Thread(Threading::ThreadStart([this]() {
    for(int32 repeat = 0; repeat < this->params.RepeatCount || this->params.IsRepeatForEver; ++repeat) {
      if (running == false)
        break;
      if (this->params.IsRepeatForEver)
        this->progress.Text = string::Format("Repeating all tests (iteration {0}) . . .", repeat+1);
      up<System::Diagnostics::Process> process = System::Diagnostics::Process::Start(this->projectTextBox.Text, ToGoogleParams());
      string consoleText = this->consoleRichTextBox.Text;
      if (this->params.RepeatCount != 1 || this->params.IsRepeatForEver)
        consoleText += string::Format("Repeating all tests (iteration {0}) . . .\n\n", repeat+1);
      consoleText += System::IO::StreamReader(process->StandardOutput()).ReadToEnd();
      consoleText += Environment::NewLine;
      this->consoleRichTextBox.Text = consoleText;
      string xmlText = this->xmlFilesRichTextBox.Text;
      xmlText += System::IO::StreamReader(this->params.XmlFileName()).ReadToEnd();
      xmlText += Environment::NewLine;
      this->xmlFilesRichTextBox.Text = xmlText;
      this->testResult += TUnitForm::XmlToTestResult(xmlText);
      this->resultsRichTextBox.Text = this->testResult.Message;
      this->progress.ForeColor = this->testResult.Failures() ? Drawing::Color::Red : Drawing::Color::Green;
      this->progress.Value = this->testResult.Tests();
      this->Pcf::System::Windows::Forms::Control::Invalidate();
      Application::DoEvent();
    }
    this->EndRun();
  }));
  this->runner.Start();
  //this->runner.Join();
  //this->EndRun();
}

TUnitForm::TestResult TUnitForm::XmlToTestResult(const string& xml) {
  TUnitForm::TestResult testResult;
  bool addToMessage = false;
  Array<string> lines = xml.Split('\n');
  
  for (string line : lines) {
    if (line.Contains("<testsuites ")) {
      line = line.Substring(12);
      Array<string> keyValues = line.Split(' ');
      for (string keyValue : keyValues) {
        if (keyValue.StartsWith("tests=")) {
          testResult.Tests(testResult.Tests() + Int32::Parse(keyValue.Substring(6).TrimStart('"').TrimEnd('"')));
        } else if (keyValue.StartsWith("failures=")) {
          testResult.Failures(testResult.Failures() + Int32::Parse(keyValue.Substring(9).TrimStart('"').TrimEnd('"')));
        } else if (keyValue.StartsWith("disabled=")) {
          testResult.Ignored(testResult.Ignored() + Int32::Parse(keyValue.Substring(9).TrimStart('"').TrimEnd('"')));
        } else if (keyValue.StartsWith("time=")) {
          testResult.Time(testResult.Time() + Convert::ToInt32(Double::Parse(keyValue.Substring(5).TrimStart('"').TrimEnd('"')) * 1000));
        }
      }
    } else if (line.Contains("<testsuite ")) {
      testResult.TestCases(testResult.TestCases() + 1);
    } else if (line.Contains("<failure message=")) {
      line = line.Substring(line.IndexOf("![CDATA[")+8);
      testResult.Message(testResult.Message() + line + Environment::NewLine());
      addToMessage = true;
    } else if (line.Contains("></failure>")) {
      addToMessage = false;
      testResult.Message(testResult.Message() + line.Remove(line.IndexOf("]]></failure>")) + Environment::NewLine() + Environment::NewLine());
    } else if (addToMessage)
      testResult.Message(testResult.Message() + line.TrimStart(' ') + Environment::NewLine());
  }
  return testResult;
}

TestCaseCollection TUnitForm::GetTests(const string& processName) {
  up<System::Diagnostics::Process> process = System::Diagnostics::Process::Start(processName, "--tunit_version");
  String version = System::IO::StreamReader(process->StandardOutput()).ReadToEnd();
  if (!version.StartsWith("TUnit version "))
    return TestCaseCollection();
  
  process = System::Diagnostics::Process::Start(processName, "--tunit_list_tests");
  //process->WaitForExit();
  System::IO::StreamReader reader(process->StandardOutput());
  TestCaseCollection testCases;
  TestCase testCase;
  while (!reader.EndOfStream()) {
    string str = reader.ReadLine();
    if (!str.StartsWith(' ')) {
      if (testCase.Tests().Count) {
        testCases.Add(testCase);
        testCase.Tests().Clear();
      }
      testCase.Name(str.Remove(str.IndexOf('.')));
    } else {
      testCase.Tests().Add(Test(str.TrimStart(' ').TrimEnd(' '), testCase.Name));
    }
  }
  
  if (testCase.Tests().Count) {
    testCases.Add(testCase);
    testCase.Tests().Clear();
  }
  
  return testCases;
}
