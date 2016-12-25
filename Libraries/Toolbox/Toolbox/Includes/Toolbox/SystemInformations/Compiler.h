#pragma once

#include <Pcf/Pcf>

namespace Pcf {
  namespace Toolbox {
    namespace SystemInformation {
      enum class Compiler {
        Acc,
        AltiumMicroBlazeC,
        AltiumCTtoHardware,
        AmsterdamCompilerKit,
        ArmCompiler,
        AztecC,
        BorlandCpp,
        Cc65,
        Clang,
        ComeauCpp,
        Compaq,
        ConvexC,
        CompCert,
        CoverityStaticAnalyzer,
        Cray,
        Diab,
        DiceC,
        DigitalMars,
        DignusSystems,
        Djgpp,
        EdgCppFrontend,
        EkoPath,
        FujitsuCpp,
        Gcc,
        GreenHill,
        HpAnsiC,
        HpaCpp,
        Iar,
        IbmXl,
        IbmZOs,
        ImageCraftC,
        Intel,
        KaiCpp,
        KeilCarm,
        KeilC166,
        KeilC51,
        Lcc,
        Llvm,
        MetaWareHigh,
        MetrowerksCodeWarrior,
        MicrosoftVisualCpp,
        Microtec,
        MicrowayNdpC,
        MinGW,
        MIPSpro,
        MiracleC,
        MpwCpp,
        NorcroftC,
        Nwcc,
        Open64,
        OracleProCPrecompiler,
        OracleSolarisStudio,
        PacificC,
        Palm,
        Pelles,
        PortlandGroup,
        Renesas,
        SasC,
        ScoOpenServer,
        SmallDeviceCCompiler,
        SnCompiler,
        SymantecCpp,
        TexasInstruments,
        ThinkC,
        TinyC,
        TurboC,
        Ultimate,
        UslC,
        Vbcc,
        WatcomCpp,
        ZortechCpp
      };

      class CompilerInformation : public object {
      public:
        static Compiler Id() {
          return Compiler::Acc;
        }
        
        static System::Version Version() {
          return System::Version();
        }
        
      private:
        CompilerInformation() {}
      };
    }
  }
}

template <>
class EnumToStrings<Toolbox::SystemInformation::Compiler> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values[(int32)Toolbox::SystemInformation::Compiler::Acc] = "Acc";
    values[(int32)Toolbox::SystemInformation::Compiler::AltiumMicroBlazeC] = "AltiumMicroBlazeC";
    values[(int32)Toolbox::SystemInformation::Compiler::AltiumCTtoHardware] = "AltiumCTtoHardware";
    values[(int32)Toolbox::SystemInformation::Compiler::AmsterdamCompilerKit] = "AmsterdamCompilerKit";
    values[(int32)Toolbox::SystemInformation::Compiler::ArmCompiler] = "ArmCompiler";
    values[(int32)Toolbox::SystemInformation::Compiler::AztecC] = "AztecC";
    values[(int32)Toolbox::SystemInformation::Compiler::BorlandCpp] = "BorlandCpp";
    values[(int32)Toolbox::SystemInformation::Compiler::Cc65] = "Cc65";
    values[(int32)Toolbox::SystemInformation::Compiler::Clang] = "Clang";
    values[(int32)Toolbox::SystemInformation::Compiler::ComeauCpp] = "ComeauCpp";
    values[(int32)Toolbox::SystemInformation::Compiler::Compaq] = "Compaq";
    values[(int32)Toolbox::SystemInformation::Compiler::ConvexC] = "ConvexC";
    values[(int32)Toolbox::SystemInformation::Compiler::CompCert] = "CompCert";
    values[(int32)Toolbox::SystemInformation::Compiler::CoverityStaticAnalyzer] = "CoverityStaticAnalyzer";
    values[(int32)Toolbox::SystemInformation::Compiler::Cray] = "Cray";
    values[(int32)Toolbox::SystemInformation::Compiler::Diab] = "Diab";
    values[(int32)Toolbox::SystemInformation::Compiler::DiceC] = "DiceC";
    values[(int32)Toolbox::SystemInformation::Compiler::DigitalMars] = "DigitalMars";
    values[(int32)Toolbox::SystemInformation::Compiler::DignusSystems] = "DignusSystems";
    values[(int32)Toolbox::SystemInformation::Compiler::Djgpp] = "Djgpp";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::GreenHill] = "GreenHill";
    values[(int32)Toolbox::SystemInformation::Compiler::HpAnsiC] = "HpAnsiC";
    values[(int32)Toolbox::SystemInformation::Compiler::HpaCpp] = "HpaCpp";
    values[(int32)Toolbox::SystemInformation::Compiler::Iar] = "Iar";
    values[(int32)Toolbox::SystemInformation::Compiler::IbmXl] = "IbmXl";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
    values[(int32)Toolbox::SystemInformation::Compiler::Gcc] = "Gcc";
  }
};
