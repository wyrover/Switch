#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<byte> bytes1(100);
      Array<byte> bytes2(100);
      Random rnd1;
      Random rnd2;
      
      rnd1.NextBytes(bytes1);
      rnd2.NextBytes(bytes2);
      
      Console::WriteLine("First Series:");
      for (int i = 0; i < bytes1.Length; i++) {
        Console::Write("{0, 5}", bytes1[i]);
        if ((i + 1) % 10 == 0)
          Console::WriteLine();
      }
      
      Console::WriteLine();
      Console::WriteLine("Second Series:");
      for (int i = 0; i < bytes2.Length; i++) {
        Console::Write("{0, 5}", bytes2[i]);
        if ((i + 1) % 10 == 0)
          Console::WriteLine();
      }
    }
  };
}

sw_startup (Examples::Program)

// This code produces the following output:
//
// First Series:
// 135   53  133  128  229  159   76  187   40  229
// 187  140  203   87  125   71  242  128  200  194
//  46   83  253  145  187  109   79  245  181   41
//  37  124   93  175   55  240  238   15  161   77
//  15  196  105  211   24   29    5    5  250  162
//  84   73   97  147   72   25   81  197   15  181
// 143  213   33  211    8   60  158   46   48  135
//  79  118  154  220  184  117   36  187  171  190
//  40  118  172   14  155   82   13   67  185   88
//  54  142   75   26  107  208  190  234  139  139
//
// Second Series:
//  45  252  134   99  193  187  220  174  160   77
// 186  216   22   42   31  167  197  135  227  225
// 178  138  176   41  151   87  203   42  206  140
// 184  137  139   85   30   65   95   44   63  104
// 174   70   19  201   95   98   34   52   46  134
//  62   11  119  224   96  115   32   55  139   51
// 229  163   85  229  101   21  107  188   20  248
// 196  235  156  193   44  211   20   54   10  138
// 101  199  202  167   34   99   75  176   95   59
