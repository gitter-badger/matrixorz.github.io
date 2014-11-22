---
layout: post
title: "install numpy scipy on ubuntu"
description: ""
category: 
tags: []
---
{% include JB/setup %}
####linux上安装numpy scipy
{% highlight bash %}
    sudo pip install numpy
    sudo apt-get install libatlas-base-dev gfortran
    sudo pip install scipy
    sudo pip install matplotlib   # recommended
{% endhighlight %}
Line 2 was necessary for SciPy, otherwise it was complaining that BLAS and a Fortran compiler were missing. Note that gfortran replaces the package g77.
