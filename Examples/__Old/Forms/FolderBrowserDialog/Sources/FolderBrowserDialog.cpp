#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

namespace FolderBrowserDialogExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "FolderBrowserDialog example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 350);
      this->MaximizeBox = false;
      
      this->buttonOpenImageFile.Location = System::Drawing::Point(10, 10);
      this->buttonOpenImageFile.Size = System::Drawing::Size(150, 23);
      this->buttonOpenImageFile.Parent = *this;
      this->buttonOpenImageFile.Text = "Open Images Folder";
      this->buttonOpenImageFile.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        FolderBrowserDialog fbd;
        fbd.ShowNewFolderButton = true;
        
        DialogResult result = fbd.ShowDialog();
        labelResult.Text = string::Format("DialogResult = {0}", result);
        
        if (result == DialogResult::OK) {
          labelFolderPath.Text = fbd.SelectedPath;
        }
      };
      
      this->labelResult.Location = System::Drawing::Point(170, 13);
      this->labelResult.AutoSize = true;
      this->labelResult.Parent = *this;
      
      this->labelFolderPath.Location = System::Drawing::Point(10, 50);
      this->labelFolderPath.AutoSize = true;
      this->labelFolderPath.Parent = *this;
    }
    
  private:
    Button buttonOpenImageFile;
    Label labelResult;
    Label labelFolderPath;
  };
}

pcf_startup (FolderBrowserDialogExample::Form1)
