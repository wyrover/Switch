![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

A library represent a unit for code programs. You can used a static link library (.lib) or dynamic link (.dll or .so). This section describes only LIB naming conventions, which then can be mapped to DLL naming conventions.

**√ DO** choose names for your libraries that suggest large chunks of functionality, such as System.Data.

Library and DLL names don’t have to correspond to namespace names, but it is reasonable to follow the namespace name when naming library. A good rule of thumb is to name the library based on the common prefix of the libraries contained in the library. For example, a library with two namespaces, MyCompany::MyTechnology::FirstFeature and MyCompany::MyTechnology::SecondFeature, could be called MyCompany.MyTechnology.lib.

**√ CONSIDER** naming libraries according to the following pattern:

`<Company>.<Component>.lib`

where <Component> contains one or more dot-separated clauses. For example:

**Switch.Core.lib**
​
# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Naming Guidelines](NamingGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
