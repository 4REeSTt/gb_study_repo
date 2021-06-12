# Just write it in crontab -e file and it will make backup of etc for us
0 5 * * 1 tar -zcf /var/backups/ect.tgz /etc/
