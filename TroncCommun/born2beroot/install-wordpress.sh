#!/bin/sh
git clone https://github.com/julien254/42Angouleme.git
echo "Installation de php8..."
sudo curl -sSL https://packages.sury.org/php/README.txt | sudo bash -x
sudo apt-get install -y php8.2
sudo apt-get install -y php-common php-cgi php-cli php-mysql
sudo apt-get purge -y apache2
echo "Installation de php8 termine"
echo "Installation de lighttpd..."
sudo apt-get install -y lighttpd
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
sudo apt-get install -y mariadb-server
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
echo "\n\n\nLiaison de la base de donnees a Wordpress :\n"
echo "Quel est le nom de votre base de donnees ?"
read DB
echo "Quel est votre nom utilisateur MariaDB ?"
read USER
echo "Quel est votre mot de passe MariaDB ?"
read MDP
echo "<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to 'wp-config.php'
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', '$DB' );

/** Database username */
define( 'DB_USER', '$USER' );

/** Database password */
define( 'DB_PASSWORD', '$MDP' );

/** Database hostname */
define( 'DB_HOST', 'localhost' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'put your unique phrase here' );
define( 'SECURE_AUTH_KEY',  'put your unique phrase here' );
define( 'LOGGED_IN_KEY',    'put your unique phrase here' );
define( 'NONCE_KEY',        'put your unique phrase here' );
define( 'AUTH_SALT',        'put your unique phrase here' );
define( 'SECURE_AUTH_SALT', 'put your unique phrase here' );
define( 'LOGGED_IN_SALT',   'put your unique phrase here' );
define( 'NONCE_SALT',       'put your unique phrase here' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
\$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the 'stop editing' line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';" > wp-config.php ; sudo mv wp-config.php /var/www/html/
echo "Apres cela redemarrer la VM (sudo reboot),puis connectez vous a l'aide de votre navigateur a l'adresse suivante pour profiter pleinement de votre tous nouveau site wordpress ! Please enjoy : http://localhost:8080 ."
