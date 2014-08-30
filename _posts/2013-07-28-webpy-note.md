---
layout: post
title: "web.py note"
description: ""
category: 
tags: []
---
{% include JB/setup %}
#webpy学习笔记

web.ctx
web.loadhook(handler)函数在web请求前执行handler函数
web.unloadhook(handler)函数在web请求后执行的handler函数

seeother:303临时重定向
redirect：301永久重定向

seeother(../)seeother（/）前者返回到上层目录，后者重定向到当强目录，造成 无限次的重定向，是一种错误的用法。
