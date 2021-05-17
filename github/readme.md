# github

## dns
解决GitHub的raw.githubusercontent.com无法连接问题

加大码先生 2020-05-17 17:08:15  23893  收藏 36
分类专栏： 工欲善其事必先利其器 文章标签： github
版权
问题描述：
Ubuntu下连接raw.githubusercontent.com失败

wget https://raw.githubusercontent.com/madmashup/targeted-marketing-predictive-engine/master/banking.csv
 
--2020-05-17 17:00:19--  https://raw.githubusercontent.com/madmashup/targeted-marketing-predictive-engine/master/banking.csv
Resolving raw.githubusercontent.com (raw.githubusercontent.com)... 0.0.0.0, ::
Connecting to raw.githubusercontent.com (raw.githubusercontent.com)|0.0.0.0|:443... failed: Connection refused.
Connecting to raw.githubusercontent.com (raw.githubusercontent.com)|::|:443... failed: Network is unreachable.
解决方法：
step-1
在 https://site.ip138.com/raw.Githubusercontent.com/

输入raw.githubusercontent.com查询IP地址

step-2
修改hosts Ubuntu，CentOS及macOS直接在终端输入

sudo vi /etc/hosts
添加以下内容保存即可 （IP地址查询后相应修改，可以ping不同IP的延时 选择最佳IP地址）

# GitHub Start
52.74.223.119 github.com
192.30.253.119 gist.github.com
54.169.195.247 api.github.com
185.199.111.153 assets-cdn.github.com
151.101.76.133 raw.githubusercontent.com
151.101.108.133 user-images.githubusercontent.com
151.101.76.133 gist.githubusercontent.com
151.101.76.133 cloud.githubusercontent.com
151.101.76.133 camo.githubusercontent.com
151.101.76.133 avatars0.githubusercontent.com
151.101.76.133 avatars1.githubusercontent.com
151.101.76.133 avatars2.githubusercontent.com
151.101.76.133 avatars3.githubusercontent.com
151.101.76.133 avatars4.githubusercontent.com
151.101.76.133 avatars5.githubusercontent.com
151.101.76.133 avatars6.githubusercontent.com
151.101.76.133 avatars7.githubusercontent.com
151.101.76.133 avatars8.githubusercontent.com
# GitHub End
 

参考：https://www.cnblogs.com/sinferwu/p/12726833.html

## 加速

<http://github.global.ssl.fastly.net.ipaddress.com>