#if !_WIN32

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#include "../../../../Includes/Pcf/Types.h"
#include "../Console.h"

using namespace Os;

namespace {
  class Terminal {
  public:
    Terminal() : peekCharacter(-1) {
      tcgetattr(0, &this->initialSettings);
      
      this->newSettings = this->initialSettings;
      this->newSettings.c_lflag &= ~(ICANON|ECHO);
      this->newSettings.c_cc[VMIN] = 1;
      this->newSettings.c_cc[VTIME] = 0;
      tcsetattr(0, TCSANOW, &this->newSettings);
    }
    
    ~Terminal() {
      if (IsAnsiSupported())
        printf("%s", "\x1b[0m");
      tcsetattr(0, TCSANOW, &this->initialSettings);
    }
    
    int32 Getch() {
      sbyte character = this->peekCharacter;
      if (this->peekCharacter != -1) {
        this->peekCharacter = -1;
        return character;
      }
      
      read(0, &character, 1);
      return character;
    }
    
    bool KeyAvailable() {
      if (this->peekCharacter != -1)
        return true;
      
      this->newSettings.c_cc[VMIN] = 0;
      tcsetattr(0, TCSANOW, &newSettings);
      
      read(0, &this->peekCharacter, 1);
      
      this->newSettings.c_cc[VMIN] = 1;
      tcsetattr(0, TCSANOW, &this->newSettings);
      
      return this->peekCharacter != -1;
    }
    
    static bool IsAnsiSupported() {
      static std::string terminal = getenv("TERM") == null ? "" : getenv("TERM");
      return isatty(fileno(stdout)) && (terminal == "xterm" ||terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
    }

  private:
    termios initialSettings;
    termios newSettings;
    sbyte peekCharacter;
  };
  
  static Terminal terminal;
  static int32 backColor = 16;
  static int32 foreColor = 16;
  static bool cursorVisible = true;
  
  class KeyInfo {
  public:
    class InputList {
    public:
      InputList() {}
      InputList(const std::list<int32>& chars) : chars(chars) {}
      InputList(std::initializer_list<int32> il) : chars(il) {}
      InputList(const InputList& il) : chars(il.chars) {}
      
      InputList& operator =(const InputList& il) {
        this->chars = il.chars;
        return *this;
      }
      
      bool operator ==(const InputList& il) const {return this->chars == il.chars;}
      bool operator !=(const InputList& il) const {return this->chars != il.chars;}
      
      using const_iterator = std::list<int32>::const_iterator;
      using iterator = std::list<int32>::iterator;
      
      const_iterator cbegin() const {return this->chars.begin();}
      const_iterator cend() const {return this->chars.end();}
      const_iterator begin() const {return this->chars.begin();}
      iterator begin() {return this->chars.begin();}
      const_iterator end() const {return this->chars.end();}
      iterator end() {return this->chars.end();}
      
      
      void Add(int32 c) {this->chars.push_back(c);}
      void AddFront(int32 c) {this->chars.push_front(c);}
      void Remove (int32 c) {this->chars.remove(c);}
      int32 Count() const {return static_cast<int32>(this->chars.size());}
      int32 Pop() { int32 c = this->chars.front();  this->chars.erase(this->chars.begin()); return c;}
      void Clear() {this->chars.clear();}
      
      bool IsEmpty() const {return this->chars.empty();}
      
      std::string ToString() const {
        std::stringstream result;
        std::list<int32>::const_iterator iterator = this->chars.begin();
        while (iterator != this->chars.end()) {
          if (char(*iterator & 0xFF) == 27)
            result << "^[";
          else
            result << char(*iterator & 0xFF);
          iterator++;
        }
        return result.str();
      }
      
      static InputList Parse(const std::string& value) {
        InputList result;
        std::string::const_iterator iterator = value.begin();
        while (iterator != value.end()) {
          if (*iterator == '^' &&  *(iterator+1) == '[') {
            result.chars.push_back(27);
            iterator++;
          } else
            result.chars.push_back(*iterator);
          iterator++;
        }
        return result;
      }
      
    private:
      std::list<int32> chars;
    };
    
    KeyInfo(const KeyInfo& keyInfo) : key(keyInfo.key), keyChar(keyInfo.keyChar), hasAltModifier(keyInfo.hasAltModifier), hasControlModifier(keyInfo.hasControlModifier), hasShiftModifier(keyInfo.hasShiftModifier) {}
    
