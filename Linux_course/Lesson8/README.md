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

