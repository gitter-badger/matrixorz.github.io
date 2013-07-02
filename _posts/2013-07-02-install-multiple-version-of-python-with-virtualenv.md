---
layout: post
title: "Run Multiple-python on your ubuntu"
description: ""
category: 
tags: []
---
{% include JB/setup %}
安装python3.3在ubuntu上

    sudo apt-get install python-software-properties
    sudo add-apt-repository ppa:fkrull/deadsnakes
    sudo apt-get update
    sudo apt-get install python3.3
建立软链接：

    ln -s /usr/bin/python3.3 /usr/bin/python3.3m

安转python2.7.5再ubuntu上:    

    sudo add-apt-repository ppa:fkrull/deadsnakes
    sudo apt-get update
    sudo apt-get install python2.4 python2.5 python2.6
    
使用virtualenv来定制自己的环境

    virtualenv -p /usr/bin/python3.3 python3.3env
    virtualenv -p /usr/bin/python2.7.5 python2.7.5env
    
Ok!
