# Урок 3
## Задание 1

##### Создаем 3 пользователя (randomusr, randomusr2, newusr) используя команды

    $ useradd -m -s /bin/bash -d /home/randomusr
    $ adduser randomusr2
    $ mkdir /home/newusr
    $ vim /etc/passwd (Добавляем в конец файла "newusr:x:1003:1003::/home/newusr:/bin/bash")
    $ cd /home/newusr | cp /etc/skel/.bash... ./  (Копируем содержимое дирректории skel)
    $ vim /etc/group (Добавляем "newusr:x:1003:")

![](./Screenshot_1.png)

##### После чего удаляем пользователя

    $ userdel randomusr2
    
![](./Screenshot_2.png)

## Задание 2
##### Создаем группу и добавляем пользователя в группу

    $ groupadd newgr
    $ usermod -aG newgr newusr
    
![](./Screenshot_3.png)
