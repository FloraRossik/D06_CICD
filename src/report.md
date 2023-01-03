# Part 1. Настройка **gitlab-runner**

## Запуск отдельной задачи:
	> gitlab-runner exec shell (name_job)
	
## Непонятные команды: 
	> ssh-keyscan -t rsa gitlab.com >> ~/.ssh/known_hosts

1. Скачать и установить на виртуальную машину **gitlab-runner 
   > sudo apt install gitlab-runner
    
   ![img.png](Part_1%2Fimg.png)
2. Проверить статус 
   > sudo service gitlab-runner status
   
   ![img_1.png](Part_1%2Fimg_1.png)
3. Зарегистрировать его для использования в текущем проекте
   > sudo gitlab-runner register

# Part 2. Сборка

   ![img_2.png](Part_2%2Fimg_2.png)
1. В файле _gitlab-ci.yml_ добавить этап запуска сборки через мейк файл из проекта _C2_

2. ![img_3.png](Part_2%2Fimg_3.png)

# Part 3. Тест кодстайла

   ![img_4.png](Part_3%2Fimg_4.png)
1. Написать этап для **CI**, который запускает скрипт кодстайла (*clang-format*):
   
   ![img_5.png](Part_3%2Fimg_5.png)
2. В пайплайне отобразить вывод утилиты *clang-format*

# Part 4. Интеграционные тесты

   ![img_6.png](Part_4%2Fimg_6.png)
1. Написать этап для **CI**, который запускает ваши интеграционные тесты из того же проекта.

   ![img_7.png](Part_4%2Fimg_7.png)
   ![img_8.png](Part_4%2Fimg_8.png)
1. В пайплайне отобразить вывод, что интеграционные тесты успешно прошли / провалились
   
# Part 5. Этап деплоя

   ![img_9.png](Part_5%2Fimg_9.png)
1. Поднять вторую виртуальную машину *Ubuntu Server 20.04 LTS*

    ![img_10.png](Part_5%2Fimg_10.png)
    ![img_11.png](Part_5%2Fimg_11.png)
2. Написать этап для **CD**, который "разворачивает" проект на другой виртуальной машине:
	- Запускаем машину
	- Включаем службу sshd / Проверяем статус (В обеих машинах)
	> systemctl start sshd / systemctl status sshd
	![img_10.png](Part_1%2Fimg_10.png)
3. Этапы соединения машин:
	3.1 sudo ssh-keygen -t rsa
	3.2 ssh-copy-id -i ./vm.pub user_2@192.168.170.120
	3.3 scp README.md -i ~/.ssh/id_rsa user_2@192.168.170.120:/home/user_2/
	3.4 ssh-copy-id -i /home/flora/.ssh/id_rsa.pub user_2@192.168.170.120
	
	cd /var/lib/gitlab-runner/
	cd .ssh/
	chown gitlab-runner:gitlab-runner id_rsa
	chown gitlab-runner:gitlab-runner id_rsa.pub
    
    
 # Part 6. Дополнительно. Уведомления

    ![img_12.png](Part_6%2Fimg_12.png)
1. Текст уведомления должен содержать информацию об успешности прохождения как этапа **CI**, так и этапа **CD**
