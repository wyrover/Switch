#include <fstream>
#include <stack>
#include <vector>

#include "CoreApi.h"

bool __OS::CoreApi::UnicodeCharacters::ValidateCodePoint(uint32 codePoint) {
  if (codePoint > 0x0010FFFFu) return false;
  if (codePoint >= 0xD800u && codePoint <= 0xDFFFu) return false;
  return true;
}

#include "unicode.auto"

static const int32 UnicodeIsAlpha = 1;
static const int32 UnicodeIsDigit = 2;
static const int32 UnicodeIsPunct = 3;

using symbol = unsigned char;

const int32 npos = -1;
const int32 nstatus = 0;

/*
System::Array<symbol> CodePointHexEncodingFunction(uint32 codePoint) {
union CPBytes{
uint32 codePoint;
byte bytes[4];
} encoding;

encoding.codePoint = 0xFF;
bool bigEndian = encoding.bytes[0] != 0xFF;

System::Array<symbol> n32(8);

encoding.codePoint = codePoint;
int index = 0;
if (bigEndian)
for (int i=0;i<4;i++) {
n32[index++] = encoding.bytes[i] >> 4;
n32[index++] = encoding.bytes[i] & 0x0F;
}
else
for (int i=3;i>=0;i--) {
n32[index++] = encoding.bytes[i] >> 4;
n32[index++] = encoding.bytes[i] & 0x0F;
}

return n32;
}
*/

System::Array<symbol> CodePointHexEncodingFunction(uint32 codePoint) {
  System::Array<symbol> w(8);
  w[0] = static_cast<symbol>((codePoint >> 28) & 0x0F);
  w[1] = static_cast<symbol>((codePoint >> 24) & 0x0F);
  w[2] = static_cast<symbol>((codePoint >> 20) & 0x0F);
  w[3] = static_cast<symbol>((codePoint >> 16) & 0x0F);
  w[4] = static_cast<symbol>((codePoint >> 12) & 0x0F);
  w[5] = static_cast<symbol>((codePoint >> 8) & 0x0F);
  w[6] = static_cast<symbol>((codePoint >> 4) & 0x0F);
  w[7] = static_cast<symbol>((codePoint) & 0x0F);
  return w;
}


namespace {
  template<int N, typename Offset, typename Status>
  struct State {
  public:
    State(Status s = nstatus) {
      status = s;
      for (symbol sym = 0; sym < N; sym += 1)
        next[sym] = npos;
    }

    State(const State& s) {
      status = s.status;
      for (symbol sym = 0; sym < N; sym += 1)
        next[sym] = s.next[sym];
    }

    State& operator =(const State& s) {
      status = s.status;
      for (symbol sym = 0; sym < N; sym += 1)
        next[sym] = s.next[sym];
      return *this;
    }

    bool Equals(const State<N, Offset, Status>& other, std::vector<Offset>& translate) const {
      if (status != other.status)
        return false;
      for (symbol s = 0; s < N; s += 1)
        if (next[s] != translate[other.next[s]])
          return false;
      return true;
    }

    Offset next[N];
    Status status;
  };

  template<int N, typename Offset = int16, typename Status = sbyte>
  class Automaton {
  public:
    Automaton() {
      initial = npos;
      maxDepth = 0;
      well = npos;
    }

    Automaton(const Automaton& a) {
      states = a.states;
      well = a.well;
      initial = a.initial;
      maxDepth = a.maxDepth;
    }

    Automaton& operator =(const Automaton& a) {
      states = a.states;
      well = a.well;
      initial = a.initial;
      maxDepth = a.maxDepth;
      return *this;
    }

    void Add(uint32 codePoint, Status status) {
      System::Array<symbol> symbols = CodePointHexEncodingFunction(codePoint);
      Add(symbols.Data(), 8, status);
    }

