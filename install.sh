OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]]; then
  OSTYPE=`lsb_release -si`
fi

case "$OSTYPE" in
  *"CentOS"*) ./install_redhat_clang.sh;;
  *"Darwin"*) ./install_macosx_xcode.sh;;
  *"elementary"*) ./install_debian_clang.sh;;
  *"Fedora"*) ./install_redhat_clang.sh;;
  *"RedHat"*) ./install_redhat_clang.sh;;
  *"Suze"*) ./install_suze_clang.sh;;
  *"Ubuntu"*) ./install_debian_clang.sh;;
  *) ./install_linux_clang.sh;;
esac
