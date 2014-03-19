---
layout: post
title: "install project on preferati"
description: ""
category: 
tags: []
draft: true
---
{% include JB/setup %}
Install OpenQuant Project

    sudo apt-get install nginx
    sudo apt-get install git
    sudo apt-get install mysql-server
    sudo apt-get install python-dev

    install easy_install on ubuntu:
    sudo apt-get install python-setuptools
    sudo easy_install virtualenv
    sudo easy_install pip
    virtualenv ~/trade
    source ~/trade/bin/activate
    install numpy scipy pandas and ta-lib
    sudo pip install Cython

**due to blas libs**

    sudo apt-get install gfortran libopenblas-dev liblapack-dev g++
    pip install numpy
    pip install scipy
**install ta-lib**

    cd ~
    wget http://prdownloads.sourceforge.net/ta-lib/ta-lib-0.4.0-src.tar.gz
    sudo apt-get  install  build-essential
    tar -zxvf ta-lib-0.4.0-src.tar.gz
    cd ta-lib-0.4.0
    ./configure --prefix=/usr
    make
    sudo make install
**install gevent**
    wget https://github.com/downloads/libevent/libevent/libevent-2.0.21-stable.tar.gz
    tar -zxvf 
    ./configure
    make 
    sudo make install



    cd ~/www
    git clone https://github.com/pydata/pandas.git
    git clone https://github.com/mrjbq7/ta-lib.git

**update the nginx**

    sudo apt-get install python-software-properties
    sudo apt-get install sotware-properties-common
    sudo add-apt-repository ppa:nginx/stable
    sudo apt-get update
    sudo apt-get install nginx

**mysql init**

    sudo apt-get install mysql-server libmysqld-dev
    pip install MySQL-python
    insert into mysql.user(Host,User,Password) values("localhost","david",password("david"));
**用户授权**

给本地用户mql分配可对所有数据库的所有表进行所有操作的权限，并设定口令为123456。

    mysql>grant all privileges on *.* to david@localhost identified by 'david';
**install redis**

    http://rubyer.me/blog/638/ redis.io

**uwsgi or gunicorn(optional)**





