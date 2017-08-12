#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::BackgroundColor = ConsoleColor::DarkGray;
      Console::ForegroundColor = ConsoleColor::DarkRed;
      Console::WriteLine("===============================================================================");
      Console::ForegroundColor = ConsoleColor::DarkBlue;
      Console::WriteLine("                                                                               ");
      Console::WriteLine("    ,▄▓▓▓▓▌   ▄▄▄▄▄▄▄╦                            ,▄▒▓▓▓▄ ▄▓▓▓▓▄,              ");
      Console::WriteLine("   ╔▓▓▓▓█▀▀  ▓▓▓▓▓▓▓▓▓▓▓▄                       ╒▓▓▓▓▓▓▓▓ ▀▀▀▓▓▓▓▌             ");
      Console::WriteLine("   ▓▓▓▓      ▓▓▓▓   `▀▓▓▓▓▄                     ▓▓▓▓▀         ▀▓▓▓             ");
      Console::WriteLine("   ▓▓▓▓      ▓▓▓▌      ▓▓▓▌                    ╔▓▓▓▌          ╫▓▓▓⌐       ,▄▄▄ ");
      Console::WriteLine("   ▓▓▓▓      ▓▓▓▌     ▄▓▓▓▌    ╓▓▓▓▓▓▓▓▓▄  ╒▒▓▓▓▓▓▓▓▓▓▓▓▌     ╫▓▓▓        ▓▓▓▓Γ");
      Console::WriteLine("  ,▓▓▓▓     ]▓▓▓▌▄▄▄▓▓▓▓▓▀    ▓▓▓▓▀▀▀▀▓▓▓▌ \"▀▓▓▓▓▓▓█▀▀▀▀^     ▓▓▓▓,        ▀▀▀ ");
      Console::WriteLine("╓▓▓▓▓▓Γ     ║▓▓▓▓▓▓▓▓▓▀▀    ,▓▓▓▓Γ             ╟▓▓▓            ▓▓▓▓▓▄          ");
      Console::WriteLine("▀▓▓▓▓▌      ╟▓▓▓░           ╣▓▓▓⌐              ╟▓▓▓            ▄▓▓▓▓▓          ");
      Console::WriteLine("  ▐▓▓▓▌     ╟▓▓▓░           ▓▓▓▓               ╟▓▓▓⌐          ║▓▓▓▌            ");
      Console::WriteLine("  ]▓▓▓▌     ╟▓▓▓░           ╙▓▓▓▓▄▄╖╖▄▓▓▓▌     ╟▓▓▓⌐          ]▓▓▓▌       ╓▓▓▓ ");
      Console::WriteLine("  ]▓▓▓▌     ╙▓▓▓              ▀▓▓▓▓▓▓▓▓▓▀¬     ▓▓▓▓           ▐▓▓▓▌      ▓▓▓▓▀ ");
      Console::WriteLine("   ▀▓▓▓▄,,                        \"`           ▀▓▓▀        ,,╔▓▓▓▓      ║▓▓▓Γ  ");
      Console::WriteLine("    ▀▓▓▓▓▓▓                                               ▓▓▓▓▓▓▀         `    ");
      Console::WriteLine("      `▀▀╙                                                 \"▀▀\"                ");
      Console::WriteLine("                                                                               ");
      Console::ForegroundColor = ConsoleColor::Blue;
      Console::WriteLine("                   P o r t a b l e  C + +  F r a m e w o r k                   ");
      Console::ForegroundColor = ConsoleColor::DarkGray;
      Console::WriteLine("                                                                               ");
      Console::WriteLine("        Native C++ port of .Net Framework on macOS, Linux and Windows.         ");
      Console::WriteLine("                                                                               ");
      Console::ForegroundColor = ConsoleColor::DarkRed;
      Console::WriteLine("===============================================================================");
      
      Console::ResetColor();
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output with colors:
//
// ===============================================================================
//
//     ,▄▓▓▓▓▌   ▄▄▄▄▄▄▄╦                            ,▄▒▓▓▓▄ ▄▓▓▓▓▄,
//    ╔▓▓▓▓█▀▀  ▓▓▓▓▓▓▓▓▓▓▓▄                       ╒▓▓▓▓▓▓▓▓ ▀▀▀▓▓▓▓▌
//    ▓▓▓▓      ▓▓▓▓   `▀▓▓▓▓▄                     ▓▓▓▓▀         ▀▓▓▓
//    ▓▓▓▓      ▓▓▓▌      ▓▓▓▌                    ╔▓▓▓▌          ╫▓▓▓⌐       ,▄▄▄
//    ▓▓▓▓      ▓▓▓▌     ▄▓▓▓▌    ╓▓▓▓▓▓▓▓▓▄  ╒▒▓▓▓▓▓▓▓▓▓▓▓▌     ╫▓▓▓        ▓▓▓▓Γ
//   ,▓▓▓▓     ]▓▓▓▌▄▄▄▓▓▓▓▓▀    ▓▓▓▓▀▀▀▀▓▓▓▌ "▀▓▓▓▓▓▓█▀▀▀▀^     ▓▓▓▓,        ▀▀▀
// ╓▓▓▓▓▓Γ     ║▓▓▓▓▓▓▓▓▓▀▀    ,▓▓▓▓Γ             ╟▓▓▓            ▓▓▓▓▓▄
// ▀▓▓▓▓▌      ╟▓▓▓░           ╣▓▓▓⌐              ╟▓▓▓            ▄▓▓▓▓▓
//   ▐▓▓▓▌     ╟▓▓▓░           ▓▓▓▓               ╟▓▓▓⌐          ║▓▓▓▌
//   ]▓▓▓▌     ╟▓▓▓░           ╙▓▓▓▓▄▄╖╖▄▓▓▓▌     ╟▓▓▓⌐          ]▓▓▓▌       ╓▓▓▓
//   ]▓▓▓▌     ╙▓▓▓              ▀▓▓▓▓▓▓▓▓▓▀¬     ▓▓▓▓           ▐▓▓▓▌      ▓▓▓▓▀
//    ▀▓▓▓▄,,                        "`           ▀▓▓▀        ,,╔▓▓▓▓      ║▓▓▓Γ
//     ▀▓▓▓▓▓▓                                               ▓▓▓▓▓▓▀         `
//       `▀▀╙                                                 "▀▀"
//
//                    P o r t a b l e  C + +  F r a m e w o r k
//
//         Native C++ port of .Net Framework on macOS, Linux and Windows.
//
// ===============================================================================
