---
layout: post
title: "install multi version JDK on ubuntu"
description: ""
category: 
tags: []
draft: true
---
{% include JB/setup %}
三条命令搞定：

    $sudo apt-get install oracle-java8-installer
    $sudo apt-get install oracle-java7-installer
    $sudo update-alternatives --config java
