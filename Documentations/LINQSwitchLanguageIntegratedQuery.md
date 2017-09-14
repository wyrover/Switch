![Switch Header](Images/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# Summary

Switch Language-Integrated Query
Getting Started with Standard Query Operators
Language Features Supporting the LINQ Project

# Switch Language-Integrated Query

After two decades, the industry has reached a stable point in the evolution of object-oriented (OO) programming technologies. Programmers now take for granted features like classes, objects, and methods. In looking at the current and next generation of technologies, it has become apparent that the next big challenge in programming technology is to reduce the complexity of accessing and integrating information that is not natively defined using OO technology. The two most common sources of non-OO information are relational databases and XML.

Rather than add relational or XML-specific features to our programming languages and runtime, with the LINQ project we have taken a more general approach and are adding general-purpose query facilities to the Switch that apply to all sources of information, not just relational or XML data. This facility is called Switch Language-Integrated Query (LINQ).

We use the term language-integrated query to indicate that query is an integrated feature of the developer's primary programming languages. Language-integrated query allows query expressions to benefit from the rich metadata, compile-time syntax checking, static typing and IntelliSense that was previously available only to imperative code. Language-integrated query also allows a single general purpose declarative query facility to be applied to all in-memory information, not just information from external sources.

Switch Language-Integrated Query defines a set of general purpose standard query operators that allow traversal, filter, and projection operations to be expressed in a direct yet declarative way in any Switch-based programming language. The standard query operators allow queries to be applied to any IEnumerable<T>-based information source. LINQ allows third parties to augment the set of standard query operators with new domain-specific operators that are appropriate for the target domain or technology. More importantly, third parties are also free to replace the standard query operators with their own implementations that provide additional services such as remote evaluation, query translation, optimization, and so on. By adhering to the conventions of the LINQ pattern, such implementations enjoy the same language integration and tool support as the standard query operators.

The extensibility of the query architecture is used in the LINQ project itself to provide implementations that work over both XML and SQL data. The query operators over XML (LINQ to XML) use an efficient, easy-to-use, in-memory XML facility to provide XPath/XQuery functionality in the host programming language. The query operators over relational data (LINQ to SQL) build on the integration of SQL-based schema definitions into the common language runtime (CLR) type system. This integration provides strong typing over relational data while retaining the expressive power of the relational model and the performance of query evaluation directly in the underlying store.

# Getting Started with Standard Query Operators

To see language-integrated query at work, we'll begin with a simple Switch program that uses the standard query operators to process the contents of an array:

```c++
#include <Switch/Switch>
​
using namespace System;
using namespace System::Linq;
using namespace System::Collections::Generic;
 
namespace Examples {
  class Program {
  public:
    // The main entry point for the application.
    static void Main() {
      Array<string> names = { "Burke", "Connor", "Frank", "Everett", "Albert", "George", "Harris", "David" };
      refptr<IEnumerable<string>> query = from<string>(names)
                                          | where<string>(_delegate(string s) {return s.Length == 5;})
                                          | orderby<string>(_delegate(string s) {return s;})
                                          | select<string>(_delegate(string s) {return s.ToUpper();});
​
      for (string item : *query)
        Console::WriteLine(item);
    }
  };
}
​
_startup (Examples::Program)
```

If you were to compile and run this program, you'd see this as output:

```c++

BURKE
DAVID
FRANK
 
To understand how language-integrated query works, we need to dissect the
first statement of our program.
 
  refptr<IEnumerable<string>> query = from<string>(names)
                                      | where<string>(_delegate(string s) {return s.Length == 5;})
                                      | orderby<string>(_delegate(string s) {return s;})
                                      | select<string>(_delegate(string s) {return s.ToUpper();});
```

The local variable query is initialized with a query expression. A query expression operates on one or more information sources by applying one or more query operators from either the standard query operators or domain-specific operators. This expression uses three of the standard query operators: Where, OrderBy, and Select.

C++ statements shown here use query expressions. Like the foreach statement, query expressions are convenient declarative shorthand over code you could write manually. The statements above are semantically identical to the following explicit syntax shown in c++: 

```c++
refptr<IEnumerable<string>> query = names.Where(_delegate(string s) {return s.Length == 5;})
                                    ->OrderBy<string>(_delegate(string s) {return s;})
                                    ->Select<string>(_delegate(string s) {return s.ToUpper();});
```

This form of query is called a method-based query. The arguments to the Where, OrderBy, and Select operators are called lambda expressions, which are fragments of code much like delegates. They allow the standard query operators to be defined individually as methods and strung together using dot notation. Together, these methods form the basis for an extensible query language.

# Language Features Supporting the LINQ Project

LINQ is built entirely on general purpose language features, some of which are new to Switch. Each of these features has utility on its own, yet collectively these features provide an extensible way to define queries and queryable APIs. In this section we explore these language features and how they contribute to a much more direct and declarative style of queries. 

# Lambda Expressions and Expression Trees

Many query operators allow the user to provide a function that performs filtering, projection, or key extraction. The query facilities build on the concept of lambda expressions, which provide developers with a convenient way to write functions that can be passed as arguments for subsequent evaluation. Lambda expressions are similar to CLR delegates and must adhere to a method signature defined by a delegate type. To illustrate this, we can expand the statement above into an equivalent but more explicit form using the Func delegate type:

```c++
Func<string, bool> filter = _delegate(string s) {
  return s.Length == 5;
};
​
Func<string, string> extract = _delegate(string s) {
  return s;
};
 
Func<string, string> project = _delegate(string s) {
  return s.ToUpper();
};
 
refptr<IEnumerable<string>> query = names.Where(filter)
                                    ->OrderBy<string>(extract)
                                    ->Select<string>(project);
```

Delegates are function pointer evolution. For example, we could have written the previous example using function pointer like this:

```c++
bool Filter(string s) {
  return s.Length == 5;
}
​
string Extract(string s) {
  return s;
}
​
string Project(string s) {
  return s.ToUpper();
}
​
refptr<IEnumerable<string>> query = names.Where(&Filter)
                                    ->OrderBy<string>(&Extract)
                                    ->Select<string>(&Project);
```

In general, the developer is free to use named methods, anonymous methods, or lambda expressions with query operators. Lambda expressions have the advantage of providing the most direct and compact syntax for authoring. More importantly, lambda expressions can be compiled as either code or data, which allows lambda expressions to be processed at runtime by
optimizers, translators, and evaluators.

# See also
​
Other Resources

* [Articles and Overviews](ArticlesAndOverviews.md)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
