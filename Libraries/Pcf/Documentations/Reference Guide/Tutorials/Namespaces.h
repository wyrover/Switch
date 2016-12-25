/// @page TutorialNamespacesPage Namespaces
///
/// This tutorial describes how to define and use namespaces.
///
/// @section TutorialSection Tutorial
/// This tutorial is divided into the following sections:
///   * @ref NamespacesInGeneralSection
///   * @ref NamespaceDeclarationSection
///   * @ref NamespaceAliasSection
///   * @ref UnamedNamespacesSection
///   * @ref DefiningNamespaceMembersSection
///   * @ref UsingDeclarationSection
///   * @ref UsingDirectiveSection
///   * @ref ExplicitQualificationSection
///
/// @section NamespacesInGeneralSection Namespaces in General
///
/// The C++ language provides a single global namespace. This can cause problems with global name clashes. For instance, consider these two C++ header files:
/// @code
/// uchar Func(uchar);
/// class String { ... };
///
/// // Pcf.h
/// class String : public object { ... };
/// @endcode
/// With these definitions, it is impossible to use both header files in a single program; the String classes will clash.
///
/// A namespace is a declarative region that attaches an additional identifier to any names declared inside it. The additional identifier makes it less likely that a name will conflict with names declared elsewhere in the program. It is possible to use the same name in separate namespaces without conflict even if the names appear in the same translation unit. As long as they appear in separate namespaces, each name will be unique because of the addition of the namespace identifier.
/// For example:
/// @code
/// namespace one {
///   uchar Func(uchar);
///   class String { ... };
/// }
///
/// // Pcf.h
/// namespace System {
///   class String : public object { ... };
/// }
/// @endcode
/// Now the class names will not clash because they become one::String and System::String, respectively.
///
/// @section NamespaceDeclarationSection namespace Declaration
/// A namespace declaration identifies and assigns a unique name to a user-declared namespace.
/// @code
/// namspace identifier
/// @endcode
/// @remarks
/// Such namespaces are used to solve the problem of name collision in large programs and libraries. Programmers can use namespaces to develop new software components and libraries without causing naming conflicts with existing components.
///
/// For example:
/// @code
/// // NamespaceDeclaration1.cpp
/// #include <Pcf/Pcf>
///
/// namespace X {
///   int32 i;
///   double j;
/// }
///
/// class Program {
/// public:
///   static void Main() {
///     X::i++;
///   }
/// }
///
/// pcf_startup(Program)
/// @endcode
///
/// The syntax for a namespace definition is:
/// @code
/// namespace identifier {
///   [ declaration-list ]
/// }
/// @endcode
/// A namespace-definition can be nested within another namespace-definition. Every namespace-definition must appear either at file scope or immediately within another namespace-definition.
///
/// For example:
/// @code
/// // NamespaceDeclaration2.cpp
/// // C2870 expected
/// #include <Pcf/Pcf>
///
/// namespace A {
///   int32 j = 3;
///   int32 f(int32 k);
/// }
///
/// namespace Outer {
///   int32 n = 6;
///   int32 Func(int32 num);
///
///   namespace Inner {
///     single f = 9.993;
///   }
/// }
///
/// class Program {
/// public:
///   static void Main() {
///     namespace local {  // C2870: not at global scope
///   }
/// }
///
/// pcf_startup(Program)
/// @endcode
///
///
/// Unlike other declarative regions, the definition of a namespace can be split over several parts of a single translation unit.
/// @code
/// // NamespaceDeclaration3.cpp
/// namespace A {
///   // declare namespace A variables
///   int32 i;
///   int32 j;
/// }
///
/// namespace B {
/// }
///
/// namespace A {
///   // declare namespace A functions
///   void Func(void);
///   int32 Int32Func(int32 i);
/// }
///
/// class Program {
/// public:
///   static void Main() {
///   }
/// }
///
/// pcf_startup(Program)
/// @endcode
///
/// When a namespace is continued in this manner, after its initial definition, the continuation is called an extension namespace definition. The original definition of that namespace is known as an original namespace definition.
/// Usage of this notation might be cumbersome with longer names or in large programs. The using declaration, using directive, and namespace aliases provide more straightforward ways to reference namespace members.
/// A namespace declaration, whether it involves a new namespace, an unnamed namespace, or an extended namespace definition, must be accompanied by a namespace body enclosed within curly braces. The statement
/// @code
/// namspace X;
/// @endcode
/// is a syntax error, The statement
/// @code
/// namespace X{};
/// @endcode
/// is not a syntax error, but is meaningless.
///
/// The identifier in an original namespace definition must be unique in the declarative region in which it is used. The identifier is the name of the namespace and is used to reference its members.
///
/// The declarative region of a namespace definition is its body. The body must be enclosed in curly braces ({}) and may contain declarations or definitions of variables, functions, objects, templates, and nested namespaces. The declarations in the declaration-list are said to be members of the namespace. The name of each namespace member is automatically qualified by the name of its namespace and the scope resolution operator.
///
/// @section NamespaceAliasSection namespace Alias
/// A namespace alias is an alternative name for a namespace.
/// @code
/// namespace identifier = [::] [nested-name-specifier] namespace-name;
/// @endcode
///
/// @remarks
/// A namespace alias definition declares an alternate name for a namespace. The identifier is a synonym for the specified namespace and becomes a namespace alias. For example:
/// @code
/// namespace AVeryLongNamespaceName { ... }
/// namespace AVLName = AVeryLongNamespaceName;
/// // AVLName is now a namespace-alias for AVeryLongNamespaceName.
/// @endcode
/// A namespace name or alias must be different from all other identifiers in its declarative region. A global namespace name or alias must be different from all other global entity names in the program.
///
/// @section ReferenceSection Reference
/// This tutorial is based on MSDN Namespaces (C++)
/// http://msdn.microsoft.com/en-us/library/5cb46ksf.aspx
