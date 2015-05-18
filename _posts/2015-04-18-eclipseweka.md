---
layout: post
title: "eclipseÉÏÅäÖÃWEKA¿ª·¢»·¾³"
description: ""
category: 
tags: []
draft: true
published: false
---
{% include JB/setup %}

1.首先下载WEKA安装程序，
2.安装成功后，在weka安装文件夹下解压weka-src.jar文件。
3.再将解压后的文件夹内的东西(build，META-INF和weka)拷贝到eclipse响应工程的src文件夹下。
3.刷新工程

package Explorer中工程名上右键，选择弹出菜单最后一项properties->在左面选中java Build Path->在右面的Library页面->单击Add External JARs…->浏览weka所在目录，将weka.jar添加进来，然后单击ok。 
