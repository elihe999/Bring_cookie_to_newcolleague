# readme

nvm是一个非常不错的node版本管理器，类似于ruby的rvm

github地址为<https://github.com/creationix/nvm>

首先下载nvm，这里我们需要使用Git，确保提前安装好了git
然后执行以下命令从git载入nvm：

```bash
 git clone https://github.com/creationix/nvm.git ~/.nvm && cd ~/.nvm && git checkout \`git describe --abbrev=0 --tags\`  
```

下载之后，进入目录执行nvm安装命令

./install.sh
source ./nvm.sh

### 查看已安装 node.js 版本

nvm ls

### 查看可安装的 node.js 版本

nvm ls-remote

### 安装长期支持版 v8.10.0   (Latest LTS: Carbon)

nvm install v8.10.0

### 切换已安装的node.js版本

nvm use 版本号

## 镜像

```bash
npm install -g cnpm --registry=https://registry.npm.taobao.org
```

yarn config set registry https://registry.npm.taobao.org



npm install -g yrm

yrm ls

**安装 yrm：**

```java
npm install -g yrm
1
```

**列出所有镜像源：**

```java
yrm ls
1
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20191101002732802.png)
**切换镜像：**

```java
yrm use taobao
1
```

**新增镜像：**

```java
yrm add aliyun http://maven.aliyun.com/nexus/content/groups/public
1
```

**删除镜像：**

```java
yrm del taobao
1
```

**测试延迟（访问速度）：**

```java
yrm test aliyun
1
```

**查看帮助：**

```java
yrm -h
```
## issue

nvm
windows
move to path there without whitespace

or

running cmd as administrator
and then mklink it to the new path there without whitespace.