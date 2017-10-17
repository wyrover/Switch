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

| class                  | Type          | Progression                           |
|------------------------|---------------|---------------------------------------|
| CommonDialog           | class         | ![Progress](Pictures/Progress0.png)   |
| FileDialog             | class         | ![Progress](Pictures/Progress0.png)   |
| FileDialogCustomPlace  | class         | ![Progress](Pictures/Progress0.png)   |
| FileDialogCustomPlaces | class         | ![Progress](Pictures/Progress0.png)   |
| OpenFileDialog         | class         | ![Progress](Pictures/Progress0.png)   |
| SaveFileDialog         | class         | ![Progress](Pictures/Progress0.png)   |

## Switch.Core (mscorelib)

### Microsoft::Win32

| class                                                                                                       | Type          | Progression                           |
|-------------------------------------------------------------------------------------------------------------|---------------|---------------------------------------|
| [Registry](../src/Switch.Core/include/Switch/Microsoft/Win32/Registry.hpp)                                  | class         | ![Progress](Pictures/Progress100.png) |
| [RegistryHive](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryHive.hpp)                          | enumeration   | ![Progress](Pictures/Progress100.png) |
| [RegistryKey](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryKey.hpp)                            | class         | ![Progress](Pictures/Progress100.png) |
| [RegistryKeyPermissionCheck](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryPermissionCheck.hpp) | enumeration   | ![Progress](Pictures/Progress100.png) |
| [RegistryOptions](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryOptions.hpp)                    | enumeration   | ![Progress](Pictures/Progress100.png) |
| [RegistryValueKind](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryValueKind.hpp)                | enumeration   | ![Progress](Pictures/Progress100.png) |
| [RegistryValueOptions](../src/Switch.Core/include/Switch/Microsoft/Win32/RegistryValueOptions.hpp)          | enumeration   | ![Progress](Pictures/Progress100.png) |
| RegistryView                                                                                                | enumeration   | ![Progress](Pictures/Progress0.png)   |

### Microsoft::Win32::SafeHandles

| class                                  | Type          | Progression                           |
|---------------------------------------|---------------|---------------------------------------|
| CriticalHandleMinusOneIsInvalid       | class         | ![Progress](Pictures/Progress0.png)   |
| CriticalHandleZeroOrMinusOneIsInvalid | class         | ![Progress](Pictures/Progress0.png)   |
| SafeAccessTokenHandle                 | class         | ![Progress](Pictures/Progress0.png)   |
| SafeFileHandle                        | class         | ![Progress](Pictures/Progress0.png)   |
| SafeHandleMinusOneIsInvalid           | class         | ![Progress](Pictures/Progress0.png)   |
| SafeHandleZeroOrMinusOneIsInvalid     | class         | ![Progress](Pictures/Progress0.png)   |
| SafeRegistryHandle                    | class         | ![Progress](Pictures/Progress0.png)   |
| SafeWaitHandle                        | class         | ![Progress](Pictures/Progress0.png)   |

### System 

