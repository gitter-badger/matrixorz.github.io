---
layout: post
title: "install hdf5 on ubuntu"
date: 2013-06-05 11:11:11
categories: python yt-project
---
#install hdf5 on ubuntu 12.04

you can probably install the debian libraries into quantal with no issues, precise is less likely to work, but it might possibly you will have to build it from source to get everything right.  
Code:
    {% highlight bash %}
    $apt-get install devscripts equivs ubuntu-dev-tools 
    $pull-debian-source hdf5 experimental    
    $cd hdf5-*
    $sudo mk-build-deps -ir
    $debuild -us -uc
    {% endhighlight %}
上述方法现在已经不适用,Google后发现,可以直接使用hdf5二进制包,由于本机为64bit linux,下载64位下的二进制包：
    {% highlight bash %}
    $wget http://www.hdfgroup.org/ftp/HDF5/releases/hdf5-1.8.9/bin/linux-x86_64/hdf5-1.8.9-linux-x86_64-shared.tar.gz
    {% endhighlight %}
解压后，并在.bashrc中设置：
    {% highlight bash %}
    $export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib:$HOME/hdf5-1.8.9-linux-x86_64-shared/lib
    $export HDF5_DIR=$HOME/hdf5-1.8.9-linux-x86_64-shared
    $source .bashrc
    {% endhighlight %}
安装 blosc (可选)
安装 lzo2-2 lzo2-dev
    {% highlight bash %}
    sudo apt-get install lzo2-2 lzo2-dev
    {% endhighlight %}
至此HDF5可用
   
