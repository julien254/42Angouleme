#!/bin/sh
echo "Installation et configuation du pare-feu UFW..."
apt install ufw -y && ufw enable && systemctl start ufw && systemctl enable ufw && ufw allow 4242 && systemctl restart ufw
echo "Installation et configuration du pare-feu UFW termine."
echo "Installation et configuration du serveur SSH."
apt install openssh-server -y
curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/sshd_config > /etc/ssh/sshd_config
service ssh restart
echo "Installation et configuration du serveur SSH termine."
echo "N'oubliez pas de configurer la redirection de port si vous utiliser un VM dans les parametres de celle-ci."
echo "Si vous n'avez pas lance le script en temp qu'utilisateur root, veillez recommencer l'installation."