| class                                                                                                                                       | Type          | Progression                           |
|---------------------------------------------------------------------------------------------------------------------------------------------|---------------|---------------------------------------|
| _AppDomain                                                                                                                                  | interface     | ![Progress](Pictures/Progress0.png)   |
| [AccessViolationException](../src/Switch.Core/include/Switch/System/AccessViolationException.hpp)                                           | class         | ![Progress](Pictures/Progress100.png) |
| [Action](../src/Switch.Core/include/Switch/System/Action.hpp)                                                                               | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                                                          | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                                                     | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                                                 | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                                             | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                                         | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                                     | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                                 | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                             | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                         | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10\>](../src/Switch.Core/include/Switch/System/Action.hpp)                                    | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11\>](../src/Switch.Core/include/Switch/System/Action.hpp)                               | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12\>](../src/Switch.Core/include/Switch/System/Action.hpp)                          | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13\>](../src/Switch.Core/include/Switch/System/Action.hpp)                     | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14\>](../src/Switch.Core/include/Switch/System/Action.hpp)                | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15\>](../src/Switch.Core/include/Switch/System/Action.hpp)           | delegate      | ![Progress](Pictures/Progress100.png) |
| [Action\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16\>](../src/Switch.Core/include/Switch/System/Action.hpp)      | delegate      | ![Progress](Pictures/Progress100.png) |
| ActivationArgument                                                                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| ActivationContext                                                                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| Activator                                                                                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| [AggregateException](../src/Switch.Core/include/Switch/System/AggregateException.hpp)                                                       | class         | ![Progress](Pictures/Progress100.png) |
| AppContext                                                                                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| AppDomain                                                                                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| AppDomainInitializer                                                                                                                        | delegate      | ![Progress](Pictures/Progress0.png)   |
| AppDomainManager                                                                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| AppDomainManagerInitializationOptions                                                                                                       | enumeration   | ![Progress](Pictures/Progress0.png)   |
| AppDomainSetup                                                                                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| [AppDomainUnloadedException](../src/Switch.Core/include/Switch/System/AppDomainUnloadedException.hpp)                                       | class         | ![Progress](Pictures/Progress100.png) |
| ApplicationActivator                                                                                                                        | class         | ![Progress](Pictures/Progress0.png)   |
| [ApplicationException](../src/Switch.Core/include/Switch/System/ApplicationException.hpp)                                                   | class         | ![Progress](Pictures/Progress100.png) |
| ApplicationId                                                                                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| ApplicationIdentity                                                                                                                         | class         | ![Progress](Pictures/Progress0.png)   |
| ArgIterator                                                                                                                                 | struct        | ![Progress](Pictures/Progress0.png)   |
| [ArgumentException](../src/Switch.Core/include/Switch/System/ArgumentException.hpp)                                                         | class         | ![Progress](Pictures/Progress100.png) |
| [ArgumentNullException](../src/Switch.Core/include/Switch/System/ArgumentNullException.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [ArgumentOutOfRangeException](../src/Switch.Core/include/Switch/System/ArgumentOutOfRangeException.hpp)                                     | class         | ![Progress](Pictures/Progress100.png) |
| [ArithmeticException](../src/Switch.Core/include/Switch/System/ArithmeticException.hpp)                                                     | class         | ![Progress](Pictures/Progress100.png) |
| [Array](../src/Switch.Core/include/Switch/System/Array.hpp)                                                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [ArraySegment\<T\>](../src/Switch.Core/include/Switch/System/ArraySegment.hpp)                                                              | struct        | ![Progress](Pictures/Progress75.png)  |
| [ArrayTypeMismatchException](../src/Switch.Core/include/Switch/System/ArrayTypeMismatchException.hpp)                                       | class         | ![Progress](Pictures/Progress100.png) |
| AssemblyLoadEventArgs                                                                                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| AssemblyLoadEventHandler                                                                                                                    | delegate      | ![Progress](Pictures/Progress0.png)   |
| [AsyncCallback](../src/Switch.Core/include/Switch/System/AsyncCallback.hpp)                                                                 | delegate      | ![Progress](Pictures/Progress100.png) |
| *Attribute*                                                                                                                                 | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *AttributeUsageAttribute*                                                                                                                   | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *AttributeTargets*                                                                                                                          | *enumeration* | ![Progress](Pictures/ProgressIna.png) |
| [BadImageFormatException](../src/Switch.Core/include/Switch/System/BadImageFormatException.hpp)                                             | class         | ![Progress](Pictures/Progress100.png) |
| Base64FormattingOptions                                                                                                                     | enumeration   | ![Progress](Pictures/Progress0.png)   |
| [BitConverter](../src/Switch.Core/include/Switch/System/BitConverter.hpp)                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [Boolean](../src/Switch.Core/include/Switch/System/Boolean.hpp)                                                                             | struct        | ![Progress](Pictures/Progress100.png) |
| [Buffer](../src/Switch.Core/include/Switch/System/Buffer.hpp)                                                                               | class         | ![Progress](Pictures/Progress100.png) |
| [Byte](../src/Switch.Core/include/Switch/System/Byte.hpp)                                                                                   | struct        | ![Progress](Pictures/Progress100.png) |
| [CannotUnloadAppDomainException](../src/Switch.Core/include/Switch/System/CannotUnloadAppDomainException.hpp)                               | class         | ![Progress](Pictures/Progress100.png) |
| [Char](../src/Switch.Core/include/Switch/System/Char.hpp)                                                                                   | struct        | ![Progress](Pictures/Progress100.png) |
| [CharEnumerator](../src/Switch.Core/include/Switch/System/CharEnumerator.hpp)                                                               | class         | ![Progress](Pictures/Progress100.png) |
| *CLSCompliantAttribute*                                                                                                                     | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [Comparison](../src/Switch.Core/include/Switch/System/Comparison.hpp)                                                                       | delegate      | ![Progress](Pictures/Progress100.png) |
| [Console](../src/Switch.Core/include/Switch/System/Console.hpp)                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| [ConsoleCancelEventArgs](../src/Switch.Core/include/Switch/System/ConsoleEventArgs.hpp)                                                     | class         | ![Progress](Pictures/Progress100.png) |
| [ConsoleCancelEventHandler](../src/Switch.Core/include/Switch/System/ConsoleEventHandler.hpp)                                               | delegate      | ![Progress](Pictures/Progress100.png) |
| [ConsoleColors](../src/Switch.Core/include/Switch/System/ConsoleColors.hpp)                                                                 | enumeration   | ![Progress](Pictures/Progress100.png) |
| [ConsoleKey](../src/Switch.Core/include/Switch/System/ConsoleKey.hpp)                                                                       | enumeration   | ![Progress](Pictures/Progress100.png) |
| [ConsoleKeyInfo](../src/Switch.Core/include/Switch/System/ConsoleKeyInfo.hpp)                                                               | struct        | ![Progress](Pictures/Progress100.png) |
| [ConsoleModifiers](../src/Switch.Core/include/Switch/System/ConsoleModifiers.hpp)                                                           | enumeration   | ![Progress](Pictures/Progress100.png) |
| [ConsoleSpecialKey](../src/Switch.Core/include/Switch/System/ConsoleKey.hpp)                                                                | enumeration   | ![Progress](Pictures/Progress100.png) |
| ContextBoundObect                                                                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| [ContextMarshalException](../src/Switch.Core/include/Switch/System/ContextMarshalException.hpp)                                             | class         | ![Progress](Pictures/Progress100.png) |
| *ContextStaticAttribute*                                                                                                                    | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [Convert](../src/Switch.Core/include/Switch/System/Convert.hpp)                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| [Converter\<Tinput, TOutput\>](../src/Switch.Core/include/Switch/System/Converter.hpp)                                                      | delegate      | ![Progress](Pictures/Progress100.png) |
| Converter                                                                                                                                   | delegate      | ![Progress](Pictures/Progress0.png)   |
| CrossAppDomainDelegate                                                                                                                      | delegate      | ![Progress](Pictures/Progress0.png)   |
| [DataMisalignedException](../src/Switch.Core/include/Switch/System/DataMisalignedException.hpp)                                             | class         | ![Progress](Pictures/Progress100.png) |
| [DateTime](../src/Switch.Core/include/Switch/System/DateTime.hpp)                                                                           | struct        | ![Progress](Pictures/Progress75.png)  |
| [DateTimeKind](../src/Switch.Core/include/Switch/System/DateTimeKind.hpp)                                                                   | enumeration   | ![Progress](Pictures/Progress100.png) |
| DateTimeOffset                                                                                                                              | struct        | ![Progress](Pictures/Progress0.png)   |
| [DayOfWeek](../src/Switch.Core/include/Switch/System/DayOfWeek.hpp)                                                                         | enumeration   | ![Progress](Pictures/Progress100.png) |
| DBNull                                                                                                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| [Decimal](../src/Switch.Core/include/Switch/System/Decimal.hpp)                                                                             | struct        | ![Progress](Pictures/Progress100.png) |
| [Delegate](../src/Switch.Core/include/Switch/System/Delegate.hpp)                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| [DivideByZeroException](../src/Switch.Core/include/Switch/System/DivideByZeroException.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [DllNotFoundException](../src/Switch.Core/include/Switch/System/DllNotFoundException.hpp)                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [Double](../src/Switch.Core/include/Switch/System/Double.hpp)                                                                               | struct        | ![Progress](Pictures/Progress100.png) |
| [DuplicateWaitObjectException](../src/Switch.Core/include/Switch/System/DuplicateWaitObjectException.hpp)                                   | class         | ![Progress](Pictures/Progress100.png) |
| [EntryPointNotFoundException](../src/Switch.Core/include/Switch/System/EntryPointNotFoundException.hpp)                                     | class         | ![Progress](Pictures/Progress100.png) |
| [Enum](../src/Switch.Core/include/Switch/System/Enum.hpp)                                                                                   | class         | ![Progress](Pictures/Progress75.png)  |
| [Environment](../src/Switch.Core/include/Switch/System/Environment.hpp)                                                                     | class         | ![Progress](Pictures/Progress100.png) |
| [EnvironmentVariableTarget](../src/Switch.Core/include/Switch/System/EnvironmentVariableTarget.hpp)                                         | enumeration   | ![Progress](Pictures/Progress100.png) |
| [EventArgs](../src/Switch.Core/include/Switch/System/EventArgs.hpp)                                                                         | class         | ![Progress](Pictures/Progress100.png) |
| EventHandler<TEventArgs>                                                                                                                    | delegate      | ![Progress](Pictures/Progress0.png)   |
| [EventHandler](../src/Switch.Core/include/Switch/System/EventHandler.hpp)                                                                   | delegate      | ![Progress](Pictures/Progress100.png) |
| [Exception](../src/Switch.Core/include/Switch/System/Exception.hpp)                                                                         | class         | ![Progress](Pictures/Progress100.png) |
| [ExceptionEngineException](../src/Switch.Core/include/Switch/System/ExceptionEngineException.hpp)                                           | class         | ![Progress](Pictures/Progress100.png) |
| [FieldAccessException](../src/Switch.Core/include/Switch/System/FileAccessException.hpp)                                                    | class         | ![Progress](Pictures/Progress100.png) |
| *FlagsAttribute*                                                                                                                            | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [FormatException](../src/Switch.Core/include/Switch/System/FormatException.hpp)                                                             | class         | ![Progress](Pictures/Progress100.png) |
| FormatableString                                                                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| [Func](../src/Switch.Core/include/Switch/System/Func.hpp)                                                                                   | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                                                        | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                                                     | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                                                | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                                            | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                                        | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                                    | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                                | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                            | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                        | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                                    | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                               | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                          | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                     | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)                | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)           | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp)      | delegate      | ![Progress](Pictures/Progress100.png) |
| [Func\<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, TResult\>](../src/Switch.Core/include/Switch/System/Func.hpp) | delegate      | ![Progress](Pictures/Progress100.png) |
| *GC*                                                                                                                                        | *class*       | ![Progress](Pictures/ProgressIna.png) |
| GCCollectionMode                                                                                                                            | enumeration   | ![Progress](Pictures/Progress0.png)   |
| GCNotificationStatus                                                                                                                        | enumeration   | ![Progress](Pictures/Progress0.png)   |
| [Guid](../src/Switch.Core/include/Switch/System/Guid.hpp)                                                                                   | struct        | ![Progress](Pictures/Progress100.png) |
| IAppDomainSetup                                                                                                                             | interface     | ![Progress](Pictures/Progress0.png)   |
| [IAsyncResult](../src/Switch.Core/include/Switch/System/IAsyncResult.hpp)                                                                   | interface     | ![Progress](Pictures/Progress100.png) |
| [IClonable](../src/Switch.Core/include/Switch/System/IClonable.hpp)                                                                         | interface     | ![Progress](Pictures/Progress100.png) |
| [IComparable\<T\>](../src/Switch.Core/include/Switch/System/IComparable.hpp)                                                                | interface     | ![Progress](Pictures/Progress100.png) |
| IComparable                                                                                                                                 | interface     | ![Progress](Pictures/Progress0.png)   |
| [IConvertible](../src/Switch.Core/include/Switch/System/IConvertible.hpp)                                                                   | interface     | ![Progress](Pictures/Progress100.png) |
| [ICustomFormater](../src/Switch.Core/include/Switch/System/ICustomFormater.hpp)                                                             | interface     | ![Progress](Pictures/Progress100.png) |
| *IDisposable*                                                                                                                               | *interface*   | ![Progress](Pictures/ProgressIna.png) |
| IEquatable\<T\>                                                                                                                             | interface     | ![Progress](Pictures/Progress0.png)   |
| [IFormatProvider](../src/Switch.Core/include/Switch/System/IFormatProvider.hpp)                                                             | interface     | ![Progress](Pictures/Progress100.png) |
| [IFormattable](../src/Switch.Core/include/Switch/System/IFormatable.hpp)                                                                    | interface     | ![Progress](Pictures/Progress100.png) |
| [IndexOutOfRangeException](../src/Switch.Core/include/Switch/System/InvexOutOfRangeException.hpp)                                           | class         | ![Progress](Pictures/Progress100.png) |
| [InsufficientExecutionStackException](../src/Switch.Core/include/Switch/System/InsufficientExecutionStackException.hpp)                     | class         | ![Progress](Pictures/Progress100.png) |
| [InsufficientMemoryException](../src/Switch.Core/include/Switch/System/InsufficientMemoryException.hpp)                                     | class         | ![Progress](Pictures/Progress100.png) |
| [Int16](../src/Switch.Core/include/Switch/System/Int16.hpp)                                                                                 | struct        | ![Progress](Pictures/Progress100.png) |
| [Int32](../src/Switch.Core/include/Switch/System/Int32.hpp)                                                                                 | struct        | ![Progress](Pictures/Progress100.png) |
| [Int64](../src/Switch.Core/include/Switch/System/Int64.hpp)                                                                                 | struct        | ![Progress](Pictures/Progress100.png) |
| [IntPtr](../src/Switch.Core/include/Switch/System/IntPtr.hpp)                                                                               | struct        | ![Progress](Pictures/Progress100.png) |
| [InvalidCastException](../src/Switch.Core/include/Switch/System/InvalidCastEception.hpp)                                                    | class         | ![Progress](Pictures/Progress100.png) |
| [InvalidOperationException](../src/Switch.Core/include/Switch/System/InvalidOperationException.hpp)                                         | class         | ![Progress](Pictures/Progress100.png) |
| [InvalidProgramException](../src/Switch.Core/include/Switch/System/InvalidProgramException.hpp)                                             | class         | ![Progress](Pictures/Progress100.png) |
| [InvalidTimeZoneException](../src/Switch.Core/include/Switch/System/InvalidTimeZoneExcception.hpp)                                          | class         | ![Progress](Pictures/Progress100.png) |
| IObservable\<T\>                                                                                                                            | interface     | ![Progress](Pictures/Progress0.png)   |
| IObserver\<T\>                                                                                                                              | interface     | ![Progress](Pictures/Progress0.png)   |
| IProgress\<T\>                                                                                                                              | interface     | ![Progress](Pictures/Progress0.png)   |
| IServiceProvider                                                                                                                            | interface     | ![Progress](Pictures/Progress0.png)   |
| Lazy<T>                                                                                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| Lazy<T, TMetadata>                                                                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| LoaderOptimization                                                                                                                          | enumeration   | ![Progress](Pictures/Progress0.png)   |
| *LoaderOptimizationAttribute*                                                                                                               | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *LoaderOptimizationAttribute*                                                                                                               | *class*       | ![Progress](Pictures/ProgressIna.png) |
| LocalDataStoreSlot                                                                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| *MarshalByRefObject*                                                                                                                        | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [Math](../src/Switch.Core/include/Switch/System/Math.hpp)                                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [MemberAccessException](../src/Switch.Core/include/Switch/System/MemberAccessException.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [MethodAccessException](../src/Switch.Core/include/Switch/System/MethodAccessException.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| MidpointRounding                                                                                                                            | enumeration   | ![Progress](Pictures/Progress0.png)   |
| [MissingFieldException](../src/Switch.Core/include/Switch/System/MissingFieldException.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [MissingMemberException](../src/Switch.Core/include/Switch/System/MissingMemberException.hpp)                                               | class         | ![Progress](Pictures/Progress100.png) |
| [MissingMethodException](../src/Switch.Core/include/Switch/System/MissingMethodException.hpp)                                               | class         | ![Progress](Pictures/Progress100.png) |
| ModuleHandle                                                                                                                                | struct        | ![Progress](Pictures/Progress0.png)   |
| *MTAThreadAttribute*                                                                                                                        | *class*       | ![Progress](Pictures/ProgressIna.png) |
| MulticastDelegate                                                                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| [MulticastNotSupportedException](../src/Switch.Core/include/Switch/System/MulticastNotSupportedException.hpp)                               | class         | ![Progress](Pictures/Progress100.png) |
| *NonSerializedAttribute*                                                                                                                    | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [NotFiniteNumberException](../src/Switch.Core/include/Switch/System/NotFiniteNumberException.hpp)                                           | class         | ![Progress](Pictures/Progress100.png) |
| [NotImplementedException](../src/Switch.Core/include/Switch/System/NotImplementedException.hpp)                                             | class         | ![Progress](Pictures/Progress100.png) |
| [NotSupportedException](../src/Switch.Core/include/Switch/System/NotSupportedException.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [Nullable\<T\>](../src/Switch.Core/include/Switch/System/Nullable.hpp)                                                                      | struct        | ![Progress](Pictures/Progress100.png) |
| Nullable                                                                                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| [NullReferenceException](../src/Switch.Core/include/Switch/System/NullReferenceException.hpp)                                               | class         | ![Progress](Pictures/Progress100.png) |
| [Object](../src/Switch.Core/include/Switch/System/Object.hpp)                                                                               | class         | ![Progress](Pictures/Progress100.png) |
| [ObjectDisposedException](../src/Switch.Core/include/Switch/System/ObjectDisposedException.hpp)                                             | class         | ![Progress](Pictures/Progress100.png) |
| ObsoleteAttribute                                                                                                                           | class         | ![Progress](Pictures/ProgressIna.png) |
| [OperatingSystem](../src/Switch.Core/include/Switch/System/OperatingSystem.hpp)                                                             | class         | ![Progress](Pictures/Progress100.png) |
| [OperationCanceledException](../src/Switch.Core/include/Switch/System/OperationCanceledException.hpp)                                       | class         | ![Progress](Pictures/Progress100.png) |
| [OutOfMemoryException](../src/Switch.Core/include/Switch/System/OutOfMemoryException.hpp)                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [OverflowException](../src/Switch.Core/include/Switch/System/OverflowException.hpp)                                                         | class         | ![Progress](Pictures/Progress100.png) |
| *ParamArrayAttribute*                                                                                                                       | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [PlatformID](../src/Switch.Core/include/Switch/System/PlatformID.hpp)                                                                       | enumeration   | ![Progress](Pictures/Progress100.png) |
| [PlatformNotSupportedException](../src/Switch.Core/include/Switch/System/PlatformNotSupportedException.hpp)                                 | class         | ![Progress](Pictures/Progress100.png) |
| [Predicate](../src/Switch.Core/include/Switch/System/Predicate.hpp)                                                                         | delegate      | ![Progress](Pictures/Progress100.png) |
| Progress                                                                                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| [Random](../src/Switch.Core/include/Switch/System/Random.hpp)                                                                               | class         | ![Progress](Pictures/Progress100.png) |
| [RankException](../src/Switch.Core/include/Switch/System/RankException.hpp)                                                                 | class         | ![Progress](Pictures/Progress100.png) |
| ResolveEventArgs                                                                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| PesolveEventHandler                                                                                                                         | delegate      | ![Progress](Pictures/Progress0.png)   |
| RuntimeArgumentHandle                                                                                                                       | struct        | ![Progress](Pictures/Progress0.png)   |
| RuntimeFieldHandle                                                                                                                          | struct        | ![Progress](Pictures/Progress0.png)   |
| RuntimeMethodHandle                                                                                                                         | struct        | ![Progress](Pictures/Progress0.png)   |
| RuntimeTypeHandle                                                                                                                           | struct        | ![Progress](Pictures/Progress0.png)   |
| [SByte](../src/Switch.Core/include/Switch/System/SByte.hpp)                                                                                 | struct        | ![Progress](Pictures/Progress100.png) |
| *SerializableAttribute*                                                                                                                     | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [Single](../src/Switch.Core/include/Switch/System/Single.hpp)                                                                               | struct        | ![Progress](Pictures/Progress100.png) |
| [StackOverflowException](../src/Switch.Core/include/Switch/System/StackOverflowEception.hpp)                                                | class         | ![Progress](Pictures/Progress100.png) |
| *STAThreadAttribute*                                                                                                                        | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [String](../src/Switch.Core/include/Switch/System/String.hpp)                                                                               | class         | ![Progress](Pictures/Progress100.png) |
| StringComparer                                                                                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| StringComparison                                                                                                                            | enumeration   | ![Progress](Pictures/Progress0.png)   |
| [StringSplitOptions](../src/Switch.Core/include/Switch/System/StringSplitoptions.hpp)                                                       | enumeration   | ![Progress](Pictures/Progress100.png) |
| [SystemException](../src/Switch.Core/include/Switch/System/SystemException.hpp)                                                             | class         | ![Progress](Pictures/Progress100.png) |
| *ThreadStaticAttribute*                                                                                                                     | *class*       | ![Progress](Pictures/ProgressIna.png) |
| [TimeoutException](../src/Switch.Core/include/Switch/System/TimeoutException.hpp)                                                           | class         | ![Progress](Pictures/Progress100.png) |
| [TimeSpan](../src/Switch.Core/include/Switch/System/TimeSpan.hpp)                                                                           | struct        | ![Progress](Pictures/Progress100.png) |
| TimeZone                                                                                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| [TimeZoneInfo](../src/Switch.Core/include/Switch/System/TimeZoneInfo.hpp)                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [TimeZoneNotFoundException](../src/Switch.Core/include/Switch/System/TimeZoneNotFoundException.hpp)                                         | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1, T2\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                                       | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1, T2, T3\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1, T2, T3, T4\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                               | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1, T2, T3, T4, T5\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                           | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1, T2, T3, T4, T5, T6\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                       | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1, T2, T3, T4, T5, T6, T7\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [Tuple\<T1, T2, T3, T4, T5, T6, T7, TRest\>](../src/Switch.Core/include/Switch/System/Tuple.hpp)                                            | class         | ![Progress](Pictures/Progress100.png) |
| TupleExtensions                                                                                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| [Type](../src/Switch.Core/include/Switch/System/Type.hpp)                                                                                   | class         | ![Progress](Pictures/Progress75.png)  |
| [TypeAccessException](../src/Switch.Core/include/Switch/System/TypeAccessException.hpp)                                                     | class         | ![Progress](Pictures/Progress100.png) |
| [TypeCode](../src/Switch.Core/include/Switch/System/TypeCode.hpp)                                                                           | enumeration   | ![Progress](Pictures/Progress100.png) |
| TypedReference                                                                                                                              | struct        | ![Progress](Pictures/Progress0.png)   |
| [TypeInitializationException](../src/Switch.Core/include/Switch/System/TypeInitializationException.hpp)                                     | class         | ![Progress](Pictures/Progress100.png) |
| [TypeLoadException](../src/Switch.Core/include/Switch/System/TypeLoadException.hpp)                                                         | class         | ![Progress](Pictures/Progress100.png) |
| [TypeUnloadedException](../src/Switch.Core/include/Switch/System/TypeUnloadedException.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [UInt16](../src/Switch.Core/include/Switch/System/UInt16.hpp)                                                                               | struct        | ![Progress](Pictures/Progress100.png) |
| [UInt32](../src/Switch.Core/include/Switch/System/UInt32.hpp)                                                                               | struct        | ![Progress](Pictures/Progress100.png) |
| [UInt64](../src/Switch.Core/include/Switch/System/UInt64.hpp)                                                                               | struct        | ![Progress](Pictures/Progress100.png) |
| [UIntPtr](../src/Switch.Core/include/Switch/System/UIntPtr.hpp)                                                                             | struct        | ![Progress](Pictures/Progress100.png) |
| [UnauthorizedAccessException](../src/Switch.Core/include/Switch/System/UnauthorizedAccessException.hpp)                                     | class         | ![Progress](Pictures/Progress100.png) |
| UnhandledExceptionEventArgs                                                                                                                 | class         | ![Progress](Pictures/Progress0.png)   |
| UnhandledExceptionEventHandler                                                                                                              | delegate      | ![Progress](Pictures/Progress0.png)   |
| [ValueTuple\<\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1, T2\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                                             | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1, T2, T3\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                                         | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1, T2, T3, T4\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                                     | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1, T2, T3, T4, T5\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                                 | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1, T2, T3, T4, T5, T6\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                             | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1, T2, T3, T4, T5, T6, T7\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                         | class         | ![Progress](Pictures/Progress100.png) |
| [ValueTuple\<T1, T2, T3, T4, T5, T6, T7, TRest\>](../src/Switch.Core/include/Switch/System/ValueTuple.hpp)                                  | class         | ![Progress](Pictures/Progress100.png) |
| [ValueType](../src/Switch.Core/include/Switch/System/ValueType.hpp)                                                                         | class         | ![Progress](Pictures/Progress100.png) |
| [Version](../src/Switch.Core/include/Switch/System/Version.hpp)                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| Void                                                                                                                                        | struct        | ![Progress](Pictures/Progress0.png)   |
| WeakReference                                                                                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| WeakReference\<T\>                                                                                                                          | class         | ![Progress](Pictures/Progress0.png)   |

### System::Collections

| class                                                                                       | Type          | Progression                           |
|---------------------------------------------------------------------------------------------|---------------|---------------------------------------|
| [ArrayList](../src/Switch.Core/include/Switch/System/Collections/ArrayList.hpp)             | class         | ![Progress](Pictures/Progress100.png) |
| [BitArray](../src/Switch.Core/include/Switch/System/Collections/BitArray.hpp)               | class         | ![Progress](Pictures/Progress100.png) |
| CaseInsensitiveComparer                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| CollectionBase                                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| [Comparer](../src/Switch.Core/include/Switch/System/Collections/Comparer.hpp)               | class         | ![Progress](Pictures/Progress100.png) |
| DictionaryBase                                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| [DictionaryEntry](../src/Switch.Core/include/Switch/System/Collections/DictionaryEntry.hpp) | struct        | ![Progress](Pictures/Progress100.png) |
| [Hashtable](../src/Switch.Core/include/Switch/System/Collections/Hashtable.hpp)             | class         | ![Progress](Pictures/Progress100.png) |
| [ICollection](../src/Switch.Core/include/Switch/System/Collections/ICollection.hpp)         | interface     | ![Progress](Pictures/Progress100.png) |
| [IComparer](../src/Switch.Core/include/Switch/System/Collections/IComparer.hpp)             | interface     | ![Progress](Pictures/Progress100.png) |
| [IDictionary](../src/Switch.Core/include/Switch/System/Collections/IDictionary.hpp)         | interface     | ![Progress](Pictures/Progress100.png) |
| IDictionaryEnumerator                                                                       | interface     | ![Progress](Pictures/Progress0.png)   |
| [IEnumerable](../src/Switch.Core/include/Switch/System/Collections/IEnumerable.hpp)         | interface     | ![Progress](Pictures/Progress100.png) |
| [IEnumerator](../src/Switch.Core/include/Switch/System/Collections/IEnumerator.hpp)         | interface     | ![Progress](Pictures/Progress100.png) |
| IEqualityComparer                                                                           | interface     | ![Progress](Pictures/Progress0.png)   |
| IHashCodeProvider                                                                           | interface     | ![Progress](Pictures/Progress0.png)   |
| [IList](../src/Switch.Core/include/Switch/System/Collections/IList.hpp)                     | interface     | ![Progress](Pictures/Progress100.png) |
| IStructuralComparable                                                                       | interface     | ![Progress](Pictures/Progress0.png)   |
| IStructuralEquatable                                                                        | interface     | ![Progress](Pictures/Progress0.png)   |
| [Queue](../src/Switch.Core/include/Switch/System/Collections/Queue.hpp)                     | class         | ![Progress](Pictures/Progress100.png) |
| ReadOnlyCollectionBase                                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| SortedList                                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| [Stack](../src/Switch.Core/include/Switch/System/Collections/Stack.hpp)                     | class         | ![Progress](Pictures/Progress100.png) |
| StructuralComparisons                                                                       | class         | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Concurrent

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| ConcurrentDictionary\<TKey, TValue\>                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| ConcurrentQueue\<T\>                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| ConcurrentStack\<T\>                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| ConcurrentStack\<T\>                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| EnumerablePartitionerOptions                                                           | enumeration   | ![Progress](Pictures/Progress0.png)   |
| IProducerConsumerCollection\<T\>                                                       | interface     | ![Progress](Pictures/Progress0.png)   |
| Partitioner                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| Partitioner\<TSource\>                                                                 | class         | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Generic

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| Comparer\<T\>                                                                          | class         | ![Progress](Pictures/Progress100.png) |
| Dictionary\<TKey, TValue\>                                                             | class         | ![Progress](Pictures/Progress100.png) |
| EqualityComparer\<T\>                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| ICollection\<T\>                                                                       | interface     | ![Progress](Pictures/Progress100.png) |
| IComparer\<T\>                                                                         | interface     | ![Progress](Pictures/Progress100.png) |
| IDictionary\<TKey, TValue\>                                                            | interface     | ![Progress](Pictures/Progress100.png) |
| IEnumerable\<T\>                                                                       | interface     | ![Progress](Pictures/Progress100.png) |
| IEnumerator\<T\>                                                                       | interface     | ![Progress](Pictures/Progress100.png) |
| IEqualityComparer\<T\>                                                                 | interface     | ![Progress](Pictures/Progress0.png)   |
| IList\<T\>                                                                             | interface     | ![Progress](Pictures/Progress100.png) |
| IReadOnlyCollection\<T\>                                                               | interface     | ![Progress](Pictures/Progress0.png)   |
| IReadOnlyDictionary\<TKey, TValue\>                                                    | interface     | ![Progress](Pictures/Progress0.png)   |
| IReadOnlyList\<T\>                                                                     | interface     | ![Progress](Pictures/Progress0.png)   |
| KeyNotFoundException                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| KeyValuePair\<TKey, TValue\>                                                           | struct        | ![Progress](Pictures/Progress100.png) |
| List\<T\>                                                                              | class         | ![Progress](Pictures/Progress100.png) |

### System::Collections::ObjectModel

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| Colection\<T\>                                                                         | class         | ![Progress](Pictures/Progress100.png) |
| KeyedCollection<TKey, TItem>                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| ReadOnlyColection\<T\>                                                                 | class         | ![Progress](Pictures/Progress100.png) |
| ReadOnlyDictionary<TKey, TValue>                                                       | class         | ![Progress](Pictures/Progress0.png)   |

### System::Configuration::Assemblies

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| AssemblyHashAlgorithm                                                                  | enumeration   | ![Progress](Pictures/Progress0.png)   |
| AAssemblyVersionCompatibility                                                          | enumeration   | ![Progress](Pictures/Progress0.png)   |

### System::Deployment::Internal

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| InternalActivationContextHelper                                                        | class         | ![Progress](Pictures/Progress0.png)   |
| InternalApplicationIdentityHelper                                                      | class         | ![Progress](Pictures/Progress0.png)   |

### System::Diagnostics

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| *ConditionalAttribute*                                                                 | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *DebuggableAttribute*                                                                  | *class*       | ![Progress](Pictures/ProgressIna.png) |
| Debugger                                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| *DebuggerBrowsableAttribute*                                                           | *class*       | ![Progress](Pictures/ProgressIna.png) |
| DebuggerBrowsableState                                                                 | enumeration   | ![Progress](Pictures/Progress0.png)   |
| *DebuggerDisplayAttribute*                                                             | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *DebuggerHiddenAttribute*                                                              | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *DebuggerNonUserCodeAttribute*                                                         | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *DebuggerStepperBoundaryAttribute*                                                     | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *DebuggerStepThroughAttribute*                                                         | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *DebuggerTypeProxyAttribute*                                                           | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *DebuggerVisualizerAttribute*                                                          | *class*       | ![Progress](Pictures/ProgressIna.png) |
| StackFrame                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| StackTrace                                                                             | class         | ![Progress](Pictures/Progress100.png) |

### System::Diagnostics::CodeAnalysis

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| *SuppressMessageAttribute*                                                             | *class*       | ![Progress](Pictures/ProgressIna.png) |

### System::Diagnostics::Contract

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| Contract                                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| *ContractAbbreviatorAttribute*                                                         | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractArgumentValidatorAttribute*                                                   | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractClassAttribute*                                                               | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractClassForAttribute*                                                            | *class*       | ![Progress](Pictures/ProgressIna.png) |
| ContractFailedEventArgs                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| ContractFailureKind                                                                    | enumeration   | ![Progress](Pictures/Progress0.png)   |
| *ContractInvariantMethodAttribute*                                                     | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractOptionAttribute*                                                              | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractPublicPropertyNameAttribute*                                                  | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractReferenceAssemblyAttribute*                                                   | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractRuntimeIgnoredAttribute*                                                      | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *ContractVerificationAttribute*                                                        | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *PureAttribute*                                                                        | *class*       | ![Progress](Pictures/ProgressIna.png) |

### System::Diagnostics::Tracing

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| EventActivityOptions                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| *EventAttribute*                                                                       | *class*       | ![Progress](Pictures/ProgressIna.png) |
| EventChannel                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| EventCommand                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| EventCommandEventArgs                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| *EventDataAttribute*                                                                   | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *EventFieldAttribute*                                                                  | *class*       | ![Progress](Pictures/ProgressIna.png) |
| EventFieldFormat                                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| EventFieldTags                                                                         | class         | ![Progress](Pictures/Progress0.png)   |
| *EventIgnoreAttribute*                                                                 | *class*       | ![Progress](Pictures/ProgressIna.png) |
| EventKeywords                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| EventLevel                                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| EventListener                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| EventManifestOptions                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| EventOpcode                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| EventSource                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| *EventSourceAttribute*                                                                 | *class*       | ![Progress](Pictures/ProgressIna.png) |
| EventSourceCreatedEventArgs                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| EventSourceException                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| EventSourceOptions                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| EventSourceSettings                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| EventTags                                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| EventTask                                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| EventWrittenEventArgs                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| *NonEventAttribute*                                                                    | *class*       | ![Progress](Pictures/ProgressIna.png) |

### System::Globalization

### System::IO

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| BinaryReader                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| BinaryReader                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| BufferedStream                                                                         | class         | ![Progress](Pictures/Progress0.png)   |
| Directory                                                                              | class         | ![Progress](Pictures/Progress100.png) |
| DirectoryInfo                                                                          | class         | ![Progress](Pictures/Progress100.png) |
| DirectoryNotFoundException                                                             | class         | ![Progress](Pictures/Progress100.png) |
| DriveInfo                                                                              | class         | ![Progress](Pictures/Progress100.png) |
| DriveType                                                                              | enumeration   | ![Progress](Pictures/Progress100.png) |
| DriveNotFoundException                                                                 | class         | ![Progress](Pictures/Progress100.png) |
| EndOfStreamExeption                                                                    | class         | ![Progress](Pictures/Progress100.png) |
| File                                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| FileAccess                                                                             | enumeration   | ![Progress](Pictures/Progress100.png) |
| FileAttributes                                                                         | enumeration   | ![Progress](Pictures/Progress100.png) |
| FileFormatException                                                                    | class         | ![Progress](Pictures/Progress100.png) |
| FileInfo                                                                               | class         | ![Progress](Pictures/Progress100.png) |
| FileLoadException                                                                      | class         | ![Progress](Pictures/Progress100.png) |
| FileNotFoundException                                                                  | class         | ![Progress](Pictures/Progress100.png) |
| FileMode                                                                               | enumeration   | ![Progress](Pictures/Progress100.png) |
| FileOptions                                                                            | enumeration   | ![Progress](Pictures/Progress0.png)   |
| FileShare                                                                              | enumeration   | ![Progress](Pictures/Progress100.png) |
| FileStream                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| FileSystemInfo                                                                         | class         | ![Progress](Pictures/Progress100.png) |
| IOException                                                                            | class         | ![Progress](Pictures/Progress100.png) |
| MemoryStream                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| Path                                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| PathTooLongException                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| SearchOption                                                                           | enumeration   | ![Progress](Pictures/Progress0.png)   |
| SeekOrigin                                                                             | enumeration   | ![Progress](Pictures/Progress100.png) |
| Stream                                                                                 | class         | ![Progress](Pictures/Progress100.png) |
| StreamReader                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| StreamWriter                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| StringReader                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| StringWriter                                                                           | class         | ![Progress](Pictures/Progress100.png) |
| TextReader                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| TextWriter                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| UnmanagedMemoryAccessor                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| UnmanagedMemoryStream                                                                  | class         | ![Progress](Pictures/Progress0.png)   |

## Switch.System (System)

### Microsoft::Win32

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| IntranetZoneCredentialPolicy                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| PowerModeChangedEventArgs                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| PowerModeChangedEventHandler                                                           | delegate      | ![Progress](Pictures/Progress0.png)   |
| PowerModes                                                                             | enumeration   | ![Progress](Pictures/Progress0.png)   |
| SessionEndedEventArgs                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| SessionEndedEventHandler                                                               | delegate      | ![Progress](Pictures/Progress0.png)   |
| SessionEndingEventArgs                                                                 | class         | ![Progress](Pictures/Progress0.png)   |
| SessionEndingEventHandler                                                              | delegate      | ![Progress](Pictures/Progress0.png)   |
| SessionEndReasons                                                                      | enumeration   | ![Progress](Pictures/Progress0.png)   |
| SessionSwitchEventArgs                                                                 | class         | ![Progress](Pictures/Progress0.png)   |
| SessionSwitchEventHandler                                                              | delegate      | ![Progress](Pictures/Progress0.png)   |
| SessionSwitchReasons                                                                   | enumeration   | ![Progress](Pictures/Progress0.png)   |
| SystemEvents                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| TimerElapsedEventArgs                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| TimerElapsedEventHandler                                                               | delegate      | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceCategory                                                                 | enumeration   | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangedEventArgs                                                         | class         | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangedEventHandler                                                      | delegate      | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangingEventArgs                                                        | class         | ![Progress](Pictures/Progress0.png)   |
| UserPreferenceChangingEventHandler                                                     | delegate      | ![Progress](Pictures/Progress0.png)   |

### Microsoft::Win32::SafeHandles

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| SafeProcessHandle                                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| SafeX509ChainHandle                                                                    | class         | ![Progress](Pictures/Progress0.png)   |

### System

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| FileStyleUriParser                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| FtpStyleUriParser                                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| GenericUriParser                                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| GenericUriParserOptions                                                                | enumeration   | ![Progress](Pictures/Progress0.png)   |
| GopherStyleUriParser                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| HttpStyleUriParser                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| LdapStyleUriParser                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| NetPipeStyleUriParser                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| NetTcpStyleUriParser                                                                   | class         | ![Progress](Pictures/Progress0.png)   |
| NewsStyleUriParser                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| Uri                                                                                    | class         | ![Progress](Pictures/Progress100.png) |
| UriBuilder                                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| UriComponents                                                                          | enumeration   | ![Progress](Pictures/Progress100.png) |
| UriFormat                                                                              | enumeration   | ![Progress](Pictures/Progress100.png) |
| UriFormatException                                                                     | class         | ![Progress](Pictures/Progress100.png) |
| UriHostNameType                                                                        | enumeration   | ![Progress](Pictures/Progress100.png) |
| UriIdnScope                                                                            | enumeration   | ![Progress](Pictures/Progress0.png)   |
| UriKind                                                                                | enumeration   | ![Progress](Pictures/Progress100.png) |
| UriParser                                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| UriPartial                                                                             | enumeration   | ![Progress](Pictures/Progress100.png) |
| UriTemplate                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| UriTemplateEquivalenceComparer                                                         | class         | ![Progress](Pictures/Progress0.png)   |
| UriTemplateMatch                                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| UriTemplateMatchException                                                              | class         | ![Progress](Pictures/Progress100.png) |
| UriTemplateTable                                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| UriTypeConverter                                                                       | class         | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Concurrent

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| BlockingCollection\<T\>                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| ConcurrentBag\<T\>                                                                     | class         | ![Progress](Pictures/Progress100.png) |

### System::Collections::Generic

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| ISet\<T\>                                                                              | interface     | ![Progress](Pictures/Progress100.png) |
| LinkedList\<T\>                                                                        | class         | ![Progress](Pictures/Progress50.png)  |
| LinkedListNode\<T\>                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| Queue\<T\>                                                                             | class         | ![Progress](Pictures/Progress100.png) |
| SortedDictionary\<T\>                                                                  | class         | ![Progress](Pictures/Progress100.png) |
| SortedList\<T\>                                                                        | class         | ![Progress](Pictures/Progress0.png)   |
| Stack\<T\>                                                                             | class         | ![Progress](Pictures/Progress100.png) |

### System::Collections::ObjectModel

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| ObservableCollection\<T\>                                                              | class         | ![Progress](Pictures/Progress0.png)   |
| ReadOnlyObservableCollection\<T\>                                                      | class         | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Specialized

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| BitVector32                                                                            | struct        | ![Progress](Pictures/Progress0.png)   |
| CollectionsUtil                                                                        | class         | ![Progress](Pictures/Progress0.png)   |
| HybridDictionary                                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| INotifyCollectionChanged                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| IOrderedDictionary.                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| ListDictionary                                                                         | class         | ![Progress](Pictures/Progress0.png)   |
| NameObjectCollectionBase                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| NameValueCollection                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| NotifyCollectionChangedEventArgs                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| NotifyCollectionChangedEventHandler                                                    | delegate      | ![Progress](Pictures/Progress0.png)   |
| OrderedDictionary                                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| StringCollection                                                                       | class         | ![Progress](Pictures/Progress100.png) |
| StringDictionary                                                                       | class         | ![Progress](Pictures/Progress100.png) |
| StringEnumerator                                                                       | class         | ![Progress](Pictures/Progress100.png) |

### System::Diagnostics

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| BooleanSwitch                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| ConsoleTraceListener                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| CorrelationManager                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| CounterCreationData                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| CounterCreationDataCollection                                                          | struct        | ![Progress](Pictures/Progress0.png)   |
| CounterSample                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| CounterSampleCalculator                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| DataReceivedEventArgs                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| DataReceivedEventHandler                                                               | delegate      | ![Progress](Pictures/Progress0.png)   |
| Debug                                                                                  | class         | ![Progress](Pictures/Progress100.png) |
| DefaultTraceListener                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| DelimitedListTraceListener                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| EntryWrittenEventArgs                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| EntryWrittenEventHandler                                                               | delegate      | ![Progress](Pictures/Progress0.png)   |
| EventInstance                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| EventLog                                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| EventLogEntry                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| EventLogEntryType                                                                      | enumeration   | ![Progress](Pictures/Progress0.png)   |
| EventLogEntryCollection                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| EventLogInstaller                                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| EventLogPermission                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| EventLogPermissionAccess                                                               | enumeration   | ![Progress](Pictures/Progress0.png)   |
| *EventLogPermissionAttribute*                                                          | *class*       | ![Progress](Pictures/ProgressIna.png) |
| EventLogPermissionEntry                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| EventLogPermissionCollection                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| EventLogTraceListener                                                                  | class         | ![Progress](Pictures/Progress0.png)   |
| EventSchemaTraceListener                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| EventSourceCreationData                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| EventTypeFilter                                                                        | class         | ![Progress](Pictures/Progress0.png)   |
| FileVersionInfo                                                                        | class         | ![Progress](Pictures/Progress0.png)   |
| ICollectionData                                                                        | interface     | ![Progress](Pictures/Progress0.png)   |
| InstanceData                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| InstanceDataCollection                                                                 | class         | ![Progress](Pictures/Progress0.png)   |
| InstanceDataCollectionCollection                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| *MonitoringDescriptionAttribute*                                                       | *class*       | ![Progress](Pictures/ProgressIna.png) |
| OverflowAction                                                                         | enumeration   | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounter                                                                     | class         | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterCategory                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterCategoryType                                                         | enumeration   | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterInstaller                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterInstanceLifetime                                                     | enumeration   | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterPermission                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterPermissionAccess                                                     | enumeration   | ![Progress](Pictures/Progress0.png)   |
| *PerformanceCounterPermissionAttribute*                                                | *class*       | ![Progress](Pictures/ProgressIna.png) |
| PerformanceCounterPermissionEntry                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterPermissionEntryCollection                                            | class         | ![Progress](Pictures/Progress0.png)   |
| PerformanceCounterType                                                                 | enumeration   | ![Progress](Pictures/Progress0.png)   |
| Process                                                                                | class         | ![Progress](Pictures/Progress50.png)  |
| ProcessModule                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| ProcessModuleCollection                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| ProcessPriorityClass                                                                   | enumeration   | ![Progress](Pictures/Progress100.png) |
| ProcessStartInfo                                                                       | class         | ![Progress](Pictures/Progress100.png) |
| ProcessThread                                                                          | class         | ![Progress](Pictures/Progress0.png)   |
| ProcessThreadCollection                                                                | class         | ![Progress](Pictures/Progress0.png)   |
| ProcessWindowStyle                                                                     | enumeration   | ![Progress](Pictures/Progress100.png) |
| SourceFilter                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| SourceLevels                                                                           | enumeration   | ![Progress](Pictures/Progress0.png)   |
| SourceSwitch                                                                           | class         | ![Progress](Pictures/Progress0.png)   |
| StopWatch                                                                              | class         | ![Progress](Pictures/Progress100.png) |
| Switch                                                                                 | class         | ![Progress](Pictures/Progress0.png)   |
| *SwitchAttribute*                                                                      | *class*       | ![Progress](Pictures/ProgressIna.png) |
| *SwitchLevelAttribute*                                                                 | *class*       | ![Progress](Pictures/ProgressIna.png) |
| TextWriterTraceListener                                                                | class         | ![Progress](Pictures/Progress100.png) |
| ThreadPriorityLevel                                                                    | enumeration   | ![Progress](Pictures/Progress0.png)   |
| ThreadState                                                                            | enumeration   | ![Progress](Pictures/Progress0.png)   |
| ThreadWaitReason                                                                       | enumeration   | ![Progress](Pictures/Progress0.png)   |
| Trace                                                                                  | class         | ![Progress](Pictures/Progress100.png) |
| TraceLevel                                                                             | enumeration   | ![Progress](Pictures/Progress0.png)   |
| TraceEventCache                                                                        | class         | ![Progress](Pictures/Progress100.png) |
| TraceEventType                                                                         | enumeration   | ![Progress](Pictures/Progress100.png) |
| TraceFilter                                                                            | class         | ![Progress](Pictures/Progress100.png) |
| TraceListener                                                                          | class         | ![Progress](Pictures/Progress100.png) |
| TraceListenerCollection                                                                | class         | ![Progress](Pictures/Progress100.png) |
| TraceOptions                                                                           | enumeration   | ![Progress](Pictures/Progress100.png) |
| TraceSource                                                                            | class         | ![Progress](Pictures/Progress100.png) |
| TraceSwitch                                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| XmlWriterTraceListener                                                                 | class         | ![Progress](Pictures/Progress0.png)   |

### System::Diagnostics::CodeAnalysis

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| *ExcludeFromCodeCoverageAttribute*                                                     | *class*       | ![Progress](Pictures/ProgressIna.png) |

### System::IO

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| ErrorEventArgs                                                                         | class         | ![Progress](Pictures/Progress100.png) |
| ErrorEventHandler                                                                      | delegate      | ![Progress](Pictures/Progress100.png) |
| FileSystemEventArg                                                                     | class         | ![Progress](Pictures/Progress100.png) |
| FileSystemEventHandler                                                                 | delegate      | ![Progress](Pictures/Progress100.png) |
| FileSystemWatcher                                                                      | class         | ![Progress](Pictures/Progress0.png)   |
| InternalBufferOverflowException                                                        | class         | ![Progress](Pictures/Progress100.png) |
| InvalidDataException                                                                   | class         | ![Progress](Pictures/Progress100.png) |
| *IODescriptionAttribute*                                                               | *class*       | ![Progress](Pictures/ProgressIna.png) |
| NotifyFilters                                                                          | enumeration   | ![Progress](Pictures/Progress0.png)   |
| RenamedEventArgs                                                                       | class         | ![Progress](Pictures/Progress100.png) |
| RenamedEventHandler                                                                    | delegate      | ![Progress](Pictures/Progress100.png) |
| WatcherChangeTypes                                                                     | enumeration   | ![Progress](Pictures/Progress100.png) |

## Switch.System.Core (System.Core)

### Microsoft::Win32::SafeHandles

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| SafeMemoryMappedFileHandle                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| SafeMemoryMappedViewHandle                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptHandle                                                                       | class         | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptKeyHandle                                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptProviderHandle                                                               | class         | ![Progress](Pictures/Progress0.png)   |
| SafeNCryptSecretHandle                                                                 | class         | ![Progress](Pictures/Progress0.png)   |
| SafePipeHandle                                                                         | class         | ![Progress](Pictures/Progress0.png)   |

### System::Collections::Generic

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| HashSet\<T\>                                                                           | class         | ![Progress](Pictures/Progress100.png) |

### System::Diagnostics

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| UnescapedXmlDiagnosticData                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| TraceLogRetentionOption                                                                | enumeration   | ![Progress](Pictures/Progress0.png)   |

### System::IO

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| HandleInheritability                                                                   | enumeration   | ![Progress](Pictures/Progress0.png)   |

## Switch.System.ServiceModel (System.ServiceModel)

### System::Collections::Generic

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| KeyedByTypeCollection\<T\>                                                             | class         | ![Progress](Pictures/Progress0.png)   |
| SynchronizedCollection\<T\>                                                            | class         | ![Progress](Pictures/Progress0.png)   |
| SynchronizedKeyedCollection\<K, T\>                                                    | class         | ![Progress](Pictures/Progress0.png)   |
| SynchronizedReadOnlyCollection\<T\>                                                    | class         | ![Progress](Pictures/Progress0.png)   |

### System::IO

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| PipeException                                                                          | class         | ![Progress](Pictures/Progress100.png) |

## Switch.WindowsBase (WindowsBase)

### System::Collections::Specialized

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| CollectionChangedEventManager                                                          | class         | ![Progress](Pictures/Progress0.png)   |

### System::Diagnostics

| class                                                                                  | Type          | Progression                           |
|----------------------------------------------------------------------------------------|---------------|---------------------------------------|
| PresentationTraceLevel                                                                 | enumeration   | ![Progress](Pictures/Progress0.png)   |
| PresentationTraceSources                                                               | class         | ![Progress](Pictures/Progress0.png)   |

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
