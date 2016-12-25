using System;
using System.Diagnostics;
using System.IO;

namespace Tools {
  enum PackageType {
    None,
    Appl,
  };

  class PropertyList : object {
    public PropertyList() {}

    public PropertyList(PropertyList pl) {
      this.info = pl.info;
      this.executable = pl.executable;
      this.identifier = pl.identifier;
      this.name = pl.name;
      this.version = pl.version;
      this.iconFile = pl.iconFile;
      this.infoDictionaryVersion = pl.infoDictionaryVersion;
      this.packageType = pl.packageType;
    }

    public PropertyList(string info, string executable, string identifier, string name, Version version, string iconFile, Version infoDictionaryVersion, PackageType packageType) {
      this.info = info;
      this.executable = executable;
      this.identifier = identifier;
      this.name = name;
      this.version = version;
      this.iconFile = System.IO.Path.GetFileName(iconFile);
      this.infoDictionaryVersion = infoDictionaryVersion;
      this.packageType = packageType;
    }

    public PropertyList(string info, string executable, string identifier, string name, Version version, string iconFile) {
      this.info = info;
      this.executable = executable;
      this.identifier = identifier;
      this.name = name;
      this.version = version;
      this.iconFile = System.IO.Path.GetFileName(iconFile);
      this.infoDictionaryVersion = new System.Version(6, 0);
      this.packageType = Tools.PackageType.Appl;
    }

    public string Info {
      get { return this.info;}
      set { this.info = value;}
    }

    public string Executable {
      get { return this.executable;}
      set { this.executable = value;}
    }

    public string Identifier {
      get { return this.identifier;}
      set { this.identifier = value;}
    }

    public string Name {
      get { return this.name;}
      set { this.name = value;}
    }

    public System.Version Version {
      get { return this.version;}
      set { this.version = value;}
    }

    public string IconFile {
      get { return this.iconFile;}
      set { this.iconFile = value;}
    }

    public System.Version InfoDictionaryVersion {
      get { return this.infoDictionaryVersion;}
      set { this.infoDictionaryVersion = value;}
    }

    public Tools.PackageType PackageType {
      get { return this.packageType;}
      set { this.packageType = value;}
    }

    public override string ToString() {
      return string.Format("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n<plist version=\"1.0\">\n<dict>\n\t<key>CFBundleGetInfoString</key>\n\t<string>{0}</string>\n\t<key>CFBundleExecutable</key>\n\t<string>mono {1}</string>\n\t<key>CFBundleIdentifier</key>\n\t<string>{2}</string>\n\t<key>CFBundleName</key>\n\t<string>{3}</string>\n\t<key>CFBundleShortVersionString</key>\n\t<string>{4}</string>\n\t<key>CFBundleIconFile</key>\n\t<string>{5}</string>\n\t<key>CFBundleInfoDictionaryVersion</key>\n\t<string>{6}</string>\n\t<key>CFBundlePackageType</key>\n\t<string>{7}</string>\n\t<key>IFMajorVersion</key>\n\t<integer>{8}</integer>\n\t<key>IFMinorVersion</key>\n\t<integer>{9}</integer>\n</dict>\n</plist>\n", this.info, this.executable, this.identifier, this.name, this.version, this.iconFile, this.infoDictionaryVersion, this.packageType, this.version.Major, this.version.Minor);
    }

    private string info;
    private string executable;
    private string identifier;
    private string name;
    private System.Version version = new System.Version();
    private string iconFile;
    private System.Version infoDictionaryVersion = new System.Version();
    private Tools.PackageType packageType;
  }
    
  class AppleApplicationCreator : object {
    public static void CreatePackage(string path, string executable, string identifier, Version version, string iconFile) {
      PropertyList pl = new PropertyList(Path.GetFileNameWithoutExtension(executable), Path.GetFileName(executable), identifier, Path.GetFileNameWithoutExtension(executable), version, iconFile);

      if (Directory.Exists(path))
        Directory.Delete(path, true);
      Directory.CreateDirectory(string.Format("{0}/Contents/MacOS", path));
      Directory.CreateDirectory(string.Format("{0}/Contents/Resources", path));

      StreamWriter writer = File.CreateText(string.Format("{0}/Contents/Info.plist", path));
      writer.Write(pl.ToString());
      writer.Close();

      File.Copy(executable, string.Format("{0}/Contents/MacOS/{1}", path, Path.GetFileName(executable)));
      System.Diagnostics.Process.Start("chmod", string.Format("+x {0}/Contents/MacOS/{1}", path, Path.GetFileName(executable)));

      if (string.IsNullOrEmpty(iconFile))
        File.Copy(iconFile, string.Format("{0}/Contents/Resources/{1}", path, Path.GetFileName(iconFile)));
    }
  }

  class MainClass {
    public static void Main(string[] args) {
      if (args.Length != 1) {
        Console.WriteLine("appify executable");
        Environment.Exit(1);
      }

      string fullPath = Path.GetFullPath(args[0]);
      AppleApplicationCreator.CreatePackage(string.Format("{0}/{1}.app", Path.GetDirectoryName(fullPath), Path.GetFileNameWithoutExtension(fullPath)), string.Format("{0}/{1}", Path.GetDirectoryName(fullPath), Path.GetFileNameWithoutExtension(fullPath)), "com.pcf.www", new Version(1, 0), "");
    }
  }
}
