---
layout: default
title: resolution to scipy installation error
categories: python
---
#ubuntu上安装scipy出错解决方法

安装scipy时出现Blas错误时，需安装以下几个包：

    apt-get libblas3gf libblas-doc libblas-dev liblapack3gf liblapack-doc liblapack-dev

安装matplib出现ft2build.h等头文件无法找出时，解决方法：
具体解决方案如下：
（1）安装freetype2开发包：

    sudo apt-get install libfreetype6-dev
    
（2）安装png开发包：

    sudo apt-get install libpng-dev
    
（3）安装matplotlib:

    sudo python setup.py install
