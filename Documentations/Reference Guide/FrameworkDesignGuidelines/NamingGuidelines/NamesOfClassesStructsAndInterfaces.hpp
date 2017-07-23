/// @page NamesOfClassesStructsAndInterfacesPage Names of Classes, Structs, and Interfaces
/// The naming guidelines that follow apply to general type naming.
///
/// <b>√ DO</b> name classes and structs with nouns or noun phrases, using PascalCasing.
///
/// This distinguishes type names from methods, which are named with verb phrases.
///
/// <b>√ DO</b> name interfaces with adjective phrases, or occasionally with nouns or noun phrases.
///
/// Nouns and noun phrases should be used rarely and they might indicate that the type should be an abstract class, and not an interface.
///
/// <b>X DO NOT</b> give class names a prefix (e.g., "C").
///
/// <b>√ CONSIDER</b> ending the name of derived classes with the name of the base class.
///
/// This is very readable and explains the relationship clearly. Some examples of this in code are: <b>ArgumentOutOfRangeException</b>, which is a kind of <b>Exception</b>, and <b>SerializableAttribute</b>, which is a kind of <b>Attribute</b>. However, it is important to use reasonable judgment in applying this guideline; for example, the Button class is a kind of <b>Control</b> event, although <b>Control</b> doesn’t appear in its name.
///
/// <b>√ DO</b> prefix interface names with the letter I, to indicate that the type is an interface.
///
/// For example, <b>IComponent</b> (descriptive noun), <b>ICustomAttributeProvider</b> (noun phrase), and <b>IPersistable</b> (adjective) are appropriate interface names. As with other type names, avoid abbreviations.
///
/// <b>√ DO</b> ensure that the names differ only by the "I" prefix on the interface name when you are defining a class–interface pair where the class is a standard implementation of the interface.
///
/// @section NamesOfGenericTypeParametersSection Names of Generic Type Parameters
/// * Generics (template) has identifier called type parameter.
///
/// <b>√ DO</b> name generic type parameters with descriptive names unless a single-letter name is completely self-explanatory and a descriptive name would not add value.
///
/// <b>√ CONSIDER</b> using T as the type parameter name for types with one single-letter type parameter.
/// @code
/// template<typename T>
/// class Predicate : public Deletegate < bool, T > {
///   ...
/// };
/// @endcode
///
/// @code
/// template<typename T=object>
/// struct Nullable  : public T {
///   ... 
/// };
/// @endcode
///
/// <b>√ DO</b> prefix descriptive type parameter names with T.
/// @code
/// template<typename TSession=ISession>
/// class ISessionChannel pcf_interface {
///   virtual TSession GetSession() = 0;
/// };
/// @endcode
/// <b>√ CONSIDER</b> indicating constraints placed on a type parameter in the name of the parameter.
///
/// For example, a parameter constrained to <b>ISession</b> might be called <b>TSession</b>.
///
/// @section NamesOfCommonTypesSection Names of Common Types
/// <b>√ DO</b> follow the guidelines described in the following table when naming types derived from or implementing certain Pcf Framework types.
/// | Base Type                       | Derived/Implementing Type Guideline                                                                                                                                                            |
/// |---------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
/// | <b>System::Delegate</b>         | <b>√ DO</b> add the suffix "EventHandler" to names of delegates that are used in events.                                                                                                       |
/// | <b>System::Delegate</b>         | <b>√ DO</b> add the suffix "Callback" to names of delegates other than those used as event handlers.                                                                                           |
/// | <b>System::Delegate</b>         | <b>X DO NOT</b> add the suffix "Delegate" to a delegate.                                                                                                                                       |
/// | <b>System::EventArgs</b>        | <b>√ DO</b> add the suffix "EventArgs”.                                                                                                                                                        |
/// | <b>System::Enum</b>             | <b>√ DO</b> derive from this class.                                                                                                                                                            |
/// | <b>System::Enum</b>             | <b>X DO NOT</b> add the suffix "Enum" or "Flag.”                                                                                                                                               |
/// | <b>System::Exception</b>        | <b>√ DO</b> add the suffix "Exception”.                                                                                                                                                        |
/// | <b>IDictionary</b>              | <b>√ DO</b> add the suffix "Dictionary". Note that IDictionary is a specific type of collection, but this guideline takes precedence over the more general collections guideline that follows. |
/// | <b>IDictionary<TKey,TValue></b> | <b>√ DO</b> add the suffix "Dictionary". Note that IDictionary is a specific type of collection, but this guideline takes precedence over the more general collections guideline that follows. |
/// | <b>IEnumarable</b>              | <b>√ DO</b> add the suffix "Collection”.                                                                                                                                                       |
/// | <b>ICollection</b>              | <b>√ DO</b> add the suffix "Collection”.                                                                                                                                                       |
/// | <b>IList</b>                    | <b>√ DO</b> add the suffix "Collection”.                                                                                                                                                       |
/// | <b>IEnumarable<T></b>           | <b>√ DO</b> add the suffix "Collection”.                                                                                                                                                       |
/// | <b>ICollection<T></b>           | <b>√ DO</b> add the suffix "Collection”.                                                                                                                                                       |
/// | <b>IList<T></b>                 | <b>√ DO</b> add the suffix "Collection”.                                                                                                                                                       |
/// | <b>System::IO::Stream</b>       | <b>√ DO</b> add the suffix "Stream”.                                                                                                                                                           |
/// | <b>CodeAccessPermission</b>     | <b>√ DO</b> add the suffix "Permission”.                                                                                                                                                       |
/// | <b>IPermission</b>              | <b>√ DO</b> add the suffix "Permission”.                                                                                                                                                       |
///
/// @section NamingEnumerationsSection Naming Enumerations
/// Names of enumeration types (also called enums) in general should follow the standard type-naming rules (PascalCasing, etc.). However, there are additional guidelines that apply specifically to enums.
///
/// <b>√ DO</b> use a singular type name for an enumeration unless its values are bit fields.
///
/// <b>√ DO</b> use a plural type name for an enumeration with bit fields as values, also called flags enum.
///
/// <b>X DO NOT</b> use an "Enum" suffix in enum type names.
///
/// <b>X DO NOT</b> use "Flag" or “Flags" suffixes in enum type names.
///
/// <b>X DO NOT</b> use a prefix on enumeration value names (e.g., "ad" for ADO enums, "rtf" for rich text enums, etc.).
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref NamingGuidelinesPage
