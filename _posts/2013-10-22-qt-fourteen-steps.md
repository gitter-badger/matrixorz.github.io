---
layout: post
title: "qt fourteen steps"
description: ""
category: 
tags: []
draft: true
---
{% include JB/setup %}

1.Hello ,World!

2.调用退出
3.家庭价值
4.使用窗口部件
5.组装积木
6.组装丰富的积木！
7.一个事物领导另一个
8.准备战斗
9.你可以使用加农炮了
10.像丝一样滑
11.给它一个炮弹
12.悬在空中的砖
13.游戏结束
14.面对墙壁

同普通的 C++ 成员函数一样，槽函数也分为三种类型，即 public slots、private slots 和 protected slots。
public slots：在这个区内声明的槽意味着任何对象都可将信号与之相连接。这对于组件编程非常有用，你可以创建彼此互不了解的对象，将它们的信号与槽进行连接以便信息能够正确的传递。
protected slots：在这个区内声明的槽意味着当前类及其子类可以将信号与之相连接。这适用于那些槽，它们是类实现的一部分，但是其界面接口却面向外部。
private slots：在这个区内声明的槽意味着只有类自己可以将信号与之相连接。这适用于联系非常紧密的类。
