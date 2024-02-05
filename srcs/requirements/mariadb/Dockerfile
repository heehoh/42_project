FROM alpine:3.18

RUN apk update && apk add --no-cache dumb-init mariadb mariadb-client openrc

COPY ./tools/my.cnf /etc/my.cnf

COPY ./tools/conf.sh .

EXPOSE 3306

ENTRYPOINT ["/usr/bin/dumb-init", "--", "sh", "conf.sh"]