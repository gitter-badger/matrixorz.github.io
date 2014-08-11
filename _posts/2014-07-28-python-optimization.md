---
layout: post
title: "python optimization"
description: ""
category: python development
tags: []
---
{% include JB/setup %}

 首先使用cprofile分析单进程，单线程环境中的性能差的部分，进行算法改写和优化，必要情况下可以通过cpython嵌入c/c++代码。

 判断程序为io-bound任务还是cpu-bound任务。

 io-bound任务程序使用gevent来优化

 cpu-bound任务程序使用multiprocess来优化

 使用队列服务进行任务分发，将大任务分成多个子任务部署于多机环境（集群）。注意：调度和单点故障。
