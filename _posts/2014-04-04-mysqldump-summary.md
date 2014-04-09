---
layout: post
title: "mysql使用总结"
description: ""
category: 
tags: []
---
{% include JB/setup %}

导出所有库<br/>
    mysqldump -uusername -ppassword --all-databases>all.sql

导入所有库<br/>
    mysql>source all.sql;

导出某些库<br/>
    mysqldump -uusername -ppassword --databases db1 db2 >db1db2.sql

导入某些库<br/>
    mysql>source db1db2.sql

导入某个库<br/>
    mysql -uusername -ppassword db1<db1.sql;
    mysql>source db1.sql;

导出某个库<br/>
    mysqldump -uusername -ppassword db1 table1 table2>tb1tb2.sql

导入某些数据表<br/>
    mysql -uusername -ppassword db1<tb1tb2.sql
    mysql>user db1;
    mysql>source tb1tb2.sql;

mysqldump字符集设置<br/>
    $mysqldump -uusername -ppassword --default-character-set=utf-8 db1 table1>tb1.sql

不写表的任何行信息。如果指向转储表的结构信息    --no-data,-d

创建用户
    
    mysql> insert into mysql.user(Host,User,Password) values("localhost","phplamp",password("1234"));
　　mysql>grant all privileges on *.* to jee@localhost identified by ‘123′；
修改用户密码
   
    mysql> UPDATE mysql.user SET password=PASSWORD(’新密码’) WHERE User=’root’;
    mysql> FLUSH PRIVILEGES;

