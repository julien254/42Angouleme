#!/bin/sh
git clone https://github.com/julien254/42Angouleme.git
echo "Installation de php8..."
sudo curl -sSL https://packages.sury.org/php/README.txt | sudo bash -x
sudo apt-get install php8.2 -y
sudo apt-get install php-common php-cgi php-cli php-mysql -y
sudo apt-get purge apache2 -y
echo "Installation de php8 termine"
echo "Installation de lighttpd..."
sudo apt-get install lighttpd -y
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
cat 42Angouleme/troncCommun2/born2beroot/wordpress/info.php > ~/info.php
sudo mv ~/info.php /var/www/html/
sudo lighty-enable-mod fastcgi
sudo lighty-enable-mod fastcgi-php
sudo service lighttpd force-reload
sleep 1
echo "Installation et configuration de mariadb..."
sleep 1
sudo apt-get install mariadb-server -y
sudo systemctl start mariadb
sudo systemctl enable mariadb
sleep 1
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
sleep 1
sudo mysql_secure_installation
sleep 1
sudo systemctl restart mariadb
echo "\nConfiguration de la base de donnees:\n"
echo "Exemple de configuration rapide d'une base de donnees :"
echo "MariaDB [(none)]> CREATE DATABASE votre-nom-de-DB;"
echo "MariaDB [(none)]> CREATE USER 'votre-user'@'localhost' IDENTIFIED BY 'votre-MDP';"
echo "MariaDB [(none)]> GRANT ALL ON nom-database.* TO 'votre-user'@'localhs;ost' IDENTIFIED BY 'votre-MDP-' WITH GRANT OPTION;"
echo "MariaDB [(none)]> FLUSH PRIVILEGES;"
echo "MariaDB [(none)]> EXIT;"
echo "Entrer votre mot de passe de mariaDB"
mysql -u root -p
echo "Database operationel"
echo "Installation de Wordpress..."
sudo apt-get install wget tar -y
wget http://wordpress.org/latest.tar.gz
tar -xzvf latest.tar.gz
sudo mv wordpress/* /var/www/html/
rm -rf latest.tar.gz wordpress/
sudo mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
echo "Changement des droits du repertoire wordpress..."
sudo chown -R www-data:www-data /var/www/html/
sudo chmod -R 755 /var/www/html/
sleep 1
sudo cp /home/judetre/42Angouleme/troncCommun2/born2beroot/wp-config.php  /var/www/html/wp-config.php
echo "Apres cela redemarrer la VM (sudo reboot),puis connectez vous a l'aide de votre navigateur a l'adresse suivante pour profiter pleinement de votre tous nouveau site wordpress ! Please enjoy : http://localhost:8080 ."
