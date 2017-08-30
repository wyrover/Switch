#include <Switch/System/Delegate.hpp>
#include <Switch/System/ConsoleKey.hpp>
#include <Switch/System/ConsoleColor.hpp>
#include <Switch/System/ConsoleModifiers.hpp>
#include <Switch/System/ConsoleKey.hpp>
#include <Switch/System/EventArgs.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class NewEventArgs : public EventArgs {
  public:
    NewEventArgs(Int32 number, const string& args) : number(number), args(args) {}
    
    Int32 GetNumber() const { return this->number; }
    const string& GetArgs() const { return this->args; }
    
  private:
    int32 number;
    string args;
  };
  
  class DelegateSender;
  using NewEventHandler = Delegate<void, const DelegateSender&, const NewEventArgs&>;
  
  class DelegateMessage : public object {
  public:
    DelegateMessage(Int32 number, const string& message) : number(number), message(message) {}
    
    Int32 GetNumber() const { return this->number; }
    string GetMessage() const { return this->message; }
    
  private:
    int32 number;
    string message;
  };
  
  class DelegateSender : public object {
  public:
    DelegateSender() : message(0, "Message0") {}
    DelegateSender(const DelegateMessage& message) : message(message) {}
    NewEventHandler Notify;
    void Send(const NewEventArgs& eventArgs) {
      this->message = DelegateMessage(1, "Message1");
      Notify(*this, eventArgs);
    }
    const DelegateMessage& GetMessage() const { return  this->message; }
    
  private:
    DelegateMessage message;
  };
  
  class DelegateReceiver : public object {
  public:
    DelegateReceiver(int32 id) : id(id) {}
    void OnNotify(const DelegateSender& sender, const NewEventArgs& args) {
      DelegateMessage message = sender.GetMessage();
      
      EXPECT_EQ(message.GetNumber(), 1);
      EXPECT_EQ(message.GetMessage(), "Message1");
      
      EXPECT_EQ(args.GetNumber(), 10);
      EXPECT_EQ(args.GetArgs(), "Argument10");
      
      EXPECT_TRUE((this->id==1)||(this->id==2));
      NotifyNumber++;
    }
    
    static int32 NotifyNumber;
    
  private:
    int32 id;
  };
  
  int32 DelegateReceiver::NotifyNumber = 0;
  
  TEST(Delegate, Ctor) {
    DelegateReceiver::NotifyNumber = 0;
    DelegateSender   sender;
    DelegateReceiver receiver1(1);
    DelegateReceiver receiver2(2);
    
    sender.Notify += NewEventHandler(receiver1, &DelegateReceiver::OnNotify);
    sender.Notify += NewEventHandler(receiver2, &DelegateReceiver::OnNotify);
    sender.Send(NewEventArgs(10, "Argument10"));
    EXPECT_EQ(2, DelegateReceiver::NotifyNumber);
    
    sender.Notify -= NewEventHandler(receiver1, &DelegateReceiver::OnNotify);
    sender.Send(NewEventArgs(10, "Argument10"));
    EXPECT_EQ(3, DelegateReceiver::NotifyNumber);
    
    sender.Notify -= NewEventHandler(receiver2, &DelegateReceiver::OnNotify);
    EXPECT_NO_THROW(sender.Send(NewEventArgs(10, "Argument10")));
    EXPECT_EQ(3, DelegateReceiver::NotifyNumber);
  }
  
  class DelegateClass : public object
  {
  public:
    DelegateClass() : MemberValue(0)  {}
    
    void MemberFctNoArgNoReturn() { MemberValue= 1; }
    static void StaticFctNoArgNoReturn() { StaticValue= 2; }
    
    Int32 MemberFctNoArgReturnInt32() { return 3; }
    static Int32 StaticFctNoArgReturnInt32() { return 4; }
    
    void MemberFctArgInt32NoReturn(Int32 a1) { MemberValue= a1; }
    static void StaticFctArgInt32NoReturn(Int32 a1) { StaticValue= a1; }
    
    string MemberFctArgInt32ReturnString(Int32 a1) { return "{" + string::Join(", ", {a1.ToString()}) + "}"; }
    static string StaticFctArgInt32ReturnString(Int32 a1) { return "{" + string::Join(", ", {a1.ToString()}) + "}"; }
    
    string MemberFctArgInt32StringReturnString(Int32 a1, const string& a2) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString()}) + "}"; }
    static string StaticFctArgInt32StringReturnString(Int32 a1, const string& a2) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrReturnString(Int32 a1, const string& a2, IntPtr a3) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrReturnString(Int32 a1, const string& a2, IntPtr a3) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrStringReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrStringReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrStringBooleanReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrStringBooleanReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrStringBooleanStringReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrStringBooleanStringReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7, ConsoleColor a8) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString(), Enum<ConsoleColor>(a8).ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7, ConsoleColor a8) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString(), Enum<ConsoleColor>(a8).ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7, ConsoleColor a8, Enum<ConsoleModifiers> a9) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString(), Enum<ConsoleColor>(a8).ToString(), a9.ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7, ConsoleColor a8, Enum<ConsoleModifiers> a9) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString(), Enum<ConsoleColor>(a8).ToString(), a9.ToString()}) + "}"; }
    
    string MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersByteReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7, ConsoleColor a8, Enum<ConsoleModifiers> a9, Byte a10) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString(), Enum<ConsoleColor>(a8).ToString(), a9.ToString(), a10.ToString()}) + "}"; }
    static string StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersByteReturnString(Int32 a1, const string& a2, IntPtr a3, const string& a4, Boolean a5, const string& a6, ConsoleKey a7, ConsoleColor a8, Enum<ConsoleModifiers> a9, Byte a10) { return "{" + string::Join(", ", {a1.ToString(), a2.ToString(), a3.ToString(), a4.ToString(), a5.ToString(), a6.ToString(), Enum<ConsoleKey>(a7).ToString(), Enum<ConsoleColor>(a8).ToString(), a9.ToString(), a10.ToString()}) + "}"; }
    
    static Int32 StaticValue;
    Int32 MemberValue;
  };
  
  Int32 DelegateClass::StaticValue = 0;
  
  TEST(Delegate, CallMemberFctNoArgNoReturn) {
    DelegateClass dc;
    Delegate<void> d(dc, &DelegateClass::MemberFctNoArgNoReturn);
    d();
    EXPECT_EQ(1, dc.MemberValue);
  }
  
  TEST(Delegate, CallStaticFctNoArgNoReturn) {
    Delegate<void> d(&DelegateClass::StaticFctNoArgNoReturn);
    d();
    EXPECT_EQ(2, DelegateClass::StaticValue);
  }
  
  TEST(Delegate, CallMemberFctNoArgReturnInt32) {
    DelegateClass dc;
    Delegate<Int32> d(dc, &DelegateClass::MemberFctNoArgReturnInt32);
    EXPECT_EQ(3, d());
  }
  
  TEST(Delegate, CallStaticFctNoArgReturnInt32) {
    Delegate<Int32> d(&DelegateClass::StaticFctNoArgReturnInt32);
    EXPECT_EQ(4, d());
  }
  
  TEST(Delegate, CallMemberFctArgInt32NoReturn) {
    DelegateClass dc;
    Delegate<void, Int32> d(dc, &DelegateClass::MemberFctArgInt32NoReturn);
    d(5);
    EXPECT_EQ(5, dc.MemberValue);
  }
  
  TEST(Delegate, CallStaticFctArgInt32NoReturn) {
    Delegate<void, Int32> d(&DelegateClass::StaticFctArgInt32NoReturn);
    d(6);
    EXPECT_EQ(6, DelegateClass::StaticValue);
  }
  
  TEST(Delegate, CallMemberFctArgInt32ReturnString) {
    DelegateClass dc;
    Delegate<string, Int32> d(dc, &DelegateClass::MemberFctArgInt32ReturnString);
    EXPECT_EQ(string("{7}"), d(7));
  }
  
  TEST(Delegate, CallStaticFctArgInt32ReturnString) {
    Delegate<string, Int32> d(&DelegateClass::StaticFctArgInt32ReturnString);
    EXPECT_EQ(string("{8}"), d(8));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&> d(dc, &DelegateClass::MemberFctArgInt32StringReturnString);
    EXPECT_EQ(string("{7, str}"), d(7, "str"));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringReturnString) {
    Delegate<string, Int32, const string&> d(&DelegateClass::StaticFctArgInt32StringReturnString);
    EXPECT_EQ(string("{8, str2}"), d(8, "str2"));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrReturnString);
    EXPECT_EQ(string("{7, str, 128}"), d(7, "str", IntPtr(Int32(128))));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrReturnString) {
    Delegate<string, Int32, const string&, IntPtr> d(&DelegateClass::StaticFctArgInt32StringIntPtrReturnString);
    EXPECT_EQ(string("{8, str2, 256}"), d(8, "str2", IntPtr(Int32(256))));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrStringReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr, const string&> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrStringReturnString);
    EXPECT_EQ(string("{7, str, 128, other}"), d(7, "str", IntPtr(Int32(128)), "other"));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrStringReturnString) {
    Delegate<string, Int32, const string&, IntPtr, const string&> d(&DelegateClass::StaticFctArgInt32StringIntPtrStringReturnString);
    EXPECT_EQ(string("{8, str2, 256, other2}"), d(8, "str2", IntPtr(Int32(256)), "other2"));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrStringBooleanReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrStringBooleanReturnString);
    EXPECT_EQ(string("{7, str, 128, other, True}"), d(7, "str", IntPtr(Int32(128)), "other", true));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrStringBooleanReturnString) {
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean> d(&DelegateClass::StaticFctArgInt32StringIntPtrStringBooleanReturnString);
    EXPECT_EQ(string("{8, str2, 256, other2, False}"), d(8, "str2", IntPtr(Int32(256)), "other2", false));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrStringBooleanStringReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrStringBooleanStringReturnString);
    EXPECT_EQ(string("{7, str, 128, other, True, Next}"), d(7, "str", IntPtr(Int32(128)), "other", true, "Next"));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrStringBooleanStringReturnString) {
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&> d(&DelegateClass::StaticFctArgInt32StringIntPtrStringBooleanStringReturnString);
    EXPECT_EQ(string("{8, str2, 256, other2, False, Prev}"), d(8, "str2", IntPtr(Int32(256)), "other2", false, "Prev"));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyReturnString);
    
    EXPECT_EQ(string("{7, str, 128, other, True, Next, Enter}"), d(7, "str", IntPtr(Int32(128)), "other", true, "Next", ConsoleKey::Enter));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyReturnString) {
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey> d(&DelegateClass::StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyReturnString);
    
    EXPECT_EQ(string("{8, str2, 256, other2, False, Prev, Escape}"), d(8, "str2", IntPtr(Int32(256)), "other2", false, "Prev", ConsoleKey::Escape));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey, ConsoleColor> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorReturnString);
    
    EXPECT_EQ(string("{7, str, 128, other, True, Next, Enter, Green}"), d(7, "str", IntPtr(Int32(128)), "other", true, "Next", ConsoleKey::Enter, ConsoleColor::Green));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorReturnString) {
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey, ConsoleColor> d(&DelegateClass::StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorReturnString);
    
    EXPECT_EQ(string("{8, str2, 256, other2, False, Prev, Escape, DarkRed}"), d(8, "str2", IntPtr(Int32(256)), "other2", false, "Prev", ConsoleKey::Escape, ConsoleColor::DarkRed));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey, ConsoleColor, Enum<ConsoleModifiers>> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersReturnString);
    
    EXPECT_EQ(string("{7, str, 128, other, True, Next, Enter, Green, Control}"), d(7, "str", IntPtr(Int32(128)), "other", true, "Next", ConsoleKey::Enter, ConsoleColor::Green, Enum<ConsoleModifiers>(ConsoleModifiers::Control)));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersReturnString) {
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey, ConsoleColor, Enum<ConsoleModifiers>> d(&DelegateClass::StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersReturnString);
    
    EXPECT_EQ(string("{8, str2, 256, other2, False, Prev, Escape, DarkRed, Shift}"), d(8, "str2", IntPtr(Int32(256)), "other2", false, "Prev", ConsoleKey::Escape, ConsoleColor::DarkRed, Enum<ConsoleModifiers>(ConsoleModifiers::Shift)));
  }
  
  TEST(Delegate, CallMemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersByteReturnString) {
    DelegateClass dc;
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey, ConsoleColor, Enum<ConsoleModifiers>, Byte> d(dc, &DelegateClass::MemberFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersByteReturnString);
    
    EXPECT_EQ(string("{7, str, 128, other, True, Next, Enter, Green, Control, 255}"), d(7, "str", IntPtr(Int32(128)), "other", true, "Next", ConsoleKey::Enter, ConsoleColor::Green, Enum<ConsoleModifiers>(ConsoleModifiers::Control), 255));
  }
  
  TEST(Delegate, CallStaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersByteReturnString) {
    Delegate<string, Int32, const string&, IntPtr, const string&, Boolean, const string&, ConsoleKey, ConsoleColor, Enum<ConsoleModifiers>, Byte> d(&DelegateClass::StaticFctArgInt32StringIntPtrStringBooleanStringConsoleKeyConsoleColorConsoleModifiersByteReturnString);
    
    EXPECT_EQ(string("{8, str2, 256, other2, False, Prev, Escape, DarkRed, Shift, 128}"), d(8, "str2", IntPtr(Int32(256)), "other2", false, "Prev", ConsoleKey::Escape, ConsoleColor::DarkRed, Enum<ConsoleModifiers>(ConsoleModifiers::Shift), 128));
  }
  
  class DelegateTest : public TestFixture {
  protected:
    using Callback = Delegate<void>;
    
    void SetUp() override {cpt = 0;}
    
    void AddStaticMethod() {
      Callback callback;
      callback += StaticMethod;
      callback();
      Assert::AreEqual(1, cpt, pcf_current_information);
    }
    
    void AddAndRemoveStaticMethod() {
      Callback callback;
      callback += StaticMethod;
      callback += {*this, &DelegateTest::MemberMethod};
      callback -= StaticMethod;
      callback();
      Assert::AreEqual(2, cpt, pcf_current_information);
    }
    
    void AddMemberMethod() {
      Callback callback;
      callback += {*this, &DelegateTest::MemberMethod};
      callback();
      Assert::AreEqual(2, cpt, pcf_current_information);
    }
    
    void AddAndRemoveMemberMethod() {
      Callback callback;
      callback += {*this, &DelegateTest::MemberMethod};
      callback += StaticMethod;
      callback -= {*this, &DelegateTest::MemberMethod};
      callback();
      Assert::AreEqual(1, cpt, pcf_current_information);
    }
    
    void AddConstMemberMethod() {
      Callback callback;
      callback += {*this, &DelegateTest::ConstMemberMethod};
      callback();
      Assert::AreEqual(3, cpt, pcf_current_information);
    }
    
    void AddAndRemoveConstMemberMethod() {
      Callback callback;
      callback += {*this, &DelegateTest::ConstMemberMethod};
      callback += StaticMethod;
      callback -= {*this, &DelegateTest::ConstMemberMethod};
      callback();
      Assert::AreEqual(1, cpt, pcf_current_information);
    }
    
    void AddFunctor() {
      Callback callback;
      callback += Functor();
      callback();
      Assert::AreEqual(4, cpt, pcf_current_information);
    }
    
    void AddAndRemoveFunctor() {
      Callback callback;
      callback += Functor();
      callback += StaticMethod;
      callback -= Functor();
      callback();
      Assert::AreEqual(1, cpt, pcf_current_information);
    }
    
    void AddLambdaExpression() {
      auto lambda = [] {cpt += 5;};
      Callback callback;
      callback += lambda;
      callback();
      Assert::AreEqual(5, cpt, pcf_current_information);
    }
    
    void AddAndRemoveLambdaExpression() {
      auto lambda = [] {cpt += 5;};
      Callback callback;
      callback += lambda;
      callback += StaticMethod;
      callback -= lambda;
      callback();
      Assert::AreEqual(1, cpt, pcf_current_information);
    }
    
  private:
    static void StaticMethod() {cpt += 1;}
    
    void MemberMethod() {cpt += 2;}
    
    void ConstMemberMethod() const {cpt += 3;}
    
    class Functor {
    public:
      void operator()() {cpt += 4;}
    };

    static int cpt;
  };

  int DelegateTest::cpt = 0;
  
  pcf_test(DelegateTest, AddStaticMethod)
  pcf_test(DelegateTest, AddAndRemoveStaticMethod)
  pcf_test(DelegateTest, AddMemberMethod)
  pcf_test(DelegateTest, AddAndRemoveMemberMethod)
  pcf_test(DelegateTest, AddConstMemberMethod)
  pcf_test(DelegateTest, AddAndRemoveConstMemberMethod)
  pcf_test(DelegateTest, AddLambdaExpression)
  pcf_test(DelegateTest, AddAndRemoveLambdaExpression)
  
  class ClassInt {
  public:
    void MemberFct(int32) {}

    void operator()(int32) {}

  };
}
