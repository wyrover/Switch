using System;

namespace ExportDotNet {
  public class ExportObject {
    public static void ExportEnum(Type type) {
      ExportEnum(new string[]{}, type);
    }

    public static void ExportEnum(string[]namespaces, Type type) {
      ExportEnum(Console.Out, namespaces, type);
    }

    public static void ExportEnum(System.IO.TextWriter tw, string[]namespaces, Type type) {
      tw.WriteLine("#pragma once");
      tw.WriteLine("");

      string indentation = "";
      foreach (string ns in namespaces) {
        tw.WriteLine("{0}namespace {1} {{", indentation, ns);
        indentation += "  ";
      }

      tw.WriteLine("{0}/**", indentation);
      tw.WriteLine("{0} * Enumeration.", indentation);
      tw.WriteLine("{0} * Specifie the {1} values", indentation, type.Name);
      tw.WriteLine("{0} * | enum  | value |   |", indentation);
      tw.WriteLine("{0} * |-------|-------|---|", indentation);
      foreach (var value in Enum.GetValues(type))
        tw.WriteLine("{0} * | {1} | {2} |   |", indentation, value, (int)value);
      tw.WriteLine("{0} */", indentation);
      tw.WriteLine("{0}class {1} : public System::Enum {{", indentation, type.Name);
      tw.WriteLine("{0}public:", indentation);
      tw.WriteLine("{0}  enum Values {{", indentation);
      string firstValue = string.Empty;
      foreach (var value in Enum.GetValues(type)) {
        if (string.IsNullOrEmpty(firstValue))
          firstValue = value.ToString();
        tw.WriteLine("{0}    {1} = {2},", indentation, value, (int)value);
      }
      tw.WriteLine("{0}  }};", indentation);
      tw.WriteLine();
      tw.WriteLine("{0}  /// @cond DEV", indentation);
      tw.WriteLine("{0}  {1}() : System::Enum({2}) {{}}", indentation, type.Name, firstValue);
      tw.WriteLine("{0}  {1}(const System::Enum& value) : System::Enum(value) {{}}", indentation, type.Name);
      tw.WriteLine("{0}  {1}(int32 value) : System::Enum(value) {{}}", indentation, type.Name);
      tw.WriteLine();
      tw.WriteLine("{0}private:", indentation);
      tw.WriteLine("{0}  void InitEnumValues(System::Collections::Generic::IDictionary<int32, string>& values) const {{", indentation);
      foreach (string value in Enum.GetNames(type))
        tw.WriteLine("{0}  values[{1}] = \"{1}\";", indentation, value);
      tw.WriteLine("{0}  }}", indentation);
      tw.WriteLine("{0}  /// @endcond", indentation);
      tw.WriteLine("{0}}};", indentation);

      for(int i = 0; i < namespaces.Length; i++) {
        indentation = indentation.Remove(indentation.Length-2);
        tw.WriteLine("{0}}}", indentation);
      }
    }

    public static void ExportFlagEnum(Type type) {
      ExportFlagEnum(new string[]{}, type);
    }

    public static void ExportFlagEnum(string[]namespaces, Type type) {
      ExportFlagEnum(Console.Out, namespaces, type);
    }

    public static void ExportFlagEnum(System.IO.TextWriter tw, string[]namespaces, Type type) {
      tw.WriteLine("#pragma once");
      tw.WriteLine("");

      string indentation = "";
      foreach (string ns in namespaces) {
        tw.WriteLine("{0}namespace {1} {{", indentation, ns);
        indentation += "  ";
      }

      tw.WriteLine("{0}/**", indentation);
      tw.WriteLine("{0} * Flags Enumeration.", indentation);
      tw.WriteLine("{0} * Specifie the {1} values", indentation, type.Name);
      tw.WriteLine("{0} * | enum  | value |   |", indentation);
      tw.WriteLine("{0} * |-------|-------|---|", indentation);
      foreach (var value in Enum.GetValues(type))
        tw.WriteLine("{0} * | {1} | {2} |   |", indentation, value, (int)value);
      tw.WriteLine("{0} */", indentation);
      tw.WriteLine("{0}class {1} : public System::FlagsEnum {{", indentation, type.Name);
      tw.WriteLine("{0}public:", indentation);
      tw.WriteLine("{0}  enum Values {{", indentation);
      string firstValue = string.Empty;
      foreach (var value in Enum.GetValues(type)) {
        if (string.IsNullOrEmpty(firstValue))
          firstValue = value.ToString();
        tw.WriteLine("{0}    {1} = {2},", indentation, value, (int)value);
      }
      tw.WriteLine("{0}  }};", indentation);
      tw.WriteLine();
      tw.WriteLine("{0}  /// @cond DEV", indentation);
      tw.WriteLine("{0}  {1}() : System::FlagsEnum({2}) {{}}", indentation, type.Name, firstValue);
      tw.WriteLine("{0}  {1}(const System::FlagsEnum& value) : System::FlagsEnum(value) {{}}", indentation, type.Name);
      tw.WriteLine("{0}  {1}(int32 value) : System::FlagsEnum(value) {{}}", indentation, type.Name);
      tw.WriteLine();
      tw.WriteLine("{0}private:", indentation);
      tw.WriteLine("{0}  void InitEnumValues(System::Collections::Generic::IDictionary<int32, string>& values) const {{", indentation);
      foreach (string value in Enum.GetNames(type))
        tw.WriteLine("{0}  values[{1}] = \"{1}\";", indentation, value);
      tw.WriteLine("{0}  }}", indentation);
      tw.WriteLine("{0}  /// @endcond", indentation);
      tw.WriteLine("{0}}};", indentation);

      for(int i = 0; i < namespaces.Length; i++) {
        indentation = indentation.Remove(indentation.Length-2);
        tw.WriteLine("{0}}}", indentation);
      }
    }
  }
}

