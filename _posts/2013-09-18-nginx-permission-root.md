---
layout: post
title: "nginx permission root"
description: ""
category: 
tags: []
draft: true
---
{% include JB/setup %}
####nginx 权限问题的解决方法  
按照下面方法配置nginx时出现用户权限问题  
{% highlight bash %}
	server{
	listen 4002;
	server_name localhost;
	access_log logs/access.log;
	location / {
	   proxy_set_header X-Real-IP $remote_addr;
	   proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
	   proxy_set_header Host $http_host;
	   proxy_set_header X-NginxX-Proxy true;
	   proxy_pass http://backend;
	   proxy_redirect off;	   
	   proxy_http_version 1.1;
	   proxy_set_header Upgrade $http_upgrade;
	   proxy_set_header Connection "upgrade";
	   }
	   }
	 upstream backend {
	 server 127.0.0.1:3201;
	 }
{% endhighlight %}

参照[nginx 13:permission denied solved](http://serverfault.com/questions/246609/trouble-with-nginx-and-serving-from-multiple-directories-under-the-same-domain)  
The root directive is the problem here. Quote from the doc:  
note: Keep in mind that the root will still append the directory to the request so that a request for "/i/top.gif" will not look in "/spool/w3/top.gif" like might happen in an Apache-like alias configuration where the location match itself is dropped. Use the alias directive to achieve the Apache-like functionality.  
Basically, only use root for real roots: if the content is to be at / use root. If it's going to end on a subfolder, use alias:  
 
    location  /map/ {
      alias  /home/user/public_html/map/;
    }  
Also check what user nginx is running as and make sure that this user can access /home/user/public_html/map
