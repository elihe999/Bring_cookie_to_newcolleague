# python

## mirrors

* [清华](https://pypi.tuna.tsinghua.edu.cn/simple)
* [阿里云](http://mirrors.aliyun.com/pypi/simple/)
* [中国科技大学](https://pypi.mirrors.ustc.edu.cn/simple/)
* [华中理工大学](http://pypi.hustunique.com/)
* [山东理工大学](http://pypi.sdutlinux.org/)
* [豆瓣](https://pypi.douban.com/simple/)


## pip

sudo apt install python3-pip
<https://www.anaconda.com/products/individual>


## conda

conda config --show
```bash
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/bioconda/
```

echo ". /home/eli/anaconda3/etc/profile.d/conda.sh" >> ~/.bashrc
sudo ln -s /home/eli/anaconda3/etc/profile.d/conda.sh /etc/profile.d/conda.sh
echo "conda activate" >> ~/.bashrc


### cmd

conda env list
conda create -n <name> python=
conda activate <model_name>
conda deactivate 
conda remove -n <env_name> --all
