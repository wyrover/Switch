OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]]; then
  OSTYPE=`lsb_release -si`
fi

case "$OSTYPE" in
  *"Darwin"*) ./install_macosx_xcode.sh;;
  *"Ubuntu"*) ./install_ubuntu_clang.sh;;
  *"CentOS"*) ./install_centos_clang.sh;;
  *) ./install_linux_clang.sh;;
esac
