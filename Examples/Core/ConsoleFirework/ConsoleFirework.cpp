#include <Switch/Switch>

using namespace System;

namespace Examples {
  class Firework : public object {
  public:
    Firework(System::Drawing::Point location, ConsoleColor color, int speed) : location(location), color(color), speed(speed) {}
    Firework(const Firework& firework) : location(firework.location), color(firework.color) {}
    
    _property<System::ConsoleColor, _readonly> Color {
      _get {return this->color;}
    };
    
    _property<System::Drawing::Point, _readonly> Location {
      _get {return this->location;}
    };
    
    _property<int, _readonly> Speed {
      _get {return this->speed;}
    };
    
    virtual void Paint() const = 0;
    
    static void Explode(_<Firework>& firexork);
    
  private:
    System::Drawing::Point location;
    System::ConsoleColor color;
    int speed = 1;
  };
  
  class FireworkStart : public Firework {
  public:
    FireworkStart(System::Drawing::Point location, ConsoleColor color, int speed) : Firework(location, color, speed) {}
    FireworkStart(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
    }
  };
  
  class FireworkExploded : public Firework {
  public:
    FireworkExploded(System::Drawing::Point location, ConsoleColor color, int speed) : Firework(location, color, speed) {}
    FireworkExploded(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->Color;
      System::Console::SetCursorPosition(this->Location().X, this->Location().Y - 1);
      System::Console::Write("-");
      System::Console::SetCursorPosition(this->Location().X - 1, this->Location().Y);
      System::Console::Write("-+-");
      System::Console::SetCursorPosition(this->Location().X, this->Location().Y + 1);
      System::Console::Write("-");
    }
  };
  
  class FireworkEnd : public Firework {
  public:
    FireworkEnd(System::Drawing::Point location, ConsoleColor color, int speed) : Firework(location, color, speed) {}
    FireworkEnd(const Firework& firework) : Firework(firework) {}
    
    void Paint() const override {
      System::Console::ForegroundColor = this->Color;
      System::Console::SetCursorPosition(this->Location().X, this->Location().Y - 1);
      System::Console::Write(" ");
      System::Console::SetCursorPosition(this->Location().X - 1, this->Location().Y);
      System::Console::Write("   ");
      System::Console::SetCursorPosition(this->Location().X, this->Location().Y + 1);
      System::Console::Write(" ");
    }
  };
  
  void Firework::Explode(_<Firework>& firework) {
    static int counter = 1;
    if (counter % firework->Speed == 0) {
      if (is<FireworkExploded>(firework)) firework = _new<FireworkEnd>(*firework);
      if (is<FireworkStart>(firework)) firework = _new<FireworkExploded>(*firework);
      firework->Paint();
    }
    ++counter;
  }
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Random rand;
      Console::Clear();
      Console::CursorVisible = false;
      System::Collections::Generic::List<_<Firework>> fireworks;
      while(!Console::KeyAvailable) {
        _<Firework> firework = _new<FireworkStart>(System::Drawing::Point(rand.Next(2, Console::WindowWidth-2), rand.Next(2, Console::WindowHeight-2)), (ConsoleColor)rand.Next(9, 16), rand.Next(20, 100));
        firework->Paint();
        fireworks.Add(firework);
        
        System::Collections::Generic::List<_<Firework>> fireworksToRemove;
        for (_<Firework>& firework : fireworks) {
          if (is<FireworkEnd>(firework))
            fireworksToRemove.Add(firework);
          Firework::Explode(firework);
        }

        for (_<Firework> firework : fireworksToRemove)
          fireworks.Remove(firework);

        System::Threading::Thread::Sleep(100);
      }
      
      Console::SetCursorPosition(0, Console::WindowHeight-1);
      System::Console::ResetColor();
      Console::Clear();
      Console::CursorVisible = true;
    }
  };
}

_startup (Examples::Program)
