---
layout: post
title: "install multi version JDK on ubuntu"
description: ""
category: 
tags: []
---
{% include JB/setup %}
三条命令搞定：
{% highlight bash %}
    sudo apt-get install oracle-java8-installer
    sudo apt-get install oracle-java7-installer
    sudo update-alternatives --config java
{% endhighlight %}
