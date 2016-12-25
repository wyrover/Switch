#include <Pcf/Core>
#include <Pcf/Keywords>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace Tools {
  pcf_enum_class(PackageType) {
    None = 0,
    Appl = 1,
  } pcf_enum_class_close;
}

namespace Pcf {
  namespace System {
    template <>
    class Enum<Tools::PackageType> : public BoxEnum<Tools::PackageType> {
    public:
      Enum() {}
      Enum(Tools::PackageType value) : BoxEnum<Tools::PackageType>(value) {}
      
    private:
      void InitValues(Collections::Generic::SortedDictionary<int32, string>& values) {
        values[(int32)Tools::PackageType::None] = "NONE";
        values[(int32)Tools::PackageType::Appl] = "APPL";
      }
    };
  }
}

namespace Tools {
  class PropertyList : public object {
  public:
    PropertyList() {}
    PropertyList(const PropertyList& pl) : info(pl.info), executable(pl.executable), identifier(pl.identifier), name(pl.name), version(pl.version), iconFile(pl.iconFile), infoDictionaryVersion(pl.infoDictionaryVersion), packageType(pl.packageType) {}
    PropertyList(const string& info, const string& executable, const string& identifier, const string& name, const Version& version, const string& iconFile, const Version& infoDictionaryVersion, const PackageType& packageType) : info(info), executable(executable), identifier(identifier), name(name), version(version), iconFile(Pcf::System::IO::Path::GetFileName(iconFile)), infoDictionaryVersion(infoDictionaryVersion), packageType(packageType) {}
    PropertyList(const string& info, const string& executable, const string& identifier, const string& name, const Version& version, const string& iconFile) : info(info), executable(executable), identifier(identifier), name(name), version(version), iconFile(Pcf::System::IO::Path::GetFileName(iconFile)), infoDictionaryVersion(Version(6, 0)), packageType(PackageType::Appl) {}

    const string& GetInfo() const {return this->info;}
    const string& GetExecutable() const {return this->executable;}
    const string& GetIdentifier() const {return this->identifier;}
    const string& Name() const {return this->name;}
    const Version& GetVersion() const {return this->version;}
    const string& GetIconFile() const {return this->iconFile;}
    const Version& GetInfoDictionaryVersion() const {return this->infoDictionaryVersion;}
    const PackageType& GetPackageType() const {return this->packageType;}

    void SetInfo(const string& info) {
      this->info = info;
    }

    void SetExecutable(const string& executable) {
      this->executable = executable;
    }
    
    void SetIdentifier(const string& identifier) {
      this->identifier = identifier;
    }
    
    void Name(const string& name) {
      this->name = name;
    }
    
    void SetVersion(const Version& version) {
      this->version = version;
    }
    
    void SetIconFile(const string& iconFile) {
      this->iconFile = Pcf::System::IO::Path::GetFileName(iconFile);
    }
    
    void SetInfoDictionaryVersion(const Version& infoDictionaryVersion) {
      this->infoDictionaryVersion = infoDictionaryVersion;
    }
    
    void SetPackageType(const PackageType& packageType) {
      this->packageType = packageType;
    }
    
    string ToString() const {
      static string format =
      "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
      "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"
      "<plist version=\"1.0\">\n"
      "<dict>\n"
      "\t<key>CFBundleGetInfoString</key>\n"
      "\t<string>{0}</string>\n"
      "\t<key>CFBundleExecutable</key>\n"
      "\t<string>{1}</string>\n"
      "\t<key>CFBundleIdentifier</key>\n"
      "\t<string>{2}</string>\n"
      "\t<key>CFBundleName</key>\n"
      "\t<string>{3}</string>\n"
      "\t<key>CFBundleShortVersionString</key>\n"
      "\t<string>{4}</string>\n"
      "\t<key>CFBundleIconFile</key>\n"
      "\t<string>{5}</string>\n"
      "\t<key>CFBundleInfoDictionaryVersion</key>\n"
      "\t<string>{6}</string>\n"
      "\t<key>CFBundlePackageType</key>\n"
      "\t<string>{7}</string>\n"
      "\t<key>IFMajorVersion</key>\n"
      "\t<integer>{8}</integer>\n"
      "\t<key>IFMinorVersion</key>\n"
      "\t<integer>{9}</integer>\n"
      "</dict>\n"
      "</plist>\n";

      return string::Format(format, this->info, this->executable, this->identifier, this->name, this->version, this->iconFile, this->infoDictionaryVersion, Enum<PackageType>(this->packageType), this->version.Major(), this->version.Minor());
    }
    
  private:
    string info;
    string executable;
    string identifier;
    string name;
    Version version;
    string iconFile;
    Version infoDictionaryVersion;
    PackageType packageType;
  };
  
  class AppleApplicationCreator : public object {
  public:
    static void Main(const Array<string>&) {
      const string path = ("/Users/yves/Projects/PcfForms/Bin/PcfForms/DESKTOP_OSX64/debug/Debug");
      System::Collections::Generic::List<string> files;
      files.Add("Application");
      files.Add("Button");
      files.Add("CheckBox");
      files.Add("CheckedListBox");
      files.Add("Controls");
      files.Add("Cursor");
      files.Add("DockedControls");
      files.Add("DragAndDrop");
      files.Add("Exception");
      files.Add("FolderBrowserDialog");
      files.Add("Form");
      files.Add("Font");
      files.Add("FontFamily");
      files.Add("GroupBox");
      files.Add("ImageList");
      files.Add("KeyEvents");
      files.Add("Label");
      files.Add("ListBox");
      files.Add("MainMenu");
      files.Add("MaskedTextBox");
      files.Add("MessageBox");
      files.Add("MouseEvents");
      files.Add("MulticamInstaller");
      files.Add("NumericUpDown");
      files.Add("OpenFileDialog");
      files.Add("Paint");
      files.Add("Panel");
      files.Add("ProgressBar");
      files.Add("PictureBox");
      files.Add("RadioButton");
      files.Add("Resource");
      files.Add("RichTextBox");
      files.Add("SaveFileDialog");
      files.Add("SystemSound");
      files.Add("TabControl");
      files.Add("TextBox");
      files.Add("Timer");
      
      for(string file : files) {
        CreatePackage(string::Format("{0}/{1}.app", path, file), string::Format("{0}/{1}", path, file), "com.pcf.www", Version(1, 0), "");
      }
    }
    
    static void CreatePackage(const string& path, const string& executable, const string& identifier, const Version& version, const string& iconFile) {
      PropertyList pl(Path::GetFileNameWithoutExtension(executable), Path::GetFileName(executable), identifier, Path::GetFileNameWithoutExtension(executable), version, iconFile);
      
      if (Directory::Exists(path))
        Directory::Delete(path, true);
      Directory::CreateDirectory(string::Format("{0}/Contents/MacOS", path));
      Directory::CreateDirectory(string::Format("{0}/Contents/Resources", path));
      
      Sp<StreamWriter> writer = File::CreateText(string::Format("{0}/Contents/Info.plist", path));
      writer->Write(pl.ToString());
      writer->Close();
      
      File::Copy(executable, string::Format("{0}/Contents/MacOS/{1}", path, Path::GetFileName(executable)));
      System::Diagnostics::Process::Start("chmod", string::Format("+x {0}/Contents/MacOS/{1}", path, Path::GetFileName(executable)));
      
      if (!iconFile.IsEmpty())
        File::Copy(iconFile, string::Format("{0}/Contents/Resources/{1}", path, Path::GetFileName(iconFile)));
    }
    
  };
}

// Specify the Main entry point to System
startup(&Tools::AppleApplicationCreator::Main);
