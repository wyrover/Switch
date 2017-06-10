/// @page BaseClassesForImplementingAbstractionsPage Base Classes for Implementing Abstractions
///
/// Strictly speaking, a class becomes a base class when another class is derived from it. For the purpose of this section, however, a base class is a class designed mainly to provide a common abstraction or for other classes to reuse some default implementation though inheritance. Base classes usually sit in the middle of inheritance hierarchies, between an abstraction at the root of a hierarchy and several custom implementations at the bottom.
///
/// They serve as implementation helpers for implementing abstractions. For example, one of the Framework’s abstractions for ordered collections of items is the IList<T> interface. Implementing IList<T> is not trivial, and therefore the Framework provides several base classes, such as Collection<T> and KeyedCollection<TKey, TItem>, which serve as helpers for implementing custom collections.
///
/// Base classes are usually not suited to serve as abstractions by themselves, because they tend to contain too much implementation. For example, the Collection<T> base class contains lots of implementation related to the fact that it implements the nongeneric IList interface (to integrate better with nongeneric collections) and to the fact that it is a collection of items stored in memory in one of its fields.
///
/// As previously discussed, base classes can provide invaluable help for users who need to implement abstractions, but at the same time they can be a significant liability. They add surface area and increase the depth of inheritance hierarchies and so conceptually complicate the framework. Therefore, base classes should be used only if they provide significant value to the users of the framework. They should be avoided if they provide value only to the implementers of the framework, in which case delegation to an internal implementation instead of inheritance from a base class should be strongly considered.
///
/// <b>✓ CONSIDER</b> making base classes abstract even if they don’t contain any abstract members. This clearly communicates to the users that the class is designed solely to be inherited from.
///
/// <b>✓ CONSIDER</b> placing base classes in a separate namespace from the mainline scenario types. By definition, base classes are intended for advanced extensibility scenarios and therefore are not interesting to the majority of users.
///
/// <b>X AVOID</b> naming base classes with a "Base" suffix if the class is intended for use in public APIs.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref DesigningForExtensibilityPage
