#!/bin/sh
cd ~/
sudo apt install -y git
git clone https://github.com/julien254/42Angouleme.git
sh 42Angouleme/TroncCommun/born2beroot/install-utils.sh
sudo sh 42Angouleme/TroncCommun/born2beroot/install-security.sh
sh 42Angouleme/TroncCommun/born2beroot/install-wordpress.sh
echo "Pour terminer l'installation des plugins de vim, lancer l'editeur et taper :PlugInstall "
