/// @page DesigningForExtensibilityPage Designing for Extensibility
///
/// One important aspect of designing a framework is making sure the extensibility of the framework has been carefully considered. This requires that you understand the costs and benefits associated with various extensibility mechanisms. This chapter helps you decide which of the extensibility mechanisms—subclassing, events, virtual members, callbacks, and so on—can best meet the requirements of your framework.
///
/// There are many ways to allow extensibility in frameworks. They range from less powerful but less costly to very powerful but expensive. For any given extensibility requirement, you should choose the least costly extensibility mechanism that meets the requirements. Keep in mind that it’s usually possible to add more extensibility later, but you can never take it away without introducing breaking changes.
///
/// @section InThisSectionSection In This Section
/// * @ref UnsealedClassesPage
/// * @ref ProtectedMembersPage
/// * @ref EventsAndCallbacksPage
/// * @ref VirtualMembersPage
/// * @ref AbstractionsPage
/// * @ref BaseClassesForImplementingAbstractionsPage
/// * @ref SealingPage
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
