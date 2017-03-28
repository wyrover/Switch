/// @page NamesOfTypeMembersPage Names of Type Members
/// Types are made of members: methods, properties, events, constructors, and fields. The following sections describe guidelines for naming type members.
///
/// @section NamesOfMethodsSection Names of Methods
/// Because methods are the means of taking action, the design guidelines require that method names be verbs or verb phrases. Following this guideline also serves to distinguish method names from property and type names, which are noun or adjective phrases.
///
/// <b>√ DO</b> give methods names that are verbs or verb phrases.
/// @code
/// class String : public object {
/// public:
///   int32 CompareTo(...);
///   Array<string> Split(...);
///   string Trim();
/// };
/// @endcode
///
/// @section NamesOfPropertiesSection Names of Properties
/// Unlike other members, properties should be given noun phrase or adjective names. That is because a property refers to data, and the name of the property reflects that. PascalCasing is always used for property names.
///
/// <b>√ DO</b> name properties using a noun, noun phrase, or adjective.
///
/// <b>X DO NOT</b> have properties that match the name of "Get" or "Set" methods as in the following example:
/// @code
/// string TextWriter() const { ... }
/// void TextWriter(const string& textWriter) { ... }
/// string GetTextWriter(int32 value) { ... }
/// @endcode
/// This pattern typically indicates that the property should really be a method.
///
/// <b>√ DO</b> name collection properties with a plural phrase describing the items in the collection instead of using a singular phrase followed by "List" or "Collection."
///
/// <b>√ DO</b> name Boolean properties with an affirmative phrase (CanSeek instead of CantSeek). Optionally, you can also prefix Boolean properties with "Is," "Can," or "Has," but only where it adds value.
///
/// <b>√ CONSIDER</b> giving a property the same name as its type.
///
/// For example, the following property correctly gets and sets an enum value named Color, so the property is named Color:
/// @code
/// class Color : public Enum {
///   ...
/// };
///
/// class Control : public object {
/// public:
///  Color Color() const { ... }
///  void Color(const Color& color) { ... }
/// };
/// @endcode
///
/// @section NamesOfEventsSection Names of Events
/// Events always refer to some action, either one that is happening or one that has occurred. Therefore, as with methods, events are named with verbs, and verb tense is used to indicate the time when the event is raised.
///
/// <b>√ DO</b> name events with a verb or a verb phrase.
///
/// Examples include Clicked, Painting, DroppedDown, and so on.
///
/// <b>√ DO</b> give events names with a concept of before and after, using the present and past tenses.
///
/// For example, a close event that is raised before a window is closed would be called Closing, and one that is raised after the window is closed would be called Closed.
///
/// <b>X DO NOT</b> use "Before" or "After" prefixes or postfixes to indicate pre- and post-events. Use present and past tenses as just described.
///
/// <b>√ DO</b> name event handlers (delegates used as types of events) with the "EventHandler" suffix, as shown in the following example:
///
/// @code
/// typedef Delegate<void, const object&, const ClickEventArgs&> ClickedEventHandler;
/// @endcode
/// <b>√ DO</b> use two parameters named sender and e in event handlers.
///
/// The sender parameter represents the object that raised the event. The sender parameter is typically of type object, even if it is possible to employ a more specific type.
///
/// <b>√ DO</b> name event argument classes with the "EventArgs" suffix.
///
/// @section NamesOfFieldsSection Names of Fields
/// The field-naming guidelines apply to static public and protected fields. Internal and private fields are not covered by guidelines, and public or protected instance fields are not allowed by the @ref MemberDesignGuidelinesPage.
///
/// <b>√ DO</b> use PascalCasing in field names.
///
/// <b>√ DO</b> name fields using a noun, noun phrase, or adjective.
///
/// <b>X DO NOT</b> use a prefix for field names.
///
/// For example, do not use "g_" or "s_" to indicate static fields.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref NamingGuidelinesPage
