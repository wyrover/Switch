OSTYPE=`uname -a`
if [[ "$OSTYPE" == *"Darwin"* ]]; then
  ./install_macosx_xcode.sh
else
  OSTYPE=`lsb_release -si`
  case "$OSTYPE" in
    *"Ubuntu"*) ./install_ubuntu_gcc.sh;;
    *"CentOS"*) ./install_centos_gcc.sh;;
    *) ./install_linux_gcc.sh;;
  esac
fi

