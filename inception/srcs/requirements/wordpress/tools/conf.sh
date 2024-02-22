#https://make.wordpress.org/cli/handbook/how-to/how-to-install/

if [ ! -e "/var/www/wp-config.php" ]; then
    wget https://ko.wordpress.org/latest-ko_KR.tar.gz && \
    gzip -d latest-ko_KR.tar.gz && tar xvf latest-ko_KR.tar && rm -f latest-ko_KR.tar && mv wordpress/* /var/www/ && rm -rf wordpress
    wp config create --dbname=$DB_NAME --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$DB_HOST --skip-check
    wp core install --url=$DOMAIN_NAME --title=$WP_NAME --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL
    wp user create $WP_USER $WP_USER_EMAIL --user_pass=$WP_USER_PASSWORD
fi

/usr/sbin/php-fpm81 -F