![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

One important aspect of designing a framework is making sure the extensibility of the framework has been carefully considered. This requires that you understand the costs and benefits associated with various extensibility mechanisms. This chapter helps you decide which of the extensibility mechanisms—subclassing, events, virtual members, callbacks, and so on—can best meet the requirements of your framework.

There are many ways to allow extensibility in frameworks. They range from less powerful but less costly to very powerful but expensive. For any given extensibility requirement, you should choose the least costly extensibility mechanism that meets the requirements. Keep in mind that it’s usually possible to add more extensibility later, but you can never take it away without introducing breaking changes.

# In This Section

* [Unsealed Classes](UnsealedClasses.md)
* [Protected Members](ProtectedMembers.md)
* [Events and Callbacks](EventsAndCallbacks.md)
* [Virtual Members](VirtualMembers.md)
* [Abstractions (Abstract Types and Interfaces)](AbstractionsAbstractTypesAndInterfaces.md)
* [Base Classes for Implementing Abstractions](BaseClassesForImplementingAbstractions.md)
* [Sealing](Sealing.md)

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
