---
layout: post
title: "python web development"
description: ""
category: 
tags: []
---
{% include JB/setup %}

两篇很好的文章：

[深入浅出网络模型](http://siddontang.github.io/high-performance-server/2012/09/02/step-by-step-network/)  
[Concurrent Programming for Scalable Web Architectures](http://berb.github.io/diploma-thesis/original/index.html)

###使用python web框架开发项目
####技术选型
tornado  --epool，pre_fork,异步io的集合体  
mongodb  --nosql技术，读快写慢  
rq/mrq   --redis队列，传递消息，方便快捷  
pandas   --处理数据的好帮手，方便操作数据，模型优化可借用scikit-learn  
####参考项目
nbviewer --tornado中如何做并行化 futures    
pyspider --flask 后台队列的实现和控制，架构方面  
####云存储
baidupcs-sdk --免费，但有token限制，可以使用refresh token使其永久有效  
pandas io方面一直没有什么好的工具，hdf5，mongodb都是相对较好的选择  
hdf5的使用可参考  
[datafeed](https://github.com/yinhm/datafeed)  
[large data flow in pandas](http://stackoverflow.com/questions/14262433/large-data-work-flows-using-pandas)  
mongodb的使用可参考[openquant]()  