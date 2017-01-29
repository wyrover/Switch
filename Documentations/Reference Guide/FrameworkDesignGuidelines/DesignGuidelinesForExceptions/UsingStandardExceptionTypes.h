/// @page UsingStandardExceptionTypesPage Using Standard Exception Types
///
/// This section describes the standard exceptions provided by the Framework and the details of their usage. The list is by no means exhaustive. Please refer to the Pcf Framework reference documentation for usage of other Framework exception types.
///
/// @section ExceptionAndSystemExceptionSection Exception and SystemException
///
/// <b>X DO NOT</b> throw Pcf::System::Exception or Pcf::System::SystemException.
///
/// <b>X DO NOT</b> catch Pcf::System::Exception or Pcf::System::SystemException in framework code, unless you intend to rethrow.
///
/// X AVOID catching Pcf::System::Exception or Pcf::System::SystemException, except in top-level exception handlers.
///
/// @section ApplicationException ApplicationException
///
/// <b>X DO NOT</b> throw or derive from ApplicationException.
///
/// @section InvalidOperationExceptionSection InvalidOperationException
///
/// <b>√ DO</b> throw an InvalidOperationException if the object is in an inappropriate state.
///
/// @section ArgumentExceptionArgumentNullExceptionArgumentOutOfRangeExceptionSection ArgumentException, ArgumentNullException, and Pcf::System::ArgumentOutOfRangeException
///
/// <b>√ DO</b> throw Pcf::System::ArgumentException or one of its subtypes if bad arguments are passed to a member. Prefer the most derived exception type, if applicable.
///
/// <b>√ DO</b> set the ParamName property when throwing one of the subclasses of ArgumentException.
///
/// This property represents the name of the parameter that caused the exception to be thrown. Note that the property can be set using one of the constructor overloads.
///
/// <b>√ DO</b> use value for the name of the implicit value parameter of property setters.
///
/// @section NullReferenceExceptionIndexOutOfRangeExceptionAndAccessViolationExceptionSection NullReferenceException, NullPointerException, IndexOutOfRangeException, and AccessViolationException
///
/// <b>X DO NOT</b> allow publicly callable APIs to explicitly or implicitly throw Pcf::System::NullReferenceException, Pcf::System::NullPointerException, Pcf::System::AccessViolationException, or Pcf::System::IndexOutOfRangeException. These exceptions are reserved and thrown by the execution engine and in most cases indicate a bug.
///
/// Do argument checking to avoid throwing these exceptions. Throwing these exceptions exposes implementation details of your method that might change over time.
///
/// @section StackOverflowException StackOverflowException
///
/// <b>X DO NOT</b> explicitly throw Pcf::System::StackOverflowException. The exception should be explicitly thrown only by the Operating System.
///
/// <b>X DO NOT</b> catch Pcf::System::StackOverflowException.
///
/// It is almost impossible to write code that remains consistent in the presence of arbitrary stack overflows.
///
/// @section OutOfMemoryExceptionSection OutOfMemoryException
///
/// <b>X DO NOT</b> explicitly throw Pcf::System::OutOfMemoryException. This exception is to be thrown only by the Pcf infrastructure.
///
/// @section ComExceptionSEHExceptionAndExecutionEngineExceptionSection ComException, SEHException, and ExecutionEngineException
///
/// <b>X DO NOT</b> explicitly throw Pcf::System::COMException, Pcf::System::ExecutionEngineException, and Pcf::System::SEHException. These exceptions are to be thrown only by the Pcf infrastructure.
///
/// @section SeeSection See also
/// Other Resources
/// * @ref CorelibSection
/// * @ref FrameworkDesignGuidelinesPage
/// * @ref DesignGuidelinesForExceptionsPage
