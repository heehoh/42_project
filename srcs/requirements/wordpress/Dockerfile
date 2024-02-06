FROM alpine:3.18

RUN apk update && \
    apk add --no-cache dumb-init \
    php81 \
    php81-fpm \
    php81-gd \
    php81-json \
    php81-curl \
    php81-mysqli \
    php81-zip \
    php81-mbstring \
    php81-intl \
    php81-xml \
    php81-pecl-imagick \
    php-phar

COPY tools/www.conf /etc/php81/php-fpm.d/www.conf
COPY tools/conf.sh /

WORKDIR /var/www

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

RUN adduser -u 82 -D -S -G www-data www-data

EXPOSE 9000

ENTRYPOINT ["/usr/bin/dumb-init", "--", "sh", "/conf.sh"]