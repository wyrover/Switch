![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

Callbacks are extensibility points that allow a framework to call back into user code through a delegate. These delegates are usually passed to the framework through a parameter of a method.

Events are a special case of callbacks that supports convenient and consistent syntax for supplying the delegate (an event handler). In addition, Visual Studio’s statement completion and designers provide help in using event-based APIs. (See Event Design.)

**✓ CONSIDER** using callbacks to allow users to provide custom code to be executed by the framework.

**✓ CONSIDER** using events to allow users to customize the behavior of a framework without the need for understanding object-oriented design.

**✓ DO** prefer events over plain callbacks, because they are more familiar to a broader range of developers and are integrated with Visual Studio statement completion.

**X AVOID** using callbacks in performance-sensitive APIs.

**✓ DO** use the new Func<...>, Action<...>, or Expression<...> types instead of custom delegates, when defining APIs with callbacks.

Func<...> and Action<...> represent generic delegates. Expression<...> represents function definitions that can be compiled and subsequently invoked at runtime but can also be serialized and passed to remote processes.

**✓ DO** measure and understand performance implications of using Expression<...>, instead of using Func<...> and Action<...> delegates.

Expression<...> types are in most cases logically equivalent to Func<...> and Action<...> delegates. The main difference between them is that the delegates are intended to be used in local process scenarios; expressions are intended for cases where it’s beneficial and possible to evaluate the expression in a remote process or machine.

**✓ DO** understand that by calling a delegate, you are executing arbitrary code and that could have security, correctness, and compatibility repercussions.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Designing for Extensibility](DesigningForExtensibility.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
