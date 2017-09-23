![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

Beyond the obvious reason of readability, it is important to follow the guidelines for parameter names because parameters are displayed in documentation and in the designer when visual design tools provide Intellisense and class browsing functionality.

**√ DO** use camelCasing in parameter names.

**√ DO** use descriptive parameter names.

**√ CONSIDER** using names based on a parameter’s meaning rather than the parameter’s type.

# Naming Operator Overload Parameters

**√ DO** use left and right for binary operator overload parameter names if there is no meaning to the parameters.

**√ DO** use value for unary operator overload parameter names if there is no meaning to the parameters.

**√ CONSIDER** meaningful names for operator overload parameters if doing so adds significant value.

**X DO NOT** use abbreviations or numeric indices for operator overload parameter names.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Naming Guidelines](NamingGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
