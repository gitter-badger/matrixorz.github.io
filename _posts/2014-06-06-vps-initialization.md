---
layout: post
title: "vps initialization"
description: ""
category: 
tags: []
---
{% include JB/setup %}

添加用户：

    useradd options <username>
添加用户组：
    
    groupadd options <groupname>
配置权限：

    echo '<username> all=(all:all) all' /etc/sudoers
ssh登陆禁用密码：

本机：

    ssh-keygen  #生成公钥、密钥对

    ssh-copy-id -i ~/.ssh/id_rsa.pub username@remote-host    #将公钥复制到远程服务器的authorized_keys中（server端authorized_keys指定公钥，客户端 -i参数指定私钥）
服务器：

登陆服务器后，修改/etc/ssh/sshd_config保存

    PasswordAuthentication no    （经用密码登陆）
重启ssh 

    sudo service ssh restart




   
   
    
     
    

    
    
   
