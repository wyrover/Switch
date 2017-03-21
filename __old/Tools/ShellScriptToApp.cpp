#include <Pcf/Pcf>

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;

namespace Tools {
  enum class PackageType {
    None = 0,
    Appl = 1,
  };
}

/// @cond
template<>
class EnumToStrings<Tools::PackageType> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Tools::PackageType::None, "NONE"}, {(int64)Tools::PackageType::Appl, "APPL"}};
    flags = false;
  }
};
/// @endcond

namespace Tools {
  class PropertyList : public object {
  public:
    PropertyList() {}
    PropertyList(const PropertyList& pl) : info(pl.info), executable(pl.executable), identifier(pl.identifier), name(pl.name), version(pl.version), iconFile(pl.iconFile), infoDictionaryVersion(pl.infoDictionaryVersion), packageType(pl.packageType) {}
    PropertyList(const string& info, const string& executable, const string& identifier, const string& name, const Version& version, const string& iconFile, const Version& infoDictionaryVersion, const PackageType& packageType) : info(info), executable(executable), identifier(identifier), name(name), version(version), iconFile(System::IO::Path::GetFileName(iconFile)), infoDictionaryVersion(infoDictionaryVersion), packageType(packageType) {}
    PropertyList(const string& info, const string& executable, const string& identifier, const string& name, const Version& version, const string& iconFile) : info(info), executable(executable), identifier(identifier), name(name), version(version), iconFile(System::IO::Path::GetFileName(iconFile)), infoDictionaryVersion(Version(6, 0)), packageType(PackageType::Appl) {}

    const string& GetInfo() const {return this->info;}
    const string& GetExecutable() const {return this->executable;}
    const string& GetIdentifier() const {return this->identifier;}
    const string& GetName() const {return this->name;}
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
    
    void SetName(const string& name) {
      this->name = name;
    }
    
    void SetVersion(const Version& version) {
      this->version = version;
    }
    
    void SetIconFile(const string& iconFile) {
      this->iconFile = System::IO::Path::GetFileName(iconFile);
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

      return string::Format(format, this->info, this->executable, this->identifier, this->name, this->version, this->iconFile, this->infoDictionaryVersion, this->packageType, this->version.Major(), this->version.Minor());
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
  
  class ShellScriptToApp : public object {
  public:
    static void Main(const Array<string>& args) {
      if (args.Length == 0) {
        Console::WriteLine("appify executable");
        Environment::Exit(1);
      }
      
      string fullPath = Path::GetFullPath(args[0]);
      
      CreatePackage(string::Format("{0}/{1}.app", Path::GetDirectoryName(fullPath), Path::GetFileNameWithoutExtension(fullPath)), "ShellScriptRunner", "com.pcf.www", Version(1, 0), "", args[0]);
    }
    
    static void CreatePackage(const string& path, const string& executable, const string& identifier, const Version& version, const string& iconFile, const string& script) {
      PropertyList pl(Path::GetFileNameWithoutExtension(executable), Path::GetFileName(executable), identifier, Path::GetFileNameWithoutExtension(executable), version, iconFile);
      
      if (Directory::Exists(path)) {
        File::Delete(string::Format("{0}/Contents/Info.plist", path));
        File::Delete(string::Format("{0}/Contents/MacOS/{1}", path, Path::GetFileName(executable)));
        File::Delete(string::Format("{0}/Contents/MacOS/Script.sh", path));
      }
      Directory::CreateDirectory(string::Format("{0}/Contents/MacOS", path));
      Directory::CreateDirectory(string::Format("{0}/Contents/Resources", path));
      
      StreamWriter writer = File::CreateText(string::Format("{0}/Contents/Info.plist", path));
      writer.Write(pl.ToString());
      writer.Close();
      
      File::Copy(executable, string::Format("{0}/Contents/MacOS/{1}", path, Path::GetFileName(executable)));
      System::Diagnostics::Process::Start("chmod", string::Format("+x {0}/Contents/MacOS/{1}", path, Path::GetFileName(executable)));
      
      File::Copy(script, string::Format("{0}/Contents/MacOS/Script.sh", path));
      System::Diagnostics::Process::Start("chmod", string::Format("+x {0}/Contents/MacOS/Script.sh", path));
      
      if (!iconFile.IsEmpty())
        File::Copy(iconFile, string::Format("{0}/Contents/Resources/{1}", path, Path::GetFileName(iconFile)));
    }
    
  };
}

pcf_startup (Tools::ShellScriptToApp)
