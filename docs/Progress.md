![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# The Switch libraries progression

#### Progression information

![Progress](Pictures/ProgressIna.png) Not applicable

![Progress](Pictures/Progress0.png) Not started

![Progress](Pictures/Progress25.png) Started

![Progress](Pictures/Progress50.png) In progress

![Progress](Pictures/Progress75.png) Usable

![Progress](Pictures/Progress100.png) Complete

## Switch.PresentationFramework (PresentationFramework)

### Microsoft::Win32

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| CommonDialog                                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| FileDialog                                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| FileDialogCustomPlace                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| FileDialogCustomPlaces                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| OpenFileDialog                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| SaveFileDialog                                                                         | class       | ![Progress](Pictures/Progress0.png)   |

## Switch.Core (mscorelib)

### Microsoft::Win32

| class                                                                                                       | Type        | Progression                           |
|-------------------------------------------------------------------------------------------------------------|-------------|---------------------------------------|
| [Registry](../src/Switch.Core/include/Switch/Microsoft/Win32/Registry.hpp)                                  | class       | ![Progress](Pictures/Progress100.png) |
| [RegistryHive](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryHive.hpp)                          | enumeration | ![Progress](Pictures/Progress100.png) |
| [RegistryKey](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryKey.hpp)                            | class       | ![Progress](Pictures/Progress100.png) |
| [RegistryKeyPermissionCheck](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryPermissionCheck.hpp) | enumeration | ![Progress](Pictures/Progress100.png) |
| [RegistryOptions](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryOptions.hpp)                    | enumeration | ![Progress](Pictures/Progress100.png) |
| [RegistryValueKind](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryValueKind.hpp)                | enumeration | ![Progress](Pictures/Progress100.png) |
| [RegistryValueOptions](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryValueOptions.hpp)          | enumeration | ![Progress](Pictures/Progress100.png) |
| RegistryView                                                                                                | enumeration | ![Progress](Pictures/Progress0.png)   |

### Microsoft::Win32::SafeHandles

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| CriticalHandleMinusOneIsInvalid                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| CriticalHandleZeroOrMinusOneIsInvalid                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| SafeAccessTokenHandle                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| SafeFileHandle                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| SafeHandleMinusOneIsInvalid                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| SafeHandleZeroOrMinusOneIsInvalid                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| SafeRegistryHandle                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| SafeWaitHandle                                                                         | class       | ![Progress](Pictures/Progress0.png)   |

### System 

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| _AppDomain                                                                             | interface   | ![Progress](Pictures/Progress0.png)   |
| AccessViolationException                                                               | class       | ![Progress](Pictures/Progress100.png) |
| Action                                                                                 | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T\>                                                                            | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2\>                                                                       | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3\>                                                                   | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4\>                                                               | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5\>                                                           | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6\>                                                       | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7\>                                                   | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8\>                                               | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9\>                                           | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10\>                                      | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11\>                                 | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12\>                            | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13\>                       | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14\>                  | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15\>             | delegate    | ![Progress](Pictures/Progress100.png) |
| Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16\>        | delegate    | ![Progress](Pictures/Progress100.png) |
| ActivationArgument                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| ActivationContext                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| Activator                                                                              | class       | ![Progress](Pictures/Progress0.png)   |
| AggregateException                                                                     | class       | ![Progress](Pictures/Progress100.png) |
| AppContext                                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| AppDomain                                                                              | class       | ![Progress](Pictures/Progress0.png)   |
| AppDomainInitializer                                                                   | delegate    | ![Progress](Pictures/Progress0.png)   |
| AppDomainManager                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| AppDomainManagerInitializationOptions                                                  | enumeration | ![Progress](Pictures/Progress0.png)   |
| AppDomainSetup                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| AppDomainUnloadedException                                                             | class       | ![Progress](Pictures/Progress100.png) |
| ApplicationActivator                                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| ApplicationException                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| ApplicationId                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| ApplicationIdentity                                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| ArgIterator                                                                            | struct      | ![Progress](Pictures/Progress0.png)   |
| ArgumentException                                                                      | class       | ![Progress](Pictures/Progress100.png) |
| ArgumentNullException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| ArgumentOutOfRangeException                                                            | class       | ![Progress](Pictures/Progress100.png) |
| ArithmeticException                                                                    | class       | ![Progress](Pictures/Progress100.png) |
| Array                                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| ArraySegment<T>                                                                        | struct      | ![Progress](Pictures/Progress75.png)  |
| ArrayTypeMismatchException                                                             | class       | ![Progress](Pictures/Progress100.png) |
| AssemblyLoadEventArgs                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| AssemblyLoadEventHandler                                                               | delegate    | ![Progress](Pictures/Progress0.png)   |
| AsyncCallback                                                                          | delegate    | ![Progress](Pictures/Progress100.png) |
| Attribute                                                                              | class       | ![Progress](Pictures/ProgressIna.png) |
| AttributeUsageAttribute                                                                | class       | ![Progress](Pictures/ProgressIna.png) |
| AttributeTargets                                                                       | enumeration | ![Progress](Pictures/ProgressIna.png) |
| BadImageFormatException                                                                | class       | ![Progress](Pictures/Progress100.png) |
| Base64FormattingOptions                                                                | enumeration | ![Progress](Pictures/Progress0.png)   |
| BitConverter                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| Boolean                                                                                | struct      | ![Progress](Pictures/Progress100.png) |
| Buffer                                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| Byte                                                                                   | struct      | ![Progress](Pictures/Progress100.png) |
| CannotUnloadAppDomainException                                                         | class       | ![Progress](Pictures/Progress100.png) |
| Char                                                                                   | struct      | ![Progress](Pictures/Progress100.png) |
| CharEnumerator                                                                         | class       | ![Progress](Pictures/Progress100.png) |
| CLSCompliantAttribute                                                                  | class       | ![Progress](Pictures/ProgressIna.png) |
| Comparison                                                                             | delegate    | ![Progress](Pictures/Progress100.png) |
| Converter                                                                              | delegate    | ![Progress](Pictures/Progress100.png) |
| Console                                                                                | class       | ![Progress](Pictures/Progress100.png) |
| ConsoleCancelEventArgs                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| ConsoleCancelEventHandler                                                              | delegate    | ![Progress](Pictures/Progress100.png) |
| ConsoleColors                                                                          | enumeration | ![Progress](Pictures/Progress100.png) |
| ConsoleKey                                                                             | enumeration | ![Progress](Pictures/Progress100.png) |
| ConsoleKeyInfo                                                                         | struct      | ![Progress](Pictures/Progress100.png) |
| ConsoleModifiers                                                                       | enumeration | ![Progress](Pictures/Progress100.png) |
| ConsoleSpecialKey                                                                      | enumeration | ![Progress](Pictures/Progress100.png) |
| ContextBoundObect                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| ContextMarshalException                                                                | class       | ![Progress](Pictures/Progress100.png) |
| ContextStaticAttribute                                                                 | class       | ![Progress](Pictures/ProgressIna.png) |
| Convert                                                                                | class       | ![Progress](Pictures/Progress100.png) |
| Converter\<Tinput, TOutput\>                                                           | delegate    | ![Progress](Pictures/Progress100.png) |
| CrossAppDomainDelegate                                                                 | delegate    | ![Progress](Pictures/Progress0.png)   |
| DataMisalignedException                                                                | class       | ![Progress](Pictures/Progress100.png) |
| DateTime                                                                               | struct      | ![Progress](Pictures/Progress75.png)  |
| DateTimeKind                                                                           | enumeration | ![Progress](Pictures/Progress100.png) |
| DateTimeOffset                                                                         | struct      | ![Progress](Pictures/Progress0.png)   |
| DayOfWeek                                                                              | enumeration | ![Progress](Pictures/Progress100.png) |
| DBNull                                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| Decimal                                                                                | struct      | ![Progress](Pictures/Progress100.png) |
| Delegate                                                                               | class       | ![Progress](Pictures/Progress100.png) |
| DivideByZeroException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| DllNotFoundException                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| Double                                                                                 | struct      | ![Progress](Pictures/Progress100.png) |
| DuplicateWaitObjectException                                                           | class       | ![Progress](Pictures/Progress100.png) |
| EntryPointNotFoundException                                                            | class       | ![Progress](Pictures/Progress100.png) |
| Enum                                                                                   | class       | ![Progress](Pictures/Progress75.png)  |
| Environment                                                                            | class       | ![Progress](Pictures/Progress100.png) |
| EnvironmentVariableTarget                                                              | enumeration | ![Progress](Pictures/Progress100.png) |
| EventArgs                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| EventHandler                                                                           | delegate    | ![Progress](Pictures/Progress100.png) |
| Exception                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| ExceptionEngineException                                                               | class       | ![Progress](Pictures/Progress100.png) |
| FieldAccessException                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| FlagsAttribute                                                                         | class       | ![Progress](Pictures/ProgressIna.png) |
| FormatException                                                                        | class       | ![Progress](Pictures/Progress100.png) |
| FormatableString                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| Func                                                                                   | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<TResult\>                                                                        | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T, TResult\>                                                                     | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, TResult\>                                                                | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, TResult\>                                                            | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, TResult\>                                                        | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, TResult\>                                                    | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, TResult\>                                                | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, TResult\>                                            | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, TResult\>                                        | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, TResult\>                                    | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, TResult\>                               | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, TResult\>                          | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, TResult\>                     | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, TResult\>                | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, TResult\>           | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TResult\>      | delegate    | ![Progress](Pictures/Progress100.png) |
| Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, TResult\> | delegate    | ![Progress](Pictures/Progress100.png) |
| GC                                                                                     | class       | ![Progress](Pictures/ProgressIna.png) |
| GCCollectionMode                                                                       | enumeration | ![Progress](Pictures/Progress0.png)   |
| GCNotificationStatus                                                                   | enumeration | ![Progress](Pictures/Progress0.png)   |
| GenericEventHandler<TEventArgs>                                                        | delegate    | ![Progress](Pictures/Progress100.png) |
| Guid                                                                                   | struct      | ![Progress](Pictures/Progress100.png) |
| IAppDomainSetup                                                                        | interface   | ![Progress](Pictures/Progress0.png)   |
| IAsyncResult                                                                           | interface   | ![Progress](Pictures/Progress100.png) |
| IClonable                                                                              | interface   | ![Progress](Pictures/Progress100.png) |
| IComparable\<T\>                                                                       | interface   | ![Progress](Pictures/Progress100.png) |
| IComparable                                                                            | interface   | ![Progress](Pictures/ProgressIna.png) |
| IConvertible                                                                           | interface   | ![Progress](Pictures/Progress100.png) |
| ICustomFormater                                                                        | interface   | ![Progress](Pictures/Progress100.png) |
| IDisposable                                                                            | interface   | ![Progress](Pictures/ProgressIna.png) |
| IEquatable\<T\>                                                                        | interface   | ![Progress](Pictures/Progress0.png)   |
| IFormatProvider                                                                        | interface   | ![Progress](Pictures/Progress100.png) |
| IFormattable                                                                           | interface   | ![Progress](Pictures/Progress100.png) |
| IndexOutOfRangeException                                                               | class       | ![Progress](Pictures/Progress100.png) |
| InsufficientExecutionStackException                                                    | class       | ![Progress](Pictures/Progress100.png) |
| InsufficientMemoryException                                                            | class       | ![Progress](Pictures/Progress100.png) |
| Int16                                                                                  | struct      | ![Progress](Pictures/Progress100.png) |
| Int32                                                                                  | struct      | ![Progress](Pictures/Progress100.png) |
| Int64                                                                                  | struct      | ![Progress](Pictures/Progress100.png) |
| IntPtr                                                                                 | struct      | ![Progress](Pictures/Progress100.png) |
| InvalidCastException                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| InvalidOperationException                                                              | class       | ![Progress](Pictures/Progress100.png) |
| InvalidProgramException                                                                | class       | ![Progress](Pictures/Progress100.png) |
| InvalidTimeZoneException                                                               | class       | ![Progress](Pictures/Progress100.png) |
| IObservable\<T\>                                                                       | interface   | ![Progress](Pictures/Progress0.png)   |
| IObserver\<T\>                                                                         | interface   | ![Progress](Pictures/Progress0.png)   |
| IProgress\<T\>                                                                         | interface   | ![Progress](Pictures/Progress0.png)   |
| IServiceProvider                                                                       | interface   | ![Progress](Pictures/Progress0.png)   |
| Lazy<T>                                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| Lazy<T, TMetadata>                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| LoaderOptimization                                                                     | enumeration | ![Progress](Pictures/Progress0.png)   |
| LoaderOptimizationAttribute                                                            | class       | ![Progress](Pictures/ProgressIna.png) |
| LoaderOptimizationAttribute                                                            | class       | ![Progress](Pictures/ProgressIna.png) |
| LocalDataStoreSlot                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| MarshalByRefObject                                                                     | class       | ![Progress](Pictures/ProgressIna.png) |
| Math                                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| MemberAccessException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| MethodAccessException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| MidpointRounding                                                                       | enumeration | ![Progress](Pictures/Progress0.png)   |
| MissingFieldException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| MissingMemberException                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| MissingMethodException                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| ModuleHandle                                                                           | struct      | ![Progress](Pictures/Progress0.png)   |
| MTAThreadAttribute                                                                     | class       | ![Progress](Pictures/ProgressIna.png) |
| MulticastDelegate                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| MulticastNotSupportedException                                                         | class       | ![Progress](Pictures/Progress100.png) |
| NonSerializedAttribute                                                                 | class       | ![Progress](Pictures/ProgressIna.png) |
| NotFiniteNumberException                                                               | class       | ![Progress](Pictures/Progress100.png) |
| NotImplementedException                                                                | class       | ![Progress](Pictures/Progress100.png) |
| NotSupportedException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| Nullable                                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| Nullable\<T\>                                                                          | struct      | ![Progress](Pictures/Progress100.png) |
| NullReferenceException                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| Object                                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| ObjectDisposedException                                                                | class       | ![Progress](Pictures/Progress100.png) |
| ObsoleteAttribute                                                                      | class       | ![Progress](Pictures/Progress100.png) |
| OpratingSystem                                                                         | class       | ![Progress](Pictures/Progress100.png) |
| OperationCanceledException                                                             | class       | ![Progress](Pictures/Progress100.png) |
| OutOfMemoryException                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| OverflowException                                                                      | class       | ![Progress](Pictures/Progress100.png) |
| ParamArrayAttribute                                                                    | class       | ![Progress](Pictures/ProgressIna.png) |
| PlatformID                                                                             | enumeration | ![Progress](Pictures/Progress100.png) |
| PlatformNotSupportedException                                                          | class       | ![Progress](Pictures/Progress100.png) |
| Predicate                                                                              | delegate    | ![Progress](Pictures/Progress100.png) |
| Progress                                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| Random                                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| RankException                                                                          | class       | ![Progress](Pictures/Progress100.png) |
| ResolveEventArgs                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| PesolveEventHandler                                                                    | delegate    | ![Progress](Pictures/Progress0.png)   |
| RuntimeArgumentHandle                                                                  | struct      | ![Progress](Pictures/Progress0.png)   |
| RuntimeFieldHandle                                                                     | struct      | ![Progress](Pictures/Progress0.png)   |
| RuntimeMethodHandle                                                                    | struct      | ![Progress](Pictures/Progress0.png)   |
| RuntimeTypeHandle.                                                                     | struct      | ![Progress](Pictures/Progress0.png)   |
| SByte                                                                                  | struct      | ![Progress](Pictures/Progress100.png) |
| SerializableAttribute                                                                  | class       | ![Progress](Pictures/ProgressIna.png) |
| Single                                                                                 | struct      | ![Progress](Pictures/Progress100.png) |
| StackOverflowException                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| STAThreadAttribute                                                                     | class       | ![Progress](Pictures/ProgressIna.png) |
| String                                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| StringComparer                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| StringComparison                                                                       | enumeration | ![Progress](Pictures/Progress0.png)   |
| StringSplitOptions                                                                     | enumeration | ![Progress](Pictures/Progress100.png) |
| SystemException                                                                        | class       | ![Progress](Pictures/Progress100.png) |
| ThreadStaticAttribute                                                                  | class       | ![Progress](Pictures/ProgressIna.png) |
| TimeoutException                                                                       | class       | ![Progress](Pictures/Progress100.png) |
| TimeSpan                                                                               | struct      | ![Progress](Pictures/Progress100.png) |
| TimeZone                                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| TimeZoneInfo                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| TimeZoneNotFoundException                                                              | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<\>                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1\>                                                                            | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1, T2\>                                                                        | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1, T2, T3\>                                                                    | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1, T2, T3, T4\>                                                                | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1, T2, T3, T4, T5\>                                                            | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1, T2, T3, T4, T5, T6\>                                                        | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1, T2, T3, T4, T5, T6, T7\>                                                    | class       | ![Progress](Pictures/Progress100.png) |
| Tuple\<T1, T2, T3, T4, T5, T6, T7, TRest\>                                             | class       | ![Progress](Pictures/Progress100.png) |
| TupleExtensions                                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| Type                                                                                   | class       | ![Progress](Pictures/Progress75.png)  |
| TypeAccessException                                                                    | class       | ![Progress](Pictures/Progress100.png) |
| TypeCode                                                                               | enumeration | ![Progress](Pictures/Progress100.png) |
| TypedReference                                                                         | struct      | ![Progress](Pictures/Progress100.png) |
| TypeInitializationException                                                            | class       | ![Progress](Pictures/Progress100.png) |
| TypeLoadException                                                                      | class       | ![Progress](Pictures/Progress100.png) |
| TypeUnloadedException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| UInt16                                                                                 | struct      | ![Progress](Pictures/Progress100.png) |
| UInt32                                                                                 | struct      | ![Progress](Pictures/Progress100.png) |
| UInt64                                                                                 | struct      | ![Progress](Pictures/Progress100.png) |
| UIntPtr                                                                                | struct      | ![Progress](Pictures/Progress100.png) |
| UnauthorizedAccessException                                                            | class       | ![Progress](Pictures/Progress100.png) |
| UnhandledExceptionEventArgs                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| UnhandledExceptionEventHandler                                                         | delegate    | ![Progress](Pictures/Progress0.png)   |
| ValueTuple\<\>                                                                         | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1\>                                                                       | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1, T2\>                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1, T2, T3\>                                                               | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1, T2, T3, T4\>                                                           | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1, T2, T3, T4, T5\>                                                       | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1, T2, T3, T4, T5, T6\>                                                   | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1, T2, T3, T4, T5, T6, T7\>                                               | class       | ![Progress](Pictures/Progress100.png) |
| ValueTuple\<T1, T2, T3, T4, T5, T6, T7, TRest\>                                        | class       | ![Progress](Pictures/Progress100.png) |
| ValueType                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| Version                                                                                | class       | ![Progress](Pictures/Progress100.png) |
| Void                                                                                   | struct      | ![Progress](Pictures/Progress0.png)   |
| WeakReference                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| WeakReference\<T\>                                                                     | class       | ![Progress](Pictures/Progress0.png)   |

### System::Collections

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| ArrayList                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| BitArray                                                                               | class       | ![Progress](Pictures/Progress100.png) |
| CaseInsensitiveComparer                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| CollectionBase                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| Comparer                                                                               | class       | ![Progress](Pictures/Progress100.png) |
| DictionaryBase                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| DictionaryEntry                                                                        | struct      | ![Progress](Pictures/Progress100.png) |
| Hashtable                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| ICollection                                                                            | interface   | ![Progress](Pictures/Progress100.png) |
| IComparer                                                                              | interface   | ![Progress](Pictures/Progress100.png) |
| IDictionary                                                                            | interface   | ![Progress](Pictures/Progress100.png) |
| IDictionaryEnumerator                                                                  | interface   | ![Progress](Pictures/Progress0.png)   |
| IEnumerable                                                                            | interface   | ![Progress](Pictures/Progress100.png) |
| IEnumerator                                                                            | interface   | ![Progress](Pictures/Progress100.png) |
| IEqualityComparer                                                                      | interface   | ![Progress](Pictures/Progress0.png)   |
| IHashCodeProvider                                                                      | interface   | ![Progress](Pictures/Progress0.png)   |
| IList                                                                                  | interface   | ![Progress](Pictures/Progress100.png) |
| IStructuralComparable                                                                  | interface   | ![Progress](Pictures/Progress0.png)   |
| IStructuralEquatable                                                                   | interface   | ![Progress](Pictures/Progress0.png)   |
| Queue                                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| ReadOnlyCollectionBase                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| SortedList                                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| Stack                                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| StructuralComparisons                                                                  | class       | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Concurrent

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| ConcurrentDictionary\<TKey, TValue\>                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| ConcurrentQueue\<T\>                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| ConcurrentStack\<T\>                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| ConcurrentStack\<T\>                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| EnumerablePartitionerOptions                                                           | enumeration | ![Progress](Pictures/Progress0.png)   |
| IProducerConsumerCollection\<T\>                                                       | interface   | ![Progress](Pictures/Progress0.png)   |
| Partitioner                                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| Partitioner\<TSource\>                                                                 | class       | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Generic

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| Comparer\<T\>                                                                          | class       | ![Progress](Pictures/Progress100.png) |
| Dictionary\<TKey, TValue\>                                                             | class       | ![Progress](Pictures/Progress100.png) |
| EqualityComparer\<T\>                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| ICollection\<T\>                                                                       | interface   | ![Progress](Pictures/Progress100.png) |
| IComparer\<T\>                                                                         | interface   | ![Progress](Pictures/Progress100.png) |
| IDictionary\<TKey, TValue\>                                                            | interface   | ![Progress](Pictures/Progress100.png) |
| IEnumerable\<T\>                                                                       | interface   | ![Progress](Pictures/Progress100.png) |
| IEnumerator\<T\>                                                                       | interface   | ![Progress](Pictures/Progress100.png) |
| IEqualityComparer\<T\>                                                                 | interface   | ![Progress](Pictures/Progress0.png)   |
| IList\<T\>                                                                             | interface   | ![Progress](Pictures/Progress100.png) |
| IReadOnlyCollection\<T\>                                                               | interface   | ![Progress](Pictures/Progress0.png)   |
| IReadOnlyDictionary\<TKey, TValue\>                                                    | interface   | ![Progress](Pictures/Progress0.png)   |
| IReadOnlyList\<T\>                                                                     | interface   | ![Progress](Pictures/Progress0.png)   |
| KeyNotFoundException                                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| KeyValuePair\<TKey, TValue\>                                                           | struct      | ![Progress](Pictures/Progress100.png) |
| List\<T\>                                                                              | class       | ![Progress](Pictures/Progress100.png) |

### System::Collections::ObjectModel

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| Colection\<T\>                                                                         | class       | ![Progress](Pictures/Progress100.png) |
| KeyedCollection<TKey, TItem>                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| ReadOnlyColection\<T\>                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| ReadOnlyDictionary<TKey, TValue>                                                       | class       | ![Progress](Pictures/Progress0.png)   |

### System::Configuration::Assemblies

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| AssemblyHashAlgorithm                                                                  | enumeration | ![Progress](Pictures/Progress0.png)   |
| AAssemblyVersionCompatibility                                                          | enumeration | ![Progress](Pictures/Progress0.png)   |

### System::Deployment::Internal

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| InternalActivationContextHelper                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| InternalApplicationIdentityHelper                                                      | class       | ![Progress](Pictures/Progress0.png)   |

### System::Diagnostics

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| ConditionalAttribute                                                                   | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggableAttribute                                                                    | class       | ![Progress](Pictures/ProgressIna.png) |
| Debugger                                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| DebuggerBrowsableAttribute                                                             | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerBrowsableState                                                                 | enumeration | ![Progress](Pictures/Progress0.png)   |
| DebuggerDisplayAttribute                                                               | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerHiddenAttribute                                                                | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerNonUserCodeAttribute                                                           | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerStepperBoundaryAttribute                                                       | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerStepThroughAttribute                                                           | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerTypeProxyAttribute                                                             | class       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerVisualizerAttribute                                                            | class       | ![Progress](Pictures/ProgressIna.png) |
| StackFrame                                                                             | class       | ![Progress](Pictures/Progress100.png) |
| StackTrace                                                                             | class       | ![Progress](Pictures/Progress100.png) |

### System::Diagnostics::CodeAnalysis

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| SuppressMessageAttribute                                                               | class       | ![Progress](Pictures/ProgressIna.png) |

### System::Diagnostics::Tracing

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| EventActivityOptions                                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| EventAttribute                                                                         | class       | ![Progress](Pictures/ProgressIna.png) |
| EventChannel                                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| EventCommand                                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| EventCommandEventArgs                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| EventDataAttribute                                                                     | class       | ![Progress](Pictures/ProgressIna.png) |
| EventFieldAttribute                                                                    | class       | ![Progress](Pictures/ProgressIna.png) |
| EventFieldFormat                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| EventFieldTags                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| EventIgnoreAttribute                                                                   | class       | ![Progress](Pictures/ProgressIna.png) |
| EventKeywords                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| EventLevel                                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| EventListener                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| EventManifestOptions                                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| EventOpcode                                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| EventSource                                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| EventSourceAttribute                                                                   | class       | ![Progress](Pictures/ProgressIna.png) |
| EventSourceCreatedEventArgs                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| EventSourceException                                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| EventSourceOptions                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| EventSourceSettings                                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| EventTags                                                                              | class       | ![Progress](Pictures/Progress0.png)   |
| EventTask                                                                              | class       | ![Progress](Pictures/Progress0.png)   |
| EventWrittenEventArgs                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| NonEventAttribute                                                                      | class       | ![Progress](Pictures/ProgressIna.png) |

### System::Globalization

### System::IO

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| BinaryReader                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| BinaryReader                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| BufferedStream                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| Directory                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| DirectoryInfo                                                                          | class       | ![Progress](Pictures/Progress100.png) |
| DirectoryNotFoundException                                                             | class       | ![Progress](Pictures/Progress100.png) |
| DriveInfo                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| DriveType                                                                              | enumeration | ![Progress](Pictures/Progress100.png) |
| DriveNotFoundException                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| EndOfStreamExeption                                                                    | class       | ![Progress](Pictures/Progress100.png) |
| File                                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| FileAccess                                                                             | enumeration | ![Progress](Pictures/Progress100.png) |
| FileAttributes                                                                         | enumeration | ![Progress](Pictures/Progress100.png) |
| FileFormatException                                                                    | class       | ![Progress](Pictures/Progress100.png) |
| FileInfo                                                                               | class       | ![Progress](Pictures/Progress100.png) |
| FileLoadException                                                                      | class       | ![Progress](Pictures/Progress100.png) |
| FileNotFoundException                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| FileMode                                                                               | enumeration | ![Progress](Pictures/Progress100.png) |
| FileOptions                                                                            | enumeration | ![Progress](Pictures/Progress0.png)   |
| FileShare                                                                              | enumeration | ![Progress](Pictures/Progress100.png) |
| FileStream                                                                             | class       | ![Progress](Pictures/Progress100.png) |
| FileSystemInfo                                                                         | class       | ![Progress](Pictures/Progress100.png) |
| IOException                                                                            | class       | ![Progress](Pictures/Progress100.png) |
| MemoryStream                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| Path                                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| PathTooLongException                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| SearchOption                                                                           | enumeration | ![Progress](Pictures/Progress0.png)   |
| SeekOrigin                                                                             | enumeration | ![Progress](Pictures/Progress100.png) |
| Stream                                                                                 | class       | ![Progress](Pictures/Progress100.png) |
| StreamReader                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| StreamWriter                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| StringReader                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| StringWriter                                                                           | class       | ![Progress](Pictures/Progress100.png) |
| TextReader                                                                             | class       | ![Progress](Pictures/Progress100.png) |
| TextWriter                                                                             | class       | ![Progress](Pictures/Progress100.png) |
| UnmanagedMemoryAccessor                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| UnmanagedMemoryStream                                                                  | class       | ![Progress](Pictures/Progress0.png)   |

## Switch.System (System)

### Microsoft::Win32

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| IntranetZoneCredentialPolicy                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| PowerModeChangedEventArgs                                                              | class       | ![Progress](Pictures/Progress0.png)   |
| PowerModeChangedEventHandler                                                           | delegate    | ![Progress](Pictures/Progress0.png)   |
| PowerModes                                                                             | enumeration | ![Progress](Pictures/Progress0.png)   |
| SessionEndedEventArgs                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| SessionEndedEventHandler                                                               | delegate    | ![Progress](Pictures/Progress0.png)   |
| SessionEndingEventArgs                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| SessionEndingEventHandler                                                              | delegate    | ![Progress](Pictures/Progress0.png)   |
| SessionEndReasons                                                                      | enumeration | ![Progress](Pictures/Progress0.png)   |
| SessionSwitchEventArgs                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| SessionSwitchEventHandler                                                              | delegate    | ![Progress](Pictures/Progress0.png)   |
| SessionSwitchReasons                                                                   | enumeration | ![Progress](Pictures/Progress0.png)   |
| SystemEvents                                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| TimerElapsedEventArgs                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| TimerElapsedEventHandler                                                               | delegate    | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceCategory                                                                 | enumeration | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangedEventArgs                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangedEventHandler                                                      | delegate    | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangingEventArgs                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangingEventHandler                                                     | delegate    | ![Progress](Pictures/Progress0.png)   |

### Microsoft::Win32::SafeHandles

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| SafeProcessHandle                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| SafeX509ChainHandle                                                                    | class       | ![Progress](Pictures/Progress0.png)   |

### System

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| FileStyleUriParser                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| FtpStyleUriParser                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| GenericUriParser                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| GenericUriParserOptions                                                                | enumeration | ![Progress](Pictures/Progress0.png)   |
| GopherStyleUriParser                                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| HttpStyleUriParser                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| LdapStyleUriParser                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| NetPipeStyleUriParser                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| NetTcpStyleUriParser                                                                   | class       | ![Progress](Pictures/Progress0.png)   |
| NewsStyleUriParser                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| Uri                                                                                    | class       | ![Progress](Pictures/Progress100.png) |
| UriBuilder                                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| UriComponents                                                                          | enumeration | ![Progress](Pictures/Progress100.png) |
| UriFormat                                                                              | enumeration | ![Progress](Pictures/Progress100.png) |
| UriFormatException                                                                     | class       | ![Progress](Pictures/Progress100.png) |
| UriHostNameType                                                                        | enumeration | ![Progress](Pictures/Progress100.png) |
| UriIdnScope                                                                            | enumeration | ![Progress](Pictures/Progress0.png)   |
| UriKind                                                                                | enumeration | ![Progress](Pictures/Progress100.png) |
| UriParser                                                                              | class       | ![Progress](Pictures/Progress0.png)   |
| UriPartial                                                                             | enumeration | ![Progress](Pictures/Progress100.png) |
| UriTemplate                                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| UriTemplateEquivalenceComparer                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| UriTemplateMatch                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| UriTemplateMatchException                                                              | class       | ![Progress](Pictures/Progress100.png) |
| UriTemplateTable                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| UriTypeConverter                                                                       | class       | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Concurrent

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| BlockingCollection\<T\>                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| ConcurrentBag\<T\>                                                                     | class       | ![Progress](Pictures/Progress100.png) |

### System::Collections::Generic

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| ISet\<T\>                                                                              | interface   | ![Progress](Pictures/Progress100.png) |
| LinkedList\<T\>                                                                        | class       | ![Progress](Pictures/Progress50.png)  |
| LinkedListNode\<T\>                                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| Queue\<T\>                                                                             | class       | ![Progress](Pictures/Progress100.png) |
| SortedDictionary\<T\>                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| SortedList\<T\>                                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| Stack\<T\>                                                                             | class       | ![Progress](Pictures/Progress100.png) |

### System::Collections::ObjectModel

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| ObservableCollection\<T\>                                                              | class       | ![Progress](Pictures/Progress0.png)   |
| ReadOnlyObservableCollection\<T\>                                                      | class       | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Specialized

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| BitVector32                                                                            | struct      | ![Progress](Pictures/Progress0.png)   |
| CollectionsUtil                                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| HybridDictionary                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| INotifyCollectionChanged                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| IOrderedDictionary.                                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| ListDictionary                                                                         | class       | ![Progress](Pictures/Progress0.png)   |
| NameObjectCollectionBase                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| NameValueCollection                                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| NotifyCollectionChangedEventArgs                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| NotifyCollectionChangedEventHandler                                                    | delegate    | ![Progress](Pictures/Progress0.png)   |
| OrderedDictionary                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| StringCollection                                                                       | class       | ![Progress](Pictures/Progress100.png) |
| StringDictionary                                                                       | class       | ![Progress](Pictures/Progress100.png) |
| StringEnumerator                                                                       | class       | ![Progress](Pictures/Progress100.png) |

### System::Diagnostics

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| BooleanSwitch                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| ConsoleTraceListener                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| CorrelationManager                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| CounterCreationData                                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| CounterCreationDataCollection                                                          | struct      | ![Progress](Pictures/Progress0.png)   |
| CounterSample                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| CounterSampleCalculator                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| DataReceivedEventArgs                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| DataReceivedEventHandler                                                               | delegate    | ![Progress](Pictures/Progress0.png)   |
| Debug                                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| DefaultTraceListener                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| DelimitedListTraceListener                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| EntryWrittenEventArgs                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| EntryWrittenEventHandler                                                               | delegate    | ![Progress](Pictures/Progress0.png)   |
| EventInstance                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| EventLog                                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| EventLogEntry                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| EventLogEntryType                                                                      | enumeration | ![Progress](Pictures/Progress0.png)   |
| EventLogEntryCollection                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| EventLogInstaller                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| EventLogPermission                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| EventLogPermissionAccess                                                               | enumeration | ![Progress](Pictures/Progress0.png)   |
| EventLogPermissionAttribute                                                            | class       | ![Progress](Pictures/ProgressIna.png) |
| EventLogPermissionEntry                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| EventLogPermissionCollection                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| EventLogTraceListener                                                                  | class       | ![Progress](Pictures/Progress0.png)   |
| EventSchemaTraceListener                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| EventSourceCreationData                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| EventTypeFilter                                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| FileVersionInfo                                                                        | class       | ![Progress](Pictures/Progress0.png)   |
| ICollectionData                                                                        | interface   | ![Progress](Pictures/Progress0.png)   |
| InstanceData                                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| InstanceDataCollection                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| InstanceDataCollectionCollection                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| MonitoringDescriptionAttribute                                                         | class       | ![Progress](Pictures/ProgressIna.png) |
| OverflowAction                                                                         | enumeration | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounter                                                                     | class       | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterCategory                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterCategoryType                                                         | enumeration | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterInstaller                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterInstanceLifetime                                                     | enumeration | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterPermission                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterPermissionAccess                                                     | enumeration | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterPermissionAttribute                                                  | class       | ![Progress](Pictures/ProgressIna.png) |
| PerformanceCounterPermissionEntry                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterPermissionEntryCollection                                            | class       | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterType                                                                 | enumeration | ![Progress](Pictures/Progress0.png)   |
| Process                                                                                | class       | ![Progress](Pictures/Progress50.png)  |
| ProcessModule                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| ProcessModuleCollection                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| ProcessPriorityClass                                                                   | enumeration | ![Progress](Pictures/Progress100.png) |
| ProcessStartInfo                                                                       | class       | ![Progress](Pictures/Progress100.png) |
| ProcessThread                                                                          | class       | ![Progress](Pictures/Progress0.png)   |
| ProcessThreadCollection                                                                | class       | ![Progress](Pictures/Progress0.png)   |
| ProcessWindowStyle                                                                     | enumeration | ![Progress](Pictures/Progress100.png) |
| SourceFilter                                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| SourceLevels                                                                           | enumeration | ![Progress](Pictures/Progress0.png)   |
| SourceSwitch                                                                           | class       | ![Progress](Pictures/Progress0.png)   |
| StopWatch                                                                              | class       | ![Progress](Pictures/Progress100.png) |
| Switch                                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| SwitchAttribute                                                                        | class       | ![Progress](Pictures/ProgressIna.png) |
| SwitchLevelAttribute                                                                   | class       | ![Progress](Pictures/ProgressIna.png) |
| TextWriterTraceListener                                                                | class       | ![Progress](Pictures/Progress100.png) |
| ThreadPriorityLevel                                                                    | enumeration | ![Progress](Pictures/Progress0.png)   |
| ThreadState                                                                            | enumeration | ![Progress](Pictures/Progress0.png)   |
| ThreadWaitReason                                                                       | enumeration | ![Progress](Pictures/Progress0.png)   |
| Trace                                                                                  | class       | ![Progress](Pictures/Progress100.png) |
| TraceLevel                                                                             | enumeration | ![Progress](Pictures/Progress0.png)   |
| TraceEventCache                                                                        | class       | ![Progress](Pictures/Progress100.png) |
| TraceEventType                                                                         | enumeration | ![Progress](Pictures/Progress100.png) |
| TraceFilter                                                                            | class       | ![Progress](Pictures/Progress100.png) |
| TraceListener                                                                          | class       | ![Progress](Pictures/Progress100.png) |
| TraceListenerCollection                                                                | class       | ![Progress](Pictures/Progress100.png) |
| TraceOptions                                                                           | enumeration | ![Progress](Pictures/Progress100.png) |
| TraceSource                                                                            | class       | ![Progress](Pictures/Progress100.png) |
| TraceSwitch                                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| XmlWriterTraceListener                                                                 | class       | ![Progress](Pictures/Progress0.png)   |

### System::Diagnostics::CodeAnalysis

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| ExcludeFromCodeCoverageAttribute                                                       | class       | ![Progress](Pictures/ProgressIna.png) |

### System::IO

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| ErrorEventArgs                                                                         | class       | ![Progress](Pictures/Progress100.png) |
| ErrorEventHandler                                                                      | delegate    | ![Progress](Pictures/Progress100.png) |
| FileSystemEventArg                                                                     | class       | ![Progress](Pictures/Progress100.png) |
| FileSystemEventHandler                                                                 | delegate    | ![Progress](Pictures/Progress100.png) |
| FileSystemWatcher                                                                      | class       | ![Progress](Pictures/Progress0.png)   |
| InternalBufferOverflowException                                                        | class       | ![Progress](Pictures/Progress100.png) |
| InvalidDataException                                                                   | class       | ![Progress](Pictures/Progress100.png) |
| IODescriptionAttribute                                                                 | class       | ![Progress](Pictures/ProgressIna.png) |
| NotifyFilters                                                                          | enumeration | ![Progress](Pictures/Progress0.png)   |
| RenamedEventArgs                                                                       | class       | ![Progress](Pictures/Progress100.png) |
| RenamedEventHandler                                                                    | delegate    | ![Progress](Pictures/Progress100.png) |
| WatcherChangeTypes                                                                     | enumeration | ![Progress](Pictures/Progress100.png) |

## Switch.System.Core (System.Core)

### Microsoft::Win32::SafeHandles

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| SafeMemoryMappedFileHandle                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| SafeMemoryMappedViewHandle                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptHandle                                                                       | class       | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptKeyHandle                                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptProviderHandle                                                               | class       | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptSecretHandle                                                                 | class       | ![Progress](Pictures/Progress0.png)   |
| SafePipeHandle                                                                         | class       | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Generic

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| HashSet\<T\>                                                                           | class       | ![Progress](Pictures/Progress100.png) |

### System::Diagnostics

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| UnescapedXmlDiagnosticData                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| TraceLogRetentionOption                                                                | enumeration | ![Progress](Pictures/Progress0.png)   |

### System::IO

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| HandleInheritability                                                                   | enumeration | ![Progress](Pictures/Progress0.png)   |

## Switch.System.ServiceModel (System.ServiceModel)

### System::Collections::Generic

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| KeyedByTypeCollection\<T\>                                                             | class       | ![Progress](Pictures/Progress0.png)   |
| SynchronizedCollection\<T\>                                                            | class       | ![Progress](Pictures/Progress0.png)   |
| SynchronizedKeyedCollection\<K, T\>                                                    | class       | ![Progress](Pictures/Progress0.png)   |
| SynchronizedReadOnlyCollection\<T\>                                                    | class       | ![Progress](Pictures/Progress0.png)   |

### System::IO

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| PipeException                                                                          | class       | ![Progress](Pictures/Progress100.png) |

## Switch.WindowsBase (WindowsBase)

### System::Collections::Specialized

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| CollectionChangedEventManager                                                          | class       | ![Progress](Pictures/Progress0.png)   |

### System::Diagnostics

| class                                                                                  | Type        | Progression                           |
|----------------------------------------------------------------------------------------|-------------|---------------------------------------|
| PresentationTraceLevel                                                                 | enumeration | ![Progress](Pictures/Progress0.png)   |
| PresentationTraceSources                                                               | class       | ![Progress](Pictures/Progress0.png)   |

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
