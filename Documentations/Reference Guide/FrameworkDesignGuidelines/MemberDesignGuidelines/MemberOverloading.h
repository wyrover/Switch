/// @page MemberOverloadingPage Member Overloading
/// Member overloading means creating two or more members on the same type that differ only in the number or type of parameters but have the same name. For example, in the following, the <b>WriteLine</b> method is overloaded:
/// @code
/// class Console {
/// public:
///   static void WriteLine();
///   static void WriteLine(const string& value);
///   static void WriteLine(boolean value);
///   ...
/// }
/// @endcode
/// Because only methods, constructors, and indexed properties can have parameters, only those members can be overloaded.
///
/// Overloading is one of the most important techniques for improving usability, productivity, and readability of reusable libraries. Overloading on the number of parameters makes it possible to provide simpler versions of constructors and methods. Overloading on the parameter type makes it possible to use the same member name for members performing identical operations on a selected set of different types.
///
/// <b>√ DO</b> try to use descriptive parameter names to indicate the default used by shorter overloads.
///
/// X AVOID arbitrarily varying parameter names in overloads. If a parameter in one overload represents the same input as a parameter in another overload, the parameters should have the same name.
///
/// X AVOID being inconsistent in the ordering of parameters in overloaded members. Parameters with the same name should appear in the same position in all overloads.
///
/// <b>√ DO</b> make only the longest overload virtual (if extensibility is required). Shorter overloads should simply call through to a longer overload.
///
/// <b>X DO NOT</b> use ref or out modifiers to overload members.
///
/// Some languages cannot resolve calls to overloads like this. In addition, such overloads usually have completely different semantics and probably should not be overloads but two separate methods instead.
///
/// <b>X DO NOT</b> have overloads with parameters at the same position and similar types yet with different semantics.
///
/// <b>√ DO</b> allow #null to be passed for optional arguments.
///
/// <b>√ DO</b> use member overloading rather than defining members with default arguments.
///
/// <b>Default arguments are not authorized.</b>
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref TypeDesignGuidelinesPage
