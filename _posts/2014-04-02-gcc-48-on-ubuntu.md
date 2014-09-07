---
layout: post
title: "gcc 4.8 on ubuntu"
description: ""
category: 
tags: []
draft: true
---
{% include JB/setup %}
命令行中输入以下命令安装相关包
{% highlight bash %}
     sudo apt-get install python-software-properties
	 sudo add-apt-repository ppa:boost-latest/ppa
	 sudo apt-get update
	 sudo apt-get install libboost1.55-all-dev
     sudo add-apt-repository ppa:ubuntu-toolchain-r/test
     sudo apt-get update
     sudo apt-get install gcc-4.8 g++-4.8
     sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.6 
     sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 40 --slave /usr/bin/g++ g++ /usr/bin/g++-4.8
     sudo update-alternatives --config gcc
{% endhighlight %}
安装完gcc-4.8后即可安装llvm-3.4 参考 [llvm/apt]()  
下载[osxcross]()  
编译若出现错误： fatal error:limits can't find?  
使用以下命令进行修正       
{% highlight bash %}
     $echo '#include <limits.h>' | clang -v -xc -o /dev/null -
{% endhighlight %}
使用上述命令排错，依依对照toolchain查找的include顺序，修改include链接，即可解决问题
其实这是一个llvm的bug  
临时解决方案[参考](https://bugs.launchpad.net/ubuntu/+source/llvm-defaults/+bug/1242300):  
{% highlight bash %}
    $cd /usr/lib/clang/<clang-version/
    $sudo ln -sf ../../llvm-3.4/lib/clang/<clang-version>/include include
{% endhighlight %}
再次编译可以通过。
一个查找文件的有用命令:
{% highlight bash %}
    $grep notification `find ./*`
{% endhighlight %}

