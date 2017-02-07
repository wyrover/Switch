$OSTYPE=`uname -a`
case "$OSTYPE" in
  darwin*) ./install_macosx_xcode.sh;;
  *Ubuntu*) ./install_ubuntu_gcc.sh;;
  *) ./install_linux_gcc.sh;;
esac
