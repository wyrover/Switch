#include <Pcf/Pcf.h>
#include "XT3.h"

using namespace System;
using namespace System::Windows::Forms;

namespace MulticamInstaller {
  class InstallerDialog : public Form {
  public:
    InstallerDialog() {
      this->StartPosition = FormStartPosition::CenterScreen;
      this->Size = System::Drawing::Point(600, 150);
      
      this->MaximizeBox = false;
      this->Text("Installation");
      
      this->message.Parent = *this;
      this->message.Location = System::Drawing::Point(10, 20);
      this->message.Text("Install version...");
      
      this->progressBar.Parent = *this;
      this->progressBar.Location = System::Drawing::Point(10, 50);
      this->progressBar.Width = 480;
      this->progressBar.Value = 0;
      
      this->briefMessage.Parent = *this;
      this->briefMessage.Location = System::Drawing::Point(10, 90);
      
      this->expander.Parent = *this;
      this->expander.Location = System::Drawing::Point(10, 120);
      this->expander.Text("@> Details");
      this->expander.Click += {*this, &InstallerDialog::OnExpandClick};
      
      this->messages.Parent = *this;
      this->messages.Location = System::Drawing::Point(10, 140);
      this->messages.Size = System::Drawing::Size(580, 0);
      this->messages.Anchor = Pcf::System::Windows::Forms::AnchorStyles::Top | Pcf::System::Windows::Forms::AnchorStyles::Bottom;
      
      this->cancel.Parent = *this;
      this->cancel.Location = System::Drawing::Point(510, 50);
      this->cancel.Text("Cancel");
      this->CancelButton = this->cancel;
      this->cancel.Click += {*this, &InstallerDialog::OnCancelClick};
      this->BackColor = Drawing::Color::White;
    }
    
    Property<string, WriteOnly> BriefMessage {
      pcf_set {
        this->briefMessage.Text = value;
        Application::DoEvent();
      }
    };
    
    Property<int, WriteOnly> Progress {
      pcf_set {
        this->progressBar.Value = value;
        Application::DoEvent();
      }
    };
    
    Property<string, WriteOnly> Message {
      pcf_set {
        this->messages.Items().Add(value);
        this->messages.SelectedIndex(this->messages.Items().Count()-1);
        Application::DoEvent();
      }
    };
    
    Property<string, WriteOnly> Title {
      pcf_set {
        this->Text = value;
        Application::DoEvent();
      }
    };
    
  private:
    void OnExpandClick(const object& sender, const EventArgs& e) {
      this->expanded = ! this->expanded;
      this->Height = this->expanded ? 450 : 150;
      this->CenterToScreen();
      this->expander.Text = this->expanded ? "@2> Details" : "@> Details";
    }
    
    void OnCancelClick(const object& sender, const EventArgs& e) {
      this->dialogResult = DialogResult::Cancel;
      this->Close();
    }
        
    Label message;
    Label expander;
    ProgressBar progressBar;
    Button cancel;
    Label briefMessage;
    bool expanded = false;
    ListBox messages;
  };
  
  class MulticamInstaller : public object {
  public:
    MulticamInstaller(const System::Net::IPAddress& target, const string& sourcePath) : target(target), sourcePath(sourcePath) {
      installThread.Start();
      this->dialog.Title = string::Format("Install on {0}", target);
      DialogResult result = this->dialog.ShowDialog();
      if (result == DialogResult::Cancel)
        cancel = true;
    }
    
    ~MulticamInstaller() {
      this->installThread.Join();
    }
    
  private:
    void Install() {
      Array<string> files = {"Code/Multicam.exe", "Code/MulSetup.exe", "Code/MulBoot.exe", "Code/CeDump.exe", "Code/CeSnmp.dll", "Const/Mtpc/Hs870.bin", "Const/Mtpc/Hs873.bin", "Const/Audio/Coda70.drv", "Const/Audio/Coda75.drv", "Const/Hct/ucode.bin", "Const/Video/jpeg.cod", "Const/Video/dvcpro.cod", "Const/Video/DnxHD.cod", "Const/Video/Mpeg.cod", "Const/Video/ProRes.cod", "Data/User/Consig.cfg", "Data/User/Default.lin"};
      this->dialog.BriefMessage = "Initializing...";
      this->dialog.Message = "Initializing protocols";
      this->dialog.Message = "  Initializing Ftp protocols...";
      this->dialog.Message = "  Ftp protocols ready";
      this->dialog.Message = "  Initializing Snmp...";
      this->dialog.Message = "  Snmp protocols ready";
      Threading::Thread::Sleep(2000);
      this->dialog.Progress = 10;
      this->dialog.BriefMessage = "Copying...";
      this->dialog.Message = "Copying files";
      for (int i = 4; i < 20 && ! cancel; i++) {
        Threading::Thread::Sleep(2000);
        this->dialog.Progress = 5*i;
        this->dialog.Message = string::Format("  Copying file {0}/{1}...", this->sourcePath, files[i-3]);
      }
      
      if (cancel) return;
      this->dialog.BriefMessage = "Closing...";
      this->dialog.Message = "Closing...";
      this->dialog.Progress = 100;
      Threading::Thread::Sleep(1000);
      if (cancel) return;
      this->dialog.Close();
    }
    
