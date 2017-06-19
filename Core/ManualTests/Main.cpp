#include <Pcf/System/Collections/ArrayList.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/System/Uri.hpp>
#include <Pcf/Event.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace System::Collections;

namespace ManualTests {
  using MyEventHandler = delegate<void, const object&, const EventArgs>;

  class Publisher : public object {
  public:
    event<Publisher, MyEventHandler> MyEvent;
    
    void RaiseMyEvent() {
      this->MyEvent.Invoke(*this, EventArgs());
    }
  };
  
  class Program {
  public:
    static void Main() {
      Publisher publisher;
      
      publisher.MyEvent += pcf_delegate(const object& sender, const EventArgs& e) {
        Console::WriteLine("On myEvent");
      };
      
      publisher.RaiseMyEvent();
    }
  };
}

pcf_startup (ManualTests::Program)
