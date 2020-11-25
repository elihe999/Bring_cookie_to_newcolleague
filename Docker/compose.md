# Compose

# Install

```
sudo curl -L "https://github.com/docker/compose/releases/download/1.24.1/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
```
```
$ sudo chmod +x /usr/local/bin/docker-compose
```
创建软链：
```
$ sudo ln -s /usr/local/bin/docker-compose /usr/bin/docker-compose
```
测试是否安装成功：
```
$ docker-compose --version
docker-compose version 1.24.1, build 4667896b
```