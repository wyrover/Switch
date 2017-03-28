OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]]; then
  OSTYPE=`lsb_release -si`
fi

case "$OSTYPE" in
  *"Darwin"*) ./install_macosx_xcode.sh;;
  *"Ubuntu"*) ./install_ubuntu_gcc.sh;;
  *"CentOS"*) ./install_centos_gcc.sh;;
  *) ./install_linux_gcc.sh;;
esac
