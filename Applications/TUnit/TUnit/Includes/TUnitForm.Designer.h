#pragma once

#include <Corelib.h>
#include <Core/Foreach.h>
#include <Forms/System/Windows/Forms/Application.h>
#include <Forms/System/Windows/Forms/Button.h>
#include <Forms/System/Windows/Forms/CheckBox.h>
#include <Forms/System/Windows/Forms/Form.h>
#include <Forms/System/Windows/Forms/GroupBox.h>
#include <Forms/System/Windows/Forms/Label.h>
#include <Forms/System/Windows/Forms/MainMenu.h>
#include <Forms/System/Windows/Forms/MessageBox.h>
#include <Forms/System/Windows/Forms/NumericUpDown.h>
#include <Forms/System/Windows/Forms/OpenFileDialog.h>
#include <Forms/System/Windows/Forms/Panel.h>
#include <Forms/System/Windows/Forms/ProgressBar.h>
#include <Forms/System/Windows/Forms/RadioButton.h>
#include <Forms/System/Windows/Forms/RichTextBox.h>
#include <Forms/System/Windows/Forms/TabControl.h>
#include <Forms/System/Windows/Forms/TabPage.h>
#include <Forms/System/Windows/Forms/TextBox.h>
#include <Forms/System/Windows/Forms/Timer.h>

namespace TUnit {
  /// @brief
  /// Required class for Designer support - do not modify
  /// the contents of this class with the editor.
  class partial_TUnitForm : public System::Windows::Forms::Form {
  protected:
    /// @method InitializeComponent
    /// @brief
    /// Required method for Designer support - do not modify
    /// the contents of this method with the editor.
    void InitializeComponent() {
      this->Location(300, 200);
      this->Size(800, 600);
      this->Text("TUnit");
      
      System::Array<System::Windows::Forms::MenuItem> openRecentsMenu = System::Array<System::Windows::Forms::MenuItem>::Build();
      System::Array<System::Windows::Forms::MenuItem> fileMenu =
      System::Array<System::Windows::Forms::MenuItem>::Build(System::Windows::Forms::MenuItem("Open...", {*this, &TUnitForm::OnFileOpenSelected}, System::Windows::Forms::Shortcut::CtrlO),
                                                             System::Windows::Forms::MenuItem("Open recent", openRecentsMenu),
                                                             System::Windows::Forms::MenuItem("-"),
                                                             System::Windows::Forms::MenuItem("Export results...", {*this, &TUnitForm::OnFileExportResultsSelected}),
                                                             System::Windows::Forms::MenuItem("Export xml...", {*this, &TUnitForm::OnFileExportXmlSelected}),
                                                             System::Windows::Forms::MenuItem("Export console output...", {*this, &TUnitForm::OnFileExportConsoleOutputSelected}),
                                                             System::Windows::Forms::MenuItem("-"),
                                                             System::Windows::Forms::MenuItem("Close", System::EventHandler(*this, &TUnitForm::OnFileCloseSelected), System::Windows::Forms::Shortcut::CtrlW));
      System::Array<System::Windows::Forms::MenuItem> ProjectMenu =
      System::Array<System::Windows::Forms::MenuItem>::Build(System::Windows::Forms::MenuItem("Run all", System::EventHandler(*this, &TUnitForm::OnProjectRunAllSelected), System::Windows::Forms::Shortcut::CtrlA),
                                                             System::Windows::Forms::MenuItem("Run", System::EventHandler(*this, &TUnitForm::OnProjectRunSelected), System::Windows::Forms::Shortcut::CtrlR),
                                                             System::Windows::Forms::MenuItem("-"),
                                                             System::Windows::Forms::MenuItem("Stop", System::EventHandler(*this, &TUnitForm::OnProjectStopSelected), System::Windows::Forms::Shortcut::CtrlS));
      System::Array<System::Windows::Forms::MenuItem> viewMenu =
      System::Array<System::Windows::Forms::MenuItem>::Build(System::Windows::Forms::MenuItem("Full GUI", System::EventHandler(*this, &TUnitForm::OnViewFullGUISelected), System::Windows::Forms::Shortcut::Ctrl1),
                                                             System::Windows::Forms::MenuItem("Mini GUI", System::EventHandler(*this, &TUnitForm::OnViewMiniGUISelected), System::Windows::Forms::Shortcut::Ctrl2));
      
      this->mainMenu.MenuItems().Add(System::Windows::Forms::MenuItem("&File", fileMenu));
      this->mainMenu.MenuItems().Add(System::Windows::Forms::MenuItem("&Project", ProjectMenu));
      this->mainMenu.MenuItems().Add(System::Windows::Forms::MenuItem("&View", viewMenu));
      
      this->Menu(this->mainMenu);
      
      this->upPanel = new System::Windows::Forms::Panel();
      this->upPanel->Parent(*this);
      this->upPanel->Location(0, 0);
      this->upPanel->Size(this->Width(), 210);
      this->upPanel->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
      this->upPanel->SizeChanged += [this](const object& sender, const System::EventArgs& e) {
        this->leftPanel->Location(0, this->upPanel->Height());
        this->leftPanel->Height(this->Height() - this->upPanel->Height());
        this->runningPanel->Location(this->leftPanel->Width() + 10, this->upPanel->Height() + 10);
        this->runningPanel->Size(this->Width() - this->leftPanel->Width() - 20, this->Height() - this->upPanel->Height() - 20);
      };
      
      this->projectPanel = new System::Windows::Forms::Panel();
      this->projectPanel->Parent(*this->upPanel);
      this->projectPanel->Location(10, 10);
      this->projectPanel->BorderStyle(System::Windows::Forms::BorderStyle::Fixed3D);
      this->projectPanel->Size(this->Width()-20, 200);
      this->projectPanel->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
      
      this->projectLabel = new System::Windows::Forms::Label();
      this->projectLabel->Parent(*this->projectPanel);
      this->projectLabel->Location(10, 15);
      this->projectLabel->Text("Project");
      
      this->projectInfos = new System::Windows::Forms::Label();
      this->projectInfos->Parent(*this->projectPanel);
      this->projectInfos->Location(10, 50);
      this->projectInfos->Text("There are 0 tests from 0 test cases.");
      this->projectInfos->Enabled(false);
      
      this->selectProjectButton = new System::Windows::Forms::Button();
      this->selectProjectButton->Parent(*this->projectPanel);
      this->selectProjectButton->Location(this->projectPanel->Width() - 85, 12);
      this->selectProjectButton->Text("&Select...");
      this->selectProjectButton->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->selectProjectButton->Click += {*this, &TUnitForm::OnFileOpenSelected};
      
      this->projectTextBox = new System::Windows::Forms::TextBox();
      this->projectTextBox->Parent(*this->projectPanel);
      this->projectTextBox->Location(60, 10);
      this->projectTextBox->Width(this->projectPanel->Width() - 155);
      this->projectTextBox->ReadOnly(true);
      this->projectTextBox->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
      
      this->resetProjectButton = new System::Windows::Forms::Button();
      this->resetProjectButton->Parent(*this->projectPanel);
      this->resetProjectButton->Location(this->projectPanel->Width() - 85, 42);
      this->resetProjectButton->Text("&Reset");
      this->resetProjectButton->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
      this->resetProjectButton->Enabled(this->params != Params::Default());
      this->resetProjectButton->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params = Params::Default();
        SetControlsFromParams();
      };
      
