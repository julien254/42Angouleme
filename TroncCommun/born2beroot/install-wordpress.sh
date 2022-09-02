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
sh config-mariadb.sh
