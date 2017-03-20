cmake_minimum_required(VERSION 3.5)

project(Examples VERSION 0.2.0)

option(BUILD_CORE_EXAMPLES "Build Pcf.Core examples" ON)
option(BUILD_DRAWING_EXAMPLES "Build Pcf.Drawing examples" ON)
option(BUILD_FORMS_EXAMPLES "Build Pcf.Forms examples" ON)
option(BUILD_TUNIT_EXAMPLES "Build Pcf.TUnit examples" ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CORE_EXAMPLES Action Action1 Action2 Action3 AggregateException Any ArgumentException Array1 Array2 ArrayArrayOperator ArrayArrayOperatorFunctor ArrayAsReadOnly ArrayConstructor ArrayCopyTo ArrayCopyTo2 ArrayGetEnumerator ArrayGetLength ArrayGetLowerBound ArrayGetSyncRoot ArrayIndexOf ArrayList Async1 Async2 Barrier BitArray BitConverterGetBytesBoolean BitConverterGetBytesChar BitConverterIsLittleEndian BitConverterToString Boolean1 Boolean2 Boolean3 Boolean4 Boolean5 Boolean6 Boolean8 Boxing ClientWebSocket ConcurrentBag ConcurrentQueue ConcurrentStack Console ConsoleOut ConsoleReadKey DateTime DateTimeSpecifyKind Debug Delegate Delegate2 Dictionary DictionaryAdd DictionaryOperators DirectorySeparatorChar Enum Enum2 Environment EventHandler Exception ExceptionPointer Factorial FlagsEnum Foreach1 Foreach2 Foreach3 Foreach4 Format FunctionPointer HashSet HelloWorld HttpWebRequest Interlocked InterlockedDecrement List List2 List3 ListBinarySearch ListCopyTo ListExists ListFind ListReverse Main Math Nullable Object ParallelInvoke Process Profile Properties  Random1 Random2 Random3 Socket SortedDictionary SortedDictionaryAdd SortedDictionaryOperators SortedSet Stopwatch StreamReader StreamReaderReadLine StreamReaderReadToEnd StringCollection StringDictionary StringLiterals StringReader Task TaskDelay TcpClient Thread Thread1 Thread2 Thread3 Thread4 ThreadLocal TextWriterTraceListener Timer Timer2 Trace Tuple2 UdpClient UdpClientListener UdpClientTalker Unused Var)
set(DRAWING_EXAMPLES Color)
set(FORMS_EXAMPLES Application Form SystemSound)
#set(FORMS_EXAMPLES Application Button Calculator CheckBox CheckedListBox Chrono Colors Controls Cursor DockedControls DragAndDrop FolderBrowserDialog Font FontFamily Form FormAndThread FormException FormHelloWorld FormTimer GroupBox ImageList KeyEvents Label ListBox MainMenu MaskedTextBox MessageBox MouseEvents MulticamInstaller NumericUpDown OpenFileDialog Paint Panel PictureBox ProgressBar RadioButton Resource RichTextBox SaveFileDialog Sudoku SystemSound TabControl TextBox UserControl)
set(TUNIT_EXAMPLES Assert Expect TestFixture)

add_subdirectory("Core")
add_subdirectory("Drawing")
add_subdirectory("Forms")
add_subdirectory("TUnit")
