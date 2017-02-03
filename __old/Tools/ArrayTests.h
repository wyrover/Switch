#pragma once

#include <Pcf/Core.h>

#include "Measures.h"
#include "Operation.h"

namespace Tools {
  namespace Performance {
    class ArrayTests : public object {
    public:
      ArrayTests() : length(10000000) {}
      ArrayTests(int32 length) : length(length) {}
      
      string ToString() const {
        return "std::vector<int32> vs System::Array<int32> tests";
      }
      
      Measures Create() {
        return {this->CreateVector(), this->CreateArray()};
      }
      
      Measures Destroy() {
        return {this->DestroyVector(), this->DestroyArray()};
      }
      
      Measures LinearRead() {
        int32 value;
        return {this->LinearReadVector(value), this->LinearReadArray(value)};
      }
      
      Measures RandomRead() {
        int32 value;
        return {this->RandomReadVector(value), this->RandomReadArray(value)};
      }
      
      Measures LinearWrite() {
        return {this->LinearWriteVector(), this->LinearWriteArray()};
      }
      
      Measures RandomWrite() {
        return {this->RandomWriteVector(), this->RandomWriteArray()};
      }
      
      Measures Foreach() {
        int32 value;
        return {this->ForeachVector(value), this->ForeachArray(value)};
      }
      
    private:
      int64 CreateVector() {
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        std::vector<int32> values(length);
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 CreateArray() {
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        System::Array<int32> values(length);
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 DestroyVector() {
        std::vector<int32>* values = new std::vector<int32>(length);
        for (int32 i = 0; i < length; i++)
          (*values)[i] = i;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        delete values;
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 DestroyArray() {
        System::Array<int32>* values = new System::Array<int32>(length);
        for (int32 i = 0; i < length; i++)
          (*values)[i] = i;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        delete values;
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 LinearReadVector(int32& value) {
        std::vector<int32> values(length);
        for(int32 i = 0; i < length; i++)
          values[i] = i;
        value = 0;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++)
          value = values[i];
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 LinearReadArray(int32& value) {
        System::Array<int32> values(length);
        for (int32 i = 0; i < length; i++)
          values[i] = i;
        value = 0;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          value = values[i];
        }
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 RandomReadVector(int32& value) {
        System::Random random;
        value = 0;
        std::vector<int32> values(length);
        for (int32 i = 0; i < length; i++)
          value = values[i];
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          value = values[random.Next(length)];
        }
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 RandomReadArray(int32& value) {
        System::Random random;
        value = 0;
        System::Array<int32> values(length);
        for (int32 i = 0; i < length; i++)
          values[i] = i;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++)
          value = values[random.Next(length)];
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 LinearWriteVector() {
        int32 value = 10;
        std::vector<int32> values(length);
        for (int32 i = 0; i < length; i++)
          values[i] = i;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++)
          values[i] = value;
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 LinearWriteArray() {
        int32 value = 10;
        System::Array<int32> values(length);
        for (int32 i = 0; i < length; i++)
          values[i] = i;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++)
          values[i] = value;
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 RandomWriteVector() {
        System::Random random;
        int32 value = 10;
        std::vector<int32> values(length);
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++)
          values[random.Next(length)] = value;
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 RandomWriteArray() {
        System::Random random;
        int32 value = 10;
        System::Array<int32> array(length);
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++)
          array[random.Next(length)] = value;
        return stopwatch.ElapsedTicks * 10;
      }

      int64 ForeachVector(int32& value) {
        value = 0;
        std::vector<int32> values(length);
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for (int32 item : values)
          value = item;
        return stopwatch.ElapsedTicks * 10;
      }
      
      int64 ForeachArray(int32& value) {
        value = 0;
        System::Array<int32> values(length);
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 item : values)
          value = item;
        return stopwatch.ElapsedTicks * 10;
      }
      
      int32 length;
    };
  }
}