      this->executionGroupBox = new System::Windows::Forms::GroupBox();
      this->executionGroupBox->Parent(*this->projectPanel);
      this->executionGroupBox->Location(10, 80);
      this->executionGroupBox->Size((this->projectPanel->Width() /2) - 15, 110);
      this->executionGroupBox->BackColor(System::Drawing::Color::LightGray());
      this->executionGroupBox->Enabled(false);
      
      this->repeatLabel = new System::Windows::Forms::Label();
      this->repeatLabel->Parent(*this->executionGroupBox);
      this->repeatLabel->Location(23, 14);
      this->repeatLabel->Text("Repeat");
      
      this->repeatNumericUpDown = new System::Windows::Forms::NumericUpDown();
      this->repeatNumericUpDown->Parent(*this->executionGroupBox);
      this->repeatNumericUpDown->Location(80, 10);
      this->repeatNumericUpDown->Minimum(1);
      this->repeatNumericUpDown->Maximum(System::Int32::MaxValue());
      this->repeatNumericUpDown->Value(this->params.RepeatCount());
      this->repeatNumericUpDown->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.RepeatCount(this->repeatNumericUpDown->Value());
        this->resetProjectButton->Enabled(this->params != Params::Default());
      };
      
      this->repeatForEverCheckBox = new System::Windows::Forms::CheckBox();
      this->repeatForEverCheckBox->Parent(*this->executionGroupBox);
      this->repeatForEverCheckBox->Location(10, 40);
      this->repeatForEverCheckBox->Checked(this->params.IsRepeatForEver());
      this->repeatForEverCheckBox->Text("Repeat for ever");
      this->repeatForEverCheckBox->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.IsRepeatForEver(this->repeatForEverCheckBox->Checked());
        this->resetProjectButton->Enabled(this->params != Params::Default());
      };
      
      this->shuffleCheckBox = new System::Windows::Forms::CheckBox();
      this->shuffleCheckBox->Parent(*this->executionGroupBox);
      this->shuffleCheckBox->Location(10, 70);
      this->shuffleCheckBox->Text("Shufle");
      this->shuffleCheckBox->Checked(this->params.IsShuffle());
      this->shuffleCheckBox->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.IsShuffle(this->shuffleCheckBox->Checked());
        this->resetProjectButton->Enabled(this->params != Params::Default());
      };
      
      this->shuffleSeedNumericUpDown = new System::Windows::Forms::NumericUpDown();
      this->shuffleSeedNumericUpDown->Parent(*this->executionGroupBox);
      this->shuffleSeedNumericUpDown->Location(80, 70);
      this->shuffleSeedNumericUpDown->Maximum(99999);
      this->shuffleSeedNumericUpDown->Value(this->params.ShuffleSeed());
      this->shuffleSeedNumericUpDown->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.ShuffleSeed(this->shuffleSeedNumericUpDown->Value());
        this->resetProjectButton->Enabled(this->params != Params::Default());
      };
      
      this->seedShuffleLabel = new System::Windows::Forms::Label();
      this->seedShuffleLabel->Parent(*this->executionGroupBox);
      this->seedShuffleLabel->Location(185, 74);
      this->seedShuffleLabel->Text("seed");
      
      this->assertionGroupBox = new System::Windows::Forms::GroupBox();
      this->assertionGroupBox->Parent(*this->projectPanel);
      this->assertionGroupBox->Location((this->projectPanel->Width() /2) + 5, 80);
      this->assertionGroupBox->Size((this->projectPanel->Width() /2) - 15, 110);
      this->assertionGroupBox->BackColor(System::Drawing::Color::LightGray());
      this->assertionGroupBox->Enabled(false);
      
      this->fastDeathTestStyleRadioButton = new System::Windows::Forms::RadioButton();
      this->fastDeathTestStyleRadioButton->Parent(*this->assertionGroupBox);
      this->fastDeathTestStyleRadioButton->Location(10, 10);
      this->fastDeathTestStyleRadioButton->Text("Fast death test style (default)");
      this->fastDeathTestStyleRadioButton->Checked(true);
      this->fastDeathTestStyleRadioButton->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.IsThreadSafeDeathTestStyle(this->threadSafeDeathTestStyleRadioButton->Checked());
        this->resetProjectButton->Enabled(this->params != Params::Default());
      };
      
      this->threadSafeDeathTestStyleRadioButton = new System::Windows::Forms::RadioButton();
      this->threadSafeDeathTestStyleRadioButton->Parent(*this->assertionGroupBox);
      this->threadSafeDeathTestStyleRadioButton->Location(10, 40);
      this->threadSafeDeathTestStyleRadioButton->Text("Thread safe death test style");
      this->threadSafeDeathTestStyleRadioButton->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.IsThreadSafeDeathTestStyle(this->threadSafeDeathTestStyleRadioButton->Checked());
        this->resetProjectButton->Enabled(this->params != Params::Default());
      };
      
      this->throwOnFailureCheckBox = new System::Windows::Forms::CheckBox();
      this->throwOnFailureCheckBox->Parent(*this->assertionGroupBox);
      this->throwOnFailureCheckBox->Location(10, 70);
      this->throwOnFailureCheckBox->Text("Throw on failure");
      this->throwOnFailureCheckBox->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.IsThrowOnFailure(this->throwOnFailureCheckBox->Checked());
        this->resetProjectButton->Enabled(this->params != Params::Default());
      };
      
      this->leftPanel = new System::Windows::Forms::Panel();
      this->leftPanel->Parent(*this);
      this->leftPanel->Location(0, this->upPanel->Height());
      this->leftPanel->Size(260, this->Height() - this->upPanel->Height());
      this->leftPanel->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
      this->leftPanel->SizeChanged += [this](const object& sender, const System::EventArgs& e) {
        this->runningPanel->Location(this->leftPanel->Width() + 10, this->upPanel->Height() + 10);
        this->runningPanel->Size(this->Width() - this->leftPanel->Width() - 20, this->Height() - this->upPanel->Height() - 20);
      };
      
      this->treePanel = new System::Windows::Forms::Panel();
      this->treePanel->Parent(*this->leftPanel);
      this->treePanel->BorderStyle(System::Windows::Forms::BorderStyle::Fixed3D);
      this->treePanel->Location(10, 10);
      this->treePanel->Size(this->treePanel->Parent().Width()-10, this->treePanel->Parent().Height() - 20);
      this->treePanel->BackColor(System::Drawing::Color::White());
      this->treePanel->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right);
      this->treePanel->Enabled(false);
      
      this->runningPanel = new System::Windows::Forms::Panel();
      this->runningPanel->Parent(*this);
      this->runningPanel->BorderStyle(System::Windows::Forms::BorderStyle::Fixed3D);
      this->runningPanel->Location(this->leftPanel->Width() + 10, this->upPanel->Height() + 10);
      this->runningPanel->Size(this->Width() - this->leftPanel->Width() - 20, this->Height() - this->upPanel->Height() - 20);
      this->runningPanel->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right);
      this->runningPanel->Enabled(false);
      
      this->progress = new System::Windows::Forms::ProgressBar();
      this->progress->Parent(*this->runningPanel);
      this->progress->Location(10, 10);
      this->progress->Width(this->runningPanel->Width() - 20);
      this->progress->ForeColor(System::Drawing::Color::Green());
      this->progress->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right);
      
      this->resultStatusLabel = new System::Windows::Forms::Label();
      this->resultStatusLabel->Parent(*this->runningPanel);
      this->resultStatusLabel->Location(10, 40);
      this->resultStatusLabel->Text("Total:          0 From:          0 Passed:          0 Failed:          0 Disabled:          0 Time: 0 ms");
      
      this->outputTabControl = new System::Windows::Forms::TabControl();
      this->outputTabControl->Parent(*this->runningPanel);
      this->outputTabControl->Location(10, 60);
      this->outputTabControl->Width(this->runningPanel->Width() - 20);
      this->outputTabControl->Height(this->runningPanel->Height() - 105);
      this->outputTabControl->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom);
      
      this->resultsTabPage = new System::Windows::Forms::TabPage();
      this->resultsTabPage->Text("Results");
      this->resultsTabPage->Parent(*this->outputTabControl);
      
      this->resultsRichTextBox = new System::Windows::Forms::RichTextBox();
      this->resultsRichTextBox->Parent(*this->resultsTabPage);
      this->resultsRichTextBox->Location(2, 10);
      this->resultsRichTextBox->BorderStyle(System::Windows::Forms::BorderStyle::None);
      this->resultsRichTextBox->Width(this->resultsTabPage->Width()-4);
      this->resultsRichTextBox->Height(this->resultsTabPage->Height()-12);
      this->resultsRichTextBox->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom);
      
      this->xmlFilesTabPage = new System::Windows::Forms::TabPage();
      this->xmlFilesTabPage->Text("XML Files");
      this->xmlFilesTabPage->Parent(*this->outputTabControl);
      
      this->xmlFilesRichTextBox = new System::Windows::Forms::RichTextBox();
      this->xmlFilesRichTextBox->Parent(*this->xmlFilesTabPage);
      this->xmlFilesRichTextBox->Location(2, 10);
      this->xmlFilesRichTextBox->BorderStyle(System::Windows::Forms::BorderStyle::None);
      this->xmlFilesRichTextBox->Width(this->xmlFilesTabPage->Width()-4);
      this->xmlFilesRichTextBox->Height(this->xmlFilesTabPage->Height()-12);
      this->xmlFilesRichTextBox->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom);
      
      this->consoleTabPage = new System::Windows::Forms::TabPage();
      this->consoleTabPage->Text("Console");
      this->consoleTabPage->Parent(*this->outputTabControl);
      
      this->consoleRichTextBox = new System::Windows::Forms::RichTextBox();
      this->consoleRichTextBox->Parent(*this->consoleTabPage);
      this->consoleRichTextBox->Location(2, 10);
      this->consoleRichTextBox->BorderStyle(System::Windows::Forms::BorderStyle::None);
      this->consoleRichTextBox->Width(this->consoleTabPage->Width()-4);
      this->consoleRichTextBox->Height(this->consoleTabPage->Height()-12);
      this->consoleRichTextBox->Font(System::Drawing::FontFamily::GenericMonospace());
      this->consoleRichTextBox->Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom);
      
      this->runAllButton = new System::Windows::Forms::Button();
      this->runAllButton->Parent(*this->runningPanel);
      this->runAllButton->Location(10, this->runningPanel->Height()-35);
      this->runAllButton->Text("Run all");
      this->runAllButton->Anchor(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom);
      this->runAllButton->Click += {*this, &TUnitForm::OnProjectRunAllSelected};
      
      this->runButton = new System::Windows::Forms::Button();
      this->runButton->Parent(*this->runningPanel);
      this->runButton->Location(95, this->runningPanel->Height()-35);
      this->runButton->Text("Run");
      this->runButton->Anchor(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom);
      this->runButton->Click += {*this, &TUnitForm::OnProjectRunSelected};;
      
      this->stopButton = new System::Windows::Forms::Button();
      this->stopButton->Parent(*this->runningPanel);
      this->stopButton->Location(180, this->runningPanel->Height()-35);
      this->stopButton->Text("Stop");
      this->stopButton->Enabled(false);
      this->stopButton->Anchor(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom);
      this->stopButton->Click += {*this, &TUnitForm::OnProjectStopSelected};
      
      this->runAlsoDisabledTestsCheckBox = new System::Windows::Forms::CheckBox();
      this->runAlsoDisabledTestsCheckBox->Parent(*this->runningPanel);
      this->runAlsoDisabledTestsCheckBox->Location(265, this->runningPanel->Height()-35);
      this->runAlsoDisabledTestsCheckBox->Text("Run also disabled tests");
      this->runAlsoDisabledTestsCheckBox->Checked(this->params.RunDisabledTest());
      this->runAlsoDisabledTestsCheckBox->Anchor(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom);
      this->runAlsoDisabledTestsCheckBox->Click += [this](const object& sender, const System::EventArgs& e) {
        this->params.RunDisabledTest(this->runAlsoDisabledTestsCheckBox->Checked());
      };
      
      this->SizeChanged += [this](const object& sender, const System::EventArgs& e) {
        this->executionGroupBox->Location(10, 80);
        this->executionGroupBox->Size((this->projectPanel->Width() /2) - 15, 110);
        this->assertionGroupBox->Location((this->projectPanel->Width() /2) + 5, 80);
        this->assertionGroupBox->Size((this->projectPanel->Width() /2) - 15, 110);
        this->runButton->Anchor(System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom);
      };
    }
    
    System::Windows::Forms::MainMenu mainMenu;
    Up<System::Windows::Forms::Panel> upPanel;
    Up<System::Windows::Forms::Panel> projectPanel;
    Up<System::Windows::Forms::Label> projectLabel;
    Up<System::Windows::Forms::TextBox> projectTextBox;
    Up<System::Windows::Forms::Button> selectProjectButton;
    Up<System::Windows::Forms::Label> projectInfos;
    Up<System::Windows::Forms::Button> resetProjectButton;
    
    Up<System::Windows::Forms::GroupBox> executionGroupBox;
    Up<System::Windows::Forms::Label> repeatLabel;
    Up<System::Windows::Forms::NumericUpDown> repeatNumericUpDown;
    Up<System::Windows::Forms::CheckBox> repeatForEverCheckBox;
    Up<System::Windows::Forms::CheckBox> shuffleCheckBox;
    Up<System::Windows::Forms::NumericUpDown> shuffleSeedNumericUpDown;
    Up<System::Windows::Forms::Label> seedShuffleLabel;
    
    Up<System::Windows::Forms::GroupBox> assertionGroupBox;
    Up<System::Windows::Forms::RadioButton> fastDeathTestStyleRadioButton;
    Up<System::Windows::Forms::RadioButton> threadSafeDeathTestStyleRadioButton;
    Up<System::Windows::Forms::CheckBox> throwOnFailureCheckBox;
    
    Up<System::Windows::Forms::Panel> leftPanel;
    Up<System::Windows::Forms::Panel> treePanel;
    
    Up<System::Windows::Forms::Panel> rightPanel;
    Up<System::Windows::Forms::Panel> runningPanel;
    Up<System::Windows::Forms::Button> runAllButton;
    Up<System::Windows::Forms::Button> runButton;
    Up<System::Windows::Forms::Button> stopButton;
    Up<System::Windows::Forms::CheckBox> runAlsoDisabledTestsCheckBox;
    
    Up<System::Windows::Forms::Timer> runningTimer;
    
    Up<System::Windows::Forms::Label> resultStatusLabel;
    Up<System::Windows::Forms::ProgressBar> progress;
    Up<System::Windows::Forms::TabControl> outputTabControl;
    Up<System::Windows::Forms::TabPage> resultsTabPage;
    Up<System::Windows::Forms::RichTextBox> resultsRichTextBox;
    Up<System::Windows::Forms::TabPage> xmlFilesTabPage;
    Up<System::Windows::Forms::RichTextBox> xmlFilesRichTextBox;
    Up<System::Windows::Forms::TabPage> consoleTabPage;
    Up<System::Windows::Forms::RichTextBox> consoleRichTextBox;
  };
}
