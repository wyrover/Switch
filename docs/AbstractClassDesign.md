![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

**X DO NOT** define public or protected internal constructors in abstract types.

Constructors should be public only if users will need to create instances of the type. Because you cannot create instances of an abstract type, an abstract type with a public constructor is incorrectly designed and misleading to the users.

**√ DO** define a protected or an internal constructor in abstract classes.

A protected constructor is more common and simply allows the base class to do its own initialization when subtypes are created.

An internal constructor can be used to limit concrete implementations of the abstract class to the assembly defining the class.

**√ DO** provide at least one concrete type that inherits from each abstract class that you ship.

Doing this helps to validate the design of the abstract class. For example, System::IO::FileStream is an implementation of the System::IO::Stream abstract class.

```c++
namespace System {
  namespace IO {
    class Stream abstract_ {
      public:
      virtual int Read(const Array<byte>& buffer, int offset, int count) const = 0;
      ...
    };
 
    class FileStream : public Stream {
    public:
      int Read(const Array<byte>& buffer, int offset, int count) const override {
        ...
      }
 
       ...
    };
  }
}
```

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Type Design Guidelines](TypeDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
