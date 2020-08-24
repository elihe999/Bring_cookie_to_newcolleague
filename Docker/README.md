# Install

```bash
# step 1: 安装必要的一些系统工具
sudo apt-get update
sudo apt-get -y install apt-transport-https ca-certificates curl software-properties-common
# step 2: 安装GPG证书
curl -fsSL http://mirrors.aliyun.com/docker-ce/linux/ubuntu/gpg | sudo apt-key add -
# Step 3: 写入软件源信息
sudo add-apt-repository "deb [arch=amd64] http://mirrors.aliyun.com/docker-ce/linux/ubuntu $(lsb_release -cs) stable"
# Step 4: 更新并安装 Docker-CE
sudo apt-get -y update
sudo apt-get -y install docker-ce
```

## list
> deb [arch=amd64] https://mirrors.aliyun.com/docker-ce/linux/ubuntu bionic stable

sudo apt-get install docker-ce docker-ce-cli containerd.io

### ignore

以下内容根据 官方文档 修改而来。

如果你过去安装过 docker，先删掉:

sudo apt-get remove docker docker-engine docker.io
首先安装依赖:

sudo apt-get install apt-transport-https ca-certificates curl gnupg2 software-properties-common
根据你的发行版，下面的内容有所不同。你使用的发行版： 
Ubuntu
信任 Docker 的 GPG 公钥:

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
对于 amd64 架构的计算机，添加软件仓库:

sudo add-apt-repository \
   "deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu \
   $(lsb_release -cs) \
   stable"
如果你是树莓派或其它ARM架构计算机，请运行:

echo "deb [arch=armhf] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu \
     $(lsb_release -cs) stable" | \
    sudo tee /etc/apt/sources.list.d/docker.list
最后安装

sudo apt-get update
sudo apt-get install docker-ce
Fedora/CentOS/RHEL
以下内容根据 官方文档 修改而来。

如果你之前安装过 docker，请先删掉

sudo yum remove docker docker-common docker-selinux docker-engine
安装一些依赖

sudo yum install -y yum-utils device-mapper-persistent-data lvm2
根据你的发行版下载repo文件: 
CentOS/RHEL
wget -O /etc/yum.repos.d/docker-ce.repo https://download.docker.com/linux/centos/docker-ce.repo
把软件仓库地址替换为 TUNA:

sudo sed -i 's+download.docker.com+mirrors.tuna.tsinghua.edu.cn/docker-ce+' /etc/yum.repos.d/docker-ce.repo
最后安装:

sudo yum makecache fast
sudo yum install docker-ce



 /etc/docker/daemon.json

```bash
sudo systemctl daemon-reload
sudo systemctl restart docker

```

<https://hub-mirror.c.163.com/>