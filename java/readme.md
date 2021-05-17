sudo apt-get install openjdk-8-jdk



https://adoptopenjdk.net/



java -version



```bash
vim /etc/profile

export JAVA_HOME=/usr/lib/jvm/java-1.7.0-openjdk-1.7.0.95.x86_64
export CLASSPATH=.:$JAVA_HOME/jre/lib/rt.jar:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar 
export PATH=$JAVA_HOME/bin:${PATH}

source /etc/profile
```

```bash
wget http://apache.fayea.com/maven/maven-3/3.3.9/binaries/apache-maven-3.3.9-bin.tar.gz
tar xzvf apache-maven-3.3.9-bin.tar.gz
```

```bash
export MAVEN_HOME=/data/apache-maven-3.3.9
export PATH=${MAVEN_HOME}/bin:${PATH}
```

https://mirrors.bfsu.edu.cn/apache/maven/maven-3/3.8.1/binaries/apache-maven-3.8.1-bin.tar.gz





