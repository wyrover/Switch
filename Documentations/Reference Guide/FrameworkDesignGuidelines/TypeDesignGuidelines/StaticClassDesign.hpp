/// @page StaticClassDesignPage Static Class Design
/// A static class is defined as a class that contains only static members (of course besides the instance members inherited from Pcf::System.Object and possibly a private constructor). C++ languages do not provide built-in support for static classes.
///
/// Static classes are a compromise between pure object-oriented design and simplicity. They are commonly used to provide shortcuts to other operations (such as Pcf::System::IO::File), holders of extension methods, or functionality for which a full object-oriented wrapper is unwarranted (such as Pcf::System::Environment).
///
/// <b>√ DO</b> use static classes sparingly.
///
/// Static classes should be used only as supporting classes for the object-oriented core of the framework.
///
/// <b>X DO NOT</b> treat static classes as a miscellaneous bucket.
///
/// <b>X DO NOT</b> declare or override instance members in static classes.
///
/// <b>√ DO</b> declare static classes as abstract, and add a private instance constructor for C++ language does not have built-in support for static classes.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref TypeDesignGuidelinesPage
