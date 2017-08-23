#include <Pcf/Startup.hpp>
#include <Pcf/System/Array.hpp>
#include <Pcf/System/Console.hpp>

using namespace System;

namespace Pcf {
  namespace System {
    /// @cond
    template<typename T = NullPtr, int32 Rank = 1, typename TAllocator = Allocator<T>>
    class _Array;
    
    template<typename T, typename TAllocator>
    class GenericArrayObject;
    /// @endcond
    
    /// @brief Base object that represent Array.
    class ArrayObject : public object {
      template<typename T, typename TAllocator>
      friend class GenericArrayObject;
      ArrayObject() = default;
    };
    
    /// @brief Generic Base object that represent Array.
    template<typename T, typename TAllocator = Allocator<T>>
    class GenericArrayObject : public ArrayObject {
    public:
      /// @brief Get access to raw data of the Array.
      /// @return A pointer to raw data of the array.
      Property<const T*, ReadOnly> Data {
        pcf_get {return this->array.data();}
      };
      
      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Length {
        pcf_get {return (int32)this->array.size();}
      };
      
      /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      Property<int64, ReadOnly> LongLength {
        pcf_get {return (int64)this->array.size();}
      };
      
      /// @brief Gets the rank (number of dimensions) of the Array.
      /// @return int32 The rank (number of dimensions) of the Array.
      /// @par Examples
      /// The following code example demonstrates methods to get the rank of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Rank {
        pcf_get {return this->GetRank();}
      };
      
      /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param value The new value for the specified element.
      /// @param index A 32-bit integer that represents the position of the Array element to set.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperator.cpp
      T& operator[](int32 index) override {
        if (index >= this->Count || index < 0)
          throw System::ArgumentOutOfRangeException(pcf_current_information);
          return this->array[index];
      }
      
      /// @brief Gets the element at the specified index.
      /// @param index The zero-based index of the element to get.
      /// @return The value at the specified position in the one-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is less than 0 || index is equal to || greater than Count.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperator.cpp
      inline const T& operator[](int32 index) const override {
          if (index >= this->Count || index < 0)
            throw System::ArgumentOutOfRangeException(pcf_current_information);
            return this->array[index];
      }
      
      /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param value The new value for the specified element.
      /// @param index A 32-bit integer that represents the position of the Array element to set.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      /// @par Examples
      /// The following code example shows how to use operator () to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      T& operator()(int32 index) {
        if (index >= this->Count || index < 0)
          throw System::ArgumentOutOfRangeException(pcf_current_information);
        
        return this->array[index];
      }
      
      /// @brief Gets the value at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
      /// @param index A 32-bit integer that represents the position of the Array element to get.
      /// @return The value at the specified position in the one-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly one dimension.
      /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
      /// @par Examples
      /// The following code example shows how to use operator () to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      const T& operator()(int32 index) const {
        if (index >= this->Count || index < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        
        return this->array[index];
      }
      
      /// @brief Sets the element at in multidimension array the specified index.
      /// @param index The zero-based index of the element to set.
      /// @return T The modified element at the specified index.
      /// @exception ArgumentOutOfRangeException index is less than 0 || index is equal to || greater than Count.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      T& operator()(int32 index1, int32 index2) {
        if (index2 >= GetLength(1) || index2 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        if (index1 >= GetLength(0) || index1 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        
        return this->array[index2 + (index1 * this->GetLength(1))];
      }
      
      /// @brief Gets the value at the specified position in the two-dimensional Array. The index is specified as a 32-bit integer.
      /// @param index1 A 32-bit integer that represents the first-dimension index of the Array element to get.
      /// @param index2 A 32-bit integer that represents the second-dimension index of the Array element to get.
      /// @return The value at the specified position in the two-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly two dimension.
      /// @exception IndexOutOfRangeException Either index1 || index2 is outside the range of valid indexes for the corresponding dimension of the current Array.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      const T& operator()(int32 index1, int32 index2) const {
        if (index2 >= GetLength(1) || index2 < 0)
          throw System::ArgumentOutOfRangeException(pcf_current_information);
        if (index1 >= GetLength(0) || index1 < 0)
          throw System::ArgumentOutOfRangeException(pcf_current_information);
        
        return this->array[index2 + (index1 * this->GetLength(1))];
      }
      
