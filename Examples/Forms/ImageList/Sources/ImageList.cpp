#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace ImageListExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 200);
      this->ClientSize = System::Drawing::Size(300, 250);
      this->Text = "ImageList Example";
      this->MaximizeBox = false;
      
      this->pictureBox.Parent = *this;
      this->pictureBox.BorderStyle = BorderStyle::Fixed3D;
      this->pictureBox.BackColor = System::Drawing::Color::White;
      this->pictureBox.Bounds = System::Drawing::Rectangle(75, 25, 152, 152);
      
      this->buttonPrevious.Parent = *this;
      this->buttonPrevious.Text = "<";
      this->buttonPrevious.Location = System::Drawing::Point(75, 200);
      this->buttonPrevious.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        if (this->currentImageIndex > 0) {
          this->currentImageIndex--;
          this->pictureBox.Image = this->imageList.Images()[currentImageIndex];
        }
        this->buttonPrevious.Enabled = this->currentImageIndex > 0;
        this->buttonNext.Enabled = this->currentImageIndex < this->imageList.Images().Count - 1;
      };
      
      this->buttonNext.Parent = *this;
      this->buttonNext.Text = ">";
      this->buttonNext.Location = System::Drawing::Point(152, 200);
      this->buttonNext.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        if (this->currentImageIndex < this->imageList.Images().Count - 1) {
          this->currentImageIndex++;
          this->pictureBox.Image = this->imageList.Images()[currentImageIndex];
        }
        this->buttonPrevious.Enabled = this->currentImageIndex > 0;
        this->buttonNext.Enabled = this->currentImageIndex < this->imageList.Images().Count - 1;
      };
      
      FolderBrowserDialog fbd;
      if (fbd.ShowDialog() == DialogResult::OK) {
        for (const auto& file : System::IO::Directory::EnumerateFiles(fbd.SelectedPath, "*.jpg"))
          this->imageList.Images().Add(System::Drawing::Bitmap(file));
      }
      
      this->buttonPrevious.Enabled = false;
      this->buttonNext.Enabled = this->imageList.Images().Count != 0;
      
      if (this->imageList.Images().Count != 0)
        this->pictureBox.Image(this->imageList.Images()[0]);
    }
    
  private:
    ImageList imageList;    
    PictureBox pictureBox;
    Button buttonPrevious;
    Button buttonNext;
    int currentImageIndex = 0;
  };
}

pcf_startup (ImageListExample::Form1)
