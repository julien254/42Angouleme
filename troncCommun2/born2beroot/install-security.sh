#!/bin/sh
git clone https://github.com/julien254/42Angouleme.git
echo "Installation et configuation du pare-feu UFW..."
apt-get install ufw -y && ufw enable && systemctl start ufw && systemctl enable ufw && ufw allow 4242 && systemctl restart ufw
echo "Installation et configuration du pare-feu UFW termine."
echo "Installation et configuration du serveur SSH."
apt-get install openssh-server -y
curl https://raw.githubusercontent.com/julien254/42Angouleme/main/troncCommun2/born2beroot/sshd_config > /etc/ssh/sshd_config
service ssh restart
echo "Installation et configuration du serveur SSH termine."
echo "Installation de fail2ban..."
apt install rsyslog -y
apt install fail2ban -y
sudo cp 42Angouleme/troncCommun2/born2beroot/jail.local /etc/fail2ban/jail.local
systemctl start fail2ban
systemctl enable fail2ban
systemctl status fail2ban
echo "Configuration du fichier sudoers..."
mkdir /var/log/sudo
cat 42Angouleme/troncCommun2/born2beroot/sudoers > /etc/sudoers
echo "Configuration du fichier sudoers termine"
echo "installation et configuration de la politique de mot de passe..."
apt-get install libpam-pwquality -y
cat 42Angouleme/troncCommun2/born2beroot/common-password > /etc/pam.d/common-password
echo "Configuration du delais de changement de mot de passe..."
cat 42Angouleme/troncCommun2/born2beroot/login.defs > /etc/login.defs
chage -M 30 root
chage -m 2 root
chage -W 7 root
chage -M 30 judetre
chage -m 2 judetre
chage -W 7 judetre
echo "Configuration termine."
echo "Si vous n'avez pas lance le script en tant qu'utilisateur root, veillez recommencer l'installation."
echo "N'oubliez pas de configurer la redirection de port si vous utiliser une VM dans les parametres de celle-ci."
echo "Penser a redemarrer la VM pour que tous les changements soient pris en compte."
