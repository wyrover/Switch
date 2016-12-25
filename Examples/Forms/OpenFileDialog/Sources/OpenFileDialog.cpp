#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace OpenFileDialogExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->Text = "OpenFileDialog example";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(640, 350);
      
      this->buttonOpenImageFile.Location = System::Drawing::Point(10, 10);
      this->buttonOpenImageFile.Size = System::Drawing::Size(150, 23);
      this->buttonOpenImageFile.Parent = *this;
      this->buttonOpenImageFile.Text = "Open Image File";
      this->buttonOpenImageFile.Click += {*this, &Form1::OnButtonOpentTextFileClick};
      
      this->labelResult.Location = System::Drawing::Point(170, 13);
      this->labelResult.AutoSize = true;
      this->labelResult.Parent = *this;
      
      this->listBoxFileNames.Location = System::Drawing::Point(10, 40);
      this->listBoxFileNames.Size = System::Drawing::Size(620, 300);
      this->listBoxFileNames.Anchor = AnchorStyles::Left | AnchorStyles::Top | AnchorStyles::Right | AnchorStyles::Bottom;
      this->listBoxFileNames.Parent = *this;
    }
    
  private:
    void OnButtonOpentTextFileClick(const object& sender, const EventArgs& e) {
      OpenFileDialog ofd;

      ofd.Title = "Open Image Files";
      ofd.Filter = "Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff";
      ofd.FilterIndex = 2;
      ofd.Multiselect = true;
      DialogResult result = ofd.ShowDialog();
      labelResult.Text = string::Format("DialogResult = {0}", result);
      
      if (result == DialogResult::OK) {
        for (string fileName : ofd.FileNames())
          listBoxFileNames.Items().Add(fileName);
      } else {
        listBoxFileNames.Items().Clear();
      }
    }
    
    Button buttonOpenImageFile;
    Label labelResult;
    ListBox listBoxFileNames;
  };
}

pcf_startup (OpenFileDialogExample::Form1)
