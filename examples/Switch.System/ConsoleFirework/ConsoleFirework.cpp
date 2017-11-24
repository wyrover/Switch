#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Firework _abstract {
  public:
    Firework(int x, int y, ConsoleColor color, int delay) : x(x), y(y), color(color), delay(delay) {}
    Firework(const Firework& firework) : x(firework.x), y(firework.y), color(firework.color), delay(firework.delay) {}
    
    _property<int, _readonly> Delay {
      _get {return this->delay;}
    };
    
    virtual void Paint() const = 0;
    
  protected:
    static void Write(int x, int y, const string& str) {
      System::Console::SetCursorPosition(x, y);
      System::Console::Write(str);
    }
    
    int x;
    int y;
    System::ConsoleColor color;
    int delay;
  };
  
  class FireworkStart : public Firework {
  public:
    FireworkStart(int x, int y, ConsoleColor color, int speed) : Firework(x, y, color, speed) {}
    explicit  FireworkStart(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->color;
      Write(this->x, this->y, "+");
    }
  };
  
  class FireworkExploded : public Firework {
  public:
    FireworkExploded(int x, int y, ConsoleColor color, int speed) : Firework(x, y, color, speed) {}
    explicit  FireworkExploded(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->color;
      Write(this->x - 1, this->y - 1, " - ");
      Write(this->x - 1, this->y,     "-+-");
      Write(this->x - 1, this->y + 1, " - ");
    }
  };
  
  class FireworkStartExpanded1 : public Firework {
  public:
    FireworkStartExpanded1(int x, int y, ConsoleColor color, int speed) : Firework(x, y, color, speed) {}
    explicit  FireworkStartExpanded1(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->color;
      Write(this->x - 2, this->y - 2, " --- ");
      Write(this->x - 2, this->y - 1, "-+++-");
      Write(this->x - 2, this->y,     "-+#+-");
      Write(this->x - 2, this->y + 1, "-+++-");
      Write(this->x - 2, this->y + 2, " --- ");
    }
  };
  
  class FireworkStartExpanded2 : public Firework {
  public:
    FireworkStartExpanded2(int x, int y, ConsoleColor color, int speed) : Firework(x, y, color, speed) {}
    explicit  FireworkStartExpanded2(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->color;
      Write(this->x - 2, this->y - 2, " +++ ");
      Write(this->x - 2, this->y - 1, "++#++");
      Write(this->x - 2, this->y,     "-# #-");
      Write(this->x - 2, this->y + 1, "++#++");
      Write(this->x - 2, this->y + 2, " +++ ");
    }
  };
  
  class FireworkStartExpanded3 : public Firework {
  public:
    FireworkStartExpanded3(int x, int y, ConsoleColor color, int speed) : Firework(x, y, color, speed) {}
    explicit  FireworkStartExpanded3(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->color;
      Write(this->x - 2, this->y - 2, "  #  ");
      Write(this->x - 2, this->y - 1, "## ##");
      Write(this->x - 2, this->y,     "#   #");
      Write(this->x - 2, this->y + 1, "## ##");
      Write(this->x - 2, this->y + 2, "  #  ");
    }
  };
  
  class FireworkStartExpanded4 : public Firework {
  public:
    FireworkStartExpanded4(int x, int y, ConsoleColor color, int speed) : Firework(x, y, color, speed) {}
    explicit  FireworkStartExpanded4(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->color;
      Write(this->x - 2, this->y - 2, " # # ");
      Write(this->x - 2, this->y - 1, "#   #");
      Write(this->x - 2, this->y,     "     ");
      Write(this->x - 2, this->y + 1, "#   #");
      Write(this->x - 2, this->y + 2, " # # ");
    }
  };
  
  class FireworkEnd : public Firework {
  public:
    FireworkEnd(int x, int y, ConsoleColor color, int speed) : Firework(x, y, color, speed) {}
    explicit  FireworkEnd(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->color;
      Write(this->x - 2, this->y - 2, "     ");
      Write(this->x - 2, this->y - 1, "     ");
      Write(this->x - 2, this->y,     "     ");
      Write(this->x - 2, this->y + 1, "     ");
      Write(this->x - 2, this->y + 2, "     ");
    }
  };
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Console::CursorVisible = false;
      Console::Clear();
      
      Random rand;
      System::Collections::Generic::List<_<Firework>> fireworks;
      Array<ConsoleColor> colors = {ConsoleColor::Blue, ConsoleColor::Green, ConsoleColor::Cyan, ConsoleColor::Red, ConsoleColor::Magenta, ConsoleColor::Yellow, ConsoleColor::White};
      
      while (!Console::KeyAvailable) {
        fireworks.Add(_new<FireworkStart>(rand.Next(2, Console::WindowWidth - 2), rand.Next(2, Console::WindowHeight - 2), colors[rand.Next(colors.Length)], rand.Next(1, 5)));
        
        System::Collections::Generic::List<_<Firework>> fireworksToRemove;
        for (_<Firework>& firework : fireworks) {
          if (is<FireworkEnd>(firework))
            fireworksToRemove.Add(firework);
          Explode(firework);
        }
        fireworksToRemove.ForEach(_delegate(_<Examples::Firework> firework) {fireworks.Remove(firework);});
        
        System::Threading::Thread::Sleep(100);
      }
      
      Console::ResetColor();
      Console::Clear();
      Console::CursorVisible = true;
    }
    
    static void Explode(_<Firework>& firework) {
      firework->Paint();
      if (is<FireworkStartExpanded4>(firework)) firework = _new<FireworkEnd>(*firework);
      if (is<FireworkStartExpanded3>(firework)) firework = _new<FireworkStartExpanded4>(*firework);
      if (is<FireworkStartExpanded2>(firework)) firework = _new<FireworkStartExpanded3>(*firework);
      if (is<FireworkStartExpanded1>(firework)) firework = _new<FireworkStartExpanded2>(*firework);
      if (is<FireworkExploded>(firework)) firework = _new<FireworkStartExpanded1>(*firework);
      if (DateTime::Now().Ticks % firework->Delay == 0 && is<FireworkStart>(firework)) firework = _new<FireworkExploded>(*firework);
    }
  };
}

_startup(Examples::Program);
