echo "Install Switch libraries version 0.3.2, copyright GAMMA Soft, 2017"
echo ""

OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]]; then
  OSTYPE=`lsb_release -si`
fi

case "$OSTYPE" in
  *"CentOS"*) ./install/install_centos_clang.sh;;
  *"Darwin"*) ./install/install_macosx_xcode.sh;;
  *"Debian"*) ./install/install_debian_clang.sh;;
  *"elementary"*) ./install/install_elementary_os_clang.sh;;
  *"Fedora"*) ./install/install_fedora_clang.sh;;
  *"LinuxMint"*) ./install/install_mint_clang.sh;;
  *"RedHat"*) ./install/install_redhat_clang.sh;;
  *"Suze"*) ./install/install_suze_clang.sh;;
  *"Ubuntu"*) ./install/install_ubuntu_clang.sh;;
  *) ./install/install_linux_clang.sh;;
esac
