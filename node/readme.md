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

