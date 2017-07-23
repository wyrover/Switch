/// @page CapitalizationConventionsPage Capitalization Conventions
///
/// The guidelines in this chapter lay out a simple method for using case that, when applied consistently, make identifiers for types, members, and parameters easy to read.
///
/// @section CapitalizationRulesForIdentifiersSection Capitalization Rules for Identifiers
/// To differentiate words in an identifier, capitalize the first letter of each word in the identifier. Do not use underscores to differentiate words, or for that matter, anywhere in identifiers. There are two appropriate ways to capitalize identifiers, depending on the use of the identifier:
/// * \b PascalCasing
/// * \b camelCasing
///
/// The PascalCasing convention, used for all identifiers except parameter and member names, capitalizes the first character of each word (including acronyms over two letters in length), as shown in the following examples:
/// @code
/// PropertyDescriptor
/// HtmlTag 
/// @endcode
///
/// A special case is made for two-letter acronyms in which both letters are capitalized, as shown in the following identifier:
/// @code
/// IOStream
/// @endcode
///
/// The camelCasing convention, used only for parameter and member names, capitalizes the first character of each word except the first word, as shown in the following examples. As the example also shows, two-letter acronyms that begin a camel-cased identifier are both lowercase.
/// @code
/// propertyDescriptor
/// ioStream
/// htmlTag 
/// @endcode
///
/// <b>√ DO</b> use PascalCasing for all public member, type, and namespace names consisting of multiple words.
///
/// <b>√ DO</b> use camelCasing for parameter names.
///
/// The following list describes the capitalization rules for different types of identifiers.
/// 
/// * <b>Namespace :</b> PascalCasing
/// @code
/// namespace System {
///   Threading {
///     ...
///   }
/// }
/// @endcode
///
/// * <b>Type :</b> PascalCasing
/// @code
/// class StreamReader : public object {
///   ...
/// };
/// @endcode
///
/// * <b>Interface :</b> PascalCasing
/// @code
/// class IEnumerable : public Interface {
///   ... 
/// };
/// @endcode
///
/// * <b>Method :</b> PascalCasing
/// @code
/// class Object {
/// public:
///   virtual string ToString() const;
/// };
/// @endcode
///
/// * <b>Property :</b> PascalCasing
/// @code
/// class String : public object {
/// public:
///   Property<int32> Length {
///     pcf_get {return this->length;},
///     pcf_set {this->length = value;}
///   )
/// };
/// @endcode
///
/// * <b>Event :</b> PascalCasing
/// @code
/// class Process : public object {
/// public:
///   EventHandler Exited;
/// };
/// @endcode
///
/// * <b>Field :</b>  PascalCasing
/// @code
/// struct UInt32 : public object {
/// public:
///   static const uint32 Min = 0;
/// };
/// @endcode
///
/// * <b>Enum Value :</b> PascalCasing
/// @code
/// enum class Values {
///   Append,
///   ...
/// };
/// @endcode
///
/// * <b>Parameter :</b> camelCasing
/// @code
/// class Convert {
/// public:
///   static int32 ToInt32(const string& value);
/// };
/// @endcode
///
/// * <b>Member :</b> camelCasing
/// @code
/// struct UInt32 : public object {
/// public:
/// ...
/// private:
///   uint32 value;
/// };
///
/// struct DateTime : public object {
/// public:
/// ...
/// private:
///   int64 value;
///   DateTimeKind kind;
/// ...
/// };
/// @endcode
///
/// @section CapitalizingCompoundWordsAndCommonTermsSection  Capitalizing Compound Words and Common Terms
/// Most compound terms are treated as single words for purposes of capitalization.
///
/// <b>X DO NOT</b> capitalize each word in so-called closed-form compound words.
///
/// These are compound words written as a single word, such as endpoint. For the purpose of casing guidelines, treat a closed-form compound word as a single word. Use a current dictionary to determine if a compound word is written in closed form.
/// | Pascal      | Camel       | Not                |
/// |-------------|-------------|--------------------|
/// | BitFlag     | bitFlag     | Bitflag            |
/// | Callback    | callback    | CallBack           |
/// | Canceled    | canceled    | Cancelled          |
/// | DoNot       | doNot       | Don't              |
/// | Email       | email       | EMail              |
/// | Endpoint    | endpoint    | EndPoint           |
/// | FileName    | fileName    | Filename           |
/// | Gridline    | gridline    | GridLine           |
/// | Hashtable   | hashtable   | HashTable          |
/// | Id          | id          | ID                 |
/// | Indexes     | indexes     | Indices            |
/// | LogOff      | logOff      | LogOut             |
/// | LogOn       | logOn       | LogIn              |
/// | Metadata    | metadata    | MetaData, metaData |
/// | Multipanel  | multipanel  | MultiPanel         |
/// | Multiview   | multiview   | MultiView          |
/// | Namespace   | namespace   | NameSpace          |
/// | Ok          | ok          | OK                 |
/// | Pi          | pi          | PI                 |
/// | Placeholder | placeholder | PlaceHolder        |
/// | SignIn      | signIn      | SignOn             |
/// | SignOut     | signout     | SignOff            |
/// | UserName    | userName    | Username           |
/// | WhiteSpace  | whiteSpace  | Whitespace         |
/// | Writable    | writable    | Writeable          |
///
/// @section CaseSensitivitySection Case Sensitivity
/// C++ are case-sensitivity. Even if your language supports it, other languages that might access your framework do not. Any APIs that are externally accessible, therefore, cannot rely on case alone to distinguish between two names in the same context.
///
/// <b>X DO NOT</b> assume that all programming languages are case sensitive. They are not. Names cannot differ by case alone.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref NamingGuidelinesPage
