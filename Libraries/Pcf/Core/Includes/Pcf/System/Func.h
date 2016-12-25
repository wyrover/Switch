/// @file
/// @brief Contains Pcf::System::Func <...Arguments, TResults> delegate.
#pragma once

#include "Object.h"
#include "../Types.h"
#include "_String.h"
#include "Delegate.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    //template<typename Reuslut, typename ... Arguments>
    //using Func=Delegate<Result, Arguments>;

    /// @brief Encapsulates a method that has 16 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @param arg14 The fourteenth parameter of the method that this delegate encapsulates.
    /// @param arg15 The fifteenth parameter of the method that this delegate encapsulates.
    /// @param arg16 The sixteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1=std::nullptr_t, typename T2=std::nullptr_t, typename T3=std::nullptr_t, typename T4=std::nullptr_t, typename T5=std::nullptr_t, typename T6=std::nullptr_t, typename T7=std::nullptr_t, typename T8=std::nullptr_t, typename T9=std::nullptr_t, typename T10=std::nullptr_t, typename T11=std::nullptr_t, typename T12=std::nullptr_t, typename T13=std::nullptr_t, typename T14=std::nullptr_t, typename T15=std::nullptr_t, typename T16=std::nullptr_t, class TResult=void>
    class Func : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>(function) {}

      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 15 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @param arg14 The fourteenth parameter of the method that this delegate encapsulates.
    /// @param arg15 The fifteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, typename T15, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 14 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @param arg14 The fourteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, typename T14, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 13 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @param arg13 The thirteenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, typename T13, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 12 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @param arg12 The twelfth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, typename T12, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 11 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @param arg11 The eleventh parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, typename T11, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 10 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @param arg10 The tenth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 9 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @param arg9 The ninth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, T9, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8, T9>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 8 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @param arg8 The heighth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, T8, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7, T8>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 7 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @param arg7 The seventh parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, T7, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6, T7> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6, T7>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 6 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @param arg6 The sixth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, class TResult>
    class Func<T1, T2, T3, T4, T5, T6, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5, T6> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5, T6>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5, T6>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 5 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @param arg5 The fifth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, typename T5, class TResult>
    class Func<T1, T2, T3, T4, T5, TResult> : public Delegate<TResult, T1, T2, T3, T4, T5> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4, T5>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4, T5>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4, T5>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 4 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @param arg4 The fourth parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, typename T4, class TResult>
    class Func<T1, T2, T3, T4, TResult> : public Delegate<TResult, T1, T2, T3, T4> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3, T4>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3, T4>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3, T4>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 3 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @param arg3 The third parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, typename T3, class TResult>
    class Func<T1, T2, T3, TResult> : public Delegate<TResult, T1, T2, T3> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2, T3>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2, T3>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2, T3>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 2 parameters and returns a value of the type specified by the TResult parameter.
    /// @param arg1 The first parameter of the method that this delegate encapsulates.
    /// @param arg2 The second parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<typename T1, typename T2, class TResult>
    class Func<T1, T2, TResult> : public Delegate<TResult, T1, T2> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T1, T2>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T1, T2>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T1, T2>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has 1 parameter and returns a value of the type specified by the TResult parameter.
    /// @param arg The first parameter of the method that this delegate encapsulates.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<class T, class TResult>
    class Func<T, TResult> : public Delegate<TResult, T> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult, T>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult, T>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult, T>(function) {}
      /// @endcond
    };

    /// @brief Encapsulates a method that has no parameter and returns a value of the type specified by the TResult parameter.
    /// @return TResult The type of the return value of the method that this delegate encapsulates.
    /// @return The return value of the method that this delegate encapsulates.
    template<class TResult>
    class Func<TResult> : public Delegate<TResult> {
    public:
      /// @brief Initializes an empty action.
      Func() {}

      /// @brief Initializes an action that invokes the specified action instance.
      /// @param delegate
      /// The delegate instance.
      Func(const Func& function) : Delegate<TResult>(function) {}

      /// @brief Initializes an action that invokes the specified instance method.
      /// @param function
      /// the method instance.
      Func(const typename Func::Function& function) : Delegate<TResult>(function) {}
      
      /// @cond
      template<typename Fn>
      Func(Fn function) : Delegate<TResult>(function) {}
      /// @endcond
    };
  }
}

using namespace Pcf;
