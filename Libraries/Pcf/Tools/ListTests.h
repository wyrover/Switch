#pragma once

#include <Pcf/Core.h>

#include "Measures.h"
#include "Operation.h"

namespace Tools {
  namespace Performance {
    class ListTests : public object {
    public:
      ListTests() : length(1000000) {}
      ListTests(int32 length) : length(length) {}
      
      string ToString() const {
        return "std::vector<int32> vs System::Collections::Generic::List<int32> tests";
      }
      
      Measures Create() {
        return {this->CreateVector(), this->CreateList()};
      }
      
      Measures Destroy() {
        return {this->DestroyVector(), this->DestroyList()};
      }
      
      Measures Add() {
        return {this->AddVector(), this->AddList()};
      }
      
      Measures Insert() {
        return {this->InsertVector(), this->InsertList()};
      }
      
      Measures RemoveLast() {
        return {this->RemoveLastVector(), this->RemoveLastList()};
      }
      
      Measures RemoveFirst() {
        return {this->RemoveFirstVector(), this->RemoveFirstList()};
      }
      
      Measures RandomRemove() {
        return {this->RandomRemoveVector(), this->RandomRemoveList()};
      }
      
      Measures LinearRead() {
        int32 value;
        return {this->LinearReadVector(value), this->LinearReadList(value)};
      }
      
      Measures RandomRead() {
        int32 value;
        return {this->RandomReadVector(value), this->RandomReadList(value)};
      }
      
      Measures LinearWrite() {
        return {this->LinearWriteVector(), this->LinearWriteList()};
      }
      
      Measures RandomWrite() {
        return {this->RandomWriteVector(), this->RandomWriteList()};
      }
      
      Measures Enumerate() {
        int32 value;
        return {this->EnumerateVector(value), this->EnumerateList(value)};
      }
      
      Measures Foreach() {
        int32 value;
        return {this->ForeachVector(value), this->ForeachList(value)};
      }
      
    private:
      int64 CreateVector() {
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        std::vector<int32> vector;
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 CreateList() {
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        System::Collections::Generic::List<int32> list;
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 AddVector() {
        std::vector<int32> vector;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 AddList() {
        System::Collections::Generic::List<int32> list;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 InsertVector() {
        std::vector<int32> vector;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length/10; i++) {
          vector.insert(vector.begin() + 0, i);
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 InsertList() {
        System::Collections::Generic::List<int32> list;
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length/10; i++) {
          list.Insert(0, i);
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RemoveLastVector() {
        std::vector<int32> vector;
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        while(vector.size()) {
          vector.pop_back();
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RemoveLastList() {
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        while (list.Count) {
          list.RemoveAt(list.Count-1);
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RemoveFirstVector() {
        std::vector<int32> vector;
        for(int32 i = 0; i < length/10; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        while(vector.size()) {
          vector.erase(vector.begin() + 0);
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RemoveFirstList() {
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length/10; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        while (list.Count) {
          list.RemoveAt(0);
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RandomRemoveVector() {
        System::Random random;
        std::vector<int32> vector;
        for(int32 i = 0; i < length/10; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        while(vector.size()) {
          vector.erase(vector.begin() + random.Next(static_cast<int32>(vector.size())));
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RandomRemoveList() {
        System::Random random;
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length/10; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        while (list.Count) {
          list.RemoveAt(random.Next(list.Count));
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 DestroyVector() {
        std::vector<int32>* vector = new std::vector<int32>();
        for(int32 i = 0; i < length; i++) {
          vector->push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        delete vector;
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 DestroyList() {
        System::Collections::Generic::List<int32>* list = new System::Collections::Generic::List<int32>();
        for(int32 i = 0; i < length; i++) {
          list->Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        delete list;
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 LinearReadVector(int32& value) {
        value = 0;
        std::vector<int32> vector;
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          value = vector[i];
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 LinearReadList(int32& value) {
        value = 0;
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          value = list[i];
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RandomReadVector(int32& value) {
        System::Random random;
        value = 0;
        std::vector<int32> vector;
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          value = vector[random.Next(length)];
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RandomReadList(int32& value) {
        System::Random random;
        value = 0;
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          value = list[random.Next(length)];
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 LinearWriteVector() {
        int32 value = 10;
        std::vector<int32> vector;
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          vector[i] = value;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 LinearWriteList() {
        int32 value = 10;
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          list[i] = value;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RandomWriteVector() {
        System::Random random;
        int32 value = 10;
        std::vector<int32> vector;
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          vector[random.Next(length)] = value;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 RandomWriteList() {
        System::Random random;
        int32 value = 10;
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 i = 0; i < length; i++) {
          list[random.Next(length)] = value;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 EnumerateVector(int32& value) {
        value = 0;
        std::vector<int32> vector;
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        auto iterator = vector.begin();
        while (iterator != vector.end()) {
          value = *iterator;
          iterator++;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 EnumerateList(int32& value) {
        value = 0;
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        auto enumerator = list.GetEnumerator();
        while(enumerator.MoveNext()) {
          value = enumerator.Current;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 ForeachVector(int32& value) {
        value = 0;
        std::vector<int32> vector;
        for(int32 i = 0; i < length; i++) {
          vector.push_back(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for (auto iterator = vector.begin() ; iterator != vector.end(); iterator++) {
          value = *iterator;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int64 ForeachList(int32& value) {
        value = 0;
        System::Collections::Generic::List<int32> list;
        for(int32 i = 0; i < length; i++) {
          list.Add(i);
        }
        System::Diagnostics::Stopwatch stopwatch;
        stopwatch.Start();
        for(int32 item : list) {
          value = item;
        }
        stopwatch.Stop();
        return stopwatch.Elapsed().Ticks()*10;
      }
      
      int32 length;
    };
  }
}
