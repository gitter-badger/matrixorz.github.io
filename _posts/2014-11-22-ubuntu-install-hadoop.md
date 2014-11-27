---
layout: post
title: "Ubuntu 14.04 install hadoop 2.4.1 记录"
description: ""
category: 
tags: [大数据,bigdata]
draft: false
published: true
---
{% include JB/setup %}
###Ubuntu 14.04 install Hadoop 2.4.1笔记
说明:
集群机器:
Master: 10.211.55.1
Slave1: 10.211.55.10
Slave2...
这里还是以两台机器为例:Master和Slave1.

下载好hadoop-2.4.1的执行文件包和安装好java执行环境(这里选择的是oracle-java7-installer).  
为了创建一个相对独立的用户环境,在机器Master和Slave1上分别使用以下命令新建用户hadoop  

    sudo adduser hadoop #该命令会自动创建用户hadoop,用户组hadoop,以及用户目录/home/hadoop  
在Master和Slave1上分别编辑文件/etc/hosts:(添加以下两行)

    10.211.55.1  Master  
    10.211.55.10 Slave1   
完成hosts修改后,保证Master和Slave1之间能够ping通.  
ssh无密码登录配置  
Master节点终端上操作: 
 
    cd ~/.ssh
    ssh-keygen -t rsa  
Master节点需要无密码登录ssh本机,Master节点上操作:

    cat ~/.ssh/id_rsa.pub>>~/.ssh/authorized_keys  
    ssh Master #测试  
将Master的公钥传输到Slave1节点  
    
    ssh-copy-id -i ~/.ssh/id_rsa.pub hadoop@Slave1  #ssh-copy-id 把Master的公钥追加到Slave1的.ssh/authorized_keys上
    ssh hadoop@Slave1  #or ssh Slave1
配置完网络交互环境后,下面进行hadoop配置文件的设置:  
Master节点上操作  
1.将hadoop-2.4.1的安装目录设置到环境变量HADOOP_HOME,并将$HADOOP_HOME/sbin添加到环境变量PATH,在/etc/profile(全局用户)或者~/.bashrc(当前用户)中进行相应的相关修改.  
2.进入到$HADOOP_HOME/etc/hadoop目录下,对slave,core-site.xml,hdfs-site.xml,mapred-site.xml(该文件若不存在,需要从模板中复制一份)  
slave文件中记录Slave的名字Slave1(如果有多个Slave记录多个对应的名字).  
core-site.xml:  

    <property>
        <name>fs.defaultFS</name>
        <value>hdfs://Master:9000</value>
    </property>
    <property>
        <name>hadoop.tmp.dir</name>
        <value>file:/usr/local/hadoop/tmp</value>
        <description>Abase for other temporary directories.</description>
    </property>
hdfs-site.xml:

    <property>
        <name>dfs.namenode.secondary.http-address</name>
        <value>Master:50090</value>
    </property>
    <property>
        <name>dfs.namenode.name.dir</name>
        <value>file:/usr/local/hadoop/tmp/dfs/name</value>
    </property>
    <property>
        <name>dfs.datanode.data.dir</name>
        <value>file:/usr/local/hadoop/tmp/dfs/data</value>
    </property>
    <property>
        <name>dfs.replication</name>
        <value>1</value>
    </property>
mapred-site.xml:

    <property>
    <name>mapreduce.framework.name</name>
    <value>yarn</value>
    </property>
yarn-site.xml:

    <property>
        <name>yarn.resourcemanager.hostname</name>
        <value>Master</value>
    </property>
    <property>
        <name>yarn.nodemanager.aux-services</name>
        <value>mapreduce_shuffle</value>
    </property>
3.配置好hadoop相关配置文件后,将Master上的整个Hadoop安装目录复制到各个Slave节点上  
    
    scp -r $HADOOP_HOME Slave1:~/ 
    ssh Slave
    sudo chown -R hadoop.hadoop $HADOOP_HOME #$HADOOP_HOME为Slave节点上的Hadoop安装目录  
4.初始化namenode和启动hadoop集群  
Master上操作:  

    hdfs namenode -format
    start-dfs.sh
    start-yarn.sh
    
    jps  #检查是否启动了Nameode,SecondaryNameNode,ResourceManager,(Jps)进程
    ssh Slave1 #登录到Slave1 
    jps #检查是否启动了DataNode,NodeManager,(Jps)进程.
5.检查DataNode运行情况:

    hdfs dfsadmin -report #Master节点上操作

Hadoop安装完毕!
参考资料:  
[Hadoop2.0详细配置教程](http://www.cnblogs.com/scotoma/archive/2012/09/18/2689902.html)  
[hadoop全分布式集群模式的搭建实验](https://www.evernote.com/shard/s185/sh/fd5ec181-a6b6-4a74-9261-38e0754b65da/f62975e507065959e1259690c5ab1c5a)  
[使用Ambari快速部署Hadoop大数据环境](http://www.cnblogs.com/scotoma/archive/2013/05/18/3085248.html)  
[Writing an hadoop mapreduce program in python](http://www.michael-noll.com/tutorials/writing-an-hadoop-mapreduce-program-in-python/)  
[如何使用python为Hadoop编写一个简单的MapReduce](http://www.cnblogs.com/end/archive/2012/08/13/2636175.html)
[writing an hadoop mapreduce program in python](http://www.michael-noll.com/tutorials/writing-an-hadoop-mapreduce-program-in-python/)
[使用Vagrant在虚拟机安装hadoop集群](http://blog.csdn.net/wf1982/article/details/8798870) 
[hadoop
2.4.1单机伪分布式安装和配置](http://www.letiantian.me/2014-10-16-hadoop-2-4-1-stand-alone-install-and-config/)  
[Hadoop 集群安装配置教程Hadoop 2.4.1/Ubuntu
14.04](http://www.powerxing.com/install-hadoop-cluster-2-4-1/)  
[Yarn
introduction](http://www.ibm.com/developerworks/cn/opensource/os-cn-hadoop-yarn/)


