/// @page FrameworkDesignGuidelinesPage Framework Design Guidelines
///
/// This section provides guidelines for designing libraries that extend and interact with the Pcf Framework. The goal is to help library designers ensure API consistency and ease of use by providing a unified programming model that is independent of the programming language used for development. We recommend that you follow these design guidelines when developing classes and components that extend the Pcf Framework. Inconsistent library design adversely affects developer productivity and discourages adoption.
/// The guidelines are organized as simple recommendations prefixed with the terms Do, Consider, Avoid, and Do not. These guidelines are intended to help class library designers understand the trade-offs between different solutions. There might be situations where good library design requires that you violate these design guidelines. Such cases should be rare, and it is important that you have a clear and compelling reason for your decision.
/// These guidelines are excerpted from the book Framework Design Guidelines: Conventions, Idioms, and Patterns for Reusable .NET Libraries, 2nd Edition, by Krzysztof Cwalina and Brad Abrams.
///
/// @section InThisSectionSection In This Section
///  * @ref NamingGuidelinesPage Provides guidelines for naming libraries, namespaces, types, and members in class libraries.
///  * @ref TypeDesignGuidelinesPage Provides guidelines for using static and abstract classes, interfaces, enumerations, structures, and other types.
///  * @ref MemberDesignGuidelinesPage Provides guidelines for designing and using properties, methods, constructors, fields, events, operators, and parameters.
///  * @ref DesigningForExtensibilityPage Discusses extensibility mechanisms such as subclassing, using events, virtual members, and callbacks, and explains how to choose the mechanisms that best meet your framework's requirements.
///  * @ref DesignGuidelinesForExceptionsPage Describes design guidelines for designing, throwing, and catching exceptions.
///  * @ref UsageGuidelinesPage Describes guidelines for using common types such as arrays, attributes, and collections, supporting serialization, and overloading equality operators.
///
/// @section ReferenceSection Reference
/// This Guideline is based on Microsoft .Net Framework Design Guidelines.
///
/// http://msdn.microsoft.com/en-us/library/ms229042.aspx
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
