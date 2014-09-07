---
layout: post
title: "http reversed on ssh"
description: ""
category: 
tags: []
---
{% include JB/setup %}
##建立一个简单的反向http代理  
nginx 配置情况
{% highlight bash %}
    upstream tunnel{
       server 127.0.0.1:8080;
    }
    server {
       listen 80;
       server_name <url>;
       
       location /{
       proxy_set_header Host $http_host;
       proxy_pass tunnel;
       }
    }
    #ssh reverse 
    ssh -R 8080:localhost:<port> <user_name>@<server>
    #port is your local application used ,and url is the url you will to visit public 
{% endhighlight %}   
[ripples.so](http://ripples.so/) is a localtunnel site that can expose your local website.



