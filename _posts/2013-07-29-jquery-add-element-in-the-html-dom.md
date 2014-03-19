---
layout: post
title: "jquery add element in the html dom"
description: ""
category: 
tags: []
---
{% include JB/setup %}
#使用jquery增加元素节点

add one element in the parent
    var $li_1=$("<li>新增节点：数据结构</li>");
    var $li_2=$("<li>新增节点：设计模式</li>");
    
    var $parent=$(".nm_ul");
    $parent.append($li_1);
    $parent.append($li_2);
    $parent.append($li_1).append($li_2);

add attribute in the added element:
    var $li_1=$("<li title='新增节点：数据结构'>数据节点</li>");
    
    var $parent=$(".nm_ul");
    $parent.append($li_1);