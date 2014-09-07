---
layout: post
title: "ubuntu 14.04 install haskell"
description: "Function Programming"
category: 
tags: [FP]
draft: false
---
haskell是一种函数编程式语言，ghc是Glasgow Haskell Compiler的简称，也是Haskell Platform的基础.   下面是安装ghc的步骤：
    {% highlight bash %}
    
    sudo aptitude build-dep ghc
    sudo aptitude install git autoconf automake libtool make ncurses-dev g++ llvm gpaco
    wget https://www.haskell.org/ghc/dist/7.8.3/ghc-7.8.3-src.tar.bz2
    tar jxvf ghc-7.8.3-src.tar.bz2
    cd ghc-7.8.3-src
    ./configure --prefix=/usr/local/ghc
    make -j8
    sudo paco -D make install
    sudo aptitude purge ghc
    {% endhighlight %}

编辑.bashrc文件
    {% highlight bash %}

    PATH="/usr/local/ghc/bin:$PATH"
    source ~/.bashrc

    ghci   #验证是否安装成功

    sudo aptitude purge ghc 
    {% endhighlight %}

Cabal是Haskell的一个package，提供Haskell包安装框架，类似python的easy_install、debian的apt-get等。
cabal-install是另一个Haskell包安装库，提供了cabal命令行程序，该程序在安装新包时会自动解决包依赖关系。
安装了cabal-install就可以了，因为cabal-install依赖与cabal，安装程序会自动下载cabal并安装。
下面是安装cabal的步骤
    {% highlight bash %}
   
    wget http://www.haskell.org/cabal/release/cabal-install-1.20.0.3/cabal-install-1.20.0.3.tar.gz
    tar zxvf cabal-install-1.20.0.3.tar.gz
    cd cabal-install-2.10.0.3
    ./bootstrap.sh

    vim ~/.bahsrc
    PATH=$HOME/.cabal/bin:$PATH
    source ~/.bashrc
    cabal update
    {% endhighlight %}

安装包haskell-platform中包含这些包，但是由于使用apt-get安装时不能获得最新的版本或者会出现一些问题，比如network-2.6.0.2通过cabal总是安装不上，报编译错误
这种使用源码安装的方式很好的解决了这些问题。非常高效！

在安装相关haskell包的时候可能会出现broken package错误，可以通过以下命令在haskell中移除broken package
    {% highlight bash %}

    ghc-pkg check --simple-output | xargs -n 1 ghc-pkg unregister --force
    {% endhighlight %}

