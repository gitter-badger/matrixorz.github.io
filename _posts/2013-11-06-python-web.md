---
layout: post
title: "understand WSGI"
description: ""
category: 
tags: []
draft: true
---
{% include JB/setup %}

[web.py源码解析](http://www.myexception.cn/perl-python/1351788.html)
[WSGI](http://ivory.idyll.org/articles/wsgi-intro/what-is-wsgi.html)

web server side:

服务器必须做两件事情：

一个environ字典和一个start_response函数：

    iterable=app(environ,start_response)
    for data in iterable:
        #send data to client
        
WSGI PEP333   
WSGI中分块传输大文件，使用yield：（rhodesmill.org/brandon/2013/chunked-wsgi）       

后续：

http://benosteen.wordpress.com

My swiss army toolkit for distributed/multiproesssing systems
        
        
       