    InstallerDialog dialog;
    System::Net::IPAddress target;
    string sourcePath;
    System::Threading::Thread installThread = System::Threading::Thread(System::Threading::ThreadStart(*this, &MulticamInstaller::Install));
    bool cancel = false;
  };
  
  class InputIpAddressDialog : public Form {
  public:
    InputIpAddressDialog() {
      this->Size = System::Drawing::Size(320, 100);
      this->StartPosition = FormStartPosition::CenterScreen;
      this->MaximizeBox = false;
      this->Text = "Server Address";
      
      this->message.Parent = *this;
      this->message.Location = System::Drawing::Point(10, 14);
      this->message.Text = "Enter server IP address";
      
      this->cancel.Parent = *this;
      this->cancel.Location = System::Drawing::Point(140, 50);
      this->cancel.Text = "Cancel";
      this->CancelButton = this->cancel;
      this->cancel.Click += {*this, &InputIpAddressDialog::OnCancelClick};
      
      this->ok.Parent = *this;
      this->ok.Location = System::Drawing::Point(225, 50);
      this->ok.Text = "Ok";
      this->AcceptButton = this->ok;
      this->ok.Enabled = false;
      this->ok.Click += {*this, &InputIpAddressDialog::OnOkClick};
      this->BackColor = Drawing::Color::White;
      
      this->textBox.Parent = *this;
      this->textBox.Location = System::Drawing::Point(180, 10);
      this->textBox.Width = 120;
      this->textBox.TextChanged += {*this, &InputIpAddressDialog::OnTextBoxChanged};
     
      this->dialogResult = System::Windows::Forms::DialogResult::Cancel;
    }
    
    Property<System::Windows::Forms::DialogResult, ReadOnly> DialogResult {
      pcf_get {return this->dialogResult;}
    };
    
    Property<System::Net::IPAddress, ReadOnly> IPAddress {
      pcf_get {return System::Net::IPAddress::Parse(this->textBox.Text());}
    };
    
  private:
    void OnTextBoxChanged(const object& sender, const EventArgs& e) {
      System::Net::IPAddress ipAddress;
      this->ok.Enabled(System::Net::IPAddress::TryParse(this->textBox.Text(), ipAddress));
    }
    
    void OnCancelClick(const object& sender, const EventArgs& e) {
      this->dialogResult = System::Windows::Forms::DialogResult::Cancel;
      this->Hide();
    }
    
    void OnOkClick(const object& sender, const EventArgs& e) {
      this->dialogResult = System::Windows::Forms::DialogResult::OK;
      this->Hide();
    }
    
    Label message;
    TextBox textBox;
    Button cancel;
    Button ok;
    System::Windows::Forms::DialogResult dialogResult;
  };
  