    KeyInfo& operator =(const KeyInfo& keyInfo) {
      this->key = keyInfo.key;
      this->keyChar = keyInfo.keyChar;
      this->hasAltModifier = keyInfo.hasAltModifier;
      this->hasControlModifier = keyInfo.hasControlModifier;
      this->hasShiftModifier = keyInfo.hasShiftModifier;
      return *this;
    }
    
    static bool KeyAvailable() {return !inputs.IsEmpty() || terminal.KeyAvailable();}
    
    static KeyInfo Read() {
      if (!inputs.IsEmpty())
        return ToKeyInfo(inputs.Pop());

      do
        inputs.Add(terminal.Getch());
      while (terminal.KeyAvailable());

      if (KeyInfo::keys.find(inputs.ToString()) != KeyInfo::keys.end()) {
        std::string str = inputs.ToString();
        inputs.Clear();
        return KeyInfo(KeyInfo::keys[str].key, KeyInfo::keys[str].keyChar, false, false, KeyInfo::keys[str].shift);
      }
      
      if (inputs.Count() == 1)
        return ToKeyInfo(inputs.Pop());
      
      if (inputs.Count() > 1 && *inputs.begin() != 27)
        return ToKeyInfo(ToKey(inputs));
 
      inputs.Pop();
      return ToKeyInfo(inputs.Pop(), true);
    }
    
    int32 Key() const {return this->key;}
    
    int32 KeyChar() const {return this->keyChar;}
    
    bool HasAltModifier() const {return this->hasAltModifier;}
    
    bool HasControlModifier() const {return this->hasControlModifier;}
    
    bool HasShiftModifier() const {return this->hasShiftModifier;}
    
    std::string ToString() const {
      std::stringstream result;
      result << "{Key=" << std::hex << this->key << ", KeyChar=" << std::dec << static_cast<char>(this->keyChar) << ", HasAltModifier=" << ToString(this->hasAltModifier) << ", HasControlModifier=" << ToString(this->hasControlModifier) << ", HasShiftModifier=" << ToString(this->hasShiftModifier) << "}";
      return result.str();
    }
    
  private:
    KeyInfo() : key(0), keyChar(0), hasAltModifier(false), hasControlModifier(false), hasShiftModifier(false) {}
    KeyInfo(int32 key, int32 keyChar) : key(key), keyChar(keyChar), hasAltModifier(false), hasControlModifier(false), hasShiftModifier(false) {}
    KeyInfo(int32 key, int32 keyChar, bool hasAltModifier, bool hasControlModifier, bool hasShiftModifier) : key(key), keyChar(keyChar), hasAltModifier(hasAltModifier), hasControlModifier(hasControlModifier), hasShiftModifier(hasShiftModifier) {}
    
    static std::string ToString(bool b) {return b ? "true" : "false";}
    
    static int32 ToKey(InputList& inputs) {
      int32 key = 0;
      int32 index = 1;
      for (auto c : inputs)
        key |= (c & 0xFF) << (8*index--);
      inputs.Clear();
      return key;
    }
  
    static KeyInfo ToKeyInfo(int32 key) {
      return ToKeyInfo(key, false);
    }
    
