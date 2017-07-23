/// @page NamesOfLibrariesAndDLLsPage Names of Libraries and DLLs
/// A library represent a unit for code programs. You can used a static link library (.lib) or dynamic link (.dll or .so). This section describes only LIB naming conventions, which then can be mapped to DLL naming conventions.
///
/// <b>√ DO</b> choose names for your libraries that suggest large chunks of functionality, such as System.Data.
///
/// Library and DLL names don’t have to correspond to namespace names, but it is reasonable to follow the namespace name when naming library. A good rule of thumb is to name the library based on the common prefix of the libraries contained in the library. 
/// For example, a library with two namespaces, <b>MyCompany::MyTechnology::FirstFeature</b> and <b>MyCompany::MyTechnology::SecondFeature</b>, could be called <b>MyCompany.MyTechnology.lib</b>.
///
/// <b>√ CONSIDER</b> naming libraries according to the following pattern:
///
/// </b><Company>.<Component>.lib</b>
///
/// where <Component> contains one or more dot-separated clauses. For example:
///
/// <b>Pcf.Core.lib.</b>
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref NamingGuidelinesPage