  class MainForm : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(MainForm());
    }
    
    MainForm() {
      this->Location = System::Drawing::Point(200, 100);
      this->Size = System::Drawing::Size(720, 250);
      this->StartPosition = FormStartPosition::CenterScreen;
      this->MaximizeBox = false;
      this->Text = "Multicam Installer";
      
      this->picture.Parent = *this;
      this->picture.Location = System::Drawing::Point(5, 5);
      this->picture.Size = System::Drawing::Size(320, 240);
      this->picture.Image = *System::Drawing::Image::FromData(XT3);
      
      this->sourcePanel.Parent = *this;
      this->sourcePanel.Bounds = System::Drawing::Rectangle(330, 10, 380, 70);
      this->sourcePanel.BorderStyle = BorderStyle::Fixed3D;
      
      this->sourceMessage.Parent = this->sourcePanel;
      this->sourceMessage.Location = System::Drawing::Point(10, 10);
      this->sourceMessage.AutoSize = true;
      this->sourceMessage.Text = "Select a Multicam version to install";
      
      this->sourcePath.Parent = this->sourcePanel;
      this->sourcePath.Location = System::Drawing::Point(10, 40);
      this->sourcePath.Width = 360;
      this->sourcePath.AutoSize = false;
      this->sourcePath.Text = "";
      
      this->select.Parent = this->sourcePanel;
      this->select.Location = System::Drawing::Point(290, 8);
      this->select.Text = "Select...";
      this->select.Click += {*this, &MainForm::OnFileClick};
      
      this->targetPanel.Parent = *this;
      this->targetPanel.Bounds = System::Drawing::Rectangle(330, 90, 380, 100);
      this->targetPanel.BorderStyle = BorderStyle::Fixed3D;
      
      this->targetMessage.Parent = this->targetPanel;
      this->targetMessage.Location = System::Drawing::Point(10, 10);
      this->targetMessage.Text = "Target Servers";
      
      this->targetServers.Parent = this->targetPanel;
      this->targetServers.Location = System::Drawing::Point(120, 10);
      this->targetServers.Height = 80;
      this->targetServers.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->remove.Enabled = this->targetServers.SelectedIndex != -1;
      };
      
      this->add.Parent = this->targetPanel;
      this->add.Location = System::Drawing::Point(290, 8);
      this->add.Text = "Add...";
      this->add.Click += {*this, &MainForm::OnAddClick};
      
      this->remove.Parent = this->targetPanel;
      this->remove.Location = System::Drawing::Point(290, 38);
      this->remove.Text = "Remove";
      this->remove.Click += {*this, &MainForm::OnRemoveClick};
      this->remove.Enabled = this->targetServers.SelectedIndex != -1;
      
      this->install.Parent = *this;
      //this->install.Location = System::Drawing::Point(325, 210);
      this->install.Location = System::Drawing::Point(620, 210);
      this->install.Text = "Install...";
      this->install.Enabled = false;
      this->install.Click += {*this, &MainForm::OnInstallClick};
      this->BackColor = Drawing::Color::White;
      
      this->sourcePath.Text = as<string>(Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Softwares").CreateSubKey("Pcf").CreateSubKey("MulticamInstaller").GetValue("SourcePath", ""));
      this->targetServers.Items().AddRange(as<Array<string>>(Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Softwares").CreateSubKey("Pcf").CreateSubKey("MulticamInstaller").GetValue("TargetServers", Array<string> {})));
      
      this->remove.Enabled = this->targetServers.SelectedIndex != -1;
      this->install.Enabled(this->targetServers.Items().Count != 0 && System::IO::File::Exists(this->sourcePath.Text));
    }
    
    ~MainForm() {
      Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Softwares").CreateSubKey("Pcf").CreateSubKey("MulticamInstaller").SetValue("SourcePath", this->sourcePath.Text());
      Array<string> targetServers(this->targetServers.Items().Count());
      int index = 0;
      for (sp<object> item : this->targetServers.Items())
        targetServers[index++] = item->ToString();
      Microsoft::Win32::Registry::CurrentUser().CreateSubKey("Softwares").CreateSubKey("Pcf").CreateSubKey("MulticamInstaller").SetValue("TargetServers", targetServers);
    }
    
    void OnAddClick(const object& sender, const EventArgs& e) {
      InputIpAddressDialog inputIpAddressDialog;
      inputIpAddressDialog.ShowDialog();
      if (inputIpAddressDialog.DialogResult == DialogResult::OK) {
        this->targetServers.Items().Add(inputIpAddressDialog.IPAddress());
        this->targetServers.SelectedIndex(this->targetServers.Items().Count()-1);
      }
      this->remove.Enabled = this->targetServers.SelectedIndex != -1;
      this->install.Enabled(this->targetServers.Items().Count != 0 && System::IO::File::Exists(this->sourcePath.Text));
    }
    
    void OnRemoveClick(const object& sender, const EventArgs& e) {
      int index = this->targetServers.SelectedIndex();
      this->targetServers.Items().Remove(this->targetServers.SelectedItem());
      if (this->targetServers.Items().Count()) {
        if (index >= this->targetServers.Items().Count())
          this->targetServers.SelectedIndex(this->targetServers.Items().Count()-1);
        else
          this->targetServers.SelectedIndex(index);
      }
      this->remove.Enabled = this->targetServers.SelectedIndex != -1;
      this->install.Enabled(this->targetServers.Items().Count != 0 && System::IO::File::Exists(this->sourcePath.Text));
    }
    
    void OnFileClick(const object& sender, const EventArgs& e) {
      OpenFileDialog ofd;
      ofd.Title = "Open Multicam installation file";
      ofd.Filter = "Zip Files|*.zip";
      ofd.FilterIndex = 0;
      ofd.Multiselect = false;
      if (ofd.ShowDialog() == DialogResult::OK)
        this->sourcePath.Text = ofd.FileName;
      this->install.Enabled(this->targetServers.Items().Count != 0 && System::IO::File::Exists(this->sourcePath.Text));
    }
    
    void OnInstallClick(const object& sender, const EventArgs& e) {
      for (sp<object> item : this->targetServers.Items()) {
        MulticamInstaller installer(System::Net::IPAddress::Parse(item->ToString()), this->sourcePath.Text);
      }
    }
    
  private:
    PictureBox picture;
    Panel sourcePanel;
    Label sourceMessage;
    Label sourcePath;
    Button select;
    Panel targetPanel;
    Label targetMessage;
    ListBox targetServers;
    Button add;
    Button remove;
    Button install;
  };
}

pcf_startup (MulticamInstaller::MainForm)
