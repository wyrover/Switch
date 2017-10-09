echo "Install Switch libraries version 0.3.4, copyright GAMMA Soft, 2017"
echo ""

OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]]; then
  OSTYPE=`lsb_release -si`
fi

case "$OSTYPE" in
  *"CentOS"*) ./scripts/install/install_centos_clang.sh;;
  *"Darwin"*) ./scripts/install/install_macosx_xcode.sh;;
  *"Debian"*) ./scripts/install/install_debian_clang.sh;;
  *"elementary"*) ./scripts/install/install_elementary_os_clang.sh;;
  *"Fedora"*) ./scripts/install/install_fedora_clang.sh;;
  *"LinuxMint"*) ./scripts/install/install_mint_clang.sh;;
  *"RedHat"*) ./scripts/install/install_redhat_clang.sh;;
  *"Suze"*) ./scripts/install/install_suze_clang.sh;;
  *"Ubuntu"*) ./scripts/install/install_ubuntu_gcc.sh;;
  *) ./scripts/install/install_linux_clang.sh;;
esac
