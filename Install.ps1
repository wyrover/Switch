param([string]$targets = "All", [string]$generator = "Visual Studio 14 2015 Win64")

# Show install version
function ShowVersion() {
  Write-Output "Install Pcf libraries version 1.0.0, copyright GAMMA Soft, 2016"
  Write-Output ""
}

# Show install parameters usage
function ShowUsage() {
  Write-Output ""
  Write-Output "Usage"
  Write-Output ""
  Write-Output "  install [options]"
  Write-Output ""
  Write-Output "options"
  Write-Output "  -generator <Generator> = cmake generator (for more information type 'cmake --help')"
  Write-Output "  -targets <Targets>     = targets to install with specified Targets:"
  Write-Output "                             * All           = All projects"
  Write-Output "                             * Applications  = Applications projects"
  Write-Output "                             * Libraries     = Libraries projects"
  Write-Output "                             * ThirdParties  = ThirdParties projects"
  Write-Output "                             * Documentation = Pcf Documentation"
  Write-Output ""
  Write-Output "Example:"
  Write-Output "  install -generator ""Eclipse CDT4 - Unix Makefiles"" -target All"
  Write-Output ""
}

# Make Project. Create build directory, generate project and build the specified target
# $1 category (e.g. ThirdParties, Libraries, ...) that specify subdirectory for the target
# $2 project the project name
# $3 target the target to build
function MakeProject($category, $project, $target, $configuration) {
  $currentFolder = Get-Location
  New-Item -force -ItemType Directory ..\Build\$category\$project
  Set-Location ..\Build\$category\$project
  cmake -G "$generator" ..\..\..\Sources\$category\$project\
  Devenv "$project.sln" /build $configuration /project $target
  Set-Location $currentFolder
}

# Make target. Create build directory, generate project and build the specified project
# $1 category (e.g. ThirdParties, Libraries, ...) that specify subdirectory for the target
# $2 project the project name
function MakeTarget($category, $project, $configuration) {
  Write-Output ""
  Write-Output "________________________________________________________________________________"
  Write-Output "MakeTaget $category $project"
  Write-Output ""
  MakeProject $category $project $project $consiguration
}
 
# Make install. Create build directory, generate project and build the install project
# $1 category (e.g. ThirdParties, Libraries, ...) that specify subdirectory for the target
# $2 project the project name
function MakeInstall($category, $project, $configuration) {
  Write-Output ""
  Write-Output "________________________________________________________________________________"
  Write-Output "MakeInstall $category $project"
  Write-Output ""
  MakeProject $category $project install $configuration
}

# Make documentation. Lauch doxygen with Pcf.Doxyfile
function MakeDocumentation() {
  Write-Output ""
  Write-Output "________________________________________________________________________________"
  Write-Output "MakeDocumentation Pcf"
  Write-Output ""
  $currentFolder = Get-Location
  Set-Location Libraries/Pcf/Documentations/
  doxygen Pcf.Doxyfile
  Invoke-Item ../../../../Help/html/index.html
  Set-Location $currentFolder
}

ForEach ($arg in $args) {
  if ($arg.Equals("-version")) {
    ShowVersion
	exit
  }
  if ($arg.Equals("-help")) {
    ShowUsage
	exit
  }
}

if (!($targets.Equals("All") -Or $targets.Equals("Applications") -Or $targets.Equals("Libraries") -Or $targets.Equals("Documentation") -Or $targets.Equals("ThirdParties"))) {
  ShowUsage
  exit
}

if ($targets.Equals("All") -Or $targets.Equals("Applications") -Or $targets.Equals("Libraries") -Or $targets.Equals("Documentation")) {
  MakeDocumentation
}

if ($targets.Equals("All") -Or $targets.Equals("Applications") -Or $targets.Equals("Libraries") -Or $targets.Equals("ThirdParties")) {
  $thirdParties = @("fltk", "zlib", "call_stack", "easywsclient", "Fl_Gel_Tabs", "gel_button", "gtest", "jpeglib", "libcurl", "libpng", "Rs232") 
  ForEach ($thirdParty In $thirdParties) {
    MakeInstall ThirdParties $thirdParty Debug
    MakeInstall ThirdParties $thirdParty Release
  }
}

if ($targets.Equals("All") -Or $targets.Equals("Applications") -Or $targets.Equals("Libraries")) {
  $libraries = @("Pcf", "ToolBox") 
  ForEach ($library In $libraries) {
    MakeInstall Libraries $library Debug
    MakeInstall Libraries $library Release
  }
}

if ($targets.Equals("All") -Or $targets.Equals("Applications") -Or $targets.Equals("Libraries")) {
  $examples = @("Examples") 
  ForEach ($example In $examples) {
    MakeInstall Examples $example Debug
    MakeInstall Examples $example Release
  }
}

if ($targets.Equals("All") -Or $targets.Equals("Applications")) {
  $applications = @("ConsoleApp", "CountsLines", "FormHelloWorld", "PasswordGenerator", "TUnit") 
  ForEach ($application In $applications) {
    MakeTarget Applications $application Debug
    MakeTarget Applications $application Release
  }
}

Write-Output ""
Write-Output "--------------------------------------------------------------------------------"
Write-Output "--- Create project, build and install with success                           ---"
Write-Output "--------------------------------------------------------------------------------"
Write-Output ""
