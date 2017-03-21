/// @page NamesOfNamespacesPage Names of Namespace
/// As with other naming guidelines, the goal when naming namespaces is creating sufficient clarity for the programmer using the framework to immediately know what the content of the namespace is likely to be. The following template specifies the general rule for naming namespaces:
///
/// <b><Company>::(<Product>|<Technology>)[::<Feature>][::<Subnamespace>]</b>
///
/// The following are examples:
///
/// <b>Fabrikam::Math</b>
///
/// <b>Litware::Security</b>
///
/// <b>√ DO</b> prefix namespace names with a company name to prevent namespaces from different companies from having the same name.
///
/// <b>√ DO</b> use a stable, version-independent product name at the second level of a namespace name.
///
/// <b>X DO NOT</b> use organizational hierarchies as the basis for names in namespace hierarchies, because group names within corporations tend to be short-lived. Organize the hierarchy of namespaces around groups of related technologies.
///
/// <b>√ DO</b> use PascalCasing, and separate namespace components with "::" (e.g., Microsoft::Office::PowerPoint). If your brand employs nontraditional casing, you should follow the casing defined by your brand, even if it deviates from normal namespace casing.
///
/// <b>√ CONSIDER</b> using plural namespace names where appropriate.
///
/// For example, use System::Collections instead of System::Collection. Brand names and acronyms are exceptions to this rule, however. For example, use System::IO instead of System::IOs.
///
/// <b>X DO NOT</b> use the same name for a namespace and a type in that namespace.
///
/// For example, do not use Debug as a namespace name and then also provide a class named Debug in the same namespace. Several compilers require such types to be fully qualified.
///
/// @section NamespacesAndTypeNameConflictsSection Namespaces and Type Name Conflicts
///
/// <b>X DO NOT</b> introduce generic type names such as <b>Element</b>, <b>Node</b>, <b>Log</b>, and <b>Message</b>.
///
/// There is a very high probability that doing so will lead to type name conflicts in common scenarios. You should qualify the generic type names (<b>FormElement</b>, <b>XmlNode</b>, <b>EventLog</b>, <b>SoapMessage</b>).
///
/// There are specific guidelines for avoiding type name conflicts for different categories of namespaces.
/// * <b>Application model namespaces</b>
///
/// Namespaces belonging to a single application model are very often used together, but they are almost never used with namespaces of other application models. For example, the <b>Pcf::System::Windows::Forms</b> namespace is very rarely used together with the <b>Pcf::System::Web::UI</b> namespace. The following is a list of well-known application model namespace groups:
///
/// <b>System::Windows*</b>
///
/// <b>System::Web::UI*</b>
///
 <b>X DO NOT</b> give the same name to types in namespaces within a single application model.
///
/// For example, do not add a type named <b>Page</b> to the <b>Pcf::System::Web::UI::Adapters</b> namespace, because the <b>Pcf::System::Web::UI</b> namespace already contains a type named <b>Page</b>.
///
/// * <b>Infrastructure namespaces</b>
///
/// This group contains namespaces that are rarely imported during development of common applications. For example, ::Design namespaces are mainly used when developing programming tools. Avoiding conflicts with types in these namespaces is not critical.
///
/// * <b>Core namespaces</b>
///
/// Core namespaces include all System namespaces, excluding namespaces of the application models and the Infrastructure namespaces. Core namespaces include, among others, System, System::IO, System::Xml, and System::Net.
///
/// <b>X DO NOT</b> give types names that would conflict with any type in the Core namespaces.
///
/// For example, never use Stream as a type name. It would conflict with Pcf::System::IO::Stream, a very commonly used type.
///
/// * <b>Technology namespace groups</b>
///
/// This category includes all namespaces with the same first two namespace nodes (<Company>::<Technology>*), such as Microsoft::Build::Utilities and Microsoft::Build::Tasks. It is important that types belonging to a single technology do not conflict with each other.
///
/// <b>X DO NOT</b> assign type names that would conflict with other types within a single technology.
///
/// <b>X DO NOT</b> introduce type name conflicts between types in technology namespaces and an application model namespace (unless the technology is not intended to be used with the application model).
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref NamingGuidelinesPage
