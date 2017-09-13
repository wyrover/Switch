![Switch Header](Images/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Download](Download.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

This section describes general naming conventions that relate to word choice, guidelines on using abbreviations and acronyms, and recommendations on how to avoid using c++ names.
 
# Word Choice
 
**√ DO** choose easily readable identifier names.
 
For example, a property named HorizontalAlignment is more English-readable than AlignmentHorizontal.
 
**√ DO** favour readability over brevity.
 
The property name CanScrollHorizontally is better than ScrollableX (an obscure reference to the X-axis).
 
**X DO NOT** use underscores, hyphens, or any other non-alphanumeric characters.
 
**X DO NOT** use Hungarian notation.
 
**X AVOID** using identifiers that conflict with keywords of widely used programming languages.
 
# Using Abbreviations and Acronyms
 
**X DO NOT** use abbreviations or contractions as part of identifier names.
 
For example, use GetWindow rather than GetWin.
 
**X DO NOT** use any acronyms that are not widely accepted, and even if they are, only when necessary.
 
# Avoiding C++ Names
 
**√ DO** use semantically interesting names rather than language-specific keywords for type names.
 
For example, GetLength is a better name than GetInt.
 
**√ DO** use a generic Switch type name, rather than a C++ name, in the rare cases when an identifier has no semantic meaning beyond its type.
 
For example, a method converting to int64 should be named ToInt64, not ToLong (because int64 is a Switch name for the c++ alias long long).
​
The following table presents several base data types using the Switch type names (as well as the corresponding type names for all platform).

| ​C++                | Switch | Size in bytes |
|--------------------|--------|---------------|
| char               | sbyte  | 1             |
| unsigned char      | byte   | 1             |
| short              | int16  | 2             |
| unsigned short     | uint16 | 2             |
| int                | int32  | 4             |
| unsigned int       | uint32 | 4             |
|long long           | int64  | 8             |
| unsigned long long | uint64 | 8             |
| float              | float  | 4             |
| double             | double | 8             |
| bool               | bool   | 1             |
| wchar_t            | char32 | 4             |
| char*              | string | variable      |

**√ DO** use a common name, such as value or item, rather than repeating the type name, in the rare cases when an identifier has no semantic meaning and the type of the parameter is not important.

​For more information about types see Types.
​
# ​Naming New Versions of Existing APIs

**√ DO** use a name similar to the old API when creating new versions of an existing API.
​
This helps to highlight the relationship between the APIs.

**√ DO** prefer adding a suffix rather than a prefix to indicate a new version of an existing API.

This will assist discovery when browsing documentation, or using Intellisense. The old version of the API will be organised close to the new APIs, because most browsers and Intellisense show identifiers in alphabetical order.

**√ CONSIDER** using a brand new, but meaningful identifier, instead of adding a suffix or a prefix.

**√ DO** use a numeric suffix to indicate a new version of an existing API, particularly if the existing name of the API is the only name that makes sense (i.e., if it is an industry standard) and if adding any meaningful suffix (or changing the name) is not an appropriate option.

**X DO NOT** use the "Ex" (or a similar) suffix for an identifier to distinguish it from an earlier version of the same API.

**√ DO** use the "64" suffix when introducing versions of APIs that operate on a 64-bit integer (a long integer) instead of a 32-bit integer. You only need to take this approach when the existing 32-bit API exists; don’t do it for brand new APIs with only a 64-bit version.
​
# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Naming Guidelines](NamingGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
