#!/bin/sh
cd ~/
sudo apt install git -y
git clone https://github.com/julien254/42Angouleme.git
sh 42Angouleme/TroncCommun/born2beroot/install-utils.sh
sudo sh 42Angouleme/TroncCommun/born2beroot/install-security.sh
sh 42Angouleme/TroncCommun/born2beroot/install-wordpress.sh
sh 42Angouleme/TroncCommun/born2beroot/install-monitoring.sh
echo "VIM: Pour finaliser l'installation des plugins de vim, lancer celui-ci et entrer la commande :PlugInstall.(Sur le compte ROOT egalement)\n"
echo "REDIRECTION DES PORTS: N'oubliez pas de configurer la redirection de port si vous utiliser une VM dans les parametres de celle-ci. (4242 et 80)\n"
echo "Vous devez rebooter le system pour que tous les changements soient pris en compte.\n"
echo "WORDPRESS: lancer le navigateur et aller sur http://localhost:8080 pour finaliser l'installation de votre site.\n"
