---
layout: post
title: install wine on ubuntu 12.04
categories: linux
---
# Wine error

Code for install wine:
{% highlight bash %}
    sudo setcap CAP_NET_RAW=ep /usr/bin/wine
    sudo setcap CAP_NET_RAW=ep /usr/bin/wineserver
    sudo setcap CAP_NET_RAW=ep /путь_до_л2/l2.exe
{% endhighlight %}