    static KeyInfo ToKeyInfo(int32 key, bool alt) {
      // Ctrl + Space
      if (key == 0)
        return KeyInfo(' ', ' ', false, true, false);
      
      // Ctrl + [a; z]
      if ((key >= 1 && key <= 7) || (key >= 10 && key <= 11) || (key >= 14 && key <= 18) || (key >= 20 && key<= 26))
        return KeyInfo(key + 'A' - 1, key, false, true, false);
      
      switch (key) {
        case 50086 : return KeyInfo(0, U'æ', alt, false, false);
        case 50054 : return KeyInfo(0, U'Æ', alt, false, false);
        case 50079 : return KeyInfo(0, U'ß', alt, false, false);
        case -1426005368 : return KeyInfo(0, U'∫', alt, false, false);
        case 49833 : return KeyInfo(0, U'©', alt, false, false);
        case 49826 : return KeyInfo(0, U'¢', alt, false, false);
        case -2113871224 : return KeyInfo(0, U'∂', alt, false, false);
        case -2046762360 : return KeyInfo(0, U'∆', alt, false, false);
        case 50090 : return KeyInfo(0, U'ê', alt, false, false);
        case 50058 : return KeyInfo(0, U'Ê', alt, false, false);
        case 50834 : return KeyInfo(0, U'ƒ', alt, false, false);
        case 49847 : return KeyInfo(0, U'·', alt, false, false);
        case -2130645076 : return KeyInfo(0, U'ﬁ', alt, false, false);
        case -2113867860 : return KeyInfo(0, U'ﬂ', alt, false, false);
        case 50060 : return KeyInfo(0, U'Ì', alt, false, false);
        case 50062 : return KeyInfo(0, U'Î', alt, false, false);
        case 50094 : return KeyInfo(0, U'î', alt, false, false);
        case 50095 : return KeyInfo(0, U'ï', alt, false, false);
        case 50063 : return KeyInfo(0, U'Ï', alt, false, false);
        case 50061 : return KeyInfo(0, U'Í', alt, false, false);
        case 50056 : return KeyInfo(0, U'È', alt, false, false);
        case 50059 : return KeyInfo(0, U'Ë', alt, false, false);
        case 49836 : return KeyInfo(0, U'¬', alt, false, false);
        case 49845 : return KeyInfo(0, U'µ', alt, false, false);
        case 50067 : return KeyInfo(0, U'Ó', alt, false, false);
        case 50353 : return KeyInfo(0, U'ı', alt, false, false);
        case 50579 : return KeyInfo(0, U'œ', alt, false, false);
        case 50578 : return KeyInfo(0, U'Œ', alt, false, false);
        case 53120 : return KeyInfo(0, U'π', alt, false, false);
        case -1895767416 : return KeyInfo(0, U'∏', alt, false, false);
        case -1593777536 : return KeyInfo(0, U'‡', alt, false, false);
        case 52905 : return KeyInfo(0, U'Ω', alt, false, false);
        case 49838 : return KeyInfo(0, U'®', alt, false, false);
        case -1577000316 : return KeyInfo(0, U'‚', alt, false, false);
        case 50066 : return KeyInfo(0, U'Ò', alt, false, false);
        case -1862212984 : return KeyInfo(0, U'∑', alt, false, false);
        case -1610554752 : return KeyInfo(0, U'†', alt, false, false);
        case -1711218048 : return KeyInfo(0, U'™', alt, false, false);
        case 49850 : return KeyInfo(0, U'º', alt, false, false);
        case 49834 : return KeyInfo(0, U'ª', alt, false, false);
        case -1979653481 : return KeyInfo(0, U'◊', alt, false, false);
        case -1711218040 : return KeyInfo(0, U'√', alt, false, false);
        case -1191124352 : return KeyInfo(0, U'‹', alt, false, false);
        case -1174347136 : return KeyInfo(0, U'›', alt, false, false);
        case -2013207927 : return KeyInfo(0, U'≈', alt, false, false);
        case -2080316799 : return KeyInfo(0, U'⁄', alt, false, false);
        case 50074 : return KeyInfo(0, U'Ú', alt, false, false);
        case 50616 : return KeyInfo(0, U'Ÿ', alt, false, false);
        case 50050 : return KeyInfo(0, U'Â', alt, false, false);
        case 50053 : return KeyInfo(0, U'Å', alt, false, false);
        case 50089 : return KeyInfo(0, U'é', alt, false, false);
        case 49831 : return KeyInfo(0, U'§', alt, false, false);
        case 50088 : return KeyInfo(0, U'è', alt, false, false);
        case 50087 : return KeyInfo(0, U'ç', alt, false, false);
        case 50080 : return KeyInfo(0, U'à', alt, false, false);
        case 49840 : return KeyInfo(0, U'°', alt, false, false);
        case 50105 : return KeyInfo(0, U'ù', alt, false, false);
        case 49827 : return KeyInfo(0, U'£', alt, false, false);
        case -1577000320 : return KeyInfo(0, U'•', alt, false, false);
        case -1090457693 : return KeyInfo(0, U'', alt, false, false);
        case 49844 : return KeyInfo(0, U'´', alt, false, false);
        case 50091 : return KeyInfo(0, U'ë', alt, false, false);
        case -1644109184 : return KeyInfo(0, U'„', alt, false, false);
        case -1677663616 : return KeyInfo(0, U'“', alt, false, false);
        case -1660886400 : return KeyInfo(0, U'”', alt, false, false);
        case -1744772480 : return KeyInfo(0, U'‘', alt, false, false);
        case -1727995264 : return KeyInfo(0, U'’', alt, false, false);
        case 49846 : return KeyInfo(0, U'¶', alt, false, false);
        case 50085 : return KeyInfo(0, U'å', alt, false, false);
        case 49835 : return KeyInfo(0, U'«', alt, false, false);
        case 49851 : return KeyInfo(0, U'»', alt, false, false);
        case 49825 : return KeyInfo(0, U'¡', alt, false, false);
        case 50075 : return KeyInfo(0, U'Û', alt, false, false);
        case 50055 : return KeyInfo(0, U'Ç', alt, false, false);
        case 50049 : return KeyInfo(0, U'Á', alt, false, false);
        case 50104 : return KeyInfo(0, U'ø', alt, false, false);
        case 50072 : return KeyInfo(0, U'Ø', alt, false, false);
        case -1811881344 : return KeyInfo(0, U'—', alt, false, false);
        case -1828658560 : return KeyInfo(0, U'–', alt, false, false);
        case -1543445879 : return KeyInfo(0, U'≤', alt, false, false);
        case -1526668663 : return KeyInfo(0, U'≥', alt, false, false);
        case 50100 : return KeyInfo(0, U'ô', alt, false, false);
        case 50068 : return KeyInfo(0, U'Ô', alt, false, false);
        case -1409228158 : return KeyInfo(0, U'€', alt, false, false);
        case 50073 : return KeyInfo(0, U'Ù', alt, false, false);
        case -1342119296 : return KeyInfo(0, U'‰', alt, false, false);
        case -1644109176 : return KeyInfo(0, U'∞', alt, false, false);
        case 49855 : return KeyInfo(0, U'¿', alt, false, false);
        case -1509891456 : return KeyInfo(0, U'…', alt, false, false);
        case 50103 : return KeyInfo(0, U'÷', alt, false, false);
        case -1610554743 : return KeyInfo(0, U'≠', alt, false, false);
        case 49841 : return KeyInfo(0, U'±', alt, false, false);
      }

       if (KeyInfo::keys.find(std::string(1, toupper((char)key))) != KeyInfo::keys.end())
         return KeyInfo(toupper(key), key, alt, false, key >= 'A' && key <= 'Z');

      return KeyInfo(0, key, alt, false, key >= 'A' && key <= 'Z');
    }
    
