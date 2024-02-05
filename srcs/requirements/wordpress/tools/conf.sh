#https://make.wordpress.org/cli/handbook/how-to/how-to-install/

# if [ ! -e "/var/www/wp-config.php" ]; then
#     adduser -u 82 -D -S -G www-data www-data
#     wp core download --allow-root
#     wp config create --dbname=$DB_NAME --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$DB_HOST --skip-check
#     wp core install --url=$DOMAIN_NAME --title=$WP_NAME --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL
#     wp user create ${WP_USER} $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD
# fi

adduser -u 82 -D -S -G www-data www-data
/usr/sbin/php-fpm81 -F