![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

As with other naming guidelines, the goal when naming namespaces is creating sufficient clarity for the programmer using the framework to immediately know what the content of the namespace is likely to be. The following template specifies the general rule for naming namespaces:
 
**`<Company>::(<Product>|<Technology>)[::<Feature>][::<Subnamespace>]`**

The following are examples:
 
**Fabrikam::Math**
 
**Litware::Security**
 
**√ DO** prefix namespace names with a company name to prevent namespaces from different companies from having the same name.
 
**√ DO** use a stable, version-independent product name at the second level of a namespace name.
 
**X DO NOT** use organisational hierarchies as the basis for names in namespace hierarchies, because group names within corporations tend to be short-lived. Organise the hierarchy of namespaces around groups of related technologies.
 
**√ DO** use PascalCasing, and separate namespace components with "::" (e.g., Microsoft::Office::PowerPoint). If your brand employs nontraditional casing, you should follow the casing defined by your brand, even if it deviates from normal namespace casing.
 
**√ CONSIDER** using plural namespace names where appropriate.
 
For example, use System::Collections instead of System::Collection. Brand names and acronyms are exceptions to this rule, however. For example, use System::IO instead of System::IOs.
 
**X DO NOT** use the same name for a namespace and a type in that namespace.
 
For example, do not use Debug as a namespace name and then also provide a class named Debug in the same namespace. Several compilers require such types to be fully qualified.
 
# Namespaces and Type Name Conflicts
 
**X DO NOT** introduce generic type names such as Element, Node, Log, and Message.
 
There is a very high probability that doing so will lead to type name conflicts in common scenarios. You should qualify the generic type names (FormElement, XmlNode, EventLog, SoapMessage).
 
There are specific guidelines for avoiding type name conflicts for different categories of namespaces.

* **Application model namespaces**

Namespaces belonging to a single application model are very often used together, but they are almost never used with namespaces of other application models. For example, the Switch::System::Windows::Forms namespace is very rarely used together with the Switch::System::Web::UI namespace. The following is a list of well-known application model namespace groups:
 
**System::Windows***
 
**System::Web::UI***
​​
# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Naming Guidelines](NamingGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
