---
layout: post
title: "install pypy from source"
description: ""
category: 
tags: []
---
{% include JB/setup %}

    hg clone https://bitbucket.org/pypy/pypy
    cd pypy/pypy/goal
    python ../../rpython/bin/rpython --opt=jit targetpypystandalone.py
    
    [config opt](http://pypy.readthedocs.org/en/latest/config/opt.html)
    
    
    
