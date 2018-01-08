![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

One common concern related to exceptions is that if exceptions are used for code that routinely fails, the performance of the implementation will be unacceptable. This is a valid concern. When a member throws an exception, its performance can be orders of magnitude slower. However, it is possible to achieve good performance while strictly adhering to the exception guidelines that disallow using error codes. Two patterns described in this section suggest ways to do this.

**X DO NOT** use error codes because of concerns that exceptions might affect performance negatively.

To improve performance, it is possible to use either the Tester-Doer Pattern or the Try-Parse Pattern, described in the next two sections.

# Tester-Doer Pattern

Sometimes performance of an exception-throwing member can be improved by breaking the member into two. Let’s look at the Add method of the System::Collections::Generic::ICollection<T> interface.

```c++
refptr<ICOllection<int>> numbers = ...
numbers->Add(1);
```

The method Add throws if the collection is read-only. This can be a performance problem in scenarios where the method call is expected to fail often. One of the ways to mitigate the problem is to test whether the collection is writable before trying to add a value.

```c++
refptr<ICOllection<int>> numbers = ...
...
if ((!numbers->IsReadOnly) {
  numbers->Add(1);
}
```

The member used to test a condition, which in our example is the property IsReadOnly, is referred to as the tester. The member used to perform a potentially throwing operation, the Add method in our example, is referred to as the doer.

**√ CONSIDER** the Tester-Doer Pattern for members that might throw exceptions in common scenarios to avoid performance problems related to exceptions.

# Try-parse Pattern

For extremely performance-sensitive APIs, an even faster pattern than the Tester-Doer Pattern described in the previous section should be used. The pattern calls for adjusting the member name to make a well-defined test case a part of the member semantics. For example, System::DateTime defines a Parse method that throws an exception if parsing of a string fails. It also defines a corresponding TryParse method that attempts to parse, but returns false if parsing is unsuccessful and returns the result of a successful parsing using an out parameter.

```c++
struct DateTime : public object {
public:
  static DateTime Parse(const string& dateTime) {
    ...
  }
 
  static bool TryParse(const string& dateTime, DateTime& result) {
    ...
  }
};
```

When using this pattern, it is important to define the try functionality in strict terms. If the member fails for any reason other than the well-defined try, the member must still throw a corresponding exception.

**√ CONSIDER** the Try-Parse Pattern for members that might throw exceptions in common scenarios to avoid performance problems related to exceptions.

**√ DO** use the prefix "Try" and Boolean return type for methods implementing this pattern.

**√ DO** provide an exception-throwing member for each member using the Try-Parse Pattern.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Design Guidelines for Exception](DesignGuidelinesForException.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
