using System;
using System.Drawing;
using System.Windows;
using System.Windows.Forms;
using System.IO.Ports;

namespace ExportDotNet {
  class MainClass {
    public static void Main (string[] args) {
      //ExportObject.ExportEnum(new string[]{"Pcf", "System", "Windows", "Forms"} , typeof(System.Windows.Forms.AccessibleNavigation));
      ExportSystemWIoPortsEnums();
      //ExportSystemWindowsFormsEnums();
    }

    enum EnumType {
      Enum,
      Flags
    }

    struct ItemType {
      public ItemType(Type type, EnumType enumType) {
        this.type = type;
        this.enumType = enumType;
      }

      public Type Type { get { return this.type; } }
      public EnumType EnumType { get { return this.enumType; } }

      private Type type;
      private EnumType enumType;
    }

    static void ExportSystemWIoPortsEnums() {
      ItemType[] itemTypes =  { 
        new ItemType(typeof(System.IO.Ports.Handshake), EnumType.Enum), 
        new ItemType(typeof(System.IO.Ports.Parity), EnumType.Enum), 
        new ItemType(typeof(System.IO.Ports.SerialData), EnumType.Enum), 
        new ItemType(typeof(System.IO.Ports.SerialError), EnumType.Enum), 
        new ItemType(typeof(System.IO.Ports.SerialPinChange), EnumType.Enum), 
        new ItemType(typeof(System.IO.Ports.StopBits), EnumType.Enum), 
      };

      foreach (ItemType itemType in itemTypes) {
        using (System.IO.StreamWriter sw = new System.IO.StreamWriter(itemType.Type.Name + ".h")) {
          if (itemType.EnumType == EnumType.Enum)
            ExportObject.ExportEnum(sw, new string[]{ "Pcf", "System", "IO", "Ports" }, itemType.Type);
          else
            ExportObject.ExportFlagEnum(sw, new string[]{ "Pcf", "System", "IO", "Ports" }, itemType.Type);
        }
      }
    }

    static void ExportSystemWindowsFormsEnums() {
      ItemType[] itemTypes =  { 
        new ItemType(typeof(System.Windows.Forms.AccessibleEvents), EnumType.Enum), 
        new ItemType(typeof(System.Windows.Forms.AccessibleNavigation), EnumType.Enum), 
        new ItemType(typeof(System.Windows.Forms.AccessibleRole), EnumType.Enum), 
        new ItemType(typeof(System.Windows.Forms.AccessibleSelection), EnumType.Enum), 
        new ItemType(typeof(System.Windows.Forms.AccessibleStates), EnumType.Enum), 
        new ItemType(typeof(System.Windows.Forms.AnchorStyles), EnumType.Flags),
        new ItemType(typeof(System.Windows.Forms.Appearance), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.ArrangeDirection), EnumType.Flags),
        new ItemType(typeof(System.Windows.Forms.ArrangeStartingPosition), EnumType.Flags),
        new ItemType(typeof(System.Windows.Forms.ArrowDirection), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.AutoCompleteMode), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.AutoCompleteSource), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.AutoCompleteSource), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.AutoScaleMode), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.AutoSizeMode), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.AutoValidate), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.BatteryChargeStatus), EnumType.Flags),
        new ItemType(typeof(System.Windows.Forms.BindingCompleteContext), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.BindingCompleteState), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.BootMode), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.Border3DSide), EnumType.Flags),
        new ItemType(typeof(System.Windows.Forms.Border3DStyle), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.BorderStyle), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.BoundsSpecified), EnumType.Flags),
        new ItemType(typeof(System.Windows.Forms.ButtonBorderStyle), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.ButtonState), EnumType.Flags),
        new ItemType(typeof(System.Windows.Forms.CaptionButton), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.CharacterCasing), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.CheckState), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.CloseReason), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.ColorDepth), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.ColumnHeaderAutoResizeStyle), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.ColumnHeaderStyle), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.ComboBoxStyle), EnumType.Enum),
        new ItemType(typeof(System.Windows.Forms.ControlStyles), EnumType.Flags),
      };

      foreach (ItemType itemType in itemTypes) {
        using (System.IO.StreamWriter sw = new System.IO.StreamWriter(itemType.Type.Name + ".h")) {
          if (itemType.EnumType == EnumType.Enum)
            ExportObject.ExportEnum(sw, new string[]{ "Pcf", "System", "Windows", "Forms" }, itemType.Type);
          else
            ExportObject.ExportFlagEnum(sw, new string[]{ "Pcf", "System", "Windows", "Forms" }, itemType.Type);
        }
      }
    }
  }
}
