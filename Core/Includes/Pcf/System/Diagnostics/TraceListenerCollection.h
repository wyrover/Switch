/// @file
/// @brief Contains Pcf::System::Diagnostics::TraceListenerCollection class.
#pragma once

#include "../../RefPtr.h"
#include "../Collections/Generic/List.h"
#include "DefaultTraceListener.h"
#include "NullTraceListener.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
    namespace Diagnostics {
      /// @cond
      class Trace;
      class TraceSource;
      /// @endcond
      
      /// @brief Provides a thread-safe list of TraceListener objects.
      class pcf_public TraceListenerCollection : public System::Collections::Generic::IList<TraceListener>, public object {
        friend class Trace;
        friend class TraceSource;
        TraceListenerCollection() {}
        TraceListenerCollection(const DefaultTraceListener& defaultTraceListener) {
          this->list.Add(defaultTraceListener.template MemberwiseClone<DefaultTraceListener>().template As<System::Diagnostics::TraceListener>());
        }
      public:
        /// @cond
        TraceListenerCollection(const TraceListenerCollection& tlc) : list(tlc.list) {}
        TraceListenerCollection& operator=(const TraceListenerCollection& tlc) {this->list = tlc.list; return *this;}
        /// @endcond
        
        template<typename TTraceListener>
        void Add(const TTraceListener& value) {
          pcf_lock (this->SyncRoot()) {
            static_assert(!std::is_same<TraceListener, TTraceListener>::value, "Must not be System::Diagnostics::TraceListener but inherited");
            static_assert(std::is_base_of<TraceListener, TTraceListener>::value, "Is not inherited from System::Diagnostics::TraceListener");
            this->list.Add(value.template MemberwiseClone<TTraceListener>().template As<System::Diagnostics::TraceListener>());
          }
        }
        
        void Clear() override {
          pcf_lock (this->SyncRoot()) {
            this->list.Clear();
          }
        }
        
        bool Contains(const TraceListener &value) const override {return this->IndexOf(value) != -1;}
        
        void CopyTo (System::Array<refptr<TraceListener>>& array, int32 index) const {this->list.CopyTo(array, index);}
        
        System::Collections::Generic::Enumerator<TraceListener> GetEnumerator() const override {
          class Enumerator : public System::Collections::Generic::IEnumerator<TraceListener>, public object {
          public:
            Enumerator(const System::Collections::Generic::Enumerator<refptr<TraceListener>>& enumerator) : enumerator(enumerator)  {}
            bool MoveNext() override {return this->enumerator.MoveNext();}
            void Reset() override {this->enumerator.Reset();}
            
          private:
            const TraceListener& GetCurrent() const override {return *this->enumerator.Current();}
            System::Collections::Generic::Enumerator<refptr<TraceListener>> enumerator;
          };
          
          return System::Collections::Generic::Enumerator<TraceListener>(new Enumerator(this->list.GetEnumerator()));
        }
        
        int32 IndexOf(const TraceListener &value) const override {
          for(int32 index = 0; index < this->list.Count; index++) {
            if (*this->list[index] == value)
              return index;
          }
          return -1;
        }
        
        template<typename TTraceListener>
        void Insert(int32 index, const TTraceListener &value) {
          pcf_lock (this->SyncRoot()) {
            static_assert(!std::is_same<TraceListener, TTraceListener>::value, "Must not be System::Diagnostics::TraceListener but inherited");
            static_assert(std::is_base_of<TraceListener, TTraceListener>::value, "Is not inherited from System::Diagnostics::TraceListener");
            this->list.Insert(index, value.template MemberwiseClone<TTraceListener>().template As<System::Diagnostics::TraceListener>());
          }
        }

        const TraceListener& operator[] (int32 index) const override {return *this->list[index];}
        
        TraceListener& operator[] (int32 index) override {return *this->list[index];}
        
        const TraceListener& operator[] (const string& name) const {
          static NullTraceListener nullTraceListener;
          for (const auto& item : this->list)
            if (item->Name == name)
              return *item;
          return nullTraceListener;
        }
        
        TraceListener& operator[] (const string& name) {
          static NullTraceListener nullTraceListener;
          for (auto& item : this->list)
            if (item->Name == name)
              return *item;
          return nullTraceListener;
        }
        
        bool Remove (const TraceListener& value) override {
          pcf_lock (this->SyncRoot()) {
            int32 index = IndexOf(value);
            if (index == -1)return false;
            this->RemoveAt(index);
          }
          return true;
        }

        void RemoveAt(int32 index) override {
          pcf_lock (this->SyncRoot()) {
            this->list.RemoveAt(index);
          }
        }
        
      protected:
        int32 GetCount() const override {return this->list.Count();}
        bool GetIsFixedSize() const override {return this->list.IsFixedSize();}
        bool GetIsReadOnly() const override {return this->list.IsReadOnly();}
        bool GetIsSynchronized() const override {return true;}
        const Object& GetSyncRoot() const override {return this->list.SyncRoot();}
        
      private:
        void Add(const TraceListener& traceListener) override {throw InvalidOperationException(pcf_current_information);}
        void CopyTo (System::Array<TraceListener>& array, int32 index) const override {throw InvalidOperationException(pcf_current_information);}
        void Insert(int32 index, const TraceListener& value) override {throw InvalidOperationException(pcf_current_information);}

        System::Collections::Generic::List<refptr<TraceListener>> list;
      };
    }
  }
}

using namespace Pcf;