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
{% highlight bash %}
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
{% endhighlight %}
**due to blas libs**
{% highlight bash %}
    sudo apt-get install gfortran libopenblas-dev liblapack-dev g++
    pip install numpy
    pip install scipy
{% endhighlight %}
**install ta-lib**
{% highlight bash %}
    cd ~
    wget http://prdownloads.sourceforge.net/ta-lib/ta-lib-0.4.0-src.tar.gz
    sudo apt-get  install  build-essential
    tar -zxvf ta-lib-0.4.0-src.tar.gz
    cd ta-lib-0.4.0
    ./configure --prefix=/usr
    make
    sudo make install
{% endhighlight %}
**install gevent**
{% highlight bash %}
    wget https://github.com/downloads/libevent/libevent/libevent-2.0.21-stable.tar.gz
    tar -zxvf 
    ./configure
    make 
    sudo make install
    cd ~/www
    git clone https://github.com/pydata/pandas.git
    git clone https://github.com/mrjbq7/ta-lib.git
{% endhighlight %}
**update the nginx**
{% highlight bash %}
    sudo apt-get install python-software-properties
    sudo apt-get install sotware-properties-common
    sudo add-apt-repository ppa:nginx/stable
    sudo apt-get update
    sudo apt-get install nginx
{% endhighlight %}
**mysql init**
{% highlight bash %}
    sudo apt-get install mysql-server libmysqld-dev
    pip install MySQL-python
    insert into mysql.user(Host,User,Password) values("localhost","username",password("password"));
{% endhighlight %}
**用户授权**  
给本地用户mql分配可对所有数据库的所有表进行所有操作的权限，并设定口令为123456。  
{% highlight bash %}
    mysql>grant all privileges on *.* to username@localhost identified by 'password';
{% endhighlight %}
**install redis**
具体参考[install redis](http://rubyer.me/blog/638/ redis.io)  

**uwsgi or gunicorn(optional)**





