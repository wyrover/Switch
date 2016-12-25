/// @brief Mark a method deprecated
/// @param message Message that may inform the users of the deprecated entity. This message must be given as a string literal.
/// @code
/// class DateTime : :public object {
/// public:
///   ...
///   DateTime Date() const { return this->date; }
///   Deprecated("Replaced by Pcf::System::DateTime::Date()")
///   DateTime GetDate() const { return Date(); }
///   ...
/// };
/// @ingroup Corelib
#define Deprecated \
  pcf_deprecated
