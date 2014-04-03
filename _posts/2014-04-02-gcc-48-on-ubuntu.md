---
layout: post
title: "gcc 4.8 on ubuntu"
description: ""
category: 
tags: []
draft: true
---
{% include JB/setup %}

     sudo apt-get install python-software-properties
	 sudo add-apt-repository ppa:boost-latest/ppa
	 sudo apt-get update
	 sudo apt-get install libboost1.55-all-dev
     sudo add-apt-repository ppa:ubuntu-toolchain-r/test
     sudo apt-get update
     sudo apt-get install gcc-4.8 g++-4.8
     sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.6 60 --slave /usr/bin/g++ g++ /usr/bin/g++-4.6 
     sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 40 --slave /usr/bin/g++ g++ /usr/bin/g++-4.8
     sudo update-alternatives --config gcc





