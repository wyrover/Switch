![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

One of the basic design decisions every framework designer faces is whether to design a type as a class or as a struct. Good understanding of the differences in the behavior of reference types and value types is crucial in making this choice.

The only difference between a class and a struct in C++ is that structs have default public members and bases and classes have default private members and bases. Both classes and structs can have a mixture of public and private members, can use inheritance, and can have member functions.

**√ CONSIDER** defining a struct instead of a class if instances of the type are small and commonly short-lived or are commonly embedded in other objects.

**X AVOID** defining a struct unless the type has all of the following characteristics:

* It logically represents a single value, similar to primitive types (int, double, etc.).
* It is immutable.

In all other cases, you should define your types as classes.
​
# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Type Design Guidelines](TypeDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
