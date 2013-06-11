---
layout: post
title: "install hdf5 on ubuntu"
date: 2013-06-05 11:11:11
categories: python yt-project
---
#install hdf5 on ubuntu 12.04

you can probably install the debian libraries into quantal with no issues, precise is less likely to work, but it might.

possibly you will have to build it from source to get everything right.
Code:
    apt-get install devscripts equivs ubuntu-dev-tools
    pull-debian-source hdf5 experimental
    cd hdf5-*
    sudo mk-build-deps -ir
    debuild -us -uc
#=>pick the library packages from ../*deb