    int32 key;
    int32 keyChar;
    bool hasAltModifier;
    bool hasControlModifier;
    bool hasShiftModifier;
    struct KeyKeyChar {
      int32 key;
      int32 keyChar;
      bool alt;
      bool control;
      bool shift;
    };
    static std::map<std::string, KeyKeyChar> keys;
    static InputList inputs;
  };
  
  KeyInfo::InputList KeyInfo::inputs;
  
  std::map<std::string, KeyInfo::KeyKeyChar> KeyInfo::keys = {
    {"\x7F", {8, 0, false, false, false}}, // Backspace
    {"\x9", {9, 9, false, false, false}}, // Tab
    {"^[[Z", {9, 9, false, false, true}}, // Shift Tab
    {"\xC", {12, 12, false, false, false}}, // Clear
    {"\xA", {13, 13, false, false, false}}, // Enter
    {"\x13", {19, 0, false, false, false}}, // Pause
    {"\x14", {20, 0, false, false, false}}, // Capslock
    {"^[", {27, 27, false, false, false}}, // Escape
    {" ", {32, 32, false, false, false}}, // Space
    {"^[[5~", {33, 0, false, false, false}}, // PgUp
    {"^[[6~", {34, 0, false, false, false}}, // PgDown
    {"^[[F", {35, 0, false, false, false}}, // End
    {"^[[H", {36, 0, false, false, false}}, // Home
    {"^[[D", {37, 0, false, false, false}}, // LeftArrow
    {"^[[A", {38, 0, false, false, false}}, // UpArrow
    {"^[[C", {39, 0, false, false, false}}, // RightArrow
    {"^[[B", {40, 0, false, false, false}}, // DownArrow
    //{"", {41, 0, false, false, false}}, // Select
    //{"", {42, 0, false, false, false}}, // Print
    //{"", {43, 0, false, false, false}}, // Execute
    //{"", {44, 0, false, false, false}}, // PrintScreen
    {"^[[2~", {45, 0, false, false, false}}, // Insert
    {"^[[3~", {46, 0, false, false, false}}, // Delete
    //{"", {47, 0, false, false, false}}, // Help
    {"0", {48, 48, false, false, false}}, // D0
    {"1", {49, 49, false, false, false}}, // D1
    {"2", {50, 50, false, false, false}}, // D2
    {"3", {51, 51, false, false, false}}, // D3
    {"4", {52, 52, false, false, false}}, // D4
    {"5", {53, 53, false, false, false}}, // D5
    {"6", {54, 54, false, false, false}}, // D6
    {"7", {55, 55, false, false, false}}, // D7
    {"8", {56, 56, false, false, false}}, // D8
    {"9", {57, 57, false, false, false}}, // D9
    {"A", {65, 65, false, false, true}}, // A
    {"B", {66, 66, false, false, true}}, // B
    {"C", {67, 67, false, false, true}}, // C
    {"D", {68, 68, false, false, true}}, // D
    {"E", {69, 69, false, false, true}}, // E
    {"F", {70, 70, false, false, true}}, // F
    {"G", {71, 71, false, false, true}}, // G
    {"H", {72, 72, false, false, true}}, // H
    {"I", {73, 73, false, false, true}}, // I
    {"J", {74, 74, false, false, true}}, // J
    {"K", {75, 75, false, false, true}}, // K
    {"L", {76, 76, false, false, true}}, // L
    {"M", {77, 77, false, false, true}}, // M
    {"N", {78, 78, false, false, true}}, // N
    {"O", {79, 79, false, false, true}}, // O
    {"P", {80, 80, false, false, true}}, // P
    {"Q", {81, 81, false, false, true}}, // Q
    {"R", {82, 82, false, false, true}}, // R
    {"S", {83, 83, false, false, true}}, // S
    {"T", {84, 84, false, false, true}}, // T
    {"U", {85, 85, false, false, true}}, // U
    {"V", {86, 86, false, false, true}}, // V
    {"W", {87, 87, false, false, true}}, // W
    {"X", {88, 88, false, false, true}}, // X
    {"Y", {89, 89, false, false, true}}, // Y
    {"Z", {90, 90, false, false, true}}, // Z
    //{"", {91, 0, false, false, false}}, // LeftWindows
    //{"", {92, 0, false, false, false}}, // RighttWindows
    //{"", {93, 0, false, false, false}}, // Applications
    //{"", {95, 0, false, false, false}}, // Sleep
    //{"", {96, 0, false, false, false}}, // NumPad0
    //{"", {97, 0, false, false, false}}, // NumPad1
    //{"", {98, 0, false, false, false}}, // NumPad2
    //{"", {99, 0, false, false, false}}, // NumPad3
    //{"", {100, 0, false, false, false}}, // NumPad4
    //{"", {101, 0, false, false, false}}, // NumPad5
    //{"", {102, 0, false, false, false}}, // NumPad6
    //{"", {103, 0, false, false, false}}, // NumPad7
    //{"", {104, 0, false, false, false}}, // NumPad8
    //{"", {105, 0, false, false, false}}, // NumPad9
    {"*", {106, 42, false, false, false}}, // Multiply
    {"+", {107, 43, false, false, false}}, // Add
    //{",", {108, 44, false, false, false}}, // Separator
    {"-", {109, 45, false, false, false}}, // Subtract
    //{".", {110, 46, false, false, false}}, // Decimal
    {"/", {111, 47, false, false, false}}, // Divide
    {"^[OP", {112, 0, false, false, false}}, // F1
    {"^[OQ", {113, 0, false, false, false}}, // F2
    {"^[OR", {114, 0, false, false, false}}, // F3
    {"^[OS", {115, 0, false, false, false}}, // F4
    {"^[[15~", {116, 0, false, false, false}}, // F5
    {"^[[17~", {117, 0, false, false, false}}, // F6
    {"^[[18~", {118, 0, false, false, false}}, // F7
    {"^[[19~", {119, 0, false, false, false}}, // F8
    {"^[[20~", {120, 0, false, false, false}}, // F9
    {"^[[21~", {121, 0, false, false, false}}, // F10
    {"^[[23~", {122, 0, false, false, false}}, // F11
    {"^[[24~", {123, 0, false, false, false}}, // F12
    //{"", {124, 0, false, false, false}}, // F13
    //{"", {125, 0, false, false, false}}, // F14
    //{"", {126, 0, false, false, false}}, // F15
    //{"", {127, 0, false, false, false}}, // F16
    //{"", {128, 0, false, false, false}}, // F17
    //{"", {129, 0, false, false, false}}, // F18
    //{"", {130, 0, false, false, false}}, // F19
    //{"", {131, 0, false, false, false}}, // F20
    //{"", {132, 0, false, false, false}}, // F21
    //{"", {133, 0, false, false, false}}, // F22
    //{"", {133, 0, false, false, false}}, // F23
    //{"", {135, 0, false, false, false}}, // F24
    //{"", {166, 0, false, false, false}}, // BrowseBack
    //{"", {167, 0, false, false, false}}, // BrowseForward
    //{"", {168, 0, false, false, false}}, // BrowseRefresh
    //{"", {169, 0, false, false, false}}, // BrowseStop
    //{"", {170, 0, false, false, false}}, // BrowseSearch
    //{"", {171, 0, false, false, false}}, // BrowseFavorite
    //{"", {172, 0, false, false, false}}, // BrowseHome
    //{"", {173, 0, false, false, false}}, // VolumeMute
    //{"", {174, 0, false, false, false}}, // VolumeDown
    //{"", {175, 0, false, false, false}}, // VolumeUp
    //{"", {176, 0, false, false, false}}, // MediaNext
    //{"", {177, 0, false, false, false}}, // MediaPrevious
    //{"", {178, 0, false, false, false}}, // MediaStop
    //{"", {179, 0, false, false, false}}, // MediaPlay
    {"a", {65, U'a', false, false, false}}, // a
    {"b", {66, U'b', false, false, false}}, // b
    {"c", {67, U'c', false, false, false}}, // c
    {"d", {68, U'd', false, false, false}}, // d
    {"e", {69, U'e', false, false, false}}, // e
    {"f", {70, U'f', false, false, false}}, // f
    {"g", {71, U'g', false, false, false}}, // g
    {"h", {72, U'h', false, false, false}}, // h
    {"i", {73, U'i', false, false, false}}, // i
    {"j", {74, U'j', false, false, false}}, // j
    {"k", {75, U'k', false, false, false}}, // k
    {"l", {76, U'l', false, false, false}}, // l
    {"m", {77, U'm', false, false, false}}, // m
    {"n", {78, U'n', false, false, false}}, // n
    {"o", {79, U'o', false, false, false}}, // o
    {"p", {80, U'p', false, false, false}}, // p
    {"q", {81, U'q', false, false, false}}, // q
    {"r", {82, U'r', false, false, false}}, // r
    {"S", {83, U's', false, false, false}}, // s
    {"t", {84, U't', false, false, false}}, // T
    {"u", {85, U'u', false, false, false}}, // u
    {"v", {86, U'v', false, false, false}}, // v
    {"w", {87, U'w', false, false, false}}, // w
    {"x", {88, U'x', false, false, false}}, // x
    {"y", {89, U'y', false, false, false}}, // y
    {"z", {90, U'z', false, false, false}}, // z
  };

