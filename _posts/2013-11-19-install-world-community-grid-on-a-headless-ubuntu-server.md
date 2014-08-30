---
layout: post
title: "install World Community Grid on a headless Ubuntu Server"
description: ""
category: 
tags: []
---
{% include JB/setup %}
在ubuntu上安装BOINC
===================
    sudo apt-get aptitude install boinc-client
(you can also download it from wcg and install)

find your account key:

    boinccmd --lookup_account http://www.worldcommunitygrid.org username password
    
You should get a response something like this
dfb74c9b9...

attach to your project

    boinccmd --project_attach http://www.worldcommunitygrid.org dfb74c....
    
if you want to verify your attached enter the following command:

    boinccmd --get_state

Futher resources:

http://boinc.berkeley.edu/wiki/installing_BOINC_ON_Ubuntu

http://boinc.berkeley.edu/wiki/Client_configuration

http://boinc.berkeley.edu/wiki/Stop_or_start_BOINC daemon_after_boot

references:

blog.joelchristian.com/?p=291

misctechmusings.com/linux/boinc-cli-for-world-community-grid/
