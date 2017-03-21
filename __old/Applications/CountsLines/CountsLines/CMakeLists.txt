# Add include files here:
set(includeFiles
./Includes/Count.h
./Includes/FileReport.h
./Includes/FileReportCollection.h
./Includes/LanguageParam.h
./Includes/SourceFilesAnalyzerEventArgs.h
./Includes/SourceFilesAnalyzerEventHandler.h
./Includes/SourceFilesAnalyzer.h
./Includes/SourceFilesReport.h
)

# Add source files here:
set(sourceFiles
./Sources/LanguageParam.cpp
./Sources/Program.cpp
)

#Add source groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_executable(CountsLines ${includeFiles} ${sourceFiles})
target_link_libraries(CountsLines Pcf.Toolbox)
