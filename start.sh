#!/usr/bin/bash/expect

cd /home/flora/DO6_CICD-0/src/cat

#scp s21_cat user_2@192.168.170.120:/usr/local/bin/
# spawn ssh "user_2\@192.168.170.120"
# - ssh "user_2\@192.168.170.120"
    # - expect "assword:"
    # - send "@flora9090\r"
    #- sshpass -p @flora9090 scp s21_cat "user_2@192.168.170.120:/usr/local/bin/"

    # - sshpass -p @flora9090 scp s21_cat "user_2@192.168.170.120:/home/user_2/"
    # - sshpass -p @flora9090 ssh user_2@192.168.170.120
    # - sudo sshpass -p @flora9090 mv s21_cat /usr/local/bin/
    # - exit
spawn ssh user_2@192.168.170.120
expect "user_2@192.168.170.120's password: "
send -- "@flora9090\r"
pwd
expect eof