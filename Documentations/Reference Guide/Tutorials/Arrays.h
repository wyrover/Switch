/// @page TutorialArraysPage Arrays
///
/// This tutorial describes arrays and shows how they work in Pcf C++.
///
/// @section TutorialSection Tutorial
/// This tutorial is divided into the following sections:
///  /// @ref ArraysInGeneralSection
///  /// @ref DeclaringArraysSection
///  /// @ref InitializingArraysSection
///  /// @ref AccessingArrayMembersSection
///  /// @ref ArraysAreObjectsSection
///  /// @ref UsingForeachOnArraysSection
///
/// @section ArraysInGeneralSection Arrays in General
///
/// C++ arrays are zero indexed; that is, the array indexes start at zero. Arrays in Pcf C++ work similarly to how arrays work in most other popular languages There are, however, a few differences that you should be aware of.
///
/// When declaring an array, use the class Array that contains the type.
/// @code
/// Array<int> table; // not Array<int> table[];
/// @endcode
/// Another detail is that the size of the array is not part of its type as it is in the C language. This allows you to declare an array and assign any array of int objects to it, regardless of the array's length.
/// @code
/// Array<int> numbers; // declare numbers as an int array of 0 element
/// Array<int> numbers2(10); // declare numbers2 as an int array of 10 element
/// Array<int> numbers3(20); // declare numbers3 as an int array of 20 element
/// @endcode
///
/// @section DeclaringArraysSection Declaring Arrays
///
/// C++ supports single-dimensional arrays, and multidimensional arrays (rectangular arrays). The following examples show how to declare different kinds of arrays:
/// 
/// Single-dimensional arrays:
/// @code
/// Array<int> numbers(25);
/// @endcode
///
/// Multidimensional arrays:
/// @code
/// Array<int, 2> names(3, 10); // a two dimensional array of 3 element for the first dimension and 10 elements for the second
/// @endcode
///
/// @b Example
///
/// The following is a complete Pcf C++ program that declares and instantiates arrays as discussed above.
/// @code
/// // arrays.cpp
/// #include <Pcf/Pcf>
///
/// using namespace System;
///
/// class DeclareArraySample {
/// public:
///   static void Main(const Array<string>&) {
///     // Single-dimensional array
///     Array<int> numbers(5);
///
///     for (int i = 0; i < numbers.Length; i++)
///       numbers[i] = i * 3;
///
///     Console::WriteLine(numbers[1]);
///     Console::WriteLine(numbers[3]);
///
///     // Multidimensional array
///     Array<string, 2> names(2, 3);
///
///     names(0, 0) = "Zero, Zero";
///     names(0, 1) = "Zero, One";
///     names(0, 2) = "Zero, Two";
///     names(1, 0) = "One, Zero";
///     names(1, 1) = "One, One";
///     names(1, 2) = "One, Two";
///
///     Console::WriteLine(names(1, 2));
///     Console::WriteLine(names(0, 1));
///   }
/// };
///
/// startup(DeclareArraySample)
/// @endcode
///
/// @b Output
/// @verbatim 3
 9
 One, Two
 Zero, One@endverbatim
///
/// @section InitializingArraysSection Initializing Arrays
///
/// Pcf provides simple and straightforward ways to initialize arrays at declaration time by using the initial values in Build method parameters. The following examples show different ways to initialize different kinds of arrays.
///
/// @b Note
///
/// If you do not initialize an array at the time of declaration, the array members are automatically initialized to the default initial value for the array type. Also, if you declare the array as a field of a type, it will be set to the default value null when you instantiate the type.
///
/// Single-Dimensional Array
/// @code
/// Array<int> numbers(5);
/// Array<string> names(3);
///
/// From initializer list
/// Array<int> numbers = {1, 2, 3 ,4, 5};
/// @endcode
///
/// From native array
/// @code
/// int n[10] = {1, 2, 3 ,4, 5};
/// Array<int>numbers(n, 10);
/// @endcode
///
/// From native array without size
/// @code
/// int n[] = {1, 2, 3 ,4, 5, 6, 7; 8, 9, 10};
/// Array<int>numbers(n);
/// @endcode
///
/// @section AccessingArrayMembersSection Accessing Array Members
///
/// Accessing array members is straightforward and similar to how you access array members in C/C++. For example, the following code creates an array called numbers and then assigns a 5 to the fifth element of the array and assigns a 7 to the seventh element of the array:
/// @code
/// Array<int> numbers(10);
/// numbers[4] = 5;
/// numbers(6) = 7;
/// @endcode
///
/// The following code declares a multidimensional array and assigns 5 to the member located at (1, 1):
/// @code
/// Array<int, 2> numbers(2, 5);
/// numbers(1, 1) = 5;
/// @endcode
///
/// @section ArraysAreObjectsSection Arrays are Objects
///
/// @section UsingForeachOnArraysSection Using foreach on Arrays
///
/// Pcf also provides the foreach statement. This statement provides a simple, clean way to iterate through the elements of an array. For example, the following code creates an array called numbers and iterates through it with the foreach statement:
/// @code
/// Array<int> numbers = {1, 2, 3, 4, 5};
/// for (int i : numbers) {
///   Console::WriteLine(i);
/// }
/// @endcode
