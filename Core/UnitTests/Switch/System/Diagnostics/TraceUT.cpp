#include <Switch/System/Diagnostics/Trace.hpp>
#include <Switch/System/Diagnostics/DefaultTraceListener.hpp>
#include <Switch/System/Diagnostics/TraceSource.hpp>
#include <Switch/System/Console.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Diagnostics;
using namespace TUnit;

namespace {
  class DefaultTraceUnittestListener : public TraceListener {
  public:
    void Fail(const string& message)  {
      EXPECT_TRUE(message.Equals("TestFail"));
    }

    void Fail(const string& message, const string& detailMessage) {
      EXPECT_TRUE(message.Equals("TestFail"));
      EXPECT_TRUE(detailMessage.Equals("Detail"));
    }

    void TraceEvent(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const string& message) {
      EXPECT_TRUE(src.Equals(Environment::CommandLine()));
      switch(type) {
      case TraceEventType::Error:
        EXPECT_TRUE(message.Equals("TestError"));
        break;
      case TraceEventType::Information:
        EXPECT_TRUE(message.Equals("TestInformation"));
        break;
      case TraceEventType::Warning:
        EXPECT_TRUE(message.Equals("TestWarning"));
        break;
        default : EXPECT_FALSE(true);
      }
    }

    void Write(const Object& obj) {
      EXPECT_TRUE(obj.ToString().Equals("Data object"));
    }

    void Write(const string& message) {
      EXPECT_TRUE(message.Equals("Data string"));
    }

    void Write(const Object& obj, const string& category) {
      EXPECT_TRUE(category.Equals("Category"));
      EXPECT_TRUE(obj.ToString().Equals("Data object"));
    }

    void Write(const string& message, const string& category) {
      EXPECT_TRUE(category.Equals("Category"));
      EXPECT_TRUE(message.Equals("Data string"));
    }

    void WriteLine(const Object& obj) {
      EXPECT_TRUE(obj.ToString().Equals("Data object"));
    }

    void WriteLine(const string& message) {
      EXPECT_TRUE(message.Equals("Data string"));
    }

    void WriteLine(const Object& obj, const string& category) {
      EXPECT_TRUE(category.Equals("Category"));
      EXPECT_TRUE(obj.ToString().Equals("Data object"));
    }

    void WriteLine(const string& message, const string& category) {
      EXPECT_TRUE(category.Equals("Category"));
      EXPECT_TRUE(message.Equals("Data string"));
    }
  };

  TEST(Trace, Default) {
    Console::SetOut(System::IO::TextWriter::Null);

    string dataString("Data string");
    const Object& dataObject=string("Data object");

    Trace::WriteLine("No listener yet");

    DefaultTraceListener defaultListener;
    defaultListener.LogFileName = "Trace.log";

    DefaultTraceListener listener = defaultListener;
    Trace::Listeners().Add(listener);

    DefaultTraceListener newListener;
    Trace::Listeners().Add(newListener);

    Trace::Fail("TestFail");
    Trace::Fail("TestFail", "Detail");

    Trace::TraceError("TestError");

    Trace::TraceInformation("TestInformation");

    Trace::TraceWarning("TestWarning");
  
    Trace::Write(dataString);
    Trace::Write(dataObject);
    Trace::Write(dataString,"Category");
    Trace::Write(dataObject,"Category");

    Trace::WriteLine(dataString);
    Trace::WriteLine(dataObject);
    Trace::WriteLine(dataString,"Category");
    Trace::WriteLine(dataObject,"Category");
    
    Trace::Listeners().Remove(listener);
    Trace::Listeners().Remove(newListener);
    
    Console::SetOut(Console::Out);
  }

  class TraceSourceUnittestListener : public TraceListener {
  public:
     void TraceData(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const System::Object& data) override {
       EXPECT_TRUE(src.Equals("TraceUnittest"));
       EXPECT_EQ(1,id);
       switch(type) {
        case TraceEventType::Error:
          EXPECT_TRUE(data.ToString().Equals("Data object"));
          break;
        default:
          EXPECT_TRUE(false);
       }
     }

    void TraceData(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const System::Collections::ArrayList& data) override {
      EXPECT_TRUE(src.Equals("TraceUnittest"));
      EXPECT_EQ(1,id);
      switch(type) {
       case TraceEventType::Error:
         EXPECT_TRUE(data[0].ToString().Equals("Object 0"));
         EXPECT_TRUE(data[1].ToString().Equals("Object 1"));
         break;
       default:
         EXPECT_TRUE(false);
      }
    }

    void TraceEvent(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id) override {
      EXPECT_TRUE(src.Equals("TraceUnittest"));
      EXPECT_EQ(2,id);
      EXPECT_EQ(TraceEventType::Error, type);
    }

    void TraceEvent(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const string& message) override {
      EXPECT_TRUE(src.Equals("TraceUnittest"));
      switch(type) {
       case TraceEventType::Error:
         EXPECT_EQ(2,id);
         EXPECT_TRUE(message.Equals("ErrorTest"));
         break;
       case TraceEventType::Information:
         EXPECT_EQ(0,id);
         EXPECT_TRUE(message.Equals("InformationTest"));
         break;
       default:
         EXPECT_TRUE(false);
      }
    }
    
    void Write(const string& message) override {}
    void WriteLine(const string& message) override {}
  };

  TEST(Trace, Source) {
    Console::SetOut(System::IO::TextWriter::Null);

    string dataString("Data string");
    const Object& dataObject=string("Data object");

    Array<refptr<Object>> dataArray(2);
    dataArray[0] = sw_new<string>("Object 0");
    dataArray[1] = sw_new<string>("Object 1");

    TraceSource traceSource("TraceUnittest");

    traceSource.Listeners().Add(DefaultTraceListener());
    traceSource.Listeners().Add(TraceSourceUnittestListener());

    traceSource.TraceData(TraceEventType(TraceEventType::Error), 1, dataObject);
    traceSource.TraceData(TraceEventType(TraceEventType::Error), 1, dataArray);

    traceSource.TraceEvent(TraceEventType(TraceEventType::Error), 2);
    traceSource.TraceEvent(TraceEventType(TraceEventType::Error), 2, "ErrorTest");

    traceSource.TraceInformation("InformationTest");

    Console::SetOut(Console::Out);
  }
}
