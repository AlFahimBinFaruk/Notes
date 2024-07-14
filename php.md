1. install php
```
sudo apt install php php-cli php-mbstring php-xml php-zip php-mysql php-json
```
2. install composer
```
curl -sS https://getcomposer.org/installer | php
sudo mv composer.phar /usr/local/bin/composer
```
3. create laravel project
```
composer create-project --prefer-dist laravel/laravel my-laravel-app
cd my-laravel-app
php artisan migrate
php artisan serve

```
4. xampp
```
-download xampp
- make it executable
chmod +x xampp-linux-x64-8.2.12-0-installer.run
- run installer
sudo ./xampp-linux-x64-8.2.12-0-installer.run
- start
sudo /opt/lampp/lampp start

```
5. move laravel app to /opt/lampp/htdocs/
6. set correct permission
```
sudo chown -R www-data:www-data /opt/lampp/htdocs/my-laravel-app/storage
sudo chown -R www-data:www-data /opt/lampp/htdocs/my-laravel-app/bootstrap/cache
sudo chmod -R 775 /opt/lampp/htdocs/my-laravel-app/storage
sudo chmod -R 775 /opt/lampp/htdocs/my-laravel-app/bootstrap/cache
```

7. configure virtual host
```
sudo nano /opt/lampp/etc/httpd.conf
- at the end of this file add
<VirtualHost *:80>
    DocumentRoot "/opt/lampp/htdocs/my-laravel-app/public"
    ServerName laravel-app.local

    <Directory "/opt/lampp/htdocs/my-laravel-app/public">
        Options Indexes FollowSymLinks
        AllowOverride All
        Require all granted
    </Directory>
</VirtualHost>
```
8. add virtual host to host file
```
sudo nano /etc/hosts
127.0.0.1 laravel-app.local

```
9. copy .env.example to .evn file
10. generate application key
```
sudo /opt/lampp/bin/php artisan key:generate
```
11. set correct ownership
```
sudo chown -R daemon:daemon /opt/lampp/htdocs/my-laravel-app/storage /opt/lampp/htdocs/my-laravel-app/bootstrap/cache
```
12. set correct permission
```
sudo chmod -R 775 /opt/lampp/htdocs/my-laravel-app/storage /opt/lampp/htdocs/my-laravel-app/bootstrap/cache
```
13. test application
```
http://laravel-app.local
```


