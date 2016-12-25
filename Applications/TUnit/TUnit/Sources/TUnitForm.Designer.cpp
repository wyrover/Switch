#include "../Includes/TUnitForm.h"

#pragma region Pcf Form Designer generated code
// Do not modify the contents of this method with the editor.
void TUnitApplication::TUnitForm::InitializeComponent() {
  this->SuspendLayout();
  //
  // mainMenu
  //
  this->mainMenu.MenuItems().Add({"&File", {
    {"Open...", {*this, &TUnitForm::OnFileOpenSelected}, System::Windows::Forms::Shortcut::CmdO},
    {"Open recent", System::Array<System::Windows::Forms::MenuItem> {}},
    {"-"},
    {"Export results...", {*this, &TUnitForm::OnFileExportResultsSelected}},
    {"Export xml...", {*this, &TUnitForm::OnFileExportXmlSelected}},
    {"Export console output...", {*this, &TUnitForm::OnFileExportConsoleOutputSelected}},
    {"-"},
    {"Close", {*this, &TUnitForm::OnFileCloseSelected}, System::Windows::Forms::Shortcut::CmdW}}});
  this->mainMenu.MenuItems().Add({"&Project", {
    {"Run all", {*this, &TUnitForm::OnProjectRunAllSelected}, System::Windows::Forms::Shortcut::CmdShiftR},
    {"Run", {*this, &TUnitForm::OnProjectRunSelected}, System::Windows::Forms::Shortcut::CmdR},
    {"-"},
    {"Stop", {*this, &TUnitForm::OnProjectStopSelected}, System::Windows::Forms::Shortcut::CmdS}}});
  this->mainMenu.MenuItems().Add({"&View", {
    {"Full GUI", {*this, &TUnitForm::OnViewFullGUISelected}, System::Windows::Forms::Shortcut::Cmd1},
    {"Mini GUI", {*this, &TUnitForm::OnViewMiniGUISelected}, System::Windows::Forms::Shortcut::Cmd2}}});
  this->Menu(this->mainMenu);
  //
  // upPanel
  //
  this->upPanel.Parent = *this;
  this->upPanel.Location = System::Drawing::Point(0, 0);
  this->upPanel.Size = System::Drawing::Size(800, 210);
  this->upPanel.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
  this->upPanel.SizeChanged += {*this, &TUnitForm::OnUpPanelSizeChangedForm};
  //
  // projectPanel
  //
  this->projectPanel.Parent = this->upPanel;
  this->projectPanel.Location = System::Drawing::Point(10, 10);
  this->projectPanel.BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
  this->projectPanel.Size = System::Drawing::Size(780, 200);
  this->projectPanel.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
  this->projectPanel.SizeChanged += {*this, &TUnitForm::OnProjectPanelSizeChangedForm};
  //
  // projectLabel
  //
  this->projectLabel.Parent = this->projectPanel;
  this->projectLabel.AutoSize = true;
  this->projectLabel.Location = System::Drawing::Point(10, 15);
  this->projectLabel.Text = "Project";
  //
  // projectInfos
  //
  this->projectInfos.Parent = this->projectPanel;
  this->projectInfos.AutoSize = true;
  this->projectInfos.Location = System::Drawing::Point(10, 50);
  this->projectInfos.Text = "There are 0 tests from 0 test cases.";
  this->projectInfos.Enabled = false;
  //
  // selectProjectButton
  //
  this->selectProjectButton.Parent = this->projectPanel;
  this->selectProjectButton.Location = System::Drawing::Point(695, 12);
  this->selectProjectButton.Text = "&Select...";
  this->selectProjectButton.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
  this->selectProjectButton.Click += {*this, &TUnitForm::OnFileOpenSelected};
  //
  // projectTextBox
  //
  this->projectTextBox.Parent = this->projectPanel;
  this->projectTextBox.Location = System::Drawing::Point(60, 10);
  this->projectTextBox.Size = System::Drawing::Size(625, 25);
  this->projectTextBox.ReadOnly(true);
  this->projectTextBox.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
  //
  // resetProjectButton
  //
  this->resetProjectButton.Parent = this->projectPanel;
  this->resetProjectButton.Location = System::Drawing::Point(695, 42);
  this->resetProjectButton.Text = "&Reset";
  this->resetProjectButton.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right;
  this->resetProjectButton.Enabled = false;
  this->resetProjectButton.Click += {*this, &TUnitForm::OnResetProjectButtonClick};
  //
  // executionGroupBox
  //
  this->executionGroupBox.Parent = this->projectPanel;
  this->executionGroupBox.Location = System::Drawing::Point(10, 80);
  this->executionGroupBox.Size = System::Drawing::Size(375, 110);
  this->executionGroupBox.BackColor = System::Drawing::Color::LightGray;
  this->executionGroupBox.Enabled = false;
  //
  // repeatLabel
  //
  this->repeatLabel.Parent = this->executionGroupBox;
  this->repeatLabel.AutoSize = true;
  this->repeatLabel.Location = System::Drawing::Point(23, 14);
  this->repeatLabel.Text = "Repeat";
  //
  // repeatNumericUpDown
  //
  this->repeatNumericUpDown.Parent = this->executionGroupBox;
  this->repeatNumericUpDown.Location = System::Drawing::Point(80, 10);
  this->repeatNumericUpDown.Minimum = 1;
  this->repeatNumericUpDown.Maximum = 2147483647;
  this->repeatNumericUpDown.Click += {*this, &TUnitForm::OnRepeatNumericUpDownClick};
  //
  // repeatForEverCheckBox
  //
  this->repeatForEverCheckBox.Parent = this->executionGroupBox;
  this->repeatForEverCheckBox.Location = System::Drawing::Point(10, 40);
  this->repeatForEverCheckBox.Text = "Repeat forever";
  this->repeatForEverCheckBox.Click += {*this, &TUnitForm::OnRepeatForEverCheckBoxClick};
  //
  // shuffleCheckBox
  //
  this->shuffleCheckBox.Parent = this->executionGroupBox;
  this->shuffleCheckBox.Location = System::Drawing::Point(10, 70);
  this->shuffleCheckBox.Text = "Shufle";
  this->shuffleCheckBox.Click += {*this, &TUnitForm::OnShuffleCheckBoxClick};
  //
  // shuffleSeedNumericUpDown
  //
  this->shuffleSeedNumericUpDown.Parent = this->executionGroupBox;
  this->shuffleSeedNumericUpDown.Location = System::Drawing::Point(80, 70);
  this->shuffleSeedNumericUpDown.Maximum = 99999;
  this->shuffleSeedNumericUpDown.Value = 0;
  this->shuffleSeedNumericUpDown.Click += {*this, &TUnitForm::OnShuffleSeedNumericUpDownClick};
  //
  // seedShuffleLabel
  //
  this->seedShuffleLabel.Parent = this->executionGroupBox;
  this->seedShuffleLabel.AutoSize = true;
  this->seedShuffleLabel.Location = System::Drawing::Point(210, 74);
  this->seedShuffleLabel.Text = "seed";
  //
  // assertionGroupBox
  //
  this->assertionGroupBox.Parent = this->projectPanel;
  this->assertionGroupBox.Location = System::Drawing::Point(395, 80);
  this->assertionGroupBox.Size = System::Drawing::Size(375, 110);
  this->assertionGroupBox.BackColor = System::Drawing::Color::LightGray;
  this->assertionGroupBox.Enabled = false;
  //
  // fastDeathTestStyleRadioButton
  //
  this->fastDeathTestStyleRadioButton.Parent = this->assertionGroupBox;
  this->fastDeathTestStyleRadioButton.Location = System::Drawing::Point(10, 10);
  this->fastDeathTestStyleRadioButton.Text = "Fast death test style (default)";
  this->fastDeathTestStyleRadioButton.Checked = true;
  this->fastDeathTestStyleRadioButton.Click += {*this, &TUnitForm::OnFastDeathTestStyleRadioButtonClick};
  //
  // threadSafeDeathTestStyleRadioButton
  //
  this->threadSafeDeathTestStyleRadioButton.Parent = this->assertionGroupBox;
  this->threadSafeDeathTestStyleRadioButton.Location = System::Drawing::Point(10, 40);
  this->threadSafeDeathTestStyleRadioButton.Text = "Thread safe death test style";
  this->threadSafeDeathTestStyleRadioButton.Click += {*this, &TUnitForm::OnThreadSafeDeathTestStyleRadioButtonClick};
  //
  // throwOnFailureCheckBox
  //
  this->throwOnFailureCheckBox.Parent = this->assertionGroupBox;
  this->throwOnFailureCheckBox.Location = System::Drawing::Point(10, 70);
  this->throwOnFailureCheckBox.Text = "Throw on failure";
  this->throwOnFailureCheckBox.Click += {*this, &TUnitForm::OnThrowOnFailureCheckBoxClick};
  //
  // leftPanel
  //
  this->leftPanel.Parent = *this;
  this->leftPanel.Location = System::Drawing::Point(0, 210);
  this->leftPanel.Size = System::Drawing::Size(260, 390);
  this->leftPanel.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
  this->leftPanel.SizeChanged += {*this, &TUnitForm::OnLeftPanelSizeChangedForm};
  //
  // treePanel
  //
  this->treePanel.Parent = this->leftPanel;
  this->treePanel.BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
  this->treePanel.Location = System::Drawing::Point(10, 10);
  this->treePanel.Size = System::Drawing::Size(250, 370);
  this->treePanel.BackColor = System::Drawing::Color::White;
  this->treePanel.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right;
  this->treePanel.Enabled = false;
  //
  // runningPanel
  //
  this->runningPanel.Parent = *this;
  this->runningPanel.BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
  this->runningPanel.Location = System::Drawing::Point(270, 220);
  this->runningPanel.Size = System::Drawing::Size(520, 370);
  this->runningPanel.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right;
  this->runningPanel.Enabled = false;
  //
  // progress
  //
  this->progress.Parent = this->runningPanel;
  this->progress.Location = System::Drawing::Point(10, 10);
  this->progress.Size = System::Drawing::Size(500, 25);
  this->progress.ForeColor = System::Drawing::Color::Green;
  this->progress.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right;
  //
  // resultStatusLabel
  //
  this->resultStatusLabel.Parent = this->runningPanel;
  this->resultStatusLabel.AutoSize = true;
  this->resultStatusLabel.Location = System::Drawing::Point(10, 40);
  this->resultStatusLabel.Text = "Tests: 0          From: 0          Passed: 0          Failures: 0          Ignored: 0          Time: 0 ms";
  //
  // outputTabControl
  //
  this->outputTabControl.Parent = this->runningPanel;
  this->outputTabControl.Location = System::Drawing::Point(10, 60);
  this->outputTabControl.BackColor = System::Drawing::SystemColors::Window;
  this->outputTabControl.Size = System::Drawing::Size(500, 255);
  this->outputTabControl.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom;
  //
  // resultsTabPage
  //
  this->resultsTabPage.Parent = this->outputTabControl;
  this->resultsTabPage.BackColor = System::Drawing::SystemColors::Window;
  this->resultsTabPage.Text = "Results";
  //
  // resultsRichTextBox
  //
  this->resultsRichTextBox.Parent = this->resultsTabPage;
  this->resultsRichTextBox.Location = System::Drawing::Point(2, 10);
  this->resultsRichTextBox.BorderStyle(System::Windows::Forms::BorderStyle::None);
  this->resultsRichTextBox.Size = System::Drawing::Size(496, 223);
  this->resultsRichTextBox.Anchor(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom);
  //
  // xmlFilesTabPage
  //
  this->xmlFilesTabPage.Text = "XML Files";
  this->xmlFilesTabPage.BackColor = System::Drawing::SystemColors::Window;
  this->xmlFilesTabPage.Parent(this->outputTabControl);
  //
  // xmlFilesRichTextBox
  //
  this->xmlFilesRichTextBox.Parent = this->xmlFilesTabPage;
  this->xmlFilesRichTextBox.Location = System::Drawing::Point(2, 10);
  this->xmlFilesRichTextBox.BorderStyle(System::Windows::Forms::BorderStyle::None);
  this->xmlFilesRichTextBox.Size = System::Drawing::Size(496, 223);
  this->xmlFilesRichTextBox.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom;
  //
  // consoleTabPage
  //
  this->consoleTabPage.Parent = this->outputTabControl;
  this->consoleTabPage.BackColor = System::Drawing::SystemColors::Window;
  this->consoleTabPage.Text = "Console";
  //
  // consoleRichTextBox
  //
  this->consoleRichTextBox.Parent = this->consoleTabPage;
  this->consoleRichTextBox.Location = System::Drawing::Point(2, 10);
  this->consoleRichTextBox.BorderStyle(System::Windows::Forms::BorderStyle::None);
  this->consoleRichTextBox.Size = System::Drawing::Size(496, 223);
  this->consoleRichTextBox.Font = System::Drawing::Font("Courier New", 12, System::Drawing::FontStyle::Regular);
  this->consoleRichTextBox.Anchor = System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right | System::Windows::Forms::AnchorStyles::Bottom;
  //
  // runAllButton
  //
  this->runAllButton.Parent = this->runningPanel;
  this->runAllButton.Location = System::Drawing::Point(10, 335);
  this->runAllButton.Text = "Run all";
  this->runAllButton.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom;
  this->runAllButton.Click += {*this, &TUnitForm::OnProjectRunAllSelected};
  //
  // runButton
  //
  this->runButton.Parent = this->runningPanel;
  this->runButton.Location = System::Drawing::Point(95, 335);
  this->runButton.Text = "Run";
  this->runButton.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom;
  this->runButton.Click += {*this, &TUnitForm::OnProjectRunSelected};;
  //
  // stopButton
  //
  this->stopButton.Parent = this->runningPanel;
  this->stopButton.Location = System::Drawing::Point(180, 335);
  this->stopButton.Text = "Stop";
  this->stopButton.Enabled = false;
  this->stopButton.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom;
  this->stopButton.Click += {*this, &TUnitForm::OnProjectStopSelected};
  //
  // runAlsoIgnoredTestsCheckBox
  //
  this->runAlsoIgnoredTestsCheckBox.Parent = this->runningPanel;
  this->runAlsoIgnoredTestsCheckBox.Location = System::Drawing::Point(265, 335);
  this->runAlsoIgnoredTestsCheckBox.Text = "Run also ignored tests";
  this->runAlsoIgnoredTestsCheckBox.Checked = false;
  this->runAlsoIgnoredTestsCheckBox.Anchor = System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Bottom;
  this->runAlsoIgnoredTestsCheckBox.Click += {*this, &TUnitForm::OnRunAlsoIgnoredTestsCheckBoxClick};
  //
  // TUnitForm
  //
  this->Location = System::Drawing::Point(300, 200);
  this->ClientSize = System::Drawing::Size(800, 600);
  this->Text = "TUnit";
  this->Closed += {*this, &TUnitForm::OnTUnitFormClosed};
  this->ResumeLayout(false);
  this->PerformLayout();
}
#pragma endregion
