# Part 1. Настройка **gitlab-runner**

## Запуск отдельной задачи:
	> gitlab-runner exec shell (name_job)
	
## Непонятные команды: 
	> ssh-keyscan -t rsa gitlab.com >> ~/.ssh/known_hosts

#### 1. Скачать и установить на виртуальную машину **gitlab-runner 
   > sudo apt install gitlab-runner
    
#### 2. Проверить статус 
   > sudo service gitlab-runner status
   ![img.png](Part_1%2Fimg.png)
   
#### 3. Зарегистрировать его для использования в текущем проекте
   > sudo gitlab-runner register
   ![img_1.png](Part_1%2Fimg_1.png)

# Part 2. Сборка

#### 1. В файле _gitlab-ci.yml_ добавить этап запуска сборки через мейк файл из проекта _C2_
   ![img_2.png](Part_2%2Fimg_2.png)

   ![img_3.png](Part_2%2Fimg_3.png)

# Part 3. Тест кодстайла

#### 1. Написать этап для **CI**, который запускает скрипт кодстайла (*clang-format*):
   ![img_4.png](Part_3%2Fimg_4.png)
   
#### 2. В пайплайне отобразить вывод утилиты *clang-format*
   ![img_5.png](Part_3%2Fimg_5.png)

# Part 4. Интеграционные тесты

#### 1. Написать этап для **CI**, который запускает ваши интеграционные тесты из того же проекта.
   ![img_6.png](Part_4%2Fimg_6.png)

#### 2. В пайплайне отобразить вывод, что интеграционные тесты успешно прошли / провалились
   ![img_7.png](Part_4%2Fimg_7.png)
   ![img_8.png](Part_4%2Fimg_8.png)
   
# Part 5. Этап деплоя

#### 1. Поднять вторую виртуальную машину *Ubuntu Server 20.04 LTS*
    ![img_9.png](Part_5%2Fimg_9.png)


#### 2. Написать этап для **CD**, который "разворачивает" проект на другой виртуальной машине:
    ![img_10.png](Part_5%2Fimg_10.png)
	> Запускаем машину
	> Включаем службу sshd / Проверяем статус (В обеих машинах)
	> systemctl start sshd / systemctl status sshd
#### 3. Этапы соединения машин:
##### Генерация ключа
	> 3.1 sudo ssh-keygen -t rsa
##### Копируем и отправляем ключь на вторую машину для соединения 
	> 3.2 ssh-copy-id -i ~/.ssh/id_rsa user_2@192.168.170.120
##### Копирование можно выполнить через команду scp. Здесь пробуем отправить какой-нибудь файл (например README.md)
	> 3.3 scp README.md -i ~/.ssh/id_rsa user_2@192.168.170.120:/home/user_2/
##### Для отправки ключа можно указать полный путь
	> 3.4 ssh-copy-id -i /home/flora/.ssh/id_rsa.pub user_2@192.168.170.120
	
#####   Сгенерированный ключь перемещаем в эту директорию и меняем название и пользователя (потому что гит лаб ищет ключ по этому пути) 	
	> cd /var/lib/gitlab-runner/
	> cd .ssh/
	> chown gitlab-runner:gitlab-runner id_rsa
	> chown gitlab-runner:gitlab-runner id_rsa.pub
	![deploy.png](Part_5%2Fimg_deploy.png)
    
    
 # Part 6. Дополнительно. Уведомления

#### 1. Текст уведомления должен содержать информацию об успешности прохождения как этапа **CI**, так и этапа **CD**
   ![img_11.ipg](Part_6%2Fimg_11.ipg)
