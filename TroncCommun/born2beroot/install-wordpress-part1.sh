#!/bin/sh
echo "Installation de php8..."
sudo curl -sSL https://packages.sury.org/php/README.txt | sudo bash -x
sudo apt install -y php8.2
sudo apt install -y php-common php-cgi php-cli php-mysql
sudo apt purge -y apache2
echo "Installation de php8 termine"
echo "Installation de lighttpd..."
sudo apt install -y lighttpd
echo "Installation de lighttpd termine"
echo "Activation de lighttpd..."
sudo systemctl start lighttpd
sudo systemctl enable lighttpd
sudo systemctl status lighttpd
echo "lighttpd est maintenant active"
echo "Ouverture des ports http"
sudo ufw allow 80
sudo systemctl restart ufw
sudo ufw status
echo "Ports configure"
curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/wordpress/info.php > ~/info.php
sudo mv info.php /var/www/html/
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo service lighttpd force-reload
echo "Installation et configuration de mariadb..."
sudo apt install -y mariadb-server
sudo systemctl start mariadb
sudo systemctl enable mariadb
echo "\n\n\n\nConfiguration de la securite de MariaDB :\n"
echo "Exemple de configuration :"
echo "Enter current password for root (enter for none): <Entrée>"
echo "Switch to unix_socket authentication [Y/n]: Y"
echo "Set root password? [Y/n]: Y"
echo "New password: choix-du-mot-de-passe"
echo "Re-enter new password: choix-du-mot-de-passe"
echo "Remove anonymous users? [Y/n]: Y"
echo "Disallow root login remotely? [Y/n]: Y"
echo "Remove test database and access to it? [Y/n]:  Y"
echo "Reload privilege tables now? [Y/n]:  Y"
sudo mysql_secure_installation
wait
echo "\nEntrer a present la commande suivante : curl https://raw.githubusercontent.com/julien254/42Angouleme/main/TroncCommun/born2beroot/install-wordpress-part2.sh | sh"
