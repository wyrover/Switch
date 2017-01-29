/// @file
/// @brief Contains Pcf::System::Tuple <> class.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "NullType.h"
#include "TupleImpl.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents an n-tuple, where n is 8 or greater.
    /// @see System::Tuple
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    template<typename T1=NullType, typename T2=NullType, typename T3=NullType, typename T4=NullType, typename T5=NullType, typename T6=NullType, typename T7=NullType, typename TRest=NullType>
    class Tuple : public TupleImpl<T1, T2, T3, T4, T5, T6, T7, TRest> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> class.
      Tuple() : TupleImpl<T1, T2, T3, T4, T5, T6, T7, TRest>() { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @param item6 The value of the tuple's sixth component.
      /// @param item7 The value of the tuple's seventh component.
      /// @param itemRest Any generic Tuple object that contains the values of the tuple's remaining components.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5, const T6& item6, const T7& item7, const TRest& rest) : TupleImpl<T1, T2, T3, T4, T5, T6, T7, TRest>(item1, item2, item3, item4, item5, item6, item7, rest) { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.

      Tuple(const Tuple<T1, T2, T3, T4, T5, T6, T7, TRest>& tuple) : TupleImpl<T1, T2, T3, T4, T5, T6, T7, TRest>(tuple) { }
      
      /// @cond
      Tuple<T1, T2, T3, T4, T5, T6, T7, TRest>& operator =(const Tuple<T1, T2, T3, T4, T5, T6, T7, TRest>& tuple) {
        this->item1 = tuple.item1;
        this->item2 = tuple.item2;
        this->item3 = tuple.item3;
        this->item4 = tuple.item4;
        this->item5 = tuple.item5;
        this->item6 = tuple.item6;
        this->item7 = tuple.item7;
        this->item8 = tuple.item8;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's first component.
      /// @param T1 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's second component.
      /// @param T2 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's second component.
      Property<const T2&> Item2 {
        pcf_get->const T2& {return this->item2;},
        pcf_set {this->item2 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's third component.
      /// @param T3 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's third component.
      Property<const T3&> Item3 {
        pcf_get->const T3& {return this->item3;},
        pcf_set {this->item3 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fourth component.
      /// @param T4 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fourth component.
      Property<const T4&> Item4 {
        pcf_get->const T4& {return this->item4;},
        pcf_set {this->item4 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fifth component.
      /// @param T5 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's fifth component.
      Property<const T5&> Item5 {
        pcf_get->const T5& {return this->item5;},
        pcf_set {this->item5 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's sixth component.
      /// @param T6 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's sixth component.
      Property<const T6&> Item6 {
        pcf_get->const T6& {return this->item6;},
        pcf_set {this->item6 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's seventh component.
      /// @param T7 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's seventh component.
      Property<const T7&> Item7 {
        pcf_get->const T7& {return this->item7;},
        pcf_set {this->item7 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's remaining component.
      /// @param TRest The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7, TRest> object's remaining component.
      Property<const TRest&> Rest {
        pcf_get->const TRest& {return this->item8;},
        pcf_set {this->item8 = value;}
      };
    };

    /// @brief Represents a 7-tuple, or septuple.
    /// @see System::Tuple
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    class Tuple<T1, T2, T3, T4, T5, T6, T7, NullType> : public TupleImpl<T1, T2, T3, T4, T5, T6, T7, NullType> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6, T7> class.
      Tuple() : TupleImpl<T1, T2, T3, T4, T5, T6, T7, NullType>() { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6, T7> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @param item6 The value of the tuple's sixth component.
      /// @param item7 The value of the tuple's seventh component.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5, const T6& item6, const T7& item7) : TupleImpl<T1, T2, T3, T4, T5, T6, T7, NullType>(item1, item2, item3, item4, item5, item6, item7, NullType()) { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6, T7> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const Tuple<T1, T2, T3, T4, T5, T6, T7>& tuple) : TupleImpl<T1, T2, T3, T4, T5, T6, T7, NullType>(tuple) { }

      /// @cond
      Tuple<T1, T2, T3, T4, T5, T6, T7>& operator =(const Tuple<T1, T2, T3, T4, T5, T6, T7>& tuple) {
        this->item1 = tuple.item1;
        this->item2 = tuple.item2;
        this->item3 = tuple.item3;
        this->item4 = tuple.item4;
        this->item5 = tuple.item5;
        this->item6 = tuple.item6;
        this->item7 = tuple.item7;
        return *this;
      }
      /// @endcond
      
      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's first component.
      /// @param T1 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };


      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's second component.
      /// @param T2 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's second component.
      Property<const T2&> Item2 {
        pcf_get->const T2& {return this->item2;},
        pcf_set {this->item2 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's third component.
      /// @param T3 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's third component.
      Property<const T3&> Item3 {
        pcf_get->const T3& {return this->item3;},
        pcf_set {this->item3 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's fourth component.
      /// @param T4 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's fourth component.
      Property<const T4&> Item4 {
        pcf_get->const T4& {return this->item4;},
        pcf_set {this->item4 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's fifth component.
      /// @param T5 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's fifth component.
      Property<const T5&> Item5 {
        pcf_get->const T5& {return this->item5;},
        pcf_set {this->item5 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's sixth component.
      /// @param T6 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's sixth component.
      Property<const T6&> Item6 {
        pcf_get->const T6& {return this->item6;},
        pcf_set {this->item6 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's seventh component.
      /// @param T7 The value of the current Tuple <T1, T2, T3, T4, T5, T6, T7> object's seventh component.
      Property<const T7&> Item7 {
        pcf_get->const T7& {return this->item7;},
        pcf_set {this->item7 = value;}
      };
    };

    /// @brief Represents a 6-tuple, or sextuple.
    /// @see System Namespace
    /// @see System::Tuple
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    class Tuple<T1, T2, T3, T4, T5, T6, NullType, NullType> : public TupleImpl<T1, T2, T3, T4, T5, T6, NullType, NullType> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6> class.
      Tuple() : TupleImpl<T1, T2, T3, T4, T5, T6, NullType, NullType>() { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @param item6 The value of the tuple's sixth component.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5, const T6& item6) : TupleImpl<T1, T2, T3, T4, T5, T6, NullType, NullType>(item1, item2, item3, item4, item5, item6, NullType(), NullType()) { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5, T6> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const Tuple<T1, T2, T3, T4, T5, T6>& tuple) : TupleImpl<T1, T2, T3, T4, T5, T6, NullType, NullType>(tuple) { }
      
      /// @cond
      Tuple<T1, T2, T3, T4, T5, T6>& operator =(const Tuple<T1, T2, T3, T4, T5, T6>& tuple) {
        this->item1 = tuple.item1;
        this->item2 = tuple.item2;
        this->item3 = tuple.item3;
        this->item4 = tuple.item4;
        this->item5 = tuple.item5;
        this->item6 = tuple.item6;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6> object's first component.
      /// @param T1 The value of the current Tuple <T1, T2, T3, T4, T5, T6> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };


      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6> object's second component.
      /// @param T2 The value of the current Tuple <T1, T2, T3, T4, T5, T6> object's second component.
      Property<const T2&> Item2 {
        pcf_get->const T2& {return this->item2;},
        pcf_set {this->item2 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6> object's third component.
      /// @param T3 The value of the current Tuple <T1, T2, T3, T4, T5, T6> object's third component.
      Property<const T3&> Item3 {
        pcf_get->const T3& {return this->item3;},
        pcf_set {this->item3 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6> object's fourth component.
      /// @param T4 The value of the current Tuple <T1, T2, T3, T4, T5, T6> object's fourth component.
      Property<const T4&> Item4 {
        pcf_get->const T4& {return this->item4;},
        pcf_set {this->item4 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6> object's fifth component.
      /// @param T5 The value of the current Tuple <T1, T2, T3, T4, T5, T6> object's fifth component.
      Property<const T5&> Item5 {
        pcf_get->const T5& {return this->item5;},
        pcf_set {this->item5 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5, T6> object's sixth component.
      /// @param T6 The value of the current Tuple <T1, T2, T3, T4, T5, T6> object's sixth component.
      Property<const T6&> Item6 {
        pcf_get->const T6& {return this->item6;},
        pcf_set {this->item6 = value;}
      };
    };

    /// @brief Represents a 5-tuple, or quintuple.
    /// @see System Namespace
    /// @see System::Tuple
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    class Tuple<T1, T2, T3, T4, T5, NullType, NullType, NullType> : public TupleImpl<T1, T2, T3, T4, T5, NullType, NullType, NullType> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5> class.
      Tuple() : TupleImpl<T1, T2, T3, T4, T5, NullType, NullType, NullType>() { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @param item5 The value of the tuple's fifth component.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4, const T5& item5) : TupleImpl<T1, T2, T3, T4, T5, NullType, NullType, NullType>(item1, item2, item3, item4, item5, NullType(), NullType(), NullType()) { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4, T5> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const Tuple<T1, T2, T3, T4, T5>& tuple) : TupleImpl<T1, T2, T3, T4, T5, NullType, NullType, NullType>(tuple) { }
      
      /// @cond
      Tuple<T1, T2, T3, T4, T5>& operator =(const Tuple<T1, T2, T3, T4, T5>& tuple) {
        this->item1 = tuple.item1;
        this->item2 = tuple.item2;
        this->item3 = tuple.item3;
        this->item4 = tuple.item4;
        this->item5 = tuple.item5;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5> object's first component.
      /// @param T1 The value of the current Tuple <T1, T2, T3, T4, T5> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };


      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5> object's second component.
      /// @param T2 The value of the current Tuple <T1, T2, T3, T4, T5> object's second component.
      Property<const T2&> Item2 {
        pcf_get->const T2& {return this->item2;},
        pcf_set {this->item2 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5> object's third component.
      /// @param T3 The value of the current Tuple <T1, T2, T3, T4, T5> object's third component.
      Property<const T3&> Item3 {
        pcf_get->const T3& {return this->item3;},
        pcf_set {this->item3 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5> object's fourth component.
      /// @param T4 The value of the current Tuple <T1, T2, T3, T4, T5> object's fourth component.
      Property<const T4&> Item4 {
        pcf_get->const T4& {return this->item4;},
        pcf_set {this->item4 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4, T5> object's fifth component.
      /// @param T5 The value of the current Tuple <T1, T2, T3, T4, T5> object's fifth component.
      Property<const T5&> Item5 {
        pcf_get->const T5& {return this->item5;},
        pcf_set {this->item5 = value;}
      };
    };

    /// @brief Represents a 4-tuple, or quadruple.
    /// @see System Namespace
    /// @see System::Tuple
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3, typename T4>
    class Tuple<T1, T2, T3, T4, NullType, NullType, NullType, NullType> : public TupleImpl<T1, T2, T3, T4, NullType, NullType, NullType, NullType> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4> class.
      Tuple() : TupleImpl<T1, T2, T3, T4, NullType, NullType, NullType, NullType>() { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @param item4 The value of the tuple's fourth component.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1, const T2& item2, const T3& item3, const T4& item4) :
      TupleImpl<T1, T2, T3, T4, NullType, NullType, NullType, NullType>(item1, item2, item3, item4, NullType(), NullType(), NullType(), NullType()) { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3, T4> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const Tuple<T1, T2, T3, T4>& tuple) : TupleImpl<T1, T2, T3, T4, NullType, NullType, NullType, NullType>(tuple) { }
      
      /// @cond
      Tuple<T1, T2, T3, T4>& operator =(const Tuple<T1, T2, T3, T4>& tuple) {
        this->item1 = tuple.item1;
        this->item2 = tuple.item2;
        this->item3 = tuple.item3;
        this->item4 = tuple.item4;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4> object's first component.
      /// @param T1 The value of the current Tuple <T1, T2, T3, T4> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };


      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4> object's second component.
      /// @param T2 The value of the current Tuple <T1, T2, T3, T4> object's second component.
      Property<const T2&> Item2 {
        pcf_get->const T2& {return this->item2;},
        pcf_set {this->item2 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4> object's third component.
      /// @param T3 The value of the current Tuple <T1, T2, T3, T4> object's third component.
      Property<const T3&> Item3 {
        pcf_get->const T3& {return this->item3;},
        pcf_set {this->item3 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3, T4> object's fourth component.
      /// @param T4 The value of the current Tuple <T1, T2, T3, T4> object's fourth component.
      Property<const T4&> Item4 {
        pcf_get->const T4& {return this->item4;},
        pcf_set {this->item4 = value;}
      };
    };

    /// @brief Represents a 3-tuple, or triple.
    /// @see System Namespace
    /// @see System::Tuple
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1, typename T2, typename T3>
    class Tuple<T1, T2, T3, NullType, NullType, NullType, NullType, NullType> : public TupleImpl<T1, T2, T3, NullType, NullType, NullType, NullType, NullType> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1, T2, T3> class.
      Tuple() : TupleImpl<T1, T2, T3, NullType, NullType, NullType, NullType, NullType>() { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @param item3 The value of the tuple's third component.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1, const T2& item2, const T3& item3) : TupleImpl<T1, T2, T3, NullType, NullType, NullType, NullType, NullType>(item1, item2, item3, NullType(), NullType(), NullType(), NullType(), NullType()) { }

      /// @brief Initializes a new instance of the Tuple <T1, T2, T3> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const Tuple<T1, T2, T3>& tuple) : TupleImpl<T1, T2, T3, NullType, NullType, NullType, NullType, NullType>(tuple) { }
      
      /// @cond
      Tuple<T1, T2, T3>& operator =(const Tuple<T1, T2, T3>& tuple) {
        this->item1 = tuple.item1;
        this->item2 = tuple.item2;
        this->item3 = tuple.item3;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the current Tuple <T1, T2, T3> object's first component.
      /// @param T1 The value of the current Tuple <T1, T2, T3> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };


      /// @brief Gets the value of the current Tuple <T1, T2, T3> object's second component.
      /// @param T2 The value of the current Tuple <T1, T2, T3> object's second component.
      Property<const T2&> Item2 {
        pcf_get->const T2& {return this->item2;},
        pcf_set {this->item2 = value;}
      };

      /// @brief Gets the value of the current Tuple <T1, T2, T3> object's third component.
      /// @param T3 The value of the current Tuple <T1, T2, T3> object's third component.
      Property<const T3&> Item3 {
        pcf_get->const T3& {return this->item3;},
        pcf_set {this->item3 = value;}
      };
    };

    /// @brief Represents a 2-tuple, or pair.
    /// @see System Namespace
    /// @see System::Tuple
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    /// @remarks A tuple is a data structure that has a specific number and sequence of values. The Tuple<T1, T2> class represents a 2-tuple, or pair, which is a tuple that has two components. A 2-tuple is similar to a KeyValuePair<TKey, TValue> structure.
    /// @remarks You can instantiate a Tuple<T1, T2> object by calling either the Tuple<T1, T2> constructor or the static Tuple.Create<T1, T2>(T1, T2) method. You can retrieve the values of the tuple's components by using the read-only Item1 and Item2 instance properties.
    /// @remarks Tuples are commonly used in four different ways:
    /// @remarks To represent a single set of data. For example, a tuple can represent a record in a database, and its components can represent that record's fields.
    /// @remarks To provide easy access to, and manipulation of, a data set. The following example defines an array of Tuple<T1, T2> objects that contain the names of students and their corresponding test scores. It then iterates the array to calculate the mean test score.
    /// @include Tuple2.cpp
    /// @remarks To return multiple values from a method without the use of out parameters. For example, the following example uses a Tuple<T1, T2> object to return the quotient and the remainder that result from integer division.
    /// @remarks To pass multiple values to a method through a single parameter. For example, the Thread.Start(object) method has a single parameter that lets you supply one value to the method that the thread executes at startup. If you supply a Tuple<T1, T2> object as the method argument, you can supply the thread’s startup routine with two items of data.
    template<typename T1, typename T2>
    class Tuple<T1, T2, NullType, NullType, NullType, NullType, NullType, NullType> : public TupleImpl<T1, T2, NullType, NullType, NullType, NullType, NullType, NullType> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1, T2> class.
      Tuple() : TupleImpl<T1, T2, NullType, NullType, NullType, NullType, NullType, NullType>() { }

      /// @brief Initializes a new instance of the Tuple <T1, T2> class.
      /// @param item1 The value of the tuple's first component.
      /// @param item2 The value of the tuple's second component.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1, const T2& item2) : TupleImpl<T1, T2, NullType, NullType, NullType, NullType, NullType, NullType>(item1, item2, NullType(), NullType(), NullType(), NullType(), NullType(), NullType()) { }

      /// @brief Initializes a new instance of the Tuple <T1, T2> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const Tuple<T1, T2>& tuple) : TupleImpl<T1, T2, NullType, NullType, NullType, NullType, NullType, NullType>(tuple) { }
      
      /// @cond
      Tuple<T1, T2>& operator =(const Tuple<T1, T2>& tuple) {
        this->item1 = tuple.item1;
        this->item2 = tuple.item2;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the current Tuple <T1, T2> object's first component.
      /// @param T1 The value of the current Tuple <T1, T2> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };


      /// @brief Gets the value of the current Tuple <T1, T2> object's second component.
      /// @param T2 The value of the current Tuple <T1, T2> object's second component.
      Property<const T2&> Item2 {
        pcf_get->const T2& {return this->item2;},
        pcf_set {this->item2 = value;}
      };
    };

    /// @brief Represents a 1-tuple, or singleton.
    /// @see System Namespace
    /// @see System::Tuple
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<typename T1>
    class Tuple<T1, NullType, NullType, NullType, NullType, NullType, NullType, NullType> : public TupleImpl<T1, NullType, NullType, NullType, NullType, NullType, NullType, NullType> {
    public:
      /// @brief Initializes a new instance of the Tuple <T1> class.
      Tuple() : TupleImpl<T1, NullType, NullType, NullType, NullType, NullType, NullType, NullType>() { }

      /// @brief Initializes a new instance of the Tuple <T1> class.
      /// @param item1 The value of the tuple's first component.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const T1& item1) : TupleImpl<T1, NullType, NullType, NullType, NullType, NullType, NullType, NullType>(item1, NullType(), NullType(), NullType(), NullType(), NullType(), NullType(), NullType()) { }

      /// @brief Initializes a new instance of the Tuple <T1> class.
      /// @param tuple The Tuple class to copy.
      /// @remarks You can also use the static Tuple::Create method to instantiate a n-tuple object without having to explicitly specify the type of its component.
      Tuple(const Tuple<T1>& tuple) : TupleImpl<T1, NullType, NullType, NullType, NullType, NullType, NullType, NullType>(tuple) { }
      
      /// @cond
      Tuple<T1>& operator =(const Tuple<T1>& tuple) {
        this->item1 = tuple.item1;
        return *this;
      }
      /// @endcond

      /// @brief Gets the value of the current Tuple <T1> object's first component.
      /// @param T1 The value of the current Tuple <T1> object's first component.
      Property<const T1&> Item1 {
        pcf_get->const T1& {return this->item1;},
        pcf_set {this->item1 = value;}
      };

    };

    /// @brief Provides static methods for creating tuple objects.
    /// @see System Namespace
    /// @see System::Tuple <T1>
    /// @see System::Tuple <T1, T2>
    /// @see System::Tuple <T1, T2, T3>
    /// @see System::Tuple <T1, T2, T3, T4>
    /// @see System::Tuple <T1, T2, T3, T4, T5>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7>
    /// @see System::Tuple <T1, T2, T3, T4, T5, T6, T7, TRest>
    template<>
    class Tuple<NullType, NullType, NullType, NullType, NullType, NullType, NullType, NullType> : public object {
    public:
      /// @brief Creates a new 8-tuple, or octuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @param item6 The value of the sixth component of the tuple.
      /// @param item7 The value of the seventh component of the tuple.
      /// @param item8 The value of the eighth component of the tuple.
      /// @return A 8-tuple whose value is (item1, item2, item3, item4, item5, item6, item7, item8).
      template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
      static Tuple<T1, T2, T3, T4, T5, T6, T7, T8> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7, T8 item8) {
        return Tuple<T1, T2, T3, T4, T5, T6, T7, T8>(item1, item2, item3, item4, item5, item6, item7, item8);
      }

      /// @brief Creates a new 7-tuple, or septuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @param item6 The value of the sixth component of the tuple.
      /// @param item7 The value of the seventh component of the tuple.
      /// @return A 7-tuple whose value is (item1, item2, item3, item4, item5, item6, item7).
      template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
      static Tuple<T1, T2, T3, T4, T5, T6, T7> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6, T7 item7) {
        return Tuple<T1, T2, T3, T4, T5, T6, T7>(item1, item2, item3, item4, item5, item6, item7);
      }

      /// @brief Creates a new 6-tuple, or sextuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @param item6 The value of the sixth component of the tuple.
      /// @return A 6-tuple whose value is (item1, item2, item3, item4, item5, item6).
      template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
      static Tuple<T1, T2, T3, T4, T5, T6> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5, T6 item6) {
        return Tuple<T1, T2, T3, T4, T5, T6>(item1, item2, item3, item4, item5, item6);
      }

      /// @brief Creates a new 5-tuple, or quintuple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @param item5 The value of the fifth component of the tuple.
      /// @return A 5-tuple whose value is (item1, item2, item3, item4, item5).
      template<typename T1, typename T2, typename T3, typename T4, typename T5>
      static Tuple<T1, T2, T3, T4, T5> Create(T1 item1, T2 item2, T3 item3, T4 item4, T5 item5) {
        return Tuple<T1, T2, T3, T4, T5>(item1, item2, item3, item4, item5);
      }

      /// @brief Creates a new 4-tuple, or quadruple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @param item4 The value of the fourth component of the tuple.
      /// @return A 4-tuple whose value is (item1, item2, item3, item4).
      template<typename T1, typename T2, typename T3, typename T4>
      static Tuple<T1, T2, T3, T4> Create(T1 item1, T2 item2, T3 item3, T4 item4) {
        return Tuple<T1, T2, T3, T4>(item1, item2, item3, item4);
      }

      /// @brief Creates a new 3-tuple, or triple.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @param item3 The value of the third component of the tuple.
      /// @return A 4-tuple whose value is (item1, item2, item3).
      template<typename T1, typename T2, typename T3>
      static Tuple<T1, T2, T3> Create(T1 item1, T2 item2, T3 item3) {
        return Tuple<T1, T2, T3>(item1, item2, item3);
      }

      /// @brief Creates a new 2-tuple, or pair.
      /// @param item1 The value of the first component of the tuple.
      /// @param item2 The value of the second component of the tuple.
      /// @return A 2-tuple whose value is (item1, item2).
      template<typename T1, typename T2>
      static Tuple<T1, T2> Create(T1 item1, T2 item2) {
        return Tuple<T1, T2>(item1, item2);
      }

      /// @brief Creates a new 1-tuple, or singleton.
      /// @param item1 The value of the only component of the tuple.
      /// @return A tuple whose value is (item1).
      template<typename T1>
      static Tuple<T1> Create(T1 item1) {
        return Tuple<T1>(item1);
      }

    private:
      /// @cond
      Tuple() {}
      /// @endcond
    };
  }
}

using namespace Pcf;
