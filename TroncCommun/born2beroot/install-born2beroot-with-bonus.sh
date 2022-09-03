#!/bin/sh
cd ~/
sudo apt install git -y
git clone https://github.com/julien254/42Angouleme.git
sh 42Angouleme/TroncCommun/born2beroot/install-utils.sh
sudo sh 42Angouleme/TroncCommun/born2beroot/install-security.sh
sh 42Angouleme/TroncCommun/born2beroot/install-wordpress.sh
echo "Pour finaliser l'installation des plugins de vim, lancer celui-ci et entrer la commande :PlugInstall. Rebooter ensuite le system pour que tout les changements soient pris en compte."
