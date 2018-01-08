![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

# c++17 ready

The following table represents some Switch classes and their Standard C++ equivalent :

| Switch C++ Class                                               | Standard C++ equivalent                                                                                                       |
|----------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| any                                                            | std::any **(C++17)**                                                                                                          |
| ExceptionPtr                                                   | std::exception_ptr **(C++11)**                                                                                                |
| ref\<T\>                                                       | std::ref\<T\> **(C++11)**                                                                                                     |
| refptr\<T\>                                                    | std::shared_ptr\<T\> **(C++11)**                                                                                              |
| _\<T\>                                                         | std::shared_ptr\<T\> **(C++11)**                                                                                              |
| System::Array\<T\>                                             | std::vector\<T\>, std::array\<T\> **(C++11)**                                                                                 |
| System::Array\<T, N\>                                          | std::vector\<T\>, std::array\<T\> **(C++11)**                                                                                 |
| System::Console::Error                                         | std::cerr                                                                                                                     |
| System::Console::In                                            | std::cin                                                                                                                      |
| System::Console::Out                                           | std::cout                                                                                                                     |
| Sytem::Delegate\<...\>                                         | std::vector\<std::function\<...\>\> **(C++11)**                                                                               |
| System::Exception                                              | std::exception                                                                                                                |
| System::Nullable\<T\>                                          | std::optional\<T\> **(C++17)**                                                                                                |
| System::String                                                 | std::string                                                                                                                   |
| System::Tuple\<...\>                                           | std::tuple\<...\> **(C++11)**                                                                                                 |
| System::Collections::ArrayList                                 | std::vector\<std::any\> **(C++17)**                                                                                           |
| System::Collections::BitArray                                  | std::bitset\<std::size_t N\>                                                                                                  |
| System::Collections::DictionaryEntry                           | std::pair\<std::any, std::any\> **(C++17)**                                                                                   |
| System::Collections::Enumerator                                | const std::iterator **(C++14)**                                                                                               |
| System::Collections::Hashtable                                 | std::unordered_map\<std::any, std::any\> **(C++17)**                                                                          |
| System::Collections::Queue                                     | std::queue\<std::any\> **(C++17)**                                                                                            |
| System::Collections::Stack                                     | std::stack\<std::any\> **(C++17)**                                                                                            |
| System::Collections::Generic::Dictionary\<TKey, TValue\>       | std::unordered_map\<TKey, TValue\> **(C++11)**                                                                                |
| System::Collections::Generic::Enumerator\<T\>                  | const std::iterator **(C++14)**                                                                                               |
| System::Collections::Generic::HashSet\<T\>                     | std::unordered_set\<T\> **(C++11)**                                                                                           |
| System::Collections::Generic::KeyValuePair\<TKey, TValue\>     | std::pair\<TKey, TValue\>                                                                                                     |
| System::Collections::Generic::LinkedList\<T\>                  | std::list\<T\>                                                                                                                |
| System::Collections::Generic::List\<T\>                        | std::vector\<T\>                                                                                                              |
| System::Collections::Generic::Queue\<T\>                       | std::queue\<T\>                                                                                                               |
| System::Collections::Generic::SortedDictionary\<TKey, TValue\> | std::map\<TKey, TValue\>                                                                                                      |
| System::Collections::Generic::SortedSet\<T\>                   | std::set\<T\>                                                                                                                 |
| System::Collections::Generic::Stack\<T\>                       | std::stack\<T\>                                                                                                               |
| System::Collections::ObjectModel::Collection\<T\>              | std::vector\<T\>                                                                                                              |
| System::Collections::ObjectModel::ReadOnlyCollection\<T\>      | const std::vector\<T\>                                                                                                        |
| System::Collections::Specialized::StringCollection             | std::vector\<std::string\>                                                                                                    |
| System::Collections::Specialized::StringDictionary             | std::map\<std::string, std::string\>                                                                                          |
| System::Collections::Specialized::StringEnumerator             | const std::iterator **(C++14)**                                                                                               |
| System::Collections::Specialized::StringKeyValuePair           | std::pair\<std::string, std::string\>                                                                                         |
| System::Collections::Specialized::StringKeyValuePairEnumerator | const std::iterator **(C++14)**                                                                                               |
| System::Diagnostics::Stopwatch                                 | std::chrono::high_resolution_clock **(C++11)**                                                                                |
| System::IO::BinaryReader                                       | std::istream                                                                                                                  |
| System::IO::BinaryWriter                                       | std::ostream                                                                                                                  |
| System::IO::Directory                                          | std Filesystem library Directory function **(C++17)**                                                                         |
| System::IO::Directory::EnumerateDirectories                    | std::directory_iterator **(C++17)**, std::recursive_directory_iterator **(C++17)**                                            |
| System::IO::DicrectoryInfo                                     | std::directory_entry **(C++17)**                                                                                              |
| System::IO::DriveInfo                                          | std::space_info **(C++17)**                                                                                                   |
| System::IO::File                                               | std Filesystem library File functions **(C++17)**                                                                             |
| System::IO::FileInfo                                           | std::file_status **(C++17)**, std::file_type **(C++17)**, std::file_time_type **(C++17)**                                     |
| System::IO::FileStream                                         | std::fstream                                                                                                                  |
| System::IO::Path                                               | std::path **(C++17)**                                                                                                         |
| System::IO::StreamReader                                       | std::istream                                                                                                                  |
| System::IO::StreamWriter                                       | std::ostream                                                                                                                  |
| System::Linq::Enumerable                                       | std Algorithms Library functions                                                                                              |
| System::Threading::Task\<\>                                    | std::future **(C++11)**, std::promise **(C++11)**, std::async **(C++11)**, std::launch **(C++11)**                            |
| System::Threading::Task\<T\>                                   | std::future **(C++11)**, std::promise **(C++11)**, std::async **(C++11)**, std::launch **(C++11)**                            |
| System::Threading::AutoResetEvent                              | std::condition_variable **(C++11)**, std::condition_variable_any **(C++11)**                                                  |
| System::Threading::EventWaitHandle                             | std::condition_variable **(C++11)**, std::condition_variable_any **(C++11)**                                                  |
| System::Threading::Interlocked                                 | std Atomic operations library functions **(C++11)**                                                                           |
| System::Threading::ManualResetEvent                            | std::condition_variable **(C++11)**, std::condition_variable_any **(C++11)**                                                  |
| System::Threading::Mutex                                       | std::mutex **(C++11)**, std::timed_mutex **(C++11)**, std::recursive_mutex **(C++11)**, std::recursive_timed_mutex **(C++11)**|
| System::Threading::Thread                                      | std::thread **(C++11)**                                                                                                       |

For more information see [Switch Reference Guide](https://gammasoft71.github.io/Switch-doc) and [C++ reference](http://en.cppreference.com)


______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
