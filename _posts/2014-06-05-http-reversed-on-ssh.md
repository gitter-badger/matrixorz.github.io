---
layout: post
title: "http reversed on ssh"
description: ""
category: 
tags: []
---
{% include JB/setup %}

nginx config details

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

ssh reverse 

    ssh -R 8080:localhost:<port> <user_name>@<server>


<port> your local application used

go to <url> to see 

enjoy!