    void Add(const symbol* symbols, int32 size, Status status) {
      Offset state;

      if (maxDepth < size) maxDepth = size;

      if (initial == npos) {
        state = AddState(size == 0 ? status : nstatus);
        initial = state;
      } else {
        state = initial;
      }

      for (int32 i = 0; i < size; i += 1) {
        const byte& s = symbols[i];
        Offset next = GetNext(state, s);
        if (next == npos) {
          next = AddState((i == size - 1) ? status : nstatus);
          SetNext(state, s, next);
        }
        state = next;
      }
    }

    void AddPadding(symbol pad_symbol) {
      if (initial != npos) {
        states[initial].next[pad_symbol] = initial;
      }
    }

    Status Get(uint32 codePoint) {
      System::Array<symbol> symbols = CodePointHexEncodingFunction(codePoint);
      return Get(symbols.Data(), 8);
    }

    Status Get(symbol* symbols, int32 size) const {
      if (initial == -1)
        return nstatus;

      Offset state = initial;
      for (int32 k = 0; k < size; k++) {
        Offset next = GetNext(state, symbols[k]);
        if (next == npos) return nstatus;
        state = next;
      }

      return GetStatus(state);
    }

    Offset Size() const { return static_cast<Offset>(states.size()); }

    /*    void Debug() {
    Console::WriteLine("------------------------------------------------------");
    Console::WriteLine($ Size() + " states.");
    for (Offset i = 0 ; i < Size() ; i++ ) {
    Status status = GetStatus(i);
    if (initial == i) Console::Write("> ");
    else Console::Write("  ");
    Console::Write($ i + " [" + String((status==nstatus)? "*": Int32(status).ToString()) +"]");
    for (symbol k = 0; k < N; k += 1) {
    Offset next = GetNext(i,k);
    if (next != npos) {
    char c = (k < 10)? k+'0' : (k-10)+'a';
    Console::Write($ " (" + Char(c) + ":" + Int32(next) + ")");
    }
    }
    Console::WriteLine("");
    }
    }*/

    void Minimize() {
      if (initial == npos) return;

      Complete();

      std::vector< State<N, Offset, Status>> newStates;
      std::vector<Offset> translate;
      translate.resize(states.size(), -1);
      std::vector< std::vector<Offset>> depthTable;
      BuildDepthTable(depthTable);

      // for each depth d
      for (size_t d = 0; d < depthTable.size(); d++) {
        // for each state i of depth d
        for (size_t i = 0; i < depthTable[d].size(); i++) {
          Offset state = depthTable[d][i];
          Offset newState = FindState(newStates, state, translate);
          if (newState == npos)
            newState = TransferState(newStates, state, translate);
          else
            translate[state] = newState;
        }
      }

      states = newStates;
      initial = translate[initial];
    }

    void Complete() {
      for (Offset i = 0; i < Size(); i++) {
        for (symbol s = 0; s < N; s += 1) {
          Offset next = states[i].next[s];
          if (next == npos) {
            if (well == npos) {
              well = AddState(nstatus);
              for (symbol n = 0; n < N; n += 1)
                states[well].next[n] = well;
            }
            states[i].next[s] = well;
          }
        }
      }
    }

    void GetDescription() const {
      std::fstream file("d:\\unicode.auto", std::ios::binary | std::ios::out);
      file << "static int16 unicodeData[] = { " << Size() << ", " << initial << ", " << well;
      for (Offset i = 0; i < Size(); i += 1) {
        file << ",\n    ";
        file << Byte(GetStatus(i));
        for (symbol s = 0; s < N; s += 1) {
          file << ", " << GetNext(i, s);
        }
      }
      file << "\n};";
      file.close();
    }

    template<int32 length>
    void FromDescription(const Offset(&data)[length]) {
      int32 index;
      states.clear();
      states.resize(data[0]);
      initial = data[1];
      well = data[2];
      index = 3;
      for (Offset i = 0; i< Size(); i++) {
        states[i].status = static_cast<Status>(data[index++]);
        for (symbol s = 0; s < N; s += 1) {
          states[i].next[s] = data[index++];
        }
      }
    }

  private:
    Offset GetNext(Offset state, symbol s) const {
      return states[state].next[s];
    }

