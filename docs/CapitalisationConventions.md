![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

The guidelines in this chapter lay out a simple method for using case that, when applied consistently, make identifiers for types, members, and parameters easy to read.
 
# Capitalisation Rules for Identifiers
​
To differentiate words in an identifier, capitalise the first letter of each word in the identifier. Do not use underscores to differentiate words, or for that matter, anywhere in identifiers. There are two appropriate ways to capitalise identifiers, depending on the use of the identifier:

* PascalCasing
* camelCasing
 
The PascalCasing convention, used for all identifiers except parameter and member names, capitalises the first character of each word (including acronyms over two letters in length), as shown in the following examples: 


```c++
​​PropertyDescriptor
HtmlTag
```

A special case is made for two-letter acronyms in which both letters are capitalised, as shown in the following identifier:

```c++
IOStream
```

The camelCasing convention, used only for parameter and member names, capitalises the first character of each word except the first word, as shown in the following examples. As the example also shows, two-letter acronyms that begin a camel-cased identifier are both lowercase.

```c++
propertyDescriptor
ioStream
htmlTag
```

**√ DO** use PascalCasing for all public member, type, and namespace names consisting of multiple words.

**√ DO** use camelCasing for parameter names.
The following list describes the capitalisation rules for different types of identifiers.

* **Naming** : PascalCasing

```c++
namespace System {
  Threading {
    ...
  }
}
```

* **Type** : PascalCasing

```c++
namespace System {
  Threading {
    ...
  }
}
```

* **Interface** : PascalCasing

```c++
class IEnumerable interface_ {
  ...
};
```

* **Method** : PascalCasing

```c++
class Object {
public:
  virtual string ToString() const;
};
```

* **Property** : PascalCasing

```c++
class String : public object {
public:
  property_<int> Length {
    get_ {return this->length;},
    set_ {this->length = value;}
  }
};
```

* **Event** : PascalCasing

```c++
class Process : public object {
public:
  EventHandler Exited;
};
```

* **Field** : PascalCasing

```c++
struct UInt32 : public object {
public:
  static const uint Min = 0;
};
```

* **Enum Value** : PascalCasing

```c++
enum class Values {
  Append,
  ...
};
```

* **Parameters** : camelCasing

```c++
class Convert {
public:
  static int ToInt32(const string& value);
};
```

* **Members** : camelCasing

```c++
struct UInt32 : public object {
public:
  ...
private:
  uint value;
};
 
struct DateTime : public object {
public:
  ...
private:
  int64 value;
  DateTimeKind kind;
  ...
};
```

# Capitalising Compound Words and Common Terms
​
Most compound terms are treated as single words for purposes of capitalisation.
 
**X DO NOT** capitalise each word in so-called closed-form compound words.
​
These are compound words written as a single word, such as endpoint. For the purpose of casing guidelines, treat a closed-form compound word as a single word. Use a current dictionary to determine if a compound word is written in closed form. ​​

| Pascal      | Camel       | Not                |
|-------------|-------------|--------------------|
| BitFlag     | bitFlag     | Bitflag            |
| Callback    | callback    | CallBack           |
| Canceled    | canceled    | Cancelled          |
| DoNot       |doNot        | Don't              |
| Email       | email       | EMail              |
| Endpoint    | endpoint    | EndPoint           |
| FileName    | fileName    | Filename           |
| Gridline    | gridline    | GridLine           |
| Hashtable   | hashtable   | HashTable          |
| Id          | id.         | ID                 |
| Indexes     | indexes     | indices            |
| LogOff      | logOff      | LogOut             |
| LogOn       | logOn       | LogIn              |
| Metadata    | metadata    | MetaData, metaData |
| Multipanel  | multipanel  | MultiPanel         |
| Multiview   | multiview   | MultiView          |
| Namespace   | namespace   | NameSpace          |
| Ok          | ok          | OK                 |
| Pi          | pi          | PI                 |
| Placeholder | placeholder | PlaceHolder        |
| SignIn      | singIn      | SignOn             |
| SignOut     | signOut     | SignOff            |
| UserName    | userName    | Username           |
| WhiteSpace  | whiteSpace  | Whitespace         |
| Writable    | writable    | Writeable          |

# Case Sensitivity
​
C++ are case-sensitivity. Even if your language supports it, other languages that might access your framework do not. Any APIs that are externally accessible, therefore, cannot rely on case alone to distinguish between two names in the same context.
 
**X DO NOT** assume that all programming languages are case sensitive. They are not. Names cannot differ by case alone.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Naming Guidelines](NamingGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
