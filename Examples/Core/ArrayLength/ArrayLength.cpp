#include <Pcf/Pcf>

using namespace System;

namespace Examples {
  template<typename T1>
  class __tuple {
  public:
    __tuple(const T1& value1) : tuple(std::make_tuple(value1)) {}
    
    Property<T1> Item1 {
      pcf_get {return std::get<0>(this->tuple);},
      pcf_set {std::get<0>(this->tuple) = value;}
    };
    
  private:
    std::tuple<T1> tuple;
  };
  
  template<typename T>
  Array<T> MyFunc(const InitializerList<T>& il) {
    System::Collections::Generic::List<T> list;
    for (auto item : il)
      list.Add(item);
    return list.ToArray();
  }
  
  template<typename T>
  Array<T> MyFunc(const InitializerList<Tuple<T, T>>& il) {
    System::Collections::Generic::List<T> list;
    for (auto item : il) {
      list.Add(item.Item1);
      list.Add(item.Item2);
    }
    return list.ToArray();
  }
  
  template<typename T>
  Array<T> MyFunc(const InitializerList<Tuple<T, T, T>>& il) {
    System::Collections::Generic::List<T> list;
    for (auto item : il) {
      list.Add(item.Item1);
      list.Add(item.Item2);
      list.Add(item.Item3);
    }
    return list.ToArray();
  }
  
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      
      Console::WriteLine("1 = {0}", string::Join(", ", MyFunc<int>({1, 2, 3, 4, 5, 6})));
      Console::WriteLine("2 = {0}", string::Join(", ", MyFunc<int>({{1, 2}, {3, 4}, {5, 6}})));
      Console::WriteLine("3 = {0}", string::Join(", ", MyFunc<int>({{1, 2, 3}, {4, 5, 6}})));
      
      // make a single dimension array
      Array<int> myArray1(5);
      
      // make a 3 dimensional array
      Array<int, 3> myArray2(5, 3, 2);
      
      Console::WriteLine("Lengths of single dimension array");
      // show the total length of the entire array or all dimensions
      Console::WriteLine("    Total length of the array = {0}", myArray1.Length);
      
      Console::WriteLine("Lengths of {0} dimension array", myArray2.Rank);
      for (int rank = 0; rank < myArray2.Rank; rank++) {
        // show the lengths of each dimension
        Console::WriteLine("    Length of dimension({0}) = {1}", rank,  myArray2.GetLength(rank));
      }
      // show the total length of the entire array or all dimensions
      Console::WriteLine("    Total length of the array = {0}", myArray2.Length);
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// Lengths of single dimension array
//     Total length of the array = 5
//
// Lengths of 3 dimension array
//     Length of dimension(0) = 5
//     Length of dimension(1) = 3
//     Length of dimension(2) = 2
//     Total length of the array = 30