      /// @brief Sets the element at in multidimension array the specified index.
      /// @param index The zero-based index of the element to set.
      /// @return T The modified element at the specified index.
      /// @exception ArgumentOutOfRangeException index is less than 0 || index is equal to || greater than Count.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      T& operator()(int32 index1, int32 index2, int32 index3) {
        if (index3 >= GetLength(2) || index3 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        if (index2 >= GetLength(1) || index2 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        if (index1 >= GetLength(0) || index1 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        
        return this->array[index3 + (index2 * this->GetLength(2)) + (index1 * this->GetLength(2) * this->GetLength(1))];
      }
      
      /// @brief Gets the value at the specified position in the three-dimensional Array. The index is specified as a 32-bit integer.
      /// @param index1 A 32-bit integer that represents the first-dimension index of the Array element to get.
      /// @param index2 A 32-bit integer that represents the second-dimension index of the Array element to get.
      /// @param index3 A 32-bit integer that represents the third-dimension index of the Array element to get.
      /// @return The value at the specified position in the three-dimensional Array.
      /// @exception ArgumentException The current Array does ! have exactly three dimension.
      /// @exception IndexOutOfRangeException Either index1 || index2 || index3 is outside the range of valid indexes for the corresponding dimension of the current Array.
      /// @par Examples
      /// The following code example shows how to use operator [] to list the elements of an array.
      /// @include ArrayArrayOperatorFunctor.cpp
      const T& operator()(int32 index1, int32 index2, int32 index3) const {
        if (index3 >= GetLength(2) || index3 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        if (index2 >= GetLength(1) || index2 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        if (index1 >= GetLength(0) || index1 < 0)
          throw System::IndexOutOfRangeException(pcf_current_information);
        
        return this->array[index3 + (index2 * this->GetLength(2)) + (index1 * this->GetLength(2) * this->GetLength(1))];
      }
      
      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @param dimension A zero-based dimension of the Array whose length needs to be determined.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @exception ArgumentOutOfRangeException dimension is less than zero. -||- dimension is equal to || greater than rank.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      int32 GetLength(int32 dimension) const { return this->GetUpperBound(dimension)+1; }
      
    private:
      template<typename TArray, int32 RankArray, typename TAllocatorArray>
      friend class _Array;
      GenericArrayObject() {
        this->lowerBound.push_back(0);
        this->upperBound.push_back(1);
      }
      
      GenericArrayObject(const GenericArrayObject& array) : length(array.length), operationNumber(array.operationNumber), array(array.array), lowerBound(array.lowerBound), upperBound(array.upperBound) {}
      
      GenericArrayObject(const Array<int32>& lengths) {
        this->length = lengths.Agregate(pcf_delegate(const int32& accumulator, const int32& value) {return accumulator * value;});
        this->array = std::vector<T, TAllocator>(this->length);
        for (int32 length : lengths) {
          this->lowerBound.push_back(0);
          this->upperBound.push_back(length - 1);
        }
      }
      
      GenericArrayObject(GenericArrayObject&& array) : array(Move(array.array)) {
        array.length = 0;
        array.operationNumber = 0;
        array.lowerBound.clear();
        array.upperBound.clear();
      }
      
      GenericArrayObject(const T* array, int32 length) : length(length), array(length) {
        if (array == null) throw System::ArgumentNullException(pcf_current_information);
        if (length < 0) throw System::ArgumentOutOfRangeException(pcf_current_information);
        
        for (int32 index = 0; index < length; index++)
          this->array[index] = array[index];
        this->lowerBound.push_back(0);
        this->upperBound.push_back(length-1);
      }
      
      explicit GenericArrayObject(const Collections::Generic::IEnumerable<T>& enumerable) {
        for (const auto& value : enumerable)
          this->array.push_back(value);
        this->length = (int32)this->array.size();
        this->lowerBound.push_back(0);
        this->upperBound.push_back(this->length-1);
      }
      
      explicit GenericArrayObject(const std::vector<T>& array) : length((int32)array.size()) {
        for (T value : array)
          this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back(length-1);
      }
      
      
      GenericArrayObject(InitializerList<T> il) : length((int32)il.size()) {
        for (T value : il)
          this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)il.size());
      }
      
      GenericArrayObject(InitializerList<InitializerList<T>> il)  {
        for (const InitializerList<T>& il1 : il)
          for (T value : il1)
            this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)il.size());
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)(*il.begin()).size());
      }
      
      GenericArrayObject(InitializerList<InitializerList<InitializerList<T>>> il)  {
        for (const InitializerList<InitializerList<T>>& il1 : il)
          for (const InitializerList<T>& il2 : il1)
            for (T value : il2)
              this->array.push_back(value);
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)il.size());
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)(*il.begin()).size());
        this->lowerBound.push_back(0);
        this->upperBound.push_back((int32)(*(*il.begin()).begin()).size());
      }
      
      virtual int32 GetRank() const = 0;
      
      int32 length = 0;
      int64 operationNumber = 0;
      std::vector<T, TAllocator> array;
      std::vector<int32> lowerBound;
      std::vector<int32> upperBound;
      object syncRoot;
    };
    
    template<typename T, int32 rank, typename TAllocator>
    class _Array : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array() {}
      
      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param lengths the lengths for each rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array(const Array<int32>& lengths) : GenericArrayObject<T, TAllocator>(lengths) {}
      
      /// @cond
      _Array(const _Array& array) : GenericArrayObject<T, TAllocator>(array) {}
      _Array(const _Array&& array) : GenericArrayObject<T, TAllocator>(Move(array)) {}
      /// @endcond
      
      /// @brief Get access to raw data of the Array.
      /// @return A pointer to raw data of the array.
      Property<const T*, ReadOnly> Data {
        pcf_get{return this->GenericArrayObject<T, TAllocator>::Data();}
      };
      
      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Length {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Length();}
      };
      
      /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      Property<int64, ReadOnly> LongLength {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::LongLength();}
      };
      
      /// @brief Gets the rank (number of dimensions) of the Array.
      /// @return int32 The rank (number of dimensions) of the Array.
      /// @par Examples
      /// The following code example demonstrates methods to get the rank of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Rank {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Rank();}
      };
      
      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return pcf_new<_Array<T, rank, TAllocator>>(*this);}
      
    private:
      int32 GetRank() const override {return rank;}
    };
    
    template<typename T, typename TAllocator>
    class _Array<T, 1, TAllocator> : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array() {}
      
      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param length the length for the first rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array(int32 length) : GenericArrayObject<T, TAllocator>(Array<int32> {length}) {}
      
      /// @brief Initializes a new instance of the Array && copy array[] T.
      /// @param array the Array to copy.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      template<int32 length>
      explicit _Array(const T (&array)[length]) : GenericArrayObject<T, TAllocator>(array, length) {}
      
      /// @brief Initializes a new instance of the Array && copy array[] T with length specified.
      /// @param array the Array to copy.
      /// @param length Length of the array.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array(const T* array, int32 length) : GenericArrayObject<T, TAllocator>(array, length) {}
      
      /// @brief Initializes a new instance of the Array && copy array Array specified.
      /// @param array the Array to copy.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      explicit _Array(const Collections::Generic::IEnumerable<T>& enumerable) : GenericArrayObject<T, TAllocator>(enumerable) {}
      
      /// @brief Initializes a new instance of the Array && copy array Array specified.
      /// @param array the Array to copy.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      explicit _Array(const Collections::Generic::IList<T>& list) : GenericArrayObject<T, TAllocator>(list) {}
      
      /// @cond
      _Array(const _Array& array) : GenericArrayObject<T, TAllocator>(array) {}
      _Array(const _Array&& array) : GenericArrayObject<T, TAllocator>(array) {}
      explicit _Array(const std::vector<T>& array) : GenericArrayObject<T, TAllocator>(array) {}
      _Array(InitializerList<T> il) : GenericArrayObject<T, TAllocator>(il) {}
      _Array(const Array<int32>& lengths) : GenericArrayObject<T, TAllocator>(lengths) {}
      /// @endcond
      
      /// @brief Get access to raw data of the Array.
      /// @return A pointer to raw data of the array.
      Property<const T*, ReadOnly> Data {
        pcf_get{return this->GenericArrayObject<T, TAllocator>::Data();}
      };
      
      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Length {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Length();}
      };
      
      /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      Property<int64, ReadOnly> LongLength {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::LongLength();}
      };
      
      /// @brief Gets the rank (number of dimensions) of the Array.
      /// @return int32 The rank (number of dimensions) of the Array.
      /// @par Examples
      /// The following code example demonstrates methods to get the rank of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Rank {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Rank();}
      };
      
      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return pcf_new<_Array<T, 1, TAllocator>>(*this);}
      
    private:
      int32 GetRank() const override {return 1;}
    };
    
    template<typename T, typename TAllocator>
    class _Array<T, 2, TAllocator> : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array() {}
      
      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param length1 the length for the first rank.
      /// @param length2 the length for the second rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array(int32 length1, int32 length2) : GenericArrayObject<T, TAllocator>(Array<int32> {length1, length2}) {}
      
      /// @cond
      _Array(const _Array& array) : GenericArrayObject<T, TAllocator>(array) {}
      _Array(const _Array&& array) : GenericArrayObject<T, TAllocator>(Move(array)) {}
      _Array(InitializerList<InitializerList<T>> il) : GenericArrayObject<T, TAllocator>(il) {}
      _Array(const Array<int32>& lengths) : GenericArrayObject<T, TAllocator>(lengths) {}
      /// @endcond
      
      /// @brief Get access to raw data of the Array.
      /// @return A pointer to raw data of the array.
      Property<const T*, ReadOnly> Data {
        pcf_get{return this->GenericArrayObject<T, TAllocator>::Data();}
      };
      
      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Length {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Length();}
      };
      
      /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      Property<int64, ReadOnly> LongLength {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::LongLength();}
      };
      
      /// @brief Gets the rank (number of dimensions) of the Array.
      /// @return int32 The rank (number of dimensions) of the Array.
      /// @par Examples
      /// The following code example demonstrates methods to get the rank of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Rank {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Rank();}
      };
      
      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return pcf_new<_Array<T, 2, TAllocator>>(*this);}
      
    private:
      int32 GetRank() const override {return 2;}
    };
    
    template<typename T, typename TAllocator>
    class _Array<T, 3, TAllocator> : public GenericArrayObject<T, TAllocator>, public ICloneable {
    public:
      /// @brief Initializes a new instance of the Array class that is empty.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array() {}
      
      /// @brief Initializes a new instance of the Array class with lengths for each rank specified.
      /// @param length1 the length for the first rank.
      /// @param length2 the length for the second rank.
      /// @param length3 the length for the third rank.
      /// @remarks The Array class is not thread safe.
      /// @par Examples
      /// The following code example demonstrates different methods to create an array.
      /// @include ArrayConstructor.cpp
      _Array(int32 length1, int32 length2, int32 length3) : GenericArrayObject<T, TAllocator>(Array<int32> {length1, length2, length3}) {}
      
      /// @cond
      _Array(const _Array& array) : GenericArrayObject<T, TAllocator>(array) {}
      _Array(const _Array&& array) : GenericArrayObject<T, TAllocator>(Move(array)) {}
      _Array(InitializerList<InitializerList<InitializerList<T>>> il) : GenericArrayObject<T, TAllocator>(il) {}
      _Array(const Array<int32>& lengths) : GenericArrayObject<T, TAllocator>(lengths) {}
      /// @endcond
      
      /// @brief Get access to raw data of the Array.
      /// @return A pointer to raw data of the array.
      Property<const T*, ReadOnly> Data {
        pcf_get{return this->GenericArrayObject<T, TAllocator>::Data();}
      };
      
      /// @brief Gets a 32-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int32 A 32-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      /// @par Examples
      /// The following code example demonstrates methods to get the length of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Length {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Length();}
      };
      
      /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the Array.
      /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the Array; zero if there are no elements in the array.
      /// @remarks Retrieving the value of this property is an O(1) operation.
      Property<int64, ReadOnly> LongLength {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::LongLength();}
      };
      
      /// @brief Gets the rank (number of dimensions) of the Array.
      /// @return int32 The rank (number of dimensions) of the Array.
      /// @par Examples
      /// The following code example demonstrates methods to get the rank of an array.
      /// @include ArrayGetLength.cpp
      Property<int32, ReadOnly> Rank {
        pcf_get {return this->GenericArrayObject<T, TAllocator>::Rank();}
      };
      
      /// @brief Creates a shallow copy of the Array.
      /// @return object A shallow copy of the Array.
      /// @remarks A shallow copy of an Array copies only the elements of the Array, whether they are reference types or value types, but it does not copy the objects that the references refer to. The references in the new Array point to the same objects that the references in the original Array point to.
      /// @remarks In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks The clone is of the same Type as the original Array.
      /// @remarks This method is an O(n) operation, where n is Length.
      refptr<object> Clone() const override {return pcf_new<_Array<T, 3, TAllocator>>(*this);}
      
    private:
      int32 GetRank() const override {return 3;}
    };
    
    template<>
    class _Array<> pcf_static {
    public:
      /// @brief Returns a read-only wrapper for the specified array.
      /// @param array The one-dimensional, zero-based array to wrap in a read-only ReadOnlyCollection<T> wrapper.
      /// @return A read-only ReadOnlyCollection<T> wrapper for the specified array.
      /// @remarks To prevent any modifications to the array, expose the array only through this wrapper.
      /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
      /// @remarks This method is an O(n) operation.
      /// @par Examples
      /// The following example wraps an array in a read-only ReadOnlyCollection<T>.
      /// @include ArrayAsReadOnly.cpp
      template<typename T, typename TAllocator>
      static System::Collections::ObjectModel::ReadOnlyCollection<T> AsReadOnly(const Array<T, 1, TAllocator>& array) { return System::Collections::ObjectModel::ReadOnlyCollection<T>(array); }
      
      /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the IComparable interface implemented by each element of the array and by the specified value.
      /// @param array The sorted one-dimensional Array to search.
      /// @param index The starting index of the range to search.
      /// @param length The length of the range to search.
      /// @param value The object to search for.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks Either value or every element of array must implement the IComparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note If value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is length.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, int32 index, int32 length, const T& value) {return BinarySearch(array, index, length, value, System::Collections::Generic::Comparer<T>::Default());}
      
      /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified IComparer interface.
      /// @param array The sorted one-dimensional Array to search.
      /// @param index The starting index of the range to search.
      /// @param length The length of the range to search.
      /// @param value The object to search for.
      /// @param comparer The IComparer implementation to use when comparing elements.  -or-  null to use the IComparable implementation of each element.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks The comparer customizes how the elements are compared. For example, you can use a System.Collections.CaseInsensitiveComparer as the comparer to perform case-insensitive string searches.
      /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified IComparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
      /// @remarks If comparer is null, the comparison is done using the IComparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note If comparer is null and value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using IComparable.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is length.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, int32 index, int32 count, const T& value, const System::Collections::Generic::IComparer<T>& comparer) {
        if (index < 0 || count < 0) throw ArgumentOutOfRangeException(pcf_current_information);
        if (index + count > array->Length) throw ArgumentException(pcf_current_information);
        
        typename std::vector<T>::const_iterator first = array.array.begin();
        typename std::vector<T>::const_iterator last = array.array.begin();
        std::advance(first, index);
        std::advance(last, index+count);
        typename std::vector<T>::const_iterator position = std::lower_bound(first, last, value, Array<T>::Comparer(&comparer));
        
        if (position != array.array.end() && !comparer->Compare(value, *position))
          return (int32)std::distance(array.array.begin(), position);
        return (int32)~std::distance(array.array.begin(), position);
      }
      
      /// @brief Searches an entire one-dimensional sorted array for a specific element, using the IComparable interface implemented by each element of the array and by the specified object.
      /// @param array The sorted one-dimensional Array to search.
      /// @param value The object to search for.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentException value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks Either value or every element of array must implement the IComparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note Ifvalue does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is the Length of array.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, const T& value) {return BinarySearch(array, 0, array.Length, value, System::Collections::Generic::Comparer<T>::Default().Release());}
      
      /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified IComparer interface.
      /// @param array The sorted one-dimensional Array to search.
      /// @param value The object to search for.
      /// @param comparer The IComparer implementation to use when comparing elements.  -or-  null to use the IComparable implementation of each element.
      /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
      /// @exception RankException array is multidimensional.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
      /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
      /// @remarks If the Array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
      /// @remarks The comparer customizes how the elements are compared. For example, you can use a System.Collections.CaseInsensitiveComparer as the comparer to perform case-insensitive string searches.
      /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified IComparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
      /// @remarks If comparer is null, the comparison is done using the IComparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
      /// @note If comparer is null and value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
      /// @remarks Duplicate elements are allowed. If the Array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
      /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using IComparable.
      /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
      /// @remarks This method is an O(log n) operation, where n is length.
      template<typename T, typename TAllocator>
      static int32 BinarySearch(const Array<T, 1, TAllocator>& array, const T& value, const System::Collections::Generic::IComparer<T>& comparer) {return BinarySearch(array, 0, array.Length, value, comparer);}
      
      /// @brief Sets a range of elements in an array to the default value of each element type.
      /// @param array The array whose elements need to be cleared.
      /// @param index The starting index of the range of elements to clear.
      /// @param length The number of elements to clear.
      /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
      /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
      /// @remarks This method resets each element in an array to the element type's default value. It sets elements of reference types (including String elements) to null, and sets elements of value types to the default values shown in the following table.
      /// | Type                                          | Value                              |
      /// |-----------------------------------------------|------------------------------------|
      /// | Boolean                                       | false                              |
      /// | All integral and floating point numeric types | 0 (zero)                           |
      /// | DateTime                                      | DateTime::MinValue                 |
      /// | Other value types                             | Default value of the type's fields |
      /// @remarks The range of cleared elements wrap from row to row in a multi-dimensional array.
      /// @remarks This method only clears the values of the elements; it does not delete the elements themselves. An array has a fixed size; therefore, elements cannot be added or removed.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator>
      static void Clear(GenericArrayObject<T, TAllocator>& array, int32 index, int32 length) {
        if (index < 0 || length < 0 || index + length > array.Length) throw ArgumentOutOfRangeException(pcf_current_information);
        if (index + length > array.Length) throw ArgumentException(pcf_current_information);
        
        for (int32 increment = 0; increment < length; increment++)
          array[index + increment] = T();
      }
      
      /// @brief Copies a range of elements from an Array starting at the specified source index and pastes them to another Array starting at the specified destination index. Guarantees that all changes are undone if the copy does not succeed completely.
      /// @param sourceArray The Array that contains the data to copy.
      /// @param sourceIndex A 32-bit integer that represents the index in the sourceArray at which copying begins.
      /// @param destinationArray The Array that receives the data.
      /// @param destinationIndex A 32-bit integer that represents the index in the destinationArray at which storing begins.
      /// @param length A 32-bit integer that represents the number of elements to copy.
      /// @exception RankException sourceArray and destinationArray have different ranks.
      /// @exception ArrayTypeMismatchException The sourceArray type is neither the same as nor derived from the destinationArray type.
      /// @exception InvalidCastException At least one element in sourceArray cannot be cast to the type of destinationArray.
      /// @exception ArgumentOutOfRangeException sourceIndex is less than the lower bound of the first dimension of sourceArray.  -or-  destinationIndex is less than the lower bound of the first dimension of destinationArray.  -or-  length is less than zero.
      /// @exception ArgumentException length is greater than the number of elements from sourceIndex to the end of sourceArray.  -or-  length is greater than the number of elements from destinationIndex to the end of destinationArray.
      /// @remarks The sourceArray and destinationArray parameters must have the same number of dimensions. The sourceArray type must be the same as or derived from the destinationArray type; otherwise, an ArrayTypeMismatchException is thrown. Unlike Copy, ConstrainedCopy verifies the compatibility of the array types before performing any operation.
      /// @remarks When copying between multidimensional arrays, the array behaves like a long one-dimensional array, where the rows (or columns) are conceptually laid end-to-end. For example, if an array has three rows (or columns) with four elements each, copying six elements from the beginning of the array would copy all four elements of the first row (or column) and the first two elements of the second row (or column). To start copying from the second element of the third row (or column), sourceIndex must be the upper bound of the first row (or column) plus the length of the second row (or column) plus two.
      /// @remarks If sourceArray and destinationArray overlap, this method behaves as if the original values of sourceArray were preserved in a temporary location before destinationArray is overwritten.
      /// @remarks The arrays can be reference-type arrays or value-type arrays. If sourceArray and destinationArray are both reference-type arrays or are both arrays of type Object, a shallow copy is performed. A shallow copy of an Array is a new Array containing references to the same elements as the original Array. The elements themselves or anything referenced by the elements are not copied. In contrast, a deep copy of an Array copies the elements and everything directly or indirectly referenced by the elements.
      /// @remarks If this method throws an exception while copying, the destinationArray remains unchanged; therefore, ConstrainedCopy can be used within a constrained execution region (Cer).
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T1, typename TAllocator1 = Allocator<T1>, typename T2, typename TAllocator2 = Allocator<T2>>
      static void ConstrainedCopy(const GenericArrayObject<T1, TAllocator1>& sourceArray, int32 sourceIndex, GenericArrayObject<T2, TAllocator2>& destinationArray, int32 destinationIndex, int32 length) {
        if (sourceArray.Rank != destinationArray.Rank) throw RankException(pcf_current_information);
        if (!std::is_base_of<T1, T2>::value) throw ArrayTypeMismatchException(pcf_current_information);
        if (sourceIndex < 0 || destinationArray < 0 || length < 0) throw ArgumentOutOfRangeException(pcf_current_information);
        if (sourceIndex + length > sourceArray.Length || destinationIndex + length > destinationArray.Length) throw ArgumentException(pcf_current_information);
        
        for (int32 increment = 0; increment < length; increment++)
          destinationArray[destinationIndex + increment] = as<T2>(sourceArray[sourceIndex + increment]);
      }
      
      /// @brief Converts an array of one type to an array of another type.
      /// @param array The one-dimensional, zero-based Array to convert to a target type.
      /// @param converter A Converter<TInput, TOutput> that converts each element from one type to another type.
      /// @return An array of the target type containing the converted elements from the source array.
      /// @remarks The Converter<TInput, TOutput> is a delegate to a method that converts an object to the target type. The elements of array are individually passed to the Converter<TInput, TOutput>, and the converted elements are saved in the new array.
      /// @remarks The source array remains unchanged.
      /// @remarks This method is an O(n) operation, where n is the Length of array.
      template<typename TInput, typename TOutput, typename TAllocatorOutput = Allocator<TOutput>, int32 Rank = 1, typename TAllocatorInput = Allocator<TInput>>
      _Array<TOutput, Rank, TAllocatorOutput> ConvertAll(const _Array<TInput, Rank, TAllocatorInput>& array, Converter<TInput, TOutput> converter) {
        Array<int32, 1, TAllocatorOutput> lengths(Rank);
        for (int32 index = 0; index < Rank; index++)
          lengths[index] = array.GetLength(index);
        _Array<TOutput, Rank, TAllocatorOutput> result = CreateInstance<TOutput, Rank, TAllocatorOutput>(lengths);
        for (int32 index = 0; index < array.Length; index++)
          result[index] = converter(array[index]);
        return result;
      }
      
      /// @brief Creates a one-dimensional Array of the specified Type and length, with zero-based indexing.
      /// @param length The size of the Array to create.
      /// @return A new one-dimensional Array of the specified Type with the specified length, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator = Allocator<T>>
      static _Array<T, 1, TAllocator> CreateInstance(int32 length) {return _Array<T, 1, TAllocator>(length);}
      
      /// @brief Creates a two-dimensional Array of the specified Type and dimension lengths, with zero-based indexing.
      /// @param length1 The size of the first dimension of the Array to create.
      /// @param length2 The size of the second dimension of the Array to create.
      /// @return A new two-dimensional Array of the specified Type with the specified length for each dimension, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length1 is less than zero.  -or-  ArgumentOutOfRangeException length2 is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator = Allocator<T>>
      static _Array<T, 2, TAllocator> CreateInstance(int32 length1, int32 length2) {return _Array<T, 2, TAllocator>(length1, length2);}
      
      /// @brief Creates a three-dimensional Array of the specified Type and dimension lengths, with zero-based indexing.
      /// @param length1 The size of the first dimension of the Array to create.
      /// @param length2 The size of the second dimension of the Array to create.
      /// @param length3 The size of the third dimension of the Array to create.
      /// @return A new three-dimensional Array of the specified Type with the specified length for each dimension, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length1 is less than zero.  -or-  ArgumentOutOfRangeException length2 is less than zero.  -or-  ArgumentOutOfRangeException length3 is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, typename TAllocator = Allocator<T>>
      static _Array<T, 3, TAllocator> CreateInstance(int32 length1, int32 length2, int32 length3) {return _Array<T, 3, TAllocator>(length1, length2, length3);}
      
      /// @brief Creates a multidimensional Array of the specified Type and dimension lengths, with zero-based indexing. The dimension lengths are specified in an array of 32-bit integers.
      /// @param An array of 32-bit integers that represent the size of each dimension of the Array to create.
      /// @return A new multidimensional Array of the specified Type with the specified length for each dimension, using zero-based indexing.
      /// @exception ArgumentException elementType is not a valid Type.
      /// @exception NotSupportedException elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
      /// @exception ArgumentOutOfRangeException length1 is less than zero.  -or-  ArgumentOutOfRangeException length2 is less than zero.  -or-  ArgumentOutOfRangeException length3 is less than zero.
      /// @remarks Unlike most classes, Array provides the CreateInstance method, instead of public constructors, to allow for late bound access.
      /// @remarks The number of elements in the lengths array must equal the number of dimensions in the new Array. Each element of the lengths array must specify the length of the corresponding dimension in the new Array.
      /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
      /// @remarks This method is an O(n) operation, where n is length.
      template<typename T, int32 Rank, typename TAllocator = Allocator<T>>
      static _Array<T, Rank, TAllocator> CreateInstance(const Array<int32>& lengths) {return _Array<T, Rank, TAllocator>(lengths);}
    };
  }
}

namespace Examples {
  class Program {
  public:
    template<typename TInput, typename TOutput>
    // The main entry point for the application.
    static void Main() {
      Array<string> strings = ConvertAll<any, string>(Array<any> {DateTime::Now, Version(1, 2, 3), DayOfWeek::Wednesday, 12_h + 23_min + 2_s, true}, pcf_delegate(any value) {return value.ToString();})));
    }
  };
}

pcf_startup (Examples::Program)

