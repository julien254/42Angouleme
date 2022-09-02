#!/bin/sh
cd ~/
sudo apt install git -y
git clone https://github.com/julien254/42Angouleme.git
sh 42Angouleme/TroncCommun/born2beroot/install-utils.sh
sudo sh 42Angouleme/TroncCommun/born2beroot/install-security.sh
sh 42Angouleme/TroncCommun/born2beroot/install-wordpress.sh
echo "Pour finaliser la configuration de mariadb utiliser la commande :"
echo "sh 42Angouleme/TroncCommun/born2beroot/config-mariadb.sh"
