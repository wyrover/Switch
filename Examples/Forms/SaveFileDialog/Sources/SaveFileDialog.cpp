#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace SaveFileDialogExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "SaveFileDialog example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 350);
      this->MaximizeBox = false;
      
      this->buttonSaveImageFile.Location = System::Drawing::Point(10, 10);
      this->buttonSaveImageFile.Size = System::Drawing::Size(150, 23);
      this->buttonSaveImageFile.Parent = *this;
      this->buttonSaveImageFile.Text = "Save Image File";
      this->buttonSaveImageFile.Click += {*this, &Form1::OnButtonOpentTextFileClick};
      
      this->labelResult.Location = System::Drawing::Point(170, 13);
      this->labelResult.AutoSize = true;
      this->labelResult.Parent = *this;
      
      this->labelFileName.Location = System::Drawing::Point(10, 50);
      this->labelFileName.AutoSize = true;
      this->labelFileName.Parent = *this;
    }
    
  private:
    void OnButtonOpentTextFileClick(const object& sender, const EventArgs& e) {
      SaveFileDialog sfd;

      sfd.Title = "Save Image Files";
      sfd.Filter = "Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff";
      sfd.FilterIndex = 2;
      DialogResult result = sfd.ShowDialog();
      this->labelResult.Text = string::Format("DialogResult = {0}", result);
      
      if (result == DialogResult::OK) {
        this->labelFileName.Text = sfd.FileName;
      } else
        this->labelFileName.Text = "";
    }
    
    Button buttonSaveImageFile;
    Label labelResult;
    Label labelFileName;
  };
}

pcf_startup (SaveFileDialogExample::Form1)
