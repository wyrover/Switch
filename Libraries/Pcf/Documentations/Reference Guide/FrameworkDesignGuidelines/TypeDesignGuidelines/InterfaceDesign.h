/// @page InterfaceDesignPage Interface Design
/// Although most APIs are best modeled using classes and structs, there are cases in which interfaces are more appropriate or are the only option.
///
/// The C++ does support multiple inheritance (i.e., C++ classes can inherit from more than one base class), but for more simplicity and avoided diamond structure, it is preferable to implement one or more interfaces in addition to inheriting from a base class. Therefore, interfaces are often used to achieve the effect of multiple inheritance. For example, Pcf::System::IClosable is an interface that allows types to support disposability independent of any other inheritance hierarchy in which they want to participate.
///
/// The other situation in which defining an interface is appropriate is in creating a common interface that can be supported by several types, including some value types. Value types cannot inherit from types other than Pcf::System::ValueType, but they can implement interfaces, so using an interface is the only option in order to provide a common base type.
///
/// <b>√ DO</b> define an interface if you need some common API to be supported by a set of types that includes value types.
///
/// <b>√ CONSIDER</b> defining an interface if you need to support its functionality on types that already inherit from some other type.
///
/// X AVOID using marker interfaces (interfaces with no members).
///
/// If you need to mark a class as having a specific characteristic (marker), in general, use a custom attribute rather than an interface.
///
/// <b>√ DO</b> provide at least one type that is an implementation of an interface.
///
/// Doing this helps to validate the design of the interface. For example, Pcf::System::Collections::Generic::List <T> is an implementation of the Pcf::System::Collections::Generic::IList <T> interface.
///
/// <b>√ DO</b> provide at least one API that consumes each interface you define (a method taking the interface as a parameter or a property typed as the interface).
///
/// Doing this helps to validate the interface design. For example, Pcf::System::Collections::Generic::List<T>.Sort consumes the Pcf::System::Collections::Generic::IComparer <T> interface.
///
/// <b>X DO NOT</b> add members to an interface that has previously shipped.
///
/// Doing so would break implementations of the interface. You should create a new interface in order to avoid versioning problems.
///
/// Except for the situations described in these guidelines, you should, in general, choose classes rather than interfaces in designing managed code reusable libraries.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref TypeDesignGuidelinesPage
