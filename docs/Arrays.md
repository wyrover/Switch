![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

**✓ DO** prefer using collections over arrays in public APIs. The Guidelines for Collections section provides details about how to choose between collections and arrays.

**X DO NOT** use read-only array fields. The field itself is read-only and can't be changed, but elements in the array can be changed.

**✓ CONSIDER** using jagged arrays instead of multidimensional arrays.

A jagged array is an array with elements that are also arrays. The arrays that make up the elements can be of different sizes, leading to less wasted space for some sets of data (e.g., sparse matrix) compared to multidimensional arrays. Furthermore, the Switch optimizes index operations on jagged arrays, so they might exhibit better runtime performance in some scenarios.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Usage Guidelines](UsageGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
