# manjaro

- yay

升级完后，安装Apache

Copy
pacman -S apache
编辑 /etc/httpd/conf/httpd.conf file

Copy
nano /etc/httpd/conf/httpd.conf
# 我这里用的nano，你可用其它的编辑器只要能编辑文本就行
找到LoadModule unique_id_module modules/mod_unique_id.so 注释了

#LoadModule unique_id_module modules/mod_unique_id.so

保存退出

让Apache 开机启动 然后重启 Apache 服务

systemctl enable httpd
systemctl restart httpd	
然后看看 Apache 服务是否启动成功

systemctl status httpd
Active: active (running) 有这个就意思成功运行

测试一下Apache#
创建一个简单的页面

nano /srv/http/index.html