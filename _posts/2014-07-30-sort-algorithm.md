---
layout: post
title: "sort algorithm"
description: ""
category: 
tags: [interview]
draft: true
---
{% include JB/setup %}

对于堆排序，需要自底向上构建堆，排序时要自上而下作堆的调整。


排序算法的特点讨论
![各类排序算法时间复杂度和空间复杂度对比表](http://a.hiphotos.baidu.com/baike/c0%3Dbaike92%2C5%2C5%2C92%2C30%3Bt%3Dgif/sign=b944a959d31373f0e13267cdc566209e/96dda144ad345982dab0d4b00ef431adcbef84dd.jpg)

##稳定排序  
冒泡排序  
归并排序  
基数排序  
插入排序  

##不稳定排序  
选择排序:    
5(前) 8 5(后) 2 9   --> 2 8 5(后) 5(前) 9  
快速排序:  
5 3(前) 3(中) 4 3(后) 8 9 10 11 --> 3(后) 3(前) 3(中) 4 5 8 9 10 11  
希尔排序:  
改进的插入排序，先将数组等间隔分组，各个分组内进行直接插入排序，迭代分组，知道最后为一组，分组的过程中可能破坏排序的稳定性。  

    void insertion_sort(int data[],int n,int increment)
    {
      int i,j;
      for(i=increment;i<n;i+increment)
      {
      for(j=i;j>=increment&&data[j]<data[j-increment];j-=increment)
      {
          swap(&data[j],&data[j-increment]);
      }
 
     
         }
    }
    void shellsort(int data[],int n)
    {
       int i,j;
    for(i=n/2;i>0;i/2)
    {
      for(j=0;j<i;j++)
      {
        insertion_sort(data,n,i);
      }
     }
   }
