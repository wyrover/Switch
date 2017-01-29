/// @page GeneralNamingConventionsPage General Naming Conventions
/// This section describes general naming conventions that relate to word choice, guidelines on using abbreviations and acronyms, and recommendations on how to avoid using c++ names.
///
/// @section WordChoiceSection Word Choice
/// <b>√ DO</b> choose easily readable identifier names.
///
/// For example, a property named HorizontalAlignment is more English-readable than AlignmentHorizontal.
///
/// <b>√ DO</b> favor readability over brevity.
///
/// The property name CanScrollHorizontally is better than ScrollableX (an obscure reference to the X-axis).
///
/// <b>X DO NOT</b> use underscores, hyphens, or any other nonalphanumeric characters.
///
/// <b>X DO NOT</b> use Hungarian notation.
///
/// X AVOID using identifiers that conflict with keywords of widely used programming languages.
///
/// @section UsingAbbreviationsAndAcronymsSection Using Abbreviations and Acronyms
///
/// <b>X DO NOT</b> use abbreviations or contractions as part of identifier names.
///
/// For example, use GetWindow rather than GetWin.
///
/// <b>X DO NOT</b> use any acronyms that are not widely accepted, and even if they are, only when necessary.
///
/// @section AvoidingCppNamesSection Avoiding C++ Names
/// <b>√ DO</b> use semantically interesting names rather than language-specific keywords for type names.
///
/// For example, GetLength is a better name than GetInt.
///
/// <b>√ DO</b> use a generic Pcf type name, rather than a C++ name, in the rare cases when an identifier has no semantic meaning beyond its type.
///
/// For example, a method converting to int64 should be named ToInt64, not ToLong (because int64 is a Pcf name for the c++ alias long long). The following table presents several base data types using the Pcf type names (as well as the corresponding type names for all platform).
///
/// | C++                | Pcf    | Size in bytes |
/// |--------------------| -------| --------------|
/// | char               | sbyte  |             1 |
/// | unsigned char      | byte   |             1 |
/// | short              | int16  |             2 |
/// | unsigned short     | uint16 |             2 |
/// | int                | int32  |             4 |
/// | unsigned int       | uint32 |             4 |
/// | long long          | int64  |             8 |
/// | unsigned long long | uint64 |             8 |
/// | float              | single |             4 |
/// | double             | double |             8 |
/// | bool               | bool   |             1 |
/// | wchar_t            | char32 |             4 |
/// | char*              | string |      variable |
///
/// <b>√ DO</b> use a common name, such as value or item, rather than repeating the type name, in the rare cases when an identifier has no semantic meaning and the type of the parameter is not important.
///
/// For more information about types see @ref TypesPage.
///
/// @section NamingNewVersionsOfExistingApisSetion Naming New Versions of Existing APIs
///
/// <b>√ DO</b> use a name similar to the old API when creating new versions of an existing API.
///
/// This helps to highlight the relationship between the APIs.
///
/// <b>√ DO</b> prefer adding a suffix rather than a prefix to indicate a new version of an existing API.
///
/// This will assist discovery when browsing documentation, or using Intellisense. The old version of the API will be organized close to the new APIs, because most browsers and Intellisense show identifiers in alphabetical order.
///
/// <b>√ CONSIDER</b> using a brand new, but meaningful identifier, instead of adding a suffix or a prefix.
///
/// <b>√ DO</b> use a numeric suffix to indicate a new version of an existing API, particularly if the existing name of the API is the only name that makes sense (i.e., if it is an industry standard) and if adding any meaningful suffix (or changing the name) is not an appropriate option.
///
/// <b>X DO NOT</b> use the "Ex" (or a similar) suffix for an identifier to distinguish it from an earlier version of the same API.
///
/// <b>√ DO</b> use the "64" suffix when introducing versions of APIs that operate on a 64-bit integer (a long integer) instead of a 32-bit integer. You only need to take this approach when the existing 32-bit API exists; don’t do it for brand new APIs with only a 64-bit version.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref NamingGuidelinesPage
