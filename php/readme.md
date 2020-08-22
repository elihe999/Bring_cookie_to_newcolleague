## Installing PHP 7.2 with Apache #
If you are using Apache as your web server to install PHP and Apache PHP module run the following command:

sudo apt install php libapache2-mod-php

## Installing PHP 7.2 with Nginx
Unlike Apache, Nginx doesn’t have a built in support for processing PHP files so we need to install a separate application such as PHP FPM (“fastCGI process manager”) which will handle PHP files.

To install the PHP and PHP FPM packages run the following command:


sudo apt install php-fpm
Once the packages are installed you can check the status of the PHP FPM service with:

systemctl status php7.2-fpm

