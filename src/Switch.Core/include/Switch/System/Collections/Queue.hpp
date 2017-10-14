/// @file
/// @brief Contains Switch::System::Collections::Queue class.
#pragma once

#include "../../Any.hpp"
#include "ArrayList.hpp"
#include "ICollection.hpp"
#include "IEnumerable.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
    namespace Collections {
      /// @brief Represents a first-in, first-out collection of objects.
      class Queue : public Object, public System::Linq::Extension::Enumerable<Queue, any>, public ICollection {
      public:
        /// @brief Initializes a new instance of the Queue<T> class that is empty and has the default initial capacity.
        Queue() : capacity(0), operationNumber(0) {}
        
        /// @brief Initializes a new instance of the System::Collections::Generic::Queue<T> class
        /// that contains elements copied from the specified collection and has sufficient
        /// capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new System::Collections::Generic::Queue<T>.
        /// @exception System::ArgumentNullException collection is null.
        Queue(const IEnumerable<& collection) : capacity(0), operationNumber(0) {
          for (const any& item : collection)
            Enqueue(item);
        }
        
        /// @brief Initializes a new instance of the System::Collections::Generic::Queue<T> class
        /// that is empty and has the specified initial capacity.
        /// @param capacity The initial number of elements that the System::Collections::Generic::Queue<T>
        ///                 can contain.
        /// @exception System::ArgumentOutOfRangeException capacity is less than zero.
        Queue(int32 capacity) : capacity(capacity), operationNumber(0) {}
        
        /// @brief Default copy constructor
        /// @param queue the Queue<T> which elements will be inserted from
        Queue(const Queue& queue) : queue(queue.queue), capacity(queue.capacity), operationNumber(queue.operationNumber) {}
        
        /// @cond
        Queue(InitializerList<any> il) : operationNumber(0) {
          for (const any& item : il)
            this->Enqueue(item);
        }
        
        Queue(Queue&& queue) : queue(Move(queue.queue)), capacity(queue.capacity), operationNumber(queue.operationNumber) {
          queue.capacity = 0;
          queue.operationNumber = 0;
        }
        /// @endcond
        
        /// @brief Removes all elements from the Queue<T>.
        void Clear() override {
          this->operationNumber++;
          this->queue.clear();
        }
        
        /// @brief Determines whether an element is in the System::Collections::Generic::Queue<T>.
        /// @param item The object to locate in the System::Collections::Generic::Queue<T>. The value
        ///             can be null for reference types.
        /// @return true if item is found in the System::Collections::Generic::Queue<T>; otherwise,
        ///         false.
        virtual bool Contains(const any& value) const override {
          typename std::list<T, TAllocator>::const_iterator it;
          for (it = this->queue.begin(); it != this->queue.end() ; it++)
            if (*it == value) return true;
          return false;
        }
        
        /// @brief Copies the System::Collections::Generic::Queue<T> elements to an existing one-dimensional
        /// System::Array, starting at the specified array index.
        /// @param array The one-dimensional System::Array that is the destination of the elements
        ///              copied from System::Collections::Generic::Queue<T>. The System::Array must have
        ///              zero-based indexing.
        /// @param arrayIndex The zero-based index in array at which copying begins.
        /// @exception System::ArgumentNullException array is null.
        /// @exception System::ArgumentOutOfRangeException arrayIndex is less than zero.
        /// @exception System::ArgumentException The number of elements in the source System::Collections::Generic::Queue<T>
        ///            is greater than the available space from arrayIndex to the end of the destination
        ///            array.
        virtual void CopyTo(System::Array<any>& array, int32 arrayIndex) const override {
          if (arrayIndex < 0) throw ArgumentOutOfRangeException(_caller);
          if (arrayIndex + this->Count > array.Length) throw ArgumentException(_caller);
          
          typename std::list<T, TAllocator>::const_iterator it;
          for (it = this->queue.begin(); it != this->queue.end() ; it++)
            array[arrayIndex++] = *it;
        }
        
        /// @brief Removes and returns the object at the beginning of the System::Collections::Generic::Queue<T>.
        /// @return The object that is removed from the beginning of the System::Collections::Generic::Queue<T>.
        /// @exception System::InvalidOperationException The System::Collections::Generic::Queue<T> is empty.
        any Dequeue() {
          any copy = Peek();
          this->RemoveAt(0);
          this->operationNumber++;
          return copy;
        }
        
        /// @brief Adds an object to the end of the System::Collections::Generic::Queue<T>.
        /// @param item The object to add to the System::Collections::Generic::Queue<T>. The value can be null for reference types.
        void Enqueue(const any& value) {
          this->Add(value);
          this->operationNumber++;
          if (this->capacity < static_cast<int32>(this->queue.size())) this->capacity = static_cast<int32>(this->queue.size());
        }
        
        /// @brief Returns an enumerator that iterates through the System::Collections::Generic::Queue<T>.
        /// @return An System::Collections::Generic::Queue<T>.Enumerator for the System::Collections::Generic::Queue<T>.
        Enumerator GetEnumerator() const override {
          return Enumerator(new Queue::Enumerator(*const_cast<Queue*>(this)));
        }
        
        /// @brief Returns the object at the beginning of the System::Collections::Generic::Queue<T>
        /// without removing it.
        /// @return The object at the beginning of the System::Collections::Generic::Queue<T>.
        /// @exception System::InvalidOperationException The System::Collections::Generic::Queue<T> is empty.
        const Any& Peek() const {
          if (this->queue.size() == 0)
            throw InvalidOperationException(_caller);
          return this->queue[0];
        }
        
        Any& Peek() {
          if (this->queue.size() == 0)
            throw InvalidOperationException(_caller);
          return this->queue[0];
        }
        
        /// @brief Copies the System::Collections::Generic::Queue<T> elements to a new array.
        /// @return A new array containing elements copied from the System::Collections::Generic::Queue<T>.
        Array<any> ToArray() const {
          return this->queue.ToArray();
        }
        
        /// @brief Sets the capacity to the actual number of elements in the System::Collections::Generic::Queue<T>,
        /// if that number is less than 90 percent of current capacity.
        void TrimExcess() {this->queue.TrimExcess();}
        
        /// @brief Copies the elements in queue to the current queue (they are equal after this operation).
        /// @return a reference to the current queue.
        Queue& operator=(const Queue& queue) {this->queue = queue.queue; return *this;;}
        
        /// @cond
        using const_iterator = typename ArrayList::const_iterator;
        using iterator = typename ArrayList::iterator;
        
        const_iterator cbegin() const {return this->queue.begin();}
        const_iterator cend() const {return this->queue.end();}
        iterator begin() {return this->queue.begin();}
        const_iterator begin() const {return this->queue.begin();}
        iterator end() {return this->queue.end();}
        const_iterator end() const {return this->queue.end();}
        /// @endcond
        
      protected:
        /// @cond
        ArrayList queue;
        /// @endcond
        
      private:
        virtual int32 GetCount() const {return this->queue.Count;}
        virtual bool GetIsReadOnly() const {return false;}
        virtual bool GetIsSynchronized() const {return this->queue.IsSynchronized;}
        virtual const object& GetSyncRoot() const {return this->queue.SyncRoot;}
        
        void Add(const any&) { }
        virtual int32 IndexOf(const any&) const { return -1; }
        virtual bool Remove(const any&) { return false; }
        virtual bool Remove(any*) { return false; }
      };
    }
  }
}

using namespace Switch;
