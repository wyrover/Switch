/// @page EventsAndCallbacksPage Events and Callbacks
///
/// Callbacks are extensibility points that allow a framework to call back into user code through a delegate. These delegates are usually passed to the framework through a parameter of a method.
///
/// Events are a special case of callbacks that supports convenient and consistent syntax for supplying the delegate (an event handler). In addition, Visual Studio’s statement completion and designers provide help in using event-based APIs. (See @ref EventDesignPage.)
///
/// <b>✓ CONSIDER</b> using callbacks to allow users to provide custom code to be executed by the framework.
///
/// <b>✓ CONSIDER</b> using events to allow users to customize the behavior of a framework without the need for understanding object-oriented design.
///
/// <b>✓ DO</b> prefer events over plain callbacks, because they are more familiar to a broader range of developers and are integrated with Visual Studio statement completion.
///
/// <b>X AVOID</b> using callbacks in performance-sensitive APIs.
///
/// <b>✓ DO</b> use the new Func<...>, Action<...>, or Expression<...> types instead of custom delegates, when defining APIs with callbacks.
///
/// Func<...> and Action<...> represent generic delegates. Expression<...> represents function definitions that can be compiled and subsequently invoked at runtime but can also be serialized and passed to remote processes.
///
/// <b>✓ DO</b> measure and understand performance implications of using Expression<...>, instead of using Func<...> and Action<...> delegates.
///
/// Expression<...> types are in most cases logically equivalent to Func<...> and Action<...> delegates. The main difference between them is that the delegates are intended to be used in local process scenarios; expressions are intended for cases where it’s beneficial and possible to evaluate the expression in a remote process or machine.
///
/// <b>✓ DO</b> understand that by calling a delegate, you are executing arbitrary code and that could have security, correctness, and compatibility repercussions.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref DesigningForExtensibilityPage
