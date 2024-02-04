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
    php81-pecl-imagick

COPY tools/www.conf /etc/php8/php-fpm.d/www.conf

WORKDIR /tmp

RUN wget https://ko.wordpress.org/latest-ko_KR.tar.gz && \
    gzip -d latest-ko_KR.tar.gz && tar xvf latest-ko_KR.tar && rm -f latest-ko_KR.tar
    
RUN mv wordpress /var/www/

WORKDIR /var/www

EXPOSE 9000

# ENTRYPOINT ["/usr/bin/dumb-init", "--", "tail", "-f"]
ENTRYPOINT ["/usr/bin/dumb-init", "--", "/usr/sbin/php-fpm81", "-F"]