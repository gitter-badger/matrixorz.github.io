---
layout: post
title: "mysql使用总结"
description: ""
category: 
tags: [sql,mysql]
---
{% include JB/setup %}

###Mysql导入导出
{% highlight bash %}
导出所有库  
    mysqldump -uusername -ppassword --all-databases>all.sql
导入所有库
    mysql>source all.sql;
导出某些库
    mysqldump -uusername -ppassword --databases db1 db2 >db1db2.sql
导入某些库
    mysql>source db1db2.sql
导入某个库
    mysql -uusername -ppassword db1<db1.sql;
    mysql>source db1.sql;
导出某个库
    mysqldump -uusername -ppassword db1 table1 table2>tb1tb2.sql
导入某些数据表
    mysql -uusername -ppassword db1<tb1tb2.sql
    mysql>user db1;
    mysql>source tb1tb2.sql;
mysqldump字符集设置
    $mysqldump -uusername -ppassword --default-character-set=utf-8 db1 table1>tb1.sql
{% endhighlight %}

###Mysql用户管理
{% highlight bash %}
创建用户
    mysql> insert into mysql.user(Host,User,Password) values("localhost","phplamp",password("1234"));
    mysql>grant all privileges on *.* to jee@localhost identified by ‘123′；
修改用户密码 
    mysql> UPDATE mysql.user SET password=PASSWORD(’新密码’) WHERE User=’root’;
    mysql> FLUSH PRIVILEGES;
显示当前用户    
    mysql>select USER();
{% endhighlight %}  
###Mysql 主从复制  
mysql复制的用途:  
读取扩展
主备份服务器  
故障转移服务器  
地理空间冗余  
数据仓库  
基准测试  
软件更新  
复制配置(my.cnf):    
主服务器配置(Alpha)  
[mysqld]  
log-bin=binary-log #log-bin参数启动二进制日志.二进制日志在MySQL环境中提供了多种用途.它为MySQL复制提供了DDL和DML语句流,能够重新应用于复制的从服务器.  
server-id=1  
重新启动MySQL后 ,使用SQL命令show master status;进行验证.(对于配置复制的从服务器是必要的)  
从服务器配置(Beta)  
[mysqld]  
server-id=2  
read_only=TRUE  

show slave status;  
change master to 
MASTER_HOST='192.168.100.1',#主服务器上的用户名和密码  
MASTER_USER='rep1',  
MASTER_PASSWORD='rep12009';  

change master to  
MASTER_LOG_FILE='binary-log.00001',#主服务器上运行show
 master status命令所检索到的日志文件名称和位置.      
MASTER_LOG_POS=106;  

slave start;#启动从服务器验证其操作  
show slave status;#Slave_IO_Running和Slave_SQL_Running的值为Yes,就证明"主服务器-从服务器"式的MySQL拓扑已经正常运行.  
测试MySQL复制  
在alpha上测试下面的代码:  
PROMPT alpha>;
alpha>  
确认从服务器上什么都不存在:  
beta> show schemas;  
###Mysql 创建视图  
{% highlight bash %}
create view v as select * from table;
create view v as select id,name,age from table;
create view v[vid,vname,vage] as select id,name,age from table;

{% endhighlight %} 

on,where,having的区别  
on,where,having这三个都可以加条件的子句中,on是最先执行,where次之,having最后.有时候如果这先后顺序不影响中间结果的话,那最终结果是相同的.但因为on是先把不符合条件的记录过滤后才进行统计,它就可以减少中间运算要处理的数据,按理说应该速度是最快的.

根据上面的分析,可以知道where应该比having快一点,应为它过滤数据后才进行sum,所以having是最慢的.但也不是说having没用,因为有时在步骤三还没有出来都不知道那个记录才符合要求时,就要用having了.
left join加上where 条件
用where是先连接然后再筛选  
用and是先筛选再连接 
数据库范式:  
第一范式:强调的是列的原子性.  
第二范式:首先使1NF,另外包含两部分内容,一是表必须有一个主键;二是没有包含在主键中的列必须完全依赖于主键,而不能只依赖于主键的一部分.  
第三范式:首先是2NF,另外非主键列必须直接依赖于主键,不能存在传递依赖.即不能存在:非主键列A依赖于非主键列B,非主键列B依赖于主键的情况.  


[无法启动mongodb的解决方法](http://stackoverflow.com/questions/16995616/monogodb-service-cannot-start-after-storage-extension-under-ubuntu-12-04)
