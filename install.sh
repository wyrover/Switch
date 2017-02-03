# Show install version
function ShowVersion() {
  echo "Install Pcf libraries version 1.0.0, copyright GAMMA Soft, 2016"
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

function RemoveDirectory() {
  CheckError rm -r $1
}

function CreateDirectory() {
  CheckError mkdir -p $1
}

# Make Project. Create build directory, generate project and build the specified target
function CreateDirectoryWithPermission() {
  CheckError sudo mkdir -p $1
  CheckError sudo chmod 777 $1
}

function Build() {
  CheckError cmake -G "Xcode" $1
  CheckError xcodebuild -target install -configuration Debug
  CheckError xcodebuild -target install -configuration Release
}

function BuildDoc() {
  CheckError cmake -G "Xcode" $1
  CheckError xcodebuild -target documentation -configuration Debug
  CheckError open Help/html/index.html
}

function InstallPackage {
  brew update
  brew install cmake
  brew install curl
  brew install doxygen
  brew install jpeg
  brew install libpng
  brew install zlib
}

MakeDirectoryWithPermission usr/local/cmake
installPackage
RemoveDirectory Build
CreateDirectory Build/ThirdParties
CreateDirectory Build/Examples
cd Build/ThirdParties
Build ../../ThirdParties
cd ..





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
  CheckError open $sources_path/Help/html/index.html
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
    -h|--help) ShowUsage; exit;;
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
  local thirdParties=( zlib call_stack easywsclient gtest jpeglib libcurl libpng Rs232 ) 
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

if [[ "$targets" == "All" || "$targets" == "Applications" ]]; then
  #local applications=( ConsoleApp CountsLines FormHelloWorld PasswordGenerator TUnit )
  local applications=( ConsoleApp CountsLines )
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
