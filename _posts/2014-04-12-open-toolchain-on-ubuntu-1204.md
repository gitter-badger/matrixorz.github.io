---
layout: post
title: "open toolchain on ubuntu 12.04"
description: ""
category: 
tags: []
---
{% include JB/setup %}
###ubuntu 12.04 安装llvm3.4、ios-lang交叉编译环境小记  
在ubuntu 12.04上先安装gcc-4.8，然后安装llvm,clang,libcxx,libcxxabi.由于libcxx和libcxxabi相互依赖，需要两次安装libcxx。最后安装theos等开放的ios开发工具链   
安装gcc-4.8如前文所述[install gcc4.8 on ubuntu 12.04](/2014/04/02/gcc-48-on-ubuntu/)  
#####安装llvm,clang
/etc/apt/sources.list中添加如下两行：
{% highlight bash %}
    deb http://llvm.org/apt/precise/ llvm-toolchain-precise-3.4 main
    deb-src http://llvm.org/apt/precise/ llvm-toolchain-precise-3.4 main
{% endhighlight %}
#####检索签名：  
{% highlight bash %}
    wget -O - http://llvm.org/apt/llvm-snapshot.gpg.key|sudo apt-key add -
{% endhighlight %}
#####安装与llvm-3.4,clang-3.4相关的所有包：  
{% highlight bash %}
    apt-get install clang-3.4 clang-3.4-doc libclang-common-3.4-dev libclang-3.4-dev libclang1-3.4 libclang1-3.4-dbg libllvm-3.4-ocaml-dev libllvm3.4 libllvm3.4-dbg lldb-3.4 llvm-3.4 llvm-3.4-dev llvm-3.4-doc llvm-3.4-examples llvm-3.4-runtime clang-modernize-3.4 clang-format-3.4 python-clang-3.4 lldb-3.4-dev
{% endhighlight %}
#####安装libcxx：  
{% highlight bash %}
    svn co http://llvm.org/svn/llvm-project/libcxx/trunk libcxx
{% endhighlight %} 
#####查看g++使用的头文件:
{% highlight bash %}  
    echo | g++ -Wp,-v -x c++ - -fsyntax-only
{% endhighlight %}
#####将会输出类似如下结果：  
{% highlight bash %} 
    ignoring nonexistent directory "/usr/local/include/x86_64-linux-gnu"
    ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux- gnu/4.8/../../../../x86_64-linux-gnu/include"
    ### #include "..." search starts here:
    ### include <...> search starts here:
    /usr/include/c++/4.8
    /usr/include/c++/4.8/x86_64-linux-gnu
    /usr/include/c++/4.8/backward
    /usr/lib/gcc/x86_64-linux-gnu/4.8/include
    /usr/local/include
    /usr/lib/gcc/x86_64-linux-gnu/4.8/include-fixed
    /usr/include/x86_64-linux-gnu
    /usr/include
    End of search list.
{% endhighlight %}
#####编译安装libcxx：
{% highlight bash %}
    CC=clang CXX=clang++ cmake -G "Unix Makefiles" -DLIBCXX_CXX_ABI=libsupc++ - DLIBCXX_LIBSUPCXX_INCLUDE_PATHS="/usr/include/c++/4.7/;/usr/include/x86_64-linux- gnu/c++/4.7/" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr <libc++-source-dir>
    make
    sudo make install
{% endhighlight %}
#####安装libcxxabi  
首先安装相关依赖：  
{% highlight bash %}
    sudo apt-get install g++ subversion cmake swig python-dev libedit-dev libunwind8 libunwind8-dev
{% endhighlight %}
下载源码并编译：  
{% highlight bash %}
    svn co http://llvm.org/svn/llvm-project/libcxxabi/trunk libcxxabi
    cd libcxxabi/lib
    ./buildit
    sudo cp libc++abi.so.1.0 /usr/lib
    sudo ln -s /usr/lib/libc++abi.so.1.0 /usr/lib/libc++abi.so.1
    sudo ln -s /usr/lib/libc++abi.so.1 /usr/lib/libc++abi.so
{% endhighlight %}
使用libc++abi来安装libc++  
{% highlight bash %}
    svn co http://llvm.org/svn/llvm-project/libcxx/trunk libcxx
    cd libcxx
    mkdir build
    cd build
    CC=clang CXX=clang++ cmake -G "Unix Makefiles" -DLIBCXX_CXX_ABI=libcxxabi -  DLIBCXX_LIBCXXABI_INCLUDE_PATHS="<libc++abi-source-dir>/include" -  DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ../
    make
    sudo make install
{% endhighlight %}
至此ubuntu 12.04上的LLVM环境就算搭建好了。


