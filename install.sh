OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]]; then
  OSTYPE=`lsb_release -si`
fi

case "$OSTYPE" in
  *"CentOS"*) ./install_centos_clang.sh;;
  *"Darwin"*) ./install_macosx_xcode.sh;;
  *"Debian"*) ./install_debian_clang.sh;;
  *"elementary"*) ./install_elementary_os_clang.sh;;
  *"Fedora"*) ./install_fedora_clang.sh;;
  *"Mint"*) ./install_mint_clang.sh;;
  *"RedHat"*) ./install_redhat_clang.sh;;
  *"Suze"*) ./install_suze_clang.sh;;
  *"Ubuntu"*) ./install_ubuntu_clang.sh;;
  *) ./install_linux_clang.sh;;
esac
