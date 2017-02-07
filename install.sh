OSTYPE=`uname -a`
if [[ "$OSTYPE" == *"darwin"* ]]; then
  echo "Install on Mac os X"
  #./install_macosx_xcode.sh
else
  OSTYPE=`lsb_release -si`
  case "$OSTYPE" in
    *"Ubuntu"*) echo "Install on Ubuntu";;
    *"CentOS"*) echo "Install on CentOs";;
    *) echo "Install on Generic linux";;
  esac
fi

#    *"Ubuntu"*) ./install_ubuntu_gcc.sh;;
#    *"CentOS"*) ./install_centos_gcc.sh;;
#    *) ./install_linux_gcc.sh;;

