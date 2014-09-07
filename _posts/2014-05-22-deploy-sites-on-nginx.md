---
layout: post
title: "deploy sites on nginx"
description: ""
category: 
tags: [web programming]
---
{% include JB/setup %}
使用nginx部署网站发现80端口一直被占用，使用一下方法杀死占用80端口进程
[emerg]: bind() to 0.0.0.0:80 failed (98: Address already in use)

Then it means nginx or some other process is already using port 80.

You can kill it using:
{% highlight bash %}
    sudo fuser -k 80/tcp
{% endhighlight %}

And then try restarting nginx again:
{% highlight bash %}
    service nginx start
{% endhighlight %}