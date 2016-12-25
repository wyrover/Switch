# Show install version
function ShowVersion() {
  echo "Install Pcf libraries version 1.0.0, copyright GAMMA Soft, 2016"
  echo ""
}

# Show install parameters usage
ShowUsage() {
  echo ""
  echo "Usage"
  echo ""
  echo "  install [options]"
  echo ""
  echo "options"
  echo "  -g, --generator <Generator> = cmake generator (for more information type 'cmake --help')"
  echo "  -t, --targets <Targets>     = targets to install with specified Targets:"
  echo "                                  * All           = All projects"
  echo "                                  * Applications  = Applications projects"
  echo "                                  * Libraries     = Libraries projects"
  echo "                                  * ThirdParties  = ThirdParties projects"
  echo "                                  * Documentation = Pcf Documentation"
  echo ""
  echo "Example:"
  echo "  ../Sources/install.sh -g \"Eclipse CDT4 - Unix Makefiles\" -t All"
  echo ""
}

# Check if an error occurred. If true exit with error.
function CheckError() {
  "$@"
  local status=$?
  if [ $status -ne 0 ]; then
    echo ""
    echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" >&2
    echo "! error $status with $1 $2 $3" >&2
    echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" >&2
    echo ""
  fi
  return $status
}

# Make Project. Create build directory, generate project and build the specified target
# $1 category (e.g. ThirdParties, Libraries, ...) that specify subdirectory for the target
# $2 project the project name
# $3 target the target to build
function MakeProject() {
  local category=$1
  local project=$2
  local target=$3
  local configuration=$4
  local currentFolder=`pwd`
  mkdir -p $output_pah/$category/$project
  cd $output_pah/$category/$project
  CheckError cmake -G "$generator" ../../$sources_path/$category/$project/
    case "$generator" in
      "Xcode") CheckError xcodebuild -target $target -configuration $configuration;;
      "Unix Makefiles") CheckError make $target;;
    esac
  cd $currentFolder
}

# Make target. Create build directory, generate project and build the specified project
# $1 category (e.g. ThirdParties, Libraries, ...) that specify subdirectory for the target
# $2 project the project name
function MakeTarget() {
  echo ""
  echo "________________________________________________________________________________"
  echo "MakeTaget $1 $2 $3"
  echo ""
  MakeProject $1 $2 $2 $3
}
 
# Make install. Create build directory, generate project and build the install project
# $1 category (e.g. ThirdParties, Libraries, ...) that specify subdirectory for the target
# $2 project the project name
function MakeInstall() {
  echo ""
  echo "________________________________________________________________________________"
  echo "MakeInstall $1 $2 $3"
  echo ""
  MakeProject $1 $2 install $3
}

function MakeDocumentation() {
  echo ""
  echo "________________________________________________________________________________"
  echo "MakeDocumentation"
  echo ""
  MakeProject Libraries Pcf doc debug
  local currentFolder=`pwd`
  CheckError open $sources_path/../../Help/html/index.html
  cd $currentFolder
}

doxygen_path=`dirname $0`
sources_path=`dirname $0`
output_pah=`dirname .`
targets=All
case "$OSTYPE" in
  darwin*) generator="Xcode";;
  linux*) generator="Unix Makefiles";;
  *) generator="Unix Makefiles";;
esac

while [[ $# -gt 0 ]]; do
  key="$1"
  case $key in 
    -g|--generator) generator="$2"; shift;;
    -h|--help) ShowUsage, exit;;
    -t|--targets) targets=$2; shift;;
    -v|--version) ShowVersion; exit;;
    *) ShowUsage; exit;;
  esac
  shift
done

if ! [[ "$targets" == "All" || "$targets" == "Applications" || "$targets" == "Libraries" || "$targets" == "ThirdParties" || "$targets" == "Documentation" ]]; then
  ShowUsage
  exit
fi

if [[ "$targets" == "All" || "$targets" == "Applications" || "$targets" == "Libraries" || "$targets" == "Documentation" ]]; then
  MakeDocumentation
fi

if [[ "$targets" == "All" || "$targets" == "ThirdParties" || "$targets" == "Libraries" || "$targets" == "Applications" ]]; then
  local thirdParties=( fltk zlib call_stack easywsclient Fl_Gel_Tabs gel_button gtest jpeglib libcurl libpng Rs232 ) 
  for thirdParty in ${thirdParties[@]}; do
    MakeInstall ThirdParties $thirdParty Debug
    MakeInstall ThirdParties $thirdParty Release
  done
fi

if [[ "$targets" == "All" || "$targets" == "Libraries" || "$targets" == "Applications" ]]; then
  local libraries=( Pcf Toolbox ) 
  for library in ${libraries[@]}; do
    MakeInstall Libraries $library Debug
    MakeInstall Libraries $library Release
  done
fi

if [[ "$targets" == "All" || "$targets" == "Libraries" || "$targets" == "Applications" ]]; then
  local examples=( Example ) 
  for example in ${examples[@]}; do
    MakeInstall Examples $exemple Debug
    MakeInstall Examples $exemple Release
  done
fi

if [[ "$targets" == "All" || "$targets" == "Applications" ]]; then
  local applications=( ConsoleApp CountsLines FormHelloWorld PasswordGenerator TUnit )
  for application in ${applications[@]}; do
    MakeTarget Applications $application Debug
    MakeTarget Applications $application Release
  done
fi

echo ""
echo "--------------------------------------------------------------------------------"
echo "--- Create project, build and install with success                           ---"
echo "--------------------------------------------------------------------------------"
echo ""
