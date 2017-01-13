/// @page ParameterDesignPage Parameter Design
/// This section provides broad guidelines on parameter design, including sections with guidelines for checking arguments. In addition, you should refer to the guidelines described in Naming Parameters.
///
/// <b>√ DO</b> use the least derived parameter type that provides the functionality required by the member.
///
/// For example, suppose you want to design a method that enumerates a collection and prints each item to the console. Such a method should take IEnumerable as the parameter, not ArrayList or IList, for example.
///
/// <b>X DO NOT</b> use reserved parameters.
///
/// If more input to a member is needed in some future version, a new overload can be added.
///
/// <b>X DO NOT</b> have publicly exposed methods that take pointers, arrays of pointers, or multidimensional arrays as parameters.
///
/// Pointers and multidimensional arrays are relatively difficult to use properly. In almost all cases, APIs can be redesigned to avoid taking these types as parameters.
///
/// <b>√ DO</b> place all out parameters following all of the by-value and ref parameters (excluding parameter arrays), even if it results in an inconsistency in parameter ordering between overloads (see Member Overloading).
///
/// The out parameters can be seen as extra return values, and grouping them together makes the method signature easier to understand.
///
/// <b>√ DO</b> be consistent in naming parameters when overriding members or implementing interface members.
///
/// This better communicates the relationship between the methods.
///
/// @section ChoosingBetweenEnumAndBooleanPrametersSection Choosing Between Enum and Boolean Paramters
///
/// <b>√ DO</b> use enums if a member would otherwise have two or more Boolean parameters.
///
/// <b>X DO NOT</b> use Booleans unless you are absolutely sure there will never be a need for more than two values.
///
/// Enums give you some room for future addition of values, but you should be aware of all the implications of adding values to enums, which are described in Enum Design.
///
/// <b>√ CONSIDER</b> using Booleans for constructor parameters that are truly two-state values and are simply used to initialize Boolean properties.
///
/// @section ValidatingArgumentsSection Validating Arguments
///
/// <b>√ DO</b> validate arguments passed to public, protected, or explicitly implemented members. Throw System.ArgumentException, or one of its subclasses, if the validation fails.
///
/// Note that the actual validation does not necessarily have to happen in the public or protected member itself. It could happen at a lower level in some private or internal routine. The main point is that the entire surface area that is exposed to the end users checks the arguments.
///
/// <b>√ DO</b> throw ArgumentNullException if a null argument is passed and the member does not support null arguments.
/// 
/// <b>√ DO</b> validate enum parameters.
///
/// Do not assume enum arguments will be in the range defined by the enum. The CLR allows casting any integer value into an enum value even if the value is not defined in the enum.
/// 
/// <b>X DO NOT</b> use Enum.IsDefined for enum range checks.
/// 
/// <b>√ DO</b> be aware that mutable arguments might have changed after they were validated.
///
/// If the member is security sensitive, you are encouraged to make a copy and then validate and process the argument.
///
/// @section ParameterPassingSection Paramter Passing
///
/// From the perspective of a framework designer, there are three main groups of parameters: by-value parameters, ref parameters, and out parameters.
///
/// When an argument is passed through a by-value parameter, the member receives a copy of the actual argument passed in. If the argument is a value type, a copy of the argument is put on the stack. If the argument is a reference type, a copy of the reference is put on the stack. Most popular CLR languages, such as C#, VB.NET, and C++, default to passing parameters by value.
///
/// When an argument is passed through a ref parameter, the member receives a reference to the actual argument passed in. If the argument is a value type, a reference to the argument is put on the stack. If the argument is a reference type, a reference to the reference is put on the stack. Ref parameters can be used to allow the member to modify arguments passed by the caller.
///
/// Out parameters are similar to ref parameters, with some small differences. The parameter is initially considered unassigned and cannot be read in the member body before it is assigned some value. Also, the parameter has to be assigned some value before the member returns.
/// 
/// X AVOID using out or ref parameters.
///
/// Using out or ref parameters requires experience with pointers, understanding how value types and reference types differ, and handling methods with multiple return values. Also, the difference between out and ref parameters is not widely understood. Framework architects designing for a general audience should not expect users to master working with out or ref parameters.
///
/// <b>X DO NOT</b> pass reference types by reference.
///
/// There are some limited exceptions to the rule, such as a method that can be used to swap references.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref TypeDesignGuidelinesPage
