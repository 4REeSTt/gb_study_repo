# Урок 3(Делается на VM centOS)
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
##### Создаем группу и добавляем пользователя в группу(группу в ручном режиме мы создали в 1ом задании)

        $ groupadd newgr
        $ usermod -aG newgr newusr
    
![](./Screenshot_3.png)

##### Добавляем группу и меняем все группы у пользователя

        $ usermod -aG newgr,newusr randomusr
        $ usermod -G newgr randomusr (удаляются все прочие группы в которых ранее состаял пользователь(кроме основной))
        
![](./Screenshot_4.png)

##### Теперь удаляем пользователя из группы ручками

        $ vim /etc/group
        
![](./Screenshot_5.png)
![](./Screenshot_6.png)

## Задание 3
##### Возможность использовать sudo без пароля мы дадим через группу wheel (раскоментируем строку NOPASSWD) так же добавим его в группу

        $ usermod -aG wheel newusr
        
![](./Screenshot_7.png)

## Задание *
##### Тут мы прописываем определенную команду которую может вводить пользователь используя sudo и пароль своей учетной записи(изменяем файл /etc/sudoers)
![](./Screenshot_8.png)
![](./Screenshot_9.png)

