/// @file
/// @brief Contains Linq keywords.
#pragma once

#include "../Collections/Generic/List.hpp"
#include "../Threading/ThreadLocal.hpp"
#include "../../Any.hpp"

extern System::Threading::ThreadLocal<any> __enumerable__;

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @cond
  enum __order__ {
    ascending,
    descending
  };
  /// @endcond
  
  /// @brief Applies an accumulator function over a sequence.
  /// @param func An accumulator function to be invoked on each element.
  /// @return The final accumulator value.
  /// @par Examples
  /// The following code example demonstrates how to reverse the order of words in a string by using Aggregate.
  /// @include LinqAgregate.cpp
  /// @ingroup Switch
  template<typename TSource>
  auto agregate(const System::Func<const TSource&, const TSource&, TSource>& func) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Agregate(func);
  }
  
  /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value.
  /// @param seed The initial accumulator value.
  /// @param func An accumulator function to be invoked on each element.
  /// @return The final accumulator value.
  /// @par Examples
  /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
  /// @include LinqAgregate2.cpp
  /// @ingroup Switch
  template<typename TSource, typename TAccumulate>
  auto agregate(const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func)  {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Agregate(seed, func);
  }
  
  /// @brief Applies an accumulator function over a sequence. The specified seed value is used as the initial accumulator value, and the specified function is used to select the result value.
  /// @param seed The initial accumulator value.
  /// @param objFunc An accumulator obj to be invoked on each element.
  /// @param func An accumulator function to be invoked on each element.
  /// @param objResultSelector A obj to transform the final accumulator value into the result value.
  /// @param resultSelector A function to transform the final accumulator value into the result value.
  /// @return The transformed final accumulator value.
  /// @par Examples
  /// The following code example demonstrates how to use Aggregate to apply an accumulator function and use a seed value.
  /// @include LinqAgregate3.cpp
  /// @ingroup Switch
  template<typename TSource, typename TAccumulate, typename TResult>
  auto agregate(const TAccumulate& seed, const System::Func<const TAccumulate&, const TSource&, TAccumulate>& func, const System::Func<const TAccumulate&, TResult>& resultSelector)  {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Agregate(seed, func, resultSelector);
  }
  
  template<typename TSource>
  auto concat(const System::Collections::Generic::IEnumerable<TSource>& second) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Concat(second);
  }
  
  template<typename TSource, int32 len>
  auto concat(const TSource (&second)[len]) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Concat(second);
  }
  
  template<typename TSource>
  auto from(const System::Collections::Generic::IEnumerable<TSource>& source) {
    __enumerable__.Value = System::Linq::Enumerable::AsEnumerable(source);
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value());
  }
  
  template<typename TSource, int32 len>
  auto from(const TSource (&source)[len]) {
    __enumerable__.Value = System::Linq::Enumerable::AsEnumerable(source);
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value());
  }
  
  template<typename TSource>
  auto intersect(const System::Collections::Generic::IEnumerable<TSource>& second) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Intersect(second);
  }
  
  template<typename TSource, int32 len>
  auto intersect(const TSource (&second)[len]) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Intersect(second);
  }
  
  template<typename TSource, typename TKey>
  auto orderby(System::Func<const TSource&, TKey> keySelector) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->OrderBy(keySelector);
  }
  
  template<typename TSource>
  auto orderby(System::Func<const TSource&, TSource> keySelector) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->OrderBy(keySelector);
  }
  
  template<__order__ order, typename TSource, typename TKey>
  auto orderby(System::Func<const TSource&, TKey> keySelector) {
    if (order == descending)
      return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->OrderByDescending(keySelector);
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->OrderBy(keySelector);
  }
  
  template<__order__ order, typename TSource>
  auto orderby(System::Func<const TSource&, TSource> keySelector) {
    if (order == descending)
      return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->OrderByDescending(keySelector);
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->OrderBy(keySelector);
  }
  
  template<typename TSource, typename TResult>
  auto select(System::Func<const TSource&, TResult> selector) {
    return as<refptr<System::Linq::EnumerableCollection<TResult>>>(__enumerable__.Value())->Select(selector);
  }
  
  template<typename TSource>
  auto select(System::Func<const TSource&, TSource> selector) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Select(selector);
  }
  
  template<typename TSource>
  auto where(System::Func<const TSource&, bool> predicate) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->Where(predicate);
  }
  
  template<typename TSource>
  refptr<System::Linq::EnumerableCollection<TSource>> operator |(const refptr<System::Linq::EnumerableCollection<TSource>>& a, const refptr<System::Linq::EnumerableCollection<TSource>>& b) {
    __enumerable__.Value = b;
    return __enumerable__.Value();
  }
  
  template<typename TSource>
  const TSource& operator |(const refptr<System::Linq::EnumerableCollection<TSource>>& a, const TSource& b) {
    return b;
  }
  
  template<typename TSource, typename TResult>
  TResult operator |(const refptr<System::Linq::EnumerableCollection<TSource>>& a, const TSource& b) {
    return b;
  }
}

using namespace Switch;
