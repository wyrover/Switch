#include <Pcf/Pcf>

#undef GetCommandLine

using namespace System;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Windows::Forms;

/// @cond
namespace Pcf {
  namespace Resources {
    class Image {
    public:
      int width;
      int height;
      string pixelFormat;
      up<byte[]> rawData;
      
      int GetDataSize() const {
        return this->width * this->height * ((Imaging::PixelFormat)Enum<Imaging::PixelFormat>::Parse(this->pixelFormat) == System::Drawing::Imaging::PixelFormat::Format32bppRgb ? 4 : 3);
      }
      
      up<Pcf::System::Drawing::Image> ToImage() const {
        up<Pcf::System::Drawing::Image> image = new Pcf::System::Drawing::Image();
        
        image->flags = Imaging::ImageFlags::ReadOnly | Imaging::ImageFlags::HasRealPixelSize | Imaging::ImageFlags::HasRealDpi | Imaging::ImageFlags::ColorSpaceRgb;
        image->frameDimensionList = {Imaging::FrameDimension::Page().Guid};
        image->pixelFormat = (Imaging::PixelFormat)Enum<Imaging::PixelFormat>::Parse(this->pixelFormat);
        image->size = Size(this->width, this->height);
        
        image->rawFormat = Imaging::ImageFormat::MemoryBmp;
        image->rawData = Array<byte>(this->rawData.ToPointer(), this->GetDataSize());
        
        return image;
      }
    };
  }
}
/// @endcond

//#include "Resources.res"

namespace ImageList {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }
    
    Form1() {
      InitializeComponent();
      
      Console::WriteLine("Path \"{0}\"", Environment::GetCommandLineArgs()[0]);
      Console::WriteLine("program \"{0}\"", Environment::CommandLine());
      //this->pictureBox->Image(*Pcf::Resources::Add_Bookmark.ToImage());
      
      //int resxMagicNumber = 0x52657378; // ==> "Resx" in concatened bytes;
      string magicNumber;
      pcf_using(StreamReader pgm(Environment::GetCommandLineArgs()[0])) {
        pgm.BaseStream().Seek(-(String("Resources added").Length()+1), SeekOrigin::End);
        magicNumber = pgm.ReadLine();
      }

      if (magicNumber == "Resources added") {
        pcf_using(StreamReader pgm(Environment::GetCommandLineArgs()[0])) {
          pgm.BaseStream().Seek(-(String("Resources added").Length()+1 + 10 + 1), SeekOrigin::End);
          int position = Int32::Parse(pgm.ReadLine(), 16);
          pgm.BaseStream().Seek(position, SeekOrigin::Begin);
          while (pgm.BaseStream().Position() < (pgm.BaseStream().Length() - String("Resources added").Length()+1 + 10 + 1)) {
            string line = pgm.ReadLine();
            if (!line.IsEmpty()) {
              
            }
          }
        }
    
      } else {
        FileStream fs(Environment::GetCommandLineArgs()[0], FileMode::Append, FileAccess::Write);
        pcf_using(BinaryWriter writer(fs)) {
          
        }
        /*
        up<StreamReader> reader = new StreamReader("/Users/yves/Desktop/Resources.res");
        up<StreamWriter> writer = new StreamWriter(Environment::GetCommandLineArgs()[0], true);
        int position = writer->GetBaseStream()->GetPosition();
        while (!reader->EndOfText()) {
          string line = reader->ReadLine();
          writer->WriteLine(line);
        }
        writer->WriteLine(string::Format("0x{0:X8}", position));
        writer->WriteLine("Resources added");
         */
      }
      
      /*
      string path = "/Users/yves/Icones/iCandy/iCandy Junior Toolbar/jpg";
      DirectoryInfo directoryInfo(path);
      Array<FileInfo> files = directoryInfo.GetFiles("*.jpg");
      
      for (FileInfo file : files) {
        string fileName =  string::Format("{0}/{1}.jpg", path, Path::GetFileNameWithoutExtension(file.Name()));
        up<Image> image = new Bitmap(fileName);
        string resourceName = ToResourceName(Path::GetFileNameWithoutExtension(fileName));
        AddResource(resourceName, *image);
      }
       */
    }

  private:
    bool HasResources() const {
      int resxMagicNumber = 0x52657378; // ==> "Resx" in concatened bytes;
      FileStream fs(Environment::GetCommandLineArgs()[0], FileMode::Open, FileAccess::Read);
      BinaryReader reader(fs);
      reader.BaseStream().Seek(-4, SeekOrigin::End);
      int magicNumber = reader.ReadInt32();
      return magicNumber == resxMagicNumber;
    }
    
    static string ToResourceName(const string& name) {
      string resourceName = string::Format("{0}{1}", (Char::IsDigit(name[0]) ? "_" : ""), name);
      
      if (resourceName.Length() > 255)
        resourceName.Remove(255);
      
      Array<char32> badChars = {' ', '-', '*', '+', '=', '/', '\\', '&', '|', '%', '~', '\"', '\'', '(', '{', '[', ')', '}', ']'};
      
      for (char32 car : badChars) {
        resourceName = resourceName.Replace(car, '_');
      }
      
      return resourceName;
    }
    
    void AddResource(const string& resourceName, const Image& image) {
      //sp<StreamWriter> writer = File::CreateText("/Users/yves/Desktop/Resources.res");
      sp<StreamWriter> writer = new StreamWriter("/Users/yves/Desktop/Resources.res", true);
      writer->WriteLine("namespace Pcf {");
      writer->WriteLine("  namespace Resources {");
      writer->WriteLine(string::Format("    static Image {0} = {{", resourceName));
      writer->WriteLine(string::Format("      {0}, {1},", image.Size().Width(), image.Size().Height()));
      writer->WriteLine(string::Format("      \"{0}\",", image.PixelFormat()));
      int count = image.Size().Width() * image.Height() * (image.PixelFormat() == System::Drawing::Imaging::PixelFormat::Format32bppRgb ? 4 : 3);
      writer->Write(    string::Format("      new byte[{0}] {{", count));
      const byte* data = image.Data();
      for (int i = 0; i < count; i++) {
        if (i % 16 == 0)
          writer->Write("\n        ");
        writer->Write(string::Format("0x{0:X2}, ", data[i]));
      }
      writer->BaseStream().Seek(-2, SeekOrigin::Current);
      writer->WriteLine();
      writer->WriteLine("      }");
      writer->WriteLine("    };");
      writer->WriteLine("  }");
      writer->WriteLine("}");
    }
    
    void InitializeComponent() {
      this->Bounds = System::Drawing::Rectangle(300, 200, 300, 250);
      this->Text = "Resource Example";
      this->MaximizeBox(false);
      
      this->pictureBox.Parent = *this;
      this->pictureBox.BorderStyle = BorderStyle::Fixed3D;
      this->pictureBox.BackColor = Color::White;
      this->pictureBox.Bounds = System::Drawing::Rectangle(75, 25, 152, 152);
    }
    
    Pcf::System::Windows::Forms::PictureBox pictureBox;
  };
}

pcf_startup (::ImageList::Form1)
