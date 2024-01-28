FROM alpine:3.18

RUN apk update && apk upgrade && apk add nginx

COPY tools/default.conf /etc/nginx/http.d/default.conf

COPY tools/index.html /var/lib/nginx/html/index.html

CMD ["nginx", "-g", "daemon off;"]