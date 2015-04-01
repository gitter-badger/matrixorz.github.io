---
layout: post
title: "Java call matlab"
description: ""
category: 
tags: []
---
{% include JB/setup %}

与C++/C调用matlab不同的是，C++是[调用matlab的生成动态库](http://blog.segmentfault.com/simbest/1190000000417000)或者使用matlab引擎，而java是调用matlab代码打包成的jar包。

使用deploytool命令打开matlab打包工具
打包完成后在eclipse除导入该包外，还要导入目录 toolbox/javabuilder/jar/javabuilder.jar包
在相关代码中完成导入语句和定义完成java调用matlab代码的调用。
具体相关代码和事例可见[example](https://github.com/matrixorz/writer_identification/blob/master/Writer/writerui/writer.java)
