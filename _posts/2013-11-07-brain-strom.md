---
layout: post
title: "brain strom"
description: ""
category: 
tags: []
---
{% include JB/setup %}


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