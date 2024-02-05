FROM alpine:3.18

RUN apk update && \
    apk add --no-cache dumb-init nginx openssl

WORKDIR /certs

# CA 인증서 생성
RUN openssl genrsa -aes256 -passout pass:${CA_PASSWORD} -out root.key 2048 && \
    openssl req -new -key root.key -passin pass:${CA_PASSWORD} -out root.csr \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=CA/CN=hujeong.42.fr/" && \
    echo "basicConstraints = CA:TRUE" > root.ext && \
    openssl x509 -req -days 3650 -in root.csr -signkey root.key -extfile root.ext -passin pass:${CA_PASSWORD} -out root.crt

# SSL 인증서 생성
RUN openssl genrsa -aes256 -passout pass:${SERVER_PASSWORD} -out server_with_password.key 2048 && \
    openssl rsa -passin pass:${SERVER_PASSWORD} -in server_with_password.key -out server.key && \
    openssl req -new -key server.key -out server.csr \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=student/CN=hujeong.42.fr/" && \
    echo "subjectAltName = DNS:hujeong.42.fr" > server.ext && \
    openssl x509 -req -days 3650 -in server.csr -CA root.crt -CAcreateserial -CAkey root.key -passin pass:${CA_PASSWORD} -extfile server.ext -out server.crt && \
    cat server.crt root.crt > server-chained.crt

WORKDIR /

COPY tools/default.conf /etc/nginx/http.d/default.conf

EXPOSE 80 443

ENTRYPOINT ["/usr/bin/dumb-init", "--", "nginx", "-g", "daemon off;"]
