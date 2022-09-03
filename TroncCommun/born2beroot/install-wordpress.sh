#!/bin/sh
git clone https://github.com/julien254/42Angouleme.git
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
cat 42Angouleme/TroncCommun/born2beroot/wordpress/info.php > ~/info.php
sudo mv ~/info.php /var/www/html/
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
sudo apt -y install wget tar
wget http://wordpress.org/latest.tar.gz
tar -xzvf latest.tar.gz
sudo mv wordpress/* /var/www/html/
rm -rf latest.tar.gz wordpress/
sudo mv /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
echo "Changement des droits du repertoire wordpress..."
sudo chown -R www-data:www-data /var/www/html/
sudo chmod -R 755 /var/www/html/
echo "Pour lier la database a wordpress,"
echo "Ouvrer avec sudo le fichier /var/www/html/wp-config.php,"
echo "Chercher les lignes suivante et changer les infos pour qu'elles correspondent qvec les infos de votre base de donne :"
echo "define( 'DB_NAME', 'nom-de-votre-database' );"
echo "define( 'DB_USER', 'votre-user' );"
echo "define( 'DB_PASSWORD', 'votre-mdp' );"
echo "define( 'DB_HOST', 'localhost' );"
echo "Apres cela redemarrer la VM (sudo reboot), connectez vous a l'aide de votre navigateur a l'adresse suivante pour profiter pleinement de votre tous nouveau site wordpress ! Please enjoy : http://localhost:8080 ."
