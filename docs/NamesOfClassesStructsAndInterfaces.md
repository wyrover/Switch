![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

The naming guidelines that follow apply to general type naming.

**√ DO** name classes and structs with nouns or noun phrases, using PascalCasing.

This distinguishes type names from methods, which are named with verb phrases.

**√ DO** name interfaces with adjective phrases, or occasionally with nouns or noun phrases.

Nouns and noun phrases should be used rarely and they might indicate that the type should be an abstract class, and not an interface.

**X DO NOT** give class names a prefix (e.g., "C").

**√ CONSIDER** ending the name of derived classes with the name of the base class.

This is very readable and explains the relationship clearly. Some examples of this in code are: ArgumentOutOfRangeException, which is a kind of Exception, and SerializableAttribute, which is a kind of Attribute. However, it is important to use reasonable judgment in applying this guideline; for example, the Button class is a kind of Control event, although Control doesn’t appear in its name.

**√ DO** prefix interface names with the letter I, to indicate that the type is an interface.

For example, IComponent (descriptive noun), ICustomAttributeProvider (noun phrase), and IPersistable (adjective) are appropriate interface names. As with other type names, avoid abbreviations.

**√ DO** ensure that the names differ only by the "I" prefix on the interface name when you are defining a class–interface pair where the class is a standard implementation of the interface.

# Names of Generic Type Parameters

Generics (template) has identifier called type parameter.

**√ DO** name generic type parameters with descriptive names unless a single-letter name is completely self-explanatory and a descriptive name would not add value.

**√ CONSIDER** using T as the type parameter name for types with one single-letter type parameter. ​​

```c++
template<typename T>
class Predicate : public Deletegate<bool, T> {
  ...
};
```

```c++
template<typename T = object>
struct Nullable : public T {
  ...
};
```

**√ DO** prefix descriptive type parameter names with T.

```c++
template<typename TSession = ISession>
class ISessionChannel interface_ {
  virtual TSession GetSession() = 0;
};
```

**√ CONSIDER** indicating constraints placed on a type parameter in the name of the parameter.
 
For example, a parameter constrained to ISession might be called TSession.

# Names of Common Types

**√ DO** follow the guidelines described in the following table when naming types derived from or implementing certain Switch Framework types.

| Base Type                  | Derived/Implementing Type Guideline                                                                                                                                                         |
|----------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| System::Delegate           | **√ DO** add the suffix "EventHandler" to names of delegates that are used in events.                                                                                                       |
| System::Delegate           | **√ DO** add the suffix "Callback" to names of delegates other than those used as event handlers.                                                                                           |
| System::Delegate           | **X DO NOT** add the suffix "Delegate" to a delegate.                                                                                                                                       |
| System::EventArgs          | **√ DO** add the suffix "EventArgs”.                                                                                                                                                        |
| System::Enum               | **√ DO** derive from this class.                                                                                                                                                            |
| System::Enum               | **X DO NOT** add the suffix "Enum" or “Flag”.                                                                                                                                               |
| System::Exception          | **√ DO** add the suffix "Exception”.                                                                                                                                                        |
| IDicationary               | **√ DO** add the suffix "Dictionary". Note that IDictionary is a specific type of collection, but this guideline takes precedence over the more general collections guideline that follows. |
| IDicationary<TKey, TValue> | **√ DO** add the suffix "Dictionary". Note that IDictionary is a specific type of collection, but this guideline takes precedence over the more general collections guideline that follows. |
| IEnumerable                | **√ DO** add the suffix “Collection”.                                                                                                                                                       |
| ICOllection                | **√ DO** add the suffix "Collection”.                                                                                                                                                       |
| List                       | **√ DO** add the suffix "Collection”.                                                                                                                                                       |
| IEnumarable<T>             | **√ DO** add the suffix "Collection”.                                                                                                                                                       |
| ICollection<T>             | **√ DO** add the suffix "Collection”.                                                                                                                                                       |
| IList<T>                   | **√ DO** add the suffix "Collection”.                                                                                                                                                       |
| System::IO::Stream         | **√ DO** add the suffix "Stream”.                                                                                                                                                           |
| CodeAccessPermission       | **√ DO** add the suffix "Permission”.                                                                                                                                                       |
| Permission                 | **√ DO** add the suffix "Permission”.                                                                                                                                                       |

# Naming Enumerations

Names of enumeration types (also called enums) in general should follow the standard type-naming rules (PascalCasing, etc.). However, there are additional guidelines that apply specifically to enums.

**√ DO** use a singular type name for an enumeration unless its values are bit fields.

**√ DO** use a plural type name for an enumeration with bit fields as values, also called flags enum.

**X DO NOT** use an "Enum" suffix in enum type names.

**X DO NOT** use "Flag" or “Flags" suffixes in enum type names.

**X DO NOT** use a prefix on enumeration value names (e.g., "ad" for ADO enums, "rtf" for rich text enums, etc.).

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Naming Guidelines](NamingGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by GAMMA Soft.