    void SetNext(Offset state, symbol s, Offset next) {
      states[state].next[s] = next;
    }

    Status GetStatus(Offset index) const {
      return states[index].status;
    }

    Offset AddState(Status status) {
      states.push_back(State<N, Offset, Status>(status));
      return static_cast<Offset>(states.size() - 1);
    }

    void BuildDepthTable(std::vector< std::vector<Offset>>& depthTable) const {
      std::vector<int32> depths;
      depths.resize(states.size(), npos);
      std::stack< std::pair<Offset, int32>> stack;
      StackPush(stack, initial, maxDepth + 1);

      while (!stack.empty()) {
        Offset state = stack.top().first;
        int32 depth = stack.top().second;
        stack.pop();

        if (depths[state] != npos) {
          if (depths[state] > depth)
            depths[state] = depth;
          continue;
        }

        depths[state] = depth;

        for (symbol s = 0; s < N; s += 1) {
          Offset next = GetNext(state, s);
          if (next != npos)
            StackPush(stack, next, depth - 1);
        }
      }

      depthTable.resize(maxDepth + 2);
      for (Offset i = 0; i < Size(); i++) {
        depthTable[depths[i]].push_back(i);
      }
    }

    void StackPush(std::stack< std::pair<Offset, int32>>& stack, Offset state, int32 depth) const {
      stack.push(std::pair<Offset, int32>(state, depth));
    }

    Offset FindState(const std::vector< State<N, Offset, Status>>& newStates, Offset state, std::vector<Offset>& translate) const {
      // for each new state
      for (Offset i = 0; i < static_cast<Offset>(newStates.size()); i++) {
        if (newStates[i].Equals(states[state], translate))
          return i;
      }
      return npos;
    }

    Offset TransferState(std::vector< State<N, Offset, Status>>& newStates, Offset state, std::vector<Offset>& translate) const {
      Offset index = static_cast<Offset>(newStates.size());
      translate[state] = index;
      newStates.push_back(State<N, Offset, Status>(GetStatus(state)));
      for (symbol k = 0; k < N; k++)
        newStates[index].next[k] = translate[GetNext(state, k)];
      return index;
    }

    std::vector< State<N, Offset, Status>> states;
    int32 maxDepth;
    Offset initial, well;
  };

  using UnicodeAutomaton = Automaton<16, int16, byte>;

  //used for debugging
  /*
  static symbol ToSymbol(char s) {
  if (s >= '0' && s <= '9')
  return s - '0';
  if (s >= 'a' && s <= 'f')
  return (s - 'a') + 10;
  if (s >= 'A' && s <= 'F')
  return (s - 'A') + 10;
  throw -1;
  }

  static char FromSymbol(symbol s) {
  if (s < 10)
  return s + '0';
  return (s - 10) + 'A';
  }
  */
  static UnicodeAutomaton& GetUnicodeCharacters() {
    static UnicodeAutomaton automaton;
    if (automaton.Size() == 0) {
      automaton.FromDescription(unicodeData);
    }
    return automaton;
  }
}

bool __OS::CoreApi::UnicodeCharacters::IsAlpha(uint32 codePoint) {
  UnicodeAutomaton& a = GetUnicodeCharacters();
  System::Array<symbol> word = CodePointHexEncodingFunction(codePoint);
  return a.Get((symbol*)word.Data(), 8) == UnicodeIsAlpha;
}

bool __OS::CoreApi::UnicodeCharacters::IsDigit(uint32 codePoint) {
  UnicodeAutomaton& a = GetUnicodeCharacters();
  System::Array<symbol> word = CodePointHexEncodingFunction(codePoint);
  return a.Get((symbol*)word.Data(), 8) == UnicodeIsDigit;
}

bool __OS::CoreApi::UnicodeCharacters::IsPunctuation(uint32 codePoint) {
  UnicodeAutomaton& a = GetUnicodeCharacters();
  System::Array<symbol> word = CodePointHexEncodingFunction(codePoint);
  return a.Get((symbol*)word.Data(), 8) == UnicodeIsPunct;
}
