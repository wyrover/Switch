![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

This section provides guidelines for designing libraries that extend and interact with the Switch Framework. The goal is to help library designers ensure API consistency and ease of use by providing a unified programming model that is independent of the programming language used for development. We recommend that you follow these design guidelines when developing classes and components that extend the Switch Framework. Inconsistent library design adversely affects developer productivity and discourages adoption. The guidelines are organised as simple recommendations prefixed with the terms Do, Consider, Avoid, and Do not. These guidelines are intended to help class library designers understand the trade-offs between different solutions. There might be situations where good library design requires that you violate these design guidelines. Such cases should be rare, and it is important that you have a clear and compelling reason for your decision. These guidelines are excerpted from the book Framework Design Guidelines: Conventions, Idioms, and Patterns for Reusable .NET Libraries, 2nd Edition, by Krzysztof Cwalina and Brad Abrams.
 
# In This Section

* [Coding Conventions Guidelines](CodingConventionsGuidelines.md) provides guidelines for comments, documentation, indentations, new lines and spacing coding conventions.
* [Naming Guidelines](NamingGuidelines.md) Provides guidelines for naming libraries, namespaces, types, and members in class libraries.
* [Type Design Guidelines](TypeDesignGuidelines.md) Provides guidelines for using static and abstract classes, interfaces, enumerations, structures, and other types.
* [Member Design Guidelines](MemberDesignGuidelines.md) Provides guidelines for designing and using properties, methods, constructors, fields, events, operators, and parameters.
* [Designing for Extensibility](DesigningForExtensibility.md) Discusses extensibility mechanisms such as subclassing, using events, virtual members, and callbacks, and explains how to choose the mechanisms that best meet your framework's requirements.
* [Design Guidelines for Exception](DesignGuidelinesForException.md) Describes design guidelines for designing, throwing, and catching exceptions.
* [Usage Guidelines](UsageGuidelines.md) Describes guidelines for using common types such as arrays, attributes, and collections, supporting serialisation, and overloading equality operators.
* [Common Design Patterns](CommonDesignPatterns.md) are solutions to software design problems you find again and again in real-world application development. Patterns are about reusable designs and interactions of objects.

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
