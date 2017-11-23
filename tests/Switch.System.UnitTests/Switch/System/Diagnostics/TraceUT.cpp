#include <Switch/System/Diagnostics/Trace.hpp>
#include <Switch/System/Diagnostics/DefaultTraceListener.hpp>
#include <Switch/System/Diagnostics/TraceSource.hpp>
#include <Switch/System/Console.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Diagnostics;

namespace {
  class DefaultTraceUnittestListener : public TraceListener {
  public:
    void Fail(const string& message)  {
      ASSERT_TRUE(message.Equals("TestFail"));
    }
    
    void Fail(const string& message, const string& detailMessage) {
      ASSERT_TRUE(message.Equals("TestFail"));
      ASSERT_TRUE(detailMessage.Equals("Detail"));
    }
    
    void TraceEvent(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const string& message) {
      ASSERT_TRUE(src.Equals(Environment::CommandLine()));
      switch(type) {
      case TraceEventType::Error:
        ASSERT_TRUE(message.Equals("TestError"));
        break;
      case TraceEventType::Information:
        ASSERT_TRUE(message.Equals("TestInformation"));
        break;
      case TraceEventType::Warning:
        ASSERT_TRUE(message.Equals("TestWarning"));
        break;
      default : ASSERT_FALSE(true);
      }
    }
    
    void Write(const Object& obj) {
      ASSERT_TRUE(obj.ToString().Equals("Data object"));
    }
    
    void Write(const string& message) {
      ASSERT_TRUE(message.Equals("Data string"));
    }
    
    void Write(const Object& obj, const string& category) {
      ASSERT_TRUE(category.Equals("Category"));
      ASSERT_TRUE(obj.ToString().Equals("Data object"));
    }
    
    void Write(const string& message, const string& category) {
      ASSERT_TRUE(category.Equals("Category"));
      ASSERT_TRUE(message.Equals("Data string"));
    }
    
    void WriteLine(const Object& obj) {
      ASSERT_TRUE(obj.ToString().Equals("Data object"));
    }
    
    void WriteLine(const string& message) {
      ASSERT_TRUE(message.Equals("Data string"));
    }
    
    void WriteLine(const Object& obj, const string& category) {
      ASSERT_TRUE(category.Equals("Category"));
      ASSERT_TRUE(obj.ToString().Equals("Data object"));
    }
    
    void WriteLine(const string& message, const string& category) {
      ASSERT_TRUE(category.Equals("Category"));
      ASSERT_TRUE(message.Equals("Data string"));
    }
  };
  
  TEST(TraceTest, Default) {
    Console::SetOut(System::IO::TextWriter::Null());
    
    string dataString("Data string");
    const Object& dataObject = string("Data object");
    
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
    Trace::Write(dataString, "Category");
    Trace::Write(dataObject, "Category");
    
    Trace::WriteLine(dataString);
    Trace::WriteLine(dataObject);
    Trace::WriteLine(dataString, "Category");
    Trace::WriteLine(dataObject, "Category");
    
    Trace::Listeners().Remove(listener);
    Trace::Listeners().Remove(newListener);
    
    Console::SetOut(Console::Out);
  }
  
  class TraceSourceUnittestListener : public TraceListener {
  public:
    void TraceData(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const System::Object& data) override {
      ASSERT_TRUE(src.Equals("TraceUnittest"));
      ASSERT_EQ(1, id);
      switch(type) {
      case TraceEventType::Error:
        ASSERT_TRUE(data.ToString().Equals("Data object"));
        break;
      default:
        ASSERT_TRUE(false);
      }
    }
    
    void TraceData(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const System::Collections::ArrayList& data) override {
      ASSERT_TRUE(src.Equals("TraceUnittest"));
      ASSERT_EQ(1, id);
      switch(type) {
      case TraceEventType::Error:
        ASSERT_TRUE(data[0].ToString().Equals("Object 0"));
        ASSERT_TRUE(data[1].ToString().Equals("Object 1"));
        break;
      default:
        ASSERT_TRUE(false);
      }
    }
    
    void TraceEvent(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id) override {
      ASSERT_TRUE(src.Equals("TraceUnittest"));
      ASSERT_EQ(2, id);
      ASSERT_EQ(TraceEventType::Error, type);
    }
    
    void TraceEvent(const TraceEventCache& /*cache*/, const string& src, const TraceEventType& type, int32 id, const string& message) override {
      ASSERT_TRUE(src.Equals("TraceUnittest"));
      switch(type) {
      case TraceEventType::Error:
        ASSERT_EQ(2, id);
        ASSERT_TRUE(message.Equals("ErrorTest"));
        break;
      case TraceEventType::Information:
        ASSERT_EQ(0, id);
        ASSERT_TRUE(message.Equals("InformationTest"));
        break;
      default:
        ASSERT_TRUE(false);
      }
    }
    
    void Write(const string& message) override {}
    void WriteLine(const string& message) override {}
  };
  
  TEST(TraceTest, Source) {
    Console::SetOut(System::IO::TextWriter::Null());
    
    string dataString("Data string");
    const Object& dataObject = string("Data object");
    
    Array<refptr<Object>> dataArray(2);
    dataArray[0] = ref_new<string>("Object 0");
    dataArray[1] = ref_new<string>("Object 1");
    
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
