[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

This tutorial describes arrays and shows how they work in Switch C++.

# Tutorial

This tutorial is divided into the following sections:

* [Arrays in General](#arrays-in-general)
* [Declaring Arrays](#declaring-arrays)
* [Initializing Arrays](#initializing-arrays)
* [Accessing Array Members](#accessing-array-members)
* [Arrays are Objects](#arrays-are-objects)
* [Using foreach on Arrays](#using-foreach-on-arrays)

# Array in General

C++ arrays are zero indexed; that is, the array indexes start at zero. Arrays in Switch C++ work similarly to how arrays work in most other popular languages There are, however, a few differences that you should be aware of.

When declaring an array, use the class Array that contains the type.

```c++
Array<int> table; // not Array<int> table[];
```

Another detail is that the size of the array is not part of its type as it is in the C language. This allows you to declare an array and assign any array of int objects to it, regardless of the array's length.

```c++
Array<int> numbers; // declare numbers as an int array of 0 element
Array<int> numbers2(10); // declare numbers2 as an int array of 10 element
Array<int> numbers3(20); // declare numbers3 as an int array of 20 element
```

# Declaring Arrays

C++ supports single-dimensional arrays, and multidimensional arrays (rectangular arrays). The following examples show how to declare different kinds of arrays:

Single-dimensional arrays:

```c++
Array<int> numbers(25);
```

Multidimensional arrays:

```c++
Array<int, 2> names(3, 10); // a two dimensional array of 3 element for the first dimension and 10 elements for the second
```

## Example

The following is a complete Switch C++ program that declares and instantiates arrays as discussed above.

```c++
// arrays.cpp
#include <Switch/Switch>
 
using namespace System;
​
class DeclareArraySample {
public:
  static void Main(const Array<string>&) {
    // Single-dimensional array
    Array<int> numbers(5);
 
    for (int i = 0; i < numbers.Length; i++)
      numbers[i] = i * 3;
​
    Console::WriteLine(numbers[1]);
    Console::WriteLine(numbers[3]);
 
    // Multidimensional array
    Array<string, 2> names(2, 3);
 
    names(0, 0) = "Zero, Zero";
    names(0, 1) = "Zero, One";
    names(0, 2) = "Zero, Two";
    names(1, 0) = "One, Zero";
    names(1, 1) = "One, One";
    names(1, 2) = "One, Two";
    Console::WriteLine(names(1, 2));
    Console::WriteLine(names(0, 1));
  }
};
​
startup_(DeclareArraySample);
```

**Output**

```
3
9
One, Two
Zero, One
```

# Initializing Arrays

Switch provides simple and straightforward ways to initialize arrays at declaration time by using the initial values in Build method parameters. The following examples show different ways to initialize different kinds of arrays.

## Note

If you do not initialize an array at the time of declaration, the array members are automatically initialized to the default initial value for the array type. Also, if you declare the array as a field of a type, it will be set to the default value null when you instantiate the type.

Single-Dimensional Array

```c++
Array<int> numbers(5);
Array<string> names(3);
From initializer list
Array<int> numbers = {1, 2, 3 ,4, 5};
```

From native array

```c++
int n[5] = {1, 2, 3 ,4, 5};
Array<int>numbers(n, 5);
```

From native array without size

```c++
int n[] = {1, 2, 3 ,4, 5, 6, 7; 8, 9, 10};
Array<int>numbers(n);
```

# Accessing Array Members

Accessing array members is straightforward and similar to how you access array members in C/C++. For example, the following code creates an array called numbers and then assigns a 5 to the fifth element of the array and assigns a 7 to the seventh element of the array:

```c++
Array<int> numbers(10);
numbers[4] = 5;
numbers(6) = 7;
```

The following code declares a multidimensional array and assigns 5 to the member located at (1, 1):

```c++
Array<int, 2> numbers(2, 5);
numbers(1, 1) = 5;
```

# Arrays are Objects

In Switch, arrays are actually objects. System.Array is the abstract base type of all array types. You can use the properties, and other class members, that System.Array has. An example of this would be using the Length property to get the length of an array. The following code assigns the length of the numbers array, which is 5, to a variable called LengthOfNumbers:

```c++
Array<int> numbers = {1, 2, 3, 4, 5};
int LengthOfNumbers = numbers.Length;
```

The System::Array class provides many other useful methods/properties, such as methods for sorting, searching, and copying arrays.

# Using foreach on Arrays

Switch also provides the foreach statement. This statement provides a simple, clean way to iterate through the elements of an array. For example, the following code creates an array called numbers and iterates through it with the foreach statement:

```c++
Array<int> numbers = {1, 2, 3, 4, 5};
for (int i : numbers) {
  Console::WriteLine(i);
}
```

# See also
​
Other Resources

* [Tutorials](Tutorials.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
