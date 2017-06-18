#include <Pcf/System/Collections/ArrayList.hpp>
#include <Pcf/System/Console.hpp>
#include <Pcf/System/Uri.hpp>
#include <Pcf/Startup.hpp>

using namespace System;
using namespace System::Collections;

namespace Pcf {
  //template<const object&, typename... Arguments>
  template<typename TDelegate>
  class event : public object {
  public:
    /// @cond
    event(ref<object> parent) : parent(parent) {}
    event(ref<object> parent, const TDelegate& delegate) : parent(parent), delegate(delegate) {}
    template<typename Function> event(ref<object> parent, Function function) : parent(parent), delegate(function) {}
    template<typename Object, typename Function> event(ref<object> parent, const Object& object, Function function) : parent(parent), delegate(object, function) {}
    /// @endcond
    
    template<typename TResult=void, typename ... TArguments>
    TResult Invoke(const object& sender, TArguments... args) {
      //std::assert(&sender != this, "must be invoked by creator");
      if (&sender != this)
        throw System::InvalidOperationException(pcf_current_information);
      return this->delegate.Invoke(sender, args...);
    }
    
    event& operator +=(const event& event) {
      this->delegate = TDelegate::Combine(this->delegate, delegate);
      return *this;
    }
    
    template<typename Fn>
    event& operator +=(Fn function) {
      this->delegate = TDelegate::Combine(this->delegate, TDelegate(function));
      return *this;
    }
    
  private:
    event() = delete;
    ref<object> parent;
    TDelegate delegate;
  };
}

namespace ManualTests {
  class Publisher : public object {
  public:
    using MyEventHandler = delegate<void, const object&, const EventArgs>;
    
    event<MyEventHandler> myEvent {*this};
    
    void RaiseMyEvent() {
      this->myEvent.Invoke(*this, EventArgs());
    }
    
  };
  
  class Program {
  public:
    static void Main() {
      Publisher publisher;
      
      publisher.myEvent += pcf_delegate(const object& sender, const EventArgs& e) {
        Console::WriteLine("On myEvent");
      };
      
      //publisher.myEvent.Invoke(object(), EventArgs());
      publisher.RaiseMyEvent();
      
    }
  };
}

pcf_startup (ManualTests::Program)
