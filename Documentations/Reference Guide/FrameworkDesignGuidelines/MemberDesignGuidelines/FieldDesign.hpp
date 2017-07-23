/// @page FieldDesignPage Field Design
/// The principle of encapsulation is one of the most important notions in object-oriented design. This principle states that data stored inside an object should be accessible only to that object.
///
/// A useful way to interpret the principle is to say that a type should be designed so that changes to fields of that type (name or type changes) can be made without breaking code other than for members of the type. This interpretation immediately implies that all fields must be private.
///
/// <b>X DO NOT</b> provide instance fields that are public or protected.
///
/// You should provide properties for accessing fields instead of making them public or protected.
///
/// <b>X DO NOT</b> use public static fields for predefined object instances.
///
/// If there are predefined instances of the type, declare them with public static Method of the type itself.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref MemberDesignGuidelinesPage
