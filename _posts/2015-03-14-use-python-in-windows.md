---
layout: post
title: "use python in windows"
description: "no module named libxmlmods"
category: 
tags: []
draft: false
published: true
---
{% include JB/setup %}

### windows 64安装libxml2dom小记

##### 用于解决no module named libxmlmods等错误
  
此[网站](http://www.lfd.uci.edu/~gohlke/pythonlibs/)上面有编译好了的各种python windows包.  
我们首先下载[libxml2-python](http://www.lfd.uci.edu/~gohlke/pythonlibs/z94jfosk/libxml2_python-2.9.2-cp27-none-win_amd64.whl)  
然后使用pip wheel安装：  

    pip wheeel libxml2_python-2.9.2-cp27-none-win_amd64.whl  
    pip install --use-wheel --no-index --find-links=wheelhouse libxml2-python
    easy_install libxml2dom

至此安装libxml2dom完毕

### windows 64安装pycurl小记
首先下载[curl 64bit mingw](http://curl.haxx.se/gknw.net/7.40.0/dist-w64/curl-7.40.0-devel-mingw64.7z)  
然后git clone https://github.com/pycurl/pycurl.git，进入到pycurl目录，修改setup.py  
    CURL_DIR=$CURL_PATH
 编译，安装，完毕。
 以上方法还是没有安装成功，还是使用上面网站里的编译好的安装包进行安装，下载[pycurl-7.19.5.1-cp27-none-win_amd64.whl](http://www.lfd.uci.edu/~gohlke/pythonlibs/z94jfosk/pycurl-7.19.5.1-cp27-none-win_amd64.whl)    
 使用以下命令进行安装：
 
     pip wheel pycurl-7.19.5.1-cp27-none-win_amd64.whl
     pip install --



### windows上的python环境搭建：
安装Anaconda。