  static const char* ColorToEscapeBackColorStr(int32 color) {
    switch (color) {
      case 0 : return "\033[40m"; break; // Black
      case 1 : return "\033[44m"; break; // DarkBlue
      case 2 : return "\033[42m"; break; // DarkGreen
      case 3 : return "\033[46m"; break; // DarkCyan
      case 4 : return "\033[41m"; break; // DarkRed
      case 5 : return "\033[45m"; break; // DarkMagenta
      case 6 : return "\033[43m"; break; // DarkYellow
      case 7 : return "\033[47m"; break; // Gray
      case 8 : return "\033[101m"; break; // DarkGray
      case 9 : return "\033[104m"; break; // Blue
      case 10 : return "\033[102m"; break; // Green
      case 11 : return "\033[106m"; break; // Cyan
      case 12 : return "\033[101m"; break; // Red
      case 13 : return "\033[105m"; break; // Magena
      case 14 : return "\033[103m"; break; // Yellow
      case 15 : return "\033[107m"; break; // White
      default : return "\033[49m"; break; // Default
    }
  }
  
  static const char* ColorToEscapeForeColorStr(int32 color) {
    switch (color) {
      case 0 : return "\033[30m"; break; // Black
      case 1 : return "\033[34m"; break; // DarkBlue
      case 2 : return "\033[32m"; break; // DarkGreen
      case 3 : return "\033[36m"; break; // DarkCyan
      case 4 : return "\033[31m"; break; // DarkRed
      case 5 : return "\033[35m"; break; // DarkMagenta
      case 6 : return "\033[33m"; break; // DarkYellow
      case 7 : return "\033[37m"; break; // Gray
      case 8 : return "\033[90m"; break; // DarkGray
      case 9 : return "\033[94m"; break; // Blue
      case 10 : return "\033[92m"; break; // Green
      case 11 : return "\033[96m"; break; // Cyan
      case 12 : return "\033[91m"; break; // Red
      case 13 : return "\033[95m"; break; // Magena
      case 14 : return "\033[93m"; break; // Yellow
      case 15 : return "\033[97m"; break; // White
      default : return "\033[39m"; break; // Default
    }
  }
  }

#ifndef KIOCSOUND
const int32 KIOCSOUND = 0x4B2F;
#endif

void Console::Beep(int32 frequency, int32 duration) {
  int32 fd = open("/dev/console", O_WRONLY);
  ioctl(fd, KIOCSOUND, (int32)(1193180/frequency));
  usleep(1000*duration);
  ioctl(fd, KIOCSOUND, 0);
  close(fd);
}

void Console::Clrscr() {
  if (Terminal::IsAnsiSupported())
    printf("\x1b[H\x1b[2J");
}

int32 Console::GetBackgroundColor() {
  return backColor;
}

int32 Console::GetCursorSize() {
  return 100;
}

bool Console::GetCursorVisible() {
  return cursorVisible;
}

int32 Console::GetForegroundColor() {
  return foreColor;
}

void Console::Gotoxy(int32 x, int32 y) {
  if (Terminal::IsAnsiSupported())
    printf("\x1b[%d;%df", y, x);
}

bool Console::KeyAvailable() {
  return KeyInfo::KeyAvailable();
}

void Console::ReadKey(int32& keyChar, int32& keyCode, bool& alt, bool& shift, bool& ctrl) {
  KeyInfo keyInfo = KeyInfo::Read();
  keyChar = static_cast<int32>(keyInfo.KeyChar());
  keyCode = static_cast<int32>(keyInfo.Key());
  alt = keyInfo.HasAltModifier();
  ctrl = keyInfo.HasControlModifier();
  shift = keyInfo.HasShiftModifier();
}

void Console::SetBackgroundColor(int32 color) {
  backColor = color;
  if (Terminal::IsAnsiSupported())
    printf("%s", ColorToEscapeBackColorStr(backColor));
}

void Console::SetCursorSize(int32 size) {
  
}

void Console::SetCursorVisible(bool visible) {
  cursorVisible = visible;
  if (Terminal::IsAnsiSupported()) {
    if (visible)
      printf("\x1b[?25h");
    else
      printf("\x1b[?25l");
  }
}

void Console::SetEchoVisible(bool visible) {
  termios settings;
  tcgetattr(0, &settings);
  if (visible)
    settings.c_lflag |= (ICANON|ECHO);
  else
    settings.c_lflag &= ~(ICANON|ECHO);
  tcsetattr(0, TCSANOW, &settings);
}

void Console::SetForegroundColor(int32 color) {
  foreColor = color;
  if (Terminal::IsAnsiSupported())
    printf("%s", ColorToEscapeForeColorStr(foreColor));
}

void Console::Wherexy(int32& x, int32& y) {
  if (Terminal::IsAnsiSupported()) {
    printf("\x1b[6n");
    fflush(stdout);
    terminal.Getch();
    terminal.Getch();
    
    char c;
    std::string str;
     
    while ((c = terminal.Getch()) != ';')
      str.push_back(c);
    y = atoi(str.c_str());

    str.clear();
    while ((c = terminal.Getch()) != 'R')
      str.push_back(c);
    x = atoi(str.c_str());
  }
}

void Console::GetBufferSize(int32& w, int32& h) {
  w = 80;
  h = 25;
}

int32 Console::GetInputCodePage() {
  return 65001;
}

int32 Console::GetOutputCodePage() {
  return 65001;
}

bool Console::SetInputCodePage(int32 codePage) {
  return true;
}

bool Console::SetOutputCodePage(int32 codePage) {
  return true;
}

#endif
