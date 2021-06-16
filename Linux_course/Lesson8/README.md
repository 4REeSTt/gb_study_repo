## Урок 8
## Задание 1

    $ sudo pacman -S docker
    
##### Так же можно устанавливать как указано в мануале(сделал так на другой системе, разницы не ощутил)

    $ apt-get install apt-transport-https ca-certificates curl gnupg-agent software-properties-common -y
    $ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | apt-key add -
    $ add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
    
    
    
## Задание 2

    $ sudo docker pull ubuntu
    $ sudo docker run -it ubuntu
    
##### Тут мы переходим в VM(контейнер) с ubutnu. Все запустилось с arch linux
## Задание 3
##### Dockerfile


    FROM ubuntu:latest
    MAINTAINER User GB
    RUN apt-get update
    RUN apt-get install -y nginx php7.2-fpm
    
    COPY default ${nginx_vhost}
    RUN mkdir -p /run/php && \
        chown -R www-data:www-data /var/www/html && \
        chown -R www-data:www-data /run/php
    RUN sed -i -e 's/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g' ${php_conf} && \
        echo "\ndaemon off;" >> ${nginx_conf}

    VOLUME ["/etc/nginx/sites-enabled", "/etc/nginx/certs", "/etc/nginx/conf.d", "/var/log/nginx", "/var/www/html"]
    
    COPY start.sh /start.sh
    CMD ["./start.sh"]
    EXPOSE 80

