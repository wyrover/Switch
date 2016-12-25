#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::FormsD;

namespace PictureBoxExample {
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
      this->ClientSize = System::Drawing::Size(640, 480);
      this->Text = "PictureBox Example";
      this->BackColor = System::Drawing::Color::Black;
      
      this->pictureBox1.Parent = *this;
      this->pictureBox1.Dock = DockStyle::Fill;
     
      Array<MenuItem> fileMenu = {
        MenuItem("Open...", EventHandler(*this, &Form1::OnFileOpenSelected), Shortcut::CmdO)
      };

      this->mainMenu.MenuItems().Add(MenuItem("File", fileMenu));
      this->Menu = this->mainMenu;
    }

  private:
    void OnFileOpenSelected(const object& sender, const EventArgs& e) {
      OpenFileDialog ofd;
      ofd.Title = "Open Image Files";
      ofd.Filter = "All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff|Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff";
      ofd.FilterIndex = 5;
      if (ofd.ShowDialog() == DialogResult::OK) {
        this->Text = string::Format("PictureBox Example [{0}]", System::IO::Path::GetFileName(ofd.FileName));
        this->pictureBox1.Image = System::Drawing::Bitmap(ofd.FileName);
      }
    }
    
    MainMenu mainMenu;
    PictureBox pictureBox1;
  };
}

pcf_startup (PictureBoxExample::Form1)
