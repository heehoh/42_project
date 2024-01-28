FROM alpine:3.18

RUN apk update && apk upgrade && apk add \
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

CMD ["tail", "-f"]