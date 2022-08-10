#!/bin/sh
echo "Installation et configuation du pare-feu UFW..."
apt install ufw -y && ufw enable && systemctl start ufw && systemctl enable ufw && ufw allow 4242 && systemctl restart ufw
echo "Installation et configuration du pare-feu UFW termine."
echo "Installation et configuration du serveur SSH."
apt install openssh-server -y
curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/sshd_config > /etc/ssh/sshd_config
service ssh restart
echo "Installation et configuration du serveur SSH termine."
echo "Configuration du fichier sudoers..."
mkdir /var/log/sudo
curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/sudoers > /etc/sudoers
echo "Configuration du fichier sudoers termine"
echo "installation et configuration de la politique de mot de passe..."
apt install libpam-pwquality
curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/common-password > /etc/pam.d/common-password
echo "Configuration du delais de changement de mot de passe"
curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/login.defs > /etc/login.defs
chage -M 30 root
chage -m 2 root
chage -W 7 root
chage -M 30 jdetre
chage -m 2 jdetre
chage -W 7 jdetre
echo "Configuration termine."
echo "Si vous n'avez pas lance le script en tant qu'utilisateur root, veillez recommencer l'installation."
echo "N'oubliez pas de configurer la redirection de port si vous utiliser un VM dans les parametres de celle-ci."
