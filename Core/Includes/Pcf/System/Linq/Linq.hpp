/// @file
/// @brief Contains Linq keywords.
#pragma once

#include "../Uri.hpp" // ??? error on build if not present ???
#include "../Collections/Generic/List.hpp"
#include "../Threading/ThreadLocal.hpp"
#include "../../Any.hpp"

extern System::Threading::ThreadLocal<any> __enumerable__;

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  enum __order__ {
    ascending,
    descending
  };
  
  template<typename TSource>
  auto concat(const System::Collections::Generic::IEnumerable<TSource>& second) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template Concat(second);
  }
  
  template<typename TSource, int32 len>
  auto concat(const TSource (&second)[len]) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template Concat(second);
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
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template Intersect(second);
  }
  
  template<typename TSource, int32 len>
  auto intersect(const TSource (&second)[len]) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template Intersect(second);
  }
  
  template<typename TSource, typename TKey>
  auto orderby(System::Func<const TSource&, TKey> keySelector) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template OrderBy(keySelector);
  }
  
  template<typename TSource>
  auto orderby(System::Func<const TSource&, TSource> keySelector) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template OrderBy(keySelector);
  }
  
  template<__order__ order, typename TSource, typename TKey>
  auto orderby(System::Func<const TSource&, TKey> keySelector) {
    if (order == descending)
      return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template OrderByDescending(keySelector);
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template OrderBy(keySelector);
  }
  
  template<__order__ order, typename TSource>
  auto orderby(System::Func<const TSource&, TSource> keySelector) {
    if (order == descending)
      return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template OrderByDescending(keySelector);
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template OrderBy(keySelector);
  }
  
  template<typename TSource, typename TResult>
  auto select(System::Func<const TSource&, TResult> selector) {
    return as<refptr<System::Linq::EnumerableCollection<TResult>>>(__enumerable__.Value())->template Select(selector);
  }
  
  template<typename TSource>
  auto select(System::Func<const TSource&, TSource> selector) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template Select(selector);
  }
  
  template<typename TSource>
  auto where(System::Func<const TSource&, bool> predicate) {
    return as<refptr<System::Linq::EnumerableCollection<TSource>>>(__enumerable__.Value())->template Where(predicate);
  }
  
  template<typename TSource>
  refptr<System::Linq::EnumerableCollection<TSource>> operator |(const refptr<System::Linq::EnumerableCollection<TSource>>& a, const refptr<System::Linq::EnumerableCollection<TSource>>& b) {
    __enumerable__.Value = b;
    return __enumerable__.Value();
  }
}

using namespace Pcf;

