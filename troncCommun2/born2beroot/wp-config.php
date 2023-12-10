<?php
// ** Paramètres de la base de données ** //
define('DB_NAME', 'mariadb');
define('DB_USER', 'judetre');
define('DB_PASSWORD', 'Lolilol04131802?');
define('DB_HOST', 'localhost');
define('DB_CHARSET', 'utf8mb4');
define('DB_COLLATE', '');

// ** Clés secrètes ** //
define('AUTH_KEY',         'mettez_ici_votre_clé_secrète');
define('SECURE_AUTH_KEY',  'mettez_ici_votre_clé_secrète');
define('LOGGED_IN_KEY',    'mettez_ici_votre_clé_secrète');
define('NONCE_KEY',        'mettez_ici_votre_clé_secrète');
define('AUTH_SALT',        'mettez_ici_votre_clé_secrète');
define('SECURE_AUTH_SALT', 'mettez_ici_votre_clé_secrète');
define('LOGGED_IN_SALT',   'mettez_ici_votre_clé_secrète');
define('NONCE_SALT',       'mettez_ici_votre_clé_secrète');

// ** Préfixe de la table de base de données ** //
$table_prefix  = 'wp_'; // Vous pouvez changer cela si vous le souhaitez.

// ** Pour les développeurs : le mode débogage ** //
define('WP_DEBUG', false);

// ** C'est tout, arrêtez d'éditer à partir de cette ligne ! ** //
if (!defined('ABSPATH')) {
    define('ABSPATH', dirname(__FILE__) . '/');
}
require_once(ABSPATH . 'wp-settings.php');
