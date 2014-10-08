---
layout: post
title: "develop tools about python"
description: ""
category: 
tags: []
---
{% include JB/setup %}

工欲善其事，必先利其器。


vagrant介绍
vagrant是一款用来构建虚拟开发环境的工具，非常适合php/python/ruby/java这类语言开发Web语言，如果说virtualenv是一个python包环境的封装，那么可以说vagrant是在一个操作系统层面上的封装，而且是跨平台的，当然也有docker，关于docker与vagrant的区别可见[这篇文章](https://www.dockboard.org/docker-vs-vagrant-why-this-two-technologies-aren't-competing/).

安装virtualbox
vagrant依赖虚拟机，可以使用virtualbox和VMware.[下载地址](https://www.virtualbox.org/wiki/Downloads)

安装vagrant
[下载地址](http://downloads.vagrantup.com)
下载基础镜像：
[ubuntu precise 32](http://files.vagrantup.com/precise32.box)
[ubuntu precise 64](http://files.vagrantup.com/precise64.box)

添加镜像到vagrant

    $vagrant box add boxname pathtobox/precise64.box

初始化开发环境
    
    $cd  devpath
    $vagrant init boxname
    $vagrant up

登陆虚拟机
    
    $vagrant ssh
    $cd /vagrant  #虚拟机下的/vagrant是宿主机上的 devpath

其他设置
    vagrant出事化后，会在初始化目录里生成一个Vagrantfile的配置文件。
    Vagrant默认是使用端口映射方式将虚拟机的端口映射本机从而实现类似http://localhost:80这种访问方式，host-only模式显得更方便，打开Vagrantfile，将下面这行的注释去掉
config.vm.network :private_network,ip:"192.168.33.10"
重启虚拟机，这样就能用192.168.33.10访问这台机器。

打包分发
  $vagrant package
  会生成一个package.box文件，可共分发。

常用命令

   $vagrant init
   $vagrant up
   $vagrant halt
   $vagrant reload
   $vagrant ssh
   $vagrant status
   $vagrant destroy
   
开发环境中Apache/nginx取消静态文件缓存

Apache
EnableSendfile off

Nginx
sendfile off


